/* manual_tutorials.cpp
 *
 * Copyright (C) 1992-2025 Paul Boersma
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

void manual_tutorials_init (ManPages me);
void manual_tutorials_init (ManPages me) {

MAN_PAGES_BEGIN R"~~~(
################################################################################
"Praat menu"
© Paul Boersma 2016-12-27

The first menu in the @@Objects window@.
In macOS, this menu is in the main menu bar along the top of the screen.

################################################################################
"Analyses menu"
© Paul Boersma 2022-12-02

A menu in the @SoundEditor or @TextGridEditor.

################################################################################
"Copy..."
© Paul Boersma 2011-10-18

One of the fixed buttons in the @@Objects window@.

Availability
============

You can choose this command after selecting one object of any type.

Behaviour
=========

The Objects window copies the selected object, and all the data it contains,
to a new object, which will appear at the bottom of the List of Objects.

Example
=======

If you select “Sound hallo” and click ##Copy...#,
a command window will appear, which prompts you for a name;
after you click #OK, a new object will appear in the list, bearing that name.

################################################################################
"Draw menu"
© Paul Boersma 2001-04-17

A menu that occurs in the @@Dynamic menu@ for many objects.

This menu contains commands for drawing the object to the @@Picture window@,
which will allow you to print the drawing or to copy it to your word processor.

################################################################################
"Dynamic menu"
© Paul Boersma 20110131  // 2023-06-08

A column of buttons in the right-hand part of the @@Objects window@,
plus the @@Save menu@ in the Objects window.

If you select one or more @objects in the list,
the possible actions that you can perform with the selected objects
will appear in the dynamic menu.
These actions can include viewing & editing, saving, drawing,
conversions to other types (including analysis and synthesis), and more.

Example of analysis:
====================

Record a Sound, select it, and click ##To Pitch...#.
This will create a new Pitch object and put it in the list of objects.
You can then edit, write, and draw this Pitch object.

Example of synthesis:
=====================

Create a Speaker, create and edit an Artword, and click ##To Sound...#.

################################################################################
"View & Edit"
© Paul Boersma 2011-01-28

A command in the @@Dynamic menu@ of several types of @objects.

This command puts an @@Editors|editor@ window on the screen, which shows the contents of the selected object.
This window will allow your to view and modify the contents of this object.

################################################################################
"Extract visible formant contour"
© Paul Boersma 2003-03-16

One of the commands in the Formant menu of the @SoundEditor and the @TextGridEditor.

See @@Intro 5. Formant analysis@

################################################################################
"Extract visible intensity contour"
© Paul Boersma 2003-03-16

One of the commands in the Intensity menu of the @SoundEditor and the @TextGridEditor.

See @@Intro 6. Intensity analysis@

################################################################################
"Extract visible pitch contour"
© Paul Boersma 2003-03-16

One of the commands in the Pitch menu of the @SoundEditor and the @TextGridEditor.

See @@Intro 4. Pitch analysis@

################################################################################
"Extract visible spectrogram"
© Paul Boersma 2003-03-16

One of the commands in the Spectrogram menu of the @SoundEditor and the @TextGridEditor.

See @@Intro 3. Spectral analysis@

################################################################################
"FAQ (Frequently Asked Questions)"
© Paul Boersma 2007-12-10

,	@@FAQ: How to cite Praat
,	@Unicode
,	@@FAQ: Formant analysis
,	@@FAQ: Pitch analysis
,	@@FAQ: Spectrograms
,	@@FAQ: Scripts

// Hardware
// Pitch: octave errors

################################################################################
"FAQ: Formant analysis"
© Paul Boersma 2003-09-16

#Problem: I get different formant values if I choose to analyse 3 formants
than if I choose to analyse 4 formants.

Solution: the “number of formants” in formant analysis determines the
number of peaks with which the %entire spectrum is modelled. For an average
female voice, you should choose to analyse 5 formants in the region up to 5500 Hz,
even if you are interested only in the first three formants.

#Problem: I often get only 1 formant in a region where I see clearly 2 formants
in the spectrogram.

This occurs mainly in back vowels (F1 and F2 close together) for male voices,
if the “maximum formant” is set to the standard of 5500 Hz, which is appropriate
for female voices. Set the “maximum formant” down to 5000 Hz.
No, Praat comes without a guarantee: the formant analysis is based on LPC,
and this comes with several assumptions as to what a speech spectrum is like.

#Question: what algorithm is used for formant analysis?

Answer: see @@Sound: To Formant (burg)...@.

################################################################################
"FAQ: How to cite Praat"
© Paul Boersma 2005,2010,2014,2025,2026

#Question: how do I cite Praat in my articles?

Answer: nowadays most journals allow you to cite computer programs and web sites.
The style approved by the American Psychological Association,
and therefore by many journals, is like the following
(change the dates and version number as needed):
{-
	writeInfoLine: “Paul Boersma, David Weenink & Anastasia Shchupak (”, appYear(),
	... “). Praat: doing phonetics by computer [Computer program]. Version ”, appVersion$(),
	... “, retrieved ”, appDay(), “ ”, appMonth$(), “ ”, appYear(), “ from https://praat.org”
}
If the journal does not allow you to cite a web site, then try:

Boersma, Paul (2001). Praat, a system for doing phonetics by computer.
%%Glot International% ##5:9/10#, 341-345.

This paper can be downloaded from Boersma’s website.

################################################################################
"FAQ: Pitch analysis"
© Paul Boersma, 2002,2006,2022-2024

Please also consult @@how to choose a pitch analysis method@.

#Question: what algorithm is used for pitch analysis?

Answer: for how the raw pitch analysis method works,
see @@Sound: To Pitch (ac)...@. The 1993 article is downloadable from
https://www.fon.hum.uva.nl/paul/

#Question: why does Praat consider my sound voiceless while I hear it as voiced?

There are at least five possibilities. Most of them can be checked by zooming in on the @waveform.

The first possibility is that the pitch has fallen below the @@pitch floor@. For instance,
your pitch floor could be 50 Hz but the English speaker produces creak at the end of the utterance.
Or your pitch floor could be 50 Hz but the Chinese speaker is in the middle of a third tone.
If this happens, it may help to lower the pitch floor to e.g. 30 Hz (@@Pitch settings...@),
although that may also smooth the pitch curve too much in other places.

The second possibility is that the pitch has moved too fast. This could happen at the end of a Chinese fourth tone,
which drops very fast. If this happens, it may help to use @@pitch analysis by raw cross-correlation@,
although Praat may then hallucinate pitches in other places that you would prefer to consider voiceless.

The third possibility is that the periods are very irregular, as in some pathological voices.
If you want to see a pitch in those cases, it may help to use @@pitch analysis by raw cross-correlation@.
Or it may help to lower the ##voicing threshold# setting
to 0.25 (instead of the standard 0.50) or so (@@Pitch settings...@).

The fourth possibility is that there is a lot of background noise, as in a recording on a busy street.
In such a case, it may help to lower the ##voicing threshold# setting
to 0.25 (instead of the standard 0.50) or so. The disadvantage of lowering this setting is that for non-noisy
recordings, Praat will become too eager to find voicing in some places that you would prefer to consider voiceless;
so make sure to set it back to 0.50 once you have finished analysing the noisy recordings.

The fifth possibility is that the part analysed as voiceless is much less loud than the rest of the sound,
or that the sound contains a loud noise elsewhere. This can be checked by zooming in on the part analysed as voiceless:
if Praat suddenly considers it as voiced, this is a sign that this part is much quieter than the rest.
To make Praat analyse this part as voiced, you can lower the ##silence threshold# setting to 0.01
(instead of the standard 0.09) or so. The disadvantage of lowering this setting is that Praat may start to consider
some distant background sounds (and quiet echos, for instance) as voiced.

#Question: why do I get different results for the maximum pitch if...?

If you select a Sound and choose @@Sound: To Pitch (filtered ac)...@, the time step will usually
be 0.015 seconds. The resulting @Pitch object will have values for times that are
0.015 seconds apart. If you then click Info or choose ##Get maximum pitch# from the @@Query submenu@,
the result is based on those time points. By contrast, if you choose ##Get maximum pitch#
from the @@Pitch menu@ in the SoundEditor window, the result will be based on the visible points,
of which there tend to be a hundred in the visible window. These different time spacings will
lead to slightly different pitch contours.

If you choose ##Move cursor to maximum pitch#, then choose ##Get pitch# from the
@@Pitch menu@, the result will be different again. This is because ##Get maximum pitch#
can do a parabolic interpolation around the maximum, whereas ##Get pitch#, not realizing
that the cursor is at a maximum, does a stupid linear interpolation, which tends to lead to
lower values.

################################################################################
"FAQ: Scripts"
© Paul Boersma 2001,2004,2011,2013,2014,2023

#Question: how do I do something to all the files in a directory?

Answer: look at @`fileNames$#` () or @@Create Strings as file list...@.
,

#Question: why doesn't the editor window react to my commands?

Your commands are probably something like:
{;
	Read from file: “hello.wav”
	View & Edit
	Zoom: 0.3, 0.5
}

Answer: Praat doesn’t know it has to send the #Zoom command to the editor
window called ##14. Sound hello#. There could be several Sound editor windows on your
screen. According to @@Scripting 7.1. Scripting an editor from a shell script@,
you will have to say this explicitly:
{;
	Read from file: “hello.wav”
	View & Edit
	editor: “Sound hello”
	Zoom: 0.3, 0.5
}
,

#Problem: a line like “%`Number = 1`” does not work.

Solution: names of variables should start with a lower-case letter.
,

#Question: why do names of variables have to start with a lower-case letter?
I would like to do things like “`F0 = Get mean pitch`”.

Answer: Praat scripts combine button commands with things that only occur
in scripts. Button commands always start with a capital letter, e.g. `Play` (there is a button #Play).
Script commands always start with lower case, e.g. `writeInfoLine: “Hello”`
($writeInfoLine is a built-in function).
A minimal pair is “$select”, which simulates a mouse click in the object list,
versus “`Select...`”, which sets the selection in editor windows. If we allowed initial capitals,
variable names would become rather ambiguous in assignments,
as in “`x = Get`”, where “%`Get`” would be a variable, versus “`x = Get mean`”,
where ##Get mean# is a button command. To prevent this confusion, Praat enforces
a rigorous lower-case/upper-case distinction.
,

#Question: how do I convert a number into a string?

Answer: `a$ = string$ (a)`

#Question: how do I convert a string into a number?

Answer: `a = number (a$)`

################################################################################
"FAQ: Spectrograms"
© Paul Boersma 2002,2003

#Problem: the background is grey instead of white (too little contrast)

Solution: reduce the ##Dynamic range# in the spectrogram settings. The standard value is 50 dB,
which is fine for detecting small things like plosive voicing in well recorded speech.
For gross features like vowel formants, or for noisy speech, you may want to change the dynamic range
to 40 or even 30 dB.

################################################################################
"File menu"
© Paul Boersma 2002

One of the menus in all @editors, in the @manual, and in the @@Picture window@.

################################################################################
"Filtering"
© Paul Boersma 2001,2003,2008,2010

This tutorial describes the use of filtering techniques in Praat.
It assumes you are familiar with the @Intro.

Frequency-domain filtering
==========================

Modern computer techniques make possible an especially simple batch filtering method:
multiplying the complex spectrum in the frequency domain by any real-valued filter function.
This leads to a zero phase shift for each frequency component. The impulse response is symmetric
in the time domain, which also means that the filter is %acausal: the filtered signal will show components
before they start in the original.

- @@Spectrum: Filter (pass Hann band)...@
- @@Spectrum: Filter (stop Hann band)...@
- @@Sound: Filter (pass Hann band)...@
- @@Sound: Filter (stop Hann band)...@
- @@Sound: Filter (formula)...@

Spectro-temporal:

- @@band filtering in the frequency domain@

Fast time-domain filtering
==========================

Some very fast Infinite Impulse Response (IIR) filters can be defined in the time domain.
These include recursive all-pole filters and pre-emphasis. These filters are causal but have non-zero phase shifts.
There are versions that create new Sound objects:

- @@Sound: Filter (one formant)...@
- @@Sound: Filter (pre-emphasis)...@
- @@Sound: Filter (de-emphasis)...@

And there are in-place versions, which modify the existing Sound objects:

- @@Sound: Filter with one formant (in-place)...@
- @@Sound: Pre-emphasize (in-place)...@
- @@Sound: De-emphasize (in-place)...@

Convolution
===========

A Finite Impulse Response (FIR) filter can be described as a sampled sound.
Filtering with such a filter amounts to a %#convolution of the original sound and the filter:

- @@Sounds: Convolve...@

Described elsewhere
===================

Described in the @@Source-filter synthesis@ tutorial:

- @@Sound & Formant: Filter@
- @@Sound & FormantGrid: Filter@
- @@LPC & Sound: Filter...@
- @@LPC & Sound: Filter (inverse)@

################################################################################
"Formants menu"
© Paul Boersma 2022

A menu in the @SoundEditor or @TextGridEditor.

################################################################################
"Formants & LPC menu"
© Paul Boersma 2001

A menu that occurs in the @@Dynamic menu@ for a @Sound.

This menu contains commands for analysing the formant contours of the selected Sound:

,	@@Sound: To Formant (burg)...
,	@@Sound: To Formant (keep all)...
,	@@Sound: To Formant (sl)...
,	@@Sound: To LPC (autocorrelation)...
,	@@Sound: To LPC (covariance)...
,	@@Sound: To LPC (burg)...
,	@@Sound: To LPC (marple)...
,	@@Sound: To MFCC...

################################################################################
"Get first formant"
© Paul Boersma 2001,2022

One of the query commands in the @@Formants menu@ of the @SoundEditor and the @TextGridEditor.

################################################################################
"Get pitch"
© Paul Boersma 2001,2022

One of the query commands in the @@Pitch menu@ of the @SoundEditor and the @TextGridEditor.

################################################################################
"Get second formant"
© Paul Boersma 2001,2022

One of the query commands in the @@Formants menu@ of the @SoundEditor and the @TextGridEditor.

################################################################################
"Goodies"
© Paul Boersma 2002,2005

The title of a submenu of the @@Praat menu@.

################################################################################
"Info"
© Paul Boersma 1996,1998

One of the fixed buttons in the @@Objects window@.

Availability
============

You can choose this command after choosing one object.

Purpose
=======

To get some information about the selected object.

Behaviour
=========

The information will appear in the @@Info window@.

################################################################################
"Info window"
© Paul Boersma 1997,1998,2003,2023

A text window into which many query commands write their answers.

You can select text from this window and copy it to other places.

In a @@Praat script@, you can bypass the Info window by having a query command
writing directly into a script variable.

Apart from the @Info command, which writes general information about the selected object,
most commands in any @@Query submenu@ also write into the Info window.

################################################################################
"Inspect"
© Paul Boersma 1996

One of the fixed buttons in the @@Objects window@.

You can use this command after selecting one object in the list.

The contents of the selected object will become visible in a Data Editor.
You can then view and change the data in the object,
but beware: changing the data directly in this way may render them inconsistent.

Changes that you make to the data with another Editor (e.g., a SoundEditor),
or with the commands under #Modify,
are immediately reflected in the top-level Data Editor;
any subeditors are destroyed, however, because they may now refer to invalid data.

Changes that you make to the data with a Data Editor,
are immediately reflected in any open type-specific Editors (e.g., a SoundEditor).

################################################################################
"Intro"
© Paul Boersma 2003,2004,2007,2009,2011,2025

本教程是 Praat 的入门指南。Praat 是一款用于分析、合成、处理语音信号，并能为您撰写论文及报告绘制高质量插图的计算机软件。建议您通读本教程的所有章节。

您可以使用窗口顶部的“##1 >#”（下一页）和“##< 1#”（上一页）按钮按顺序阅读，也可以通过点击蓝色超链接直接跳转到所需的信息页。

, @@Intro 1. How to get a sound|Intro 1. 如何获取声音@:
	@@Intro 1.1. Recording a sound|录音@,
	@@Intro 1.2. Reading a sound from disk|从磁盘读取@,
	@@Intro 1.3. Creating a sound from a formula|通过公式创建@.
, @@Intro 2. What to do with a sound|Intro 2. 声音的操作与处理@:
	@@Intro 2.1. Saving a sound to disk|保存声音到磁盘@,
	@@Intro 2.2. Viewing and editing a sound|查看与编辑@.
, @@Intro 3. Spectral analysis|Intro 3. 声谱分析@
	, 声谱图：@@Intro 3.1. Viewing a spectrogram|查看声谱图@,
		@@Intro 3.2. Configuring the spectrogram|设置声谱图参数@,
		@@Intro 3.3. Querying the spectrogram|查询声谱图信息@,
		@@Intro 3.4. Printing the spectrogram|打印声谱图@,
		@@Intro 3.5. The Spectrogram object|Spectrogram 对象@.
	, 频谱切片：@@Intro 3.6. Viewing a spectral slice|查看频谱切片@,
		@@Intro 3.7. Configuring the spectral slice|设置频谱切片参数@,
		@@Intro 3.8. The Spectrum object|Spectrum 对象@.
, @@Intro 4. Pitch analysis|Intro 4. 音高分析@
	, 音高曲线：@@Intro 4.1. Viewing a pitch contour|查看音高曲线@,
		@@Intro 4.2. Configuring the pitch contour|设置音高曲线参数@,
		@@Intro 4.3. Querying the pitch contour|查询音高曲线信息@,
		@@Intro 4.4. Printing the pitch contour|打印音高曲线@,
		@@Intro 4.5. The Pitch object|Pitch 对象@.
, @@Intro 5. Formant analysis|Intro 5. 共振峰分析@
	, 共振峰曲线：@@Intro 5.1. Viewing formant contours|查看共振峰曲线@,
		@@Intro 5.2. Configuring the formant contours|设置共振峰曲线参数@,
		@@Intro 5.3. Querying the formant contours|查询共振峰曲线信息@,
		@@Intro 5.4. The Formant object|Formant 对象@.
, @@Intro 6. Intensity analysis|Intro 6. 音强分析@
	, 音强曲线：@@Intro 6.1. Viewing an intensity contour|查看音强曲线@,
		@@Intro 6.2. Configuring the intensity contour|设置音强曲线参数@,
		@@Intro 6.3. Querying the intensity contour|查询音强曲线信息@,
		@@Intro 6.4. The Intensity object|Intensity 对象@.
, @@Intro 7. Annotation|Intro 7. 标注@
, @@Intro 8. Manipulation|Intro 8. 声音操控@：包括
	@@Intro 8.1. Manipulation of pitch|音高@、
	@@Intro 8.2. Manipulation of duration|时长@、
	@@Intro 8.3. Manipulation of intensity|音强@、
	@@Intro 8.4. Manipulation of formants|共振峰@的操控。

此外还有一些更具针对性的专题教程：
, 语音学相关：
	• 嗓音/声源分析（基频微扰、振幅微扰、噪声）：@Voice
	• 听辨实验：@@ExperimentMFC@
	• @@Sound files|声音文件操作@
	• @@Filtering|滤波器与滤波操作@
	• @@Source-filter synthesis|源-滤波器合成@
	• @@Articulatory synthesis|声道模拟/发音合成@
, 机器学习与认知建模：
	• @@Feedforward neural networks|前馈神经网络模型@
	• @@OT learning|优选论（OT）学习算法@
, 统计分析：
	• @@Principal component analysis|主成分分析（PCA）@
	• @@Multidimensional scaling|多维尺度分析（MDS）@
	• @@Discriminant analysis|判别分析@
, 通用与基础功能：
	• @@Scripting|脚本编写与批处理@
	• @@Demo window|演示窗口交互界面@
	• @@Printing|图形输出与打印@

关于作者：

Praat 软件由阿姆斯特丹大学语音科学研究所的 Paul Boersma 和 David Weenink 共同开发。
官方主页：#`https://praat.org` 或 #`https://www.fon.hum.uva.nl/praat`。

如有任何问题或建议，欢迎发送邮件至 Praat 讨论组（可从 Praat 主页访问），或直接发送至 #`paul.boersma@uva.nl`。

################################################################################
)~~~"
MAN_PAGES_END

MAN_BEGIN (U"Intro 1. How to get a sound", U"ppgb", 20021212)
INTRO (U"大多数人使用 Praat 都是从一个声音开始的。 "
	"获取声音至少有以下三种方法：")
LIST_ITEM (U"@@Intro 1.1. Recording a sound|Intro 1.1. 录音@")
LIST_ITEM (U"@@Intro 1.2. Reading a sound from disk|Intro 1.2. 从磁盘读取声音@")
LIST_ITEM (U"@@Intro 1.3. Creating a sound from a formula|Intro 1.3. 通过公式创建声音@")
MAN_END

MAN_BEGIN (U"Intro 1.1. Recording a sound", U"ppgb", 20201120)
INTRO (U"要在 Praat 中录制语音，您需要一台带有麦克风的计算机。")
NORMAL (U"要使用麦克风进行录音，请执行以下步骤：")
LIST_ITEM (U"1. 从 @@Objects window|对象窗口@ 的 @@New menu|新建菜单@ 中选择 @@Record mono Sound...@（录制单声道声音...）。 "
	"屏幕上将弹出一个 @SoundRecorder 录音机窗口。")
LIST_ITEM (U"2. 在 SoundRecorder 窗口的左侧，选择合适的输入设备，例如选择 ##Internal microphone#（内置麦克风）。 "
	"（在 Windows 上，您也可以右键单击任务栏上的扬声器图标进行设置；有关更多详细信息，请参阅 @SoundRecorder 手册页。）")
LIST_ITEM (U"3. 使用 #Record（录音）和 #Stop（停止）按钮录制几秒钟的语音。")
LIST_ITEM (U"4. 使用 #Play（播放）按钮聆听您录制的声音。")
LIST_ITEM (U"5. 重复步骤 3 和 4，直到您对录音满意为止。")
LIST_ITEM (U"6. 点击 ##Save to list#（保存到列表）按钮。您的录音现在会出现在对象窗口中， "
	"名称为“Sound sound”。")
LIST_ITEM (U"7. 您现在可以关闭 SoundRecorder 窗口了。")
LIST_ITEM (U"8. 当您将声音保存到对象窗口时，该窗口中会出现一些按钮。 "
	"这些按钮向您展示了您可以对该声音进行的操作。试试 #Play（播放）和 @@View & Edit@（查看与编辑）按钮。")
NORMAL (U"有关录音的更多信息，请参阅 @SoundRecorder 手册页。")
MAN_END

MAN_BEGIN (U"Intro 1.2. Reading a sound from disk", U"ppgb", 20041126)
INTRO (U"除了使用麦克风录制新声音外，您也可以从磁盘中读取现有的声音文件。")
NORMAL (U"通过 @@Open menu|打开菜单@ 中的 @@Read from file...@，Praat 将能够读取大多数标准类型的声音文件，例如 WAV 文件。 "
	"它们将作为 @Sound 对象出现在对象窗口中。例如，如果您打开了 ##hello.wav# 文件， "
	"列表中就会出现一个名为“Sound hello”的对象。")
NORMAL (U"如果您的磁盘上没有声音文件，您可以从互联网上下载一个 WAV 文件（或类似格式文件）， "
	"然后使用 ##Read from file...#（从文件读取...）将其读入 Praat。")
MAN_END

MAN_BEGIN (U"Intro 1.3. Creating a sound from a formula", U"ppgb", 20070225)
INTRO (U"如果您没有麦克风、磁盘上没有声音文件，且无法访问互联网， "
	"您仍然可以使用 @@New menu|新建菜单@ 中的 @@Create Sound from formula...@（通过公式创建声音...）来生成声音。")
MAN_END

MAN_BEGIN (U"Intro 2. What to do with a sound", U"ppgb", 20110131)
INTRO (U"一旦您在 @@List of Objects|对象列表@ 中有了 @Sound 对象， "
	"@@Objects window|对象窗口@右侧的 @@Dynamic menu|动态菜单@ 按钮就会向您展示可以对其执行的操作。")
LIST_ITEM (U"@@Intro 2.1. Saving a sound to disk|Intro 2.1. 保存声音到磁盘@")
LIST_ITEM (U"@@Intro 2.2. Viewing and editing a sound|Intro 2.2. 查看与编辑声音@")
MAN_END

MAN_BEGIN (U"Intro 2.1. Saving a sound to disk", U"ppgb", 20110131)
INTRO (U"有几种不同的方法可以将声音写入磁盘。")
NORMAL (U"首先，@SoundRecorder 录音机窗口的 @@File menu|文件菜单@ 包含了将录制声音的左声道、右声道或双声道保存为四种标准类型 "
	"声音文件（WAV、AIFC、NeXT/Sun、NIST）中的任何一种的命令。这四种文件类型对 Praat 来说都一样好： "
	"Praat 在每台计算机上都能同样好地处理它们。这四种类型中的前三种也将 "
	"几乎被所有其他声音播放程序所识别。")
NORMAL (U"其次，一旦您在 @@List of Objects|对象列表@ 中有了一个 @Sound 对象， "
	"您就可以使用 @@Save menu|保存菜单@ 中的命令以多种格式保存它。 "
	"同样，WAV、AIFF、AIFC、NeXT/Sun 和 NIST 格式都同样适用。")
NORMAL (U"有关更多信息，请参阅 @@Sound files|声音文件@ 教程。")
MAN_END

MAN_BEGIN (U"Intro 2.2. Viewing and editing a sound", U"ppgb", 20230202)   // 2023-06-08
NORMAL (U"要查看对象列表中某个 @Sound 对象的波形图， "
	"请选中该声音对象并点击 @@View & Edit@（查看与编辑）。屏幕上将弹出一个 @SoundEditor 窗口。 "
	"您会看到波形图（如果是双声道立体声，则为上下两个波形图），以及可能位于其下方的分析图。 "
	"您可以放大和滚动来详细查看声音的各个部分。 "
	"您可以通过鼠标拖动来选定声音的某一部分。 "
	"要播放声音的某一部分，可以单击其下方的任何控制条矩形。 "
	"要将选中的声音部分移动到其他位置，可以使用 Edit（编辑）菜单中的 #Cut（剪切）和 #Paste（粘贴）命令。 "
	"您可以同时为多个不同的声音打开编辑器窗口，然后在不同声音之间进行剪切、复制和粘贴， "
	"这与您在文字处理或图像处理软件中操作文本 and 图片的方式完全一致。")
NORMAL (U"如果您的音频文件长达数分钟或更久， "
	"或者您希望同时查看并聆听立体声文件的两个声道， "
	"您可能会更倾向于使用 @@Open long sound file...@（打开长声音文件...）。 "
	"这将在列表中放入一个 @LongSound（长声音）对象。采用这种方式时，声音的绝大部分数据将保留在磁盘文件中， "
	"每次播放或查看某一小段时，只会读取最多 60 秒的音频数据到内存中。 "
	"若要更改这个 60 秒的限制（例如改为 500 秒）， "
	"请选择 Praat 菜单中 ##Settings#（设置）子菜单下的 ##LongSound settings...#（长声音设置...）。")
MAN_END

MAN_BEGIN (U"Intro 3. Spectral analysis", U"ppgb", 20070905)
INTRO (U"本节介绍如何分析现有声音的频谱内容。 "
	"您将学习如何使用%spectrograms（声谱图）和%%spectral slices%（频谱切片）。")
LIST_ITEM (U"@@Intro 3.1. Viewing a spectrogram|Intro 3.1. 查看声谱图@")
LIST_ITEM (U"@@Intro 3.2. Configuring the spectrogram|Intro 3.2. 设置声谱图参数@")
LIST_ITEM (U"@@Intro 3.3. Querying the spectrogram|Intro 3.3. 查询声谱图信息@")
LIST_ITEM (U"@@Intro 3.4. Printing the spectrogram|Intro 3.4. 打印声谱图@")
LIST_ITEM (U"@@Intro 3.5. The Spectrogram object|Intro 3.5. Spectrogram 对象@")
LIST_ITEM (U"@@Intro 3.6. Viewing a spectral slice|Intro 3.6. 查看频谱切片@")
LIST_ITEM (U"@@Intro 3.7. Configuring the spectral slice|Intro 3.7. 设置频谱切片参数@")
LIST_ITEM (U"@@Intro 3.8. The Spectrum object|Intro 3.8. Spectrum 对象@")
MAN_END

MAN_BEGIN (U"Intro 3.1. Viewing a spectrogram", U"ppgb", 20110128)  // 2023-06-08
INTRO (U"要查看声音频谱内容随时间的变化， "
	"请在对象列表中选择一个 @Sound 或 @LongSound 对象，然后选择 @@View & Edit@。 "
	"屏幕上将弹出一个 @SoundEditor 或 @LongSoundEditor 窗口。 "
	"在此窗口的整个下半部分，您将看到一个灰度图像，它被称为%spectrogram（声谱图）。 "
	"如果未显示声谱图，请从 Spectrogram（声谱图）菜单中选择 @@Show spectrogram@（显示声谱图）。")
NORMAL (U"声谱图是声音的@@spectro-temporal representation|时频表示@。 "
	"声谱图的水平方向表示@@time|时间@，垂直方向表示@@frequency|频率@。 "
	"声谱图的时间轴与波形图完全一致，因此声谱图会随着您的缩放和滚动操作而联动。 "
	"在声谱图的左侧，您可以看到频率刻度。声谱图底部的频率通常是 0 Hz（赫兹，每秒周期数），顶部的常见频率上限值是 5000 Hz。")
NORMAL (U"声谱图中颜色较深的部分表示能量密度较高，颜色较浅的部分表示能量密度较低。 "
	"如果声谱图在 1.2 秒左右且频率为 4000 Hz 处有一块深色区域， "
	"这意味着声音在那个时刻的该高频段含有大量能量。 "
	"有关语音声谱图的更多实例，请参阅 @@Ladefoged (2001)@ 的教科书以及 "
	"@@Ladefoged & Maddieson (1996)@ 的参考著作。")
NORMAL (U"要查看声谱图某一部分所对应的具体时间和频率， "
	"只需在声谱图中单击，您就会看到垂直的时间光标在波形图上方显示时间， "
	"水平的频率光标在声谱图左侧显示频率。 "
	"这是寻找元音%formant（共振峰）频率或摩擦音主要频谱峰值的方法之一。")
ENTRY (U"哎呀，边缘怎么有白色的垂直条纹？")
NORMAL (U"这是正常现象。频谱分析需要一定长度的%%analysis window%（分析窗）。 "
	"例如，如果 Praat 想要计算 1.342 秒处的频谱，它需要包含该时间点周围 10 毫秒窗口内的信号信息， "
	"即 Praat 会使用 1.337 到 1.347 秒之间的所有信号信息。但在声音的最边缘， "
	"这些信息是不可用的： "
	"如果声音的时间跨度是 0 到 1.8 秒，那么在 0 到 0.005 秒之间或 1.795 到 1.800 秒之间就无法计算频谱。 "
	"因此会出现白色条纹。如果您在刚打开声音时没有立即看到它们，可以放大声音的开头或结尾部分查看。")
NORMAL (U"当您放大声音的中间部分（或任何远离边缘的地方）时，这些白色条纹就会消失。 "
	"例如，您会突然只看到 0.45 到 1.35 秒之间的时间段。 "
	"但 Praat 并没有忘记此时窗边缘之外的信号是什么样的。 "
	"为了显示 0.45 到 1.35 秒的声谱图，Praat 会使用波形图中 0.445 到 1.355 秒之间的信号信息， "
	"如果这部分信息可用，您就不会在视窗边缘看到白色条纹。")
ENTRY (U"哎呀，我滚动时它会发生变化！")
NORMAL (U"这也是正常现象，尤其是在视窗较长时。如果您的可见时间窗口长达 20 秒， "
	"且该窗口在水平方向上占用了 1000 个屏幕像素， "
	"那么您可能会认为每个一像素宽的垂直线应该代表 20 毫秒声音的频谱。 "
	"但出于计算速度的考虑，Praat 只会显示这 20 毫秒中心附近那部分声音的频谱， "
	"而不是这 20 毫秒内所有频谱的平均值或总和。 "
	"这种对底层声谱图的%undersampling（欠采样）与绘制波形图时的情况不同。 "
	"在波形图中，垂直的黑线会连接落入同一个屏幕像素内的所有采样点的最小 and 最大振幅。 "
	"但我们无法对声谱图做类似的处理。由于滚动是按固定时间步长（即可见窗口时长的 5%）进行的， "
	"而不是按整像素进行的，因此每次滚动时像素的中心都会落入声谱图的不同部分。 "
	"从而导致了这种视觉上的变化。如果您的可见窗口短于几秒钟， "
	"滚动声谱图看起来就会平滑得多。")
NORMAL (U"声谱图的亮度/黑度在您滚动时也会发生变化，因为系统会将当前可见部分中能量最高的地方定义为黑色。 "
	"当信号中能量非常高的一部分滚动到视窗外时，声谱图的其余部分就会变深。 "
	"下一节将介绍如何关闭此自动调整功能。")
MAN_END

MAN_BEGIN (U"Intro 3.2. Configuring the spectrogram", U"ppgb", 20220907)
NORMAL (U"通过选择 Spectrogram（声谱图）菜单中的 @@Spectrogram settings...@（声谱图设置...）， "
	"您可以决定声谱图的计算和显示方式。 "
	"这些设置将在不同的 Praat 运行周期中被记录。 "
	"所有这些设置都具有默认的标准值（“出厂设置”），在点击 ##Standards#（标准值）时就会恢复。")
TERM (U"%%View range%（显示频率范围，Hz）")
DEFINITION (U"要显示的频率范围。标准值是底部 0 Hz，顶部 5000 Hz。 "
	"如果此最大频率高于声音对象的奈奎斯特频率（Nyquist frequency，即其采样频率的一半）， "
	"则声谱图中的某些值将为零，且更高的频率将绘制为白色。 "
	"如果您以 44100 Hz 录制一段声音，并将显示范围设置为 0 Hz 到 25000 Hz，您就可以看到这种现象。")
TERM (U"%%Window length%（窗长度）")
DEFINITION (U"分析窗的持续时间。如果是 0.005 秒（标准值）， "
	"Praat 会在每一帧中使用该帧中心前 0.0025 秒和后 0.0025 秒之间的那部分声音信号 "
	"（对于高斯窗，Praat 实际上使用的比这稍微多一点）。 "
	"窗长度决定了频谱分析的%带宽（bandwidth）， "
	"即纯正弦波声谱图中水平线的宽度（见下文）。 "
	"对于高斯窗，-3 dB 带宽为 2*sqrt(6*ln(2))/(\\pi*%%Window length%)， "
	"或 1.2982804 / %%Window length%。 "
	"要获得“宽带”声谱图（带宽为 260 Hz），请保持 5 毫秒的标准窗长度； "
	"要获得“窄带”声谱图（带宽为 43 Hz），请将其设置为 30 毫秒（0.03 秒）。 "
	"其他窗口形状会给出略微不同的数值。")
TERM (U"%%Dynamic range%（动态范围，dB）")
DEFINITION (U"所有比最大值低 %%Dynamic range% dB 以上的值（可能是在动态压缩之后， "
	"参见 @@Advanced spectrogram settings...@（高级声谱图设置）） "
	"都将绘制为白色。介于两者之间的值则具有相应的灰色阴影。因此，如果声谱图中的最高峰值 "
	"高度为 30 dB/Hz，且动态范围为 50 dB（这是标准值）， "
	"那么低于 -20 dB/Hz 的值将绘制为白色，而介于 -20 dB/Hz 和 30 dB/Hz 之间的值将绘制为 "
	"各种不同深浅的灰色。")
ENTRY (U"带宽（The bandwidth）")
NORMAL (U"要查看窗长度如何影响带宽， "
	"首先使用 @@Create Sound from formula...@ 通过公式创建一个 1000 Hz 的正弦波， "
	"在公式框中输入 `1/2 * sin (2*pi*1000*x)`，然后点击 ##View & Edit#。 "
	"声谱图将显示一条水平黑线。 "
	"您现在可以在声谱图设置中改变窗长度，并观察线条的粗细如何变化。 "
	"如果增加窗长度，线条会变细。 "
	"显然，如果分析窗包含该波形的更多周期， "
	"声谱图就能够以更高的精度告诉我们该波形的频率。")
NORMAL (U"为了更精确地观察这一点，请创建一个频率分别为 1000 Hz 和 1200 Hz 的两个正弦波之和。 "
	"公式为 `1/4 * sin (2*pi*1000*x) + 1/4 * sin (2*pi*1200*x)`。在编辑器中， "
	"如果分析窗很短（5 毫秒），您将看到单条粗谱带；如果分析窗较长（30 毫秒）， "
	"您将看到两条分离的谱带。显然，频率分辨率会随着分析窗的增长而变好。")
NORMAL (U"那为什么我们不一直使用长分析窗呢？答案是它们的时间分辨率较差。 "
	"要观察这一点，请创建一个由两个正弦波和两个短脉冲（clicks）组成的声音。公式为 "
	"`0.02*(sin(2*pi*1000*x)+sin(2*pi*1200*x)) + (col=10000)+(col=10200)`。 "
	"如果查看这段声音，您会发现如果分析窗较长，两个脉冲在时间上会重叠； "
	"而如果分析窗较短，正弦波在频率上会重叠。 "
	"显然，在时间分辨率和频率分辨率之间存在着权衡关系。 "
	"人们无法同时极其精确地获知时间和频率。")
ENTRY (U"高级设置（Advanced settings）")
NORMAL (U"Spectrogram（声谱图）菜单中还包含了 @@Advanced spectrogram settings...@（高级声谱图设置...）。")
MAN_END

MAN_BEGIN (U"Advanced spectrogram settings...", U"ppgb", 20120531)
ENTRY (U"Optimization")
TERM (U"%%Number of time steps%")
DEFINITION (U"the maximum number of points along the time window for which Praat has to compute "
	"the spectrum. If your screen is not wider than 1200 pixels, then the standard of 1000 is "
	"appropriate, since there is no point in computing more than one spectrum per one-pixel-wide vertical line. "
	"If you have a really wide screen, you may see improvement if you raise this number to 1500.")
TERM (U"%%Number of frequency steps%")
DEFINITION (U"the maximum number of points along the frequency axis for which Praat has to compute "
	"the spectrum. If your screen is not taller than 768 pixels, then the standard of 250 is "
	"appropriate, since there is no point in computing more than one spectrum per one-pixel-height horizontal line. "
	"If you have a really tall screen, you may see improvement if you raise this number.")
NORMAL (U"For purposes of computation speed, Praat may decide to change the time step and the frequency step. "
	"This is because the time step never needs to be smaller than 1/(8\\Vr\\pi) of the window length, "
	"and the frequency step never needs to be smaller than (\\Vr\\pi)/8 of the inverse of the window length. "
	"For instance, if the window length is 5 ms, "
	"the actual time step will never be less than 5/(8\\Vr\\pi) = 0.353 ms, "
	"and the actual frequency step will never be less than (\\Vr\\pi)/8/0.005 = 44.31 Hz.")
ENTRY (U"Spectrogram analysis settings")
TERM (U"%%Method")
DEFINITION (U"there is currently only one method available in this window for computing a spectrum from "
	"a sound: the Fourier transform.")
TERM (U"%%Window shape")
DEFINITION (U"the shape of the analysis window. To compute the spectrum at, say, 3.850 seconds, "
	"samples that lie close to 3.850 seconds are given more weight than samples further away. "
	"The relative extent to which each sample contributes to the spectrum is given by the window shape. "
	"You can choose from: Gaussian, Square (none, rectangular), Hamming (raised sine-squared), "
	"Bartlett (triangular), Welch (parabolic), and Hanning (sine-squared). "
	"The Gaussian window is superior, as it gives no %sidelobes in your spectrogram (see below); "
	"it analyzes a factor of 2 slower than the other window shapes, "
	"because the analysis is actually performed on twice as many samples per frame.")
ENTRY (U"Sidelobes; anybody wants to win a cake?")
NORMAL (U"The Gaussian window is the only shape that we can consider seriously as a candidate for "
	"the analysis window. To see this, create a 1000-Hz sine wave with @@Create Sound from formula...@ "
	"by typing `1/2 * sin (2*pi*1000*x)` as the formula, then click ##View & Edit#. "
	"If the window shape is Gaussian, the spectrogram will show a horizontal black line. "
	"If the window shape is anything else, the spectrogram will show many horizontal grey lines (%sidelobes), "
	"which do not represent anything that is available in the signal. They are artifacts of the "
	"window shapes.")
NORMAL (U"We include these other window shapes only for pedagogical purposes "
	"and because the Hanning and Hamming windows have traditionally been used in other programs before "
	"computers were as fast as they are now (a spectrogram is computed twice as fast "
	"with these other windows). Several other programs still use these inferior window shapes, and you are "
	"likely to run into people who claim that the Gaussian window has disadvantages. "
	"We promise such people a large cake if they can come up with sounds that look better "
	"with Hanning or Hamming windows than with a Gaussian window. An example of the reverse is easy "
	"to find; we have just seen one.")
ENTRY (U"Spectrogram blackness settings")
TERM (U"%%Autoscaling%")
TERM (U"%%Maximum% (dB/Hz)")
DEFINITION (U"all parts of the spectrogram that have a power above %maximum (after preemphasis) "
	"will be drawn in black. The standard maximum is 100 dB/Hz, but if %autoscaling is on (which is the standard), "
	"Praat will use the maximum of the visible part of the spectrogram instead; "
	"this ensures that the window will always look well, but it also means that the blackness "
	"of a certain part of the spectrogram will change as you scroll.")
TERM (U"%%Preemphasis% (dB/octave)")
DEFINITION (U"determines the steepness of a high-pass filter, "
	"i.e., how much the power of higher frequencies will be raised before drawing, as compared to lower frequencies. "
	"Since the spectral slope of human vowels is approximately -6 dB per octave, "
	"the standard value for this setting is +6 dB per octave, "
	"so that the spectrum is flattened and the higher formants look as strong as the lower ones. "
	"When you raise the preemphasis, frequency bands above 1000 Hz will become darker, those below 1000 Hz will become lighter.")
TERM (U"%%Dynamic compression")
DEFINITION (U"determines how much stronger weak spectra should be made before drawing. "
	"Normally, this parameter is between 0 and 1. If it is 0 (the standard value), there is no dynamic compression. "
	"If it is 1, all spectra will be drawn equally strong, "
	"i.e., all of them will contain frequencies that are drawn in black. "
	"If this parameter is 0.4 and the global maximum is at 80 dB, then a spectrum with a maximum at 20 dB "
	"(which will normally be drawn all white if the dynamic range is 50 dB), "
	"will be raised by 0.4 * (80 - 20) = 24 dB, "
	"so that its maximum will be seen at 44 dB (thus making this frame visible).")
MAN_END

MAN_BEGIN (U"Intro 3.3. Querying the spectrogram", U"ppgb", 20221202)
NORMAL (U"如果您在声谱图内任意位置单击，将会出现一个光标十字交叉线， "
	"并且您会在窗口顶部 and 左侧以红色字样看到对应的时间和频率值。 "
	"要在信息窗口（@@Info window@）中显示时间， "
	"请从 Spectrogram 菜单中选择 ##Get cursor#（获取光标位置）或按下 F6 键。 "
	"要在信息窗口中显示频率， "
	"请从 Spectrogram 菜单中选择 ##Get frequency#（获取频率）。")
NORMAL (U"要查询光标十字交叉处的声谱图功率， "
	"请从 Spectrum 菜单中选择 ##Get spectral power at cursor cross#（获取光标处频谱功率）或按下 F9 键。 "
	"信息窗口将向您显示功率密度，以 Pascal^2/Hz 表示。")
MAN_END

MAN_BEGIN (U"Intro 3.4. Printing the spectrogram", U"ppgb", 20220907)
NORMAL (U"要打印声谱图，或者将其保存为 EPS 文件或复制到剪贴板以便插入到您的文字处理器中， "
	"您首先必须将其绘制到图像窗口（@@Picture window@）中。 "
	"您可以通过在 Sound 或 TextGrid 窗口的 Spectrogram 菜单中选择 ##Paint visible spectrogram...#（绘制可见声谱图...）来完成此操作。 "
	"然后，您可以从图像窗口的 File（文件）菜单中进行打印、保存为 EPS 文件， "
	"或复制到剪贴板（例如，以便在您的文字处理软件中进行粘贴）。")
MAN_END

MAN_BEGIN (U"Intro 3.5. The Spectrogram object", U"ppgb", 20220907)
NORMAL (U"要对声谱图进行更多操作，您可以在对象列表（@@List of Objects@）中创建一个 @Spectrogram（声谱图）对象。 "
	"您可以通过在 Sound 或 TextGrid 窗口的 Spectrogram 菜单中选择 ##Extract visible spectrogram#（提取可见声谱图）来完成此操作， "
	"也可以在列表中选中一个 Sound 对象，并从 Spectrum 菜单中选择 @@Sound: To Spectrogram...@（转换为声谱图...）。 "
	"在上述任一情况下，列表中都会出现一个全新的 Spectrogram 对象。 "
	"要将该 Spectrogram 对象绘制到图像窗口（@@Picture window@）， "
	"请选中它并选择 @@Spectrogram: Paint...|Paint...@ 命令。 "
	"从图像窗口中，您可以将其打印、保存为 EPS 文件或复制到剪贴板。 "
	"在动态菜单（@@Dynamic menu|dynamic menu@）中还有许多其他命令可用。")
MAN_END

MAN_BEGIN (U"Intro 3.6. Viewing a spectral slice", U"ppgb", 20220907)
INTRO (U"通过选择 @SoundEditor 和 @TextGridEditor 中 Spectrogram 菜单下的 ##View spectral slice#（查看频谱切片）， "
	"您可以查看时间光标处的即时频谱， "
	"或者当前时间选区内的平均频谱。")
ENTRY (U"光标处的频谱切片")
NORMAL (U"如果您在 SoundEditor 或 TextGridEditor 窗口的波形图中任意位置单击， "
	"该时间点上将出现一个光标。如果您随后选择 ##View spectral slice#， "
	"Praat 会在对象窗口中创建一个名为 %slice 的 @Spectrum（频谱）对象，并在 @SpectrumEditor 窗口中将其显示出来。 "
	"通过这种方式，您可以检查光标位置周围信号的频率内容。")
ENTRY (U"选区内的频谱切片")
NORMAL (U"如果您在 SoundEditor 或 TextGridEditor 窗口的波形图中拖动鼠标， "
	"静态选择（@@time selection|时间选区@）将会出现。如果您随后选择 ##View spectral slice#， "
	"Praat 同样会在对象窗口中创建一个名为 %slice 的 @Spectrum 对象，并在 @SpectrumEditor 窗口中将其显示。 "
	"通过这种方式，您可以检查选区内信号的频率内容。")
MAN_END


MAN_BEGIN (U"Intro 3.7. Configuring the spectral slice", U"ppgb", 20110128)
ENTRY (U"光标处的频谱切片")
NORMAL (U"Praat 的具体操作取决于您的声谱图设置（Spectrogram settings）。 "
	"假设%%window length%（窗长度）设置为 0.005 秒（5 毫秒）。 "
	"如果%%window shape%（窗形状）不是高斯窗（Gaussian），Praat 会提取该声音信号中 "
	"光标前 2.5 毫秒到光标后 2.5 毫秒之间的部分。 "
	"然后，Praat 将这一段 5 毫秒长的信号与窗口形状相乘（加窗），再使用 @@Sound: To Spectrum...@（转换为频谱...）中的方法计算频谱， "
	"计算出的频谱将放入对象窗口中并自动在编辑器窗口中打开。 "
	"如果窗形状是高斯窗，Praat 会提取该声音信号中 "
	"光标前 5 毫秒到光标后 5 毫秒之间的部分。此时的频谱计算将基于 "
	"10 毫秒的“物理”窗长度，尽管“有效”窗长度仍然是 5 毫秒 "
	"（详情请参阅 @@Intro 3.2. Configuring the spectrogram@）。")
ENTRY (U"选区内的频谱切片")
NORMAL (U"Praat 的具体操作同样取决于声谱图设置中的%%window shape%（窗形状）。 "
	"假设您的选区是 50 毫秒长。Praat 会提取整个选区， "
	"然后将这一段 50 毫秒长的信号与窗口形状相乘，计算频谱，再将其放入对象窗口中并在编辑器窗口中打开。 "
	"这个过程等同于先选择 ##Extract windowed selection...#（提取加窗选区...）（设置%%relative duration%（相对持续时间）为 1.0）， "
	"然后执行 ##To Spectrum...#（转换为频谱...）（开启 %fast 选项），最后点击 #Edit（编辑）。")
NORMAL (U"如果选用高斯窗，Praat 仍将仅使用该选区，而不会将其持续时间翻倍。 "
	"这意味着在这种情况下您看到的频谱将主要基于选区中心的一半， "
	"而靠近边缘的信号能量在很大程度上会被忽略。")
MAN_END

MAN_BEGIN (U"Intro 3.8. The Spectrum object", U"ppgb", 20030403)
NORMAL (U"要计算整个声音的傅里叶频谱， "
	"请选中一个 @Sound 对象，并选择 Spectrum 菜单下的 @@Sound: To Spectrum...|To Spectrum...@。 "
	"一个新的 @Spectrum（频谱）对象将会出现在@@List of Objects|对象列表@中。 "
	"若要查看、修改或聆听它的某些部分，请点击 @@View & Edit@。 "
	"要打印它，请先选中它并执行相应的 #Draw（绘制）命令，将该 Spectrum 对象绘制到图像窗口（@@Picture window@）中。")
MAN_END

MAN_BEGIN (U"Intro 4. Pitch analysis", U"ppgb", 20070905)
INTRO (U"本节介绍如何分析现有声音的音高曲线（音高轮廓）。")
LIST_ITEM (U"@@Intro 4.1. Viewing a pitch contour|Intro 4.1. 查看音高曲线@")
LIST_ITEM (U"@@Intro 4.2. Configuring the pitch contour|Intro 4.2. 设置音高曲线参数@")
LIST_ITEM (U"@@Intro 4.3. Querying the pitch contour|Intro 4.3. 查询音高曲线信息@")
LIST_ITEM (U"@@Intro 4.4. Printing the pitch contour|Intro 4.4. 打印音高曲线@")
LIST_ITEM (U"@@Intro 4.5. The Pitch object|Intro 4.5. Pitch 对象@")
MAN_END

MAN_BEGIN (U"Intro 4.1. Viewing a pitch contour", U"ppgb", 20110128)
NORMAL (U"要查看现有声音随时间变化的音高曲线， "
	"请在对象列表中选择一个 @Sound 或 @LongSound 对象，然后选择 @@View & Edit@。 "
	"屏幕上将弹出一个 @SoundEditor 窗口。 "
	"该窗口的下半部分将包含一条音高曲线，绘制为蓝色实线或一系列蓝色点。 "
	"如果您没有看到音高曲线，请从 Pitch 菜单中选择 @@Show pitch@（显示音高）。")
NORMAL (U"在窗口的右侧，您可能会看到三个以蓝色数字书写的音高数值： "
	"在最下方，您会看到可视音高范围的下限（通常为 75 Hz）；在最上方， "
	"您会看到音高范围的上限（通常为 600 Hz）；在两者之间的某个位置，您会看到光标处的即时音高值， "
	"或者是当前选区内的平均音高。")
MAN_END

MAN_BEGIN (U"Intro 4.2. Configuring the pitch contour", U"ppgb", 20231115 /*20190331*/)  /*2024*/
NORMAL (U"通过选择 Pitch 菜单中的 @@Pitch settings...@（音高设置...）， "
	"您可以决定音高曲线的显示和计算方式。 "
	"这些设置将在不同的 Praat 运行周期中被记录。 "
	"所有这些设置都具有默认的标准值（“出厂设置”），点击 #Standards（标准值）按钮即可恢复。")
