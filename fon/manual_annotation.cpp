/* manual_annotation.cpp
 *
 * Copyright (C) 1992-2011,2014-2017,2019,2021-2023,2025 Paul Boersma
 *
 * This code is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * This code is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this work. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ManPagesM.h"

void manual_annotation_init (ManPages me);
void manual_annotation_init (ManPages me) {

MAN_BEGIN (U"Create TextGrid...", U"ppgb", 20101228) // 2025
INTRO (U"从头创建一个新的 @@TextGrid|TextGrid（标注网格）@。")
ENTRY (U"设置")
TERM (U"##Start time (s)#（开始时间，秒）")
DEFINITION (U"起始时间，通常为 0 秒。")
TERM (U"##End time (s)#（结束时间，秒）")
DEFINITION (U"以秒为单位的结束时间，通常是音频的时长。")
TERM (U"##Tier names#（层名称）")
DEFINITION (U"您想创建的层的名称列表，以空格分隔。")
TERM (U"##Point tiers#（点层）")
DEFINITION (U"您想设为%%点层（point tiers）%的层级名称列表；"
	"其余的层将为%%区间层（interval tiers）%。"
	"如果您不想创建点层，可以将此设置留空。")
MAN_END

MAN_BEGIN (U"PointProcess: To TextGrid...", U"ppgb", 19980113) // 2025
INTRO (U"从每个选定的 @@PointProcess|PointProcess（点过程）@ 对象创建一个空的 @@TextGrid|TextGrid@。")
NORMAL (U"在此操作中，PointProcess 对象唯一被使用的信息是其起始和结束时间。")
ENTRY (U"设置")
TERM (U"##Tier names#（层名称）")
DEFINITION (U"您想创建的层的名称列表，以空格分隔。")
TERM (U"##Point tiers#（点层）")
DEFINITION (U"您想设为%%点层（point tiers）%的层级名称列表；"
	"其余的层将为%%区间层（interval tiers）%。"
	"如果您不想创建点层，可以将此设置留空。")
ENTRY (U"示例")
NORMAL (U"如果 ##Tier names# 为 \"a b c\"，且 ##Point tiers# 为 \"b\"，"
	"则生成的 TextGrid 对象将包含一个名为 \"a\" 的区间层，"
	"一个名为 \"b\" 的点层，以及另一个名为 \"c\" 的区间层。")
MAN_END

MAN_BEGIN (U"PointProcess: To TextGrid (vuv)...", U"ppgb", 19980210)
INTRO (U"从每个选定的 @@PointProcess|PointProcess（点过程）@ 对象创建一个包含浊音/清音（voiced/unvoiced）信息的 @@TextGrid|TextGrid@。")
ENTRY (U"设置")
TERM (U"##Maximum period (s)#（最大周期，秒）")
DEFINITION (U"将被视为较大浊音区间一部分的最大间隔。")
TERM (U"##Mean period (s)#（平均周期，秒）")
DEFINITION (U"该值的一半将被视为浊音区间超出其起始点和终点的延伸量。##Mean period# 应小于 "
	"##Maximum period#，否则您可能会得到负时长的区间。")
ENTRY (U"示例")
NORMAL (U"如果 ##Maximum period# 为 0.02 秒，且 ##Mean period# 为 0.01 秒，"
	"点过程时长为 0.1 秒，脉冲点分别位于 20、28、39、61 和 72 毫秒处，"
	"则生成的 TextGrid 对象将包含一个区间层，"
	"其中 \"U\"（清音）区间位于 [0 ms, 15 ms]、[44 ms, 56 ms] 和 [77 ms, 100 ms]，"
	"而 \"V\"（浊音）区间位于 [15 ms, 44 ms] 和 [56 ms, 77 ms]。")
MAN_END

MAN_BEGIN (U"PointProcess: Up to TextGrid...", U"ppgb", 20101230)
INTRO (U"将每个选定的 @@PointProcess|PointProcess（点过程）@ 提升为一个包含单个文本层的 @@TextGrid|TextGrid@。")
ENTRY (U"设置")
TERM (U"##Text#（文本）")
DEFINITION (U"将放置在每个点中的文本。")
ENTRY (U"行为")
NORMAL (U"所有点的时间位置以及时间域都会被直接复制。"
	"每个点中的文本信息都将是相同的。")
MAN_END

MAN_BEGIN (U"Sound: To TextGrid...", U"ppgb", 19980730)  // 2025
INTRO (U"创建一个没有任何标签的 @@TextGrid|TextGrid@，复制所选 @@Sound|Sound（声音）@ 对象的时间域。")
ENTRY (U"设置")
TERM (U"%%Tier names#（层名称）")
DEFINITION (U"您想创建的层的名称列表，以空格分隔。")
TERM (U"%%Point tiers#（点层）")
DEFINITION (U"您想设为%%点层（point tiers）%的层级名称列表；"
	"其余的层将为%%区间层（interval tiers）%。"
	"如果您不想创建点层，可以将此设置留空。")
ENTRY (U"示例")
NORMAL (U"如果 ##Tier names# 为 \"a b c\"，且 ##Point tiers# 为 \"b\"，"
	"则生成的 TextGrid 对象将包含一个名为 \"a\" 的区间层，"
	"一个名为 \"b\" 的点层，以及另一个名为 \"c\" 的区间层。")
MAN_END

MAN_BEGIN (U"SpellingChecker", U"ppgb", 20190616)
INTRO (U"Praat 的 @@types of objects|对象类型@ 之一。用于检查文本和 @@TextGrid|TextGrid@ 对象中的拼写。")
ENTRY (U"1. 如何创建 SpellingChecker 对象")
NORMAL (U"您通常使用 #Open 菜单中的 @@Read from file...|从文件读取...@ 命令来载入 SpellingChecker。")
ENTRY (U"2. 如何检查 @TextGrid 的拼写")
NORMAL (U"SpellingChecker 对象可用于拼写检查。为了 "
	"检查 @@TextGrid|TextGrid@ 对象中的拼写，您需要同时选中该 TextGrid 和 SpellingChecker 对象，然后点击 ##View & Edit# 在编辑器窗口中查看。在大多数情况下，您还需要 "
	"在点击 ##View & Edit# 之前选中 @@Sound|Sound@ 或 @@LongSound|LongSound@ 对象，以便在编辑器中同时显示（和播放）声音。因此，您通常需要选择三个对象并点击 ##View & Edit#。 "
	"然后，在编辑器中，您就可以检查拼写 "
	"（#Spell 菜单中的 ##Check spelling in tier# 和 ##Check spelling in interval# 命令）。")
ENTRY (U"3. 如何首次创建 SpellingChecker 对象")
NORMAL (U"如果您是用于拼写检查的单词列表的维护者，您会希望 "
	"将此列表转换为 SpellingChecker 对象，以便分发给您的语料库转录人员。")
NORMAL (U"第一步是根据 @@WordList|WordList@ 帮助页面上的描述，从您的文本文件创建一个 @@WordList|WordList@ 对象。 "
	"然后您只需点击 ##To SpellingChecker#。接着会出现一个名为 ##View & Edit...# 的按钮。 "
	"该命令允许您设置 SpellingChecker 对象的以下属性：")
/*TERM (U"##Check matching parentheses")
DEFINITION (U"determines whether it is considered a spelling error if parentheses do not match, as in the string \"Hi) there\".")*/
TERM (U"##Allow all parenthesized#（允许所有括号内容）")
DEFINITION (U"此标记决定在拼写检查中是否忽略括号之间的文本。 "
	"这将允许转录人员标记外语发音，这些词汇在词典中是找不到的。")
