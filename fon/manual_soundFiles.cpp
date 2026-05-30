/* manual_soundFiles.cpp
 *
 * Copyright (C) 1992-2005,2007,2008,2010,2011,2014-2017,2019-2023,2025 Paul Boersma
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

void manual_soundFiles_init (ManPages me);
void manual_soundFiles_init (ManPages me) {

MAN_BEGIN (U"Sound files", U"ppgb", 20210603)
INTRO (U"本教程介绍了您可以使用 Praat 进行读取和写入的声音文件。本教程假定您已熟悉 @@Intro|简介@ 教程。")
NORMAL (U"您可以使用窗口底部的 \"< 1\" 和 \"1 >\" 按钮按顺序阅读本教程。")
LIST_ITEM (U"1. @@Sound files 1. General structure|基本结构@")
LIST_ITEM1 (U"1.1. @@Sound files 1.1. Sampling|采样@ (采样频率)")
LIST_ITEM1 (U"1.2. @@Sound files 1.2. Quantization|量化@ (线性、端序、μ-law、A-law)")
LIST_ITEM1 (U"1.3. @@Sound files 1.3. Channels|通道@ (单声道、双声道)")
LIST_ITEM1 (U"1.4. @@Sound files 1.4. The header|文件头@")
LIST_ITEM1 (U"1.5. @@Sound files 1.5. Size|文件大小@")
LIST_ITEM1 (U"1.6. @@Sound files 1.6. Compression|压缩格式@")
LIST_ITEM (U"2. @@Sound files 2. File types|文件类型@")
LIST_ITEM1 (U"2.1. @@Sound files 2.1. WAV files|WAV 文件@")
LIST_ITEM1 (U"2.2. @@Sound files 2.2. AIFF files|AIFF 文件@")
LIST_ITEM1 (U"2.3. @@Sound files 2.3. AIFC files|AIFC 文件@")
LIST_ITEM1 (U"2.4. @@Sound files 2.4. NeXT/Sun (.au) files|NeXT/Sun (.au) 文件@")
LIST_ITEM1 (U"2.5. @@Sound files 2.5. NIST files|NIST 文件@")
LIST_ITEM1 (U"2.6. @@Sound files 2.6. FLAC files|FLAC 文件@")
LIST_ITEM1 (U"2.7. @@Sound files 2.7. MP3 files|MP3 文件@")
LIST_ITEM1 (U"2.8. @@Sound files 2.8. Ogg Vorbis files|Ogg Vorbis 文件@")
LIST_ITEM1 (U"2.9. @@Sound files 2.9. Ogg Opus files|Ogg Opus 文件@")
LIST_ITEM (U"3. @@Sound files 3. Files that Praat can read|Praat 支持读取的文件@")
LIST_ITEM (U"4. @@Sound files 4. Files that Praat can write|Praat 支持写入的文件@")
MAN_END

MAN_BEGIN (U"Sound files 1. General structure", U"ppgb", 20000123)
INTRO (U"这是 @@Sound files|声音文件@ 教程的第 1 章。"
	"它介绍了声音文件头部 and 数据部分的通用结构。")
LIST_ITEM (U"1.1. @@Sound files 1.1. Sampling|采样@ (采样频率)")
LIST_ITEM (U"1.2. @@Sound files 1.2. Quantization|量化@ (线性、μ-law、A-law)")
LIST_ITEM (U"1.3. @@Sound files 1.3. Channels|通道@ (单声道、双声道)")
LIST_ITEM (U"1.4. @@Sound files 1.4. The header|文件头@")
LIST_ITEM (U"1.5. @@Sound files 1.5. Size|文件大小@")
LIST_ITEM (U"1.6. @@Sound files 1.6. Compression|压缩格式@")
MAN_END

MAN_BEGIN (U"Sound files 1.1. Sampling", U"ppgb", 20220102)
NORMAL (U"当麦克风或磁带中的声音信号需要读入计算机时，"
	"它必须被 %数字化，这意味着它必须经过 %采样 和 %量化。")
NORMAL (U"采样是信号在时间域上的离散化："
	"信号的每一秒被分割成 44100、48000 或 96000 "
	"个切片（或任何其他合适的数值），并且一个 %%采样值% 与"
	"每个切片相关联。例如，一个连续的 377 Hz 正弦波表示为：")
EQUATION (U"%x(%t) = sin (2%π 377 %t)")
NORMAL (U"如果 %%采样频率% (或 %%采样率%) 是 44100 Hz，此正弦波将在相隔 "
	"Δ%t = 1/44100 秒的点上进行采样，采样值将为：")
EQUATION (U"%x__%i_ = sin (2%π 377 (%t__0_ + %i Δ%t))")
NORMAL (U"其中 %t__0_ 是采样开始的时间。"
	"Δ%t 被称为 %%采样周期%。")
NORMAL (U"量化将在下一节进行介绍 (@@Sound files 1.2. Quantization|第 1.2 节@)。")
MAN_END

MAN_BEGIN (U"Sound files 1.2. Quantization", U"ppgb", 20190517)
NORMAL (U"除了采样 (@@Sound files 1.1. Sampling|第 1.1 节@) 之外，"
	"数字化还涉及量化，即将采样值转换为"
	"适合放入 8、16、24 或 32 位的数字。")
ENTRY (U"保存")
NORMAL (U"当将 @Sound 对象导出为磁盘上的 16 位音频文件时，"
	"Praat 将 Sound 的采样乘以 32768，然后将它们四舍五入为整数，"
	"这样 -1.0 到 +1.0 Pa 之间的气压值最终将被编码为 -32768 到 +32767 之间的整数。"
	"低于 -1.0 的采样值将被编码为 -32768，高于 +1.0 的采样值将被编码为 +32767。"
	"为了避免这种“削波”现象，请将 @Sound 对象的绝对振幅保持在 1.000 以下，"
	"您可以在保存之前使用 @@Sound: Scale peak...@。")
NORMAL (U"当将 @Sound 对象导出为磁盘上的 24 位音频文件时，"
	"Praat 会将 Sound 的采样乘以 8388608。")
ENTRY (U"打开")
NORMAL (U"对于 16 位声音文件，磁盘上的采样值是 -32768 到 +32767 之间的整数。"
	"当将文件转换为 @Sound 对象时，Praat 会将这些整数转换为 -1.0 到 +1.0 之间的实数值，"
	"方法是将采样值除以 32768.0 (即 2^^(16 – 1)^)。"
	"Praat 随后将这些实数值视为帕斯卡单位的气压 (参见 @@sound pressure calibration|声压校准@)。"
	"对于 24 位 AIFF 文件，磁盘上的采样值是 -8388608 到 +8388607 之间的整数，"
	"Praat 将其除以 8388608.0，以在 @Sound 对象中获得 -1.0 到 +1.0 Pa 之间的值。")
MAN_END

MAN_BEGIN (U"Sound files 1.3. Channels", U"ppgb", 20000126)
NORMAL (U"对于大多数文件类型，Praat 支持单声道 (mono) 和双声道 (stereo) 的声音。")
MAN_END

MAN_BEGIN (U"Sound files 1.4. The header", U"ppgb", 20040223)
NORMAL (U"大多数声音文件的大部分都是由采样数据构成的。"
	"采样部分通常前面有一个文件头，其中包含有关以下内容的信息：")
LIST_ITEM (U"1. 文件类型 (WAV, AIFF, AIFC, NeXT/Sun, NIST, Kay, FLAC...)。")
LIST_ITEM (U"2. 采样频率 (@@Sound files 1.1. Sampling|第 1.1 节@)。")
LIST_ITEM (U"3. 编码方式 (线性、8 或 16 位、字节序、μ-law、A-law，参见 @@Sound files 1.2. Quantization|第 1.2 节@)。")
LIST_ITEM (U"4. 通道数 (单声道、双声道，参见 @@Sound files 1.3. Channels|第 1.3 节@)。")
LIST_ITEM (U"5. 时长 (通常为采样点个数)。")
MAN_END

MAN_BEGIN (U"Sound files 1.5. Size", U"ppgb", 20000126)
NORMAL (U"声音文件的大小等于文件头的大小"
	"加上采样点数、量化大小和通道数的乘积。")
NORMAL (U"例如，一个时长为 3 秒、采样率为 44100 Hz 的立体声声音，"
	"当写入 16 位 NeXT/Sun 文件时，将占用磁盘空间为：")
EQUATION (U"28 + 2 * 3.0 * 44100 * 2 = 529228 字节")
NORMAL (U"而相同的声音，当混音为单声道、降采样至 8000 Hz，"
	"并写入 μ-law NeXT/Sun 文件时，仅占用磁盘空间为：")
EQUATION (U"28 + 1 * 3.0 * 8000 * 1 = 24028 字节")
NORMAL (U"第一个例子是典型的 CD 音质，第二个是电话语音。")
MAN_END

MAN_BEGIN (U"Sound files 1.6. Compression", U"ppgb", 20210604)
NORMAL (U"Praat 过去能够读取某些压缩声音文件格式 (例如 shortened NIST、Polyphone)，"
	"但由于许可问题 (Praat 走向了开源，而 Shorten 没有)，"
	"您现在需要在将它们读入 Praat 之前，使用其他 (免费提供的) 程序进行转换。"
	"Praat 可以解码 (但不能创建) MP3 文件、Ogg Vorbis 文件和 Ogg Opus 文件。"
	"Praat 完全支持 FLAC 压缩文件。")
MAN_END

MAN_BEGIN (U"Sound files 2. File types", U"ppgb", 20201229)
LIST_ITEM (U"2.1. @@Sound files 2.1. WAV files|WAV 文件@")
LIST_ITEM (U"2.2. @@Sound files 2.2. AIFF files|AIFF 文件@")
LIST_ITEM (U"2.3. @@Sound files 2.3. AIFC files|AIFC 文件@")
LIST_ITEM (U"2.4. @@Sound files 2.4. NeXT/Sun (.au) files|NeXT/Sun (.au) 文件@")
LIST_ITEM (U"2.5. @@Sound files 2.5. NIST files|NIST 文件@")
LIST_ITEM (U"2.6. @@Sound files 2.6. FLAC files|FLAC 文件@")
LIST_ITEM (U"2.7. @@Sound files 2.7. MP3 files|MP3 文件@")
LIST_ITEM (U"2.8. @@Sound files 2.8. Ogg Vorbis files|Ogg Vorbis 文件@")
LIST_ITEM (U"2.9. @@Sound files 2.9. Ogg Opus files|Ogg Opus 文件@")
MAN_END

MAN_BEGIN (U"Sound files 2.1. WAV files", U"ppgb", 20040223)
NORMAL (U"这是 Windows 计算机上最常用的音频文件类型，在互联网上也非​​常普遍。")
MAN_END

MAN_BEGIN (U"Sound files 2.2. AIFF files", U"ppgb", 20190517)
NORMAL (U"AIFF 代表：音频交换文件格式 (Audio Interchange File Format)。")
NORMAL (U"这种声音文件的标准格式是由 Apple 定义的。"
	"它也是 Iris Indigo 上声音文件的格式，"
	"其中每个采样被量化为 16 位。")
ENTRY (U"读取")
NORMAL (U"要从磁盘打开 AIFF 文件，请从 Open 菜单中选择 @@Read from file...@。"
	"Praat 支持普通的 8 位、16 位、24 位或 32 位编码的 AIFF 和 AIFC 文件，"
	"但不支持压缩的 AIFC 文件。Praat 能够识别任何采样频率和任意通道数。")
NORMAL (U"生成的 Sound 对象将出现在对象列表中。"
	"其名称将与文件名相同，但不带扩展名。")
ENTRY (U"保存")
NORMAL (U"要将 @Sound 对象导出为 16 位 AIFF 文件，请选中 @Sound 并从 Save 菜单中选择 @@Save as AIFF file...@。")
MAN_END

MAN_BEGIN (U"Sound files 2.3. AIFC files", U"ppgb", 20190517)
NORMAL (U"AIFC 是 AIFF(C) 或 AIFF-C 的缩写，即支持可选压缩的音频交换文件格式"
	" (参见 @@Sound files 2.2. AIFF files|第 2.2 节@)。")
NORMAL (U"Praat 读取普通的 8 位、16 位、24 位或 32 位编码的未压缩 AIFC 文件，"
	"但不支持压缩的 AIFC 文件。")
MAN_END

MAN_BEGIN (U"Sound files 2.4. NeXT/Sun (.au) files", U"ppgb", 20210604)
NORMAL (U"这是 Sun 工作站上的声音文件格式。")
ENTRY (U"读取")
NORMAL (U"要从磁盘读取 Sun 音频文件中的 #Sound，请使用 @@Read from file...@。"
	"Praat 会要求您输入文件名。"
	"单击“确定”后，Praat 会确定文件的编码。"
	"如果编码是 16 位线性，则 16 位采样值除以 32768，以便"
	"生成的 Sound 的振幅在 -1.0 和 +1.0 之间。"
	"如果编码是 8 位 %μ-law，则 16 位采样值首先通过查表确定。")
NORMAL (U"生成的 Sound 将出现在对象列表中；"
	"其名称将与文件名相同，但不包含扩展名。")
ENTRY (U"保存")
NORMAL (U"使用 @@Save as NeXT/Sun file...@。Sound 的采样点乘以 32768"
	"并量化在 -32768 和 32767 之间；"
	"结果以 16 位单声道 Sun 音频格式写入文件。")
NORMAL (U"为避免削波，请将绝对振幅保持在 1.000 以下。"
	"如果最大声压级为 91 dB（最大值 = 32767），"
	"则量化阈值为 (最大值 = 1/2) -5 dB。")
MAN_END

MAN_BEGIN (U"Sound files 2.5. NIST files", U"ppgb", 20040223)
NORMAL (U"这是一种由语音研究人员使用的音频文件类型。例如用在 TIMIT 数据库中。"
	"Praat 可读取多种类型的 NIST 文件：大端序、小端序、μ-law、A-law、Polyphone。"
	"使用 #shorten 压缩的 NIST 文件已不再受支持"
	" (参见 @@Sound files 1.6. Compression|第 1.6 节@)。")
MAN_END

MAN_BEGIN (U"Sound files 2.6. FLAC files", U"Erez Volk", 20070514)
NORMAL (U"一种无损压缩音频格式 (参见 ##http://flac.sourceforge.net#)。"
	"Praat 支持读取所有比特率/频率设置下的 FLAC 文件"
	" (参见 @@Sound files 1.6. Compression|第 1.6 节@)。")
MAN_END

MAN_BEGIN (U"Sound files 2.7. MP3 files", U"Erez Volk", 20070601)
NORMAL (U"一种广泛使用的有损音频压缩格式。"
	"Praat 通过 MPEG 音频解码器库 (MPEG Audio Decoder library) 支持 MP3 解码"
	" ##http://www.underbit.com/products/mad/#。"
	" (参见 @@Sound files 1.6. Compression|第 1.6 节@)。")
MAN_END

MAN_BEGIN (U"Sound files 2.8. Ogg Vorbis files", U"djmw", 20210604)
NORMAL (U"Vorbis 是一种通用且免专利的有损音频压缩格式。"
	"Praat 通过公开的开源代码支持 Ogg Vorbis 解码："
	" ##https://xiph.org/downloads/#。Praat 使用了 libogg-1.3.4 和 libvorbis-1.3.7"
	" (参见 @@Sound files 1.6. Compression|第 1.6 节@)。")
MAN_END

MAN_BEGIN (U"Sound files 2.9. Ogg Opus files", U"djmw", 20210604)
NORMAL (U"Opus 是一种通用且免专利的有损音频压缩格式，"
	"是 @@Sound files 2.8. Ogg Vorbis files|Vorbis@ 的后继者。"
	"根据 Xiph.Org 官方网站的说法，该格式 “由 Xiph.Org 基金会开发，并由互联网工程任务组 (IETF) 标准化，旨在以单一格式高效地"
	"编码语音和通用音频，同时保持足够低的延迟以进行实时交互式通信，"
	"并且复杂度足够低以适用于低端嵌入式处理器。”"
	"Praat 通过公开的开源代码支持 Ogg Opus 解码："
	" ##https://opus-codec.org/downloads/#。Praat 使用了 opus-1.3.1 和 opusfile-0.12"
	" (参见 @@Sound files 1.6. Compression|第 1.6 节@)。")
MAN_END

MAN_BEGIN (U"Sound files 3. Files that Praat can read", U"ppgb", 20210604)
INTRO (U"Praat 可以读取多种格式的五种标准声音文件，"
	"以及许多专有的声音文件类型。")
ENTRY (U"标准声音文件")
NORMAL (U"@@Open menu|Open（打开）菜单@ 包含两个用于打开声音文件的命令：")
LIST_ITEM (U"• 通过 @@Read from file...@，您可以将整个声音文件读取到内存中。"
	"列表中将出现一个 @Sound 对象。"
	"如果您的声音文件不是很长且能放进内存，这是合适的。"
	"拥有 @Sound 对象的好处是您可以直接对其"
	"进行各种语音分析。")
LIST_ITEM (U"• 通过 @@Open long sound file...@，您可以打开一个由于太大而"
	"无法完整读入内存的声音文件（例如长达数小时）。列表中将出现一个 @LongSound 对象。"
	"您通常会选择 #View 来查看该声音的内容并进行分析。"
	"Praat 仅在播放或显示特定部分时，才会将文件中的所需部分"
	"读取到内存中。")
NORMAL (U"这两个命令都支持以下六种标准音频文件格式：")
LIST_ITEM (U"• WAV:")
LIST_ITEM1 (U"• 线性 16 位小端序 (linear 16-bit little-endian)")
LIST_ITEM1 (U"• 8 位 μ-law (8-bit μ-law)")
LIST_ITEM1 (U"• 8 位 A-law (8-bit A-law)")
LIST_ITEM1 (U"• 线性 8 位无符号 (linear 8-bit unsigned)")
LIST_ITEM (U"• AIFF 或 AIFC:")
LIST_ITEM1 (U"• 线性 16 位大端序 (linear 16-bit big-endian)")
LIST_ITEM1 (U"• 线性 8 位有符号 (linear 8-bit signed)")
LIST_ITEM (U"• NeXT/Sun (.au):")
LIST_ITEM1 (U"• 线性 16 位大端序 (linear 16-bit big-endian)")
LIST_ITEM1 (U"• 8 位 μ-law (8-bit μ-law)")
LIST_ITEM1 (U"• 8 位 A-law (8-bit A-law)")
LIST_ITEM1 (U"• 线性 8 位有符号 (linear 8-bit signed)")
LIST_ITEM (U"• NIST:")
LIST_ITEM1 (U"• 线性 16 位小端序 (linear 16-bit little-endian)")
LIST_ITEM1 (U"• 线性 16 位大端序 (linear 16-bit big-endian)")
LIST_ITEM1 (U"• 8 位 μ-law (8-bit μ-law)")
LIST_ITEM1 (U"• 8 位 A-law (8-bit A-law)")
LIST_ITEM1 (U"• 线性 8 位有符号 (linear 8-bit signed)")
LIST_ITEM (U"• FLAC:")
LIST_ITEM1 (U"• 8 位、16 位、24 位或 32 位")
LIST_ITEM1 (U"• 所有采样频率")
LIST_ITEM (U"• MP3:")
LIST_ITEM1 (U"• 所有恒定或可变比特率")
LIST_ITEM (U"• Shorten:")
LIST_ITEM1 (U"• 8 位 A-law")
MAN_END

MAN_BEGIN (U"Sound files 4. Files that Praat can write", U"ppgb", 20210604)
INTRO (U"Praat 可以将 Sound 对象导出为六种类型的标准声音文件，使用相应的线性 16 位格式：")
LIST_ITEM (U"• @@Save as WAV file...@ (16 位小端序)")
LIST_ITEM (U"• @@Save as AIFF file...@ (16 位大端序)")
LIST_ITEM (U"• @@Save as AIFC file...@ (16 位大端序)")
LIST_ITEM (U"• @@Save as NeXT/Sun file...@ (16 位大端序)")
LIST_ITEM (U"• @@Save as NIST file...@ (16 位小端序)")
LIST_ITEM (U"• @@Save as FLAC file...@ (16 位)")
MAN_END

MAN_BEGIN (U"Save as WAV file...", U"ppgb", 20110129)
INTRO (U"使用此命令，您可以将一个或多个选定的 @Sound 和/或 @LongSound 对象以单个 16 位小端序 WAV 文件的格式保存到磁盘上。有关更多信息，请参见 @@Sound files|声音文件@ 教程。")
MAN_END

MAN_BEGIN (U"Save as AIFF file...", U"ppgb", 20110129)
INTRO (U"使用此命令，您可以将一个或多个选定的 @Sound 和/或 @LongSound 对象以单个 16 位大端序 AIFF 文件的格式保存到磁盘上。有关更多信息，请参见 @@Sound files|声音文件@ 教程。")
/*ENTRY (U"AIFF file format for writing")
NORMAL (U"Although")*/
MAN_END