ENTRY (U"%%Pitch floor and top%（音高分析范围下限与上限）设置")
NORMAL (U"这是音高分析中最关键的设置。 "
	"标准范围（对于滤波自相关分析法）是 50 到 800 Hz， "
	"这意味着音高分析算法只会寻找并输出 50 到 800 Hz 之间的数值 "
	"（且极少能探测到 400 到 800 Hz 之间的值）。 "
	"您在此处设置的范围将显示在分析窗口的右侧。")
NORMAL (U"您需要将该范围设置为适合您录音的发音人的数值， "
	"因为不同发音人的音高范围差异极大。 "
	"对于一些低沉的声音（例如成年男性的平均声线），您可能需要将下限设为 50 Hz，上限设为 600 Hz； "
	"对于一些高亢的声音（例如成年女性的平均声线），100 到 800 Hz 的范围可能更为合适； "
	"然而，在很多情况下，默认的 50 到 800 Hz 设置可以很好地适用于所有这些声音。 "
	"但在极端情况下，例如一些儿童在尖叫时其音高可以接近 2000 Hz； "
	"而在另一极端，吱嘎声（喉塞音/劈裂声/Creaky voice）的音高可能会低至 30 Hz； "
	"如果您正在研究这些特殊的声音情况，您可能需要对该设置进行测试和微调。")
