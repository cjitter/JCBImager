{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 9,
			"minor" : 0,
			"revision" : 8,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 280.0, 87.0, 1414.0, 896.0 ],
		"gridsize" : [ 15.0, 15.0 ],
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-116",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 585.0, 7.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-115",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 761.75, 7.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-107",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 761.75, 64.0, 29.5, 22.0 ],
					"text" : "0"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-106",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 690.5, 64.0, 29.5, 22.0 ],
					"text" : "0"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-105",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 616.5, 64.0, 29.5, 22.0 ],
					"text" : "0"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-86",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 174.75, 486.0, 33.0, 22.0 ],
					"text" : "* 0.5"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-85",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 174.75, 455.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-78",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 27.0, 614.0, 33.0, 114.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-77",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 27.0, 550.0, 42.0, 22.0 ],
					"text" : "-~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-70",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1009.0, 233.0, 29.5, 22.0 ],
					"text" : "0.5"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-69",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 917.0, 233.0, 29.5, 22.0 ],
					"text" : "0.5"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-68",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 820.0, 233.0, 29.5, 22.0 ],
					"text" : "0.5"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-66",
					"maxclass" : "flonum",
					"maximum" : 12.0,
					"minimum" : -12.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1199.0, 259.0, 50.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 0 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[12]",
							"parameter_mmax" : 12.0,
							"parameter_mmin" : -12.0,
							"parameter_modmode" : 3,
							"parameter_shortname" : "number[11]",
							"parameter_type" : 0
						}

					}
,
					"varname" : "number[12]"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-65",
					"maxclass" : "flonum",
					"maximum" : 12.0,
					"minimum" : -12.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1124.0, 259.0, 50.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 0 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[11]",
							"parameter_mmax" : 12.0,
							"parameter_mmin" : -12.0,
							"parameter_modmode" : 3,
							"parameter_shortname" : "number[11]",
							"parameter_type" : 0
						}

					}
,
					"varname" : "number[11]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-63",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1199.0, 294.0, 91.0, 22.0 ],
					"text" : "w_MAKEUP $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-62",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1124.0, 294.0, 67.0, 22.0 ],
					"text" : "v_TRIM $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-52",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 317.0, 513.0, 93.0, 20.0 ],
					"text" : "3,4 POST TRIM"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-40",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 366.0, 425.0, 20.0, 76.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-47",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 339.0, 425.0, 20.0, 76.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-60",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1086.0, 97.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-61",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1086.0, 140.0, 95.0, 22.0 ],
					"text" : "p_MUTHIGH $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-58",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 983.0, 97.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-59",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 983.0, 140.0, 91.0, 22.0 ],
					"text" : "o_MUTMED $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-57",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 877.0, 97.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-54",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 877.0, 140.0, 92.0, 22.0 ],
					"text" : "n_MUTLOW $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-53",
					"maxclass" : "flonum",
					"maximum" : 1.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1219.5, 107.0, 50.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 1.0 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[6]",
							"parameter_mmax" : 1.0,
							"parameter_modmode" : 3,
							"parameter_shortname" : "number[6]",
							"parameter_type" : 0
						}

					}
,
					"varname" : "number[6]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-50",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1219.5, 141.0, 89.0, 22.0 ],
					"text" : "x_DRYWET $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-46",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 659.0, 234.0, 131.0, 20.0 ],
					"text" : "0 input MS / 1 input XY"
				}

			}
, 			{
				"box" : 				{
					"attr" : "autoexport",
					"id" : "obj-23",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 275.0, 327.0, 420.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"attr" : "exportfolder",
					"id" : "obj-19",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 260.0, 299.0, 449.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"attr" : "exportname",
					"id" : "obj-17",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 241.0, 273.0, 310.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-45",
					"maxclass" : "flonum",
					"maximum" : 1.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1009.0, 259.0, 50.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 0.5 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[10]",
							"parameter_mmax" : 1.0,
							"parameter_modmode" : 3,
							"parameter_shortname" : "number[10]",
							"parameter_type" : 0
						}

					}
,
					"varname" : "number[10]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-44",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1009.0, 294.0, 95.0, 22.0 ],
					"text" : "m_HIGH_bal $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-42",
					"maxclass" : "flonum",
					"maximum" : 1.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 917.0, 259.0, 50.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 0.5 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[9]",
							"parameter_mmax" : 1.0,
							"parameter_modmode" : 3,
							"parameter_shortname" : "number[9]",
							"parameter_type" : 0
						}

					}
,
					"varname" : "number[9]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-43",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 917.0, 294.0, 84.0, 22.0 ],
					"text" : "l_MED_bal $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-41",
					"maxclass" : "flonum",
					"maximum" : 1.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 820.0, 259.0, 50.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 0.5 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[8]",
							"parameter_mmax" : 1.0,
							"parameter_modmode" : 3,
							"parameter_shortname" : "number[8]",
							"parameter_type" : 0
						}

					}
,
					"varname" : "number[8]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-39",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 820.0, 294.0, 88.0, 22.0 ],
					"text" : "k_LOW_bal $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-35",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 746.0, 259.0, 24.0, 24.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_enum" : [ "off", "on" ],
							"parameter_initial" : [ 1.0 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "toggle",
							"parameter_mmax" : 1,
							"parameter_modmode" : 0,
							"parameter_shortname" : "toggle",
							"parameter_type" : 2
						}

					}
,
					"varname" : "toggle"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 1.0, 0.0, 0.0, 1.0 ],
					"bgcolor2" : [ 0.2, 0.2, 0.2, 1.0 ],
					"bgfillcolor_angle" : 270.0,
					"bgfillcolor_autogradient" : 0.0,
					"bgfillcolor_color" : [ 1.0, 0.0, 0.0, 1.0 ],
					"bgfillcolor_color1" : [ 1.0, 0.0, 0.0, 1.0 ],
					"bgfillcolor_color2" : [ 0.2, 0.2, 0.2, 1.0 ],
					"bgfillcolor_proportion" : 0.5,
					"bgfillcolor_type" : "gradient",
					"gradient" : 1,
					"id" : "obj-22",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 746.0, 294.0, 61.0, 22.0 ],
					"text" : "j_input $1"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 17.0,
					"id" : "obj-21",
					"linecount" : 26,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 438.0, 375.0, 477.0, 500.0 ],
					"text" : "Param a_FREQ1(0, min=20, default=250, max=1000);\nParam b_FREQ2(0, min=1000, default=5000, max=20000);\n\nParam c_LOW(1, min=0, default=1, max=2);\nParam d_MED(1, min=0, default=1, max=2);\nParam e_HIGH(1, min=0, default=1, max=2);\n\nParam f_SOLOLOW(0, min=0, default=0, max=1);\nParam g_SOLOMED(0, min=0, default=0, max=1);\nParam h_SOLOHIGH(0, min=0, default=0, max=1);\n\nParam i_BYPASS(0, min=0, default=0, max=1);\nParam j_input(0, min=0, default=1, max=1);\n\nParam k_LOW_bal(0, max=1, default=0.5, min=0);\nParam l_MED_bal(0, min=0, default=0.5, max=1);\nParam m_HIGH_bal(0, min=0, default=0.5, max=1);\n\nParam x_DRYWET(0, min=0, default=1, max=1);\nParam n_MUTLOW(0, min=0, default=0, max=1);\nParam o_MUTMED(0, min=0, default=0, max=1);\nParam p_MUTHIGH(0, min=0, default=0, max=1);\n\n\nParam v_TRIM(0, min=-12, default=0, max=12);\nParam w_MAKEUP(0, min=-12, default=0, max=12);"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 117.0, 131.0, 19.0, 93.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 190.0, 131.0, 19.0, 93.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-11",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 260.0, 614.0, 33.0, 114.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 101.0, 614.0, 33.0, 114.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-38",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 730.0, 64.0, 29.5, 22.0 ],
					"text" : "1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-37",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 659.0, 64.0, 29.5, 22.0 ],
					"text" : "1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-36",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 585.0, 64.0, 29.5, 22.0 ],
					"text" : "1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-33",
					"maxclass" : "flonum",
					"maximum" : 2.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 659.0, 98.0, 50.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 100.0 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[3]",
							"parameter_mmax" : 2.0,
							"parameter_modmode" : 0,
							"parameter_shortname" : "number[3]",
							"parameter_type" : 0
						}

					}
,
					"varname" : "number[3]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-34",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 659.0, 131.0, 65.0, 22.0 ],
					"text" : "d_MED $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-31",
					"maxclass" : "flonum",
					"maximum" : 10000.0,
					"minimum" : 2500.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 438.0, 60.0, 59.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 5000.0 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[1]",
							"parameter_mmax" : 10000.0,
							"parameter_mmin" : 2500.0,
							"parameter_modmode" : 0,
							"parameter_shortname" : "number[1]",
							"parameter_type" : 0
						}

					}
,
					"varname" : "number[1]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-32",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 438.0, 93.0, 79.0, 22.0 ],
					"text" : "b_FREQ2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-29",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1070.0, 31.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-30",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1070.0, 64.0, 102.0, 22.0 ],
					"text" : "h_SOLOHIGH $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-26",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 967.0, 31.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-27",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 967.0, 64.0, 99.0, 22.0 ],
					"text" : "g_SOLOMED $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 857.0, 31.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-25",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 857.0, 64.0, 96.0, 22.0 ],
					"text" : "f_SOLOLOW $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-20",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 237.0, 43.0, 50.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 1.0 ],
							"parameter_initial_enable" : 1,
							"parameter_invisible" : 1,
							"parameter_longname" : "number[5]",
							"parameter_modmode" : 0,
							"parameter_shortname" : "number[5]",
							"parameter_type" : 3
						}

					}
,
					"varname" : "number[5]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-18",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1192.0, 31.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-16",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1192.0, 64.0, 82.0, 22.0 ],
					"text" : "i_BYPASS $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-12",
					"maxclass" : "flonum",
					"maximum" : 1.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 174.75, 512.0, 45.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 0.5 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[7]",
							"parameter_mmax" : 1.0,
							"parameter_modmode" : 3,
							"parameter_shortname" : "number[7]",
							"parameter_type" : 0
						}

					}
,
					"varname" : "number[7]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 117.0, 42.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 227.0, 678.0, 29.5, 22.0 ],
					"text" : "*~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-4",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 143.0, 678.0, 29.5, 22.0 ],
					"text" : "*~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 161.75, 755.0, 59.0, 59.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-5",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 34.0, 249.0, 68.0, 22.0 ],
					"text" : "exportcode"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-3",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 143.0, 43.0, 88.0, 22.0 ],
					"text" : "open, loop 1, 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 3,
					"outlettype" : [ "signal", "signal", "bang" ],
					"patching_rect" : [ 143.0, 88.0, 113.0, 22.0 ],
					"text" : "sfplay~ 2"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-79",
					"maxclass" : "flonum",
					"maximum" : 2.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 730.0, 98.0, 50.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 100.0 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[4]",
							"parameter_mmax" : 2.0,
							"parameter_modmode" : 0,
							"parameter_shortname" : "number[4]",
							"parameter_type" : 0
						}

					}
,
					"varname" : "number[4]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-56",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 730.0, 131.0, 69.0, 22.0 ],
					"text" : "e_HIGH $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-51",
					"maxclass" : "flonum",
					"maximum" : 2.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 585.0, 98.0, 50.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 100.0 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[2]",
							"parameter_mmax" : 2.0,
							"parameter_modmode" : 0,
							"parameter_shortname" : "number[2]",
							"parameter_type" : 0
						}

					}
,
					"varname" : "number[2]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-48",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 585.0, 131.0, 65.0, 22.0 ],
					"text" : "c_LOW $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-28",
					"maxclass" : "flonum",
					"maximum" : 1000.0,
					"minimum" : 20.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 351.0, 60.0, 59.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 500.0 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number",
							"parameter_mmax" : 1000.0,
							"parameter_mmin" : 20.0,
							"parameter_modmode" : 0,
							"parameter_shortname" : "number",
							"parameter_type" : 0
						}

					}
,
					"varname" : "number"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-8",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 351.0, 93.0, 79.0, 22.0 ],
					"text" : "a_FREQ1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 4,
					"outlettype" : [ "signal", "signal", "signal", "signal" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 9,
							"minor" : 0,
							"revision" : 8,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "dsp.gen",
						"rect" : [ 34.0, 87.0, 1852.0, 904.0 ],
						"gridsize" : [ 15.0, 15.0 ],
						"boxes" : [ 							{
								"box" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1555.600000000000136, 834.0, 35.0, 22.0 ],
									"text" : "out 4"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"id" : "obj-2",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1074.400000000000091, 824.0, 35.0, 22.0 ],
									"text" : "out 3"
								}

							}
