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
INTRO (U"A command to create a @TextGrid from scratch.")
ENTRY (U"Settings")
TERM (U"##Start time (s)")
DEFINITION (U"the start time, usually 0 seconds.")
TERM (U"##End time (s)")
DEFINITION (U"the end time in seconds, usually the duration.")
TERM (U"##Tier names")
DEFINITION (U"a list of the names of the tiers that you want to create, separated by spaces.")
TERM (U"##Point tiers")
DEFINITION (U"a list of the names of the tiers that you want to be %%point tiers%; "
	"the rest of the tiers will be %%interval tiers%. "
	"If you want to create no point tiers, you can leave this setting empty.")
MAN_END

MAN_BEGIN (U"PointProcess: To TextGrid...", U"ppgb", 19980113) // 2025
INTRO (U"A command to create an empty @TextGrid from every selected @PointProcess.")
NORMAL (U"The only information in the PointProcess that is used, is its starting and finishing times.")
ENTRY (U"Settings")
TERM (U"##Tier names")
DEFINITION (U"a list of the names of the tiers that you want to create, separated by spaces.")
TERM (U"##Point tiers")
DEFINITION (U"a list of the names of the tiers that you want to be %%point tiers%; "
	"the rest of the tiers will be %%interval tiers%. "
	"If you want to create no point tiers, you can leave this setting empty.")
ENTRY (U"Example")
NORMAL (U"If ##Tier names# is \"a b c\", and ##Point tiers# is \"b\", "
	"the resulting TextGrid object will contain an interval tier named \"a\", "
	"a point tier named \"b\", and another interval tier named \"c\".")
MAN_END

MAN_BEGIN (U"PointProcess: To TextGrid (vuv)...", U"ppgb", 19980210)
INTRO (U"A command to create a @TextGrid with voiced/unvoiced information "
	"from every selected @PointProcess.")
ENTRY (U"Settings")
TERM (U"##Maximum period (s)")
DEFINITION (U"the maximum interval that will be consider part of a larger voiced interval.")
TERM (U"##Mean period (s)")
DEFINITION (U"half of this value will be taken to be the amount to which a voiced interval "
	"will extend beyond its initial and final points. ##Mean period# should be less than "
	"##Maximum period#, or you may get intervals with negative durations.")
ENTRY (U"Example")
NORMAL (U"If ##Maximum period# is 0.02 s, and ##Mean period# is 0.01 s, "
	"and the point process is 0.1 seconds long, with points at 20, 28, 39, 61, and 72 milliseconds, "
	"the resulting TextGrid object will contain an interval tier "
	"with \"U\" intervals at [0 ms, 15 ms], [44 ms, 56 ms], and [77 ms, 100 ms], "
	"and \"V\" intervals at [15 ms, 44 ms] and [56 ms, 77 ms].")
MAN_END

MAN_BEGIN (U"PointProcess: Up to TextGrid...", U"ppgb", 20101230)
INTRO (U"A command to promote every selected @PointProcess to a @TextGrid with a single text tier in it.")
ENTRY (U"Setting")
TERM (U"##Text")
DEFINITION (U"the text that will be placed in every point.")
ENTRY (U"Behaviour")
NORMAL (U"The times of all the points are trivially copied, and so is the time domain. "
	"The text information will be the same for every point.")
MAN_END

MAN_BEGIN (U"Sound: To TextGrid...", U"ppgb", 19980730)  // 2025
INTRO (U"A command to create a @TextGrid without any labels, copying the time domain from the selected @Sound.")
ENTRY (U"Settings")
TERM (U"%%Tier names")
DEFINITION (U"a list of the names of the tiers that you want to create, separated by spaces.")
TERM (U"%%Point tiers")
DEFINITION (U"a list of the names of the tiers that you want to be %%point tiers%; "
	"the rest of the tiers will be %%interval tiers%. "
	"If you want to create no point tiers, you can leave this setting empty.")
ENTRY (U"Example")
NORMAL (U"If ##Tier names# is \"a b c\", and ##Point tiers# is \"b\", "
	"the resulting TextGrid object will contain an interval tier named \"a\", "
	"a point tier named \"b\", and another interval tier named \"c\".")