NORMAL (U"以下是为什么必须提供这些范围设置的技术原因。如果音高下限设为 50 Hz， "
	"音高分析算法需要一个 60 毫秒长的分析窗。 "
	"即为了计算例如 0.850 秒处的基频（F0）， "
	"Praat 需要提取并考虑声音信号中从 0.820 到 0.880 秒的部分。 "
	"这 60 毫秒对应于 3 个最长的音高周期（3 / 50 = 0.060 秒）。 "
	"如果您将音高下限降低到 25 Hz，分析窗将扩大到 120 毫秒 "
	"（同样是 3 个最长音高周期），即必须提取并计算 0.790 到 0.910 秒之间的所有信号。 "
	"这会导致声学细节的时间分辨率变差，难以观察到快速的 F0 变化。")
NORMAL (U"因此，设置音高范围的下限是音高分析的一项硬性技术要求。 "
	"如果您设置得太低，您将错失非常快速的 F0 变化；如果设置得太高， "
	"您将错失非常低的 F0 基频值。对于儿童的声音，您通常可以使用 200 Hz 作为下限， "
	"尽管使用 50 Hz 作为下限也仍然能为您提供与低沉声音相同的时间分辨率。")
ENTRY (U"%%Units%（音高单位）设置")
NORMAL (U"该设置决定了垂直音高刻度的单位。大多数人喜欢以赫兹（Hz）来查看音高范围， "
	"但也有其他几种可选的单位（例如半音 semitones 等）。")