TERM (U"##Separating characters#（分隔符字符）")
DEFINITION (U"确定分隔单词的字符集（空格字符除外）。 "
	"标准是 \".,;:()\"。如果类似于 \"error-prone\" 的字符串应被视为两个独立的单词， "
	"您可能需要将其更改为 \".,;:()-\"。 "
	"对于荷兰语口语语料库（CGN），连字符不是分隔符，因为诸如 \"mee-eter\" 之类的词应作为一个整体进行检查。 "
	"如果类似于 \"Mary's\" 的字符串应被视为两个独立的单词，请包含单引号。")
/*TERM (U"##Forbidden strings")
DEFINITION (U"this will mainly contain characters that are not allowed in your corpus. For the CGN, this is \": ; \\\" \".")*/
TERM (U"##Allow all names#（允许所有名称）")
DEFINITION (U"确定是否允许所有以大写字母开头的单词。对于 CGN，此项为开启， "
	"因为词库中不包含很多名称。")
TERM (U"##Name prefixes#（名称前缀）")
DEFINITION (U"一个以空格分隔的列表，确定哪些小字符组可以出现在名称之前。对于 CGN， "
	"这是 \"'s- d' l'\"，因为像 %%'s-Gravenhage%、%%d'Ancona% 和 %%l'H\\o^pital% 这样的名称应该被拼写检查器忽略。")
