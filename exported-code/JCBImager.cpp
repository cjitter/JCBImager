#include "JCBImager.h"

namespace JCBImager {

/****************************************************************************************
Copyright (c) 2023 Cycling '74

The code that Max generates automatically and that end users are capable of
exporting and using, and any associated documentation files (the “Software”)
is a work of authorship for which Cycling '74 is the author and owner for
copyright purposes.

This Software is dual-licensed either under the terms of the Cycling '74
License for Max-Generated Code for Export, or alternatively under the terms
of the General Public License (GPL) Version 3. You may use the Software
according to either of these licenses as it is most appropriate for your
project on a case-by-case basis (proprietary or not).

A) Cycling '74 License for Max-Generated Code for Export

A license is hereby granted, free of charge, to any person obtaining a copy
of the Software (“Licensee”) to use, copy, modify, merge, publish, and
distribute copies of the Software, and to permit persons to whom the Software
is furnished to do so, subject to the following conditions:

The Software is licensed to Licensee for all uses that do not include the sale,
sublicensing, or commercial distribution of software that incorporates this
source code. This means that the Licensee is free to use this software for
educational, research, and prototyping purposes, to create musical or other
creative works with software that incorporates this source code, or any other
use that does not constitute selling software that makes use of this source
code. Commercial distribution also includes the packaging of free software with
other paid software, hardware, or software-provided commercial services.

For entities with UNDER 200k USD in annual revenue or funding, a license is hereby
granted, free of charge, for the sale, sublicensing, or commercial distribution
of software that incorporates this source code, for as long as the entity's
annual revenue remains below 200k USD annual revenue or funding.

For entities with OVER 200k USD in annual revenue or funding interested in the
sale, sublicensing, or commercial distribution of software that incorporates
this source code, please send inquiries to licensing (at) cycling74.com.

The above copyright notice and this license shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Please see
https://support.cycling74.com/hc/en-us/articles/360050779193-Gen-Code-Export-Licensing-FAQ
for additional information

B) General Public License Version 3 (GPLv3)
Details of the GPLv3 license can be found at: https://www.gnu.org/licenses/gpl-3.0.html
****************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	int __exception;
	int vectorsize;
	t_sample m_dryLeftMidLpStage1X_156;
	t_sample m_dryLeftLowHpStage2Y_157;
	t_sample m_dryLeftLowHpStage2Y_158;
	t_sample m_dryLeftLowHpStage2X_159;
	t_sample m_dryLeftMidLpStage1X_155;
	t_sample m_dryLeftLowHpStage2X_160;
	t_sample m_dryLeftMidLpStage1Y_154;
	t_sample m_dryLeftMidLpStage2X_152;
	t_sample m_dryLeftMidLpStage2Y_149;
	t_sample m_dryLeftMidLpStage1Y_153;
	t_sample m_dryLeftMidLpStage2Y_150;
	t_sample m_dryLeftMidLpStage2X_151;
	t_sample m_dryLeftLowHpStage1Y_161;
	t_sample m_dryLeftLowHpStage1Y_162;
	t_sample m_dryLeftLowHpStage1X_163;
	t_sample m_dryLeftLowLpStage1X_171;
	t_sample m_dryLeftLowLpStage1Y_170;
	t_sample m_dryLeftLowLpStage1X_172;
	t_sample m_highCrossoverHistory_174;
	t_sample m_lowCrossoverHistory_173;
	t_sample m_dryLeftHighHpStage1X_148;
	t_sample m_dryLeftLowLpStage1Y_169;
	t_sample m_dryLeftLowLpStage2X_167;
	t_sample m_dryLeftLowHpStage1X_164;
	t_sample m_dryLeftLowLpStage2X_168;
	t_sample m_dryLeftLowLpStage2Y_165;
	t_sample m_dryLeftLowLpStage2Y_166;
	t_sample m_dryLeftHighHpStage1X_147;
	t_sample m_dryLeftHighHpStage1Y_146;
	t_sample m_dryLeftHighHpStage1Y_145;
	t_sample m_apLeftLowHpStage2Y_126;
	t_sample m_apLeftLowHpStage2Y_125;
	t_sample m_apLeftLowHpStage2X_127;
	t_sample m_apLeftLowHpStage1Y_129;
	t_sample m_apLeftLowHpStage2X_128;
	t_sample m_apLeftLowHpStage1Y_130;
	t_sample m_dryRightLowLpStage1X_124;
	t_sample m_dryRightLowLpStage1Y_122;
	t_sample m_dryRightLowLpStage2X_119;
	t_sample m_dryRightLowLpStage1X_123;
	t_sample m_dryRightLowLpStage2X_120;
	t_sample m_dryRightLowLpStage1Y_121;
	t_sample m_highBalanceHistory_175;
	t_sample m_apLeftLowHpStage1X_131;
	t_sample m_apLeftLowLpStage2Y_133;
	t_sample m_dryLeftHighHpStage2Y_141;
	t_sample m_apLeftLowLpStage1X_140;
	t_sample m_dryLeftHighHpStage2Y_142;
	t_sample m_dryLeftHighHpStage2X_144;
	t_sample m_dryLeftHighHpStage2X_143;
	t_sample m_apLeftLowHpStage1X_132;
	t_sample m_apLeftLowLpStage1X_139;
	t_sample m_apLeftLowLpStage1Y_137;
	t_sample m_apLeftLowLpStage2Y_134;
	t_sample m_apLeftLowLpStage1Y_138;
	t_sample m_apLeftLowLpStage2X_135;
	t_sample m_apLeftLowLpStage2X_136;
	t_sample m_highBandGainHistory_176;
	t_sample m_midBalanceHistory_177;
	t_sample m_midBandGainHistory_178;
	t_sample m_wetRightLowStage1X_216;
	t_sample m_wetRightLowStage1Y_215;
	t_sample m_wetRightLowStage1X_217;
	t_sample m_v_TRIM_219;
	t_sample m_w_MAKEUP_218;
	t_sample m_p_MUTHIGH_220;
	t_sample m_wetRightLowStage1Y_214;
	t_sample m_wetRightLowStage2X_212;
	t_sample m_wetRightHighStage1X_209;
	t_sample m_wetRightLowStage2X_213;
	t_sample m_wetRightLowStage2Y_210;
	t_sample m_wetRightLowStage2Y_211;
	t_sample m_wetRightHighStage1X_208;
	t_sample m_o_MUTMED_221;
	t_sample m_x_DRYWET_223;
	t_sample m_f_SOLOLOW_231;
	t_sample m_g_SOLOMED_230;
	t_sample m_e_HIGH_232;
	t_sample m_c_LOW_234;
	t_sample m_d_MED_233;
	t_sample m_n_MUTLOW_222;
	t_sample m_h_SOLOHIGH_229;
	t_sample m_j_input_227;
	t_sample m_m_HIGH_bal_224;
	t_sample m_i_BYPASS_228;
	t_sample m_l_MED_bal_225;
	t_sample m_k_LOW_bal_226;
	t_sample m_dryRightLowLpStage2Y_118;
	t_sample m_wetRightHighStage1Y_207;
	t_sample m_wetRightHighStage2X_205;
	t_sample m_wetRightHighBandStage2Y_186;
	t_sample m_dryWetHistory_185;
	t_sample m_wetRightHighBandStage2Y_187;
	t_sample m_wetRightHighBandStage2X_189;
	t_sample m_wetRightHighBandStage2X_188;
	t_sample m_wetRightHighBandStage1Y_190;
	t_sample m_bypassHistory_184;
	t_sample m_soloHighHistory_182;
	t_sample m_lowBandGainHistory_179;
	t_sample m_soloMidHistory_183;
	t_sample m_inputModeHistory_180;
	t_sample m_soloLowHistory_181;
	t_sample m_wetRightHighStage1Y_206;
	t_sample m_wetRightHighBandStage1Y_191;
	t_sample m_wetRightHighBandStage1X_193;
	t_sample m_wetRightMidStage1X_201;
	t_sample m_wetRightMidStage1X_200;
	t_sample m_wetRightHighStage2Y_202;
	t_sample m_wetRightHighStage2X_204;
	t_sample m_wetRightHighStage2Y_203;
	t_sample m_wetRightHighBandStage1X_192;
	t_sample m_wetRightMidStage1Y_199;
	t_sample m_wetRightMidStage2X_197;
	t_sample m_wetRightMidStage2Y_194;
	t_sample m_wetRightMidStage1Y_198;
	t_sample m_wetRightMidStage2Y_195;
	t_sample m_wetRightMidStage2X_196;
	t_sample m_b_FREQ_235;
	t_sample m_dryRightLowLpStage2Y_117;
	t_sample m_dryRightLowHpStage1X_115;
	t_sample m_wetLeftLowStage1X_37;
	t_sample m_wetLeftLowStage1Y_36;
	t_sample m_wetLeftLowStage1X_38;
	t_sample m_highCrossCorrelationM_40;
	t_sample m_highInvertHistory_39;
	t_sample m_highSideEnergyM_41;
	t_sample m_wetLeftLowStage1Y_35;
	t_sample m_wetLeftLowStage2X_33;
	t_sample m_wetLeftHighStage1X_30;
	t_sample m_wetLeftLowStage2X_34;
	t_sample m_wetLeftLowStage2Y_31;
	t_sample m_wetLeftLowStage2Y_32;
	t_sample m_wetLeftHighStage1X_29;
	t_sample m_highEnergyM_42;
	t_sample m_midSideEnergyM_44;
	t_sample m_lowCrossCorrelationM_52;
	t_sample m_lowLeftEnergyM_51;
	t_sample m_lowSideEnergyM_53;
	t_sample m_muteHighHistory_55;
	t_sample m_lowEnergyM_54;
	t_sample m_midCrossCorrelationM_43;
	t_sample m_lowRightEnergyM_50;
	t_sample m_midRightEnergyM_48;
	t_sample m_midEnergyM_45;
	t_sample m_midLeftEnergyM_49;
	t_sample m_highRightEnergyM_46;
	t_sample m_highLeftEnergyM_47;
	t_sample m_muteMidHistory_56;
	t_sample m_wetLeftHighStage1Y_28;
	t_sample m_wetLeftHighStage2X_26;
	t_sample m_wetLeftHighBandStage2Y_7;
	t_sample m_trimLeftHistory_6;
	t_sample m_wetLeftHighBandStage2Y_8;
	t_sample m_wetLeftHighBandStage2X_10;
	t_sample m_wetLeftHighBandStage2X_9;
	t_sample m_wetLeftHighBandStage1Y_11;
	t_sample m_trimRightHistory_5;
	t_sample m_makeupRightHistory_3;
	t_sample samplerate;
	t_sample m_makeupLeftHistory_4;
	t_sample m_makeupSharedHistory_1;
	t_sample m_trimSharedHistory_2;
	t_sample m_wetLeftHighStage1Y_27;
	t_sample m_wetLeftHighBandStage1Y_12;
	t_sample m_wetLeftHighBandStage1X_14;
	t_sample m_wetLeftMidStage1X_22;
	t_sample m_wetLeftMidStage1X_21;
	t_sample m_wetLeftHighStage2Y_23;
	t_sample m_wetLeftHighStage2X_25;
	t_sample m_wetLeftHighStage2Y_24;
	t_sample m_wetLeftHighBandStage1X_13;
	t_sample m_wetLeftMidStage1Y_20;
	t_sample m_wetLeftMidStage2X_18;
	t_sample m_wetLeftMidStage2Y_15;
	t_sample m_wetLeftMidStage1Y_19;
	t_sample m_wetLeftMidStage2Y_16;
	t_sample m_wetLeftMidStage2X_17;
	t_sample m_dryRightLowHpStage1X_116;
	t_sample m_muteLowHistory_57;
	t_sample m_highBandGainHistoryInternal_59;
	t_sample m_dryRightHighHpStage2X_96;
	t_sample m_dryRightHighHpStage2X_95;
	t_sample m_dryRightHighHpStage1Y_97;
	t_sample m_dryRightHighHpStage1X_99;
	t_sample m_dryRightHighHpStage1Y_98;
	t_sample m_dryRightHighHpStage1X_100;
	t_sample m_dryRightHighHpStage2Y_94;
	t_sample m_apRightLowLpStage1X_92;
	t_sample m_apRightLowLpStage1Y_89;
	t_sample m_dryRightHighHpStage2Y_93;
	t_sample m_apRightLowLpStage1Y_90;
	t_sample m_apRightLowLpStage1X_91;
	t_sample m_apRightLowLpStage2X_88;
	t_sample m_dryRightMidLpStage2Y_101;
	t_sample m_dryRightMidLpStage2X_103;
	t_sample m_dryRightLowHpStage2X_111;
	t_sample m_dryRightLowHpStage2Y_110;
	t_sample m_dryRightLowHpStage2X_112;
	t_sample m_dryRightLowHpStage1Y_114;
	t_sample m_dryRightLowHpStage1Y_113;
	t_sample m_dryRightMidLpStage2Y_102;
	t_sample m_dryRightLowHpStage2Y_109;
	t_sample m_dryRightMidLpStage1X_107;
	t_sample m_dryRightMidLpStage2X_104;
	t_sample m_dryRightMidLpStage1X_108;
	t_sample m_dryRightMidLpStage1Y_105;
	t_sample m_dryRightMidLpStage1Y_106;
	t_sample m_highSideGainHistory_58;
	t_sample m_apRightLowLpStage2X_87;
	t_sample m_apRightLowLpStage2Y_85;
	t_sample m_midBandGainHistoryInternal_67;
	t_sample m_midSideGainHistory_66;
	t_sample m_midInputModeHistory_68;
	t_sample m_midBalanceInternalHistory_70;
	t_sample m_midWidthHistory_69;
	t_sample m_midMakeupHistory_71;
	t_sample m_midInvertHistory_65;
	t_sample m_highMakeupHistory_63;
	t_sample m_highInputModeHistory_60;
	t_sample m_highBypassHistory_64;
	t_sample m_highWidthHistory_61;
	t_sample m_highBalanceHistoryInternal_62;
	t_sample m_apRightLowLpStage2Y_86;
	t_sample m_midBypassHistory_72;
	t_sample m_lowWidthHistory_74;
	t_sample m_apRightLowHpStage1Y_82;
	t_sample m_apRightLowHpStage1Y_81;
	t_sample m_apRightLowHpStage1X_83;
	t_sample m_apRightLowHpStage1X_84;
	t_sample m_lowInputModeHistory_73;
	t_sample m_apRightLowHpStage2X_80;
	t_sample m_apRightLowHpStage2Y_78;
	t_sample m_lowBalanceHistory_75;
	t_sample m_apRightLowHpStage2X_79;
	t_sample m_lowBypassHistory_76;
	t_sample m_apRightLowHpStage2Y_77;
	t_sample m_a_FREQ_236;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_makeupSharedHistory_1 = ((int)1);
		m_trimSharedHistory_2 = ((int)1);
		m_makeupRightHistory_3 = ((int)1);
		m_makeupLeftHistory_4 = ((int)1);
		m_trimRightHistory_5 = ((int)1);
		m_trimLeftHistory_6 = ((int)1);
		m_wetLeftHighBandStage2Y_7 = ((int)0);
		m_wetLeftHighBandStage2Y_8 = ((int)0);
		m_wetLeftHighBandStage2X_9 = ((int)0);
		m_wetLeftHighBandStage2X_10 = ((int)0);
		m_wetLeftHighBandStage1Y_11 = ((int)0);
		m_wetLeftHighBandStage1Y_12 = ((int)0);
		m_wetLeftHighBandStage1X_13 = ((int)0);
		m_wetLeftHighBandStage1X_14 = ((int)0);
		m_wetLeftMidStage2Y_15 = ((int)0);
		m_wetLeftMidStage2Y_16 = ((int)0);
		m_wetLeftMidStage2X_17 = ((int)0);
		m_wetLeftMidStage2X_18 = ((int)0);
		m_wetLeftMidStage1Y_19 = ((int)0);
		m_wetLeftMidStage1Y_20 = ((int)0);
		m_wetLeftMidStage1X_21 = ((int)0);
		m_wetLeftMidStage1X_22 = ((int)0);
		m_wetLeftHighStage2Y_23 = ((int)0);
		m_wetLeftHighStage2Y_24 = ((int)0);
		m_wetLeftHighStage2X_25 = ((int)0);
		m_wetLeftHighStage2X_26 = ((int)0);
		m_wetLeftHighStage1Y_27 = ((int)0);
		m_wetLeftHighStage1Y_28 = ((int)0);
		m_wetLeftHighStage1X_29 = ((int)0);
		m_wetLeftHighStage1X_30 = ((int)0);
		m_wetLeftLowStage2Y_31 = ((int)0);
		m_wetLeftLowStage2Y_32 = ((int)0);
		m_wetLeftLowStage2X_33 = ((int)0);
		m_wetLeftLowStage2X_34 = ((int)0);
		m_wetLeftLowStage1Y_35 = ((int)0);
		m_wetLeftLowStage1Y_36 = ((int)0);
		m_wetLeftLowStage1X_37 = ((int)0);
		m_wetLeftLowStage1X_38 = ((int)0);
		m_highInvertHistory_39 = ((int)0);
		m_highCrossCorrelationM_40 = ((int)0);
		m_highSideEnergyM_41 = ((t_sample)1e-12);
		m_highEnergyM_42 = ((t_sample)1e-12);
		m_midCrossCorrelationM_43 = ((int)0);
		m_midSideEnergyM_44 = ((t_sample)1e-12);
		m_midEnergyM_45 = ((t_sample)1e-12);
		m_highRightEnergyM_46 = ((t_sample)1e-12);
		m_highLeftEnergyM_47 = ((t_sample)1e-12);
		m_midRightEnergyM_48 = ((t_sample)1e-12);
		m_midLeftEnergyM_49 = ((t_sample)1e-12);
		m_lowRightEnergyM_50 = ((t_sample)1e-12);
		m_lowLeftEnergyM_51 = ((t_sample)1e-12);
		m_lowCrossCorrelationM_52 = ((int)0);
		m_lowSideEnergyM_53 = ((t_sample)1e-12);
		m_lowEnergyM_54 = ((t_sample)1e-12);
		m_muteHighHistory_55 = ((int)0);
		m_muteMidHistory_56 = ((int)0);
		m_muteLowHistory_57 = ((int)0);
		m_highSideGainHistory_58 = ((int)0);
		m_highBandGainHistoryInternal_59 = ((int)0);
		m_highInputModeHistory_60 = ((int)0);
		m_highWidthHistory_61 = ((int)0);
		m_highBalanceHistoryInternal_62 = ((int)0);
		m_highMakeupHistory_63 = ((int)0);
		m_highBypassHistory_64 = ((int)0);
		m_midInvertHistory_65 = ((int)0);
		m_midSideGainHistory_66 = ((int)0);
		m_midBandGainHistoryInternal_67 = ((int)0);
		m_midInputModeHistory_68 = ((int)0);
		m_midWidthHistory_69 = ((int)0);
		m_midBalanceInternalHistory_70 = ((int)0);
		m_midMakeupHistory_71 = ((int)0);
		m_midBypassHistory_72 = ((int)0);
		m_lowInputModeHistory_73 = ((int)0);
		m_lowWidthHistory_74 = ((int)0);
		m_lowBalanceHistory_75 = ((int)0);
		m_lowBypassHistory_76 = ((int)0);
		m_apRightLowHpStage2Y_77 = ((int)0);
		m_apRightLowHpStage2Y_78 = ((int)0);
		m_apRightLowHpStage2X_79 = ((int)0);
		m_apRightLowHpStage2X_80 = ((int)0);
		m_apRightLowHpStage1Y_81 = ((int)0);
		m_apRightLowHpStage1Y_82 = ((int)0);
		m_apRightLowHpStage1X_83 = ((int)0);
		m_apRightLowHpStage1X_84 = ((int)0);
		m_apRightLowLpStage2Y_85 = ((int)0);
		m_apRightLowLpStage2Y_86 = ((int)0);
		m_apRightLowLpStage2X_87 = ((int)0);
		m_apRightLowLpStage2X_88 = ((int)0);
		m_apRightLowLpStage1Y_89 = ((int)0);
		m_apRightLowLpStage1Y_90 = ((int)0);
		m_apRightLowLpStage1X_91 = ((int)0);
		m_apRightLowLpStage1X_92 = ((int)0);
		m_dryRightHighHpStage2Y_93 = ((int)0);
		m_dryRightHighHpStage2Y_94 = ((int)0);
		m_dryRightHighHpStage2X_95 = ((int)0);
		m_dryRightHighHpStage2X_96 = ((int)0);
		m_dryRightHighHpStage1Y_97 = ((int)0);
		m_dryRightHighHpStage1Y_98 = ((int)0);
		m_dryRightHighHpStage1X_99 = ((int)0);
		m_dryRightHighHpStage1X_100 = ((int)0);
		m_dryRightMidLpStage2Y_101 = ((int)0);
		m_dryRightMidLpStage2Y_102 = ((int)0);
		m_dryRightMidLpStage2X_103 = ((int)0);
		m_dryRightMidLpStage2X_104 = ((int)0);
		m_dryRightMidLpStage1Y_105 = ((int)0);
		m_dryRightMidLpStage1Y_106 = ((int)0);
		m_dryRightMidLpStage1X_107 = ((int)0);
		m_dryRightMidLpStage1X_108 = ((int)0);
		m_dryRightLowHpStage2Y_109 = ((int)0);
		m_dryRightLowHpStage2Y_110 = ((int)0);
		m_dryRightLowHpStage2X_111 = ((int)0);
		m_dryRightLowHpStage2X_112 = ((int)0);
		m_dryRightLowHpStage1Y_113 = ((int)0);
		m_dryRightLowHpStage1Y_114 = ((int)0);
		m_dryRightLowHpStage1X_115 = ((int)0);
		m_dryRightLowHpStage1X_116 = ((int)0);
		m_dryRightLowLpStage2Y_117 = ((int)0);
		m_dryRightLowLpStage2Y_118 = ((int)0);
		m_dryRightLowLpStage2X_119 = ((int)0);
		m_dryRightLowLpStage2X_120 = ((int)0);
		m_dryRightLowLpStage1Y_121 = ((int)0);
		m_dryRightLowLpStage1Y_122 = ((int)0);
		m_dryRightLowLpStage1X_123 = ((int)0);
		m_dryRightLowLpStage1X_124 = ((int)0);
		m_apLeftLowHpStage2Y_125 = ((int)0);
		m_apLeftLowHpStage2Y_126 = ((int)0);
		m_apLeftLowHpStage2X_127 = ((int)0);
		m_apLeftLowHpStage2X_128 = ((int)0);
		m_apLeftLowHpStage1Y_129 = ((int)0);
		m_apLeftLowHpStage1Y_130 = ((int)0);
		m_apLeftLowHpStage1X_131 = ((int)0);
		m_apLeftLowHpStage1X_132 = ((int)0);
		m_apLeftLowLpStage2Y_133 = ((int)0);
		m_apLeftLowLpStage2Y_134 = ((int)0);
		m_apLeftLowLpStage2X_135 = ((int)0);
		m_apLeftLowLpStage2X_136 = ((int)0);
		m_apLeftLowLpStage1Y_137 = ((int)0);
		m_apLeftLowLpStage1Y_138 = ((int)0);
		m_apLeftLowLpStage1X_139 = ((int)0);
		m_apLeftLowLpStage1X_140 = ((int)0);
		m_dryLeftHighHpStage2Y_141 = ((int)0);
		m_dryLeftHighHpStage2Y_142 = ((int)0);
		m_dryLeftHighHpStage2X_143 = ((int)0);
		m_dryLeftHighHpStage2X_144 = ((int)0);
		m_dryLeftHighHpStage1Y_145 = ((int)0);
		m_dryLeftHighHpStage1Y_146 = ((int)0);
		m_dryLeftHighHpStage1X_147 = ((int)0);
		m_dryLeftHighHpStage1X_148 = ((int)0);
		m_dryLeftMidLpStage2Y_149 = ((int)0);
		m_dryLeftMidLpStage2Y_150 = ((int)0);
		m_dryLeftMidLpStage2X_151 = ((int)0);
		m_dryLeftMidLpStage2X_152 = ((int)0);
		m_dryLeftMidLpStage1Y_153 = ((int)0);
		m_dryLeftMidLpStage1Y_154 = ((int)0);
		m_dryLeftMidLpStage1X_155 = ((int)0);
		m_dryLeftMidLpStage1X_156 = ((int)0);
		m_dryLeftLowHpStage2Y_157 = ((int)0);
		m_dryLeftLowHpStage2Y_158 = ((int)0);
		m_dryLeftLowHpStage2X_159 = ((int)0);
		m_dryLeftLowHpStage2X_160 = ((int)0);
		m_dryLeftLowHpStage1Y_161 = ((int)0);
		m_dryLeftLowHpStage1Y_162 = ((int)0);
		m_dryLeftLowHpStage1X_163 = ((int)0);
		m_dryLeftLowHpStage1X_164 = ((int)0);
		m_dryLeftLowLpStage2Y_165 = ((int)0);
		m_dryLeftLowLpStage2Y_166 = ((int)0);
		m_dryLeftLowLpStage2X_167 = ((int)0);
		m_dryLeftLowLpStage2X_168 = ((int)0);
		m_dryLeftLowLpStage1Y_169 = ((int)0);
		m_dryLeftLowLpStage1Y_170 = ((int)0);
		m_dryLeftLowLpStage1X_171 = ((int)0);
		m_dryLeftLowLpStage1X_172 = ((int)0);
		m_lowCrossoverHistory_173 = ((int)0);
		m_highCrossoverHistory_174 = ((int)0);
		m_highBalanceHistory_175 = ((int)0);
		m_highBandGainHistory_176 = ((int)0);
		m_midBalanceHistory_177 = ((int)0);
		m_midBandGainHistory_178 = ((int)0);
		m_lowBandGainHistory_179 = ((int)0);
		m_inputModeHistory_180 = ((int)0);
		m_soloLowHistory_181 = ((int)0);
		m_soloHighHistory_182 = ((int)0);
		m_soloMidHistory_183 = ((int)0);
		m_bypassHistory_184 = ((int)0);
		m_dryWetHistory_185 = ((int)0);
		m_wetRightHighBandStage2Y_186 = ((int)0);
		m_wetRightHighBandStage2Y_187 = ((int)0);
		m_wetRightHighBandStage2X_188 = ((int)0);
		m_wetRightHighBandStage2X_189 = ((int)0);
		m_wetRightHighBandStage1Y_190 = ((int)0);
		m_wetRightHighBandStage1Y_191 = ((int)0);
		m_wetRightHighBandStage1X_192 = ((int)0);
		m_wetRightHighBandStage1X_193 = ((int)0);
		m_wetRightMidStage2Y_194 = ((int)0);
		m_wetRightMidStage2Y_195 = ((int)0);
		m_wetRightMidStage2X_196 = ((int)0);
		m_wetRightMidStage2X_197 = ((int)0);
		m_wetRightMidStage1Y_198 = ((int)0);
		m_wetRightMidStage1Y_199 = ((int)0);
		m_wetRightMidStage1X_200 = ((int)0);
		m_wetRightMidStage1X_201 = ((int)0);
		m_wetRightHighStage2Y_202 = ((int)0);
		m_wetRightHighStage2Y_203 = ((int)0);
		m_wetRightHighStage2X_204 = ((int)0);
		m_wetRightHighStage2X_205 = ((int)0);
		m_wetRightHighStage1Y_206 = ((int)0);
		m_wetRightHighStage1Y_207 = ((int)0);
		m_wetRightHighStage1X_208 = ((int)0);
		m_wetRightHighStage1X_209 = ((int)0);
		m_wetRightLowStage2Y_210 = ((int)0);
		m_wetRightLowStage2Y_211 = ((int)0);
		m_wetRightLowStage2X_212 = ((int)0);
		m_wetRightLowStage2X_213 = ((int)0);
		m_wetRightLowStage1Y_214 = ((int)0);
		m_wetRightLowStage1Y_215 = ((int)0);
		m_wetRightLowStage1X_216 = ((int)0);
		m_wetRightLowStage1X_217 = ((int)0);
		m_w_MAKEUP_218 = 0;
		m_v_TRIM_219 = 0;
		m_p_MUTHIGH_220 = 0;
		m_o_MUTMED_221 = 0;
		m_n_MUTLOW_222 = 0;
		m_x_DRYWET_223 = 1;
		m_m_HIGH_bal_224 = 0.5;
		m_l_MED_bal_225 = 0.5;
		m_k_LOW_bal_226 = 0.5;
		m_j_input_227 = 1;
		m_i_BYPASS_228 = 0;
		m_h_SOLOHIGH_229 = 0;
		m_g_SOLOMED_230 = 0;
		m_f_SOLOLOW_231 = 0;
		m_e_HIGH_232 = 1;
		m_d_MED_233 = 1;
		m_c_LOW_234 = 1;
		m_b_FREQ_235 = 5000;
		m_a_FREQ_236 = 250;
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		t_sample * __out3 = __outs[2];
		t_sample * __out4 = __outs[3];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample freqLowHz = m_a_FREQ_236;
		t_sample freqHighHz = m_b_FREQ_235;
		t_sample bandLowGain = m_c_LOW_234;
		t_sample bandMidGain = m_d_MED_233;
		t_sample bandHighGain = m_e_HIGH_232;
		t_sample soloLow = m_f_SOLOLOW_231;
		t_sample soloMid = m_g_SOLOMED_230;
		t_sample soloHigh = m_h_SOLOHIGH_229;
		t_sample bypass = m_i_BYPASS_228;
		t_sample inputMode = m_j_input_227;
		t_sample lowBalance = m_k_LOW_bal_226;
		t_sample midBalance = m_l_MED_bal_225;
		t_sample highBalance = m_m_HIGH_bal_224;
		t_sample dryWet = m_x_DRYWET_223;
		t_sample muteLow = m_n_MUTLOW_222;
		t_sample muteMid = m_o_MUTMED_221;
		t_sample muteHigh = m_p_MUTHIGH_220;
		t_sample trimDb = m_v_TRIM_219;
		t_sample makeupDb = m_w_MAKEUP_218;
		t_sample trimTarget = dbtoa(trimDb);
		t_sample makeupTarget = dbtoa(makeupDb);
		t_sample xoverLow = ((freqLowHz <= ((int)20)) ? ((int)20) : ((freqLowHz >= ((int)1000)) ? ((int)1000) : freqLowHz));
		t_sample xoverHigh = ((freqHighHz <= ((int)1000)) ? ((int)1000) : ((freqHighHz >= ((int)20000)) ? ((int)20000) : freqHighHz));
		int rightSampleRate = samplerate;
		t_sample minb_237 = (((t_sample)0.45) * rightSampleRate);
		t_sample maxb_238 = ((minb_237 < xoverLow) ? minb_237 : xoverLow);
		t_sample rightLowHz = ((((int)10) < maxb_238) ? maxb_238 : ((int)10));
		t_sample minb_239 = (((t_sample)0.45) * rightSampleRate);
		t_sample maxb_240 = ((minb_239 < xoverHigh) ? minb_239 : xoverHigh);
		t_sample rightHighPreHz = ((((int)10) < maxb_240) ? maxb_240 : ((int)10));
		t_sample maxb_241 = (rightLowHz + ((int)1));
		t_sample rightHighHz = ((rightHighPreHz < maxb_241) ? maxb_241 : rightHighPreHz);
		t_sample rightW0Low = safediv((((t_sample)6.2831853071796) * rightLowHz), rightSampleRate);
		t_sample rightCosLow = cos(rightW0Low);
		t_sample rightSinLow = sin(rightW0Low);
		t_sample rightAlphaLow = (rightSinLow * ((t_sample)0.70710678118655));
		t_sample rightA0Low = (((int)1) + rightAlphaLow);
		t_sample rightA1Low = (((int)-2) * rightCosLow);
		t_sample rightA2Low = (((int)1) - rightAlphaLow);
		t_sample rightLpB0Low = safediv(((((int)1) - rightCosLow) * ((t_sample)0.5)), rightA0Low);
		t_sample rightLpB1Low = safediv((((int)1) - rightCosLow), rightA0Low);
		t_sample rightLpB2Low = rightLpB0Low;
		t_sample rightLpA1Low = safediv(rightA1Low, rightA0Low);
		t_sample rightLpA2Low = safediv(rightA2Low, rightA0Low);
		t_sample rightHpB0Low = safediv(((((int)1) + rightCosLow) * ((t_sample)0.5)), rightA0Low);
		t_sample rightHpB1Low = safediv((-(((int)1) + rightCosLow)), rightA0Low);
		t_sample rightHpB2Low = rightHpB0Low;
		t_sample rightHpA1Low = rightLpA1Low;
		t_sample rightHpA2Low = rightLpA2Low;
		t_sample rightW0High = safediv((((t_sample)6.2831853071796) * rightHighHz), rightSampleRate);
		t_sample rightCosHigh = cos(rightW0High);
		t_sample rightSinHigh = sin(rightW0High);
		t_sample rightAlphaHigh = (rightSinHigh * ((t_sample)0.70710678118655));
		t_sample rightA0High = (((int)1) + rightAlphaHigh);
		t_sample rightA1High = (((int)-2) * rightCosHigh);
		t_sample rightA2High = (((int)1) - rightAlphaHigh);
		t_sample rightLpB0High = safediv(((((int)1) - rightCosHigh) * ((t_sample)0.5)), rightA0High);
		t_sample rightLpB1High = safediv((((int)1) - rightCosHigh), rightA0High);
		t_sample rightLpB2High = rightLpB0High;
		t_sample rightLpA1High = safediv(rightA1High, rightA0High);
		t_sample rightLpA2High = safediv(rightA2High, rightA0High);
		t_sample rightHpB0High = safediv(((((int)1) + rightCosHigh) * ((t_sample)0.5)), rightA0High);
		t_sample rightHpB1High = safediv((-(((int)1) + rightCosHigh)), rightA0High);
		t_sample rightHpB2High = rightHpB0High;
		t_sample rightHpA1High = rightLpA1High;
		t_sample rightHpA2High = rightLpA2High;
		int leftSampleRate = samplerate;
		t_sample minb_242 = (((t_sample)0.45) * leftSampleRate);
		t_sample maxb_243 = ((minb_242 < xoverLow) ? minb_242 : xoverLow);
		t_sample leftLowHz = ((((int)10) < maxb_243) ? maxb_243 : ((int)10));
		t_sample minb_244 = (((t_sample)0.45) * leftSampleRate);
		t_sample maxb_245 = ((minb_244 < xoverHigh) ? minb_244 : xoverHigh);
		t_sample leftHighPreHz = ((((int)10) < maxb_245) ? maxb_245 : ((int)10));
		t_sample maxb_246 = (leftLowHz + ((int)1));
		t_sample leftHighHz = ((leftHighPreHz < maxb_246) ? maxb_246 : leftHighPreHz);
		t_sample leftW0Low = safediv((((t_sample)6.2831853071796) * leftLowHz), leftSampleRate);
		t_sample leftCosLow = cos(leftW0Low);
		t_sample leftSinLow = sin(leftW0Low);
		t_sample leftAlphaLow = (leftSinLow * ((t_sample)0.70710678118655));
		t_sample leftA0Low = (((int)1) + leftAlphaLow);
		t_sample leftA1Low = (((int)-2) * leftCosLow);
		t_sample leftA2Low = (((int)1) - leftAlphaLow);
		t_sample leftLpB0Low = safediv(((((int)1) - leftCosLow) * ((t_sample)0.5)), leftA0Low);
		t_sample leftLpB1Low = safediv((((int)1) - leftCosLow), leftA0Low);
		t_sample leftLpB2Low = leftLpB0Low;
		t_sample leftLpA1Low = safediv(leftA1Low, leftA0Low);
		t_sample leftLpA2Low = safediv(leftA2Low, leftA0Low);
		t_sample leftHpB0Low = safediv(((((int)1) + leftCosLow) * ((t_sample)0.5)), leftA0Low);
		t_sample leftHpB1Low = safediv((-(((int)1) + leftCosLow)), leftA0Low);
		t_sample leftHpB2Low = leftHpB0Low;
		t_sample leftHpA1Low = leftLpA1Low;
		t_sample leftHpA2Low = leftLpA2Low;
		t_sample leftW0High = safediv((((t_sample)6.2831853071796) * leftHighHz), leftSampleRate);
		t_sample leftCosHigh = cos(leftW0High);
		t_sample leftSinHigh = sin(leftW0High);
		t_sample leftAlphaHigh = (leftSinHigh * ((t_sample)0.70710678118655));
		t_sample leftA0High = (((int)1) + leftAlphaHigh);
		t_sample leftA1High = (((int)-2) * leftCosHigh);
		t_sample leftA2High = (((int)1) - leftAlphaHigh);
		t_sample leftLpB0High = safediv(((((int)1) - leftCosHigh) * ((t_sample)0.5)), leftA0High);
		t_sample leftLpB1High = safediv((((int)1) - leftCosHigh), leftA0High);
		t_sample leftLpB2High = leftLpB0High;
		t_sample leftLpA1High = safediv(leftA1High, leftA0High);
		t_sample leftLpA2High = safediv(leftA2High, leftA0High);
		t_sample leftHpB0High = safediv(((((int)1) + leftCosHigh) * ((t_sample)0.5)), leftA0High);
		t_sample leftHpB1High = safediv((-(((int)1) + leftCosHigh)), leftA0High);
		t_sample leftHpB2High = leftHpB0High;
		t_sample leftHpA1High = leftLpA1High;
		t_sample leftHpA2High = leftLpA2High;
		int dryLeftSampleRate = samplerate;
		t_sample minb_247 = (((t_sample)0.45) * dryLeftSampleRate);
		t_sample minb_249 = (((t_sample)0.45) * dryLeftSampleRate);
		int dryRightSampleRate = samplerate;
		t_sample minb_252 = (((t_sample)0.45) * dryRightSampleRate);
		t_sample minb_254 = (((t_sample)0.45) * dryRightSampleRate);
		t_sample lowBalanceParam = ((lowBalance <= ((int)0)) ? ((int)0) : ((lowBalance >= ((int)1)) ? ((int)1) : lowBalance));
		t_sample lowRmsAlpha = (((int)1) - exp(safediv(((int)-1), (((t_sample)0.08) * samplerate))));
		t_sample midRmsAlpha = (((int)1) - exp(safediv(((int)-1), (((t_sample)0.08) * samplerate))));
		t_sample highRmsAlpha = (((int)1) - exp(safediv(((int)-1), (((t_sample)0.08) * samplerate))));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample trimSharedNext = fixdenorm(((((t_sample)0.999) * m_trimSharedHistory_2) + (((t_sample)0.001) * trimTarget)));
			t_sample trimLeftNext = trimSharedNext;
			t_sample trimRightNext = trimSharedNext;
			t_sample makeupSharedNext = fixdenorm(((((t_sample)0.999) * m_makeupSharedHistory_1) + (((t_sample)0.001) * makeupTarget)));
			t_sample makeupLeftNext = makeupSharedNext;
			t_sample makeupRightNext = makeupSharedNext;
			t_sample wetInL = (in1 * trimLeftNext);
			t_sample wetInR = (in2 * trimRightNext);
			t_sample expr_12419 = wetInL;
			t_sample expr_12420 = wetInR;
			t_sample wetRIn = wetInR;
			t_sample wetRightLowStage1X1Prev = m_wetRightLowStage1X_217;
			t_sample wetRightLowStage1X2Prev = m_wetRightLowStage1X_216;
			t_sample wetRightLowStage1Y1Prev = m_wetRightLowStage1Y_215;
			t_sample wetRightLowStage1Y2Prev = m_wetRightLowStage1Y_214;
			t_sample wetRightLowStage1Sum = (((rightLpB0Low * wetRIn) + (rightLpB1Low * wetRightLowStage1X1Prev)) + (rightLpB2Low * wetRightLowStage1X2Prev));
			t_sample wetRightLowStage1Out = ((wetRightLowStage1Sum - (rightLpA1Low * wetRightLowStage1Y1Prev)) - (rightLpA2Low * wetRightLowStage1Y2Prev));
			m_wetRightLowStage1X_216 = wetRightLowStage1X1Prev;
			m_wetRightLowStage1X_217 = wetRIn;
			m_wetRightLowStage1Y_214 = wetRightLowStage1Y1Prev;
			m_wetRightLowStage1Y_215 = wetRightLowStage1Out;
			t_sample wetRightLowStage2X1Prev = m_wetRightLowStage2X_213;
			t_sample wetRightLowStage2X2Prev = m_wetRightLowStage2X_212;
			t_sample wetRightLowStage2Y1Prev = m_wetRightLowStage2Y_211;
			t_sample wetRightLowStage2Y2Prev = m_wetRightLowStage2Y_210;
			t_sample wetRightLowStage2Sum = (((rightLpB0Low * wetRightLowStage1Out) + (rightLpB1Low * wetRightLowStage2X1Prev)) + (rightLpB2Low * wetRightLowStage2X2Prev));
			t_sample wetRightLowStage2Out = ((wetRightLowStage2Sum - (rightLpA1Low * wetRightLowStage2Y1Prev)) - (rightLpA2Low * wetRightLowStage2Y2Prev));
			m_wetRightLowStage2X_212 = wetRightLowStage2X1Prev;
			m_wetRightLowStage2X_213 = wetRightLowStage1Out;
			m_wetRightLowStage2Y_210 = wetRightLowStage2Y1Prev;
			m_wetRightLowStage2Y_211 = wetRightLowStage2Out;
			t_sample wetRightHighStage1X1Prev = m_wetRightHighStage1X_209;
			t_sample wetRightHighStage1X2Prev = m_wetRightHighStage1X_208;
			t_sample wetRightHighStage1Y1Prev = m_wetRightHighStage1Y_207;
			t_sample wetRightHighStage1Y2Prev = m_wetRightHighStage1Y_206;
			t_sample wetRightHighStage1Sum = (((rightHpB0Low * wetRIn) + (rightHpB1Low * wetRightHighStage1X1Prev)) + (rightHpB2Low * wetRightHighStage1X2Prev));
			t_sample wetRightHighStage1Out = ((wetRightHighStage1Sum - (rightHpA1Low * wetRightHighStage1Y1Prev)) - (rightHpA2Low * wetRightHighStage1Y2Prev));
			m_wetRightHighStage1X_208 = wetRightHighStage1X1Prev;
			m_wetRightHighStage1X_209 = wetRIn;
			m_wetRightHighStage1Y_206 = wetRightHighStage1Y1Prev;
			m_wetRightHighStage1Y_207 = wetRightHighStage1Out;
			t_sample wetRightHighStage2X1Prev = m_wetRightHighStage2X_205;
			t_sample wetRightHighStage2X2Prev = m_wetRightHighStage2X_204;
			t_sample wetRightHighStage2Y1Prev = m_wetRightHighStage2Y_203;
			t_sample wetRightHighStage2Y2Prev = m_wetRightHighStage2Y_202;
			t_sample wetRightHighStage2Sum = (((rightHpB0Low * wetRightHighStage1Out) + (rightHpB1Low * wetRightHighStage2X1Prev)) + (rightHpB2Low * wetRightHighStage2X2Prev));
			t_sample wetRightHighStage2Out = ((wetRightHighStage2Sum - (rightHpA1Low * wetRightHighStage2Y1Prev)) - (rightHpA2Low * wetRightHighStage2Y2Prev));
			m_wetRightHighStage2X_204 = wetRightHighStage2X1Prev;
			m_wetRightHighStage2X_205 = wetRightHighStage1Out;
			m_wetRightHighStage2Y_202 = wetRightHighStage2Y1Prev;
			m_wetRightHighStage2Y_203 = wetRightHighStage2Out;
			t_sample stage1OutR = (wetRightLowStage2Out + wetRightHighStage2Out);
			t_sample wetRightMidStage1X1Prev = m_wetRightMidStage1X_201;
			t_sample wetRightMidStage1X2Prev = m_wetRightMidStage1X_200;
			t_sample wetRightMidStage1Y1Prev = m_wetRightMidStage1Y_199;
			t_sample wetRightMidStage1Y2Prev = m_wetRightMidStage1Y_198;
			t_sample wetRightMidStage1Sum = (((rightLpB0High * stage1OutR) + (rightLpB1High * wetRightMidStage1X1Prev)) + (rightLpB2High * wetRightMidStage1X2Prev));
			t_sample wetRightMidStage1Out = ((wetRightMidStage1Sum - (rightLpA1High * wetRightMidStage1Y1Prev)) - (rightLpA2High * wetRightMidStage1Y2Prev));
			m_wetRightMidStage1X_200 = wetRightMidStage1X1Prev;
			m_wetRightMidStage1X_201 = stage1OutR;
			m_wetRightMidStage1Y_198 = wetRightMidStage1Y1Prev;
			m_wetRightMidStage1Y_199 = wetRightMidStage1Out;
			t_sample wetRightMidStage2X1Prev = m_wetRightMidStage2X_197;
			t_sample wetRightMidStage2X2Prev = m_wetRightMidStage2X_196;
			t_sample wetRightMidStage2Y1Prev = m_wetRightMidStage2Y_195;
			t_sample wetRightMidStage2Y2Prev = m_wetRightMidStage2Y_194;
			t_sample wetRightMidStage2Sum = (((rightLpB0High * wetRightMidStage1Out) + (rightLpB1High * wetRightMidStage2X1Prev)) + (rightLpB2High * wetRightMidStage2X2Prev));
			t_sample wetRightMidStage2Out = ((wetRightMidStage2Sum - (rightLpA1High * wetRightMidStage2Y1Prev)) - (rightLpA2High * wetRightMidStage2Y2Prev));
			m_wetRightMidStage2X_196 = wetRightMidStage2X1Prev;
			m_wetRightMidStage2X_197 = wetRightMidStage1Out;
			m_wetRightMidStage2Y_194 = wetRightMidStage2Y1Prev;
			m_wetRightMidStage2Y_195 = wetRightMidStage2Out;
			t_sample wetRightHighBandStage1X1Prev = m_wetRightHighBandStage1X_193;
			t_sample wetRightHighBandStage1X2Prev = m_wetRightHighBandStage1X_192;
			t_sample wetRightHighBandStage1Y1Prev = m_wetRightHighBandStage1Y_191;
			t_sample wetRightHighBandStage1Y2Prev = m_wetRightHighBandStage1Y_190;
			t_sample wetRightHighBandStage1Sum = (((rightHpB0High * stage1OutR) + (rightHpB1High * wetRightHighBandStage1X1Prev)) + (rightHpB2High * wetRightHighBandStage1X2Prev));
			t_sample wetRightHighBandStage1Out = ((wetRightHighBandStage1Sum - (rightHpA1High * wetRightHighBandStage1Y1Prev)) - (rightHpA2High * wetRightHighBandStage1Y2Prev));
			m_wetRightHighBandStage1X_192 = wetRightHighBandStage1X1Prev;
			m_wetRightHighBandStage1X_193 = stage1OutR;
			m_wetRightHighBandStage1Y_190 = wetRightHighBandStage1Y1Prev;
			m_wetRightHighBandStage1Y_191 = wetRightHighBandStage1Out;
			t_sample wetRightHighBandStage2X1Prev = m_wetRightHighBandStage2X_189;
			t_sample wetRightHighBandStage2X2Prev = m_wetRightHighBandStage2X_188;
			t_sample wetRightHighBandStage2Y1Prev = m_wetRightHighBandStage2Y_187;
			t_sample wetRightHighBandStage2Y2Prev = m_wetRightHighBandStage2Y_186;
			t_sample wetRightHighBandStage2Sum = (((rightHpB0High * wetRightHighBandStage1Out) + (rightHpB1High * wetRightHighBandStage2X1Prev)) + (rightHpB2High * wetRightHighBandStage2X2Prev));
			t_sample wetRightHighBandStage2Out = ((wetRightHighBandStage2Sum - (rightHpA1High * wetRightHighBandStage2Y1Prev)) - (rightHpA2High * wetRightHighBandStage2Y2Prev));
			m_wetRightHighBandStage2X_188 = wetRightHighBandStage2X1Prev;
			m_wetRightHighBandStage2X_189 = wetRightHighBandStage1Out;
			m_wetRightHighBandStage2Y_186 = wetRightHighBandStage2Y1Prev;
			m_wetRightHighBandStage2Y_187 = wetRightHighBandStage2Out;
			t_sample wetLIn = wetInL;
			t_sample wetLeftLowStage1X1Prev = m_wetLeftLowStage1X_38;
			t_sample wetLeftLowStage1X2Prev = m_wetLeftLowStage1X_37;
			t_sample wetLeftLowStage1Y1Prev = m_wetLeftLowStage1Y_36;
			t_sample wetLeftLowStage1Y2Prev = m_wetLeftLowStage1Y_35;
			t_sample wetLeftLowStage1Sum = (((leftLpB0Low * wetLIn) + (leftLpB1Low * wetLeftLowStage1X1Prev)) + (leftLpB2Low * wetLeftLowStage1X2Prev));
			t_sample wetLeftLowStage1Out = ((wetLeftLowStage1Sum - (leftLpA1Low * wetLeftLowStage1Y1Prev)) - (leftLpA2Low * wetLeftLowStage1Y2Prev));
			m_wetLeftLowStage1X_37 = wetLeftLowStage1X1Prev;
			m_wetLeftLowStage1X_38 = wetLIn;
			m_wetLeftLowStage1Y_35 = wetLeftLowStage1Y1Prev;
			m_wetLeftLowStage1Y_36 = wetLeftLowStage1Out;
			t_sample wetLeftLowStage2X1Prev = m_wetLeftLowStage2X_34;
			t_sample wetLeftLowStage2X2Prev = m_wetLeftLowStage2X_33;
			t_sample wetLeftLowStage2Y1Prev = m_wetLeftLowStage2Y_32;
			t_sample wetLeftLowStage2Y2Prev = m_wetLeftLowStage2Y_31;
			t_sample wetLeftLowStage2Sum = (((leftLpB0Low * wetLeftLowStage1Out) + (leftLpB1Low * wetLeftLowStage2X1Prev)) + (leftLpB2Low * wetLeftLowStage2X2Prev));
			t_sample wetLeftLowStage2Out = ((wetLeftLowStage2Sum - (leftLpA1Low * wetLeftLowStage2Y1Prev)) - (leftLpA2Low * wetLeftLowStage2Y2Prev));
			m_wetLeftLowStage2X_33 = wetLeftLowStage2X1Prev;
			m_wetLeftLowStage2X_34 = wetLeftLowStage1Out;
			m_wetLeftLowStage2Y_31 = wetLeftLowStage2Y1Prev;
			m_wetLeftLowStage2Y_32 = wetLeftLowStage2Out;
			t_sample wetLeftHighStage1X1Prev = m_wetLeftHighStage1X_30;
			t_sample wetLeftHighStage1X2Prev = m_wetLeftHighStage1X_29;
			t_sample wetLeftHighStage1Y1Prev = m_wetLeftHighStage1Y_28;
			t_sample wetLeftHighStage1Y2Prev = m_wetLeftHighStage1Y_27;
			t_sample wetLeftHighStage1Sum = (((leftHpB0Low * wetLIn) + (leftHpB1Low * wetLeftHighStage1X1Prev)) + (leftHpB2Low * wetLeftHighStage1X2Prev));
			t_sample wetLeftHighStage1Out = ((wetLeftHighStage1Sum - (leftHpA1Low * wetLeftHighStage1Y1Prev)) - (leftHpA2Low * wetLeftHighStage1Y2Prev));
			m_wetLeftHighStage1X_29 = wetLeftHighStage1X1Prev;
			m_wetLeftHighStage1X_30 = wetLIn;
			m_wetLeftHighStage1Y_27 = wetLeftHighStage1Y1Prev;
			m_wetLeftHighStage1Y_28 = wetLeftHighStage1Out;
			t_sample wetLeftHighStage2X1Prev = m_wetLeftHighStage2X_26;
			t_sample wetLeftHighStage2X2Prev = m_wetLeftHighStage2X_25;
			t_sample wetLeftHighStage2Y1Prev = m_wetLeftHighStage2Y_24;
			t_sample wetLeftHighStage2Y2Prev = m_wetLeftHighStage2Y_23;
			t_sample wetLeftHighStage2Sum = (((leftHpB0Low * wetLeftHighStage1Out) + (leftHpB1Low * wetLeftHighStage2X1Prev)) + (leftHpB2Low * wetLeftHighStage2X2Prev));
			t_sample wetLeftHighStage2Out = ((wetLeftHighStage2Sum - (leftHpA1Low * wetLeftHighStage2Y1Prev)) - (leftHpA2Low * wetLeftHighStage2Y2Prev));
			m_wetLeftHighStage2X_25 = wetLeftHighStage2X1Prev;
			m_wetLeftHighStage2X_26 = wetLeftHighStage1Out;
			m_wetLeftHighStage2Y_23 = wetLeftHighStage2Y1Prev;
			m_wetLeftHighStage2Y_24 = wetLeftHighStage2Out;
			t_sample stage1OutL = (wetLeftLowStage2Out + wetLeftHighStage2Out);
			t_sample wetLeftMidStage1X1Prev = m_wetLeftMidStage1X_22;
			t_sample wetLeftMidStage1X2Prev = m_wetLeftMidStage1X_21;
			t_sample wetLeftMidStage1Y1Prev = m_wetLeftMidStage1Y_20;
			t_sample wetLeftMidStage1Y2Prev = m_wetLeftMidStage1Y_19;
			t_sample wetLeftMidStage1Sum = (((leftLpB0High * stage1OutL) + (leftLpB1High * wetLeftMidStage1X1Prev)) + (leftLpB2High * wetLeftMidStage1X2Prev));
			t_sample wetLeftMidStage1Out = ((wetLeftMidStage1Sum - (leftLpA1High * wetLeftMidStage1Y1Prev)) - (leftLpA2High * wetLeftMidStage1Y2Prev));
			m_wetLeftMidStage1X_21 = wetLeftMidStage1X1Prev;
			m_wetLeftMidStage1X_22 = stage1OutL;
			m_wetLeftMidStage1Y_19 = wetLeftMidStage1Y1Prev;
			m_wetLeftMidStage1Y_20 = wetLeftMidStage1Out;
			t_sample wetLeftMidStage2X1Prev = m_wetLeftMidStage2X_18;
			t_sample wetLeftMidStage2X2Prev = m_wetLeftMidStage2X_17;
			t_sample wetLeftMidStage2Y1Prev = m_wetLeftMidStage2Y_16;
			t_sample wetLeftMidStage2Y2Prev = m_wetLeftMidStage2Y_15;
			t_sample wetLeftMidStage2Sum = (((leftLpB0High * wetLeftMidStage1Out) + (leftLpB1High * wetLeftMidStage2X1Prev)) + (leftLpB2High * wetLeftMidStage2X2Prev));
			t_sample wetLeftMidStage2Out = ((wetLeftMidStage2Sum - (leftLpA1High * wetLeftMidStage2Y1Prev)) - (leftLpA2High * wetLeftMidStage2Y2Prev));
			m_wetLeftMidStage2X_17 = wetLeftMidStage2X1Prev;
			m_wetLeftMidStage2X_18 = wetLeftMidStage1Out;
			m_wetLeftMidStage2Y_15 = wetLeftMidStage2Y1Prev;
			m_wetLeftMidStage2Y_16 = wetLeftMidStage2Out;
			t_sample wetLeftHighBandStage1X1Prev = m_wetLeftHighBandStage1X_14;
			t_sample wetLeftHighBandStage1X2Prev = m_wetLeftHighBandStage1X_13;
			t_sample wetLeftHighBandStage1Y1Prev = m_wetLeftHighBandStage1Y_12;
			t_sample wetLeftHighBandStage1Y2Prev = m_wetLeftHighBandStage1Y_11;
			t_sample wetLeftHighBandStage1Sum = (((leftHpB0High * stage1OutL) + (leftHpB1High * wetLeftHighBandStage1X1Prev)) + (leftHpB2High * wetLeftHighBandStage1X2Prev));
			t_sample wetLeftHighBandStage1Out = ((wetLeftHighBandStage1Sum - (leftHpA1High * wetLeftHighBandStage1Y1Prev)) - (leftHpA2High * wetLeftHighBandStage1Y2Prev));
			m_wetLeftHighBandStage1X_13 = wetLeftHighBandStage1X1Prev;
			m_wetLeftHighBandStage1X_14 = stage1OutL;
			m_wetLeftHighBandStage1Y_11 = wetLeftHighBandStage1Y1Prev;
			m_wetLeftHighBandStage1Y_12 = wetLeftHighBandStage1Out;
			t_sample wetLeftHighBandStage2X1Prev = m_wetLeftHighBandStage2X_10;
			t_sample wetLeftHighBandStage2X2Prev = m_wetLeftHighBandStage2X_9;
			t_sample wetLeftHighBandStage2Y1Prev = m_wetLeftHighBandStage2Y_8;
			t_sample wetLeftHighBandStage2Y2Prev = m_wetLeftHighBandStage2Y_7;
			t_sample wetLeftHighBandStage2Sum = (((leftHpB0High * wetLeftHighBandStage1Out) + (leftHpB1High * wetLeftHighBandStage2X1Prev)) + (leftHpB2High * wetLeftHighBandStage2X2Prev));
			t_sample wetLeftHighBandStage2Out = ((wetLeftHighBandStage2Sum - (leftHpA1High * wetLeftHighBandStage2Y1Prev)) - (leftHpA2High * wetLeftHighBandStage2Y2Prev));
			m_wetLeftHighBandStage2X_9 = wetLeftHighBandStage2X1Prev;
			m_wetLeftHighBandStage2X_10 = wetLeftHighBandStage1Out;
			m_wetLeftHighBandStage2Y_7 = wetLeftHighBandStage2Y1Prev;
			m_wetLeftHighBandStage2Y_8 = wetLeftHighBandStage2Out;
			t_sample mix_12487 = (dryWet + (((t_sample)0.999) * (m_dryWetHistory_185 - dryWet)));
			t_sample dryWetSmoothed = mix_12487;
			t_sample dryWetControl = dryWetSmoothed;
			t_sample dryWetHistoryNext = fixdenorm(dryWetSmoothed);
			t_sample mix_12488 = (bypass + (((t_sample)0.999) * (m_bypassHistory_184 - bypass)));
			t_sample bypassSmoothed = mix_12488;
			t_sample bypassHistoryNext = fixdenorm(bypassSmoothed);
			t_sample bypassMask = (((int)1) - bypassSmoothed);
			t_sample mix_12489 = (soloMid + (((t_sample)0.999) * (m_soloMidHistory_183 - soloMid)));
			t_sample soloMidSmoothed = mix_12489;
			t_sample soloMidHistoryNext = fixdenorm(soloMidSmoothed);
			t_sample mix_12490 = (soloHigh + (((t_sample)0.999) * (m_soloHighHistory_182 - soloHigh)));
			t_sample soloHighSmoothed = mix_12490;
			t_sample soloHighHistoryNext = fixdenorm(soloHighSmoothed);
			t_sample mix_12491 = (soloLow + (((t_sample)0.999) * (m_soloLowHistory_181 - soloLow)));
			t_sample soloLowSmoothed = mix_12491;
			t_sample soloLowSm = soloLowSmoothed;
			t_sample soloMaskLow = (soloHighSmoothed + soloMidSmoothed);
			t_sample soloMaskMid = (soloHighSmoothed + soloLowSm);
			t_sample soloMaskHigh = (soloMidSmoothed + soloLowSm);
			t_sample soloLowHistoryNext = fixdenorm(soloLowSmoothed);
			t_sample mix_12492 = (inputMode + (((t_sample)0.999) * (m_inputModeHistory_180 - inputMode)));
			t_sample inputModeSmoothed = mix_12492;
			t_sample inputModeHistoryNext = fixdenorm(inputModeSmoothed);
			t_sample mix_12493 = (bandLowGain + (((t_sample)0.999) * (m_lowBandGainHistory_179 - bandLowGain)));
			t_sample lowBandGainSmoothed = mix_12493;
			t_sample lowBandGainHistoryNext = fixdenorm(lowBandGainSmoothed);
			t_sample mix_12494 = (bandMidGain + (((t_sample)0.999) * (m_midBandGainHistory_178 - bandMidGain)));
			t_sample midBandGainSmoothed = mix_12494;
			t_sample midBandGainHistoryNext = fixdenorm(midBandGainSmoothed);
			t_sample mix_12495 = (midBalance + (((t_sample)0.999) * (m_midBalanceHistory_177 - midBalance)));
			t_sample midBalanceSmoothed = mix_12495;
			t_sample midBalanceHistoryNext = fixdenorm(midBalanceSmoothed);
			t_sample mix_12496 = (bandHighGain + (((t_sample)0.999) * (m_highBandGainHistory_176 - bandHighGain)));
			t_sample highBandGainSmoothed = mix_12496;
			t_sample highBandGainHistoryNext = fixdenorm(highBandGainSmoothed);
			t_sample mix_12497 = (highBalance + (((t_sample)0.999) * (m_highBalanceHistory_175 - highBalance)));
			t_sample highBalanceSmoothed = mix_12497;
			t_sample highBalanceHistoryNext = fixdenorm(highBalanceSmoothed);
			t_sample mix_12498 = (freqHighHz + (((t_sample)0.999) * (m_highCrossoverHistory_174 - freqHighHz)));
			t_sample highCrossoverSmoothed = mix_12498;
			t_sample highCrossoverHistoryNext = fixdenorm(highCrossoverSmoothed);
			t_sample setparamHighCrossover = highCrossoverSmoothed;
			t_sample mix_12499 = (freqLowHz + (((t_sample)0.999) * (m_lowCrossoverHistory_173 - freqLowHz)));
			t_sample lowCrossoverSmoothed = mix_12499;
			t_sample lowCrossoverHistoryNext = fixdenorm(lowCrossoverSmoothed);
			t_sample setparamLowCrossover = lowCrossoverSmoothed;
			t_sample leftLowTargetHz = ((setparamLowCrossover <= ((int)20)) ? ((int)20) : ((setparamLowCrossover >= ((int)1000)) ? ((int)1000) : setparamLowCrossover));
			t_sample leftHighTargetHz = ((setparamHighCrossover <= ((int)1000)) ? ((int)1000) : ((setparamHighCrossover >= ((int)20000)) ? ((int)20000) : setparamHighCrossover));
			t_sample dryLeftInput = wetInL;
			t_sample maxb_248 = ((minb_247 < leftLowTargetHz) ? minb_247 : leftLowTargetHz);
			t_sample leftLowHz_12355 = ((((int)10) < maxb_248) ? maxb_248 : ((int)10));
			t_sample maxb_250 = ((minb_249 < leftHighTargetHz) ? minb_249 : leftHighTargetHz);
			t_sample leftHighPreHz_12356 = ((((int)10) < maxb_250) ? maxb_250 : ((int)10));
			t_sample maxb_251 = (leftLowHz_12355 + ((int)1));
			t_sample leftHighHz_12357 = ((leftHighPreHz_12356 < maxb_251) ? maxb_251 : leftHighPreHz_12356);
			t_sample leftDryW0Low = safediv((((t_sample)6.2831853071796) * leftLowHz_12355), dryLeftSampleRate);
			t_sample leftDryCosLow = cos(leftDryW0Low);
			t_sample leftDrySinLow = sin(leftDryW0Low);
			t_sample leftDryAlphaLow = (leftDrySinLow * ((t_sample)0.70710678118655));
			t_sample leftDryA0Low = (((int)1) + leftDryAlphaLow);
			t_sample leftDryA1Low = (((int)-2) * leftDryCosLow);
			t_sample leftDryA2Low = (((int)1) - leftDryAlphaLow);
			t_sample leftDryLpB0Low = safediv(((((int)1) - leftDryCosLow) * ((t_sample)0.5)), leftDryA0Low);
			t_sample leftDryLpB1Low = safediv((((int)1) - leftDryCosLow), leftDryA0Low);
			t_sample leftDryLpB2Low = leftDryLpB0Low;
			t_sample leftDryLpA1Low = safediv(leftDryA1Low, leftDryA0Low);
			t_sample leftDryLpA2Low = safediv(leftDryA2Low, leftDryA0Low);
			t_sample leftDryHpB0Low = safediv(((((int)1) + leftDryCosLow) * ((t_sample)0.5)), leftDryA0Low);
			t_sample leftDryHpB1Low = safediv((-(((int)1) + leftDryCosLow)), leftDryA0Low);
			t_sample leftDryHpB2Low = leftDryHpB0Low;
			t_sample leftDryHpA1Low = leftDryLpA1Low;
			t_sample leftDryHpA2Low = leftDryLpA2Low;
			t_sample leftDryW0High = safediv((((t_sample)6.2831853071796) * leftHighHz_12357), dryLeftSampleRate);
			t_sample leftDryCosHigh = cos(leftDryW0High);
			t_sample leftDrySinHigh = sin(leftDryW0High);
			t_sample leftDryAlphaHigh = (leftDrySinHigh * ((t_sample)0.70710678118655));
			t_sample leftDryA0High = (((int)1) + leftDryAlphaHigh);
			t_sample leftDryA1High = (((int)-2) * leftDryCosHigh);
			t_sample leftDryA2High = (((int)1) - leftDryAlphaHigh);
			t_sample leftDryLpB0High = safediv(((((int)1) - leftDryCosHigh) * ((t_sample)0.5)), leftDryA0High);
			t_sample leftDryLpB1High = safediv((((int)1) - leftDryCosHigh), leftDryA0High);
			t_sample leftDryLpB2High = leftDryLpB0High;
			t_sample leftDryLpA1High = safediv(leftDryA1High, leftDryA0High);
			t_sample leftDryLpA2High = safediv(leftDryA2High, leftDryA0High);
			t_sample leftDryHpB0High = safediv(((((int)1) + leftDryCosHigh) * ((t_sample)0.5)), leftDryA0High);
			t_sample leftDryHpB1High = safediv((-(((int)1) + leftDryCosHigh)), leftDryA0High);
			t_sample leftDryHpB2High = leftDryHpB0High;
			t_sample leftDryHpA1High = leftDryLpA1High;
			t_sample leftDryHpA2High = leftDryLpA2High;
			t_sample dryLeftLowStage1X1Prev = fixdenorm(m_dryLeftLowLpStage1X_172);
			t_sample dryLeftLowStage1X2Prev = fixdenorm(m_dryLeftLowLpStage1X_171);
			t_sample dryLeftLowStage1Y1Prev = fixdenorm(m_dryLeftLowLpStage1Y_170);
			t_sample dryLeftLowStage1Y2Prev = fixdenorm(m_dryLeftLowLpStage1Y_169);
			t_sample dryLeftLowStage1Sum = (((leftDryLpB0Low * dryLeftInput) + (leftDryLpB1Low * dryLeftLowStage1X1Prev)) + (leftDryLpB2Low * dryLeftLowStage1X2Prev));
			t_sample dryLeftLowStage1Out = ((dryLeftLowStage1Sum - (leftDryLpA1Low * dryLeftLowStage1Y1Prev)) - (leftDryLpA2Low * dryLeftLowStage1Y2Prev));
			m_dryLeftLowLpStage1X_171 = dryLeftLowStage1X1Prev;
			m_dryLeftLowLpStage1X_172 = dryLeftInput;
			m_dryLeftLowLpStage1Y_169 = dryLeftLowStage1Y1Prev;
			m_dryLeftLowLpStage1Y_170 = dryLeftLowStage1Out;
			t_sample dryLeftLowStage2X1Prev = fixdenorm(m_dryLeftLowLpStage2X_168);
			t_sample dryLeftLowStage2X2Prev = fixdenorm(m_dryLeftLowLpStage2X_167);
			t_sample dryLeftLowStage2Y1Prev = fixdenorm(m_dryLeftLowLpStage2Y_166);
			t_sample dryLeftLowStage2Y2Prev = fixdenorm(m_dryLeftLowLpStage2Y_165);
			t_sample dryLeftLowStage2Sum = (((leftDryLpB0Low * dryLeftLowStage1Out) + (leftDryLpB1Low * dryLeftLowStage2X1Prev)) + (leftDryLpB2Low * dryLeftLowStage2X2Prev));
			t_sample dryLeftLowStage2Out = ((dryLeftLowStage2Sum - (leftDryLpA1Low * dryLeftLowStage2Y1Prev)) - (leftDryLpA2Low * dryLeftLowStage2Y2Prev));
			m_dryLeftLowLpStage2X_167 = dryLeftLowStage2X1Prev;
			m_dryLeftLowLpStage2X_168 = dryLeftLowStage1Out;
			m_dryLeftLowLpStage2Y_165 = dryLeftLowStage2Y1Prev;
			m_dryLeftLowLpStage2Y_166 = dryLeftLowStage2Out;
			t_sample dryLeftHighStage1X1Prev = fixdenorm(m_dryLeftLowHpStage1X_164);
			t_sample dryLeftHighStage1X2Prev = fixdenorm(m_dryLeftLowHpStage1X_163);
			t_sample dryLeftHighStage1Y1Prev = fixdenorm(m_dryLeftLowHpStage1Y_162);
			t_sample dryLeftHighStage1Y2Prev = fixdenorm(m_dryLeftLowHpStage1Y_161);
			t_sample dryLeftHighStage1Sum = (((leftDryHpB0Low * dryLeftInput) + (leftDryHpB1Low * dryLeftHighStage1X1Prev)) + (leftDryHpB2Low * dryLeftHighStage1X2Prev));
			t_sample dryLeftHighStage1Out = ((dryLeftHighStage1Sum - (leftDryHpA1Low * dryLeftHighStage1Y1Prev)) - (leftDryHpA2Low * dryLeftHighStage1Y2Prev));
			m_dryLeftLowHpStage1X_163 = dryLeftHighStage1X1Prev;
			m_dryLeftLowHpStage1X_164 = dryLeftInput;
			m_dryLeftLowHpStage1Y_161 = dryLeftHighStage1Y1Prev;
			m_dryLeftLowHpStage1Y_162 = dryLeftHighStage1Out;
			t_sample dryLeftHighStage2X1Prev = fixdenorm(m_dryLeftLowHpStage2X_160);
			t_sample dryLeftHighStage2X2Prev = fixdenorm(m_dryLeftLowHpStage2X_159);
			t_sample dryLeftHighStage2Y1Prev = fixdenorm(m_dryLeftLowHpStage2Y_158);
			t_sample dryLeftHighStage2Y2Prev = fixdenorm(m_dryLeftLowHpStage2Y_157);
			t_sample dryLeftHighStage2Sum = (((leftDryHpB0Low * dryLeftHighStage1Out) + (leftDryHpB1Low * dryLeftHighStage2X1Prev)) + (leftDryHpB2Low * dryLeftHighStage2X2Prev));
			t_sample dryLeftHighStage2Out = ((dryLeftHighStage2Sum - (leftDryHpA1Low * dryLeftHighStage2Y1Prev)) - (leftDryHpA2Low * dryLeftHighStage2Y2Prev));
			m_dryLeftLowHpStage2X_159 = dryLeftHighStage2X1Prev;
			m_dryLeftLowHpStage2X_160 = dryLeftHighStage1Out;
			m_dryLeftLowHpStage2Y_157 = dryLeftHighStage2Y1Prev;
			m_dryLeftLowHpStage2Y_158 = dryLeftHighStage2Out;
			t_sample dryLeftApLowLpStage1X1Prev = fixdenorm(m_apLeftLowLpStage1X_140);
			t_sample dryLeftApLowLpStage1X2Prev = fixdenorm(m_apLeftLowLpStage1X_139);
			t_sample dryLeftApLowLpStage1Y1Prev = fixdenorm(m_apLeftLowLpStage1Y_138);
			t_sample dryLeftApLowLpStage1Y2Prev = fixdenorm(m_apLeftLowLpStage1Y_137);
			t_sample dryLeftApLowLpStage1Sum = (((leftDryLpB0High * dryLeftLowStage2Out) + (leftDryLpB1High * dryLeftApLowLpStage1X1Prev)) + (leftDryLpB2High * dryLeftApLowLpStage1X2Prev));
			t_sample dryLeftApLowLpStage1Out = ((dryLeftApLowLpStage1Sum - (leftDryLpA1High * dryLeftApLowLpStage1Y1Prev)) - (leftDryLpA2High * dryLeftApLowLpStage1Y2Prev));
			m_apLeftLowLpStage1X_139 = dryLeftApLowLpStage1X1Prev;
			m_apLeftLowLpStage1X_140 = dryLeftLowStage2Out;
			m_apLeftLowLpStage1Y_137 = dryLeftApLowLpStage1Y1Prev;
			m_apLeftLowLpStage1Y_138 = dryLeftApLowLpStage1Out;
			t_sample dryLeftApLowLpStage2X1Prev = fixdenorm(m_apLeftLowLpStage2X_136);
			t_sample dryLeftApLowLpStage2X2Prev = fixdenorm(m_apLeftLowLpStage2X_135);
			t_sample dryLeftApLowLpStage2Y1Prev = fixdenorm(m_apLeftLowLpStage2Y_134);
			t_sample dryLeftApLowLpStage2Y2Prev = fixdenorm(m_apLeftLowLpStage2Y_133);
			t_sample dryLeftApLowLpStage2Sum = (((leftDryLpB0High * dryLeftApLowLpStage1Out) + (leftDryLpB1High * dryLeftApLowLpStage2X1Prev)) + (leftDryLpB2High * dryLeftApLowLpStage2X2Prev));
			t_sample dryLeftApLowLpStage2Out = ((dryLeftApLowLpStage2Sum - (leftDryLpA1High * dryLeftApLowLpStage2Y1Prev)) - (leftDryLpA2High * dryLeftApLowLpStage2Y2Prev));
			m_apLeftLowLpStage2X_135 = dryLeftApLowLpStage2X1Prev;
			m_apLeftLowLpStage2X_136 = dryLeftApLowLpStage1Out;
			m_apLeftLowLpStage2Y_133 = dryLeftApLowLpStage2Y1Prev;
			m_apLeftLowLpStage2Y_134 = dryLeftApLowLpStage2Out;
			t_sample dryLeftApLowHpStage1X1Prev = fixdenorm(m_apLeftLowHpStage1X_132);
			t_sample dryLeftApLowHpStage1X2Prev = fixdenorm(m_apLeftLowHpStage1X_131);
			t_sample dryLeftApLowHpStage1Y1Prev = fixdenorm(m_apLeftLowHpStage1Y_130);
			t_sample dryLeftApLowHpStage1Y2Prev = fixdenorm(m_apLeftLowHpStage1Y_129);
			t_sample dryLeftApLowHpStage1Sum = (((leftDryHpB0High * dryLeftLowStage2Out) + (leftDryHpB1High * dryLeftApLowHpStage1X1Prev)) + (leftDryHpB2High * dryLeftApLowHpStage1X2Prev));
			t_sample dryLeftApLowHpStage1Out = ((dryLeftApLowHpStage1Sum - (leftDryHpA1High * dryLeftApLowHpStage1Y1Prev)) - (leftDryHpA2High * dryLeftApLowHpStage1Y2Prev));
			m_apLeftLowHpStage1X_131 = dryLeftApLowHpStage1X1Prev;
			m_apLeftLowHpStage1X_132 = dryLeftLowStage2Out;
			m_apLeftLowHpStage1Y_129 = dryLeftApLowHpStage1Y1Prev;
			m_apLeftLowHpStage1Y_130 = dryLeftApLowHpStage1Out;
			t_sample dryLeftApLowHpStage2X1Prev = fixdenorm(m_apLeftLowHpStage2X_128);
			t_sample dryLeftApLowHpStage2X2Prev = fixdenorm(m_apLeftLowHpStage2X_127);
			t_sample dryLeftApLowHpStage2Y1Prev = fixdenorm(m_apLeftLowHpStage2Y_126);
			t_sample dryLeftApLowHpStage2Y2Prev = fixdenorm(m_apLeftLowHpStage2Y_125);
			t_sample dryLeftApLowHpStage2Sum = (((leftDryHpB0High * dryLeftApLowHpStage1Out) + (leftDryHpB1High * dryLeftApLowHpStage2X1Prev)) + (leftDryHpB2High * dryLeftApLowHpStage2X2Prev));
			t_sample dryLeftApLowHpStage2Out = ((dryLeftApLowHpStage2Sum - (leftDryHpA1High * dryLeftApLowHpStage2Y1Prev)) - (leftDryHpA2High * dryLeftApLowHpStage2Y2Prev));
			m_apLeftLowHpStage2X_127 = dryLeftApLowHpStage2X1Prev;
			m_apLeftLowHpStage2X_128 = dryLeftApLowHpStage1Out;
			m_apLeftLowHpStage2Y_125 = dryLeftApLowHpStage2Y1Prev;
			m_apLeftLowHpStage2Y_126 = dryLeftApLowHpStage2Out;
			t_sample dryLeftLowBand = (dryLeftApLowLpStage2Out + dryLeftApLowHpStage2Out);
			t_sample dryLeftMidStage1X1Prev = fixdenorm(m_dryLeftMidLpStage1X_156);
			t_sample dryLeftMidStage1X2Prev = fixdenorm(m_dryLeftMidLpStage1X_155);
			t_sample dryLeftMidStage1Y1Prev = fixdenorm(m_dryLeftMidLpStage1Y_154);
			t_sample dryLeftMidStage1Y2Prev = fixdenorm(m_dryLeftMidLpStage1Y_153);
			t_sample dryLeftMidStage1Sum = (((leftDryLpB0High * dryLeftHighStage2Out) + (leftDryLpB1High * dryLeftMidStage1X1Prev)) + (leftDryLpB2High * dryLeftMidStage1X2Prev));
			t_sample dryLeftMidStage1Out = ((dryLeftMidStage1Sum - (leftDryLpA1High * dryLeftMidStage1Y1Prev)) - (leftDryLpA2High * dryLeftMidStage1Y2Prev));
			m_dryLeftMidLpStage1X_155 = dryLeftMidStage1X1Prev;
			m_dryLeftMidLpStage1X_156 = dryLeftHighStage2Out;
			m_dryLeftMidLpStage1Y_153 = dryLeftMidStage1Y1Prev;
			m_dryLeftMidLpStage1Y_154 = dryLeftMidStage1Out;
			t_sample dryLeftMidStage2X1Prev = fixdenorm(m_dryLeftMidLpStage2X_152);
			t_sample dryLeftMidStage2X2Prev = fixdenorm(m_dryLeftMidLpStage2X_151);
			t_sample dryLeftMidStage2Y1Prev = fixdenorm(m_dryLeftMidLpStage2Y_150);
			t_sample dryLeftMidStage2Y2Prev = fixdenorm(m_dryLeftMidLpStage2Y_149);
			t_sample dryLeftMidStage2Sum = (((leftDryLpB0High * dryLeftMidStage1Out) + (leftDryLpB1High * dryLeftMidStage2X1Prev)) + (leftDryLpB2High * dryLeftMidStage2X2Prev));
			t_sample dryLeftMidStage2Out = ((dryLeftMidStage2Sum - (leftDryLpA1High * dryLeftMidStage2Y1Prev)) - (leftDryLpA2High * dryLeftMidStage2Y2Prev));
			m_dryLeftMidLpStage2X_151 = dryLeftMidStage2X1Prev;
			m_dryLeftMidLpStage2X_152 = dryLeftMidStage1Out;
			m_dryLeftMidLpStage2Y_149 = dryLeftMidStage2Y1Prev;
			m_dryLeftMidLpStage2Y_150 = dryLeftMidStage2Out;
			t_sample dryLeftMidBand = dryLeftMidStage2Out;
			t_sample dryLeftHighBandStage1X1Prev = fixdenorm(m_dryLeftHighHpStage1X_148);
			t_sample dryLeftHighBandStage1X2Prev = fixdenorm(m_dryLeftHighHpStage1X_147);
			t_sample dryLeftHighBandStage1Y1Prev = fixdenorm(m_dryLeftHighHpStage1Y_146);
			t_sample dryLeftHighBandStage1Y2Prev = fixdenorm(m_dryLeftHighHpStage1Y_145);
			t_sample dryLeftHighBandStage1Sum = (((leftDryHpB0High * dryLeftHighStage2Out) + (leftDryHpB1High * dryLeftHighBandStage1X1Prev)) + (leftDryHpB2High * dryLeftHighBandStage1X2Prev));
			t_sample dryLeftHighBandStage1Out = ((dryLeftHighBandStage1Sum - (leftDryHpA1High * dryLeftHighBandStage1Y1Prev)) - (leftDryHpA2High * dryLeftHighBandStage1Y2Prev));
			m_dryLeftHighHpStage1X_147 = dryLeftHighBandStage1X1Prev;
			m_dryLeftHighHpStage1X_148 = dryLeftHighStage2Out;
			m_dryLeftHighHpStage1Y_145 = dryLeftHighBandStage1Y1Prev;
			m_dryLeftHighHpStage1Y_146 = dryLeftHighBandStage1Out;
			t_sample dryLeftHighBandStage2X1Prev = fixdenorm(m_dryLeftHighHpStage2X_144);
			t_sample dryLeftHighBandStage2X2Prev = fixdenorm(m_dryLeftHighHpStage2X_143);
			t_sample dryLeftHighBandStage2Y1Prev = fixdenorm(m_dryLeftHighHpStage2Y_142);
			t_sample dryLeftHighBandStage2Y2Prev = fixdenorm(m_dryLeftHighHpStage2Y_141);
			t_sample dryLeftHighBandStage2Sum = (((leftDryHpB0High * dryLeftHighBandStage1Out) + (leftDryHpB1High * dryLeftHighBandStage2X1Prev)) + (leftDryHpB2High * dryLeftHighBandStage2X2Prev));
			t_sample dryLeftHighBandStage2Out = ((dryLeftHighBandStage2Sum - (leftDryHpA1High * dryLeftHighBandStage2Y1Prev)) - (leftDryHpA2High * dryLeftHighBandStage2Y2Prev));
			m_dryLeftHighHpStage2X_143 = dryLeftHighBandStage2X1Prev;
			m_dryLeftHighHpStage2X_144 = dryLeftHighBandStage1Out;
			m_dryLeftHighHpStage2Y_141 = dryLeftHighBandStage2Y1Prev;
			m_dryLeftHighHpStage2Y_142 = dryLeftHighBandStage2Out;
			t_sample dryLeftHighBand = dryLeftHighBandStage2Out;
			t_sample dryLeftSumBands = ((dryLeftLowBand + dryLeftMidBand) + dryLeftHighBand);
			t_sample lowLIn = dryLeftLowBand;
			t_sample midLIn = dryLeftMidBand;
			t_sample highLIn = dryLeftHighBand;
			t_sample rightLowTargetHz = ((setparamLowCrossover <= ((int)20)) ? ((int)20) : ((setparamLowCrossover >= ((int)1000)) ? ((int)1000) : setparamLowCrossover));
			t_sample rightHighTargetHz = ((setparamHighCrossover <= ((int)1000)) ? ((int)1000) : ((setparamHighCrossover >= ((int)20000)) ? ((int)20000) : setparamHighCrossover));
			t_sample dryRightInput = wetInR;
			t_sample maxb_253 = ((minb_252 < rightLowTargetHz) ? minb_252 : rightLowTargetHz);
			t_sample rightLowHz_12359 = ((((int)10) < maxb_253) ? maxb_253 : ((int)10));
			t_sample maxb_255 = ((minb_254 < rightHighTargetHz) ? minb_254 : rightHighTargetHz);
			t_sample rightHighPreHz_12360 = ((((int)10) < maxb_255) ? maxb_255 : ((int)10));
			t_sample maxb_256 = (rightLowHz_12359 + ((int)1));
			t_sample rightHighHz_12361 = ((rightHighPreHz_12360 < maxb_256) ? maxb_256 : rightHighPreHz_12360);
			t_sample rightW0Low_12362 = safediv((((t_sample)6.2831853071796) * rightLowHz_12359), dryRightSampleRate);
			t_sample rightCosLow_12363 = cos(rightW0Low_12362);
			t_sample rightSinLow_12364 = sin(rightW0Low_12362);
			t_sample rightAlphaLow_12365 = (rightSinLow_12364 * ((t_sample)0.70710678118655));
			t_sample rightA0Low_12366 = (((int)1) + rightAlphaLow_12365);
			t_sample rightA1Low_12367 = (((int)-2) * rightCosLow_12363);
			t_sample rightA2Low_12368 = (((int)1) - rightAlphaLow_12365);
			t_sample rightLpB0Low_12369 = safediv(((((int)1) - rightCosLow_12363) * ((t_sample)0.5)), rightA0Low_12366);
			t_sample rightLpB1Low_12370 = safediv((((int)1) - rightCosLow_12363), rightA0Low_12366);
			t_sample rightLpB2Low_12371 = rightLpB0Low_12369;
			t_sample rightLpA1Low_12372 = safediv(rightA1Low_12367, rightA0Low_12366);
			t_sample rightLpA2Low_12373 = safediv(rightA2Low_12368, rightA0Low_12366);
			t_sample rightHpB0Low_12374 = safediv(((((int)1) + rightCosLow_12363) * ((t_sample)0.5)), rightA0Low_12366);
			t_sample rightHpB1Low_12375 = safediv((-(((int)1) + rightCosLow_12363)), rightA0Low_12366);
			t_sample rightHpB2Low_12376 = rightHpB0Low_12374;
			t_sample rightHpA1Low_12377 = rightLpA1Low_12372;
			t_sample rightHpA2Low_12378 = rightLpA2Low_12373;
			t_sample rightW0High_12379 = safediv((((t_sample)6.2831853071796) * rightHighHz_12361), dryRightSampleRate);
			t_sample rightCosHigh_12380 = cos(rightW0High_12379);
			t_sample rightSinHigh_12381 = sin(rightW0High_12379);
			t_sample rightAlphaHigh_12382 = (rightSinHigh_12381 * ((t_sample)0.70710678118655));
			t_sample rightA0High_12383 = (((int)1) + rightAlphaHigh_12382);
			t_sample rightA1High_12384 = (((int)-2) * rightCosHigh_12380);
			t_sample rightA2High_12385 = (((int)1) - rightAlphaHigh_12382);
			t_sample rightLpB0High_12386 = safediv(((((int)1) - rightCosHigh_12380) * ((t_sample)0.5)), rightA0High_12383);
			t_sample rightLpB1High_12387 = safediv((((int)1) - rightCosHigh_12380), rightA0High_12383);
			t_sample rightLpB2High_12388 = rightLpB0High_12386;
			t_sample rightLpA1High_12389 = safediv(rightA1High_12384, rightA0High_12383);
			t_sample rightLpA2High_12390 = safediv(rightA2High_12385, rightA0High_12383);
			t_sample rightHpB0High_12391 = safediv(((((int)1) + rightCosHigh_12380) * ((t_sample)0.5)), rightA0High_12383);
			t_sample rightHpB1High_12392 = safediv((-(((int)1) + rightCosHigh_12380)), rightA0High_12383);
			t_sample rightHpB2High_12393 = rightHpB0High_12391;
			t_sample rightHpA1High_12394 = rightLpA1High_12389;
			t_sample rightHpA2High_12395 = rightLpA2High_12390;
			t_sample rightLowStage1X1Prev = fixdenorm(m_dryRightLowLpStage1X_124);
			t_sample rightLowStage1X2Prev = fixdenorm(m_dryRightLowLpStage1X_123);
			t_sample rightLowStage1Y1Prev = fixdenorm(m_dryRightLowLpStage1Y_122);
			t_sample rightLowStage1Y2Prev = fixdenorm(m_dryRightLowLpStage1Y_121);
			t_sample rightLowStage1Sum = (((rightLpB0Low_12369 * dryRightInput) + (rightLpB1Low_12370 * rightLowStage1X1Prev)) + (rightLpB2Low_12371 * rightLowStage1X2Prev));
			t_sample rightLowStage1Out = ((rightLowStage1Sum - (rightLpA1Low_12372 * rightLowStage1Y1Prev)) - (rightLpA2Low_12373 * rightLowStage1Y2Prev));
			m_dryRightLowLpStage1X_123 = rightLowStage1X1Prev;
			m_dryRightLowLpStage1X_124 = dryRightInput;
			m_dryRightLowLpStage1Y_121 = rightLowStage1Y1Prev;
			m_dryRightLowLpStage1Y_122 = rightLowStage1Out;
			t_sample rightLowStage2X1Prev = fixdenorm(m_dryRightLowLpStage2X_120);
			t_sample rightLowStage2X2Prev = fixdenorm(m_dryRightLowLpStage2X_119);
			t_sample rightLowStage2Y1Prev = fixdenorm(m_dryRightLowLpStage2Y_118);
			t_sample rightLowStage2Y2Prev = fixdenorm(m_dryRightLowLpStage2Y_117);
			t_sample rightLowStage2Sum = (((rightLpB0Low_12369 * rightLowStage1Out) + (rightLpB1Low_12370 * rightLowStage2X1Prev)) + (rightLpB2Low_12371 * rightLowStage2X2Prev));
			t_sample rightLowStage2Out = ((rightLowStage2Sum - (rightLpA1Low_12372 * rightLowStage2Y1Prev)) - (rightLpA2Low_12373 * rightLowStage2Y2Prev));
			m_dryRightLowLpStage2X_119 = rightLowStage2X1Prev;
			m_dryRightLowLpStage2X_120 = rightLowStage1Out;
			m_dryRightLowLpStage2Y_117 = rightLowStage2Y1Prev;
			m_dryRightLowLpStage2Y_118 = rightLowStage2Out;
			t_sample rightHighStage1X1Prev = fixdenorm(m_dryRightLowHpStage1X_116);
			t_sample rightHighStage1X2Prev = fixdenorm(m_dryRightLowHpStage1X_115);
			t_sample rightHighStage1Y1Prev = fixdenorm(m_dryRightLowHpStage1Y_114);
			t_sample rightHighStage1Y2Prev = fixdenorm(m_dryRightLowHpStage1Y_113);
			t_sample rightHighStage1Sum = (((rightHpB0Low_12374 * dryRightInput) + (rightHpB1Low_12375 * rightHighStage1X1Prev)) + (rightHpB2Low_12376 * rightHighStage1X2Prev));
			t_sample rightHighStage1Out = ((rightHighStage1Sum - (rightHpA1Low_12377 * rightHighStage1Y1Prev)) - (rightHpA2Low_12378 * rightHighStage1Y2Prev));
			m_dryRightLowHpStage1X_115 = rightHighStage1X1Prev;
			m_dryRightLowHpStage1X_116 = dryRightInput;
			m_dryRightLowHpStage1Y_113 = rightHighStage1Y1Prev;
			m_dryRightLowHpStage1Y_114 = rightHighStage1Out;
			t_sample rightHighStage2X1Prev = fixdenorm(m_dryRightLowHpStage2X_112);
			t_sample rightHighStage2X2Prev = fixdenorm(m_dryRightLowHpStage2X_111);
			t_sample rightHighStage2Y1Prev = fixdenorm(m_dryRightLowHpStage2Y_110);
			t_sample rightHighStage2Y2Prev = fixdenorm(m_dryRightLowHpStage2Y_109);
			t_sample rightHighStage2Sum = (((rightHpB0Low_12374 * rightHighStage1Out) + (rightHpB1Low_12375 * rightHighStage2X1Prev)) + (rightHpB2Low_12376 * rightHighStage2X2Prev));
			t_sample rightHighStage2Out = ((rightHighStage2Sum - (rightHpA1Low_12377 * rightHighStage2Y1Prev)) - (rightHpA2Low_12378 * rightHighStage2Y2Prev));
			m_dryRightLowHpStage2X_111 = rightHighStage2X1Prev;
			m_dryRightLowHpStage2X_112 = rightHighStage1Out;
			m_dryRightLowHpStage2Y_109 = rightHighStage2Y1Prev;
			m_dryRightLowHpStage2Y_110 = rightHighStage2Out;
			t_sample rightApLowLpStage1X1Prev = fixdenorm(m_apRightLowLpStage1X_92);
			t_sample rightApLowLpStage1X2Prev = fixdenorm(m_apRightLowLpStage1X_91);
			t_sample rightApLowLpStage1Y1Prev = fixdenorm(m_apRightLowLpStage1Y_90);
			t_sample rightApLowLpStage1Y2Prev = fixdenorm(m_apRightLowLpStage1Y_89);
			t_sample rightApLowLpStage1Sum = (((rightLpB0High_12386 * rightLowStage2Out) + (rightLpB1High_12387 * rightApLowLpStage1X1Prev)) + (rightLpB2High_12388 * rightApLowLpStage1X2Prev));
			t_sample rightApLowLpStage1Out = ((rightApLowLpStage1Sum - (rightLpA1High_12389 * rightApLowLpStage1Y1Prev)) - (rightLpA2High_12390 * rightApLowLpStage1Y2Prev));
			m_apRightLowLpStage1X_91 = rightApLowLpStage1X1Prev;
			m_apRightLowLpStage1X_92 = rightLowStage2Out;
			m_apRightLowLpStage1Y_89 = rightApLowLpStage1Y1Prev;
			m_apRightLowLpStage1Y_90 = rightApLowLpStage1Out;
			t_sample rightApLowLpStage2X1Prev = fixdenorm(m_apRightLowLpStage2X_88);
			t_sample rightApLowLpStage2X2Prev = fixdenorm(m_apRightLowLpStage2X_87);
			t_sample rightApLowLpStage2Y1Prev = fixdenorm(m_apRightLowLpStage2Y_86);
			t_sample rightApLowLpStage2Y2Prev = fixdenorm(m_apRightLowLpStage2Y_85);
			t_sample rightApLowLpStage2Sum = (((rightLpB0High_12386 * rightApLowLpStage1Out) + (rightLpB1High_12387 * rightApLowLpStage2X1Prev)) + (rightLpB2High_12388 * rightApLowLpStage2X2Prev));
			t_sample rightApLowLpStage2Out = ((rightApLowLpStage2Sum - (rightLpA1High_12389 * rightApLowLpStage2Y1Prev)) - (rightLpA2High_12390 * rightApLowLpStage2Y2Prev));
			m_apRightLowLpStage2X_87 = rightApLowLpStage2X1Prev;
			m_apRightLowLpStage2X_88 = rightApLowLpStage1Out;
			m_apRightLowLpStage2Y_85 = rightApLowLpStage2Y1Prev;
			m_apRightLowLpStage2Y_86 = rightApLowLpStage2Out;
			t_sample rightApLowHpStage1X1Prev = fixdenorm(m_apRightLowHpStage1X_84);
			t_sample rightApLowHpStage1X2Prev = fixdenorm(m_apRightLowHpStage1X_83);
			t_sample rightApLowHpStage1Y1Prev = fixdenorm(m_apRightLowHpStage1Y_82);
			t_sample rightApLowHpStage1Y2Prev = fixdenorm(m_apRightLowHpStage1Y_81);
			t_sample rightApLowHpStage1Sum = (((rightHpB0High_12391 * rightLowStage2Out) + (rightHpB1High_12392 * rightApLowHpStage1X1Prev)) + (rightHpB2High_12393 * rightApLowHpStage1X2Prev));
			t_sample rightApLowHpStage1Out = ((rightApLowHpStage1Sum - (rightHpA1High_12394 * rightApLowHpStage1Y1Prev)) - (rightHpA2High_12395 * rightApLowHpStage1Y2Prev));
			m_apRightLowHpStage1X_83 = rightApLowHpStage1X1Prev;
			m_apRightLowHpStage1X_84 = rightLowStage2Out;
			m_apRightLowHpStage1Y_81 = rightApLowHpStage1Y1Prev;
			m_apRightLowHpStage1Y_82 = rightApLowHpStage1Out;
			t_sample rightApLowHpStage2X1Prev = fixdenorm(m_apRightLowHpStage2X_80);
			t_sample rightApLowHpStage2X2Prev = fixdenorm(m_apRightLowHpStage2X_79);
			t_sample rightApLowHpStage2Y1Prev = fixdenorm(m_apRightLowHpStage2Y_78);
			t_sample rightApLowHpStage2Y2Prev = fixdenorm(m_apRightLowHpStage2Y_77);
			t_sample rightApLowHpStage2Sum = (((rightHpB0High_12391 * rightApLowHpStage1Out) + (rightHpB1High_12392 * rightApLowHpStage2X1Prev)) + (rightHpB2High_12393 * rightApLowHpStage2X2Prev));
			t_sample rightApLowHpStage2Out = ((rightApLowHpStage2Sum - (rightHpA1High_12394 * rightApLowHpStage2Y1Prev)) - (rightHpA2High_12395 * rightApLowHpStage2Y2Prev));
			m_apRightLowHpStage2X_79 = rightApLowHpStage2X1Prev;
			m_apRightLowHpStage2X_80 = rightApLowHpStage1Out;
			m_apRightLowHpStage2Y_77 = rightApLowHpStage2Y1Prev;
			m_apRightLowHpStage2Y_78 = rightApLowHpStage2Out;
			t_sample dryRightLowBand = (rightApLowLpStage2Out + rightApLowHpStage2Out);
			t_sample rightMidStage1X1Prev = fixdenorm(m_dryRightMidLpStage1X_108);
			t_sample rightMidStage1X2Prev = fixdenorm(m_dryRightMidLpStage1X_107);
			t_sample rightMidStage1Y1Prev = fixdenorm(m_dryRightMidLpStage1Y_106);
			t_sample rightMidStage1Y2Prev = fixdenorm(m_dryRightMidLpStage1Y_105);
			t_sample rightMidStage1Sum = (((rightLpB0High_12386 * rightHighStage2Out) + (rightLpB1High_12387 * rightMidStage1X1Prev)) + (rightLpB2High_12388 * rightMidStage1X2Prev));
			t_sample rightMidStage1Out = ((rightMidStage1Sum - (rightLpA1High_12389 * rightMidStage1Y1Prev)) - (rightLpA2High_12390 * rightMidStage1Y2Prev));
			m_dryRightMidLpStage1X_107 = rightMidStage1X1Prev;
			m_dryRightMidLpStage1X_108 = rightHighStage2Out;
			m_dryRightMidLpStage1Y_105 = rightMidStage1Y1Prev;
			m_dryRightMidLpStage1Y_106 = rightMidStage1Out;
			t_sample rightMidStage2X1Prev = fixdenorm(m_dryRightMidLpStage2X_104);
			t_sample rightMidStage2X2Prev = fixdenorm(m_dryRightMidLpStage2X_103);
			t_sample rightMidStage2Y1Prev = fixdenorm(m_dryRightMidLpStage2Y_102);
			t_sample rightMidStage2Y2Prev = fixdenorm(m_dryRightMidLpStage2Y_101);
			t_sample rightMidStage2Sum = (((rightLpB0High_12386 * rightMidStage1Out) + (rightLpB1High_12387 * rightMidStage2X1Prev)) + (rightLpB2High_12388 * rightMidStage2X2Prev));
			t_sample rightMidStage2Out = ((rightMidStage2Sum - (rightLpA1High_12389 * rightMidStage2Y1Prev)) - (rightLpA2High_12390 * rightMidStage2Y2Prev));
			m_dryRightMidLpStage2X_103 = rightMidStage2X1Prev;
			m_dryRightMidLpStage2X_104 = rightMidStage1Out;
			m_dryRightMidLpStage2Y_101 = rightMidStage2Y1Prev;
			m_dryRightMidLpStage2Y_102 = rightMidStage2Out;
			t_sample dryRightMidBand = rightMidStage2Out;
			t_sample rightHighBandStage1X1Prev = fixdenorm(m_dryRightHighHpStage1X_100);
			t_sample rightHighBandStage1X2Prev = fixdenorm(m_dryRightHighHpStage1X_99);
			t_sample rightHighBandStage1Y1Prev = fixdenorm(m_dryRightHighHpStage1Y_98);
			t_sample rightHighBandStage1Y2Prev = fixdenorm(m_dryRightHighHpStage1Y_97);
			t_sample rightHighBandStage1Sum = (((rightHpB0High_12391 * rightHighStage2Out) + (rightHpB1High_12392 * rightHighBandStage1X1Prev)) + (rightHpB2High_12393 * rightHighBandStage1X2Prev));
			t_sample rightHighBandStage1Out = ((rightHighBandStage1Sum - (rightHpA1High_12394 * rightHighBandStage1Y1Prev)) - (rightHpA2High_12395 * rightHighBandStage1Y2Prev));
			m_dryRightHighHpStage1X_99 = rightHighBandStage1X1Prev;
			m_dryRightHighHpStage1X_100 = rightHighStage2Out;
			m_dryRightHighHpStage1Y_97 = rightHighBandStage1Y1Prev;
			m_dryRightHighHpStage1Y_98 = rightHighBandStage1Out;
			t_sample rightHighBandStage2X1Prev = fixdenorm(m_dryRightHighHpStage2X_96);
			t_sample rightHighBandStage2X2Prev = fixdenorm(m_dryRightHighHpStage2X_95);
			t_sample rightHighBandStage2Y1Prev = fixdenorm(m_dryRightHighHpStage2Y_94);
			t_sample rightHighBandStage2Y2Prev = fixdenorm(m_dryRightHighHpStage2Y_93);
			t_sample rightHighBandStage2Sum = (((rightHpB0High_12391 * rightHighBandStage1Out) + (rightHpB1High_12392 * rightHighBandStage2X1Prev)) + (rightHpB2High_12393 * rightHighBandStage2X2Prev));
			t_sample rightHighBandStage2Out = ((rightHighBandStage2Sum - (rightHpA1High_12394 * rightHighBandStage2Y1Prev)) - (rightHpA2High_12395 * rightHighBandStage2Y2Prev));
			m_dryRightHighHpStage2X_95 = rightHighBandStage2X1Prev;
			m_dryRightHighHpStage2X_96 = rightHighBandStage1Out;
			m_dryRightHighHpStage2Y_93 = rightHighBandStage2Y1Prev;
			m_dryRightHighHpStage2Y_94 = rightHighBandStage2Out;
			t_sample dryRightHighBand = rightHighBandStage2Out;
			t_sample dryRightSumBands = ((dryRightLowBand + dryRightMidBand) + dryRightHighBand);
			t_sample lowRIn = dryRightLowBand;
			t_sample midRIn = dryRightMidBand;
			t_sample highRIn = dryRightHighBand;
			t_sample lowWidthParam = ((lowBandGainSmoothed <= ((int)0)) ? ((int)0) : ((lowBandGainSmoothed >= ((int)200)) ? ((int)200) : lowBandGainSmoothed));
			t_sample lowInputParam = ((inputModeSmoothed <= ((int)0)) ? ((int)0) : ((inputModeSmoothed >= ((int)1)) ? ((int)1) : inputModeSmoothed));
			t_sample mix_12500 = (((int)0) + (((t_sample)0.999) * (m_lowBypassHistory_76 - ((int)0))));
			t_sample lowBypassSmoothed = mix_12500;
			t_sample lowBypassHistoryNext = fixdenorm(lowBypassSmoothed);
			t_sample lowBypassMask = (((int)1) - lowBypassSmoothed);
			t_sample mix_12501 = (lowBalanceParam + (((t_sample)0.999) * (m_lowBalanceHistory_75 - lowBalanceParam)));
			t_sample lowBalanceSmoothed = mix_12501;
			t_sample lowBalanceHistoryNext = fixdenorm(lowBalanceSmoothed);
			t_sample lowBalT = ((lowBalanceSmoothed - ((t_sample)0.5)) * ((int)2));
			t_sample lowBalPos = ((lowBalT < ((int)0)) ? ((int)0) : lowBalT);
			t_sample lowBalNeg = ((((int)0) < lowBalT) ? ((int)0) : lowBalT);
			t_sample v_257 = (((int)1) - lowBalPos);
			t_sample lowBalGL = ((v_257 <= ((int)0)) ? ((int)0) : ((v_257 >= ((int)1)) ? ((int)1) : v_257));
			t_sample v_258 = (((int)1) + lowBalNeg);
			t_sample lowBalGR = ((v_258 <= ((int)0)) ? ((int)0) : ((v_258 >= ((int)1)) ? ((int)1) : v_258));
			t_sample mix_12502 = (lowWidthParam + (((t_sample)0.999) * (m_lowWidthHistory_74 - lowWidthParam)));
			t_sample lowWidthSmoothed = mix_12502;
			t_sample lowWidthHistoryNext = fixdenorm(lowWidthSmoothed);
			t_sample mix_12503 = (lowInputParam + (((t_sample)0.999) * (m_lowInputModeHistory_73 - lowInputParam)));
			t_sample lowInputModeSmoothed = mix_12503;
			t_sample lowInputModeHistoryNext = fixdenorm(lowInputModeSmoothed);
			t_sample mix_12504 = (lowLIn + (lowInputModeSmoothed * (((int)0) - lowLIn)));
			t_sample lowLeftBlend = mix_12504;
			t_sample mix_12505 = (lowRIn + (lowInputModeSmoothed * (((int)0) - lowRIn)));
			t_sample lowRightBlend = mix_12505;
			t_sample mix_12506 = (((int)0) + (lowInputModeSmoothed * (lowLIn - ((int)0))));
			t_sample lowLeftProcessed = mix_12506;
			t_sample mix_12507 = (((int)0) + (lowInputModeSmoothed * (lowRIn - ((int)0))));
			t_sample lowRightProcessed = mix_12507;
			t_sample lowInputSum = (lowLeftProcessed + lowRightProcessed);
			t_sample mLowRaw = ((lowInputSum + lowLeftBlend) * ((int)1));
			t_sample lowInputDiff = (lowLeftProcessed - lowRightProcessed);
			t_sample sLowRaw = ((lowRightBlend + lowInputDiff) * ((int)1));
			t_sample lowWidthNormalized = ((lowWidthSmoothed <= ((int)0)) ? ((int)0) : ((lowWidthSmoothed >= ((int)2)) ? ((int)2) : lowWidthSmoothed));
			t_sample lowWidthHalf = (lowWidthNormalized * ((t_sample)0.5));
			t_sample lowTheta = (lowWidthHalf * ((t_sample)1.2319971190548));
			t_sample lowMonoGain = cos(lowTheta);
			t_sample lowSideGain = sin(lowTheta);
			t_sample lLowPre = ((mLowRaw + sLowRaw) * ((t_sample)0.5));
			t_sample rLowPre = ((mLowRaw - sLowRaw) * ((t_sample)0.5));
			m_lowLeftEnergyM_51 = fixdenorm((m_lowLeftEnergyM_51 + (lowRmsAlpha * ((lLowPre * lLowPre) - m_lowLeftEnergyM_51))));
			m_lowRightEnergyM_50 = fixdenorm((m_lowRightEnergyM_50 + (lowRmsAlpha * ((rLowPre * rLowPre) - m_lowRightEnergyM_50))));
			m_lowCrossCorrelationM_52 = fixdenorm((m_lowCrossCorrelationM_52 + (lowRmsAlpha * ((lLowPre * rLowPre) - m_lowCrossCorrelationM_52))));
			m_lowEnergyM_54 = fixdenorm((m_lowEnergyM_54 + (lowRmsAlpha * ((mLowRaw * mLowRaw) - m_lowEnergyM_54))));
			m_lowSideEnergyM_53 = fixdenorm((m_lowSideEnergyM_53 + (lowRmsAlpha * ((sLowRaw * sLowRaw) - m_lowSideEnergyM_53))));
			t_sample lowMatrixA = (((t_sample)0.5) * (lowMonoGain + lowSideGain));
			t_sample lowMatrixB = (((t_sample)0.5) * (lowMonoGain - lowSideGain));
			t_sample lowInputPower = ((m_lowLeftEnergyM_51 + m_lowRightEnergyM_50) + ((t_sample)1e-12));
			t_sample lowOutputPower = (((((lowMatrixA * lowMatrixA) + (lowMatrixB * lowMatrixB)) * (m_lowLeftEnergyM_51 + m_lowRightEnergyM_50)) + (((((int)4) * lowMatrixA) * lowMatrixB) * m_lowCrossCorrelationM_52)) + ((t_sample)1e-12));
			t_sample lowNormalizationGain = sqrt(safediv(lowInputPower, lowOutputPower));
			t_sample lowCorrelationNumerator = m_lowCrossCorrelationM_52;
			t_sample maxa_259 = (m_lowLeftEnergyM_51 * m_lowRightEnergyM_50);
			t_sample lowCorrelationDenominator = sqrt(((maxa_259 < ((t_sample)1e-12)) ? ((t_sample)1e-12) : maxa_259));
			t_sample v_260 = safediv(lowCorrelationNumerator, (lowCorrelationDenominator + ((t_sample)1e-12)));
			t_sample lowCorrelation = ((v_260 <= ((int)-1)) ? ((int)-1) : ((v_260 >= ((int)1)) ? ((int)1) : v_260));
			t_sample lowMonoGainSafe = ((lowMonoGain < ((t_sample)0.05)) ? ((t_sample)0.05) : lowMonoGain);
			t_sample v_261 = safediv(((int)1), lowMonoGainSafe);
			t_sample monoNeedLow = ((v_261 <= ((t_sample)1.6788040181226)) ? ((t_sample)1.6788040181226) : ((v_261 >= ((t_sample)3.3496543915783)) ? ((t_sample)3.3496543915783) : v_261));
			t_sample lowCorrelationPositive = ((lowCorrelation < ((int)0)) ? ((int)0) : lowCorrelation);
			t_sample boostAllowanceLow = (((t_sample)1.6788040181226) + ((monoNeedLow - ((t_sample)1.6788040181226)) * lowCorrelationPositive));
			t_sample lowNormalizationGain_12397 = ((lowNormalizationGain <= ((t_sample)0.59566214352901)) ? ((t_sample)0.59566214352901) : ((lowNormalizationGain >= boostAllowanceLow) ? boostAllowanceLow : lowNormalizationGain));
			t_sample maxb_262 = (lowWidthHalf - ((t_sample)0.5));
			t_sample lowLiftBase = ((((int)0) < maxb_262) ? maxb_262 : ((int)0));
			t_sample lowLiftDb = ((((int)6) * lowLiftBase) * (((int)1) - lowCorrelation));
			t_sample lowNormalizationGain_12398 = (lowNormalizationGain_12397 * dbtoa(lowLiftDb));
			t_sample lowMonoHalf = (mLowRaw * ((t_sample)0.5));
			t_sample lowSideHalf = (sLowRaw * ((t_sample)0.5));
			t_sample lowMonoScaled = (lowMonoHalf * (lowMonoGain * lowNormalizationGain_12398));
			t_sample lowSideScaled = (lowSideHalf * (lowSideGain * lowNormalizationGain_12398));
			t_sample lowSidePolarity = (lowSideScaled * ((int)1));
			t_sample lowRightPreWidth = (lowMonoScaled - lowSidePolarity);
			t_sample lowLeftPreWidth = (lowMonoScaled + lowSidePolarity);
			t_sample lowLeftBalanced = (lowLeftPreWidth * lowBalGL);
			t_sample lowLeftWithGain = (lowLeftBalanced * ((int)1));
			t_sample mix_12508 = (lowLIn + (lowBypassMask * (lowLeftWithGain - lowLIn)));
			t_sample mix_12509 = (muteLow + (((t_sample)0.999) * (m_muteLowHistory_57 - muteLow)));
			t_sample muteLowSmoothed = mix_12509;
			m_muteLowHistory_57 = fixdenorm(muteLowSmoothed);
			t_sample lowMuteGateRaw = (((int)1) - ((muteLowSmoothed <= ((int)0)) ? ((int)0) : ((muteLowSmoothed >= ((int)1)) ? ((int)1) : muteLowSmoothed)));
			t_sample lowLeftMixed_12399 = (mix_12508 * lowMuteGateRaw);
			t_sample lowRightBalanced = (lowRightPreWidth * lowBalGR);
			t_sample lowRightWithGain = (lowRightBalanced * ((int)1));
			t_sample mix_12510 = (lowRIn + (lowBypassMask * (lowRightWithGain - lowRIn)));
			t_sample lowRightMixed_12400 = (mix_12510 * lowMuteGateRaw);
			t_sample mix_12511 = (lowRightMixed_12400 + (soloMaskLow * (((int)0) - lowRightMixed_12400)));
			t_sample mix_12512 = (lowLeftMixed_12399 + (soloMaskLow * (((int)0) - lowLeftMixed_12399)));
			t_sample midBalanceParam = ((midBalanceSmoothed <= ((int)0)) ? ((int)0) : ((midBalanceSmoothed >= ((int)1)) ? ((int)1) : midBalanceSmoothed));
			t_sample midWidthParam = ((midBandGainSmoothed <= ((int)0)) ? ((int)0) : ((midBandGainSmoothed >= ((int)200)) ? ((int)200) : midBandGainSmoothed));
			t_sample midInputParam = ((inputModeSmoothed <= ((int)0)) ? ((int)0) : ((inputModeSmoothed >= ((int)1)) ? ((int)1) : inputModeSmoothed));
			t_sample mix_12513 = (((int)0) + (((t_sample)0.999) * (m_midBypassHistory_72 - ((int)0))));
			t_sample midBypassSmoothed = mix_12513;
			t_sample midBypassHistoryNext = fixdenorm(midBypassSmoothed);
			t_sample midBypassMask = (((int)1) - midBypassSmoothed);
			t_sample mix_12514 = (((int)0) + (((t_sample)0.999) * (m_midMakeupHistory_71 - ((int)0))));
			t_sample midMakeupDbSmoothed = mix_12514;
			t_sample midMakeupHistoryNext = fixdenorm(midMakeupDbSmoothed);
			t_sample midMakeupLinear = dbtoa(midMakeupDbSmoothed);
			t_sample mix_12515 = (midBalanceParam + (((t_sample)0.999) * (m_midBalanceInternalHistory_70 - midBalanceParam)));
			t_sample midBalanceSmoothed_12402 = mix_12515;
			t_sample midBalanceInternalHistoryNext = fixdenorm(midBalanceSmoothed_12402);
			t_sample midBalT = ((midBalanceSmoothed_12402 - ((t_sample)0.5)) * ((int)2));
			t_sample midBalPos = ((midBalT < ((int)0)) ? ((int)0) : midBalT);
			t_sample midBalNeg = ((((int)0) < midBalT) ? ((int)0) : midBalT);
			t_sample v_263 = (((int)1) - midBalPos);
			t_sample midBalGL = ((v_263 <= ((int)0)) ? ((int)0) : ((v_263 >= ((int)1)) ? ((int)1) : v_263));
			t_sample v_264 = (((int)1) + midBalNeg);
			t_sample midBalGR = ((v_264 <= ((int)0)) ? ((int)0) : ((v_264 >= ((int)1)) ? ((int)1) : v_264));
			t_sample mix_12516 = (midWidthParam + (((t_sample)0.999) * (m_midWidthHistory_69 - midWidthParam)));
			t_sample midWidthSmoothed = mix_12516;
			t_sample midWidthHistoryNext = fixdenorm(midWidthSmoothed);
			t_sample mix_12517 = (midInputParam + (((t_sample)0.999) * (m_midInputModeHistory_68 - midInputParam)));
			t_sample midInputModeSmoothed = mix_12517;
			t_sample midInputModeHistoryNext = fixdenorm(midInputModeSmoothed);
			t_sample mix_12518 = (midLIn + (midInputModeSmoothed * (((int)0) - midLIn)));
			t_sample midLeftBypassBlend = mix_12518;
			t_sample mix_12519 = (midRIn + (midInputModeSmoothed * (((int)0) - midRIn)));
			t_sample midRightBypassBlend = mix_12519;
			t_sample mix_12520 = (((int)0) + (midInputModeSmoothed * (midLIn - ((int)0))));
			t_sample midLeftProcessed = mix_12520;
			t_sample mix_12521 = (((int)0) + (midInputModeSmoothed * (midRIn - ((int)0))));
			t_sample midRightProcessed = mix_12521;
			t_sample midInputSum = (midLeftProcessed + midRightProcessed);
			t_sample midInputDiff = (midLeftProcessed - midRightProcessed);
			t_sample mix_12522 = (((int)1) + (((t_sample)0.999) * (m_midBandGainHistoryInternal_67 - ((int)1))));
			t_sample midBandGainSmoothed_12404 = mix_12522;
			t_sample midBandGainHistoryInternalNext = fixdenorm(midBandGainSmoothed_12404);
			t_sample midBandGainLinear = midBandGainSmoothed_12404;
			t_sample mMidRaw = ((midInputSum + midLeftBypassBlend) * midBandGainLinear);
			t_sample mix_12523 = (((int)1) + (((t_sample)0.999) * (m_midSideGainHistory_66 - ((int)1))));
			t_sample midSideGainSmoothed = mix_12523;
			t_sample midSideGainHistoryNext = fixdenorm(midSideGainSmoothed);
			t_sample midSideGainLinear = midSideGainSmoothed;
			t_sample sMidRaw = ((midRightBypassBlend + midInputDiff) * midSideGainLinear);
			t_sample mix_12524 = (((int)1) + (((int)0) * (m_midInvertHistory_65 - ((int)1))));
			t_sample midInvertSmoothed = mix_12524;
			t_sample midInvertHistoryNext = fixdenorm(midInvertSmoothed);
			t_sample midWidthNormalized = ((midWidthSmoothed <= ((int)0)) ? ((int)0) : ((midWidthSmoothed >= ((int)2)) ? ((int)2) : midWidthSmoothed));
			t_sample midWidthHalf = (midWidthNormalized * ((t_sample)0.5));
			t_sample midTheta = (midWidthHalf * ((t_sample)1.2319971190548));
			t_sample midMonoGain = cos(midTheta);
			t_sample midSideGain = sin(midTheta);
			t_sample lMidPre = ((mMidRaw + sMidRaw) * ((t_sample)0.5));
			t_sample rMidPre = ((mMidRaw - sMidRaw) * ((t_sample)0.5));
			m_midLeftEnergyM_49 = fixdenorm((m_midLeftEnergyM_49 + (midRmsAlpha * ((lMidPre * lMidPre) - m_midLeftEnergyM_49))));
			m_midRightEnergyM_48 = fixdenorm((m_midRightEnergyM_48 + (midRmsAlpha * ((rMidPre * rMidPre) - m_midRightEnergyM_48))));
			m_midCrossCorrelationM_43 = fixdenorm((m_midCrossCorrelationM_43 + (midRmsAlpha * ((lMidPre * rMidPre) - m_midCrossCorrelationM_43))));
			m_midEnergyM_45 = fixdenorm((m_midEnergyM_45 + (midRmsAlpha * ((mMidRaw * mMidRaw) - m_midEnergyM_45))));
			m_midSideEnergyM_44 = fixdenorm((m_midSideEnergyM_44 + (midRmsAlpha * ((sMidRaw * sMidRaw) - m_midSideEnergyM_44))));
			t_sample midMatrixA = (((t_sample)0.5) * (midMonoGain + midSideGain));
			t_sample midMatrixB = (((t_sample)0.5) * (midMonoGain - midSideGain));
			t_sample midInputPower = ((m_midLeftEnergyM_49 + m_midRightEnergyM_48) + ((t_sample)1e-12));
			t_sample midOutputPower = (((((midMatrixA * midMatrixA) + (midMatrixB * midMatrixB)) * (m_midLeftEnergyM_49 + m_midRightEnergyM_48)) + (((((int)4) * midMatrixA) * midMatrixB) * m_midCrossCorrelationM_43)) + ((t_sample)1e-12));
			t_sample midNormalizationGain = sqrt(safediv(midInputPower, midOutputPower));
			t_sample midCorrelationNumerator = m_midCrossCorrelationM_43;
			t_sample maxa_265 = (m_midLeftEnergyM_49 * m_midRightEnergyM_48);
			t_sample midCorrelationDenominator = sqrt(((maxa_265 < ((t_sample)1e-12)) ? ((t_sample)1e-12) : maxa_265));
			t_sample v_266 = safediv(midCorrelationNumerator, (midCorrelationDenominator + ((t_sample)1e-12)));
			t_sample midCorrelation = ((v_266 <= ((int)-1)) ? ((int)-1) : ((v_266 >= ((int)1)) ? ((int)1) : v_266));
			t_sample midMonoGainSafe = ((midMonoGain < ((t_sample)0.05)) ? ((t_sample)0.05) : midMonoGain);
			t_sample v_267 = safediv(((int)1), midMonoGainSafe);
			t_sample monoNeedMid = ((v_267 <= ((t_sample)1.6788040181226)) ? ((t_sample)1.6788040181226) : ((v_267 >= ((t_sample)3.3496543915783)) ? ((t_sample)3.3496543915783) : v_267));
			t_sample midCorrelationPositive = ((midCorrelation < ((int)0)) ? ((int)0) : midCorrelation);
			t_sample boostAllowanceMid = (((t_sample)1.6788040181226) + ((monoNeedMid - ((t_sample)1.6788040181226)) * midCorrelationPositive));
			t_sample midNormalizationGain_12405 = ((midNormalizationGain <= ((t_sample)0.59566214352901)) ? ((t_sample)0.59566214352901) : ((midNormalizationGain >= boostAllowanceMid) ? boostAllowanceMid : midNormalizationGain));
			t_sample maxb_268 = (midWidthHalf - ((t_sample)0.5));
			t_sample midLiftBase = ((((int)0) < maxb_268) ? maxb_268 : ((int)0));
			t_sample midLiftDb = ((((int)6) * midLiftBase) * (((int)1) - midCorrelation));
			t_sample midNormalizationGain_12406 = (midNormalizationGain_12405 * dbtoa(midLiftDb));
			t_sample midMonoHalf = (mMidRaw * ((t_sample)0.5));
			t_sample midSideHalf = (sMidRaw * ((t_sample)0.5));
			t_sample midMonoScaled = (midMonoHalf * (midMonoGain * midNormalizationGain_12406));
			t_sample midSideScaled = (midSideHalf * (midSideGain * midNormalizationGain_12406));
			t_sample midSidePolarity = (midSideScaled * midInvertSmoothed);
			t_sample midRightPreWidth = (midMonoScaled - midSidePolarity);
			t_sample midLeftPreWidth = (midMonoScaled + midSidePolarity);
			t_sample midRightBalanced = (midRightPreWidth * midBalGR);
			t_sample midRightWithBandGain = (midRightBalanced * midMakeupLinear);
			t_sample mix_12525 = (midRIn + (midBypassMask * (midRightWithBandGain - midRIn)));
			t_sample mix_12526 = (muteMid + (((t_sample)0.999) * (m_muteMidHistory_56 - muteMid)));
			t_sample muteMidSmoothed = mix_12526;
			m_muteMidHistory_56 = fixdenorm(muteMidSmoothed);
			t_sample midMuteGateRaw = (((int)1) - ((muteMidSmoothed <= ((int)0)) ? ((int)0) : ((muteMidSmoothed >= ((int)1)) ? ((int)1) : muteMidSmoothed)));
			t_sample midRightMixed_12407 = (mix_12525 * midMuteGateRaw);
			t_sample midLeftBalanced = (midLeftPreWidth * midBalGL);
			t_sample midLeftWithBandGain = (midLeftBalanced * midMakeupLinear);
			t_sample mix_12527 = (midLIn + (midBypassMask * (midLeftWithBandGain - midLIn)));
			t_sample midLeftMixed_12408 = (mix_12527 * midMuteGateRaw);
			t_sample mix_12528 = (midRightMixed_12407 + (soloMaskMid * (((int)0) - midRightMixed_12407)));
			t_sample mix_12529 = (midLeftMixed_12408 + (soloMaskMid * (((int)0) - midLeftMixed_12408)));
			t_sample highBalanceParam = ((highBalanceSmoothed <= ((int)0)) ? ((int)0) : ((highBalanceSmoothed >= ((int)1)) ? ((int)1) : highBalanceSmoothed));
			t_sample highWidthParam = ((highBandGainSmoothed <= ((int)0)) ? ((int)0) : ((highBandGainSmoothed >= ((int)200)) ? ((int)200) : highBandGainSmoothed));
			t_sample highInputParam = ((inputModeSmoothed <= ((int)0)) ? ((int)0) : ((inputModeSmoothed >= ((int)1)) ? ((int)1) : inputModeSmoothed));
			t_sample mix_12530 = (((int)0) + (((t_sample)0.999) * (m_highBypassHistory_64 - ((int)0))));
			t_sample highBypassSmoothed = mix_12530;
			t_sample highBypassHistoryNext = fixdenorm(highBypassSmoothed);
			t_sample highBypassMask = (((int)1) - highBypassSmoothed);
			t_sample mix_12531 = (((int)0) + (((t_sample)0.999) * (m_highMakeupHistory_63 - ((int)0))));
			t_sample highMakeupDbSmoothed = mix_12531;
			t_sample highMakeupHistoryNext = fixdenorm(highMakeupDbSmoothed);
			t_sample highMakeupLinear = dbtoa(highMakeupDbSmoothed);
			t_sample mix_12532 = (highBalanceParam + (((t_sample)0.999) * (m_highBalanceHistoryInternal_62 - highBalanceParam)));
			t_sample highBalanceSmoothed_12410 = mix_12532;
			t_sample highBalanceHistoryInternalNext = fixdenorm(highBalanceSmoothed_12410);
			t_sample highBalT = ((highBalanceSmoothed_12410 - ((t_sample)0.5)) * ((int)2));
			t_sample highBalPos = ((highBalT < ((int)0)) ? ((int)0) : highBalT);
			t_sample highBalNeg = ((((int)0) < highBalT) ? ((int)0) : highBalT);
			t_sample v_269 = (((int)1) - highBalPos);
			t_sample highBalGL = ((v_269 <= ((int)0)) ? ((int)0) : ((v_269 >= ((int)1)) ? ((int)1) : v_269));
			t_sample v_270 = (((int)1) + highBalNeg);
			t_sample highBalGR = ((v_270 <= ((int)0)) ? ((int)0) : ((v_270 >= ((int)1)) ? ((int)1) : v_270));
			t_sample mix_12533 = (highWidthParam + (((t_sample)0.999) * (m_highWidthHistory_61 - highWidthParam)));
			t_sample highWidthSmoothed = mix_12533;
			t_sample highWidthHistoryNext = fixdenorm(highWidthSmoothed);
			t_sample mix_12534 = (highInputParam + (((t_sample)0.999) * (m_highInputModeHistory_60 - highInputParam)));
			t_sample highInputModeSmoothed = mix_12534;
			t_sample highInputModeHistoryNext = fixdenorm(highInputModeSmoothed);
			t_sample mix_12535 = (highLIn + (highInputModeSmoothed * (((int)0) - highLIn)));
			t_sample highLeftBypassBlend = mix_12535;
			t_sample mix_12536 = (highRIn + (highInputModeSmoothed * (((int)0) - highRIn)));
			t_sample highRightBypassBlend = mix_12536;
			t_sample mix_12537 = (((int)0) + (highInputModeSmoothed * (highLIn - ((int)0))));
			t_sample highLeftProcessed = mix_12537;
			t_sample mix_12538 = (((int)0) + (highInputModeSmoothed * (highRIn - ((int)0))));
			t_sample highRightProcessed = mix_12538;
			t_sample highInputSum = (highLeftProcessed + highRightProcessed);
			t_sample highInputDiff = (highLeftProcessed - highRightProcessed);
			t_sample mix_12539 = (((int)1) + (((t_sample)0.999) * (m_highBandGainHistoryInternal_59 - ((int)1))));
			t_sample highBandGainSmoothed_12412 = mix_12539;
			t_sample highBandGainHistoryInternalNext = fixdenorm(highBandGainSmoothed_12412);
			t_sample highBandGainLinear = highBandGainSmoothed_12412;
			t_sample mHighRaw = ((highInputSum + highLeftBypassBlend) * highBandGainLinear);
			t_sample mix_12540 = (((int)1) + (((t_sample)0.999) * (m_highSideGainHistory_58 - ((int)1))));
			t_sample highSideGainSmoothed = mix_12540;
			t_sample highSideGainHistoryNext = fixdenorm(highSideGainSmoothed);
			t_sample highSideGainLinear = highSideGainSmoothed;
			t_sample sHighRaw = ((highRightBypassBlend + highInputDiff) * highSideGainLinear);
			t_sample mix_12541 = (((int)1) + (((int)0) * (m_highInvertHistory_39 - ((int)1))));
			t_sample highInvertSmoothed = mix_12541;
			t_sample highInvertHistoryNext = fixdenorm(highInvertSmoothed);
			t_sample highWidthNormalized = ((highWidthSmoothed <= ((int)0)) ? ((int)0) : ((highWidthSmoothed >= ((int)2)) ? ((int)2) : highWidthSmoothed));
			t_sample highWidthHalf = (highWidthNormalized * ((t_sample)0.5));
			t_sample highTheta = (highWidthHalf * ((t_sample)1.2319971190548));
			t_sample highMonoGain = cos(highTheta);
			t_sample highSideGain = sin(highTheta);
			t_sample lHighPre = ((mHighRaw + sHighRaw) * ((t_sample)0.5));
			t_sample rHighPre = ((mHighRaw - sHighRaw) * ((t_sample)0.5));
			m_highLeftEnergyM_47 = fixdenorm((m_highLeftEnergyM_47 + (highRmsAlpha * ((lHighPre * lHighPre) - m_highLeftEnergyM_47))));
			m_highRightEnergyM_46 = fixdenorm((m_highRightEnergyM_46 + (highRmsAlpha * ((rHighPre * rHighPre) - m_highRightEnergyM_46))));
			m_highCrossCorrelationM_40 = fixdenorm((m_highCrossCorrelationM_40 + (highRmsAlpha * ((lHighPre * rHighPre) - m_highCrossCorrelationM_40))));
			m_highEnergyM_42 = fixdenorm((m_highEnergyM_42 + (highRmsAlpha * ((mHighRaw * mHighRaw) - m_highEnergyM_42))));
			m_highSideEnergyM_41 = fixdenorm((m_highSideEnergyM_41 + (highRmsAlpha * ((sHighRaw * sHighRaw) - m_highSideEnergyM_41))));
			t_sample highMatrixA = (((t_sample)0.5) * (highMonoGain + highSideGain));
			t_sample highMatrixB = (((t_sample)0.5) * (highMonoGain - highSideGain));
			t_sample highInputPower = ((m_highLeftEnergyM_47 + m_highRightEnergyM_46) + ((t_sample)1e-12));
			t_sample highOutputPower = (((((highMatrixA * highMatrixA) + (highMatrixB * highMatrixB)) * (m_highLeftEnergyM_47 + m_highRightEnergyM_46)) + (((((int)4) * highMatrixA) * highMatrixB) * m_highCrossCorrelationM_40)) + ((t_sample)1e-12));
			t_sample highNormalizationGain = sqrt(safediv(highInputPower, highOutputPower));
			t_sample highCorrelationNumerator = m_highCrossCorrelationM_40;
			t_sample maxa_271 = (m_highLeftEnergyM_47 * m_highRightEnergyM_46);
			t_sample highCorrelationDenominator = sqrt(((maxa_271 < ((t_sample)1e-12)) ? ((t_sample)1e-12) : maxa_271));
			t_sample v_272 = safediv(highCorrelationNumerator, (highCorrelationDenominator + ((t_sample)1e-12)));
			t_sample highCorrelation = ((v_272 <= ((int)-1)) ? ((int)-1) : ((v_272 >= ((int)1)) ? ((int)1) : v_272));
			t_sample highMonoGainSafe = ((highMonoGain < ((t_sample)0.05)) ? ((t_sample)0.05) : highMonoGain);
			t_sample v_273 = safediv(((int)1), highMonoGainSafe);
			t_sample monoNeedHigh = ((v_273 <= ((t_sample)1.6788040181226)) ? ((t_sample)1.6788040181226) : ((v_273 >= ((t_sample)3.3496543915783)) ? ((t_sample)3.3496543915783) : v_273));
			t_sample highCorrelationPositive = ((highCorrelation < ((int)0)) ? ((int)0) : highCorrelation);
			t_sample boostAllowanceHigh = (((t_sample)1.6788040181226) + ((monoNeedHigh - ((t_sample)1.6788040181226)) * highCorrelationPositive));
			t_sample highNormalizationGain_12413 = ((highNormalizationGain <= ((t_sample)0.59566214352901)) ? ((t_sample)0.59566214352901) : ((highNormalizationGain >= boostAllowanceHigh) ? boostAllowanceHigh : highNormalizationGain));
			t_sample maxb_274 = (highWidthHalf - ((t_sample)0.5));
			t_sample highLiftBase = ((((int)0) < maxb_274) ? maxb_274 : ((int)0));
			t_sample highLiftDb = ((((int)6) * highLiftBase) * (((int)1) - highCorrelation));
			t_sample highNormalizationGain_12414 = (highNormalizationGain_12413 * dbtoa(highLiftDb));
			t_sample highMonoHalf = (mHighRaw * ((t_sample)0.5));
			t_sample highSideHalf = (sHighRaw * ((t_sample)0.5));
			t_sample highMonoScaled = (highMonoHalf * (highMonoGain * highNormalizationGain_12414));
			t_sample highSideScaled = (highSideHalf * (highSideGain * highNormalizationGain_12414));
			t_sample highSidePolarity = (highSideScaled * highInvertSmoothed);
			t_sample highRightPreWidth = (highMonoScaled - highSidePolarity);
			t_sample highLeftPreWidth = (highMonoScaled + highSidePolarity);
			t_sample highLeftBalanced = (highLeftPreWidth * highBalGL);
			t_sample highLeftWithBandGain = (highLeftBalanced * highMakeupLinear);
			t_sample mix_12542 = (highLIn + (highBypassMask * (highLeftWithBandGain - highLIn)));
			t_sample mix_12543 = (muteHigh + (((t_sample)0.999) * (m_muteHighHistory_55 - muteHigh)));
			t_sample muteHighSmoothed = mix_12543;
			m_muteHighHistory_55 = fixdenorm(muteHighSmoothed);
			t_sample highMuteGateRaw = (((int)1) - ((muteHighSmoothed <= ((int)0)) ? ((int)0) : ((muteHighSmoothed >= ((int)1)) ? ((int)1) : muteHighSmoothed)));
			t_sample highLeftMixed_12415 = (mix_12542 * highMuteGateRaw);
			t_sample highRightBalanced = (highRightPreWidth * highBalGR);
			t_sample highRightWithBandGain = (highRightBalanced * highMakeupLinear);
			t_sample mix_12544 = (highRIn + (highBypassMask * (highRightWithBandGain - highRIn)));
			t_sample highRightMixed_12416 = (mix_12544 * highMuteGateRaw);
			t_sample wetMakeupL = makeupLeftNext;
			t_sample wetMakeupR = makeupRightNext;
			t_sample mix_12545 = (highRightMixed_12416 + (soloMaskHigh * (((int)0) - highRightMixed_12416)));
			t_sample wetRightTotal = ((mix_12545 + mix_12528) + mix_12511);
			t_sample mul_12547 = (wetRightTotal * wetMakeupR);
			t_sample mix_12546 = (dryRightSumBands + (dryWetControl * (mul_12547 - dryRightSumBands)));
			t_sample mix_12548 = (in2 + (bypassMask * (mix_12546 - in2)));
			t_sample mix_12549 = (highLeftMixed_12415 + (soloMaskHigh * (((int)0) - highLeftMixed_12415)));
			t_sample wetLeftTotal = ((mix_12549 + mix_12529) + mix_12512);
			t_sample mul_12551 = (wetLeftTotal * wetMakeupL);
			t_sample mix_12550 = (dryLeftSumBands + (dryWetControl * (mul_12551 - dryLeftSumBands)));
			t_sample mix_12552 = (in1 + (bypassMask * (mix_12550 - in1)));
			m_dryWetHistory_185 = dryWetHistoryNext;
			m_bypassHistory_184 = bypassHistoryNext;
			m_soloMidHistory_183 = soloMidHistoryNext;
			m_soloHighHistory_182 = soloHighHistoryNext;
			m_soloLowHistory_181 = soloLowHistoryNext;
			m_inputModeHistory_180 = inputModeHistoryNext;
			m_lowBandGainHistory_179 = lowBandGainHistoryNext;
			m_midBandGainHistory_178 = midBandGainHistoryNext;
			m_midBalanceHistory_177 = midBalanceHistoryNext;
			m_highBandGainHistory_176 = highBandGainHistoryNext;
			m_highBalanceHistory_175 = highBalanceHistoryNext;
			m_highCrossoverHistory_174 = highCrossoverHistoryNext;
			m_lowCrossoverHistory_173 = lowCrossoverHistoryNext;
			m_highMakeupHistory_63 = highMakeupHistoryNext;
			m_highBalanceHistoryInternal_62 = highBalanceHistoryInternalNext;
			m_highWidthHistory_61 = highWidthHistoryNext;
			m_highInputModeHistory_60 = highInputModeHistoryNext;
			m_highBandGainHistoryInternal_59 = highBandGainHistoryInternalNext;
			m_highSideGainHistory_58 = highSideGainHistoryNext;
			m_highInvertHistory_39 = highInvertHistoryNext;
			m_highBypassHistory_64 = highBypassHistoryNext;
			m_midMakeupHistory_71 = midMakeupHistoryNext;
			m_midBalanceInternalHistory_70 = midBalanceInternalHistoryNext;
			m_midWidthHistory_69 = midWidthHistoryNext;
			m_midInputModeHistory_68 = midInputModeHistoryNext;
			m_midBandGainHistoryInternal_67 = midBandGainHistoryInternalNext;
			m_midSideGainHistory_66 = midSideGainHistoryNext;
			m_midInvertHistory_65 = midInvertHistoryNext;
			m_midBypassHistory_72 = midBypassHistoryNext;
			m_lowBalanceHistory_75 = lowBalanceHistoryNext;
			m_lowWidthHistory_74 = lowWidthHistoryNext;
			m_lowInputModeHistory_73 = lowInputModeHistoryNext;
			m_lowBypassHistory_76 = lowBypassHistoryNext;
			m_trimLeftHistory_6 = trimLeftNext;
			m_trimRightHistory_5 = trimRightNext;
			m_trimSharedHistory_2 = trimSharedNext;
			m_makeupLeftHistory_4 = makeupLeftNext;
			m_makeupRightHistory_3 = makeupRightNext;
			m_makeupSharedHistory_1 = makeupSharedNext;
			t_sample out3 = expr_12419;
			t_sample out1 = mix_12552;
			t_sample out2 = mix_12548;
			t_sample out4 = expr_12420;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			(*(__out4++)) = out4;
			
		};
		return __exception;
		
	};
	inline void set_w_MAKEUP(t_param _value) {
		m_w_MAKEUP_218 = (_value < -12 ? -12 : (_value > 12 ? 12 : _value));
	};
	inline void set_v_TRIM(t_param _value) {
		m_v_TRIM_219 = (_value < -12 ? -12 : (_value > 12 ? 12 : _value));
	};
	inline void set_p_MUTHIGH(t_param _value) {
		m_p_MUTHIGH_220 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_o_MUTMED(t_param _value) {
		m_o_MUTMED_221 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_n_MUTLOW(t_param _value) {
		m_n_MUTLOW_222 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_x_DRYWET(t_param _value) {
		m_x_DRYWET_223 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_m_HIGH_bal(t_param _value) {
		m_m_HIGH_bal_224 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_l_MED_bal(t_param _value) {
		m_l_MED_bal_225 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_k_LOW_bal(t_param _value) {
		m_k_LOW_bal_226 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_j_input(t_param _value) {
		m_j_input_227 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_i_BYPASS(t_param _value) {
		m_i_BYPASS_228 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_h_SOLOHIGH(t_param _value) {
		m_h_SOLOHIGH_229 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_g_SOLOMED(t_param _value) {
		m_g_SOLOMED_230 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_f_SOLOLOW(t_param _value) {
		m_f_SOLOLOW_231 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_e_HIGH(t_param _value) {
		m_e_HIGH_232 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_d_MED(t_param _value) {
		m_d_MED_233 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_c_LOW(t_param _value) {
		m_c_LOW_234 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_b_FREQ2(t_param _value) {
		m_b_FREQ_235 = (_value < 1000 ? 1000 : (_value > 20000 ? 20000 : _value));
	};
	inline void set_a_FREQ1(t_param _value) {
		m_a_FREQ_236 = (_value < 20 ? 20 : (_value > 1000 ? 1000 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 4;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 19; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2", "out3", "out4" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_a_FREQ1(value); break;
		case 1: self->set_b_FREQ2(value); break;
		case 2: self->set_c_LOW(value); break;
		case 3: self->set_d_MED(value); break;
		case 4: self->set_e_HIGH(value); break;
		case 5: self->set_f_SOLOLOW(value); break;
		case 6: self->set_g_SOLOMED(value); break;
		case 7: self->set_h_SOLOHIGH(value); break;
		case 8: self->set_i_BYPASS(value); break;
		case 9: self->set_j_input(value); break;
		case 10: self->set_k_LOW_bal(value); break;
		case 11: self->set_l_MED_bal(value); break;
		case 12: self->set_m_HIGH_bal(value); break;
		case 13: self->set_n_MUTLOW(value); break;
		case 14: self->set_o_MUTMED(value); break;
		case 15: self->set_p_MUTHIGH(value); break;
		case 16: self->set_v_TRIM(value); break;
		case 17: self->set_w_MAKEUP(value); break;
		case 18: self->set_x_DRYWET(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_a_FREQ_236; break;
		case 1: *value = self->m_b_FREQ_235; break;
		case 2: *value = self->m_c_LOW_234; break;
		case 3: *value = self->m_d_MED_233; break;
		case 4: *value = self->m_e_HIGH_232; break;
		case 5: *value = self->m_f_SOLOLOW_231; break;
		case 6: *value = self->m_g_SOLOMED_230; break;
		case 7: *value = self->m_h_SOLOHIGH_229; break;
		case 8: *value = self->m_i_BYPASS_228; break;
		case 9: *value = self->m_j_input_227; break;
		case 10: *value = self->m_k_LOW_bal_226; break;
		case 11: *value = self->m_l_MED_bal_225; break;
		case 12: *value = self->m_m_HIGH_bal_224; break;
		case 13: *value = self->m_n_MUTLOW_222; break;
		case 14: *value = self->m_o_MUTMED_221; break;
		case 15: *value = self->m_p_MUTHIGH_220; break;
		case 16: *value = self->m_v_TRIM_219; break;
		case 17: *value = self->m_w_MAKEUP_218; break;
		case 18: *value = self->m_x_DRYWET_223; break;
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(19 * sizeof(ParamInfo));
	self->__commonstate.numparams = 19;
	// initialize parameter 0 ("m_a_FREQ_236")
	pi = self->__commonstate.params + 0;
	pi->name = "a_FREQ1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_a_FREQ_236;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 20;
	pi->outputmax = 1000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_b_FREQ_235")
	pi = self->__commonstate.params + 1;
	pi->name = "b_FREQ2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_b_FREQ_235;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1000;
	pi->outputmax = 20000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_c_LOW_234")
	pi = self->__commonstate.params + 2;
	pi->name = "c_LOW";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_c_LOW_234;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_d_MED_233")
	pi = self->__commonstate.params + 3;
	pi->name = "d_MED";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d_MED_233;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_e_HIGH_232")
	pi = self->__commonstate.params + 4;
	pi->name = "e_HIGH";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_e_HIGH_232;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_f_SOLOLOW_231")
	pi = self->__commonstate.params + 5;
	pi->name = "f_SOLOLOW";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_f_SOLOLOW_231;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_g_SOLOMED_230")
	pi = self->__commonstate.params + 6;
	pi->name = "g_SOLOMED";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_g_SOLOMED_230;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_h_SOLOHIGH_229")
	pi = self->__commonstate.params + 7;
	pi->name = "h_SOLOHIGH";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_h_SOLOHIGH_229;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_i_BYPASS_228")
	pi = self->__commonstate.params + 8;
	pi->name = "i_BYPASS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_i_BYPASS_228;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_j_input_227")
	pi = self->__commonstate.params + 9;
	pi->name = "j_input";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_j_input_227;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_k_LOW_bal_226")
	pi = self->__commonstate.params + 10;
	pi->name = "k_LOW_bal";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_k_LOW_bal_226;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_l_MED_bal_225")
	pi = self->__commonstate.params + 11;
	pi->name = "l_MED_bal";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_l_MED_bal_225;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_m_HIGH_bal_224")
	pi = self->__commonstate.params + 12;
	pi->name = "m_HIGH_bal";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_m_HIGH_bal_224;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_n_MUTLOW_222")
	pi = self->__commonstate.params + 13;
	pi->name = "n_MUTLOW";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_n_MUTLOW_222;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_o_MUTMED_221")
	pi = self->__commonstate.params + 14;
	pi->name = "o_MUTMED";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_o_MUTMED_221;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_p_MUTHIGH_220")
	pi = self->__commonstate.params + 15;
	pi->name = "p_MUTHIGH";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_p_MUTHIGH_220;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 16 ("m_v_TRIM_219")
	pi = self->__commonstate.params + 16;
	pi->name = "v_TRIM";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_v_TRIM_219;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -12;
	pi->outputmax = 12;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_w_MAKEUP_218")
	pi = self->__commonstate.params + 17;
	pi->name = "w_MAKEUP";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_w_MAKEUP_218;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -12;
	pi->outputmax = 12;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_x_DRYWET_223")
	pi = self->__commonstate.params + 18;
	pi->name = "x_DRYWET";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_x_DRYWET_223;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // JCBImager::