ENTRY (U"显示范围与分析范围不同")
NORMAL (U"通常，编辑器窗口中可视的音高范围等于分析算法可计算出的音高范围。 "
	"如果您将分析范围设置为 50 到 800 Hz，那么您在编辑器窗口中看到的刻度也是 50 到 800 Hz。 "
	"如果曲线中的音高值恰好落在 350 到 400 Hz 之间， "
	"您可能希望将刻度局部放大到该 350-400 Hz 区域。 "
	"您通常可以通过在 @@Pitch settings...@ 窗口中修改音高范围来达到此目的。 "
	"但是，这样一来，分析算法本身的计算范围也改变了，导致曲线的形态可能发生改变。 "
	"如果您不希望曲线发生改变，您可以将显示范围设置（%%View range%） "
	"从 “0.0 (= auto)” - “0.0 (= auto)”（自动调整）修改为具体的数值，例如 “350” - “400”。")
ENTRY (U"延伸阅读")
NORMAL (U"有关更多详细信息，请参阅：")
LIST_ITEM (U"@@how to choose a pitch analysis method|如何选择音高分析方法@")
LIST_ITEM (U"@@pitch analysis by filtered autocorrelation|滤波自相关音高分析法@")
LIST_ITEM (U"@@pitch analysis by raw cross-correlation|原始互相关音高分析法@")
LIST_ITEM (U"@@pitch analysis by raw autocorrelation|原始自相关音高分析法@")
LIST_ITEM (U"@@pitch analysis by filtered cross-correlation|滤波互相关音高分析法@")
MAN_END

MAN_BEGIN (U"Time step settings...", U"ppgb", 20231115 /*20031003,20220814*/)
INTRO (U"这是 @SoundEditor 和 @TextGridEditor 中 Analysis（分析）菜单下的一个命令， "
	"用于决定基频、共振峰和音强连续测量之间的时间步长（测量时间间隔）。")
ENTRY (U"自动时间步长")
NORMAL (U"建议您将时间步长策略（%%Time step strategy%）设置为 #Automatic（自动）。 "
	"这样，Praat 就会计算出值足够精确的音高、共振峰和音强数据，从而绘制出 "
	"准确可靠的音高曲线、共振峰曲线和音强曲线。通常情况下，Praat 会在每个分析窗内 "
	"计算 4 个值（“四倍过采样”）。")
NORMAL (U"如 @@Sound: To Pitch (filtered ac)...@ 中所述， "
	"Praat 进行音高分析的标准时间步长是 0.75 除以音高下限， "
	"例如，如果音高下限为 50 Hz，则时间步长为 0.015 秒。 "
	"采用这种方式，在 60 毫秒（即 3 / 50 Hz）长的分析窗内将会有 4 个音高测量点。")
NORMAL (U"如 @@Sound: To Formant (burg)...@ 中所述，Praat 进行共振峰测量的标准时间步长是窗长度（%%Window length%）除以 4， "
	"例如，如果窗长度为 0.025 秒，则步长为 6.25 毫秒。")
NORMAL (U"如 @@Sound: To Intensity...@ 中所述，Praat 进行音强测量的标准时间步长是 0.8 除以音高下限， "
	"例如，如果音高下限为 50 Hz，时间步长将为 16 毫秒。 "
	"在此设置下，在 64 毫秒（即 3.2 / 50 Hz）长的音强分析窗内将会有 4 个音强测量点。")
ENTRY (U"固定时间步长")
NORMAL (U"您可以通过将时间步长策略（%%Time step strategy%）设置为 #Fixed（固定）来覆盖自动步长设置。 "
	"此时，固定时间步长（%%Fixed time step%）参数将决定 Praat 实际采用的步长： "
	"如果您将其设置为 0.001 秒，Praat 将会为每 1 毫秒都计算音高、共振峰和音强值。 "
	"请注意，这会显著降低编辑器窗口的运行速度，因为该步长比自动时间步长的默认值要小得多（见上文）。")
NORMAL (U"将时间步长增大至例如 0.1 秒可以加快编辑器窗口的响应速度， "
	"但会降低音高、共振峰和音强曲线的精确度（由于发生了%欠采样%（undersampled））， "
	"这会直接影响您的测量精度和脉冲点定位。")
NORMAL (U"如果在每个分析窗内音高测量点少于 2.0 个， "
	"Praat 将把音高曲线绘制为彼此分离的蓝色小圆盘形状， "
	"而不是连续的蓝色实线，以此警告您发生了欠采样。 "
	"例如，如果音高下限为 75 Hz，当时间步长大于 0.02 秒时，Praat 会将音高曲线绘制为离散的圆盘。")
ENTRY (U"视窗自适应时间步长")
NORMAL (U"覆盖标准时间步长的另一种方式是将时间步长策略（%%Time step strategy%）设置为 ##View-dependent#（视窗自适应）。 "
	"此时，单视窗时间步数（%%Number of time steps per view%）参数将决定实际的时间步长： "
	"如果您将其设置为 100，Praat 将在当前可见视窗内固定计算 100 个音高、共振峰和音强点。 "
	"更具体地讲：如果您将视窗缩放至 3 秒，Praat 将在间隔 0.03 秒处为您显示共 100 个测量点（如果您靠近信号边缘，可能少于 100 个）。 "
	"与固定时间步长设置相同，在发生欠采样时，Praat 会将音高绘制为离散的圆盘。 "
	"如果您希望绘制音高曲线的速度不受缩放比例的影响，可以使用此设置。")
MAN_END

MAN_BEGIN (U"Intro 4.3. Querying the pitch contour", U"ppgb", 20040614)
NORMAL (U"通过选择 @SoundEditor 或 @TextGridEditor 中 Pitch 菜单下的 @@Get pitch@（获取音高）， "
	"您可以获取关于光标处或当前选区内音高（基频）的信息。 "
	"如果窗口内有可见的光标线，##Get pitch# 会在信息窗口（@@Info window@）中输出该时间点处的线性插值音高； "
	"如果窗口内有选定的一段时间区域，##Get pitch# 会在信息窗口中输出当前选区可见部分内的平均音高； "
	"否则，##Get pitch# 将输出整个声音对象当前可见部分的平均音高。")
MAN_END

MAN_BEGIN (U"Intro 4.4. Printing the pitch contour", U"ppgb", 20070905)
NORMAL (U"要打印音高曲线，或者将其保存为 EPS 文件或复制到剪贴板中以便插入到您的文字处理器中， "
	"您必须首先将其绘制到图像窗口（@@Picture window@）中。 "
	"您可以通过在 Sound 或 TextGrid 窗口的 Pitch 菜单中选择 ##Draw visible pitch contour...#（绘制可见音高曲线...）来完成此操作。 "
	"然后，在图像窗口的 File（文件）菜单中，您可以对其进行打印、保存为 EPS 文件， "
	"或复制到剪贴板中（例如，随后在您的文字处理软件中执行“粘贴”）。")
MAN_END

MAN_BEGIN (U"Intro 4.5. The Pitch object", U"ppgb", 20110128)
NORMAL (U"在 @SoundEditor 或 @TextGridEditor 窗口中可见的音高曲线， "
	"可以作为一个单独的 @Pitch（音高）对象复制到对象列表（@@List of Objects@）中。为此， "
	"请选择 Pitch 菜单下的 @@Extract visible pitch contour@（提取可见音高曲线）。")
NORMAL (U"获取独立 Pitch 对象的另一种方法是在列表中选中一个 @Sound 对象， "
	"然后选择 @@Sound: To Pitch...@（转换为音高...）（推荐方法）或者 @@Periodicity menu|周期性菜单@ 下的任何其他算法。")
NORMAL (U"要查看和修改 Pitch 对象的内容，请在列表中选中它并点击 @@View & Edit@（查看与编辑）。 "
	"这将在屏幕上打开一个 @PitchEditor（音高编辑器）窗口。")
NORMAL (U"要将音高曲线保存到磁盘，请在列表中选择该 @Pitch 对象，然后执行 @@Save menu|保存菜单@ 中的命令。")
NORMAL (U"稍后，您可以使用 @@Open menu|打开菜单@ 中的 @@Read from file...@（从文件读取...）重新读入保存的音高文件。")
NORMAL (U"要将 @Pitch 对象绘制到图像窗口（@@Picture window@），请选中它并选择 @@Draw menu|绘制菜单@ 中的命令。 "
	"在图像窗口中，您可以对其进行打印、保存为 EPS 文件，或复制到剪贴板中以便插入文字处理软件。")
MAN_END

MAN_BEGIN (U"Advanced pulses settings...", U"ppgb", 20110220)
INTRO (U"这是 @SoundEditor 或 @TextGridEditor 窗口中 Pulses 菜单下的一个命令。 "
	"在修改高级脉冲设置之前，请确保您已经理解了 @@Voice|嗓音分析@ 教程的内容。")
NORMAL (U"有关最大周期因子（##Maximum period factor#）设置的信息，请参阅 @@PointProcess: Get jitter (local)...@。 "
	"在大多数情况下，默认设置是最好的。 "
	"周期下限（##Period floor#）和周期上限（##Period ceiling#）参数是根据音高下限与上限（@@Pitch settings...@） "
	"通过 @@Voice 2. Jitter|嗓音分析 2. 基频微扰@ 中给出的公式计算得出的。")
MAN_END

MAN_BEGIN (U"Intro 5. Formant analysis", U"ppgb", 20030316)
INTRO (U"本节介绍如何分析现有声音的共振峰曲线（共振峰轮廓）。")
LIST_ITEM (U"@@Intro 5.1. Viewing formant contours|Intro 5.1. 查看共振峰曲线@")
LIST_ITEM (U"@@Intro 5.2. Configuring the formant contours|Intro 5.2. 设置共振峰曲线参数@")
LIST_ITEM (U"@@Intro 5.3. Querying the formant contours|Intro 5.3. 查询共振峰曲线信息@")
LIST_ITEM (U"@@Intro 5.4. The Formant object|Intro 5.4. Formant 对象@")
MAN_END

MAN_BEGIN (U"Intro 5.1. Viewing formant contours", U"ppgb", 20110128)
NORMAL (U"要查看声音共振峰随时间的变化曲线，请在对象列表中选中一个 @Sound 或 @LongSound 对象，然后选择 @@View & Edit@。 "
	"屏幕上将弹出一个 @SoundEditor 窗口。 "
	"该窗口的分析绘图区域中会包含共振峰曲线，绘制为红色的散点。 "
	"如果您没有看到共振峰，请从 Formant 菜单中选择 @@Show formant@（显示共振峰）。")
MAN_END

MAN_BEGIN (U"Intro 5.2. Configuring the formant contours", U"ppgb", 20030316)
NORMAL (U"您可以通过 Formant 菜单进行设置的共振峰分析参数是非常重要的。 "
	"对于女性的发音，您可能需要将最大频率设置为 5500 Hz； "
	"对于男性的发音，则应将其设置为 5000 Hz。 "
	"有关分析参数的更多信息，请参阅 @@Sound: To Formant (burg)...@。")
MAN_END

MAN_BEGIN (U"Intro 5.3. Querying the formant contours", U"ppgb", 20040616)
NORMAL (U"通过选择 @SoundEditor 或 @TextGridEditor 中 Formant 菜单下的 @@Get first formant@（获取第一共振峰）， "
	"您可以获取光标处或选区内第一共振峰（F1）的信息。 "
	"如果窗口中有可见的光标，##Get first formant# 会在信息窗口（@@Info window@）中输出该时间点处的线性插值第一共振峰频率。 "
	"如果窗口中选定了某个时间段，##Get first formant# 会在信息窗口中输出该选区可见部分内的平均第一共振峰频率。 "
	"获取第二共振峰（@@Get second formant@）及更高共振峰以此类推。")
MAN_END