MAN_BEGIN (U"Save as AIFC file...", U"ppgb", 20110129)
INTRO (U"使用此命令，您可以将一个或多个选定的 @Sound 和/或 @LongSound 对象以单个 16 位大端序 AIFC 文件的格式保存到磁盘上。有关更多信息，请参见 @@Sound files|声音文件@ 教程。")
MAN_END

MAN_BEGIN (U"Save as NeXT/Sun file...", U"ppgb", 20110129)
INTRO (U"使用此命令，您可以将一个或多个选定的 @Sound 和/或 @LongSound 对象以单个 16 位大端序 NeXT/Sun (.au) 文件的格式保存到磁盘上。有关更多信息，请参见 @@Sound files|声音文件@ 教程。")
MAN_END

MAN_BEGIN (U"Save as NIST file...", U"ppgb", 20110129)
INTRO (U"使用此命令，您可以将一个或多个选定的 @Sound 和/或 @LongSound 对象以单个 16 位小端序 NIST 音频文件的格式保存到磁盘上。有关更多信息，请参见 @@Sound files|声音文件@ 教程。")
MAN_END

MAN_BEGIN (U"Save as FLAC file...", U"ppgb", 20110129)
INTRO (U"使用此命令，您可以将一个或多个选定的 @Sound 和/或 @LongSound 对象以单个 16 位 FLAC 音频文件的格式保存到磁盘上。有关更多信息，请参见 @@Sound files|声音文件@ 教程。")
MAN_END