TERM (U"##Allow all words containing#（允许包含以下内容的所有单词）")
DEFINITION (U"一个以空格分隔的字符串列表，即使单词不在词库中，也使其正确。 "
	"对于 CGN，这是 \"* xxx\"，因为像 %%keuje*d% 和 %%verxxxing% 这样的单词应该被拼写检查器忽略。")
TERM (U"##Allow all words starting with#（允许以以下内容开头的所有单词）")
DEFINITION (U"一个以空格分隔的前缀列表，即使单词不在词库中，也使其正确。 "
	"对于 CGN，这为空。")
TERM (U"##Allow all words ending in#（允许以以下内容结尾的所有单词）")
DEFINITION (U"一个以空格分隔的后缀列表，即使单词不在词库中，也使其正确。 "
	"对于 CGN，这是 \"-\"，因为 %%verzekerings- en bankwezen% 中的第一个词应该被拼写检查器忽略。")
MAN_END

MAN_BEGIN (U"TextGrid", U"ppgb", 20110128 2025)
INTRO (U"Praat 中的 @@types of objects|对象类型@ 之一，用于%标注（分段和打标签）。"
	"有关教程信息，请参见 @@Intro 7. Annotation|语音标注简介@。")
ENTRY (U"描述")
NORMAL (U"一个 #TextGrid 对象包含若干个%层（tiers）。层有两种类型："
	"一个%%区间层（interval tier）%是首尾相连的已标注区间的序列，区间之间有%边界（boundaries）。"
	"一个%%点层（point tier）%是已标注时间点的序列。")
ENTRY (U"如何创建 TextGrid")
TERM (U"从头创建：")
LIST_ITEM (U"@@Sound: To TextGrid...@（从 Sound 声音对象复制时间域）")
LIST_ITEM (U"@@LongSound: To TextGrid...@（从 LongSound 长音频对象复制时间域）")
LIST_ITEM (U"@@PointProcess: To TextGrid...@（从 PointProcess 点过程对象复制时间域）")
LIST_ITEM (U"@@PointProcess: To TextGrid (vuv)...@（标注浊音和清音区间）")
LIST_ITEM (U"@@Create TextGrid...@")
TERM (U"通过合并现有的 TextGrid 对象：")
LIST_ITEM (U"@@TextGrids: Merge...@")
ENTRY (U"如何编辑 TextGrid")
NORMAL (U"您可以单独选中一个 TextGrid，或者同时选中 TextGrid 与 @@Sound|Sound@ 或 @@LongSound|LongSound@，然后点击 ##View & Edit#。 "
	"屏幕上会出现一个 @@TextGridEditor|TextGrid 图像编辑器@，其中包含该 TextGrid "
	"以及声音或长音频的拷贝。")
ENTRY (U"如何绘制 TextGrid")
TERM (U"您可以使用以下命令将 TextGrid 绘制到 @@Picture window|图像窗口@：")
LIST_ITEM (U"##TextGrid: Draw...")
LIST_ITEM (U"##TextGrid & Sound: Draw...")
LIST_ITEM (U"##TextGrid & Pitch: Draw...")
LIST_ITEM (U"##TextGrid & Pitch: Draw separately...")
MAN_END

MAN_BEGIN (U"TextGrid: Count labels...", U"ppgb", 20140421)
INTRO (U"查询选定的 @@TextGrid|TextGrid@ 对象中指定的层包含多少个指定的标签。")
ENTRY (U"设置")
TERM (U"##Tier number#（层编号）")
DEFINITION (U"您想查询的层的编号（1, 2, 3...）。")
TERM (U"##Label text#（标签文本）")
DEFINITION (U"您想计数的标签文本内容。")
ENTRY (U"行为")
NORMAL (U"层级 ##Tier number# 中包含 %%Label text% 标签的区间或点的数量 "
	"将被写入到 @@Info window|信息窗口@ 中。如果指定的层不存在，则数量为 0。")
