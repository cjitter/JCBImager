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
	t_sample m_m1_x_156;
	t_sample m_h2_y_157;
	t_sample m_h2_y_158;
	t_sample m_h2_x_159;
	t_sample m_m1_x_155;
	t_sample m_h2_x_160;
	t_sample m_m1_y_154;
	t_sample m_m2_x_152;
	t_sample m_m2_y_149;
	t_sample m_m1_y_153;
	t_sample m_m2_y_150;
	t_sample m_m2_x_151;
	t_sample m_h1_y_161;
	t_sample m_h1_y_162;
	t_sample m_h1_x_163;
	t_sample m_l1_x_171;
	t_sample m_l1_y_170;
	t_sample m_l1_x_172;
	t_sample m_history_174;
	t_sample m_history_173;
	t_sample m_u1_x_148;
	t_sample m_l1_y_169;
	t_sample m_l2_x_167;
	t_sample m_h1_x_164;
	t_sample m_l2_x_168;
	t_sample m_l2_y_165;
	t_sample m_l2_y_166;
	t_sample m_u1_x_147;
	t_sample m_u1_y_146;
	t_sample m_u1_y_145;
	t_sample m_ap_low_hp2_y_126;
	t_sample m_ap_low_hp2_y_125;
	t_sample m_ap_low_hp2_x_127;
	t_sample m_ap_low_hp1_y_129;
	t_sample m_ap_low_hp2_x_128;
	t_sample m_ap_low_hp1_y_130;
	t_sample m_l1_x_124;
	t_sample m_l1_y_122;
	t_sample m_l2_x_119;
	t_sample m_l1_x_123;
	t_sample m_l2_x_120;
	t_sample m_l1_y_121;
	t_sample m_history_175;
	t_sample m_ap_low_hp1_x_131;
	t_sample m_ap_low_lp2_y_133;
	t_sample m_u2_y_141;
	t_sample m_ap_low_lp1_x_140;
	t_sample m_u2_y_142;
	t_sample m_u2_x_144;
	t_sample m_u2_x_143;
	t_sample m_ap_low_hp1_x_132;
	t_sample m_ap_low_lp1_x_139;
	t_sample m_ap_low_lp1_y_137;
	t_sample m_ap_low_lp2_y_134;
	t_sample m_ap_low_lp1_y_138;
	t_sample m_ap_low_lp2_x_135;
	t_sample m_ap_low_lp2_x_136;
	t_sample m_history_176;
	t_sample m_history_177;
	t_sample m_history_178;
	t_sample m_ap1_lp1_x_216;
	t_sample m_ap1_lp1_y_215;
	t_sample m_ap1_lp1_x_217;
	t_sample m_v_TRIM_219;
	t_sample m_w_MAKEUP_218;
	t_sample m_p_MUTHIGH_220;
	t_sample m_ap1_lp1_y_214;
	t_sample m_ap1_lp2_x_212;
	t_sample m_ap1_hp1_x_209;
	t_sample m_ap1_lp2_x_213;
	t_sample m_ap1_lp2_y_210;
	t_sample m_ap1_lp2_y_211;
	t_sample m_ap1_hp1_x_208;
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
	t_sample m_l2_y_118;
	t_sample m_ap1_hp1_y_207;
	t_sample m_ap1_hp2_x_205;
	t_sample m_ap2_hp2_y_186;
	t_sample m_history_185;
	t_sample m_ap2_hp2_y_187;
	t_sample m_ap2_hp2_x_189;
	t_sample m_ap2_hp2_x_188;
	t_sample m_ap2_hp1_y_190;
	t_sample m_history_184;
	t_sample m_history_182;
	t_sample m_history_179;
	t_sample m_history_183;
	t_sample m_history_180;
	t_sample m_history_181;
	t_sample m_ap1_hp1_y_206;
	t_sample m_ap2_hp1_y_191;
	t_sample m_ap2_hp1_x_193;
	t_sample m_ap2_lp1_x_201;
	t_sample m_ap2_lp1_x_200;
	t_sample m_ap1_hp2_y_202;
	t_sample m_ap1_hp2_x_204;
	t_sample m_ap1_hp2_y_203;
	t_sample m_ap2_hp1_x_192;
	t_sample m_ap2_lp1_y_199;
	t_sample m_ap2_lp2_x_197;
	t_sample m_ap2_lp2_y_194;
	t_sample m_ap2_lp1_y_198;
	t_sample m_ap2_lp2_y_195;
	t_sample m_ap2_lp2_x_196;
	t_sample m_b_FREQ_235;
	t_sample m_l2_y_117;
	t_sample m_h1_x_115;
	t_sample m_ap1_lp1_x_37;
	t_sample m_ap1_lp1_y_36;
	t_sample m_ap1_lp1_x_38;
	t_sample m_high_CCS_40;
	t_sample m_history_39;
	t_sample m_high_ES_41;
	t_sample m_ap1_lp1_y_35;
	t_sample m_ap1_lp2_x_33;
	t_sample m_ap1_hp1_x_30;
	t_sample m_ap1_lp2_x_34;
	t_sample m_ap1_lp2_y_31;
	t_sample m_ap1_lp2_y_32;
	t_sample m_ap1_hp1_x_29;
	t_sample m_high_EM_42;
	t_sample m_mid_ES_44;
	t_sample m_low_CCS_52;
	t_sample m_low_EL_51;
	t_sample m_low_ES_53;
	t_sample m_mute_high_h_55;
	t_sample m_low_EM_54;
	t_sample m_mid_CCS_43;
	t_sample m_low_ER_50;
	t_sample m_mid_ER_48;
	t_sample m_mid_EM_45;
	t_sample m_mid_EL_49;
	t_sample m_high_ER_46;
	t_sample m_high_EL_47;
	t_sample m_mute_mid_h_56;
	t_sample m_ap1_hp1_y_28;
	t_sample m_ap1_hp2_x_26;
	t_sample m_ap2_hp2_y_7;
	t_sample m_w_trimL_6;
	t_sample m_ap2_hp2_y_8;
	t_sample m_ap2_hp2_x_10;
	t_sample m_ap2_hp2_x_9;
	t_sample m_ap2_hp1_y_11;
	t_sample m_w_trimR_5;
	t_sample m_w_muR_3;
	t_sample samplerate;
	t_sample m_w_muL_4;
	t_sample m_w_muS_1;
	t_sample m_w_trimS_2;
	t_sample m_ap1_hp1_y_27;
	t_sample m_ap2_hp1_y_12;
	t_sample m_ap2_hp1_x_14;
	t_sample m_ap2_lp1_x_22;
	t_sample m_ap2_lp1_x_21;
	t_sample m_ap1_hp2_y_23;
	t_sample m_ap1_hp2_x_25;
	t_sample m_ap1_hp2_y_24;
	t_sample m_ap2_hp1_x_13;
	t_sample m_ap2_lp1_y_20;
	t_sample m_ap2_lp2_x_18;
	t_sample m_ap2_lp2_y_15;
	t_sample m_ap2_lp1_y_19;
	t_sample m_ap2_lp2_y_16;
	t_sample m_ap2_lp2_x_17;
	t_sample m_h1_x_116;
	t_sample m_mute_low_h_57;
	t_sample m_history_59;
	t_sample m_u2_x_96;
	t_sample m_u2_x_95;
	t_sample m_u1_y_97;
	t_sample m_u1_x_99;
	t_sample m_u1_y_98;
	t_sample m_u1_x_100;
	t_sample m_u2_y_94;
	t_sample m_ap_low_lp1_x_92;
	t_sample m_ap_low_lp1_y_89;
	t_sample m_u2_y_93;
	t_sample m_ap_low_lp1_y_90;
	t_sample m_ap_low_lp1_x_91;
	t_sample m_ap_low_lp2_x_88;
	t_sample m_m2_y_101;
	t_sample m_m2_x_103;
	t_sample m_h2_x_111;
	t_sample m_h2_y_110;
	t_sample m_h2_x_112;
	t_sample m_h1_y_114;
	t_sample m_h1_y_113;
	t_sample m_m2_y_102;
	t_sample m_h2_y_109;
	t_sample m_m1_x_107;
	t_sample m_m2_x_104;
	t_sample m_m1_x_108;
	t_sample m_m1_y_105;
	t_sample m_m1_y_106;
	t_sample m_history_58;
	t_sample m_ap_low_lp2_x_87;
	t_sample m_ap_low_lp2_y_85;
	t_sample m_history_67;
	t_sample m_history_66;
	t_sample m_history_68;
	t_sample m_history_70;
	t_sample m_history_69;
	t_sample m_history_71;
	t_sample m_history_65;
	t_sample m_history_63;
	t_sample m_history_60;
	t_sample m_history_64;
	t_sample m_history_61;
	t_sample m_history_62;
	t_sample m_ap_low_lp2_y_86;
	t_sample m_history_72;
	t_sample m_history_74;
	t_sample m_ap_low_hp1_y_82;
	t_sample m_ap_low_hp1_y_81;
	t_sample m_ap_low_hp1_x_83;
	t_sample m_ap_low_hp1_x_84;
	t_sample m_history_73;
	t_sample m_ap_low_hp2_x_80;
	t_sample m_ap_low_hp2_y_78;
	t_sample m_history_75;
	t_sample m_ap_low_hp2_x_79;
	t_sample m_history_76;
	t_sample m_ap_low_hp2_y_77;
	t_sample m_a_FREQ_236;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_w_muS_1 = ((int)1);
		m_w_trimS_2 = ((int)1);
		m_w_muR_3 = ((int)1);
		m_w_muL_4 = ((int)1);
		m_w_trimR_5 = ((int)1);
		m_w_trimL_6 = ((int)1);
		m_ap2_hp2_y_7 = ((int)0);
		m_ap2_hp2_y_8 = ((int)0);
		m_ap2_hp2_x_9 = ((int)0);
		m_ap2_hp2_x_10 = ((int)0);
		m_ap2_hp1_y_11 = ((int)0);
		m_ap2_hp1_y_12 = ((int)0);
		m_ap2_hp1_x_13 = ((int)0);
		m_ap2_hp1_x_14 = ((int)0);
		m_ap2_lp2_y_15 = ((int)0);
		m_ap2_lp2_y_16 = ((int)0);
		m_ap2_lp2_x_17 = ((int)0);
		m_ap2_lp2_x_18 = ((int)0);
		m_ap2_lp1_y_19 = ((int)0);
		m_ap2_lp1_y_20 = ((int)0);
		m_ap2_lp1_x_21 = ((int)0);
		m_ap2_lp1_x_22 = ((int)0);
		m_ap1_hp2_y_23 = ((int)0);
		m_ap1_hp2_y_24 = ((int)0);
		m_ap1_hp2_x_25 = ((int)0);
		m_ap1_hp2_x_26 = ((int)0);
		m_ap1_hp1_y_27 = ((int)0);
		m_ap1_hp1_y_28 = ((int)0);
		m_ap1_hp1_x_29 = ((int)0);
		m_ap1_hp1_x_30 = ((int)0);
		m_ap1_lp2_y_31 = ((int)0);
		m_ap1_lp2_y_32 = ((int)0);
		m_ap1_lp2_x_33 = ((int)0);
		m_ap1_lp2_x_34 = ((int)0);
		m_ap1_lp1_y_35 = ((int)0);
		m_ap1_lp1_y_36 = ((int)0);
		m_ap1_lp1_x_37 = ((int)0);
		m_ap1_lp1_x_38 = ((int)0);
		m_history_39 = ((int)0);
		m_high_CCS_40 = ((int)0);
		m_high_ES_41 = ((t_sample)1e-12);
		m_high_EM_42 = ((t_sample)1e-12);
		m_mid_CCS_43 = ((int)0);
		m_mid_ES_44 = ((t_sample)1e-12);
		m_mid_EM_45 = ((t_sample)1e-12);
		m_high_ER_46 = ((t_sample)1e-12);
		m_high_EL_47 = ((t_sample)1e-12);
		m_mid_ER_48 = ((t_sample)1e-12);
		m_mid_EL_49 = ((t_sample)1e-12);
		m_low_ER_50 = ((t_sample)1e-12);
		m_low_EL_51 = ((t_sample)1e-12);
		m_low_CCS_52 = ((int)0);
		m_low_ES_53 = ((t_sample)1e-12);
		m_low_EM_54 = ((t_sample)1e-12);
		m_mute_high_h_55 = ((int)0);
		m_mute_mid_h_56 = ((int)0);
		m_mute_low_h_57 = ((int)0);
		m_history_58 = ((int)0);
		m_history_59 = ((int)0);
		m_history_60 = ((int)0);
		m_history_61 = ((int)0);
		m_history_62 = ((int)0);
		m_history_63 = ((int)0);
		m_history_64 = ((int)0);
		m_history_65 = ((int)0);
		m_history_66 = ((int)0);
		m_history_67 = ((int)0);
		m_history_68 = ((int)0);
		m_history_69 = ((int)0);
		m_history_70 = ((int)0);
		m_history_71 = ((int)0);
		m_history_72 = ((int)0);
		m_history_73 = ((int)0);
		m_history_74 = ((int)0);
		m_history_75 = ((int)0);
		m_history_76 = ((int)0);
		m_ap_low_hp2_y_77 = ((int)0);
		m_ap_low_hp2_y_78 = ((int)0);
		m_ap_low_hp2_x_79 = ((int)0);
		m_ap_low_hp2_x_80 = ((int)0);
		m_ap_low_hp1_y_81 = ((int)0);
		m_ap_low_hp1_y_82 = ((int)0);
		m_ap_low_hp1_x_83 = ((int)0);
		m_ap_low_hp1_x_84 = ((int)0);
		m_ap_low_lp2_y_85 = ((int)0);
		m_ap_low_lp2_y_86 = ((int)0);
		m_ap_low_lp2_x_87 = ((int)0);
		m_ap_low_lp2_x_88 = ((int)0);
		m_ap_low_lp1_y_89 = ((int)0);
		m_ap_low_lp1_y_90 = ((int)0);
		m_ap_low_lp1_x_91 = ((int)0);
		m_ap_low_lp1_x_92 = ((int)0);
		m_u2_y_93 = ((int)0);
		m_u2_y_94 = ((int)0);
		m_u2_x_95 = ((int)0);
		m_u2_x_96 = ((int)0);
		m_u1_y_97 = ((int)0);
		m_u1_y_98 = ((int)0);
		m_u1_x_99 = ((int)0);
		m_u1_x_100 = ((int)0);
		m_m2_y_101 = ((int)0);
		m_m2_y_102 = ((int)0);
		m_m2_x_103 = ((int)0);
		m_m2_x_104 = ((int)0);
		m_m1_y_105 = ((int)0);
		m_m1_y_106 = ((int)0);
		m_m1_x_107 = ((int)0);
		m_m1_x_108 = ((int)0);
		m_h2_y_109 = ((int)0);
		m_h2_y_110 = ((int)0);
		m_h2_x_111 = ((int)0);
		m_h2_x_112 = ((int)0);
		m_h1_y_113 = ((int)0);
		m_h1_y_114 = ((int)0);
		m_h1_x_115 = ((int)0);
		m_h1_x_116 = ((int)0);
		m_l2_y_117 = ((int)0);
		m_l2_y_118 = ((int)0);
		m_l2_x_119 = ((int)0);
		m_l2_x_120 = ((int)0);
		m_l1_y_121 = ((int)0);
		m_l1_y_122 = ((int)0);
		m_l1_x_123 = ((int)0);
		m_l1_x_124 = ((int)0);
		m_ap_low_hp2_y_125 = ((int)0);
		m_ap_low_hp2_y_126 = ((int)0);
		m_ap_low_hp2_x_127 = ((int)0);
		m_ap_low_hp2_x_128 = ((int)0);
		m_ap_low_hp1_y_129 = ((int)0);
		m_ap_low_hp1_y_130 = ((int)0);
		m_ap_low_hp1_x_131 = ((int)0);
		m_ap_low_hp1_x_132 = ((int)0);
		m_ap_low_lp2_y_133 = ((int)0);
		m_ap_low_lp2_y_134 = ((int)0);
		m_ap_low_lp2_x_135 = ((int)0);
		m_ap_low_lp2_x_136 = ((int)0);
		m_ap_low_lp1_y_137 = ((int)0);
		m_ap_low_lp1_y_138 = ((int)0);
		m_ap_low_lp1_x_139 = ((int)0);
		m_ap_low_lp1_x_140 = ((int)0);
		m_u2_y_141 = ((int)0);
		m_u2_y_142 = ((int)0);
		m_u2_x_143 = ((int)0);
		m_u2_x_144 = ((int)0);
		m_u1_y_145 = ((int)0);
		m_u1_y_146 = ((int)0);
		m_u1_x_147 = ((int)0);
		m_u1_x_148 = ((int)0);
		m_m2_y_149 = ((int)0);
		m_m2_y_150 = ((int)0);
		m_m2_x_151 = ((int)0);
		m_m2_x_152 = ((int)0);
		m_m1_y_153 = ((int)0);
		m_m1_y_154 = ((int)0);
		m_m1_x_155 = ((int)0);
		m_m1_x_156 = ((int)0);
		m_h2_y_157 = ((int)0);
		m_h2_y_158 = ((int)0);
		m_h2_x_159 = ((int)0);
		m_h2_x_160 = ((int)0);
		m_h1_y_161 = ((int)0);
		m_h1_y_162 = ((int)0);
		m_h1_x_163 = ((int)0);
		m_h1_x_164 = ((int)0);
		m_l2_y_165 = ((int)0);
		m_l2_y_166 = ((int)0);
		m_l2_x_167 = ((int)0);
		m_l2_x_168 = ((int)0);
		m_l1_y_169 = ((int)0);
		m_l1_y_170 = ((int)0);
		m_l1_x_171 = ((int)0);
		m_l1_x_172 = ((int)0);
		m_history_173 = ((int)0);
		m_history_174 = ((int)0);
		m_history_175 = ((int)0);
		m_history_176 = ((int)0);
		m_history_177 = ((int)0);
		m_history_178 = ((int)0);
		m_history_179 = ((int)0);
		m_history_180 = ((int)0);
		m_history_181 = ((int)0);
		m_history_182 = ((int)0);
		m_history_183 = ((int)0);
		m_history_184 = ((int)0);
		m_history_185 = ((int)0);
		m_ap2_hp2_y_186 = ((int)0);
		m_ap2_hp2_y_187 = ((int)0);
		m_ap2_hp2_x_188 = ((int)0);
		m_ap2_hp2_x_189 = ((int)0);
		m_ap2_hp1_y_190 = ((int)0);
		m_ap2_hp1_y_191 = ((int)0);
		m_ap2_hp1_x_192 = ((int)0);
		m_ap2_hp1_x_193 = ((int)0);
		m_ap2_lp2_y_194 = ((int)0);
		m_ap2_lp2_y_195 = ((int)0);
		m_ap2_lp2_x_196 = ((int)0);
		m_ap2_lp2_x_197 = ((int)0);
		m_ap2_lp1_y_198 = ((int)0);
		m_ap2_lp1_y_199 = ((int)0);
		m_ap2_lp1_x_200 = ((int)0);
		m_ap2_lp1_x_201 = ((int)0);
		m_ap1_hp2_y_202 = ((int)0);
		m_ap1_hp2_y_203 = ((int)0);
		m_ap1_hp2_x_204 = ((int)0);
		m_ap1_hp2_x_205 = ((int)0);
		m_ap1_hp1_y_206 = ((int)0);
		m_ap1_hp1_y_207 = ((int)0);
		m_ap1_hp1_x_208 = ((int)0);
		m_ap1_hp1_x_209 = ((int)0);
		m_ap1_lp2_y_210 = ((int)0);
		m_ap1_lp2_y_211 = ((int)0);
		m_ap1_lp2_x_212 = ((int)0);
		m_ap1_lp2_x_213 = ((int)0);
		m_ap1_lp1_y_214 = ((int)0);
		m_ap1_lp1_y_215 = ((int)0);
		m_ap1_lp1_x_216 = ((int)0);
		m_ap1_lp1_x_217 = ((int)0);
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
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
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
			t_sample w_trim_tgt = dbtoa(trimDb);
			t_sample w_trimS_next = fixdenorm(((((t_sample)0.999) * m_w_trimS_2) + (((t_sample)0.001) * w_trim_tgt)));
			t_sample w_trimL_next = w_trimS_next;
			t_sample w_trimR_next = w_trimS_next;
			t_sample w_mu_tgt = dbtoa(makeupDb);
			t_sample w_muS_next = fixdenorm(((((t_sample)0.999) * m_w_muS_1) + (((t_sample)0.001) * w_mu_tgt)));
			t_sample w_muL_next = w_muS_next;
			t_sample w_muR_next = w_muS_next;
			t_sample wetInL = (in1 * w_trimL_next);
			t_sample wetInR = (in2 * w_trimR_next);
			t_sample expr_10036 = wetInL;
			t_sample expr_10037 = wetInR;
			t_sample xoverLow = ((freqLowHz <= ((int)20)) ? ((int)20) : ((freqLowHz >= ((int)1000)) ? ((int)1000) : freqLowHz));
			t_sample xoverHigh = ((freqHighHz <= ((int)1000)) ? ((int)1000) : ((freqHighHz >= ((int)20000)) ? ((int)20000) : freqHighHz));
			t_sample wetRIn = wetInR;
			int sr = samplerate;
			t_sample minb_237 = (((t_sample)0.45) * sr);
			t_sample maxb_238 = ((minb_237 < xoverLow) ? minb_237 : xoverLow);
			t_sample loF = ((((int)10) < maxb_238) ? maxb_238 : ((int)10));
			t_sample minb_239 = (((t_sample)0.45) * sr);
			t_sample maxb_240 = ((minb_239 < xoverHigh) ? minb_239 : xoverHigh);
			t_sample hiFr = ((((int)10) < maxb_240) ? maxb_240 : ((int)10));
			t_sample maxb_241 = (loF + ((int)1));
			t_sample hiF = ((hiFr < maxb_241) ? maxb_241 : hiFr);
			t_sample w0_lo = safediv((((t_sample)6.2831853071796) * loF), sr);
			t_sample cos_lo = cos(w0_lo);
			t_sample sin_lo = sin(w0_lo);
			t_sample alpha_lo = (sin_lo * ((t_sample)0.70710678118655));
			t_sample a0_lo = (((int)1) + alpha_lo);
			t_sample a1_lo = (((int)-2) * cos_lo);
			t_sample a2_lo = (((int)1) - alpha_lo);
			t_sample lp_b0_l = safediv(((((int)1) - cos_lo) * ((t_sample)0.5)), a0_lo);
			t_sample lp_b1_l = safediv((((int)1) - cos_lo), a0_lo);
			t_sample lp_b2_l = lp_b0_l;
			t_sample lp_a1_l = safediv(a1_lo, a0_lo);
			t_sample lp_a2_l = safediv(a2_lo, a0_lo);
			t_sample hp_b0_l = safediv(((((int)1) + cos_lo) * ((t_sample)0.5)), a0_lo);
			t_sample hp_b1_l = safediv((-(((int)1) + cos_lo)), a0_lo);
			t_sample hp_b2_l = hp_b0_l;
			t_sample hp_a1_l = lp_a1_l;
			t_sample hp_a2_l = lp_a2_l;
			t_sample w0_hi = safediv((((t_sample)6.2831853071796) * hiF), sr);
			t_sample cos_hi = cos(w0_hi);
			t_sample sin_hi = sin(w0_hi);
			t_sample alpha_hi = (sin_hi * ((t_sample)0.70710678118655));
			t_sample a0_hi = (((int)1) + alpha_hi);
			t_sample a1_hi = (((int)-2) * cos_hi);
			t_sample a2_hi = (((int)1) - alpha_hi);
			t_sample lp_b0_h = safediv(((((int)1) - cos_hi) * ((t_sample)0.5)), a0_hi);
			t_sample lp_b1_h = safediv((((int)1) - cos_hi), a0_hi);
			t_sample lp_b2_h = lp_b0_h;
			t_sample lp_a1_h = safediv(a1_hi, a0_hi);
			t_sample lp_a2_h = safediv(a2_hi, a0_hi);
			t_sample hp_b0_h = safediv(((((int)1) + cos_hi) * ((t_sample)0.5)), a0_hi);
			t_sample hp_b1_h = safediv((-(((int)1) + cos_hi)), a0_hi);
			t_sample hp_b2_h = hp_b0_h;
			t_sample hp_a1_h = lp_a1_h;
			t_sample hp_a2_h = lp_a2_h;
			t_sample ap1_lp1_x1p = m_ap1_lp1_x_217;
			t_sample ap1_lp1_x2p = m_ap1_lp1_x_216;
			t_sample ap1_lp1_y1p = m_ap1_lp1_y_215;
			t_sample ap1_lp1_y2p = m_ap1_lp1_y_214;
			t_sample ap1_lp_s1 = (((((lp_b0_l * wetRIn) + (lp_b1_l * ap1_lp1_x1p)) + (lp_b2_l * ap1_lp1_x2p)) - (lp_a1_l * ap1_lp1_y1p)) - (lp_a2_l * ap1_lp1_y2p));
			m_ap1_lp1_x_216 = ap1_lp1_x1p;
			m_ap1_lp1_x_217 = wetRIn;
			m_ap1_lp1_y_214 = ap1_lp1_y1p;
			m_ap1_lp1_y_215 = ap1_lp_s1;
			t_sample ap1_lp2_x1p = m_ap1_lp2_x_213;
			t_sample ap1_lp2_x2p = m_ap1_lp2_x_212;
			t_sample ap1_lp2_y1p = m_ap1_lp2_y_211;
			t_sample ap1_lp2_y2p = m_ap1_lp2_y_210;
			t_sample ap1_lp = (((((lp_b0_l * ap1_lp_s1) + (lp_b1_l * ap1_lp2_x1p)) + (lp_b2_l * ap1_lp2_x2p)) - (lp_a1_l * ap1_lp2_y1p)) - (lp_a2_l * ap1_lp2_y2p));
			m_ap1_lp2_x_212 = ap1_lp2_x1p;
			m_ap1_lp2_x_213 = ap1_lp_s1;
			m_ap1_lp2_y_210 = ap1_lp2_y1p;
			m_ap1_lp2_y_211 = ap1_lp;
			t_sample ap1_hp1_x1p = m_ap1_hp1_x_209;
			t_sample ap1_hp1_x2p = m_ap1_hp1_x_208;
			t_sample ap1_hp1_y1p = m_ap1_hp1_y_207;
			t_sample ap1_hp1_y2p = m_ap1_hp1_y_206;
			t_sample ap1_hp_s1 = (((((hp_b0_l * wetRIn) + (hp_b1_l * ap1_hp1_x1p)) + (hp_b2_l * ap1_hp1_x2p)) - (hp_a1_l * ap1_hp1_y1p)) - (hp_a2_l * ap1_hp1_y2p));
			m_ap1_hp1_x_208 = ap1_hp1_x1p;
			m_ap1_hp1_x_209 = wetRIn;
			m_ap1_hp1_y_206 = ap1_hp1_y1p;
			m_ap1_hp1_y_207 = ap1_hp_s1;
			t_sample ap1_hp2_x1p = m_ap1_hp2_x_205;
			t_sample ap1_hp2_x2p = m_ap1_hp2_x_204;
			t_sample ap1_hp2_y1p = m_ap1_hp2_y_203;
			t_sample ap1_hp2_y2p = m_ap1_hp2_y_202;
			t_sample ap1_hp = (((((hp_b0_l * ap1_hp_s1) + (hp_b1_l * ap1_hp2_x1p)) + (hp_b2_l * ap1_hp2_x2p)) - (hp_a1_l * ap1_hp2_y1p)) - (hp_a2_l * ap1_hp2_y2p));
			m_ap1_hp2_x_204 = ap1_hp2_x1p;
			m_ap1_hp2_x_205 = ap1_hp_s1;
			m_ap1_hp2_y_202 = ap1_hp2_y1p;
			m_ap1_hp2_y_203 = ap1_hp;
			t_sample stage1OutR = (ap1_lp + ap1_hp);
			t_sample ap2_lp1_x1p = m_ap2_lp1_x_201;
			t_sample ap2_lp1_x2p = m_ap2_lp1_x_200;
			t_sample ap2_lp1_y1p = m_ap2_lp1_y_199;
			t_sample ap2_lp1_y2p = m_ap2_lp1_y_198;
			t_sample ap2_lp_s1 = (((((lp_b0_h * stage1OutR) + (lp_b1_h * ap2_lp1_x1p)) + (lp_b2_h * ap2_lp1_x2p)) - (lp_a1_h * ap2_lp1_y1p)) - (lp_a2_h * ap2_lp1_y2p));
			m_ap2_lp1_x_200 = ap2_lp1_x1p;
			m_ap2_lp1_x_201 = stage1OutR;
			m_ap2_lp1_y_198 = ap2_lp1_y1p;
			m_ap2_lp1_y_199 = ap2_lp_s1;
			t_sample ap2_lp2_x1p = m_ap2_lp2_x_197;
			t_sample ap2_lp2_x2p = m_ap2_lp2_x_196;
			t_sample ap2_lp2_y1p = m_ap2_lp2_y_195;
			t_sample ap2_lp2_y2p = m_ap2_lp2_y_194;
			t_sample ap2_lp = (((((lp_b0_h * ap2_lp_s1) + (lp_b1_h * ap2_lp2_x1p)) + (lp_b2_h * ap2_lp2_x2p)) - (lp_a1_h * ap2_lp2_y1p)) - (lp_a2_h * ap2_lp2_y2p));
			m_ap2_lp2_x_196 = ap2_lp2_x1p;
			m_ap2_lp2_x_197 = ap2_lp_s1;
			m_ap2_lp2_y_194 = ap2_lp2_y1p;
			m_ap2_lp2_y_195 = ap2_lp;
			t_sample ap2_hp1_x1p = m_ap2_hp1_x_193;
			t_sample ap2_hp1_x2p = m_ap2_hp1_x_192;
			t_sample ap2_hp1_y1p = m_ap2_hp1_y_191;
			t_sample ap2_hp1_y2p = m_ap2_hp1_y_190;
			t_sample ap2_hp_s1 = (((((hp_b0_h * stage1OutR) + (hp_b1_h * ap2_hp1_x1p)) + (hp_b2_h * ap2_hp1_x2p)) - (hp_a1_h * ap2_hp1_y1p)) - (hp_a2_h * ap2_hp1_y2p));
			m_ap2_hp1_x_192 = ap2_hp1_x1p;
			m_ap2_hp1_x_193 = stage1OutR;
			m_ap2_hp1_y_190 = ap2_hp1_y1p;
			m_ap2_hp1_y_191 = ap2_hp_s1;
			t_sample ap2_hp2_x1p = m_ap2_hp2_x_189;
			t_sample ap2_hp2_x2p = m_ap2_hp2_x_188;
			t_sample ap2_hp2_y1p = m_ap2_hp2_y_187;
			t_sample ap2_hp2_y2p = m_ap2_hp2_y_186;
			t_sample ap2_hp = (((((hp_b0_h * ap2_hp_s1) + (hp_b1_h * ap2_hp2_x1p)) + (hp_b2_h * ap2_hp2_x2p)) - (hp_a1_h * ap2_hp2_y1p)) - (hp_a2_h * ap2_hp2_y2p));
			m_ap2_hp2_x_188 = ap2_hp2_x1p;
			m_ap2_hp2_x_189 = ap2_hp_s1;
			m_ap2_hp2_y_186 = ap2_hp2_y1p;
			m_ap2_hp2_y_187 = ap2_hp;
			t_sample expr_114 = (ap2_lp + ap2_hp);
			t_sample wetLIn = wetInL;
			int sr_116 = samplerate;
			t_sample minb_242 = (((t_sample)0.45) * sr_116);
			t_sample maxb_243 = ((minb_242 < xoverLow) ? minb_242 : xoverLow);
			t_sample loF_117 = ((((int)10) < maxb_243) ? maxb_243 : ((int)10));
			t_sample minb_244 = (((t_sample)0.45) * sr_116);
			t_sample maxb_245 = ((minb_244 < xoverHigh) ? minb_244 : xoverHigh);
			t_sample hiFr_118 = ((((int)10) < maxb_245) ? maxb_245 : ((int)10));
			t_sample maxb_246 = (loF_117 + ((int)1));
			t_sample hiF_119 = ((hiFr_118 < maxb_246) ? maxb_246 : hiFr_118);
			t_sample w0_lo_120 = safediv((((t_sample)6.2831853071796) * loF_117), sr_116);
			t_sample cos_lo_121 = cos(w0_lo_120);
			t_sample sin_lo_122 = sin(w0_lo_120);
			t_sample alpha_lo_123 = (sin_lo_122 * ((t_sample)0.70710678118655));
			t_sample a0_lo_124 = (((int)1) + alpha_lo_123);
			t_sample a1_lo_125 = (((int)-2) * cos_lo_121);
			t_sample a2_lo_126 = (((int)1) - alpha_lo_123);
			t_sample lp_b0_l_127 = safediv(((((int)1) - cos_lo_121) * ((t_sample)0.5)), a0_lo_124);
			t_sample lp_b1_l_128 = safediv((((int)1) - cos_lo_121), a0_lo_124);
			t_sample lp_b2_l_129 = lp_b0_l_127;
			t_sample lp_a1_l_130 = safediv(a1_lo_125, a0_lo_124);
			t_sample lp_a2_l_131 = safediv(a2_lo_126, a0_lo_124);
			t_sample hp_b0_l_132 = safediv(((((int)1) + cos_lo_121) * ((t_sample)0.5)), a0_lo_124);
			t_sample hp_b1_l_133 = safediv((-(((int)1) + cos_lo_121)), a0_lo_124);
			t_sample hp_b2_l_134 = hp_b0_l_132;
			t_sample hp_a1_l_135 = lp_a1_l_130;
			t_sample hp_a2_l_136 = lp_a2_l_131;
			t_sample w0_hi_137 = safediv((((t_sample)6.2831853071796) * hiF_119), sr_116);
			t_sample cos_hi_138 = cos(w0_hi_137);
			t_sample sin_hi_139 = sin(w0_hi_137);
			t_sample alpha_hi_140 = (sin_hi_139 * ((t_sample)0.70710678118655));
			t_sample a0_hi_141 = (((int)1) + alpha_hi_140);
			t_sample a1_hi_142 = (((int)-2) * cos_hi_138);
			t_sample a2_hi_143 = (((int)1) - alpha_hi_140);
			t_sample lp_b0_h_144 = safediv(((((int)1) - cos_hi_138) * ((t_sample)0.5)), a0_hi_141);
			t_sample lp_b1_h_145 = safediv((((int)1) - cos_hi_138), a0_hi_141);
			t_sample lp_b2_h_146 = lp_b0_h_144;
			t_sample lp_a1_h_147 = safediv(a1_hi_142, a0_hi_141);
			t_sample lp_a2_h_148 = safediv(a2_hi_143, a0_hi_141);
			t_sample hp_b0_h_149 = safediv(((((int)1) + cos_hi_138) * ((t_sample)0.5)), a0_hi_141);
			t_sample hp_b1_h_150 = safediv((-(((int)1) + cos_hi_138)), a0_hi_141);
			t_sample hp_b2_h_151 = hp_b0_h_149;
			t_sample hp_a1_h_152 = lp_a1_h_147;
			t_sample hp_a2_h_153 = lp_a2_h_148;
			t_sample ap1_lp1_x1p_154 = m_ap1_lp1_x_38;
			t_sample ap1_lp1_x2p_155 = m_ap1_lp1_x_37;
			t_sample ap1_lp1_y1p_156 = m_ap1_lp1_y_36;
			t_sample ap1_lp1_y2p_157 = m_ap1_lp1_y_35;
			t_sample ap1_lp_s_158 = (((((lp_b0_l_127 * wetLIn) + (lp_b1_l_128 * ap1_lp1_x1p_154)) + (lp_b2_l_129 * ap1_lp1_x2p_155)) - (lp_a1_l_130 * ap1_lp1_y1p_156)) - (lp_a2_l_131 * ap1_lp1_y2p_157));
			m_ap1_lp1_x_37 = ap1_lp1_x1p_154;
			m_ap1_lp1_x_38 = wetLIn;
			m_ap1_lp1_y_35 = ap1_lp1_y1p_156;
			m_ap1_lp1_y_36 = ap1_lp_s_158;
			t_sample ap1_lp2_x1p_159 = m_ap1_lp2_x_34;
			t_sample ap1_lp2_x2p_160 = m_ap1_lp2_x_33;
			t_sample ap1_lp2_y1p_161 = m_ap1_lp2_y_32;
			t_sample ap1_lp2_y2p_162 = m_ap1_lp2_y_31;
			t_sample ap1_lp_163 = (((((lp_b0_l_127 * ap1_lp_s_158) + (lp_b1_l_128 * ap1_lp2_x1p_159)) + (lp_b2_l_129 * ap1_lp2_x2p_160)) - (lp_a1_l_130 * ap1_lp2_y1p_161)) - (lp_a2_l_131 * ap1_lp2_y2p_162));
			m_ap1_lp2_x_33 = ap1_lp2_x1p_159;
			m_ap1_lp2_x_34 = ap1_lp_s_158;
			m_ap1_lp2_y_31 = ap1_lp2_y1p_161;
			m_ap1_lp2_y_32 = ap1_lp_163;
			t_sample ap1_hp1_x1p_164 = m_ap1_hp1_x_30;
			t_sample ap1_hp1_x2p_165 = m_ap1_hp1_x_29;
			t_sample ap1_hp1_y1p_166 = m_ap1_hp1_y_28;
			t_sample ap1_hp1_y2p_167 = m_ap1_hp1_y_27;
			t_sample ap1_hp_s_168 = (((((hp_b0_l_132 * wetLIn) + (hp_b1_l_133 * ap1_hp1_x1p_164)) + (hp_b2_l_134 * ap1_hp1_x2p_165)) - (hp_a1_l_135 * ap1_hp1_y1p_166)) - (hp_a2_l_136 * ap1_hp1_y2p_167));
			m_ap1_hp1_x_29 = ap1_hp1_x1p_164;
			m_ap1_hp1_x_30 = wetLIn;
			m_ap1_hp1_y_27 = ap1_hp1_y1p_166;
			m_ap1_hp1_y_28 = ap1_hp_s_168;
			t_sample ap1_hp2_x1p_169 = m_ap1_hp2_x_26;
			t_sample ap1_hp2_x2p_170 = m_ap1_hp2_x_25;
			t_sample ap1_hp2_y1p_171 = m_ap1_hp2_y_24;
			t_sample ap1_hp2_y2p_172 = m_ap1_hp2_y_23;
			t_sample ap1_hp_173 = (((((hp_b0_l_132 * ap1_hp_s_168) + (hp_b1_l_133 * ap1_hp2_x1p_169)) + (hp_b2_l_134 * ap1_hp2_x2p_170)) - (hp_a1_l_135 * ap1_hp2_y1p_171)) - (hp_a2_l_136 * ap1_hp2_y2p_172));
			m_ap1_hp2_x_25 = ap1_hp2_x1p_169;
			m_ap1_hp2_x_26 = ap1_hp_s_168;
			m_ap1_hp2_y_23 = ap1_hp2_y1p_171;
			m_ap1_hp2_y_24 = ap1_hp_173;
			t_sample stage1OutL = (ap1_lp_163 + ap1_hp_173);
			t_sample ap2_lp1_x1p_175 = m_ap2_lp1_x_22;
			t_sample ap2_lp1_x2p_176 = m_ap2_lp1_x_21;
			t_sample ap2_lp1_y1p_177 = m_ap2_lp1_y_20;
			t_sample ap2_lp1_y2p_178 = m_ap2_lp1_y_19;
			t_sample ap2_lp_s_179 = (((((lp_b0_h_144 * stage1OutL) + (lp_b1_h_145 * ap2_lp1_x1p_175)) + (lp_b2_h_146 * ap2_lp1_x2p_176)) - (lp_a1_h_147 * ap2_lp1_y1p_177)) - (lp_a2_h_148 * ap2_lp1_y2p_178));
			m_ap2_lp1_x_21 = ap2_lp1_x1p_175;
			m_ap2_lp1_x_22 = stage1OutL;
			m_ap2_lp1_y_19 = ap2_lp1_y1p_177;
			m_ap2_lp1_y_20 = ap2_lp_s_179;
			t_sample ap2_lp2_x1p_180 = m_ap2_lp2_x_18;
			t_sample ap2_lp2_x2p_181 = m_ap2_lp2_x_17;
			t_sample ap2_lp2_y1p_182 = m_ap2_lp2_y_16;
			t_sample ap2_lp2_y2p_183 = m_ap2_lp2_y_15;
			t_sample ap2_lp_184 = (((((lp_b0_h_144 * ap2_lp_s_179) + (lp_b1_h_145 * ap2_lp2_x1p_180)) + (lp_b2_h_146 * ap2_lp2_x2p_181)) - (lp_a1_h_147 * ap2_lp2_y1p_182)) - (lp_a2_h_148 * ap2_lp2_y2p_183));
			m_ap2_lp2_x_17 = ap2_lp2_x1p_180;
			m_ap2_lp2_x_18 = ap2_lp_s_179;
			m_ap2_lp2_y_15 = ap2_lp2_y1p_182;
			m_ap2_lp2_y_16 = ap2_lp_184;
			t_sample ap2_hp1_x1p_185 = m_ap2_hp1_x_14;
			t_sample ap2_hp1_x2p_186 = m_ap2_hp1_x_13;
			t_sample ap2_hp1_y1p_187 = m_ap2_hp1_y_12;
			t_sample ap2_hp1_y2p_188 = m_ap2_hp1_y_11;
			t_sample ap2_hp_s_189 = (((((hp_b0_h_149 * stage1OutL) + (hp_b1_h_150 * ap2_hp1_x1p_185)) + (hp_b2_h_151 * ap2_hp1_x2p_186)) - (hp_a1_h_152 * ap2_hp1_y1p_187)) - (hp_a2_h_153 * ap2_hp1_y2p_188));
			m_ap2_hp1_x_13 = ap2_hp1_x1p_185;
			m_ap2_hp1_x_14 = stage1OutL;
			m_ap2_hp1_y_11 = ap2_hp1_y1p_187;
			m_ap2_hp1_y_12 = ap2_hp_s_189;
			t_sample ap2_hp2_x1p_190 = m_ap2_hp2_x_10;
			t_sample ap2_hp2_x2p_191 = m_ap2_hp2_x_9;
			t_sample ap2_hp2_y1p_192 = m_ap2_hp2_y_8;
			t_sample ap2_hp2_y2p_193 = m_ap2_hp2_y_7;
			t_sample ap2_hp_194 = (((((hp_b0_h_149 * ap2_hp_s_189) + (hp_b1_h_150 * ap2_hp2_x1p_190)) + (hp_b2_h_151 * ap2_hp2_x2p_191)) - (hp_a1_h_152 * ap2_hp2_y1p_192)) - (hp_a2_h_153 * ap2_hp2_y2p_193));
			m_ap2_hp2_x_9 = ap2_hp2_x1p_190;
			m_ap2_hp2_x_10 = ap2_hp_s_189;
			m_ap2_hp2_y_7 = ap2_hp2_y1p_192;
			m_ap2_hp2_y_8 = ap2_hp_194;
			t_sample expr_195 = (ap2_lp_184 + ap2_hp_194);
			t_sample mix_10104 = (dryWet + (((t_sample)0.999) * (m_history_185 - dryWet)));
			t_sample mix_197 = mix_10104;
			t_sample gen_198 = mix_197;
			t_sample history_1_next_199 = fixdenorm(mix_197);
			t_sample mix_10105 = (bypass + (((t_sample)0.999) * (m_history_184 - bypass)));
			t_sample mix_201 = mix_10105;
			t_sample gen_202 = mix_201;
			t_sample history_2_next_203 = fixdenorm(mix_201);
			t_sample rsub_204 = (((int)1) - gen_202);
			t_sample mix_10106 = (soloMid + (((t_sample)0.999) * (m_history_183 - soloMid)));
			t_sample mix_207 = mix_10106;
			t_sample gen_208 = mix_207;
			t_sample history_3_next_209 = fixdenorm(mix_207);
			t_sample mix_10107 = (soloHigh + (((t_sample)0.999) * (m_history_182 - soloHigh)));
			t_sample mix_211 = mix_10107;
			t_sample gen_212 = mix_211;
			t_sample history_4_next_213 = fixdenorm(mix_211);
			t_sample mix_10108 = (soloLow + (((t_sample)0.999) * (m_history_181 - soloLow)));
			t_sample mix_216 = mix_10108;
			t_sample gen_217 = mix_216;
			t_sample soloMaskLow = (gen_212 + gen_208);
			t_sample soloMaskMid = (gen_212 + gen_217);
			t_sample soloMaskHigh = (gen_208 + gen_217);
			t_sample history_5_next_218 = fixdenorm(mix_216);
			t_sample setparam_220 = lowBalance;
			t_sample mix_10109 = (inputMode + (((t_sample)0.999) * (m_history_180 - inputMode)));
			t_sample mix_222 = mix_10109;
			t_sample gen_223 = mix_222;
			t_sample history_6_next_224 = fixdenorm(mix_222);
			t_sample setparam_225 = gen_223;
			t_sample mix_10110 = (bandLowGain + (((t_sample)0.999) * (m_history_179 - bandLowGain)));
			t_sample mix_229 = mix_10110;
			t_sample gen_230 = mix_229;
			t_sample history_7_next_231 = fixdenorm(mix_229);
			t_sample setparam_232 = gen_230;
			t_sample mix_10111 = (bandMidGain + (((t_sample)0.999) * (m_history_178 - bandMidGain)));
			t_sample mix_236 = mix_10111;
			t_sample gen_237 = mix_236;
			t_sample history_8_next_238 = fixdenorm(mix_236);
			t_sample setparam_239 = gen_237;
			t_sample mix_10112 = (midBalance + (((t_sample)0.999) * (m_history_177 - midBalance)));
			t_sample mix_241 = mix_10112;
			t_sample gen_242 = mix_241;
			t_sample history_9_next_243 = fixdenorm(mix_241);
			t_sample setparam_244 = gen_242;
			t_sample mix_10113 = (bandHighGain + (((t_sample)0.999) * (m_history_176 - bandHighGain)));
			t_sample mix_248 = mix_10113;
			t_sample gen_249 = mix_248;
			t_sample history_10_next_250 = fixdenorm(mix_248);
			t_sample setparam_251 = gen_249;
			t_sample mix_10114 = (highBalance + (((t_sample)0.999) * (m_history_175 - highBalance)));
			t_sample mix_253 = mix_10114;
			t_sample gen_254 = mix_253;
			t_sample history_11_next_255 = fixdenorm(mix_253);
			t_sample setparam_256 = gen_254;
			t_sample mix_10115 = (freqHighHz + (((t_sample)0.999) * (m_history_174 - freqHighHz)));
			t_sample mix_258 = mix_10115;
			t_sample gen_259 = mix_258;
			t_sample history_12_next_260 = fixdenorm(mix_258);
			t_sample setparam_261 = gen_259;
			t_sample mix_10116 = (freqLowHz + (((t_sample)0.999) * (m_history_173 - freqLowHz)));
			t_sample mix_263 = mix_10116;
			t_sample gen_264 = mix_263;
			t_sample history_13_next_265 = fixdenorm(mix_263);
			t_sample setparam_266 = gen_264;
			t_sample freq_low_267 = ((setparam_266 <= ((int)20)) ? ((int)20) : ((setparam_266 >= ((int)1000)) ? ((int)1000) : setparam_266));
			t_sample freq_high_268 = ((setparam_261 <= ((int)1000)) ? ((int)1000) : ((setparam_261 >= ((int)20000)) ? ((int)20000) : setparam_261));
			t_sample wetLInBand = wetInL;
			int sr_270 = samplerate;
			t_sample minb_247 = (((t_sample)0.45) * sr_270);
			t_sample maxb_248 = ((minb_247 < freq_low_267) ? minb_247 : freq_low_267);
			t_sample loF_271 = ((((int)10) < maxb_248) ? maxb_248 : ((int)10));
			t_sample minb_249 = (((t_sample)0.45) * sr_270);
			t_sample maxb_250 = ((minb_249 < freq_high_268) ? minb_249 : freq_high_268);
			t_sample hiFr_272 = ((((int)10) < maxb_250) ? maxb_250 : ((int)10));
			t_sample maxb_251 = (loF_271 + ((int)1));
			t_sample hiF_273 = ((hiFr_272 < maxb_251) ? maxb_251 : hiFr_272);
			t_sample w0_lo_274 = safediv((((t_sample)6.2831853071796) * loF_271), sr_270);
			t_sample cos_lo_275 = cos(w0_lo_274);
			t_sample sin_lo_276 = sin(w0_lo_274);
			t_sample alpha_lo_277 = (sin_lo_276 * ((t_sample)0.70710678118655));
			t_sample a0_lo_278 = (((int)1) + alpha_lo_277);
			t_sample a1_lo_279 = (((int)-2) * cos_lo_275);
			t_sample a2_lo_280 = (((int)1) - alpha_lo_277);
			t_sample lp_b0_l_281 = safediv(((((int)1) - cos_lo_275) * ((t_sample)0.5)), a0_lo_278);
			t_sample lp_b1_l_282 = safediv((((int)1) - cos_lo_275), a0_lo_278);
			t_sample lp_b2_l_283 = lp_b0_l_281;
			t_sample lp_a1_l_284 = safediv(a1_lo_279, a0_lo_278);
			t_sample lp_a2_l_285 = safediv(a2_lo_280, a0_lo_278);
			t_sample hp_b0_l_286 = safediv(((((int)1) + cos_lo_275) * ((t_sample)0.5)), a0_lo_278);
			t_sample hp_b1_l_287 = safediv((-(((int)1) + cos_lo_275)), a0_lo_278);
			t_sample hp_b2_l_288 = hp_b0_l_286;
			t_sample hp_a1_l_289 = lp_a1_l_284;
			t_sample hp_a2_l_290 = lp_a2_l_285;
			t_sample w0_hi_291 = safediv((((t_sample)6.2831853071796) * hiF_273), sr_270);
			t_sample cos_hi_292 = cos(w0_hi_291);
			t_sample sin_hi_293 = sin(w0_hi_291);
			t_sample alpha_hi_294 = (sin_hi_293 * ((t_sample)0.70710678118655));
			t_sample a0_hi_295 = (((int)1) + alpha_hi_294);
			t_sample a1_hi_296 = (((int)-2) * cos_hi_292);
			t_sample a2_hi_297 = (((int)1) - alpha_hi_294);
			t_sample lp_b0_h_298 = safediv(((((int)1) - cos_hi_292) * ((t_sample)0.5)), a0_hi_295);
			t_sample lp_b1_h_299 = safediv((((int)1) - cos_hi_292), a0_hi_295);
			t_sample lp_b2_h_300 = lp_b0_h_298;
			t_sample lp_a1_h_301 = safediv(a1_hi_296, a0_hi_295);
			t_sample lp_a2_h_302 = safediv(a2_hi_297, a0_hi_295);
			t_sample hp_b0_h_303 = safediv(((((int)1) + cos_hi_292) * ((t_sample)0.5)), a0_hi_295);
			t_sample hp_b1_h_304 = safediv((-(((int)1) + cos_hi_292)), a0_hi_295);
			t_sample hp_b2_h_305 = hp_b0_h_303;
			t_sample hp_a1_h_306 = lp_a1_h_301;
			t_sample hp_a2_h_307 = lp_a2_h_302;
			t_sample l1_x1p = m_l1_x_172;
			t_sample l1_x2p = m_l1_x_171;
			t_sample l1_y1p = m_l1_y_170;
			t_sample l1_y2p = m_l1_y_169;
			t_sample low_s1 = (((((lp_b0_l_281 * wetLInBand) + (lp_b1_l_282 * l1_x1p)) + (lp_b2_l_283 * l1_x2p)) - (lp_a1_l_284 * l1_y1p)) - (lp_a2_l_285 * l1_y2p));
			m_l1_x_171 = l1_x1p;
			m_l1_x_172 = wetLInBand;
			m_l1_y_169 = l1_y1p;
			m_l1_y_170 = low_s1;
			t_sample l2_x1p = m_l2_x_168;
			t_sample l2_x2p = m_l2_x_167;
			t_sample l2_y1p = m_l2_y_166;
			t_sample l2_y2p = m_l2_y_165;
			t_sample low_raw = (((((lp_b0_l_281 * low_s1) + (lp_b1_l_282 * l2_x1p)) + (lp_b2_l_283 * l2_x2p)) - (lp_a1_l_284 * l2_y1p)) - (lp_a2_l_285 * l2_y2p));
			m_l2_x_167 = l2_x1p;
			m_l2_x_168 = low_s1;
			m_l2_y_165 = l2_y1p;
			m_l2_y_166 = low_raw;
			t_sample h1_x1p = m_h1_x_164;
			t_sample h1_x2p = m_h1_x_163;
			t_sample h1_y1p = m_h1_y_162;
			t_sample h1_y2p = m_h1_y_161;
			t_sample rest_s1 = (((((hp_b0_l_286 * wetLInBand) + (hp_b1_l_287 * h1_x1p)) + (hp_b2_l_288 * h1_x2p)) - (hp_a1_l_289 * h1_y1p)) - (hp_a2_l_290 * h1_y2p));
			m_h1_x_163 = h1_x1p;
			m_h1_x_164 = wetLInBand;
			m_h1_y_161 = h1_y1p;
			m_h1_y_162 = rest_s1;
			t_sample h2_x1p = m_h2_x_160;
			t_sample h2_x2p = m_h2_x_159;
			t_sample h2_y1p = m_h2_y_158;
			t_sample h2_y2p = m_h2_y_157;
			t_sample rest = (((((hp_b0_l_286 * rest_s1) + (hp_b1_l_287 * h2_x1p)) + (hp_b2_l_288 * h2_x2p)) - (hp_a1_l_289 * h2_y1p)) - (hp_a2_l_290 * h2_y2p));
			m_h2_x_159 = h2_x1p;
			m_h2_x_160 = rest_s1;
			m_h2_y_157 = h2_y1p;
			m_h2_y_158 = rest;
			t_sample ap_low_lp1_x1p = m_ap_low_lp1_x_140;
			t_sample ap_low_lp1_x2p = m_ap_low_lp1_x_139;
			t_sample ap_low_lp1_y1p = m_ap_low_lp1_y_138;
			t_sample ap_low_lp1_y2p = m_ap_low_lp1_y_137;
			t_sample ap_low_lp_s1 = (((((lp_b0_h_298 * low_raw) + (lp_b1_h_299 * ap_low_lp1_x1p)) + (lp_b2_h_300 * ap_low_lp1_x2p)) - (lp_a1_h_301 * ap_low_lp1_y1p)) - (lp_a2_h_302 * ap_low_lp1_y2p));
			m_ap_low_lp1_x_139 = ap_low_lp1_x1p;
			m_ap_low_lp1_x_140 = low_raw;
			m_ap_low_lp1_y_137 = ap_low_lp1_y1p;
			m_ap_low_lp1_y_138 = ap_low_lp_s1;
			t_sample ap_low_lp2_x1p = m_ap_low_lp2_x_136;
			t_sample ap_low_lp2_x2p = m_ap_low_lp2_x_135;
			t_sample ap_low_lp2_y1p = m_ap_low_lp2_y_134;
			t_sample ap_low_lp2_y2p = m_ap_low_lp2_y_133;
			t_sample ap_low_lp = (((((lp_b0_h_298 * ap_low_lp_s1) + (lp_b1_h_299 * ap_low_lp2_x1p)) + (lp_b2_h_300 * ap_low_lp2_x2p)) - (lp_a1_h_301 * ap_low_lp2_y1p)) - (lp_a2_h_302 * ap_low_lp2_y2p));
			m_ap_low_lp2_x_135 = ap_low_lp2_x1p;
			m_ap_low_lp2_x_136 = ap_low_lp_s1;
			m_ap_low_lp2_y_133 = ap_low_lp2_y1p;
			m_ap_low_lp2_y_134 = ap_low_lp;
			t_sample ap_low_hp1_x1p = m_ap_low_hp1_x_132;
			t_sample ap_low_hp1_x2p = m_ap_low_hp1_x_131;
			t_sample ap_low_hp1_y1p = m_ap_low_hp1_y_130;
			t_sample ap_low_hp1_y2p = m_ap_low_hp1_y_129;
			t_sample ap_low_hp_s1 = (((((hp_b0_h_303 * low_raw) + (hp_b1_h_304 * ap_low_hp1_x1p)) + (hp_b2_h_305 * ap_low_hp1_x2p)) - (hp_a1_h_306 * ap_low_hp1_y1p)) - (hp_a2_h_307 * ap_low_hp1_y2p));
			m_ap_low_hp1_x_131 = ap_low_hp1_x1p;
			m_ap_low_hp1_x_132 = low_raw;
			m_ap_low_hp1_y_129 = ap_low_hp1_y1p;
			m_ap_low_hp1_y_130 = ap_low_hp_s1;
			t_sample ap_low_hp2_x1p = m_ap_low_hp2_x_128;
			t_sample ap_low_hp2_x2p = m_ap_low_hp2_x_127;
			t_sample ap_low_hp2_y1p = m_ap_low_hp2_y_126;
			t_sample ap_low_hp2_y2p = m_ap_low_hp2_y_125;
			t_sample ap_low_hp = (((((hp_b0_h_303 * ap_low_hp_s1) + (hp_b1_h_304 * ap_low_hp2_x1p)) + (hp_b2_h_305 * ap_low_hp2_x2p)) - (hp_a1_h_306 * ap_low_hp2_y1p)) - (hp_a2_h_307 * ap_low_hp2_y2p));
			m_ap_low_hp2_x_127 = ap_low_hp2_x1p;
			m_ap_low_hp2_x_128 = ap_low_hp_s1;
			m_ap_low_hp2_y_125 = ap_low_hp2_y1p;
			m_ap_low_hp2_y_126 = ap_low_hp;
			t_sample low = (ap_low_lp + ap_low_hp);
			t_sample m1_x1p = m_m1_x_156;
			t_sample m1_x2p = m_m1_x_155;
			t_sample m1_y1p = m_m1_y_154;
			t_sample m1_y2p = m_m1_y_153;
			t_sample mid_s1 = (((((lp_b0_h_298 * rest) + (lp_b1_h_299 * m1_x1p)) + (lp_b2_h_300 * m1_x2p)) - (lp_a1_h_301 * m1_y1p)) - (lp_a2_h_302 * m1_y2p));
			m_m1_x_155 = m1_x1p;
			m_m1_x_156 = rest;
			m_m1_y_153 = m1_y1p;
			m_m1_y_154 = mid_s1;
			t_sample m2_x1p = m_m2_x_152;
			t_sample m2_x2p = m_m2_x_151;
			t_sample m2_y1p = m_m2_y_150;
			t_sample m2_y2p = m_m2_y_149;
			t_sample mid = (((((lp_b0_h_298 * mid_s1) + (lp_b1_h_299 * m2_x1p)) + (lp_b2_h_300 * m2_x2p)) - (lp_a1_h_301 * m2_y1p)) - (lp_a2_h_302 * m2_y2p));
			m_m2_x_151 = m2_x1p;
			m_m2_x_152 = mid_s1;
			m_m2_y_149 = m2_y1p;
			m_m2_y_150 = mid;
			t_sample u1_x1p = m_u1_x_148;
			t_sample u1_x2p = m_u1_x_147;
			t_sample u1_y1p = m_u1_y_146;
			t_sample u1_y2p = m_u1_y_145;
			t_sample high_s1 = (((((hp_b0_h_303 * rest) + (hp_b1_h_304 * u1_x1p)) + (hp_b2_h_305 * u1_x2p)) - (hp_a1_h_306 * u1_y1p)) - (hp_a2_h_307 * u1_y2p));
			m_u1_x_147 = u1_x1p;
			m_u1_x_148 = rest;
			m_u1_y_145 = u1_y1p;
			m_u1_y_146 = high_s1;
			t_sample u2_x1p = m_u2_x_144;
			t_sample u2_x2p = m_u2_x_143;
			t_sample u2_y1p = m_u2_y_142;
			t_sample u2_y2p = m_u2_y_141;
			t_sample high = (((((hp_b0_h_303 * high_s1) + (hp_b1_h_304 * u2_x1p)) + (hp_b2_h_305 * u2_x2p)) - (hp_a1_h_306 * u2_y1p)) - (hp_a2_h_307 * u2_y2p));
			m_u2_x_143 = u2_x1p;
			m_u2_x_144 = high_s1;
			m_u2_y_141 = u2_y1p;
			m_u2_y_142 = high;
			t_sample expr_308 = low;
			t_sample expr_309 = mid;
			t_sample expr_310 = high;
			t_sample gen_312 = expr_308;
			t_sample gen_313 = expr_309;
			t_sample gen_314 = expr_310;
			t_sample lowLIn = gen_312;
			t_sample midLIn = gen_313;
			t_sample highLIn = gen_314;
			t_sample freq_low_315 = ((setparam_266 <= ((int)20)) ? ((int)20) : ((setparam_266 >= ((int)1000)) ? ((int)1000) : setparam_266));
			t_sample freq_high_316 = ((setparam_261 <= ((int)1000)) ? ((int)1000) : ((setparam_261 >= ((int)20000)) ? ((int)20000) : setparam_261));
			t_sample wetRInBand = wetInR;
			int sr_318 = samplerate;
			t_sample minb_252 = (((t_sample)0.45) * sr_318);
			t_sample maxb_253 = ((minb_252 < freq_low_315) ? minb_252 : freq_low_315);
			t_sample loF_319 = ((((int)10) < maxb_253) ? maxb_253 : ((int)10));
			t_sample minb_254 = (((t_sample)0.45) * sr_318);
			t_sample maxb_255 = ((minb_254 < freq_high_316) ? minb_254 : freq_high_316);
			t_sample hiFr_320 = ((((int)10) < maxb_255) ? maxb_255 : ((int)10));
			t_sample maxb_256 = (loF_319 + ((int)1));
			t_sample hiF_321 = ((hiFr_320 < maxb_256) ? maxb_256 : hiFr_320);
			t_sample w0_lo_322 = safediv((((t_sample)6.2831853071796) * loF_319), sr_318);
			t_sample cos_lo_323 = cos(w0_lo_322);
			t_sample sin_lo_324 = sin(w0_lo_322);
			t_sample alpha_lo_325 = (sin_lo_324 * ((t_sample)0.70710678118655));
			t_sample a0_lo_326 = (((int)1) + alpha_lo_325);
			t_sample a1_lo_327 = (((int)-2) * cos_lo_323);
			t_sample a2_lo_328 = (((int)1) - alpha_lo_325);
			t_sample lp_b0_l_329 = safediv(((((int)1) - cos_lo_323) * ((t_sample)0.5)), a0_lo_326);
			t_sample lp_b1_l_330 = safediv((((int)1) - cos_lo_323), a0_lo_326);
			t_sample lp_b2_l_331 = lp_b0_l_329;
			t_sample lp_a1_l_332 = safediv(a1_lo_327, a0_lo_326);
			t_sample lp_a2_l_333 = safediv(a2_lo_328, a0_lo_326);
			t_sample hp_b0_l_334 = safediv(((((int)1) + cos_lo_323) * ((t_sample)0.5)), a0_lo_326);
			t_sample hp_b1_l_335 = safediv((-(((int)1) + cos_lo_323)), a0_lo_326);
			t_sample hp_b2_l_336 = hp_b0_l_334;
			t_sample hp_a1_l_337 = lp_a1_l_332;
			t_sample hp_a2_l_338 = lp_a2_l_333;
			t_sample w0_hi_339 = safediv((((t_sample)6.2831853071796) * hiF_321), sr_318);
			t_sample cos_hi_340 = cos(w0_hi_339);
			t_sample sin_hi_341 = sin(w0_hi_339);
			t_sample alpha_hi_342 = (sin_hi_341 * ((t_sample)0.70710678118655));
			t_sample a0_hi_343 = (((int)1) + alpha_hi_342);
			t_sample a1_hi_344 = (((int)-2) * cos_hi_340);
			t_sample a2_hi_345 = (((int)1) - alpha_hi_342);
			t_sample lp_b0_h_346 = safediv(((((int)1) - cos_hi_340) * ((t_sample)0.5)), a0_hi_343);
			t_sample lp_b1_h_347 = safediv((((int)1) - cos_hi_340), a0_hi_343);
			t_sample lp_b2_h_348 = lp_b0_h_346;
			t_sample lp_a1_h_349 = safediv(a1_hi_344, a0_hi_343);
			t_sample lp_a2_h_350 = safediv(a2_hi_345, a0_hi_343);
			t_sample hp_b0_h_351 = safediv(((((int)1) + cos_hi_340) * ((t_sample)0.5)), a0_hi_343);
			t_sample hp_b1_h_352 = safediv((-(((int)1) + cos_hi_340)), a0_hi_343);
			t_sample hp_b2_h_353 = hp_b0_h_351;
			t_sample hp_a1_h_354 = lp_a1_h_349;
			t_sample hp_a2_h_355 = lp_a2_h_350;
			t_sample l1_x1p_356 = m_l1_x_124;
			t_sample l1_x2p_357 = m_l1_x_123;
			t_sample l1_y1p_358 = m_l1_y_122;
			t_sample l1_y2p_359 = m_l1_y_121;
			t_sample low_s_360 = (((((lp_b0_l_329 * wetRInBand) + (lp_b1_l_330 * l1_x1p_356)) + (lp_b2_l_331 * l1_x2p_357)) - (lp_a1_l_332 * l1_y1p_358)) - (lp_a2_l_333 * l1_y2p_359));
			m_l1_x_123 = l1_x1p_356;
			m_l1_x_124 = wetRInBand;
			m_l1_y_121 = l1_y1p_358;
			m_l1_y_122 = low_s_360;
			t_sample l2_x1p_361 = m_l2_x_120;
			t_sample l2_x2p_362 = m_l2_x_119;
			t_sample l2_y1p_363 = m_l2_y_118;
			t_sample l2_y2p_364 = m_l2_y_117;
			t_sample low_raw_365 = (((((lp_b0_l_329 * low_s_360) + (lp_b1_l_330 * l2_x1p_361)) + (lp_b2_l_331 * l2_x2p_362)) - (lp_a1_l_332 * l2_y1p_363)) - (lp_a2_l_333 * l2_y2p_364));
			m_l2_x_119 = l2_x1p_361;
			m_l2_x_120 = low_s_360;
			m_l2_y_117 = l2_y1p_363;
			m_l2_y_118 = low_raw_365;
			t_sample h1_x1p_366 = m_h1_x_116;
			t_sample h1_x2p_367 = m_h1_x_115;
			t_sample h1_y1p_368 = m_h1_y_114;
			t_sample h1_y2p_369 = m_h1_y_113;
			t_sample rest_s_370 = (((((hp_b0_l_334 * wetRInBand) + (hp_b1_l_335 * h1_x1p_366)) + (hp_b2_l_336 * h1_x2p_367)) - (hp_a1_l_337 * h1_y1p_368)) - (hp_a2_l_338 * h1_y2p_369));
			m_h1_x_115 = h1_x1p_366;
			m_h1_x_116 = wetRInBand;
			m_h1_y_113 = h1_y1p_368;
			m_h1_y_114 = rest_s_370;
			t_sample h2_x1p_371 = m_h2_x_112;
			t_sample h2_x2p_372 = m_h2_x_111;
			t_sample h2_y1p_373 = m_h2_y_110;
			t_sample h2_y2p_374 = m_h2_y_109;
			t_sample rest_375 = (((((hp_b0_l_334 * rest_s_370) + (hp_b1_l_335 * h2_x1p_371)) + (hp_b2_l_336 * h2_x2p_372)) - (hp_a1_l_337 * h2_y1p_373)) - (hp_a2_l_338 * h2_y2p_374));
			m_h2_x_111 = h2_x1p_371;
			m_h2_x_112 = rest_s_370;
			m_h2_y_109 = h2_y1p_373;
			m_h2_y_110 = rest_375;
			t_sample ap_low_lp1_x1p_376 = m_ap_low_lp1_x_92;
			t_sample ap_low_lp1_x2p_377 = m_ap_low_lp1_x_91;
			t_sample ap_low_lp1_y1p_378 = m_ap_low_lp1_y_90;
			t_sample ap_low_lp1_y2p_379 = m_ap_low_lp1_y_89;
			t_sample ap_low_lp_s_380 = (((((lp_b0_h_346 * low_raw_365) + (lp_b1_h_347 * ap_low_lp1_x1p_376)) + (lp_b2_h_348 * ap_low_lp1_x2p_377)) - (lp_a1_h_349 * ap_low_lp1_y1p_378)) - (lp_a2_h_350 * ap_low_lp1_y2p_379));
			m_ap_low_lp1_x_91 = ap_low_lp1_x1p_376;
			m_ap_low_lp1_x_92 = low_raw_365;
			m_ap_low_lp1_y_89 = ap_low_lp1_y1p_378;
			m_ap_low_lp1_y_90 = ap_low_lp_s_380;
			t_sample ap_low_lp2_x1p_381 = m_ap_low_lp2_x_88;
			t_sample ap_low_lp2_x2p_382 = m_ap_low_lp2_x_87;
			t_sample ap_low_lp2_y1p_383 = m_ap_low_lp2_y_86;
			t_sample ap_low_lp2_y2p_384 = m_ap_low_lp2_y_85;
			t_sample ap_low_lp_385 = (((((lp_b0_h_346 * ap_low_lp_s_380) + (lp_b1_h_347 * ap_low_lp2_x1p_381)) + (lp_b2_h_348 * ap_low_lp2_x2p_382)) - (lp_a1_h_349 * ap_low_lp2_y1p_383)) - (lp_a2_h_350 * ap_low_lp2_y2p_384));
			m_ap_low_lp2_x_87 = ap_low_lp2_x1p_381;
			m_ap_low_lp2_x_88 = ap_low_lp_s_380;
			m_ap_low_lp2_y_85 = ap_low_lp2_y1p_383;
			m_ap_low_lp2_y_86 = ap_low_lp_385;
			t_sample ap_low_hp1_x1p_386 = m_ap_low_hp1_x_84;
			t_sample ap_low_hp1_x2p_387 = m_ap_low_hp1_x_83;
			t_sample ap_low_hp1_y1p_388 = m_ap_low_hp1_y_82;
			t_sample ap_low_hp1_y2p_389 = m_ap_low_hp1_y_81;
			t_sample ap_low_hp_s_390 = (((((hp_b0_h_351 * low_raw_365) + (hp_b1_h_352 * ap_low_hp1_x1p_386)) + (hp_b2_h_353 * ap_low_hp1_x2p_387)) - (hp_a1_h_354 * ap_low_hp1_y1p_388)) - (hp_a2_h_355 * ap_low_hp1_y2p_389));
			m_ap_low_hp1_x_83 = ap_low_hp1_x1p_386;
			m_ap_low_hp1_x_84 = low_raw_365;
			m_ap_low_hp1_y_81 = ap_low_hp1_y1p_388;
			m_ap_low_hp1_y_82 = ap_low_hp_s_390;
			t_sample ap_low_hp2_x1p_391 = m_ap_low_hp2_x_80;
			t_sample ap_low_hp2_x2p_392 = m_ap_low_hp2_x_79;
			t_sample ap_low_hp2_y1p_393 = m_ap_low_hp2_y_78;
			t_sample ap_low_hp2_y2p_394 = m_ap_low_hp2_y_77;
			t_sample ap_low_hp_395 = (((((hp_b0_h_351 * ap_low_hp_s_390) + (hp_b1_h_352 * ap_low_hp2_x1p_391)) + (hp_b2_h_353 * ap_low_hp2_x2p_392)) - (hp_a1_h_354 * ap_low_hp2_y1p_393)) - (hp_a2_h_355 * ap_low_hp2_y2p_394));
			m_ap_low_hp2_x_79 = ap_low_hp2_x1p_391;
			m_ap_low_hp2_x_80 = ap_low_hp_s_390;
			m_ap_low_hp2_y_77 = ap_low_hp2_y1p_393;
			m_ap_low_hp2_y_78 = ap_low_hp_395;
			t_sample low_396 = (ap_low_lp_385 + ap_low_hp_395);
			t_sample m1_x1p_397 = m_m1_x_108;
			t_sample m1_x2p_398 = m_m1_x_107;
			t_sample m1_y1p_399 = m_m1_y_106;
			t_sample m1_y2p_400 = m_m1_y_105;
			t_sample mid_s_401 = (((((lp_b0_h_346 * rest_375) + (lp_b1_h_347 * m1_x1p_397)) + (lp_b2_h_348 * m1_x2p_398)) - (lp_a1_h_349 * m1_y1p_399)) - (lp_a2_h_350 * m1_y2p_400));
			m_m1_x_107 = m1_x1p_397;
			m_m1_x_108 = rest_375;
			m_m1_y_105 = m1_y1p_399;
			m_m1_y_106 = mid_s_401;
			t_sample m2_x1p_402 = m_m2_x_104;
			t_sample m2_x2p_403 = m_m2_x_103;
			t_sample m2_y1p_404 = m_m2_y_102;
			t_sample m2_y2p_405 = m_m2_y_101;
			t_sample mid_406 = (((((lp_b0_h_346 * mid_s_401) + (lp_b1_h_347 * m2_x1p_402)) + (lp_b2_h_348 * m2_x2p_403)) - (lp_a1_h_349 * m2_y1p_404)) - (lp_a2_h_350 * m2_y2p_405));
			m_m2_x_103 = m2_x1p_402;
			m_m2_x_104 = mid_s_401;
			m_m2_y_101 = m2_y1p_404;
			m_m2_y_102 = mid_406;
			t_sample u1_x1p_407 = m_u1_x_100;
			t_sample u1_x2p_408 = m_u1_x_99;
			t_sample u1_y1p_409 = m_u1_y_98;
			t_sample u1_y2p_410 = m_u1_y_97;
			t_sample high_s_411 = (((((hp_b0_h_351 * rest_375) + (hp_b1_h_352 * u1_x1p_407)) + (hp_b2_h_353 * u1_x2p_408)) - (hp_a1_h_354 * u1_y1p_409)) - (hp_a2_h_355 * u1_y2p_410));
			m_u1_x_99 = u1_x1p_407;
			m_u1_x_100 = rest_375;
			m_u1_y_97 = u1_y1p_409;
			m_u1_y_98 = high_s_411;
			t_sample u2_x1p_412 = m_u2_x_96;
			t_sample u2_x2p_413 = m_u2_x_95;
			t_sample u2_y1p_414 = m_u2_y_94;
			t_sample u2_y2p_415 = m_u2_y_93;
			t_sample high_416 = (((((hp_b0_h_351 * high_s_411) + (hp_b1_h_352 * u2_x1p_412)) + (hp_b2_h_353 * u2_x2p_413)) - (hp_a1_h_354 * u2_y1p_414)) - (hp_a2_h_355 * u2_y2p_415));
			m_u2_x_95 = u2_x1p_412;
			m_u2_x_96 = high_s_411;
			m_u2_y_93 = u2_y1p_414;
			m_u2_y_94 = high_416;
			t_sample expr_418 = low_396;
			t_sample expr_419 = mid_406;
			t_sample expr_420 = high_416;
			t_sample gen_422 = expr_419;
			t_sample gen_423 = expr_418;
			t_sample gen_424 = expr_420;
			t_sample midRIn = gen_422;
			t_sample lowRIn = gen_423;
			t_sample highRIn = gen_424;
			t_sample e_wide = ((setparam_232 <= ((int)0)) ? ((int)0) : ((setparam_232 >= ((int)200)) ? ((int)200) : setparam_232));
			t_sample d_balance = ((setparam_220 <= ((int)0)) ? ((int)0) : ((setparam_220 >= ((int)1)) ? ((int)1) : setparam_220));
			t_sample a_input = ((setparam_225 <= ((int)0)) ? ((int)0) : ((setparam_225 >= ((int)1)) ? ((int)1) : setparam_225));
			t_sample mix_10117 = (((int)0) + (((t_sample)0.999) * (m_history_76 - ((int)0))));
			t_sample mix_427 = mix_10117;
			t_sample gen_428 = mix_427;
			t_sample history_62_next_429 = fixdenorm(mix_427);
			t_sample rsub_430 = (((int)1) - gen_428);
			t_sample mix_10118 = (d_balance + (((t_sample)0.999) * (m_history_75 - d_balance)));
			t_sample mix_433 = mix_10118;
			t_sample gen_434 = mix_433;
			t_sample history_63_next_435 = fixdenorm(mix_433);
			t_sample lowBalT = ((gen_434 - ((t_sample)0.5)) * ((int)2));
			t_sample lowBalPos = ((lowBalT < ((int)0)) ? ((int)0) : lowBalT);
			t_sample lowBalNeg = ((((int)0) < lowBalT) ? ((int)0) : lowBalT);
			t_sample v_257 = (((int)1) - lowBalPos);
			t_sample lowBalGL = ((v_257 <= ((int)0)) ? ((int)0) : ((v_257 >= ((int)1)) ? ((int)1) : v_257));
			t_sample v_258 = (((int)1) + lowBalNeg);
			t_sample lowBalGR = ((v_258 <= ((int)0)) ? ((int)0) : ((v_258 >= ((int)1)) ? ((int)1) : v_258));
			t_sample mix_10119 = (e_wide + (((t_sample)0.999) * (m_history_74 - e_wide)));
			t_sample mix_442 = mix_10119;
			t_sample gen_443 = mix_442;
			t_sample history_64_next_444 = fixdenorm(mix_442);
			t_sample mix_10120 = (a_input + (((t_sample)0.999) * (m_history_73 - a_input)));
			t_sample mix_448 = mix_10120;
			t_sample gen_449 = mix_448;
			t_sample history_65_next_450 = fixdenorm(mix_448);
			t_sample mix_10121 = (lowLIn + (gen_449 * (((int)0) - lowLIn)));
			t_sample mix_451 = mix_10121;
			t_sample mix_10122 = (lowRIn + (gen_449 * (((int)0) - lowRIn)));
			t_sample mix_452 = mix_10122;
			t_sample mix_10123 = (((int)0) + (gen_449 * (lowLIn - ((int)0))));
			t_sample mix_453 = mix_10123;
			t_sample mix_10124 = (((int)0) + (gen_449 * (lowRIn - ((int)0))));
			t_sample mix_454 = mix_10124;
			t_sample add_455 = (mix_453 + mix_454);
			t_sample mul_456 = ((add_455 + mix_451) * ((int)1));
			t_sample sub_457 = (mix_453 - mix_454);
			t_sample mul_458 = ((mix_452 + sub_457) * ((int)1));
			t_sample alpha_low = (((int)1) - exp(safediv(((int)-1), (((t_sample)0.08) * samplerate))));
			t_sample mLowRaw = mul_456;
			t_sample sLowRaw = mul_458;
			t_sample w_low_c = ((gen_443 <= ((int)0)) ? ((int)0) : ((gen_443 >= ((int)2)) ? ((int)2) : gen_443));
			t_sample u_low = (w_low_c * ((t_sample)0.5));
			t_sample theta_low = (u_low * ((t_sample)1.2319971190549));
			t_sample gM_low = cos(theta_low);
			t_sample gS_low = sin(theta_low);
			t_sample lLowPre = ((mLowRaw + sLowRaw) * ((t_sample)0.5));
			t_sample rLowPre = ((mLowRaw - sLowRaw) * ((t_sample)0.5));
			m_low_EL_51 = fixdenorm((m_low_EL_51 + (alpha_low * ((lLowPre * lLowPre) - m_low_EL_51))));
			m_low_ER_50 = fixdenorm((m_low_ER_50 + (alpha_low * ((rLowPre * rLowPre) - m_low_ER_50))));
			m_low_CCS_52 = fixdenorm((m_low_CCS_52 + (alpha_low * ((lLowPre * rLowPre) - m_low_CCS_52))));
			m_low_EM_54 = fixdenorm((m_low_EM_54 + (alpha_low * ((mLowRaw * mLowRaw) - m_low_EM_54))));
			m_low_ES_53 = fixdenorm((m_low_ES_53 + (alpha_low * ((sLowRaw * sLowRaw) - m_low_ES_53))));
			t_sample a_low = (((t_sample)0.5) * (gM_low + gS_low));
			t_sample b_low = (((t_sample)0.5) * (gM_low - gS_low));
			t_sample Pin_low = ((m_low_EL_51 + m_low_ER_50) + ((t_sample)1e-12));
			t_sample Pout_low = (((((a_low * a_low) + (b_low * b_low)) * (m_low_EL_51 + m_low_ER_50)) + (((((int)4) * a_low) * b_low) * m_low_CCS_52)) + ((t_sample)1e-12));
			t_sample G_low = sqrt(safediv(Pin_low, Pout_low));
			t_sample G_low_10021 = ((G_low <= ((t_sample)0.59566214352901)) ? ((t_sample)0.59566214352901) : ((G_low >= ((t_sample)1.6788040181226)) ? ((t_sample)1.6788040181226) : G_low));
			t_sample rho_low_num = m_low_CCS_52;
			t_sample maxa_259 = (m_low_EL_51 * m_low_ER_50);
			t_sample rho_low_den = sqrt(((maxa_259 < ((t_sample)1e-12)) ? ((t_sample)1e-12) : maxa_259));
			t_sample v_260 = safediv(rho_low_num, (rho_low_den + ((t_sample)1e-12)));
			t_sample rho_low = ((v_260 <= ((int)-1)) ? ((int)-1) : ((v_260 >= ((int)1)) ? ((int)1) : v_260));
			t_sample maxb_261 = (u_low - ((t_sample)0.5));
			t_sample lift_base_low = ((((int)0) < maxb_261) ? maxb_261 : ((int)0));
			t_sample lift_dB_low = ((((int)6) * lift_base_low) * (((int)1) - rho_low));
			t_sample G_low_10022 = (G_low_10021 * dbtoa(lift_dB_low));
			t_sample mul_459 = (mLowRaw * ((t_sample)0.5));
			t_sample mul_462 = (sLowRaw * ((t_sample)0.5));
			t_sample mul_461 = (mul_459 * (gM_low * G_low_10022));
			t_sample mul_463 = (mul_462 * (gS_low * G_low_10022));
			t_sample mul_464 = (mul_463 * ((int)1));
			t_sample sub_465 = (mul_461 - mul_464);
			t_sample add_467 = (mul_461 + mul_464);
			t_sample mul_469 = (add_467 * lowBalGL);
			t_sample mul_470 = (mul_469 * ((int)1));
			t_sample mix_10125 = (lowLIn + (rsub_430 * (mul_470 - lowLIn)));
			t_sample mix_10126 = (muteLow + (((t_sample)0.999) * (m_mute_low_h_57 - muteLow)));
			t_sample mute_low_sm = mix_10126;
			m_mute_low_h_57 = fixdenorm(mute_low_sm);
			t_sample low_gate = (((int)1) - ((mute_low_sm <= ((int)0)) ? ((int)0) : ((mute_low_sm >= ((int)1)) ? ((int)1) : mute_low_sm)));
			t_sample gen_10023 = (mix_10125 * low_gate);
			t_sample mul_473 = (sub_465 * lowBalGR);
			t_sample mul_474 = (mul_473 * ((int)1));
			t_sample mix_10127 = (lowRIn + (rsub_430 * (mul_474 - lowRIn)));
			t_sample gen_10024 = (mix_10127 * low_gate);
			t_sample mix_10128 = (gen_10024 + (soloMaskLow * (((int)0) - gen_10024)));
			t_sample mix_10129 = (gen_10023 + (soloMaskLow * (((int)0) - gen_10023)));
			t_sample d_balance_483 = ((setparam_244 <= ((int)0)) ? ((int)0) : ((setparam_244 >= ((int)1)) ? ((int)1) : setparam_244));
			t_sample e_wide_484 = ((setparam_239 <= ((int)0)) ? ((int)0) : ((setparam_239 >= ((int)200)) ? ((int)200) : setparam_239));
			t_sample a_input_486 = ((setparam_225 <= ((int)0)) ? ((int)0) : ((setparam_225 >= ((int)1)) ? ((int)1) : setparam_225));
			t_sample mix_10130 = (((int)0) + (((t_sample)0.999) * (m_history_72 - ((int)0))));
			t_sample mix_488 = mix_10130;
			t_sample gen_489 = mix_488;
			t_sample history_66_next_490 = fixdenorm(mix_488);
			t_sample rsub_491 = (((int)1) - gen_489);
			t_sample mix_10131 = (((int)0) + (((t_sample)0.999) * (m_history_71 - ((int)0))));
			t_sample mix_493 = mix_10131;
			t_sample gen_494 = mix_493;
			t_sample history_67_next_495 = fixdenorm(mix_493);
			t_sample dbtoa_496 = dbtoa(gen_494);
			t_sample mix_10132 = (d_balance_483 + (((t_sample)0.999) * (m_history_70 - d_balance_483)));
			t_sample mix_498 = mix_10132;
			t_sample gen_499 = mix_498;
			t_sample history_68_next_500 = fixdenorm(mix_498);
			t_sample midBalT = ((gen_499 - ((t_sample)0.5)) * ((int)2));
			t_sample midBalPos = ((midBalT < ((int)0)) ? ((int)0) : midBalT);
			t_sample midBalNeg = ((((int)0) < midBalT) ? ((int)0) : midBalT);
			t_sample v_262 = (((int)1) - midBalPos);
			t_sample midBalGL = ((v_262 <= ((int)0)) ? ((int)0) : ((v_262 >= ((int)1)) ? ((int)1) : v_262));
			t_sample v_263 = (((int)1) + midBalNeg);
			t_sample midBalGR = ((v_263 <= ((int)0)) ? ((int)0) : ((v_263 >= ((int)1)) ? ((int)1) : v_263));
			t_sample mix_10133 = (e_wide_484 + (((t_sample)0.999) * (m_history_69 - e_wide_484)));
			t_sample mix_505 = mix_10133;
			t_sample gen_506 = mix_505;
			t_sample history_69_next_507 = fixdenorm(mix_505);
			t_sample mix_10134 = (a_input_486 + (((t_sample)0.999) * (m_history_68 - a_input_486)));
			t_sample mix_511 = mix_10134;
			t_sample gen_512 = mix_511;
			t_sample history_70_next_513 = fixdenorm(mix_511);
			t_sample mix_10135 = (midLIn + (gen_512 * (((int)0) - midLIn)));
			t_sample mix_514 = mix_10135;
			t_sample mix_10136 = (midRIn + (gen_512 * (((int)0) - midRIn)));
			t_sample mix_515 = mix_10136;
			t_sample mix_10137 = (((int)0) + (gen_512 * (midLIn - ((int)0))));
			t_sample mix_516 = mix_10137;
			t_sample mix_10138 = (((int)0) + (gen_512 * (midRIn - ((int)0))));
			t_sample mix_517 = mix_10138;
			t_sample add_518 = (mix_516 + mix_517);
			t_sample sub_519 = (mix_516 - mix_517);
			t_sample mix_10139 = (((int)1) + (((t_sample)0.999) * (m_history_67 - ((int)1))));
			t_sample mix_522 = mix_10139;
			t_sample gen_523 = mix_522;
			t_sample history_71_next_524 = fixdenorm(mix_522);
			t_sample m_525 = gen_523;
			t_sample mul_526 = ((add_518 + mix_514) * m_525);
			t_sample mix_10140 = (((int)1) + (((t_sample)0.999) * (m_history_66 - ((int)1))));
			t_sample mix_529 = mix_10140;
			t_sample gen_530 = mix_529;
			t_sample history_72_next_531 = fixdenorm(mix_529);
			t_sample s_532 = gen_530;
			t_sample mul_533 = ((mix_515 + sub_519) * s_532);
			t_sample mix_10141 = (((int)1) + (((int)0) * (m_history_65 - ((int)1))));
			t_sample mix_538 = mix_10141;
			t_sample gen_539 = mix_538;
			t_sample history_73_next_540 = fixdenorm(mix_538);
			t_sample alpha_mid = (((int)1) - exp(safediv(((int)-1), (((t_sample)0.08) * samplerate))));
			t_sample mMidRaw = mul_526;
			t_sample sMidRaw = mul_533;
			t_sample w_mid_c = ((gen_506 <= ((int)0)) ? ((int)0) : ((gen_506 >= ((int)2)) ? ((int)2) : gen_506));
			t_sample u_mid = (w_mid_c * ((t_sample)0.5));
			t_sample theta_mid = (u_mid * ((t_sample)1.2319971190549));
			t_sample gM_mid = cos(theta_mid);
			t_sample gS_mid = sin(theta_mid);
			t_sample lMidPre = ((mMidRaw + sMidRaw) * ((t_sample)0.5));
			t_sample rMidPre = ((mMidRaw - sMidRaw) * ((t_sample)0.5));
			m_mid_EL_49 = fixdenorm((m_mid_EL_49 + (alpha_mid * ((lMidPre * lMidPre) - m_mid_EL_49))));
			m_mid_ER_48 = fixdenorm((m_mid_ER_48 + (alpha_mid * ((rMidPre * rMidPre) - m_mid_ER_48))));
			m_mid_CCS_43 = fixdenorm((m_mid_CCS_43 + (alpha_mid * ((lMidPre * rMidPre) - m_mid_CCS_43))));
			m_mid_EM_45 = fixdenorm((m_mid_EM_45 + (alpha_mid * ((mMidRaw * mMidRaw) - m_mid_EM_45))));
			m_mid_ES_44 = fixdenorm((m_mid_ES_44 + (alpha_mid * ((sMidRaw * sMidRaw) - m_mid_ES_44))));
			t_sample a_mid = (((t_sample)0.5) * (gM_mid + gS_mid));
			t_sample b_mid_10025 = (((t_sample)0.5) * (gM_mid - gS_mid));
			t_sample Pin_mid = ((m_mid_EL_49 + m_mid_ER_48) + ((t_sample)1e-12));
			t_sample Pout_mid = (((((a_mid * a_mid) + (b_mid_10025 * b_mid_10025)) * (m_mid_EL_49 + m_mid_ER_48)) + (((((int)4) * a_mid) * b_mid_10025) * m_mid_CCS_43)) + ((t_sample)1e-12));
			t_sample G_mid = sqrt(safediv(Pin_mid, Pout_mid));
			t_sample G_mid_10026 = ((G_mid <= ((t_sample)0.59566214352901)) ? ((t_sample)0.59566214352901) : ((G_mid >= ((t_sample)1.6788040181226)) ? ((t_sample)1.6788040181226) : G_mid));
			t_sample rho_mid_num = m_mid_CCS_43;
			t_sample maxa_264 = (m_mid_EL_49 * m_mid_ER_48);
			t_sample rho_mid_den = sqrt(((maxa_264 < ((t_sample)1e-12)) ? ((t_sample)1e-12) : maxa_264));
			t_sample v_265 = safediv(rho_mid_num, (rho_mid_den + ((t_sample)1e-12)));
			t_sample rho_mid = ((v_265 <= ((int)-1)) ? ((int)-1) : ((v_265 >= ((int)1)) ? ((int)1) : v_265));
			t_sample maxb_266 = (u_mid - ((t_sample)0.5));
			t_sample lift_base_mid = ((((int)0) < maxb_266) ? maxb_266 : ((int)0));
			t_sample lift_dB_mid = ((((int)6) * lift_base_mid) * (((int)1) - rho_mid));
			t_sample G_mid_10027 = (G_mid_10026 * dbtoa(lift_dB_mid));
			t_sample mul_542 = (mMidRaw * ((t_sample)0.5));
			t_sample mul_545 = (sMidRaw * ((t_sample)0.5));
			t_sample mul_544 = (mul_542 * (gM_mid * G_mid_10027));
			t_sample mul_546 = (mul_545 * (gS_mid * G_mid_10027));
			t_sample mul_547 = (mul_546 * gen_539);
			t_sample sub_548 = (mul_544 - mul_547);
			t_sample add_550 = (mul_544 + mul_547);
			t_sample mul_552 = (sub_548 * midBalGR);
			t_sample mul_553 = (mul_552 * dbtoa_496);
			t_sample mix_10142 = (midRIn + (rsub_491 * (mul_553 - midRIn)));
			t_sample mix_10143 = (muteMid + (((t_sample)0.999) * (m_mute_mid_h_56 - muteMid)));
			t_sample mute_mid_sm = mix_10143;
			m_mute_mid_h_56 = fixdenorm(mute_mid_sm);
			t_sample mid_gate = (((int)1) - ((mute_mid_sm <= ((int)0)) ? ((int)0) : ((mute_mid_sm >= ((int)1)) ? ((int)1) : mute_mid_sm)));
			t_sample gen_10028 = (mix_10142 * mid_gate);
			t_sample mul_556 = (add_550 * midBalGL);
			t_sample mul_557 = (mul_556 * dbtoa_496);
			t_sample mix_10144 = (midLIn + (rsub_491 * (mul_557 - midLIn)));
			t_sample gen_10029 = (mix_10144 * mid_gate);
			t_sample mix_10145 = (gen_10028 + (soloMaskMid * (((int)0) - gen_10028)));
			t_sample mix_10146 = (gen_10029 + (soloMaskMid * (((int)0) - gen_10029)));
			t_sample d_balance_566 = ((setparam_256 <= ((int)0)) ? ((int)0) : ((setparam_256 >= ((int)1)) ? ((int)1) : setparam_256));
			t_sample e_wide_567 = ((setparam_251 <= ((int)0)) ? ((int)0) : ((setparam_251 >= ((int)200)) ? ((int)200) : setparam_251));
			t_sample a_input_569 = ((setparam_225 <= ((int)0)) ? ((int)0) : ((setparam_225 >= ((int)1)) ? ((int)1) : setparam_225));
			t_sample mix_10147 = (((int)0) + (((t_sample)0.999) * (m_history_64 - ((int)0))));
			t_sample mix_571 = mix_10147;
			t_sample gen_572 = mix_571;
			t_sample history_74_next_573 = fixdenorm(mix_571);
			t_sample rsub_574 = (((int)1) - gen_572);
			t_sample mix_10148 = (((int)0) + (((t_sample)0.999) * (m_history_63 - ((int)0))));
			t_sample mix_576 = mix_10148;
			t_sample gen_577 = mix_576;
			t_sample history_75_next_578 = fixdenorm(mix_576);
			t_sample dbtoa_579 = dbtoa(gen_577);
			t_sample mix_10149 = (d_balance_566 + (((t_sample)0.999) * (m_history_62 - d_balance_566)));
			t_sample mix_581 = mix_10149;
			t_sample gen_582 = mix_581;
			t_sample history_76_next_583 = fixdenorm(mix_581);
			t_sample highBalT = ((gen_582 - ((t_sample)0.5)) * ((int)2));
			t_sample highBalPos = ((highBalT < ((int)0)) ? ((int)0) : highBalT);
			t_sample highBalNeg = ((((int)0) < highBalT) ? ((int)0) : highBalT);
			t_sample v_267 = (((int)1) - highBalPos);
			t_sample highBalGL = ((v_267 <= ((int)0)) ? ((int)0) : ((v_267 >= ((int)1)) ? ((int)1) : v_267));
			t_sample v_268 = (((int)1) + highBalNeg);
			t_sample highBalGR = ((v_268 <= ((int)0)) ? ((int)0) : ((v_268 >= ((int)1)) ? ((int)1) : v_268));
			t_sample mix_10150 = (e_wide_567 + (((t_sample)0.999) * (m_history_61 - e_wide_567)));
			t_sample mix_588 = mix_10150;
			t_sample gen_589 = mix_588;
			t_sample history_77_next_590 = fixdenorm(mix_588);
			t_sample mix_10151 = (a_input_569 + (((t_sample)0.999) * (m_history_60 - a_input_569)));
			t_sample mix_594 = mix_10151;
			t_sample gen_595 = mix_594;
			t_sample history_78_next_596 = fixdenorm(mix_594);
			t_sample mix_10152 = (highLIn + (gen_595 * (((int)0) - highLIn)));
			t_sample mix_597 = mix_10152;
			t_sample mix_10153 = (highRIn + (gen_595 * (((int)0) - highRIn)));
			t_sample mix_598 = mix_10153;
			t_sample mix_10154 = (((int)0) + (gen_595 * (highLIn - ((int)0))));
			t_sample mix_599 = mix_10154;
			t_sample mix_10155 = (((int)0) + (gen_595 * (highRIn - ((int)0))));
			t_sample mix_600 = mix_10155;
			t_sample add_601 = (mix_599 + mix_600);
			t_sample sub_602 = (mix_599 - mix_600);
			t_sample mix_10156 = (((int)1) + (((t_sample)0.999) * (m_history_59 - ((int)1))));
			t_sample mix_605 = mix_10156;
			t_sample gen_606 = mix_605;
			t_sample history_79_next_607 = fixdenorm(mix_605);
			t_sample m_608 = gen_606;
			t_sample mul_609 = ((add_601 + mix_597) * m_608);
			t_sample mix_10157 = (((int)1) + (((t_sample)0.999) * (m_history_58 - ((int)1))));
			t_sample mix_612 = mix_10157;
			t_sample gen_613 = mix_612;
			t_sample history_80_next_614 = fixdenorm(mix_612);
			t_sample s_615 = gen_613;
			t_sample mul_616 = ((mix_598 + sub_602) * s_615);
			t_sample mix_10158 = (((int)1) + (((int)0) * (m_history_39 - ((int)1))));
			t_sample mix_621 = mix_10158;
			t_sample gen_622 = mix_621;
			t_sample history_81_next_623 = fixdenorm(mix_621);
			t_sample alpha_high = (((int)1) - exp(safediv(((int)-1), (((t_sample)0.08) * samplerate))));
			t_sample mHighRaw = mul_609;
			t_sample sHighRaw = mul_616;
			t_sample w_high_c = ((gen_589 <= ((int)0)) ? ((int)0) : ((gen_589 >= ((int)2)) ? ((int)2) : gen_589));
			t_sample u_high = (w_high_c * ((t_sample)0.5));
			t_sample theta_high = (u_high * ((t_sample)1.2319971190549));
			t_sample gM_high = cos(theta_high);
			t_sample gS_high = sin(theta_high);
			t_sample lHighPre = ((mHighRaw + sHighRaw) * ((t_sample)0.5));
			t_sample rHighPre = ((mHighRaw - sHighRaw) * ((t_sample)0.5));
			m_high_EL_47 = fixdenorm((m_high_EL_47 + (alpha_high * ((lHighPre * lHighPre) - m_high_EL_47))));
			m_high_ER_46 = fixdenorm((m_high_ER_46 + (alpha_high * ((rHighPre * rHighPre) - m_high_ER_46))));
			m_high_CCS_40 = fixdenorm((m_high_CCS_40 + (alpha_high * ((lHighPre * rHighPre) - m_high_CCS_40))));
			m_high_EM_42 = fixdenorm((m_high_EM_42 + (alpha_high * ((mHighRaw * mHighRaw) - m_high_EM_42))));
			m_high_ES_41 = fixdenorm((m_high_ES_41 + (alpha_high * ((sHighRaw * sHighRaw) - m_high_ES_41))));
			t_sample a_high = (((t_sample)0.5) * (gM_high + gS_high));
			t_sample b_high = (((t_sample)0.5) * (gM_high - gS_high));
			t_sample Pin_high = ((m_high_EL_47 + m_high_ER_46) + ((t_sample)1e-12));
			t_sample Pout_high = (((((a_high * a_high) + (b_high * b_high)) * (m_high_EL_47 + m_high_ER_46)) + (((((int)4) * a_high) * b_high) * m_high_CCS_40)) + ((t_sample)1e-12));
			t_sample G_high = sqrt(safediv(Pin_high, Pout_high));
			t_sample G_high_10030 = ((G_high <= ((t_sample)0.59566214352901)) ? ((t_sample)0.59566214352901) : ((G_high >= ((t_sample)1.6788040181226)) ? ((t_sample)1.6788040181226) : G_high));
			t_sample rho_high_num = m_high_CCS_40;
			t_sample maxa_269 = (m_high_EL_47 * m_high_ER_46);
			t_sample rho_high_den = sqrt(((maxa_269 < ((t_sample)1e-12)) ? ((t_sample)1e-12) : maxa_269));
			t_sample v_270 = safediv(rho_high_num, (rho_high_den + ((t_sample)1e-12)));
			t_sample rho_high = ((v_270 <= ((int)-1)) ? ((int)-1) : ((v_270 >= ((int)1)) ? ((int)1) : v_270));
			t_sample maxb_271 = (u_high - ((t_sample)0.5));
			t_sample lift_base_high = ((((int)0) < maxb_271) ? maxb_271 : ((int)0));
			t_sample lift_dB_high = ((((int)6) * lift_base_high) * (((int)1) - rho_high));
			t_sample G_high_10031 = (G_high_10030 * dbtoa(lift_dB_high));
			t_sample mul_625 = (mHighRaw * ((t_sample)0.5));
			t_sample mul_628 = (sHighRaw * ((t_sample)0.5));
			t_sample mul_627 = (mul_625 * (gM_high * G_high_10031));
			t_sample mul_629 = (mul_628 * (gS_high * G_high_10031));
			t_sample mul_630 = (mul_629 * gen_622);
			t_sample sub_631 = (mul_627 - mul_630);
			t_sample add_633 = (mul_627 + mul_630);
			t_sample mul_635 = (add_633 * highBalGL);
			t_sample mul_636 = (mul_635 * dbtoa_579);
			t_sample mix_10159 = (highLIn + (rsub_574 * (mul_636 - highLIn)));
			t_sample mix_10160 = (muteHigh + (((t_sample)0.999) * (m_mute_high_h_55 - muteHigh)));
			t_sample mute_high_sm = mix_10160;
			m_mute_high_h_55 = fixdenorm(mute_high_sm);
			t_sample high_gate = (((int)1) - ((mute_high_sm <= ((int)0)) ? ((int)0) : ((mute_high_sm >= ((int)1)) ? ((int)1) : mute_high_sm)));
			t_sample gen_10032 = (mix_10159 * high_gate);
			t_sample mul_639 = (sub_631 * highBalGR);
			t_sample mul_640 = (mul_639 * dbtoa_579);
			t_sample mix_10161 = (highRIn + (rsub_574 * (mul_640 - highRIn)));
			t_sample gen_10033 = (mix_10161 * high_gate);
			t_sample wetMakeupL = w_muL_next;
			t_sample wetMakeupR = w_muR_next;
			t_sample mix_10162 = (gen_10033 + (soloMaskHigh * (((int)0) - gen_10033)));
			t_sample wetSumR = ((mix_10162 + mix_10145) + mix_10128);
			t_sample mul_10164 = (wetSumR * wetMakeupR);
			t_sample mix_10163 = (expr_114 + (gen_198 * (mul_10164 - expr_114)));
			t_sample mix_10165 = (in2 + (rsub_204 * (mix_10163 - in2)));
			t_sample mix_10166 = (gen_10032 + (soloMaskHigh * (((int)0) - gen_10032)));
			t_sample wetSumL = ((mix_10166 + mix_10146) + mix_10129);
			t_sample mul_10168 = (wetSumL * wetMakeupL);
			t_sample mix_10167 = (expr_195 + (gen_198 * (mul_10168 - expr_195)));
			t_sample mix_10169 = (in1 + (rsub_204 * (mix_10167 - in1)));
			m_history_185 = history_1_next_199;
			m_history_63 = history_75_next_578;
			m_history_62 = history_76_next_583;
			m_history_61 = history_77_next_590;
			m_history_60 = history_78_next_596;
			m_history_59 = history_79_next_607;
			m_history_58 = history_80_next_614;
			m_history_39 = history_81_next_623;
			m_history_64 = history_74_next_573;
			m_history_71 = history_67_next_495;
			m_history_70 = history_68_next_500;
			m_history_69 = history_69_next_507;
			m_history_68 = history_70_next_513;
			m_history_67 = history_71_next_524;
			m_history_66 = history_72_next_531;
			m_history_65 = history_73_next_540;
			m_history_72 = history_66_next_490;
			m_history_75 = history_63_next_435;
			m_history_74 = history_64_next_444;
			m_history_73 = history_65_next_450;
			m_history_76 = history_62_next_429;
			m_history_173 = history_13_next_265;
			m_history_174 = history_12_next_260;
			m_history_175 = history_11_next_255;
			m_history_176 = history_10_next_250;
			m_history_177 = history_9_next_243;
			m_history_178 = history_8_next_238;
			m_history_179 = history_7_next_231;
			m_history_180 = history_6_next_224;
			m_history_181 = history_5_next_218;
			m_history_182 = history_4_next_213;
			m_history_183 = history_3_next_209;
			m_history_184 = history_2_next_203;
			m_w_trimL_6 = w_trimL_next;
			m_w_trimR_5 = w_trimR_next;
			m_w_trimS_2 = w_trimS_next;
			m_w_muL_4 = w_muL_next;
			m_w_muR_3 = w_muR_next;
			m_w_muS_1 = w_muS_next;
			t_sample out1 = mix_10169;
			t_sample out4 = expr_10037;
			t_sample out2 = mix_10165;
			t_sample out3 = expr_10036;
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
