RustboroCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
	.byte 0

RustboroCity_OnTransition:
	setflag FLAG_VISITED_RUSTBORO_CITY
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	end

RustboroCity_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

RustboroCity_OnFrame:
	.2byte 0

RustboroSignDontEnter::
	msgbox Rustboro_Text_SignDontEnter MSGBOX_AUTOCLOSE
	end

RustboroCity_EventScript_FatMan::
	lock
	faceplayer
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_DevonEmployee2::
	lock
	faceplayer
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Woman::
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
	end

RustboroCity_EventScript_Man1::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Man1HaveBadge::
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Boy2::
	lock
	faceplayer
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Twin::
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
	end

RustboroCity_EventScript_NinjaBoy::
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
	end

RustboroCity_EventScript_TunnelSign::
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
	end

RustboroCity_EventScript_DevonCorpSign::
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_GymSign::
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CitySign::
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
	end

RustboroCity_EventScript_TrainersSchoolSign::
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CuttersHouseSign::
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
	end

RustboroCity_EventScript_LittleBoy::
	lock
	faceplayer
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
	applymovement LOCALID_RUSTBORO_LITTLE_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
	applymovement LOCALID_RUSTBORO_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_EventScript_Man2::
	lock
	faceplayer
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Boy1::
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
	end

RustboroCity_EventScript_Check_ToFallarbor::
	goto_if_unset FLAG_FALLARBOR_RUSTBORO_STRETCH, RustboroCity_EventScript_Check_Fallarbor_Rustboro
	end

RustboroCity_EventScript_Check_Fallarbor_Rustboro::
	lock
	goto_if_unset FLAG_RUSTBORO_BOSS, RustboroCity_EventScript_ToFallarbor_BossUndefeated
	goto_if_lt VAR_NUMBER_OF_KEYS, 1, RustboroCity_EventScript_Cannot_Unlock_Fallarbor
	@ msgbox RustboroCity_Text_To_Fallarbor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_EventScript_Reject_ToFallarbor
	copyvar VAR_FALLARBOR_RUSTBORO_LEVEL, VAR_WORLD_DIFFICULTY
	special DecrementPlayerKeys
	release
	end

RustboroCity_EventScript_ToFallarbor_BossUndefeated::
	@ msgbox RustboroCity_Text_Boss_Undefeated, MSGBOX_DEFAULT
	@ applymovement LOCALID_PLAYER, RustboroCity_Movement_TurnFrom_Fallarbor
	waitmovement 0
	release
	end

RustboroCity_EventScript_Cannot_Unlock_Fallarbor::
	@ msgbox RustboroCity_Text_Cannot_Unlock, MSGBOX_DEFAULT
	@ applymovement LOCALID_PLAYER, RustboroCity_Movement_TurnFrom_Fallarbor
	waitmovement 0
	release
	end

RustboroCity_EventScript_Reject_ToFallarbor::
	@ msgbox RustboroCity_Text_Reject_Path, MSGBOX_DEFAULT
	@ applymovement LOCALID_PLAYER, RustboroCity_Movement_TurnFrom_Fallarbor
	waitmovement 0
	release
	end

RustboroCity_EventScript_Check_ToMauville::
	goto_if_unset FLAG_RUSTBORO_MAUVILLE_STRETCH, RustboroCity_EventScript_Check_Rustboro_Mauville
	end

RustboroCity_EventScript_Check_Rustboro_Mauville::
	lock
	@ goto_if_unset FLAG_RUSTBORO_BOSS, RustboroCity_EventScript_ToMauville_BossUndefeated
	@ goto_if_lt VAR_NUMBER_OF_KEYS, 1 RustboroCity_EventScript_Cannot_Unlock_Mauville
	@ msgbox RustboroCity_Text_To_Mauville, MSGBOX_YESNO
	@ goto_if_eq VAR_RESULT, NO, RustboroCity_EventScript_Reject_ToMauville
	copyvar VAR_RUSTBORO_MAUVILLE_LEVEL, VAR_WORLD_DIFFICULTY
	special DecrementPlayerKeys
	release
	end

Rustboro_Text_SignDontEnter:
	.string "No soliciting!$"

RustboroCity_Text_WeShortenItToDevon:
	.string "The DEVON CORPORATION…\n"
	.string "We all just shorten it to DEVON.\p"
	.string "That company makes all sorts of\n"
	.string "convenient products.$"

