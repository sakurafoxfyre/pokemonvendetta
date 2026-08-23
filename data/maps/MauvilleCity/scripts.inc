MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	setflag FLAG_SYS_TV_START
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_Check_ToRustboro::
	goto_if_unset FLAG_RUSTBORO_MAUVILLE_STRETCH, MauvilleCity_EventScript_Check_Rustboro_Mauville
	end

MauvilleCity_EventScript_Check_Rustboro_Mauville::
	lock
	goto_if_unset FLAG_MAUVILLE_BOSS, MauvilleCity_EventScript_ToRustboro_BossUndefeated
	goto_if_lt VAR_NUMBER_OF_KEYS, 1, MauvilleCity_EventScript_Cannot_Unlock_Rustboro
	msgbox MauvilleCity_Text_To_Rustboro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_Reject_ToRustboro
	copyvar VAR_RUSTBORO_MAUVILLE_LEVEL, VAR_WORLD_DIFFICULTY
	copyvar VAR_RUSTBORO_LEVEL, VAR_WORLD_DIFFICULTY
	special DecrementPlayerKeys
	release
	end

MauvilleCity_EventScript_ToRustboro_BossUndefeated::
	msgbox MauvilleCity_Text_Boss_Undefeated, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_TurnFrom_Rustboro
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Cannot_Unlock_Rustboro::
	msgbox MauvilleCity_Text_Cannot_Unlock, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_TurnFrom_Rustboro
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Reject_ToRustboro::
	msgbox MauvilleCity_Text_Reject_Path, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_TurnFrom_Rustboro
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Check_ToLavaridge::
	goto_if_unset FLAG_LAVARIDGE_MAUVILLE_STRETCH, MauvilleCity_EventScript_Check_Lavaridge_Mauville
	end

MauvilleCity_EventScript_Check_Lavaridge_Mauville::
	lock
	goto_if_unset FLAG_MAUVILLE_BOSS, MauvilleCity_EventScript_ToLavaridge_BossUndefeated
	goto_if_lt VAR_NUMBER_OF_KEYS, 1, MauvilleCity_EventScript_Cannot_Unlock_Lavaridge
	msgbox MauvilleCity_Text_To_Lavaridge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_Reject_ToLavaridge
	setflag FLAG_LAVARIDGE_MAUVILLE_STRETCH
	copyvar VAR_LAVARIDGE_MAUVILLE_LEVEL, VAR_WORLD_DIFFICULTY
	copyvar VAR_LAVARIDGE_LEVEL, VAR_WORLD_DIFFICULTY
	special DecrementPlayerKeys
	release
	end

MauvilleCity_EventScript_ToLavaridge_BossUndefeated::
	msgbox MauvilleCity_Text_Boss_Undefeated, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_TurnFrom_Lavaridge
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Cannot_Unlock_Lavaridge::
	msgbox MauvilleCity_Text_Cannot_Unlock, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_TurnFrom_Lavaridge
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Reject_ToLavaridge::
	msgbox MauvilleCity_Text_Reject_Path, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_TurnFrom_Lavaridge
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Check_ToMtPyre::
	goto_if_unset FLAG_MAUVILLE_MTPYRE_STRETCH, MauvilleCity_EventScript_Check_Mauville_MtPyre
	end

MauvilleCity_EventScript_Check_Mauville_MtPyre::
	lock
	goto_if_unset FLAG_MAUVILLE_BOSS, MauvilleCity_EventScript_ToMtPyre_BossUndefeated
	goto_if_lt VAR_NUMBER_OF_KEYS, 1, MauvilleCity_EventScript_Cannot_Unlock_MtPyre
	msgbox MauvilleCity_Text_To_MtPyre, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_Reject_ToMtPyre
	setflag FLAG_MAUVILLE_MTPYRE_STRETCH
	copyvar VAR_MAUVILLE_MTPYRE_LEVEL, VAR_WORLD_DIFFICULTY
	copyvar VAR_MTPYRE_LEVEL, VAR_WORLD_DIFFICULTY
	release
	end

MauvilleCity_EventScript_ToMtPyre_BossUndefeated::
	msgbox MauvilleCity_Text_Boss_Undefeated, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_TurnFrom_MtPyre
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Cannot_Unlock_MtPyre::
	msgbox MauvilleCity_Text_Cannot_Unlock, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_TurnFrom_MtPyre
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Reject_ToMtPyre::
	msgbox MauvilleCity_Text_Reject_Path, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_TurnFrom_MtPyre
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Check_ToSlateport::
	goto_if_unset FLAG_SLATEPORT_MAUVILLE_STRETCH, MauvilleCity_EventScript_Check_Slateport_Mauville
	end

MauvilleCity_EventScript_Check_Slateport_Mauville::
	lock
	goto_if_unset FLAG_MAUVILLE_BOSS, MauvilleCity_EventScript_ToSlateport_BossUndefeated
	goto_if_lt VAR_NUMBER_OF_KEYS, 1, MauvilleCity_EventScript_Cannot_Unlock_Slateport
	msgbox MauvilleCity_Text_To_Slateport, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_Reject_ToSlateport
	setflag FLAG_SLATEPORT_MAUVILLE_STRETCH
	copyvar VAR_SLATEPORT_MAUVILLE_LEVEL, VAR_WORLD_DIFFICULTY
	copyvar VAR_SLATEPORT_LEVEL, VAR_WORLD_DIFFICULTY
	special DecrementPlayerKeys
	release
	end