ENTRY (U"脚本编写")
NORMAL (U"您可以使用此命令将数量赋值给脚本变量：")
CODE (U"selectObject: \"TextGrid hallo\"")
CODE (U"number_of_a = Count labels: 1, \"a\"")
NORMAL (U"在此情况下，结果数值将不会写入到信息窗口中。")
MAN_END
 
MAN_BEGIN (U"TextGrids: Merge", U"ppgb", 20101230)
INTRO (U"一个过时的命令，用于将所有选定的 @@TextGrid|TextGrid@ 对象合并为一个新的 @@TextGrid|TextGrid@。")
NORMAL (U"这与将 “Equalize domains” 设置为 false 的 @@TextGrids: Merge...@ 相同。")
MAN_END

MAN_BEGIN (U"TextGrids: Merge...", U"ppgb", 2025)
INTRO (U"将所有选定的 @@TextGrid|TextGrid@ 对象合并为一个新的 @@TextGrid|TextGrid@。")
NORMAL (U"合并后的 TextGrid 的时间域将是组成它的各 TextGrid 时间域的并集。")
TERM (U"##Equalize time domains#（对齐时间域，默认：开启）")
DEFINITION (U"如果开启，每个层级的时间域将被调整为与合并后生成的 TextGrid 的时间域相同。 "
	"如果这导致区间层级的结束时间发生改变，则会在该层级的原始结束时间与新结束时间之间添加一个新的空区间（在层级开始处也有可能发生类似的插入，但在实践中这非常罕见，因为通常所有层级都从 0 秒开始）。")
MAN_END