MAN_BEGIN (U"Intro 5.4. The Formant object", U"ppgb", 20030316)
NORMAL (U"在 @SoundEditor 或 @TextGridEditor 窗口中可见的共振峰曲线， "
	"可以作为一个单独的 @Formant（共振峰）对象复制到对象列表（@@List of Objects@）中。为此， "
	"请选择 Formant 菜单下的 @@Extract visible formant contour@（提取可见共振峰曲线）。")
NORMAL (U"获取独立 Formant 对象的另一种方法是在列表中选中一个 @Sound 对象， "
	"然后选择 @@Sound: To Formant (burg)...@（Burg 算法转换共振峰...）（推荐方法）或者 @@Formants & LPC menu|共振峰与线性预测分析菜单@ 下的任何其他算法。")
ENTRY (U"将共振峰曲线保存到磁盘")
NORMAL (U"要将共振峰曲线数据保存到磁盘，请在列表中选择该 @Formant 对象，然后执行 @@Save menu|保存菜单@ 中的命令。")
NORMAL (U"稍后，您可以使用 @@Open menu|打开菜单@ 中的 @@Read from file...@（从文件读取...）重新读入保存的共振峰文件。")
ENTRY (U"绘制共振峰曲线")
NORMAL (U"要将 @Formant 对象绘制到图像窗口（@@Picture window@），请选中它并选择 @@Draw menu|绘制菜单@ 中的命令。 "
	"在图像窗口中，您可以对其进行打印、保存为 EPS 文件，或复制到剪贴板中以便插入文字处理软件。")
MAN_END

MAN_BEGIN (U"Intro 6. Intensity analysis", U"ppgb", 20030316)
INTRO (U"本节介绍如何分析现有声音的音强曲线（强度轮廓/能量曲线）。")
LIST_ITEM1 (U"@@Intro 6.1. Viewing an intensity contour|Intro 6.1. 查看音强曲线@")
LIST_ITEM1 (U"@@Intro 6.2. Configuring the intensity contour|Intro 6.2. 设置音强曲线参数@")
LIST_ITEM1 (U"@@Intro 6.3. Querying the intensity contour|Intro 6.3. 查询音强曲线信息@")
LIST_ITEM1 (U"@@Intro 6.4. The Intensity object|Intro 6.4. Intensity 对象@")
MAN_END

MAN_BEGIN (U"Intro 6.1. Viewing an intensity contour", U"ppgb", 20110128)
INTRO (U"要查看声音音强随时间的变化曲线，请在对象列表中选中一个 @Sound 或 @LongSound 对象，然后选择 @@View & Edit@。 "
	"屏幕上将弹出一个 @SoundEditor 窗口。 "
	"该窗口的分析绘图区域中会包含一条音强曲线，绘制为黄色或绿色的实线 "
	"（如果未显示，请从 Intensity 菜单中选择 ##Show intensity#（显示音强））。 "
	"该操作在 @TextGridEditor 中同样适用。")
MAN_END

MAN_BEGIN (U"Intro 6.2. Configuring the intensity contour", U"ppgb", 20041123)   // 2023
INTRO (U"通过选择 Intensity 菜单中的 ##Intensity settings...#（音强设置...）， "
	"您可以控制音强曲线的计算和显示方式。")
ENTRY (U"显示范围")
NORMAL (U"By changing these two numbers you can set the vertical scale. "
	"The standard setting is from 50 to 100 dB, but if you are interested in the power of the background noise "
	"you may want to set it to the range from 0 to 100 dB.")
ENTRY (U"均值计算方法")
NORMAL (U"均值计算发生在您选定了一段时间区域（而不是将光标放在单一时间点）时。 "
	"音强曲线左侧或右侧显示的绿色 dB 数值将指示当前选区内的平均音强。 "
	"这与您从 Intensity 菜单中选择 ##Get intensity#（获取音强）时获得的值相同。 "
	"您可以选择适用于 @@Intensity: Get mean...@（获取平均音强...）的三种均值计算方法中的任何一种， "
	"或者选择该选区内的中位数（#median）音强。")
ENTRY (U"音高下限设置")
NORMAL (U"音强曲线是经过%平滑（smoothed）处理的，因为您通常不希望音强曲线随着音高周期内部的微小强度变化而上下起伏。 "
	"为了避免这种与基频周期同步的波动，每个时间点处的音强值都是对其周围许多邻近时间点进行加权平均计算出来的。 "
	"加权是通过高斯（“双 Kaiser”）窗实现的，其窗的持续时间由 "
	"##Pitch floor#（音高下限）设置决定（参见 @@Intro 4.2. Configuring the pitch contour@）。 "
	"如果您希望看到比平常更多的细节，可以提高音高下限；若希望获得比平常更多的平滑效果，可以降低音高下限。 "
	"有关更多信息，请参阅 @@Sound: To Intensity...@。")
ENTRY (U"是否减去平均气压（直流分量）？")
NORMAL (U"许多麦克风、麦克风前置放大器或录音系统中的其他硬件组件， "
	"可能会在空气压力信号中添加一个恒定的偏移量（即%%DC 偏移/直流分量%）。 "
	"您可以在波形图的静音区域中观察到这一现象， "
	"此时静音处的平均振幅并不是零，而是围绕某个非零值小幅波动。 "
	"通常您不会把这个恒定偏移的静态压力计算进声学能量，即音强曲线不应该 "
	"计入此恒定压力所对应的能量。 "
	"如果您开启了 ##Subtract mean pressure#（减去平均气压）开关（默认设置也是开启的）， "
	"Praat 在计算每个时间点处的音强值时，会先减去该时间点周围的平均气压， "
	"然后再应用高斯窗进行加权计算。")
MAN_END

MAN_BEGIN (U"Intro 6.3. Querying the intensity contour", U"ppgb", 20041123)
INTRO (U"要查询光标处的音强值，或当前选区可见部分内的平均音强值， "
	"请从 Intensity 菜单中选择 ##Get intensity#（获取音强）或按下 F11 键。您将在信息窗口中获得与音强曲线左侧或右侧显示的绿色数值相同的 dB 值，但包含更多的小数位数。")
MAN_END

MAN_BEGIN (U"Intro 6.4. The Intensity object", U"ppgb", 20041123)
NORMAL (U"要打印音强曲线，或者将其保存为 EPS 文件或复制到剪贴板中以便插入到您的文字处理器中， "
	"您必须首先在对象列表（@@List of Objects@）中创建一个 @Intensity（音强）对象。 "
	"您可以通过在 SoundEditor 或 TextGridEditor 窗口的 Intensity 菜单中选择 ##Extract visible intensity contour#（提取可见音强曲线）， "
	"或者在列表中选中一个 Sound 对象并选择 @@Sound: To Intensity...@（转换为音强...）来完成此操作。 "
	"在上述任一情况下，列表中都会出现一个全新的 Intensity 对象。 "
	"要将该 Intensity 对象绘制到图像窗口（@@Picture window@），请选中它并选择 ##Draw...#（绘制...）命令。 "
	"从图像窗口中，您可以将其打印、保存为 EPS 文件，或直接复制到剪贴板。")
MAN_END

MAN_BEGIN (U"Intro 7. Annotation", U"ppgb", 20110129)
INTRO (U"您可以对现有的 @Sound 对象和声音文件（@LongSound 对象）进行标注。")
NORMAL (U"标注的数据将保存在一个 @TextGrid（文本网格）对象中。该对象与声音对象是相互分离的， "
	"这意味着在对象列表中您通常会看到两个对象：一个 Sound 或 LongSound 对象， "
	"以及一个 TextGrid 对象。")
ENTRY (U"创建 TextGrid")
NORMAL (U"您可以通过选中 Sound 或 LongSound，然后选择 #Annotate 菜单下的 @@Sound: To TextGrid...@（转换为 TextGrid...） "
	"或 @@LongSound: To TextGrid...@（转换为 TextGrid...）来创建新的空白 TextGrid 对象（当您选中 Sound 或 LongSound 时，该菜单会出现在对象窗口中）。 "
	"通过这种方式，@TextGrid 的时间范围将自动与声音的时间范围完全相同。 "
	"（相比之下，如果您从 @@New menu|新建菜单@ 中选择 @@Create TextGrid...@（创建 TextGrid...）， "
	"则必须自行手动输入指定的时间范围。）")
NORMAL (U"在创建 TextGrid 时，您需要指定层级（%tiers（层级））的名称。例如，如果您想将 "
	"声音切分为单词（words）和音素（phonemes），您可能需要创建两个层级，并命名为 "
	"\"words\" 和 \"phonemes\"（您稍后可以轻松添加、删除和重命名层级）。 "
	"由于这两个层级都是%%interval tiers%（区间层级）（因为您是对单词和音素边界之间的区间进行标注， "
	"而不是对边界本身进行标注），因此在层级名称（%%Tier names%）中指定 \"phonemes words\"， "
	"并保持点层级（%%Point tiers%）为空。")
ENTRY (U"查看与编辑")
NORMAL (U"您可以单独编辑一个 TextGrid 对象，但通常您也希望在编辑器窗口中同时看到对应的 "
	"声音信号。为实现这一点，请在列表中同时选中 Sound（或 LongSound）和 "
	"TextGrid 对象，然后点击 @@View & Edit@。屏幕上将弹出一个 @TextGridEditor 窗口。 "
	"与 Sound 编辑器类似，TextGrid 编辑器也会向您显示声谱图、音高曲线、共振峰曲线和音强曲线。 "
	"该编辑器允许您添加、删除和编辑标注、边界线以及层级。在 TextGridEditor 的 Help（帮助）菜单下， "
	"您可以找到 @TextGridEditor 的手册页。强烈建议您通读该页，因为它会向您展示 "
	"如何快速缩放（拖动鼠标）、播放（单击相应的控制矩形）以及编辑标注（直接键入即可）。")
ENTRY (U"保存")
NORMAL (U"您通常会使用 @@Save as text file...@（保存为文本文件...） "
	"或 @@Save as short text file...@（保存为简短文本文件...）将 TextGrid 写入磁盘。 "
	"虽然 @@Save as binary file...@（保存为二进制文件...）也同样有效，但其他两种格式 "
	"生成的文件可以使用任何普通的文本编辑器打开并直接阅读。")
NORMAL (U"无论您如何保存，稍后都可以使用 @@Read from file...@（从文件读取...）将 TextGrid 重新读取到 Praat 中。")
MAN_END

MAN_BEGIN (U"Intro 8. Manipulation", U"ppgb", 20021212) //2025
LIST_ITEM (U"@@Intro 8.1. Manipulation of pitch|Intro 8.1. 操控音高@")
LIST_ITEM (U"@@Intro 8.2. Manipulation of duration|Intro 8.2. 操控时长@")
LIST_ITEM (U"@@Intro 8.3. Manipulation of intensity|Intro 8.3. 操控音强@")
LIST_ITEM (U"@@Intro 8.4. Manipulation of formants|Intro 8.4. 操控共振峰@")
MAN_END

MAN_BEGIN (U"Intro 8.1. Manipulation of pitch", U"ppgb", 20220814)
INTRO (U"要修改现有 @Sound 对象的音高曲线， "
	"请选中该 @Sound 对象，然后点击 ##To Manipulation#（转换为 Manipulation 对象）。 "
	"列表中随后将出现一个 @Manipulation（声音操控）对象。 "
	"您可以选中它并点击 @@View & Edit@ 以打开 @ManipulationEditor 操控编辑器窗口， "
	"它将把音高曲线（@PitchTier）显示为一系列粗蓝色点。 "
	"为了减少点的数量，您可以从 Pitch 菜单中选择 ##Stylize pitch (2 st)#（音高简捷化/平滑化）； "
	"这样您就可以在时间-音高区域内轻松地拖动这些点 "
	"（按住 Option 键/Alt 键可限制拖动方向仅为垂直移动，按住 Command 键/Ctrl 键可限制为仅水平移动）。")
NORMAL (U"如果您单击窗口下方的任何播放条矩形 "
	"（或者选择 Play 菜单下的任何命令）， "
	"您就可以聆听修改后的声音。通过按住 Shift 键播放，您将听到 "
	"原始声音。")
NORMAL (U"要将修改后的声音生成为一个单独的声音对象， "
	"请选择 File 菜单下的 ##Publish resynthesis#（输出重合成声音）。")
NORMAL (U"如果您同时也修改了时长曲线（参见 @@Intro 8.2. Manipulation of duration@）， "
	"合成的声音将同时基于修改后的音高与时长。")
ENTRY (U"复制/克隆音高曲线")
NORMAL (U"如果您想将一个 Manipulation 对象的音高曲线用作另一个 Manipulation 对象的音高曲线， "
	"您可以首先选中第一个 Manipulation 对象并选择 ##Extract pitch tier#（提取音高层）， "
	"然后将生成的 PitchTier 对象和另一个 Manipulation 对象同时选中 "
	"（...）并选择 ##Replace pitch tier#（替换音高层）。")
NORMAL (U"如果你想直接克隆，可以先点击 PitchTier，然后按住 @@Command-click|Ctrl 键单击@ Manipulation，然后选择 ##Replace pitch tier#。")
ENTRY (U"精确地操控音高")
NORMAL (U"如果您极其清楚自己想要什么样的音高曲线， "
	"您可以通过 New 菜单中的 @@Create PitchTier...@（创建 PitchTier...）来新建一个空白的 PitchTier， "
	"然后使用 @@PitchTier: Add point...@（添加点）命令在其上添加音高点。")
NORMAL (U"例如，假设您希望音高在 1 秒内从 350 Hz 降到 150 Hz。 "
	"您先创建 PitchTier，然后在 0 秒处添加一个 350 Hz 的点， "
	"在 1 秒处添加一个 150 Hz 的点。 "
	"之后您就可以按上述方式将该 PitchTier 放入一个 Manipulation 对象中进行合成。")
MAN_END

MAN_BEGIN (U"Intro 8.2. Manipulation of duration", U"ppgb", 20200901)
INTRO (U"您可以使用 Praat 来修改现有声音中各个部分的相对时长（持续时间）。")
NORMAL (U"首先，您选中一个 @Sound 对象并点击 ##To Manipulation#。 "
	"列表中随后将出现一个 @Manipulation 对象。 "
	"然后您可以点击 @@View & Edit@ 来打开 @ManipulationEditor 编辑器窗口， "
	"该窗口中会显示一条空白的 @DurationTier（时长层）。 "
	"您可以通过在 Dur 菜单中选择 ##Add duration point at cursor#（在光标处添加时长点）来为该层级添加目标。 "
	"这些目标将显示为蓝色的点，您可以在时长区域中轻松地拖动它们。")
NORMAL (U"如果您单击窗口下方的任何播放条矩形 "
	"（或者选择 Play 菜单下的任何命令）， "
	"您就可以聆听修改后的声音。通过按住 Shift 键播放，您将听到 "
	"原始声音。")
NORMAL (U"To get the modified sound as a separate object, "
	"choose ##Publish resynthesis# from the @@File menu@.")
NORMAL (U"如果您同时也修改了音高曲线（参见 @@Intro 8.1. Manipulation of pitch@）， "
	"合成的声音将同时基于修改后的时长和音高。")
ENTRY (U"精确地操控时长")
NORMAL (U"如果您极其精确地知道需要修改的时间点和相对时长比例，建议编写脚本（参见 @Scripting）。 "
	"例如，假设您有一段 355 毫秒长的声音，您希望将前 85 毫秒缩短为 70 毫秒， "
	"而将剩余的 270 毫秒缩短为 200 毫秒。")
NORMAL (U"在前 85 毫秒内，您的相对时长比例应该是 70/85， "
	"在最后的 270 毫秒内，比例应该是 200/270。 "
	"DurationTier（时长层）采用的是线性插值，因此它只能近似地逼近这些精确的时间点， "
	"但幸运的是，您可以达到任意想要的逼近精度：")
CODE (U"Create DurationTier: \"shorten\", 0, 0.085 + 0.270")
CODE (U"Add point: 0.000, 70/85")
CODE (U"Add point: 0.084999, 70/85")
CODE (U"Add point: 0.085001, 200/270")
CODE (U"Add point: 0.355, 200/270")
NORMAL (U"要将该 DurationTier 放回 Manipulation 对象中，请在列表中同时选中这两个对象 "
	"（例如，先单击 DurationTier，然后按住 @@Command-click|Ctrl 键单击@ Manipulation 对象）， "
	"最后选择 ##Replace duration tier#（替换时长层）。")
MAN_END

MAN_BEGIN (U"Intro 8.3. Manipulation of intensity", U"ppgb", 20110128)
INTRO (U"您可以修改现有声音的音强曲线（强度轮廓）。")
NORMAL (U"尽管声音的音高和时长可以使用 @ManipulationEditor 进行修改 "
	"（参见 @@Intro 8.1. Manipulation of pitch@ 与 @@Intro 8.2. Manipulation of duration@）， "
	"但强度曲线（音强）的修改方式会有所不同。")
