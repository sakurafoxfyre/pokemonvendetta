CargoShip_Rooms_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CargoShip_Rooms_B1F_OnTransition
	.byte 0

CargoShip_Rooms_B1F_OnTransition:
	checkflag FLAG_CARGO_RIP_RIVAL_ONE
	goto_if_eq VAR_RESULT, TRUE, RipRivalOne
	end

RipRivalOne::
	removeobject RivalOne
	end

Script_IntroPhoneCall::
	lock
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, CameraPanRival
	waitmovement 0
	msgbox Text_IntroPhoneCallPartOne MSGBOX_DEFAULT
	closemessage
	msgbox Text_IntroPhoneCallPartTwo MSGBOX_DEFAULT
	closemessage
	msgbox Text_IntroPhoneCallPartThree MSGBOX_DEFAULT
	closemessage
	msgbox Text_IntroPhoneCallPartFour MSGBOX_DEFAULT
	closemessage
	msgbox Text_IntroPhoneCallPartFive MSGBOX_DEFAULT
	closemessage
	msgbox Text_IntroPhoneCallPartSix MSGBOX_DEFAULT
	closemessage
	applymovement RivalOne, RivalGoesForWalkOne
	applymovement LOCALID_CAMERA, CameraPanPlayer
	waitmovement 0
	opendoor 22 1
	waitdooranim
	applymovement RivalOne, RivalGoesForWalkTwo
	removeobject RivalOne
	setflag FLAG_CARGO_RIP_RIVAL_ONE
	closedoor 22 1
	waitdooranim
	msgbox Text_IntroPhoneCallPartSeven MSGBOX_DEFAULT
	closemessage
	special RemoveCameraObject
	release
	end

CameraPanRival::
	walk_right
	walk_right
	walk_right
	walk_right
	delay_16
	step_end

CameraPanPlayer::
	delay_8
	walk_left
	walk_left
	walk_left
	walk_left
	delay_16
	step_end

RivalGoesForWalkOne::
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

RivalGoesForWalkTwo::
	walk_up
	step_end

Text_IntroPhoneCallPartOne:
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}TEAK:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} ...about that. How has the voyage\n"
	.string "been treating you? I remember my own\l"
	.string "journey to Hoenn, oh, some twenty years\l"
	.string "ago now.\p"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}YOUNG MAN:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} I read about that! Compared\n"
	.string "to the ship almost being upended by a\l"
	.string "Wailord and its pod, its been smooth\l"
	.string "sailing, Professor. We had to route\l"
	.string "around a Tentacruel bloom, though.\p"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}TEAK:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} That's out of season... but not\n"
	.string "unexpected, considering.\p"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}YOUNG MAN:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} The Basculin?\p"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}TEAK:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} Indeed. I can tell you're eager;\n"
	.string "I won't leave you in suspense, then.\l"
	.string "You have the Aether Balls?\l"
	.string "Put them in the device, please.$"

Text_IntroPhoneCallPartTwo:
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}The researcher does so. There's a digital{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\n"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}beeping sound, reminiscent of a{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\l"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}Pokecenter transfer device.{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}$"

Text_IntroPhoneCallPartThree:
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}TEAK:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} You're clearly aware of some of our\n"
	.string "ecological work here in Hoenn.\l"
	.string "What do you know of our purpose?\p"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}YOUNG MAN:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} Not much, Professor- and I've\n"
	.string "looked! Something about Cyndaquil?\p"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}TEAK:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} That's more than most, even inside\n"
	.string "Aether. Allow me to explain.\p"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}TEAK:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} It is well known that Pokemon, when\n"
	.string "placed in a new environment, will begin\l"
	.string "to exhibit vastly different qualities\l"
	.string "within just a few generations.\p"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}TEAK:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} Our region's Ninetales and\n"
	.string "Sandslash are among the most famous of\l"
	.string "these. To this day there is debate if\l"
	.string "they can be considered the same\l"
	.string "species at all.\p"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}TEAK:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} When I came to Hoenn in the\n"
	.string "aftermath of the Aqua incident, I\l"
	.string "brought with me a breeding pair\l"
	.string "of Quilava.\p"
	.string "Over these past decades, seven\n"
	.string "generations of Cyndaquil have hatched\l"
	.string "in the shadow of Mt. Chimney.\p"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}TEAK:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} The most incredible thing happened:\n"
	.string "they developed an innate control of the\l"
	.string "local weather, not unlike some Ninetales\l"
	.string "and the sun or snow. I call it Ashfall.$"