MAN_BEGIN (U"NIST files", U"Erez Volk", 20110131)
INTRO (U"在磁盘上存储 @Sound（声音）对象的一种方法。")
ENTRY (U"文件格式")
NORMAL (U"Timit 数据库和 Groningen 语音语料库的压缩声音文件。")
ENTRY (U"读取")
NORMAL (U"使用 @@Read from file...|从文件读取...@。")
ENTRY (U"保存")
NORMAL (U"使用 ##Save as NIST file...#。")
MAN_END

MAN_BEGIN (U"FLAC files", U"Erez Volk", 20110131)
INTRO (U"在磁盘上存储 @Sound（声音）对象的一种方法。")
ENTRY (U"文件格式")
NORMAL (U"一种无损压缩的音频文件格式。")
ENTRY (U"读取")
NORMAL (U"使用 @@Read from file...|从文件读取...@。")
ENTRY (U"保存")
NORMAL (U"使用 ##Save as FLAC file...#。")
MAN_END

MAN_BEGIN (U"How to concatenate sound files", U"ppgb", 20110131)
INTRO (U"您可以拼接 AIFF、AIFC、WAV、NeXT/Sun、NIST 和 FLAC 音频文件以及已读入内存的其他文件的任意组合。")
NORMAL (U"例如，如果您想将一个 30 分钟的 AIFF 文件、一个 4 分钟的 Kay 声音文件和一个 60 分钟的 NeXT/Sun 文件拼接并保存为一个 94 分钟的 WAV 文件，您可以按照以下步骤操作：")
LIST_ITEM (U"1. 从 @@Open menu|Open 菜单@ 使用 @@Open long sound file...|打开长音频文件...@ 打开 AIFF 文件。列表中将出现一个 @LongSound 对象。")
LIST_ITEM (U"2. 使用 @@Read from file...|从文件读取...@ 将 Kay 声音文件读入内存。列表中将出现一个 @Sound 对象。")
LIST_ITEM (U"3. 从 @@Open menu|Open 菜单@ 使用 @@Open long sound file...|打开长音频文件...@ 打开 NeXT/Sun 文件。列表中将出现第二个 @LongSound 对象。")
LIST_ITEM (U"4. 同时选中这三个对象，然后从 @@Save menu|Save 菜单@ 中选择 @@Save as WAV file...|保存为 WAV 文件...@。")
NORMAL (U"这仅在所有声音的采样频率和通道数均相同时才有效。")
ENTRY (U"可用格式")
NORMAL (U"原始声音文件的格式可以是 16 位线性（大端序或小端序字节序）、8 位线性（有符号或无符号）、8 位 μ-law 或 8 位 A-law。生成的音频文件格式始终是 16 位线性，具有相应的默认字节序。当您选中 @LongSound 和/或 @Sound 对象的任意组合时，@@Save menu|Save 菜单@ 中将提供以下命令：")
LIST_ITEM (U"• @@Save as WAV file...|保存为 WAV 文件...@ (小端序)")
LIST_ITEM (U"• @@Save as AIFF file...|保存为 AIFF 文件...@ (大端序)")
LIST_ITEM (U"• @@Save as AIFC file...|保存为 AIFC 文件...@ (大端序)")
LIST_ITEM (U"• @@Save as NeXT/Sun file...|保存为 NeXT/Sun 文件...@ (大端序)")
LIST_ITEM (U"• @@Save as NIST file...|保存为 NIST 文件...@ (小端序)")
LIST_ITEM (U"• @@Save as FLAC file...|保存为 FLAC 文件...@")
MAN_END

