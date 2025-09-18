{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 2,
			"revision" : 2,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 308.0, 112.0, 1320.0, 633.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"assistshowspatchername" : 0,
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-11",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 489.0, 393.0, 70.0, 131.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 66.0, 393.0, 70.0, 131.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-38",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 723.5, 28.0, 29.5, 22.0 ],
					"text" : "100"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-37",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 652.5, 28.0, 29.5, 22.0 ],
					"text" : "100"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-36",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 578.5, 28.0, 29.5, 22.0 ],
					"text" : "100"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-33",
					"maxclass" : "flonum",
					"maximum" : 200.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 652.5, 78.0, 50.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 100.0 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[3]",
							"parameter_mmax" : 200.0,
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
					"patching_rect" : [ 652.5, 111.0, 65.0, 22.0 ],
					"text" : "d_MED $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-31",
					"maxclass" : "flonum",
					"maximum" : 20000.0,
					"minimum" : 20.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 480.0, 78.0, 59.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 5000.0 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[1]",
							"parameter_mmax" : 20000.0,
							"parameter_mmin" : 20.0,
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
					"patching_rect" : [ 480.0, 111.0, 79.0, 22.0 ],
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
					"patching_rect" : [ 1022.5, 78.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-30",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1022.5, 111.0, 102.0, 22.0 ],
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
					"patching_rect" : [ 919.5, 78.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-27",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 919.5, 111.0, 99.0, 22.0 ],
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
					"patching_rect" : [ 809.5, 78.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-25",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 809.5, 111.0, 96.0, 22.0 ],
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
					"parameter_enable" : 0,
					"patching_rect" : [ 265.0, 44.0, 50.0, 22.0 ]
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
					"patching_rect" : [ 1149.5, 78.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-16",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1149.5, 111.0, 82.0, 22.0 ],
					"text" : "i_BYPASS $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-12",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 426.0, 393.0, 50.0, 22.0 ]
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
					"patching_rect" : [ 142.0, 44.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 381.000000000000227, 457.0, 29.5, 22.0 ],
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
					"patching_rect" : [ 170.999999999999972, 457.0, 29.5, 22.0 ],
					"text" : "*~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 250.000000000000114, 519.0, 53.0, 53.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-5",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 41.0, 137.0, 68.0, 22.0 ],
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
					"patching_rect" : [ 171.0, 44.0, 88.0, 22.0 ],
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
					"patching_rect" : [ 171.0, 77.0, 113.0, 22.0 ],
					"text" : "sfplay~ 2"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-79",
					"maxclass" : "flonum",
					"maximum" : 200.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 723.5, 78.0, 50.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 100.0 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[4]",
							"parameter_mmax" : 200.0,
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
					"patching_rect" : [ 723.5, 111.0, 69.0, 22.0 ],
					"text" : "e_HIGH $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-51",
					"maxclass" : "flonum",
					"maximum" : 200.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 578.5, 78.0, 50.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 100.0 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[2]",
							"parameter_mmax" : 200.0,
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
					"patching_rect" : [ 578.5, 111.0, 65.0, 22.0 ],
					"text" : "c_LOW $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-28",
					"maxclass" : "flonum",
					"maximum" : 20000.0,
					"minimum" : 20.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 393.0, 78.0, 59.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 500.0 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number",
							"parameter_mmax" : 20000.0,
							"parameter_mmin" : 20.0,
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
					"patching_rect" : [ 393.0, 111.0, 79.0, 22.0 ],
					"text" : "a_FREQ1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"linecount" : 5,
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "signal" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 8,
							"minor" : 2,
							"revision" : 2,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "dsp.gen",
						"rect" : [ 157.0, 87.0, 1676.0, 907.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 1,
						"objectsnaponopen" : 1,
						"statusbarvisible" : 2,
						"toolbarvisible" : 1,
						"lefttoolbarpinned" : 0,
						"toptoolbarpinned" : 0,
						"righttoolbarpinned" : 0,
						"bottomtoolbarpinned" : 0,
						"toolbars_unpinned_last_save" : 0,
						"tallnewobj" : 0,
						"boxanimatetime" : 200,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"description" : "",
						"digest" : "",
						"tags" : "",
						"style" : "",
						"subpatcher_template" : "",
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-44",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 930.0, 337.0, 100.0, 22.0 ],
									"text" : "setparam e_wide"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-42",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 843.5, 305.0, 100.0, 22.0 ],
									"text" : "setparam e_wide"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-37",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 617.0, 177.0, 21.0, 22.0 ],
									"text" : "i 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-35",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 967.5, 601.0, 113.0, 22.0 ],
									"text" : "setparam h_bypass"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-30",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 947.5, 575.0, 98.0, 22.0 ],
									"text" : "setparam g_gain"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-28",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 911.5, 551.0, 109.0, 22.0 ],
									"text" : "setparam f_invertS"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-27",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 763.0, 265.0, 100.0, 22.0 ],
									"text" : "setparam e_wide"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-25",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 815.0, 606.0, 117.0, 22.0 ],
									"text" : "setparam d_balance"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-24",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 791.0, 580.0, 97.0, 22.0 ],
									"text" : "setparam c_side"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-22",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 763.0, 554.0, 95.0, 22.0 ],
									"text" : "setparam b_mid"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-18",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 617.0, 217.0, 101.0, 22.0 ],
									"text" : "setparam a_input"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-17",
									"linecount" : 8,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 786.5, 649.0, 325.0, 114.0 ],
									"text" : "Param h_bypass(0, min=0, default=0, max=1);\nParam g_gain(0, min=-24, default=0, max=6);\nParam b_mid(0, min=-96, default=0, max=12);\nParam f_invertS(0, min=0, default=1, max=1);\nParam e_wide(0, min=0, default=100, max=200);\nParam a_input(0, min=0, default=0, max=1);\nParam d_balance(0, min=0, default=0.5, max=1);\nParam c_side(0, min=-96, default=0, max=12);"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-14",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 2,
											"revision" : 2,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "dsp.gen",
										"rect" : [ 82.0, 87.0, 1098.0, 909.0 ],
										"bglocked" : 0,
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 1,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 1,
										"objectsnaponopen" : 1,
										"statusbarvisible" : 2,
										"toolbarvisible" : 1,
										"lefttoolbarpinned" : 0,
										"toptoolbarpinned" : 0,
										"righttoolbarpinned" : 0,
										"bottomtoolbarpinned" : 0,
										"toolbars_unpinned_last_save" : 0,
										"tallnewobj" : 0,
										"boxanimatetime" : 200,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"description" : "",
										"digest" : "",
										"tags" : "",
										"style" : "",
										"subpatcher_template" : "",
										"assistshowspatchername" : 0,
										"boxes" : [ 											{
												"box" : 												{
													"id" : "obj-5",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 1001.0, 866.0, 35.0, 22.0 ],
													"text" : "out 2"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-1",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 26.0, 8.0, 28.0, 22.0 ],
													"text" : "in 1"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-2",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 1001.0, 8.0, 28.0, 22.0 ],
													"text" : "in 2"
												}

											}
, 											{
												"box" : 												{
													"code" : "// Parameters\r\nParam h_bypass(0, min=0, default=0, max=1);\nParam g_gain(0, min=-24, default=0, max=6);\nParam b_mid(0, min=-96, default=0, max=12);\nParam f_invertS(0, min=0, default=1, max=1);\nParam e_wide(0, min=0, default=100, max=200);\nParam a_input(0, min=0, default=0, max=1);\nParam d_balance(0, min=0, default=0.5, max=1);\nParam c_side(0, min=-96, default=0, max=12);\r\n\r\n// Histories\nHistory history_1(0);\nHistory history_2(0);\nHistory history_3(0);\nHistory history_4(0);\nHistory history_5(0);\nHistory history_6(0);\nHistory history_7(0);\nHistory history_8(0);\r\n\nfloat_9 = float(0.999);\nmix_10 = mix(h_bypass, history_1, float_9);\ngen_11 = mix_10;\nhistory_1_next_12 = fixdenorm(mix_10);\nrsub_13 = 1 - gen_11;\nmix_14 = mix(g_gain, history_2, float_9);\ngen_15 = mix_14;\nhistory_2_next_16 = fixdenorm(mix_14);\ndbtoa_17 = dbtoa(gen_15);\nmix_18 = mix(d_balance, history_3, float_9);\ngen_19 = mix_18;\nhistory_3_next_20 = fixdenorm(mix_18);\nsqrt_21 = sqrt(gen_19);\nrsub_22 = 1 - gen_19;\nsqrt_23 = sqrt(rsub_22);\nmix_24 = mix(e_wide, history_4, float_9);\ngen_25 = mix_24;\nhistory_4_next_26 = fixdenorm(mix_24);\nmul_27 = gen_25 * 0.01;\nint_28 = int(0);\nmix_29 = mix(a_input, history_5, float_9);\ngen_30 = mix_29;\nhistory_5_next_31 = fixdenorm(mix_29);\nmix_32 = mix(in1, int_28, gen_30);\nmix_33 = mix(in2, int_28, gen_30);\nmix_34 = mix(int_28, in1, gen_30);\nmix_35 = mix(int_28, in2, gen_30);\nadd_36 = mix_34 + mix_35;\nsub_37 = mix_34 - mix_35;\ndbtoa_38 = dbtoa(b_mid);\nmix_39 = mix(dbtoa_38, history_6, float_9);\ngen_40 = mix_39;\nhistory_6_next_41 = fixdenorm(mix_39);\nm_42 = gen_40;\nmul_43 = ((mix_32 + add_36)) * m_42;\ndbtoa_44 = dbtoa(c_side);\nmix_45 = mix(dbtoa_44, history_7, float_9);\ngen_46 = mix_45;\nhistory_7_next_47 = fixdenorm(mix_45);\ns_48 = gen_46;\nmul_49 = ((mix_33 + sub_37)) * s_48;\nint_50 = int(1);\nint_51 = int(-1);\nswitch_52 = f_invertS ? int_50 : int_51;\nmul_53 = switch_52 * -1;\nmix_54 = mix(mul_53, history_8, float_9);\ngen_55 = mix_54;\nhistory_8_next_56 = fixdenorm(mix_54);\ninvert_57 = gen_55;\nmul_58 = mul_43 * 0.7071;\nrsub_59 = 2 - mul_27;\nmul_60 = mul_58 * rsub_59;\nmul_61 = mul_49 * 0.7071;\nmul_62 = mul_61 * mul_27;\nmul_63 = mul_62 * invert_57;\nadd_64 = mul_60 + mul_63;\ngen_65 = add_64;\nsub_66 = mul_60 - mul_63;\ngen_67 = sub_66;\nmul_68 = gen_67 * sqrt_21;\nmul_69 = mul_68 * dbtoa_17;\nmix_70 = mix(in2, mul_69, rsub_13);\nmul_71 = gen_65 * sqrt_23;\nmul_72 = mul_71 * dbtoa_17;\nmix_73 = mix(in1, mul_72, rsub_13);\r\nhistory_1 = history_1_next_12;\nhistory_8 = history_8_next_56;\nhistory_7 = history_7_next_47;\nhistory_6 = history_6_next_41;\nhistory_5 = history_5_next_31;\nhistory_4 = history_4_next_26;\nhistory_3 = history_3_next_20;\nhistory_2 = history_2_next_16;\r\n\r\n// outputs\r\nout1 = mix_73;\nout2 = mix_70;\n",
													"fontface" : 0,
													"fontname" : "<Monospaced>",
													"fontsize" : 12.0,
													"id" : "obj-3",
													"maxclass" : "codebox",
													"numinlets" : 2,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patching_rect" : [ 26.0, 44.0, 994.0, 810.0 ]
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-4",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 26.0, 866.0, 35.0, 22.0 ],
													"text" : "out 1"
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-3", 0 ],
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-3", 1 ],
													"source" : [ "obj-2", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-4", 0 ],
													"source" : [ "obj-3", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-5", 0 ],
													"source" : [ "obj-3", 1 ]
												}

											}
 ]
									}
,
									"patching_rect" : [ 314.0, 468.0, 99.0, 22.0 ],
									"text" : "gen @title matriz"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-13",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 2,
											"revision" : 2,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "dsp.gen",
										"rect" : [ 82.0, 87.0, 1098.0, 909.0 ],
										"bglocked" : 0,
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 1,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 1,
										"objectsnaponopen" : 1,
										"statusbarvisible" : 2,
										"toolbarvisible" : 1,
										"lefttoolbarpinned" : 0,
										"toptoolbarpinned" : 0,
										"righttoolbarpinned" : 0,
										"bottomtoolbarpinned" : 0,
										"toolbars_unpinned_last_save" : 0,
										"tallnewobj" : 0,
										"boxanimatetime" : 200,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"description" : "",
										"digest" : "",
										"tags" : "",
										"style" : "",
										"subpatcher_template" : "",
										"assistshowspatchername" : 0,
										"boxes" : [ 											{
												"box" : 												{
													"id" : "obj-5",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 1001.0, 866.0, 35.0, 22.0 ],
													"text" : "out 2"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-1",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 26.0, 8.0, 28.0, 22.0 ],
													"text" : "in 1"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-2",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 1001.0, 8.0, 28.0, 22.0 ],
													"text" : "in 2"
												}

											}
, 											{
												"box" : 												{
													"code" : "// Parameters\r\nParam h_bypass(0, min=0, default=0, max=1);\nParam g_gain(0, min=-24, default=0, max=6);\nParam b_mid(0, min=-96, default=0, max=12);\nParam f_invertS(0, min=0, default=1, max=1);\nParam e_wide(0, min=0, default=100, max=200);\nParam a_input(0, min=0, default=0, max=1);\nParam d_balance(0, min=0, default=0.5, max=1);\nParam c_side(0, min=-96, default=0, max=12);\r\n\r\n// Histories\nHistory history_1(0);\nHistory history_2(0);\nHistory history_3(0);\nHistory history_4(0);\nHistory history_5(0);\nHistory history_6(0);\nHistory history_7(0);\nHistory history_8(0);\r\n\nfloat_9 = float(0.999);\nmix_10 = mix(h_bypass, history_1, float_9);\ngen_11 = mix_10;\nhistory_1_next_12 = fixdenorm(mix_10);\nrsub_13 = 1 - gen_11;\nmix_14 = mix(g_gain, history_2, float_9);\ngen_15 = mix_14;\nhistory_2_next_16 = fixdenorm(mix_14);\ndbtoa_17 = dbtoa(gen_15);\nmix_18 = mix(d_balance, history_3, float_9);\ngen_19 = mix_18;\nhistory_3_next_20 = fixdenorm(mix_18);\nsqrt_21 = sqrt(gen_19);\nrsub_22 = 1 - gen_19;\nsqrt_23 = sqrt(rsub_22);\nmix_24 = mix(e_wide, history_4, float_9);\ngen_25 = mix_24;\nhistory_4_next_26 = fixdenorm(mix_24);\nmul_27 = gen_25 * 0.01;\nint_28 = int(0);\nmix_29 = mix(a_input, history_5, float_9);\ngen_30 = mix_29;\nhistory_5_next_31 = fixdenorm(mix_29);\nmix_32 = mix(in1, int_28, gen_30);\nmix_33 = mix(in2, int_28, gen_30);\nmix_34 = mix(int_28, in1, gen_30);\nmix_35 = mix(int_28, in2, gen_30);\nadd_36 = mix_34 + mix_35;\nsub_37 = mix_34 - mix_35;\ndbtoa_38 = dbtoa(b_mid);\nmix_39 = mix(dbtoa_38, history_6, float_9);\ngen_40 = mix_39;\nhistory_6_next_41 = fixdenorm(mix_39);\nm_42 = gen_40;\nmul_43 = ((mix_32 + add_36)) * m_42;\ndbtoa_44 = dbtoa(c_side);\nmix_45 = mix(dbtoa_44, history_7, float_9);\ngen_46 = mix_45;\nhistory_7_next_47 = fixdenorm(mix_45);\ns_48 = gen_46;\nmul_49 = ((mix_33 + sub_37)) * s_48;\nint_50 = int(1);\nint_51 = int(-1);\nswitch_52 = f_invertS ? int_50 : int_51;\nmul_53 = switch_52 * -1;\nmix_54 = mix(mul_53, history_8, float_9);\ngen_55 = mix_54;\nhistory_8_next_56 = fixdenorm(mix_54);\ninvert_57 = gen_55;\nmul_58 = mul_43 * 0.7071;\nrsub_59 = 2 - mul_27;\nmul_60 = mul_58 * rsub_59;\nmul_61 = mul_49 * 0.7071;\nmul_62 = mul_61 * mul_27;\nmul_63 = mul_62 * invert_57;\nadd_64 = mul_60 + mul_63;\ngen_65 = add_64;\nsub_66 = mul_60 - mul_63;\ngen_67 = sub_66;\nmul_68 = gen_67 * sqrt_21;\nmul_69 = mul_68 * dbtoa_17;\nmix_70 = mix(in2, mul_69, rsub_13);\nmul_71 = gen_65 * sqrt_23;\nmul_72 = mul_71 * dbtoa_17;\nmix_73 = mix(in1, mul_72, rsub_13);\r\nhistory_1 = history_1_next_12;\nhistory_8 = history_8_next_56;\nhistory_7 = history_7_next_47;\nhistory_6 = history_6_next_41;\nhistory_5 = history_5_next_31;\nhistory_4 = history_4_next_26;\nhistory_3 = history_3_next_20;\nhistory_2 = history_2_next_16;\r\n\r\n// outputs\r\nout1 = mix_73;\nout2 = mix_70;\n",
													"fontface" : 0,
													"fontname" : "<Monospaced>",
													"fontsize" : 12.0,
													"id" : "obj-3",
													"maxclass" : "codebox",
													"numinlets" : 2,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patching_rect" : [ 26.0, 44.0, 994.0, 810.0 ]
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-4",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 26.0, 866.0, 35.0, 22.0 ],
													"text" : "out 1"
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-3", 0 ],
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-3", 1 ],
													"source" : [ "obj-2", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-4", 0 ],
													"source" : [ "obj-3", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-5", 0 ],
													"source" : [ "obj-3", 1 ]
												}

											}
 ]
									}
,
									"patching_rect" : [ 190.0, 468.0, 99.0, 22.0 ],
									"text" : "gen @title matriz"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-4",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 2,
											"revision" : 2,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "dsp.gen",
										"rect" : [ 513.0, 87.0, 1098.0, 909.0 ],
										"bglocked" : 0,
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 1,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 1,
										"objectsnaponopen" : 1,
										"statusbarvisible" : 2,
										"toolbarvisible" : 1,
										"lefttoolbarpinned" : 0,
										"toptoolbarpinned" : 0,
										"righttoolbarpinned" : 0,
										"bottomtoolbarpinned" : 0,
										"toolbars_unpinned_last_save" : 0,
										"tallnewobj" : 0,
										"boxanimatetime" : 200,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"description" : "",
										"digest" : "",
										"tags" : "",
										"style" : "",
										"subpatcher_template" : "",
										"assistshowspatchername" : 0,
										"boxes" : [ 											{
												"box" : 												{
													"id" : "obj-79",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 557.0, 487.0, 29.0, 22.0 ],
													"text" : "sqrt"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-78",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 526.0, 487.0, 29.0, 22.0 ],
													"text" : "sqrt"
												}

											}
, 											{
												"box" : 												{
													"color" : [ 0.500002145767212, 0.000045299530029, 0.500004887580872, 1.0 ],
													"id" : "obj-73",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 706.0, 148.0, 255.0, 303.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"id" : "obj-5",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 103.0, 263.0, 117.0, 20.0 ],
																	"text" : "FILTRO DE 1 POLO"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-4",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 41.0, 112.0, 35.0, 20.0 ],
																	"text" : "valor"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-27",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 136.0, 112.0, 31.0, 20.0 ],
																	"text" : "coef"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-24",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 28.0, 247.0, 35.0, 22.0 ],
																	"text" : "out 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-18",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 98.0, 187.0, 82.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-17",
																	"maxclass" : "newobj",
																	"numinlets" : 3,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 28.0, 134.0, 152.0, 22.0 ],
																	"text" : "mix"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-3",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 161.0, 31.0, 30.0, 22.0 ],
																	"text" : "in 2"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-1",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 28.0, 31.0, 30.0, 22.0 ],
																	"text" : "in 1"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 0 ],
																	"source" : [ "obj-1", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-18", 0 ],
																	"midpoints" : [ 37.5, 170.0, 107.5, 170.0 ],
																	"order" : 0,
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-24", 0 ],
																	"order" : 1,
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 1 ],
																	"midpoints" : [ 107.5, 237.0, 238.0, 237.0, 238.0, 85.0, 104.0, 85.0 ],
																	"source" : [ "obj-18", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 2 ],
																	"source" : [ "obj-3", 0 ]
																}

															}
 ],
														"editing_bgcolor" : [ 0.9, 0.9, 0.9, 1.0 ]
													}
