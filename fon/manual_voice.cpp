/* manual_voice.cpp
 *
 * Copyright (C) 1992-2007,2010,2011,2014-2017,2022-2025 Paul Boersma
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

void manual_voice_init (ManPages me);
void manual_voice_init (ManPages me) {

MAN_PAGES_BEGIN
R"~~~(
################################################################################
"Voice"
© Paul Boersma 2003-2006

本教程介绍如何在 Praat 中进行嗓音分析（voice analysis）。
要理解本教程，您需要先熟悉 @@Intro|入门教程@，其中介绍了 @@SoundEditor|声音编辑器@ 窗口的更通用功能。

Praat 的大多数嗓音分析方法都始于声门脉冲（glottal pulses），它们在 @@SoundEditor|声音编辑器@ 窗口中显示为穿过波形图的蓝色垂直线。如果您没有看到这些线，请从 #Pulses（脉冲）菜单中选择 @@Show pulses|显示脉冲@。如果您的声音较长，您可能需要放大（zoom in）才能看到单个脉冲。您可能会注意到，对于某些声音，当您放大或滚动时，脉冲的时间位置可能会发生变化。这是因为分析时仅使用声音的可见部分。当您放大或滚动时，测量结果也会略有不同。

Pulse（脉冲）菜单包含 @@Voice report|嗓音报告@ 命令，它会在 @@Info window|信息窗口@ 中显示选区可见部分（如果只有光标而没有选区，或者选区不可见，则为整个声音的可见部分）的许多嗓音测量结果。

Pitch settings（音高设置）
=========================

嗓音测量结果将取决于您的 @@Pitch settings...|音高设置...@。
通常，您需要注意音高范围。标准范围是 75\--600 赫兹（Hertz），但如果是病理性的男性嗓音，如果其典型范围处于该区间，可以采用例如 50\--200 赫兹的范围。
您可能还需要选择 ##Optimize for voice analysis#（针对嗓音分析优化）；否则，嗓音报告会抱怨可能存在不准确性。
“高级”音高设置（例如 ##Silence threshold#（静音阈值）和 ##Octave jump cost#（倍频跳变惩罚））可以保持在其标准值。

,	@@Voice 1. Voice breaks|Voice 1. 语音中断@
,	@@Voice 2. Jitter|Voice 2. 基频微扰 (Jitter)@
,	@@Voice 3. Shimmer|Voice 3. 振幅微扰 (Shimmer)@
,	@@Voice 4. Additive noise|Voice 4. 加性噪声@ (HNR, harmonicity)
,	@@Voice 5. Comparison with other programs|Voice 5. 与其他软件的对比@
,	@@Voice 6. Automating voice analysis with a script|Voice 6. 使用脚本自动进行嗓音分析@

################################################################################
"Voice 1. Voice breaks"
© Paul Boersma 2003

正常嗓音在发音 [a] 时可以轻松维持一段时间的发声（phonation）。
有些病理嗓音在这方面会遇到困难。在 Praat 中可以通过两种方式来测量这一点。

局部清音音高帧比例 (Fraction of locally unvoiced pitch frames)
=============================================================

这是被分析为清音（无声）的音高帧比例（MDVP 称之为 DUV）。如果音高下限（pitch floor）是 75 Hz，您的 @@SoundEditor|声音编辑器@ 窗口将包含间隔 0.01 秒的音高测量值，因此如果您选择一秒，将会有 100 个音高帧。如果其中有 86 个是局部浊音帧，则比例将为 14%。

通常的音高分析包含一个%%寻路器%（path finder），它会在局部的音高候选者中搜索一条平滑的路径。在确定局部清音帧比例时，该寻路器会被临时关闭。如果一个帧的发声强度低于%%发声阈值%（voicing threshold，标准值为 0.45），或者其局部峰值低于%%静音阈值%（silence threshold，标准值为 0.03），则该帧被视为%局部清音帧。

在嗓音报告中，清音帧的比例将报告如下：
{;
	Fraction of locally unvoiced frames: 14.000% (14/100)
}
括号中的数字分别是清音帧数和总帧数（在 MDVP 中，它们分别被称为 NUV 和 SEG）。

清音帧比例的规范值（参考值）为 0，即正常健康的嗓音在持续元音发音期间应该能够毫无困难地维持发声。任何非零值都可以被视为病理迹象（类似于普通感微度）。
自然地，在测量此参数时，您不应选择音频开头和结尾的静音段。

语音中断次数 (Number of voice breaks)
=====================================

相邻脉冲之间的距离长于 1.25 除以音高下限（pitch floor）的次数。
因此，如果音高下限是 75 Hz，则所有长于 16.6667 毫秒的脉冲间间隔都将被视为语音中断（voice breaks）。

语音中断程度 (Degree of voice breaks)
=====================================

这是信号中浊音部分之间中断的总时长，除以被分析信号的总时长（MDVP 称之为 DVB）。由于信号开头 and 结尾的静音不被视为中断，在测量此参数时，您可能不想选择这些静音段。

在嗓音报告中，语音中断程度将报告如下：
{;
	Degree of voice breaks: 29.529% (1.163061 s / 3.938685 s)
}
括号中的数字分别是语音中断的总时长和被分析信号的持续时间。

################################################################################
"Voice 2. Jitter"
© Paul Boersma 2003,2011

您可以在 @@SoundEditor|声音编辑器@ 窗口中测量基频微扰（Jitter）。首先，从 #Pulses（脉冲）菜单中选择 @@Show pulses|显示脉冲@。您将看到蓝色垂直线，它们可以被理解为代表声门的关闭。使用 #Pulses 菜单中的 @@Voice report|嗓音报告@ 来获取选定部分的 Jitter。通常，您只对持续的长元音进行 Jitter 测量。

嗓音报告提供了五种 Jitter 测量。所有这些测量都基于通过波形匹配程序（waveform-matching procedure，参见 @@Voice 6. Automating voice analysis with a script|Voice 6. 使用脚本自动进行嗓音分析@）对所有%周期（periods）进行的计算。其中，##Period floor#（周期下限）设置是 0.8 除以音高上限（pitch ceiling），##Period ceiling#（周期上限）设置是 1.25 除以音高下限（pitch floor），而 ##Maximum period factor#（最大周期因子）则在 @@Advanced pulses settings...@ 中确定。

Jitter (local) 局部基频微扰
==========================

这是相邻周期之间差值的平均绝对值，除以平均周期。有关精确的过程，参见 @@PointProcess: Get jitter (local)...@。

MDVP 将此参数称为 %Jitt，并将 1.040% 设定为病理学阈值。由于该数值基于受噪声影响的 Jitter 测量（参见 @@Voice 5. Comparison with other programs|Voice 5. 与其他软件的对比@），正确的阈值可能更低。

Jitter (local, absolute) 绝对局部基频微扰
========================================

这是相邻周期之间差值的平均绝对值，单位为秒。有关精确的过程，参见 @@PointProcess: Get jitter (local, absolute)...@。

MDVP 将此参数称为 %Jita，并将 83.200 \mus（微秒）设定为病理学阈值。由于该数值基于受噪声影响的 Jitter 测量（参见 @@Voice 5. Comparison with other programs|Voice 5. 与其他软件的对比@），正确的阈值可能更低。

Jitter (rap) 相对平均扰动
=========================

这是相对平均扰动（Relative Average Perturbation），即一个周期与其相邻的两个周期的平均值之间的绝对差值的平均值，除以平均周期。有关精确的过程，参见 @@PointProcess: Get jitter (rap)...@。

MDVP 将 0.680% 设定为病理学阈值。由于该数值基于受噪声影响的 Jitter 测量（参见 @@Voice 5. Comparison with other programs|Voice 5. 与其他软件的对比@），正确的阈值可能更低。

Jitter (ppq5) 五点周期扰动商
===========================

这是五点周期扰动商（Period Perturbation Quotient），即一个周期与其自身及最邻近的四个周期的平均值之间的绝对差值的平均值，除以平均周期。有关精确的过程，参见 @@PointProcess: Get jitter (ppq5)...@。

MDVP 将此参数称为 %PPQ，并将 0.840% 设定为病理学阈值；由于该数值基于受噪声影响的 Jitter 测量（参见 @@Voice 5. Comparison with other programs|Voice 5. 与其他软件的对比@），正确的阈值可能更低。

Jitter (ddp) 差分基频微扰
=========================

这是相邻周期的差值之间差值的平均绝对值，除以平均周期。有关精确的过程，参见 @@PointProcess: Get jitter (ddp)...@。

这是 Praat 原始的 ##Get jitter# 测量值。其值是 RAP 的三倍。

################################################################################
"Voice 3. Shimmer"
© Paul Boersma 2003,2026

您可以在 @@SoundEditor|声音编辑器@ 窗口中测量振幅微扰（Shimmer）。首先，从 #Pulses（脉冲）菜单中选择 @@Show pulses|显示脉冲@。您将看到蓝色垂直线，它们可以被理解为代表声门的关闭。使用 Pulse（脉冲）菜单来获取选定部分的 Shimmer。通常，您只对持续的长元音进行 Shimmer 测量。嗓音报告提供了六种 Shimmer 测量。

Shimmer (local) 局部振幅微扰
===========================

这是相邻周期振幅之间绝对差值的平均值，除以平均振幅。MDVP 将此参数称为 %Shim，并将 3.810% 设定为病理学阈值。

Shimmer (local, dB) 分贝局部振幅微扰
===================================

这是相邻周期振幅之比的以 10 为底的对数的平均绝对值，乘以 20。MDVP 将此参数称为 %ShdB，并将 0.350 dB 设定为病理学阈值。

Shimmer (apq3) 三点振幅扰动商
============================

这是三点振幅扰动商（Amplitude Perturbation Quotient），即一个周期的振幅与其相邻的两个周期的振幅平均值之间的绝对差值的平均值，除以平均振幅。

Shimmer (apq5) 五点振幅扰动商
============================

这是五点振幅扰动商（Amplitude Perturbation Quotient），即一个周期的振幅与其自身及最邻近的四个周期的振幅平均值之间的绝对差值的平均值，除以平均振幅。

Shimmer (apq11) 十一点振幅扰动商
===============================

这是十一点振幅扰动商（Amplitude Perturbation Quotient），即一个周期的振幅与其自身及最邻近的十个周期的振幅平均值之间的绝对差值的平均值，除以平均振幅。MDVP 将此参数称为 %APQ，并将 3.070% 设定为病理学阈值。

Shimmer (dda) 差分振幅微扰
==========================

这是相邻周期振幅的差值之间差值的平均绝对值。这是 Praat 原始的 ##Get shimmer# 测量值。其值是 APQ3 的三倍。

################################################################################
"Voice 4. Additive noise"
© Paul Boersma 2002

对于可以假定为周期性的信号（例如持续元音），信噪比（signal-to-noise ratio）等于谐噪比（harmonics-to-noise ratio，HNR），您可以通过选择一个 @Sound（声音）对象并从 Periodicity（周期性）菜单中选择 ##To Harmonicity...# 命令之一来获取该值（有关算法，请参见 @@Sound: To Harmonicity (ac)...@ 或 @@Sound: To Harmonicity (cc)...@）。这是世界上最灵敏的 HNR 测量（最高可达 90 dB）。有关更多信息，请参阅 @Harmonicity 手册页。

################################################################################
"Voice 5. Comparison with other programs"
© Paul Boersma 2003,2006,2010

Praat 所做的发声（voicing）、基频微扰（jitter）和振幅微扰（shimmer）测量并不总是能与 MDVP 等其他软件做出的测量直接进行对比。原因在于发声判定决策策略以及周期和峰值确定的准确性差异。

5.1. 发声判定决策：略有不同
===========================

不同的软件使用非常不同的方法来决定信号的某个不规则部分是否被判断为浊音（voiced）。通过对比 Praat 的 @@Boersma (1993)@ 和 MDVP 的 @@Deliyski (1993)@ 可以得出以下思考。Praat 和 MDVP 都使用自相关方法（autocorrelation method）进行音高分析，但 MDVP 在计算自相关之前会将振幅量化为 -1、0 和 +1，而 Praat 使用原始振幅。此外，Praat 会通过将自相关函数除以窗口的自相关函数来进行校正，这与其他任何软件都不同。最后，Praat 使用 sinc 插值计算自相关峰值高度的精确估计，这与其他任何软件都不同。这三种差异（还有更多）都会影响 1/F0 处自相关峰值高度 of 的测量。这个高度通常被用作判断是否发声（voiced）的标准：如果它大于%%发声阈值%（voicing threshold，您可以通过 @@Pitch settings...|音高设置...@ 进行更改），该帧就被认为是浊音，否则被认为是清音（无声）。
在 Praat 中，标准的发声阈值是 0.45，而在 MDVP 中是 0.29，这表明 MDVP 倾向于比 Praat 将更多的帧判断为浊音。但这二者数值之间的差异部分可以通过以下事实来解释：MDVP 不校正自相关函数，且 MDVP 不进行精确的 sinc 插值。这两个特性都导致（在 MDVP 中）测量得到的 1/F0 处的峰值高度低于真实高度，正如 @@Boersma (1993)@ 所解释的那样。

5.2. Jitter 测量：有时非常不同
==============================

不同软件中的 Jitter 测量可能会产生不同的结果，Praat 经常给出比 MDVP 低得多的值，尤其是对于多噪声的声音。我现在来解释一下其中的差异来自哪里。在 @@Boersma (2009a)@ 中提供了更详细的带有插图的说明。

如果一段声音由计算机生成为声门源信号，具有 1% 的随机周期时长变化（围绕恒定的 F0 波动），然后使用对应于持续元音的声道配置特征进行滤波，Praat 和 MDVP 都将测量该声音具有 1% 的“Jitter”。因此，对于无噪声的微扰信号，这两个软件给出同样准确的结果。

如果一段声音由计算机生成为具有恒定周期的声门源信号，然后使用对应于持续元音的声道配置特征进行滤波，Praat 和 MDVP 测得该声音的“Jitter”都将小于 0.01%。因此，这两个软件在测量极小 Jitter 值时具有相当的灵敏度。

到目前为止，这两个软件给出的结果还是相当的。当加入噪声时，两者的差异就出现了。

如果一段声音由计算机生成为具有恒定周期的声门源信号，然后使用对应于持续元音的声道配置特征进行滤波，并且接着加入 1% 的加性“白”噪声（这是一个非常普通的量），Praat 测得该声音的“Jitter”为 0.02%，而 MDVP 测得该声音的“Jitter”为 0.6%。换句话说，Praat 会告诉您几乎没有 Jitter，而 MDVP 则会告诉您 Jitter 达到了接近病理的水平。相关的曲线可以在我的论文《Stemmen meten met Praat》和 @@Boersma (2009a)@ 中看到，其数值已由 Deliyski, Shaw & Evans 证实（%%Journal of Voice%, 2005: 23）。

可以看出，Praat 的“Jitter”测量试图将周期时长变化的影响（它报告为“Jitter”）与加性噪声的影响（它不报告为“Jitter”）分离开来；而 MDVP 的“Jitter”测量则结合了周期时长变化与加性噪声的影响（两者都被其报告为“Jitter”）。

Praat 和 MDVP 在 Jitter 测量上的差异是由于测量周期方式的不同所致。Praat 使用%%波形匹配%（waveform-matching）法，其中周期的长度是通过寻找最佳匹配的波形形状（“互相关”最大值）来确定的。而 MDVP 使用%%峰值拾取%（peak-picking）法，通过测量波形中两个局部最高峰值之间的时间差来确定周期长度。波形匹配方法平均去掉了加性噪声的很大一部分影响，而峰值拾取方法对加性噪声高度敏感。详细图解参见 @@Boersma (2009a)@。

################################################################################
"Voice 6. Automating voice analysis with a script"
© Paul Boersma 2005,2006,2014,2022,2023,2025

在 Praat 脚本中，您通常不想弹出声音窗口（Sound window）。相反，您可能只想在对象窗口（Objects window）中对数据对象进行操作。本页向您介绍如何使用脚本进行嗓音分析。

1. 在对象窗口中创建脉冲 (Creating the pulses in the Objects window)
=============================================================

您看到的蓝色垂直线脉冲是一个 @PointProcess 对象。如果您在声音窗口的 #Pulses 菜单中选择 ##Extract visible pulses#（提取可见脉冲），您就会看到这一点：一个 PointProcess 对象将会出现在列表中。

您也可以直接在对象窗口中创建 PointProcess。为此，选择一个 @Sound 对象，并从 Periodicity（周期性）菜单中选择 @@Sound: To PointProcess (periodic, cc)...@。

您也可以分两步来完成。首先，使用 @@Sound: To Pitch (raw autocorrelation)...@ 或 @@Sound: To Pitch (raw cross-correlation)...@ 创建一个 @Pitch 对象。然后，选择生成的 Pitch %连同原始 @Sound 对象，并选择 @@Sound & Pitch: To PointProcess (cc)@。

由于 @@Sound: To PointProcess (periodic, cc)...@ 的直接方法实际上使用 AC（自相关）方法来计算 Pitch（这对于语调分析是最佳的），如果您的目标是进行嗓音分析，您可能更倾向于采用两步法版本。在这种情况下，第一步使用 @@Sound: To Pitch (raw cc)...@，第二步使用 @@Sound & Pitch: To PointProcess (cc)@。声音编辑器窗口也是这样处理的：如果您在 @@Pitch settings...|音高设置...@ 中选择了 ##Optimize for voice analysis#（针对嗓音分析优化），Praat 会使用 @@Sound: To Pitch (raw cc)...@ 进行音高分析。

如果您想进行嗓音分析，%不应该做 的是仅通过选择一个 Pitch 对象并选择 @@Pitch: To PointProcess@ 来创建 PointProcess。因为这样生成的脉冲不会与 Sound 中的周期对齐。

2. 从脚本测量 Jitter (Measuring jitter from a script)
====================================================

一旦您拥有了代表 Sound 中周期的 PointProcess，您可以选择它并从 @@Query submenu|查询子菜单@ 中选择一些 ##Get jitter# 命令。

3. 从脚本测量 Shimmer (Measuring shimmer from a script)
======================================================

一旦您拥有了代表 Sound 中周期的 PointProcess，您可以将它与 Sound 一起选中，然后从 @@Query submenu|查询子菜单@ 中选择一些 ##Get shimmer# 命令。

4. 从脚本获取整个嗓音报告 (Getting the whole voice report from a script)
======================================================================

如果您将 Sound、Pitch 和 PointProcess 一起选中（全部三个），将会出现一个名为 ##Voice report...# 的按钮。如果您按下它，嗓音报告将会输出到 @@Info window|信息窗口@ 中。这与声音窗口中的嗓音报告完全相同，尽管您必须手动键入以指定时间范围。

在脚本中，您可以通过以下类似操作从嗓音报告中提取 Jitter 和 Shimmer 值：
{;
	voiceReport$ = \#{Voice report:} 0, 0, 75, 500, 1.3, 1.6, 0.03, 0.45
	jitter = \`{extractNumber} (voiceReport$, “Jitter (local): ”)
	shimmer = \`{extractNumber} (voiceReport$, “Shimmer (local): ”)
	\`{writeInfoLine}: “Jitter = ”, percent$ (jitter, 3), “, shimmer = ”, \`{percent$} (shimmer, 3)
}

5. 自动嗓音分析的缺点 (Disadvantage of automating voice analysis)
=============================================================

在上述所有命令中，您必须估算时间范围，并且通常会提供“0.0”和“0.0”，在这种情况下，您将获得整个声音的平均 Jitter 和 Shimmer。这可能会包含您通常不感兴趣的声音部分，例如不正确的人声起音。当在声音窗口中索取嗓音报告时，您不会遇到这些问题，因为在判断哪部分声音是相关的之后，您可以用手做出明确的时间选择。

################################################################################
"Voice report"
© Paul Boersma 2003

#Pulses（脉冲）菜单中的一个命令，它将向 @@Info window|信息窗口@ 写入关于许多嗓音参数的详细报告。参见 @Voice 教程。

)~~~"
MAN_PAGES_END
}

/* End of file manual_voice.cpp */