RustboroCity_Text_HaveYouChallengedGym:
	.string "Have you taken the POKéMON GYM\n"
	.string "challenge?\p"
	.string "When you get that shiny GYM BADGE\n"
	.string "in hand, I guess TRAINERS begin to\l"
	.string "realize what is required of them.$"

RustboroCity_Text_HeyThatsRustborosGymBadge:
	.string "Hey, that's RUSTBORO's GYM BADGE!\p"
	.string "Out of all the POKéMON GYM BADGES,\n"
	.string "RUSTBORO's is the coolest, I'd say.$"

RustboroCity_Text_YoureNewAroundHere:
	.string "Oh? Who might you be?\n"
	.string "You're a new face around these parts.\p"
	.string "Have you just transferred into the\n"
	.string "POKéMON TRAINER'S SCHOOL?$"

RustboroCity_Text_GymLeaderIsntEasyWithFire:
	.string "I challenged the GYM LEADER, but…\p"
	.string "It's not going to be easy winning with\n"
	.string "my FIRE-type POKéMON…\p"
	.string "FIRE-type POKéMON don't match up\n"
	.string "well against ROCK-type POKéMON…$"

RustboroCity_Text_MrBrineyWalksInTheTunnel:
	.string "The old sailor MR. BRINEY lives in\n"
	.string "a cottage by the sea.\p"
	.string "He goes for walks in the tunnel every\n"
	.string "so often.$"

RustboroCity_Text_MrBrineyLovesPeeko:
	.string "The old sailor MR. BRINEY lives in\n"
	.string "a cottage by the sea.\p"
	.string "He said he was going shopping in\n"
	.string "SLATEPORT for his pet, PEEKO.\p"
	.string "That old sea dog, he must really love\n"
	.string "that PEEKO.$"

RustboroCity_Text_WowYouHavePokemon:
	.string "Wow, you have POKéMON with you, too.\p"
	.string "When I get bigger, I'm going to go\n"
	.string "places with POKéMON, too.$"

RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
	.string "POKéMON TRAINER'S SCHOOL!\p"
	.string "If I go to this school, will I be able\n"
	.string "to catch rare POKéMON easily?$"

RustboroCity_Text_PokemonCanChangeLookFromExp:
	.string "If a POKéMON gains experience in\n"
	.string "battles, it can sometimes change in\l"
	.string "the way it looks.$"

RustboroCity_Text_PokemonChangeShape:
	.string "A POKéMON changes shape?\n"
	.string "If one did that, I would be shocked!$"

RustboroCity_Text_TradePokemonGrowFast:
	.string "A POKéMON you get in a trade from\n"
	.string "someone grows fast.\p"
	.string "But if you don't have certain GYM\n"
	.string "BADGES, it may not obey you…$"

RustboroCity_Text_TunnelNearingCompletion:
	.string "“Timesaving tunnel nearing\n"
	.string "completion!”\p"
	.string "…Is what it says on the sign, but\n"
	.string "there's also a big “X” splashed\l"
	.string "across it in red paint…$"

RustboroCity_Text_DevonCorpSign:
	.string "DEVON CORPORATION\p"
	.string "“For all your living needs, we make\n"
	.string "it all.”$"

RustboroCity_Text_GymSign:
	.string "RUSTBORO CITY POKéMON GYM\n"
	.string "LEADER: ROXANNE\p"
	.string "“The ROCK-loving honors student!”$"

RustboroCity_Text_CitySign:
	.string "RUSTBORO CITY\p"
	.string "“The city probing the integration of\n"
	.string "nature and science.”$"

RustboroCity_Text_TrainersSchoolSign:
	.string "POKéMON TRAINER'S SCHOOL\p"
	.string "“We'll teach you anything about\n"
	.string "POKéMON!”$"

RustboroCity_Text_CuttersHouse:
	.string "CUTTER'S HOUSE$"

RustboroCity_Text_YouCanHave2On2Battle:
	.string "Did you know this?\p"
	.string "You can have a 2-on-2 battle even\n"
	.string "if you're not with another TRAINER.\p"
	.string "If you catch the eyes of two TRAINERS\n"
	.string "when you have two or more POKéMON,\l"
	.string "they'll both challenge you.\p"
	.string "Don't you think it'd be cool if you\n"
	.string "could beat two TRAINERS by yourself?$"
