Route128_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route128_OnTransition
	.byte 0

Route128_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

Route128_EventScript_GeniusFeather::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, Route128_ThreeGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, Route128_ThreeGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, Route128_ThreeGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, Route128_ThreeGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, Route128_FourGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, Route128_FourGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, Route128_FourGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, Route128_FourGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, Route128_FiveGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, Route128_FiveGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, Route128_FiveGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, Route128_FiveGeniusFeathers
	end

Route128_ThreeGeniusFeathers::
	finditem ITEM_GENIUS_FEATHER, amount=3
	end

Route128_FourGeniusFeathers::
	finditem ITEM_GENIUS_FEATHER, amount=4
	end

Route128_FiveGeniusFeathers::
	finditem ITEM_GENIUS_FEATHER, amount=5
	end

Route128_EventScript_BigBerryAgent::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Route128_BigBerryAgent
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Route128_BigBerryAgent:
	.2byte ITEM_FIGY_BERRY
	.2byte ITEM_WIKI_BERRY
	.2byte ITEM_MAGO_BERRY
	.2byte ITEM_AGUAV_BERRY
	.2byte ITEM_IAPAPA_BERRY
	pokemartlistend

Route128_EventScript_Isaiah::
	trainerbattle_single TRAINER_ISAIAH, Route128_Text_IsaiahIntro, Route128_Text_IsaiahDefeat
	msgbox Route128_Text_IsaiahPostBattle, MSGBOX_DEFAULT
	release
	end

Route128_EventScript_Katelyn::
	trainerbattle_single TRAINER_KATELYN, Route128_Text_KatelynIntro, Route128_Text_KatelynDefeat
	msgbox Route128_Text_KatelynPostBattle, MSGBOX_DEFAULT
	release
	end

Route128_EventScript_Alexa::
	trainerbattle_single TRAINER_ALEXA, Route128_Text_AlexaIntro, Route128_Text_AlexaDefeat
	msgbox Route128_Text_AlexaPostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Ruben::
	trainerbattle_single TRAINER_RUBEN, Route128_Text_RubenIntro, Route128_Text_RubenDefeat
	msgbox Route128_Text_RubenPostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Wayne::
	trainerbattle_single TRAINER_WAYNE, Route128_Text_WayneIntro, Route128_Text_WayneDefeat
	msgbox Route128_Text_WaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Harrison::
	trainerbattle_single TRAINER_HARRISON, Route128_Text_HarrisonIntro, Route128_Text_HarrisonDefeat
	msgbox Route128_Text_HarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Carlee::
	trainerbattle_single TRAINER_CARLEE, Route128_Text_CarleeIntro, Route128_Text_CarleeDefeat
	msgbox Route128_Text_CarleePostBattle, MSGBOX_AUTOCLOSE
	end