MauvilleCity_EventScript_ToSlateport_BossUndefeated::
	msgbox MauvilleCity_Text_Boss_Undefeated, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_TurnFrom_Slateport
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Cannot_Unlock_Slateport::
	msgbox MauvilleCity_Text_Cannot_Unlock, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_TurnFrom_Slateport
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Reject_ToSlateport::
	msgbox MauvilleCity_Text_Reject_Path, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_TurnFrom_Slateport
	waitmovement 0
	release
	end

MauvilleCity_Movement_TurnFrom_Rustboro::
	walk_right
	step_end

MauvilleCity_Movement_TurnFrom_Lavaridge::
	walk_down
	step_end

MauvilleCity_Movement_TurnFrom_MtPyre::
	walk_left
	step_end

MauvilleCity_Movement_TurnFrom_Slateport::
	walk_up
	step_end

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "WATTSON: Oh, {PLAYER}{KUN}!\n"
	.string "You look like you have a lot of zip!\l"
	.string "That's a good thing, wahahahaha!\p"
	.string "Fine! I've decided!\n"
	.string "I need a favor, {PLAYER}{KUN}!\p"
	.string "MAUVILLE CITY has an underground\n"
	.string "sector called NEW MAUVILLE.\p"
	.string "{PLAYER}{KUN}, I'd like you to go there and\n"
	.string "switch off the GENERATOR.\p"
	.string "The GENERATOR has been running a bit\n"
	.string "haywire. It's getting unsafe.\p"
	.string "Here, this is the KEY to get into\n"
	.string "NEW MAUVILLE.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "WATTSON: Don't you worry about it.\n"
	.string "It won't be a challenge to you.\p"
	.string "The entrance to NEW MAUVILLE is just\n"
	.string "a short SURF away from ROUTE 110.\p"
	.string "That's it, then, you have my trust!\n"
	.string "Wahahahaha!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "WATTSON: Wahahahaha!\p"
	.string "I knew it, {PLAYER}{KUN}! I knew I'd made\n"
	.string "the right choice asking you!\p"
	.string "This is my thanks--a TM containing\n"
	.string "THUNDERBOLT!\p"
	.string "Go on, you've earned it!$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "WATTSON: Wahahahaha!\p"
	.string "It pleases me to no end to see\n"
	.string "the young step up and take charge!$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "You know, it's cool to have POKéMON\n"
	.string "battles and stuff…\p"
	.string "But if your POKéMON gets hurt,\n"
	.string "you have to nurse it back to health.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "The roads of this town stretch north\n"
	.string "and south, and east and west.\p"
	.string "Because of that, we get all sorts of\n"
	.string "people coming through.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "Have you been to RYDEL'S CYCLES yet?\p"
	.string "RYDEL, the owner, is a very generous\n"
	.string "man.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "Even if you're riding a BIKE,\n"
	.string "wild POKéMON could jump you.$"

MauvilleCity_Text_CitySign:
	.string "MAUVILLE CITY\n"
	.string "“The bright and shiny city of fun!”$"

MauvilleCity_Text_GymSign:
	.string "MAUVILLE CITY POKéMON GYM\n"
	.string "LEADER: WATTSON\l"
	.string "“The cheerfully electrifying man!”$"

MauvilleCity_Text_BikeShopSign:
	.string "“Ride in gravel and shake up your\n"
	.string "soul!”\l"
	.string "RYDEL'S CYCLES$"

MauvilleCity_Text_GameCornerSign:
	.string "“The play spot for all!”\n"
	.string "MAUVILLE GAME CORNER$"

MauvilleCity_Text_ExplainTV:
	.string "Hi, do you check out TV at all?\p"
	.string "They've added a bunch of cool new\n"
	.string "shows recently.\p"
	.string "TV is so cool. I've seen my friends on\n"
	.string "TV just out of the blue.\p"
	.string "And, sometimes, they even put you on TV\n"
	.string "without telling you.\p"
	.string "I wish I would be on TV sometime.\p"
	.string "That's why I think you should check\n"
	.string "out TVs whenever you can.$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "Hi, have you been checking out TVs?$"

MauvilleCity_Text_Boss_Undefeated:
	.string "There are still things I need\n"
	.string "to do here.$"

MauvilleCity_Text_Cannot_Unlock:
	.string "I have things to do elsewhere first.$"

MauvilleCity_Text_To_Rustboro:
	.string "This is the way to Rustboro City...\n"
	.string "Head this way?$"

MauvilleCity_Text_Accept_Rustboro:
	.string "Time to head for Rustboro City.$"

MauvilleCity_Text_To_Lavaridge:
	.string "This is the way to Lavaridge Town...\n"
	.string "Head this way?$"

MauvilleCity_Text_Accept_Lavaridge:
	.string "Time to head to Lavaridge Town.$"

MauvilleCity_Text_To_MtPyre:
	.string "This is the way to Mt. Pyre...\n"
	.string "Head this way?$"

MauvilleCity_Text_Accept_MtPyre:
	.string "Time to head to Mt. Pyre.$"

MauvilleCity_Text_To_Slateport:
	.string "This is the way to Slateport City...\n"
	.string "Head this way?$"

MauvilleCity_Text_Accept_Slateport:
	.string "Time to head for Slateport City.$"

MauvilleCity_Text_Reject_Path:
	.string "Maybe next time.$"
