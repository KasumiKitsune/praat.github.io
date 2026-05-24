import re
import os

INPUT_FILE = r"C:\Users\Sager\.gemini\antigravity\brain\fb84dbc7-6204-4b36-bf21-51a5be09a3f0\scratch\ui_strings.txt"
OUTPUT_CPP = r"c:\Users\Sager\Desktop\Program\Praat_ZH\sys\praat_translate.cpp"
DEBUG_OUTPUT = r"c:\Users\Sager\Desktop\Program\Praat_ZH\debug_translations.txt"
CANDIDATE_OUTPUT = r"c:\Users\Sager\Desktop\Program\Praat_ZH\translation_candidates.txt"

# Helper to escape non-ASCII characters to standard C++ \uXXXX escapes
def to_cpp_unicode_literal(s):
    res = ""
    for c in s:
        code = ord(c)
        if code > 127:
            res += f"\\u{code:04x}"
        else:
            if c == '"':
                res += '\\"'
            elif c == '\\':
                res += '\\\\'
            elif c == '\n':
                res += '\\n'
            elif c == '\r':
                res += '\\r'
            elif c == '\t':
                res += '\\t'
            else:
                res += c
    return res


# 1. Exact string mappings for critical GUI items
EXACT_MAP = {
    # Main menu titles & buttons
    "Objects": "对象",
    "Objects:": "对象:",
    "New": "新建",
    "Open": "打开",
    "Save": "保存",
    "Rename...": "重命名...",
    "Copy...": "复制...",
    "Remove": "删除",
    "Info": "信息",
    "Inspect": "检查",
    "Close": "关闭",
    "Help": "帮助",
    "Quit": "退出",
    "OK": "确定",
    "Cancel": "取消",
    "Apply": "应用",
    "Standards": "标准值",
    "Revert": "重置",
    "View & Edit": "查看与编辑",
    "Search": "搜索",
    "Preferences": "偏好设置",
    "Praat": "Praat",
    "Picture": "图像",
    "File": "文件",
    "Edit": "编辑",
    "Query": "查询",
    "Modify": "修改",
    "Analyse": "分析",
    "Synthesize": "合成",
    "Draw": "绘制",
    "Analyse -": "分析 -",
    "Synthesize -": "合成 -",
    "Modify -": "修改 -",
    "Query -": "查询 -",
    "Draw -": "绘制 -",
    "Tabulate -": "制表 -",
    "Annotate -": "标注 -",
    "Combine -": "合并 -",
    "Convert -": "转换 -",
    "Extract -": "提取 -",
    "Play": "播放",
    "Stop": "停止",
    "Pause": "暂停",
    "Continue": "继续",
    "Publish": "发布",
    "Buttons...": "按键...",
    "New Praat script": "新建 Praat 脚本",
    "Open Praat script...": "打开 Praat 脚本...",
    "Run script...": "运行脚本...",
    "Run": "运行",
    "Save to list": "保存到列表",
    "These settings determine how fast transcription and diarization procedures are performed on your computer.": "这些设置决定了在您的计算机上执行转写和说话人日志程序的速度。",
    "Number of threads for transcription:": "转写线程数:",
    "Number of threads for diarization:": "说话人日志线程数:",
    "0 (= automatic)": "0 (= 自动)",
    "automatic": "自动",

    # Main window / Objects window Open Menu (打开)
    "Read from file": "从文件读取",
    "Open long sound file": "打开长声音文件",
    "Read separate channels from sound file": "从声音文件读取分离通道",
    "Read from special sound file": "从特殊声音文件读取",
    "Read Table from tab-separated file": "从制表符分隔文件读取表格",
    "Read Table from comma-separated file": "从逗号分隔文件读取表格",
    "Read Table from semicolon-separated file": "从分号分隔文件读取表格",
    "Read Table from whitespace-separated file": "从空格分隔文件读取表格",
    "Read Table of Real from headerless spreadsheet file": "从无表头电子表格文件读取实数表",
    "Read TableOfReal from headerless spreadsheet file": "从无表头电子表格文件读取实数表",
    "Read Matrix from raw text file": "从原始文本文件读取矩阵",
    "Read Strings from raw text file": "从原始文本文件读取 Strings 字符串列表",
    "Read from special annotation file": "从特殊标注文件读取",
    "Read Sound with adjacent annotation files": "从声音与相邻标注文件读取",
    "Read Sound with adjacent annotation files (Buckeye)": "从声音与相邻标注文件读取 (Buckeye)",
    "Read Sound with adjacent annotation files (TIMIT)": "从声音与相邻标注文件读取 (TIMIT)",

    # Help menus (both in main window and editor windows)
    "Praat Intro": "Praat 简介",
    "Objects window": "对象窗口",
    "Frequently asked questions": "常见问题 (FAQ)",
    "Types of objects": "对象类型",
    "Editors": "编辑器",
    "What's new?": "新特性?",
    "What’s new?": "新特性?",
    "Acknowledgments": "致谢",
    "License": "许可证",
    "Privacy and security": "隐私与安全",
    "Checking for updates": "检查更新",
    "Checking for updates?": "检查更新?",
    "Reporting a problem": "报告问题",
    "Reporting a problem?": "报告问题?",
    "Formulas tutorial": "公式教程",
    "Scripting tutorial": "脚本教程",
    "Functions": "函数",
    "Demo window": "演示窗口",
    "Interoperability": "互操作性",
    "Programming": "编程",
    "Programming with Praat": "用 Praat 进行编程",
    "Go to manual page": "转到手册页",
    "Search Praat manual": "搜索 Praat 手册",
    "About Praat": "关于 Praat",
    "Intro": "简介",
    "FAQ (Frequently Asked Questions)": "常见问题 (FAQ)",

    # Time menu (inside Sound Editor)
    "Query visible part:": "查询可见部分:",
    "Get start of visible part": "获取可见部分起点",
    "Get end of visible part": "获取可见部分终点",
    "Get length of visible part": "获取可见部分长度",
    "Set visible part:": "设置可见部分:",
    "Zoom and scroll settings": "缩放与滚动设置",
    "Zoom": "缩放",
    "Show all": "显示全部",
    "Zoom in": "放大",
    "Zoom out": "缩小",
    "Zoom to selection": "缩放到选择部分",
    "Zoom back": "返回上一次缩放",
    "Scroll page back": "向后滚动一页",
    "Scroll page forward": "向前滚动一页",
    "Query selection:": "查询选择部分:",
    "Get start of selection": "获取选择部分起点",
    "Get cursor": "获取光标位置",
    "Get end of selection": "获取选择部分终点",
    "Get length of selection": "获取选择部分长度",
    "Set selection:": "设置选择部分:",
    "Select": "选择",
    "Widen or shrink selection": "扩大或缩小选择范围",
    "Move cursor to start of selection": "移动光标到选择起点",
    "Move cursor to end of selection": "移动光标到选择终点",
    "Move cursor to": "移动光标到",
    "Move cursor by": "移动光标位移",
    "Move start of selection by": "移动选择起点位移",
    "Move end of selection by": "移动选择终点位移",
    "Selection step settings": "选择步长设置",
    "Select earlier": "选择较早部分",
    "Select later": "选择较晚部分",

    # Sound Editor Window main menus
    "Time": "时间",
    "Analyses": "分析",
    "Spectrogram": "语图",
    "Pitch": "音高",
    "Formants": "共振峰",
    "Pulses": "脉冲",
    "Intensity": "音强",
    "Sound": "声音",
    "Spectrum": "频谱",

    # Bottom Editor Buttons/Labels
    "all": "全部",
    "in": "放大",
    "out": "缩小",
    "sel": "选择",
    "bak": "返回",
    "Group": "分组",
    "Visible part": "可见部分",
    "Total duration": "总时长",
    "seconds": "秒",

    # Static Sound Editor window texts
    "(To see the analyses, zoom in to at most ": "(要查看分析，请放大至最多 ",
    "or raise the “longest analysis” setting with “Show analyses” in the Analyses menu.)": "或者在“分析”菜单中使用“显示分析”来调大“最长分析”设置。）",
    "or raise the \"longest analysis\" setting with \"Show analyses\" in the Analyses menu.)": "或者在“分析”菜单中使用“显示分析”来调大“最长分析”设置。）",
    "(Cannot show pitch contour. Zoom out or change bottom of pitch range in pitch settings.)": "(无法显示音高曲线。请缩小窗口，或在音高设置中修改音高范围下限。)",

    # SoundRecorder & main window labels/buttons
    "Save to list & Close": "保存到列表并关闭",
    "SoundRecorder (mono)": "录音机 (单声道)",
    "SoundRecorder (stereo)": "录音机 (双声道)",
    "use Windows mixer without meters": "在没有电平表时使用 Windows 混音器",
    "Sampling frequency:": "采样频率:",
    "Record": "录音",
    "Name:": "名称:",
    "untitled": "无标题",
    "Can't undo": "无法撤销",
    "Can't redo": "无法重做",
    "Undo": "撤销",
    "Redo": "重做",
    "Clear undo history": "清除撤销历史",
    "Cut": "剪切",
    "Copy": "复制",
    "Paste": "粘贴",
    "Copy selection to Sound clipboard": "复制选择到声音剪贴板",
    "Paste before selection": "粘贴到选择之前",
    "Paste over selection": "覆盖粘贴到选择",
    "Paste after selection": "粘贴到选择之后",
    "Cut text": "剪切文本",
    "Copy text": "复制文本",
    "Paste text": "粘贴文本",
    "Copy to clipboard": "复制到剪贴板",
    
    # --- VETTED EXTENSIONS FOR OBJECTS WINDOW & MENUS ---
    "Rename object": "重命名对象",
    "New name": "新名称",
    "Copy object": "复制对象",
    "Name of new object": "新对象名称",
    "Add menu command": "添加菜单命令",
    "Add menu command...": "添加菜单命令...",
    "Hide menu command": "隐藏菜单命令",
    "Hide menu command...": "隐藏菜单命令...",
    "Show menu command": "显示菜单命令",
    "Show menu command...": "显示菜单命令...",
    "Add action command": "添加动作命令",
    "Add action command...": "添加动作命令...",
    "Hide action command": "隐藏动作命令",
    "Hide action command...": "隐藏动作命令...",
    "Show action command": "显示动作命令",
    "Show action command...": "显示动作命令...",
    
    # --- GOODIES & CALCULATOR ---
    "Calculator": "计算器",
    "Calculator...": "计算器...",
    "Type any numeric formula or string formula": "输入任何数值公式或字符串公式",
    "Note that you can include many special functions in your formula,": "请注意，您可以在公式中包含许多特殊函数，",
    "including statistical functions and acoustics-auditory conversions.": "包括统计函数以及声学-听觉转换。",
    "For details, click Help.": "有关详细信息，请单击帮助。",
    "Report difference of two proportions": "报告两个比例的差异",
    "Report difference of two proportions...": "报告两个比例的差异...",
    "Difference of two proportions": "两个比例的差异",
    "left Row 1": "左 第1行",
    "right Row 1": "右 第1行",
    "left Row 2": "左 第2行",
    "right Row 2": "右 第2行",
    "Save Demo window as PDF file": "保存演示窗口为 PDF 文件",
    "Save Demo window as PDF file...": "保存演示窗口为 PDF 文件...",

    # --- SETTINGS & PREFERENCES ---
    "Text reading settings": "文本读取设置",
    "Text reading settings... || Text reading preferences...": "文本读取设置... || 文本读取偏好...",
    "Encoding of 8-bit text files": "8位文本文件的编码",
    "Text writing settings": "文本写入设置",
    "Text writing settings... || Text writing preferences...": "文本写入设置... || 文本写入偏好...",
    "Output encoding": "输出编码",
    "CJK font style settings": "CJK 字体样式设置",
    "CJK font style settings... || CJK font style preferences...": "CJK 字体样式设置... || CJK 字体样式偏好...",
    "CJK font style": "CJK 字体样式",
    "Set debugging options": "设置调试选项",
    "Debug...": "调试...",
    "Debug multi-threading": "调试多线程",
    "Debug multi-threading...": "调试多线程...",
    "Use multi-threading": "使用多线程",
    "Maximum number of threads": "最大线程数",
    "Minimum number of frames per thread": "每个线程的最小帧数",
    "Trace threads": "追踪线程",
    "List readable types of objects": "列出可读取的对象类型",
    "Create C interface...": "创建 C 接口...",
    "Read Object(s) from file": "从文件读取对象",
    "Save Object(s) as one text file": "保存多个对象为一个文本文件",
    "Save as text file... || Write to text file...": "保存为文本文件... || 写入文本文件...",
    "Save Object(s) as one short text file": "保存多个对象为一个短文本文件",
    "Save as short text file... || Write to short text file...": "保存为短文本文件... || 写入短文本文件...",
    "Save Object(s) as one binary file": "保存多个对象为一个二进制文件",
    "Save as binary file... || Write to binary file...": "保存为二进制文件... || 写入二进制文件...",
    "Save all pages as HTML files": "保存所有页面为 HTML 文件",
    "Save to HTML folder... || Save to HTML directory...": "保存到 HTML 文件夹... || 保存到 HTML 目录...",

    # --- HELP & MANUALS ---
    "Go to manual page...": "转到手册页...",
    "Save manual to HTML folder...": "保存手册到 HTML 文件夹...",
    "Search Praat manual...": "搜索 Praat 手册...",
    "Search manual": "搜索手册",
    "Search for strings (separate with spaces)": "搜索字符串 (用空格分隔)",

    # --- SOUND / TEXTGRID EDITOR MENUS & DIALOGS ---
    "Show analyses": "显示分析",
    "Show analyses...": "显示分析...",
    "Time step settings": "时间步长设置",
    "Time step settings...": "时间步长设置...",
    "Log settings...": "记录设置...",
    "Delete log file 1": "删除记录文件 1",
    "Delete log file 2": "删除记录文件 2",
    "Log 1": "记录 1",
    "Log 2": "记录 2",
    "Log script 3 (...)": "日志脚本 3 (...)",
    "Log script 4 (...)": "日志脚本 4 (...)",
    "Show spectrogram": "显示声谱图",
    "Spectrogram settings": "声谱图设置",
    "Spectrogram settings...": "声谱图设置...",
    "Advanced spectrogram settings": "高级声谱图设置",
    "Advanced spectrogram settings...": "高级声谱图设置...",
    "Get frequency at frequency cursor": "获取频率光标处的频率",
    "Get spectral power at cursor cross": "获取光标交叉处的谱功率",
    "Move frequency cursor to...": "移动频率光标到...",
    "Paint visible spectrogram...": "绘制可见声谱图...",
    "Extract visible spectrogram": "提取可见声谱图",
    "View spectral slice": "查看频谱切片",
    "Show pitch": "显示音高",
    "How to choose a pitch analysis method": "如何选择音高分析方法",
    "Pitch analysis method is filtered autocorrelation": "音高分析方法为滤波自相关",
    "Pitch settings (filtered autocorrelation)...": "音高设置 (滤波自相关)...",
    "Pitch analysis method is raw cross-correlation": "音高分析方法为原始互相关",
    "Pitch settings (raw cross-correlation)...": "音高设置 (原始互相关)...",
    "Pitch analysis method is raw autocorrelation": "音高分析方法为原始自相关",
    "Pitch settings (raw autocorrelation)...": "音高设置 (原始自相关)...",
    "Pitch analysis method is filtered cross-correlation": "音高分析方法为滤波互相关",
    "Pitch settings (filtered cross-correlation)...": "音高设置 (滤波互相关)...",
    "Pitch listing": "音高列表",
    "Get pitch": "获取音高",
    "Get minimum pitch": "获取最小音高",
    "Get maximum pitch": "获取最大音高",
    "Move cursor to minimum pitch": "移动光标到最小音高",
    "Move cursor to maximum pitch": "移动光标到最大音高",
    "Draw visible pitch contour...": "绘制可见音高曲线...",
    "Extract visible pitch contour": "提取可见音高曲线",
    "Show intensity": "显示音强",
    "Intensity settings": "音强设置",
    "Intensity settings...": "音强设置...",
    "Intensity listing": "音强列表",
    "Get intensity": "获取音强",
    "Get minimum intensity": "获取最小音强",
    "Get maximum intensity": "获取最大音强",
    "Draw visible intensity contour...": "绘制可见音强曲线...",
    "Extract visible intensity contour": "提取可见音强曲线",
    "Show formants": "显示共振峰",
    "Formant settings": "共振峰设置",
    "Formant settings...": "共振峰设置...",
    "Advanced formant settings": "高级共振峰设置",
    "Advanced formant settings...": "高级共振峰设置...",
    "Formant listing": "共振峰列表",
    "Get first formant": "获取第一共振峰",
    "Get first bandwidth": "获取第一带宽",
    "Get second formant": "获取第二共振峰",
    "Get second bandwidth": "获取第二带宽",
    "Get third formant": "获取第三共振峰",
    "Get third bandwidth": "获取第三带宽",
    "Get fourth formant": "获取第四共振峰",
    "Get fourth bandwidth": "获取第四带宽",
    "Get formant...": "获取共振峰...",
    "Get bandwidth...": "获取带宽...",
    "Draw visible formant contour...": "绘制可见共振峰曲线...",
    "Extract visible formant contour": "提取可见共振峰曲线",
    "Show pulses": "显示脉冲",
    "Advanced pulses settings": "高级脉冲设置",
    "Advanced pulses settings...": "高级脉冲设置...",
    "Voice report": "嗓音报告",
    "Pulse listing": "脉冲列表",
    "Draw visible pulses...": "绘制可见脉冲...",
    "Extract visible pulses": "提取可见脉冲",
    "Time step strategy": "时间步长策略",
    "Fixed time step (s)": "固定时间步长 (秒)",
    "Number of time steps per view": "每个视口的时间步数",
    "Longest analysis (s)": "最长分析时间 (秒)",
    "Maximum period factor": "最大周期因子",
    "Maximum amplitude factor": "最大振幅因子",

    # --- TEXTGRID EDITOR SPECIFIC ---
    "Boundary": "边界",
    "Tier": "层",
    "Interval": "区间",
    "Point": "点",
    "Add tier...": "添加层...",
    "Add interval tier": "添加区间层",
    "Add point tier": "添加点层",
    "Add interval tier...": "添加区间层...",
    "Add point tier...": "添加点层...",
    "Duplicate tier": "复制层",
    "Duplicate tier...": "复制层...",
    "Remove tier": "删除层",
    "Remove tier...": "删除层...",
    "Rename tier": "重命名层",
    "Rename tier...": "重命名层...",
    "Get tier name": "获取层名称",
    "Get tier type": "获取层类型",
    "Get number of tiers": "获取层数量",
    "Get number of intervals": "获取区间数量",
    "Get number of points": "获取点数量",
    "To TextGrid...": "转为 TextGrid...",
    "To TextGrid": "转为 TextGrid",

    # --- ERROR & WARNING MESSAGES ---
    "Selection changed!\nNo object selected. Cannot rename.": "选区已更改！\n没有选中任何对象。无法重命名。",
    "Selection changed!\nCannot rename more than one object at a time.": "选区已更改！\n一次只能重命名一个对象。",
    "Selection changed!\nNo object selected. Cannot copy.": "选区已更改！\n没有选中任何对象。无法复制。",
    "Selection changed!\nCannot copy more than one object at a time.": "选区已更改！\n一次只能复制一个对象。",
    "Selection changed!\nNo object selected. Cannot query.": "选区已更改！\n没有选中任何对象。无法查询。",
    "Selection changed!\nCannot query more than one object at a time.": "选区已更改！\n一次只能查询一个对象。",
    "Selection changed!\nNo object selected. Cannot inspect.": "选区已更改！\n没有选中任何对象。无法检查。",
    "Cannot inspect data from batch.": "无法从批处理中检查数据。",
    "The numbers should not be negative.": "数值不能为负数。",
    "The row totals should be positive.": "行总数必须为正数。",
    "The column totals should be positive.": "列总数必须为正数。",
    "Cannot open /dev/mixer.": "无法打开 /dev/mixer。",
    "Cannot open audio device.": "无法打开音频设备。",
    "Cannot open audio device.\n": "无法打开音频设备。\n",
    "Cannot open audio device.\nPlease switch on PortAudio in the Sound Recording Preferences.": "无法打开音频设备。\n请在“录音偏好设置”中启用 PortAudio。",
    "Cannot open dropped file.": "无法打开拖入的文件。",
    "Cannot open folder": "无法打开文件夹",
    "Cannot open null file.": "无法打开空文件。",
    "Cannot open picture file": "无法打开图像文件",
    "PortAudio cannot open sound output:": "PortAudio 无法打开声音输出:",
    "This Praat version cannot open movie files.": "此 Praat 版本无法打开视频文件。",
    "No text selected.": "未选择任何文本。",
    "File too short.": "文件太短。",
    "Write error.": "写入错误。",
    "This is not a Praat picture file.": "这不是一个有效的 Praat 图像文件。",
    # --- PHASE 2 EXTRA CURATED ACOUSTICS & GRID localizations ---
    "To Pitch...": "转为音高...",
    "To Pitch": "转为音高",
    "To Formant...": "转为共振峰...",
    "To Formant": "转为共振峰",
    "To Intensity...": "转为音强...",
    "To Intensity": "转为音强",
    "To Spectrogram...": "转为声谱图...",
    "To Spectrogram": "转为声谱图",
    "To Matrix...": "转为矩阵...",
    "To Matrix": "转为矩阵",
    "To Sound...": "转为声音...",
    "To Sound": "转为声音",
    "To PointProcess...": "转为点过程...",
    "To PointProcess": "转为点过程",
    "To DurationTier...": "转为时长层...",
    "To DurationTier": "转为时长层",
    "To RealTier...": "转为实数层...",
    "To RealTier": "转为实数层",
    "To Table...": "转为表格...",
    "To Table": "转为表格",
    "To TableOfReal...": "转为实数表...",
    "To TableOfReal": "转为实数表",
    "Add VocalTract...": "添加声道...",
    "Add amplitude point...": "添加振幅点...",
    "Add bandwidth point...": "添加带宽点...",
    "Add connection...": "添加连接...",
    "Add duration point at cursor": "在光标处添加时长点",
    "Add duration point at...": "添加时长点于...",
    "Add formant point...": "添加共振峰点...",
    "Add new word...": "添加新单词...",
    "Add on all tiers": "在所有层上添加",
    "Add on selected tier": "在选定层上添加",
    "Add open phase point...": "添加开放相位点...",
    "Add pitch point at cursor": "在光标处添加音高点",
    "Add pitch point at time slice": "在时间片上添加音高点",
    "Add pitch point at...": "添加音高点于...",
    "Add pitch point...": "添加音高点...",
    "Add point at cursor": "在光标处添加点",
    "Add point at...": "添加点于...",
    "Add point...": "添加点...",
    "Add pulse at cursor": "在光标处添加脉冲",
    "Add pulse at...": "添加脉冲于...",
    "Add search tier...": "添加搜索层...",
    "Add to dynamic menu...": "添加到动态菜单...",
    "Add to fixed menu...": "添加到固定菜单...",
    "Add to menu...": "添加到菜单...",
    "Add...": "添加...",
    "Align interval...": "对齐区间...",
    "Alignment settings...": "对齐设置...",
    "Amplitude scale in dB": "振幅刻度 (dB)",
    "AmplitudeTier help": "振幅层帮助",
    "AmplitudeTier: Add point...": "振幅层: 添加点...",
    "AmplitudeTier: Formula...": "振幅层: 公式...",
    "AmplitudeTier: To IntensityTier...": "振幅层: 转为音强层...",
    "yes": "是",
    "no": "否",
    "Linear": "线性",
    "Logarithmic": "对数",
    "Hertz": "赫兹",
    "Bark": "巴克",
    "Mel": "美尔",
    "Semitones": "半音",
    "Pitch floor (Hz)": "音高下限 (Hz)",
    "Pitch ceiling (Hz)": "音高上限 (Hz)",
    "Maximum formant (Hz)": "最大共振峰 (Hz)",
    "Time range (s)": "时间范围 (秒)",
    "Time step (s)": "时间步长 (秒)",
    "Window length (s)": "窗长 (秒)",
    "\nPlease change its name or remove it.": "\n请更改其名称或将其删除。",
    "& Sound: To TextGrid?": "& 声音: 转为 TextGrid？",
    "(cannot read sound file)": "（无法读取声音文件）",
    "(zoom in to see the samples)": "（放大以查看采样）",
    "(zoom out to see the data)": "（缩小以查看数据）",
    ") already exists, but it is not an interval tier.": "）已存在，但它不是一个区间层。",
    ") does not match length of string (": "）与字符串长度不匹配（",
    ") exceeds my number of tiers (": "）超过了我的层数（",
    ") is less than the selected number of columns (": "）少于所选的列数（",
    ") on Mark tier.": "）在标记层上。",
    ") on Trigger tier.": "）在触发层上。",
    ") should not be greater than the number of tiers (": "）不应大于层数（",
    ").\nMissing samples were set to zero.": "）。\n缺失的采样已被设置为零。",
    ", because that TextGrid has only": "，因为该 TextGrid 仅有",
    ", because that tier has only": "，因为该层仅有",
    ", because that tier is a point tier instead of an interval tier.": "，因为该层是点层，而不是区间层。",
    ", because that tier is an interval tier instead of a point tier.": "，因为该层是区间层，而不是点层。",
    ", because that tier is not an interval tier.": "，因为该层不是区间层。",
    ", because the FormantGrid has only": "，因为该共振峰网格仅有",
    ", because this is at the left edge of the tier.": "，因为这处于该层的左边缘。",
    ", because this is at the right edge of the tier.": "，因为这处于该层的右边缘。",
    ", but should be at most my number of columns (": "，但最多应为我的列数（",
    ".\nCannot play sound.": "。\n无法播放声音。",
    ". Model file not found?": "。找不到模型文件？",
    ". Please reverse.": "。请反转。",
    ": Cannot align.": "：无法对齐。",
    ": Cannot find language code.": "：找不到语言代码。",
    ": Cannot find phoneme set code.": "：找不到音素集代码。",
    ": Cannot find voice code.": "：找不到嗓音代码。",
    ": Correlation not created.": "：相关未创建。",
    ": Excitation not extracted.": "：激励未提取。",
    ": I don't contain a DurationTier.": "：我不包含时长层。",
    ": I don't contain a PitchTier.": "：我不包含音高层。",
    ": I don't contain a PointProcess.": "：我不包含点过程。",
    ": I don't contain a Sound.": "：我不包含声音。",
    ": Intensity not created.": "：音强未创建。",
    ": LPC synthesis not performed.": "：LPC 合成未执行。",
    ": Matrix not created.": "：矩阵未创建。",
    ": No matrix created.": "：未创建矩阵。",
    ": Permutation not created.": "：置换未创建。",
    ": Sound not extracted.": "：声音未提取。",
    ": TableOfReal not created.": "：实数表未创建。",
    ": TextGrid not created.": "：TextGrid 未创建。",
    ": cannot convert to Sound.": "：无法转换为声音。",
    ": cannot convert to Spectrum.": "：无法转换为频谱。",
    ": cannot extract files.": "：无法提取文件。",
    ": cannot find matches.": "：找不到匹配项。",
    ": cannot find path.": "：找不到路径。",
    ": cannot remove my only row.": "：无法删除我唯一的行。",
    ": cannot replace the tier.": "：无法替换该层。",
    ": channel not converted to sound.": "：通道未转换为声音。",
    ": channels not extracted.": "：通道未提取。",
    ": column": "：列",
    ": could not detect speech activity.": "：无法检测语音活动。",
    ": could not determine Intensity.": "：无法确定音强。",
    ": could not extract part.": "：无法提取部分。",
    ": could not list all classes.": "：无法列出所有类别。",
    ": cumulative costs matrix not created.": "：累积代价矩阵未创建。",
    ": difference not computed.": "：差异未计算。",
    ": duration tier not replaced with": "：时长层未替换为",
    ": formant analysis (Burg) not performed.": "：共振峰分析 (Burg) 未执行。",
    ": formant point not added.": "：共振峰点未添加。",
    ": formula not completed.": "：公式未完成。",
    ": group labels not extracted.": "：组标签未提取。",
    ": intensity analysis not performed.": "：音强分析未执行。",
    ": left boundary not moved.": "：左边界未移动。",
    ": left boundary not removed.": "：左边界未删除。",
    ": no Formant created.": "：未创建共振峰。",
    ": no FormantGrid extracted.": "：未提取共振峰网格。",
    ": no IntensityTier created.": "：未创建音强层。",
    ": no Matrix created.": "：未创建矩阵。",
    ": no Pitch created.": "：未创建音高。",
    ": no PitchTier created.": "：未创建音高层。",
    ": no PointProcess created.": "：未创建点过程。",
    ": no Sound created.": "：未创建声音。",
    ": no Spectrogram created.": "：未创建声谱图。",
    ": no Spectrum created.": "：未创建频谱。",
    ": no Table created.": "：未创建表格。",
    ": no TableOfReal created.": "：未创建实数表。",
    ": no VocalTract created.": "：未创建声道。",
    ": no formant added.": "：未添加共振峰。",
    ": no robust Formant created.": "：未创建鲁棒共振峰。",
    ": no start probabilities set.": "：未设置起始概率。",
    ": no synthesis.": "：未合成。",
    ": no trend subtracted.": "：未减去趋势。",
    ": not converted to BarkSpectrogram.": "：未转换为巴克声谱图。",
    ": not converted to Cochleagram.": "：未转换为耳蜗图。",
    ": not converted to DurationTier.": "：未转换为时长层。",
    ": not converted to Formant.": "：未转换为共振峰。",
    ": not converted to FormantGrid.": "：未转换为共振峰网格。",
    ": not converted to FormantTier.": "：未转换为共振峰层。",
    ": not converted to Intensity.": "：未转换为音强。",
    ": not converted to IntensityTier.": "：未转换为音强层。",
    ": not converted to Manipulation.": "：未转换为 Manipulation。",
    ": not converted to Matrix.": "：未转换为矩阵。",
    ": not converted to Pitch.": "：未转换为音高。",
    ": not converted to PitchTier.": "：未转换为音高层。",
    ": not converted to PointProcess.": "：未转换为点过程。",
    ": not converted to RealTier.": "：未转换为实数层。",
    ": not converted to Sound.": "：未转换为声音。",
    ": not converted to Spectrogram.": "：未转换为语图。",
    ": not converted to Spectrum.": "：未转换为频谱。",
    ": not converted to Table.": "：未转换为表格。",
    ": not converted to TableOfReal.": "：未转换为实数表。",
    ": not converted to TextGrid.": "：未转换为 TextGrid。",
    ": not converted to VocalTract.": "：未转换为声道。",
    ": not converted to mono.": "：未转换为单声道。",
    ": not converted to stereo.": "：未转换为双声道。",
    ": not written to raw sound file": "：未写入原始声音文件",
    "A Sound cannot have a duration less than zero.": "声音时长不能小于零。",
    "A Sound cannot have a duration of zero.": "声音时长不能为零。",
    "A Sound cannot have zero channels.": "声音通道数不能为零。",
    "A column number cannot be less than 1 (the column number you supplied is": "列号不能小于 1 (您提供的列号为",
    "A folder in one of the paths is busy.": "路径中的某个文件夹正忙。",
    "A folder or file in the path does not exist.": "路径中的文件夹或文件不存在。",
    "A part of the path is not a folder (hint: look at the slahes).": "路径的一部分不是文件夹 (提示: 请检查斜杠)。",
    "All Formant objects must have the same starting and finishing times.": "所有共振峰对象必须具有相同的起始和终止时间。",
    "Artword & Speaker: To Sound...": "发音词与说话人: 转为声音...",
    "Artword help": "发音词帮助",

    # --- SCREENSHOT 1: SOUND EDITOR - SOUND MENU ---
    "Sound scaling...": "声音缩放...",
    "Mute channels...": "静音通道...",
    "Modify sound:": "修改声音:",
    "Set selection to zero": "设置选区为零",
    "Reverse selection": "反向选定部分",
    "Query sound:": "查询声音:",
    "Info on whole Sound": "完整声音信息",
    "Get amplitude(s)": "获取振幅",
    "Select by sound:": "根据声音选择:",
    "Move start of selection to nearest zero crossing": "移动选区起点到最近的零交叉点",
    "Move cursor to nearest zero crossing": "移动光标到最近的零交叉点",
    "Move end of selection to nearest zero crossing": "移动选区终点到最近的零交叉点",
    "Draw sound to picture window:": "绘制声音到图像窗口:",
    "Draw visible sound...": "绘制可见声音...",
    "Draw selected sound...": "绘制选定声音...",
    "Extract sound to objects window:": "提取声音到对象窗口:",
    "Extract selected sound (preserve times)": "提取选定声音 (保留时间)",
    "Extract selected sound (time from 0)": "提取选定声音 (时间从0开始)",
    "Extract selected sound (windowed)...": "提取选定声音 (加窗)...",
    "Extract selected sound for overlap...": "提取用于重叠的选定声音...",

    # --- SCREENSHOT 2: SOUND EDITOR - PLAY MENU ---
    "Audio:": "音频:",
    "Play...": "播放...",
    "Play or stop": "播放或停止",
    "Play window": "播放视口内声音",
    "Interrupt playing": "中断播放",

    # --- SCREENSHOT 3: SOUND EDITOR - TIME MENU ---
    "Zoom and scroll settings...": "缩放与滚动设置...",
    "Zoom...": "缩放...",
    "Select...": "选择...",
    "Widen or shrink selection...": "扩大或缩小选择范围...",
    "Move cursor to...": "移动光标到...",
    "Move cursor by...": "移动光标位移...",
    "Move start of selection by...": "移动选择起点位移...",
    "Move end of selection by...": "移动选择终点位移...",
    "Selection step settings...": "选择步长设置...",
    "Move start of selection left": "左移选择起点",
    "Move start of selection right": "右移选择起点",
    "Move end of selection left": "左移选择终点",
    "Move end of selection right": "右移选择终点",

    # --- SCREENSHOT 4 & 5: OBJECTS WINDOW PANELS ---
    "TextGrid help": "TextGrid 帮助",
    "View & Edit alone": "单独查看与编辑",
    "View & Edit with Sound?": "与声音一起查看与编辑？",
    "Extract one tier...": "提取单层...",
    "Extract part...": "提取部分...",
    "To Table (text alignment)...": "转为表格 (文本对齐)...",
    "Analyse interval tier -": "分析区间层 -",
    "Analyse point tier -": "分析点层 -",
    "Merge...": "合并...",
    "Concatenate": "连接 (串联)",
    "Sound help": "声音帮助",
    "Analyse periodicity -": "分析周期性 -",
    "Analyse spectrum -": "分析频谱 -",
    "Manipulate -": "操作 -",
    "Filter -": "滤波 -",

    # --- NEW SOUND AND LONGSOUND REGISTRATIONS ---
    "Record mono Sound...": "录制单声道声音...",
    "Record stereo Sound...": "录制双声道声音...",
    "Record Sound (fixed time)...": "录制声音 (固定时间)...",
    "Create Sound as pure tone...": "创建声音为纯音...",
    "Create Sound from formula...": "通过公式创建声音...",
    "Create Sound as tone complex... || Create Sound from tone complex...": "创建声音为复音... || 从复音创建声音...",
    "Open long sound file...": "打开长声音文件...",
    "Read separate channels from sound file... || Read two Sounds from stereo file...": "从声音文件读取分离通道... || 从双声道文件读取两个声音...",
    "Read Sound from raw Alaw file...": "从原始 Alaw 文件读取声音...",
    "Sound recording settings... || Sound recording preferences...": "录音设置... || 录音偏好...",
    "Sound playing settings... || Sound playing preferences...": "播放设置... || 播放偏好...",
    "LongSound settings... || LongSound preferences...": "长声音设置... || 长声音偏好...",
    "LongSound help": "长声音帮助",
    "Play part...": "播放部分...",
    "Get number of samples": "获取采样数",
    "Get sampling period || Get sample duration || Get sample period": "获取采样周期 || 获取采样时长 || 获取采样周期",
    "Get sampling frequency || Get sample rate": "获取采样频率 || 获取采样率",
    "Get time from sample number... || Get time from index...": "通过采样号获取时间... || 通过索引获取时间...",
    "Get sample number from time... || Get index from time...": "通过时间获取采样号... || 通过时间获取索引...",
    "Annotation tutorial": "标注教程",
    "Save as WAV file... || Write to WAV file...": "保存为 WAV 文件... || 写入 WAV 文件...",
    "Save as AIFF file... || Write to AIFF file...": "保存为 AIFF 文件... || 写入 AIFF 文件...",
    "Save as AIFC file... || Write to AIFC file...": "保存为 AIFC 文件... || 写入 AIFC 文件...",
    "Save as NeXT/Sun file... || Write to NeXT/Sun file...": "保存为 NeXT/Sun 文件... || 写入 NeXT/Sun 文件...",
    "Save as NIST file... || Write to NIST file...": "保存为 NIST 文件... || 写入 NIST 文件...",
    "Save as FLAC file... || Write to FLAC file...": "保存为 FLAC 文件... || 写入 FLAC 文件...",
    "Save left channel as WAV file... || Write left channel to WAV file...": "保存左声道为 WAV 文件... || 写入左声道到 WAV 文件...",
    "Save left channel as AIFF file... || Write left channel to AIFF file...": "保存左声道为 AIFF 文件... || 写入左声道到 AIFF 文件...",
    "Save left channel as AIFC file... || Write left channel to AIFC file...": "保存左声道为 AIFC 文件... || 写入左声道到 AIFC 文件...",
    "Save left channel as NeXT/Sun file... || Write left channel to NeXT/Sun file...": "保存左声道为 NeXT/Sun 文件... || 写入左声道到 NeXT/Sun 文件...",
    "Save left channel as NIST file... || Write left channel to NIST file...": "保存左声道为 NIST 文件... || 写入左声道到 NIST 文件...",
    "Save left channel as FLAC file... || Write left channel to FLAC file...": "保存左声道为 FLAC 文件... || 写入左声道到 FLAC 文件...",
    "Save right channel as WAV file... || Write right channel to WAV file...": "保存右声道为 WAV 文件... || 写入右声道到 WAV 文件...",
    "Save right channel as AIFF file... || Write right channel to AIFF file...": "保存右声道为 AIFF 文件... || 写入右声道到 AIFF 文件...",
    "Save right channel as AIFC file... || Write right channel to AIFC file...": "保存右声道为 AIFC 文件... || 写入右声道到 AIFC 文件...",
    "Save right channel as NeXT/Sun file... || Write right channel to NeXT/Sun file...": "保存右声道为 NeXT/Sun 文件... || 写入右声道到 NeXT/Sun 文件...",
    "Save right channel as NIST file... || Write right channel to NIST file...": "保存右声道为 NIST 文件... || 写入右声道到 NIST 文件...",
    "Save right channel as FLAC file... || Write right channel to FLAC file...": "保存右声道为 FLAC 文件... || 写入右声道到 FLAC 文件...",
    "Save part as audio file... || Write part to audio file...": "保存部分为音频文件... || 写入部分到音频文件...",

    # --- SCREENSHOTS PHASE 3: MAIN OPEN MENU & EDITOR FILE/TEXTGRID/INTERVAL MENUS ---
    # Main Open Menu (打开)
    "Read from file...": "从文件读取...",
    "Read separate channels from sound file... || Read two Sounds from stereo file...": "从声音文件读取分离通道... || 从双声道文件读取两个声音...",
    "Read Table from tab-separated file...": "从制表符分隔文件读取表格...",
    "Read Table from comma-separated file...": "从逗号分隔文件读取表格...",
    "Read Table from semicolon-separated file...": "从分号分隔文件读取表格...",
    "Read Table from whitespace-separated file... || Read Table from table file...": "从空格分隔文件读取表格... || 从表格文件读取表格...",
    "Read TableOfReal from headerless spreadsheet file...": "从无表头电子表格文件读取实数表...",
    "Read Matrix from raw text file...": "从原始文本文件读取矩阵...",
    "Read Strings from raw text file...": "从原始文本文件读取 Strings 字符串列表...",
    "Read from special annotation file...": "从特殊标注文件读取...",
    "Read Sound with adjacent annotation files...": "从声音与相邻标注文件读取...",

    # Editor File Menu (文件)
    "Editor info": "编辑器信息",
    "Sound info": "声音信息",
    "Save sound to disk:": "保存声音到磁盘:",
    "Save selected sound as WAV file... ||": "保存选定声音为 WAV 文件... ||",
    "Save selected sound as 24-bit WAV file...": "保存选定声音为 24位 WAV 文件...",
    "Save selected sound as 32-bit WAV file...": "保存选定声音为 32位 WAV 文件...",
    "Save selected sound as AIFF file... ||": "保存选定声音为 AIFF 文件... ||",
    "Save selected sound as AIFC file... ||": "保存选定声音为 AIFC 文件... ||",
    "Save selected sound as NeXT/Sun file... ||": "保存选定声音为 NeXT/Sun 文件... ||",
    "Save selected sound as NIST file... ||": "保存选定声音为 NIST 文件... ||",
    "Save selected sound as FLAC file... ||": "保存选定声音为 FLAC 文件... ||",
    "New editor script": "新建编辑器脚本",
    "Open editor script...": "打开编辑器脚本...",
    "Quit Praat": "退出 Praat",

    # Editor TextGrid Menu (文本标注)
    "Convert entire TextGrid to backslash trigraphs": "将整个 TextGrid 转换为反斜杠三合字符",
    "Convert entire TextGrid to Unicode": "将整个 TextGrid 转换为 Unicode",
    "Select by TextGrid:": "根据 TextGrid 选择:",
    "Select previous tier": "选择上一层",
    "Select next tier": "选择下一层",
    "Select previous interval": "选择上一个区间",
    "Select next interval": "选择下一个区间",
    "Extend-select left": "向左扩展选择",
    "Extend-select right": "向右扩展选择",
    "Draw TextGrid to picture window:": "绘制 TextGrid 到图像窗口:",
    "Draw visible sound and TextGrid...": "绘制可见声音与 TextGrid...",
    "Draw visible pitch contour and TextGrid...": "绘制可见音高曲线与 TextGrid...",
    "Extract TextGrid to objects window:": "提取 TextGrid 到对象窗口:",
    "Extract selected TextGrid (preserve times)": "提取选定 TextGrid (保留时间)",
    "Extract selected TextGrid (time from 0)": "提取选定 TextGrid (时间从0开始)",

    # Editor Interval Menu (区间)
    "Transcribe interval": "转写区间",
    "Transcription settings...": "转写设置...",
    "Diarize interval": "进行说话人日志分析",
    "Diarization settings...": "说话人日志分析设置...",
    "Query interval:": "查询区间:",
    "Get starting point of interval": "获取区间起点时间",
    "Get starting point of interval...": "获取区间起点时间...",
    "Get end point of interval": "获取区间终点时间",
    "Get end point of interval...": "获取区间终点时间...",
    "Get label of interval": "获取区间标签",
    "Get label of interval...": "获取区间标签...",

    # Objects Window panel
    "Modify TextGrid": "修改 TextGrid",
    "Scale times": "缩放时间",
    "Transcribe interval...": "转写区间...",
    "Diarize interval...": "进行说话人日志分析...",
    "Modify Sound": "修改声音",

    # --- DIALOG COMMENTS & POPUPS (Batch 4) ---
    "If the time step strategy is \"fixed\":" : "如果时间步长策略为 \"固定 (fixed)\":",
    "If the time step strategy is \"view-dependent\":" : "如果时间步长策略为 \"每个视口 (view-dependent)\":",
    "View range (dB)" : "显示范围 (dB)",
    "Averaging method" : "平均方法",
    "median" : "中位数",
    "mean energy" : "平均能量",
    "mean sones" : "平均宋 (sones)",
    "mean dB" : "平均分贝 (dB)",
    "Subtract mean pressure" : "减去平均声压",
    "Note: the pitch floor is taken from the pitch settings." : "注：音高下限取自音高设置。",
    "(your \"time step strategy\" has its standard value: automatic)" : "（您的 \"时间步长策略\" 具有标准值：自动）",

    # Pitch Settings Heading & Fields (proactive)
    "Where to search..." : "搜索范围...",
    "How to view..." : "显示方式...",
    "Unit" : "单位",
    "View range (units)" : "显示范围 (单位)",
    "Drawing method" : "绘制方法",
    "How to find the candidates..." : "如何寻找候选音高...",
    "Max. number of candidates" : "最大候选音高数量",
    "Very accurate" : "非常精确",
    "How to find a path through the candidates..." : "如何确定最终音高路径...",
    "Silence threshold" : "静音阈值",
    "Voicing threshold" : "浊音阈值",
    "Octave cost" : "倍频程惩罚",
    "Octave-jump cost" : "倍频程跳跃惩罚",
    "Voiced / unvoiced cost" : "浊音/清音转换惩罚",

    # Formant Settings Fields (proactive)
    "Formant ceiling (Hz)" : "共振峰上限 (Hz)",
    "Number of formants" : "共振峰数量",
    "Window length (s)" : "窗长 (秒)",
    "Dynamic range (dB)" : "动态范围 (dB)",
    "Dot size (mm)" : "点大小 (毫米)",
    "Pre-emphasis from (Hz)" : "预加重起点 (Hz)",
    "Method" : "方法",

    # Pulses settings Fields (proactive)
    "Maximum period factor" : "最大周期因子",
    "Maximum amplitude factor" : "最大振幅因子",

    # --- SECONDARY MENUS ---
    # Sound - Analyse Periodicity Menu
    "To Pitch (filtered autocorrelation)..." : "转为音高 (滤波自相关)...",
    "To Pitch (raw cross-correlation)..." : "转为音高 (原始互相关)...",
    "To Pitch (raw autocorrelation)..." : "转为音高 (原始自相关)...",
    "To Pitch (filtered cross-correlation)..." : "转为音高 (滤波互相关)...",
    "To Pitch (shs)..." : "转为音高 (SHS)...",
    "To Pitch (SPINET)..." : "转为音高 (SPINET)...",
    "To PointProcess (periodic, cc)..." : "转为点过程 (周期性, cc)...",
    "To PointProcess (periodic, peaks)..." : "转为点过程 (周期性, 峰值)...",
    "To PointProcess (extrema)..." : "转为点过程 (极值)...",
    "To PointProcess (zeroes)..." : "转为点过程 (零点)...",
    "To Harmonicity (cc)..." : "转为谐噪比 (cc)...",
    "To Harmonicity (ac)..." : "转为谐噪比 (ac)...",
    "To Harmonicity (gne)..." : "转为谐噪比 (gne)...",
    "To PowerCepstrogram..." : "转为倒谱图 (PowerCepstrogram)...",

    # Sound - Convert Menu
    "Convert to mono" : "转换为单声道",
    "Convert to stereo" : "转换为双声道",
    "Extract all channels" : "提取所有通道",
    "Extract one channel..." : "提取单个通道...",
    "Extract part for overlap..." : "提取用于重叠的部分...",
    "Extract Electroglottogram..." : "提取声带电图 (EGG)...",
    "Resample..." : "重采样...",
    "To Sound (white channels)..." : "转为声音 (白噪声通道)...",
    "To Sound (bss)..." : "转为声音 (盲源分离 bss)...",
    "To CrossCorrelationTable..." : "转为互相关表...",
    "Lengthen (overlap-add)..." : "拉长 (重叠相加)...",
    "Deepen band modulation..." : "加深频带调制...",
    "Change gender..." : "改变性别...",
    "Down to Matrix" : "降为矩阵",

    # --- SPECTROGRAM SETTINGS DIALOG (Screenshot 1) ---
    "Time and frequency resolutions:" : "时间与频率分辨率:",
    "Number of time steps" : "时间步数",
    "Number of time steps:" : "时间步数:",
    "Number of frequency steps" : "频率步数",
    "Number of frequency steps:" : "频率步数:",
    "Spectrogram analysis settings:" : "声学谱图分析设置:",
    "Spectrogram analysis settings" : "声学谱图分析设置",
    "Window shape" : "窗形状",
    "Window shape:" : "窗形状:",
    "square (rectangular)" : "矩形窗 (square/rectangular)",
    "Hamming (raised sine-squared)" : "海明窗 (Hamming/raised sine-squared)",
    "Bartlett (triangular)" : "巴特利特窗 (Bartlett/triangular)",
    "Welch (parabolic)" : "韦尔奇窗 (Welch/parabolic)",
    "Hanning (sine-squared)" : "汉宁窗 (Hanning/sine-squared)",
    "Gaussian" : "高斯窗 (Gaussian)",
    "Fourier" : "傅里叶 (Fourier)",
    "Spectrogram view settings:" : "声学谱图显示设置:",
    "Spectrogram view settings" : "声学谱图显示设置",
    "Maximum (dB/Hz)" : "最大值 (dB/Hz)",
    "Maximum (dB/Hz):" : "最大值 (dB/Hz):",
    "Pre-emphasis (dB/oct)" : "预加重 (dB/oct)",
    "Pre-emphasis (dB/oct):" : "预加重 (dB/oct):",
    "Dynamic compression (0 - 1)" : "动态压缩 (0 - 1)",
    "Dynamic compression (0 - 1):" : "动态压缩 (0 - 1):",

    # --- STATUS BAR AND OTHER LABELS ---
    "Visible part" : "可见部分",
    "Total duration" : "总时长",

    # --- MENU "修改 >" (Screenshot 3) ---
    "Modify times" : "修改时间",
    "Shift times by..." : "偏移时间 (相对量)...",
    "Shift times to..." : "偏移时间 (绝对量)...",
    "Scale times by..." : "缩放时间 (相对值)...",
    "Scale times to..." : "缩放时间 (绝对值)...",
    "Subtract mean" : "减去均值",
    "Multiply..." : "乘...",
    "Multiply by window..." : "乘窗...",
    "Scale peak..." : "缩放峰值...",
    "Scale intensity..." : "缩放音强...",
    "Set value at sample number..." : "设置采样点处的数值...",
    "Set part to zero..." : "设置部分为零...",
    "Override sampling frequency..." : "覆盖采样频率...",
    "In-place filter" : "就地滤波",

    # --- MENU "操作 >" ---
    "To Manipulation..." : "转为 Manipulation 操纵对象...",
    "To KlattGrid (simple)..." : "转为 KlattGrid (简单)...",

    # --- MENU "分析频谱 >" ---
    "To Spectrum..." : "转为频谱 (Spectrum)...",
    "To Spectrum (resampled)..." : "转为频谱 (重采样)...",
    "To Ltas..." : "转为长期平均实数谱 (Ltas)...",
    "To Ltas (pitch-corrected)..." : "转为长期平均实数谱 (音高修正)...",
    "To Cochleagram..." : "转为耳蜗图...",
    "To Spectrogram (pitch-dependent)..." : "转为语图 (音高相关)...",
    "To BarkSpectrogram..." : "转为 Bark 语图...",
    "To MelSpectrogram..." : "转为 Mel 语图...",
    "To Formant (burg)..." : "转为共振峰 (Burg)...",
    "To Formant (hack)" : "转为共振峰 (Hack)",
    "To Formant (hack)..." : "转为共振峰 (Hack)...",
    "To LPC" : "转为 LPC",
    "To LPC..." : "转为 LPC...",
    "To MFCC..." : "转为 倒谱系数 (MFCC)...",
    "To FormantPath (burg)..." : "转为共振峰路径 (Burg)...",

    # --- MENU "标注 >" ---
    "To TextGrid (speech activity, Silero)..." : "转为 TextGrid (语音活动检测, Silero)...",
    "To TextGrid (speech activity, LTSF)..." : "转为 TextGrid (语音活动检测, LTSF)...",
    "To TextGrid (silences)..." : "转为 TextGrid (静音检测)...",

    # --- MENU "滤波 >" ---
    "Filtering tutorial" : "滤波教程",
    "Filter (pass Hann band)..." : "滤波 (带通 Hanning窗)...",
    "Filter (stop Hann band)..." : "滤波 (带阻 Hanning窗)...",
    "To Sound (derivative)..." : "转为声音 (求导)...",
    "Reduce noise..." : "降噪...",
    "Filter (one formant)..." : "滤波 (单共振峰)...",
    "Filter (pre-emphasis)..." : "滤波 (预加重)...",
    "Filter (de-emphasis)..." : "滤波 (去加重)...",
    "Filter (gammatone)..." : "滤波 (伽马通)...",

    # --- MAIN PRAAT MENUS & TECHNICAL SUBMENU ---
    "New Praat notebook" : "新建 Praat 笔记本 (Notebook)",
    "Open Praat notebook..." : "打开 Praat 笔记本 (Notebook)...",
    "Goodies" : "小工具 (Goodies)",
    "Technical" : "技术调试 (Technical)",
    "Report memory use" : "报告内存占用",
    "Report integer properties" : "报告整型属性",
    "Report floating point properties" : "报告浮点属性",
    "Report system properties" : "报告系统属性",
    "Report app properties" : "报告应用属性",
    "Report graphical properties" : "报告图形属性",
    "Report text properties" : "报告文本属性",
    "Report font properties" : "报告字体属性",
    "Praat test..." : "Praat 测试...",

    # --- INSPECTOR FORM BUTTONS ---
    "Change" : "修改",

    # --- MENU "合并 >" (Batch 6) ---
    "Combine to stereo" : "合并为双声道",
    "Concatenate recoverably" : "可恢复连接 (Concatenate)",
    "Concatenate with overlap..." : "重叠连接 (overlap)...",
    "Cross-correlate..." : "计算互相关...",
    "To CrossCorrelationTable (combined)..." : "转为互相关表 (合并)...",
    "To DTW..." : "转为动态时间规整 (DTW)...",
    "To ParamCurve" : "转为参数曲线 (ParamCurve)",

    # --- DIALOG "Draw visible sound" ---
    "Draw visible sound" : "绘制可见声音",
    "Picture window:" : "图像窗口:",
    "Erase first" : "先擦除",
    "Preserve times" : "保留时间",
    "Vertical range:" : "垂直范围:",
    "0.0 (= auto)" : "0.0 (= 自动)",
    "(= auto)" : "(= 自动)",
    "Margins:" : "边距:",
    "Write name at top:" : "在顶部写入名称:",
    "Draw selection times" : "绘制选定时间",
    "Draw selection hairs" : "绘制选定定位线",
    "Garnish" : "装饰 (Garnish)",

    # --- MENU "查询 >" ---
    "Get number of channels" : "获取通道数",
    "Query time sampling" : "查询时间采样",
    "Query time sampling >" : "查询时间采样 >",
    "Get value at time..." : "获取指定时间的数值...",
    "Get value at sample number..." : "获取指定采样点号的数值...",
    "Get minimum..." : "获取最小值...",
    "Get time of minimum..." : "获取最小值的时间...",
    "Get maximum..." : "获取最大值...",
    "Get time of maximum..." : "获取最大值的时间...",
    "Get absolute extremum..." : "获取绝对极值...",
    "Get nearest zero crossing..." : "获取最近的零交叉点...",
    "Get nearest level crossing..." : "获取最近的电平交叉点...",
    "Get mean..." : "获取均值...",
    "Get root-mean-square..." : "获取均方根 (RMS)...",
    "Get standard deviation..." : "获取标准差...",
    "Get energy..." : "获取能量...",
    "Get power..." : "获取功率...",
    "Get energy in air" : "获取空气中的能量",
    "Get power in air" : "获取空气中的功率",

    # --- MENU "脉冲 >" ---
    "Query pulses:" : "查询脉冲:",
    "Draw pulses to picture window:" : "绘制脉冲到图像窗口:",
    "Extract pulses to objects window:" : "提取脉冲到对象窗口:",

    # --- MENU "绘制 >" ---
    "Draw where..." : "绘制于指定条件...",
    "Paint where..." : "着色于指定条件...",
    "Paint enclosed..." : "对闭合区域着色...",

    # --- MENU "保存声音到磁盘:" ---
    "Save selected sound as WAV file..." : "保存选定声音为 WAV 文件...",
    "Save selected sound as AIFF file..." : "保存选定声音为 AIFF 文件...",
    "Save selected sound as AIFC file..." : "保存选定声音为 AIFC 文件...",
    "Save selected sound as NeXT/Sun file..." : "保存选定声音为 NeXT/Sun 文件...",
    "Save selected sound as NIST file..." : "保存选定声音为 NIST 文件...",
    "Save selected sound as FLAC file..." : "保存选定声音为 FLAC 文件...",

    # --- MENU "音高 >" ---
    "Pitch methods and settings:" : "音高分析方法与设置:",
    "Query pitch:" : "查询音高:",
    "Select by pitch:" : "根据音高选择:",
    "Draw pitch to picture window:" : "绘制音高到图像窗口:",
    "Extract pitch to objects window:" : "提取音高到对象窗口:",

    # --- DIALOG "音高设置" ---
    "(your current pitch analysis method is indeed filtered autocorrelation)" : "（您当前的音高分析方法确为：滤波自相关）",
    "(you have standard time step settings, see Analyse menu)" : "（您的时间步长设置为标准值，详见“分析”菜单）",
    "Hertz (logarithmic)" : "赫兹 (对数)",
    "logHertz" : "对数赫兹 (logHertz)",
    "semitones re 1 Hz" : "半音 (基准 1 Hz)",
    "semitones re 100 Hz" : "半音 (基准 100 Hz)",
    "semitones re 200 Hz" : "半音 (基准 200 Hz)",
    "semitones re 440 Hz" : "半音 (基准 440 Hz)",
    "ERB" : "等效矩形带宽 (ERB)",
    "How to preprocess the sound..." : "如何预处理声音...",
    "Attenuation at tops" : "高频衰减量",

    # --- ACOUSTIC SYNTHESIS & TTS SUBMENUS ---
    "Acoustic synthesis (Klatt) >" : "声学合成 (Klatt) >",
    "Text-to-speech synthesis >" : "文本转语音合成 (TTS) >",
    "Speech-to-text recognition >" : "语音转文本识别 (ASR) >",

    # --- MENU "提取 >" ---
    "Extract all intervals..." : "提取所有区间...",
    "Extract non-empty intervals..." : "提取非空区间...",
    "Extract intervals where..." : "提取符合条件的区间...",

    # --- MENU "帮助 >" ---
    "KlattGrid help" : "KlattGrid 帮助",
    "Create KlattGrid..." : "创建 KlattGrid...",
    "Create KlattGrid from vowel..." : "从元音创建 KlattGrid...",
    "TextGridEditor help" : "TextGrid 编辑器帮助",
    "About special symbols" : "关于特殊符号",
    "Phonetic symbols" : "音标符号",
    "About text styles" : "关于文本样式",

    # --- DIALOG "Sound: Draw where" ---
    "Sound: Draw where" : "绘制声音至指定条件",
    "Time range (s):" : "时间范围 (秒):",
    "0.0 (= all)" : "0.0 (= 全部)",
    "(= all)" : "(= 全部)",
    "Draw only those parts where the following condition holds:" : "仅绘制符合以下条件的区域:",

    # --- MARGINS MENU (Margins) IN PICTURE WINDOW (Batch 7) ---
    # --- MARGINS MENU (Margins) IN PICTURE WINDOW (Batch 7) ---
    "Margins" : "页边距",
    "Draw inner box" : "绘制内侧边框",
    "Text left..." : "在左侧添加文本...",
    "Text right..." : "在右侧添加文本...",
    "Text top..." : "在顶部添加文本...",
    "Text bottom..." : "在底部添加文本...",
    "Marks left every..." : "左侧每隔...标出刻度...",
    "Marks right every..." : "右侧每隔...标出刻度...",
    "Marks bottom every..." : "底部每隔...标出刻度...",
    "Marks top every..." : "顶部每隔...标出刻度...",
    "One mark left..." : "在左侧标出单个刻度...",
    "One mark right..." : "在右侧标出单个刻度...",
    "One mark bottom..." : "在底部标出单个刻度...",
    "One mark top..." : "在顶部标出单个刻度...",
    "Marks" : "刻度标记",
    "Logarithmic marks" : "对数刻度标记",
    "One logarithmic mark" : "单个对数刻度标记",

    # --- WORLD MENU (World) IN PICTURE WINDOW ---
    "World" : "绘制",
    "Text..." : "绘制文本...",
    "Text special..." : "绘制特殊文本...",
    "Rectangle text (maximal fit)..." : "矩形区域文本 (最大拟合)...",
    "Rectangle text (wrap & truncate)..." : "矩形区域文本 (换行与截断)...",
    "Draw line..." : "绘制直线...",
    "Draw arrow..." : "绘制箭头...",
    "Draw two-way arrow..." : "绘制双向箭头...",
    "Draw function..." : "绘制数学函数曲线...",
    "Draw rectangle..." : "绘制矩形...",
    "Paint rectangle..." : "填充矩形...",
    "Draw rounded rectangle..." : "绘制圆角矩形...",
    "Paint rounded rectangle..." : "填充圆角矩形...",
    "Draw arc..." : "绘制圆弧...",
    "Draw ellipse..." : "绘制椭圆...",
    "Paint ellipse..." : "填充椭圆...",
    "Draw circle..." : "绘制圆形...",
    "Paint circle..." : "填充圆形...",
    "Draw circle (mm)..." : "绘制圆形 (毫米)...",
    "Paint circle (mm)..." : "填充圆形 (毫米)...",
    "Insert picture from file..." : "从文件插入图像...",
    "Insert picture from file (embedded)..." : "从文件插入图像 (嵌入式)...",
    "Measure" : "测量",

    # --- PEN MENU (Pen) & COLORS IN PICTURE WINDOW ---
    "Pen" : "画笔",
    "Solid line" : "实线",
    "Dotted line" : "点线",
    "Dashed line" : "虚线",
    "Dashed-dotted line" : "双点划线",
    "Line width..." : "线宽...",
    "Arrow size..." : "箭头大小...",
    "Speckle size..." : "斑点大小...",
    "Colour..." : "画笔颜色...",
    "Black" : "黑色",
    "White" : "白色",
    "Red" : "红色",
    "Green" : "绿色",
    "Blue" : "蓝色",
    "Yellow" : "黄色",
    "Cyan" : "青色",
    "Magenta" : "品红",
    "Maroon" : "褐红",
    "Lime" : "浅绿 (酸橙)",
    "Navy" : "藏青",
    "Teal" : "蓝绿 (鸭绿)",
    "Purple" : "紫色",
    "Olive" : "橄榄绿",
    "Pink" : "粉红",
    "Silver" : "银色",
    "Grey" : "灰色",

    # --- FONT MENU (Font) & FONTS IN PICTURE WINDOW ---
    "Font" : "字体",
    "Font size..." : "字号...",
    "Times" : "Times 罗马体",
    "Helvetica" : "Helvetica 无衬线体",
    "Palatino" : "Palatino 优雅体",
    "Courier" : "Courier 等宽体",

    # --- PICTURE FILE OPTIONS IN PICTURE WINDOW ---
    "Picture info" : "图像属性信息",
    "Save as 300-dpi PNG file..." : "保存为 300-dpi PNG 图像...",
    "Save as 600-dpi PNG file..." : "保存为 600-dpi PNG 图像...",
    "Save as EPS file..." : "保存为 EPS 矢量图...",
    "Save as EPS file" : "保存为 EPS 矢量图",
    "Save as Windows metafile..." : "保存为 Windows 图元文件 (WMF)...",
    "Read from praat picture file..." : "从 Praat Picture 文件读取...",
    "Save as praat picture file..." : "保存为 Praat Picture 文件...",
    "Print..." : "打印图像...",

    # --- ACTION SUBMENU IN RIGHT ACTION LIST ---
    "Query formants:" : "查询共振峰:",
    "Draw formants to picture window:" : "绘制共振峰到图像窗口:",
    "Extract formants to objects window:" : "提取共振峰到对象窗口:",
    "Query spectrogram:" : "查询声学谱图:",
    "Select frequency:" : "选择频率:",
    "Draw spectrogram to picture window:" : "绘制声学谱图到图像窗口:",
    "Extract to objects window:" : "提取到对象窗口:",

    # --- DIALOG "Sound scaling" ---
    "Sound scaling" : "声音缩放",
    "Scaling strategy:" : "缩放策略:",
    "by whole" : "全局缩放 (by whole)",
    "by window" : "视口缩放 (by window)",
    "by window and channel" : "视口与通道独立缩放",
    "fixed height" : "固定高度 (fixed height)",
    "fixed range" : "固定数值范围 (fixed range)",
    "Minimum:" : "最小值:",
    "Maximum:" : "最大值:",

    # --- SECTION 1: Praat Objects Selection Menu Items ---
    "Draw with sound..." : "随声音绘制...",
    "Draw with sound2..." : "随声音绘制2...",
    "Tabulate occurrences..." : "列表显示出现次数...",
    "Query dictionary..." : "查询词典...",
    "Convert to backslash trigraphs" : "转换为反斜杠三元字符",
    "Convert to Unicode" : "转换为 Unicode",
    "Insert interval tier..." : "插入区间层...",
    "Insert point tier..." : "插入点层...",
    "Set tier name..." : "设置层名称...",
    "Insert boundary..." : "插入边界...",
    "Remove left boundary..." : "移除左边界...",
    "Remove right boundary..." : "移除右边界...",
    "Remove boundary at time..." : "移除指定时间的边界...",
    "Set interval text..." : "设置区间文本...",
    "Replace interval texts..." : "替换区间文本...",
    "Insert point..." : "插入点...",
    "Remove point..." : "移除点...",
    "Remove points..." : "移除多个点...",
    "Set point text..." : "设置点文本...",
    "Replace point texts..." : "替换点文本...",
    "Get starting points..." : "获取起点...",
    "Get end points..." : "获取终点...",
    "Get centre points..." : "获取中心点...",
    "Get points..." : "获取点...",
    "Get points (preceded)..." : "获取前面的点...",
    "Get points (followed)..." : "获取后面的点...",

    # --- SECTION 2: Picture Dropdowns & Extra ---
    "Mouse selects inner viewport" : "鼠标选择内部视口",
    "Mouse selects outer viewport" : "鼠标选择外部视口",
    "Select inner viewport..." : "选择内部视口...",
    "Select outer viewport..." : "选择外部视口...",
    "Viewport text..." : "视口文本...",
    "Picture window help" : "图像窗口帮助",

    # --- SECTION 3: Sound Editor ---
    "Draw spectrogram to picture window" : "绘制声谱图到图像窗口",
    "Query intensity" : "查询音强",
    "Draw intensity to picture window" : "绘制音强到图像窗口",
    "Extract intensity to objects window" : "提取音强到对象窗口",
    "SoundEditor help" : "声音编辑器帮助",
    "LongSoundEditor help" : "长声音编辑器帮助",

    # --- SECTION 4: Common Dialogs ---
    "Synchronize zoom and scroll" : "同步缩放与滚动",
    "For \"fixed height\":" : "对于 \"固定高度\":",
    "For \"fixed range\":" : "对于 \"固定范围\":",
    "(by window)" : "(按当前视口)",
    "(by whole)" : "(按完整对象)",
    "(fixed height)" : "(固定高度)",
    "(fixed range)" : "(固定范围)",
    "Mute channels" : "静音通道",
    "Channels to mute" : "静音的通道",
    "Channels to mute:" : "静音的通道:",
    "(whitespace-separated)" : "(以空格分隔)",

    # --- SECTION 5: Praat Info window Edit Menu ---
    "Convert to C string" : "转换为 C 字符串",

    # Final translations added
    "Stop playing sound": "停止播放声音",
    "Feedforward neural networks": "前馈神经网络",
    "Create FFNet...": "创建前馈神经网络...",
    "Create iris example...": "创建鸢尾花示例...",
    "Create FFNet (linear outputs)...": "创建前馈神经网络 (线性输出)...",
    "Create PatternList...": "创建模式列表...",
    "Create PatternList... || Create Pattern...": "创建模式列表... || 创建模式...",
    "Create Categories...": "创建类别...",
    "Advanced": "高级",
    "Create empty Network...": "创建空网络...",
    "Create rectangular Network...": "创建矩形网络...",
    "Create rectangular Network (vertical)...": "创建矩形网络（垂直）...",
    "Create Net as deep belief network...": "创建深度信念网络...",
    "Create Net as DeepBeliefNetwork": "创建深度信念网络",
    "Create Corpus...": "创建语料库...",
    "Acoustic synthesis (Klatt)": "声学合成 (Klatt)",
    "Acoustic synthesis (Klatt) >": "声学合成 (Klatt) >",
    "Text-to-speech synthesis": "文本转语音合成",
    "Text-to-speech synthesis >": "文本转语音合成 >",
    "Tabulate SpeechSynthesizer language properties": "列表显示语音合成器语言属性",
    "Tabulate SpeechSynthesizer voice properties": "列表显示语音合成器声音属性",
    "Speech-to-text recognition": "语音转文本识别",
    "Speech-to-text recognition >": "语音转文本识别 >",
    "OT learning tutorial": "优选论学习教程",
    "Create NoCoda grammar": "创建无尾音语法",
    "Create place assimilation grammar": "创建部位同化语法",
    "Create place assimilation distribution": "创建部位同化分布",
    "Create tongue-root grammar...": "创建舌根语法...",
    "Create metrics grammar...": "创建节律语法...",
    "Create multi-level metrics grammar...": "创建多层级节律语法...",
    "Folder with sound files": "声音文件文件夹",
    "Folder with sound files:": "声音文件文件夹：",
    "Sound file extension": "声音文件拓展名",
    "Sound file extension:": "声音文件拓展名：",
    "Folder with annotation files": "标注文件文件夹",
    "Folder with annotation files:": "标注文件文件夹：",
    "Annotation file extension": "标注文件拓展名",
    "Annotation file extension:": "标注文件拓展名：",
    "You have objects in your list!": "您的列表中还有对象！",
    "Do you still want to quit Praat?": "您确定要退出 Praat 吗？",
    "You have objects in your list, and unsaved scripts or notebooks!": "您的列表中还有对象，并且有未保存的脚本或笔记本！",
    "You have unsaved scripts or notebooks!": "您有未保存的脚本或笔记本！",
    "Do you still want to quit?": "您确定要退出吗？",
    "Read Sound from raw 16-bit Little Endian file...": "从原始 16 位小端文件读取声音...",
    "Read Sound from raw 16-bit Big Endian file...": "从原始 16 位大端文件读取声音...",
    "Read TextGrid from Xwaves...": "从 Xwaves 读取 TextGrid...",
    "Read TextGrid from Xwaves... || Read TextGrid from ESPS label file...": "从 Xwaves 读取 TextGrid... || 从 ESPS 标签文件读取 TextGrid...",
    "Read Sound with adjacent annotation files (Buckeye)...": "从声音与相邻标注文件读取 (Buckeye)...",
    "Read Sound with adjacent annotation files (TIMIT)...": "从声音与相邻标注文件读取 (TIMIT)...",
    "Save as Kay sound file...": "保存为 Kay 声音文件...",
    "Save as Kay sound file... || Write to Kay sound file...": "保存为 Kay 声音文件... || 写入为 Kay 声音文件...",
    "Save as 24-bit WAV file...": "保存为 24 位 WAV 文件...",
    "Save as 32-bit WAV file...": "保存为 32 位 WAV 文件...",
    "Save as highest quality MP3 file...": "保存为最高品质 MP3 文件...",
    "Save as raw 8-bit signed file...": "保存为原始 8 位有符号文件...",
    "Save as raw 8-bit signed file... || Write to raw 8-bit signed file...": "保存为原始 8 位有符号文件... || 写入到原始 8 位有符号文件...",
    "Save as raw 8-bit unsigned file...": "保存为原始 8 位无符号文件...",
    "Save as raw 8-bit unsigned file... || Write to raw 8-bit unsigned file...": "保存为原始 8 位无符号文件... || 写入到原始 8 位无符号文件...",
    "Save as raw 16-bit big-endian file...": "保存为原始 16 位大端文件...",
    "Save as raw 16-bit little-endian file...": "保存为原始 16 位小端文件...",
    "Save as raw 24-bit big-endian file...": "保存为原始 24 位大端文件...",
    "Save as raw 24-bit little-endian file...": "保存为原始 24 位小端文件...",
    "Save as raw 32-bit big-endian file...": "保存为原始 32 位大端文件...",
    "Save as raw 32-bit little-endian file...": "保存为原始 32 位小端文件...",
    "Append to existing sound file...": "追加到现有声音文件...",
    "Get start time of interval...": "获取区间起始时间...",
    "Get start time of interval... || Get starting point... || Get start point...": "获取区间起始时间... || 获取起始点... || 获取起始点...",
    "Get end time of interval...": "获取区间结束时间...",
    "Get end time of interval... || Get end point...": "获取区间结束时间... || 获取结束点...",
    "Get low interval at time...": "获取时间处的低层区间...",
    "Get high interval at time...": "获取时间处的高层区间...",
    "Get interval at time...": "获取时间处的区间...",
    "Get interval edge from time...": "从时间获取区间边缘...",
    "Get interval boundary from time...": "从时间获取区间边界...",
    "Count intervals where...": "计数区间，当...",
    "Get total duration of intervals where...": "获取区间总时长，当...",
    "Get time of point...": "获取点的时间...",
    "Get label of point...": "获取点的标签...",
    "Get low index from time...": "从时间获取低层索引...",
    "Get high index from time...": "从时间获取高层索引...",
    "Get nearest index from time...": "从时间获取最近索引...",
    "Count points where...": "计数点，当...",
    "Include line number": "包含行号",
    "Time decimals": "时间小数位数",
    "Time decimals:": "时间小数位数：",
    "Include tier names": "包含层名称",
    "Include empty intervals": "包含空区间",
}



