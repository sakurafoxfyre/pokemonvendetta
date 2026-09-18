GraniteCave_1F_MapScripts::
	.byte 0

GraniteCaveB1F_EventScript_Fiona::
	trainerbattle_single TRAINER_FIONA, GraniteCave_Text_FionaIntro, GraniteCave_Text_FionaDefeated
	msgbox GraniteCave_Text_FionaPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB1F_EventScript_Ezra::
	trainerbattle_single TRAINER_EZRA, GraniteCave_Text_EzraIntro, GraniteCave_Text_EzraDefeated
	msgbox GraniteCave_Text_EzraPostBattle, MSGBOX_AUTOCLOSE
	end