,
													"patching_rect" : [ 492.0, 238.0, 75.0, 22.0 ],
													"text" : "gen onepole"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-71",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 397.0, 325.0, 46.0, 22.0 ],
													"text" : "mix"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-72",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 312.666666666666686, 325.0, 74.0, 22.0 ],
													"text" : "mix"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-63",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 273.0, 24.0, 21.0, 22.0 ],
													"text" : "i 0"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-60",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 151.333333333333314, 325.0, 46.0, 22.0 ],
													"text" : "mix"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-58",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 67.0, 325.0, 71.0, 22.0 ],
													"text" : "mix"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-40",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 751.0, 551.5, 39.0, 22.0 ],
													"text" : "dbtoa"
												}

											}
, 											{
												"box" : 												{
													"color" : [ 0.500002145767212, 0.000045299530029, 0.500004887580872, 1.0 ],
													"id" : "obj-39",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 706.0, 148.0, 255.0, 303.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"id" : "obj-5",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 103.0, 263.0, 117.0, 20.0 ],
																	"text" : "FILTRO DE 1 POLO"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-4",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 41.0, 112.0, 35.0, 20.0 ],
																	"text" : "valor"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-27",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 136.0, 112.0, 31.0, 20.0 ],
																	"text" : "coef"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-24",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 28.0, 247.0, 35.0, 22.0 ],
																	"text" : "out 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-18",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 98.0, 187.0, 82.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-17",
																	"maxclass" : "newobj",
																	"numinlets" : 3,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 28.0, 134.0, 152.0, 22.0 ],
																	"text" : "mix"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-3",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 161.0, 31.0, 30.0, 22.0 ],
																	"text" : "in 2"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-1",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 28.0, 31.0, 30.0, 22.0 ],
																	"text" : "in 1"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 0 ],
																	"source" : [ "obj-1", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-18", 0 ],
																	"midpoints" : [ 37.5, 170.0, 107.5, 170.0 ],
																	"order" : 0,
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-24", 0 ],
																	"order" : 1,
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 1 ],
																	"midpoints" : [ 107.5, 237.0, 238.0, 237.0, 238.0, 85.0, 104.0, 85.0 ],
																	"source" : [ "obj-18", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 2 ],
																	"source" : [ "obj-3", 0 ]
																}

															}
 ],
														"editing_bgcolor" : [ 0.9, 0.9, 0.9, 1.0 ]
													}
,
													"patching_rect" : [ 791.0, 259.0, 75.0, 22.0 ],
													"text" : "gen onepole"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-38",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 848.0, 664.5, 26.0, 22.0 ],
													"text" : "!- 1"
												}

											}
, 											{
												"box" : 												{
													"color" : [ 0.500002145767212, 0.000045299530029, 0.500004887580872, 1.0 ],
													"id" : "obj-32",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 706.0, 148.0, 255.0, 303.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"id" : "obj-5",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 103.0, 263.0, 117.0, 20.0 ],
																	"text" : "FILTRO DE 1 POLO"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-4",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 41.0, 112.0, 35.0, 20.0 ],
																	"text" : "valor"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-27",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 136.0, 112.0, 31.0, 20.0 ],
																	"text" : "coef"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-24",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 28.0, 247.0, 35.0, 22.0 ],
																	"text" : "out 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-18",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 98.0, 187.0, 82.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-17",
																	"maxclass" : "newobj",
																	"numinlets" : 3,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 28.0, 134.0, 152.0, 22.0 ],
																	"text" : "mix"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-3",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 161.0, 31.0, 30.0, 22.0 ],
																	"text" : "in 2"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-1",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 28.0, 31.0, 30.0, 22.0 ],
																	"text" : "in 1"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 0 ],
																	"source" : [ "obj-1", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-18", 0 ],
																	"midpoints" : [ 37.5, 170.0, 107.5, 170.0 ],
																	"order" : 0,
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-24", 0 ],
																	"order" : 1,
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 1 ],
																	"midpoints" : [ 107.5, 237.0, 238.0, 237.0, 238.0, 85.0, 104.0, 85.0 ],
																	"source" : [ "obj-18", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 2 ],
																	"source" : [ "obj-3", 0 ]
																}

															}
 ],
														"editing_bgcolor" : [ 0.9, 0.9, 0.9, 1.0 ]
													}
,
													"patching_rect" : [ 848.0, 636.5, 128.0, 22.0 ],
													"text" : "gen onepole"
												}

											}
, 											{
												"box" : 												{
													"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
													"id" : "obj-33",
													"linecount" : 4,
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 848.0, 551.5, 100.0, 62.0 ],
													"text" : "Param @name h_bypass @min 0 @max 1 @default 0"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-31",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 236.0, 818.0, 69.0, 22.0 ],
													"text" : "mix"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-30",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 41.5, 813.0, 70.0, 22.0 ],
													"text" : "mix"
												}

											}
, 											{
												"box" : 												{
													"color" : [ 0.500002145767212, 0.000045299530029, 0.500004887580872, 1.0 ],
													"id" : "obj-28",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 706.0, 148.0, 255.0, 303.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"id" : "obj-5",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 103.0, 263.0, 117.0, 20.0 ],
																	"text" : "FILTRO DE 1 POLO"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-4",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 41.0, 112.0, 35.0, 20.0 ],
																	"text" : "valor"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-27",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 136.0, 112.0, 31.0, 20.0 ],
																	"text" : "coef"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-24",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 28.0, 247.0, 35.0, 22.0 ],
																	"text" : "out 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-18",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 98.0, 187.0, 82.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-17",
																	"maxclass" : "newobj",
																	"numinlets" : 3,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 28.0, 134.0, 152.0, 22.0 ],
																	"text" : "mix"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-3",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 161.0, 31.0, 30.0, 22.0 ],
																	"text" : "in 2"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-1",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 28.0, 31.0, 30.0, 22.0 ],
																	"text" : "in 1"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 0 ],
																	"source" : [ "obj-1", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-18", 0 ],
																	"midpoints" : [ 37.5, 170.0, 107.5, 170.0 ],
																	"order" : 0,
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-24", 0 ],
																	"order" : 1,
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 1 ],
																	"midpoints" : [ 107.5, 237.0, 238.0, 237.0, 238.0, 85.0, 104.0, 85.0 ],
																	"source" : [ "obj-18", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 2 ],
																	"source" : [ "obj-3", 0 ]
																}

															}
 ],
														"editing_bgcolor" : [ 0.9, 0.9, 0.9, 1.0 ]
													}
,
													"patching_rect" : [ 751.0, 516.0, 75.0, 22.0 ],
													"text" : "gen onepole"
												}

											}
, 											{
												"box" : 												{
													"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
													"id" : "obj-29",
													"linecount" : 3,
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 751.0, 449.5, 153.0, 49.0 ],
													"text" : "Param @name g_gain @min -24 @max 6 @default 0"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-25",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 261.0, 762.0, 35.0, 22.0 ],
													"text" : "*"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-26",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 67.0, 762.0, 35.0, 22.0 ],
													"text" : "*"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-24",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 663.5, 426.0, 40.0, 22.0 ],
													"text" : "* 0.01"
												}

											}
, 											{
												"box" : 												{
													"fontsize" : 31.0,
													"id" : "obj-23",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 448.5, 24.0, 34.0, 41.0 ],
													"text" : "R"
												}

											}
, 											{
												"box" : 												{
													"fontsize" : 31.0,
													"id" : "obj-22",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 197.5, 24.0, 34.0, 41.0 ],
													"text" : "L"
												}

											}
, 											{
												"box" : 												{
													"fontsize" : 31.0,
													"id" : "obj-17",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 360.0, 24.0, 34.0, 41.0 ],
													"text" : "S"
												}

											}
, 											{
												"box" : 												{
													"fontsize" : 31.0,
													"id" : "obj-16",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 120.5, 24.0, 34.0, 41.0 ],
													"text" : "M"
												}

											}
, 											{
												"box" : 												{
													"color" : [ 0.500002145767212, 0.000045299530029, 0.500004887580872, 1.0 ],
													"id" : "obj-15",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 706.0, 148.0, 255.0, 303.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"id" : "obj-5",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 103.0, 263.0, 117.0, 20.0 ],
																	"text" : "FILTRO DE 1 POLO"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-4",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 41.0, 112.0, 35.0, 20.0 ],
																	"text" : "valor"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-27",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 136.0, 112.0, 31.0, 20.0 ],
																	"text" : "coef"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-24",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 28.0, 247.0, 35.0, 22.0 ],
																	"text" : "out 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-18",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 98.0, 187.0, 82.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-17",
																	"maxclass" : "newobj",
																	"numinlets" : 3,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 28.0, 134.0, 152.0, 22.0 ],
																	"text" : "mix"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-3",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 161.0, 31.0, 30.0, 22.0 ],
																	"text" : "in 2"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-1",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 28.0, 31.0, 30.0, 22.0 ],
																	"text" : "in 1"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 0 ],
																	"source" : [ "obj-1", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-18", 0 ],
																	"midpoints" : [ 37.5, 170.0, 107.5, 170.0 ],
																	"order" : 0,
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-24", 0 ],
																	"order" : 1,
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 1 ],
																	"midpoints" : [ 107.5, 237.0, 238.0, 237.0, 238.0, 85.0, 104.0, 85.0 ],
																	"source" : [ "obj-18", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 2 ],
																	"source" : [ "obj-3", 0 ]
																}

															}
 ],
														"editing_bgcolor" : [ 0.9, 0.9, 0.9, 1.0 ]
													}
,
													"patching_rect" : [ 663.5, 399.0, 75.0, 22.0 ],
													"text" : "gen onepole"
												}

											}
, 											{
												"box" : 												{
													"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
													"id" : "obj-12",
													"linecount" : 2,
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 663.5, 348.5, 174.5, 35.0 ],
													"text" : "Param @name e_wide @min 0 @max 200 @default 100"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-11",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 132.333333333333314, 566.0, 36.5, 22.0 ],
													"text" : "*"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-10",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 68.0, 566.0, 36.5, 22.0 ],
													"text" : "*"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-9",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 335.0, 442.0, 53.0, 20.0 ],
													"text" : "XY - MS"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-3",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 149.833333333333314, 463.0, 22.0, 22.0 ],
													"text" : "r s"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-6",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 85.5, 463.0, 26.0, 22.0 ],
													"text" : "r m"
												}

											}
, 											{
												"box" : 												{
													"color" : [ 0.500002145767212, 0.000045299530029, 0.500004887580872, 1.0 ],
													"id" : "obj-90",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 706.0, 148.0, 255.0, 303.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"id" : "obj-5",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 103.0, 263.0, 117.0, 20.0 ],
																	"text" : "FILTRO DE 1 POLO"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-4",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 41.0, 112.0, 35.0, 20.0 ],
																	"text" : "valor"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-27",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 136.0, 112.0, 31.0, 20.0 ],
																	"text" : "coef"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-24",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 28.0, 247.0, 35.0, 22.0 ],
																	"text" : "out 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-18",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 98.0, 187.0, 82.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-17",
																	"maxclass" : "newobj",
																	"numinlets" : 3,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 28.0, 134.0, 152.0, 22.0 ],
																	"text" : "mix"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-3",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 161.0, 31.0, 30.0, 22.0 ],
																	"text" : "in 2"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-1",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 28.0, 31.0, 30.0, 22.0 ],
																	"text" : "in 1"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 0 ],
																	"source" : [ "obj-1", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-18", 0 ],
																	"midpoints" : [ 37.5, 170.0, 107.5, 170.0 ],
																	"order" : 0,
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-24", 0 ],
																	"order" : 1,
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 1 ],
																	"midpoints" : [ 107.5, 237.0, 238.0, 237.0, 238.0, 85.0, 104.0, 85.0 ],
																	"source" : [ "obj-18", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 2 ],
																	"source" : [ "obj-3", 0 ]
																}

															}
 ],
														"editing_bgcolor" : [ 0.9, 0.9, 0.9, 1.0 ]
													}
,
													"patching_rect" : [ 557.0, 325.0, 75.0, 22.0 ],
													"text" : "gen onepole"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-88",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 526.0, 418.5, 26.0, 22.0 ],
													"text" : "!- 1"
												}

											}
, 											{
												"box" : 												{
													"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
													"id" : "obj-86",
													"linecount" : 2,
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 557.0, 276.0, 222.0, 35.0 ],
													"text" : "Param @name d_balance @min 0 @max 1 @default 0.5"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-85",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 261.0, 688.0, 35.0, 22.0 ],
													"text" : "*"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-84",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 67.0, 688.0, 35.0, 22.0 ],
													"text" : "*"
												}

											}