# 2. Phrase replacements (matched first, from longest to shortest)
PHRASE_REPLACEMENTS = [
    ("without column names", "不带列名"),
    ("with column names", "带列名"),
    ("from VowelEditor", "从元音编辑器"),
    ("as Shepard tone", "为谢泼德音"),
    ("as gammatone", "为伽马通"),
    ("as tone complex", "为复音"),
    ("as pure tone", "为纯音"),
    ("from formula", "通过公式"),
    ("from special sound file", "从特殊声音文件"),
    ("from special annotation file", "从特殊标注文件"),
    ("tab-separated file", "制表符分隔文件"),
    ("comma-separated file", "逗号分隔文件"),
    ("semicolon-separated file", "分号分隔文件"),
    ("whitespace-separated file", "空格分隔文件"),
    ("headerless spreadsheet file", "无表头电子表格文件"),
    ("raw text file", "原始文本文件"),
    ("adjacent annotation files", "相邻标注文件"),
    ("sound files", "声音文件"),
    ("sound file", "声音文件"),
    ("separate channels", "分离通道"),
    ("from directory contents", "从目录内容"),
    ("to existing sound file", "到现有声音文件"),
    ("to clipboard", "到剪贴板"),
    ("to mono", "为单声道"),
    ("to stereo", "为双声道"),
    ("into SoundList", "放入声音列表"),
    ("into SoundSet", "放入声音集合"),
    ("from values", "从数值"),
    ("random points", "随机点"),
    ("random vertices", "随机顶点"),
    ("at cursor", "在光标处"),
    ("at time slice", "在时间片处"),
    ("to Table", "转为表格"),
    ("to Sound", "转为声音"),
    ("to Pitch", "转为音高"),
    ("to Formant", "转为共振峰"),
    ("to Intensity", "转为音强"),
    ("to TextGrid", "转为文本标注"),
    ("to Spectrogram", "转为语图"),
    ("to Matrix", "转为矩阵"),
    ("to PointProcess", "转为点过程"),
    ("to RealTier", "转为实数层"),
    ("to DurationTier", "转为时长层"),
    ("to TableOfReal", "转为实数表"),
    ("to ClassificationTable", "转为分类表"),
    ("to Configuration", "转为配置"),
    ("formant table", "共振峰表"),
    ("style settings", "样式设置"),
    ("style preferences", "样式偏好"),
    ("candidate drawing", "候选绘制"),
    ("spectrogram settings", "语图设置"),
    ("pitch settings", "音高设置"),
    ("pulses settings", "脉冲设置"),
    ("formant settings", "共振峰设置"),
    ("intensity settings", "音强设置"),
    ("convex hull", "凸包"),
    ("vowel marks", "元音标记"),
    ("double pulsing", "双脉冲"),
    ("open phase", "开放相位"),
    ("spectral tilt", "频谱倾斜"),
    ("deep belief", "深度信念"),
    ("place assimilation", "部位同化"),
    ("letter R", "字母 R"),
    ("long sound", "长声音"),
    ("Text-to-speech", "文本转语音"),
    ("Speech-to-text", "语音转文本"),
    ("neural networks", "神经网络"),
    ("neural network", "神经网络"),
    ("Vocal Tract", "声道"),
]