NORMAL (U"您可以通过 @@New menu|新建菜单@ 中的 @@Create IntensityTier...@（创建 IntensityTier...）命令来新建一个 @IntensityTier（音强层）。 "
	"然后通过 @@View & Edit@ 在该层级上添加点。 "
	"之后，您可以通过在列表中同时选中 @Sound 对象和 IntensityTier 对象， "
	"然后点击 @@Sound & IntensityTier: Multiply|Multiply@（相乘）来将该层与声音进行“乘法”合成。 "
	"IntensityTier 中的点代表以 dB 为单位的相对强度； "
	"因此，声音中的声压值将乘以 10^^(dB/20)^。")
NORMAL (U"除了 IntensityTier，您也可以使用 @AmplitudeTier（振幅层）； "
	"当您为选中的 Sound 和 AmplitudeTier 对象点击 #Multiply（相乘）时， "
	"声音中的声压值将直接乘以 AmplitudeTier 中的值。")
MAN_END

MAN_BEGIN (U"Intro 8.4. Manipulation of formants", U"ppgb", 20010408)
INTRO (U"操控共振峰曲线的过程无法像操控音高、时长或音强曲线那样简单直接。 "
	"有关如何在 Praat 中修改共振峰的详细解释，请参阅 @@Source-filter synthesis@（源-滤波器合成）教程。")
MAN_END


/*
 * Who uses Praat?
 * phonetics
 * linguistics
 * speech pathology
 * psychology
 * bioacoustics: e.g.
hapalemur, crow, monkey, frog, turtle dove, grasshopper, cricket, alligator, crocodile,
gecko, elephant, swallow, chicken, dolphin, humpback, [killer] whale, [electric] fish,
sparrow, meerkat, [fruit] bat, lion, parrot, red deer, sperm whale, [bearded] seal, mouse, cracid, chacma baboon
* music
*/

MAN_BEGIN (U"Labelling", U"ppgb", 20010408)
INTRO (U"See @@Intro 7. Annotation@.")
MAN_END

MAN_BEGIN (U"List of Objects", U"ppgb", 20210228)
INTRO (U"A list in the left-hand part of the @@Objects window@.")
ENTRY (U"Purpose")
NORMAL (U"If you select one or more @objects in this list, "
	"the possible actions that you can perform with the selected objects "
	"will appear in the @@Dynamic menu@.")
ENTRY (U"How to select objects")
NORMAL (U"To select one object (and deselect all the others), click on the object.")
NORMAL (U"To extend the selection, drag the mouse or use Shift-click.")
NORMAL (U"To change the selection of one object (without changing the others), use @@Command-click@.")
MAN_END

MAN_PAGES_BEGIN
R"~~~(
################################################################################
"New menu"
© Paul Boersmma 2016,2023

The ##New menu# is one of the menus in the @@Objects window@.
You use this menu to create new objects from scratch. It contains the following commands:

• @@Record mono Sound...
• @@Record stereo Sound...

, Sound:
	• @@Create Sound as pure tone...
	• @@Create Sound from formula...
	• @@Create Sound as tone complex...
	• @@Create Sound as gammatone...
	• @@Create Sound as Shepard tone...
• @@Create TextGrid...

, Tiers:
	• @@Create empty PointProcess...
	• @@Create Poisson process...
	• @@Create PitchTier...
	• @@Create FormantGrid...
	• @@Create IntensityTier...
	• @@Create DurationTier...
	• @@Create AmplitudeTier...

• @@Create Corpus...

, Tables:
	• @@Create Table with column names...
	• @@Create Table without column names...
	• ##Create TableOfReal...
	, Datasets from the literature:
		• @@Create formant table (Peterson & Barney 1952)
		///• Create formant table (Hillenbrand et al. 1995)
		• @@Create formant table (Pols & Van Nierop 1973)
		• @@Create formant table (Weenink 1985)
		• @@Create H1H2 table (Keating & Esposito 2006)
		• @@Create Table (Ganong 1980)
		• @@Create iris data set
		,
		• @@Create TableOfReal (Pols 1973)...
		• @@Create TableOfReal (Van Nierop 1973)...
		• @@Create TableOfReal (Weenink 1985)...
		• @@Create TableOfReal (Sandwell 1987)

, Stats:
	, Multidimensional scaling:
		• @@Multidimensional scaling@ tutorial
		• Create letter R example...
		• Create INDSCAL Carrol Wish example...
		• Create Configuration...
		• Draw splines...
		• Draw MDS class relations

, Generics:
	, Matrix:
		• @@Create Matrix...@ (from a formula)
		• @@Create simple Matrix...@ (from a formula)
		• @@Create simple Matrix from values...
	, Photo:
		• @@Create Photo...@ (from a formula)
		• @@Create simple Photo...@ (from a formula)
	, Polygon:
		• @@Create Polygon from values...
	, Strings:
		• @@Create Strings as file list...
		• @@Create Strings as folder list...
		• @@Create Strings from tokens...
	• @@Create Permutation...
	, Polynomial:
		• @@Create Polynomial...
		• ##Create Polynomial from product terms...
		• ##Create Polynomial from real zeros...
		• @@Create LegendreSeries...
		• @@Create ChebyshevSeries...
		• @@Create MSpline...
		• @@Create ISpline...
, Acoustic synthesis (Klatt):
	• @KlattGrid help
	• @@Create KlattGrid...
	• @@Create KlattGrid from vowel...
, Articulatory synthesis:
	• @@Articulatory synthesis@ tutorial
	• ##Create Articulation...
	• @@Create Speaker...
	• @@Create Artword...
	• ##Create VocalTract from phone...
, Text-to-speech synthesis:
	• @@Create SpeechSynthesizer...
, Constraint grammars:
	• @@OT learning@ tutorial
	• @@Create NoCoda grammar
	• ##Create place assimilation grammar
	• ##Create place assimilation distribution
	• @@Create tongue-root grammar...
	• ##Create metrics grammar...
	• ##Create multi-level metrics grammar...
, Symmetric neural networks:
	• ##Create empty Network...
	• ##Create rectangular Network...
	• ##Create rectangular Network (vertical)...
	• ##Create Net as deep belief network...
, Feedforward neural networks:
	• @@Create FFNet...
	• @@Create iris example...
	, Advanced:
		• @@Create FFNet (linear outputs)...
		• ##Create PatternList...
		• ##Create Categories...

To create new objects from files on disk, use the @@Open menu@ instead.
Objects can also often be created from other objects, with commands that start with ##To#.
################################################################################
)~~~"
MAN_PAGES_END

MAN_BEGIN (U"Objects window", U"ppgb", 20230325)
INTRO (U"One of the two main windows in the Praat program.")
ENTRY (U"Subdivision")
LIST_ITEM (U"To the left: the @@List of Objects@.")
LIST_ITEM (U"To the right: the @@Dynamic menu@.")
ENTRY (U"Fixed buttons")
NORMAL (U"The following buttons appear below the List of Objects:")
LIST_ITEM (U"• @@Rename...")
LIST_ITEM (U"• @@Info")
LIST_ITEM (U"• @@Copy...")
LIST_ITEM (U"• @@Remove")
LIST_ITEM (U"• @@Inspect")
ENTRY (U"Menus")
LIST_ITEM (U"The Objects window contains several fixed menus: "
	"the #Praat, #New, #Open, and #Help menus. "
	"It also contains the @@Save menu@, whose contents vary with the kinds of selected objects, "
	"and must, therefore, be considered part of the dynamic menu.")
ENTRY (U"The Praat menu")
LIST_ITEM (U"• @@New Praat script@: creates an empty @@ScriptEditor@")
LIST_ITEM (U"• @@New Praat notebook@: creates an empty @@NotebookEditor@")
LIST_ITEM (U"• @@Open Praat script...@: creates a @@ScriptEditor@ with a script from disk")
LIST_ITEM (U"• @@Open Praat notebook...@: creates a @@NotebookEditor@ with a notebook from disk")
LIST_ITEM (U"• The ##Goodies submenu#: for doing things (like using the Calculator) "
	"that do not create new objects and do not depend on the kinds of selected objects.")
LIST_ITEM (U"• The ##Settings submenu#: for program-wide preferences, "
	"like audio input and output settings.")
LIST_ITEM (U"• ##Buttons...#: raises a @@ButtonEditor@")
LIST_ITEM (U"• (@@Add menu command...@)")
LIST_ITEM (U"• (@@Add action command...@)")
LIST_ITEM (U"• @@Quit")
ENTRY (U"Other menus")
LIST_ITEM (U"• The @@New menu@: for creating objects from scratch.")
LIST_ITEM (U"• The @@Open menu@: for reading objects from file into memory.")
LIST_ITEM (U"• The @@Save menu@: for writing objects from memory to file.")
LIST_ITEM (U"• The ##Help menu#: for viewing the manual.")
MAN_END

MAN_BEGIN (U"Periodicity menu", U"ppgb", 20240722 /*20010417, 20231115*/)
INTRO (U"A menu that occurs in the @@Dynamic menu@ for a @Sound.")
NORMAL (U"This menu contains commands for analysing the pitch contour of the selected Sound:")
LIST_ITEM (U"@@Sound: To Pitch (filtered autocorrelation)...")
LIST_ITEM (U"@@Sound: To Pitch (raw cross-correlation)...")
LIST_ITEM (U"@@Sound: To Pitch (raw autocorrelation)...")
LIST_ITEM (U"@@Sound: To Pitch (filtered cross-correlation)...")
LIST_ITEM (U"@@Sound: To Pitch (shs)...")
LIST_ITEM (U"@@Sound: To Harmonicity (cc)...")
LIST_ITEM (U"@@Sound: To Harmonicity (ac)...")
MAN_END

MAN_BEGIN (U"Pitch menu", U"ppgb", 20221202)
INTRO (U"A menu in the @SoundEditor or @TextGridEditor.")
MAN_END

MAN_BEGIN (U"Play", U"ppgb", /*20021212*/ 20220814)
INTRO (U"A command that is available if you select a @Sound, @Pitch, or @PointProcess object. "
	"It gives you an acoustic representation of the selected object, if your loudspeakers are on "
	"and you did not \"mute\" your computer sound system.")
NORMAL (U"A Play button is also available in the @SoundRecorder window "
	"and in the @Play menu of the @SoundEditor or @TextGridEditor. In the editors, "
	"you will usually play a sound by clicking on any of the rectangles around the data.")
MAN_END

MAN_BEGIN (U"Query submenu", U"ppgb", 20221202)
INTRO (U"A submenu that appears in the @@Objects window@ if you select an object of almost any type.")
INTRO (U"Query commands give you information about objects.")
NORMAL (U"Most query commands start with the word #%Get or sometimes the word #%Count. "
	"You will find these commands in two places: under the @@Query submenu@ that usually appears if you "
	"select an @@Objects|object@ in the list, and in the query parts of several menus of the @editors "
	"(such as the @@Pitch menu@, the @@Formants menu@ or the @@Spectrogram menu@.")
ENTRY (U"Behaviour")
NORMAL (U"If you click a query command, the answer will be written to the @@Info window@.")
ENTRY (U"Scripting")
NORMAL (U"In a script, you can still use query commands to write the information to the Info window "
	"but you can also use any query command to put the information into a variable. "
	"(see @@Scripting 6.3. Query commands@). In such a case, the value will not be written into the Info window.")
ENTRY (U"Some pages that link here")
ENTRY (U"Query commands in the Praat program")
LIST_ITEM (U"@@FAQ: Pitch analysis")
LIST_ITEM (U"@@Formulas 8. Attributes of objects")
LIST_ITEM (U"@@OT learning 7. Learning from overt forms")
LIST_ITEM (U"@@Script for listing F0 statistics")
LIST_ITEM (U"@@Scripting 3.3. Numeric queries")
LIST_ITEM (U"@@Scripting 3.5. String queries")
LIST_ITEM (U"@@Scripting 6.2. Writing to the Info window")
LIST_ITEM (U"@@time domain")
LIST_ITEM (U"@@Voice 6. Automating voice analysis with a script")
NORMAL (U"The Praat program contains at least the following query commands:")
MAN_END

MAN_BEGIN (U"Quit", U"ppgb", 20050822)
INTRO (U"One of the commands in the @@Praat menu@.")
ENTRY (U"Purpose")
NORMAL (U"To leave the program.")
ENTRY (U"Behaviour")
NORMAL (U"All @objects not written to a file will be lost. "
	"However, file-based objects (like large lexica) will be saved correctly.")
ENTRY (U"Usage")
NORMAL (U"To save your data to a disk file before quitting, choose a command from the @@Save menu@.")
MAN_END

MAN_BEGIN (U"Read from file...", U"ppgb", 20111018)
INTRO (U"One of the commands in the @@Open menu@.")
ENTRY (U"Purpose")
NORMAL (U"To read one or more @objects from a file on disk.")
ENTRY (U"Behaviour")
NORMAL (U"Many kinds of files are recognized:")
LIST_ITEM (U"1. Text files that are structured as described under @@Save as text file...@; "
	"these can contain an object of any type, or a collection of objects.")
LIST_ITEM (U"2. Files that were produced by @@Save as binary file...@ (any type).")
LIST_ITEM (U"3. Files in a LISP text format (only for object types that can be written to a LISP file).")
LIST_ITEM (U"4. Files that were made recognizable by the libraries built on Praat. "
	"For instance, the phonetics library adds recognizers for many kinds of sound files.")
NORMAL (U"If the file contains more than one object, these objects will appear in the list, "
	"and their names will be the same as the names that they had "
	"when they were saved with ##Save as text file...# or ##Save as binary file...#.")
ENTRY (U"Examples")
LIST_ITEM (U"• If the file contains only one Pitch object and is called \"hallo.pit\", "
	"an object with the name \"Pitch hallo\" will appear in the list of objects. "
	"You may have more objects with the same name.")
LIST_ITEM (U"• If the file contains one object of type Pitch, named \"hallo\", "
	"and one object of type Polygon, named \"kromme\", "
	"there will appear two objects in the list, "
	"called \"Pitch hallo\" and \"Polygon kromme\".")
MAN_END

MAN_BEGIN (U"Open menu", U"ppgb", 20110111)
INTRO (U"One of the menus in the @@Objects window@.")
NORMAL (U"With the Open menu, you read one or more @objects from a file on disk into memory. "
	"The resulting object(s) will appear in the @@List of Objects@.")
NORMAL (U"The Open menu contains the command @@Read from file...@, which recognizes most file types, "
	"and perhaps several other commands for reading unrecognizable file types (e.g., raw sound data), "
	"or for interpreting known file types in a different way "
	"(e.g., reading two mono sounds from one stereo sound file):")
MAN_END

MAN_BEGIN (U"pause window", U"ppgb", 20230723)
INTRO (U"A window, popped up by a script, that asks the user for input.")
NORMAL (U"For details, see @@Scripting 6.6. Controlling the user@.")
MAN_END

MAN_BEGIN (U"Remove", U"ppgb", 20021212)
INTRO (U"One of the fixed buttons in the @@Objects window@.")
NORMAL (U"You can choose this command after selecting one or more @objects in the list.")
NORMAL (U"The selected objects will permanently disappear from the list, "
	"and the computer memory that they occupied will be freed.")
NORMAL (U"To save your data before removing, choose a command from the @@Save menu@.")
MAN_END

MAN_BEGIN (U"Rename...", U"ppgb", 20111018)
INTRO (U"One of the fixed buttons in the @@Objects window@.")
ENTRY (U"Availability")
NORMAL (U"You can choose this command after selecting one object of any type.")
ENTRY (U"Purpose")
NORMAL (U"You can give the selected object a new name.")
ENTRY (U"Behaviour")
NORMAL (U"If you type special symbols or spaces, the Objects window will replace them with underscores.")
MAN_END

MAN_BEGIN (U"Save menu", U"ppgb", 20211015)
INTRO (U"One of the menus in the @@Objects window@.")
ENTRY (U"Purpose")
NORMAL (U"With the #Save menu, you write one or more selected @objects from memory to a file on disk. "
	"The data can be read in again with one of the commands in the @@Open menu@ "
	"(most often simply with @@Read from file...@).")
ENTRY (U"Usage: save your work")
NORMAL (U"You will often choose a command from this menu just before clicking the @Remove button "
	"or choosing the @Quit command.")
ENTRY (U"Fixed commands")
NORMAL (U"If no object is selected, the #Save menu is empty. "
	"If any object is selected, it will at least contain the following commands:")
