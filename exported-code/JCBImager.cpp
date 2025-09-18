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
	t_sample m_h2_y_151;
	t_sample m_h2_y_152;
	t_sample m_h2_x_153;
	t_sample m_h2_x_154;
	t_sample m_m1_x_150;
	t_sample m_h1_y_155;
	t_sample m_m1_x_149;
	t_sample m_m1_y_147;
	t_sample m_m2_y_144;
	t_sample m_m1_y_148;
	t_sample m_m2_x_145;
	t_sample m_m2_x_146;
	t_sample m_m2_y_143;
	t_sample m_h1_y_156;
	t_sample m_h1_x_158;
	t_sample m_l1_x_166;
	t_sample m_l1_x_165;
	t_sample m_history_167;
	t_sample m_history_168;
	t_sample m_h1_x_157;
	t_sample m_l1_y_164;
	t_sample m_l2_x_162;
	t_sample m_l2_y_159;
	t_sample m_l1_y_163;
	t_sample m_l2_y_160;
	t_sample m_l2_x_161;
	t_sample m_u1_x_142;
	t_sample m_u1_x_141;
	t_sample m_u1_y_140;
	t_sample m_ap_low_hp2_x_122;
	t_sample m_ap_low_hp2_x_121;
	t_sample m_ap_low_hp1_y_123;
	t_sample m_ap_low_hp1_x_125;
	t_sample m_ap_low_hp1_y_124;
	t_sample m_ap_low_hp1_x_126;
	t_sample m_ap_low_hp2_y_120;
	t_sample m_l1_x_118;
	t_sample m_l1_y_115;
	t_sample m_ap_low_hp2_y_119;
	t_sample m_l1_y_116;
	t_sample m_l1_x_117;
	t_sample m_history_169;
	t_sample m_ap_low_lp2_y_127;
	t_sample m_ap_low_lp2_x_129;
	t_sample m_u2_x_137;
	t_sample m_u2_y_136;
	t_sample m_u2_x_138;
	t_sample m_u1_y_139;
	t_sample m_ap_low_lp2_y_128;
	t_sample m_u2_y_135;
	t_sample m_ap_low_lp1_x_133;
	t_sample m_ap_low_lp2_x_130;
	t_sample m_ap_low_lp1_x_134;
	t_sample m_ap_low_lp1_y_131;
	t_sample m_ap_low_lp1_y_132;
	t_sample m_history_170;
	t_sample m_history_171;
	t_sample m_history_172;
	t_sample m_ap1_lp1_y_209;
	t_sample m_ap1_lp1_y_208;
	t_sample m_ap1_lp1_x_210;
	t_sample m_p_MUTHIGH_212;
	t_sample m_ap1_lp1_x_211;
	t_sample m_o_MUTMED_213;
	t_sample m_ap1_lp2_x_207;
	t_sample m_ap1_lp2_y_205;
	t_sample m_ap1_hp1_x_202;
	t_sample m_ap1_lp2_x_206;
	t_sample m_ap1_hp1_x_203;
	t_sample m_ap1_lp2_y_204;
	t_sample m_ap1_hp1_y_201;
	t_sample m_n_MUTLOW_214;
	t_sample m_m_HIGH_bal_216;
	t_sample m_e_HIGH_224;
	t_sample m_f_SOLOLOW_223;
	t_sample m_d_MED_225;
	t_sample m_c_LOW_226;
	t_sample m_x_DRYWET_215;
	t_sample m_g_SOLOMED_222;
	t_sample m_i_BYPASS_220;
	t_sample m_l_MED_bal_217;
	t_sample m_h_SOLOHIGH_221;
	t_sample m_k_LOW_bal_218;
	t_sample m_j_input_219;
	t_sample m_l2_x_114;
	t_sample m_ap1_hp1_y_200;
	t_sample m_ap1_hp2_x_198;
	t_sample m_ap2_hp2_y_180;
	t_sample m_history_179;
	t_sample m_ap2_hp2_y_181;
	t_sample m_ap2_hp2_x_183;
	t_sample m_ap2_hp2_x_182;
	t_sample m_ap2_hp1_y_184;
	t_sample m_history_178;
	t_sample m_history_176;
	t_sample m_history_173;
	t_sample m_history_177;
	t_sample m_history_174;
	t_sample m_history_175;
	t_sample m_ap1_hp2_x_199;
	t_sample m_ap2_hp1_y_185;
	t_sample m_ap2_hp1_x_187;
	t_sample m_ap2_lp1_x_195;
	t_sample m_ap2_lp1_x_194;
	t_sample m_ap1_hp2_y_196;
	t_sample m_ap1_hp2_y_197;
	t_sample m_ap2_hp1_x_186;
	t_sample m_ap2_lp1_y_193;
	t_sample m_ap2_lp2_x_191;
	t_sample m_ap2_lp2_y_188;
	t_sample m_ap2_lp1_y_192;
	t_sample m_ap2_lp2_y_189;
	t_sample m_ap2_lp2_x_190;
	t_sample m_b_FREQ_227;
	t_sample m_l2_x_113;
	t_sample m_l2_y_111;
	t_sample m_high_EM_36;
	t_sample m_high_ES_35;
	t_sample m_mid_CCS_37;
	t_sample m_mid_EM_39;
	t_sample m_mid_ES_38;
	t_sample m_high_ER_40;
	t_sample m_high_CCS_34;
	t_sample m_ap1_lp1_x_32;
	t_sample m_ap1_lp1_y_29;
	t_sample m_history_33;
	t_sample m_ap1_lp1_y_30;
	t_sample m_ap1_lp1_x_31;
	t_sample m_ap1_lp2_x_28;
	t_sample m_high_EL_41;
	t_sample m_mid_EL_43;
	t_sample m_mute_low_h_51;
	t_sample m_mute_mid_h_50;
	t_sample m_history_52;
	t_sample m_history_53;
	t_sample m_mid_ER_42;
	t_sample m_mute_high_h_49;
	t_sample m_low_ES_47;
	t_sample m_low_ER_44;
	t_sample m_low_EM_48;
	t_sample m_low_EL_45;
	t_sample m_low_CCS_46;
	t_sample m_history_54;
	t_sample m_ap1_lp2_x_27;
	t_sample m_ap1_lp2_y_25;
	t_sample m_ap2_hp1_x_7;
	t_sample m_ap2_hp1_y_6;
	t_sample m_ap2_hp1_x_8;
	t_sample m_ap2_lp2_y_10;
	t_sample m_ap2_lp2_y_9;
	t_sample m_ap2_lp2_x_11;
	t_sample m_ap2_hp1_y_5;
	t_sample m_ap2_hp2_x_3;
	t_sample samplerate;
	t_sample m_ap2_hp2_x_4;
	t_sample m_ap2_hp2_y_1;
	t_sample m_ap2_hp2_y_2;
	t_sample m_ap1_lp2_y_26;
	t_sample m_ap2_lp2_x_12;
	t_sample m_ap2_lp1_y_14;
	t_sample m_ap1_hp1_y_22;
	t_sample m_ap1_hp1_y_21;
	t_sample m_ap1_hp1_x_23;
	t_sample m_ap1_hp1_x_24;
	t_sample m_ap2_lp1_y_13;
	t_sample m_ap1_hp2_x_20;
	t_sample m_ap1_hp2_y_18;
	t_sample m_ap2_lp1_x_15;
	t_sample m_ap1_hp2_x_19;
	t_sample m_ap2_lp1_x_16;
	t_sample m_ap1_hp2_y_17;
	t_sample m_l2_y_112;
	t_sample m_history_55;
	t_sample m_history_57;
	t_sample m_u1_x_93;
	t_sample m_u1_y_92;
	t_sample m_u1_x_94;
	t_sample m_m2_y_96;
	t_sample m_m2_y_95;
	t_sample m_m2_x_97;
	t_sample m_u1_y_91;
	t_sample m_u2_x_89;
	t_sample m_ap_low_lp1_x_86;
	t_sample m_u2_x_90;
	t_sample m_u2_y_87;
	t_sample m_u2_y_88;
	t_sample m_ap_low_lp1_x_85;
	t_sample m_m2_x_98;
	t_sample m_m1_y_100;
	t_sample m_h1_y_108;
	t_sample m_h1_y_107;
	t_sample m_h1_x_109;
	t_sample m_h1_x_110;
	t_sample m_m1_y_99;
	t_sample m_h2_x_106;
	t_sample m_h2_y_104;
	t_sample m_m1_x_101;
	t_sample m_h2_x_105;
	t_sample m_m1_x_102;
	t_sample m_h2_y_103;
	t_sample m_history_56;
	t_sample m_ap_low_lp1_y_84;
	t_sample m_ap_low_lp2_x_82;
	t_sample m_history_65;
	t_sample m_history_64;
	t_sample m_history_66;
	t_sample m_history_67;
	t_sample m_history_68;
	t_sample m_history_63;
	t_sample m_history_61;
	t_sample m_history_58;
	t_sample m_history_62;
	t_sample m_history_59;
	t_sample m_history_60;
	t_sample m_ap_low_lp1_y_83;
	t_sample m_history_69;
	t_sample m_ap_low_hp2_y_71;
	t_sample m_ap_low_lp2_y_79;
	t_sample m_ap_low_hp1_x_78;
	t_sample m_ap_low_lp2_y_80;
	t_sample m_ap_low_lp2_x_81;
	t_sample m_history_70;
	t_sample m_ap_low_hp1_x_77;
	t_sample m_ap_low_hp1_y_75;
	t_sample m_ap_low_hp2_y_72;
	t_sample m_ap_low_hp1_y_76;
	t_sample m_ap_low_hp2_x_73;
	t_sample m_ap_low_hp2_x_74;
	t_sample m_a_FREQ_228;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_ap2_hp2_y_1 = ((int)0);
		m_ap2_hp2_y_2 = ((int)0);
		m_ap2_hp2_x_3 = ((int)0);
		m_ap2_hp2_x_4 = ((int)0);
		m_ap2_hp1_y_5 = ((int)0);
		m_ap2_hp1_y_6 = ((int)0);
		m_ap2_hp1_x_7 = ((int)0);
		m_ap2_hp1_x_8 = ((int)0);
		m_ap2_lp2_y_9 = ((int)0);
		m_ap2_lp2_y_10 = ((int)0);
		m_ap2_lp2_x_11 = ((int)0);
		m_ap2_lp2_x_12 = ((int)0);
		m_ap2_lp1_y_13 = ((int)0);
		m_ap2_lp1_y_14 = ((int)0);
		m_ap2_lp1_x_15 = ((int)0);
		m_ap2_lp1_x_16 = ((int)0);
		m_ap1_hp2_y_17 = ((int)0);
		m_ap1_hp2_y_18 = ((int)0);
		m_ap1_hp2_x_19 = ((int)0);
		m_ap1_hp2_x_20 = ((int)0);
		m_ap1_hp1_y_21 = ((int)0);
		m_ap1_hp1_y_22 = ((int)0);
		m_ap1_hp1_x_23 = ((int)0);
		m_ap1_hp1_x_24 = ((int)0);
		m_ap1_lp2_y_25 = ((int)0);
		m_ap1_lp2_y_26 = ((int)0);
		m_ap1_lp2_x_27 = ((int)0);
		m_ap1_lp2_x_28 = ((int)0);
		m_ap1_lp1_y_29 = ((int)0);
		m_ap1_lp1_y_30 = ((int)0);
		m_ap1_lp1_x_31 = ((int)0);
		m_ap1_lp1_x_32 = ((int)0);
		m_history_33 = ((int)0);
		m_high_CCS_34 = ((int)0);
		m_high_ES_35 = ((t_sample)1e-12);
		m_high_EM_36 = ((t_sample)1e-12);
		m_mid_CCS_37 = ((int)0);
		m_mid_ES_38 = ((t_sample)1e-12);
		m_mid_EM_39 = ((t_sample)1e-12);
		m_high_ER_40 = ((t_sample)1e-12);
		m_high_EL_41 = ((t_sample)1e-12);
		m_mid_ER_42 = ((t_sample)1e-12);
		m_mid_EL_43 = ((t_sample)1e-12);
		m_low_ER_44 = ((t_sample)1e-12);
		m_low_EL_45 = ((t_sample)1e-12);
		m_low_CCS_46 = ((int)0);
		m_low_ES_47 = ((t_sample)1e-12);
		m_low_EM_48 = ((t_sample)1e-12);
		m_mute_high_h_49 = ((int)0);
		m_mute_mid_h_50 = ((int)0);
		m_mute_low_h_51 = ((int)0);
		m_history_52 = ((int)0);
		m_history_53 = ((int)0);
		m_history_54 = ((int)0);
		m_history_55 = ((int)0);
		m_history_56 = ((int)0);
		m_history_57 = ((int)0);
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
		m_ap_low_hp2_y_71 = ((int)0);
		m_ap_low_hp2_y_72 = ((int)0);
		m_ap_low_hp2_x_73 = ((int)0);
		m_ap_low_hp2_x_74 = ((int)0);
		m_ap_low_hp1_y_75 = ((int)0);
		m_ap_low_hp1_y_76 = ((int)0);
		m_ap_low_hp1_x_77 = ((int)0);
		m_ap_low_hp1_x_78 = ((int)0);
		m_ap_low_lp2_y_79 = ((int)0);
		m_ap_low_lp2_y_80 = ((int)0);
		m_ap_low_lp2_x_81 = ((int)0);
		m_ap_low_lp2_x_82 = ((int)0);
		m_ap_low_lp1_y_83 = ((int)0);
		m_ap_low_lp1_y_84 = ((int)0);
		m_ap_low_lp1_x_85 = ((int)0);
		m_ap_low_lp1_x_86 = ((int)0);
		m_u2_y_87 = ((int)0);
		m_u2_y_88 = ((int)0);
		m_u2_x_89 = ((int)0);
		m_u2_x_90 = ((int)0);
		m_u1_y_91 = ((int)0);
		m_u1_y_92 = ((int)0);
		m_u1_x_93 = ((int)0);
		m_u1_x_94 = ((int)0);
		m_m2_y_95 = ((int)0);
		m_m2_y_96 = ((int)0);
		m_m2_x_97 = ((int)0);
		m_m2_x_98 = ((int)0);
		m_m1_y_99 = ((int)0);
		m_m1_y_100 = ((int)0);
		m_m1_x_101 = ((int)0);
		m_m1_x_102 = ((int)0);
		m_h2_y_103 = ((int)0);
		m_h2_y_104 = ((int)0);
		m_h2_x_105 = ((int)0);
		m_h2_x_106 = ((int)0);
		m_h1_y_107 = ((int)0);
		m_h1_y_108 = ((int)0);
		m_h1_x_109 = ((int)0);
		m_h1_x_110 = ((int)0);
		m_l2_y_111 = ((int)0);
		m_l2_y_112 = ((int)0);
		m_l2_x_113 = ((int)0);
		m_l2_x_114 = ((int)0);
		m_l1_y_115 = ((int)0);
		m_l1_y_116 = ((int)0);
		m_l1_x_117 = ((int)0);
		m_l1_x_118 = ((int)0);
		m_ap_low_hp2_y_119 = ((int)0);
		m_ap_low_hp2_y_120 = ((int)0);
		m_ap_low_hp2_x_121 = ((int)0);
		m_ap_low_hp2_x_122 = ((int)0);
		m_ap_low_hp1_y_123 = ((int)0);
		m_ap_low_hp1_y_124 = ((int)0);
		m_ap_low_hp1_x_125 = ((int)0);
		m_ap_low_hp1_x_126 = ((int)0);
		m_ap_low_lp2_y_127 = ((int)0);
		m_ap_low_lp2_y_128 = ((int)0);
		m_ap_low_lp2_x_129 = ((int)0);
		m_ap_low_lp2_x_130 = ((int)0);
		m_ap_low_lp1_y_131 = ((int)0);
		m_ap_low_lp1_y_132 = ((int)0);
		m_ap_low_lp1_x_133 = ((int)0);
		m_ap_low_lp1_x_134 = ((int)0);
		m_u2_y_135 = ((int)0);
		m_u2_y_136 = ((int)0);
		m_u2_x_137 = ((int)0);
		m_u2_x_138 = ((int)0);
		m_u1_y_139 = ((int)0);
		m_u1_y_140 = ((int)0);
		m_u1_x_141 = ((int)0);
		m_u1_x_142 = ((int)0);
		m_m2_y_143 = ((int)0);
		m_m2_y_144 = ((int)0);
		m_m2_x_145 = ((int)0);
		m_m2_x_146 = ((int)0);
		m_m1_y_147 = ((int)0);
		m_m1_y_148 = ((int)0);
		m_m1_x_149 = ((int)0);
		m_m1_x_150 = ((int)0);
		m_h2_y_151 = ((int)0);
		m_h2_y_152 = ((int)0);
		m_h2_x_153 = ((int)0);
		m_h2_x_154 = ((int)0);
		m_h1_y_155 = ((int)0);
		m_h1_y_156 = ((int)0);
		m_h1_x_157 = ((int)0);
		m_h1_x_158 = ((int)0);
		m_l2_y_159 = ((int)0);
		m_l2_y_160 = ((int)0);
		m_l2_x_161 = ((int)0);
		m_l2_x_162 = ((int)0);
		m_l1_y_163 = ((int)0);
		m_l1_y_164 = ((int)0);
		m_l1_x_165 = ((int)0);
		m_l1_x_166 = ((int)0);
		m_history_167 = ((int)0);
		m_history_168 = ((int)0);
		m_history_169 = ((int)0);
		m_history_170 = ((int)0);
		m_history_171 = ((int)0);
		m_history_172 = ((int)0);
		m_history_173 = ((int)0);
		m_history_174 = ((int)0);
		m_history_175 = ((int)0);
		m_history_176 = ((int)0);
		m_history_177 = ((int)0);
		m_history_178 = ((int)0);
		m_history_179 = ((int)0);
		m_ap2_hp2_y_180 = ((int)0);
		m_ap2_hp2_y_181 = ((int)0);
		m_ap2_hp2_x_182 = ((int)0);
		m_ap2_hp2_x_183 = ((int)0);
		m_ap2_hp1_y_184 = ((int)0);
		m_ap2_hp1_y_185 = ((int)0);
		m_ap2_hp1_x_186 = ((int)0);
		m_ap2_hp1_x_187 = ((int)0);
		m_ap2_lp2_y_188 = ((int)0);
		m_ap2_lp2_y_189 = ((int)0);
		m_ap2_lp2_x_190 = ((int)0);
		m_ap2_lp2_x_191 = ((int)0);
		m_ap2_lp1_y_192 = ((int)0);
		m_ap2_lp1_y_193 = ((int)0);
		m_ap2_lp1_x_194 = ((int)0);
		m_ap2_lp1_x_195 = ((int)0);
		m_ap1_hp2_y_196 = ((int)0);
		m_ap1_hp2_y_197 = ((int)0);
		m_ap1_hp2_x_198 = ((int)0);
		m_ap1_hp2_x_199 = ((int)0);
		m_ap1_hp1_y_200 = ((int)0);
		m_ap1_hp1_y_201 = ((int)0);
		m_ap1_hp1_x_202 = ((int)0);
		m_ap1_hp1_x_203 = ((int)0);
		m_ap1_lp2_y_204 = ((int)0);
		m_ap1_lp2_y_205 = ((int)0);
		m_ap1_lp2_x_206 = ((int)0);
		m_ap1_lp2_x_207 = ((int)0);
		m_ap1_lp1_y_208 = ((int)0);
		m_ap1_lp1_y_209 = ((int)0);
		m_ap1_lp1_x_210 = ((int)0);
		m_ap1_lp1_x_211 = ((int)0);
		m_p_MUTHIGH_212 = 0;
		m_o_MUTMED_213 = 0;
		m_n_MUTLOW_214 = 0;
		m_x_DRYWET_215 = 1;
		m_m_HIGH_bal_216 = 0.5;
		m_l_MED_bal_217 = 0.5;
		m_k_LOW_bal_218 = 0.5;
		m_j_input_219 = 1;
		m_i_BYPASS_220 = 0;
		m_h_SOLOHIGH_221 = 0;
		m_g_SOLOMED_222 = 0;
		m_f_SOLOLOW_223 = 0;
		m_e_HIGH_224 = 1;
		m_d_MED_225 = 1;
		m_c_LOW_226 = 1;
		m_b_FREQ_227 = 5000;
		m_a_FREQ_228 = 250;
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample xoverLow = ((m_a_FREQ_228 <= ((int)20)) ? ((int)20) : ((m_a_FREQ_228 >= ((int)1000)) ? ((int)1000) : m_a_FREQ_228));
		t_sample xoverHigh = ((m_b_FREQ_227 <= ((int)1000)) ? ((int)1000) : ((m_b_FREQ_227 >= ((int)20000)) ? ((int)20000) : m_b_FREQ_227));
		int sr = samplerate;
		t_sample minb_229 = (((t_sample)0.45) * sr);
		t_sample maxb_230 = ((minb_229 < xoverLow) ? minb_229 : xoverLow);
		t_sample loF = ((((int)10) < maxb_230) ? maxb_230 : ((int)10));
		t_sample minb_231 = (((t_sample)0.45) * sr);
		t_sample maxb_232 = ((minb_231 < xoverHigh) ? minb_231 : xoverHigh);
		t_sample hiFr = ((((int)10) < maxb_232) ? maxb_232 : ((int)10));
		t_sample maxb_233 = (loF + ((int)1));
		t_sample hiF = ((hiFr < maxb_233) ? maxb_233 : hiFr);
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
		int sr_116 = samplerate;
		t_sample minb_234 = (((t_sample)0.45) * sr_116);
		t_sample maxb_235 = ((minb_234 < xoverLow) ? minb_234 : xoverLow);
		t_sample loF_117 = ((((int)10) < maxb_235) ? maxb_235 : ((int)10));
		t_sample minb_236 = (((t_sample)0.45) * sr_116);
		t_sample maxb_237 = ((minb_236 < xoverHigh) ? minb_236 : xoverHigh);
		t_sample hiFr_118 = ((((int)10) < maxb_237) ? maxb_237 : ((int)10));
		t_sample maxb_238 = (loF_117 + ((int)1));
		t_sample hiF_119 = ((hiFr_118 < maxb_238) ? maxb_238 : hiFr_118);
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
		t_sample setparam_220 = m_k_LOW_bal_218;
		int sr_270 = samplerate;
		t_sample minb_239 = (((t_sample)0.45) * sr_270);
		t_sample minb_241 = (((t_sample)0.45) * sr_270);
		int sr_318 = samplerate;
		t_sample minb_244 = (((t_sample)0.45) * sr_318);
		t_sample minb_246 = (((t_sample)0.45) * sr_318);
		t_sample d_balance = ((setparam_220 <= ((int)0)) ? ((int)0) : ((setparam_220 >= ((int)1)) ? ((int)1) : setparam_220));
		t_sample alpha_low = (((int)1) - exp(safediv(((int)-1), (((t_sample)0.08) * samplerate))));
		t_sample alpha_mid = (((int)1) - exp(safediv(((int)-1), (((t_sample)0.08) * samplerate))));
		t_sample alpha_high = (((int)1) - exp(safediv(((int)-1), (((t_sample)0.08) * samplerate))));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample x = in2;
			t_sample ap1_lp1_x1p = m_ap1_lp1_x_211;
			t_sample ap1_lp1_x2p = m_ap1_lp1_x_210;
			t_sample ap1_lp1_y1p = m_ap1_lp1_y_209;
			t_sample ap1_lp1_y2p = m_ap1_lp1_y_208;
			t_sample ap1_lp_s1 = (((((lp_b0_l * x) + (lp_b1_l * ap1_lp1_x1p)) + (lp_b2_l * ap1_lp1_x2p)) - (lp_a1_l * ap1_lp1_y1p)) - (lp_a2_l * ap1_lp1_y2p));
			m_ap1_lp1_x_210 = ap1_lp1_x1p;
			m_ap1_lp1_x_211 = x;
			m_ap1_lp1_y_208 = ap1_lp1_y1p;
			m_ap1_lp1_y_209 = ap1_lp_s1;
			t_sample ap1_lp2_x1p = m_ap1_lp2_x_207;
			t_sample ap1_lp2_x2p = m_ap1_lp2_x_206;
			t_sample ap1_lp2_y1p = m_ap1_lp2_y_205;
			t_sample ap1_lp2_y2p = m_ap1_lp2_y_204;
			t_sample ap1_lp = (((((lp_b0_l * ap1_lp_s1) + (lp_b1_l * ap1_lp2_x1p)) + (lp_b2_l * ap1_lp2_x2p)) - (lp_a1_l * ap1_lp2_y1p)) - (lp_a2_l * ap1_lp2_y2p));
			m_ap1_lp2_x_206 = ap1_lp2_x1p;
			m_ap1_lp2_x_207 = ap1_lp_s1;
			m_ap1_lp2_y_204 = ap1_lp2_y1p;
			m_ap1_lp2_y_205 = ap1_lp;
			t_sample ap1_hp1_x1p = m_ap1_hp1_x_203;
			t_sample ap1_hp1_x2p = m_ap1_hp1_x_202;
			t_sample ap1_hp1_y1p = m_ap1_hp1_y_201;
			t_sample ap1_hp1_y2p = m_ap1_hp1_y_200;
			t_sample ap1_hp_s1 = (((((hp_b0_l * x) + (hp_b1_l * ap1_hp1_x1p)) + (hp_b2_l * ap1_hp1_x2p)) - (hp_a1_l * ap1_hp1_y1p)) - (hp_a2_l * ap1_hp1_y2p));
			m_ap1_hp1_x_202 = ap1_hp1_x1p;
			m_ap1_hp1_x_203 = x;
			m_ap1_hp1_y_200 = ap1_hp1_y1p;
			m_ap1_hp1_y_201 = ap1_hp_s1;
			t_sample ap1_hp2_x1p = m_ap1_hp2_x_199;
			t_sample ap1_hp2_x2p = m_ap1_hp2_x_198;
			t_sample ap1_hp2_y1p = m_ap1_hp2_y_197;
			t_sample ap1_hp2_y2p = m_ap1_hp2_y_196;
			t_sample ap1_hp = (((((hp_b0_l * ap1_hp_s1) + (hp_b1_l * ap1_hp2_x1p)) + (hp_b2_l * ap1_hp2_x2p)) - (hp_a1_l * ap1_hp2_y1p)) - (hp_a2_l * ap1_hp2_y2p));
			m_ap1_hp2_x_198 = ap1_hp2_x1p;
			m_ap1_hp2_x_199 = ap1_hp_s1;
			m_ap1_hp2_y_196 = ap1_hp2_y1p;
			m_ap1_hp2_y_197 = ap1_hp;
			t_sample stage1_out = (ap1_lp + ap1_hp);
			t_sample ap2_lp1_x1p = m_ap2_lp1_x_195;
			t_sample ap2_lp1_x2p = m_ap2_lp1_x_194;
			t_sample ap2_lp1_y1p = m_ap2_lp1_y_193;
			t_sample ap2_lp1_y2p = m_ap2_lp1_y_192;
			t_sample ap2_lp_s1 = (((((lp_b0_h * stage1_out) + (lp_b1_h * ap2_lp1_x1p)) + (lp_b2_h * ap2_lp1_x2p)) - (lp_a1_h * ap2_lp1_y1p)) - (lp_a2_h * ap2_lp1_y2p));
			m_ap2_lp1_x_194 = ap2_lp1_x1p;
			m_ap2_lp1_x_195 = stage1_out;
			m_ap2_lp1_y_192 = ap2_lp1_y1p;
			m_ap2_lp1_y_193 = ap2_lp_s1;
			t_sample ap2_lp2_x1p = m_ap2_lp2_x_191;
			t_sample ap2_lp2_x2p = m_ap2_lp2_x_190;
			t_sample ap2_lp2_y1p = m_ap2_lp2_y_189;
			t_sample ap2_lp2_y2p = m_ap2_lp2_y_188;
			t_sample ap2_lp = (((((lp_b0_h * ap2_lp_s1) + (lp_b1_h * ap2_lp2_x1p)) + (lp_b2_h * ap2_lp2_x2p)) - (lp_a1_h * ap2_lp2_y1p)) - (lp_a2_h * ap2_lp2_y2p));
			m_ap2_lp2_x_190 = ap2_lp2_x1p;
			m_ap2_lp2_x_191 = ap2_lp_s1;
			m_ap2_lp2_y_188 = ap2_lp2_y1p;
			m_ap2_lp2_y_189 = ap2_lp;
			t_sample ap2_hp1_x1p = m_ap2_hp1_x_187;
			t_sample ap2_hp1_x2p = m_ap2_hp1_x_186;
			t_sample ap2_hp1_y1p = m_ap2_hp1_y_185;
			t_sample ap2_hp1_y2p = m_ap2_hp1_y_184;
			t_sample ap2_hp_s1 = (((((hp_b0_h * stage1_out) + (hp_b1_h * ap2_hp1_x1p)) + (hp_b2_h * ap2_hp1_x2p)) - (hp_a1_h * ap2_hp1_y1p)) - (hp_a2_h * ap2_hp1_y2p));
			m_ap2_hp1_x_186 = ap2_hp1_x1p;
			m_ap2_hp1_x_187 = stage1_out;
			m_ap2_hp1_y_184 = ap2_hp1_y1p;
			m_ap2_hp1_y_185 = ap2_hp_s1;
			t_sample ap2_hp2_x1p = m_ap2_hp2_x_183;
			t_sample ap2_hp2_x2p = m_ap2_hp2_x_182;
			t_sample ap2_hp2_y1p = m_ap2_hp2_y_181;
			t_sample ap2_hp2_y2p = m_ap2_hp2_y_180;
			t_sample ap2_hp = (((((hp_b0_h * ap2_hp_s1) + (hp_b1_h * ap2_hp2_x1p)) + (hp_b2_h * ap2_hp2_x2p)) - (hp_a1_h * ap2_hp2_y1p)) - (hp_a2_h * ap2_hp2_y2p));
			m_ap2_hp2_x_182 = ap2_hp2_x1p;
			m_ap2_hp2_x_183 = ap2_hp_s1;
			m_ap2_hp2_y_180 = ap2_hp2_y1p;
			m_ap2_hp2_y_181 = ap2_hp;
			t_sample expr_114 = (ap2_lp + ap2_hp);
			t_sample x_115 = in1;
			t_sample ap1_lp1_x1p_154 = m_ap1_lp1_x_32;
			t_sample ap1_lp1_x2p_155 = m_ap1_lp1_x_31;
			t_sample ap1_lp1_y1p_156 = m_ap1_lp1_y_30;
			t_sample ap1_lp1_y2p_157 = m_ap1_lp1_y_29;
			t_sample ap1_lp_s_158 = (((((lp_b0_l_127 * x_115) + (lp_b1_l_128 * ap1_lp1_x1p_154)) + (lp_b2_l_129 * ap1_lp1_x2p_155)) - (lp_a1_l_130 * ap1_lp1_y1p_156)) - (lp_a2_l_131 * ap1_lp1_y2p_157));
			m_ap1_lp1_x_31 = ap1_lp1_x1p_154;
			m_ap1_lp1_x_32 = x_115;
			m_ap1_lp1_y_29 = ap1_lp1_y1p_156;
			m_ap1_lp1_y_30 = ap1_lp_s_158;
			t_sample ap1_lp2_x1p_159 = m_ap1_lp2_x_28;
			t_sample ap1_lp2_x2p_160 = m_ap1_lp2_x_27;
			t_sample ap1_lp2_y1p_161 = m_ap1_lp2_y_26;
			t_sample ap1_lp2_y2p_162 = m_ap1_lp2_y_25;
			t_sample ap1_lp_163 = (((((lp_b0_l_127 * ap1_lp_s_158) + (lp_b1_l_128 * ap1_lp2_x1p_159)) + (lp_b2_l_129 * ap1_lp2_x2p_160)) - (lp_a1_l_130 * ap1_lp2_y1p_161)) - (lp_a2_l_131 * ap1_lp2_y2p_162));
			m_ap1_lp2_x_27 = ap1_lp2_x1p_159;
			m_ap1_lp2_x_28 = ap1_lp_s_158;
			m_ap1_lp2_y_25 = ap1_lp2_y1p_161;
			m_ap1_lp2_y_26 = ap1_lp_163;
			t_sample ap1_hp1_x1p_164 = m_ap1_hp1_x_24;
			t_sample ap1_hp1_x2p_165 = m_ap1_hp1_x_23;
			t_sample ap1_hp1_y1p_166 = m_ap1_hp1_y_22;
			t_sample ap1_hp1_y2p_167 = m_ap1_hp1_y_21;
			t_sample ap1_hp_s_168 = (((((hp_b0_l_132 * x_115) + (hp_b1_l_133 * ap1_hp1_x1p_164)) + (hp_b2_l_134 * ap1_hp1_x2p_165)) - (hp_a1_l_135 * ap1_hp1_y1p_166)) - (hp_a2_l_136 * ap1_hp1_y2p_167));
			m_ap1_hp1_x_23 = ap1_hp1_x1p_164;
			m_ap1_hp1_x_24 = x_115;
			m_ap1_hp1_y_21 = ap1_hp1_y1p_166;
			m_ap1_hp1_y_22 = ap1_hp_s_168;
			t_sample ap1_hp2_x1p_169 = m_ap1_hp2_x_20;
			t_sample ap1_hp2_x2p_170 = m_ap1_hp2_x_19;
			t_sample ap1_hp2_y1p_171 = m_ap1_hp2_y_18;
			t_sample ap1_hp2_y2p_172 = m_ap1_hp2_y_17;
			t_sample ap1_hp_173 = (((((hp_b0_l_132 * ap1_hp_s_168) + (hp_b1_l_133 * ap1_hp2_x1p_169)) + (hp_b2_l_134 * ap1_hp2_x2p_170)) - (hp_a1_l_135 * ap1_hp2_y1p_171)) - (hp_a2_l_136 * ap1_hp2_y2p_172));
			m_ap1_hp2_x_19 = ap1_hp2_x1p_169;
			m_ap1_hp2_x_20 = ap1_hp_s_168;
			m_ap1_hp2_y_17 = ap1_hp2_y1p_171;
			m_ap1_hp2_y_18 = ap1_hp_173;
			t_sample stage1_out_174 = (ap1_lp_163 + ap1_hp_173);
			t_sample ap2_lp1_x1p_175 = m_ap2_lp1_x_16;
			t_sample ap2_lp1_x2p_176 = m_ap2_lp1_x_15;
			t_sample ap2_lp1_y1p_177 = m_ap2_lp1_y_14;
			t_sample ap2_lp1_y2p_178 = m_ap2_lp1_y_13;
			t_sample ap2_lp_s_179 = (((((lp_b0_h_144 * stage1_out_174) + (lp_b1_h_145 * ap2_lp1_x1p_175)) + (lp_b2_h_146 * ap2_lp1_x2p_176)) - (lp_a1_h_147 * ap2_lp1_y1p_177)) - (lp_a2_h_148 * ap2_lp1_y2p_178));
			m_ap2_lp1_x_15 = ap2_lp1_x1p_175;
			m_ap2_lp1_x_16 = stage1_out_174;
			m_ap2_lp1_y_13 = ap2_lp1_y1p_177;
			m_ap2_lp1_y_14 = ap2_lp_s_179;
			t_sample ap2_lp2_x1p_180 = m_ap2_lp2_x_12;
			t_sample ap2_lp2_x2p_181 = m_ap2_lp2_x_11;
			t_sample ap2_lp2_y1p_182 = m_ap2_lp2_y_10;
			t_sample ap2_lp2_y2p_183 = m_ap2_lp2_y_9;
			t_sample ap2_lp_184 = (((((lp_b0_h_144 * ap2_lp_s_179) + (lp_b1_h_145 * ap2_lp2_x1p_180)) + (lp_b2_h_146 * ap2_lp2_x2p_181)) - (lp_a1_h_147 * ap2_lp2_y1p_182)) - (lp_a2_h_148 * ap2_lp2_y2p_183));
			m_ap2_lp2_x_11 = ap2_lp2_x1p_180;
			m_ap2_lp2_x_12 = ap2_lp_s_179;
			m_ap2_lp2_y_9 = ap2_lp2_y1p_182;
			m_ap2_lp2_y_10 = ap2_lp_184;
			t_sample ap2_hp1_x1p_185 = m_ap2_hp1_x_8;
			t_sample ap2_hp1_x2p_186 = m_ap2_hp1_x_7;
			t_sample ap2_hp1_y1p_187 = m_ap2_hp1_y_6;
			t_sample ap2_hp1_y2p_188 = m_ap2_hp1_y_5;
			t_sample ap2_hp_s_189 = (((((hp_b0_h_149 * stage1_out_174) + (hp_b1_h_150 * ap2_hp1_x1p_185)) + (hp_b2_h_151 * ap2_hp1_x2p_186)) - (hp_a1_h_152 * ap2_hp1_y1p_187)) - (hp_a2_h_153 * ap2_hp1_y2p_188));
			m_ap2_hp1_x_7 = ap2_hp1_x1p_185;
			m_ap2_hp1_x_8 = stage1_out_174;
			m_ap2_hp1_y_5 = ap2_hp1_y1p_187;
			m_ap2_hp1_y_6 = ap2_hp_s_189;
			t_sample ap2_hp2_x1p_190 = m_ap2_hp2_x_4;
			t_sample ap2_hp2_x2p_191 = m_ap2_hp2_x_3;
			t_sample ap2_hp2_y1p_192 = m_ap2_hp2_y_2;
			t_sample ap2_hp2_y2p_193 = m_ap2_hp2_y_1;
			t_sample ap2_hp_194 = (((((hp_b0_h_149 * ap2_hp_s_189) + (hp_b1_h_150 * ap2_hp2_x1p_190)) + (hp_b2_h_151 * ap2_hp2_x2p_191)) - (hp_a1_h_152 * ap2_hp2_y1p_192)) - (hp_a2_h_153 * ap2_hp2_y2p_193));
			m_ap2_hp2_x_3 = ap2_hp2_x1p_190;
			m_ap2_hp2_x_4 = ap2_hp_s_189;
			m_ap2_hp2_y_1 = ap2_hp2_y1p_192;
			m_ap2_hp2_y_2 = ap2_hp_194;
			t_sample expr_195 = (ap2_lp_184 + ap2_hp_194);
			t_sample mix_29095 = (m_x_DRYWET_215 + (((t_sample)0.999) * (m_history_179 - m_x_DRYWET_215)));
			t_sample mix_197 = mix_29095;
			t_sample gen_198 = mix_197;
			t_sample history_1_next_199 = fixdenorm(mix_197);
			t_sample mix_29096 = (m_i_BYPASS_220 + (((t_sample)0.999) * (m_history_178 - m_i_BYPASS_220)));
			t_sample mix_201 = mix_29096;
			t_sample gen_202 = mix_201;
			t_sample history_2_next_203 = fixdenorm(mix_201);
			t_sample rsub_204 = (((int)1) - gen_202);
			t_sample mix_29097 = (m_g_SOLOMED_222 + (((t_sample)0.999) * (m_history_177 - m_g_SOLOMED_222)));
			t_sample mix_207 = mix_29097;
			t_sample gen_208 = mix_207;
			t_sample history_3_next_209 = fixdenorm(mix_207);
			t_sample mix_29098 = (m_h_SOLOHIGH_221 + (((t_sample)0.999) * (m_history_176 - m_h_SOLOHIGH_221)));
			t_sample mix_211 = mix_29098;
			t_sample gen_212 = mix_211;
			t_sample history_4_next_213 = fixdenorm(mix_211);
			t_sample mix_29099 = (m_f_SOLOLOW_223 + (((t_sample)0.999) * (m_history_175 - m_f_SOLOLOW_223)));
			t_sample mix_216 = mix_29099;
			t_sample gen_217 = mix_216;
			t_sample history_5_next_218 = fixdenorm(mix_216);
			t_sample mix_29100 = (m_j_input_219 + (((t_sample)0.999) * (m_history_174 - m_j_input_219)));
			t_sample mix_222 = mix_29100;
			t_sample gen_223 = mix_222;
			t_sample history_6_next_224 = fixdenorm(mix_222);
			t_sample setparam_225 = gen_223;
			t_sample mix_29101 = (m_c_LOW_226 + (((t_sample)0.999) * (m_history_173 - m_c_LOW_226)));
			t_sample mix_229 = mix_29101;
			t_sample gen_230 = mix_229;
			t_sample history_7_next_231 = fixdenorm(mix_229);
			t_sample setparam_232 = gen_230;
			t_sample mix_29102 = (m_d_MED_225 + (((t_sample)0.999) * (m_history_172 - m_d_MED_225)));
			t_sample mix_236 = mix_29102;
			t_sample gen_237 = mix_236;
			t_sample history_8_next_238 = fixdenorm(mix_236);
			t_sample setparam_239 = gen_237;
			t_sample mix_29103 = (m_l_MED_bal_217 + (((t_sample)0.999) * (m_history_171 - m_l_MED_bal_217)));
			t_sample mix_241 = mix_29103;
			t_sample gen_242 = mix_241;
			t_sample history_9_next_243 = fixdenorm(mix_241);
			t_sample setparam_244 = gen_242;
			t_sample mix_29104 = (m_e_HIGH_224 + (((t_sample)0.999) * (m_history_170 - m_e_HIGH_224)));
			t_sample mix_248 = mix_29104;
			t_sample gen_249 = mix_248;
			t_sample history_10_next_250 = fixdenorm(mix_248);
			t_sample setparam_251 = gen_249;
			t_sample mix_29105 = (m_m_HIGH_bal_216 + (((t_sample)0.999) * (m_history_169 - m_m_HIGH_bal_216)));
			t_sample mix_253 = mix_29105;
			t_sample gen_254 = mix_253;
			t_sample history_11_next_255 = fixdenorm(mix_253);
			t_sample setparam_256 = gen_254;
			t_sample mix_29106 = (m_b_FREQ_227 + (((t_sample)0.999) * (m_history_168 - m_b_FREQ_227)));
			t_sample mix_258 = mix_29106;
			t_sample gen_259 = mix_258;
			t_sample history_12_next_260 = fixdenorm(mix_258);
			t_sample setparam_261 = gen_259;
			t_sample mix_29107 = (m_a_FREQ_228 + (((t_sample)0.999) * (m_history_167 - m_a_FREQ_228)));
			t_sample mix_263 = mix_29107;
			t_sample gen_264 = mix_263;
			t_sample history_13_next_265 = fixdenorm(mix_263);
			t_sample setparam_266 = gen_264;
			t_sample freq_low_267 = ((setparam_266 <= ((int)20)) ? ((int)20) : ((setparam_266 >= ((int)1000)) ? ((int)1000) : setparam_266));
			t_sample freq_high_268 = ((setparam_261 <= ((int)1000)) ? ((int)1000) : ((setparam_261 >= ((int)20000)) ? ((int)20000) : setparam_261));
			t_sample x_269 = in1;
			t_sample maxb_240 = ((minb_239 < freq_low_267) ? minb_239 : freq_low_267);
			t_sample loF_271 = ((((int)10) < maxb_240) ? maxb_240 : ((int)10));
			t_sample maxb_242 = ((minb_241 < freq_high_268) ? minb_241 : freq_high_268);
			t_sample hiFr_272 = ((((int)10) < maxb_242) ? maxb_242 : ((int)10));
			t_sample maxb_243 = (loF_271 + ((int)1));
			t_sample hiF_273 = ((hiFr_272 < maxb_243) ? maxb_243 : hiFr_272);
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
			t_sample l1_x1p = m_l1_x_166;
			t_sample l1_x2p = m_l1_x_165;
			t_sample l1_y1p = m_l1_y_164;
			t_sample l1_y2p = m_l1_y_163;
			t_sample low_s1 = (((((lp_b0_l_281 * x_269) + (lp_b1_l_282 * l1_x1p)) + (lp_b2_l_283 * l1_x2p)) - (lp_a1_l_284 * l1_y1p)) - (lp_a2_l_285 * l1_y2p));
			m_l1_x_165 = l1_x1p;
			m_l1_x_166 = x_269;
			m_l1_y_163 = l1_y1p;
			m_l1_y_164 = low_s1;
			t_sample l2_x1p = m_l2_x_162;
			t_sample l2_x2p = m_l2_x_161;
			t_sample l2_y1p = m_l2_y_160;
			t_sample l2_y2p = m_l2_y_159;
			t_sample low_raw = (((((lp_b0_l_281 * low_s1) + (lp_b1_l_282 * l2_x1p)) + (lp_b2_l_283 * l2_x2p)) - (lp_a1_l_284 * l2_y1p)) - (lp_a2_l_285 * l2_y2p));
			m_l2_x_161 = l2_x1p;
			m_l2_x_162 = low_s1;
			m_l2_y_159 = l2_y1p;
			m_l2_y_160 = low_raw;
			t_sample h1_x1p = m_h1_x_158;
			t_sample h1_x2p = m_h1_x_157;
			t_sample h1_y1p = m_h1_y_156;
			t_sample h1_y2p = m_h1_y_155;
			t_sample rest_s1 = (((((hp_b0_l_286 * x_269) + (hp_b1_l_287 * h1_x1p)) + (hp_b2_l_288 * h1_x2p)) - (hp_a1_l_289 * h1_y1p)) - (hp_a2_l_290 * h1_y2p));
			m_h1_x_157 = h1_x1p;
			m_h1_x_158 = x_269;
			m_h1_y_155 = h1_y1p;
			m_h1_y_156 = rest_s1;
			t_sample h2_x1p = m_h2_x_154;
			t_sample h2_x2p = m_h2_x_153;
			t_sample h2_y1p = m_h2_y_152;
			t_sample h2_y2p = m_h2_y_151;
			t_sample rest = (((((hp_b0_l_286 * rest_s1) + (hp_b1_l_287 * h2_x1p)) + (hp_b2_l_288 * h2_x2p)) - (hp_a1_l_289 * h2_y1p)) - (hp_a2_l_290 * h2_y2p));
			m_h2_x_153 = h2_x1p;
			m_h2_x_154 = rest_s1;
			m_h2_y_151 = h2_y1p;
			m_h2_y_152 = rest;
			t_sample ap_low_lp1_x1p = m_ap_low_lp1_x_134;
			t_sample ap_low_lp1_x2p = m_ap_low_lp1_x_133;
			t_sample ap_low_lp1_y1p = m_ap_low_lp1_y_132;
			t_sample ap_low_lp1_y2p = m_ap_low_lp1_y_131;
			t_sample ap_low_lp_s1 = (((((lp_b0_h_298 * low_raw) + (lp_b1_h_299 * ap_low_lp1_x1p)) + (lp_b2_h_300 * ap_low_lp1_x2p)) - (lp_a1_h_301 * ap_low_lp1_y1p)) - (lp_a2_h_302 * ap_low_lp1_y2p));
			m_ap_low_lp1_x_133 = ap_low_lp1_x1p;
			m_ap_low_lp1_x_134 = low_raw;
			m_ap_low_lp1_y_131 = ap_low_lp1_y1p;
			m_ap_low_lp1_y_132 = ap_low_lp_s1;
			t_sample ap_low_lp2_x1p = m_ap_low_lp2_x_130;
			t_sample ap_low_lp2_x2p = m_ap_low_lp2_x_129;
			t_sample ap_low_lp2_y1p = m_ap_low_lp2_y_128;
			t_sample ap_low_lp2_y2p = m_ap_low_lp2_y_127;
			t_sample ap_low_lp = (((((lp_b0_h_298 * ap_low_lp_s1) + (lp_b1_h_299 * ap_low_lp2_x1p)) + (lp_b2_h_300 * ap_low_lp2_x2p)) - (lp_a1_h_301 * ap_low_lp2_y1p)) - (lp_a2_h_302 * ap_low_lp2_y2p));
			m_ap_low_lp2_x_129 = ap_low_lp2_x1p;
			m_ap_low_lp2_x_130 = ap_low_lp_s1;
			m_ap_low_lp2_y_127 = ap_low_lp2_y1p;
			m_ap_low_lp2_y_128 = ap_low_lp;
			t_sample ap_low_hp1_x1p = m_ap_low_hp1_x_126;
			t_sample ap_low_hp1_x2p = m_ap_low_hp1_x_125;
			t_sample ap_low_hp1_y1p = m_ap_low_hp1_y_124;
			t_sample ap_low_hp1_y2p = m_ap_low_hp1_y_123;
			t_sample ap_low_hp_s1 = (((((hp_b0_h_303 * low_raw) + (hp_b1_h_304 * ap_low_hp1_x1p)) + (hp_b2_h_305 * ap_low_hp1_x2p)) - (hp_a1_h_306 * ap_low_hp1_y1p)) - (hp_a2_h_307 * ap_low_hp1_y2p));
			m_ap_low_hp1_x_125 = ap_low_hp1_x1p;
			m_ap_low_hp1_x_126 = low_raw;
			m_ap_low_hp1_y_123 = ap_low_hp1_y1p;
			m_ap_low_hp1_y_124 = ap_low_hp_s1;
			t_sample ap_low_hp2_x1p = m_ap_low_hp2_x_122;
			t_sample ap_low_hp2_x2p = m_ap_low_hp2_x_121;
			t_sample ap_low_hp2_y1p = m_ap_low_hp2_y_120;
			t_sample ap_low_hp2_y2p = m_ap_low_hp2_y_119;
			t_sample ap_low_hp = (((((hp_b0_h_303 * ap_low_hp_s1) + (hp_b1_h_304 * ap_low_hp2_x1p)) + (hp_b2_h_305 * ap_low_hp2_x2p)) - (hp_a1_h_306 * ap_low_hp2_y1p)) - (hp_a2_h_307 * ap_low_hp2_y2p));
			m_ap_low_hp2_x_121 = ap_low_hp2_x1p;
			m_ap_low_hp2_x_122 = ap_low_hp_s1;
			m_ap_low_hp2_y_119 = ap_low_hp2_y1p;
			m_ap_low_hp2_y_120 = ap_low_hp;
			t_sample low = (ap_low_lp + ap_low_hp);
			t_sample m1_x1p = m_m1_x_150;
			t_sample m1_x2p = m_m1_x_149;
			t_sample m1_y1p = m_m1_y_148;
			t_sample m1_y2p = m_m1_y_147;
			t_sample mid_s1 = (((((lp_b0_h_298 * rest) + (lp_b1_h_299 * m1_x1p)) + (lp_b2_h_300 * m1_x2p)) - (lp_a1_h_301 * m1_y1p)) - (lp_a2_h_302 * m1_y2p));
			m_m1_x_149 = m1_x1p;
			m_m1_x_150 = rest;
			m_m1_y_147 = m1_y1p;
			m_m1_y_148 = mid_s1;
			t_sample m2_x1p = m_m2_x_146;
			t_sample m2_x2p = m_m2_x_145;
			t_sample m2_y1p = m_m2_y_144;
			t_sample m2_y2p = m_m2_y_143;
			t_sample mid = (((((lp_b0_h_298 * mid_s1) + (lp_b1_h_299 * m2_x1p)) + (lp_b2_h_300 * m2_x2p)) - (lp_a1_h_301 * m2_y1p)) - (lp_a2_h_302 * m2_y2p));
			m_m2_x_145 = m2_x1p;
			m_m2_x_146 = mid_s1;
			m_m2_y_143 = m2_y1p;
			m_m2_y_144 = mid;
			t_sample u1_x1p = m_u1_x_142;
			t_sample u1_x2p = m_u1_x_141;
			t_sample u1_y1p = m_u1_y_140;
			t_sample u1_y2p = m_u1_y_139;
			t_sample high_s1 = (((((hp_b0_h_303 * rest) + (hp_b1_h_304 * u1_x1p)) + (hp_b2_h_305 * u1_x2p)) - (hp_a1_h_306 * u1_y1p)) - (hp_a2_h_307 * u1_y2p));
			m_u1_x_141 = u1_x1p;
			m_u1_x_142 = rest;
			m_u1_y_139 = u1_y1p;
			m_u1_y_140 = high_s1;
			t_sample u2_x1p = m_u2_x_138;
			t_sample u2_x2p = m_u2_x_137;
			t_sample u2_y1p = m_u2_y_136;
			t_sample u2_y2p = m_u2_y_135;
			t_sample high = (((((hp_b0_h_303 * high_s1) + (hp_b1_h_304 * u2_x1p)) + (hp_b2_h_305 * u2_x2p)) - (hp_a1_h_306 * u2_y1p)) - (hp_a2_h_307 * u2_y2p));
			m_u2_x_137 = u2_x1p;
			m_u2_x_138 = high_s1;
			m_u2_y_135 = u2_y1p;
			m_u2_y_136 = high;
			t_sample expr_308 = low;
			t_sample expr_309 = mid;
			t_sample expr_310 = high;
			t_sample gen_312 = expr_308;
			t_sample gen_313 = expr_309;
			t_sample gen_314 = expr_310;
			t_sample freq_low_315 = ((setparam_266 <= ((int)20)) ? ((int)20) : ((setparam_266 >= ((int)1000)) ? ((int)1000) : setparam_266));
			t_sample freq_high_316 = ((setparam_261 <= ((int)1000)) ? ((int)1000) : ((setparam_261 >= ((int)20000)) ? ((int)20000) : setparam_261));
			t_sample x_317 = in2;
			t_sample maxb_245 = ((minb_244 < freq_low_315) ? minb_244 : freq_low_315);
			t_sample loF_319 = ((((int)10) < maxb_245) ? maxb_245 : ((int)10));
			t_sample maxb_247 = ((minb_246 < freq_high_316) ? minb_246 : freq_high_316);
			t_sample hiFr_320 = ((((int)10) < maxb_247) ? maxb_247 : ((int)10));
			t_sample maxb_248 = (loF_319 + ((int)1));
			t_sample hiF_321 = ((hiFr_320 < maxb_248) ? maxb_248 : hiFr_320);
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
			t_sample l1_x1p_356 = m_l1_x_118;
			t_sample l1_x2p_357 = m_l1_x_117;
			t_sample l1_y1p_358 = m_l1_y_116;
			t_sample l1_y2p_359 = m_l1_y_115;
			t_sample low_s_360 = (((((lp_b0_l_329 * x_317) + (lp_b1_l_330 * l1_x1p_356)) + (lp_b2_l_331 * l1_x2p_357)) - (lp_a1_l_332 * l1_y1p_358)) - (lp_a2_l_333 * l1_y2p_359));
			m_l1_x_117 = l1_x1p_356;
			m_l1_x_118 = x_317;
			m_l1_y_115 = l1_y1p_358;
			m_l1_y_116 = low_s_360;
			t_sample l2_x1p_361 = m_l2_x_114;
			t_sample l2_x2p_362 = m_l2_x_113;
			t_sample l2_y1p_363 = m_l2_y_112;
			t_sample l2_y2p_364 = m_l2_y_111;
			t_sample low_raw_365 = (((((lp_b0_l_329 * low_s_360) + (lp_b1_l_330 * l2_x1p_361)) + (lp_b2_l_331 * l2_x2p_362)) - (lp_a1_l_332 * l2_y1p_363)) - (lp_a2_l_333 * l2_y2p_364));
			m_l2_x_113 = l2_x1p_361;
			m_l2_x_114 = low_s_360;
			m_l2_y_111 = l2_y1p_363;
			m_l2_y_112 = low_raw_365;
			t_sample h1_x1p_366 = m_h1_x_110;
			t_sample h1_x2p_367 = m_h1_x_109;
			t_sample h1_y1p_368 = m_h1_y_108;
			t_sample h1_y2p_369 = m_h1_y_107;
			t_sample rest_s_370 = (((((hp_b0_l_334 * x_317) + (hp_b1_l_335 * h1_x1p_366)) + (hp_b2_l_336 * h1_x2p_367)) - (hp_a1_l_337 * h1_y1p_368)) - (hp_a2_l_338 * h1_y2p_369));
			m_h1_x_109 = h1_x1p_366;
			m_h1_x_110 = x_317;
			m_h1_y_107 = h1_y1p_368;
			m_h1_y_108 = rest_s_370;
			t_sample h2_x1p_371 = m_h2_x_106;
			t_sample h2_x2p_372 = m_h2_x_105;
			t_sample h2_y1p_373 = m_h2_y_104;
			t_sample h2_y2p_374 = m_h2_y_103;
			t_sample rest_375 = (((((hp_b0_l_334 * rest_s_370) + (hp_b1_l_335 * h2_x1p_371)) + (hp_b2_l_336 * h2_x2p_372)) - (hp_a1_l_337 * h2_y1p_373)) - (hp_a2_l_338 * h2_y2p_374));
			m_h2_x_105 = h2_x1p_371;
			m_h2_x_106 = rest_s_370;
			m_h2_y_103 = h2_y1p_373;
			m_h2_y_104 = rest_375;
			t_sample ap_low_lp1_x1p_376 = m_ap_low_lp1_x_86;
			t_sample ap_low_lp1_x2p_377 = m_ap_low_lp1_x_85;
			t_sample ap_low_lp1_y1p_378 = m_ap_low_lp1_y_84;
			t_sample ap_low_lp1_y2p_379 = m_ap_low_lp1_y_83;
			t_sample ap_low_lp_s_380 = (((((lp_b0_h_346 * low_raw_365) + (lp_b1_h_347 * ap_low_lp1_x1p_376)) + (lp_b2_h_348 * ap_low_lp1_x2p_377)) - (lp_a1_h_349 * ap_low_lp1_y1p_378)) - (lp_a2_h_350 * ap_low_lp1_y2p_379));
			m_ap_low_lp1_x_85 = ap_low_lp1_x1p_376;
			m_ap_low_lp1_x_86 = low_raw_365;
			m_ap_low_lp1_y_83 = ap_low_lp1_y1p_378;
			m_ap_low_lp1_y_84 = ap_low_lp_s_380;
			t_sample ap_low_lp2_x1p_381 = m_ap_low_lp2_x_82;
			t_sample ap_low_lp2_x2p_382 = m_ap_low_lp2_x_81;
			t_sample ap_low_lp2_y1p_383 = m_ap_low_lp2_y_80;
			t_sample ap_low_lp2_y2p_384 = m_ap_low_lp2_y_79;
			t_sample ap_low_lp_385 = (((((lp_b0_h_346 * ap_low_lp_s_380) + (lp_b1_h_347 * ap_low_lp2_x1p_381)) + (lp_b2_h_348 * ap_low_lp2_x2p_382)) - (lp_a1_h_349 * ap_low_lp2_y1p_383)) - (lp_a2_h_350 * ap_low_lp2_y2p_384));
			m_ap_low_lp2_x_81 = ap_low_lp2_x1p_381;
			m_ap_low_lp2_x_82 = ap_low_lp_s_380;
			m_ap_low_lp2_y_79 = ap_low_lp2_y1p_383;
			m_ap_low_lp2_y_80 = ap_low_lp_385;
			t_sample ap_low_hp1_x1p_386 = m_ap_low_hp1_x_78;
			t_sample ap_low_hp1_x2p_387 = m_ap_low_hp1_x_77;
			t_sample ap_low_hp1_y1p_388 = m_ap_low_hp1_y_76;
			t_sample ap_low_hp1_y2p_389 = m_ap_low_hp1_y_75;
			t_sample ap_low_hp_s_390 = (((((hp_b0_h_351 * low_raw_365) + (hp_b1_h_352 * ap_low_hp1_x1p_386)) + (hp_b2_h_353 * ap_low_hp1_x2p_387)) - (hp_a1_h_354 * ap_low_hp1_y1p_388)) - (hp_a2_h_355 * ap_low_hp1_y2p_389));
			m_ap_low_hp1_x_77 = ap_low_hp1_x1p_386;
			m_ap_low_hp1_x_78 = low_raw_365;
			m_ap_low_hp1_y_75 = ap_low_hp1_y1p_388;
			m_ap_low_hp1_y_76 = ap_low_hp_s_390;
			t_sample ap_low_hp2_x1p_391 = m_ap_low_hp2_x_74;
			t_sample ap_low_hp2_x2p_392 = m_ap_low_hp2_x_73;
			t_sample ap_low_hp2_y1p_393 = m_ap_low_hp2_y_72;
			t_sample ap_low_hp2_y2p_394 = m_ap_low_hp2_y_71;
			t_sample ap_low_hp_395 = (((((hp_b0_h_351 * ap_low_hp_s_390) + (hp_b1_h_352 * ap_low_hp2_x1p_391)) + (hp_b2_h_353 * ap_low_hp2_x2p_392)) - (hp_a1_h_354 * ap_low_hp2_y1p_393)) - (hp_a2_h_355 * ap_low_hp2_y2p_394));
			m_ap_low_hp2_x_73 = ap_low_hp2_x1p_391;
			m_ap_low_hp2_x_74 = ap_low_hp_s_390;
			m_ap_low_hp2_y_71 = ap_low_hp2_y1p_393;
			m_ap_low_hp2_y_72 = ap_low_hp_395;
			t_sample low_396 = (ap_low_lp_385 + ap_low_hp_395);
			t_sample m1_x1p_397 = m_m1_x_102;
			t_sample m1_x2p_398 = m_m1_x_101;
			t_sample m1_y1p_399 = m_m1_y_100;
			t_sample m1_y2p_400 = m_m1_y_99;
			t_sample mid_s_401 = (((((lp_b0_h_346 * rest_375) + (lp_b1_h_347 * m1_x1p_397)) + (lp_b2_h_348 * m1_x2p_398)) - (lp_a1_h_349 * m1_y1p_399)) - (lp_a2_h_350 * m1_y2p_400));
			m_m1_x_101 = m1_x1p_397;
			m_m1_x_102 = rest_375;
			m_m1_y_99 = m1_y1p_399;
			m_m1_y_100 = mid_s_401;
			t_sample m2_x1p_402 = m_m2_x_98;
			t_sample m2_x2p_403 = m_m2_x_97;
			t_sample m2_y1p_404 = m_m2_y_96;
			t_sample m2_y2p_405 = m_m2_y_95;
			t_sample mid_406 = (((((lp_b0_h_346 * mid_s_401) + (lp_b1_h_347 * m2_x1p_402)) + (lp_b2_h_348 * m2_x2p_403)) - (lp_a1_h_349 * m2_y1p_404)) - (lp_a2_h_350 * m2_y2p_405));
			m_m2_x_97 = m2_x1p_402;
			m_m2_x_98 = mid_s_401;
			m_m2_y_95 = m2_y1p_404;
			m_m2_y_96 = mid_406;
			t_sample u1_x1p_407 = m_u1_x_94;
			t_sample u1_x2p_408 = m_u1_x_93;
			t_sample u1_y1p_409 = m_u1_y_92;
			t_sample u1_y2p_410 = m_u1_y_91;
			t_sample high_s_411 = (((((hp_b0_h_351 * rest_375) + (hp_b1_h_352 * u1_x1p_407)) + (hp_b2_h_353 * u1_x2p_408)) - (hp_a1_h_354 * u1_y1p_409)) - (hp_a2_h_355 * u1_y2p_410));
			m_u1_x_93 = u1_x1p_407;
			m_u1_x_94 = rest_375;
			m_u1_y_91 = u1_y1p_409;
			m_u1_y_92 = high_s_411;
			t_sample u2_x1p_412 = m_u2_x_90;
			t_sample u2_x2p_413 = m_u2_x_89;
			t_sample u2_y1p_414 = m_u2_y_88;
			t_sample u2_y2p_415 = m_u2_y_87;
			t_sample high_416 = (((((hp_b0_h_351 * high_s_411) + (hp_b1_h_352 * u2_x1p_412)) + (hp_b2_h_353 * u2_x2p_413)) - (hp_a1_h_354 * u2_y1p_414)) - (hp_a2_h_355 * u2_y2p_415));
			m_u2_x_89 = u2_x1p_412;
			m_u2_x_90 = high_s_411;
			m_u2_y_87 = u2_y1p_414;
			m_u2_y_88 = high_416;
			t_sample expr_418 = low_396;
			t_sample expr_419 = mid_406;
			t_sample expr_420 = high_416;
			t_sample gen_422 = expr_419;
			t_sample gen_423 = expr_418;
			t_sample gen_424 = expr_420;
			t_sample e_wide = ((setparam_232 <= ((int)0)) ? ((int)0) : ((setparam_232 >= ((int)200)) ? ((int)200) : setparam_232));
			t_sample a_input = ((setparam_225 <= ((int)0)) ? ((int)0) : ((setparam_225 >= ((int)1)) ? ((int)1) : setparam_225));
			t_sample mix_29108 = (((int)0) + (((t_sample)0.999) * (m_history_70 - ((int)0))));
			t_sample mix_427 = mix_29108;
			t_sample gen_428 = mix_427;
			t_sample history_62_next_429 = fixdenorm(mix_427);
			t_sample rsub_430 = (((int)1) - gen_428);
			t_sample mix_29109 = (d_balance + (((t_sample)0.999) * (m_history_69 - d_balance)));
			t_sample mix_433 = mix_29109;
			t_sample gen_434 = mix_433;
			t_sample history_63_next_435 = fixdenorm(mix_433);
			t_sample bl_t = ((gen_434 - ((t_sample)0.5)) * ((int)2));
			t_sample bl_pos = ((bl_t < ((int)0)) ? ((int)0) : bl_t);
			t_sample bl_neg = ((((int)0) < bl_t) ? ((int)0) : bl_t);
			t_sample v_249 = (((int)1) - bl_pos);
			t_sample bl_gL = ((v_249 <= ((int)0)) ? ((int)0) : ((v_249 >= ((int)1)) ? ((int)1) : v_249));
			t_sample v_250 = (((int)1) + bl_neg);
			t_sample bl_gR = ((v_250 <= ((int)0)) ? ((int)0) : ((v_250 >= ((int)1)) ? ((int)1) : v_250));
			t_sample mix_29110 = (e_wide + (((t_sample)0.999) * (m_history_68 - e_wide)));
			t_sample mix_442 = mix_29110;
			t_sample gen_443 = mix_442;
			t_sample history_64_next_444 = fixdenorm(mix_442);
			t_sample mix_29111 = (a_input + (((t_sample)0.999) * (m_history_67 - a_input)));
			t_sample mix_448 = mix_29111;
			t_sample gen_449 = mix_448;
			t_sample history_65_next_450 = fixdenorm(mix_448);
			t_sample mix_29112 = (gen_312 + (gen_449 * (((int)0) - gen_312)));
			t_sample mix_451 = mix_29112;
			t_sample mix_29113 = (gen_423 + (gen_449 * (((int)0) - gen_423)));
			t_sample mix_452 = mix_29113;
			t_sample mix_29114 = (((int)0) + (gen_449 * (gen_312 - ((int)0))));
			t_sample mix_453 = mix_29114;
			t_sample mix_29115 = (((int)0) + (gen_449 * (gen_423 - ((int)0))));
			t_sample mix_454 = mix_29115;
			t_sample add_455 = (mix_453 + mix_454);
			t_sample mul_456 = ((add_455 + mix_451) * ((int)1));
			t_sample sub_457 = (mix_453 - mix_454);
			t_sample mul_458 = ((mix_452 + sub_457) * ((int)1));
			t_sample M_low_raw = mul_456;
			t_sample S_low_raw = mul_458;
			t_sample w_low_c = ((gen_443 <= ((t_sample)0.5)) ? ((t_sample)0.5) : ((gen_443 >= ((t_sample)1.5)) ? ((t_sample)1.5) : gen_443));
			t_sample u_low = (w_low_c * ((t_sample)0.5));
			t_sample theta_low = (u_low * ((t_sample)1.2319971190549));
			t_sample gM_low = cos(theta_low);
			t_sample gS_low = sin(theta_low);
			t_sample L_low_pre = ((M_low_raw + S_low_raw) * ((t_sample)0.5));
			t_sample R_low_pre = ((M_low_raw - S_low_raw) * ((t_sample)0.5));
			m_low_EL_45 = fixdenorm((m_low_EL_45 + (alpha_low * ((L_low_pre * L_low_pre) - m_low_EL_45))));
			m_low_ER_44 = fixdenorm((m_low_ER_44 + (alpha_low * ((R_low_pre * R_low_pre) - m_low_ER_44))));
			m_low_CCS_46 = fixdenorm((m_low_CCS_46 + (alpha_low * ((L_low_pre * R_low_pre) - m_low_CCS_46))));
			m_low_EM_48 = fixdenorm((m_low_EM_48 + (alpha_low * ((M_low_raw * M_low_raw) - m_low_EM_48))));
			m_low_ES_47 = fixdenorm((m_low_ES_47 + (alpha_low * ((S_low_raw * S_low_raw) - m_low_ES_47))));
			t_sample a_low = (((t_sample)0.5) * (gM_low + gS_low));
			t_sample b_low = (((t_sample)0.5) * (gM_low - gS_low));
			t_sample Pin_low = ((m_low_EL_45 + m_low_ER_44) + ((t_sample)1e-12));
			t_sample Pout_low = (((((a_low * a_low) + (b_low * b_low)) * (m_low_EL_45 + m_low_ER_44)) + (((((int)4) * a_low) * b_low) * m_low_CCS_46)) + ((t_sample)1e-12));
			t_sample G_low = sqrt(safediv(Pin_low, Pout_low));
			t_sample G_low_28936 = ((G_low <= ((t_sample)0.59566214352901)) ? ((t_sample)0.59566214352901) : ((G_low >= ((t_sample)1.6788040181226)) ? ((t_sample)1.6788040181226) : G_low));
			t_sample rho_low_num = m_low_CCS_46;
			t_sample maxa_251 = (m_low_EL_45 * m_low_ER_44);
			t_sample rho_low_den = sqrt(((maxa_251 < ((t_sample)1e-12)) ? ((t_sample)1e-12) : maxa_251));
			t_sample v_252 = safediv(rho_low_num, (rho_low_den + ((t_sample)1e-12)));
			t_sample rho_low = ((v_252 <= ((int)-1)) ? ((int)-1) : ((v_252 >= ((int)1)) ? ((int)1) : v_252));
			t_sample maxb_253 = (u_low - ((t_sample)0.5));
			t_sample lift_base_low = ((((int)0) < maxb_253) ? maxb_253 : ((int)0));
			t_sample lift_dB_low = ((((int)6) * lift_base_low) * (((int)1) - rho_low));
			t_sample G_low_28937 = (G_low_28936 * dbtoa(lift_dB_low));
			t_sample mul_459 = (M_low_raw * ((t_sample)0.5));
			t_sample mul_462 = (S_low_raw * ((t_sample)0.5));
			t_sample mul_461 = (mul_459 * (gM_low * G_low_28937));
			t_sample mul_463 = (mul_462 * (gS_low * G_low_28937));
			t_sample mul_464 = (mul_463 * ((int)1));
			t_sample sub_465 = (mul_461 - mul_464);
			t_sample add_467 = (mul_461 + mul_464);
			t_sample mul_469 = (add_467 * bl_gL);
			t_sample mul_470 = (mul_469 * ((int)1));
			t_sample mix_29116 = (gen_312 + (rsub_430 * (mul_470 - gen_312)));
			t_sample mix_29117 = (m_n_MUTLOW_214 + (((t_sample)0.999) * (m_mute_low_h_51 - m_n_MUTLOW_214)));
			t_sample mute_low_sm = mix_29117;
			m_mute_low_h_51 = fixdenorm(mute_low_sm);
			t_sample low_gate = (((int)1) - ((mute_low_sm <= ((int)0)) ? ((int)0) : ((mute_low_sm >= ((int)1)) ? ((int)1) : mute_low_sm)));
			t_sample gen_28938 = (mix_29116 * low_gate);
			t_sample mul_473 = (sub_465 * bl_gR);
			t_sample mul_474 = (mul_473 * ((int)1));
			t_sample mix_29118 = (gen_423 + (rsub_430 * (mul_474 - gen_423)));
			t_sample gen_28939 = (mix_29118 * low_gate);
			t_sample add_29120 = (gen_212 + gen_208);
			t_sample mix_29119 = (gen_28939 + (add_29120 * (((int)0) - gen_28939)));
			t_sample add_29122 = (gen_212 + gen_208);
			t_sample mix_29121 = (gen_28938 + (add_29122 * (((int)0) - gen_28938)));
			t_sample d_balance_483 = ((setparam_244 <= ((int)0)) ? ((int)0) : ((setparam_244 >= ((int)1)) ? ((int)1) : setparam_244));
			t_sample e_wide_484 = ((setparam_239 <= ((int)0)) ? ((int)0) : ((setparam_239 >= ((int)200)) ? ((int)200) : setparam_239));
			t_sample a_input_486 = ((setparam_225 <= ((int)0)) ? ((int)0) : ((setparam_225 >= ((int)1)) ? ((int)1) : setparam_225));
			t_sample mix_29123 = (((int)0) + (((t_sample)0.999) * (m_history_66 - ((int)0))));
			t_sample mix_488 = mix_29123;
			t_sample gen_489 = mix_488;
			t_sample history_66_next_490 = fixdenorm(mix_488);
			t_sample rsub_491 = (((int)1) - gen_489);
			t_sample mix_29124 = (((int)0) + (((t_sample)0.999) * (m_history_65 - ((int)0))));
			t_sample mix_493 = mix_29124;
			t_sample gen_494 = mix_493;
			t_sample history_67_next_495 = fixdenorm(mix_493);
			t_sample dbtoa_496 = dbtoa(gen_494);
			t_sample mix_29125 = (d_balance_483 + (((t_sample)0.999) * (m_history_64 - d_balance_483)));
			t_sample mix_498 = mix_29125;
			t_sample gen_499 = mix_498;
			t_sample history_68_next_500 = fixdenorm(mix_498);
			t_sample bm_t = ((gen_499 - ((t_sample)0.5)) * ((int)2));
			t_sample bm_pos = ((bm_t < ((int)0)) ? ((int)0) : bm_t);
			t_sample bm_neg = ((((int)0) < bm_t) ? ((int)0) : bm_t);
			t_sample v_254 = (((int)1) - bm_pos);
			t_sample bm_gL = ((v_254 <= ((int)0)) ? ((int)0) : ((v_254 >= ((int)1)) ? ((int)1) : v_254));
			t_sample v_255 = (((int)1) + bm_neg);
			t_sample bm_gR = ((v_255 <= ((int)0)) ? ((int)0) : ((v_255 >= ((int)1)) ? ((int)1) : v_255));
			t_sample mix_29126 = (e_wide_484 + (((t_sample)0.999) * (m_history_63 - e_wide_484)));
			t_sample mix_505 = mix_29126;
			t_sample gen_506 = mix_505;
			t_sample history_69_next_507 = fixdenorm(mix_505);
			t_sample mix_29127 = (a_input_486 + (((t_sample)0.999) * (m_history_62 - a_input_486)));
			t_sample mix_511 = mix_29127;
			t_sample gen_512 = mix_511;
			t_sample history_70_next_513 = fixdenorm(mix_511);
			t_sample mix_29128 = (gen_313 + (gen_512 * (((int)0) - gen_313)));
			t_sample mix_514 = mix_29128;
			t_sample mix_29129 = (gen_422 + (gen_512 * (((int)0) - gen_422)));
			t_sample mix_515 = mix_29129;
			t_sample mix_29130 = (((int)0) + (gen_512 * (gen_313 - ((int)0))));
			t_sample mix_516 = mix_29130;
			t_sample mix_29131 = (((int)0) + (gen_512 * (gen_422 - ((int)0))));
			t_sample mix_517 = mix_29131;
			t_sample add_518 = (mix_516 + mix_517);
			t_sample sub_519 = (mix_516 - mix_517);
			t_sample mix_29132 = (((int)1) + (((t_sample)0.999) * (m_history_61 - ((int)1))));
			t_sample mix_522 = mix_29132;
			t_sample gen_523 = mix_522;
			t_sample history_71_next_524 = fixdenorm(mix_522);
			t_sample m_525 = gen_523;
			t_sample mul_526 = ((add_518 + mix_514) * m_525);
			t_sample mix_29133 = (((int)1) + (((t_sample)0.999) * (m_history_60 - ((int)1))));
			t_sample mix_529 = mix_29133;
			t_sample gen_530 = mix_529;
			t_sample history_72_next_531 = fixdenorm(mix_529);
			t_sample s_532 = gen_530;
			t_sample mul_533 = ((mix_515 + sub_519) * s_532);
			t_sample mix_29134 = (((int)1) + (((int)0) * (m_history_59 - ((int)1))));
			t_sample mix_538 = mix_29134;
			t_sample gen_539 = mix_538;
			t_sample history_73_next_540 = fixdenorm(mix_538);
			t_sample M_mid_raw = mul_526;
			t_sample S_mid_raw = mul_533;
			t_sample w_mid_c = ((gen_506 <= ((t_sample)0.5)) ? ((t_sample)0.5) : ((gen_506 >= ((t_sample)1.5)) ? ((t_sample)1.5) : gen_506));
			t_sample u_mid = (w_mid_c * ((t_sample)0.5));
			t_sample theta_mid = (u_mid * ((t_sample)1.2319971190549));
			t_sample gM_mid = cos(theta_mid);
			t_sample gS_mid = sin(theta_mid);
			t_sample L_mid_pre = ((M_mid_raw + S_mid_raw) * ((t_sample)0.5));
			t_sample R_mid_pre = ((M_mid_raw - S_mid_raw) * ((t_sample)0.5));
			m_mid_EL_43 = fixdenorm((m_mid_EL_43 + (alpha_mid * ((L_mid_pre * L_mid_pre) - m_mid_EL_43))));
			m_mid_ER_42 = fixdenorm((m_mid_ER_42 + (alpha_mid * ((R_mid_pre * R_mid_pre) - m_mid_ER_42))));
			m_mid_CCS_37 = fixdenorm((m_mid_CCS_37 + (alpha_mid * ((L_mid_pre * R_mid_pre) - m_mid_CCS_37))));
			m_mid_EM_39 = fixdenorm((m_mid_EM_39 + (alpha_mid * ((M_mid_raw * M_mid_raw) - m_mid_EM_39))));
			m_mid_ES_38 = fixdenorm((m_mid_ES_38 + (alpha_mid * ((S_mid_raw * S_mid_raw) - m_mid_ES_38))));
			t_sample a_mid = (((t_sample)0.5) * (gM_mid + gS_mid));
			t_sample b_mid_28940 = (((t_sample)0.5) * (gM_mid - gS_mid));
			t_sample Pin_mid = ((m_mid_EL_43 + m_mid_ER_42) + ((t_sample)1e-12));
			t_sample Pout_mid = (((((a_mid * a_mid) + (b_mid_28940 * b_mid_28940)) * (m_mid_EL_43 + m_mid_ER_42)) + (((((int)4) * a_mid) * b_mid_28940) * m_mid_CCS_37)) + ((t_sample)1e-12));
			t_sample G_mid = sqrt(safediv(Pin_mid, Pout_mid));
			t_sample G_mid_28941 = ((G_mid <= ((t_sample)0.59566214352901)) ? ((t_sample)0.59566214352901) : ((G_mid >= ((t_sample)1.6788040181226)) ? ((t_sample)1.6788040181226) : G_mid));
			t_sample rho_mid_num = m_mid_CCS_37;
			t_sample maxa_256 = (m_mid_EL_43 * m_mid_ER_42);
			t_sample rho_mid_den = sqrt(((maxa_256 < ((t_sample)1e-12)) ? ((t_sample)1e-12) : maxa_256));
			t_sample v_257 = safediv(rho_mid_num, (rho_mid_den + ((t_sample)1e-12)));
			t_sample rho_mid = ((v_257 <= ((int)-1)) ? ((int)-1) : ((v_257 >= ((int)1)) ? ((int)1) : v_257));
			t_sample maxb_258 = (u_mid - ((t_sample)0.5));
			t_sample lift_base_mid = ((((int)0) < maxb_258) ? maxb_258 : ((int)0));
			t_sample lift_dB_mid = ((((int)6) * lift_base_mid) * (((int)1) - rho_mid));
			t_sample G_mid_28942 = (G_mid_28941 * dbtoa(lift_dB_mid));
			t_sample mul_542 = (M_mid_raw * ((t_sample)0.5));
			t_sample mul_545 = (S_mid_raw * ((t_sample)0.5));
			t_sample mul_544 = (mul_542 * (gM_mid * G_mid_28942));
			t_sample mul_546 = (mul_545 * (gS_mid * G_mid_28942));
			t_sample mul_547 = (mul_546 * gen_539);
			t_sample sub_548 = (mul_544 - mul_547);
			t_sample add_550 = (mul_544 + mul_547);
			t_sample mul_552 = (sub_548 * bm_gR);
			t_sample mul_553 = (mul_552 * dbtoa_496);
			t_sample mix_29135 = (gen_422 + (rsub_491 * (mul_553 - gen_422)));
			t_sample mix_29136 = (m_o_MUTMED_213 + (((t_sample)0.999) * (m_mute_mid_h_50 - m_o_MUTMED_213)));
			t_sample mute_mid_sm = mix_29136;
			m_mute_mid_h_50 = fixdenorm(mute_mid_sm);
			t_sample mid_gate = (((int)1) - ((mute_mid_sm <= ((int)0)) ? ((int)0) : ((mute_mid_sm >= ((int)1)) ? ((int)1) : mute_mid_sm)));
			t_sample gen_28943 = (mix_29135 * mid_gate);
			t_sample mul_556 = (add_550 * bm_gL);
			t_sample mul_557 = (mul_556 * dbtoa_496);
			t_sample mix_29137 = (gen_313 + (rsub_491 * (mul_557 - gen_313)));
			t_sample gen_28944 = (mix_29137 * mid_gate);
			t_sample add_29139 = (gen_212 + gen_217);
			t_sample mix_29138 = (gen_28943 + (add_29139 * (((int)0) - gen_28943)));
			t_sample add_29141 = (gen_212 + gen_217);
			t_sample mix_29140 = (gen_28944 + (add_29141 * (((int)0) - gen_28944)));
			t_sample d_balance_566 = ((setparam_256 <= ((int)0)) ? ((int)0) : ((setparam_256 >= ((int)1)) ? ((int)1) : setparam_256));
			t_sample e_wide_567 = ((setparam_251 <= ((int)0)) ? ((int)0) : ((setparam_251 >= ((int)200)) ? ((int)200) : setparam_251));
			t_sample a_input_569 = ((setparam_225 <= ((int)0)) ? ((int)0) : ((setparam_225 >= ((int)1)) ? ((int)1) : setparam_225));
			t_sample mix_29142 = (((int)0) + (((t_sample)0.999) * (m_history_58 - ((int)0))));
			t_sample mix_571 = mix_29142;
			t_sample gen_572 = mix_571;
			t_sample history_74_next_573 = fixdenorm(mix_571);
			t_sample rsub_574 = (((int)1) - gen_572);
			t_sample mix_29143 = (((int)0) + (((t_sample)0.999) * (m_history_57 - ((int)0))));
			t_sample mix_576 = mix_29143;
			t_sample gen_577 = mix_576;
			t_sample history_75_next_578 = fixdenorm(mix_576);
			t_sample dbtoa_579 = dbtoa(gen_577);
			t_sample mix_29144 = (d_balance_566 + (((t_sample)0.999) * (m_history_56 - d_balance_566)));
			t_sample mix_581 = mix_29144;
			t_sample gen_582 = mix_581;
			t_sample history_76_next_583 = fixdenorm(mix_581);
			t_sample bh_t = ((gen_582 - ((t_sample)0.5)) * ((int)2));
			t_sample bh_pos = ((bh_t < ((int)0)) ? ((int)0) : bh_t);
			t_sample bh_neg = ((((int)0) < bh_t) ? ((int)0) : bh_t);
			t_sample v_259 = (((int)1) - bh_pos);
			t_sample bh_gL = ((v_259 <= ((int)0)) ? ((int)0) : ((v_259 >= ((int)1)) ? ((int)1) : v_259));
			t_sample v_260 = (((int)1) + bh_neg);
			t_sample bh_gR = ((v_260 <= ((int)0)) ? ((int)0) : ((v_260 >= ((int)1)) ? ((int)1) : v_260));
			t_sample mix_29145 = (e_wide_567 + (((t_sample)0.999) * (m_history_55 - e_wide_567)));
			t_sample mix_588 = mix_29145;
			t_sample gen_589 = mix_588;
			t_sample history_77_next_590 = fixdenorm(mix_588);
			t_sample mix_29146 = (a_input_569 + (((t_sample)0.999) * (m_history_54 - a_input_569)));
			t_sample mix_594 = mix_29146;
			t_sample gen_595 = mix_594;
			t_sample history_78_next_596 = fixdenorm(mix_594);
			t_sample mix_29147 = (gen_314 + (gen_595 * (((int)0) - gen_314)));
			t_sample mix_597 = mix_29147;
			t_sample mix_29148 = (gen_424 + (gen_595 * (((int)0) - gen_424)));
			t_sample mix_598 = mix_29148;
			t_sample mix_29149 = (((int)0) + (gen_595 * (gen_314 - ((int)0))));
			t_sample mix_599 = mix_29149;
			t_sample mix_29150 = (((int)0) + (gen_595 * (gen_424 - ((int)0))));
			t_sample mix_600 = mix_29150;
			t_sample add_601 = (mix_599 + mix_600);
			t_sample sub_602 = (mix_599 - mix_600);
			t_sample mix_29151 = (((int)1) + (((t_sample)0.999) * (m_history_53 - ((int)1))));
			t_sample mix_605 = mix_29151;
			t_sample gen_606 = mix_605;
			t_sample history_79_next_607 = fixdenorm(mix_605);
			t_sample m_608 = gen_606;
			t_sample mul_609 = ((add_601 + mix_597) * m_608);
			t_sample mix_29152 = (((int)1) + (((t_sample)0.999) * (m_history_52 - ((int)1))));
			t_sample mix_612 = mix_29152;
			t_sample gen_613 = mix_612;
			t_sample history_80_next_614 = fixdenorm(mix_612);
			t_sample s_615 = gen_613;
			t_sample mul_616 = ((mix_598 + sub_602) * s_615);
			t_sample mix_29153 = (((int)1) + (((int)0) * (m_history_33 - ((int)1))));
			t_sample mix_621 = mix_29153;
			t_sample gen_622 = mix_621;
			t_sample history_81_next_623 = fixdenorm(mix_621);
			t_sample M_high_raw = mul_609;
			t_sample S_high_raw = mul_616;
			t_sample w_high_c = ((gen_589 <= ((t_sample)0.5)) ? ((t_sample)0.5) : ((gen_589 >= ((t_sample)1.5)) ? ((t_sample)1.5) : gen_589));
			t_sample u_high = (w_high_c * ((t_sample)0.5));
			t_sample theta_high = (u_high * ((t_sample)1.2319971190549));
			t_sample gM_high = cos(theta_high);
			t_sample gS_high = sin(theta_high);
			t_sample L_high_pre = ((M_high_raw + S_high_raw) * ((t_sample)0.5));
			t_sample R_high_pre = ((M_high_raw - S_high_raw) * ((t_sample)0.5));
			m_high_EL_41 = fixdenorm((m_high_EL_41 + (alpha_high * ((L_high_pre * L_high_pre) - m_high_EL_41))));
			m_high_ER_40 = fixdenorm((m_high_ER_40 + (alpha_high * ((R_high_pre * R_high_pre) - m_high_ER_40))));
			m_high_CCS_34 = fixdenorm((m_high_CCS_34 + (alpha_high * ((L_high_pre * R_high_pre) - m_high_CCS_34))));
			m_high_EM_36 = fixdenorm((m_high_EM_36 + (alpha_high * ((M_high_raw * M_high_raw) - m_high_EM_36))));
			m_high_ES_35 = fixdenorm((m_high_ES_35 + (alpha_high * ((S_high_raw * S_high_raw) - m_high_ES_35))));
			t_sample a_high = (((t_sample)0.5) * (gM_high + gS_high));
			t_sample b_high = (((t_sample)0.5) * (gM_high - gS_high));
			t_sample Pin_high = ((m_high_EL_41 + m_high_ER_40) + ((t_sample)1e-12));
			t_sample Pout_high = (((((a_high * a_high) + (b_high * b_high)) * (m_high_EL_41 + m_high_ER_40)) + (((((int)4) * a_high) * b_high) * m_high_CCS_34)) + ((t_sample)1e-12));
			t_sample G_high = sqrt(safediv(Pin_high, Pout_high));
			t_sample G_high_28945 = ((G_high <= ((t_sample)0.59566214352901)) ? ((t_sample)0.59566214352901) : ((G_high >= ((t_sample)1.6788040181226)) ? ((t_sample)1.6788040181226) : G_high));
			t_sample rho_high_num = m_high_CCS_34;
			t_sample maxa_261 = (m_high_EL_41 * m_high_ER_40);
			t_sample rho_high_den = sqrt(((maxa_261 < ((t_sample)1e-12)) ? ((t_sample)1e-12) : maxa_261));
			t_sample v_262 = safediv(rho_high_num, (rho_high_den + ((t_sample)1e-12)));
			t_sample rho_high = ((v_262 <= ((int)-1)) ? ((int)-1) : ((v_262 >= ((int)1)) ? ((int)1) : v_262));
			t_sample maxb_263 = (u_high - ((t_sample)0.5));
			t_sample lift_base_high = ((((int)0) < maxb_263) ? maxb_263 : ((int)0));
			t_sample lift_dB_high = ((((int)6) * lift_base_high) * (((int)1) - rho_high));
			t_sample G_high_28946 = (G_high_28945 * dbtoa(lift_dB_high));
			t_sample mul_625 = (M_high_raw * ((t_sample)0.5));
			t_sample mul_628 = (S_high_raw * ((t_sample)0.5));
			t_sample mul_627 = (mul_625 * (gM_high * G_high_28946));
			t_sample mul_629 = (mul_628 * (gS_high * G_high_28946));
			t_sample mul_630 = (mul_629 * gen_622);
			t_sample sub_631 = (mul_627 - mul_630);
			t_sample add_633 = (mul_627 + mul_630);
			t_sample mul_635 = (add_633 * bh_gL);
			t_sample mul_636 = (mul_635 * dbtoa_579);
			t_sample mix_29154 = (gen_314 + (rsub_574 * (mul_636 - gen_314)));
			t_sample mix_29155 = (m_p_MUTHIGH_212 + (((t_sample)0.999) * (m_mute_high_h_49 - m_p_MUTHIGH_212)));
			t_sample mute_high_sm = mix_29155;
			m_mute_high_h_49 = fixdenorm(mute_high_sm);
			t_sample high_gate = (((int)1) - ((mute_high_sm <= ((int)0)) ? ((int)0) : ((mute_high_sm >= ((int)1)) ? ((int)1) : mute_high_sm)));
			t_sample gen_28947 = (mix_29154 * high_gate);
			t_sample mul_639 = (sub_631 * bh_gR);
			t_sample mul_640 = (mul_639 * dbtoa_579);
			t_sample mix_29156 = (gen_424 + (rsub_574 * (mul_640 - gen_424)));
			t_sample gen_28948 = (mix_29156 * high_gate);
			t_sample add_29158 = (gen_208 + gen_217);
			t_sample mix_29157 = (gen_28948 + (add_29158 * (((int)0) - gen_28948)));
			t_sample add_29160 = ((mix_29157 + mix_29138) + mix_29119);
			t_sample mix_29159 = (expr_114 + (gen_198 * (add_29160 - expr_114)));
			t_sample mix_29161 = (in2 + (rsub_204 * (mix_29159 - in2)));
			t_sample add_29163 = (gen_208 + gen_217);
			t_sample mix_29162 = (gen_28947 + (add_29163 * (((int)0) - gen_28947)));
			t_sample add_29165 = ((mix_29162 + mix_29140) + mix_29121);
			t_sample mix_29164 = (expr_195 + (gen_198 * (add_29165 - expr_195)));
			t_sample mix_29166 = (in1 + (rsub_204 * (mix_29164 - in1)));
			m_history_179 = history_1_next_199;
			m_history_57 = history_75_next_578;
			m_history_56 = history_76_next_583;
			m_history_55 = history_77_next_590;
			m_history_54 = history_78_next_596;
			m_history_53 = history_79_next_607;
			m_history_52 = history_80_next_614;
			m_history_33 = history_81_next_623;
			m_history_58 = history_74_next_573;
			m_history_65 = history_67_next_495;
			m_history_64 = history_68_next_500;
			m_history_63 = history_69_next_507;
			m_history_62 = history_70_next_513;
			m_history_61 = history_71_next_524;
			m_history_60 = history_72_next_531;
			m_history_59 = history_73_next_540;
			m_history_66 = history_66_next_490;
			m_history_69 = history_63_next_435;
			m_history_68 = history_64_next_444;
			m_history_67 = history_65_next_450;
			m_history_70 = history_62_next_429;
			m_history_167 = history_13_next_265;
			m_history_168 = history_12_next_260;
			m_history_169 = history_11_next_255;
			m_history_170 = history_10_next_250;
			m_history_171 = history_9_next_243;
			m_history_172 = history_8_next_238;
			m_history_173 = history_7_next_231;
			m_history_174 = history_6_next_224;
			m_history_175 = history_5_next_218;
			m_history_176 = history_4_next_213;
			m_history_177 = history_3_next_209;
			m_history_178 = history_2_next_203;
			t_sample out1 = mix_29166;
			t_sample out2 = mix_29161;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			
		};
		return __exception;
		
	};
	inline void set_p_MUTHIGH(t_param _value) {
		m_p_MUTHIGH_212 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_o_MUTMED(t_param _value) {
		m_o_MUTMED_213 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_n_MUTLOW(t_param _value) {
		m_n_MUTLOW_214 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_x_DRYWET(t_param _value) {
		m_x_DRYWET_215 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_m_HIGH_bal(t_param _value) {
		m_m_HIGH_bal_216 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_l_MED_bal(t_param _value) {
		m_l_MED_bal_217 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_k_LOW_bal(t_param _value) {
		m_k_LOW_bal_218 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_j_input(t_param _value) {
		m_j_input_219 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_i_BYPASS(t_param _value) {
		m_i_BYPASS_220 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_h_SOLOHIGH(t_param _value) {
		m_h_SOLOHIGH_221 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_g_SOLOMED(t_param _value) {
		m_g_SOLOMED_222 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_f_SOLOLOW(t_param _value) {
		m_f_SOLOLOW_223 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_e_HIGH(t_param _value) {
		m_e_HIGH_224 = (_value < 0.5 ? 0.5 : (_value > 1.5 ? 1.5 : _value));
	};
	inline void set_d_MED(t_param _value) {
		m_d_MED_225 = (_value < 0.5 ? 0.5 : (_value > 1.5 ? 1.5 : _value));
	};
	inline void set_c_LOW(t_param _value) {
		m_c_LOW_226 = (_value < 0.5 ? 0.5 : (_value > 1.5 ? 1.5 : _value));
	};
	inline void set_b_FREQ2(t_param _value) {
		m_b_FREQ_227 = (_value < 1000 ? 1000 : (_value > 20000 ? 20000 : _value));
	};
	inline void set_a_FREQ1(t_param _value) {
		m_a_FREQ_228 = (_value < 20 ? 20 : (_value > 1000 ? 1000 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 2;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 17; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2" };

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
		case 16: self->set_x_DRYWET(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_a_FREQ_228; break;
		case 1: *value = self->m_b_FREQ_227; break;
		case 2: *value = self->m_c_LOW_226; break;
		case 3: *value = self->m_d_MED_225; break;
		case 4: *value = self->m_e_HIGH_224; break;
		case 5: *value = self->m_f_SOLOLOW_223; break;
		case 6: *value = self->m_g_SOLOMED_222; break;
		case 7: *value = self->m_h_SOLOHIGH_221; break;
		case 8: *value = self->m_i_BYPASS_220; break;
		case 9: *value = self->m_j_input_219; break;
		case 10: *value = self->m_k_LOW_bal_218; break;
		case 11: *value = self->m_l_MED_bal_217; break;
		case 12: *value = self->m_m_HIGH_bal_216; break;
		case 13: *value = self->m_n_MUTLOW_214; break;
		case 14: *value = self->m_o_MUTMED_213; break;
		case 15: *value = self->m_p_MUTHIGH_212; break;
		case 16: *value = self->m_x_DRYWET_215; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(17 * sizeof(ParamInfo));
	self->__commonstate.numparams = 17;
	// initialize parameter 0 ("m_a_FREQ_228")
	pi = self->__commonstate.params + 0;
	pi->name = "a_FREQ1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_a_FREQ_228;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 20;
	pi->outputmax = 1000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_b_FREQ_227")
	pi = self->__commonstate.params + 1;
	pi->name = "b_FREQ2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_b_FREQ_227;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1000;
	pi->outputmax = 20000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_c_LOW_226")
	pi = self->__commonstate.params + 2;
	pi->name = "c_LOW";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_c_LOW_226;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.5;
	pi->outputmax = 1.5;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_d_MED_225")
	pi = self->__commonstate.params + 3;
	pi->name = "d_MED";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d_MED_225;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.5;
	pi->outputmax = 1.5;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_e_HIGH_224")
	pi = self->__commonstate.params + 4;
	pi->name = "e_HIGH";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_e_HIGH_224;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.5;
	pi->outputmax = 1.5;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_f_SOLOLOW_223")
	pi = self->__commonstate.params + 5;
	pi->name = "f_SOLOLOW";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_f_SOLOLOW_223;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_g_SOLOMED_222")
	pi = self->__commonstate.params + 6;
	pi->name = "g_SOLOMED";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_g_SOLOMED_222;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_h_SOLOHIGH_221")
	pi = self->__commonstate.params + 7;
	pi->name = "h_SOLOHIGH";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_h_SOLOHIGH_221;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_i_BYPASS_220")
	pi = self->__commonstate.params + 8;
	pi->name = "i_BYPASS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_i_BYPASS_220;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_j_input_219")
	pi = self->__commonstate.params + 9;
	pi->name = "j_input";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_j_input_219;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_k_LOW_bal_218")
	pi = self->__commonstate.params + 10;
	pi->name = "k_LOW_bal";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_k_LOW_bal_218;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_l_MED_bal_217")
	pi = self->__commonstate.params + 11;
	pi->name = "l_MED_bal";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_l_MED_bal_217;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_m_HIGH_bal_216")
	pi = self->__commonstate.params + 12;
	pi->name = "m_HIGH_bal";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_m_HIGH_bal_216;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_n_MUTLOW_214")
	pi = self->__commonstate.params + 13;
	pi->name = "n_MUTLOW";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_n_MUTLOW_214;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_o_MUTMED_213")
	pi = self->__commonstate.params + 14;
	pi->name = "o_MUTMED";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_o_MUTMED_213;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_p_MUTHIGH_212")
	pi = self->__commonstate.params + 15;
	pi->name = "p_MUTHIGH";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_p_MUTHIGH_212;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 16 ("m_x_DRYWET_215")
	pi = self->__commonstate.params + 16;
	pi->name = "x_DRYWET";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_x_DRYWET_215;
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
