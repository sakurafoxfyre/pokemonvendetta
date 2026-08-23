Route121_MapScripts::
	.byte 0

Route121_EventScript_GeniusFeather::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, Route121_ThreeGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, Route121_ThreeGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, Route121_ThreeGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, Route121_ThreeGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, Route121_FourGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, Route121_FourGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, Route121_FourGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, Route121_FourGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, Route121_FiveGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, Route121_FiveGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, Route121_FiveGeniusFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, Route121_FiveGeniusFeathers
	end

Route121_ThreeGeniusFeathers::
	finditem ITEM_GENIUS_FEATHER, amount=3
	end

Route121_FourGeniusFeathers::
	finditem ITEM_GENIUS_FEATHER, amount=4
	end

Route121_FiveGeniusFeathers::
	finditem ITEM_GENIUS_FEATHER, amount=5
	end

Route121_NetBalls::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, Route121_FiveNetBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, Route121_FiveNetBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, Route121_FiveNetBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, Route121_FiveNetBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, Route121_SevenNetBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, Route121_SevenNetBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, Route121_SevenNetBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, Route121_SevenNetBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, Route121_TenNetBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, Route121_TenNetBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, Route121_TenNetBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, Route121_TenNetBalls
	end

Route121_FiveNetBalls::
	finditem ITEM_NET_BALL, amount=5
	end

Route121_SevenNetBalls::
	finditem ITEM_NET_BALL, amount=7
	end

Route121_TenNetBalls::
	finditem ITEM_NET_BALL, amount=10
	end

Route121_QuickBalls::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, Route121_FiveQuickBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, Route121_FiveQuickBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, Route121_FiveQuickBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, Route121_FiveQuickBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, Route121_SevenQuickBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, Route121_SevenQuickBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, Route121_SevenQuickBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, Route121_SevenQuickBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, Route121_TenQuickBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, Route121_TenQuickBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, Route121_TenQuickBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, Route121_TenQuickBalls
	end

Route121_FiveQuickBalls::
	finditem ITEM_QUICK_BALL, amount=5
	end

Route121_SevenQuickBalls::
	finditem ITEM_QUICK_BALL, amount=7
	end

Route121_TenQuickBalls::
	finditem ITEM_QUICK_BALL, amount=10
	end

Route121_TimerBalls::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, Route121_FiveTimerBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, Route121_FiveTimerBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, Route121_FiveTimerBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, Route121_FiveTimerBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, Route121_SevenTimerBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, Route121_SevenTimerBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, Route121_SevenTimerBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, Route121_SevenTimerBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, Route121_TenTimerBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, Route121_TenTimerBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, Route121_TenTimerBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, Route121_TenTimerBalls
	end

Route121_FiveTimerBalls::
	finditem ITEM_TIMER_BALL, amount=5
	end

Route121_SevenTimerBalls::
	finditem ITEM_TIMER_BALL, amount=7
	end

Route121_TenTimerBalls::
	finditem ITEM_TIMER_BALL, amount=10
	end

Route121_EventScript_Woman::
	msgbox Route121_Text_AheadLoomsMtPyre, MSGBOX_NPC
	end

Route121_EventScript_MtPyrePierSign::
	msgbox Route121_Text_MtPyrePierSign, MSGBOX_SIGN
	end

Route121_EventScript_SafariZoneSign::
	msgbox Route121_Text_SafariZoneSign, MSGBOX_SIGN
	end

Route121_EventScript_Vanessa::
	trainerbattle_single TRAINER_VANESSA, Route121_Text_VanessaIntro, Route121_Text_VanessaDefeat
	msgbox Route121_Text_VanessaPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Walter::
	trainerbattle_single TRAINER_WALTER, Route121_Text_WalterIntro, Route121_Text_WalterDefeat
	msgbox Route121_Text_WalterPostBattle, MSGBOX_DEFAULT
	release
	end

Route121_EventScript_Tammy::
	trainerbattle_single TRAINER_TAMMY, Route121_Text_TammyIntro, Route121_Text_TammyDefeat
	msgbox Route121_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Kate::
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_KateIntro, Route121_Text_KateDefeat, Route121_Text_KateNotEnoughMons
	msgbox Route121_Text_KatePostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Joy::
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_JoyIntro, Route121_Text_JoyDefeat, Route121_Text_JoyNotEnoughMons
	msgbox Route121_Text_JoyPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Jessica::
	trainerbattle_single TRAINER_JESSICA, Route121_Text_JessicaIntro, Route121_Text_JessicaDefeat
	msgbox Route121_Text_JessicaPostBattle, MSGBOX_DEFAULT
	release
	end

Route121_EventScript_Cale::
	trainerbattle_single TRAINER_CALE, Route121_Text_CaleIntro, Route121_Text_CaleDefeat
	msgbox Route121_Text_CalePostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Myles::
	trainerbattle_single TRAINER_MYLES, Route121_Text_MylesIntro, Route121_Text_MylesDefeat
	msgbox Route121_Text_MylesPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Pat::
	trainerbattle_single TRAINER_PAT, Route121_Text_PatIntro, Route121_Text_PatDefeat
	msgbox Route121_Text_PatPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Marcel::
	trainerbattle_single TRAINER_MARCEL, Route121_Text_MarcelIntro, Route121_Text_MarcelDefeat
	msgbox Route121_Text_MarcelPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Cristin::
	trainerbattle_single TRAINER_CRISTIN, Route121_Text_CristinIntro, Route121_Text_CristinDefeat
	msgbox Route121_Text_CristinPostBattle, MSGBOX_DEFAULT
	release
	end

Route121_Text_AheadLoomsMtPyre:
	.string "Ahead looms MT. PYRE…\p"
	.string "It is a natural monument to the spirits \n"
	.string "of departed POKéMON…$"

Route121_Text_MtPyrePierSign:
	.string "MT. PYRE PIER\p"
	.string "…The sign is old and worn out.\n"
	.string "The words are barely legible…$"

Route121_Text_SafariZoneSign:
	.string "“Filled with rare POKéMON!”\n"
	.string "SAFARI ZONE$"