, 											{
												"box" : 												{
													"color" : [ 0.500002145767212, 0.000045299530029, 0.500004887580872, 1.0 ],
													"id" : "obj-77",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 706.0, 148.0, 255.0, 303.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"id" : "obj-5",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 103.0, 263.0, 117.0, 20.0 ],
																	"text" : "FILTRO DE 1 POLO"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-4",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 41.0, 112.0, 35.0, 20.0 ],
																	"text" : "valor"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-27",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 136.0, 112.0, 31.0, 20.0 ],
																	"text" : "coef"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-24",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 28.0, 247.0, 35.0, 22.0 ],
																	"text" : "out 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-18",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 98.0, 187.0, 82.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-17",
																	"maxclass" : "newobj",
																	"numinlets" : 3,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 28.0, 134.0, 152.0, 22.0 ],
																	"text" : "mix"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-3",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 161.0, 31.0, 30.0, 22.0 ],
																	"text" : "in 2"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-1",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 28.0, 31.0, 30.0, 22.0 ],
																	"text" : "in 1"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 0 ],
																	"source" : [ "obj-1", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-18", 0 ],
																	"midpoints" : [ 37.5, 170.0, 107.5, 170.0 ],
																	"order" : 0,
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-24", 0 ],
																	"order" : 1,
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 1 ],
																	"midpoints" : [ 107.5, 237.0, 238.0, 237.0, 238.0, 85.0, 104.0, 85.0 ],
																	"source" : [ "obj-18", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 2 ],
																	"source" : [ "obj-3", 0 ]
																}

															}
 ],
														"editing_bgcolor" : [ 0.9, 0.9, 0.9, 1.0 ]
													}
,
													"patching_rect" : [ 645.0, 141.0, 75.0, 22.0 ],
													"text" : "gen onepole"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-76",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 492.0, 168.0, 28.0, 22.0 ],
													"text" : "s m"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-75",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 957.0, 86.0, 45.0, 22.0 ],
													"text" : "f 0.999"
												}

											}
, 											{
												"box" : 												{
													"color" : [ 0.500002145767212, 0.000045299530029, 0.500004887580872, 1.0 ],
													"id" : "obj-74",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 706.0, 148.0, 255.0, 303.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"id" : "obj-5",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 103.0, 263.0, 117.0, 20.0 ],
																	"text" : "FILTRO DE 1 POLO"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-4",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 41.0, 112.0, 35.0, 20.0 ],
																	"text" : "valor"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-27",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 136.0, 112.0, 31.0, 20.0 ],
																	"text" : "coef"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-24",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 28.0, 247.0, 35.0, 22.0 ],
																	"text" : "out 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-18",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 98.0, 187.0, 82.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-17",
																	"maxclass" : "newobj",
																	"numinlets" : 3,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 28.0, 134.0, 152.0, 22.0 ],
																	"text" : "mix"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-3",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 161.0, 31.0, 30.0, 22.0 ],
																	"text" : "in 2"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-1",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 28.0, 31.0, 30.0, 22.0 ],
																	"text" : "in 1"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 0 ],
																	"source" : [ "obj-1", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-18", 0 ],
																	"midpoints" : [ 37.5, 170.0, 107.5, 170.0 ],
																	"order" : 0,
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-24", 0 ],
																	"order" : 1,
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 1 ],
																	"midpoints" : [ 107.5, 237.0, 238.0, 237.0, 238.0, 85.0, 104.0, 85.0 ],
																	"source" : [ "obj-18", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-17", 2 ],
																	"source" : [ "obj-3", 0 ]
																}

															}
 ],
														"editing_bgcolor" : [ 0.9, 0.9, 0.9, 1.0 ]
													}
