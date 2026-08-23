PetalburgCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_OnTransition
	.byte 0

PetalburgCity_OnTransition:
	setflag FLAG_VISITED_PETALBURG_CITY
	end

LucianToHauntwood::
	lock
	msgbox Text_LucianToHauntwood MSGBOX_YESNO 
	goto_if_eq VAR_RESULT, YES, TaxiToHauntwood
	end

TaxiToHauntwood::
	warp MAP_HAUNTWOOD, 11, 16
	waitstate
	release
	end

Text_LucianToHauntwood:
	.string "You ready to go to the Hauntwood?$"

Petalburg_LockedDoor_Sign::
	msgbox Petalburg_Text_LockedDoor_Sign MSGBOX_AUTOCLOSE
	end

PetalburgCity_EventScript_Boy::
	lock
	faceplayer
	msgbox PetalburgCity_Text_WaterReflection, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PetalburgCity_EventScript_GymSign::
	msgbox PetalburgCity_Text_GymSign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_CitySign::
	msgbox PetalburgCity_Text_CitySign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_Gentleman::
	msgbox PetalburgCity_Text_FullPartyExplanation, MSGBOX_NPC
	end

PetalburgCity_EventScript_WallyHouseSign::
	msgbox PetalburgCity_Text_WallyHouseSign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_Check_ToRustboro::
	goto_if_unset FLAG_RUSTBORO_PETALBURG_STRETCH, PetalburgCity_EventScript_Check_Rustboro_Petalburg
	end

PetalburgCity_EventScript_Check_Rustboro_Petalburg::
	lock
	goto_if_unset FLAG_PETALBURG_BOSS, PetalburgCity_EventScript_ToRustboro_BossUndefeated
	goto_if_lt VAR_NUMBER_OF_KEYS, 1, PetalburgCity_EventScript_Cannot_Unlock_Rustboro
	msgbox PetalburgCity_Text_To_Rustboro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PetalburgCity_EventScript_Reject_ToRustboro
	msgbox PetalburgCity_Text_Accept_Rustboro, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_PETALBURG_STRETCH
	copyvar VAR_RUSTBORO_PETALBURG_LEVEL, VAR_WORLD_DIFFICULTY
	copyvar VAR_RUSTBORO_LEVEL, VAR_WORLD_DIFFICULTY
	special DecrementPlayerKeys
	release
	end

PetalburgCity_EventScript_ToRustboro_BossUndefeated::
	msgbox PetalburgCity_Text_Boss_Undefeated, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_TurnFrom_Rustboro
	waitmovement 0
	release
	end

PetalburgCity_EventScript_Cannot_Unlock_Rustboro::
	msgbox PetalburgCity_Text_Cannot_Unlock, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_TurnFrom_Rustboro
	waitmovement 0
	release
	end

PetalburgCity_EventScript_Reject_ToRustboro::
	msgbox PetalburgCity_Text_Reject_Path, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_TurnFrom_Rustboro
	waitmovement 0
	release
	end

PetalburgCity_EventScript_Check_ToDewford::
	goto_if_unset FLAG_PETALBURG_DEWFORD_STRETCH, PetalburgCity_EventScript_Check_Petalburg_Dewford
	end

PetalburgCity_EventScript_Check_Petalburg_Dewford::
	lock
	goto_if_unset FLAG_PETALBURG_BOSS, PetalburgCity_EventScript_ToDewford_BossUndefeated
	goto_if_lt VAR_NUMBER_OF_KEYS, 1, PetalburgCity_EventScript_Cannot_Unlock_Dewford
	msgbox PetalburgCity_Text_To_Dewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PetalburgCity_EventScript_Reject_ToDewford
	msgbox PetalburgCity_Text_Accept_Dewford, MSGBOX_DEFAULT
	setflag FLAG_PETALBURG_DEWFORD_STRETCH
	copyvar VAR_PETALBURG_DEWFORD_LEVEL, VAR_WORLD_DIFFICULTY
	copyvar VAR_DEWFORD_LEVEL, VAR_WORLD_DIFFICULTY
	special DecrementPlayerKeys
	release
	end

PetalburgCity_EventScript_ToDewford_BossUndefeated::
	msgbox PetalburgCity_Text_Boss_Undefeated, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_TurnFrom_Dewford
	waitmovement 0
	release
	end