MAN_BEGIN (U"TextGridEditor", U"ppgb", 20210228)
INTRO (U"Praat 中的 @@Editors|编辑器@ 之一，用于编辑 @@TextGrid|TextGrid@（标注网格/文本标注对象）对象。")
NORMAL (U"您在启动此编辑器时，可以同时选中 TextGrid 对象以及 @@Sound|Sound@（声音对象）或 @@LongSound|LongSound@（长音频对象）对象，然后再点击 ##View & Edit#。此时，声音波形或长音频将显示在窗口的上半部分，标注层级显示在下半部分。窗口最上方有一个文本输入框，显示当前选中区间或点（即光标当前所在位置的区间或点）的文本内容。所有层级默认都是可见的，如果您不缩放窗口，所有的边界、时间点和标注文本也都清晰可见。您在 TextGridEditor 中可以进行大部分在 @@SoundEditor|SoundEditor@ 或 @@LongSoundEditor|LongSoundEditor@ 中可用的操作。")
ENTRY (U"定位光标与设置选区")
NORMAL (U"若要定位光标，请在声音（#Sound）、边界、时间点或区间内部@@Click|单击@。")
NORMAL (U"若要选择特定时间段，请使用 @@time selection|时间选区@ 操作；如果您是在某个层级内拖动鼠标进行选择，选区边界会自动吸附到最近的边界线或时间点上。")
ENTRY (U"创建新的区间、边界、点或层级")
NORMAL (U"若要创建新区间，请在区间层级（interval tier）中创建一个新的边界线。")
NORMAL (U"若要在层级中创建新的边界线或时间点，请点击该层级上光标对应的小圆圈，或者也可以通过 Boundary/Point（边界/点）菜单中的命令在光标时刻插入边界。这既可以在当前选中的层级上操作（快捷键：Enter），也可以在任意层级上操作（快捷键：@@Keyboard shortcuts|Command-F1@ 到 @@Keyboard shortcuts|Command-F9@）。区间被分割时，原来区间里的文字会根据文字光标在上方文本框中的位置，分别划分到分割后的两个新区间内。")
NORMAL (U"若要创建新层级，请在 Tier（层级）菜单中选择 ##Add interval tier#（添加区间层）或 ##Add point tier#（添加点层）。")
ENTRY (U"播放整个区间或其中一部分")
NORMAL (U"与许多其他编辑器一样，您可以通过点击绘制区域周围的任何矩形来播放一段声音。")
NORMAL (U"若要播放区间层中的某个区间，请先在区间内部点击以选中它。被选中的区间在可见区域内会以黄色高亮显示。此时光标会自动定位在区间的起点，时间选区也会刚好包容该区间。这代表您可以直接按 Tab 键来播放这个选中的区间。如果在播放声音时再次按下 Tab 键，声音播放会停止，并且光标会移动到播放中断的时刻。这可以帮助您将较长的句子分割为一个个小片段，方便您听写记录。")
NORMAL (U"Tab 键将播放选中的区间。")
ENTRY (U"编辑区间或点中的文本")
NORMAL (U"若要编辑区间或时间点的标注文本：")
LIST_ITEM (U"1. 单击区间或点以选中它。该区间或点当前的文本内容将显示在顶部的文本输入框中。")
LIST_ITEM (U"2. 直接输入文本，并使用鼠标和方向键在文本输入框中导航。您输入的所有内容都将立即显示在顶部文本框以及选中的区间或时间点中。")
NORMAL (U"您可以使用在 Praat 其他地方可用的所有 @@Special symbols|特殊符号@，包括数学符号、希腊字母、中文字符、上标以及国际音标（IPA）等。")
ENTRY (U"选择层级")
NORMAL (U"若要选中某个层级，只需在层级区域内的任意空白位置点击一下。该层级的编号和名称将变为红色，且其左侧会显示一个指向它的手指符号（☞）。")
ENTRY (U"选择边界或点")
NORMAL (U"若要在区间层级上选中一条边界线，请在边界线附近或右侧相邻的区间内点击；被选中的边界线会变为红色。该边界线右侧区间的文本将显示在顶部的文本输入框中。")
NORMAL (U"若要在点层级上选中一个时间点，请在其附近点击；选中的点会变为红色。该点的文本会显示在顶部的文本输入框中。")
ENTRY (U"移动边界或点")
NORMAL (U"若要将边界或点移动 to 另一个时间位置，请使用鼠标@@Drag|拖动@它。")
NORMAL (U"若要将多个层级上处于同一时刻的所有边界线和时间点同步移动到另一个位置，请按住 Shift 键并 @@Shift-drag|拖动@ 它们。")
NORMAL (U"若要把边界或点精准移动到另一个层级上某条边界线或时间点的时刻，请将它们拖动到该层级对应位置附近，它们会自动吸附对齐。")
NORMAL (U"若要把边界或点精准移动到光标所在的时刻，请将它们拖动到光标位置附近，它们会自动吸附到光标上。")
ENTRY (U"移除边界、点或层级")
NORMAL (U"若要移除选中的边界线，请在 Boundary（边界）菜单中选择 #Remove（移除）。这会把原本由该边界线隔开的两个区间合并为一个新区间；新区间的内容将自动拼接在一起（如果两个区间的原文本完全相同，合并后则只保留一个，不会重复拼接）。")
NORMAL (U"若要移除选中的时间点，请在 Point（点）菜单中选择 #Remove（移除）。")
NORMAL (U"若要移除选中的层级，请在 Tier（层级）菜单中选择 ##Remove entire tier#（移除整个层级）。")
/*"To rename a selected tier, choose 'Rename...' from the 'Tier' menu. "*/
/*"To remove all the boundaries and labels in a selected tier, "
"   choose 'Clear entire tier' from the 'Tier' menu. "*/
ENTRY (U"Extracting a part of the sound")
NORMAL (U"若要将 Sound 或 LongSound 中选定的音频部分作为独立的 Sound 对象复制到对象列表（@@List of Objects@）中，请在 File（文件）菜单中选择 ##Extract sound selection#（提取所选声音）。您可以选择新生成的 Sound 对象的时间轴是保持选区的原始时刻，还是将其起点重置为 0 秒。")
NORMAL (U"如果您正在查看 LongSound 对象，则可以直接使用 File 菜单下的命令将选定部分的音频保存为 16 位的标准声音文件（支持 AIFF、AIFC、WAV、NeXT/Sun、NIST 等格式）。")
ENTRY (U"便捷操作")
NORMAL (U"若要直接将 TextGrid 对象保存为文本文件而无需返回对象窗口：请在编辑器窗口的 File 菜单中选择 ##Save TextGrid as text file...#（保存 TextGrid 为文本文件...）。")
ENTRY (U"搜索功能")
NORMAL (U"Search（搜索）菜单中提供了 #Find（查找，快捷键：@@Keyboard shortcuts|Command-F@）命令。您可以通过它输入特定的查找文本，编辑器会从当前选中区间的当前字符开始，在当前选中的层级中向后搜索第一个匹配项。使用 ##Find again#（再次查找，快捷键：@@Keyboard shortcuts|Command-G@）则可以继续查找下一个匹配项。")
ENTRY (U"拼写检查")
NORMAL (U"您可以在启动编辑器时同时选中 TextGrid 对象、(Long)Sound 对象以及一个 @@SpellingChecker|SpellingChecker@（拼写检查器）对象来使用拼写检查功能：选中这三个对象并点击 ##View & Edit# 启动编辑器后，Spell（拼写）菜单中将出现 ##Check spelling in tier#（检查层级拼写，快捷键：@@Keyboard shortcuts|Command-N@）和 ##Check spelling in interval#（检查区间拼写）命令，它们会在层级或区间中搜索下一个不在词典中的词汇。")
MAN_END