Text_IntroPhoneCallPartFour:
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}YOUNG MAN:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} That's incredible!\p"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}TEAK:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} It is, is it not? With our proof\n"
	.string "of concept, securing funding was a\l"
	.string "breeze, and we've expanded operations\l"
	.string "all across the region.\p"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}TEAK:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} We've even begun collaboration with\n"
	.string "Devon Corporation, which means de\l"
	.string "facto permission from Champion Stone.\p"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}TEAK:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} All across Hoenn, you'll find your\n"
	.string "compatriots studying our ecological\l"
	.string "transplants. You will join their number.\p"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}TEAK:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} I have transferred to you\n"
	.string "a young Chikorita, Fennekin, and Squirtle.\p"
	.string "Take them to Route 104, just west of\n"
	.string "Petalburg City, and release them into\l"
	.string "the wild there. Take detailed notes.\p"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}TEAK:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} Under absolutely no circumstances\n"
	.string "must your supervision falter.\p"
	.string "These Pokemon are beyond rare; they are\n"
	.string "not to be lost.\p"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}YOUNG MAN:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} I won't let you down,\n"
	.string "Professor!\p"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}TEAK:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} I trust that you won't.\p"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}A disconnection sound plays.{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\p"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}YOUNG MAN:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} 'Beyond rare' is an\n"
	.string "understatement. Hundreds of thousands\l"
	.string "of dollars, at least.\p"
	.string "If something happens to even one...\p"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}YOUNG MAN:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} Haha, that's it for my career.$"

Text_IntroPhoneCallPartFive:
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}For several moments, silence.{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}$"

Text_IntroPhoneCallPartSix:
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}YOUNG MAN:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} ...I need some air.$"

Text_IntroPhoneCallPartSeven:
	.string "{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} ...Now, isn't this interesting.$"

Script_RivalCatchesTheft::
	lock
	opendoor 22 1
	waitdooranim
	setobjectxy RivalTwo, 22, 1
	applymovement RivalTwo, RivalCatchesThiefOne
	waitmovement 0
	closedoor 22 1
	waitdooranim
	msgbox Text_StopThief MSGBOX_DEFAULT
	closemessage
	applymovement RivalTwo, RivalCatchesThiefTwo
	applymovement LOCALID_PLAYER, PlayerLooksUp
	waitmovement 0
	msgbox Text_Struggle MSGBOX_DEFAULT
	closemessage
	applymovement RivalTwo, RivalStepsBack
	applymovement LOCALID_PLAYER, PlayerStepsBack
	waitmovement 0
	msgbox Text_RivalPlayerArgueOne MSGBOX_DEFAULT
	closemessage
	call Script_RivalPlayerArgueTwo
	msgbox Text_RivalPlayerArgueThree MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_RIVALSQUIRTLE, CargoShip_RivalBattle_Text_Intro, CargoShip_RivalBattle_Text_Defeated
	call Script_RivalCatchesTheftTwo
	end

Script_RivalCatchesTheftTwo::
	msgbox Text_RivalPlayerArgueFour MSGBOX_DEFAULT
	closemessage
	applymovement RivalTwo, RivalLosesBattle
	waitmovement 0
	applymovement LOCALID_PLAYER, PlayerWinsBattle
	waitmovement 0
	opendoor 22 1
	waitdooranim
	applymovement RivalTwo, RivalBeginsToSpeak
	msgbox Text_RivalPlayerArgueFive MSGBOX_DEFAULT
	closemessage
	call PlayerGetsLastWordOne
	applymovement LOCALID_PLAYER, PlayerGetsLastWordTwo
	waitmovement 0
