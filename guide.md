# Praat ZH (简体中文本地化版本) 开发与打包维护指南

本指南旨在向后续接手此项目的 AI 助手或开发者说明 **Praat ZH** 项目的翻译原理、代码规约、编译打包流程以及 CI/CD 工作流，以防止重复试错。

---

## 1. 界面 UI 翻译机制 (UI Translation)

Praat 的界面翻译是基于静态映射表实现的。

*   **翻译映射文件**：[`sys/praat_translate.cpp`](file:///c:/Users/Sager/Desktop/Program/Praat_ZH/sys/praat_translate.cpp)
*   **核心结构**：`g_translation_map`，这是一个从 `std::u32string` (English Key) 到 `std::u32string` (Chinese Value) 的 `std::unordered_map`。

### ⚠️ 界面翻译关键规约与避坑指南

1.  **字母表排序规则 (Strict Alphabetical Sorting)**
    为了便于后续查找和代码维护，`g_translation_map` 中的初始化列表**必须严格按照 Unicode/ASCII 值大小进行升序排序**。
    *   **排序优先级**：特殊符号/标点 (如 `-`, `.`) > 数字 (如 `0`) > 冒号 (如 `:`) > 大写字母 (`A-Z`) > 小写字母 (`a-z`) > 中文/其他字符。
    *   在添加新词条时，请务必找到最精确的顺序位置进行插入，不可随意追加到文件末尾。

2.  **拼写错误匹配 (Upstream Typos)**
    有些上游注册的菜单命令本身包含拼写错误，但在翻译表中**必须精确匹配错误拼写**，否则翻译引擎无法匹配成功。
    *   *典型案例*：在绘制声谱图时，上游原代码 (`SoundAnalysisArea.cpp:2386`) 注册的命令是 `"- Draw spectogram to picture window:"` (漏写了 `r`，错写为 `spectogram`)。
    *   *对应翻译*：必须为 `{ U"- Draw spectogram to picture window:", U"-绘制声谱图到图像窗口:" }`，如果写成正确的 `spectrogram` 则无法匹配。

3.  **菜单路径前缀与后缀 (Menu Path Prefixes & Suffixes)**
    子菜单命令或某些输入字段如果含有前缀（如连字符 `"- "`）或后缀（如冒号 `":"`），翻译表需要包含整个前缀和后缀，否则无法翻译。
    *   *示例*：`"- Draw intensity to picture window:"` -> `"-绘制音强到图像窗口:"`。

4.  **十六进制 Unicode 转义字符 (Hex Unicode Escapes)**
    在 `praat_translate.cpp` 中编写中文翻译时，尽量采用十六进制转义格式（如 `\uXXXX`）来表示汉字，以规避某些古老编译器在解析 UTF-8 窄/宽字符时产生的字符集混乱或警告。

---

## 2. 内置帮助手册翻译机制 (Help Manual Translation)

Praat 拥有一套自研的文档系统，文档在 C++ 源码中以原始超长字符串定义。

*   **核心文档文件**：大部分教程和问答位于 [`fon/manual_tutorials.cpp`](file:///c:/Users/Sager/Desktop/Program/Praat_ZH/fon/manual_tutorials.cpp) 等 `manual_*.cpp` 文件中。
*   **语法格式**：
    *   `@PageTitle` 或 `@@PageTitle`：行内跳转到名称为 `PageTitle` 的手册页面。
    *   `@@PageTitle|显示文本@`：跳转到 `PageTitle` 页面，但界面上只渲染并显示为“显示文本”。
    *   `##Command#`：以特殊样式渲染的按钮/命令项。

### ⚠️ 帮助文档翻译避坑指南 (重要！)

*   **防止 dangling link (悬空链接报错)**：
    Praat 在启动时会使用 `ManPages::grind` 静态扫描并解析所有内置手册链接。**所有的跳转页面标题 (PageTitle) 必须是英文原版且真实存在的页面名字**，绝不能翻译 PageTitle 本身！
    *   *错误写法*：`@波形图（waveform）` —— 这会被编译器解析为寻找名为 `波形图（waveform）` 的页面，启动时会弹出 `Page "..." contains a dangling link to "波形图"` 的报错警告。
    *   *正确写法*：`@@waveform|波形图@` —— 链接保持官方的 `waveform` 不变，仅向用户显示中文“波形图”。

---

## 3. 本地编译与打包流程 (Compilation & Packaging)

Windows 本地开发采用 **MSYS2 UCRT64** 环境进行交叉编译。

### 编译步骤 (MSYS2 UCRT64)

1.  打开 Windows PowerShell。
2.  执行以下并行构建命令（开启 16 线程构建）：
    ```powershell
    $env:MSYSTEM="UCRT64"; C:\msys64\usr\bin\bash.exe -lc "cd /c/Users/Sager/Desktop/Program/Praat_ZH && make PRAAT_COMPILER=gcc -j16"
    ```
3.  编译成功后，会在根目录下直接生成最新的 **`Praat.exe`**。

### 分包打包步骤

项目通过压缩脚本打包可执行文件与发行说明：
```powershell
Compress-Archive -Path Praat.exe, README.txt -DestinationPath Praat-ZH-Windows-x64.zip -Force
```

---

## 4. 自动化 CI/CD 工作流 (GitHub Actions)

工作流文件位于 [`.github/workflows/release-windows.yml`](file:///c:/Users/Sager/Desktop/Program/Praat_ZH/.github/workflows/release-windows.yml)，负责自动化构建并发布多端制品。

### 工作流特性
*   **多端构建**：包含 Windows x64 与 macOS Universal（M1/M2/Intel 通用）的并行自动编译任务。
*   **手动触发**：支持在 GitHub 仓库中通过 `workflow_dispatch` 传入自定义 Tag（如 `v6.4.67-zh.1`）和版本标题来手动触发构建并自动生成发布草稿。
*   **macOS 构建机制**：macOS 任务跑在 `macos` 虚拟环境中，工作流会自动从官方 Release 拉取上游工程 `praatXXXX_xcodeproj.zip`，加载自定义源码后调用 `xcodebuild` 编译打包并制成 `.dmg` 磁盘映像文件。
