SootopolisCity_MapScripts::
	.byte 
	
Sootopolis_EventScript_EvoItems::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration Sootopolis_EvoItems
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Sootopolis_EvoItems:
	.2byte ITEM_DRAGON_SCALE
	.2byte ITEM_PRISM_SCALE
	pokemartlistend

Sootopolis_EventScript_MegaStones::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration Sootopolis_MegaStones
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Sootopolis_MegaStones:
	.2byte ITEM_GENGARITE
	.2byte ITEM_GARDEVOIRITE
	.2byte ITEM_AMPHAROSITE
	.2byte ITEM_VENUSAURITE
	.2byte ITEM_CHARIZARDITE_X
	.2byte ITEM_CHARIZARDITE_Y
	.2byte ITEM_BLASTOISINITE
	.2byte ITEM_MEWTWONITE_X
	.2byte ITEM_MEWTWONITE_Y
	.2byte ITEM_BLAZIKENITE
	.2byte ITEM_HOUNDOOMINITE
	.2byte ITEM_AGGRONITE
	.2byte ITEM_BANETTITE
	.2byte ITEM_TYRANITARITE
	.2byte ITEM_SCIZORITE
	.2byte ITEM_PINSIRITE
	.2byte ITEM_AERODACTYLITE
	.2byte ITEM_LUCARIONITE
	.2byte ITEM_GYARADOSITE
	.2byte ITEM_ABSOLITE
	.2byte ITEM_ALAKAZITE
	.2byte ITEM_HERACRONITE
	.2byte ITEM_MAWILITE
	.2byte ITEM_MANECTITE
	.2byte ITEM_GARCHOMPITE
	.2byte ITEM_LATIASITE
	.2byte ITEM_LATIOSITE
	.2byte ITEM_SWAMPERTITE
	.2byte ITEM_SCEPTILITE
	.2byte ITEM_SABLENITE
	.2byte ITEM_ALTARIANITE
	.2byte ITEM_GALLADITE
	.2byte ITEM_METAGROSSITE
	.2byte ITEM_SHARPEDONITE
	.2byte ITEM_SLOWBRONITE
	.2byte ITEM_STEELIXITE
	.2byte ITEM_GLALITITE
	.2byte ITEM_DIANCITE
	.2byte ITEM_CAMERUPTITE
	.2byte ITEM_SALAMENCITE
	.2byte ITEM_CLEFABLITE
	.2byte ITEM_VICTREEBELITE
	.2byte ITEM_STARMINITE
	.2byte ITEM_DRAGONINITE
	.2byte ITEM_MEGANIUMITE
	.2byte ITEM_FERALIGITE
	.2byte ITEM_SKARMORITE
	.2byte ITEM_FROSLASSITE
	.2byte ITEM_EXCADRITE
	.2byte ITEM_EELEKTROSSITE
	.2byte ITEM_CHANDELURITE
	.2byte ITEM_DELPHOXITE
	.2byte ITEM_GRENINJITE
	.2byte ITEM_MALAMARITE
	.2byte ITEM_BARBARACITE
	.2byte ITEM_DRAGALGITE
	.2byte ITEM_DRAMPANITE
	pokemartlistend

SootopolisCity_EventScript_Kiri::
	lock
	faceplayer
	@KiriGiveBerry is currently throwing an error so commenting out the call
	@SootopolisCity_EventScript_KiriGiveBerry
	end

@ Gives 2 berries daily. First ranges from FIRST_KIRI_BERRY to LAST_KIRI_BERRY, second is always Figy or Iapapa
SootopolisCity_EventScript_KiriGiveBerry::
	dotimebasedevents
	special GetPlayerBigGuyGirlString
	goto_if_set FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY, SootopolisCity_EventScript_KiriReceivedBerry
	msgbox SootopolisCity_Text_NameIsKiriHaveOneOfThese, MSGBOX_DEFAULT
	random NUM_KIRI_BERRIES
	addvar VAR_RESULT, NUM_KIRI_BERRIES_SKIPPED
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY
	msgbox SootopolisCity_Text_GiveYouThisBerryToo, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 0, SootopolisCity_EventScript_GiveFigyBerry
	goto_if_eq VAR_RESULT, 1, SootopolisCity_EventScript_GiveIapapaBerry
	end