MAN_BEGIN (U"LongSound", U"ppgb", 20110131)
INTRO (U"Praat 中的 @@types of objects|数据对象类型@ 之一。详细信息请参见 @@Sound files|声音文件@ 教程。")
NORMAL (U"LongSound 对象允许您直接查看和标注保存在磁盘上的声音文件。当音频文件过大，无法作为 @Sound 对象完整加载到内存中时（通常指几分钟以上的长音频），推荐使用此对象。")
ENTRY (U"如何创建 LongSound 对象")
NORMAL (U"在 @@Open menu|Open（打开）菜单@ 中选择 @@Open long sound file...@（打开长音频文件...），即可创建一个 LongSound 对象。")
ENTRY (U"LongSound 对象的操作与应用")
NORMAL (U"您可以使用 Save（保存）菜单中的命令，将 LongSound 对象另存为新的声音文件，也可以在此过程中转换其格式（支持 AIFF、AIFC、WAV、NeXT/Sun、NIST、FLAC 等格式）。您还可以通过这种方式将多个 LongSound 对象首尾拼接合并。详情请参阅 @@How to concatenate sound files|如何拼接声音文件@。")
ENTRY (U"如何查看 LongSound 对象")
NORMAL (U"在列表中选中该对象并选择 @@LongSound: View|View（查看）@，可以在 @LongSoundEditor 中打开并查看它。这也允许您将长音频中的某些片段提取为内存中的 @Sound 对象，或将选定片段直接另存为独立的声音文件。目前 Praat 暂不支持直接修改原始声音文件中的音频数据。")
ENTRY (U"如何对 LongSound 对象进行标注")
NORMAL (U"您可以通过以下步骤对 LongSound 对象进行分段和标注：")
LIST_ITEM (U"1. 选中该 LongSound 对象。")
LIST_ITEM (U"2. 选择 @@LongSound: To TextGrid...@ 并输入需要创建的层级名称。")
LIST_ITEM (U"3. 同时选中生成的 @TextGrid 对象和 LongSound 对象，然后点击 ##View & Edit#。")
NORMAL (U"屏幕上会弹出一个 @TextGridEditor 窗口，并在其中载入该长音频。")
ENTRY (U"局限性")
NORMAL (U"支持的原始声音文件大小上限为 2 GB（吉字节），这相当于约 3 小时的 CD 级音质双声道立体声，或者 12 小时的 16 位单声道（采样率为 22050 Hz）音频。")
MAN_END