PetalburgCity_EventScript_Cannot_Unlock_Dewford::
	msgbox PetalburgCity_Text_Cannot_Unlock, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_TurnFrom_Dewford
	waitmovement 0
	release
	end

PetalburgCity_EventScript_Reject_ToDewford::
	msgbox PetalburgCity_Text_Reject_Path, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_TurnFrom_Dewford
	waitmovement 0
	release
	end

PetalburgCity_EventScript_Check_ToSlateport::
	goto_if_unset FLAG_PETALBURG_SLATEPORT_STRETCH, PetalburgCity_EventScript_Check_Petalburg_Slateport
	end

PetalburgCity_EventScript_Check_Petalburg_Slateport::
	lock
	goto_if_unset FLAG_PETALBURG_BOSS, PetalburgCity_EventScript_ToSlateport_BossUndefeated
	goto_if_lt VAR_NUMBER_OF_KEYS, 1, PetalburgCity_EventScript_Cannot_Unlock_Slateport
	msgbox PetalburgCity_Text_To_Slateport, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PetalburgCity_EventScript_Reject_ToSlateport
	setflag FLAG_PETALBURG_SLATEPORT_STRETCH
	copyvar VAR_PETALBURG_SLATEPORT_LEVEL, VAR_WORLD_DIFFICULTY
	copyvar VAR_SLATEPORT_LEVEL, VAR_WORLD_DIFFICULTY
	special DecrementPlayerKeys
	release
	end

PetalburgCity_EventScript_ToSlateport_BossUndefeated::
	msgbox PetalburgCity_Text_Boss_Undefeated, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_TurnFrom_Slateport
	waitmovement 0
	release
	end

PetalburgCity_EventScript_Cannot_Unlock_Slateport::
	msgbox PetalburgCity_Text_Cannot_Unlock, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_TurnFrom_Slateport
	waitmovement 0
	release
	end

PetalburgCity_EventScript_Reject_ToSlateport::
	msgbox PetalburgCity_Text_Reject_Path, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_TurnFrom_Slateport
	waitmovement 0
	release
	end

PetalburgCity_Movement_TurnFrom_Rustboro::
	walk_right
	step_end

PetalburgCity_Movement_TurnFrom_Dewford::
	walk_up
	step_end

PetalburgCity_Movement_TurnFrom_Slateport::
	walk_left
	step_end

Petalburg_Text_LockedDoor_Sign:
	.string "Still can't wander into people's homes.$"

PetalburgCity_Text_WaterReflection:
	.string "My face is reflected in the water.\p"
	.string "It's a shining grin full of hope…\p"
	.string "Or it could be a look of somber silence\n"
	.string "struggling with fear…\p"
	.string "What do you see reflected in your face?$"

PetalburgCity_Text_FullPartyExplanation:
	.string "Let's say you have six POKéMON.\n"
	.string "If you catch another one…\p"
	.string "It is automatically sent to a STORAGE\n"
	.string "BOX over a PC connection.$"

PetalburgCity_Text_GymSign:
	.string "PETALBURG CITY POKéMON GYM\n"
	.string "LEADER: NORMAN\l"
	.string "“A man in pursuit of power!”$"

PetalburgCity_Text_CitySign:
	.string "PETALBURG CITY\n"
	.string "“Where people mingle with nature.”$"

PetalburgCity_Text_WallyHouseSign:
	.string "WALLY'S HOUSE$"

PetalburgCity_Text_Boss_Undefeated:
	.string "There are still things I need\n"
	.string "to do here.$"

PetalburgCity_Text_Cannot_Unlock:
	.string "I have things to do elsewhere first.$"

PetalburgCity_Text_To_Rustboro:
	.string "This is the way to Rustboro City...\n"
	.string "Head this way?$"

PetalburgCity_Text_Accept_Rustboro:
	.string "Time to head for Rustboro City.$"

PetalburgCity_Text_To_Dewford:
	.string "This is the way to Dewford Town...\n"
	.string "Head this way?$"

PetalburgCity_Text_Accept_Dewford:
	.string "Time to head for Dewford Town.$"

PetalburgCity_Text_To_Slateport:
	.string "This is the way to Slateport City...\n"
	.string "Head this way?$"

PetalburgCity_Text_Accept_Slateport:
	.string "Time to head for Slateport City.$"

PetalburgCity_Text_Reject_Path:
	.string "Maybe next time.$"