# 3. Word replacements (matched with word boundaries)
WORD_REPLACEMENTS = {
    # Ordinals
    "first": "第一",
    "second": "第二",
    "third": "第三",
    "fourth": "第四",
    "fifth": "第五",
    "sixth": "第六",
    "seventh": "第七",
    "eighth": "第八",
    "ninth": "第九",
    "tenth": "第十",

    # UI Nouns/Adjectives
    "visible": "可见",
    "part": "部分",
    "selection": "选择",
    "cursor": "光标",
    "begin": "起点",
    "start": "起点",
    "end": "终点",
    "length": "长度",
    "width": "宽度",
    "height": "高度",
    "left": "左",
    "right": "右",
    "top": "上",
    "bottom": "下",
    "time": "时间",
    "frequency": "频率",

    # Verbs / Actions
    "Create": "创建",
    "To": "转为",
    "Draw": "绘制",
    "Get": "获取",
    "Set": "设置",
    "Extract": "提取",
    "Edit": "编辑",
    "Remove": "移除",
    "Add": "添加",
    "Analyse": "分析",
    "Analyze": "分析",
    "Synthesize": "合成",
    "Query": "查询",
    "Read": "读取",
    "Write": "写入",
    "Save": "保存",
    "Append": "追加",
    "Combine": "合并",
    "Convert": "转换",
    "List": "列表",
    "Play": "播放",
    "Show": "显示",
    "Check": "检查",
    "Count": "计数",
    "Find": "寻找",
    "Reverse": "反转",
    "Shift": "移动",
    "Align": "对齐",
    "Autocorrelate": "自相关",
    "convolve": "卷积",
    "Convolve": "卷积",
    "Record": "录制",
    "Open": "打开",
    
    # Nouns (Linguistics / Scientific)
    "Cochleagram": "耳蜗图",
    "Spectrogram": "声学谱图",
    "Spectrum": "频谱",
    "Sound": "声音",
    "Pitch": "音高",
    "Formant": "共振峰",
    "Intensity": "音强",
    "TextGrid": "文本标注",
    "Duration": "时长",
    "Table": "表格",
    "Matrix": "矩阵",
    "Formula": "公式",
    "File": "文件",
    "Directory": "目录",
    "Folder": "文件夹",
    "Interval": "区间",
    "Point": "点",
    "Tier": "层",
    "Grid": "网格",
    "PointProcess": "点过程",
    "Harmonicity": "谐噪比",
    "Excitation": "激励",
    "VocalTract": "声道",
    "Articulation": "发音",
    "Speaker": "说话人",
    "SpeechRecognizer": "语音识别器",
    "SpeechSynthesizer": "语音合成器",
    "Word": "单词",
    "Permutation": "置换",
    "Polynomial": "多项式",
    "LegendreSeries": "勒让德级数",
    "ChebyshevSeries": "切比雪夫级数",
    "MSpline": "M样条",
    "ISpline": "I样条",
    "Confusion": "混淆矩阵",
    "Correlation": "相关",
    "Covariance": "协方差",
    "CrossCorrelationTable": "互相关表",
    "DataModeler": "数据建模器",
    "MixingMatrix": "混合矩阵",
    "Polygon": "多边形",
    "Photo": "照片",
    "EditCostsTable": "编辑代价表",
    "Network": "网络",
    "FormantGrid": "共振峰网格",
    "FormantTier": "共振峰层",
    "IntensityTier": "音强层",
    "PitchTier": "音高层",
    "RealTier": "实数层",
    "DurationTier": "时长层",
    "TableOfReal": "实数表",
    
    # Plural nouns
    "Tiers": "层",
    "Tables": "表格",
    "Generics": "通用",
    "grammars": "语法",
    "networks": "网络",
    
    # Sub-words / Modifiers
    "help": "帮助",
    "settings": "设置",
    "preferences": "偏好设置",
    "tutorial": "教程",
    "mono": "单声道",
    "stereo": "双声道",
    "pure": "纯",
    "tone": "音",
    "complex": "复",
    "average": "平均",
    "axes": "坐标轴",
    "back": "返回",
    "bar": "条形",
    "plot": "图",
    "plots": "图",
    "style": "样式",
    "calculator": "计算器",
    "redo": "重做",
    "undo": "撤销",
    "history": "历史",
    "updates": "更新",
    "circular": "循环",
    "clear": "清除",
    "clone": "克隆",
    "domain": "域",
    "collapse": "折叠",
    "collect": "收集",
    "columns": "列",
    "column": "列",
    "rows": "行",
    "row": "行",
    "centre": "中心化",
    "gravity": "重心",
    "smoothing": "平滑",
    "ceiling": "上限",
    "gender": "性别",
    "compare": "比较",
    "compress": "压缩",
    "trend": "趋势",
    "line": "线",
    "overlap": "重叠",
    "conflate": "合并",
    "conjugate": "共轭",
    "constraint": "约束",
    "channel": "通道",
    "ranges": "范围",
    "difference": "差异",
    "differences": "差异",
    "label": "标签",
    "labels": "标签",
    "voiced": "浊音",
    "frames": "帧",
    "frame": "帧",
    "gain": "增益",
    "moments": "矩",
    "parameter": "参数",
    "slope": "斜率",
    "statistics": "统计",
    "stats": "统计",
    "discretization": "离散化",
    "value": "值",
    "values": "值",
    "lexicon": "词典",
    "roots": "根",
    "scatter": "散点",
    "monic": "首一",
    "rotations": "旋转",
    "reflections": "反射",
    "singular": "奇异",
    "stylize": "样式化",
    "tableau": "表格",
    "viewport": "视口",
    "weight": "权重",
    "states": "状态",
    "symbols": "符号",
    "trajectory": "轨迹",
    "acoustic": "声学",
    "amplitude": "振幅",
    "aspiration": "吸气",
    "bandwidth": "带宽",
    "breathiness": "气音",
    "collision": "碰撞",
    "phase": "相位",
    "connection": "连接",
    "flutter": "抖动",
    "frication": "摩擦",
    "bypass": "旁路",
    "voicing": "浊音化",
    "vertical": "垂直",
    "mixing": "混合",
    "from": "从",
    "with": "与",
    "special": "特殊",
    "adjacent": "相邻",
    "separate": "分离",
    "channels": "通道",
    "speech": "语音",
    "recognition": "识别",
    "synthesis": "合成",
    "Symmetric": "对称",
    "Feedforward": "前馈",
    "Articulatory": "发音",
    "periodicity": "周期性",
    "spectrum": "频谱",
    "Manipulate": "操作",
    "Filter": "滤波",
}