MAN_BEGIN (U"LongSound: To TextGrid...", U"ppgb", 19980730)
INTRO (U"该命令可以创建一个没有任何标签的 @TextGrid，并从选定的 @LongSound 复制其时间范围。")
NORMAL (U"有关设置的信息，请参见 @@Sound: To TextGrid...|Sound: To TextGrid...（声音转 TextGrid...）@。")
MAN_END

MAN_BEGIN (U"LongSound: View", U"ppgb", 19980730)
INTRO (U"该命令可在 @LongSoundEditor 中查看选定的 @LongSound 对象。")
MAN_END

MAN_BEGIN (U"LongSoundEditor", U"ppgb", 20041124)
INTRO (U"Praat 中的 @@Editors|编辑器@ 之一，用于查看 @@LongSound|LongSound@（长音频对象）对象。")
NORMAL (U"此查看器允许您：")
LIST_ITEM (U"• 查看并聆听磁盘上声音文件的任意部分；")
LIST_ITEM (U"• 将选定部分作为 @@Sound|Sound@（声音）对象复制到对象列表中，以便对其进行详细分析或保存为较小的声音文件；")
LIST_ITEM (U"• 将选定部分作为 @@Sound|Sound@（声音）对象复制到声音剪贴板中，以便将其粘贴到您正在 @SoundEditor 中查看的另一个声音对象中。")
NORMAL (U"若要对 LongSound 对象进行标注和分段，请改用 @TextGridEditor（参见 @LongSound）。")
NORMAL (U"出于运行速度的考虑，单次显示和播放采样的长度限制在 60 秒以内（不过您可以通过主菜单 Preferences 中的 ##LongSound prefs# 来修改这一限制）；声音文件本身可以包含数小时 of 声音。")
MAN_END