MAN_END

MAN_BEGIN (U"SpellingChecker", U"ppgb", 20190616)
INTRO (U"One of the @@types of objects@ in Praat. For checking the spelling in texts and @TextGrid objects.")
ENTRY (U"1. How to create a SpellingChecker object")
NORMAL (U"You normally read in a SpellingChecker with @@Read from file...@ from the #Open menu.")
ENTRY (U"2. How to check the spelling of a @TextGrid")
NORMAL (U"A SpellingChecker object can be used fur purposes of spelling checking. In order "
	"to check the spellings in a @TextGrid object, you first view the TextGrid in an editor window by selecting "
	"the TextGrid together with the SpellingChecker object, and clicking ##View & Edit#. In most cases, you will also want "
	"to select a @Sound or @LongSound object before clicking ##View & Edit#, so that a representation of the sound "
	"is also visible (and audible) in the editor. Thus, you typically select three objects and click ##View & Edit#. "
	"The editor then allows you to check the spellings "
	"(commands ##Check spelling in tier# and ##Check spelling in interval# from the #Spell menu).")
ENTRY (U"3. How to create a SpellingChecker object for the first time")
NORMAL (U"If you are the maintainer of a word list for spelling checking, you will want "
	"to convert this list to a SpellingChecker object that you can distribute among the transcribers of your corpus.")
NORMAL (U"The first step is to create a @WordList object from your text file, as described on the @WordList man page. "
	"Then you simply click ##To SpellingChecker#. A button labelled ##View & Edit...# appears. "
	"This command allows you to set the following attributes of the SpellingChecker object:")
/*TERM (U"##Check matching parentheses")
DEFINITION (U"determines whether it is considered a spelling error if parentheses do not match, as in the string \"Hi) there\".")*/
TERM (U"##Allow all parenthesized")
DEFINITION (U"this flag determines whether text between parentheses is ignored in spelling checking. "
	"This would allow the transcriber to mark utterances in foreign languages, which cannot be found in the lexicon.")
TERM (U"##Separating characters")
DEFINITION (U"determines the set of characters (apart from the space character) that separate words. "
	"The standard is \".,;:()\". If a string like \"error-prone\" should be considered two separate words, "
	"you will like to change this to \".,;:()-\". "
	"For the Corpus of Spoken Dutch (CGN), the hyphen is not a separator, since words like \"mee-eter\" should be checked as a whole. "
	"If a string like \"Mary's\" should be considered two separate words, include the apostrophe.")
/*TERM (U"##Forbidden strings")
DEFINITION (U"this will mainly contain characters that are not allowed in your corpus. For the CGN, this is \": ; \\\" \".")*/
TERM (U"##Allow all names")
DEFINITION (U"determines whether all words that start with a capital are allowed. For the CGN, this is on, "
	"since the lexicon does not contain many names.")
TERM (U"##Name prefixes")
DEFINITION (U"a space-separated list that determines what small groups of characters can precede names. For the CGN, "
	"this is \"'s- d' l'\", since names like %%'s-Gravenhage%, %%d'Ancona%, and %%l'H\\o^pital% should be ignored by the spelling checker.")
TERM (U"##Allow all words containing")
DEFINITION (U"a space-separated list of strings that make a word correct even if not in the lexicon. "
	"For the CGN, this is \"* xxx\", since words like %%keuje*d% and %%verxxxing% should be ignored by the spelling checker.")
TERM (U"##Allow all words starting with")
DEFINITION (U"a space-separated list of prefixes that make a word correct even if not in the lexicon. "
	"For the CGN, this is empty.")
TERM (U"##Allow all words ending in")
DEFINITION (U"a space-separated list of suffixes that make a word correct even if not in the lexicon. "
	"For the CGN, this is \"-\", since the first word in %%verzekerings- en bankwezen% should be ignored by the spelling checker.")
MAN_END

MAN_BEGIN (U"TextGrid", U"ppgb", 20110128 2025)
INTRO (U"One of the @@types of objects@ in Praat, used for %annotation (segmentation and labelling). "
	"For tutorial information, see @@Intro 7. Annotation@.")