,
													"patching_rect" : [ 492.0, 141.0, 75.0, 22.0 ],
													"text" : "gen onepole"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-65",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 391.0, 438.0, 55.5, 22.0 ],
													"text" : "-"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-64",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 273.0, 438.0, 55.5, 22.0 ],
													"text" : "+"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-59",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 261.0, 602.0, 45.0, 22.0 ],
													"text" : "r invert"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-56",
													"maxclass" : "newobj",
													"numinlets" : 4,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 1184.0, 502.0, 568.0, 376.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"id" : "obj-11",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 302.0, 143.0, 46.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-10",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 73.5, 112.0, 26.0, 22.0 ],
																	"text" : "!- 2"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-5",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 406.0, 50.0, 121.0, 22.0 ],
																	"text" : "in 3 @comment wide"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-4",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 46.0, 143.0, 46.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-2",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 302.0, 46.0, 53.0, 22.0 ],
																	"text" : "* 0.7071"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-1",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 46.0, 50.0, 53.0, 22.0 ],
																	"text" : "* 0.7071"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-3",
																	"linecount" : 2,
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 444.0, 91.0, 96.0, 35.0 ],
																	"text" : "in 4 @comment invertS"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-22",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 302.0, 177.0, 67.0, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-7",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 291.5, 287.0, 29.5, 22.0 ],
																	"text" : "-"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-6",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 45.5, 292.0, 29.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-51",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 46.0, 7.0, 28.0, 22.0 ],
																	"text" : "in 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-52",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 302.0, 7.0, 28.0, 22.0 ],
																	"text" : "in 2"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-53",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 45.5, 321.0, 35.0, 22.0 ],
																	"text" : "out 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-54",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 291.5, 324.0, 35.0, 22.0 ],
																	"text" : "out 2"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-4", 0 ],
																	"source" : [ "obj-1", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-4", 1 ],
																	"source" : [ "obj-10", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-22", 0 ],
																	"source" : [ "obj-11", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-11", 0 ],
																	"source" : [ "obj-2", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-6", 1 ],
																	"order" : 1,
																	"source" : [ "obj-22", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-7", 1 ],
																	"order" : 0,
																	"source" : [ "obj-22", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-22", 1 ],
																	"source" : [ "obj-3", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-6", 0 ],
																	"order" : 1,
																	"source" : [ "obj-4", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-7", 0 ],
																	"order" : 0,
																	"source" : [ "obj-4", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-10", 0 ],
																	"order" : 1,
																	"source" : [ "obj-5", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-11", 1 ],
																	"order" : 0,
																	"source" : [ "obj-5", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-1", 0 ],
																	"source" : [ "obj-51", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-2", 0 ],
																	"source" : [ "obj-52", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-53", 0 ],
																	"source" : [ "obj-6", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-54", 0 ],
																	"source" : [ "obj-7", 0 ]
																}

															}
 ]
													}
,
													"patching_rect" : [ 68.0, 636.0, 212.0, 22.0 ],
													"text" : "gen @matriz_ms"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-50",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 791.0, 174.0, 27.0, 22.0 ],
													"text" : "* -1"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-45",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 791.0, 289.0, 47.0, 22.0 ],
													"text" : "s invert"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-44",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 897.0, 86.0, 25.0, 22.0 ],
													"text" : "i -1"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-43",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 844.0, 86.0, 21.0, 22.0 ],
													"text" : "i 1"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-42",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 791.0, 141.0, 125.0, 22.0 ],
													"text" : "?"
												}

											}
, 											{
												"box" : 												{
													"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
													"id" : "obj-36",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 492.0, 199.0, 287.0, 22.0 ],
													"text" : "Param @name a_input @min 0 @max 1 @default 0"
												}

											}
, 											{
												"box" : 												{
													"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
													"id" : "obj-21",
													"linecount" : 2,
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 791.0, 24.0, 211.0, 35.0 ],
													"text" : "Param @name f_invertS @min 0 @max 1 @default 1"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-18",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 645.0, 168.0, 24.0, 22.0 ],
													"text" : "s s"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-19",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 645.0, 86.0, 39.0, 22.0 ],
													"text" : "dbtoa"
												}

											}
, 											{
												"box" : 												{
													"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
													"id" : "obj-20",
													"linecount" : 3,
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 645.0, 24.0, 123.0, 49.0 ],
													"text" : "Param @name c_side @min -96 @max 12 @default 0"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-14",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 492.0, 86.0, 39.0, 22.0 ],
													"text" : "dbtoa"
												}

											}
, 											{
												"box" : 												{
													"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
													"id" : "obj-13",
													"linecount" : 3,
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 492.0, 24.0, 129.0, 49.0 ],
													"text" : "Param @name b_mid @min -96 @max 12 @default 0"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-5",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 236.0, 854.0, 35.0, 22.0 ],
													"text" : "out 2"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-1",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 165.0, 24.0, 28.0, 22.0 ],
													"text" : "in 1"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-2",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 410.5, 24.0, 28.0, 22.0 ],
													"text" : "in 2"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-4",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 41.5, 854.0, 35.0, 22.0 ],
													"text" : "out 1"
												}

											}
, 											{
												"box" : 												{
													"angle" : 270.0,
													"bgcolor" : [ 0.823529411764706, 0.266666666666667, 0.831372549019608, 0.07 ],
													"border" : 2,
													"bordercolor" : [ 0.850980392156863, 0.0, 1.0, 1.0 ],
													"id" : "obj-7",
													"maxclass" : "panel",
													"mode" : 0,
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 261.5, 429.75, 200.0, 41.5 ],
													"proportion" : 0.5
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"color" : [ 0.0, 0.0, 0.0, 1.0 ],
													"destination" : [ "obj-30", 0 ],
													"midpoints" : [ 174.5, 125.0, 51.0, 125.0 ],
													"order" : 2,
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.000066079199314, 0.001801013946533, 0.998228549957275, 1.0 ],
													"destination" : [ "obj-58", 0 ],
													"midpoints" : [ 174.5, 206.75, 76.5, 206.75 ],
													"order" : 1,
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.000066079199314, 0.001801013946533, 0.998228549957275, 1.0 ],
													"destination" : [ "obj-60", 1 ],
													"midpoints" : [ 174.5, 206.75, 174.333333333333314, 206.75 ],
													"order" : 0,
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.000066079199314, 0.001801013946533, 0.998228549957275, 1.0 ],
													"destination" : [ "obj-56", 0 ],
													"source" : [ "obj-10", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.986251831054688, 0.007236152887344, 0.027423052117229, 1.0 ],
													"destination" : [ "obj-56", 1 ],
													"source" : [ "obj-11", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-15", 0 ],
													"source" : [ "obj-12", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-14", 0 ],
													"source" : [ "obj-13", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-74", 0 ],
													"source" : [ "obj-14", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-24", 0 ],
													"source" : [ "obj-15", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-77", 0 ],
													"source" : [ "obj-19", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.0, 0.0, 0.0, 1.0 ],
													"destination" : [ "obj-31", 0 ],
													"midpoints" : [ 420.0, 169.0, 245.5, 169.0 ],
													"order" : 2,
													"source" : [ "obj-2", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.986251831054688, 0.007236152887344, 0.027423052117229, 1.0 ],
													"destination" : [ "obj-71", 1 ],
													"order" : 0,
													"source" : [ "obj-2", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.986251831054688, 0.007236152887344, 0.027423052117229, 1.0 ],
													"destination" : [ "obj-72", 0 ],
													"midpoints" : [ 420.0, 206.75, 322.166666666666686, 206.75 ],
													"order" : 1,
													"source" : [ "obj-2", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-19", 0 ],
													"source" : [ "obj-20", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-42", 0 ],
													"source" : [ "obj-21", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.131302371621132, 0.99969744682312, 0.023593800142407, 1.0 ],
													"destination" : [ "obj-56", 2 ],
													"midpoints" : [ 673.0, 577.5, 206.166666666666657, 577.5 ],
													"source" : [ "obj-24", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.986251831054688, 0.007236152887344, 0.027423052117229, 1.0 ],
													"destination" : [ "obj-31", 1 ],
													"source" : [ "obj-25", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.000066079199314, 0.001801013946533, 0.998228549957275, 1.0 ],
													"destination" : [ "obj-30", 1 ],
													"source" : [ "obj-26", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-40", 0 ],
													"source" : [ "obj-28", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-28", 0 ],
													"source" : [ "obj-29", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-11", 1 ],
													"source" : [ "obj-3", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-4", 0 ],
													"source" : [ "obj-30", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-5", 0 ],
													"source" : [ "obj-31", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-38", 0 ],
													"source" : [ "obj-32", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-32", 0 ],
													"source" : [ "obj-33", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-73", 0 ],
													"source" : [ "obj-36", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.0, 0.0, 0.0, 1.0 ],
													"destination" : [ "obj-30", 2 ],
													"midpoints" : [ 857.5, 808.5, 102.0, 808.5 ],
													"order" : 1,
													"source" : [ "obj-38", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.0, 0.0, 0.0, 1.0 ],
													"destination" : [ "obj-31", 2 ],
													"midpoints" : [ 857.5, 808.0, 295.5, 808.0 ],
													"order" : 0,
													"source" : [ "obj-38", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-45", 0 ],
													"source" : [ "obj-39", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.0, 0.0, 0.0, 1.0 ],
													"destination" : [ "obj-25", 1 ],
													"midpoints" : [ 760.5, 753.25, 286.5, 753.25 ],
													"order" : 0,
													"source" : [ "obj-40", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.0, 0.0, 0.0, 1.0 ],
													"destination" : [ "obj-26", 1 ],
													"midpoints" : [ 760.5, 753.25, 92.5, 753.25 ],
													"order" : 1,
													"source" : [ "obj-40", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-50", 0 ],
													"source" : [ "obj-42", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-42", 1 ],
													"source" : [ "obj-43", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-42", 2 ],
													"source" : [ "obj-44", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-39", 0 ],
													"source" : [ "obj-50", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.000066079199314, 0.001801013946533, 0.998228549957275, 1.0 ],
													"destination" : [ "obj-84", 0 ],
													"source" : [ "obj-56", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.986251831054688, 0.007236152887344, 0.027423052117229, 1.0 ],
													"destination" : [ "obj-85", 0 ],
													"source" : [ "obj-56", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.000066079199314, 0.001801013946533, 0.998228549957275, 1.0 ],
													"destination" : [ "obj-10", 0 ],
													"source" : [ "obj-58", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-56", 3 ],
													"source" : [ "obj-59", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-10", 1 ],
													"source" : [ "obj-6", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.000066079199314, 0.001801013946533, 0.998228549957275, 1.0 ],
													"destination" : [ "obj-64", 0 ],
													"order" : 1,
													"source" : [ "obj-60", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.000066079199314, 0.001801013946533, 0.998228549957275, 1.0 ],
													"destination" : [ "obj-65", 0 ],
													"order" : 0,
													"source" : [ "obj-60", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.60000091791153, 0.400011628866196, 0.200000643730164, 1.0 ],
													"destination" : [ "obj-58", 1 ],
													"order" : 3,
													"source" : [ "obj-63", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.60000091791153, 0.400011628866196, 0.200000643730164, 1.0 ],
													"destination" : [ "obj-60", 0 ],
													"order" : 2,
													"source" : [ "obj-63", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.60000091791153, 0.400011628866196, 0.200000643730164, 1.0 ],
													"destination" : [ "obj-71", 0 ],
													"order" : 0,
													"source" : [ "obj-63", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.60000091791153, 0.400011628866196, 0.200000643730164, 1.0 ],
													"destination" : [ "obj-72", 1 ],
													"order" : 1,
													"source" : [ "obj-63", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.000066079199314, 0.001801013946533, 0.998228549957275, 1.0 ],
													"destination" : [ "obj-10", 0 ],
													"source" : [ "obj-64", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.986251831054688, 0.007236152887344, 0.027423052117229, 1.0 ],
													"destination" : [ "obj-11", 0 ],
													"source" : [ "obj-65", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.986251831054688, 0.007236152887344, 0.027423052117229, 1.0 ],
													"destination" : [ "obj-64", 1 ],
													"order" : 1,
													"source" : [ "obj-71", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.986251831054688, 0.007236152887344, 0.027423052117229, 1.0 ],
													"destination" : [ "obj-65", 1 ],
													"order" : 0,
													"source" : [ "obj-71", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.986251831054688, 0.007236152887344, 0.027423052117229, 1.0 ],
													"destination" : [ "obj-11", 0 ],
													"midpoints" : [ 140.833333333333314, 421.25 ],
													"source" : [ "obj-72", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.0, 0.0, 0.0, 1.0 ],
													"destination" : [ "obj-58", 2 ],
													"midpoints" : [ 501.5, 287.25, 128.5, 287.25 ],
													"order" : 3,
													"source" : [ "obj-73", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.0, 0.0, 0.0, 1.0 ],
													"destination" : [ "obj-60", 2 ],
													"midpoints" : [ 501.5, 287.25, 187.833333333333314, 287.25 ],
													"order" : 2,
													"source" : [ "obj-73", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.0, 0.0, 0.0, 1.0 ],
													"destination" : [ "obj-71", 2 ],
													"midpoints" : [ 501.5, 312.25, 433.5, 312.25 ],
													"order" : 0,
													"source" : [ "obj-73", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.0, 0.0, 0.0, 1.0 ],
													"destination" : [ "obj-72", 2 ],
													"midpoints" : [ 501.5, 311.25, 377.166666666666686, 311.25 ],
													"order" : 1,
													"source" : [ "obj-73", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-76", 0 ],
													"source" : [ "obj-74", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-15", 1 ],
													"midpoints" : [ 966.5, 391.0, 729.0, 391.0 ],
													"order" : 3,
													"source" : [ "obj-75", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-28", 1 ],
													"midpoints" : [ 966.5, 508.5, 816.5, 508.5 ],
													"order" : 2,
													"source" : [ "obj-75", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-32", 1 ],
													"midpoints" : [ 966.5, 627.5, 966.5, 627.5 ],
													"order" : 0,
													"source" : [ "obj-75", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-39", 1 ],
													"midpoints" : [ 966.5, 250.5, 856.5, 250.5 ],
													"order" : 1,
													"source" : [ "obj-75", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-73", 1 ],
													"midpoints" : [ 966.5, 230.0, 557.5, 230.0 ],
													"order" : 6,
													"source" : [ "obj-75", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-74", 1 ],
													"midpoints" : [ 966.5, 126.0, 557.5, 126.0 ],
													"order" : 7,
													"source" : [ "obj-75", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-77", 1 ],
													"midpoints" : [ 966.5, 126.0, 710.5, 126.0 ],
													"order" : 4,
													"source" : [ "obj-75", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-90", 1 ],
													"midpoints" : [ 966.5, 319.5, 622.5, 319.5 ],
													"order" : 5,
													"source" : [ "obj-75", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-18", 0 ],
													"source" : [ "obj-77", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.990419030189514, 0.500286221504211, 0.032855235040188, 1.0 ],
													"destination" : [ "obj-84", 1 ],
													"midpoints" : [ 535.5, 677.75, 92.5, 677.75 ],
													"source" : [ "obj-78", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.990419030189514, 0.500286221504211, 0.032855235040188, 1.0 ],
													"destination" : [ "obj-85", 1 ],
													"midpoints" : [ 566.5, 677.75, 286.5, 677.75 ],
													"source" : [ "obj-79", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.000066079199314, 0.001801013946533, 0.998228549957275, 1.0 ],
													"destination" : [ "obj-26", 0 ],
													"source" : [ "obj-84", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.986251831054688, 0.007236152887344, 0.027423052117229, 1.0 ],
													"destination" : [ "obj-25", 0 ],
													"source" : [ "obj-85", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-90", 0 ],
													"source" : [ "obj-86", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.990419030189514, 0.500286221504211, 0.032855235040188, 1.0 ],
													"destination" : [ "obj-78", 0 ],
													"source" : [ "obj-88", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.990419030189514, 0.500286221504211, 0.032855235040188, 1.0 ],
													"destination" : [ "obj-79", 0 ],
													"order" : 0,
													"source" : [ "obj-90", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.990419030189514, 0.500286221504211, 0.032855235040188, 1.0 ],
													"destination" : [ "obj-88", 0 ],
													"order" : 1,
													"source" : [ "obj-90", 0 ]
												}

											}
 ]
									}
,
									"patching_rect" : [ 63.0, 468.0, 99.0, 22.0 ],
									"text" : "gen @title matriz"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-48",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1146.5, 249.0, 40.0, 22.0 ],
									"text" : "* 0.01"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-47",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1096.0, 195.0, 40.0, 22.0 ],
									"text" : "* 0.01"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-46",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1048.0, 139.0, 40.0, 22.0 ],
									"text" : "* 0.01"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.500002145767212, 0.000045299530029, 0.500004887580872, 1.0 ],
									"id" : "obj-33",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 2,
											"revision" : 2,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "dsp.gen",
										"rect" : [ 706.0, 148.0, 255.0, 303.0 ],
										"bglocked" : 0,
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 1,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 1,
										"objectsnaponopen" : 1,
										"statusbarvisible" : 2,
										"toolbarvisible" : 1,
										"lefttoolbarpinned" : 0,
										"toptoolbarpinned" : 0,
										"righttoolbarpinned" : 0,
										"bottomtoolbarpinned" : 0,
										"toolbars_unpinned_last_save" : 0,
										"tallnewobj" : 0,
										"boxanimatetime" : 200,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"description" : "",
										"digest" : "",
										"tags" : "",
										"style" : "",
										"subpatcher_template" : "",
										"assistshowspatchername" : 0,
										"boxes" : [ 											{
												"box" : 												{
													"id" : "obj-5",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 103.0, 263.0, 117.0, 20.0 ],
													"text" : "FILTRO DE 1 POLO"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-4",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 41.0, 112.0, 35.0, 20.0 ],
													"text" : "valor"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-27",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 136.0, 112.0, 31.0, 20.0 ],
													"text" : "coef"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-24",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 28.0, 247.0, 35.0, 22.0 ],
													"text" : "out 1"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-18",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 98.0, 187.0, 82.0, 22.0 ],
													"text" : "history"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-17",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 28.0, 134.0, 152.0, 22.0 ],
													"text" : "mix"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-3",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 161.0, 31.0, 45.0, 22.0 ],
													"text" : "f 0.999"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-1",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 28.0, 31.0, 30.0, 22.0 ],
													"text" : "in 1"
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 0 ],
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-18", 0 ],
													"midpoints" : [ 37.5, 170.0, 107.5, 170.0 ],
													"order" : 0,
													"source" : [ "obj-17", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-24", 0 ],
													"order" : 1,
													"source" : [ "obj-17", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 1 ],
													"midpoints" : [ 107.5, 237.0, 238.0, 237.0, 238.0, 85.0, 104.0, 85.0 ],
													"source" : [ "obj-18", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 2 ],
													"source" : [ "obj-3", 0 ]
												}

											}
 ],
										"editing_bgcolor" : [ 0.9, 0.9, 0.9, 1.0 ]
									}
,
									"patching_rect" : [ 1327.5, 527.0, 75.0, 22.0 ],
									"text" : "gen onepole"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-34",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1327.5, 491.0, 323.0, 22.0 ],
									"text" : "param @name h_SOLOHIGH @min 0 @max 1 @default 0"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.500002145767212, 0.000045299530029, 0.500004887580872, 1.0 ],
									"id" : "obj-31",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 2,
											"revision" : 2,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "dsp.gen",
										"rect" : [ 706.0, 148.0, 255.0, 303.0 ],
										"bglocked" : 0,
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 1,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 1,
										"objectsnaponopen" : 1,
										"statusbarvisible" : 2,
										"toolbarvisible" : 1,
										"lefttoolbarpinned" : 0,
										"toptoolbarpinned" : 0,
										"righttoolbarpinned" : 0,
										"bottomtoolbarpinned" : 0,
										"toolbars_unpinned_last_save" : 0,
										"tallnewobj" : 0,
										"boxanimatetime" : 200,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"description" : "",
										"digest" : "",
										"tags" : "",
										"style" : "",
										"subpatcher_template" : "",
										"assistshowspatchername" : 0,
										"boxes" : [ 											{
												"box" : 												{
													"id" : "obj-5",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 103.0, 263.0, 117.0, 20.0 ],
													"text" : "FILTRO DE 1 POLO"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-4",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 41.0, 112.0, 35.0, 20.0 ],
													"text" : "valor"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-27",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 136.0, 112.0, 31.0, 20.0 ],
													"text" : "coef"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-24",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 28.0, 247.0, 35.0, 22.0 ],
													"text" : "out 1"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-18",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 98.0, 187.0, 82.0, 22.0 ],
													"text" : "history"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-17",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 28.0, 134.0, 152.0, 22.0 ],
													"text" : "mix"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-3",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 161.0, 31.0, 45.0, 22.0 ],
													"text" : "f 0.999"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-1",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 28.0, 31.0, 30.0, 22.0 ],
													"text" : "in 1"
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 0 ],
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-18", 0 ],
													"midpoints" : [ 37.5, 170.0, 107.5, 170.0 ],
													"order" : 0,
													"source" : [ "obj-17", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-24", 0 ],
													"order" : 1,
													"source" : [ "obj-17", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 1 ],
													"midpoints" : [ 107.5, 237.0, 238.0, 237.0, 238.0, 85.0, 104.0, 85.0 ],
													"source" : [ "obj-18", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 2 ],
													"source" : [ "obj-3", 0 ]
												}

											}
 ],
										"editing_bgcolor" : [ 0.9, 0.9, 0.9, 1.0 ]
									}
,
									"patching_rect" : [ 1295.5, 443.0, 75.0, 22.0 ],
									"text" : "gen onepole"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-32",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1295.5, 407.0, 319.0, 22.0 ],
									"text" : "param @name g_SOLOMED @min 0 @max 1 @default 0"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.500002145767212, 0.000045299530029, 0.500004887580872, 1.0 ],
									"id" : "obj-19",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 2,
											"revision" : 2,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "dsp.gen",
										"rect" : [ 706.0, 148.0, 255.0, 303.0 ],
										"bglocked" : 0,
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 1,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 1,
										"objectsnaponopen" : 1,
										"statusbarvisible" : 2,
										"toolbarvisible" : 1,
										"lefttoolbarpinned" : 0,
										"toptoolbarpinned" : 0,
										"righttoolbarpinned" : 0,
										"bottomtoolbarpinned" : 0,
										"toolbars_unpinned_last_save" : 0,
										"tallnewobj" : 0,
										"boxanimatetime" : 200,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"description" : "",
										"digest" : "",
										"tags" : "",
										"style" : "",
										"subpatcher_template" : "",
										"assistshowspatchername" : 0,
										"boxes" : [ 											{
												"box" : 												{
													"id" : "obj-5",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 103.0, 263.0, 117.0, 20.0 ],
													"text" : "FILTRO DE 1 POLO"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-4",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 41.0, 112.0, 35.0, 20.0 ],
													"text" : "valor"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-27",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 136.0, 112.0, 31.0, 20.0 ],
													"text" : "coef"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-24",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 28.0, 247.0, 35.0, 22.0 ],
													"text" : "out 1"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-18",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 98.0, 187.0, 82.0, 22.0 ],
													"text" : "history"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-17",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 28.0, 134.0, 152.0, 22.0 ],
													"text" : "mix"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-3",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 161.0, 31.0, 45.0, 22.0 ],
													"text" : "f 0.999"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-1",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 28.0, 31.0, 30.0, 22.0 ],
													"text" : "in 1"
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 0 ],
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-18", 0 ],
													"midpoints" : [ 37.5, 170.0, 107.5, 170.0 ],
													"order" : 0,
													"source" : [ "obj-17", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-24", 0 ],
													"order" : 1,
													"source" : [ "obj-17", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 1 ],
													"midpoints" : [ 107.5, 237.0, 238.0, 237.0, 238.0, 85.0, 104.0, 85.0 ],
													"source" : [ "obj-18", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 2 ],
													"source" : [ "obj-3", 0 ]
												}

											}
 ],
										"editing_bgcolor" : [ 0.9, 0.9, 0.9, 1.0 ]
									}
,
									"patching_rect" : [ 1263.5, 365.0, 75.0, 22.0 ],
									"text" : "gen onepole"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-20",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1263.5, 329.0, 317.0, 22.0 ],
									"text" : "param @name f_SOLOLOW @min 0 @max 1 @default 0"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.500002145767212, 0.000045299530029, 0.500004887580872, 1.0 ],
									"id" : "obj-11",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 2,
											"revision" : 2,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "dsp.gen",
										"rect" : [ 706.0, 148.0, 255.0, 303.0 ],
										"bglocked" : 0,
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 1,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 1,
										"objectsnaponopen" : 1,
										"statusbarvisible" : 2,
										"toolbarvisible" : 1,
										"lefttoolbarpinned" : 0,
										"toptoolbarpinned" : 0,
										"righttoolbarpinned" : 0,
										"bottomtoolbarpinned" : 0,
										"toolbars_unpinned_last_save" : 0,
										"tallnewobj" : 0,
										"boxanimatetime" : 200,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"description" : "",
										"digest" : "",
										"tags" : "",
										"style" : "",
										"subpatcher_template" : "",
										"assistshowspatchername" : 0,
										"boxes" : [ 											{
												"box" : 												{
													"id" : "obj-5",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 103.0, 263.0, 117.0, 20.0 ],
													"text" : "FILTRO DE 1 POLO"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-4",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 41.0, 112.0, 35.0, 20.0 ],
													"text" : "valor"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-27",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 136.0, 112.0, 31.0, 20.0 ],
													"text" : "coef"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-24",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 28.0, 247.0, 35.0, 22.0 ],
													"text" : "out 1"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-18",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 98.0, 187.0, 82.0, 22.0 ],
													"text" : "history"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-17",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 28.0, 134.0, 152.0, 22.0 ],
													"text" : "mix"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-3",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 161.0, 31.0, 45.0, 22.0 ],
													"text" : "f 0.999"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-1",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 28.0, 31.0, 30.0, 22.0 ],
													"text" : "in 1"
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 0 ],
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-18", 0 ],
													"midpoints" : [ 37.5, 170.0, 107.5, 170.0 ],
													"order" : 0,
													"source" : [ "obj-17", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-24", 0 ],
													"order" : 1,
													"source" : [ "obj-17", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 1 ],
													"midpoints" : [ 107.5, 237.0, 238.0, 237.0, 238.0, 85.0, 104.0, 85.0 ],
													"source" : [ "obj-18", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 2 ],
													"source" : [ "obj-3", 0 ]
												}

											}
 ],
										"editing_bgcolor" : [ 0.9, 0.9, 0.9, 1.0 ]
									}
,
									"patching_rect" : [ 960.5, 48.0, 75.0, 22.0 ],
									"text" : "gen onepole"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-12",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 960.5, 12.0, 353.0, 22.0 ],
									"text" : "param @name b_FREQ2 @min 20 @max 20000 @default 5000"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.500002145767212, 0.000045299530029, 0.500004887580872, 1.0 ],
									"id" : "obj-10",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 2,
											"revision" : 2,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "dsp.gen",
										"rect" : [ 706.0, 148.0, 255.0, 303.0 ],
										"bglocked" : 0,
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 1,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 1,
										"objectsnaponopen" : 1,
										"statusbarvisible" : 2,
										"toolbarvisible" : 1,
										"lefttoolbarpinned" : 0,
										"toptoolbarpinned" : 0,
										"righttoolbarpinned" : 0,
										"bottomtoolbarpinned" : 0,
										"toolbars_unpinned_last_save" : 0,
										"tallnewobj" : 0,
										"boxanimatetime" : 200,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"description" : "",
										"digest" : "",
										"tags" : "",
										"style" : "",
										"subpatcher_template" : "",
										"assistshowspatchername" : 0,
										"boxes" : [ 											{
												"box" : 												{
													"id" : "obj-5",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 103.0, 263.0, 117.0, 20.0 ],
													"text" : "FILTRO DE 1 POLO"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-4",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 41.0, 112.0, 35.0, 20.0 ],
													"text" : "valor"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-27",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 136.0, 112.0, 31.0, 20.0 ],
													"text" : "coef"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-24",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 28.0, 247.0, 35.0, 22.0 ],
													"text" : "out 1"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-18",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 98.0, 187.0, 82.0, 22.0 ],
													"text" : "history"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-17",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 28.0, 134.0, 152.0, 22.0 ],
													"text" : "mix"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-3",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 161.0, 31.0, 45.0, 22.0 ],
													"text" : "f 0.999"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-1",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 28.0, 31.0, 30.0, 22.0 ],
													"text" : "in 1"
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 0 ],
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-18", 0 ],
													"midpoints" : [ 37.5, 170.0, 107.5, 170.0 ],
													"order" : 0,
													"source" : [ "obj-17", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-24", 0 ],
													"order" : 1,
													"source" : [ "obj-17", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 1 ],
													"midpoints" : [ 107.5, 237.0, 238.0, 237.0, 238.0, 85.0, 104.0, 85.0 ],
													"source" : [ "obj-18", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 2 ],
													"source" : [ "obj-3", 0 ]
												}

											}
 ],
										"editing_bgcolor" : [ 0.9, 0.9, 0.9, 1.0 ]
									}
,
									"patching_rect" : [ 1146.5, 221.0, 75.0, 22.0 ],
									"text" : "gen onepole"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.500002145767212, 0.000045299530029, 0.500004887580872, 1.0 ],
									"id" : "obj-9",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 2,
											"revision" : 2,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "dsp.gen",
										"rect" : [ 706.0, 148.0, 255.0, 303.0 ],
										"bglocked" : 0,
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 1,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 1,
										"objectsnaponopen" : 1,
										"statusbarvisible" : 2,
										"toolbarvisible" : 1,
										"lefttoolbarpinned" : 0,
										"toptoolbarpinned" : 0,
										"righttoolbarpinned" : 0,
										"bottomtoolbarpinned" : 0,
										"toolbars_unpinned_last_save" : 0,
										"tallnewobj" : 0,
										"boxanimatetime" : 200,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"description" : "",
										"digest" : "",
										"tags" : "",
										"style" : "",
										"subpatcher_template" : "",
										"assistshowspatchername" : 0,
										"boxes" : [ 											{
												"box" : 												{
													"id" : "obj-5",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 103.0, 263.0, 117.0, 20.0 ],
													"text" : "FILTRO DE 1 POLO"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-4",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 41.0, 112.0, 35.0, 20.0 ],
													"text" : "valor"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-27",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 136.0, 112.0, 31.0, 20.0 ],
													"text" : "coef"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-24",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 28.0, 247.0, 35.0, 22.0 ],
													"text" : "out 1"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-18",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 98.0, 187.0, 82.0, 22.0 ],
													"text" : "history"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-17",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 28.0, 134.0, 152.0, 22.0 ],
													"text" : "mix"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-3",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 161.0, 31.0, 45.0, 22.0 ],
													"text" : "f 0.999"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-1",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 28.0, 31.0, 30.0, 22.0 ],
													"text" : "in 1"
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 0 ],
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-18", 0 ],
													"midpoints" : [ 37.5, 170.0, 107.5, 170.0 ],
													"order" : 0,
													"source" : [ "obj-17", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-24", 0 ],
													"order" : 1,
													"source" : [ "obj-17", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 1 ],
													"midpoints" : [ 107.5, 237.0, 238.0, 237.0, 238.0, 85.0, 104.0, 85.0 ],
													"source" : [ "obj-18", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 2 ],
													"source" : [ "obj-3", 0 ]
												}

											}
 ],
										"editing_bgcolor" : [ 0.9, 0.9, 0.9, 1.0 ]
									}
,
									"patching_rect" : [ 1096.0, 167.0, 75.0, 22.0 ],
									"text" : "gen onepole"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.500002145767212, 0.000045299530029, 0.500004887580872, 1.0 ],
									"id" : "obj-8",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 2,
											"revision" : 2,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "dsp.gen",
										"rect" : [ 706.0, 148.0, 255.0, 303.0 ],
										"bglocked" : 0,
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 1,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 1,
										"objectsnaponopen" : 1,
										"statusbarvisible" : 2,
										"toolbarvisible" : 1,
										"lefttoolbarpinned" : 0,
										"toptoolbarpinned" : 0,
										"righttoolbarpinned" : 0,
										"bottomtoolbarpinned" : 0,
										"toolbars_unpinned_last_save" : 0,
										"tallnewobj" : 0,
										"boxanimatetime" : 200,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"description" : "",
										"digest" : "",
										"tags" : "",
										"style" : "",
										"subpatcher_template" : "",
										"assistshowspatchername" : 0,
										"boxes" : [ 											{
												"box" : 												{
													"id" : "obj-5",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 103.0, 263.0, 117.0, 20.0 ],
													"text" : "FILTRO DE 1 POLO"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-4",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 41.0, 112.0, 35.0, 20.0 ],
													"text" : "valor"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-27",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 136.0, 112.0, 31.0, 20.0 ],
													"text" : "coef"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-24",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 28.0, 247.0, 35.0, 22.0 ],
													"text" : "out 1"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-18",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 98.0, 187.0, 82.0, 22.0 ],
													"text" : "history"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-17",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 28.0, 134.0, 152.0, 22.0 ],
													"text" : "mix"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-3",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 161.0, 31.0, 45.0, 22.0 ],
													"text" : "f 0.999"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-1",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 28.0, 31.0, 30.0, 22.0 ],
													"text" : "in 1"
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 0 ],
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-18", 0 ],
													"midpoints" : [ 37.5, 170.0, 107.5, 170.0 ],
													"order" : 0,
													"source" : [ "obj-17", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-24", 0 ],
													"order" : 1,
													"source" : [ "obj-17", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 1 ],
													"midpoints" : [ 107.5, 237.0, 238.0, 237.0, 238.0, 85.0, 104.0, 85.0 ],
													"source" : [ "obj-18", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 2 ],
													"source" : [ "obj-3", 0 ]
												}

											}
 ],
										"editing_bgcolor" : [ 0.9, 0.9, 0.9, 1.0 ]
									}
,
									"patching_rect" : [ 1048.0, 110.0, 75.0, 22.0 ],
									"text" : "gen onepole"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.500002145767212, 0.000045299530029, 0.500004887580872, 1.0 ],
									"id" : "obj-7",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 2,
											"revision" : 2,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "dsp.gen",
										"rect" : [ 706.0, 148.0, 255.0, 303.0 ],
										"bglocked" : 0,
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 1,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 1,
										"objectsnaponopen" : 1,
										"statusbarvisible" : 2,
										"toolbarvisible" : 1,
										"lefttoolbarpinned" : 0,
										"toptoolbarpinned" : 0,
										"righttoolbarpinned" : 0,
										"bottomtoolbarpinned" : 0,
										"toolbars_unpinned_last_save" : 0,
										"tallnewobj" : 0,
										"boxanimatetime" : 200,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"description" : "",
										"digest" : "",
										"tags" : "",
										"style" : "",
										"subpatcher_template" : "",
										"assistshowspatchername" : 0,
										"boxes" : [ 											{
												"box" : 												{
													"id" : "obj-5",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 103.0, 263.0, 117.0, 20.0 ],
													"text" : "FILTRO DE 1 POLO"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-4",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 41.0, 112.0, 35.0, 20.0 ],
													"text" : "valor"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-27",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 136.0, 112.0, 31.0, 20.0 ],
													"text" : "coef"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-24",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 28.0, 247.0, 35.0, 22.0 ],
													"text" : "out 1"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-18",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 98.0, 187.0, 82.0, 22.0 ],
													"text" : "history"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-17",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 28.0, 134.0, 152.0, 22.0 ],
													"text" : "mix"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-3",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 161.0, 31.0, 45.0, 22.0 ],
													"text" : "f 0.999"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-1",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 28.0, 31.0, 30.0, 22.0 ],
													"text" : "in 1"
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 0 ],
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-18", 0 ],
													"midpoints" : [ 37.5, 170.0, 107.5, 170.0 ],
													"order" : 0,
													"source" : [ "obj-17", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-24", 0 ],
													"order" : 1,
													"source" : [ "obj-17", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 1 ],
													"midpoints" : [ 107.5, 237.0, 238.0, 237.0, 238.0, 85.0, 104.0, 85.0 ],
													"source" : [ "obj-18", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 2 ],
													"source" : [ "obj-3", 0 ]
												}

											}
 ],
										"editing_bgcolor" : [ 0.9, 0.9, 0.9, 1.0 ]
									}
,
									"patching_rect" : [ 597.5, 48.0, 75.0, 22.0 ],
									"text" : "gen onepole"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.500002145767212, 0.000045299530029, 0.500004887580872, 1.0 ],
									"id" : "obj-6",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 2,
											"revision" : 2,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "dsp.gen",
										"rect" : [ 706.0, 148.0, 255.0, 303.0 ],
										"bglocked" : 0,
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 1,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 1,
										"objectsnaponopen" : 1,
										"statusbarvisible" : 2,
										"toolbarvisible" : 1,
										"lefttoolbarpinned" : 0,
										"toptoolbarpinned" : 0,
										"righttoolbarpinned" : 0,
										"bottomtoolbarpinned" : 0,
										"toolbars_unpinned_last_save" : 0,
										"tallnewobj" : 0,
										"boxanimatetime" : 200,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"description" : "",
										"digest" : "",
										"tags" : "",
										"style" : "",
										"subpatcher_template" : "",
										"assistshowspatchername" : 0,
										"boxes" : [ 											{
												"box" : 												{
													"id" : "obj-5",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 103.0, 263.0, 117.0, 20.0 ],
													"text" : "FILTRO DE 1 POLO"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-4",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 41.0, 112.0, 35.0, 20.0 ],
													"text" : "valor"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-27",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 136.0, 112.0, 31.0, 20.0 ],
													"text" : "coef"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-24",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 28.0, 247.0, 35.0, 22.0 ],
													"text" : "out 1"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-18",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 98.0, 187.0, 82.0, 22.0 ],
													"text" : "history"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-17",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 28.0, 134.0, 152.0, 22.0 ],
													"text" : "mix"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-3",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 161.0, 31.0, 45.0, 22.0 ],
													"text" : "f 0.999"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-1",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 28.0, 31.0, 30.0, 22.0 ],
													"text" : "in 1"
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 0 ],
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-18", 0 ],
													"midpoints" : [ 37.5, 170.0, 107.5, 170.0 ],
													"order" : 0,
													"source" : [ "obj-17", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-24", 0 ],
													"order" : 1,
													"source" : [ "obj-17", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 1 ],
													"midpoints" : [ 107.5, 237.0, 238.0, 237.0, 238.0, 85.0, 104.0, 85.0 ],
													"source" : [ "obj-18", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-17", 2 ],
													"source" : [ "obj-3", 0 ]
												}

											}
 ],
										"editing_bgcolor" : [ 0.9, 0.9, 0.9, 1.0 ]
									}
,
									"patching_rect" : [ 1307.0, 706.0, 75.0, 22.0 ],
									"text" : "gen onepole"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-5",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1307.0, 732.0, 26.0, 22.0 ],
									"text" : "!- 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-3",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 35.0, 794.0, 85.0, 22.0 ],
									"text" : "mix"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-2",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 359.5, 794.0, 88.0, 22.0 ],
									"text" : "mix"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1307.0, 670.0, 302.0, 22.0 ],
									"text" : "param @name i_BYPASS @min 0 @max 1 @default 0"
								}

							}
, 							{
								"box" : 								{
									"fontsize" : 35.0,
									"id" : "obj-112",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 370.0, 810.0, 38.0, 46.0 ],
									"text" : "R"
								}

							}
