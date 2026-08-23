FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_WorldLevelCyndaquilGreeting::
	lock
	buffernumberstring STR_VAR_1, VAR_WORLD_DIFFICULTY
	msgbox FallarborTown_Text_WorldLevelCyndaquil, MSGBOX_DEFAULT
	goto FallarborTown_EventScript_WorldLevelCyndaquil
	releaseall
	end

FallarborTown_EventScript_WorldLevelCyndaquil::
	msgbox FallarborTown_Text_WorldLevelCyndaquil_Question, MSGBOX_DEFAULT
	dynmultipush FallarborTown_Text_WorldLevel0, 0
	dynmultipush FallarborTown_Text_WorldLevel1, 1
	dynmultipush FallarborTown_Text_WorldLevel2, 2
	dynmultipush FallarborTown_Text_WorldLevel3, 3
	dynmultipush FallarborTown_Text_WorldLevel4, 4
	dynmultipush FallarborTown_Text_WorldLevel5, 5
	dynmultipush FallarborTown_Text_WorldLevel6, 6
	dynmultipush FallarborTown_Text_WorldLevel7, 7
	dynmultipush FallarborTown_Text_WorldLevel8, 8
	dynmultipush FallarborTown_Text_WorldLevel9, 9
	dynmultipush FallarborTown_Text_WorldLevel10, 10
	dynmultipush FallarborTown_Text_WorldLevel11, 11
	dynmultistack 0, 0, FALSE, 4, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, SetWorldLevel0
	case 1, SetWorldLevel1
	case 2, SetWorldLevel2
	case 3, SetWorldLevel3
	case 4, SetWorldLevel4
	case 5, SetWorldLevel5
	case 6, SetWorldLevel6
	case 7, SetWorldLevel7
	case 8, SetWorldLevel8
	case 9, SetWorldLevel9
	case 10, SetWorldLevel10
	case 11, SetWorldLevel11
	releaseall
	end

SetWorldLevel0::
	setvar VAR_WORLD_DIFFICULTY, 0
	buffernumberstring STR_VAR_1, VAR_WORLD_DIFFICULTY
	goto WorldLevelChanged
	end

SetWorldLevel1::
	setvar VAR_WORLD_DIFFICULTY,  1
	buffernumberstring STR_VAR_1, VAR_WORLD_DIFFICULTY
	goto WorldLevelChanged
	end

SetWorldLevel2::
	setvar VAR_WORLD_DIFFICULTY, 2
	buffernumberstring STR_VAR_1, VAR_WORLD_DIFFICULTY
	goto WorldLevelChanged
	end

SetWorldLevel3::
	setvar VAR_WORLD_DIFFICULTY,  3
	buffernumberstring STR_VAR_1, VAR_WORLD_DIFFICULTY
	goto WorldLevelChanged
	end

SetWorldLevel4::
	setvar VAR_WORLD_DIFFICULTY, 4
	buffernumberstring STR_VAR_1, VAR_WORLD_DIFFICULTY
	goto WorldLevelChanged
	end

SetWorldLevel5::
	setvar VAR_WORLD_DIFFICULTY, 5
	buffernumberstring STR_VAR_1, VAR_WORLD_DIFFICULTY
	goto WorldLevelChanged
	end

SetWorldLevel6::
	setvar VAR_WORLD_DIFFICULTY, 6
	buffernumberstring STR_VAR_1, VAR_WORLD_DIFFICULTY
	goto WorldLevelChanged
	end

SetWorldLevel7::
	setvar VAR_WORLD_DIFFICULTY, 7
	buffernumberstring STR_VAR_1, VAR_WORLD_DIFFICULTY
	goto WorldLevelChanged
	end

SetWorldLevel8::
	setvar VAR_WORLD_DIFFICULTY, 8
	buffernumberstring STR_VAR_1, VAR_WORLD_DIFFICULTY
	goto WorldLevelChanged
	end

SetWorldLevel9::
	setvar VAR_WORLD_DIFFICULTY, 9
	buffernumberstring STR_VAR_1, VAR_WORLD_DIFFICULTY
	goto WorldLevelChanged
	end

SetWorldLevel10::
	setvar VAR_WORLD_DIFFICULTY, 10
	buffernumberstring STR_VAR_1, VAR_WORLD_DIFFICULTY
	goto WorldLevelChanged
	end

SetWorldLevel11::
	setvar VAR_WORLD_DIFFICULTY, 11
	buffernumberstring STR_VAR_1, VAR_WORLD_DIFFICULTY
	goto WorldLevelChanged
	end

WorldLevelChanged::
	msgbox FallarborTown_Text_WorldLevelCyndaquil_Changed, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_EventScript_TestTrainer::
	trainerbattle_single TRAINER_TEST_TRAINER, FallarborTown_Text_TestIntro, FallarborTown_Text_TestLose
	msgbox FallarborTown_Text_TestPostBattle, MSGBOX_NPC
	end

FallarborTown_EventScript_TestItemBall::
	@goto_if_eq VAR_RESULT, TRUE, MyScript
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, FallarborTown_WorldZero_Item
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, FallarborTown_WorldOne_Item
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, FallarborTown_WorldTwo_Item
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, FallarborTown_WorldThree_Item
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, FallarborTown_WorldFour_Item
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, FallarborTown_WorldFive_Item
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, FallarborTown_WorldSix_Item
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, FallarborTown_WorldSeven_Item
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, FallarborTown_WorldEight_Item
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, FallarborTown_WorldNine_Item
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, FallarborTown_WorldTen_Item
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, FallarborTown_WorldEleven_Item
	end