MAN_BEGIN (U"WordList", U"ppgb", 20190616)
INTRO (U"Praat 中的 @@types of objects|对象类型@ 之一。 "
	"WordList 类的对象以系统无关的格式包含一个排序的字符串列表。 "
	"WordList 对象在转换为 @@SpellingChecker|SpellingChecker（拼写检查器）@ 对象后，可用于拼写检查。")
ENTRY (U"1. 如何创建 WordList 对象")
NORMAL (U"您通常会通过读取二进制 WordList file 来创建 WordList 对象。 "
	"您将使用 #Open 菜单中的通用 @@Read from file...|从文件读取...@ 命令。")
NORMAL (U"如何创建此类文件，请参阅下面的第 3 点。")
ENTRY (U"2. 您可以使用 WordList 对象做什么")
NORMAL (U"WordList 的主要功能是能够告诉您它是否包含某个特定的字符串。 "
	"如果您选中一个 WordList，您可以使用 ##Has word# "
	"命令查询是否存在特定单词。您输入单词并按下“确定”。如果 WordList 确实包含该单词， "
	"数值 \"1\" 将被写入信息窗口；否则，将写入数值 \"0\"。")
ENTRY (U"3. 如何创建二进制 WordList 文件")
NORMAL (U"您可以从包含长单词列表的简单文本文件创建二进制 WordList 文件。 "
	"此类文本文件可能由您国家的辞书机构提供； "
	"由于版权问题，此类单词列表无法随 Praat 程序一起分发。 "
	"要将简单文本文件转换为压缩的 WordList 文件，您基本上需要执行以下步骤：")
CODE (U"Read Strings from raw text file: \"lexicon.txt\"")
CODE (U"Sort")
CODE (U"To WordList")
CODE (U"Save as binary file: \"lexicon.WordList\"")
NORMAL (U"我将详细解释这些步骤。 "
	"例如，一个简单的文本文件可能包含以下单词列表：")
CODE (U"cook")
CODE (U"cooked")
CODE (U"cookie")
CODE (U"cookies")
CODE (U"cooking")
CODE (U"cooks")
CODE (U"Copenhagen")
CODE (U"København")
CODE (U"München")
CODE (U"Munich")
CODE (U"ångström")
NORMAL (U"这只有 11 个单词，但如果您的电脑有足够的内存，即使您有一百万个单词，该程序也能正常运行。")
NORMAL (U"您可以使用对象窗口中 #Open 菜单下的 @@Read Strings from raw text file...|从原始文本文件读取 Strings...@ "
	"命令将该文件读取到一个 @@Strings|Strings（字符串列表）@ 对象中。生成的 @Strings 对象按上述顺序包含 11 个字符串， "
	"您可以通过使用 @@Inspect|Inspect（检查）@ 查看它们来验证这一点。")
NORMAL (U"如果选中该 Strings 对象，您可以点击 ##To WordList# 按钮。 "
	"但是，您会收到以下抱怨提示：")
CODE1 (U"String \"Copenhagen\" not sorted. Please sort first.")
NORMAL (U"该提示意味着这些字符串尚未按照 Unicode 排序顺序进行排序。 "
	"所以您点击 #Sort，Strings 对象变为：")