, 							{
								"box" : 								{
									"fontsize" : 35.0,
									"id" : "obj-111",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 48.0, 810.0, 38.0, 46.0 ],
									"text" : "L"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-107",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1096.0, 229.0, 26.0, 22.0 ],
									"text" : "!- 2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-108",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1096.0, 141.0, 313.0, 22.0 ],
									"text" : "param @name d_MED @min 0 @max 200 @default 100"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-106",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1146.5, 281.0, 26.0, 22.0 ],
									"text" : "!- 2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-105",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1048.0, 177.0, 26.0, 22.0 ],
									"text" : "!- 2"
								}

							}
, 							{
								"box" : 								{
									"fontsize" : 35.0,
									"id" : "obj-50",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 453.0, 12.0, 38.0, 46.0 ],
									"text" : "R"
								}

							}
, 							{
								"box" : 								{
									"fontsize" : 35.0,
									"id" : "obj-49",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 98.0, 12.0, 38.0, 46.0 ],
									"text" : "L"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-29",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1146.5, 195.0, 316.0, 22.0 ],
									"text" : "param @name e_HIGH @min 0 @max 200 @default 100"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-26",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1048.0, 83.0, 313.0, 22.0 ],
									"text" : "param @name c_LOW @min 0 @max 200 @default 100"
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
									"patching_rect" : [ 420.5, 19.0, 28.0, 22.0 ],
									"text" : "in 2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-21",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 2,
											"revision" : 2,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "dsp.gen",
										"rect" : [ 312.0, 157.0, 889.0, 603.0 ],
										"bglocked" : 0,
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 1,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 1,
										"objectsnaponopen" : 1,
										"statusbarvisible" : 2,
										"toolbarvisible" : 1,
										"lefttoolbarpinned" : 0,
										"toptoolbarpinned" : 0,
										"righttoolbarpinned" : 0,
										"bottomtoolbarpinned" : 0,
										"toolbars_unpinned_last_save" : 0,
										"tallnewobj" : 0,
										"boxanimatetime" : 200,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"description" : "",
										"digest" : "",
										"tags" : "",
										"style" : "",
										"subpatcher_template" : "",
										"assistshowspatchername" : 0,
										"boxes" : [ 											{
												"box" : 												{
													"id" : "obj-20",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 728.5, 524.0, 108.0, 20.0 ],
													"text" : "Graham Wakefield"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-43",
													"linecount" : 5,
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 544.5, 398.5, 228.0, 74.0 ],
													"text" : "2nd stage splits the lowshelf again into 2nd lowshelf + phase-matched corresponding highpass\nAlso applies same allpass to the first highpass to keep it in phase"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-42",
													"linecount" : 2,
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 544.5, 274.5, 228.0, 33.0 ],
													"text" : "1st stage splits to lowshelf & phase-matched corresponding highpass"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-41",
													"linecount" : 2,
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 428.0, 127.5, 165.0, 33.0 ],
													"text" : "Set the lower & upper frequencies of the shelf filters"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-40",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 395.0, 150.0, 29.5, 22.0 ],
													"text" : "min"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-39",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 253.0, 150.0, 31.0, 22.0 ],
													"text" : "max"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-38",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 59.0, 106.0, 640.0, 480.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-35",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 246.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-34",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 216.5, 32.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-31",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 181.5, 32.5, 22.0 ],
																	"text" : "-"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-30",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 65.0, 151.5, 32.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-26",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 95.0, 111.5, 46.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-3",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 40.0, 28.0, 22.0 ],
																	"text" : "in 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-4",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 83.0, 40.0, 28.0, 22.0 ],
																	"text" : "in 2"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-15",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 50.0, 328.5, 35.0, 22.0 ],
																	"text" : "out 1"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-30", 0 ],
																	"midpoints" : [ 104.5, 139.5, 74.5, 139.5 ],
																	"order" : 1,
																	"source" : [ "obj-26", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-35", 1 ],
																	"midpoints" : [ 104.5, 239.5, 73.0, 239.5 ],
																	"order" : 0,
																	"source" : [ "obj-26", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-31", 0 ],
																	"source" : [ "obj-3", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-31", 1 ],
																	"source" : [ "obj-30", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-26", 0 ],
																	"midpoints" : [ 59.5, 213.5, 184.5, 213.5, 184.5, 101.5, 104.5, 101.5 ],
																	"order" : 0,
																	"source" : [ "obj-31", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-34", 0 ],
																	"order" : 1,
																	"source" : [ "obj-31", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-35", 0 ],
																	"source" : [ "obj-34", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-15", 0 ],
																	"source" : [ "obj-35", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-30", 1 ],
																	"order" : 0,
																	"source" : [ "obj-4", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-34", 1 ],
																	"order" : 1,
																	"source" : [ "obj-4", 0 ]
																}

															}
 ]
													}
,
													"patching_rect" : [ 284.0, 398.5, 103.0, 22.0 ],
													"text" : "gen @title allpass"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-34",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 109.0, 128.0, 267.0, 628.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-1",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 135.0, 497.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-2",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 468.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-3",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 426.5, 32.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-4",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 391.5, 32.5, 22.0 ],
																	"text" : "-"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-5",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 128.25, 345.5, 46.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-50",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 135.0, 260.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-40",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 231.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-38",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 189.5, 32.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-37",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 154.5, 32.5, 22.0 ],
																	"text" : "-"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-27",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 128.25, 108.5, 46.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-17",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 40.0, 28.0, 22.0 ],
																	"text" : "in 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-18",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 89.0, 40.0, 57.0, 22.0 ],
																	"text" : "in 2 coeff"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-21",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 50.0, 575.0, 35.0, 22.0 ],
																	"text" : "out 1"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-5", 0 ],
																	"midpoints" : [ 144.5, 528.5, 206.5, 528.5, 206.5, 337.5, 137.75, 337.5 ],
																	"source" : [ "obj-1", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-37", 0 ],
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"color" : [ 0.447058823529412, 0.125490196078431, 0.125490196078431, 1.0 ],
																	"destination" : [ "obj-3", 1 ],
																	"midpoints" : [ 98.5, 421.75, 73.0, 421.75 ],
																	"order" : 0,
																	"source" : [ "obj-18", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"color" : [ 0.447058823529412, 0.125490196078431, 0.125490196078431, 1.0 ],
																	"destination" : [ "obj-38", 1 ],
																	"midpoints" : [ 98.5, 183.25, 73.0, 183.25 ],
																	"order" : 1,
																	"source" : [ "obj-18", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-1", 0 ],
																	"midpoints" : [ 59.5, 493.0, 144.5, 493.0 ],
																	"order" : 0,
																	"source" : [ "obj-2", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-21", 0 ],
																	"order" : 1,
																	"source" : [ "obj-2", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-37", 1 ],
																	"midpoints" : [ 137.75, 141.5, 73.0, 141.5 ],
																	"order" : 1,
																	"source" : [ "obj-27", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-40", 1 ],
																	"midpoints" : [ 137.75, 223.5, 73.0, 223.5 ],
																	"order" : 0,
																	"source" : [ "obj-27", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-1", 1 ],
																	"midpoints" : [ 59.5, 455.0, 158.0, 455.0 ],
																	"order" : 0,
																	"source" : [ "obj-3", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-2", 0 ],
																	"order" : 1,
																	"source" : [ "obj-3", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-38", 0 ],
																	"source" : [ "obj-37", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-40", 0 ],
																	"order" : 1,
																	"source" : [ "obj-38", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-50", 1 ],
																	"midpoints" : [ 59.5, 218.0, 158.0, 218.0 ],
																	"order" : 0,
																	"source" : [ "obj-38", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-3", 0 ],
																	"source" : [ "obj-4", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-4", 0 ],
																	"order" : 1,
																	"source" : [ "obj-40", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-50", 0 ],
																	"midpoints" : [ 59.5, 256.0, 144.5, 256.0 ],
																	"order" : 0,
																	"source" : [ "obj-40", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-2", 1 ],
																	"midpoints" : [ 137.75, 460.5, 73.0, 460.5 ],
																	"order" : 0,
																	"source" : [ "obj-5", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-4", 1 ],
																	"midpoints" : [ 137.75, 378.5, 73.0, 378.5 ],
																	"order" : 1,
																	"source" : [ "obj-5", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-27", 0 ],
																	"midpoints" : [ 144.5, 291.5, 206.5, 291.5, 206.5, 100.5, 137.75, 100.5 ],
																	"source" : [ "obj-50", 0 ]
																}

															}
 ]
													}
,
													"patching_rect" : [ 24.5, 398.5, 116.0, 22.0 ],
													"text" : "gen @title lowshelf2"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-35",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 59.0, 106.0, 640.0, 480.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-35",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 246.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-34",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 216.5, 32.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-31",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 181.5, 32.5, 22.0 ],
																	"text" : "-"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-30",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 65.0, 151.5, 32.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-26",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 95.0, 111.5, 46.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-3",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 40.0, 28.0, 22.0 ],
																	"text" : "in 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-4",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 83.0, 40.0, 28.0, 22.0 ],
																	"text" : "in 2"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-15",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 50.0, 328.5, 35.0, 22.0 ],
																	"text" : "out 1"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-30", 0 ],
																	"midpoints" : [ 104.5, 139.5, 74.5, 139.5 ],
																	"order" : 1,
																	"source" : [ "obj-26", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-35", 1 ],
																	"midpoints" : [ 104.5, 239.5, 73.0, 239.5 ],
																	"order" : 0,
																	"source" : [ "obj-26", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-31", 0 ],
																	"source" : [ "obj-3", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-31", 1 ],
																	"source" : [ "obj-30", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-26", 0 ],
																	"midpoints" : [ 59.5, 213.5, 184.5, 213.5, 184.5, 101.5, 104.5, 101.5 ],
																	"order" : 0,
																	"source" : [ "obj-31", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-34", 0 ],
																	"order" : 1,
																	"source" : [ "obj-31", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-35", 0 ],
																	"source" : [ "obj-34", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-15", 0 ],
																	"source" : [ "obj-35", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-30", 1 ],
																	"order" : 0,
																	"source" : [ "obj-4", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-34", 1 ],
																	"order" : 1,
																	"source" : [ "obj-4", 0 ]
																}

															}
 ]
													}
,
													"patching_rect" : [ 155.0, 398.5, 103.0, 22.0 ],
													"text" : "gen @title allpass"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-36",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 155.0, 450.5, 32.5, 22.0 ],
													"text" : "-"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-33",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 155.0, 506.0, 58.0, 22.0 ],
													"text" : "out 2 mid"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-31",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 109.0, 128.0, 473.0, 430.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-24",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 309.5, 36.0, 22.0 ],
																	"text" : "* 0.5"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-23",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 279.5, 28.0, 22.0 ],
																	"text" : "+ 1"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-20",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 232.5, 32.5, 22.0 ],
																	"text" : "/"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-19",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 202.5, 28.0, 22.0 ],
																	"text" : "- 1."
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-14",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 155.5, 172.5, 30.0, 22.0 ],
																	"text" : "cos"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-13",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 172.5, 26.0, 22.0 ],
																	"text" : "sin"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-12",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 230.5, 126.5, 119.0, 20.0 ],
																	"text" : "radians per sample"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-10",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 126.5, 107.0, 22.0 ],
																	"text" : "* twopi/samplerate"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-26",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 96.0, 44.0, 22.0 ],
																	"text" : "in 1 hz"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-27",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 121.5, 339.5, 89.0, 22.0 ],
																	"text" : "out 1 lowpass2"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-28",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 219.0, 339.5, 76.0, 22.0 ],
																	"text" : "out 2 allpass"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-13", 0 ],
																	"midpoints" : [ 131.0, 166.0, 131.0, 166.0 ],
																	"order" : 1,
																	"source" : [ "obj-10", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-14", 0 ],
																	"midpoints" : [ 131.0, 166.0, 165.0, 166.0 ],
																	"order" : 0,
																	"source" : [ "obj-10", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-19", 0 ],
																	"source" : [ "obj-13", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-20", 1 ],
																	"midpoints" : [ 165.0, 224.0, 144.5, 224.0 ],
																	"source" : [ "obj-14", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-20", 0 ],
																	"source" : [ "obj-19", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-23", 0 ],
																	"midpoints" : [ 131.0, 263.0, 131.0, 263.0 ],
																	"order" : 1,
																	"source" : [ "obj-20", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-28", 0 ],
																	"midpoints" : [ 131.0, 266.0, 228.5, 266.0 ],
																	"order" : 0,
																	"source" : [ "obj-20", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-24", 0 ],
																	"source" : [ "obj-23", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-27", 0 ],
																	"source" : [ "obj-24", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-10", 0 ],
																	"source" : [ "obj-26", 0 ]
																}

															}
 ]
													}
,
													"patching_rect" : [ 395.0, 180.0, 134.0, 22.0 ],
													"text" : "gen @title xover_coeffs"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-32",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 405.5, 99.5, 296.0, 22.0 ],
													"text" : "in 3 freq2 @default 4000 @min 1 @max samplerate/2"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-30",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 109.0, 128.0, 473.0, 430.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-24",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 309.5, 36.0, 22.0 ],
																	"text" : "* 0.5"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-23",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 279.5, 28.0, 22.0 ],
																	"text" : "+ 1"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-20",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 232.5, 32.5, 22.0 ],
																	"text" : "/"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-19",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 202.5, 28.0, 22.0 ],
																	"text" : "- 1."
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-14",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 155.5, 172.5, 30.0, 22.0 ],
																	"text" : "cos"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-13",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 172.5, 26.0, 22.0 ],
																	"text" : "sin"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-12",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 230.5, 126.5, 119.0, 20.0 ],
																	"text" : "radians per sample"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-10",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 126.5, 107.0, 22.0 ],
																	"text" : "* twopi/samplerate"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-26",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 96.0, 44.0, 22.0 ],
																	"text" : "in 1 hz"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-27",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 121.5, 339.5, 89.0, 22.0 ],
																	"text" : "out 1 lowpass2"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-28",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 219.0, 339.5, 76.0, 22.0 ],
																	"text" : "out 2 allpass"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-13", 0 ],
																	"midpoints" : [ 131.0, 166.0, 131.0, 166.0 ],
																	"order" : 1,
																	"source" : [ "obj-10", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-14", 0 ],
																	"midpoints" : [ 131.0, 166.0, 165.0, 166.0 ],
																	"order" : 0,
																	"source" : [ "obj-10", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-19", 0 ],
																	"source" : [ "obj-13", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-20", 1 ],
																	"midpoints" : [ 165.0, 224.0, 144.5, 224.0 ],
																	"source" : [ "obj-14", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-20", 0 ],
																	"source" : [ "obj-19", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-23", 0 ],
																	"midpoints" : [ 131.0, 263.0, 131.0, 263.0 ],
																	"order" : 1,
																	"source" : [ "obj-20", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-28", 0 ],
																	"midpoints" : [ 131.0, 266.0, 228.5, 266.0 ],
																	"order" : 0,
																	"source" : [ "obj-20", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-24", 0 ],
																	"source" : [ "obj-23", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-27", 0 ],
																	"source" : [ "obj-24", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-10", 0 ],
																	"source" : [ "obj-26", 0 ]
																}

															}
 ]
													}
,
													"patching_rect" : [ 253.0, 180.0, 134.0, 22.0 ],
													"text" : "gen @title xover_coeffs"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-22",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 109.0, 128.0, 267.0, 628.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-1",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 135.0, 497.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-2",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 468.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-3",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 426.5, 32.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-4",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 391.5, 32.5, 22.0 ],
																	"text" : "-"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-5",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 128.25, 345.5, 46.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-50",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 135.0, 260.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-40",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 231.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-38",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 189.5, 32.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-37",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 154.5, 32.5, 22.0 ],
																	"text" : "-"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-27",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 128.25, 108.5, 46.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-17",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 40.0, 28.0, 22.0 ],
																	"text" : "in 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-18",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 89.0, 40.0, 57.0, 22.0 ],
																	"text" : "in 2 coeff"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-21",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 50.0, 575.0, 35.0, 22.0 ],
																	"text" : "out 1"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-5", 0 ],
																	"midpoints" : [ 144.5, 528.5, 206.5, 528.5, 206.5, 337.5, 137.75, 337.5 ],
																	"source" : [ "obj-1", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-37", 0 ],
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"color" : [ 0.447058823529412, 0.125490196078431, 0.125490196078431, 1.0 ],
																	"destination" : [ "obj-3", 1 ],
																	"midpoints" : [ 98.5, 421.75, 73.0, 421.75 ],
																	"order" : 0,
																	"source" : [ "obj-18", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"color" : [ 0.447058823529412, 0.125490196078431, 0.125490196078431, 1.0 ],
																	"destination" : [ "obj-38", 1 ],
																	"midpoints" : [ 98.5, 183.25, 73.0, 183.25 ],
																	"order" : 1,
																	"source" : [ "obj-18", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-1", 0 ],
																	"midpoints" : [ 59.5, 493.0, 144.5, 493.0 ],
																	"order" : 0,
																	"source" : [ "obj-2", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-21", 0 ],
																	"order" : 1,
																	"source" : [ "obj-2", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-37", 1 ],
																	"midpoints" : [ 137.75, 141.5, 73.0, 141.5 ],
																	"order" : 1,
																	"source" : [ "obj-27", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-40", 1 ],
																	"midpoints" : [ 137.75, 223.5, 73.0, 223.5 ],
																	"order" : 0,
																	"source" : [ "obj-27", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-1", 1 ],
																	"midpoints" : [ 59.5, 455.0, 158.0, 455.0 ],
																	"order" : 0,
																	"source" : [ "obj-3", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-2", 0 ],
																	"order" : 1,
																	"source" : [ "obj-3", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-38", 0 ],
																	"source" : [ "obj-37", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-40", 0 ],
																	"order" : 1,
																	"source" : [ "obj-38", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-50", 1 ],
																	"midpoints" : [ 59.5, 218.0, 158.0, 218.0 ],
																	"order" : 0,
																	"source" : [ "obj-38", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-3", 0 ],
																	"source" : [ "obj-4", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-4", 0 ],
																	"order" : 1,
																	"source" : [ "obj-40", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-50", 0 ],
																	"midpoints" : [ 59.5, 256.0, 144.5, 256.0 ],
																	"order" : 0,
																	"source" : [ "obj-40", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-2", 1 ],
																	"midpoints" : [ 137.75, 460.5, 73.0, 460.5 ],
																	"order" : 0,
																	"source" : [ "obj-5", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-4", 1 ],
																	"midpoints" : [ 137.75, 378.5, 73.0, 378.5 ],
																	"order" : 1,
																	"source" : [ "obj-5", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-27", 0 ],
																	"midpoints" : [ 144.5, 291.5, 206.5, 291.5, 206.5, 100.5, 137.75, 100.5 ],
																	"source" : [ "obj-50", 0 ]
																}

															}
 ]
													}
,
													"patching_rect" : [ 24.5, 273.5, 116.0, 22.0 ],
													"text" : "gen @title lowshelf2"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-16",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 1065.0, 317.0, 353.0, 434.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-35",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 324.5, 158.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-34",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 270.5, 101.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-31",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 207.5, 47.5, 22.0 ],
																	"text" : "-"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-30",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 78.5, 161.5, 44.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-26",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 190.0, 36.5, 46.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-3",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 40.0, 28.0, 22.0 ],
																	"text" : "in 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-4",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 136.0, 40.0, 28.0, 22.0 ],
																	"text" : "in 2"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-15",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 48.75, 366.5, 35.0, 22.0 ],
																	"text" : "out 1"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-30", 0 ],
																	"midpoints" : [ 199.5, 139.5, 88.0, 139.5 ],
																	"order" : 1,
																	"source" : [ "obj-26", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-35", 1 ],
																	"midpoints" : [ 199.5, 316.5, 199.0, 316.5 ],
																	"order" : 0,
																	"source" : [ "obj-26", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-31", 0 ],
																	"source" : [ "obj-3", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-31", 1 ],
																	"source" : [ "obj-30", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-26", 0 ],
																	"midpoints" : [ 59.5, 249.5, 296.5, 249.5, 296.5, 16.5, 199.5, 16.5 ],
																	"order" : 0,
																	"source" : [ "obj-31", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-34", 0 ],
																	"order" : 1,
																	"source" : [ "obj-31", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-35", 0 ],
																	"source" : [ "obj-34", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-15", 0 ],
																	"source" : [ "obj-35", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-30", 1 ],
																	"order" : 1,
																	"source" : [ "obj-4", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-34", 1 ],
																	"order" : 0,
																	"source" : [ "obj-4", 0 ]
																}

															}
 ]
													}
,
													"patching_rect" : [ 284.0, 274.5, 103.0, 22.0 ],
													"text" : "gen @title allpass"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-29",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 284.0, 326.0, 32.5, 22.0 ],
													"text" : "-"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-1",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 253.0, 68.5, 289.0, 22.0 ],
													"text" : "in 2 freq1 @default 400 @min 1 @max samplerate/2"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-9",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 284.0, 506.0, 61.0, 22.0 ],
													"text" : "out 3 high"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-8",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 24.5, 25.0, 306.0, 20.0 ],
													"text" : "A 2-stage crossover filter"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-6",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 24.5, 506.0, 57.0, 22.0 ],
													"text" : "out 1 low"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-5",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 24.5, 68.5, 127.0, 22.0 ],
													"text" : "in 1 @comment input"
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-39", 0 ],
													"order" : 1,
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-40", 0 ],
													"order" : 0,
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-29", 0 ],
													"source" : [ "obj-16", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-29", 1 ],
													"midpoints" : [ 34.0, 311.0, 307.0, 311.0 ],
													"order" : 0,
													"source" : [ "obj-22", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-34", 0 ],
													"order" : 2,
													"source" : [ "obj-22", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-35", 0 ],
													"midpoints" : [ 34.0, 353.0, 164.5, 353.0 ],
													"order" : 1,
													"source" : [ "obj-22", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-38", 0 ],
													"source" : [ "obj-29", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.992156862745098, 0.776470588235294, 0.533333333333333, 1.0 ],
													"destination" : [ "obj-16", 1 ],
													"source" : [ "obj-30", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.996078431372549, 0.517647058823529, 0.517647058823529, 1.0 ],
													"destination" : [ "obj-22", 1 ],
													"midpoints" : [ 262.5, 261.25, 131.0, 261.25 ],
													"source" : [ "obj-30", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.52156862745098, 0.525490196078431, 0.996078431372549, 1.0 ],
													"destination" : [ "obj-34", 1 ],
													"midpoints" : [ 404.5, 376.25, 131.0, 376.25 ],
													"source" : [ "obj-31", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.952941176470588, 0.486274509803922, 0.996078431372549, 1.0 ],
													"destination" : [ "obj-35", 1 ],
													"midpoints" : [ 519.5, 384.25, 248.5, 384.25 ],
													"order" : 1,
													"source" : [ "obj-31", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.952941176470588, 0.486274509803922, 0.996078431372549, 1.0 ],
													"destination" : [ "obj-38", 1 ],
													"midpoints" : [ 519.5, 386.25, 377.5, 386.25 ],
													"order" : 0,
													"source" : [ "obj-31", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-39", 1 ],
													"order" : 1,
													"source" : [ "obj-32", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-40", 1 ],
													"order" : 0,
													"source" : [ "obj-32", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-36", 1 ],
													"midpoints" : [ 34.0, 440.0, 178.0, 440.0 ],
													"order" : 0,
													"source" : [ "obj-34", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-6", 0 ],
													"order" : 1,
													"source" : [ "obj-34", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-36", 0 ],
													"source" : [ "obj-35", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-33", 0 ],
													"source" : [ "obj-36", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-9", 0 ],
													"source" : [ "obj-38", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-30", 0 ],
													"source" : [ "obj-39", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-31", 0 ],
													"source" : [ "obj-40", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.0, 0.568627450980392, 0.074509803921569, 1.0 ],
													"destination" : [ "obj-16", 0 ],
													"midpoints" : [ 34.0, 242.75, 293.5, 242.75 ],
													"order" : 0,
													"source" : [ "obj-5", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.0, 0.568627450980392, 0.074509803921569, 1.0 ],
													"destination" : [ "obj-22", 0 ],
													"order" : 1,
													"source" : [ "obj-5", 0 ]
												}

											}
 ]
									}
,
									"patching_rect" : [ 420.5, 167.0, 124.5, 22.0 ],
									"text" : "gen @title lr-formula"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"id" : "obj-142",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 359.5, 858.0, 35.0, 22.0 ],
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
									"patching_rect" : [ 35.0, 858.0, 35.0, 22.0 ],
									"text" : "out 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-140",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 2,
											"revision" : 2,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "dsp.gen",
										"rect" : [ 428.0, 191.0, 869.0, 610.0 ],
										"bglocked" : 0,
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 1,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 1,
										"objectsnaponopen" : 1,
										"statusbarvisible" : 2,
										"toolbarvisible" : 1,
										"lefttoolbarpinned" : 0,
										"toptoolbarpinned" : 0,
										"righttoolbarpinned" : 0,
										"bottomtoolbarpinned" : 0,
										"toolbars_unpinned_last_save" : 0,
										"tallnewobj" : 0,
										"boxanimatetime" : 200,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"description" : "",
										"digest" : "",
										"tags" : "",
										"style" : "",
										"subpatcher_template" : "",
										"assistshowspatchername" : 0,
										"boxes" : [ 											{
												"box" : 												{
													"id" : "obj-20",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 728.5, 524.0, 108.0, 20.0 ],
													"text" : "Graham Wakefield"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-43",
													"linecount" : 5,
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 544.5, 398.5, 228.0, 74.0 ],
													"text" : "2nd stage splits the lowshelf again into 2nd lowshelf + phase-matched corresponding highpass\nAlso applies same allpass to the first highpass to keep it in phase"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-42",
													"linecount" : 2,
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 544.5, 274.5, 228.0, 33.0 ],
													"text" : "1st stage splits to lowshelf & phase-matched corresponding highpass"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-41",
													"linecount" : 2,
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 428.0, 127.5, 165.0, 33.0 ],
													"text" : "Set the lower & upper frequencies of the shelf filters"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-40",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 395.0, 150.0, 29.5, 22.0 ],
													"text" : "min"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-39",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 253.0, 150.0, 31.0, 22.0 ],
													"text" : "max"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-38",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 59.0, 106.0, 640.0, 480.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-35",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 246.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-34",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 216.5, 32.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-31",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 181.5, 32.5, 22.0 ],
																	"text" : "-"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-30",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 65.0, 151.5, 32.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-26",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 95.0, 111.5, 46.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-3",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 40.0, 28.0, 22.0 ],
																	"text" : "in 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-4",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 83.0, 40.0, 28.0, 22.0 ],
																	"text" : "in 2"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-15",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 50.0, 328.5, 35.0, 22.0 ],
																	"text" : "out 1"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-30", 0 ],
																	"midpoints" : [ 104.5, 139.5, 74.5, 139.5 ],
																	"order" : 1,
																	"source" : [ "obj-26", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-35", 1 ],
																	"midpoints" : [ 104.5, 239.5, 73.0, 239.5 ],
																	"order" : 0,
																	"source" : [ "obj-26", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-31", 0 ],
																	"source" : [ "obj-3", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-31", 1 ],
																	"source" : [ "obj-30", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-26", 0 ],
																	"midpoints" : [ 59.5, 213.5, 184.5, 213.5, 184.5, 101.5, 104.5, 101.5 ],
																	"order" : 0,
																	"source" : [ "obj-31", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-34", 0 ],
																	"order" : 1,
																	"source" : [ "obj-31", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-35", 0 ],
																	"source" : [ "obj-34", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-15", 0 ],
																	"source" : [ "obj-35", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-30", 1 ],
																	"order" : 0,
																	"source" : [ "obj-4", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-34", 1 ],
																	"order" : 1,
																	"source" : [ "obj-4", 0 ]
																}

															}
 ]
													}
,
													"patching_rect" : [ 284.0, 398.5, 103.0, 22.0 ],
													"text" : "gen @title allpass"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-34",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 109.0, 128.0, 267.0, 628.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-1",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 135.0, 497.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-2",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 468.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-3",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 426.5, 32.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-4",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 391.5, 32.5, 22.0 ],
																	"text" : "-"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-5",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 128.25, 345.5, 46.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-50",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 135.0, 260.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-40",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 231.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-38",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 189.5, 32.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-37",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 154.5, 32.5, 22.0 ],
																	"text" : "-"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-27",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 128.25, 108.5, 46.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-17",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 40.0, 28.0, 22.0 ],
																	"text" : "in 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-18",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 89.0, 40.0, 57.0, 22.0 ],
																	"text" : "in 2 coeff"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-21",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 50.0, 575.0, 35.0, 22.0 ],
																	"text" : "out 1"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-5", 0 ],
																	"midpoints" : [ 144.5, 528.5, 206.5, 528.5, 206.5, 337.5, 137.75, 337.5 ],
																	"source" : [ "obj-1", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-37", 0 ],
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"color" : [ 0.447058823529412, 0.125490196078431, 0.125490196078431, 1.0 ],
																	"destination" : [ "obj-3", 1 ],
																	"midpoints" : [ 98.5, 421.75, 73.0, 421.75 ],
																	"order" : 0,
																	"source" : [ "obj-18", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"color" : [ 0.447058823529412, 0.125490196078431, 0.125490196078431, 1.0 ],
																	"destination" : [ "obj-38", 1 ],
																	"midpoints" : [ 98.5, 183.25, 73.0, 183.25 ],
																	"order" : 1,
																	"source" : [ "obj-18", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-1", 0 ],
																	"midpoints" : [ 59.5, 493.0, 144.5, 493.0 ],
																	"order" : 0,
																	"source" : [ "obj-2", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-21", 0 ],
																	"order" : 1,
																	"source" : [ "obj-2", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-37", 1 ],
																	"midpoints" : [ 137.75, 141.5, 73.0, 141.5 ],
																	"order" : 1,
																	"source" : [ "obj-27", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-40", 1 ],
																	"midpoints" : [ 137.75, 223.5, 73.0, 223.5 ],
																	"order" : 0,
																	"source" : [ "obj-27", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-1", 1 ],
																	"midpoints" : [ 59.5, 455.0, 158.0, 455.0 ],
																	"order" : 0,
																	"source" : [ "obj-3", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-2", 0 ],
																	"order" : 1,
																	"source" : [ "obj-3", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-38", 0 ],
																	"source" : [ "obj-37", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-40", 0 ],
																	"order" : 1,
																	"source" : [ "obj-38", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-50", 1 ],
																	"midpoints" : [ 59.5, 218.0, 158.0, 218.0 ],
																	"order" : 0,
																	"source" : [ "obj-38", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-3", 0 ],
																	"source" : [ "obj-4", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-4", 0 ],
																	"order" : 1,
																	"source" : [ "obj-40", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-50", 0 ],
																	"midpoints" : [ 59.5, 256.0, 144.5, 256.0 ],
																	"order" : 0,
																	"source" : [ "obj-40", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-2", 1 ],
																	"midpoints" : [ 137.75, 460.5, 73.0, 460.5 ],
																	"order" : 0,
																	"source" : [ "obj-5", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-4", 1 ],
																	"midpoints" : [ 137.75, 378.5, 73.0, 378.5 ],
																	"order" : 1,
																	"source" : [ "obj-5", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-27", 0 ],
																	"midpoints" : [ 144.5, 291.5, 206.5, 291.5, 206.5, 100.5, 137.75, 100.5 ],
																	"source" : [ "obj-50", 0 ]
																}

															}
 ]
													}
,
													"patching_rect" : [ 24.5, 398.5, 116.0, 22.0 ],
													"text" : "gen @title lowshelf2"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-35",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 59.0, 106.0, 640.0, 480.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-35",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 246.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-34",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 216.5, 32.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-31",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 181.5, 32.5, 22.0 ],
																	"text" : "-"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-30",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 65.0, 151.5, 32.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-26",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 95.0, 111.5, 46.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-3",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 40.0, 28.0, 22.0 ],
																	"text" : "in 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-4",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 83.0, 40.0, 28.0, 22.0 ],
																	"text" : "in 2"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-15",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 50.0, 328.5, 35.0, 22.0 ],
																	"text" : "out 1"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-30", 0 ],
																	"midpoints" : [ 104.5, 139.5, 74.5, 139.5 ],
																	"order" : 1,
																	"source" : [ "obj-26", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-35", 1 ],
																	"midpoints" : [ 104.5, 239.5, 73.0, 239.5 ],
																	"order" : 0,
																	"source" : [ "obj-26", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-31", 0 ],
																	"source" : [ "obj-3", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-31", 1 ],
																	"source" : [ "obj-30", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-26", 0 ],
																	"midpoints" : [ 59.5, 213.5, 184.5, 213.5, 184.5, 101.5, 104.5, 101.5 ],
																	"order" : 0,
																	"source" : [ "obj-31", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-34", 0 ],
																	"order" : 1,
																	"source" : [ "obj-31", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-35", 0 ],
																	"source" : [ "obj-34", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-15", 0 ],
																	"source" : [ "obj-35", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-30", 1 ],
																	"order" : 0,
																	"source" : [ "obj-4", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-34", 1 ],
																	"order" : 1,
																	"source" : [ "obj-4", 0 ]
																}

															}
 ]
													}
,
													"patching_rect" : [ 155.0, 398.5, 103.0, 22.0 ],
													"text" : "gen @title allpass"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-36",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 155.0, 450.5, 32.5, 22.0 ],
													"text" : "-"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-33",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 155.0, 506.0, 58.0, 22.0 ],
													"text" : "out 2 mid"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-31",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 109.0, 128.0, 473.0, 430.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-24",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 309.5, 36.0, 22.0 ],
																	"text" : "* 0.5"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-23",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 279.5, 28.0, 22.0 ],
																	"text" : "+ 1"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-20",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 232.5, 32.5, 22.0 ],
																	"text" : "/"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-19",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 202.5, 28.0, 22.0 ],
																	"text" : "- 1."
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-14",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 155.5, 172.5, 30.0, 22.0 ],
																	"text" : "cos"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-13",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 172.5, 26.0, 22.0 ],
																	"text" : "sin"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-12",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 230.5, 126.5, 119.0, 20.0 ],
																	"text" : "radians per sample"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-10",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 126.5, 107.0, 22.0 ],
																	"text" : "* twopi/samplerate"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-26",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 96.0, 44.0, 22.0 ],
																	"text" : "in 1 hz"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-27",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 121.5, 339.5, 89.0, 22.0 ],
																	"text" : "out 1 lowpass2"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-28",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 219.0, 339.5, 76.0, 22.0 ],
																	"text" : "out 2 allpass"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-13", 0 ],
																	"midpoints" : [ 131.0, 166.0, 131.0, 166.0 ],
																	"order" : 1,
																	"source" : [ "obj-10", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-14", 0 ],
																	"midpoints" : [ 131.0, 166.0, 165.0, 166.0 ],
																	"order" : 0,
																	"source" : [ "obj-10", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-19", 0 ],
																	"source" : [ "obj-13", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-20", 1 ],
																	"midpoints" : [ 165.0, 224.0, 144.5, 224.0 ],
																	"source" : [ "obj-14", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-20", 0 ],
																	"source" : [ "obj-19", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-23", 0 ],
																	"midpoints" : [ 131.0, 263.0, 131.0, 263.0 ],
																	"order" : 1,
																	"source" : [ "obj-20", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-28", 0 ],
																	"midpoints" : [ 131.0, 266.0, 228.5, 266.0 ],
																	"order" : 0,
																	"source" : [ "obj-20", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-24", 0 ],
																	"source" : [ "obj-23", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-27", 0 ],
																	"source" : [ "obj-24", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-10", 0 ],
																	"source" : [ "obj-26", 0 ]
																}

															}
 ]
													}
,
													"patching_rect" : [ 395.0, 180.0, 134.0, 22.0 ],
													"text" : "gen @title xover_coeffs"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-32",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 405.5, 99.5, 296.0, 22.0 ],
													"text" : "in 3 freq2 @default 4000 @min 1 @max samplerate/2"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-30",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 109.0, 128.0, 473.0, 430.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-24",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 309.5, 36.0, 22.0 ],
																	"text" : "* 0.5"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-23",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 279.5, 28.0, 22.0 ],
																	"text" : "+ 1"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-20",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 232.5, 32.5, 22.0 ],
																	"text" : "/"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-19",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 202.5, 28.0, 22.0 ],
																	"text" : "- 1."
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-14",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 155.5, 172.5, 30.0, 22.0 ],
																	"text" : "cos"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-13",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 172.5, 26.0, 22.0 ],
																	"text" : "sin"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-12",
																	"maxclass" : "comment",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 230.5, 126.5, 119.0, 20.0 ],
																	"text" : "radians per sample"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-10",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 126.5, 107.0, 22.0 ],
																	"text" : "* twopi/samplerate"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-26",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 121.5, 96.0, 44.0, 22.0 ],
																	"text" : "in 1 hz"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-27",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 121.5, 339.5, 89.0, 22.0 ],
																	"text" : "out 1 lowpass2"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-28",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 219.0, 339.5, 76.0, 22.0 ],
																	"text" : "out 2 allpass"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-13", 0 ],
																	"midpoints" : [ 131.0, 166.0, 131.0, 166.0 ],
																	"order" : 1,
																	"source" : [ "obj-10", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-14", 0 ],
																	"midpoints" : [ 131.0, 166.0, 165.0, 166.0 ],
																	"order" : 0,
																	"source" : [ "obj-10", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-19", 0 ],
																	"source" : [ "obj-13", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-20", 1 ],
																	"midpoints" : [ 165.0, 224.0, 144.5, 224.0 ],
																	"source" : [ "obj-14", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-20", 0 ],
																	"source" : [ "obj-19", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-23", 0 ],
																	"midpoints" : [ 131.0, 263.0, 131.0, 263.0 ],
																	"order" : 1,
																	"source" : [ "obj-20", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-28", 0 ],
																	"midpoints" : [ 131.0, 266.0, 228.5, 266.0 ],
																	"order" : 0,
																	"source" : [ "obj-20", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-24", 0 ],
																	"source" : [ "obj-23", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-27", 0 ],
																	"source" : [ "obj-24", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-10", 0 ],
																	"source" : [ "obj-26", 0 ]
																}

															}
 ]
													}
,
													"patching_rect" : [ 253.0, 180.0, 134.0, 22.0 ],
													"text" : "gen @title xover_coeffs"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-22",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 109.0, 128.0, 267.0, 628.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-1",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 135.0, 497.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-2",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 468.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-3",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 426.5, 32.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-4",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 391.5, 32.5, 22.0 ],
																	"text" : "-"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-5",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 128.25, 345.5, 46.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-50",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 135.0, 260.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-40",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 231.5, 32.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-38",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 189.5, 32.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-37",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 154.5, 32.5, 22.0 ],
																	"text" : "-"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-27",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 128.25, 108.5, 46.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-17",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 40.0, 28.0, 22.0 ],
																	"text" : "in 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-18",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 89.0, 40.0, 57.0, 22.0 ],
																	"text" : "in 2 coeff"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-21",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 50.0, 575.0, 35.0, 22.0 ],
																	"text" : "out 1"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-5", 0 ],
																	"midpoints" : [ 144.5, 528.5, 206.5, 528.5, 206.5, 337.5, 137.75, 337.5 ],
																	"source" : [ "obj-1", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-37", 0 ],
																	"source" : [ "obj-17", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"color" : [ 0.447058823529412, 0.125490196078431, 0.125490196078431, 1.0 ],
																	"destination" : [ "obj-3", 1 ],
																	"midpoints" : [ 98.5, 421.75, 73.0, 421.75 ],
																	"order" : 0,
																	"source" : [ "obj-18", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"color" : [ 0.447058823529412, 0.125490196078431, 0.125490196078431, 1.0 ],
																	"destination" : [ "obj-38", 1 ],
																	"midpoints" : [ 98.5, 183.25, 73.0, 183.25 ],
																	"order" : 1,
																	"source" : [ "obj-18", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-1", 0 ],
																	"midpoints" : [ 59.5, 493.0, 144.5, 493.0 ],
																	"order" : 0,
																	"source" : [ "obj-2", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-21", 0 ],
																	"order" : 1,
																	"source" : [ "obj-2", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-37", 1 ],
																	"midpoints" : [ 137.75, 141.5, 73.0, 141.5 ],
																	"order" : 1,
																	"source" : [ "obj-27", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-40", 1 ],
																	"midpoints" : [ 137.75, 223.5, 73.0, 223.5 ],
																	"order" : 0,
																	"source" : [ "obj-27", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-1", 1 ],
																	"midpoints" : [ 59.5, 455.0, 158.0, 455.0 ],
																	"order" : 0,
																	"source" : [ "obj-3", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-2", 0 ],
																	"order" : 1,
																	"source" : [ "obj-3", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-38", 0 ],
																	"source" : [ "obj-37", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-40", 0 ],
																	"order" : 1,
																	"source" : [ "obj-38", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-50", 1 ],
																	"midpoints" : [ 59.5, 218.0, 158.0, 218.0 ],
																	"order" : 0,
																	"source" : [ "obj-38", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-3", 0 ],
																	"source" : [ "obj-4", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-4", 0 ],
																	"order" : 1,
																	"source" : [ "obj-40", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-50", 0 ],
																	"midpoints" : [ 59.5, 256.0, 144.5, 256.0 ],
																	"order" : 0,
																	"source" : [ "obj-40", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-2", 1 ],
																	"midpoints" : [ 137.75, 460.5, 73.0, 460.5 ],
																	"order" : 0,
																	"source" : [ "obj-5", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-4", 1 ],
																	"midpoints" : [ 137.75, 378.5, 73.0, 378.5 ],
																	"order" : 1,
																	"source" : [ "obj-5", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-27", 0 ],
																	"midpoints" : [ 144.5, 291.5, 206.5, 291.5, 206.5, 100.5, 137.75, 100.5 ],
																	"source" : [ "obj-50", 0 ]
																}

															}
 ]
													}
,
													"patching_rect" : [ 24.5, 273.5, 116.0, 22.0 ],
													"text" : "gen @title lowshelf2"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-16",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 8,
															"minor" : 2,
															"revision" : 2,
															"architecture" : "x64",
															"modernui" : 1
														}
,
														"classnamespace" : "dsp.gen",
														"rect" : [ 1065.0, 317.0, 353.0, 434.0 ],
														"bglocked" : 0,
														"openinpresentation" : 0,
														"default_fontsize" : 12.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 1,
														"gridsize" : [ 15.0, 15.0 ],
														"gridsnaponopen" : 1,
														"objectsnaponopen" : 1,
														"statusbarvisible" : 2,
														"toolbarvisible" : 1,
														"lefttoolbarpinned" : 0,
														"toptoolbarpinned" : 0,
														"righttoolbarpinned" : 0,
														"bottomtoolbarpinned" : 0,
														"toolbars_unpinned_last_save" : 0,
														"tallnewobj" : 0,
														"boxanimatetime" : 200,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"description" : "",
														"digest" : "",
														"tags" : "",
														"style" : "",
														"subpatcher_template" : "",
														"assistshowspatchername" : 0,
														"boxes" : [ 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-35",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 324.5, 158.5, 22.0 ],
																	"text" : "+"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-34",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 270.5, 101.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-31",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 207.5, 47.5, 22.0 ],
																	"text" : "-"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-30",
																	"maxclass" : "newobj",
																	"numinlets" : 2,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 78.5, 161.5, 44.5, 22.0 ],
																	"text" : "*"
																}

															}
, 															{
																"box" : 																{
																	"fontname" : "Arial",
																	"fontsize" : 12.0,
																	"id" : "obj-26",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 190.0, 36.5, 46.0, 22.0 ],
																	"text" : "history"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-3",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 50.0, 40.0, 28.0, 22.0 ],
																	"text" : "in 1"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-4",
																	"maxclass" : "newobj",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"outlettype" : [ "" ],
																	"patching_rect" : [ 136.0, 40.0, 28.0, 22.0 ],
																	"text" : "in 2"
																}

															}
, 															{
																"box" : 																{
																	"id" : "obj-15",
																	"maxclass" : "newobj",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"patching_rect" : [ 48.75, 366.5, 35.0, 22.0 ],
																	"text" : "out 1"
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"destination" : [ "obj-30", 0 ],
																	"midpoints" : [ 199.5, 139.5, 88.0, 139.5 ],
																	"order" : 1,
																	"source" : [ "obj-26", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-35", 1 ],
																	"midpoints" : [ 199.5, 316.5, 199.0, 316.5 ],
																	"order" : 0,
																	"source" : [ "obj-26", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-31", 0 ],
																	"source" : [ "obj-3", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-31", 1 ],
																	"source" : [ "obj-30", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-26", 0 ],
																	"midpoints" : [ 59.5, 249.5, 296.5, 249.5, 296.5, 16.5, 199.5, 16.5 ],
																	"order" : 0,
																	"source" : [ "obj-31", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-34", 0 ],
																	"order" : 1,
																	"source" : [ "obj-31", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-35", 0 ],
																	"source" : [ "obj-34", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-15", 0 ],
																	"source" : [ "obj-35", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-30", 1 ],
																	"order" : 1,
																	"source" : [ "obj-4", 0 ]
																}

															}
, 															{
																"patchline" : 																{
																	"destination" : [ "obj-34", 1 ],
																	"order" : 0,
																	"source" : [ "obj-4", 0 ]
																}

															}
 ]
													}
,
													"patching_rect" : [ 284.0, 274.5, 103.0, 22.0 ],
													"text" : "gen @title allpass"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-29",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 284.0, 326.0, 32.5, 22.0 ],
													"text" : "-"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-1",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 253.0, 68.5, 289.0, 22.0 ],
													"text" : "in 2 freq1 @default 400 @min 1 @max samplerate/2"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-9",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 284.0, 506.0, 61.0, 22.0 ],
													"text" : "out 3 high"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-8",
													"maxclass" : "comment",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 24.5, 25.0, 306.0, 20.0 ],
													"text" : "A 2-stage crossover filter"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-6",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 24.5, 506.0, 57.0, 22.0 ],
													"text" : "out 1 low"
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Arial",
													"fontsize" : 12.0,
													"id" : "obj-5",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 24.5, 68.5, 127.0, 22.0 ],
													"text" : "in 1 @comment input"
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-39", 0 ],
													"order" : 1,
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-40", 0 ],
													"order" : 0,
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-29", 0 ],
													"source" : [ "obj-16", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-29", 1 ],
													"midpoints" : [ 34.0, 311.0, 307.0, 311.0 ],
													"order" : 0,
													"source" : [ "obj-22", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-34", 0 ],
													"order" : 2,
													"source" : [ "obj-22", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-35", 0 ],
													"midpoints" : [ 34.0, 353.0, 164.5, 353.0 ],
													"order" : 1,
													"source" : [ "obj-22", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-38", 0 ],
													"source" : [ "obj-29", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.992156862745098, 0.776470588235294, 0.533333333333333, 1.0 ],
													"destination" : [ "obj-16", 1 ],
													"source" : [ "obj-30", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.996078431372549, 0.517647058823529, 0.517647058823529, 1.0 ],
													"destination" : [ "obj-22", 1 ],
													"midpoints" : [ 262.5, 261.25, 131.0, 261.25 ],
													"source" : [ "obj-30", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.52156862745098, 0.525490196078431, 0.996078431372549, 1.0 ],
													"destination" : [ "obj-34", 1 ],
													"midpoints" : [ 404.5, 376.25, 131.0, 376.25 ],
													"source" : [ "obj-31", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.952941176470588, 0.486274509803922, 0.996078431372549, 1.0 ],
													"destination" : [ "obj-35", 1 ],
													"midpoints" : [ 519.5, 384.25, 248.5, 384.25 ],
													"order" : 1,
													"source" : [ "obj-31", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.952941176470588, 0.486274509803922, 0.996078431372549, 1.0 ],
													"destination" : [ "obj-38", 1 ],
													"midpoints" : [ 519.5, 386.25, 377.5, 386.25 ],
													"order" : 0,
													"source" : [ "obj-31", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-39", 1 ],
													"order" : 1,
													"source" : [ "obj-32", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-40", 1 ],
													"order" : 0,
													"source" : [ "obj-32", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-36", 1 ],
													"midpoints" : [ 34.0, 440.0, 178.0, 440.0 ],
													"order" : 0,
													"source" : [ "obj-34", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-6", 0 ],
													"order" : 1,
													"source" : [ "obj-34", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-36", 0 ],
													"source" : [ "obj-35", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-33", 0 ],
													"source" : [ "obj-36", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-9", 0 ],
													"source" : [ "obj-38", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-30", 0 ],
													"source" : [ "obj-39", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-31", 0 ],
													"source" : [ "obj-40", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.0, 0.568627450980392, 0.074509803921569, 1.0 ],
													"destination" : [ "obj-16", 0 ],
													"midpoints" : [ 34.0, 242.75, 293.5, 242.75 ],
													"order" : 0,
													"source" : [ "obj-5", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"color" : [ 0.0, 0.568627450980392, 0.074509803921569, 1.0 ],
													"destination" : [ "obj-22", 0 ],
													"order" : 1,
													"source" : [ "obj-5", 0 ]
												}

											}
 ]
									}
,
									"patching_rect" : [ 68.0, 167.0, 124.5, 22.0 ],
									"text" : "gen @title lr-formula"
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
									"patching_rect" : [ 68.0, 19.0, 28.0, 22.0 ],
									"text" : "in 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-115",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 597.5, 12.0, 346.0, 22.0 ],
									"text" : "param @name a_FREQ1 @min 20 @max 20000 @default 500"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-44", 0 ],
									"order" : 1,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-48", 0 ],
									"order" : 0,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-9", 0 ],
									"source" : [ "obj-108", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-140", 2 ],
									"order" : 1,
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-21", 2 ],
									"order" : 0,
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-7", 0 ],
									"source" : [ "obj-115", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-140", 0 ],
									"order" : 0,
									"source" : [ "obj-116", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"midpoints" : [ 77.5, 52.0, 44.5, 52.0 ],
									"order" : 1,
									"source" : [ "obj-116", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-11", 0 ],
									"source" : [ "obj-12", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-2", 1 ],
									"source" : [ "obj-13", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 1 ],
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-2", 1 ],
									"source" : [ "obj-14", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 1 ],
									"source" : [ "obj-14", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-13", 0 ],
									"source" : [ "obj-140", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-14", 0 ],
									"source" : [ "obj-140", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 0 ],
									"source" : [ "obj-140", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-13", 0 ],
									"order" : 1,
									"source" : [ "obj-18", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-14", 0 ],
									"order" : 0,
									"source" : [ "obj-18", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.986251831054688, 0.007236152887344, 0.027423052117229, 1.0 ],
									"destination" : [ "obj-4", 0 ],
									"order" : 2,
									"source" : [ "obj-18", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-142", 0 ],
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"source" : [ "obj-20", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-13", 1 ],
									"source" : [ "obj-21", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-14", 1 ],
									"source" : [ "obj-21", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-2", 0 ],
									"midpoints" : [ 430.0, 51.0, 369.0, 51.0 ],
									"order" : 1,
									"source" : [ "obj-23", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-21", 0 ],
									"order" : 0,
									"source" : [ "obj-23", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-26", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"destination" : [ "obj-4", 0 ],
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-10", 0 ],
									"source" : [ "obj-29", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-141", 0 ],
									"source" : [ "obj-3", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-31", 0 ],
									"source" : [ "obj-32", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-33", 0 ],
									"source" : [ "obj-34", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-18", 0 ],
									"source" : [ "obj-37", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-2", 1 ],
									"source" : [ "obj-4", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 1 ],
									"source" : [ "obj-4", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"destination" : [ "obj-13", 0 ],
									"source" : [ "obj-42", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"destination" : [ "obj-14", 0 ],
									"source" : [ "obj-44", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-105", 0 ],
									"source" : [ "obj-46", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-107", 0 ],
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-106", 0 ],
									"source" : [ "obj-48", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.60000091791153, 0.400011628866196, 0.200000643730164, 1.0 ],
									"destination" : [ "obj-2", 2 ],
									"midpoints" : [ 1316.5, 783.5, 438.0, 783.5 ],
									"order" : 0,
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.60000091791153, 0.400011628866196, 0.200000643730164, 1.0 ],
									"destination" : [ "obj-3", 2 ],
									"midpoints" : [ 1316.5, 783.5, 110.5, 783.5 ],
									"order" : 1,
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"source" : [ "obj-6", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-140", 1 ],
									"order" : 1,
									"source" : [ "obj-7", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-21", 1 ],
									"order" : 0,
									"source" : [ "obj-7", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-27", 0 ],
									"order" : 1,
									"source" : [ "obj-8", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-46", 0 ],
									"order" : 0,
									"source" : [ "obj-8", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-42", 0 ],
									"order" : 1,
									"source" : [ "obj-9", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-47", 0 ],
									"order" : 0,
									"source" : [ "obj-9", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 170.999999999999972, 276.0, 229.000000000000256, 76.0 ],
					"saved_object_attributes" : 					{
						"autoexport" : 0,
						"exportfolder" : "NVME:/Users/jcba/Documents/JUCE/my_plugins/JCBImager/exported-code/",
						"exportname" : "IMG_GEN"
					}
,
					"text" : "gen~ @title Linkwitz-Riley-2nd-order @autoexport 0 @exportfolder ~/Documents/JUCE/my_plugins/JCBImager/exported-code @exportname IMG_GEN"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 1 ],
					"source" : [ "obj-1", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 1 ],
					"midpoints" : [ 435.5, 434.0, 190.999999999999972, 434.0 ],
					"order" : 1,
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 1 ],
					"midpoints" : [ 435.5, 434.0, 401.000000000000227, 434.0 ],
					"order" : 0,
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 1159.0, 234.0, 180.499999999999972, 234.0 ],
					"source" : [ "obj-16", 0 ]
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
					"destination" : [ "obj-1", 1 ],
					"source" : [ "obj-20", 0 ]
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
					"midpoints" : [ 819.0, 204.5, 180.499999999999972, 204.5 ],
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
					"midpoints" : [ 929.0, 204.5, 180.499999999999972, 204.5 ],
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
					"midpoints" : [ 1032.0, 204.5, 180.499999999999972, 204.5 ],
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
					"midpoints" : [ 489.5, 204.0, 180.499999999999972, 204.0 ],
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
					"midpoints" : [ 662.0, 202.0, 180.499999999999972, 202.0 ],
					"source" : [ "obj-34", 0 ]
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
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 180.499999999999972, 497.5, 259.500000000000114, 497.5 ],
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 588.0, 233.5, 180.499999999999972, 233.5 ],
					"source" : [ "obj-48", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 50.5, 217.0, 180.499999999999972, 217.0 ],
					"source" : [ "obj-5", 0 ]
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
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 733.0, 233.5, 180.499999999999972, 233.5 ],
					"source" : [ "obj-56", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"midpoints" : [ 390.500000000000227, 372.0, 498.5, 372.0 ],
					"order" : 0,
					"source" : [ "obj-6", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"midpoints" : [ 180.499999999999972, 404.0, 180.499999999999972, 404.0 ],
					"order" : 0,
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"midpoints" : [ 390.500000000000227, 404.0, 390.500000000000227, 404.0 ],
					"order" : 1,
					"source" : [ "obj-6", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"midpoints" : [ 180.499999999999972, 372.0, 75.5, 372.0 ],
					"order" : 1,
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 1 ],
					"midpoints" : [ 390.500000000000227, 497.5, 293.500000000000114, 497.5 ],
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
					"midpoints" : [ 402.5, 233.5, 180.499999999999972, 233.5 ],
					"source" : [ "obj-8", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-28" : [ "number", "number", 0 ],
			"obj-31" : [ "number[1]", "number[1]", 0 ],
			"obj-33" : [ "number[3]", "number[3]", 0 ],
			"obj-51" : [ "number[2]", "number[2]", 0 ],
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
