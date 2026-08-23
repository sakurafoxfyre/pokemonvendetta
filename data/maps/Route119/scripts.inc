Route119_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
	.byte 0

Route119_OnTransition:
	special SetRoute119Weather
	end

Route119_EventScript_LuminousMoss::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, Route119_ThreeLuminousMoss
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, Route119_ThreeLuminousMoss
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, Route119_ThreeLuminousMoss
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, Route119_ThreeLuminousMoss
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, Route119_FiveLuminousMoss
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, Route119_FiveLuminousMoss
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, Route119_FiveLuminousMoss
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, Route119_FiveLuminousMoss
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, Route119_SevenLuminousMoss
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, Route119_SevenLuminousMoss
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, Route119_SevenLuminousMoss
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, Route119_SevenLuminousMoss
	end

Route119_ThreeLuminousMoss::
	finditem ITEM_LUMINOUS_MOSS, amount=3
	end

Route119_FiveLuminousMoss::
	finditem ITEM_LUMINOUS_MOSS, amount=5
	end

Route119_SevenLuminousMoss::
	finditem ITEM_LUMINOUS_MOSS, amount=7
	end

Route119_EventScript_PoisonGems::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, Route119_ThreePoisonGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, Route119_ThreePoisonGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, Route119_ThreePoisonGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, Route119_ThreePoisonGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, Route119_FivePoisonGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, Route119_FivePoisonGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, Route119_FivePoisonGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, Route119_FivePoisonGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, Route119_SevenPoisonGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, Route119_SevenPoisonGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, Route119_SevenPoisonGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, Route119_SevenPoisonGems
	end

Route119_ThreePoisonGems::
	finditem ITEM_POISON_GEM, amount=3
	end

Route119_FivePoisonGems::
	finditem ITEM_POISON_GEM, amount=5
	end

Route119_SevenPoisonGems::
	finditem ITEM_POISON_GEM, amount=7
	end

Route119_EventScript_CyclingTriathleteM::
	msgbox Route119_Text_TallGrassSnaresBikeTires, MSGBOX_NPC
	end

Route119_EventScript_RouteSignFortree::
	msgbox Route119_Text_RouteSignFortree, MSGBOX_SIGN
	end

Route119_EventScript_WeatherInstituteSign::
	msgbox Route119_Text_WeatherInstitute, MSGBOX_SIGN
	end

Route119_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT, Route119_Text_BrentIntro, Route119_Text_BrentDefeat
	msgbox Route119_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD, Route119_Text_DonaldIntro, Route119_Text_DonaldDefeat
	msgbox Route119_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Taylor::
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_TaylorIntro, Route119_Text_TaylorDefeat
	msgbox Route119_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Doug::
	trainerbattle_single TRAINER_DOUG, Route119_Text_DougIntro, Route119_Text_DougDefeat
	msgbox Route119_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Greg::
	trainerbattle_single TRAINER_GREG, Route119_Text_GregIntro, Route119_Text_GregDefeat
	msgbox Route119_Text_GregPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Kent::
	trainerbattle_single TRAINER_KENT, Route119_Text_KentIntro, Route119_Text_KentDefeat
	msgbox Route119_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Jackson::
	trainerbattle_single TRAINER_JACKSON, Route119_Text_JacksonIntro, Route119_Text_JacksonDefeat
	msgbox Route119_Text_JacksonPostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_Catherine::
	trainerbattle_single TRAINER_CATHERINE, Route119_Text_CatherineIntro, Route119_Text_CatherineDefeat
	msgbox Route119_Text_CatherinePostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_Hugh::
	trainerbattle_single TRAINER_HUGH, Route119_Text_HughIntro, Route119_Text_HughDefeat
	msgbox Route119_Text_HughPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL, Route119_Text_PhilIntro, Route119_Text_PhilDefeat
	msgbox Route119_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Yasu::
	trainerbattle_single TRAINER_YASU, Route119_Text_YasuIntro, Route119_Text_YasuDefeat
	msgbox Route119_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Takashi::
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_TakashiIntro, Route119_Text_TakashiDefeat
	msgbox Route119_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hideo::
	trainerbattle_single TRAINER_HIDEO, Route119_Text_HideoIntro, Route119_Text_HideoDefeat
	msgbox Route119_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Chris::
	trainerbattle_single TRAINER_CHRIS, Route119_Text_ChrisIntro, Route119_Text_ChrisDefeat
	msgbox Route119_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Fabian::
	trainerbattle_single TRAINER_FABIAN, Route119_Text_FabianIntro, Route119_Text_FabianDefeat
	msgbox Route119_Text_FabianPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Dayton::
	trainerbattle_single TRAINER_DAYTON, Route119_Text_DaytonIntro, Route119_Text_DaytonDefeat
	msgbox Route119_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Rachel::
	trainerbattle_single TRAINER_RACHEL, Route119_Text_RachelIntro, Route119_Text_RachelDefeat
	msgbox Route119_Text_RachelPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Boy1::
	msgbox Route119_Text_ThoughtFlyByCatchingBirdMons, MSGBOX_NPC
	end

Route119_EventScript_Boy2::
	msgbox Route119_Text_CanYourMonMakeSecretBase, MSGBOX_NPC
	end

Route119_EventScript_TrainerTipsDecoration::
	msgbox Route119_Text_TrainerTipsDecoration, MSGBOX_SIGN
	end

Route119_Text_ThoughtFlyByCatchingBirdMons:
	.string "I thought you FLY by catching a whole\n"
	.string "flock of BIRD POKéMON, and then\l"
	.string "hanging on to them somehow.\p"
	.string "But it turns out there's an HM move\n"
	.string "called FLY!\p"
	.string "I wish I'd known about that a long\n"
	.string "time ago…$"

Route119_Text_TallGrassSnaresBikeTires:
	.string "Tch…\n"
	.string "It's a no-go…\p"
	.string "The tall grass snares BIKE tires.\n"
	.string "There's no way you can cycle here.$"

Route119_Text_CanYourMonMakeSecretBase:
	.string "Can your POKéMON use its SECRET POWER\n"
	.string "on a big pile of grass and make a\l"
	.string "SECRET BASE?$"

Route119_Text_RouteSignFortree:
	.string "ROUTE 119\n"
	.string "{RIGHT_ARROW} FORTREE CITY$"

Route119_Text_WeatherInstitute:
	.string "WEATHER INSTITUTE$"

Route119_Text_TrainerTipsDecoration:
	.string "TRAINER TIPS\p"
	.string "Up to sixteen decorations and\n"
	.string "furniture items can be placed in\l"
	.string "a SECRET BASE.\p"
	.string "Pick your favorite items and create\n"
	.string "your very own SECRET BASE exactly the\l"
	.string "way you want.$"