MAN_BEGIN (U"Open long sound file...", U"ppgb", 19980730)
INTRO (U"@@Open menu|Open 菜单@ 中的一个命令，用于创建一个 @LongSound 对象。")
NORMAL (U"该文件将以只读方式打开。在您删除该 LongSound 对象之前，该文件将一直保持打开状态。")
MAN_END

MAN_BEGIN (U"Sesam/LVS files", U"ppgb", 20170828)
INTRO (U"在磁盘上存储 @Sound（声音）对象的一种方法。")
ENTRY (U"文件格式")
NORMAL (U"SESAM 和 LVS 程序所使用的声音文件。每个采样点通常被量化为 12 位。")
ENTRY (U"读取")
NORMAL (U"要从磁盘读取 Sesam 文件中的 #Sound，请使用 @@Read from file...|从文件读取...@。文件名应以 \".sdf\" 或 \".SDF\" 结尾。")
NORMAL (U"12 位采样值将除以 2048，以便生成的 Sound 振幅在 -1.0 到 +1.0 之间。")
NORMAL (U"生成的 #Sound 将出现在对象列表中；其名称将与文件名相同（不带扩展名）。")
NORMAL (U"如果声音是按每个采样点 16 位编码的，则读取后应除以 16（使用 `Formula: ~ self / 16`）。")
ENTRY (U"保存")
NORMAL (U"使用 ##Save as Sesam file...#。Praat 会要求您输入文件名。单击“确定”后，Sound 的采样值将乘以 2048，并量化在 -2048 到 2047 之间；结果将以 12 位 LVS 和 Sesam 格式写入文件。")
NORMAL (U"为避免削波，请将绝对振幅保持在 1.000 以下。如果最大声压级为 91 dB（最大值 = 2047），则量化阈值为（最大值 = 1/2）19 dB。")
NORMAL (U"如果您更喜欢 16 位编码，则在保存之前应乘以 16（使用 `Formula: ~ self * 16`）。")
MAN_END

}

/* End of file manual_soundFiles.cpp */