# Sort WORD_REPLACEMENTS keys by length descending to match longer words first
WORD_REPLACEMENTS_SORTED = sorted(WORD_REPLACEMENTS.items(), key=lambda x: len(x[0]), reverse=True)

def clean_spaces(text):
    # Remove spaces between Chinese characters
    text = re.sub(r'(?<=[\u4e00-\u9fff])\s+(?=[\u4e00-\u9fff])', '', text)
    # Remove spaces between Chinese characters and punctuation
    text = re.sub(r'(?<=[\u4e00-\u9fff])\s+(?=[^\w\s])', '', text)
    text = re.sub(r'(?<=[^\w\s])\s+(?=[\u4e00-\u9fff])', '', text)
    # Remove double spaces
    text = re.sub(r'\s+', ' ', text).strip()
    return text

def translate_single_part(part):
    # Strip dots (ellipsis) and restore later
    has_dots = part.endswith("...")
    if has_dots:
        part = part[:-3]

    if part in EXACT_MAP:
        res = EXACT_MAP[part]
        if has_dots:
            res += "..."
        return clean_spaces(res)

    # Apply phrase replacements
    for eng_phrase, chi_phrase in PHRASE_REPLACEMENTS:
        part = re.sub(rf'\b{re.escape(eng_phrase)}\b', chi_phrase, part, flags=re.IGNORECASE)

    # Apply word replacements (case-insensitive, whole-word matching)
    for eng_word, chi_word in WORD_REPLACEMENTS_SORTED:
        part = re.sub(rf'\b{re.escape(eng_word)}\b', chi_word, part, flags=re.IGNORECASE)

    if has_dots:
        part += "..."

    return clean_spaces(part)

