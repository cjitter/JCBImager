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
		"rect" : [ 274.0, 87.0, 1339.0, 879.0 ],
		"gridsize" : [ 15.0, 15.0 ],
		"boxes" : [ 			{
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
					"patching_rect" : [ 1210.0, 106.0, 50.0, 22.0 ],
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
					"patching_rect" : [ 1210.0, 140.0, 89.0, 22.0 ],
					"text" : "x_DRYWET $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-46",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 814.0, 237.0, 131.0, 20.0 ],
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
					"patching_rect" : [ 1140.0, 262.0, 50.0, 22.0 ],
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
					"patching_rect" : [ 1140.0, 297.0, 95.0, 22.0 ],
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
					"patching_rect" : [ 1048.0, 262.0, 50.0, 22.0 ],
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
					"patching_rect" : [ 1048.0, 297.0, 84.0, 22.0 ],
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
					"patching_rect" : [ 951.0, 262.0, 50.0, 22.0 ],
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
					"patching_rect" : [ 951.0, 297.0, 88.0, 22.0 ],
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
					"patching_rect" : [ 877.0, 262.0, 24.0, 24.0 ],
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
					"patching_rect" : [ 877.0, 297.0, 61.0, 22.0 ],
					"text" : "j_input $1"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 17.0,
					"id" : "obj-21",
					"linecount" : 23,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 530.0, 393.0, 477.0, 443.0 ],
					"text" : "// Params\nParam a_FREQ1(0, min=20, default=250, max=1000);\nParam b_FREQ2(0, min=1000, default=5000, max=20000);\n\nParam c_LOW(1, min=0.5, default=1, max=1.5);\nParam d_MED(1, min=0.5, default=1, max=1.5);\nParam e_HIGH(1, min=0.5, default=1, max=1.5);\n\nParam f_SOLOLOW(0, min=0, default=0, max=1);\nParam g_SOLOMED(0, min=0, default=0, max=1);\nParam h_SOLOHIGH(0, min=0, default=0, max=1);\n\nParam i_BYPASS(0, min=0, default=0, max=1);\nParam j_input(0, min=0, default=1, max=1);\n\nParam k_LOW_bal(0, max=1, default=0.5, min=0);\nParam l_MED_bal(0, min=0, default=0.5, max=1);\nParam m_HIGH_bal(0, min=0, default=0.5, max=1);\n\nParam x_DRYWET(0, min=0, default=1, max=1);\nParam n_MUTLOW(0, min=0, default=0, max=1);\nParam o_MUTMED(0, min=0, default=0, max=1);\nParam p_MUTHIGH(0, min=0, default=0, max=1);"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 129.0, 140.0, 19.0, 58.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 203.0, 140.0, 19.0, 58.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-11",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 405.0, 614.0, 70.0, 131.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 58.0, 614.0, 70.0, 131.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-38",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 730.0, 48.0, 29.5, 22.0 ],
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
					"patching_rect" : [ 659.0, 48.0, 29.5, 22.0 ],
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
					"patching_rect" : [ 585.0, 48.0, 29.5, 22.0 ],
					"text" : "1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-33",
					"maxclass" : "flonum",
					"maximum" : 1.5,
					"minimum" : 0.5,
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
							"parameter_mmax" : 1.5,
							"parameter_mmin" : 0.5,
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
					"maximum" : 20000.0,
					"minimum" : 1000.0,
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
							"parameter_mmax" : 20000.0,
							"parameter_mmin" : 1000.0,
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
					"patching_rect" : [ 233.0, 516.0, 50.0, 22.0 ],
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
					"patching_rect" : [ 353.0, 678.0, 29.5, 22.0 ],
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
					"patching_rect" : [ 222.0, 740.0, 53.0, 53.0 ]
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
					"maximum" : 1.5,
					"minimum" : 0.5,
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
							"parameter_mmax" : 1.5,
							"parameter_mmin" : 0.5,
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
					"maximum" : 1.5,
					"minimum" : 0.5,
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
							"parameter_mmax" : 1.5,
							"parameter_mmin" : 0.5,
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
					"numoutlets" : 2,
					"outlettype" : [ "signal", "signal" ],
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
						"rect" : [ 34.0, 87.0, 1304.0, 905.0 ],
						"gridsize" : [ 15.0, 15.0 ],
						"boxes" : [ 							{
								"box" : 								{
									"code" : "// Params\nParam a_FREQ1(0, min=20, default=250, max=1000);\nParam b_FREQ2(0, min=1000, default=5000, max=20000);\n\nParam c_LOW(1, min=0.5, default=1, max=1.5);\nParam d_MED(1, min=0.5, default=1, max=1.5);\nParam e_HIGH(1, min=0.5, default=1, max=1.5);\n\nParam f_SOLOLOW(0, min=0, default=0, max=1);\nParam g_SOLOMED(0, min=0, default=0, max=1);\nParam h_SOLOHIGH(0, min=0, default=0, max=1);\n\nParam i_BYPASS(0, min=0, default=0, max=1);\nParam j_input(0, min=0, default=1, max=1);\n\nParam k_LOW_bal(0, max=1, default=0.5, min=0);\nParam l_MED_bal(0, min=0, default=0.5, max=1);\nParam m_HIGH_bal(0, min=0, default=0.5, max=1);\n\nParam x_DRYWET(0, min=0, default=1, max=1);\nParam n_MUTLOW(0, min=0, default=0, max=1);\nParam o_MUTMED(0, min=0, default=0, max=1);\nParam p_MUTHIGH(0, min=0, default=0, max=1);\n\n// History\nHistory ap1_lp1_x1(0);\nHistory ap1_lp1_x2(0);\nHistory ap1_lp1_y1(0);\nHistory ap1_lp1_y2(0);\nHistory ap1_lp2_x1(0);\nHistory ap1_lp2_x2(0);\nHistory ap1_lp2_y1(0);\nHistory ap1_lp2_y2(0);\nHistory ap1_hp1_x1(0);\nHistory ap1_hp1_x2(0);\nHistory ap1_hp1_y1(0);\nHistory ap1_hp1_y2(0);\nHistory ap1_hp2_x1(0);\nHistory ap1_hp2_x2(0);\nHistory ap1_hp2_y1(0);\nHistory ap1_hp2_y2(0);\nHistory ap2_lp1_x1(0);\nHistory ap2_lp1_x2(0);\nHistory ap2_lp1_y1(0);\nHistory ap2_lp1_y2(0);\nHistory ap2_lp2_x1(0);\nHistory ap2_lp2_x2(0);\nHistory ap2_lp2_y1(0);\nHistory ap2_lp2_y2(0);\nHistory ap2_hp1_x1(0);\nHistory ap2_hp1_x2(0);\nHistory ap2_hp1_y1(0);\nHistory ap2_hp1_y2(0);\nHistory ap2_hp2_x1(0);\nHistory ap2_hp2_x2(0);\nHistory ap2_hp2_y1(0);\nHistory ap2_hp2_y2(0);\n\nHistory history_1(0);\nHistory history_2(0);\nHistory history_3(0);\nHistory history_4(0);\nHistory history_5(0);\nHistory history_6(0);\nHistory history_7(0);\nHistory history_8(0);\nHistory history_9(0);\nHistory history_10(0);\nHistory history_11(0);\nHistory history_12(0);\nHistory history_13(0);\n\nHistory l1_x1(0);\nHistory l1_x2(0);\nHistory l1_y1(0);\nHistory l1_y2(0);\nHistory l2_x1(0);\nHistory l2_x2(0);\nHistory l2_y1(0);\nHistory l2_y2(0);\nHistory h1_x1(0);\nHistory h1_x2(0);\nHistory h1_y1(0);\nHistory h1_y2(0);\nHistory h2_x1(0);\nHistory h2_x2(0);\nHistory h2_y1(0);\nHistory h2_y2(0);\nHistory m1_x1(0);\nHistory m1_x2(0);\nHistory m1_y1(0);\nHistory m1_y2(0);\nHistory m2_x1(0);\nHistory m2_x2(0);\nHistory m2_y1(0);\nHistory m2_y2(0);\nHistory u1_x1(0);\nHistory u1_x2(0);\nHistory u1_y1(0);\nHistory u1_y2(0);\nHistory u2_x1(0);\nHistory u2_x2(0);\nHistory u2_y1(0);\nHistory u2_y2(0);\n\nHistory ap_low_lp1_x1(0);\nHistory ap_low_lp1_x2(0);\nHistory ap_low_lp1_y1(0);\nHistory ap_low_lp1_y2(0);\nHistory ap_low_lp2_x1(0);\nHistory ap_low_lp2_x2(0);\nHistory ap_low_lp2_y1(0);\nHistory ap_low_lp2_y2(0);\nHistory ap_low_hp1_x1(0);\nHistory ap_low_hp1_x2(0);\nHistory ap_low_hp1_y1(0);\nHistory ap_low_hp1_y2(0);\nHistory ap_low_hp2_x1(0);\nHistory ap_low_hp2_x2(0);\nHistory ap_low_hp2_y1(0);\nHistory ap_low_hp2_y2(0);\nHistory l1_x_14(0);\nHistory l1_x_15(0);\nHistory l1_y_16(0);\nHistory l1_y_17(0);\nHistory l2_x_18(0);\nHistory l2_x_19(0);\nHistory l2_y_20(0);\nHistory l2_y_21(0);\nHistory h1_x_22(0);\nHistory h1_x_23(0);\nHistory h1_y_24(0);\nHistory h1_y_25(0);\nHistory h2_x_26(0);\nHistory h2_x_27(0);\nHistory h2_y_28(0);\nHistory h2_y_29(0);\nHistory m1_x_30(0);\nHistory m1_x_31(0);\nHistory m1_y_32(0);\nHistory m1_y_33(0);\nHistory m2_x_34(0);\nHistory m2_x_35(0);\nHistory m2_y_36(0);\nHistory m2_y_37(0);\nHistory u1_x_38(0);\nHistory u1_x_39(0);\nHistory u1_y_40(0);\nHistory u1_y_41(0);\nHistory u2_x_42(0);\nHistory u2_x_43(0);\nHistory u2_y_44(0);\nHistory u2_y_45(0);\nHistory ap_low_lp1_x_46(0);\nHistory ap_low_lp1_x_47(0);\nHistory ap_low_lp1_y_48(0);\nHistory ap_low_lp1_y_49(0);\nHistory ap_low_lp2_x_50(0);\nHistory ap_low_lp2_x_51(0);\nHistory ap_low_lp2_y_52(0);\nHistory ap_low_lp2_y_53(0);\nHistory ap_low_hp1_x_54(0);\nHistory ap_low_hp1_x_55(0);\nHistory ap_low_hp1_y_56(0);\nHistory ap_low_hp1_y_57(0);\nHistory ap_low_hp2_x_58(0);\nHistory ap_low_hp2_x_59(0);\nHistory ap_low_hp2_y_60(0);\nHistory ap_low_hp2_y_61(0);\nHistory history_62(0);\nHistory history_63(0);\nHistory history_64(0);\nHistory history_65(0);\nHistory history_66(0);\nHistory history_67(0);\nHistory history_68(0);\nHistory history_69(0);\nHistory history_70(0);\nHistory history_71(0);\nHistory history_72(0);\nHistory history_73(0);\nHistory history_74(0);\nHistory history_75(0);\nHistory history_76(0);\nHistory history_77(0);\nHistory history_78(0);\nHistory history_79(0);\nHistory history_80(0);\n// [PATCH-MUTE] smoothing histories for band mutes\nHistory mute_low_h(0);\nHistory mute_mid_h(0);\nHistory mute_high_h(0);\n\n// [PATCH] Per-band RMS and cross-correlation energies for width normalization\nHistory low_EM2(1e-12);\nHistory low_ES2(1e-12);\nHistory low_CCS2(0);      // [PATCH] Cross-correlation (LR) for LOW\n// [PATCH] Per-band input-channel energies for correlation-aware normalization\nHistory low_EL2(1e-12);   // <L^2> LOW\nHistory low_ER2(1e-12);   // <R^2> LOW\nHistory mid_EL2(1e-12);   // <L^2> MID\nHistory mid_ER2(1e-12);   // <R^2> MID\nHistory high_EL2(1e-12);  // <L^2> HIGH\nHistory high_ER2(1e-12);  // <R^2> HIGH\nHistory mid_EM2(1e-12);\nHistory mid_ES2(1e-12);\nHistory mid_CCS2(0);      // [PATCH] Cross-correlation (LR) for MID\nHistory high_EM2(1e-12);\nHistory high_ES2(1e-12);\nHistory high_CCS2(0);     // [PATCH] Cross-correlation (LR) for HIGH\nHistory history_81(0);\nHistory ap1_lp1_x_82(0);\nHistory ap1_lp1_x_83(0);\nHistory ap1_lp1_y_84(0);\nHistory ap1_lp1_y_85(0);\nHistory ap1_lp2_x_86(0);\nHistory ap1_lp2_x_87(0);\nHistory ap1_lp2_y_88(0);\nHistory ap1_lp2_y_89(0);\nHistory ap1_hp1_x_90(0);\nHistory ap1_hp1_x_91(0);\nHistory ap1_hp1_y_92(0);\nHistory ap1_hp1_y_93(0);\nHistory ap1_hp2_x_94(0);\nHistory ap1_hp2_x_95(0);\nHistory ap1_hp2_y_96(0);\nHistory ap1_hp2_y_97(0);\nHistory ap2_lp1_x_98(0);\nHistory ap2_lp1_x_99(0);\nHistory ap2_lp1_y_100(0);\nHistory ap2_lp1_y_101(0);\nHistory ap2_lp2_x_102(0);\nHistory ap2_lp2_x_103(0);\nHistory ap2_lp2_y_104(0);\nHistory ap2_lp2_y_105(0);\nHistory ap2_hp1_x_106(0);\nHistory ap2_hp1_x_107(0);\nHistory ap2_hp1_y_108(0);\nHistory ap2_hp1_y_109(0);\nHistory ap2_hp2_x_110(0);\nHistory ap2_hp2_x_111(0);\nHistory ap2_hp2_y_112(0);\nHistory ap2_hp2_y_113(0);\n\n// ================================\n// [JCBImager] Width normalization helpers (per-band RMS energies)\n// NOTE: Added by patch — used to stabilize level when changing width\n// ================================\n// ================================\n// Crossovers derived from public params (single source of truth)\n// ================================\nxoverLow  = clamp(a_FREQ1,  20,  1000);\nxoverHigh = clamp(b_FREQ2, 1000, 20000);\n\nx = in2;\nsr = samplerate;\nloF = max(10, min(xoverLow, 0.45 * sr));\nhiFr = max(10, min(xoverHigh, 0.45 * sr));\nhiF = max(hiFr, loF + 1);\nw0_lo = ((TWOPI * loF)) / sr;\ncos_lo = cos(w0_lo);\nsin_lo = sin(w0_lo);\nalpha_lo = sin_lo / 1.4142135623731;\na0_lo = 1 + alpha_lo;\na1_lo = -2 * cos_lo;\na2_lo = 1 - alpha_lo;\nlp_b0_l = ((((1 - cos_lo)) * 0.5)) / a0_lo;\nlp_b1_l = ((1 - cos_lo)) / a0_lo;\nlp_b2_l = lp_b0_l;\nlp_a1_l = a1_lo / a0_lo;\nlp_a2_l = a2_lo / a0_lo;\nhp_b0_l = ((((1 + cos_lo)) * 0.5)) / a0_lo;\nhp_b1_l = (-(1 + cos_lo)) / a0_lo;\nhp_b2_l = hp_b0_l;\nhp_a1_l = lp_a1_l;\nhp_a2_l = lp_a2_l;\nw0_hi = ((TWOPI * hiF)) / sr;\ncos_hi = cos(w0_hi);\nsin_hi = sin(w0_hi);\nalpha_hi = sin_hi / 1.4142135623731;\na0_hi = 1 + alpha_hi;\na1_hi = -2 * cos_hi;\na2_hi = 1 - alpha_hi;\nlp_b0_h = ((((1 - cos_hi)) * 0.5)) / a0_hi;\nlp_b1_h = ((1 - cos_hi)) / a0_hi;\nlp_b2_h = lp_b0_h;\nlp_a1_h = a1_hi / a0_hi;\nlp_a2_h = a2_hi / a0_hi;\nhp_b0_h = ((((1 + cos_hi)) * 0.5)) / a0_hi;\nhp_b1_h = (-(1 + cos_hi)) / a0_hi;\nhp_b2_h = hp_b0_h;\nhp_a1_h = lp_a1_h;\nhp_a2_h = lp_a2_h;\nap1_lp1_x1p = ap1_lp1_x1;\nap1_lp1_x2p = ap1_lp1_x2;\nap1_lp1_y1p = ap1_lp1_y1;\nap1_lp1_y2p = ap1_lp1_y2;\nap1_lp_s1 = (((((((lp_b0_l * x) + (lp_b1_l * ap1_lp1_x1p))) + (lp_b2_l * ap1_lp1_x2p))) - (lp_a1_l * ap1_lp1_y1p))) - (lp_a2_l * ap1_lp1_y2p);\nap1_lp1_x2 = ap1_lp1_x1p;\nap1_lp1_x1 = x;\nap1_lp1_y2 = ap1_lp1_y1p;\nap1_lp1_y1 = ap1_lp_s1;\nap1_lp2_x1p = ap1_lp2_x1;\nap1_lp2_x2p = ap1_lp2_x2;\nap1_lp2_y1p = ap1_lp2_y1;\nap1_lp2_y2p = ap1_lp2_y2;\nap1_lp = (((((((lp_b0_l * ap1_lp_s1) + (lp_b1_l * ap1_lp2_x1p))) + (lp_b2_l * ap1_lp2_x2p))) - (lp_a1_l * ap1_lp2_y1p))) - (lp_a2_l * ap1_lp2_y2p);\nap1_lp2_x2 = ap1_lp2_x1p;\nap1_lp2_x1 = ap1_lp_s1;\nap1_lp2_y2 = ap1_lp2_y1p;\nap1_lp2_y1 = ap1_lp;\nap1_hp1_x1p = ap1_hp1_x1;\nap1_hp1_x2p = ap1_hp1_x2;\nap1_hp1_y1p = ap1_hp1_y1;\nap1_hp1_y2p = ap1_hp1_y2;\nap1_hp_s1 = (((((((hp_b0_l * x) + (hp_b1_l * ap1_hp1_x1p))) + (hp_b2_l * ap1_hp1_x2p))) - (hp_a1_l * ap1_hp1_y1p))) - (hp_a2_l * ap1_hp1_y2p);\nap1_hp1_x2 = ap1_hp1_x1p;\nap1_hp1_x1 = x;\nap1_hp1_y2 = ap1_hp1_y1p;\nap1_hp1_y1 = ap1_hp_s1;\nap1_hp2_x1p = ap1_hp2_x1;\nap1_hp2_x2p = ap1_hp2_x2;\nap1_hp2_y1p = ap1_hp2_y1;\nap1_hp2_y2p = ap1_hp2_y2;\nap1_hp = (((((((hp_b0_l * ap1_hp_s1) + (hp_b1_l * ap1_hp2_x1p))) + (hp_b2_l * ap1_hp2_x2p))) - (hp_a1_l * ap1_hp2_y1p))) - (hp_a2_l * ap1_hp2_y2p);\nap1_hp2_x2 = ap1_hp2_x1p;\nap1_hp2_x1 = ap1_hp_s1;\nap1_hp2_y2 = ap1_hp2_y1p;\nap1_hp2_y1 = ap1_hp;\nstage1_out = ap1_lp + ap1_hp;\nap2_lp1_x1p = ap2_lp1_x1;\nap2_lp1_x2p = ap2_lp1_x2;\nap2_lp1_y1p = ap2_lp1_y1;\nap2_lp1_y2p = ap2_lp1_y2;\nap2_lp_s1 = (((((((lp_b0_h * stage1_out) + (lp_b1_h * ap2_lp1_x1p))) + (lp_b2_h * ap2_lp1_x2p))) - (lp_a1_h * ap2_lp1_y1p))) - (lp_a2_h * ap2_lp1_y2p);\nap2_lp1_x2 = ap2_lp1_x1p;\nap2_lp1_x1 = stage1_out;\nap2_lp1_y2 = ap2_lp1_y1p;\nap2_lp1_y1 = ap2_lp_s1;\nap2_lp2_x1p = ap2_lp2_x1;\nap2_lp2_x2p = ap2_lp2_x2;\nap2_lp2_y1p = ap2_lp2_y1;\nap2_lp2_y2p = ap2_lp2_y2;\nap2_lp = (((((((lp_b0_h * ap2_lp_s1) + (lp_b1_h * ap2_lp2_x1p))) + (lp_b2_h * ap2_lp2_x2p))) - (lp_a1_h * ap2_lp2_y1p))) - (lp_a2_h * ap2_lp2_y2p);\nap2_lp2_x2 = ap2_lp2_x1p;\nap2_lp2_x1 = ap2_lp_s1;\nap2_lp2_y2 = ap2_lp2_y1p;\nap2_lp2_y1 = ap2_lp;\nap2_hp1_x1p = ap2_hp1_x1;\nap2_hp1_x2p = ap2_hp1_x2;\nap2_hp1_y1p = ap2_hp1_y1;\nap2_hp1_y2p = ap2_hp1_y2;\nap2_hp_s1 = (((((((hp_b0_h * stage1_out) + (hp_b1_h * ap2_hp1_x1p))) + (hp_b2_h * ap2_hp1_x2p))) - (hp_a1_h * ap2_hp1_y1p))) - (hp_a2_h * ap2_hp1_y2p);\nap2_hp1_x2 = ap2_hp1_x1p;\nap2_hp1_x1 = stage1_out;\nap2_hp1_y2 = ap2_hp1_y1p;\nap2_hp1_y1 = ap2_hp_s1;\nap2_hp2_x1p = ap2_hp2_x1;\nap2_hp2_x2p = ap2_hp2_x2;\nap2_hp2_y1p = ap2_hp2_y1;\nap2_hp2_y2p = ap2_hp2_y2;\nap2_hp = (((((((hp_b0_h * ap2_hp_s1) + (hp_b1_h * ap2_hp2_x1p))) + (hp_b2_h * ap2_hp2_x2p))) - (hp_a1_h * ap2_hp2_y1p))) - (hp_a2_h * ap2_hp2_y2p);\nap2_hp2_x2 = ap2_hp2_x1p;\nap2_hp2_x1 = ap2_hp_s1;\nap2_hp2_y2 = ap2_hp2_y1p;\nap2_hp2_y1 = ap2_hp;\nexpr_114 = ap2_lp + ap2_hp;\nx_115 = in1;\nsr_116 = samplerate;\nloF_117 = max(10, min(xoverLow, 0.45 * sr_116));\nhiFr_118 = max(10, min(xoverHigh, 0.45 * sr_116));\nhiF_119 = max(hiFr_118, loF_117 + 1);\nw0_lo_120 = ((TWOPI * loF_117)) / sr_116;\ncos_lo_121 = cos(w0_lo_120);\nsin_lo_122 = sin(w0_lo_120);\nalpha_lo_123 = sin_lo_122 / 1.4142135623731;\na0_lo_124 = 1 + alpha_lo_123;\na1_lo_125 = -2 * cos_lo_121;\na2_lo_126 = 1 - alpha_lo_123;\nlp_b0_l_127 = ((((1 - cos_lo_121)) * 0.5)) / a0_lo_124;\nlp_b1_l_128 = ((1 - cos_lo_121)) / a0_lo_124;\nlp_b2_l_129 = lp_b0_l_127;\nlp_a1_l_130 = a1_lo_125 / a0_lo_124;\nlp_a2_l_131 = a2_lo_126 / a0_lo_124;\nhp_b0_l_132 = ((((1 + cos_lo_121)) * 0.5)) / a0_lo_124;\nhp_b1_l_133 = (-(1 + cos_lo_121)) / a0_lo_124;\nhp_b2_l_134 = hp_b0_l_132;\nhp_a1_l_135 = lp_a1_l_130;\nhp_a2_l_136 = lp_a2_l_131;\nw0_hi_137 = ((TWOPI * hiF_119)) / sr_116;\ncos_hi_138 = cos(w0_hi_137);\nsin_hi_139 = sin(w0_hi_137);\nalpha_hi_140 = sin_hi_139 / 1.4142135623731;\na0_hi_141 = 1 + alpha_hi_140;\na1_hi_142 = -2 * cos_hi_138;\na2_hi_143 = 1 - alpha_hi_140;\nlp_b0_h_144 = ((((1 - cos_hi_138)) * 0.5)) / a0_hi_141;\nlp_b1_h_145 = ((1 - cos_hi_138)) / a0_hi_141;\nlp_b2_h_146 = lp_b0_h_144;\nlp_a1_h_147 = a1_hi_142 / a0_hi_141;\nlp_a2_h_148 = a2_hi_143 / a0_hi_141;\nhp_b0_h_149 = ((((1 + cos_hi_138)) * 0.5)) / a0_hi_141;\nhp_b1_h_150 = (-(1 + cos_hi_138)) / a0_hi_141;\nhp_b2_h_151 = hp_b0_h_149;\nhp_a1_h_152 = lp_a1_h_147;\nhp_a2_h_153 = lp_a2_h_148;\nap1_lp1_x1p_154 = ap1_lp1_x_82;\nap1_lp1_x2p_155 = ap1_lp1_x_83;\nap1_lp1_y1p_156 = ap1_lp1_y_84;\nap1_lp1_y2p_157 = ap1_lp1_y_85;\nap1_lp_s_158 = (((((((lp_b0_l_127 * x_115) + (lp_b1_l_128 * ap1_lp1_x1p_154))) + (lp_b2_l_129 * ap1_lp1_x2p_155))) - (lp_a1_l_130 * ap1_lp1_y1p_156))) - (lp_a2_l_131 * ap1_lp1_y2p_157);\nap1_lp1_x_83 = ap1_lp1_x1p_154;\nap1_lp1_x_82 = x_115;\nap1_lp1_y_85 = ap1_lp1_y1p_156;\nap1_lp1_y_84 = ap1_lp_s_158;\nap1_lp2_x1p_159 = ap1_lp2_x_86;\nap1_lp2_x2p_160 = ap1_lp2_x_87;\nap1_lp2_y1p_161 = ap1_lp2_y_88;\nap1_lp2_y2p_162 = ap1_lp2_y_89;\nap1_lp_163 = (((((((lp_b0_l_127 * ap1_lp_s_158) + (lp_b1_l_128 * ap1_lp2_x1p_159))) + (lp_b2_l_129 * ap1_lp2_x2p_160))) - (lp_a1_l_130 * ap1_lp2_y1p_161))) - (lp_a2_l_131 * ap1_lp2_y2p_162);\nap1_lp2_x_87 = ap1_lp2_x1p_159;\nap1_lp2_x_86 = ap1_lp_s_158;\nap1_lp2_y_89 = ap1_lp2_y1p_161;\nap1_lp2_y_88 = ap1_lp_163;\nap1_hp1_x1p_164 = ap1_hp1_x_90;\nap1_hp1_x2p_165 = ap1_hp1_x_91;\nap1_hp1_y1p_166 = ap1_hp1_y_92;\nap1_hp1_y2p_167 = ap1_hp1_y_93;\nap1_hp_s_168 = (((((((hp_b0_l_132 * x_115) + (hp_b1_l_133 * ap1_hp1_x1p_164))) + (hp_b2_l_134 * ap1_hp1_x2p_165))) - (hp_a1_l_135 * ap1_hp1_y1p_166))) - (hp_a2_l_136 * ap1_hp1_y2p_167);\nap1_hp1_x_91 = ap1_hp1_x1p_164;\nap1_hp1_x_90 = x_115;\nap1_hp1_y_93 = ap1_hp1_y1p_166;\nap1_hp1_y_92 = ap1_hp_s_168;\nap1_hp2_x1p_169 = ap1_hp2_x_94;\nap1_hp2_x2p_170 = ap1_hp2_x_95;\nap1_hp2_y1p_171 = ap1_hp2_y_96;\nap1_hp2_y2p_172 = ap1_hp2_y_97;\nap1_hp_173 = (((((((hp_b0_l_132 * ap1_hp_s_168) + (hp_b1_l_133 * ap1_hp2_x1p_169))) + (hp_b2_l_134 * ap1_hp2_x2p_170))) - (hp_a1_l_135 * ap1_hp2_y1p_171))) - (hp_a2_l_136 * ap1_hp2_y2p_172);\nap1_hp2_x_95 = ap1_hp2_x1p_169;\nap1_hp2_x_94 = ap1_hp_s_168;\nap1_hp2_y_97 = ap1_hp2_y1p_171;\nap1_hp2_y_96 = ap1_hp_173;\nstage1_out_174 = ap1_lp_163 + ap1_hp_173;\nap2_lp1_x1p_175 = ap2_lp1_x_98;\nap2_lp1_x2p_176 = ap2_lp1_x_99;\nap2_lp1_y1p_177 = ap2_lp1_y_100;\nap2_lp1_y2p_178 = ap2_lp1_y_101;\nap2_lp_s_179 = (((((((lp_b0_h_144 * stage1_out_174) + (lp_b1_h_145 * ap2_lp1_x1p_175))) + (lp_b2_h_146 * ap2_lp1_x2p_176))) - (lp_a1_h_147 * ap2_lp1_y1p_177))) - (lp_a2_h_148 * ap2_lp1_y2p_178);\nap2_lp1_x_99 = ap2_lp1_x1p_175;\nap2_lp1_x_98 = stage1_out_174;\nap2_lp1_y_101 = ap2_lp1_y1p_177;\nap2_lp1_y_100 = ap2_lp_s_179;\nap2_lp2_x1p_180 = ap2_lp2_x_102;\nap2_lp2_x2p_181 = ap2_lp2_x_103;\nap2_lp2_y1p_182 = ap2_lp2_y_104;\nap2_lp2_y2p_183 = ap2_lp2_y_105;\nap2_lp_184 = (((((((lp_b0_h_144 * ap2_lp_s_179) + (lp_b1_h_145 * ap2_lp2_x1p_180))) + (lp_b2_h_146 * ap2_lp2_x2p_181))) - (lp_a1_h_147 * ap2_lp2_y1p_182))) - (lp_a2_h_148 * ap2_lp2_y2p_183);\nap2_lp2_x_103 = ap2_lp2_x1p_180;\nap2_lp2_x_102 = ap2_lp_s_179;\nap2_lp2_y_105 = ap2_lp2_y1p_182;\nap2_lp2_y_104 = ap2_lp_184;\nap2_hp1_x1p_185 = ap2_hp1_x_106;\nap2_hp1_x2p_186 = ap2_hp1_x_107;\nap2_hp1_y1p_187 = ap2_hp1_y_108;\nap2_hp1_y2p_188 = ap2_hp1_y_109;\nap2_hp_s_189 = (((((((hp_b0_h_149 * stage1_out_174) + (hp_b1_h_150 * ap2_hp1_x1p_185))) + (hp_b2_h_151 * ap2_hp1_x2p_186))) - (hp_a1_h_152 * ap2_hp1_y1p_187))) - (hp_a2_h_153 * ap2_hp1_y2p_188);\nap2_hp1_x_107 = ap2_hp1_x1p_185;\nap2_hp1_x_106 = stage1_out_174;\nap2_hp1_y_109 = ap2_hp1_y1p_187;\nap2_hp1_y_108 = ap2_hp_s_189;\nap2_hp2_x1p_190 = ap2_hp2_x_110;\nap2_hp2_x2p_191 = ap2_hp2_x_111;\nap2_hp2_y1p_192 = ap2_hp2_y_112;\nap2_hp2_y2p_193 = ap2_hp2_y_113;\nap2_hp_194 = (((((((hp_b0_h_149 * ap2_hp_s_189) + (hp_b1_h_150 * ap2_hp2_x1p_190))) + (hp_b2_h_151 * ap2_hp2_x2p_191))) - (hp_a1_h_152 * ap2_hp2_y1p_192))) - (hp_a2_h_153 * ap2_hp2_y2p_193);\nap2_hp2_x_111 = ap2_hp2_x1p_190;\nap2_hp2_x_110 = ap2_hp_s_189;\nap2_hp2_y_113 = ap2_hp2_y1p_192;\nap2_hp2_y_112 = ap2_hp_194;\nexpr_195 = ap2_lp_184 + ap2_hp_194;\nfloat_196 = float(0.999);\nmix_197 = mix(x_DRYWET, history_1, float_196);\ngen_198 = mix_197;\nhistory_1_next_199 = fixdenorm(mix_197);\nfloat_200 = float(0.999);\nmix_201 = mix(i_BYPASS, history_2, float_200);\ngen_202 = mix_201;\nhistory_2_next_203 = fixdenorm(mix_201);\nrsub_204 = 1 - gen_202;\nint_205 = int(0);\nfloat_206 = float(0.999);\nmix_207 = mix(g_SOLOMED, history_3, float_206);\ngen_208 = mix_207;\nhistory_3_next_209 = fixdenorm(mix_207);\nfloat_210 = float(0.999);\nmix_211 = mix(h_SOLOHIGH, history_4, float_210);\ngen_212 = mix_211;\nhistory_4_next_213 = fixdenorm(mix_211);\nint_214 = int(0);\nfloat_215 = float(0.999);\nmix_216 = mix(f_SOLOLOW, history_5, float_215);\ngen_217 = mix_216;\nhistory_5_next_218 = fixdenorm(mix_216);\nint_219 = int(0);\nsetparam_220 = k_LOW_bal;\nfloat_221 = float(0.999);\nmix_222 = mix(j_input, history_6, float_221);\ngen_223 = mix_222;\nhistory_6_next_224 = fixdenorm(mix_222);\nsetparam_225 = gen_223;\nint_226 = int(0);\nsetparam_227 = int_226;\nfloat_228 = float(0.999);\nmix_229 = mix(c_LOW, history_7, float_228);\ngen_230 = mix_229;\nhistory_7_next_231 = fixdenorm(mix_229);\nsetparam_232 = gen_230;\nint_233 = int(0);\nsetparam_234 = int_233;\nfloat_235 = float(0.999);\nmix_236 = mix(d_MED, history_8, float_235);\ngen_237 = mix_236;\nhistory_8_next_238 = fixdenorm(mix_236);\nsetparam_239 = gen_237;\nfloat_240 = float(0.999);\nmix_241 = mix(l_MED_bal, history_9, float_240);\ngen_242 = mix_241;\nhistory_9_next_243 = fixdenorm(mix_241);\nsetparam_244 = gen_242;\nint_245 = int(0);\nsetparam_246 = int_245;\nfloat_247 = float(0.999);\nmix_248 = mix(e_HIGH, history_10, float_247);\ngen_249 = mix_248;\nhistory_10_next_250 = fixdenorm(mix_248);\nsetparam_251 = gen_249;\nfloat_252 = float(0.999);\nmix_253 = mix(m_HIGH_bal, history_11, float_252);\ngen_254 = mix_253;\nhistory_11_next_255 = fixdenorm(mix_253);\nsetparam_256 = gen_254;\nfloat_257 = float(0.999);\nmix_258 = mix(b_FREQ2, history_12, float_257);\ngen_259 = mix_258;\nhistory_12_next_260 = fixdenorm(mix_258);\nsetparam_261 = gen_259;\nfloat_262 = float(0.999);\nmix_263 = mix(a_FREQ1, history_13, float_262);\ngen_264 = mix_263;\nhistory_13_next_265 = fixdenorm(mix_263);\nsetparam_266 = gen_264;\nfreq_low_267 = clamp(setparam_266, 20, 1000);\nfreq_high_268 = clamp(setparam_261, 1000, 20000);\nx_269 = in1;\nsr_270 = samplerate;\nloF_271 = max(10, min(freq_low_267, 0.45 * sr_270));\nhiFr_272 = max(10, min(freq_high_268, 0.45 * sr_270));\nhiF_273 = max(hiFr_272, loF_271 + 1);\nw0_lo_274 = ((TWOPI * loF_271)) / sr_270;\ncos_lo_275 = cos(w0_lo_274);\nsin_lo_276 = sin(w0_lo_274);\nalpha_lo_277 = sin_lo_276 / 1.4142135623731;\na0_lo_278 = 1 + alpha_lo_277;\na1_lo_279 = -2 * cos_lo_275;\na2_lo_280 = 1 - alpha_lo_277;\nlp_b0_l_281 = ((((1 - cos_lo_275)) * 0.5)) / a0_lo_278;\nlp_b1_l_282 = ((1 - cos_lo_275)) / a0_lo_278;\nlp_b2_l_283 = lp_b0_l_281;\nlp_a1_l_284 = a1_lo_279 / a0_lo_278;\nlp_a2_l_285 = a2_lo_280 / a0_lo_278;\nhp_b0_l_286 = ((((1 + cos_lo_275)) * 0.5)) / a0_lo_278;\nhp_b1_l_287 = (-(1 + cos_lo_275)) / a0_lo_278;\nhp_b2_l_288 = hp_b0_l_286;\nhp_a1_l_289 = lp_a1_l_284;\nhp_a2_l_290 = lp_a2_l_285;\nw0_hi_291 = ((TWOPI * hiF_273)) / sr_270;\ncos_hi_292 = cos(w0_hi_291);\nsin_hi_293 = sin(w0_hi_291);\nalpha_hi_294 = sin_hi_293 / 1.4142135623731;\na0_hi_295 = 1 + alpha_hi_294;\na1_hi_296 = -2 * cos_hi_292;\na2_hi_297 = 1 - alpha_hi_294;\nlp_b0_h_298 = ((((1 - cos_hi_292)) * 0.5)) / a0_hi_295;\nlp_b1_h_299 = ((1 - cos_hi_292)) / a0_hi_295;\nlp_b2_h_300 = lp_b0_h_298;\nlp_a1_h_301 = a1_hi_296 / a0_hi_295;\nlp_a2_h_302 = a2_hi_297 / a0_hi_295;\nhp_b0_h_303 = ((((1 + cos_hi_292)) * 0.5)) / a0_hi_295;\nhp_b1_h_304 = (-(1 + cos_hi_292)) / a0_hi_295;\nhp_b2_h_305 = hp_b0_h_303;\nhp_a1_h_306 = lp_a1_h_301;\nhp_a2_h_307 = lp_a2_h_302;\nl1_x1p = l1_x1;\nl1_x2p = l1_x2;\nl1_y1p = l1_y1;\nl1_y2p = l1_y2;\nlow_s1 = (((((((lp_b0_l_281 * x_269) + (lp_b1_l_282 * l1_x1p))) + (lp_b2_l_283 * l1_x2p))) - (lp_a1_l_284 * l1_y1p))) - (lp_a2_l_285 * l1_y2p);\nl1_x2 = l1_x1p;\nl1_x1 = x_269;\nl1_y2 = l1_y1p;\nl1_y1 = low_s1;\nl2_x1p = l2_x1;\nl2_x2p = l2_x2;\nl2_y1p = l2_y1;\nl2_y2p = l2_y2;\nlow_raw = (((((((lp_b0_l_281 * low_s1) + (lp_b1_l_282 * l2_x1p))) + (lp_b2_l_283 * l2_x2p))) - (lp_a1_l_284 * l2_y1p))) - (lp_a2_l_285 * l2_y2p);\nl2_x2 = l2_x1p;\nl2_x1 = low_s1;\nl2_y2 = l2_y1p;\nl2_y1 = low_raw;\nh1_x1p = h1_x1;\nh1_x2p = h1_x2;\nh1_y1p = h1_y1;\nh1_y2p = h1_y2;\nrest_s1 = (((((((hp_b0_l_286 * x_269) + (hp_b1_l_287 * h1_x1p))) + (hp_b2_l_288 * h1_x2p))) - (hp_a1_l_289 * h1_y1p))) - (hp_a2_l_290 * h1_y2p);\nh1_x2 = h1_x1p;\nh1_x1 = x_269;\nh1_y2 = h1_y1p;\nh1_y1 = rest_s1;\nh2_x1p = h2_x1;\nh2_x2p = h2_x2;\nh2_y1p = h2_y1;\nh2_y2p = h2_y2;\nrest = (((((((hp_b0_l_286 * rest_s1) + (hp_b1_l_287 * h2_x1p))) + (hp_b2_l_288 * h2_x2p))) - (hp_a1_l_289 * h2_y1p))) - (hp_a2_l_290 * h2_y2p);\nh2_x2 = h2_x1p;\nh2_x1 = rest_s1;\nh2_y2 = h2_y1p;\nh2_y1 = rest;\nap_low_lp1_x1p = ap_low_lp1_x1;\nap_low_lp1_x2p = ap_low_lp1_x2;\nap_low_lp1_y1p = ap_low_lp1_y1;\nap_low_lp1_y2p = ap_low_lp1_y2;\nap_low_lp_s1 = (((((((lp_b0_h_298 * low_raw) + (lp_b1_h_299 * ap_low_lp1_x1p))) + (lp_b2_h_300 * ap_low_lp1_x2p))) - (lp_a1_h_301 * ap_low_lp1_y1p))) - (lp_a2_h_302 * ap_low_lp1_y2p);\nap_low_lp1_x2 = ap_low_lp1_x1p;\nap_low_lp1_x1 = low_raw;\nap_low_lp1_y2 = ap_low_lp1_y1p;\nap_low_lp1_y1 = ap_low_lp_s1;\nap_low_lp2_x1p = ap_low_lp2_x1;\nap_low_lp2_x2p = ap_low_lp2_x2;\nap_low_lp2_y1p = ap_low_lp2_y1;\nap_low_lp2_y2p = ap_low_lp2_y2;\nap_low_lp = (((((((lp_b0_h_298 * ap_low_lp_s1) + (lp_b1_h_299 * ap_low_lp2_x1p))) + (lp_b2_h_300 * ap_low_lp2_x2p))) - (lp_a1_h_301 * ap_low_lp2_y1p))) - (lp_a2_h_302 * ap_low_lp2_y2p);\nap_low_lp2_x2 = ap_low_lp2_x1p;\nap_low_lp2_x1 = ap_low_lp_s1;\nap_low_lp2_y2 = ap_low_lp2_y1p;\nap_low_lp2_y1 = ap_low_lp;\nap_low_hp1_x1p = ap_low_hp1_x1;\nap_low_hp1_x2p = ap_low_hp1_x2;\nap_low_hp1_y1p = ap_low_hp1_y1;\nap_low_hp1_y2p = ap_low_hp1_y2;\nap_low_hp_s1 = (((((((hp_b0_h_303 * low_raw) + (hp_b1_h_304 * ap_low_hp1_x1p))) + (hp_b2_h_305 * ap_low_hp1_x2p))) - (hp_a1_h_306 * ap_low_hp1_y1p))) - (hp_a2_h_307 * ap_low_hp1_y2p);\nap_low_hp1_x2 = ap_low_hp1_x1p;\nap_low_hp1_x1 = low_raw;\nap_low_hp1_y2 = ap_low_hp1_y1p;\nap_low_hp1_y1 = ap_low_hp_s1;\nap_low_hp2_x1p = ap_low_hp2_x1;\nap_low_hp2_x2p = ap_low_hp2_x2;\nap_low_hp2_y1p = ap_low_hp2_y1;\nap_low_hp2_y2p = ap_low_hp2_y2;\nap_low_hp = (((((((hp_b0_h_303 * ap_low_hp_s1) + (hp_b1_h_304 * ap_low_hp2_x1p))) + (hp_b2_h_305 * ap_low_hp2_x2p))) - (hp_a1_h_306 * ap_low_hp2_y1p))) - (hp_a2_h_307 * ap_low_hp2_y2p);\nap_low_hp2_x2 = ap_low_hp2_x1p;\nap_low_hp2_x1 = ap_low_hp_s1;\nap_low_hp2_y2 = ap_low_hp2_y1p;\nap_low_hp2_y1 = ap_low_hp;\nlow = ap_low_lp + ap_low_hp;\nm1_x1p = m1_x1;\nm1_x2p = m1_x2;\nm1_y1p = m1_y1;\nm1_y2p = m1_y2;\nmid_s1 = (((((((lp_b0_h_298 * rest) + (lp_b1_h_299 * m1_x1p))) + (lp_b2_h_300 * m1_x2p))) - (lp_a1_h_301 * m1_y1p))) - (lp_a2_h_302 * m1_y2p);\nm1_x2 = m1_x1p;\nm1_x1 = rest;\nm1_y2 = m1_y1p;\nm1_y1 = mid_s1;\nm2_x1p = m2_x1;\nm2_x2p = m2_x2;\nm2_y1p = m2_y1;\nm2_y2p = m2_y2;\nmid = (((((((lp_b0_h_298 * mid_s1) + (lp_b1_h_299 * m2_x1p))) + (lp_b2_h_300 * m2_x2p))) - (lp_a1_h_301 * m2_y1p))) - (lp_a2_h_302 * m2_y2p);\nm2_x2 = m2_x1p;\nm2_x1 = mid_s1;\nm2_y2 = m2_y1p;\nm2_y1 = mid;\nu1_x1p = u1_x1;\nu1_x2p = u1_x2;\nu1_y1p = u1_y1;\nu1_y2p = u1_y2;\nhigh_s1 = (((((((hp_b0_h_303 * rest) + (hp_b1_h_304 * u1_x1p))) + (hp_b2_h_305 * u1_x2p))) - (hp_a1_h_306 * u1_y1p))) - (hp_a2_h_307 * u1_y2p);\nu1_x2 = u1_x1p;\nu1_x1 = rest;\nu1_y2 = u1_y1p;\nu1_y1 = high_s1;\nu2_x1p = u2_x1;\nu2_x2p = u2_x2;\nu2_y1p = u2_y1;\nu2_y2p = u2_y2;\nhigh = (((((((hp_b0_h_303 * high_s1) + (hp_b1_h_304 * u2_x1p))) + (hp_b2_h_305 * u2_x2p))) - (hp_a1_h_306 * u2_y1p))) - (hp_a2_h_307 * u2_y2p);\nu2_x2 = u2_x1p;\nu2_x1 = high_s1;\nu2_y2 = u2_y1p;\nu2_y1 = high;\nsum3 = ((low + mid)) + high;\nexpr_308 = low;\nexpr_309 = mid;\nexpr_310 = high;\nexpr_311 = sum3;\ngen_312 = expr_308;\ngen_313 = expr_309;\ngen_314 = expr_310;\nfreq_low_315 = clamp(setparam_266, 20, 1000);\nfreq_high_316 = clamp(setparam_261, 1000, 20000);\nx_317 = in2;\nsr_318 = samplerate;\nloF_319 = max(10, min(freq_low_315, 0.45 * sr_318));\nhiFr_320 = max(10, min(freq_high_316, 0.45 * sr_318));\nhiF_321 = max(hiFr_320, loF_319 + 1);\nw0_lo_322 = ((TWOPI * loF_319)) / sr_318;\ncos_lo_323 = cos(w0_lo_322);\nsin_lo_324 = sin(w0_lo_322);\nalpha_lo_325 = sin_lo_324 / 1.4142135623731;\na0_lo_326 = 1 + alpha_lo_325;\na1_lo_327 = -2 * cos_lo_323;\na2_lo_328 = 1 - alpha_lo_325;\nlp_b0_l_329 = ((((1 - cos_lo_323)) * 0.5)) / a0_lo_326;\nlp_b1_l_330 = ((1 - cos_lo_323)) / a0_lo_326;\nlp_b2_l_331 = lp_b0_l_329;\nlp_a1_l_332 = a1_lo_327 / a0_lo_326;\nlp_a2_l_333 = a2_lo_328 / a0_lo_326;\nhp_b0_l_334 = ((((1 + cos_lo_323)) * 0.5)) / a0_lo_326;\nhp_b1_l_335 = (-(1 + cos_lo_323)) / a0_lo_326;\nhp_b2_l_336 = hp_b0_l_334;\nhp_a1_l_337 = lp_a1_l_332;\nhp_a2_l_338 = lp_a2_l_333;\nw0_hi_339 = ((TWOPI * hiF_321)) / sr_318;\ncos_hi_340 = cos(w0_hi_339);\nsin_hi_341 = sin(w0_hi_339);\nalpha_hi_342 = sin_hi_341 / 1.4142135623731;\na0_hi_343 = 1 + alpha_hi_342;\na1_hi_344 = -2 * cos_hi_340;\na2_hi_345 = 1 - alpha_hi_342;\nlp_b0_h_346 = ((((1 - cos_hi_340)) * 0.5)) / a0_hi_343;\nlp_b1_h_347 = ((1 - cos_hi_340)) / a0_hi_343;\nlp_b2_h_348 = lp_b0_h_346;\nlp_a1_h_349 = a1_hi_344 / a0_hi_343;\nlp_a2_h_350 = a2_hi_345 / a0_hi_343;\nhp_b0_h_351 = ((((1 + cos_hi_340)) * 0.5)) / a0_hi_343;\nhp_b1_h_352 = (-(1 + cos_hi_340)) / a0_hi_343;\nhp_b2_h_353 = hp_b0_h_351;\nhp_a1_h_354 = lp_a1_h_349;\nhp_a2_h_355 = lp_a2_h_350;\nl1_x1p_356 = l1_x_14;\nl1_x2p_357 = l1_x_15;\nl1_y1p_358 = l1_y_16;\nl1_y2p_359 = l1_y_17;\nlow_s_360 = (((((((lp_b0_l_329 * x_317) + (lp_b1_l_330 * l1_x1p_356))) + (lp_b2_l_331 * l1_x2p_357))) - (lp_a1_l_332 * l1_y1p_358))) - (lp_a2_l_333 * l1_y2p_359);\nl1_x_15 = l1_x1p_356;\nl1_x_14 = x_317;\nl1_y_17 = l1_y1p_358;\nl1_y_16 = low_s_360;\nl2_x1p_361 = l2_x_18;\nl2_x2p_362 = l2_x_19;\nl2_y1p_363 = l2_y_20;\nl2_y2p_364 = l2_y_21;\nlow_raw_365 = (((((((lp_b0_l_329 * low_s_360) + (lp_b1_l_330 * l2_x1p_361))) + (lp_b2_l_331 * l2_x2p_362))) - (lp_a1_l_332 * l2_y1p_363))) - (lp_a2_l_333 * l2_y2p_364);\nl2_x_19 = l2_x1p_361;\nl2_x_18 = low_s_360;\nl2_y_21 = l2_y1p_363;\nl2_y_20 = low_raw_365;\nh1_x1p_366 = h1_x_22;\nh1_x2p_367 = h1_x_23;\nh1_y1p_368 = h1_y_24;\nh1_y2p_369 = h1_y_25;\nrest_s_370 = (((((((hp_b0_l_334 * x_317) + (hp_b1_l_335 * h1_x1p_366))) + (hp_b2_l_336 * h1_x2p_367))) - (hp_a1_l_337 * h1_y1p_368))) - (hp_a2_l_338 * h1_y2p_369);\nh1_x_23 = h1_x1p_366;\nh1_x_22 = x_317;\nh1_y_25 = h1_y1p_368;\nh1_y_24 = rest_s_370;\nh2_x1p_371 = h2_x_26;\nh2_x2p_372 = h2_x_27;\nh2_y1p_373 = h2_y_28;\nh2_y2p_374 = h2_y_29;\nrest_375 = (((((((hp_b0_l_334 * rest_s_370) + (hp_b1_l_335 * h2_x1p_371))) + (hp_b2_l_336 * h2_x2p_372))) - (hp_a1_l_337 * h2_y1p_373))) - (hp_a2_l_338 * h2_y2p_374);\nh2_x_27 = h2_x1p_371;\nh2_x_26 = rest_s_370;\nh2_y_29 = h2_y1p_373;\nh2_y_28 = rest_375;\nap_low_lp1_x1p_376 = ap_low_lp1_x_46;\nap_low_lp1_x2p_377 = ap_low_lp1_x_47;\nap_low_lp1_y1p_378 = ap_low_lp1_y_48;\nap_low_lp1_y2p_379 = ap_low_lp1_y_49;\nap_low_lp_s_380 = (((((((lp_b0_h_346 * low_raw_365) + (lp_b1_h_347 * ap_low_lp1_x1p_376))) + (lp_b2_h_348 * ap_low_lp1_x2p_377))) - (lp_a1_h_349 * ap_low_lp1_y1p_378))) - (lp_a2_h_350 * ap_low_lp1_y2p_379);\nap_low_lp1_x_47 = ap_low_lp1_x1p_376;\nap_low_lp1_x_46 = low_raw_365;\nap_low_lp1_y_49 = ap_low_lp1_y1p_378;\nap_low_lp1_y_48 = ap_low_lp_s_380;\nap_low_lp2_x1p_381 = ap_low_lp2_x_50;\nap_low_lp2_x2p_382 = ap_low_lp2_x_51;\nap_low_lp2_y1p_383 = ap_low_lp2_y_52;\nap_low_lp2_y2p_384 = ap_low_lp2_y_53;\nap_low_lp_385 = (((((((lp_b0_h_346 * ap_low_lp_s_380) + (lp_b1_h_347 * ap_low_lp2_x1p_381))) + (lp_b2_h_348 * ap_low_lp2_x2p_382))) - (lp_a1_h_349 * ap_low_lp2_y1p_383))) - (lp_a2_h_350 * ap_low_lp2_y2p_384);\nap_low_lp2_x_51 = ap_low_lp2_x1p_381;\nap_low_lp2_x_50 = ap_low_lp_s_380;\nap_low_lp2_y_53 = ap_low_lp2_y1p_383;\nap_low_lp2_y_52 = ap_low_lp_385;\nap_low_hp1_x1p_386 = ap_low_hp1_x_54;\nap_low_hp1_x2p_387 = ap_low_hp1_x_55;\nap_low_hp1_y1p_388 = ap_low_hp1_y_56;\nap_low_hp1_y2p_389 = ap_low_hp1_y_57;\nap_low_hp_s_390 = (((((((hp_b0_h_351 * low_raw_365) + (hp_b1_h_352 * ap_low_hp1_x1p_386))) + (hp_b2_h_353 * ap_low_hp1_x2p_387))) - (hp_a1_h_354 * ap_low_hp1_y1p_388))) - (hp_a2_h_355 * ap_low_hp1_y2p_389);\nap_low_hp1_x_55 = ap_low_hp1_x1p_386;\nap_low_hp1_x_54 = low_raw_365;\nap_low_hp1_y_57 = ap_low_hp1_y1p_388;\nap_low_hp1_y_56 = ap_low_hp_s_390;\nap_low_hp2_x1p_391 = ap_low_hp2_x_58;\nap_low_hp2_x2p_392 = ap_low_hp2_x_59;\nap_low_hp2_y1p_393 = ap_low_hp2_y_60;\nap_low_hp2_y2p_394 = ap_low_hp2_y_61;\nap_low_hp_395 = (((((((hp_b0_h_351 * ap_low_hp_s_390) + (hp_b1_h_352 * ap_low_hp2_x1p_391))) + (hp_b2_h_353 * ap_low_hp2_x2p_392))) - (hp_a1_h_354 * ap_low_hp2_y1p_393))) - (hp_a2_h_355 * ap_low_hp2_y2p_394);\nap_low_hp2_x_59 = ap_low_hp2_x1p_391;\nap_low_hp2_x_58 = ap_low_hp_s_390;\nap_low_hp2_y_61 = ap_low_hp2_y1p_393;\nap_low_hp2_y_60 = ap_low_hp_395;\nlow_396 = ap_low_lp_385 + ap_low_hp_395;\nm1_x1p_397 = m1_x_30;\nm1_x2p_398 = m1_x_31;\nm1_y1p_399 = m1_y_32;\nm1_y2p_400 = m1_y_33;\nmid_s_401 = (((((((lp_b0_h_346 * rest_375) + (lp_b1_h_347 * m1_x1p_397))) + (lp_b2_h_348 * m1_x2p_398))) - (lp_a1_h_349 * m1_y1p_399))) - (lp_a2_h_350 * m1_y2p_400);\nm1_x_31 = m1_x1p_397;\nm1_x_30 = rest_375;\nm1_y_33 = m1_y1p_399;\nm1_y_32 = mid_s_401;\nm2_x1p_402 = m2_x_34;\nm2_x2p_403 = m2_x_35;\nm2_y1p_404 = m2_y_36;\nm2_y2p_405 = m2_y_37;\nmid_406 = (((((((lp_b0_h_346 * mid_s_401) + (lp_b1_h_347 * m2_x1p_402))) + (lp_b2_h_348 * m2_x2p_403))) - (lp_a1_h_349 * m2_y1p_404))) - (lp_a2_h_350 * m2_y2p_405);\nm2_x_35 = m2_x1p_402;\nm2_x_34 = mid_s_401;\nm2_y_37 = m2_y1p_404;\nm2_y_36 = mid_406;\nu1_x1p_407 = u1_x_38;\nu1_x2p_408 = u1_x_39;\nu1_y1p_409 = u1_y_40;\nu1_y2p_410 = u1_y_41;\nhigh_s_411 = (((((((hp_b0_h_351 * rest_375) + (hp_b1_h_352 * u1_x1p_407))) + (hp_b2_h_353 * u1_x2p_408))) - (hp_a1_h_354 * u1_y1p_409))) - (hp_a2_h_355 * u1_y2p_410);\nu1_x_39 = u1_x1p_407;\nu1_x_38 = rest_375;\nu1_y_41 = u1_y1p_409;\nu1_y_40 = high_s_411;\nu2_x1p_412 = u2_x_42;\nu2_x2p_413 = u2_x_43;\nu2_y1p_414 = u2_y_44;\nu2_y2p_415 = u2_y_45;\nhigh_416 = (((((((hp_b0_h_351 * high_s_411) + (hp_b1_h_352 * u2_x1p_412))) + (hp_b2_h_353 * u2_x2p_413))) - (hp_a1_h_354 * u2_y1p_414))) - (hp_a2_h_355 * u2_y2p_415);\nu2_x_43 = u2_x1p_412;\nu2_x_42 = high_s_411;\nu2_y_45 = u2_y1p_414;\nu2_y_44 = high_416;\nsum_417 = ((low_396 + mid_406)) + high_416;\nexpr_418 = low_396;\nexpr_419 = mid_406;\nexpr_420 = high_416;\nexpr_421 = sum_417;\ngen_422 = expr_419;\ngen_423 = expr_418;\ngen_424 = expr_420;\nb_mid = clamp(0, -96, 12);\nc_side = clamp(0, -96, 12);\nf_invertS = clamp(0, 0, 1);\ng_gain = clamp(0, -24, 6);\ne_wide = clamp(setparam_232, 0, 200);\nd_balance = clamp(setparam_220, 0, 1);\nh_bypass = clamp(setparam_227, 0, 1);\na_input = clamp(setparam_225, 0, 1);\nint_425 = int(1);\nfloat_426 = float(0.999);\nmix_427 = mix(h_bypass, history_62, float_426);\ngen_428 = mix_427;\nhistory_62_next_429 = fixdenorm(mix_427);\nrsub_430 = 1 - gen_428;\nint_431 = int(1);\nfloat_432 = float(0.999);\nmix_433 = mix(d_balance, history_63, float_432);\ngen_434 = mix_433;\nhistory_63_next_435 = fixdenorm(mix_433);\n// [PATCH] Stereo balance law (unity at centre). b∈[0..1], b=0.5 → gL=gR=1\nbal_low   = gen_434;\nbl_t      = (bal_low - 0.5) * 2.0;\nbl_pos    = max(bl_t, 0);\nbl_neg    = min(bl_t, 0);\nbl_gL     = clamp(1 - bl_pos, 0, 1);\nbl_gR     = clamp(1 + bl_neg, 0, 1);\nint_439 = int(1);\nint_440 = int(1);\nfloat_441 = float(0.999);\nmix_442 = mix(e_wide, history_64, float_441);\ngen_443 = mix_442;\nhistory_64_next_444 = fixdenorm(mix_442);\n// width already in [0.5..1.5] → no 0.01 scaling\nmul_445 = gen_443;\nint_446 = int(0);\nfloat_447 = float(0.999);\nmix_448 = mix(a_input, history_65, float_447);\ngen_449 = mix_448;\nhistory_65_next_450 = fixdenorm(mix_448);\nmix_451 = mix(gen_312, int_446, gen_449);\nmix_452 = mix(gen_423, int_446, gen_449);\nmix_453 = mix(int_446, gen_312, gen_449);\nmix_454 = mix(int_446, gen_423, gen_449);\nadd_455 = mix_453 + mix_454;\nmul_456 = ((add_455 + mix_451)) * int_439;\nsub_457 = mix_453 - mix_454;\nmul_458 = ((mix_452 + sub_457)) * int_440;\n// -------------------------------\n// [JCBImager][LOW] Width control with content‑aware normalization\n// 1) constant‑power mapping (M/S)  2) per‑band RMS normalization (≈50 ms)\n// -------------------------------\npi_low    = 3.14159265359;\nsqrt2_low = 1.41421356237;\nEPS_low   = 1e-12;\n// [PATCH] RMS window 80 ms for steadier normalization\nalpha_low = 1 - exp(-1 / ((80 * 0.001) * samplerate));\n\n// M/S before MS→LR scaling (your 0.7071 happens after)\nM_low_raw = mul_456;\nS_low_raw = mul_458;\n\n// constant‑power gains from width (w ∈ [0..2])\n// clamp width to 50–150% to avoid extreme spreads\nw_low_c   = clamp(mul_445, 0.5, 1.5);\nu_low     = w_low_c * 0.5;                 // → [0..1]\n// [PATCH] Slightly wider again\ntheta_low = u_low * (pi_low / 2.55);\n// [PATCH] Use cosine/sine directly; reconstruction uses 0.5 (not 0.7071)\ngM_low    = cos(theta_low);\ngS_low    = sin(theta_low);\n\n// Reconstruct band-limited L/R from M/S (pre‑gains)\n// [PATCH] MS→LR pre‑gains reconstruction for measurement with 0.5 since M=L+R, S=L−R\nL_low_pre = (M_low_raw + S_low_raw) * 0.5;\nR_low_pre = (M_low_raw - S_low_raw) * 0.5;\n// Update energies in L/R domain and cross-term <L*R>\nlow_EL2   = fixdenorm(low_EL2 + alpha_low * ((L_low_pre * L_low_pre) - low_EL2));\nlow_ER2   = fixdenorm(low_ER2 + alpha_low * ((R_low_pre * R_low_pre) - low_ER2));\nlow_CCS2  = fixdenorm(low_CCS2 + alpha_low * ((L_low_pre * R_low_pre) - low_CCS2)); // now stores <L*R>\n// (kept for compatibility, not used in normalization anymore)\nlow_EM2   = fixdenorm(low_EM2 + alpha_low * ((M_low_raw * M_low_raw) - low_EM2));\nlow_ES2   = fixdenorm(low_ES2 + alpha_low * ((S_low_raw * S_low_raw) - low_ES2));\n\n// Coeffs after MS gains when going back to L/R\na_low = 0.5 * (gM_low + gS_low);\nb_low = 0.5 * (gM_low - gS_low);\n// Input and predicted output power including correlation\nPin_low  = low_EL2 + low_ER2 + EPS_low;\nPout_low = (a_low*a_low + b_low*b_low) * (low_EL2 + low_ER2) + (4.0 * a_low * b_low) * low_CCS2 + EPS_low;\nG_low    = sqrt(Pin_low / Pout_low);\n// [PATCH] limit normalization to ±4.5 dB using db scale\nG_low     = clamp(G_low, dbtoa(-4.5), dbtoa(4.5));\n\n// [PATCH-PERCEPTUAL] small loudness lift when width > 1.0 (content-aware)\nrho_low_num = low_CCS2;\nrho_low_den = sqrt(max(low_EL2 * low_ER2, EPS_low));\nrho_low     = clamp(rho_low_num / (rho_low_den + EPS_low), -1, 1);\n\n// Sólo empujar cuando abrimos (> 1.0). u_low ∈ [0.25..0.75]\nlift_base_low = max(0, u_low - 0.5);   // 0..0.25\n\n// Constante de “empuje” (ajustable 5..7 dB). 6 dB → máx ≈ +1.5 dB\nK_low_dB    = 6.0;\nlift_dB_low = K_low_dB * lift_base_low * (1 - rho_low);\n\n// Aplicar después de la normalización base\nG_low = G_low * dbtoa(lift_dB_low);\n// Genera leve bump de 0.4 en la banda grave, si molesta quitar de momento lo mantengo\n\n// apply MS→LR matrix with gains and normalization\n// [PATCH] MS→LR matrix when M=L+R, S=L−R\nmul_459 = M_low_raw * 0.5;\nmul_462 = S_low_raw * 0.5;\nmul_461 = mul_459 * (gM_low * G_low);\nmul_463 = mul_462 * (gS_low * G_low);\nmul_464 = mul_463 * int_431;\nsub_465 = mul_461 - mul_464;\ngen_466 = sub_465;\nadd_467 = mul_461 + mul_464;\ngen_468 = add_467;\nmul_469 = gen_468 * bl_gL;  // left gain\nmul_470 = mul_469 * int_425;\nmix_471 = mix(gen_312, mul_470, rsub_430);\ngen_472 = mix_471;\n// [PATCH-MUTE][LOW] smoothed mute gate\nmute_slew_low = float(0.999);\nmute_low_sm = mix(n_MUTLOW, mute_low_h, mute_slew_low);\nmute_low_h = fixdenorm(mute_low_sm);\nlow_gate = 1 - clamp(mute_low_sm, 0, 1);\n// apply to LOW L/R\ngen_472 = gen_472 * low_gate;\nmul_473 = gen_466 * bl_gR;  // right gain\nmul_474 = mul_473 * int_425;\nmix_475 = mix(gen_423, mul_474, rsub_430);\ngen_476 = mix_475;\n// [PATCH-MUTE][LOW] apply to LOW R\ngen_476 = gen_476 * low_gate;\nmix_477 = mix(gen_476, int_205, gen_212 + gen_208);\nmix_478 = mix(gen_472, int_205, gen_212 + gen_208);\nb_mid_479 = clamp(0, -96, 12);\nc_side_480 = clamp(0, -96, 12);\ng_gain_481 = clamp(0, -24, 6);\nf_invertS_482 = clamp(0, 0, 1);\nd_balance_483 = clamp(setparam_244, 0, 1);\ne_wide_484 = clamp(setparam_239, 0, 200);\nh_bypass_485 = clamp(setparam_234, 0, 1);\na_input_486 = clamp(setparam_225, 0, 1);\nfloat_487 = float(0.999);\nmix_488 = mix(h_bypass_485, history_66, float_487);\ngen_489 = mix_488;\nhistory_66_next_490 = fixdenorm(mix_488);\nrsub_491 = 1 - gen_489;\nfloat_492 = float(0.999);\nmix_493 = mix(g_gain_481, history_67, float_492);\ngen_494 = mix_493;\nhistory_67_next_495 = fixdenorm(mix_493);\ndbtoa_496 = dbtoa(gen_494);\nfloat_497 = float(0.999);\nmix_498 = mix(d_balance_483, history_68, float_497);\ngen_499 = mix_498;\nhistory_68_next_500 = fixdenorm(mix_498);\n// [PATCH] Stereo balance law (unity at centre) for MID\nbal_mid   = gen_499;\nbm_t      = (bal_mid - 0.5) * 2.0;\nbm_pos    = max(bm_t, 0);\nbm_neg    = min(bm_t, 0);\nbm_gL     = clamp(1 - bm_pos, 0, 1);\nbm_gR     = clamp(1 + bm_neg, 0, 1);\nfloat_504 = float(0.999);\nmix_505 = mix(e_wide_484, history_69, float_504);\ngen_506 = mix_505;\nhistory_69_next_507 = fixdenorm(mix_505);\n// width already in [0.5..1.5]\nmul_508 = gen_506;\nint_509 = int(0);\nfloat_510 = float(0.999);\nmix_511 = mix(a_input_486, history_70, float_510);\ngen_512 = mix_511;\nhistory_70_next_513 = fixdenorm(mix_511);\nmix_514 = mix(gen_313, int_509, gen_512);\nmix_515 = mix(gen_422, int_509, gen_512);\nmix_516 = mix(int_509, gen_313, gen_512);\nmix_517 = mix(int_509, gen_422, gen_512);\nadd_518 = mix_516 + mix_517;\nsub_519 = mix_516 - mix_517;\ndbtoa_520 = dbtoa(b_mid_479);\nfloat_521 = float(0.999);\nmix_522 = mix(dbtoa_520, history_71, float_521);\ngen_523 = mix_522;\nhistory_71_next_524 = fixdenorm(mix_522);\nm_525 = gen_523;\nmul_526 = ((add_518 + mix_514)) * m_525;\ndbtoa_527 = dbtoa(c_side_480);\nfloat_528 = float(0.999);\nmix_529 = mix(dbtoa_527, history_72, float_528);\ngen_530 = mix_529;\nhistory_72_next_531 = fixdenorm(mix_529);\ns_532 = gen_530;\nmul_533 = ((mix_515 + sub_519)) * s_532;\nint_534 = int(1);\nint_535 = int(-1);\nswitch_536 = f_invertS_482 ? int_534 : int_535;\nmul_537 = switch_536 * -1;\nmix_538 = mix(mul_537, history_73, 0);\ngen_539 = mix_538;\nhistory_73_next_540 = fixdenorm(mix_538);\ninvert_541 = gen_539;\n// -------------------------------\n// [JCBImager][MID] Width control with content‑aware normalization\n// -------------------------------\npi_mid    = 3.14159265359;\nsqrt2_mid = 1.41421356237;\nEPS_mid   = 1e-12;\n// [PATCH] RMS window 80 ms\nalpha_mid = 1 - exp(-1 / ((80 * 0.001) * samplerate));\n\nM_mid_raw = mul_526;\nS_mid_raw = mul_533;\n\n// clamp width to 50–150%\nw_mid_c   = clamp(mul_508, 0.5, 1.5);\nu_mid     = w_mid_c * 0.5;\n// [PATCH] Slightly wider again\ntheta_mid = u_mid * (pi_mid / 2.55);\n// [PATCH] Direct cos/sin; LR matrix uses 0.5\ngM_mid    = cos(theta_mid);\ngS_mid    = sin(theta_mid);\n\n// [PATCH]\nL_mid_pre = (M_mid_raw + S_mid_raw) * 0.5;\nR_mid_pre = (M_mid_raw - S_mid_raw) * 0.5;\nmid_EL2    = fixdenorm(mid_EL2 + alpha_mid * ((L_mid_pre * L_mid_pre) - mid_EL2));\nmid_ER2    = fixdenorm(mid_ER2 + alpha_mid * ((R_mid_pre * R_mid_pre) - mid_ER2));\nmid_CCS2   = fixdenorm(mid_CCS2 + alpha_mid * ((L_mid_pre * R_mid_pre) - mid_CCS2)); // now <L*R>\n// (compatibility updates, not used below)\nmid_EM2    = fixdenorm(mid_EM2 + alpha_mid * ((M_mid_raw * M_mid_raw) - mid_EM2));\nmid_ES2    = fixdenorm(mid_ES2 + alpha_mid * ((S_mid_raw * S_mid_raw) - mid_ES2));\n\na_mid  = 0.5 * (gM_mid + gS_mid);\nb_mid  = 0.5 * (gM_mid - gS_mid);\nPin_mid  = mid_EL2 + mid_ER2 + EPS_mid;\nPout_mid = (a_mid*a_mid + b_mid*b_mid) * (mid_EL2 + mid_ER2) + (4.0 * a_mid * b_mid) * mid_CCS2 + EPS_mid;\nG_mid    = sqrt(Pin_mid / Pout_mid);\n// [PATCH] ±4.5 dB cap\nG_mid     = clamp(G_mid, dbtoa(-4.5), dbtoa(4.5));\n\n// [PATCH-PERCEPTUAL]\nrho_mid_num = mid_CCS2;\nrho_mid_den = sqrt(max(mid_EL2 * mid_ER2, EPS_mid));\nrho_mid     = clamp(rho_mid_num / (rho_mid_den + EPS_mid), -1, 1);\n\nlift_base_mid = max(0, u_mid - 0.5);\nK_mid_dB      = 6.0;\nlift_dB_mid   = K_mid_dB * lift_base_mid * (1 - rho_mid);\n\nG_mid = G_mid * dbtoa(lift_dB_mid);\n\n\n// [PATCH]\nmul_542 = M_mid_raw * 0.5;\nmul_545 = S_mid_raw * 0.5;\nmul_544 = mul_542 * (gM_mid * G_mid);\nmul_546 = mul_545 * (gS_mid * G_mid);\nmul_547 = mul_546 * invert_541;\nsub_548 = mul_544 - mul_547;\ngen_549 = sub_548;\nadd_550 = mul_544 + mul_547;\ngen_551 = add_550;\nmul_552 = gen_549 * bm_gR;  // right gain\nmul_553 = mul_552 * dbtoa_496;\nmix_554 = mix(gen_422, mul_553, rsub_491);\ngen_555 = mix_554;\n// [PATCH-MUTE][MID]\nmute_slew_mid = float(0.999);\nmute_mid_sm = mix(o_MUTMED, mute_mid_h, mute_slew_mid);\nmute_mid_h = fixdenorm(mute_mid_sm);\nmid_gate = 1 - clamp(mute_mid_sm, 0, 1);\n// apply to MID R\ngen_555 = gen_555 * mid_gate;\nmul_556 = gen_551 * bm_gL;  // left gain\nmul_557 = mul_556 * dbtoa_496;\nmix_558 = mix(gen_313, mul_557, rsub_491);\ngen_559 = mix_558;\n// [PATCH-MUTE][MID] apply to MID L\ngen_559 = gen_559 * mid_gate;\nmix_560 = mix(gen_555, int_214, gen_212 + gen_217);\nmix_561 = mix(gen_559, int_214, gen_212 + gen_217);\nc_side_562 = clamp(0, -96, 12);\nb_mid_563 = clamp(0, -96, 12);\nf_invertS_564 = clamp(0, 0, 1);\ng_gain_565 = clamp(0, -24, 6);\nd_balance_566 = clamp(setparam_256, 0, 1);\ne_wide_567 = clamp(setparam_251, 0, 200);\nh_bypass_568 = clamp(setparam_246, 0, 1);\na_input_569 = clamp(setparam_225, 0, 1);\nfloat_570 = float(0.999);\nmix_571 = mix(h_bypass_568, history_74, float_570);\ngen_572 = mix_571;\nhistory_74_next_573 = fixdenorm(mix_571);\nrsub_574 = 1 - gen_572;\nfloat_575 = float(0.999);\nmix_576 = mix(g_gain_565, history_75, float_575);\ngen_577 = mix_576;\nhistory_75_next_578 = fixdenorm(mix_576);\ndbtoa_579 = dbtoa(gen_577);\nfloat_580 = float(0.999);\nmix_581 = mix(d_balance_566, history_76, float_580);\ngen_582 = mix_581;\nhistory_76_next_583 = fixdenorm(mix_581);\n// [PATCH] Stereo balance law (unity at centre) for HIGH\nbal_high  = gen_582;\nbh_t      = (bal_high - 0.5) * 2.0;\nbh_pos    = max(bh_t, 0);\nbh_neg    = min(bh_t, 0);\nbh_gL     = clamp(1 - bh_pos, 0, 1);\nbh_gR     = clamp(1 + bh_neg, 0, 1);\nfloat_587 = float(0.999);\nmix_588 = mix(e_wide_567, history_77, float_587);\ngen_589 = mix_588;\nhistory_77_next_590 = fixdenorm(mix_588);\n// width already in [0.5..1.5]\nmul_591 = gen_589;\nint_592 = int(0);\nfloat_593 = float(0.999);\nmix_594 = mix(a_input_569, history_78, float_593);\ngen_595 = mix_594;\nhistory_78_next_596 = fixdenorm(mix_594);\nmix_597 = mix(gen_314, int_592, gen_595);\nmix_598 = mix(gen_424, int_592, gen_595);\nmix_599 = mix(int_592, gen_314, gen_595);\nmix_600 = mix(int_592, gen_424, gen_595);\nadd_601 = mix_599 + mix_600;\nsub_602 = mix_599 - mix_600;\ndbtoa_603 = dbtoa(b_mid_563);\nfloat_604 = float(0.999);\nmix_605 = mix(dbtoa_603, history_79, float_604);\ngen_606 = mix_605;\nhistory_79_next_607 = fixdenorm(mix_605);\nm_608 = gen_606;\nmul_609 = ((add_601 + mix_597)) * m_608;\ndbtoa_610 = dbtoa(c_side_562);\nfloat_611 = float(0.999);\nmix_612 = mix(dbtoa_610, history_80, float_611);\ngen_613 = mix_612;\nhistory_80_next_614 = fixdenorm(mix_612);\ns_615 = gen_613;\nmul_616 = ((mix_598 + sub_602)) * s_615;\nint_617 = int(1);\nint_618 = int(-1);\nswitch_619 = f_invertS_564 ? int_617 : int_618;\nmul_620 = switch_619 * -1;\nmix_621 = mix(mul_620, history_81, 0);\ngen_622 = mix_621;\nhistory_81_next_623 = fixdenorm(mix_621);\ninvert_624 = gen_622;\n// -------------------------------\n// [JCBImager][HIGH] Width control with content‑aware normalization\n// -------------------------------\npi_high    = 3.14159265359;\nsqrt2_high = 1.41421356237;\nEPS_high   = 1e-12;\n// [PATCH] RMS window 80 ms\nalpha_high = 1 - exp(-1 / ((80 * 0.001) * samplerate));\n\nM_high_raw = mul_609;\nS_high_raw = mul_616;\n\n// clamp width to 50–150%\nw_high_c  = clamp(mul_591, 0.5, 1.5);\nu_high     = w_high_c * 0.5;\n// [PATCH] Slightly wider again\ntheta_high = u_high * (pi_high / 2.55);\n// [PATCH]\ngM_high    = cos(theta_high);\ngS_high    = sin(theta_high);\n\n// [PATCH]\nL_high_pre = (M_high_raw + S_high_raw) * 0.5;\nR_high_pre = (M_high_raw - S_high_raw) * 0.5;\nhigh_EL2    = fixdenorm(high_EL2 + alpha_high * ((L_high_pre * L_high_pre) - high_EL2));\nhigh_ER2    = fixdenorm(high_ER2 + alpha_high * ((R_high_pre * R_high_pre) - high_ER2));\nhigh_CCS2   = fixdenorm(high_CCS2 + alpha_high * ((L_high_pre * R_high_pre) - high_CCS2)); // now <L*R>\n// (compatibility updates)\nhigh_EM2    = fixdenorm(high_EM2 + alpha_high * ((M_high_raw * M_high_raw) - high_EM2));\nhigh_ES2    = fixdenorm(high_ES2 + alpha_high * ((S_high_raw * S_high_raw) - high_ES2));\n\na_high  = 0.5 * (gM_high + gS_high);\nb_high  = 0.5 * (gM_high - gS_high);\nPin_high  = high_EL2 + high_ER2 + EPS_high;\nPout_high = (a_high*a_high + b_high*b_high) * (high_EL2 + high_ER2) + (4.0 * a_high * b_high) * high_CCS2 + EPS_high;\nG_high    = sqrt(Pin_high / Pout_high);\n// [PATCH] ±4.5 dB cap\nG_high     = clamp(G_high, dbtoa(-4.5), dbtoa(4.5));\n\n// [PATCH-PERCEPTUAL]\nrho_high_num = high_CCS2;\nrho_high_den = sqrt(max(high_EL2 * high_ER2, EPS_high));\nrho_high     = clamp(rho_high_num / (rho_high_den + EPS_high), -1, 1);\n\nlift_base_high = max(0, u_high - 0.5);\nK_high_dB      = 6.0;\nlift_dB_high   = K_high_dB * lift_base_high * (1 - rho_high);\n\nG_high = G_high * dbtoa(lift_dB_high);\n\n// [PATCH]\nmul_625 = M_high_raw * 0.5;\nmul_628 = S_high_raw * 0.5;\nmul_627 = mul_625 * (gM_high * G_high);\nmul_629 = mul_628 * (gS_high * G_high);\nmul_630 = mul_629 * invert_624;\nsub_631 = mul_627 - mul_630;\ngen_632 = sub_631;\nadd_633 = mul_627 + mul_630;\ngen_634 = add_633;\nmul_635 = gen_634 * bh_gL;  // left gain\nmul_636 = mul_635 * dbtoa_579;\nmix_637 = mix(gen_314, mul_636, rsub_574);\ngen_638 = mix_637;\n// [PATCH-MUTE][HIGH]\nmute_slew_high = float(0.999);\nmute_high_sm = mix(p_MUTHIGH, mute_high_h, mute_slew_high);\nmute_high_h = fixdenorm(mute_high_sm);\nhigh_gate = 1 - clamp(mute_high_sm, 0, 1);\n// apply to HIGH L\ngen_638 = gen_638 * high_gate;\nmul_639 = gen_632 * bh_gR;  // right gain\nmul_640 = mul_639 * dbtoa_579;\nmix_641 = mix(gen_424, mul_640, rsub_574);\ngen_642 = mix_641;\n// [PATCH-MUTE][HIGH] apply to HIGH R\ngen_642 = gen_642 * high_gate;\nmix_643 = mix(gen_642, int_219, gen_208 + gen_217);\nmix_644 = mix(expr_114, ((mix_643 + mix_560)) + mix_477, gen_198);\nmix_645 = mix(in2, mix_644, rsub_204);\nout2 = mix_645;\nmix_646 = mix(gen_638, int_219, gen_208 + gen_217);\nmix_647 = mix(expr_195, ((mix_646 + mix_561)) + mix_478, gen_198);\nmix_648 = mix(in1, mix_647, rsub_204);\nout1 = mix_648;\n\n// actualizaciones history\nhistory_1 = history_1_next_199;\nhistory_75 = history_75_next_578;\nhistory_76 = history_76_next_583;\nhistory_77 = history_77_next_590;\nhistory_78 = history_78_next_596;\nhistory_79 = history_79_next_607;\nhistory_80 = history_80_next_614;\nhistory_81 = history_81_next_623;\nhistory_74 = history_74_next_573;\nhistory_67 = history_67_next_495;\nhistory_68 = history_68_next_500;\nhistory_69 = history_69_next_507;\nhistory_70 = history_70_next_513;\nhistory_71 = history_71_next_524;\nhistory_72 = history_72_next_531;\nhistory_73 = history_73_next_540;\nhistory_66 = history_66_next_490;\nhistory_63 = history_63_next_435;\nhistory_64 = history_64_next_444;\nhistory_65 = history_65_next_450;\nhistory_62 = history_62_next_429;\nhistory_13 = history_13_next_265;\nhistory_12 = history_12_next_260;\nhistory_11 = history_11_next_255;\nhistory_10 = history_10_next_250;\nhistory_9 = history_9_next_243;\nhistory_8 = history_8_next_238;\nhistory_7 = history_7_next_231;\nhistory_6 = history_6_next_224;\nhistory_5 = history_5_next_218;\nhistory_4 = history_4_next_213;\nhistory_3 = history_3_next_209;\nhistory_2 = history_2_next_203;",
									"fontface" : 0,
									"fontname" : "<Monospaced>",
									"fontsize" : 12.0,
									"id" : "obj-38",
									"maxclass" : "codebox",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 112.0, 96.0, 420.0, 688.0 ]
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
									"patching_rect" : [ 513.0, 34.0, 28.0, 22.0 ],
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
									"patching_rect" : [ 513.0, 834.0, 35.0, 22.0 ],
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
									"patching_rect" : [ 112.0, 834.0, 35.0, 22.0 ],
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
									"patching_rect" : [ 112.0, 34.0, 28.0, 22.0 ],
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
 ]
					}
