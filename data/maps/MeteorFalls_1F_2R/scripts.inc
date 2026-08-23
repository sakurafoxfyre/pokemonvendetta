MeteorFalls_1F_2R_MapScripts::
	.byte 0

Meteor1F2R_DuskBalls::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, Meteor1F2R_FiveDuskBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, Meteor1F2R_FiveDuskBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, Meteor1F2R_FiveDuskBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, Meteor1F2R_FiveDuskBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, Meteor1F2R_SevenDuskBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, Meteor1F2R_SevenDuskBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, Meteor1F2R_SevenDuskBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, Meteor1F2R_SevenDuskBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, Meteor1F2R_TenDuskBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, Meteor1F2R_TenDuskBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, Meteor1F2R_TenDuskBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, Meteor1F2R_TenDuskBalls
	end

Meteor1F2R_FiveDuskBalls::
	finditem ITEM_DUSK_BALL, amount=5
	end

Meteor1F2R_SevenDuskBalls::
	finditem ITEM_DUSK_BALL, amount=7
	end

Meteor1F2R_TenDuskBalls::
	finditem ITEM_DUSK_BALL, amount=10
	end

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "This is where we DRAGON users do our\n"
	.string "training.\p"
	.string "The CHAMPION even visits.\n"
	.string "Now do you see how special it is here?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "Urgh!\n"
	.string "I didn't expect you to be so strong!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "The road ahead remains long and harsh.\p"
	.string "When will my POKéMON and I become\n"
	.string "the best?$"
