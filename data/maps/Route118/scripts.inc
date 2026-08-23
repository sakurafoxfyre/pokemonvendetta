Route118_MapScripts::
	.byte 0

Route118_EventScript_HealthFeather::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, Route118_ThreeHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, Route118_ThreeHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, Route118_ThreeHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, Route118_ThreeHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, Route118_FourHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, Route118_FourHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, Route118_FourHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, Route118_FourHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, Route118_FiveHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, Route118_FiveHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, Route118_FiveHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, Route118_FiveHealthFeathers
	end

Route118_ThreeHealthFeathers::
	finditem ITEM_HEALTH_FEATHER, amount=3
	end

Route118_FourHealthFeathers::
	finditem ITEM_HEALTH_FEATHER, amount=4
	end

Route118_FiveHealthFeathers::
	finditem ITEM_HEALTH_FEATHER, amount=5
	end

Route118_EventScript_Girl::
	msgbox Route118_Text_CanCrossRiversWithSurf, MSGBOX_NPC
	end

Route118_EventScript_RouteSignMauville::
	msgbox Route118_Text_RouteSignMauville, MSGBOX_SIGN
	end

Route118_EventScript_RouteSign119::
	msgbox Route118_Text_RouteSign119, MSGBOX_SIGN
	end

Route118_EventScript_Rose::
	trainerbattle_single TRAINER_ROSE, Route118_Text_RoseIntro, Route118_Text_RoseDefeat
	msgbox Route118_Text_RosePostBattle, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_Barny::
	trainerbattle_single TRAINER_BARNY, Route118_Text_BarnyIntro, Route118_Text_BarnyDefeat
	msgbox Route118_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Wade::
	trainerbattle_single TRAINER_WADE, Route118_Text_WadeIntro, Route118_Text_WadeDefeat
	msgbox Route118_Text_WadePostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Dalton::
	trainerbattle_single TRAINER_DALTON, Route118_Text_DaltonIntro, Route118_Text_DaltonDefeat
	msgbox Route118_Text_DaltonPostBattle, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_Perry::
	trainerbattle_single TRAINER_PERRY, Route118_Text_PerryIntro, Route118_Text_PerryDefeat
	msgbox Route118_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Chester::
	trainerbattle_single TRAINER_CHESTER, Route118_Text_ChesterIntro, Route118_Text_ChesterDefeat
	msgbox Route118_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Deandre::
	trainerbattle_single TRAINER_DEANDRE, Route118_Text_DeandreIntro, Route118_Text_DeandreDefeat
	msgbox Route118_Text_DeandrePostBattle, MSGBOX_AUTOCLOSE
	end

Route118_Text_CanCrossRiversWithSurf:
	.string "Even if there isn't a boat, you can\n"
	.string "cross rivers and the sea if you have\l"
	.string "a POKéMON that knows SURF.\p"
	.string "POKéMON can be counted on to do so\n"
	.string "much!$"

Route118_Text_RouteSignMauville:
	.string "ROUTE 118\n"
	.string "{LEFT_ARROW} MAUVILLE CITY$"

Route118_Text_RouteSign119:
	.string "ROUTE 118\n"
	.string "{UP_ARROW} ROUTE 119$"

