Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_PURE_MOCHI, 1
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_MochiHouse_Vendor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_MochiHouse_Vendor:
	.2byte ITEM_HEALTH_MOCHI
	.2byte ITEM_MUSCLE_MOCHI
	.2byte ITEM_RESIST_MOCHI
	.2byte ITEM_GENIUS_MOCHI
	.2byte ITEM_CLEVER_MOCHI
	.2byte ITEM_SWIFT_MOCHI
	.2byte ITEM_STRAWBERRY_SWEET
	.2byte ITEM_LOVE_SWEET
	.2byte ITEM_BERRY_SWEET
	.2byte ITEM_CLOVER_SWEET
	.2byte ITEM_FLOWER_SWEET
	.2byte ITEM_STAR_SWEET
	.2byte ITEM_RIBBON_SWEET
	pokemartlistend

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "I'm the new owner of the Seashore House.\n"
	.string "And I'm renaming it the Mochi House!\p"
	.string "My special mochi recipe can enhance a\n"
	.string "Pokémon's innate capabilities. So, it's\l"
	.string "pretty useful. I won't sell to losers!\p"
	.string "If you can defeat all the trainers here,\n"
	.string "I'll reward your efforts.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Show me some hot matches!\p"
	.string "I got into the mochi business pretty\n"
	.string "much for that reason alone!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Ahh... Nothing satisfies quite like\n"
	.string "forcing young people to battle for\l"
	.string "my amusement. I'm satisfied!\p"
	.string "As thanks for showing me your hot\n"
	.string "streak, I want you to take these.\p"
	.string "It's a prototype mochi flavor!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Oh, but hey, your BAG's jammed full.\n"
	.string "I'll hang on to these for you.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Want to buy some mochi?\n"
	.string "Pokémon love it! Can't get enough.$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Here you go!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "You don't have the money.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "No?\n"
	.string "That's too bad.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "If it means proving to the Mochi Man\n"
	.string "that I am worthy, I'd toss you\l"
	.string "overboard. Compared to that resolve...\p"
	.string "Crushing your Pokémon is nothing!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "I lost? I lost. I am unworthy...\n"
	.string "The Mochi Man will forsake me.$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "My ship left many moons ago. I am\n"
	.string "destitute and alone. My Pokémon\l"
	.string "stay with me for the Mochi, not me.\p"
	.string "What do I do...?$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Boring battles aren't worth the effort.\p"
	.string "You better put up a fight, child, or\n"
	.string "this won't impress the Mochi Man!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "He's unimpressed, but in me...$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "A sudden clarity has washed over me,\n"
	.string "like the waves on the shore outside.\p"
	.string "Have I just woken up? Or is this\n"
	.string "nothing but a deeper kind of dream?\p"
	.string "My mother was correct. Mochi, Protein,\n"
	.string "Feathers... these are but crutches for\l"
	.string "weak trainers. True strength...\p"
	.string "lies in the bonds we make with our\n"
	.string "Pokémon, and the memories we make on\l"
	.string "this long, winding road called life.\p"
	.string "{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} You sound like an idiot.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "I'm going to show you how great\n"
	.string "my Pokémon are, but don't cry!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "…I lost, but I won't cry…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "I wanted to beat you so I could earn\n"
	.string "some Mochi from that guy over there, but\l"
	.string "everyone here is creeping me out.\p"
	.string "Maybe I should just... go...?$"