ENTRY (U"Description")
NORMAL (U"A #TextGrid object consists of a number of %tiers. There are two kinds of tiers: "
	"an %%interval tier% is a connected sequence of labelled intervals, with %boundaries in between. "
	"A %%point tier% is a sequence of labelled points.")
ENTRY (U"How to create a TextGrid")
TERM (U"From scratch:")
LIST_ITEM (U"@@Sound: To TextGrid...@ (takes the time domain from the Sound)")
LIST_ITEM (U"@@LongSound: To TextGrid...@ (takes the time domain from the LongSound)")
LIST_ITEM (U"@@PointProcess: To TextGrid...@ (takes the time domain from the PointProcess)")
LIST_ITEM (U"@@PointProcess: To TextGrid (vuv)...@ (labels voiced and unvoiced intervals)")
LIST_ITEM (U"@@Create TextGrid...@")
TERM (U"From merging existing TextGrids with each other:")
LIST_ITEM (U"@@TextGrids: Merge...@")
ENTRY (U"How to edit a TextGrid")
NORMAL (U"You select a TextGrid alone or together with a @Sound or @LongSound, and click ##View & Edit#. "
	"A @TextGridEditor will appear on your screen, containing the TextGrid "
	"and an optional copy of the Sound or LongSound.")
ENTRY (U"How to draw a TextGrid")
TERM (U"You can draw a TextGrid to the @@Picture window@ with:")
LIST_ITEM (U"##TextGrid: Draw...")
LIST_ITEM (U"##TextGrid & Sound: Draw...")
LIST_ITEM (U"##TextGrid & Pitch: Draw...")
LIST_ITEM (U"##TextGrid & Pitch: Draw separately...")
MAN_END

MAN_BEGIN (U"TextGrid: Count labels...", U"ppgb", 20140421)
INTRO (U"A command to ask the selected @TextGrid object how many of the specified labels "
	"it contains in the specified tier.")
ENTRY (U"Settings")
TERM (U"##Tier number")
DEFINITION (U"the number (1, 2, 3...) of the tier whose labels you want to investigate.")
TERM (U"##Label text")
DEFINITION (U"the text on the labels that you want to count.")
ENTRY (U"Behaviour")
NORMAL (U"The number of intervals or points with label %%Label text% in tier %%Tier number% "
	"is written into the @@Info window@. If the specified tier does not exist, the number will be 0.")
ENTRY (U"Scripting")
NORMAL (U"You can use this command to put the number into a script variable:")
CODE (U"selectObject: \"TextGrid hallo\"")
CODE (U"number_of_a = Count labels: 1, \"a\"")
NORMAL (U"In this case, the value will not be written into the Info window.")
MAN_END
 
MAN_BEGIN (U"TextGrids: Merge", U"ppgb", 20101230)
INTRO (U"An obsolete command to merge all selected @TextGrid objects into a new @TextGrid.")
NORMAL (U"The same as @@TextGrids: Merge...@ with “Equalize domains” set to false.")
MAN_END

MAN_BEGIN (U"TextGrids: Merge...", U"ppgb", 2025)
INTRO (U"A command to merge all selected @TextGrid objects into a new @TextGrid.")
NORMAL (U"The time domain of the resulting TextGrid will be the union of the time domains "
	"of the constituent TextGrids.")
TERM (U"##Equalize time domains# (default: on)")
DEFINITION (U"If on, then the time domain of each tier will be made equal to the time domain of the resulting TextGrid. "
	"If this leads to a change in the end time of an interval tier, a new empty interval will be added "
	"between the original end time of the tier and its new end time (an analogous insertion could happen at the start of the tier, "
	"though that is quite rare in practice, because usually all tiers start at 0 seconds).")
MAN_END