SootopolisCity_EventScript_GiveFigyBerry::
	giveitem ITEM_FIGY_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GiveIapapaBerry::
	giveitem ITEM_IAPAPA_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_KiriReceivedBerry::
	msgbox SootopolisCity_Text_LikeSeasonBornIn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_EventScript_KiriLikeSeasonBornIn
	msgbox SootopolisCity_Text_OhDoesntMatter, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_KiriLikeSeasonBornIn::
	msgbox SootopolisCity_Text_ThenILoveAutumn, MSGBOX_DEFAULT
	release
	end


SootopolisCity_EventScript_Man::
	lock
	faceplayer
	msgbox SootopolisCity_Text_NoOrdinaryTourist, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman1::
	lock
	faceplayer
	msgbox SootopolisCity_Text_SootopolisSkyBeautiful, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_NinjaBoy::
	lockall
	applymovement LOCALID_SOOTOPOLIS_NINJA_BOY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SootopolisCity_Text_WonderWhatWorldIsLike, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_NINJA_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_Boy1::
	lockall
	applymovement LOCALID_SOOTOPOLIS_BOY_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SootopolisCity_Text_PhysicallyFitLivingHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_BOY_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_GymSign::
	msgbox SootopolisCity_Text_GymSign, MSGBOX_SIGN
	end

SootopolisCity_EventScript_CitySign::
	msgbox SootopolisCity_Text_CitySign, MSGBOX_SIGN
	end

SootopolisCity_Text_GymSign:
	.string "SOOTOPOLIS CITY POKéMON GYM\n"
	.string "LEADER: JUAN\p"
	.string "“The GYM LEADER with the beauty\n"
	.string "of pure water!”$"

SootopolisCity_Text_CitySign:
	.string "SOOTOPOLIS CITY\p"
	.string "“The mystical city where history\n"
	.string "slumbers.”$"

SootopolisCity_Text_DoorIsClosed:
	.string "The door is closed.$"

SootopolisCity_Text_PhysicallyFitLivingHere:
	.string "Diving in the sea. Climbing up and\n"
	.string "down stairs all the time…\p"
	.string "If you live in this town, you end up\n"
	.string "getting physically fit.$"

SootopolisCity_Text_FlyingMonStoppedRampage:
	.string "That flying POKéMON came down from\n"
	.string "the sky and stopped the rampaging\l"
	.string "POKéMON…$"

SootopolisCity_Text_WonderWhatWorldIsLike:
	.string "I… I've never been out of this city.\p"
	.string "I wonder what the world is like on\n"
	.string "the other side of this round sky?$"

SootopolisCity_Text_SootopolisDidntGetWrecked:
	.string "SOOTOPOLIS CITY didn't get wrecked!$"

SootopolisCity_Text_NoOrdinaryTourist:
	.string "Hm!\n"
	.string "You've come all the way to SOOTOPOLIS?\l"
	.string "You're no ordinary tourist.\p"
	.string "But I suppose that doesn't make you\n"
	.string "an extraordinary tourist, either.$"

SootopolisCity_Text_SootopolisSkyBeautiful:
	.string "SOOTOPOLIS sprang up as a town in\n"
	.string "the crater of a volcano.\p"
	.string "If you look up at the sky, the lip of\n"
	.string "the crater is also visible.\l"
	.string "So, all you see is the sky in a circle.\p"
	.string "But that's what makes the sky above\n"
	.string "SOOTOPOLIS the most beautiful.$"

SootopolisCity_Text_NightSkyFavoriteScenery:
	.string "A circle of a night sky framed by\n"
	.string "the crater of a volcano…\p"
	.string "And in that ring, stars flicker and\n"
	.string "blink as if they were alive…\l"
	.string "It's my favorite scenery.$"