LIST_ITEM (U"• @@Save as text file...")
LIST_ITEM (U"• @@Save as short text file...")
LIST_ITEM (U"• @@Save as binary file...")
ENTRY (U"Dynamic commands")
NORMAL (U"Depending on the type of the selected object, the following commands may be available "
	"in the #Save menu:")
MAN_END

MAN_BEGIN (U"Save as binary file...", U"ppgb", 20110129)
INTRO (U"One of the commands in the @@Save menu@.")
ENTRY (U"Availability")
NORMAL (U"You can choose this command after selecting one or more @objects.")
ENTRY (U"Behaviour")
NORMAL (U"The Objects window will ask you for a file name. "
	"After you click OK, the objects will be written to a binary file on disk.")
ENTRY (U"Usage")
NORMAL (U"The file can be read again with @@Read from file...@.")
ENTRY (U"File format")
NORMAL (U"These files are in a device-independent binary format, "
	"and can be written and read on any machine.")
MAN_END

MAN_BEGIN (U"Save as short text file...", U"ppgb", 20110129)
INTRO (U"One of the commands in the @@Save menu@.")
ENTRY (U"Availability")
NORMAL (U"You can choose this command after selecting one or more @objects.")
ENTRY (U"Behaviour")
NORMAL (U"The Objects window will ask you for a file name. "
	"After you click OK, the objects will be written to a text file on disk.")
ENTRY (U"File format")
NORMAL (U"The format is much shorter than the one described at @@Save as text file...@. "
	"Most of the comments are gone, and there is normally one piece of data per line.")
NORMAL (U"The file can be read again with the all-purpose @@Read from file...@.")
MAN_END

MAN_BEGIN (U"Save as text file...", U"ppgb", 20110129)
INTRO (U"One of the commands in the @@Save menu@.")
ENTRY (U"Availability")
NORMAL (U"You can choose this command after selecting one or more @objects.")
ENTRY (U"Behaviour")
NORMAL (U"The Objects window will ask you for a file name. "
	"After you click OK, the objects will be written to a text file on disk.")
ENTRY (U"File format")
NORMAL (U"If you selected a single object, e.g., of type Pitch, "
	"the file will start with the lines:")
CODE (U"File type = \"ooTextFile\"")
CODE (U"Object class = \"Pitch\"")
NORMAL (U"After this, the pitch data will follow.")
LIST_ITEM (U"If you selected more than one object, e.g., “Pitch hallo” and “Polygon kromme”, "
	"the file will look like:")
CODE (U"File type = \"ooTextFile\"")
CODE (U"Object class = \"Collection\"")
CODE (U"size = 2")
CODE (U"item []:")
CODE (U"    item [1]:")
CODE (U"        class = \"Pitch\"")
CODE (U"        name = \"hallo\"")
CODE (U"        (pitch data...)")
CODE (U"    item [2]:")
CODE (U"        class = \"Polygon\"")
CODE (U"        name = \"kromme\"")
CODE (U"        (polygon data...)")
NORMAL (U"The file can be read again with @@Read from file...@, "
	"which, by the way, does not need the verbosity of the above example. "
	"The following minimal format will also be read correctly:")
CODE (U"\"ooTextFile\"")
CODE (U"\"Collection\"  2")
CODE (U"\"Pitch\"  \"hallo\"  (pitch data...)")
CODE (U"\"Polygon\"  \"kromme\"  (polygon data...)")
NORMAL (U"Thus, all text that is not a free-standing number and is not enclosed in double quotes or < >, "
	"is considered a comment, as is all text following an exclamation mark (“!”) on the same line.")
MAN_END

MAN_BEGIN (U"Segmentation", U"ppgb", 20010408)
INTRO (U"See @@Intro 7. Annotation@.")
MAN_END

MAN_BEGIN (U"Show formant", U"ppgb", 20030316)
INTRO (U"One of the commands in the Formant menu of the @SoundEditor and the @TextGridEditor.")
NORMAL (U"See @@Intro 5. Formant analysis@.")
MAN_END

MAN_BEGIN (U"Show intensity", U"ppgb", 20030316)
INTRO (U"One of the commands in the Intensity menu of the @SoundEditor and the @TextGridEditor.")
NORMAL (U"See @@Intro 6. Intensity analysis@.")
MAN_END

MAN_BEGIN (U"Show pitch", U"ppgb", 20030316)
INTRO (U"One of the commands in the Pitch menu of the @SoundEditor and the @TextGridEditor.")
NORMAL (U"See @@Intro 4. Pitch analysis@.")
MAN_END

MAN_BEGIN (U"Show pulses", U"ppgb", 20030316)
INTRO (U"One of the commands in the Pulses menu of the @SoundEditor and the @TextGridEditor.")
NORMAL (U"See @Voice.")
MAN_END

MAN_BEGIN (U"Show spectrogram", U"ppgb", 20030316)
INTRO (U"One of the commands in the Spectrogram menu of the @SoundEditor and the @TextGridEditor.")
NORMAL (U"See @@Intro 3. Spectral analysis@.")
MAN_END

MAN_PAGES_BEGIN
R"~~~(
################################################################################
"Source-filter synthesis"
© Paul Boersma 2005-07-13

This tutorial describes how you can do acoustic synthesis with Praat.
It assumes that you are familiar with the @Intro.

1. The source-filter theory of speech production
======================================

The source-filter theory (@@Fant (1960)|Fant 1960@) hypothesizes that an acoustic speech signal can be seen
as a %source signal (the glottal source, or noise generated at a constriction in the vocal tract),
%filtered with the resonances in the cavities of the vocal tract downstream from the glottis
or the constriction. The %%Klatt synthesizer% (@@Klatt & Klatt (1990)|Klatt & Klatt 1990@), for instance,
is based on this idea.

In the Praat program, you can create a %source signal from scratch of from an existing
speech signal, and you can create a %filter from scratch or extract it from an existing speech signal.
You can manipulate (change, adapt) both the source and the filter before doing
the actual synthesis, which combines the two.

,	@@Source-filter synthesis 1. Creating a source from pitch targets
,	@@Source-filter synthesis 2. Filtering a source
,	@@Source-filter synthesis 3. The ba-da continuum
,	@@Source-filter synthesis 4. Using existing sounds

################################################################################
"Source-filter synthesis 1. Creating a source from pitch targets"
© Paul Boersma 2014-04-21

Creating a glottal source signal for speech synthesis involves creating a @PointProcess,
which is a series of time points that should represent the exact moments of glottal closure.