def translate_text(text):
    if text in EXACT_MAP:
        return EXACT_MAP[text]

    # Handle split delimiters like " || ", " -- ", " - ", "::"
    delimiters = [" || ", " -- ", " - ", "::"]
    for delim in delimiters:
        if delim in text:
            parts = text.split(delim)
            translated_parts = [translate_text(p) for p in parts]
            return delim.join(translated_parts)

    # Handle surrounding double hyphens like "-- Pitch --"
    match = re.match(r'^(--\s*)(.*?)(\s*--)$', text)
    if match:
        prefix, inner, suffix = match.groups()
        return prefix + translate_text(inner) + suffix

    return translate_single_part(text)

def escape_for_tsv(s):
    return s.replace("\t", "\\t").replace("\n", "\\n").replace("\r", "\\r")

def analyze_retained_and_review(eng, chi):
    retained = []
    
    # Check for placeholder
    if "%" in eng:
        retained.append("占位符(%)")
    # Check for brackets
    if any(c in eng for c in "()[]{}"):
        retained.append("括号")
    # Check for colons
    if ":" in eng:
        retained.append("冒号")
    # Check for quotes
    if any(c in eng for c in "\"'`"):
        retained.append("引号")
    # Check for ellipsis
    if "..." in eng:
        retained.append("省略号")
    # Check for newlines
    if "\n" in eng or "\r" in eng:
        retained.append("换行")
    # Check for numbers
    if any(c.isdigit() for c in eng):
        retained.append("数字")
        
    # Check for unit preservation (Hz, dB, s, Pa, mel, Bark)
    units_found = []
    for u in ["Hz", "dB", "mel", "Bark", "Pa", "seconds"]:
        if re.search(rf"\b{u}\b", eng, re.IGNORECASE):
            units_found.append(u)
    if units_found:
        retained.append(f"单位({','.join(units_found)})")
    
    retained_desc = ",".join(retained) if retained else "无"
    
    # Needs review rules:
    # If the original string contains dangerous words that require context
    dangerous_words = ["to", "with", "from", "point", "line", "value"]
    has_dangerous = any(re.search(rf"\b{dw}\b", eng, re.IGNORECASE) for dw in dangerous_words)
    
    if has_dangerous:
        needs_review = "是 (高风险:含上下文敏感词)"
    else:
        # Check if translation still contains English words longer than 2 chars
        is_clean_chi = True
        for word in re.findall(r"[a-zA-Z]{3,}", chi):
            if word not in ["Hz", "dB", "mel", "Bark", "Pa", "TextGrid", "Sound", "Pitch", "Formant", "Intensity", "Spectrum", "Harmonicity"]:
                is_clean_chi = False
                break
        if not is_clean_chi:
            needs_review = "是 (混合英文)"
        else:
            needs_review = "是"
        
    return retained_desc, needs_review