, 							{
								"box" : 								{
									"code" : "// =============================================================================\n// PARAMETROS PRINCIPALES DE CONTROL\n// =============================================================================\nParam a_FREQ1(0, min=20, default=250, max=1000);\nParam b_FREQ2(0, min=1000, default=5000, max=20000);\n\nParam c_LOW(1, min=0, default=1, max=2);\nParam d_MED(1, min=0, default=1, max=2);\nParam e_HIGH(1, min=0, default=1, max=2);\n\nParam f_SOLOLOW(0, min=0, default=0, max=1);\nParam g_SOLOMED(0, min=0, default=0, max=1);\nParam h_SOLOHIGH(0, min=0, default=0, max=1);\n\nParam i_BYPASS(0, min=0, default=0, max=1);\nParam j_input(0, min=0, default=1, max=1);\n\nParam k_LOW_bal(0, max=1, default=0.5, min=0);\nParam l_MED_bal(0, min=0, default=0.5, max=1);\nParam m_HIGH_bal(0, min=0, default=0.5, max=1);\n\nParam x_DRYWET(0, min=0, default=1, max=1);\nParam n_MUTLOW(0, min=0, default=0, max=1);\nParam o_MUTMED(0, min=0, default=0, max=1);\nParam p_MUTHIGH(0, min=0, default=0, max=1);\n\nParam v_TRIM(0, min=-12, default=0, max=12); // implementar\nParam w_MAKEUP(0, min=-12, default=0, max=12);\n\n// =============================================================================\n// HISTORIALES (ESTADOS DEL PROCESADOR)\n// =============================================================================\nHistory wetRightLowStage1X1(0);\nHistory wetRightLowStage1X2(0);\nHistory wetRightLowStage1Y1(0);\nHistory wetRightLowStage1Y2(0);\nHistory wetRightLowStage2X1(0);\nHistory wetRightLowStage2X2(0);\nHistory wetRightLowStage2Y1(0);\nHistory wetRightLowStage2Y2(0);\nHistory wetRightHighStage1X1(0);\nHistory wetRightHighStage1X2(0);\nHistory wetRightHighStage1Y1(0);\nHistory wetRightHighStage1Y2(0);\nHistory wetRightHighStage2X1(0);\nHistory wetRightHighStage2X2(0);\nHistory wetRightHighStage2Y1(0);\nHistory wetRightHighStage2Y2(0);\nHistory wetRightMidStage1X1(0);\nHistory wetRightMidStage1X2(0);\nHistory wetRightMidStage1Y1(0);\nHistory wetRightMidStage1Y2(0);\nHistory wetRightMidStage2X1(0);\nHistory wetRightMidStage2X2(0);\nHistory wetRightMidStage2Y1(0);\nHistory wetRightMidStage2Y2(0);\nHistory wetRightHighBandStage1X1(0);\nHistory wetRightHighBandStage1X2(0);\nHistory wetRightHighBandStage1Y1(0);\nHistory wetRightHighBandStage1Y2(0);\nHistory wetRightHighBandStage2X1(0);\nHistory wetRightHighBandStage2X2(0);\nHistory wetRightHighBandStage2Y1(0);\nHistory wetRightHighBandStage2Y2(0);\n\nHistory dryWetHistory(0);\nHistory bypassHistory(0);\nHistory soloMidHistory(0);\nHistory soloHighHistory(0);\nHistory soloLowHistory(0);\nHistory inputModeHistory(0);\nHistory lowBandGainHistory(0);\nHistory midBandGainHistory(0);\nHistory midBalanceHistory(0);\nHistory highBandGainHistory(0);\nHistory highBalanceHistory(0);\nHistory highCrossoverHistory(0);\nHistory lowCrossoverHistory(0);\n\nHistory dryLeftLowLpStage1X1(0);\nHistory dryLeftLowLpStage1X2(0);\nHistory dryLeftLowLpStage1Y1(0);\nHistory dryLeftLowLpStage1Y2(0);\nHistory dryLeftLowLpStage2X1(0);\nHistory dryLeftLowLpStage2X2(0);\nHistory dryLeftLowLpStage2Y1(0);\nHistory dryLeftLowLpStage2Y2(0);\nHistory dryLeftLowHpStage1X1(0);\nHistory dryLeftLowHpStage1X2(0);\nHistory dryLeftLowHpStage1Y1(0);\nHistory dryLeftLowHpStage1Y2(0);\nHistory dryLeftLowHpStage2X1(0);\nHistory dryLeftLowHpStage2X2(0);\nHistory dryLeftLowHpStage2Y1(0);\nHistory dryLeftLowHpStage2Y2(0);\nHistory dryLeftMidLpStage1X1(0);\nHistory dryLeftMidLpStage1X2(0);\nHistory dryLeftMidLpStage1Y1(0);\nHistory dryLeftMidLpStage1Y2(0);\nHistory dryLeftMidLpStage2X1(0);\nHistory dryLeftMidLpStage2X2(0);\nHistory dryLeftMidLpStage2Y1(0);\nHistory dryLeftMidLpStage2Y2(0);\nHistory dryLeftHighHpStage1X1(0);\nHistory dryLeftHighHpStage1X2(0);\nHistory dryLeftHighHpStage1Y1(0);\nHistory dryLeftHighHpStage1Y2(0);\nHistory dryLeftHighHpStage2X1(0);\nHistory dryLeftHighHpStage2X2(0);\nHistory dryLeftHighHpStage2Y1(0);\nHistory dryLeftHighHpStage2Y2(0);\n\nHistory apLeftLowLpStage1X1(0);\nHistory apLeftLowLpStage1X2(0);\nHistory apLeftLowLpStage1Y1(0);\nHistory apLeftLowLpStage1Y2(0);\nHistory apLeftLowLpStage2X1(0);\nHistory apLeftLowLpStage2X2(0);\nHistory apLeftLowLpStage2Y1(0);\nHistory apLeftLowLpStage2Y2(0);\nHistory apLeftLowHpStage1X1(0);\nHistory apLeftLowHpStage1X2(0);\nHistory apLeftLowHpStage1Y1(0);\nHistory apLeftLowHpStage1Y2(0);\nHistory apLeftLowHpStage2X1(0);\nHistory apLeftLowHpStage2X2(0);\nHistory apLeftLowHpStage2Y1(0);\nHistory apLeftLowHpStage2Y2(0);\nHistory dryRightLowLpStage1X1(0);\nHistory dryRightLowLpStage1X2(0);\nHistory dryRightLowLpStage1Y1(0);\nHistory dryRightLowLpStage1Y2(0);\nHistory dryRightLowLpStage2X1(0);\nHistory dryRightLowLpStage2X2(0);\nHistory dryRightLowLpStage2Y1(0);\nHistory dryRightLowLpStage2Y2(0);\nHistory dryRightLowHpStage1X1(0);\nHistory dryRightLowHpStage1X2(0);\nHistory dryRightLowHpStage1Y1(0);\nHistory dryRightLowHpStage1Y2(0);\nHistory dryRightLowHpStage2X1(0);\nHistory dryRightLowHpStage2X2(0);\nHistory dryRightLowHpStage2Y1(0);\nHistory dryRightLowHpStage2Y2(0);\nHistory dryRightMidLpStage1X1(0);\nHistory dryRightMidLpStage1X2(0);\nHistory dryRightMidLpStage1Y1(0);\nHistory dryRightMidLpStage1Y2(0);\nHistory dryRightMidLpStage2X1(0);\nHistory dryRightMidLpStage2X2(0);\nHistory dryRightMidLpStage2Y1(0);\nHistory dryRightMidLpStage2Y2(0);\nHistory dryRightHighHpStage1X1(0);\nHistory dryRightHighHpStage1X2(0);\nHistory dryRightHighHpStage1Y1(0);\nHistory dryRightHighHpStage1Y2(0);\nHistory dryRightHighHpStage2X1(0);\nHistory dryRightHighHpStage2X2(0);\nHistory dryRightHighHpStage2Y1(0);\nHistory dryRightHighHpStage2Y2(0);\nHistory apRightLowLpStage1X1(0);\nHistory apRightLowLpStage1X2(0);\nHistory apRightLowLpStage1Y1(0);\nHistory apRightLowLpStage1Y2(0);\nHistory apRightLowLpStage2X1(0);\nHistory apRightLowLpStage2X2(0);\nHistory apRightLowLpStage2Y1(0);\nHistory apRightLowLpStage2Y2(0);\nHistory apRightLowHpStage1X1(0);\nHistory apRightLowHpStage1X2(0);\nHistory apRightLowHpStage1Y1(0);\nHistory apRightLowHpStage1Y2(0);\nHistory apRightLowHpStage2X1(0);\nHistory apRightLowHpStage2X2(0);\nHistory apRightLowHpStage2Y1(0);\nHistory apRightLowHpStage2Y2(0);\nHistory lowBypassHistory(0);\nHistory lowBalanceHistory(0);\nHistory lowWidthHistory(0);\nHistory lowInputModeHistory(0);\nHistory midBypassHistory(0);\nHistory midMakeupHistory(0);\nHistory midBalanceInternalHistory(0);\nHistory midWidthHistory(0);\nHistory midInputModeHistory(0);\nHistory midBandGainHistoryInternal(0);\nHistory midSideGainHistory(0);\nHistory midInvertHistory(0);\nHistory highBypassHistory(0);\nHistory highMakeupHistory(0);\nHistory highBalanceHistoryInternal(0);\nHistory highWidthHistory(0);\nHistory highInputModeHistory(0);\nHistory highBandGainHistoryInternal(0);\nHistory highSideGainHistory(0);\n\n//  smoothing histories for band mutes\nHistory muteLowHistory(0);\nHistory muteMidHistory(0);\nHistory muteHighHistory(0);\n\n//  Energías RMS y correlación por banda para la normalización de anchura\nHistory lowEnergyM2(1e-12);\nHistory lowSideEnergyM2(1e-12);\nHistory lowCrossCorrelationM2(0); //  Correlación cruzada (LR) LOW\n\n//  Energías por canal para normalización sensible a la correlación\nHistory lowLeftEnergyM2(1e-12);   // <L^2> LOW\nHistory lowRightEnergyM2(1e-12);   // <R^2> LOW\nHistory midLeftEnergyM2(1e-12);   // <L^2> MID\nHistory midRightEnergyM2(1e-12);   // <R^2> MID\nHistory highLeftEnergyM2(1e-12);  // <L^2> HIGH\nHistory highRightEnergyM2(1e-12);  // <R^2> HIGH\nHistory midEnergyM2(1e-12);\nHistory midSideEnergyM2(1e-12);\nHistory midCrossCorrelationM2(0); //  Correlación cruzada (LR) MID\nHistory highEnergyM2(1e-12);\nHistory highSideEnergyM2(1e-12);\nHistory highCrossCorrelationM2(0); //  Correlación cruzada (LR) HIGH\nHistory highInvertHistory(0);\nHistory wetLeftLowStage1X1(0);\nHistory wetLeftLowStage1X2(0);\nHistory wetLeftLowStage1Y1(0);\nHistory wetLeftLowStage1Y2(0);\nHistory wetLeftLowStage2X1(0);\nHistory wetLeftLowStage2X2(0);\nHistory wetLeftLowStage2Y1(0);\nHistory wetLeftLowStage2Y2(0);\nHistory wetLeftHighStage1X1(0);\nHistory wetLeftHighStage1X2(0);\nHistory wetLeftHighStage1Y1(0);\nHistory wetLeftHighStage1Y2(0);\nHistory wetLeftHighStage2X1(0);\nHistory wetLeftHighStage2X2(0);\nHistory wetLeftHighStage2Y1(0);\nHistory wetLeftHighStage2Y2(0);\nHistory wetLeftMidStage1X1(0);\nHistory wetLeftMidStage1X2(0);\nHistory wetLeftMidStage1Y1(0);\nHistory wetLeftMidStage1Y2(0);\nHistory wetLeftMidStage2X1(0);\nHistory wetLeftMidStage2X2(0);\nHistory wetLeftMidStage2Y1(0);\nHistory wetLeftMidStage2Y2(0);\nHistory wetLeftHighBandStage1X1(0);\nHistory wetLeftHighBandStage1X2(0);\nHistory wetLeftHighBandStage1Y1(0);\nHistory wetLeftHighBandStage1Y2(0);\nHistory wetLeftHighBandStage2X1(0);\nHistory wetLeftHighBandStage2X2(0);\nHistory wetLeftHighBandStage2Y1(0);\nHistory wetLeftHighBandStage2Y2(0);\n\n// -----------------------------------------------------------------------------\n// HISTORIALES DE TRIM (SMOOTHING)\n// -----------------------------------------------------------------------------\nHistory trimLeftHistory(1); // smoother L (1 = 0 dB)\nHistory trimRightHistory(1); // smoother R\n\n// -----------------------------------------------------------------------------\n// HISTORIALES DE MAKEUP (SMOOTHING)\n// -----------------------------------------------------------------------------\nHistory makeupLeftHistory(1); // smoother L (arranca en 0 dB = 1)\nHistory makeupRightHistory(1); // smoother R\nHistory trimSharedHistory(1);\nHistory makeupSharedHistory(1);\n\n// =============================================================================\n// CONSTANTES MATEMATICAS COMPARTIDAS\n// =============================================================================\n// Agrupa constantes reutilizables para todas las bandas\npiConstant      = pi;\nsqrtTwoConstant = sqrt(2);\nepsilonConstant = 1e-12;\nslewDefault     = 0.999;\n\n// =============================================================================\n// ALIAS DE PARAMETROS EN camelCase\n// =============================================================================\nfreqLowHz    = a_FREQ1;\nfreqHighHz   = b_FREQ2;\n\nbandLowGain  = c_LOW;\nbandMidGain  = d_MED;\nbandHighGain = e_HIGH;\n\nsoloLow      = f_SOLOLOW;\nsoloMid      = g_SOLOMED;\nsoloHigh     = h_SOLOHIGH;\n\nbypass       = i_BYPASS;\n\ninputMode    = j_input; // 0 = MS, 1 = XY (default = 1, estéreo normal)\n\nlowBalance   = k_LOW_bal;\nmidBalance   = l_MED_bal;\nhighBalance  = m_HIGH_bal;\n\ndryWet       = x_DRYWET;\n\nmuteLow      = n_MUTLOW;\nmuteMid      = o_MUTMED;\nmuteHigh     = p_MUTHIGH;\n\ntrimDb       = v_TRIM;\nmakeupDb     = w_MAKEUP;\n\n// =============================================================================\n// BLOQUE DE ENTRADA Y SUAVIZADO (TRIM / MAKEUP)\n// =============================================================================\n// Suavizado TRIM one-pole (a=0.999) — estéreo linkado\n// =============================================================================\ntrimTarget = dbtoa(trimDb);\n\n// Suavizador compartido (enlazado)\ntrimSharedNext = fixdenorm(0.999 * trimSharedHistory + 0.001 * trimTarget);\n\n// Aplica el mismo valor a ambos canales\ntrimLeftNext  = trimSharedNext;\ntrimRightNext = trimSharedNext;\n\n// Suavizado MAKEUP one-pole (a=0.999) — estéreo linkado // [REFAC-COMMENTS]\nmakeupTarget     = dbtoa(makeupDb);\nmakeupSharedNext = fixdenorm(0.999 * makeupSharedHistory + 0.001 * makeupTarget);\nmakeupLeftNext   = makeupSharedNext;\nmakeupRightNext  = makeupSharedNext;\n\n// -----------------------------------------------------------------------------\n// PUNTOS DE TOMA WET (POST-TRIM)\n// -----------------------------------------------------------------------------\n// Señal wet recortada tras TRIM; la rama seca permanece intacta\nwetInL = in1 * trimLeftNext; // enlazado\nwetInR = in2 * trimRightNext; // enlazado\n\n// Monitor post-trim antes de procesado → out3/out4 // [REFAC-COMMENTS]\nout3 = wetInL;\nout4 = wetInR;\n\n// =============================================================================\n// HELPERS DE NORMALIZACION DE ANCHURA (ENERGIA RMS POR BANDA)\n// =============================================================================\n// FRECUENCIAS DE CRUCE DERIVADAS DE LOS PARAMETROS PUBLICOS\n// =============================================================================\nxoverLow  = clamp(freqLowHz,  20,  1000);\nxoverHigh = clamp(freqHighHz, 1000, 20000);\n\n// =============================================================================\n// CRUCE LR4 (RAMO WET DERECHO)\n// =============================================================================\nwetRIn          = wetInR;\nrightSampleRate = samplerate;\nrightLowHz      = max(10, min(xoverLow, 0.45 * rightSampleRate));\nrightHighPreHz  = max(10, min(xoverHigh, 0.45 * rightSampleRate));\nrightHighHz     = max(rightHighPreHz, rightLowHz + 1);\n\nrightW0Low    = (TWOPI * rightLowHz) / rightSampleRate;\nrightCosLow   = cos(rightW0Low);\nrightSinLow   = sin(rightW0Low);\nrightAlphaLow = rightSinLow / sqrtTwoConstant;\nrightA0Low    = 1 + rightAlphaLow;\nrightA1Low    = -2 * rightCosLow;\nrightA2Low    = 1 - rightAlphaLow;\nrightLpB0Low  = ((1 - rightCosLow) * 0.5) / rightA0Low;\nrightLpB1Low  = (1 - rightCosLow) / rightA0Low;\nrightLpB2Low  = rightLpB0Low;\nrightLpA1Low  = rightA1Low / rightA0Low;\nrightLpA2Low  = rightA2Low / rightA0Low;\nrightHpB0Low  = ((1 + rightCosLow) * 0.5) / rightA0Low;\nrightHpB1Low  = (-(1 + rightCosLow)) / rightA0Low;\nrightHpB2Low  = rightHpB0Low;\nrightHpA1Low  = rightLpA1Low;\nrightHpA2Low  = rightLpA2Low;\n\nrightW0High    = (TWOPI * rightHighHz) / rightSampleRate;\nrightCosHigh   = cos(rightW0High);\nrightSinHigh   = sin(rightW0High);\nrightAlphaHigh = rightSinHigh / sqrtTwoConstant;\nrightA0High    = 1 + rightAlphaHigh;\nrightA1High    = -2 * rightCosHigh;\nrightA2High    = 1 - rightAlphaHigh;\nrightLpB0High  = ((1 - rightCosHigh) * 0.5) / rightA0High;\nrightLpB1High  = (1 - rightCosHigh) / rightA0High;\nrightLpB2High  = rightLpB0High;\nrightLpA1High  = rightA1High / rightA0High;\nrightLpA2High  = rightA2High / rightA0High;\nrightHpB0High  = ((1 + rightCosHigh) * 0.5) / rightA0High;\nrightHpB1High  = (-(1 + rightCosHigh)) / rightA0High;\nrightHpB2High  = rightHpB0High;\nrightHpA1High  = rightLpA1High;\nrightHpA2High  = rightLpA2High;\n\n// Cascada rama baja (LP → LP)\nwetRightLowStage1X1Prev = wetRightLowStage1X1;\nwetRightLowStage1X2Prev = wetRightLowStage1X2;\nwetRightLowStage1Y1Prev = wetRightLowStage1Y1;\nwetRightLowStage1Y2Prev = wetRightLowStage1Y2;\nwetRightLowStage1Sum = (rightLpB0Low * wetRIn) + (rightLpB1Low * wetRightLowStage1X1Prev) + (rightLpB2Low * wetRightLowStage1X2Prev);\nwetRightLowStage1Out = (wetRightLowStage1Sum - (rightLpA1Low * wetRightLowStage1Y1Prev)) - (rightLpA2Low * wetRightLowStage1Y2Prev);\nwetRightLowStage1X2 = wetRightLowStage1X1Prev;\nwetRightLowStage1X1 = wetRIn;\nwetRightLowStage1Y2 = wetRightLowStage1Y1Prev;\nwetRightLowStage1Y1 = wetRightLowStage1Out;\n\nwetRightLowStage2X1Prev = wetRightLowStage2X1;\nwetRightLowStage2X2Prev = wetRightLowStage2X2;\nwetRightLowStage2Y1Prev = wetRightLowStage2Y1;\nwetRightLowStage2Y2Prev = wetRightLowStage2Y2;\nwetRightLowStage2Sum = (rightLpB0Low * wetRightLowStage1Out) + (rightLpB1Low * wetRightLowStage2X1Prev) + (rightLpB2Low * wetRightLowStage2X2Prev);\nwetRightLowStage2Out = (wetRightLowStage2Sum - (rightLpA1Low * wetRightLowStage2Y1Prev)) - (rightLpA2Low * wetRightLowStage2Y2Prev);\nwetRightLowStage2X2 = wetRightLowStage2X1Prev;\nwetRightLowStage2X1 = wetRightLowStage1Out;\nwetRightLowStage2Y2 = wetRightLowStage2Y1Prev;\nwetRightLowStage2Y1 = wetRightLowStage2Out;\n\n// Cascada rama alta (HP → HP)\nwetRightHighStage1X1Prev = wetRightHighStage1X1;\nwetRightHighStage1X2Prev = wetRightHighStage1X2;\nwetRightHighStage1Y1Prev = wetRightHighStage1Y1;\nwetRightHighStage1Y2Prev = wetRightHighStage1Y2;\nwetRightHighStage1Sum = (rightHpB0Low * wetRIn) + (rightHpB1Low * wetRightHighStage1X1Prev) + (rightHpB2Low * wetRightHighStage1X2Prev);\nwetRightHighStage1Out = (wetRightHighStage1Sum - (rightHpA1Low * wetRightHighStage1Y1Prev)) - (rightHpA2Low * wetRightHighStage1Y2Prev);\nwetRightHighStage1X2 = wetRightHighStage1X1Prev;\nwetRightHighStage1X1 = wetRIn;\nwetRightHighStage1Y2 = wetRightHighStage1Y1Prev;\nwetRightHighStage1Y1 = wetRightHighStage1Out;\n\nwetRightHighStage2X1Prev = wetRightHighStage2X1;\nwetRightHighStage2X2Prev = wetRightHighStage2X2;\nwetRightHighStage2Y1Prev = wetRightHighStage2Y1;\nwetRightHighStage2Y2Prev = wetRightHighStage2Y2;\nwetRightHighStage2Sum = (rightHpB0Low * wetRightHighStage1Out) + (rightHpB1Low * wetRightHighStage2X1Prev) + (rightHpB2Low * wetRightHighStage2X2Prev);\nwetRightHighStage2Out = (wetRightHighStage2Sum - (rightHpA1Low * wetRightHighStage2Y1Prev)) - (rightHpA2Low * wetRightHighStage2Y2Prev);\nwetRightHighStage2X2 = wetRightHighStage2X1Prev;\nwetRightHighStage2X1 = wetRightHighStage1Out;\nwetRightHighStage2Y2 = wetRightHighStage2Y1Prev;\nwetRightHighStage2Y1 = wetRightHighStage2Out;\n\nstage1OutR = wetRightLowStage2Out + wetRightHighStage2Out;\n\n// Banda media (LP @ crossover alto)\nwetRightMidStage1X1Prev = wetRightMidStage1X1;\nwetRightMidStage1X2Prev = wetRightMidStage1X2;\nwetRightMidStage1Y1Prev = wetRightMidStage1Y1;\nwetRightMidStage1Y2Prev = wetRightMidStage1Y2;\nwetRightMidStage1Sum = (rightLpB0High * stage1OutR) + (rightLpB1High * wetRightMidStage1X1Prev) + (rightLpB2High * wetRightMidStage1X2Prev);\nwetRightMidStage1Out = (wetRightMidStage1Sum - (rightLpA1High * wetRightMidStage1Y1Prev)) - (rightLpA2High * wetRightMidStage1Y2Prev);\nwetRightMidStage1X2 = wetRightMidStage1X1Prev;\nwetRightMidStage1X1 = stage1OutR;\nwetRightMidStage1Y2 = wetRightMidStage1Y1Prev;\nwetRightMidStage1Y1 = wetRightMidStage1Out;\n\nwetRightMidStage2X1Prev = wetRightMidStage2X1;\nwetRightMidStage2X2Prev = wetRightMidStage2X2;\nwetRightMidStage2Y1Prev = wetRightMidStage2Y1;\nwetRightMidStage2Y2Prev = wetRightMidStage2Y2;\nwetRightMidStage2Sum = (rightLpB0High * wetRightMidStage1Out) + (rightLpB1High * wetRightMidStage2X1Prev) + (rightLpB2High * wetRightMidStage2X2Prev);\nwetRightMidStage2Out = (wetRightMidStage2Sum - (rightLpA1High * wetRightMidStage2Y1Prev)) - (rightLpA2High * wetRightMidStage2Y2Prev);\nwetRightMidStage2X2 = wetRightMidStage2X1Prev;\nwetRightMidStage2X1 = wetRightMidStage1Out;\nwetRightMidStage2Y2 = wetRightMidStage2Y1Prev;\nwetRightMidStage2Y1 = wetRightMidStage2Out;\n\n// Banda alta (HP @ crossover alto)\nwetRightHighBandStage1X1Prev = wetRightHighBandStage1X1;\nwetRightHighBandStage1X2Prev = wetRightHighBandStage1X2;\nwetRightHighBandStage1Y1Prev = wetRightHighBandStage1Y1;\nwetRightHighBandStage1Y2Prev = wetRightHighBandStage1Y2;\nwetRightHighBandStage1Sum = (rightHpB0High * stage1OutR) + (rightHpB1High * wetRightHighBandStage1X1Prev) + (rightHpB2High * wetRightHighBandStage1X2Prev);\nwetRightHighBandStage1Out = (wetRightHighBandStage1Sum - (rightHpA1High * wetRightHighBandStage1Y1Prev)) - (rightHpA2High * wetRightHighBandStage1Y2Prev);\nwetRightHighBandStage1X2 = wetRightHighBandStage1X1Prev;\nwetRightHighBandStage1X1 = stage1OutR;\nwetRightHighBandStage1Y2 = wetRightHighBandStage1Y1Prev;\nwetRightHighBandStage1Y1 = wetRightHighBandStage1Out;\n\nwetRightHighBandStage2X1Prev = wetRightHighBandStage2X1;\nwetRightHighBandStage2X2Prev = wetRightHighBandStage2X2;\nwetRightHighBandStage2Y1Prev = wetRightHighBandStage2Y1;\nwetRightHighBandStage2Y2Prev = wetRightHighBandStage2Y2;\nwetRightHighBandStage2Sum = (rightHpB0High * wetRightHighBandStage1Out) + (rightHpB1High * wetRightHighBandStage2X1Prev) + (rightHpB2High * wetRightHighBandStage2X2Prev);\nwetRightHighBandStage2Out = (wetRightHighBandStage2Sum - (rightHpA1High * wetRightHighBandStage2Y1Prev)) - (rightHpA2High * wetRightHighBandStage2Y2Prev);\nwetRightHighBandStage2X2 = wetRightHighBandStage2X1Prev;\nwetRightHighBandStage2X1 = wetRightHighBandStage1Out;\nwetRightHighBandStage2Y2 = wetRightHighBandStage2Y1Prev;\nwetRightHighBandStage2Y1 = wetRightHighBandStage2Out;\n\n// Alias para legibilidad (salidas crossover R)\nlowBandR    = wetRightMidStage2Out;\nhighBandR   = wetRightHighBandStage2Out;\nstage1SumR  = stage1OutR; // identidad: wetRightLowStage2Out + wetRightHighStage2Out\nwetBandSumR = lowBandR + highBandR; // suma en línea para facilitar la lectura\n\n// =============================================================================\n// CRUCE LR4 (RAMO WET IZQUIERDO)\n// =============================================================================\n// Reflejo del LR4 derecho con nombres legibles para el canal izquierdo\nwetLIn         = wetInL;\nleftSampleRate = samplerate;\nleftLowHz      = max(10, min(xoverLow, 0.45 * leftSampleRate));\nleftHighPreHz  = max(10, min(xoverHigh, 0.45 * leftSampleRate));\nleftHighHz     = max(leftHighPreHz, leftLowHz + 1);\n\nleftW0Low    = (TWOPI * leftLowHz) / leftSampleRate;\nleftCosLow   = cos(leftW0Low);\nleftSinLow   = sin(leftW0Low);\nleftAlphaLow = leftSinLow / sqrtTwoConstant;\nleftA0Low    = 1 + leftAlphaLow;\nleftA1Low    = -2 * leftCosLow;\nleftA2Low    = 1 - leftAlphaLow;\nleftLpB0Low  = ((1 - leftCosLow) * 0.5) / leftA0Low;\nleftLpB1Low  = (1 - leftCosLow) / leftA0Low;\nleftLpB2Low  = leftLpB0Low;\nleftLpA1Low  = leftA1Low / leftA0Low;\nleftLpA2Low  = leftA2Low / leftA0Low;\nleftHpB0Low  = ((1 + leftCosLow) * 0.5) / leftA0Low;\nleftHpB1Low  = (-(1 + leftCosLow)) / leftA0Low;\nleftHpB2Low  = leftHpB0Low;\nleftHpA1Low  = leftLpA1Low;\nleftHpA2Low  = leftLpA2Low;\n\nleftW0High    = (TWOPI * leftHighHz) / leftSampleRate;\nleftCosHigh   = cos(leftW0High);\nleftSinHigh   = sin(leftW0High);\nleftAlphaHigh = leftSinHigh / sqrtTwoConstant;\nleftA0High    = 1 + leftAlphaHigh;\nleftA1High    = -2 * leftCosHigh;\nleftA2High    = 1 - leftAlphaHigh;\nleftLpB0High  = ((1 - leftCosHigh) * 0.5) / leftA0High;\nleftLpB1High  = (1 - leftCosHigh) / leftA0High;\nleftLpB2High  = leftLpB0High;\nleftLpA1High  = leftA1High / leftA0High;\nleftLpA2High  = leftA2High / leftA0High;\nleftHpB0High  = ((1 + leftCosHigh) * 0.5) / leftA0High;\nleftHpB1High  = (-(1 + leftCosHigh)) / leftA0High;\nleftHpB2High  = leftHpB0High;\nleftHpA1High  = leftLpA1High;\nleftHpA2High  = leftLpA2High;\n\n// Cascada rama baja (LP → LP)\nwetLeftLowStage1X1Prev = wetLeftLowStage1X1;\nwetLeftLowStage1X2Prev = wetLeftLowStage1X2;\nwetLeftLowStage1Y1Prev = wetLeftLowStage1Y1;\nwetLeftLowStage1Y2Prev = wetLeftLowStage1Y2;\nwetLeftLowStage1Sum = (leftLpB0Low * wetLIn) + (leftLpB1Low * wetLeftLowStage1X1Prev) + (leftLpB2Low * wetLeftLowStage1X2Prev);\nwetLeftLowStage1Out = (wetLeftLowStage1Sum - (leftLpA1Low * wetLeftLowStage1Y1Prev)) - (leftLpA2Low * wetLeftLowStage1Y2Prev);\nwetLeftLowStage1X2 = wetLeftLowStage1X1Prev;\nwetLeftLowStage1X1 = wetLIn;\nwetLeftLowStage1Y2 = wetLeftLowStage1Y1Prev;\nwetLeftLowStage1Y1 = wetLeftLowStage1Out;\n\nwetLeftLowStage2X1Prev = wetLeftLowStage2X1;\nwetLeftLowStage2X2Prev = wetLeftLowStage2X2;\nwetLeftLowStage2Y1Prev = wetLeftLowStage2Y1;\nwetLeftLowStage2Y2Prev = wetLeftLowStage2Y2;\nwetLeftLowStage2Sum = (leftLpB0Low * wetLeftLowStage1Out) + (leftLpB1Low * wetLeftLowStage2X1Prev) + (leftLpB2Low * wetLeftLowStage2X2Prev);\nwetLeftLowStage2Out = (wetLeftLowStage2Sum - (leftLpA1Low * wetLeftLowStage2Y1Prev)) - (leftLpA2Low * wetLeftLowStage2Y2Prev);\nwetLeftLowStage2X2 = wetLeftLowStage2X1Prev;\nwetLeftLowStage2X1 = wetLeftLowStage1Out;\nwetLeftLowStage2Y2 = wetLeftLowStage2Y1Prev;\nwetLeftLowStage2Y1 = wetLeftLowStage2Out;\n\n// Cascada rama alta (HP → HP)\nwetLeftHighStage1X1Prev = wetLeftHighStage1X1;\nwetLeftHighStage1X2Prev = wetLeftHighStage1X2;\nwetLeftHighStage1Y1Prev = wetLeftHighStage1Y1;\nwetLeftHighStage1Y2Prev = wetLeftHighStage1Y2;\nwetLeftHighStage1Sum = (leftHpB0Low * wetLIn) + (leftHpB1Low * wetLeftHighStage1X1Prev) + (leftHpB2Low * wetLeftHighStage1X2Prev);\nwetLeftHighStage1Out = (wetLeftHighStage1Sum - (leftHpA1Low * wetLeftHighStage1Y1Prev)) - (leftHpA2Low * wetLeftHighStage1Y2Prev);\nwetLeftHighStage1X2 = wetLeftHighStage1X1Prev;\nwetLeftHighStage1X1 = wetLIn;\nwetLeftHighStage1Y2 = wetLeftHighStage1Y1Prev;\nwetLeftHighStage1Y1 = wetLeftHighStage1Out;\n\nwetLeftHighStage2X1Prev = wetLeftHighStage2X1;\nwetLeftHighStage2X2Prev = wetLeftHighStage2X2;\nwetLeftHighStage2Y1Prev = wetLeftHighStage2Y1;\nwetLeftHighStage2Y2Prev = wetLeftHighStage2Y2;\nwetLeftHighStage2Sum = (leftHpB0Low * wetLeftHighStage1Out) + (leftHpB1Low * wetLeftHighStage2X1Prev) + (leftHpB2Low * wetLeftHighStage2X2Prev);\nwetLeftHighStage2Out = (wetLeftHighStage2Sum - (leftHpA1Low * wetLeftHighStage2Y1Prev)) - (leftHpA2Low * wetLeftHighStage2Y2Prev);\nwetLeftHighStage2X2 = wetLeftHighStage2X1Prev;\nwetLeftHighStage2X1 = wetLeftHighStage1Out;\nwetLeftHighStage2Y2 = wetLeftHighStage2Y1Prev;\nwetLeftHighStage2Y1 = wetLeftHighStage2Out;\n\nstage1OutL = wetLeftLowStage2Out + wetLeftHighStage2Out;\n\n// Banda media (LP @ crossover alto)\nwetLeftMidStage1X1Prev = wetLeftMidStage1X1;\nwetLeftMidStage1X2Prev = wetLeftMidStage1X2;\nwetLeftMidStage1Y1Prev = wetLeftMidStage1Y1;\nwetLeftMidStage1Y2Prev = wetLeftMidStage1Y2;\nwetLeftMidStage1Sum = (leftLpB0High * stage1OutL) + (leftLpB1High * wetLeftMidStage1X1Prev) + (leftLpB2High * wetLeftMidStage1X2Prev);\nwetLeftMidStage1Out = (wetLeftMidStage1Sum - (leftLpA1High * wetLeftMidStage1Y1Prev)) - (leftLpA2High * wetLeftMidStage1Y2Prev);\nwetLeftMidStage1X2 = wetLeftMidStage1X1Prev;\nwetLeftMidStage1X1 = stage1OutL;\nwetLeftMidStage1Y2 = wetLeftMidStage1Y1Prev;\nwetLeftMidStage1Y1 = wetLeftMidStage1Out;\n\nwetLeftMidStage2X1Prev = wetLeftMidStage2X1;\nwetLeftMidStage2X2Prev = wetLeftMidStage2X2;\nwetLeftMidStage2Y1Prev = wetLeftMidStage2Y1;\nwetLeftMidStage2Y2Prev = wetLeftMidStage2Y2;\nwetLeftMidStage2Sum = (leftLpB0High * wetLeftMidStage1Out) + (leftLpB1High * wetLeftMidStage2X1Prev) + (leftLpB2High * wetLeftMidStage2X2Prev);\nwetLeftMidStage2Out = (wetLeftMidStage2Sum - (leftLpA1High * wetLeftMidStage2Y1Prev)) - (leftLpA2High * wetLeftMidStage2Y2Prev);\nwetLeftMidStage2X2 = wetLeftMidStage2X1Prev;\nwetLeftMidStage2X1 = wetLeftMidStage1Out;\nwetLeftMidStage2Y2 = wetLeftMidStage2Y1Prev;\nwetLeftMidStage2Y1 = wetLeftMidStage2Out;\n\n// Banda alta (HP @ crossover alto)\nwetLeftHighBandStage1X1Prev = wetLeftHighBandStage1X1;\nwetLeftHighBandStage1X2Prev = wetLeftHighBandStage1X2;\nwetLeftHighBandStage1Y1Prev = wetLeftHighBandStage1Y1;\nwetLeftHighBandStage1Y2Prev = wetLeftHighBandStage1Y2;\nwetLeftHighBandStage1Sum = (leftHpB0High * stage1OutL) + (leftHpB1High * wetLeftHighBandStage1X1Prev) + (leftHpB2High * wetLeftHighBandStage1X2Prev);\nwetLeftHighBandStage1Out = (wetLeftHighBandStage1Sum - (leftHpA1High * wetLeftHighBandStage1Y1Prev)) - (leftHpA2High * wetLeftHighBandStage1Y2Prev);\nwetLeftHighBandStage1X2 = wetLeftHighBandStage1X1Prev;\nwetLeftHighBandStage1X1 = stage1OutL;\nwetLeftHighBandStage1Y2 = wetLeftHighBandStage1Y1Prev;\nwetLeftHighBandStage1Y1 = wetLeftHighBandStage1Out;\n\nwetLeftHighBandStage2X1Prev = wetLeftHighBandStage2X1;\nwetLeftHighBandStage2X2Prev = wetLeftHighBandStage2X2;\nwetLeftHighBandStage2Y1Prev = wetLeftHighBandStage2Y1;\nwetLeftHighBandStage2Y2Prev = wetLeftHighBandStage2Y2;\nwetLeftHighBandStage2Sum = (leftHpB0High * wetLeftHighBandStage1Out) + (leftHpB1High * wetLeftHighBandStage2X1Prev) + (leftHpB2High * wetLeftHighBandStage2X2Prev);\nwetLeftHighBandStage2Out = (wetLeftHighBandStage2Sum - (leftHpA1High * wetLeftHighBandStage2Y1Prev)) - (leftHpA2High * wetLeftHighBandStage2Y2Prev);\nwetLeftHighBandStage2X2 = wetLeftHighBandStage2X1Prev;\nwetLeftHighBandStage2X1 = wetLeftHighBandStage1Out;\nwetLeftHighBandStage2Y2 = wetLeftHighBandStage2Y1Prev;\nwetLeftHighBandStage2Y1 = wetLeftHighBandStage2Out;\n\n// Alias para legibilidad (salidas crossover L)\nlowBandL    = wetLeftMidStage2Out;\nhighBandL   = wetLeftHighBandStage2Out;\nstage1SumL  = stage1OutL; // identidad: low + high\nwetBandSumL = lowBandL + highBandL;\n\n// =============================================================================\n// SUAVIZADO DE CONTROLES GLOBALES (DRYWET/BYPASS/SOLOS)\n// =============================================================================\ndryWetSlew        = slewDefault;\ndryWetSmoothed    = mix(dryWet, dryWetHistory, dryWetSlew);\ndryWetControl     = dryWetSmoothed;\ndryWetHistoryNext = fixdenorm(dryWetSmoothed);\n\nbypassSlew        = slewDefault;\nbypassSmoothed    = mix(bypass, bypassHistory, bypassSlew);\nbypassHistoryNext = fixdenorm(bypassSmoothed);\nbypassMask        = 1 - bypassSmoothed;\n\nsoloZero           = int(0);\nsoloMidSlew        = slewDefault;\nsoloMidSmoothed    = mix(soloMid, soloMidHistory, soloMidSlew);\nsoloMidHistoryNext = fixdenorm(soloMidSmoothed);\n\nsoloHighSlew        = slewDefault;\nsoloHighSmoothed    = mix(soloHigh, soloHighHistory, soloHighSlew);\nsoloHighHistoryNext = fixdenorm(soloHighSmoothed);\n\nsoloMidZero     = int(0);\nsoloLowSlew     = slewDefault;\nsoloLowSmoothed = mix(soloLow, soloLowHistory, soloLowSlew);\n\n// Alias para la etapa de suavizado de solos\nsoloMidSm  = soloMidSmoothed;\nsoloHighSm = soloHighSmoothed;\nsoloLowSm  = soloLowSmoothed;\n\n// Máscaras de solo por banda\nsoloMaskLow  = soloHighSm + soloMidSm;  // silencia LOW cuando MID o HIGH están en solo\nsoloMaskMid  = soloHighSm + soloLowSm;  // silencia MID cuando HIGH o LOW están en solo\nsoloMaskHigh = soloMidSm  + soloLowSm;  // silencia HIGH cuando MID o LOW están en solo\nsoloLowHistoryNext = fixdenorm(soloLowSmoothed);\nsoloHighZero       = int(0);\n\n// Los relés setparam con nombre mantienen legible la automatización del host\nsetparamLowBalance     = lowBalance;\ninputModeSlew          = slewDefault;\ninputModeSmoothed      = mix(inputMode, inputModeHistory, inputModeSlew);\ninputModeHistoryNext   = fixdenorm(inputModeSmoothed);\nsetparamInputMode      = inputModeSmoothed;\nsetparamInputModeReset = int(0);\n\nlowBandGainSlew        = slewDefault;\nlowBandGainSmoothed    = mix(bandLowGain, lowBandGainHistory, lowBandGainSlew);\nlowBandGainHistoryNext = fixdenorm(lowBandGainSmoothed);\nsetparamLowGain        = lowBandGainSmoothed;\n\nsetparamLowGainReset = int(0);\n\nmidBandGainSlew        = slewDefault;\nmidBandGainSmoothed    = mix(bandMidGain, midBandGainHistory, midBandGainSlew);\nmidBandGainHistoryNext = fixdenorm(midBandGainSmoothed);\nsetparamMidGain        = midBandGainSmoothed;\n\nmidBalanceSlew        = slewDefault;\nmidBalanceSmoothed    = mix(midBalance, midBalanceHistory, midBalanceSlew);\nmidBalanceHistoryNext = fixdenorm(midBalanceSmoothed);\nsetparamMidBalance    = midBalanceSmoothed;\n\nsetparamMidGainReset = int(0);\n\nhighBandGainSlew        = slewDefault;\nhighBandGainSmoothed    = mix(bandHighGain, highBandGainHistory, highBandGainSlew);\nhighBandGainHistoryNext = fixdenorm(highBandGainSmoothed);\nsetparamHighGain        = highBandGainSmoothed;\n\nhighBalanceSlew        = slewDefault;\nhighBalanceSmoothed    = mix(highBalance, highBalanceHistory, highBalanceSlew);\nhighBalanceHistoryNext = fixdenorm(highBalanceSmoothed);\nsetparamHighBalance    = highBalanceSmoothed;\n\nhighCrossoverSlew        = slewDefault;\nhighCrossoverSmoothed    = mix(freqHighHz, highCrossoverHistory, highCrossoverSlew);\nhighCrossoverHistoryNext = fixdenorm(highCrossoverSmoothed);\nsetparamHighCrossover    = highCrossoverSmoothed;\n\nlowCrossoverSlew        = slewDefault;\nlowCrossoverSmoothed    = mix(freqLowHz, lowCrossoverHistory, lowCrossoverSlew);\nlowCrossoverHistoryNext = fixdenorm(lowCrossoverSmoothed);\nsetparamLowCrossover    = lowCrossoverSmoothed;\n\n// Red LR4/all-pass seca izquierda con nombres legibles\nleftLowTargetHz   = clamp(setparamLowCrossover, 20, 1000);\nleftHighTargetHz  = clamp(setparamHighCrossover, 1000, 20000);\ndryLeftInput      = wetInL;\ndryLeftSampleRate = samplerate;\n\nleftLowHz     = max(10, min(leftLowTargetHz, 0.45 * dryLeftSampleRate));\nleftHighPreHz = max(10, min(leftHighTargetHz, 0.45 * dryLeftSampleRate));\nleftHighHz    = max(leftHighPreHz, leftLowHz + 1);\n\nleftDryW0Low    = (TWOPI * leftLowHz) / dryLeftSampleRate;\nleftDryCosLow   = cos(leftDryW0Low);\nleftDrySinLow   = sin(leftDryW0Low);\nleftDryAlphaLow = leftDrySinLow / sqrtTwoConstant;\nleftDryA0Low    = 1 + leftDryAlphaLow;\nleftDryA1Low    = -2 * leftDryCosLow;\nleftDryA2Low    = 1 - leftDryAlphaLow;\nleftDryLpB0Low  = ((1 - leftDryCosLow) * 0.5) / leftDryA0Low;\nleftDryLpB1Low  = (1 - leftDryCosLow) / leftDryA0Low;\nleftDryLpB2Low  = leftDryLpB0Low;\nleftDryLpA1Low  = leftDryA1Low / leftDryA0Low;\nleftDryLpA2Low  = leftDryA2Low / leftDryA0Low;\nleftDryHpB0Low  = ((1 + leftDryCosLow) * 0.5) / leftDryA0Low;\nleftDryHpB1Low  = (-(1 + leftDryCosLow)) / leftDryA0Low;\nleftDryHpB2Low  = leftDryHpB0Low;\nleftDryHpA1Low  = leftDryLpA1Low;\nleftDryHpA2Low  = leftDryLpA2Low;\n\nleftDryW0High    = (TWOPI * leftHighHz) / dryLeftSampleRate;\nleftDryCosHigh   = cos(leftDryW0High);\nleftDrySinHigh   = sin(leftDryW0High);\nleftDryAlphaHigh = leftDrySinHigh / sqrtTwoConstant;\nleftDryA0High    = 1 + leftDryAlphaHigh;\nleftDryA1High    = -2 * leftDryCosHigh;\nleftDryA2High    = 1 - leftDryAlphaHigh;\nleftDryLpB0High  = ((1 - leftDryCosHigh) * 0.5) / leftDryA0High;\nleftDryLpB1High  = (1 - leftDryCosHigh) / leftDryA0High;\nleftDryLpB2High  = leftDryLpB0High;\nleftDryLpA1High  = leftDryA1High / leftDryA0High;\nleftDryLpA2High  = leftDryA2High / leftDryA0High;\nleftDryHpB0High  = ((1 + leftDryCosHigh) * 0.5) / leftDryA0High;\nleftDryHpB1High  = (-(1 + leftDryCosHigh)) / leftDryA0High;\nleftDryHpB2High  = leftDryHpB0High;\nleftDryHpA1High  = leftDryLpA1High;\nleftDryHpA2High  = leftDryLpA2High;\n\n// Cascada rama baja (LP → LP)\ndryLeftLowStage1X1Prev = fixdenorm(dryLeftLowLpStage1X1);\ndryLeftLowStage1X2Prev = fixdenorm(dryLeftLowLpStage1X2);\ndryLeftLowStage1Y1Prev = fixdenorm(dryLeftLowLpStage1Y1);\ndryLeftLowStage1Y2Prev = fixdenorm(dryLeftLowLpStage1Y2);\ndryLeftLowStage1Sum = (leftDryLpB0Low * dryLeftInput) + (leftDryLpB1Low * dryLeftLowStage1X1Prev) + (leftDryLpB2Low * dryLeftLowStage1X2Prev);\ndryLeftLowStage1Out = (dryLeftLowStage1Sum - (leftDryLpA1Low * dryLeftLowStage1Y1Prev)) - (leftDryLpA2Low * dryLeftLowStage1Y2Prev);\ndryLeftLowLpStage1X2 = dryLeftLowStage1X1Prev;\ndryLeftLowLpStage1X1 = dryLeftInput;\ndryLeftLowLpStage1Y2 = dryLeftLowStage1Y1Prev;\ndryLeftLowLpStage1Y1 = dryLeftLowStage1Out;\n\ndryLeftLowStage2X1Prev = fixdenorm(dryLeftLowLpStage2X1);\ndryLeftLowStage2X2Prev = fixdenorm(dryLeftLowLpStage2X2);\ndryLeftLowStage2Y1Prev = fixdenorm(dryLeftLowLpStage2Y1);\ndryLeftLowStage2Y2Prev = fixdenorm(dryLeftLowLpStage2Y2);\ndryLeftLowStage2Sum = (leftDryLpB0Low * dryLeftLowStage1Out) + (leftDryLpB1Low * dryLeftLowStage2X1Prev) + (leftDryLpB2Low * dryLeftLowStage2X2Prev);\ndryLeftLowStage2Out = (dryLeftLowStage2Sum - (leftDryLpA1Low * dryLeftLowStage2Y1Prev)) - (leftDryLpA2Low * dryLeftLowStage2Y2Prev);\ndryLeftLowLpStage2X2 = dryLeftLowStage2X1Prev;\ndryLeftLowLpStage2X1 = dryLeftLowStage1Out;\ndryLeftLowLpStage2Y2 = dryLeftLowStage2Y1Prev;\ndryLeftLowLpStage2Y1 = dryLeftLowStage2Out;\n\n// Cascada rama alta (HP → HP)\ndryLeftHighStage1X1Prev = fixdenorm(dryLeftLowHpStage1X1);\ndryLeftHighStage1X2Prev = fixdenorm(dryLeftLowHpStage1X2);\ndryLeftHighStage1Y1Prev = fixdenorm(dryLeftLowHpStage1Y1);\ndryLeftHighStage1Y2Prev = fixdenorm(dryLeftLowHpStage1Y2);\ndryLeftHighStage1Sum = (leftDryHpB0Low * dryLeftInput) + (leftDryHpB1Low * dryLeftHighStage1X1Prev) + (leftDryHpB2Low * dryLeftHighStage1X2Prev);\ndryLeftHighStage1Out = (dryLeftHighStage1Sum - (leftDryHpA1Low * dryLeftHighStage1Y1Prev)) - (leftDryHpA2Low * dryLeftHighStage1Y2Prev);\ndryLeftLowHpStage1X2 = dryLeftHighStage1X1Prev;\ndryLeftLowHpStage1X1 = dryLeftInput;\ndryLeftLowHpStage1Y2 = dryLeftHighStage1Y1Prev;\ndryLeftLowHpStage1Y1 = dryLeftHighStage1Out;\n\ndryLeftHighStage2X1Prev = fixdenorm(dryLeftLowHpStage2X1);\ndryLeftHighStage2X2Prev = fixdenorm(dryLeftLowHpStage2X2);\ndryLeftHighStage2Y1Prev = fixdenorm(dryLeftLowHpStage2Y1);\ndryLeftHighStage2Y2Prev = fixdenorm(dryLeftLowHpStage2Y2);\ndryLeftHighStage2Sum = (leftDryHpB0Low * dryLeftHighStage1Out) + (leftDryHpB1Low * dryLeftHighStage2X1Prev) + (leftDryHpB2Low * dryLeftHighStage2X2Prev);\ndryLeftHighStage2Out = (dryLeftHighStage2Sum - (leftDryHpA1Low * dryLeftHighStage2Y1Prev)) - (leftDryHpA2Low * dryLeftHighStage2Y2Prev);\ndryLeftLowHpStage2X2 = dryLeftHighStage2X1Prev;\ndryLeftLowHpStage2X1 = dryLeftHighStage1Out;\ndryLeftLowHpStage2Y2 = dryLeftHighStage2Y1Prev;\ndryLeftLowHpStage2Y1 = dryLeftHighStage2Out;\n\n// Compensación all-pass (banda baja)\ndryLeftApLowLpStage1X1Prev = fixdenorm(apLeftLowLpStage1X1);\ndryLeftApLowLpStage1X2Prev = fixdenorm(apLeftLowLpStage1X2);\ndryLeftApLowLpStage1Y1Prev = fixdenorm(apLeftLowLpStage1Y1);\ndryLeftApLowLpStage1Y2Prev = fixdenorm(apLeftLowLpStage1Y2);\ndryLeftApLowLpStage1Sum = (leftDryLpB0High * dryLeftLowStage2Out) + (leftDryLpB1High * dryLeftApLowLpStage1X1Prev) + (leftDryLpB2High * dryLeftApLowLpStage1X2Prev);\ndryLeftApLowLpStage1Out = (dryLeftApLowLpStage1Sum - (leftDryLpA1High * dryLeftApLowLpStage1Y1Prev)) - (leftDryLpA2High * dryLeftApLowLpStage1Y2Prev);\napLeftLowLpStage1X2 = dryLeftApLowLpStage1X1Prev;\napLeftLowLpStage1X1 = dryLeftLowStage2Out;\napLeftLowLpStage1Y2 = dryLeftApLowLpStage1Y1Prev;\napLeftLowLpStage1Y1 = dryLeftApLowLpStage1Out;\n\ndryLeftApLowLpStage2X1Prev = fixdenorm(apLeftLowLpStage2X1);\ndryLeftApLowLpStage2X2Prev = fixdenorm(apLeftLowLpStage2X2);\ndryLeftApLowLpStage2Y1Prev = fixdenorm(apLeftLowLpStage2Y1);\ndryLeftApLowLpStage2Y2Prev = fixdenorm(apLeftLowLpStage2Y2);\ndryLeftApLowLpStage2Sum = (leftDryLpB0High * dryLeftApLowLpStage1Out) + (leftDryLpB1High * dryLeftApLowLpStage2X1Prev) + (leftDryLpB2High * dryLeftApLowLpStage2X2Prev);\ndryLeftApLowLpStage2Out = (dryLeftApLowLpStage2Sum - (leftDryLpA1High * dryLeftApLowLpStage2Y1Prev)) - (leftDryLpA2High * dryLeftApLowLpStage2Y2Prev);\napLeftLowLpStage2X2 = dryLeftApLowLpStage2X1Prev;\napLeftLowLpStage2X1 = dryLeftApLowLpStage1Out;\napLeftLowLpStage2Y2 = dryLeftApLowLpStage2Y1Prev;\napLeftLowLpStage2Y1 = dryLeftApLowLpStage2Out;\n\ndryLeftApLowHpStage1X1Prev = fixdenorm(apLeftLowHpStage1X1);\ndryLeftApLowHpStage1X2Prev = fixdenorm(apLeftLowHpStage1X2);\ndryLeftApLowHpStage1Y1Prev = fixdenorm(apLeftLowHpStage1Y1);\ndryLeftApLowHpStage1Y2Prev = fixdenorm(apLeftLowHpStage1Y2);\ndryLeftApLowHpStage1Sum = (leftDryHpB0High * dryLeftLowStage2Out) + (leftDryHpB1High * dryLeftApLowHpStage1X1Prev) + (leftDryHpB2High * dryLeftApLowHpStage1X2Prev);\ndryLeftApLowHpStage1Out = (dryLeftApLowHpStage1Sum - (leftDryHpA1High * dryLeftApLowHpStage1Y1Prev)) - (leftDryHpA2High * dryLeftApLowHpStage1Y2Prev);\napLeftLowHpStage1X2 = dryLeftApLowHpStage1X1Prev;\napLeftLowHpStage1X1 = dryLeftLowStage2Out;\napLeftLowHpStage1Y2 = dryLeftApLowHpStage1Y1Prev;\napLeftLowHpStage1Y1 = dryLeftApLowHpStage1Out;\n\ndryLeftApLowHpStage2X1Prev = fixdenorm(apLeftLowHpStage2X1);\ndryLeftApLowHpStage2X2Prev = fixdenorm(apLeftLowHpStage2X2);\ndryLeftApLowHpStage2Y1Prev = fixdenorm(apLeftLowHpStage2Y1);\ndryLeftApLowHpStage2Y2Prev = fixdenorm(apLeftLowHpStage2Y2);\ndryLeftApLowHpStage2Sum = (leftDryHpB0High * dryLeftApLowHpStage1Out) + (leftDryHpB1High * dryLeftApLowHpStage2X1Prev) + (leftDryHpB2High * dryLeftApLowHpStage2X2Prev);\ndryLeftApLowHpStage2Out = (dryLeftApLowHpStage2Sum - (leftDryHpA1High * dryLeftApLowHpStage2Y1Prev)) - (leftDryHpA2High * dryLeftApLowHpStage2Y2Prev);\napLeftLowHpStage2X2 = dryLeftApLowHpStage2X1Prev;\napLeftLowHpStage2X1 = dryLeftApLowHpStage1Out;\napLeftLowHpStage2Y2 = dryLeftApLowHpStage2Y1Prev;\napLeftLowHpStage2Y1 = dryLeftApLowHpStage2Out;\n\ndryLeftLowBand = dryLeftApLowLpStage2Out + dryLeftApLowHpStage2Out;\n\n// Banda media (LP @ crossover alto)\ndryLeftMidStage1X1Prev = fixdenorm(dryLeftMidLpStage1X1);\ndryLeftMidStage1X2Prev = fixdenorm(dryLeftMidLpStage1X2);\ndryLeftMidStage1Y1Prev = fixdenorm(dryLeftMidLpStage1Y1);\ndryLeftMidStage1Y2Prev = fixdenorm(dryLeftMidLpStage1Y2);\ndryLeftMidStage1Sum = (leftDryLpB0High * dryLeftHighStage2Out) + (leftDryLpB1High * dryLeftMidStage1X1Prev) + (leftDryLpB2High * dryLeftMidStage1X2Prev);\ndryLeftMidStage1Out = (dryLeftMidStage1Sum - (leftDryLpA1High * dryLeftMidStage1Y1Prev)) - (leftDryLpA2High * dryLeftMidStage1Y2Prev);\ndryLeftMidLpStage1X2 = dryLeftMidStage1X1Prev;\ndryLeftMidLpStage1X1 = dryLeftHighStage2Out;\ndryLeftMidLpStage1Y2 = dryLeftMidStage1Y1Prev;\ndryLeftMidLpStage1Y1 = dryLeftMidStage1Out;\n\ndryLeftMidStage2X1Prev = fixdenorm(dryLeftMidLpStage2X1);\ndryLeftMidStage2X2Prev = fixdenorm(dryLeftMidLpStage2X2);\ndryLeftMidStage2Y1Prev = fixdenorm(dryLeftMidLpStage2Y1);\ndryLeftMidStage2Y2Prev = fixdenorm(dryLeftMidLpStage2Y2);\ndryLeftMidStage2Sum = (leftDryLpB0High * dryLeftMidStage1Out) + (leftDryLpB1High * dryLeftMidStage2X1Prev) + (leftDryLpB2High * dryLeftMidStage2X2Prev);\ndryLeftMidStage2Out = (dryLeftMidStage2Sum - (leftDryLpA1High * dryLeftMidStage2Y1Prev)) - (leftDryLpA2High * dryLeftMidStage2Y2Prev);\ndryLeftMidLpStage2X2 = dryLeftMidStage2X1Prev;\ndryLeftMidLpStage2X1 = dryLeftMidStage1Out;\ndryLeftMidLpStage2Y2 = dryLeftMidStage2Y1Prev;\ndryLeftMidLpStage2Y1 = dryLeftMidStage2Out;\n\ndryLeftMidBand = dryLeftMidStage2Out;\n\n// Banda alta (HP @ crossover alto)\ndryLeftHighBandStage1X1Prev = fixdenorm(dryLeftHighHpStage1X1);\ndryLeftHighBandStage1X2Prev = fixdenorm(dryLeftHighHpStage1X2);\ndryLeftHighBandStage1Y1Prev = fixdenorm(dryLeftHighHpStage1Y1);\ndryLeftHighBandStage1Y2Prev = fixdenorm(dryLeftHighHpStage1Y2);\ndryLeftHighBandStage1Sum = (leftDryHpB0High * dryLeftHighStage2Out) + (leftDryHpB1High * dryLeftHighBandStage1X1Prev) + (leftDryHpB2High * dryLeftHighBandStage1X2Prev);\ndryLeftHighBandStage1Out = (dryLeftHighBandStage1Sum - (leftDryHpA1High * dryLeftHighBandStage1Y1Prev)) - (leftDryHpA2High * dryLeftHighBandStage1Y2Prev);\ndryLeftHighHpStage1X2 = dryLeftHighBandStage1X1Prev;\ndryLeftHighHpStage1X1 = dryLeftHighStage2Out;\ndryLeftHighHpStage1Y2 = dryLeftHighBandStage1Y1Prev;\ndryLeftHighHpStage1Y1 = dryLeftHighBandStage1Out;\n\ndryLeftHighBandStage2X1Prev = fixdenorm(dryLeftHighHpStage2X1);\ndryLeftHighBandStage2X2Prev = fixdenorm(dryLeftHighHpStage2X2);\ndryLeftHighBandStage2Y1Prev = fixdenorm(dryLeftHighHpStage2Y1);\ndryLeftHighBandStage2Y2Prev = fixdenorm(dryLeftHighHpStage2Y2);\ndryLeftHighBandStage2Sum = (leftDryHpB0High * dryLeftHighBandStage1Out) + (leftDryHpB1High * dryLeftHighBandStage2X1Prev) + (leftDryHpB2High * dryLeftHighBandStage2X2Prev);\ndryLeftHighBandStage2Out = (dryLeftHighBandStage2Sum - (leftDryHpA1High * dryLeftHighBandStage2Y1Prev)) - (leftDryHpA2High * dryLeftHighBandStage2Y2Prev);\ndryLeftHighHpStage2X2 = dryLeftHighBandStage2X1Prev;\ndryLeftHighHpStage2X1 = dryLeftHighBandStage1Out;\ndryLeftHighHpStage2Y2 = dryLeftHighBandStage2Y1Prev;\ndryLeftHighHpStage2Y1 = dryLeftHighBandStage2Out;\n\ndryLeftHighBand = dryLeftHighBandStage2Out;\ndryLeftSumBands = (dryLeftLowBand + dryLeftMidBand) + dryLeftHighBand;\n\n// Alias para las divisiones en 3 bandas (L) → entradas a LOW/MID/HIGH\nlowLIn  = dryLeftLowBand;\nmidLIn  = dryLeftMidBand;\nhighLIn = dryLeftHighBand;\n\n// Alias opcional con la suma L\nsum3BandL = dryLeftSumBands;\n\n// La ruta dry fuerza la misma reconstrucción de 3 bandas que la rama wet\nwetBandSumL = sum3BandL;\n\n// =============================================================================\n// COMPENSACION DE FASE EN LA RUTA DRY\n//   • Reaplica divisiones LR4 en la señal dry para igualar latencia/fase wet\n//   • All-pass (apLow*/dryLow*) aseguran suma coherente en la mezcla final\n// =============================================================================\n// Nombres y estructura de la rama derecha más legibles\nrightLowTargetHz   = clamp(setparamLowCrossover, 20, 1000);\nrightHighTargetHz  = clamp(setparamHighCrossover, 1000, 20000);\ndryRightInput      = wetInR;\ndryRightSampleRate = samplerate;\n\nrightLowHz     = max(10, min(rightLowTargetHz, 0.45 * dryRightSampleRate));\nrightHighPreHz = max(10, min(rightHighTargetHz, 0.45 * dryRightSampleRate));\nrightHighHz    = max(rightHighPreHz, rightLowHz + 1);\n\nrightW0Low    = (TWOPI * rightLowHz) / dryRightSampleRate;\nrightCosLow   = cos(rightW0Low);\nrightSinLow   = sin(rightW0Low);\nrightAlphaLow = rightSinLow / sqrtTwoConstant;\nrightA0Low    = 1 + rightAlphaLow;\nrightA1Low    = -2 * rightCosLow;\nrightA2Low    = 1 - rightAlphaLow;\nrightLpB0Low  = ((1 - rightCosLow) * 0.5) / rightA0Low;\nrightLpB1Low  = (1 - rightCosLow) / rightA0Low;\nrightLpB2Low  = rightLpB0Low;\nrightLpA1Low  = rightA1Low / rightA0Low;\nrightLpA2Low  = rightA2Low / rightA0Low;\nrightHpB0Low  = ((1 + rightCosLow) * 0.5) / rightA0Low;\nrightHpB1Low  = (-(1 + rightCosLow)) / rightA0Low;\nrightHpB2Low  = rightHpB0Low;\nrightHpA1Low  = rightLpA1Low;\nrightHpA2Low  = rightLpA2Low;\n\nrightW0High    = (TWOPI * rightHighHz) / dryRightSampleRate;\nrightCosHigh   = cos(rightW0High);\nrightSinHigh   = sin(rightW0High);\nrightAlphaHigh = rightSinHigh / sqrtTwoConstant;\nrightA0High    = 1 + rightAlphaHigh;\nrightA1High    = -2 * rightCosHigh;\nrightA2High    = 1 - rightAlphaHigh;\nrightLpB0High  = ((1 - rightCosHigh) * 0.5) / rightA0High;\nrightLpB1High  = (1 - rightCosHigh) / rightA0High;\nrightLpB2High  = rightLpB0High;\nrightLpA1High  = rightA1High / rightA0High;\nrightLpA2High  = rightA2High / rightA0High;\nrightHpB0High  = ((1 + rightCosHigh) * 0.5) / rightA0High;\nrightHpB1High  = (-(1 + rightCosHigh)) / rightA0High;\nrightHpB2High  = rightHpB0High;\nrightHpA1High  = rightLpA1High;\nrightHpA2High  = rightLpA2High;\n\n// Cascada rama baja (LP → LP)\nrightLowStage1X1Prev = fixdenorm(dryRightLowLpStage1X1);\nrightLowStage1X2Prev = fixdenorm(dryRightLowLpStage1X2);\nrightLowStage1Y1Prev = fixdenorm(dryRightLowLpStage1Y1);\nrightLowStage1Y2Prev = fixdenorm(dryRightLowLpStage1Y2);\nrightLowStage1Sum = (rightLpB0Low * dryRightInput) + (rightLpB1Low * rightLowStage1X1Prev) + (rightLpB2Low * rightLowStage1X2Prev);\nrightLowStage1Out = (rightLowStage1Sum - (rightLpA1Low * rightLowStage1Y1Prev)) - (rightLpA2Low * rightLowStage1Y2Prev);\ndryRightLowLpStage1X2 = rightLowStage1X1Prev;\ndryRightLowLpStage1X1 = dryRightInput;\ndryRightLowLpStage1Y2 = rightLowStage1Y1Prev;\ndryRightLowLpStage1Y1 = rightLowStage1Out;\n\nrightLowStage2X1Prev = fixdenorm(dryRightLowLpStage2X1);\nrightLowStage2X2Prev = fixdenorm(dryRightLowLpStage2X2);\nrightLowStage2Y1Prev = fixdenorm(dryRightLowLpStage2Y1);\nrightLowStage2Y2Prev = fixdenorm(dryRightLowLpStage2Y2);\nrightLowStage2Sum = (rightLpB0Low * rightLowStage1Out) + (rightLpB1Low * rightLowStage2X1Prev) + (rightLpB2Low * rightLowStage2X2Prev);\nrightLowStage2Out = (rightLowStage2Sum - (rightLpA1Low * rightLowStage2Y1Prev)) - (rightLpA2Low * rightLowStage2Y2Prev);\ndryRightLowLpStage2X2 = rightLowStage2X1Prev;\ndryRightLowLpStage2X1 = rightLowStage1Out;\ndryRightLowLpStage2Y2 = rightLowStage2Y1Prev;\ndryRightLowLpStage2Y1 = rightLowStage2Out;\n\n// Cascada rama alta (HP → HP)\nrightHighStage1X1Prev = fixdenorm(dryRightLowHpStage1X1);\nrightHighStage1X2Prev = fixdenorm(dryRightLowHpStage1X2);\nrightHighStage1Y1Prev = fixdenorm(dryRightLowHpStage1Y1);\nrightHighStage1Y2Prev = fixdenorm(dryRightLowHpStage1Y2);\nrightHighStage1Sum = (rightHpB0Low * dryRightInput) + (rightHpB1Low * rightHighStage1X1Prev) + (rightHpB2Low * rightHighStage1X2Prev);\nrightHighStage1Out = (rightHighStage1Sum - (rightHpA1Low * rightHighStage1Y1Prev)) - (rightHpA2Low * rightHighStage1Y2Prev);\ndryRightLowHpStage1X2 = rightHighStage1X1Prev;\ndryRightLowHpStage1X1 = dryRightInput;\ndryRightLowHpStage1Y2 = rightHighStage1Y1Prev;\ndryRightLowHpStage1Y1 = rightHighStage1Out;\n\nrightHighStage2X1Prev = fixdenorm(dryRightLowHpStage2X1);\nrightHighStage2X2Prev = fixdenorm(dryRightLowHpStage2X2);\nrightHighStage2Y1Prev = fixdenorm(dryRightLowHpStage2Y1);\nrightHighStage2Y2Prev = fixdenorm(dryRightLowHpStage2Y2);\nrightHighStage2Sum = (rightHpB0Low * rightHighStage1Out) + (rightHpB1Low * rightHighStage2X1Prev) + (rightHpB2Low * rightHighStage2X2Prev);\nrightHighStage2Out = (rightHighStage2Sum - (rightHpA1Low * rightHighStage2Y1Prev)) - (rightHpA2Low * rightHighStage2Y2Prev);\ndryRightLowHpStage2X2 = rightHighStage2X1Prev;\ndryRightLowHpStage2X1 = rightHighStage1Out;\ndryRightLowHpStage2Y2 = rightHighStage2Y1Prev;\ndryRightLowHpStage2Y1 = rightHighStage2Out;\n\n// Compensación all-pass (banda baja)\nrightApLowLpStage1X1Prev = fixdenorm(apRightLowLpStage1X1);\nrightApLowLpStage1X2Prev = fixdenorm(apRightLowLpStage1X2);\nrightApLowLpStage1Y1Prev = fixdenorm(apRightLowLpStage1Y1);\nrightApLowLpStage1Y2Prev = fixdenorm(apRightLowLpStage1Y2);\nrightApLowLpStage1Sum = (rightLpB0High * rightLowStage2Out) + (rightLpB1High * rightApLowLpStage1X1Prev) + (rightLpB2High * rightApLowLpStage1X2Prev);\nrightApLowLpStage1Out = (rightApLowLpStage1Sum - (rightLpA1High * rightApLowLpStage1Y1Prev)) - (rightLpA2High * rightApLowLpStage1Y2Prev);\napRightLowLpStage1X2 = rightApLowLpStage1X1Prev;\napRightLowLpStage1X1 = rightLowStage2Out;\napRightLowLpStage1Y2 = rightApLowLpStage1Y1Prev;\napRightLowLpStage1Y1 = rightApLowLpStage1Out;\n\nrightApLowLpStage2X1Prev = fixdenorm(apRightLowLpStage2X1);\nrightApLowLpStage2X2Prev = fixdenorm(apRightLowLpStage2X2);\nrightApLowLpStage2Y1Prev = fixdenorm(apRightLowLpStage2Y1);\nrightApLowLpStage2Y2Prev = fixdenorm(apRightLowLpStage2Y2);\nrightApLowLpStage2Sum = (rightLpB0High * rightApLowLpStage1Out) + (rightLpB1High * rightApLowLpStage2X1Prev) + (rightLpB2High * rightApLowLpStage2X2Prev);\nrightApLowLpStage2Out = (rightApLowLpStage2Sum - (rightLpA1High * rightApLowLpStage2Y1Prev)) - (rightLpA2High * rightApLowLpStage2Y2Prev);\napRightLowLpStage2X2 = rightApLowLpStage2X1Prev;\napRightLowLpStage2X1 = rightApLowLpStage1Out;\napRightLowLpStage2Y2 = rightApLowLpStage2Y1Prev;\napRightLowLpStage2Y1 = rightApLowLpStage2Out;\n\nrightApLowHpStage1X1Prev = fixdenorm(apRightLowHpStage1X1);\nrightApLowHpStage1X2Prev = fixdenorm(apRightLowHpStage1X2);\nrightApLowHpStage1Y1Prev = fixdenorm(apRightLowHpStage1Y1);\nrightApLowHpStage1Y2Prev = fixdenorm(apRightLowHpStage1Y2);\nrightApLowHpStage1Sum = (rightHpB0High * rightLowStage2Out) + (rightHpB1High * rightApLowHpStage1X1Prev) + (rightHpB2High * rightApLowHpStage1X2Prev);\nrightApLowHpStage1Out = (rightApLowHpStage1Sum - (rightHpA1High * rightApLowHpStage1Y1Prev)) - (rightHpA2High * rightApLowHpStage1Y2Prev);\napRightLowHpStage1X2 = rightApLowHpStage1X1Prev;\napRightLowHpStage1X1 = rightLowStage2Out;\napRightLowHpStage1Y2 = rightApLowHpStage1Y1Prev;\napRightLowHpStage1Y1 = rightApLowHpStage1Out;\n\nrightApLowHpStage2X1Prev = fixdenorm(apRightLowHpStage2X1);\nrightApLowHpStage2X2Prev = fixdenorm(apRightLowHpStage2X2);\nrightApLowHpStage2Y1Prev = fixdenorm(apRightLowHpStage2Y1);\nrightApLowHpStage2Y2Prev = fixdenorm(apRightLowHpStage2Y2);\nrightApLowHpStage2Sum = (rightHpB0High * rightApLowHpStage1Out) + (rightHpB1High * rightApLowHpStage2X1Prev) + (rightHpB2High * rightApLowHpStage2X2Prev);\nrightApLowHpStage2Out = (rightApLowHpStage2Sum - (rightHpA1High * rightApLowHpStage2Y1Prev)) - (rightHpA2High * rightApLowHpStage2Y2Prev);\napRightLowHpStage2X2 = rightApLowHpStage2X1Prev;\napRightLowHpStage2X1 = rightApLowHpStage1Out;\napRightLowHpStage2Y2 = rightApLowHpStage2Y1Prev;\napRightLowHpStage2Y1 = rightApLowHpStage2Out;\n\ndryRightLowBand = rightApLowLpStage2Out + rightApLowHpStage2Out;\n\n// Banda media (LP @ crossover alto)\nrightMidStage1X1Prev = fixdenorm(dryRightMidLpStage1X1);\nrightMidStage1X2Prev = fixdenorm(dryRightMidLpStage1X2);\nrightMidStage1Y1Prev = fixdenorm(dryRightMidLpStage1Y1);\nrightMidStage1Y2Prev = fixdenorm(dryRightMidLpStage1Y2);\nrightMidStage1Sum = (rightLpB0High * rightHighStage2Out) + (rightLpB1High * rightMidStage1X1Prev) + (rightLpB2High * rightMidStage1X2Prev);\nrightMidStage1Out = (rightMidStage1Sum - (rightLpA1High * rightMidStage1Y1Prev)) - (rightLpA2High * rightMidStage1Y2Prev);\ndryRightMidLpStage1X2 = rightMidStage1X1Prev;\ndryRightMidLpStage1X1 = rightHighStage2Out;\ndryRightMidLpStage1Y2 = rightMidStage1Y1Prev;\ndryRightMidLpStage1Y1 = rightMidStage1Out;\nrightMidStage2X1Prev = fixdenorm(dryRightMidLpStage2X1);\nrightMidStage2X2Prev = fixdenorm(dryRightMidLpStage2X2);\nrightMidStage2Y1Prev = fixdenorm(dryRightMidLpStage2Y1);\nrightMidStage2Y2Prev = fixdenorm(dryRightMidLpStage2Y2);\nrightMidStage2Sum = (rightLpB0High * rightMidStage1Out) + (rightLpB1High * rightMidStage2X1Prev) + (rightLpB2High * rightMidStage2X2Prev);\nrightMidStage2Out = (rightMidStage2Sum - (rightLpA1High * rightMidStage2Y1Prev)) - (rightLpA2High * rightMidStage2Y2Prev);\ndryRightMidLpStage2X2 = rightMidStage2X1Prev;\ndryRightMidLpStage2X1 = rightMidStage1Out;\ndryRightMidLpStage2Y2 = rightMidStage2Y1Prev;\ndryRightMidLpStage2Y1 = rightMidStage2Out;\ndryRightMidBand = rightMidStage2Out;\n\n// Banda alta (HP @ crossover alto)\nrightHighBandStage1X1Prev = fixdenorm(dryRightHighHpStage1X1);\nrightHighBandStage1X2Prev = fixdenorm(dryRightHighHpStage1X2);\nrightHighBandStage1Y1Prev = fixdenorm(dryRightHighHpStage1Y1);\nrightHighBandStage1Y2Prev = fixdenorm(dryRightHighHpStage1Y2);\nrightHighBandStage1Sum = (rightHpB0High * rightHighStage2Out) + (rightHpB1High * rightHighBandStage1X1Prev) + (rightHpB2High * rightHighBandStage1X2Prev);\nrightHighBandStage1Out = (rightHighBandStage1Sum - (rightHpA1High * rightHighBandStage1Y1Prev)) - (rightHpA2High * rightHighBandStage1Y2Prev);\ndryRightHighHpStage1X2 = rightHighBandStage1X1Prev;\ndryRightHighHpStage1X1 = rightHighStage2Out;\ndryRightHighHpStage1Y2 = rightHighBandStage1Y1Prev;\ndryRightHighHpStage1Y1 = rightHighBandStage1Out;\n\nrightHighBandStage2X1Prev = fixdenorm(dryRightHighHpStage2X1);\nrightHighBandStage2X2Prev = fixdenorm(dryRightHighHpStage2X2);\nrightHighBandStage2Y1Prev = fixdenorm(dryRightHighHpStage2Y1);\nrightHighBandStage2Y2Prev = fixdenorm(dryRightHighHpStage2Y2);\nrightHighBandStage2Sum = (rightHpB0High * rightHighBandStage1Out) + (rightHpB1High * rightHighBandStage2X1Prev) + (rightHpB2High * rightHighBandStage2X2Prev);\nrightHighBandStage2Out = (rightHighBandStage2Sum - (rightHpA1High * rightHighBandStage2Y1Prev)) - (rightHpA2High * rightHighBandStage2Y2Prev);\ndryRightHighHpStage2X2 = rightHighBandStage2X1Prev;\ndryRightHighHpStage2X1 = rightHighBandStage1Out;\ndryRightHighHpStage2Y2 = rightHighBandStage2Y1Prev;\ndryRightHighHpStage2Y1 = rightHighBandStage2Out;\ndryRightHighBand = rightHighBandStage2Out;\ndryRightSumBands = (dryRightLowBand + dryRightMidBand) + dryRightHighBand;\n\n// Alias para las divisiones en 3 bandas (R) → entradas a LOW/MID/HIGH\nlowRIn  = dryRightLowBand;\nmidRIn  = dryRightMidBand;\nhighRIn = dryRightHighBand;\n\n// Alias opcional con la suma R\nsum3BandR = dryRightSumBands;\n\n// Alinea la reconstrucción dry con la rama de 3 bandas para evitar desbalances de nivel\nwetBandSumR = sum3BandR;\n\n// Alias y suavizado del control de la banda LOW\nlowBalanceParam = clamp(lowBalance, 0, 1);\nlowWidthParam   = clamp(lowBandGainSmoothed, 0, 200);\nlowBypassParam  = clamp(setparamInputModeReset, 0, 1);\nlowInputParam   = clamp(inputModeSmoothed, 0, 1);\nlowUnityGain    = int(1);\n\nlowBypassSlew = slewDefault;\nlowBypassSmoothed    = mix(lowBypassParam, lowBypassHistory, lowBypassSlew);\nlowBypassHistoryNext = fixdenorm(lowBypassSmoothed);\nlowBypassMask = 1 - lowBypassSmoothed;\n\nlowInvertPolarity = int(1); // mantiene el comportamiento original (sin control de inversión)\n\nlowBalanceSlew        = slewDefault;\nlowBalanceSmoothed    = mix(lowBalanceParam, lowBalanceHistory, lowBalanceSlew);\nlowBalanceHistoryNext = fixdenorm(lowBalanceSmoothed);\n//  Ley de balance estéreo (unidad en el centro)\nlowBal       = lowBalanceSmoothed;\nlowBalT      = (lowBal - 0.5) * 2.0;\nlowBalPos    = max(lowBalT, 0);\nlowBalNeg    = min(lowBalT, 0);\nlowBalGL     = clamp(1 - lowBalPos, 0, 1);\nlowBalGR     = clamp(1 + lowBalNeg, 0, 1);\n\nlowWidthSlew        = slewDefault;\nlowWidthSmoothed    = mix(lowWidthParam, lowWidthHistory, lowWidthSlew);\nlowWidthHistoryNext = fixdenorm(lowWidthSmoothed);\nlowWidthControl     = lowWidthSmoothed;\n\nlowInputZero            = int(0);\nlowInputSlew            = slewDefault;\nlowInputModeSmoothed    = mix(lowInputParam, lowInputModeHistory, lowInputSlew);\nlowInputModeHistoryNext = fixdenorm(lowInputModeSmoothed);\nlowLeftBlend            = mix(lowLIn, lowInputZero, lowInputModeSmoothed);   // transición suave de la señal dry LOW-L cuando cambia el modo de entrada\nlowRightBlend           = mix(lowRIn, lowInputZero, lowInputModeSmoothed);\n\nlowLeftProcessed  = mix(lowInputZero, lowLIn, lowInputModeSmoothed);\nlowRightProcessed = mix(lowInputZero, lowRIn, lowInputModeSmoothed);\n\nlowInputSum  = lowLeftProcessed + lowRightProcessed;\nmLowRaw      = ((lowInputSum + lowLeftBlend)) * lowUnityGain;\nlowInputDiff = lowLeftProcessed - lowRightProcessed;\nsLowRaw      = ((lowRightBlend + lowInputDiff)) * lowUnityGain;\n\n// =============================================================================\n// PROCESADO DE BANDA — LOW\n// =============================================================================\n// -----------------------------------------------------------------------------\n// [JCBImager][LOW] Control de anchura con normalizacion dependiente del contenido\n//   1) Mapeo de potencia constante (M/S)\n//   2) Normalizacion RMS por banda (≈50 ms)\n// -----------------------------------------------------------------------------\n// Usa las constantes compartidas piConstant/epsilonConstant declaradas arriba\n//  Ventana RMS de 80 ms para una normalización más estable\nlowRmsAlpha = 1 - exp(-1 / ((80 * 0.001) * samplerate));\n\n// M/S antes de aplicar la matriz MS→LR (el factor 0.7071 llega después)\n\n// Ganancias de potencia constante a partir de la anchura (w ∈ [0..2])\n// Limita la anchura al 50–150% para evitar aperturas extremas\nlowWidthNormalized = clamp(lowWidthControl, 0.0, 2.0);\nlowWidthHalf       = lowWidthNormalized * 0.5;\n\n//  Un toque adicional de anchura\nlowTheta = lowWidthHalf * (piConstant / 2.55);\n\n//  Usa coseno/seno directamente; la reconstrucción emplea 0.5 (no 0.7071)\nlowMonoGain = cos(lowTheta);\nlowSideGain = sin(lowTheta);\n\n// Reconstruye L/R limitado en banda desde M/S (antes de las ganancias)\n//  Reconstrucción MS→LR previa con factor 0.5 porque M=L+R y S=L−R\nlLowPre = (mLowRaw + sLowRaw) * 0.5;\nrLowPre = (mLowRaw - sLowRaw) * 0.5;\n\n// Actualiza energías en el dominio L/R y el término cruzado <L*R>\nlowLeftEnergyM2       = fixdenorm(lowLeftEnergyM2 + lowRmsAlpha * ((lLowPre * lLowPre) - lowLeftEnergyM2));\nlowRightEnergyM2      = fixdenorm(lowRightEnergyM2 + lowRmsAlpha * ((rLowPre * rLowPre) - lowRightEnergyM2));\nlowCrossCorrelationM2 = fixdenorm(lowCrossCorrelationM2 + lowRmsAlpha * ((lLowPre * rLowPre) - lowCrossCorrelationM2)); // ahora almacena <L*R>\n\n// (kept for compatibility, not used in normalization anymore)\nlowEnergyM2     = fixdenorm(lowEnergyM2 + lowRmsAlpha * ((mLowRaw * mLowRaw) - lowEnergyM2));\nlowSideEnergyM2 = fixdenorm(lowSideEnergyM2 + lowRmsAlpha * ((sLowRaw * sLowRaw) - lowSideEnergyM2));\n\n// Coeficientes tras las ganancias MS al volver a L/R\nlowMatrixA = 0.5 * (lowMonoGain + lowSideGain);\nlowMatrixB = 0.5 * (lowMonoGain - lowSideGain);\n\n// Potencia de entrada y salida prevista, incluyendo correlación\nlowInputPower        = lowLeftEnergyM2 + lowRightEnergyM2 + epsilonConstant;\nlowOutputPower       = (lowMatrixA*lowMatrixA + lowMatrixB*lowMatrixB) * (lowLeftEnergyM2 + lowRightEnergyM2) + (4.0 * lowMatrixA * lowMatrixB) * lowCrossCorrelationM2 + epsilonConstant;\nlowNormalizationGain = sqrt(lowInputPower / lowOutputPower);\n\n// Impulso ligero de nivel cuando la anchura > 1.0 (dependiente del contenido)\nlowCorrelationNumerator   = lowCrossCorrelationM2;\nlowCorrelationDenominator = sqrt(max(lowLeftEnergyM2 * lowRightEnergyM2, epsilonConstant));\nlowCorrelation            = clamp(lowCorrelationNumerator / (lowCorrelationDenominator + epsilonConstant), -1, 1);\n\n// Permite el rango completo 0–2 sin atenuar en exceso la banda\nbaseGainLow            = dbtoa(4.5);\nmaxBoostLow            = dbtoa(10.5);\nlowMonoGainSafe        = max(lowMonoGain, 0.05);\nmonoNeedLow            = clamp(1 / lowMonoGainSafe, baseGainLow, maxBoostLow);\nlowCorrelationPositive = max(lowCorrelation, 0);\nboostAllowanceLow      = baseGainLow + (monoNeedLow - baseGainLow) * lowCorrelationPositive;\nlowNormalizationGain   = clamp(lowNormalizationGain, dbtoa(-4.5), boostAllowanceLow);\n\n// Sólo empujar cuando abrimos (> 1.0). lowWidthHalf ∈ [0.25..0.75]\nlowLiftBase = max(0, lowWidthHalf - 0.5);   // 0..0.25\n\n// Constante de “empuje” (ajustable 5..7 dB). 6 dB → máx ≈ +1.5 dB\nlowLiftSlopeDb = 6.0;\nlowLiftDb      = lowLiftSlopeDb * lowLiftBase * (1 - lowCorrelation);\n\n// Aplicar después de la normalización base\nlowNormalizationGain = lowNormalizationGain * dbtoa(lowLiftDb);\n// Alias solo para facilitar la lectura\nlowNormGain   = lowNormalizationGain;\nlowCorr       = lowCorrelation;\nlowWidthCtrl  = lowWidthNormalized;\n// Genera leve bump de 0.4 en la banda grave, si molesta quitar de momento lo mantengo\n\n// Aplica la matriz MS→LR con las ganancias y la normalización\n//  Matriz MS→LR cuando M=L+R y S=L−R\nlowMonoHalf      = mLowRaw * 0.5;\nlowSideHalf      = sLowRaw * 0.5;\nlowMonoScaled    = lowMonoHalf * (lowMonoGain * lowNormGain);\nlowSideScaled    = lowSideHalf * (lowSideGain * lowNormGain);\nlowSidePolarity  = lowSideScaled * lowInvertPolarity;\nlowRightPreWidth = lowMonoScaled - lowSidePolarity;\nwetLowR          = lowRightPreWidth;\nlowLeftPreWidth  = lowMonoScaled + lowSidePolarity;\nwetLowL          = lowLeftPreWidth;\nlowLeftBalanced  = wetLowL * lowBalGL;\nlowLeftWithGain  = lowLeftBalanced * lowUnityGain;\nlowLeftMixed     = mix(lowLIn, lowLeftWithGain, lowBypassMask);\n\n// [LOW] compuerta mute suavizada\nmuteLowSlew     = slewDefault;\nmuteLowSmoothed = mix(muteLow, muteLowHistory, muteLowSlew);\nmuteLowHistory  = fixdenorm(muteLowSmoothed);\nlowMuteGateRaw  = 1 - clamp(muteLowSmoothed, 0, 1);\nmuteLowGate     = lowMuteGateRaw;\n\n// aplicar a LOW L/R\nlowLeftMixed     = lowLeftMixed * muteLowGate;\nlowRightBalanced = wetLowR * lowBalGR;  // ganancia derecha\nlowRightWithGain = lowRightBalanced * lowUnityGain;\nlowRightMixed    = mix(lowRIn, lowRightWithGain, lowBypassMask);\n\n// [LOW] aplicar a LOW R\nlowRightMixed       = lowRightMixed * muteLowGate;\nwetLowRightPostSolo = mix(lowRightMixed, soloZero, soloMaskLow);\nwetLowLeftPostSolo  = mix(lowLeftMixed, soloZero, soloMaskLow);\n\n// Salidas wet de banda (tras solo/mute) — LOW\nwetLowRPost = wetLowRightPostSolo;\nwetLowLPost = wetLowLeftPostSolo;\n\n// Alias y suavizado del control de la banda MID\nmidBandGainDbParam   = clamp(0, -96, 12);\nmidSideGainDbParam   = clamp(0, -96, 12);\nmidMakeupDbParam     = clamp(0, -24, 6);\nmidInvertParam       = clamp(0, 0, 1);\nmidBalanceParam      = clamp(midBalanceSmoothed, 0, 1);\nmidWidthParam        = clamp(midBandGainSmoothed, 0, 200);\nmidBypassParam       = clamp(setparamLowGainReset, 0, 1);\nmidInputParam        = clamp(inputModeSmoothed, 0, 1);\n\nmidBypassSlew        = slewDefault;\nmidBypassSmoothed    = mix(midBypassParam, midBypassHistory, midBypassSlew);\nmidBypassHistoryNext = fixdenorm(midBypassSmoothed);\nmidBypassMask        = 1 - midBypassSmoothed;\n\nmidMakeupSlew        = slewDefault;\nmidMakeupDbSmoothed  = mix(midMakeupDbParam, midMakeupHistory, midMakeupSlew);\nmidMakeupHistoryNext = fixdenorm(midMakeupDbSmoothed);\nmidMakeupLinear      = dbtoa(midMakeupDbSmoothed);\n\nmidBalanceSlew                = slewDefault;\nmidBalanceSmoothed            = mix(midBalanceParam, midBalanceInternalHistory, midBalanceSlew);\nmidBalanceInternalHistoryNext = fixdenorm(midBalanceSmoothed);\n\n//  Ley de balance estéreo (unidad en el centro) para MID\nmidBal    = midBalanceSmoothed;\nmidBalT   = (midBal - 0.5) * 2.0;\nmidBalPos = max(midBalT, 0);\nmidBalNeg = min(midBalT, 0);\nmidBalGL  = clamp(1 - midBalPos, 0, 1);\nmidBalGR  = clamp(1 + midBalNeg, 0, 1);\n\nmidWidthSlew            = slewDefault;\nmidWidthSmoothed        = mix(midWidthParam, midWidthHistory, midWidthSlew);\nmidWidthHistoryNext     = fixdenorm(midWidthSmoothed);\nmidWidthParameter       = midWidthSmoothed;\nmidInputZero            = int(0);\nmidInputSlew            = slewDefault;\nmidInputModeSmoothed    = mix(midInputParam, midInputModeHistory, midInputSlew);\nmidInputModeHistoryNext = fixdenorm(midInputModeSmoothed);\nmidLeftBypassBlend      = mix(midLIn, midInputZero, midInputModeSmoothed);\nmidRightBypassBlend     = mix(midRIn, midInputZero, midInputModeSmoothed);\n\nmidLeftProcessed  = mix(midInputZero, midLIn, midInputModeSmoothed);\nmidRightProcessed = mix(midInputZero, midRIn, midInputModeSmoothed);\n\nmidInputSum  = midLeftProcessed + midRightProcessed;\nmidInputDiff = midLeftProcessed - midRightProcessed;\n\nmidBandGainLinearTarget        = dbtoa(midBandGainDbParam);\nmidBandGainSlew                = slewDefault;\nmidBandGainSmoothed            = mix(midBandGainLinearTarget, midBandGainHistoryInternal, midBandGainSlew);\nmidBandGainHistoryInternalNext = fixdenorm(midBandGainSmoothed);\nmidBandGainLinear              = midBandGainSmoothed;\nmMidRaw                        = (midInputSum + midLeftBypassBlend) * midBandGainLinear;\n\nmidSideGainLinearTarget = dbtoa(midSideGainDbParam);\nmidSideGainSlew         = slewDefault;\nmidSideGainSmoothed     = mix(midSideGainLinearTarget, midSideGainHistory, midSideGainSlew);\nmidSideGainHistoryNext  = fixdenorm(midSideGainSmoothed);\nmidSideGainLinear       = midSideGainSmoothed;\nsMidRaw                 = (midRightBypassBlend + midInputDiff) * midSideGainLinear;\ninvertPositive          = int(1);\ninvertNegative          = int(-1);\nmidInvertSwitch         = midInvertParam ? invertPositive : invertNegative;\nmidInvertTarget         = midInvertSwitch * -1;\nmidInvertSmoothed       = mix(midInvertTarget, midInvertHistory, 0);\nmidInvertHistoryNext    = fixdenorm(midInvertSmoothed);\nmidInvertPolarity       = midInvertSmoothed;\n// =============================================================================\n// PROCESADO DE BANDA — MID\n// =============================================================================\n// -----------------------------------------------------------------------------\n// [JCBImager][MID] Control de anchura con normalizacion dependiente del contenido\n// -----------------------------------------------------------------------------\n// Las constantes piConstant/epsilonConstant también aplican aquí\n//  Ventana RMS de 80 ms\nmidRmsAlpha = 1 - exp(-1 / ((80 * 0.001) * samplerate));\n\n// Limita la anchura al 50–150%\nmidWidthNormalized = clamp(midWidthParameter, 0.0, 2.0);\nmidWidthHalf       = midWidthNormalized * 0.5;\n\n//  Un toque adicional de anchura\nmidTheta = midWidthHalf * (piConstant / 2.55);\n\n//  Usa cos/sin de forma directa; la matriz LR emplea 0.5\nmidMonoGain = cos(midTheta);\nmidSideGain = sin(midTheta);\n\n// Reconstruye L/R limitado en banda desde M/S (antes de las ganancias)\n//  Reconstrucción MS→LR previa con factor 0.5 porque M=L+R y S=L−R\nlMidPre = (mMidRaw + sMidRaw) * 0.5;\nrMidPre = (mMidRaw - sMidRaw) * 0.5;\n\nmidLeftEnergyM2       = fixdenorm(midLeftEnergyM2 + midRmsAlpha * ((lMidPre * lMidPre) - midLeftEnergyM2));\nmidRightEnergyM2      = fixdenorm(midRightEnergyM2 + midRmsAlpha * ((rMidPre * rMidPre) - midRightEnergyM2));\nmidCrossCorrelationM2 = fixdenorm(midCrossCorrelationM2 + midRmsAlpha * ((lMidPre * rMidPre) - midCrossCorrelationM2)); // ahora almacena <L*R>\n\n// (se mantiene por compatibilidad, ya no se usa en la normalización)\nmidEnergyM2     = fixdenorm(midEnergyM2 + midRmsAlpha * ((mMidRaw * mMidRaw) - midEnergyM2));\nmidSideEnergyM2 = fixdenorm(midSideEnergyM2 + midRmsAlpha * ((sMidRaw * sMidRaw) - midSideEnergyM2));\n\nmidMatrixA           = 0.5 * (midMonoGain + midSideGain);\nmidMatrixB           = 0.5 * (midMonoGain - midSideGain);\nmidInputPower        = midLeftEnergyM2 + midRightEnergyM2 + epsilonConstant;\nmidOutputPower       = (midMatrixA*midMatrixA + midMatrixB*midMatrixB) * (midLeftEnergyM2 + midRightEnergyM2) + (4.0 * midMatrixA * midMatrixB) * midCrossCorrelationM2 + epsilonConstant;\nmidNormalizationGain = sqrt(midInputPower / midOutputPower);\n\nmidCorrelationNumerator   = midCrossCorrelationM2;\nmidCorrelationDenominator = sqrt(max(midLeftEnergyM2 * midRightEnergyM2, epsilonConstant));\nmidCorrelation            = clamp(midCorrelationNumerator / (midCorrelationDenominator + epsilonConstant), -1, 1); //\n\n// Headroom adaptativo mantiene el nivel con material muy correlacionado en anchuras extremas\nbaseGainMid            = dbtoa(4.5);\nmaxBoostMid            = dbtoa(10.5);\nmidMonoGainSafe        = max(midMonoGain, 0.05);\nmonoNeedMid            = clamp(1 / midMonoGainSafe, baseGainMid, maxBoostMid);\nmidCorrelationPositive = max(midCorrelation, 0);\nboostAllowanceMid      = baseGainMid + (monoNeedMid - baseGainMid) * midCorrelationPositive;\nmidNormalizationGain   = clamp(midNormalizationGain, dbtoa(-4.5), boostAllowanceMid);\nmidLiftBase            = max(0, midWidthHalf - 0.5);\nmidLiftSlopeDb         = 6.0;\nmidLiftDb              = midLiftSlopeDb * midLiftBase * (1 - midCorrelation);\nmidNormalizationGain   = midNormalizationGain * dbtoa(midLiftDb);\n\n// Alias solo para facilitar la lectura\nmidNormGain   = midNormalizationGain;\nmidCorr       = midCorrelation;\nmidWidthCtrl  = midWidthNormalized;\n\nmidMonoHalf          = mMidRaw * 0.5;\nmidSideHalf          = sMidRaw * 0.5;\nmidMonoScaled        = midMonoHalf * (midMonoGain * midNormGain);\nmidSideScaled        = midSideHalf * (midSideGain * midNormGain);\nmidSidePolarity      = midSideScaled * midInvertPolarity;\nmidRightPreWidth     = midMonoScaled - midSidePolarity;\nwetMidR              = midRightPreWidth;\nmidLeftPreWidth      = midMonoScaled + midSidePolarity;\nwetMidL              = midLeftPreWidth;\nmidRightBalanced     = wetMidR * midBalGR;  // ganancia derecha\nmidRightWithBandGain = midRightBalanced * midMakeupLinear;\nmidRightMixed        = mix(midRIn, midRightWithBandGain, midBypassMask);\n\n// [MID]\nmuteMidSlew     = slewDefault;\nmuteMidSmoothed = mix(muteMid, muteMidHistory, muteMidSlew);\nmuteMidHistory  = fixdenorm(muteMidSmoothed);\nmidMuteGateRaw  = 1 - clamp(muteMidSmoothed, 0, 1);\nmuteMidGate     = midMuteGateRaw;\n\n// aplicar a MID R\nmidRightMixed       = midRightMixed * muteMidGate;\nmidLeftBalanced     = wetMidL * midBalGL;  // ganancia izquierda\nmidLeftWithBandGain = midLeftBalanced * midMakeupLinear;\nmidLeftMixed        = mix(midLIn, midLeftWithBandGain, midBypassMask);\n\n// [MID] aplicar a MID L\nmidLeftMixed        = midLeftMixed * muteMidGate;\nwetMidRightPostSolo = mix(midRightMixed, soloMidZero, soloMaskMid);\nwetMidLeftPostSolo  = mix(midLeftMixed, soloMidZero, soloMaskMid);\n\n// Salidas wet de banda (tras solo/mute) — MID\nwetMidRPost = wetMidRightPostSolo;\nwetMidLPost = wetMidLeftPostSolo;\n\n// Alias y suavizado del control de la banda HIGH\nhighSideGainDbParam  = clamp(0, -96, 12);\nhighBandGainDbParam  = clamp(0, -96, 12);\nhighInvertParam      = clamp(0, 0, 1);\nhighMakeupDbParam    = clamp(0, -24, 6);\nhighBalanceParam     = clamp(highBalanceSmoothed, 0, 1);\nhighWidthParam       = clamp(highBandGainSmoothed, 0, 200);\nhighBypassParam      = clamp(setparamMidGainReset, 0, 1);\nhighInputParam       = clamp(inputModeSmoothed, 0, 1);\n\nhighBypassSlew = slewDefault;\nhighBypassSmoothed    = mix(highBypassParam, highBypassHistory, highBypassSlew);\nhighBypassHistoryNext = fixdenorm(highBypassSmoothed);\nhighBypassMask        = 1 - highBypassSmoothed;\n\nhighMakeupSlew        = slewDefault;\nhighMakeupDbSmoothed  = mix(highMakeupDbParam, highMakeupHistory, highMakeupSlew);\nhighMakeupHistoryNext = fixdenorm(highMakeupDbSmoothed);\nhighMakeupLinear      = dbtoa(highMakeupDbSmoothed);\n\nhighBalanceSlew                = slewDefault;\nhighBalanceSmoothed            = mix(highBalanceParam, highBalanceHistoryInternal, highBalanceSlew);\nhighBalanceHistoryInternalNext = fixdenorm(highBalanceSmoothed);\n\n//  Ley de balance estéreo (unidad en el centro) para HIGH\nhighBal  = highBalanceSmoothed;\nhighBalT      = (highBal - 0.5) * 2.0;\nhighBalPos    = max(highBalT, 0);\nhighBalNeg    = min(highBalT, 0);\nhighBalGL     = clamp(1 - highBalPos, 0, 1);\nhighBalGR     = clamp(1 + highBalNeg, 0, 1);\n\nhighWidthSlew        = slewDefault;\nhighWidthSmoothed    = mix(highWidthParam, highWidthHistory, highWidthSlew);\nhighWidthHistoryNext = fixdenorm(highWidthSmoothed);\n\nhighWidthParameter = highWidthSmoothed;\nhighInputZero            = int(0);\nhighInputSlew            = slewDefault;\nhighInputModeSmoothed    = mix(highInputParam, highInputModeHistory, highInputSlew);\nhighInputModeHistoryNext = fixdenorm(highInputModeSmoothed);\nhighLeftBypassBlend      = mix(highLIn, highInputZero, highInputModeSmoothed);\nhighRightBypassBlend     = mix(highRIn, highInputZero, highInputModeSmoothed);\n\nhighLeftProcessed  = mix(highInputZero, highLIn, highInputModeSmoothed);\nhighRightProcessed = mix(highInputZero, highRIn, highInputModeSmoothed);\n\nhighInputSum  = highLeftProcessed + highRightProcessed;\nhighInputDiff = highLeftProcessed - highRightProcessed;\n\nhighBandGainLinearTarget        = dbtoa(highBandGainDbParam);\nhighBandGainSlew                = slewDefault;\nhighBandGainSmoothed            = mix(highBandGainLinearTarget, highBandGainHistoryInternal, highBandGainSlew);\nhighBandGainHistoryInternalNext = fixdenorm(highBandGainSmoothed);\nhighBandGainLinear              = highBandGainSmoothed;\nmHighRaw                        = (highInputSum + highLeftBypassBlend) * highBandGainLinear;\n\nhighSideGainLinearTarget = dbtoa(highSideGainDbParam);\nhighSideGainSlew         = slewDefault;\nhighSideGainSmoothed     = mix(highSideGainLinearTarget, highSideGainHistory, highSideGainSlew);\nhighSideGainHistoryNext  = fixdenorm(highSideGainSmoothed);\nhighSideGainLinear       = highSideGainSmoothed;\nsHighRaw                 = (highRightBypassBlend + highInputDiff) * highSideGainLinear;\ninvertPositiveHigh       = int(1);\ninvertNegativeHigh       = int(-1);\nhighInvertSwitch         = highInvertParam ? invertPositiveHigh : invertNegativeHigh;\nhighInvertTarget         = highInvertSwitch * -1;\nhighInvertSmoothed       = mix(highInvertTarget, highInvertHistory, 0);\nhighInvertHistoryNext    = fixdenorm(highInvertSmoothed);\nhighInvertPolarity       = highInvertSmoothed;\n\n// =============================================================================\n// PROCESADO DE BANDA — HIGH\n// =============================================================================\n// -----------------------------------------------------------------------------\n// [JCBImager][HIGH] Control de anchura con normalizacion dependiente del contenido\n// -----------------------------------------------------------------------------\n//  Ventana RMS de 80 ms\nhighRmsAlpha = 1 - exp(-1 / ((80 * 0.001) * samplerate));\n\n// Limita la anchura al 50–150%\nhighWidthNormalized  = clamp(highWidthParameter, 0.0, 2.0);\nhighWidthHalf        = highWidthNormalized * 0.5;\n\n//  Un toque adicional de anchura\nhighTheta = highWidthHalf * (piConstant / 2.55);\n\nhighMonoGain = cos(highTheta);\nhighSideGain = sin(highTheta);\n\n// Reconstruye L/R limitado en banda desde M/S (antes de las ganancias)\nlHighPre = (mHighRaw + sHighRaw) * 0.5;\nrHighPre = (mHighRaw - sHighRaw) * 0.5;\n\n// Actualiza energías en el dominio L/R y el término cruzado <L*R>\nhighLeftEnergyM2       = fixdenorm(highLeftEnergyM2 + highRmsAlpha * ((lHighPre * lHighPre) - highLeftEnergyM2));\nhighRightEnergyM2      = fixdenorm(highRightEnergyM2 + highRmsAlpha * ((rHighPre * rHighPre) - highRightEnergyM2));\nhighCrossCorrelationM2 = fixdenorm(highCrossCorrelationM2 + highRmsAlpha * ((lHighPre * rHighPre) - highCrossCorrelationM2)); // ahora almacena <L*R>\n\n// (se mantiene por compatibilidad, ya no se usa en la normalización)\nhighEnergyM2     = fixdenorm(highEnergyM2 + highRmsAlpha * ((mHighRaw * mHighRaw) - highEnergyM2));\nhighSideEnergyM2 = fixdenorm(highSideEnergyM2 + highRmsAlpha * ((sHighRaw * sHighRaw) - highSideEnergyM2));\n\nhighMatrixA           = 0.5 * (highMonoGain + highSideGain);\nhighMatrixB           = 0.5 * (highMonoGain - highSideGain);\nhighInputPower        = highLeftEnergyM2 + highRightEnergyM2 + epsilonConstant;\nhighOutputPower       = (highMatrixA*highMatrixA + highMatrixB*highMatrixB) * (highLeftEnergyM2 + highRightEnergyM2) + (4.0 * highMatrixA * highMatrixB) * highCrossCorrelationM2 + epsilonConstant;\nhighNormalizationGain = sqrt(highInputPower / highOutputPower);\n\nhighCorrelationNumerator   = highCrossCorrelationM2;\nhighCorrelationDenominator = sqrt(max(highLeftEnergyM2 * highRightEnergyM2, epsilonConstant));\nhighCorrelation            = clamp(highCorrelationNumerator / (highCorrelationDenominator + epsilonConstant), -1, 1);\n\n// Headroom adaptativo replica el comportamiento LOW/MID con material correlacionado\nbaseGainHigh               = dbtoa(4.5);\nmaxBoostHigh               = dbtoa(10.5);\nhighMonoGainSafe           = max(highMonoGain, 0.05);\nmonoNeedHigh               = clamp(1 / highMonoGainSafe, baseGainHigh, maxBoostHigh);\nhighCorrelationPositive    = max(highCorrelation, 0);\nboostAllowanceHigh         = baseGainHigh + (monoNeedHigh - baseGainHigh) * highCorrelationPositive;\nhighNormalizationGain      = clamp(highNormalizationGain, dbtoa(-4.5), boostAllowanceHigh);\n\nhighLiftBase          = max(0, highWidthHalf - 0.5);\nhighLiftSlopeDb       = 6.0;\nhighLiftDb            = highLiftSlopeDb * highLiftBase * (1 - highCorrelation);\nhighNormalizationGain = highNormalizationGain * dbtoa(highLiftDb);\n\n// Alias solo para facilitar la lectura\nhighNormGain   = highNormalizationGain;\nhighCorr       = highCorrelation;\nhighWidthCtrl  = highWidthNormalized;\n\nhighMonoHalf         = mHighRaw * 0.5;\nhighSideHalf         = sHighRaw * 0.5;\nhighMonoScaled       = highMonoHalf * (highMonoGain * highNormGain);\nhighSideScaled       = highSideHalf * (highSideGain * highNormGain);\nhighSidePolarity     = highSideScaled * highInvertPolarity;\nhighRightPreWidth    = highMonoScaled - highSidePolarity;\nwetHighR             = highRightPreWidth;\nhighLeftPreWidth     = highMonoScaled + highSidePolarity;\nwetHighL             = highLeftPreWidth;\nhighLeftBalanced     = wetHighL * highBalGL;  // ganancia izquierda\nhighLeftWithBandGain = highLeftBalanced * highMakeupLinear;\nhighLeftMixed        = mix(highLIn, highLeftWithBandGain, highBypassMask);\n\n// [HIGH]\nmuteHighSlew     = slewDefault;\nmuteHighSmoothed = mix(muteHigh, muteHighHistory, muteHighSlew);\nmuteHighHistory  = fixdenorm(muteHighSmoothed);\nhighMuteGateRaw  = 1 - clamp(muteHighSmoothed, 0, 1);\nmuteHighGate     = highMuteGateRaw;\n\n// aplicar a HIGH L\nhighLeftMixed         = highLeftMixed * muteHighGate;\nhighRightBalanced     = wetHighR * highBalGR;  // ganancia derecha\nhighRightWithBandGain = highRightBalanced * highMakeupLinear;\nhighRightMixed        = mix(highRIn, highRightWithBandGain, highBypassMask);\n\n// [HIGH] aplicar a HIGH R\nhighRightMixed = highRightMixed * muteHighGate;\n\n// Salidas wet de banda (tras solo/mute) — HIGH\nwetHighRPost = highRightMixed; // R tras gestionar solo/mute\nwetHighLPost = highLeftMixed; // L tras gestionar solo/mute\n\n// Alias (solo rama wet)\nwetTrimL    = trimLeftNext;\nwetTrimR    = trimRightNext;\nwetMakeupL  = makeupLeftNext;\nwetMakeupR  = makeupRightNext;\n\n// =============================================================================\n// ALIAS PARA LEGIBILIDAD EN LA ETAPA DE SALIDA\n// =============================================================================\n// Ramas dry y máscaras de control\ndryInL     = in1;\ndryInR     = in2;\ndryWetMix  = dryWetControl;  // control dry/wet suavizado\n\n// =============================================================================\n// MEZCLA FINAL (MAKEUP SOLO WET → BYPASS → DRY/WET)\n// =============================================================================\nwetHighRightPostSolo = mix(highRightMixed, soloHighZero, soloMaskHigh);\n\n// Sumas wet por lado (tras solo/mute) para facilitar la lectura\nwetRightTotal   = (wetHighRightPostSolo + wetMidRightPostSolo) + wetLowRightPostSolo; // high + mid + low (canal derecho)\nwetRightBlended = mix(wetBandSumR, wetRightTotal * wetMakeupR, dryWetMix);\nwetOutR         = wetRightBlended;\nfinalRightMix   = mix(dryInR, wetRightBlended, bypassMask);\nfinalOutR       = finalRightMix;\nout2            = finalOutR;\n\nwetHighLeftPostSolo = mix(highLeftMixed, soloHighZero, soloMaskHigh);\nwetLeftTotal    = (wetHighLeftPostSolo + wetMidLeftPostSolo) + wetLowLeftPostSolo; // high + mid + low (canal izquierdo)\nwetLeftBlended  = mix(wetBandSumL, wetLeftTotal * wetMakeupL, dryWetMix);\nwetOutL         = wetLeftBlended;\nfinalLeftMix    = mix(dryInL, wetLeftBlended, bypassMask);\nfinalOutL       = finalLeftMix;\nout1            = finalOutL;\n\n// -----------------------------------------------------------------------------\n// ACTUALIZACION DE HISTORIALES\n// -----------------------------------------------------------------------------\ndryWetHistory        = dryWetHistoryNext;\nbypassHistory        = bypassHistoryNext;\nsoloMidHistory       = soloMidHistoryNext;\nsoloHighHistory      = soloHighHistoryNext;\nsoloLowHistory       = soloLowHistoryNext;\ninputModeHistory     = inputModeHistoryNext;\nlowBandGainHistory   = lowBandGainHistoryNext;\nmidBandGainHistory   = midBandGainHistoryNext;\nmidBalanceHistory    = midBalanceHistoryNext;\nhighBandGainHistory  = highBandGainHistoryNext;\nhighBalanceHistory   = highBalanceHistoryNext;\nhighCrossoverHistory = highCrossoverHistoryNext;\nlowCrossoverHistory  = lowCrossoverHistoryNext;\n\nhighMakeupHistory           = highMakeupHistoryNext;\nhighBalanceHistoryInternal  = highBalanceHistoryInternalNext;\nhighWidthHistory            = highWidthHistoryNext;\nhighInputModeHistory        = highInputModeHistoryNext;\nhighBandGainHistoryInternal = highBandGainHistoryInternalNext;\nhighSideGainHistory         = highSideGainHistoryNext;\nhighInvertHistory           = highInvertHistoryNext;\nhighBypassHistory           = highBypassHistoryNext;\nmidMakeupHistory            = midMakeupHistoryNext;\nmidBalanceInternalHistory   = midBalanceInternalHistoryNext;\nmidWidthHistory             = midWidthHistoryNext;\nmidInputModeHistory         = midInputModeHistoryNext;\nmidBandGainHistoryInternal  = midBandGainHistoryInternalNext;\nmidSideGainHistory          = midSideGainHistoryNext;\nmidInvertHistory            = midInvertHistoryNext;\nmidBypassHistory            = midBypassHistoryNext;\nlowBalanceHistory           = lowBalanceHistoryNext;\nlowWidthHistory             = lowWidthHistoryNext;\nlowInputModeHistory         = lowInputModeHistoryNext;\nlowBypassHistory            = lowBypassHistoryNext;\n\n// Actualizaciones de trim\ntrimLeftHistory   = trimLeftNext;\ntrimRightHistory  = trimRightNext;\ntrimSharedHistory = trimSharedNext;\n\n// Actualizaciones de makeup\nmakeupLeftHistory   = makeupLeftNext;\nmakeupRightHistory  = makeupRightNext;\nmakeupSharedHistory = makeupSharedNext;\n",
									"fontface" : 0,
									"fontname" : "<Monospaced>",
									"fontsize" : 12.0,
									"id" : "obj-38",
									"maxclass" : "codebox",
									"numinlets" : 2,
									"numoutlets" : 4,
									"outlettype" : [ "", "", "", "" ],
									"patching_rect" : [ 112.0, 96.0, 1462.600000000000136, 694.0 ]
								}

							}
