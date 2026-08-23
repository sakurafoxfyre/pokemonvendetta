Route112_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_OnTransition
	.byte 0

Route112_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

Route112_EventScript_Stardust::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, Route112_Stardust
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, Route112_Stardust
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, Route112_Stardust
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, Route112_Stardust
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, Route112_Stardust
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, Route112_Stardust
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, Route112_Stardust
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, Route112_Star_Piece
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, Route112_Star_Piece
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, Route112_Star_Piece
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, Route112_Star_Piece
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, Route112_Star_Piece
	end

Route112_Stardust::
	finditem ITEM_STARDUST, amount=1
	end

Route112_Star_Piece::
	finditem ITEM_STAR_PIECE, amount=1
	end

Route112_EventScript_MtChimneyCableCarSign::
	msgbox Route112_Text_MtChimneyCableCarSign, MSGBOX_SIGN
	end

Route112_EventScript_MtChimneySign::
	msgbox Route112_Text_MtChimneySign, MSGBOX_SIGN
	end

Route112_EventScript_RouteSignLavaridge::
	msgbox Route112_Text_RouteSignLavaridge, MSGBOX_SIGN
	end

Route112_EventScript_Hiker::
	end

Route112_EventScript_Brice::
	trainerbattle_single TRAINER_BRICE, Route112_Text_BriceIntro, Route112_Text_BriceDefeat
	msgbox Route112_Text_BricePostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Trent::
	trainerbattle_single TRAINER_TRENT, Route112_Text_TrentIntro, Route112_Text_TrentDefeat
	msgbox Route112_Text_TrentPostBattle, MSGBOX_DEFAULT
	release
	end

Route112_EventScript_Larry::
	trainerbattle_single TRAINER_LARRY, Route112_Text_LarryIntro, Route112_Text_LarryDefeat
	msgbox Route112_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL, Route112_Text_CarolIntro, Route112_Text_CarolDefeat
	msgbox Route112_Text_CarolPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Bryant::
	trainerbattle_single TRAINER_BRYANT, Route112_Text_BryantIntro, Route112_Text_BryantDefeat
	msgbox Route112_Text_BryantPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Shayla::
	trainerbattle_single TRAINER_SHAYLA, Route112_Text_ShaylaIntro, Route112_Text_ShaylaDefeat
	msgbox Route112_Text_ShaylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_Text_MtChimneyCableCarSign:
	.string "MT. CHIMNEY CABLE CAR\n"
	.string "“A short walk {UP_ARROW} way!”$"

Route112_Text_MtChimneySign:
	.string "MT. CHIMNEY\p"
	.string "“For LAVARIDGE TOWN or the summit,\n"
	.string "please take the CABLE CAR.”$"

Route112_Text_RouteSignLavaridge:
	.string "ROUTE 112\n"
	.string "{LEFT_ARROW} LAVARIDGE TOWN$"