def main():
    translations = {}
    
    # 1. Unconditionally add all EXACT_MAP items first
    for eng, chi in EXACT_MAP.items():
        translations[eng] = chi

    # 2. Safely add clean candidate suggestions that do not contain dangerous or mixed-language text
    auto_added = 0
    if os.path.exists(INPUT_FILE):
        with open(INPUT_FILE, "r", encoding="utf-8") as f:
            lines = f.read().splitlines()
        
        for line in lines:
            line = line.strip()
            if not line:
                continue
            if line in translations:
                continue
            
            translated = translate_text(line)
            if translated != line:
                retained, review = analyze_retained_and_review(line, translated)
                if review == "是":
                    translations[line] = translated
                    auto_added += 1
    print(f"Dynamically loaded {auto_added} clean auto-translated candidates.")

    # For every key containing " || ", also add the individual split parts to translations
    # so that dynamically split parts are translated correctly
    extra_translations = {}
    for eng, chi in translations.items():
        if " || " in eng and " || " in chi:
            eng_parts = eng.split(" || ")
            chi_parts = chi.split(" || ")
            if len(eng_parts) == len(chi_parts):
                for ep, cp in zip(eng_parts, chi_parts):
                    ep_strip = ep.strip()
                    cp_strip = cp.strip()
                    if ep_strip and cp_strip and ep_strip not in translations:
                        extra_translations[ep_strip] = cp_strip
    translations.update(extra_translations)

    # Write debug file for verification
    with open(DEBUG_OUTPUT, "w", encoding="utf-8") as df:
        for eng, chi in sorted(translations.items()):
            df.write(f"{eng} ===> {chi}\n")
    print(f"Logged {len(translations)} active compiled translations to {DEBUG_OUTPUT}")

    # Generate candidate suggestions for the rest of ui_strings.txt
    candidates_count = 0
    if os.path.exists(INPUT_FILE):
        with open(INPUT_FILE, "r", encoding="utf-8") as f:
            lines = f.read().splitlines()
        
        with open(CANDIDATE_OUTPUT, "w", encoding="utf-8") as cand_file:
            # TSV Header
            cand_file.write("英文原文\t中文译文\t保留项说明\t是否需要人工复核\n")
            
            for line in lines:
                line = line.strip()
                if not line:
                    continue
                # If it's already exactly mapped, we don't need to review it as a candidate
                if line in translations:
                    continue
                
                translated = translate_text(line)
                if translated != line:
                    retained, review = analyze_retained_and_review(line, translated)
                    cand_file.write(f"{escape_for_tsv(line)}\t{escape_for_tsv(translated)}\t{retained}\t{review}\n")
                    candidates_count += 1
                    
        print(f"Logged {candidates_count} candidate suggestions to {CANDIDATE_OUTPUT}")

    # Generate the praat_translate.cpp code
    cpp_lines = [
        '#include "praat_translate.h"',
        '#include <unordered_map>',
        '#include <string>',
        '',
        'static const std::unordered_map<std::u32string, std::u32string> g_translation_map = {'
    ]

    for eng, chi in sorted(translations.items()):
        # Escape string for C++ and convert Chinese to unicode escape sequences
        eng_esc = to_cpp_unicode_literal(eng)
        chi_esc = to_cpp_unicode_literal(chi)
        cpp_lines.append(f'\t{{ U"{eng_esc}", U"{chi_esc}" }},')

    if len(translations) > 0:
        cpp_lines[-1] = cpp_lines[-1][:-1]

    cpp_lines.extend([
        '};',
        '',
        '#include <mutex>',
        'static std::unordered_map<std::u32string, std::u32string> g_dynamic_cache;',
        'static std::mutex g_cache_mutex;',
        '',
        'const char32* praat_translate (const char32* text) {',
        '\tif (!text) {',
        '\t\treturn nullptr;',
        '\t}',
        '\t',
        '\tstd::u32string key(text);',
        '\tauto it = g_translation_map.find(key);',
        '\tif (it != g_translation_map.end()) {',
        '\t\treturn it->second.c_str();',
        '\t}',
        '\t',
        '\t{',
        '\t\tstd::lock_guard<std::mutex> lock(g_cache_mutex);',
        '\t\tauto it_cache = g_dynamic_cache.find(key);',
        '\t\tif (it_cache != g_dynamic_cache.end()) {',
        '\t\t\treturn it_cache->second.c_str();',
        '\t\t}',
        '\t}',
        '\t',
        '\tsize_t leading_spaces = 0;',
        '\twhile (leading_spaces < key.length() && key[leading_spaces] == U\' \') {',
        '\t\tleading_spaces++;',
        '\t}',
        '\t',
        '\tif (leading_spaces > 0) {',
        '\t\tstd::u32string stripped_key = key.substr(leading_spaces);',
        '\t\tauto it_stripped = g_translation_map.find(stripped_key);',
        '\t\tif (it_stripped != g_translation_map.end()) {',
        '\t\t\tstd::u32string translated = key.substr(0, leading_spaces) + it_stripped->second;',
        '\t\t\tstd::lock_guard<std::mutex> lock(g_cache_mutex);',
        '\t\t\tg_dynamic_cache[key] = translated;',
        '\t\t\treturn g_dynamic_cache[key].c_str();',
        '\t\t}',
        '\t}',
        '\t',
        '\treturn text;',
        '}',
        ''
    ])

    with open(OUTPUT_CPP, "w", encoding="utf-8") as cpp_file:
        cpp_file.write("\n".join(cpp_lines))
    print(f"Generated {OUTPUT_CPP} successfully!")

if __name__ == "__main__":
    main()