MAN_BEGIN (U"TextGridEditor", U"ppgb", 20210228)
INTRO (U"Praat 中的 @@Editors|编辑器@ 之一，用于编辑 @@TextGrid|TextGrid@（文本标注网格）对象。")
NORMAL (U"您在启动此编辑器时，可以同时选中 TextGrid 对象以及 @@Sound|Sound@（声音）或 @@LongSound|LongSound@（长声音）对象，然后再点击 ##View & Edit#。此时，声音波形或长声音将显示在窗口的上半部分，标注层级显示在下半部分。窗口最上方有一个文本输入框，显示当前选中区间或点（即光标当前所在位置的区间或点）的文本内容。所有层级默认都是可见的，如果您不缩放窗口，所有的边界、时间点和标注文本也都清晰可见。您在 TextGridEditor 中可以进行大部分在 @@SoundEditor|SoundEditor@ 或 @@LongSoundEditor|LongSoundEditor@ 中可用的操作。")
ENTRY (U"定位光标与设置选区")
NORMAL (U"To position the cursor hair, @click in the #Sound, on a boundary, on a point, or inside an interval.")
NORMAL (U"若要选择特定时间段，请使用 @@time selection|时间选区@ 操作；如果您是在某个层级内拖动鼠标进行选择，选区边界会自动吸附到最近的边界线或时间点上。")
ENTRY (U"创建新的区间、边界、点或层级")
NORMAL (U"若要创建新区间，请在区间层级（interval tier）中创建一个新的边界线。")
NORMAL (U"若要在层级中创建新的边界线或时间点，请点击该层级上光标对应的小圆圈，或者也可以通过 Boundary/Point（边界/点）菜单中的命令在光标时刻插入边界。这既可以在当前选中的层级上操作（快捷键：Enter），也可以在任意层级上操作（快捷键：@@Keyboard shortcuts|Command-F1@ 到 @@Keyboard shortcuts|Command-F9@）。区间被分割时，原来区间里的文字会根据文字光标在上方文本框中的位置，分别划分到分割后的两个新区间内。")
NORMAL (U"若要创建新层级，请在 Tier（层级）菜单中选择 ##Add interval tier#（添加区间层）或 ##Add point tier#（添加点层）。")
ENTRY (U"播放整个区间或其中一部分")
NORMAL (U"As in many other editors, you can play a stretch of sound by clicking in any of the rectangles "
	"around the drawing area.")
NORMAL (U"若要播放区间层中的某个区间，请先在区间内部点击以选中它。被选中的区间在可见区域内会以黄色高亮显示。此时光标会自动定位在区间的起点，时间选区也会刚好包容该区间。这代表您可以直接按 Tab 键来播放这个选中的区间。如果在播放声音时再次按下 Tab 键，声音播放会停止，并且光标会移动到播放中断的时刻。这可以帮助您将较长的句子分割为一个个小片段，方便您听写记录。")
NORMAL (U"Tab 键将播放选中的区间。")
ENTRY (U"编辑区间或点中的文本")
NORMAL (U"To edit the label text of an interval or point:")
LIST_ITEM (U"1. Select that interval or point by clicking in or on it. The text currently in the interval or point "
	"will appear in the text window.")
LIST_ITEM (U"2. Just type the text, and use the mouse and the arrow keys to navigate the text window. "
	"Everything you type will become visible immediately in the text window as well as in the selected "
	"interval or point.")