FallarborTown_WorldZero_Item::
	finditem ITEM_POTION, amount=1
	end

FallarborTown_WorldOne_Item::
	finditem ITEM_POTION, amount=2
	end

FallarborTown_WorldTwo_Item::
	finditem ITEM_SUPER_POTION, amount=1
	end

FallarborTown_WorldThree_Item::
	finditem ITEM_SUPER_POTION, amount=2
	end

FallarborTown_WorldFour_Item::
	finditem ITEM_HYPER_POTION, amount=1
	end

FallarborTown_WorldFive_Item::
	finditem ITEM_HYPER_POTION, amount=2
	end

FallarborTown_WorldSix_Item::
	finditem ITEM_MAX_POTION, amount=1
	end

FallarborTown_WorldSeven_Item::
	finditem ITEM_FULL_RESTORE, amount=1
	end

FallarborTown_WorldEight_Item::
	finditem ITEM_FULL_RESTORE, amount=2
	end

FallarborTown_WorldNine_Item::
	finditem ITEM_MAX_REVIVE, amount=1
	end

FallarborTown_WorldTen_Item::
	finditem ITEM_MAX_REVIVE, amount=2
	end

FallarborTown_WorldEleven_Item::
	finditem ITEM_SACRED_ASH, amount=1
	end

FallarborTown_EventScript_TestingNatu_Greeting::
	lock
	msgbox FallarborTown_Text_TestingNatu_Greeing, MSGBOX_DEFAULT
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, FallarborTown_EventScript_TestingNatu_Zero
	msgbox FallarborTown_Text_TestingNatu_GoodDay, MSGBOX_NPC @ this isn't being called
	special IncrementWorldLevel @ this also isn't being called
	releaseall @ it's actually not.... >>
	end

FallarborTown_EventScript_TestingNatu_Zero::
	msgbox FallarborTown_Text_TestingNatu_Zero, MSGBOX_DEFAULT 
	closemessage
	return @ WHY ARE YOU NOT RETURNING TO THE PREVIOUS
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Something's happening,\n"
	.string "and I don't like it!\p"
	.string "I've seen shady characters wandering\n"
	.string "in and out of PROF. COZMO's home…$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "This region's been known for meteors\n"
	.string "since the olden days.\p"
	.string "They say METEOR FALLS was gouged out\n"
	.string "by a falling meteorite long ago.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "See! Take a look!\n"
	.string "This is my precious AZURILL!\p"
	.string "It's slick and smooth and plushy, too!$"

FallarborTown_Text_Azurill:
	.string "AZURILL: Rooreelooo.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "Have you already challenged FLANNERY,\n"
	.string "the LEADER of LAVARIDGE GYM?\p"
	.string "The girl's grandfather was famous.\n"
	.string "He was one of the ELITE FOUR in the\l"
	.string "POKéMON LEAGUE at one point.\p"
	.string "It wouldn't surprise me to see FLANNERY\n"
	.string "become a great TRAINER in her own\l"
	.string "right.$"

FallarborTown_Text_BattleTentSign:
	.string "BATTLE TENT FALLARBOR SITE\n"
	.string "“May the Greatest Teams Gather!”$"

FallarborTown_Text_TownSign:
	.string "FALLARBOR TOWN\n"
	.string "“A farm community with small gardens.”$"

FallarborTown_Text_MoveTutorSign:
	.string "MOVE TUTOR'S HOUSE\n"
	.string "“New moves taught to POKéMON.”$"

FallarborTown_Text_WorldLevelCyndaquil:
	.string "Currently, the World Level is {STR_VAR_1}.\n"
	.string "Nice!$"

FallarborTown_Text_WorldLevelCyndaquil_Question:
	.string "What would you like to change it to?$"

FallarborTown_Text_WorldLevel0:
	.string "Level 0$"

FallarborTown_Text_WorldLevel1:
	.string "Level 1$"

FallarborTown_Text_WorldLevel2:
	.string "Level 2$"

FallarborTown_Text_WorldLevel3:
	.string "Level 3$"

FallarborTown_Text_WorldLevel4:
	.string "Level 4$"

FallarborTown_Text_WorldLevel5:
	.string "Level 5$"

FallarborTown_Text_WorldLevel6:
	.string "Level 6$"

FallarborTown_Text_WorldLevel7:
	.string "Level 7$"

FallarborTown_Text_WorldLevel8:
	.string "Level 8$"

FallarborTown_Text_WorldLevel9:
	.string "Level 9$"

FallarborTown_Text_WorldLevel10:
	.string "Level 10$"

FallarborTown_Text_WorldLevel11:
	.string "Level 11$"	

FallarborTown_Text_WorldLevelCyndaquil_Changed:
	.string "The World Level is now {STR_VAR_1}.\n"
	.string "Let's hope this works.$"

FallarborTown_Text_TestIntro:
	.string "Here we go!$"

FallarborTown_Text_TestLose:
	.string "Darn.$"

FallarborTown_Text_TestPostBattle:
	.string "You already fought me!$"

FallarborTown_Text_TestingNatu_Greeing:
	.string "Hello!$"

FallarborTown_Text_TestingNatu_Zero:
	.string "The world level is 0!$"

FallarborTown_Text_TestingNatu_GoodDay:
	.string "Are you having a good day\n"
	.string "today?$"
