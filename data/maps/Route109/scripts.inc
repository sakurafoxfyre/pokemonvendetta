Route109_MapScripts::
	.byte 0

Route109_EventScript_SeashoreHouseSign::
	msgbox Route109_Text_SeashoreHouseSign, MSGBOX_SIGN
	end

Route109_EventScript_TrainerTipsSign::
	msgbox Route109_Text_TrainerTipsSign, MSGBOX_SIGN
	end

Route109_EventScript_David::
	trainerbattle_single TRAINER_DAVID, Route109_Text_DavidIntro, Route109_Text_DavidDefeated
	msgbox Route109_Text_DavidPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Joline::
	trainerbattle_single TRAINER_JOLINE, Route109_Text_JolineIntro, Route109_Text_JolineDefeated
	msgbox Route109_Text_JolinePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Ricky::
	trainerbattle_single TRAINER_RICKY, Route109_Text_RickyIntro, Route109_Text_RickyDefeated, Route109_TuberKing_EventScript_CheckTrainersCompletion
	msgbox Route109_Text_RickyPostBattle, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_Lola::
	trainerbattle_single TRAINER_LOLA, Route109_Text_LolaIntro, Route109_Text_LolaDefeated, Route109_TuberKing_EventScript_CheckTrainersCompletion
	msgbox Route109_Text_LolaPostBattle, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_Austina::
	trainerbattle_single TRAINER_AUSTINA, Route109_Text_AustinaIntro, Route109_Text_AustinaDefeated, Route109_TuberKing_EventScript_CheckTrainersCompletion
	msgbox Route109_Text_AustinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Gwen::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_TUBERS, Route109_EventScript_ChallengeGwen
	msgbox Route109_Text_IAmTuberQueen, MSGBOX_DEFAULT
	applymovement Gwen, LookDown
	waitmovement 0
	release
	end

LookDown:
	face_down
	step_end

Route109_EventScript_ChallengeGwen::
	trainerbattle_single TRAINER_GWEN, Route109_Text_GwenIntro, Route109_Text_GwenDefeated
	msgbox Route109_Text_GwenPostBattle, MSGBOX_AUTOCLOSE
	giveitem ITEM_TM_SWEET_SCENT
	release
	end

Route109_EventScript_ReceivedSweetScent::
	msgbox Route109_Text_ExplainSweetScent, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_Paul::
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route109_Text_PaulIntro, Route109_Text_PaulDefeated, Route109_Text_PaulNotEnoughPokemon
	msgbox Route109_Text_PaulPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Mel::
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route109_Text_MelIntro, Route109_Text_MelDefeated, Route109_Text_MelNotEnoughPokemon
	msgbox Route109_Text_MelPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Chandler::
	trainerbattle_single TRAINER_CHANDLER, Route109_Text_ChandlerIntro, Route109_Text_ChandlerDefeated, Route109_TuberKing_EventScript_CheckTrainersCompletion
	msgbox Route109_Text_ChandlerPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Hailey::
	trainerbattle_single TRAINER_HAILEY, Route109_Text_HaileyIntro, Route109_Text_HaileyDefeated, Route109_TuberKing_EventScript_CheckTrainersCompletion
	msgbox Route109_Text_HaileyPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_TuberKing_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_HAILEY, Route109_TuberKing_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_RICKY, Route109_TuberKing_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_LOLA, Route109_TuberKing_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_CHANDLER, Route109_TuberKing_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_AUSTINA, Route109_TuberKing_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_TUBERS
	release
	end

Route109_TuberKing_EventScript_TrainersNotCompleted::
	release
	end

Route109_Text_ExplainSweetScent:
	.string "Let's change the subject to my favorite\n"
	.string "move, Sweet Scent!\p"
	.string "It's a new Terrain move, which means\n"
	.string "going in the air won't protect you,\l"
	.string "unlike stupid old Terrains like Electric\l"
	.string "or Psychic.\p"
	.string "Something like Shadow Force would still\n"
	.string "dodge it, though.\p"
	.string "In Aromatic Terrain, you will never fail\n"
	.string "a move due to a status condition or\l"
	.string "another move's effect, but it doesn't\l"
	.string "protect you from your own failure,\l"
	.string "like spamming Protect.\p"
	.string "If a Pokemon is not infatuated and\n"
	.string "attacks another Pokemon, it will fall\l"
	.string "for that Pokemon.\p"
	.string "You don't look local, so I'll make it\n"
	.string "clear to you: here in Hoenn,\l"
	.string "the Pokemon's gender doesn't matter.\p"
	.string "Infatuation doesn't make you fail moves\n"
	.string "out of love, though, it just makes you\l"
	.string "deal half damage to your crush.\p"
	.string "While in Aromatic Terrain, Grass, Poison,\n"
	.string "and Fairy-type Pokemon have their\l"
	.string "special defense increased by one stage.\p"
	.string "Nature and Secret Power can infatuate,\n"
	.string "Terrain Pulse and Camouflage are\l"
	.string "Grass-type, and Aromatic Seeds are for\l"
	.string "sale at the Flower House by Rustboro.\p"
	.string "Use this information responsibly, okay?\n"
	.string "Or don't, I don't really care.$"

Route109_Text_IAmTuberQueen:
	.string "Ara, ara. You dare approach me?\n"
	.string "Perhaps, if you defeat my five subjects,\l"
	.string "I will bestow upon you a moment of\l"
	.string "my time.$"

Route109_Text_SeashoreHouseSign:
	.string "The words SEASHORE HOUSE are crudely\n"
	.string "crossed out. The other text is written\l"
	.string "around it in an unsteady hand.\p"
	.string "'Fight for the right to purchase MOCHI!\n"
	.string "The future in Pokémon power! MOCHI HOUSE!'$"

Route109_Text_TrainerTipsSign:
	.string "SLATEPORT BEACH ADVISORY WARNING\n"
	.string "By order of Slateport City Hall.\p"
	.string "There have been reports of injuries\n"
	.string "by TOTODILE, SANDYGAST, and STUNFISK.\p"
	.string "Children are not to play on SLATEPORT\n"
	.string "BEACH without supervision.\p"
	.string "For questions, please contact the AETHER\n"
	.string "FOUNDATION in FORTREE. It's their mess.$"