, 							{
								"box" : 								{
									"color" : [ 1.0, 0.0, 0.933333333333333, 1.0 ],
									"id" : "obj-23",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1555.600000000000136, 57.0, 28.0, 22.0 ],
									"text" : "in 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"id" : "obj-142",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 593.200000000000045, 828.0, 35.0, 22.0 ],
									"text" : "out 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"id" : "obj-141",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 112.0, 828.0, 35.0, 22.0 ],
									"text" : "out 1"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 1.0, 0.0, 0.933333333333333, 1.0 ],
									"id" : "obj-116",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 112.0, 52.0, 28.0, 22.0 ],
									"text" : "in 1"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-38", 0 ],
									"source" : [ "obj-116", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-38", 1 ],
									"source" : [ "obj-23", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-38", 3 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-141", 0 ],
									"source" : [ "obj-38", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-142", 0 ],
									"source" : [ "obj-38", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-2", 0 ],
									"source" : [ "obj-38", 2 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 143.0, 386.0, 275.0, 22.0 ],
					"saved_object_attributes" : 					{
						"autoexport" : 0,
						"exportfolder" : "Sequoia:/Users/jcb/JUCEProjects/JCBImager/exported-code/",
						"exportname" : "JCBImager"
					}
,
					"text" : "gen~ @title JCBImager"
				}

			}
, 			{
				"box" : 				{
					"attr" : "title",
					"id" : "obj-15",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 227.0, 249.0, 310.0, 22.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"midpoints" : [ 199.5, 125.0, 199.5, 125.0 ],
					"order" : 1,
					"source" : [ "obj-1", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"midpoints" : [ 152.5, 125.0, 126.5, 125.0 ],
					"order" : 1,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 1 ],
					"midpoints" : [ 199.5, 120.0, 234.0, 120.0, 234.0, 234.0, 213.0, 234.0, 213.0, 378.52734375, 408.5, 378.52734375 ],
					"order" : 0,
					"source" : [ "obj-1", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 152.5, 285.0, 152.5, 285.0 ],
					"order" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"midpoints" : [ 126.5, 74.0, 152.5, 74.0 ],
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"source" : [ "obj-105", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-33", 0 ],
					"source" : [ "obj-106", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-79", 0 ],
					"source" : [ "obj-107", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-105", 0 ],
					"midpoints" : [ 771.25, 47.5, 626.0, 47.5 ],
					"order" : 2,
					"source" : [ "obj-115", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-106", 0 ],
					"midpoints" : [ 771.25, 47.5, 700.0, 47.5 ],
					"order" : 1,
					"source" : [ "obj-115", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-107", 0 ],
					"midpoints" : [ 771.25, 47.5, 771.25, 47.5 ],
					"order" : 0,
					"source" : [ "obj-115", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-36", 0 ],
					"midpoints" : [ 594.5, 47.5, 594.5, 47.5 ],
					"order" : 2,
					"source" : [ "obj-116", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-37", 0 ],
					"midpoints" : [ 594.5, 47.5, 668.5, 47.5 ],
					"order" : 1,
					"source" : [ "obj-116", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-38", 0 ],
					"midpoints" : [ 594.5, 47.5, 739.5, 47.5 ],
					"order" : 0,
					"source" : [ "obj-116", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 1 ],
					"midpoints" : [ 184.25, 655.0, 163.0, 655.0 ],
					"order" : 1,
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 1 ],
					"midpoints" : [ 184.25, 655.0, 247.0, 655.0 ],
					"order" : 0,
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 1201.5, 224.0, 152.5, 224.0 ],
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"source" : [ "obj-19", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 1 ],
					"source" : [ "obj-20", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 755.5, 369.0, 152.5, 369.0 ],
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 866.5, 224.5, 152.5, 224.5 ],
					"source" : [ "obj-25", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 976.5, 224.5, 152.5, 224.5 ],
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"source" : [ "obj-28", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 1079.5, 224.5, 152.5, 224.5 ],
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-32", 0 ],
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 447.5, 224.0, 152.5, 224.0 ],
					"source" : [ "obj-32", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-34", 0 ],
					"source" : [ "obj-33", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 668.5, 224.0, 152.5, 224.0 ],
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"source" : [ "obj-36", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-33", 0 ],
					"source" : [ "obj-37", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-79", 0 ],
					"source" : [ "obj-38", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 829.5, 369.0, 152.5, 369.0 ],
					"source" : [ "obj-39", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 152.5, 718.5, 171.25, 718.5 ],
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-39", 0 ],
					"source" : [ "obj-41", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-43", 0 ],
					"source" : [ "obj-42", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 926.5, 369.0, 152.5, 369.0 ],
					"source" : [ "obj-43", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 1018.5, 369.0, 152.5, 369.0 ],
					"source" : [ "obj-44", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-44", 0 ],
					"source" : [ "obj-45", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 594.5, 224.5, 152.5, 224.5 ],
					"source" : [ "obj-48", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 43.5, 339.0, 152.5, 339.0 ],
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 1229.0, 224.03125, 152.5, 224.03125 ],
					"source" : [ "obj-50", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-48", 0 ],
					"source" : [ "obj-51", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-50", 0 ],
					"source" : [ "obj-53", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 886.5, 222.0, 152.5, 222.0 ],
					"source" : [ "obj-54", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 739.5, 224.5, 152.5, 224.5 ],
					"source" : [ "obj-56", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-54", 0 ],
					"source" : [ "obj-57", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-59", 0 ],
					"source" : [ "obj-58", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 992.5, 222.0, 152.5, 222.0 ],
					"source" : [ "obj-59", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"midpoints" : [ 237.833333333333314, 577.04296875, 269.5, 577.04296875 ],
					"order" : 0,
					"source" : [ "obj-6", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"midpoints" : [ 152.5, 625.0, 152.5, 625.0 ],
					"order" : 0,
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-40", 0 ],
					"midpoints" : [ 408.5, 416.5, 375.5, 416.5 ],
					"source" : [ "obj-6", 3 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-47", 0 ],
					"midpoints" : [ 323.166666666666629, 416.5, 348.5, 416.5 ],
					"source" : [ "obj-6", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"midpoints" : [ 237.833333333333314, 625.0, 236.5, 625.0 ],
					"order" : 1,
					"source" : [ "obj-6", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-77", 1 ],
					"midpoints" : [ 237.833333333333314, 436.06640625, 59.5, 436.06640625 ],
					"order" : 2,
					"source" : [ "obj-6", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-77", 0 ],
					"midpoints" : [ 152.5, 437.0703125, 36.5, 437.0703125 ],
					"order" : 2,
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"midpoints" : [ 152.5, 579.0, 110.5, 579.0 ],
					"order" : 1,
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-61", 0 ],
					"source" : [ "obj-60", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 1095.5, 222.0, 152.5, 222.0 ],
					"source" : [ "obj-61", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 1133.5, 369.0, 152.5, 369.0 ],
					"source" : [ "obj-62", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 1208.5, 369.0, 152.5, 369.0 ],
					"source" : [ "obj-63", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-62", 0 ],
					"source" : [ "obj-65", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-63", 0 ],
					"source" : [ "obj-66", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 0 ],
					"source" : [ "obj-68", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-42", 0 ],
					"source" : [ "obj-69", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 1 ],
					"midpoints" : [ 236.5, 718.5, 211.25, 718.5 ],
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-45", 0 ],
					"source" : [ "obj-70", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-78", 0 ],
					"source" : [ "obj-77", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-56", 0 ],
					"source" : [ "obj-79", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 360.5, 224.5, 152.5, 224.5 ],
					"source" : [ "obj-8", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-86", 0 ],
					"source" : [ "obj-85", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"source" : [ "obj-86", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-12" : [ "number[7]", "number[7]", 0 ],
			"obj-20" : [ "number[5]", "number[5]", 0 ],
			"obj-28" : [ "number", "number", 0 ],
			"obj-31" : [ "number[1]", "number[1]", 0 ],
			"obj-33" : [ "number[3]", "number[3]", 0 ],
			"obj-35" : [ "toggle", "toggle", 0 ],
			"obj-41" : [ "number[8]", "number[8]", 0 ],
			"obj-42" : [ "number[9]", "number[9]", 0 ],
			"obj-45" : [ "number[10]", "number[10]", 0 ],
			"obj-51" : [ "number[2]", "number[2]", 0 ],
			"obj-53" : [ "number[6]", "number[6]", 0 ],
			"obj-65" : [ "number[11]", "number[11]", 0 ],
			"obj-66" : [ "number[12]", "number[11]", 0 ],
			"obj-79" : [ "number[4]", "number[4]", 0 ],
			"parameterbanks" : 			{

			}
,
			"inherited_shortname" : 1
		}
,
		"dependency_cache" : [  ],
		"autosave" : 0,
		"styles" : [ 			{
				"name" : "tap",
				"default" : 				{
					"fontname" : [ "Lato Light" ]
				}
,
				"parentstyle" : "",
				"multi" : 0
			}
 ]
	}

}