NORMAL (U"您可以使用在 Praat 其他地方可用的所有 @@Special symbols|特殊符号@，包括数学符号、希腊字母、中文字符、上标以及国际音标（IPA）等。")
ENTRY (U"选择层级")
NORMAL (U"若要选中某个层级，只需在层级区域内的任意空白位置点击一下。该层级的编号和名称将变为红色，且其左侧会显示一个指向它的手指符号（☞）。")
ENTRY (U"选择边界或点")
NORMAL (U"若要在区间层级上选中一条边界线，请在边界线附近或右侧相邻的区间内点击；被选中的边界线会变为红色。该边界线右侧区间的文本将显示在顶部的文本输入框中。")
NORMAL (U"若要在点层级上选中一个时间点，请在其附近点击；选中的点会变为红色。该点的文本会显示在顶部的文本输入框中。")
ENTRY (U"移动边界或点")
NORMAL (U"To move a boundary or point to another time position, @drag it with the mouse.")
NORMAL (U"若要将多个层级上处于同一时刻的所有边界线和时间点同步移动到另一个位置，请按住 Shift 键并 @@Shift-drag|拖动@ 它们。")
NORMAL (U"若要把边界或点精准移动到另一个层级上某条边界线或时间点的时刻，请将它们拖动到该层级对应位置附近，它们会自动吸附对齐。")
NORMAL (U"若要把边界或点精准移动到光标所在的时刻，请将它们拖动到光标位置附近，它们会自动吸附到光标上。")
ENTRY (U"删除边界、点或层级")
NORMAL (U"若要删除选中的边界线，请在 Boundary（边界）菜单中选择 #Remove（移除）。这会把原本由该边界线隔开的两个区间合并为一个新区间；新区间的内容将自动拼接在一起（如果两个区间的原文本完全相同，合并后则只保留一个，不会重复拼接）。")
NORMAL (U"若要删除选中的时间点，请在 Point（点）菜单中选择 #Remove（移除）。")
NORMAL (U"若要删除选中的层级，请在 Tier（层级）菜单中选择 ##Remove entire tier#（删除整个层级）。")
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
INTRO (U"One of the @@types of objects@ in Praat. "
	"An object of class WordList contains a sorted list of strings in a system-independent format. "
	"WordList objects can be used for spelling checking after conversion to a @SpellingChecker object.")
ENTRY (U"1. How to create a WordList object")
NORMAL (U"You will normally create a WordList object by reading a binary WordList file. "
	"You'll use the generic @@Read from file...@ command from the #Open menu.")
NORMAL (U"See below under 3 for how to create such a file.")
ENTRY (U"2. What you can do with a Wordlist object")
NORMAL (U"The main functionality of a WordList is its ability to tell you whether it contains a certain string. "
	"If you select a WordList, you can query the existence of a specific word by using the ##Has word# "
	"command. You supply the word and press OK. If the WordList does contain the word, "
	"the value \"1\" will be written to the Info window; otherwise, the value \"0\" will be written.")
ENTRY (U"3. How to create a binary WordList file")
NORMAL (U"You can create a binary WordList file from a simple text file that contains a long list of words. "
	"Perhaps such a text file has been supplied by a lexicographic institution in your country; "
	"because of copyright issues, such word lists cannot be distributed with the Praat program. "
	"To convert the simple text file into a compressed WordList file, you basically take the following steps:")
CODE (U"Read Strings from raw text file: \"lexicon.txt\"")
CODE (U"Sort")
CODE (U"To WordList")
CODE (U"Save as binary file: \"lexicon.WordList\"")
NORMAL (U"I'll explain these steps in detail. "
	"For instance, a simple text file may contain the following list of words:")
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
NORMAL (U"These are just 11 words, but the procedure will work fine if you have a million of them, "
	"and enough memory in your computer.")
NORMAL (U"You can read the file into a @Strings object with @@Read Strings from raw text file...@ "
	"from the #Open menu in the Objects window. The resulting @Strings object contains 11 strings in the above order, "
	"as you can verify by viewing them with @Inspect.")
NORMAL (U"If you select the Strings, you can click the ##To WordList# button. "
	"However, you will get the following complaint:")
CODE1 (U"String \"Copenhagen\" not sorted. Please sort first.")
NORMAL (U"This complaint means that the strings have not been sorted in Unicode sorting order. "
	"So you click #Sort, and the Strings object becomes:")
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
NORMAL (U"The strings are now in Unicode sorting order, in which capitals come before lower-case letters, "
	"and composite characters follow the latter.")
NORMAL (U"Clicking ##To WordList# now succeeds, and a WordList object appears in the list. "
	"If you save it to a text file (with the Save menu), you will get the following file:")
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
NORMAL (U"Note that any double quotes (\\\" ) that appear inside the strings, will be doubled, "
	"as is done everywhere inside strings in Praat text files.")
NORMAL (U"After you have created a WordList text file, you can create a WordList object just by reading this file "
	"with @@Read from file...@ from the #Open menu.")
NORMAL (U"The WordList object has the advantage over the Strings object that it won't take up more "
	"memory than the original word list. This is because the WordList is stored as a single string: "
	"a contiguous list of strings, separated by new-line symbols.")
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