//	warpspinenter CargoShip_Corridors_B1F, 11, 8
	release
	end

Script_RivalPlayerArgueTwo::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RivalPlayerArgueTwoMale
	goto_if_eq VAR_RESULT, FEMALE, RivalPlayerArgueTwoFemale

RivalPlayerArgueTwoMale::
	msgbox Text_RivalPlayerArgueTwoMale
	closemessage
	return

RivalPlayerArgueTwoFemale::
	msgbox Text_RivalPlayerArgueTwoFemale
	closemessage
	return

RivalCatchesThiefOne::
	walk_down
	step_end

RivalCatchesThiefTwo::
	jump_in_place_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_down
	step_end

PlayerLooksUp::
	face_up
	step_end

RivalStepsBack::
	delay_16
	walk_fast_up
	face_down
	step_end

PlayerStepsBack::
	delay_16
	walk_fast_down
	face_up
	step_end

RivalLosesBattle::
	delay_16
	walk_slow_left
	face_down
	face_right
	step_end

PlayerWinsBattle::
	delay_16
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

RivalBeginsToSpeak::
	walk_in_place_right
	step_end

PlayerGetsLastWordTwo::
	walk_up
	step_end

Text_StopThief:
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}YOUNG MAN:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} Hey! What are you doing?!$"

Text_Struggle:
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}There's a brief struggle.{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\n"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}A pokeball rolls under the bed;{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\l"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}the young man secures the other.{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}$"

Text_RivalPlayerArgueOne:
	.string "{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} Tch. Guy like you, thought\n"
	.string "you'd take more time.\p"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}YOUNG MAN:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} You- did you just steal\n"
	.string "a Pokemon?!\p"
	.string "{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} You were going to release it\n"
	.string "anyway.\p"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}YOUNG MAN:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} That doesn't matter! You-\n"
	.string "put the ball down- you're under arrest!$"

Text_RivalPlayerArgueTwoMale:
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}YOUNG MAN:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} Hey, Pokemon- you're being\n"
	.string "stolen! You don't need to fight for him!\p"
	.string "{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} Nonsense. You have two options:\n"
	.string "let this coward release you into the wild\l"
	.string "and be studied, or join me as I work\l"
	.string "to become the very strongest.$"

Text_RivalPlayerArgueTwoFemale:
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}YOUNG MAN:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} Hey, Pokemon- you're being\n"
	.string "stolen! You don't need to fight for her!\p"
	.string "{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} Nonsense. You have two options:\n"
	.string "let this coward release you into the wild\l"
	.string "and be studied, or join me as I work\l"
	.string "to become the very strongest.$"

Text_RivalPlayerArgueThree:
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}YOUNG MAN:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} What...?\p"
	.string "{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} Surprised? You Aether types are\n"
	.string "all the same. You have your noses buried\l"
	.string "so deep in what's possible, you can't\l"
	.string "see what's obvious.\p"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}YOUNG MAN:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} Oh? And what's that, huh?\p"
	.string "{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} Only the weak cling to rules!$"

CargoShip_RivalBattle_Text_Intro:
	.string "I'll stop you myself!$"

CargoShip_RivalBattle_Text_Defeated:
	.string "I was in the right, how could I lose...?$"

Text_RivalPlayerArgueFour:
	.string "{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} I win. You lose. Stand aside,\n"
	.string "or you'll regret it.$"

Text_RivalPlayerArgueFive:
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}YOUNG MAN:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} I'm going to catch you.\p"
	.string "{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} ... Sure, dude.$"

PlayerGetsLastWordOne::
	multichoice 16, 0, MULTI_BRIAR_RIVAL, TRUE
	case 0, CargoShip_EventScript_LastWord_Sorry
	case 1, CargoShip_EventScript_LastWord_SureDude
	return

CargoShip_EventScript_LastWord_Sorry::
	setvar VAR_KARMA, 13
	return

CargoShip_EventScript_LastWord_SureDude::
	setvar VAR_KARMA, 7
	return