,
					"patching_rect" : [ 143.0, 460.0, 230.0, 22.0 ],
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
					"midpoints" : [ 199.5, 125.0, 212.5, 125.0 ],
					"order" : 1,
					"source" : [ "obj-1", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"midpoints" : [ 152.5, 125.0, 138.5, 125.0 ],
					"order" : 1,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 1 ],
					"midpoints" : [ 199.5, 439.06640625, 363.5, 439.06640625 ],
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
					"destination" : [ "obj-4", 1 ],
					"midpoints" : [ 242.5, 655.0, 163.0, 655.0 ],
					"order" : 1,
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 1 ],
					"midpoints" : [ 242.5, 655.0, 373.0, 655.0 ],
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
					"midpoints" : [ 886.5, 376.5, 152.5, 376.5 ],
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
					"midpoints" : [ 960.5, 376.5, 152.5, 376.5 ],
					"source" : [ "obj-39", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 152.5, 718.5, 231.5, 718.5 ],
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
					"midpoints" : [ 1057.5, 376.5, 152.5, 376.5 ],
					"source" : [ "obj-43", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 1149.5, 376.5, 152.5, 376.5 ],
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
					"midpoints" : [ 1219.5, 224.03125, 152.5, 224.03125 ],
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
					"midpoints" : [ 363.5, 577.0, 414.5, 577.0 ],
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
					"destination" : [ "obj-7", 0 ],
					"midpoints" : [ 363.5, 625.0, 362.5, 625.0 ],
					"order" : 1,
					"source" : [ "obj-6", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"midpoints" : [ 152.5, 579.0, 67.5, 579.0 ],
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
					"destination" : [ "obj-2", 1 ],
					"midpoints" : [ 362.5, 718.5, 265.5, 718.5 ],
					"source" : [ "obj-7", 0 ]
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
