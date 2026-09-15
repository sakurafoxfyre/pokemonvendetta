Route106_MapScripts::
	.byte 0

Route106_EventScript_TrainerTipsSign::
	msgbox Route106_Text_TrainerTips, MSGBOX_SIGN
	end

Route106_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS, Route106_Text_DouglasIntro, Route106_Text_DouglasDefeated
	msgbox Route106_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Kyla::
	trainerbattle_single TRAINER_KYLA, Route106_Text_KylaIntro, Route106_Text_KylaDefeated
	msgbox Route106_Text_KylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Elliot::
	trainerbattle_single TRAINER_ELLIOT, Route106_Text_ElliotIntro, Route106_Text_ElliotDefeated
	msgbox Route106_Text_ElliotPostBattle, MSGBOX_DEFAULT
	release
	end

Route106_EventScript_Ned::
	trainerbattle_single TRAINER_NED, Route106_Text_NedIntro, Route106_Text_NedDefeated
	msgbox Route106_Text_NedPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Check_ToPetalburg::
	goto_if_unset FLAG_PETALBURG_DEWFORD_STRETCH, Route106_EventScript_Check_Petalburg_Dewford
	end

Route106_EventScript_Check_Petalburg_Dewford::
	lock
	goto_if_unset FLAG_DEWFORD_BOSS, Route106_EventScript_ToPetalburg_BossUndefeated
	goto_if_lt VAR_NUMBER_OF_KEYS, 1, Route106_EventScript_Cannot_Unlock_Petalburg
	msgbox Route106_Text_To_Petalburg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route106_EventScript_Reject_ToPetalburg
	msgbox Route106_Text_Accept_Petalburg, MSGBOX_DEFAULT
	setflag FLAG_PETALBURG_DEWFORD_STRETCH
	copyvar VAR_PETALBURG_DEWFORD_LEVEL, VAR_WORLD_DIFFICULTY
	copyvar VAR_PETALBURG_LEVEL, VAR_WORLD_DIFFICULTY
	special DecrementPlayerKeys
	release
	end

Route106_EventScript_ToPetalburg_BossUndefeated::
	msgbox Route106_Text_Boss_Undefeated, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Route106_Movement_TurnFrom_Petalburg
	waitmovement 0
	release
	end

Route106_EventScript_Cannot_Unlock_Petalburg::
	msgbox Route106_Text_Cannot_Unlock, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Route106_Movement_TurnFrom_Petalburg
	waitmovement 0
	release
	end

Route106_EventScript_Reject_ToPetalburg::
	msgbox Route106_Text_Reject_Path, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Route106_Movement_TurnFrom_Petalburg

Route106_Movement_TurnFrom_Petalburg:
	walk_down
	step_end

Route106_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "Advice on catching POKéMON with a ROD:\n"
	.string "Press the A Button if you get a bite.$"

Route106_Text_To_Petalburg:
	.string "This is the way to Petalburg City...\n"
	.string "Head this way?$"

Route106_Text_Accept_Petalburg:
	.string "Time to head for Petalburg City.$"

Route106_Text_Boss_Undefeated:
	.string "There are still things I need\n"
	.string "to do here.$"

Route106_Text_Cannot_Unlock:
	.string "I have things to do elsewhere first.$"

Route106_Text_Reject_Path:
	.string "Maybe next time.$"
