Route115_MapScripts::
	.byte 0

NorthIslandApples::
	finditem ITEM_SWEET_APPLE
	finditem ITEM_TART_APPLE
	finditem ITEM_SYRUPY_APPLE
	end

Route115_EventScript_Nugget::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, Route115_Nugget
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, Route115_Nugget
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, Route115_Nugget
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, Route115_Nugget
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, Route115_Nugget
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, Route115_Nugget
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, Route115_Nugget
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, Route115_BigNugget
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, Route115_BigNugget
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, Route115_BigNugget
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, Route115_BigNugget
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, Route115_BigNugget
	end

Route115_Nugget::
	finditem ITEM_NUGGET, amount=1
	end

Route115_BigNugget::
	finditem ITEM_BIG_NUGGET, amount=1
	end

Route115_EventScript_Woman::
	msgbox Route115_Text_NeverKnowWhenCavePokemonWillAppear, MSGBOX_NPC
	end

Route115_EventScript_RouteSignRustboro::
	msgbox Route115_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route115_EventScript_MeteorFallsSign::
	msgbox Route115_Text_MeteorFallsSign, MSGBOX_SIGN
	end

Route115_EventScript_Timothy::
	trainerbattle_single TRAINER_TIMOTHY, Route115_Text_TimothyIntro, Route115_Text_TimothyDefeat
	msgbox Route115_Text_TimothyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_Koichi::
	trainerbattle_single TRAINER_KOICHI, Route115_Text_KoichiIntro, Route115_Text_KoichiDefeat
	msgbox Route115_Text_KoichiPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Nob::
	trainerbattle_single TRAINER_NOB, Route115_Text_NobIntro, Route115_Text_NobDefeat
	msgbox Route115_Text_NobPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_Cyndy::
	trainerbattle_single TRAINER_CYNDY, Route115_Text_CyndyIntro, Route115_Text_CyndyDefeat
	msgbox Route115_Text_CyndyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_Hector::
	trainerbattle_single TRAINER_HECTOR, Route115_Text_HectorIntro, Route115_Text_HectorDefeat
	msgbox Route115_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Kyra::
	trainerbattle_single TRAINER_KYRA, Route115_Text_KyraIntro, Route115_Text_KyraDefeat
	msgbox Route115_Text_KyraPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Jaiden::
	trainerbattle_single TRAINER_JAIDEN, Route115_Text_JaidenIntro, Route115_Text_JaidenDefeat
	msgbox Route115_Text_JaidenPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Alix::
	trainerbattle_single TRAINER_ALIX, Route115_Text_AlixIntro, Route115_Text_AlixDefeat
	msgbox Route115_Text_AlixPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Helene::
	trainerbattle_single TRAINER_HELENE, Route115_Text_HeleneIntro, Route115_Text_HeleneDefeat
	msgbox Route115_Text_HelenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Marlene::
	trainerbattle_single TRAINER_MARLENE, Route115_Text_MarleneIntro, Route115_Text_MarleneDefeat
	msgbox Route115_Text_MarlenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_Text_NeverKnowWhenCavePokemonWillAppear:
	.string "Exploring a cave isn't like walking\n"
	.string "on a road.\p"
	.string "You never know when wild POKéMON will\n"
	.string "appear. It's full of suspense.$"

Route115_Text_RouteSignRustboro:
	.string "ROUTE 115\n"
	.string "{DOWN_ARROW} RUSTBORO CITY$"

Route115_Text_MeteorFallsSign:
	.string "METEOR FALLS\n"
	.string "FALLARBOR TOWN THROUGH HERE$"

