Route124_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route124_OnTransition
	.byte 0

Route124_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

Route124_EventScript_GeniusFeather::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, Route124_ThreeGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, Route124_ThreeGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, Route124_ThreeGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, Route124_ThreeGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, Route124_FourGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, Route124_FourGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, Route124_FourGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, Route124_FourGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, Route124_FiveGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, Route124_FiveGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, Route124_FiveGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, Route124_FiveGeniusFeathers
	end

Route124_ThreeGeniusFeathers::
	finditem ITEM_GENIUS_FEATHER, amount=3
	end

Route124_FourGeniusFeathers::
	finditem ITEM_GENIUS_FEATHER, amount=4
	end

Route124_FiveGeniusFeathers::
	finditem ITEM_GENIUS_FEATHER, amount=5
	end

Route124_EventScript_HuntersHouseSign::
	msgbox Route124_Text_HuntersHouse, MSGBOX_SIGN
	end

Route124_EventScript_Spencer::
	trainerbattle_single TRAINER_SPENCER, Route124_Text_SpencerIntro, Route124_Text_SpencerDefeat
	msgbox Route124_Text_SpencerPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Roland::
	trainerbattle_single TRAINER_ROLAND, Route124_Text_RolandIntro, Route124_Text_RolandDefeat
	msgbox Route124_Text_RolandPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Jenny::
	trainerbattle_single TRAINER_JENNY, Route124_Text_JennyIntro, Route124_Text_JennyDefeat
	msgbox Route124_Text_JennyPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_Grace::
	trainerbattle_single TRAINER_GRACE, Route124_Text_GraceIntro, Route124_Text_GraceDefeat
	msgbox Route124_Text_GracePostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Chad::
	trainerbattle_single TRAINER_CHAD, Route124_Text_ChadIntro, Route124_Text_ChadDefeat
	msgbox Route124_Text_ChadPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Lila::
	trainerbattle_double TRAINER_LILA_AND_ROY, Route124_Text_LilaIntro, Route124_Text_LilaDefeat, Route124_Text_LilaNotEnoughMons
	msgbox Route124_Text_LilaPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_Roy::
	trainerbattle_double TRAINER_LILA_AND_ROY, Route124_Text_RoyIntro, Route124_Text_RoyDefeat, Route124_Text_RoyNotEnoughMons
	msgbox Route124_Text_RoyPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_Declan::
	trainerbattle_single TRAINER_DECLAN, Route124_Text_DeclanIntro, Route124_Text_DeclanDefeat
	msgbox Route124_Text_DeclanPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Isabella::
	trainerbattle_single TRAINER_ISABELLA, Route124_Text_IsabellaIntro, Route124_Text_IsabellaDefeat
	msgbox Route124_Text_IsabellaPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_Text_HuntersHouse:
	.string "HUNTER'S HOUSE$"