You may want to start with creating a well-defined pitch contour.
Suppose you want to create a sound with a duration of half a second with a pitch that falls from 300 to 200 Hz
during that time. You first create an empty @PitchTier by choosing @@Create PitchTier...@ from the #New menu
(I call this PitchTier “empty” because it does not contain any pitch information yet);
you may want to name the PitchTier “source” and have it start at 0 seconds and end at 0.5 seconds.
Once the PitchTier exists and is selected, you can ##View & Edit# it to add pitch points (pitch targets) to it at certain times
(or you choose @@PitchTier: Add point...@ from the #Modify menu repeatedly).
You could add a pitch point of 150 Hz at time 0.0 and a pitch point of 100 Hz at time 0.5.
In the PitchTier window, you can see that the pitch curve falls linearly
from 150 to 100 Hz during its time domain:
{- 4.5x2.5
	Create PitchTier: “source”, 0, 0.5
	Add point: 0.0, 150
	Add point: 0.5, 100
	Draw: 0, 0, 0, 200, “yes”, “lines and speckles”
	Text top: “no”, ~%%An F0 linearly falling between two points
	One mark left: 100, “yes”, “yes”, “no”, “”
	Remove
}

You can hear the falling pitch by clicking on the rectangles in the PitchTier window
(or by clicking ##Play pulses#, #Hum, or ##Play sine# in the Objects window).

From this PitchTier, you can create a @PointProcess with @@PitchTier: To PointProcess@.
The resulting PointProcess now represents a series of glottal pulses. To make some parts of this
point process voiceless, you can use @@PointProcess: Remove points between...@.
It is advisable to make the very beginning and end of this point process voiceless, so that the filtered sound
will not start or end abruptly. In the following example, the first and last 20 ms are devoiced,
and a stretch of 70 ms in the middle
is made voiceless as well, perhaps because you want to simulate a voiceless plosive there:
{- 4.5x2.5
	pitchTier = Create PitchTier: “source”, 0, 0.5
	Add point: 0.0, 150
	Add point: 0.5, 100
	pulses = To PointProcess
	Remove points between: 0, 0.02
	Remove points between: 0.24, 0.31
	Remove points between: 0.48, 0.5
	Draw: 0, 0, “yes”
	Text top: “no”, ~%%The times of the glottal pulses
	One mark bottom: 0.24, “yes”, “yes”, “no”, “”
	One mark bottom: 0.31, “yes”, “yes”, “no”, “”
	removeObject: pitchTier, pulses
}

Now that we have a glottal point process (a glottal pulse train), the only thing left
is to turn it into a sound by choosing @@PointProcess: To Sound (phonation)...@.
If you use the standard settings of this command (but with ##Adaptation factor# set to 0.6), the result will be a @Sound with
reasonable glottal flow derivatives centred around each of the original pulses in the point process.
You can check this by selecting the Sound and choosing ##View & Edit#:
{- 4.5x2.5
	pitchTier = Create PitchTier: “source”, 0, 0.5
	Add point: 0.0, 150
	Add point: 0.5, 100
	pulses = To PointProcess
	Remove points between: 0, 0.02
	Remove points between: 0.24, 0.31
	Remove points between: 0.48, 0.5
	source = To Sound (phonation): 44100, 0.6, 0.05, 0.7, 0.03, 3.0, 4.0
	Draw: 0, 0, 0, 0, “yes”, “curve”
	Text top: “no”, ~%%The source waveform
	One mark bottom: 0.24, “yes”, “yes”, “no”, “”
	One mark bottom: 0.31, “yes”, “yes”, “no”, “”
	removeObject: pitchTier, pulses, source
}

You will also see that the amplitude of the first two glottal wave shapes of every voiced stretch
is (realistically) somewhat smaller than the amplitudes of the following wave shapes;
This is the result of setting ##Adaptation factor# to 0.6.

What you have now is what we call a %%glottal source signal%. It does two things: it contains information on the glottal flow,
and it already takes into account one aspect of the %filter, namely the radiation at the lips.
This combination is standard procedure in acoustic synthesis.

The glottal source signal sounds as a voice without a vocal tract.
The following section describes how you add vocal-tract resonances, i.e. the %filter.

Automation
==========

In a clean Praat script, the procedure described above will look as follows:
{
	pitchTier = Create PitchTier: “source”, 0, 0.5
	Add point: 0.0, 150
	Add point: 0.5, 100
	pulses = To PointProcess
	Remove points between: 0, 0.02
	Remove points between: 0.24, 0.31
	Remove points between: 0.48, 0.5
	source = To Sound (phonation): 44100, 0.6, 0.05, 0.7, 0.03, 3.0, 4.0
	removeObject: pitchTier, pulses
	selectObject: source
}

################################################################################
"Source-filter synthesis 2. Filtering a source"
© Paul Boersma 2014-04-21

Once you have a glottal source signal, you are ready to create a filter that represents
the resonances of the vocal tract, as a function of time. In other words, you create a @FormantGrid object.

For a vowel spoken by an average (i.e. adult female) human voice, tradition assumes five formants in the range
between 0 and 5500 hertz. This number comes from a computation of the formants of a
straight tube, which has resonances at wavelengths of four tube lengths, four thirds of a tube length,
four fifths, and so on. For a straight tube 16 centimetres long, the shortest wavelength is 64 cm,
which, with a sound velocity of 352 m/s, means a resonance frequency of 352/0.64 = 550 hertz.
The other resonances will be at 1650, 2750, 3850, and 4950 hertz.

You can create a @FormantGrid object with @@Create FormantGrid...@ from the #New menu (submenu #Tiers):
{
	Create FormantGrid: “filter”, 0, 0.5, 10, 550, 1100, 60, 50
}
This creates a FormantGrid with 10 formants and a single frequency value for each formant: %F_1 is 550 Hz
and the higher formants are spaced 1100 Hz apart, i.e., they are
1650, 2750, 3850, 4950, 6050, 7150, 8250, 9350, and 10450 hertz;
the ten bandwidths start at 60 Hz and have a spacing of 50 Hz,
i.e., they are 60, 110, 160, 210, 260, 310, 360, 410, 460, and 510 hertz.

You can then create formant contours with @@FormantGrid: Add formant point...@:
{
	Remove formant points between: 1, 0, 0.5
	Add formant point: 1, 0.00, 100
	Add formant point: 1, 0.05, 700
	Remove formant points between: 2, 0, 0.5
	Add formant point: 2, 0.00, 500
	Add formant point: 2, 0.05, 1100
}
This example creates a spectral specification whose %F_1 rises from 100 to 700 hertz during the
first 50 milliseconds (as for any obstruent), and whose %F_2 rises from 500 to 1100 hertz.
The other eight formants keep their original values, as do the ten bandwidths.
The resulting sound may be a [ba]-like formant transition.

To get the final acoustic result (the sound), you select the glottal source signal
together with the FormantGrid and choose @@Sound & FormantGrid: Filter@.

The resulting sound will have a fairly straight intensity contour. You can change this with
the #Formula command (@@Sound: Formula...@), or by multiplying the source signal or the
acoustic result with an @Intensity or @IntensityTier object.

################################################################################
"Source-filter synthesis 3. The ba-da continuum"
© Paul Boersma 2014-04-21,2025

As an example, we are going to create a male [ba]-[da] continuum in six steps. The acoustic difference
between [ba] and [da] is the initial %F_2, which is 500 Hz for [ba], and 2500 Hz for [da].

We use the same @PitchTier throughout, to model a falling intonation contour:
{
	Create PitchTier: “f0”, 0.00, 0.50
	Add point: 0.00, 150
	Add point: 0.50, 100
}

The first and last 50 milliseconds are voiceless:
{
	To PointProcess
	Remove points between: 0.00, 0.05
	Remove points between: 0.45, 0.50
}

Generate the glottal source signal:
{
	To Sound (phonation): 44100, 0.6, 0.05, 0.7, 0.03, 3.0, 4.0
}

During the labial or coronal closure, the sound is almost silent, so we use an @IntensityTier
that models this:
{
	Create IntensityTier: “intens”, 0.00, 0.50
	Add point: 0.05, 60
	Add point: 0.10, 80
}

Generate the source signal:
{
	plusObject: “Sound f0”
	Multiply
	Rename: “source”
}

The ten sounds are generated in a loop:
{
	for i from 1 to 10
		f2_locus = 500 + (2500/9) * (i - 1) ; variable names start with lower case!
		Create FormantGrid: “filter”, 0.0, 0.5, 9, 800, 1000, 60, 80
		Add formant point: 1, 0.05, 100
		Add bandwidth point: 1, 0.05, 50
		Add formant point: 1, 0.10, 800
		Add bandwidth point: 1, 0.10, 60
		Add formant point: 2, 0.05, f2_locus
		Add bandwidth point: 2, 0.05, 100
		Add formant point: 2, 0.05, 1800
		Add bandwidth point: 2, 0.05, 140
		plusObject: “Sound source”
		Filter (no scale)
		Rename: “bada” + string$ (i)
		removeObject: “FormantGrid filter”
	endfor
}

Clean up:
{
	removeObject: “Sound source”, “Sound f0”, “IntensityTier intens”,
	... “PointProcess f0”, “PitchTier f0”
}

In this example, filtering was done without automatic scaling, so that
the resulting signals have equal intensities in the areas where they have
equal formants. You will probably want to multiply all these signals with
the same value in order to bring their amplitudes in a suitable range
between -1 and +1 Pascal.

################################################################################
"Source-filter synthesis 4. Using existing sounds"
© Paul Boersma 2017-08-28

1. How to extract the %filter from an existing speech sound
======================================

You can separate source and filter with the help of the technique of %%linear prediction%
(see @@Sound: LPC analysis@). This technique tries to approximate a given frequency spectrum with
a small number of peaks, for which it finds the mid frequencies and the bandwidths.
If we do this for an overlapping sequence of windowed parts of a sound signal
(i.e. a %%short-term analysis%), we get a quasi-stationary approximation of the signal's
spectral characteristics as a function of time, i.e. a smoothed version of the @Spectrogram.

For a speech signal, the peaks are identified with the resonances (%formants) of the vocal tract.
Since the spectrum of a vowel spoken by an average human being falls off with approximately
6 dB per octave, %%pre-emphasis% is applied to the signal before the linear-prediction analysis,
so that the algorithm will not try to match only the lower parts of the spectrum.

For an adult female human voice, tradition assumes five formants in the range
between 0 and 5500 hertz, say at 550, 1650, 2750, 3850, and 4950 hertz. For the linear prediction in
Praat, you will have to implement this 5500-Hz band-limiting by resampling the original
speech signal to 11 kHz. For a male voice, you would use 10 kHz; for a young child, 20 kHz.

To perform the resampling, you use @@Sound: Resample...@:
you select a @Sound object, and click ##Resample...#.
In the rest of this tutorial, I will use the syntax that you would use in a script,
though you will usually do these things by clicking on objects and buttons. Thus:
{;
	selectObject: “Sound hallo”
	Resample: 11000, 50
}
You can then perform a linear-prediction analysis on the resampled sound
with @@Sound: To LPC (burg)...@:
{;
	selectObject: “Sound hallo_11000”
	To LPC (burg): 10, 0.025, 0.005, 50
}
This says that your analysis is done with 10 linear-prediction parameters
(which will yield at most five formant-bandwidth pairs), with an analysis window
effectively 25 milliseconds long, with time steps of 5 milliseconds (so that the windows
will appreciably overlap), and with a pre-emphasis frequency of 50 Hz (which is the point
above which the sound will be amplified by 6 dB/octave prior to the analysis proper).

As a result, an object called “LPC hallo” will appear in the list of objects.
This @LPC object is a time function with 10 %%linear-prediction coefficients% in each %%time frame%.
These coefficients are rather opaque even to the expert (try to view them with @Inspect),
but they are the raw material from which formant and bandwidth values can be computed.
To see the smoothed @Spectrogram associated with the LPC object, choose @@LPC: To Spectrogram...@:
{;
	selectObject: “LPC hallo_11000”
	To Spectrogram: 20, 0, 50
	Paint: 0, 0, 0, 0, 50, 0, 0, “yes”
}
Note that when drawing this Spectrogram, you will want to set the pre-emphasis to zero
(the fifth 0 in the last line), because pre-emphasis has already been applied in the analysis.

You can get and draw the formant-bandwidth pairs from the LPC object,
with @@LPC: To Formant@ and @@Formant: Speckle...@:
{;
	selectObject: “LPC hallo_11000”
	To Formant
	Speckle: 0, 0, 5500, 30, “yes”
}
Note that in converting the @LPC into a @Formant object, you may have lost some
information about spectral peaks at very low frequencies (below 50 Hz) or at very high
frequencies (near the @@Nyquist frequency@ of 5500 Hz. Such peaks usually try to fit
an overall spectral slope (if the 6 dB/octave model is inappropriate), and are not seen
as related with resonances in the vocal tract, so they are ignored in a formant analysis.
For resynthesis purposes, they might still be important.

Instead of using the intermediate LPC object, you could have done a formant analysis
directly on the original Sound, with @@Sound: To Formant (burg)...@:
{;
	selectObject: “Sound hallo”
	To Formant (burg): 0.005, 5, 5500, 0.025, 50
}
A @Formant object has a fixed sampling (time step, frame length), and for every
%%formant frame%, it contains a number of formant-bandwidth pairs.

From a Formant object, you can create a @FormantGrid with @@Formant: Down to FormantGrid@.
A FormantGrid object contains a number of tiers with time-stamped %%formant points% and %%bandwidth points%.

Any of these three types (@LPC, @Formant, and @FormantGrid) can represent the %filter
in source-filter synthesis.

2. How to extract the %source from an existing speech sound
======================================

If you are only interested in the %filter characteristics, you can get by with @Formant objects.
To get at the %source signal, however, you need the raw @LPC object:
you select it together with the resampled @Sound, and apply %%inverse filtering%:
{;
	selectObject: “Sound hallo_11000”, “LPC hallo_11000”
	Filter (inverse)
}
A new Sound named `hallo_11000` will appear in the list of objects
(you could rename it to `source`).
This is the estimated source signal. Since the LPC analysis was designed to yield a spectrally
flat filter (through the use of pre-emphasis), this source signal represents everything in the
speech signal that cannot be attributed to the resonating cavities. Thus, the “source signal”
will consist of the glottal volume-velocity source (with an expected spectral slope of
-12 dB/octave for vowels) and the radiation characteristics at the lips, which cause a
6 dB/octave spectral rise, so that the resulting spectrum of the “source signal”
is actually the %derivative of the glottal flow, with an expected spectral slope of -6 dB/octave.

Note that with inverse filtering you cannot measure the actual spectral slope of the source signal.
Even if the actual slope is very different from -6 dB/octave, formant extraction will try to
match the pre-emphasized spectrum. Thus, by choosing a pre-emhasis of -6 dB/octave,
you %impose a slope of -6 dB/octave on the source signal.

3. How to do the synthesis
==========================

You can create a new Sound from a source Sound and a filter, in at least four ways.

If your filter is an @LPC object, you select it and the source, and choose @@LPC & Sound: Filter...@:
{;
	selectObject: “Sound source”, “LPC filter”
	Filter: “no”
}
If you had computed the source and filter from an LPC analysis, this procedure should give
you back the original Sound, except that windowing has caused 25 milliseconds at the beginning
and end of the signal to be set to zero.

If your filter is a @Formant object, you select it and the source, and choose @@Sound & Formant: Filter@:
{;
	selectObject: “Sound source”, “Formant filter”
	Filter
}
If you had computed the source and filter from an LPC analysis, this procedure will not generally give
you back the original Sound, because some linear-prediction coefficients will have been ignored
in the conversion to formant-bandwidth pairs.

If your filter is a @FormantGrid object, you select it and the source, and choose @@Sound & FormantGrid: Filter@:
{;
	selectObject: “Sound source”, “FormantGrid filter”
	Filter
}
Finally, you could just know the %%impulse response% of your filter (in a @Sound object).
You then select both Sound objects, and choose @@Sounds: Convolve...@:
{;
	selectObject: “Sound source”, “Sound filter”
	Convolve: “integral”, “zero”
}
As a last step, you may want to bring the resulting sound within the [-1; +1] range:
{;
	Scale peak: 0.99
}

4. How to manipulate the filter
===============================

You can hardly change the values in an @LPC object in a meaningful way:
you would have to manually change its rather opaque data with the help of @Inspect.

A @Formant object can be changed in a friendlier way, with @@Formant: Formula (frequencies)...@
and @@Formant: Formula (bandwidths)...@. For instance, to multiply all formant frequencies by 0.9,
you do
{;
	selectObject: “Formant filter”
	Formula (frequencies): “self * 0.9”
}
To add 200 hertz to all values of %F_2, you do
{;
	Formula (frequencies): ~ if row = 2 then self + 200 else self fi
}
A @FormantGrid object can be changed by adding or removing points:
,	@@FormantGrid: Add formant point...@
,	@@FormantGrid: Add bandwidth point...@
,	@@FormantGrid: Remove formant points between...@
,	@@FormantGrid: Remove bandwidth points between...@

5. How to manipulate the source signal
======================================

You can manipulate the source signal in the same way you that would manipulate any sound,
for instance with the @ManipulationEditor.

)~~~"
MAN_PAGES_END

MAN_BEGIN (U"Spectrogram menu", U"ppgb", 20221202)
INTRO (U"A menu in the @SoundEditor or @TextGridEditor.")
MAN_END

MAN_BEGIN (U"Spectrogram settings...", U"ppgb", 20221202)
INTRO (U"A command in the @@Spectrogram menu@ of the @SoundEditor and @TextGridEditor windows. "
	"See @@Intro 3.2. Configuring the spectrogram@.")
MAN_END

MAN_BEGIN (U"Technical", U"ppgb", 20120915)
INTRO (U"The title of a submenu of the @@Praat menu@.")
MAN_END

MAN_BEGIN (U"Types of objects", U"ppgb", 20190928)
INTRO (U"Praat contains the following types of objects and @Editors. "
	"For an introduction and tutorials, see @Intro.")
NORMAL (U"General purpose:")
LIST_ITEM (U"• @Matrix: a sampled real-valued function of two variables")
LIST_ITEM (U"• @Polygon")
LIST_ITEM (U"• @PointProcess: a point process (@PointEditor)")
LIST_ITEM (U"• @Sound: a sampled continuous process (@SoundEditor, @SoundRecorder, @@Sound files@)")
LIST_ITEM (U"• @LongSound: a file-based version of a sound (@LongSoundEditor)")
LIST_ITEM (U"• @Strings")
LIST_ITEM (U"• @Distributions, @PairDistribution")
LIST_ITEM (U"• @Table, @TableOfReal")
LIST_ITEM (U"• @Permutation")
LIST_ITEM (U"• @ParamCurve")
NORMAL (U"Periodicity analysis:")
LIST_ITEM (U"• Tutorials:")
LIST_ITEM1 (U"• @@Intro 4. Pitch analysis")
LIST_ITEM1 (U"• @@Intro 6. Intensity analysis")
LIST_ITEM1 (U"• @Voice (jitter, shimmer, noise)")
LIST_ITEM (U"• @Pitch: articulatory fundamental frequency, acoustic periodicity, or perceptual pitch (@PitchEditor)")
LIST_ITEM (U"• @Harmonicity: degree of periodicity")
LIST_ITEM (U"• @Intensity, @IntensityTier: intensity contour")
LIST_ITEM (U"• @Electroglottogram")
NORMAL (U"Spectral analysis:")
LIST_ITEM (U"• Tutorials:")
LIST_ITEM1 (U"• @@Intro 3. Spectral analysis")
LIST_ITEM1 (U"• @@Intro 5. Formant analysis")
LIST_ITEM (U"• @Spectrum: complex-valued equally spaced frequency spectrum (@SpectrumEditor)")
LIST_ITEM (U"• @Ltas: long-term average spectrum")
LIST_ITEM (U"• Spectro-temporal: @Spectrogram, @BarkSpectrogram, @MelSpectrogram")
LIST_ITEM (U"• @Formant: acoustic formant contours")
LIST_ITEM (U"• @LPC: coefficients of Linear Predictive Coding, as a function of time")
LIST_ITEM (U"• @Cepstrum, @CC, @LFCC, @MFCC (cepstral coefficients)")
LIST_ITEM (U"• @Excitation: excitation pattern of basilar membrane")
LIST_ITEM (U"• @Excitations: an ensemble of #Excitation objects")
LIST_ITEM (U"• @Cochleagram: excitation pattern as a function of time")
NORMAL (U"Labelling and segmentation (see @@Intro 7. Annotation@):")
LIST_ITEM (U"• @TextGrid (@TextGridEditor)")
NORMAL (U"Listening experiments:")
LIST_ITEM (U"• @ExperimentMFC")
NORMAL (U"Manipulation of sound:")
LIST_ITEM (U"• Tutorials:")
LIST_ITEM1 (U"• @@Intro 8.1. Manipulation of pitch")
LIST_ITEM1 (U"• @@Intro 8.2. Manipulation of duration")
LIST_ITEM1 (U"• @@Intro 8.3. Manipulation of intensity")
LIST_ITEM1 (U"• @@Filtering")
LIST_ITEM1 (U"• @@Source-filter synthesis")
LIST_ITEM (U"• @PitchTier (@PitchTierEditor)")
LIST_ITEM (U"• @Manipulation (@ManipulationEditor): @@overlap-add@")
LIST_ITEM (U"• @DurationTier")
LIST_ITEM (U"• @FormantGrid")
NORMAL (U"Articulatory synthesis (see the @@Articulatory synthesis@ tutorial):")
LIST_ITEM (U"• @Speaker: speaker characteristics of a woman, a man, or a child")
LIST_ITEM (U"• #Articulation: snapshot of articulatory specifications (muscle activities)")
LIST_ITEM (U"• @Artword: articulatory target specifications as functions of time")
LIST_ITEM (U"• (@VocalTract: area function)")
NORMAL (U"Neural net package:")
LIST_ITEM (U"• @FFNet: feed-forward neural net")
LIST_ITEM (U"• @PatternList")
LIST_ITEM (U"• @Categories: for classification (#CategoriesEditor)")
NORMAL (U"Numerical and statistical analysis:")
LIST_ITEM (U"• @Eigen: eigenvectors and eigenvalues")
LIST_ITEM (U"• @Polynomial, @Roots, @ChebyshevSeries, @LegendreSeries, @ISpline, @MSpline")
LIST_ITEM (U"• @Covariance: covariance matrix")
LIST_ITEM (U"• @Confusion: confusion matrix")
LIST_ITEM (U"• @@Discriminant analysis@: @Discriminant")
LIST_ITEM (U"• @@Principal component analysis@: @PCA")
LIST_ITEM (U"• @Correlation, @ClassificationTable, @SSCP")
LIST_ITEM (U"• @DTW: dynamic time warping")
NORMAL (U"@@Multidimensional scaling@:")
LIST_ITEM (U"• @Configuration (@Salience)")
LIST_ITEM (U"• @@Kruskal analysis@: @Dissimilarity (@Weight), @Similarity")
LIST_ITEM (U"• @@INDSCAL analysis@: @Distance, @ScalarProduct")
LIST_ITEM (U"• @@Correspondence analysis@: @ContingencyTable")
NORMAL (U"Optimality-theoretic learning (see the @@OT learning@ tutorial)")
LIST_ITEM (U"• @OTGrammar (@OTGrammarEditor)")
NORMAL (U"Bureaucracy")
LIST_ITEM (U"• @WordList, @SpellingChecker")
MAN_END

MAN_PAGES_BEGIN
R"~~~(
################################################################################
"Unicode"
© Paul Boersma 2023

Praat aims at being a fully international program:
the texts in Praat’s TextGrids, Tables, scripts, or Info window (and elsewhere) can contain many types of characters
(see @@special symbols@).
For this reason, Praat saves its text files in one of two possible formats: UTF-8 (including ASCII) or UTF-16.

ASCII text files
================

If your TextGrid (or Table, or script, or Info window...) contains only characters that can be encoded as ASCII,
namely the characters `!\"#$%&'()*+,-./0123456789:;<=>?@
ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`` abcdefghijklmnopqrstuvwxyz{|}~`,
then when you say @@Save as text file...@ or #Save, Praat will write an ASCII text file,
which is a text file in which every character is encoded in a single byte (8 bits).
All programs that can read plain text files can read such files produced by Praat.

UTF-16 text files
=================

If your TextGrid (or Table, or script, or Info window...) contains one or more characters that cannot be encoded as ASCII,
for instance West-European characters such as \ao\c,\e'\o"\ss\?d, East-European characters such as \c<\l/\o:\s<\uo\z',
or Hebrew characters such as \?+\B+\G+\M%\vO\sU,
then when you say @@Save as text file...@ or #Save, Praat will write an UTF-16 text file,
which is a text file in which every character is encoded in two bytes (and some very rare characters in four bytes).
Many programs can read such text files, for instance NotePad, WordPad, Microsoft Word, and TextWrangler.

What if my other programs cannot read UTF-16 text files?
========================================================

If you want to export your Table to Microsoft Excel or to SPSS, or if you want your TextGrid file to be read
by somebody else's Perl script, then there will be no problem if your Table contains only ASCII characters (see above).
But if your Table contains any other (i.e. non-ASCII) characters, you may be in trouble, because Praat will write the Table
as an UTF-16 text file, and not all of the programs just mentioned can read such files yet.

What you can do is go to ##Text writing settings...# in the #Settings submenu of the #Praat menu,
and there set the output encoding to ##UTF-8#. Praat will from then on save your text files in the UTF-8 format,
which means one byte for every ASCII character and 2 to 4 bytes for every non-ASCII character.
Especially on Linux, many programs understand UTF-8 text and will display the correct characters.
Programs such as SPSS do not understand UTF-8 but will still display ASCII characters correctly;
for instance, the names München and Wałęsa may appear as M\A~\:-nchen and Wa\Ao,\A"\TMsa or so.

If you can get by with West-European characters (on Windows),
then you may choose ##try ISO Latin-1, then UTF-16# for the output encoding.
It is possible (but not guaranteed) that programs like SPSS then display your West-European text correctly.
This trick is of limited use, because it will not work if your operating system is set to a “codepage”
differently from ISO Latin-1 (or “ANSI”), or if you need East-European or Hebrew characters, or if you want
to share your text files with Macintosh users.

If you already have some UTF-16 text files and you want to convert them to UTF-8 or ISO Latin-1 (the latter only if
they do not contain non-West-European characters), then you can read them into Praat and save them again
(with the appropriate output encoding setting).
Other programs, such a NotePad and TextWrangler, can also do this conversion.

Finally, it is still possible to make sure that all texts are ASCII, e.g. you type the characters ß and ő
as “`\ss`” and “`\o:`” respectively. See @@special symbols@.

################################################################################
"Play"
© Paul Boersma 2022

One of the menus in several @editors and in the @manual.
################################################################################
)~~~"
MAN_PAGES_END

}

/* End of file manual_tutorials.cpp */