CODE (U"Copenhagen")
CODE (U"København")
CODE (U"Munich")
CODE (U"München")
CODE (U"cook")
CODE (U"cooked")
CODE (U"cookie")
CODE (U"cookies")
CODE (U"cooking")
CODE (U"cooks")
CODE (U"ångström")
NORMAL (U"这些字符串现在按照 Unicode 排序顺序排列，其中大写字母排在小写字母之前， "
	"复合字符跟在后者后面。")
NORMAL (U"现在点击 ##To WordList# 成功，并且列表中出现一个 WordList 对象。 "
	"如果将其保存为文本文件（使用 Save 菜单），您将得到以下文件：")
CODE (U"File type = \"ooTextFile\"")
CODE (U"Object class = \"WordList\"")
CODE (U"")
CODE (U"string = \"Copenhagen")
CODE (U"København")
CODE (U"Munich")
CODE (U"München")
CODE (U"cook")
CODE (U"cooked")
CODE (U"cookie")
CODE (U"cookies")
CODE (U"cooking")
CODE (U"cooks")
CODE (U"ångström\\\" ")
NORMAL (U"请注意，字符串内部出现的任何双引号 (\\\" ) 都将双写， "
	"就像 Praat 文本文件中所有字符串内部所做的一样。")
NORMAL (U"创建 WordList 文本文件后，您只需通过 #Open 菜单中的 @@Read from file...|从文件读取...@ 命令 "
	"读取此文件即可创建 WordList 对象。")
NORMAL (U"与 Strings 对象相比，WordList 对象的优势在于它不会占用比原始单词列表更多的 "
	"内存。这是因为 WordList 被存储为单个字符串： "
	"以换行符分隔的连续字符串列表。")
MAN_END

/*
longSound = selected ("LongSound")
longSoundNaam$ = selected$ ("LongSound")
textGrid = selected ("TextGrid")
select 'textGrid'
aantalIntervallen = Get number of intervals... 1
for interval to aantalIntervallen
   select 'textGrid'
   begintijd = Get starting point... 1 interval
   eindtijd = Get end point... 1 interval
   select 'longSound'
   Extract part... begintijd eindtijd no
   Save as WAV file... C:\Geluiden\'longSoundNaam$'_'interval'.wav
   Remove
endfor


# This is a Praat script that assumes that a single TextGrid is selected,
# and that the data in the first (or only) tier is in the form
# silence-text-silence-text and so on. The script will then write
# the durations of the silences and the texts into the Info window.

form Tabulate speech and silences
   comment Give the output file name:
   text fileName c:\windows\desktop\kim\out.txt
endform

# The following line provides the header,
# separated by tabs for easy inclusion in Excel.
echo Pause'tab$'Speech'tab$'Text

# Every next line writes three pieces of data,
# separated by tabs again.

# The following is a command from the Query menu
# that appears when you select a TextGrid object.
numberOfIntervals = Get number of intervals... 1

# The number of silence-speech pairs is half of that number,
# disregarding any silence at the end.
numberOfPairs = numberOfIntervals div 2

# Cycle through all the silence-speech pairs.

for pair to numberOfPairs
   silenceInterval = 2 * pair - 1   ; interval 1, 3, 5, and so on
   speechInterval = 2 * pair   ; interval 2, 4, 6, and so on
   # Check that the silence interval is indeed empty.
   silenceText$ = Get label of interval... 1 silenceInterval
   if silenceText$ <> ""
      exit Interval 'silenceInterval' should be a silence, but isn't.
   endif
   # Also check that the speech interval contains some text.
   speechText$ = Get label of interval... 1 speechInterval
   if speechText$ = ""
      exit Interval 'speechInterval' should contain text, but doesn't.
   endif
   # So now we have checked that the intervals contain the data
   # that Kim wanted them to contain. We're ready to write the data!
   silenceBegin = Get starting point... 1 silenceInterval
   silenceEnd = Get end point... 1 silenceInterval
   silenceDuration_ms = (silenceEnd - silenceBegin) * 1000
   speechBegin = Get starting point... 1 speechInterval
   speechEnd = Get end point... 1 speechInterval
   speechDuration_ms = (speechEnd - speechBegin) * 1000
   printline 'silenceDuration_ms:0''tab$'
   ...'speechDuration_ms:0''tab$'
   ...'speechText$'
endfor
filedelete 'fileName$'
fappendinfo 'fileName$'

*/

}

/* End of file manual_annotation.cpp */
