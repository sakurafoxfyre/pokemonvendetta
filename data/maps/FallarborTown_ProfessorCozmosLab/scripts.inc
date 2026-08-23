FallarborTown_ProfessorCozmosLab_MapScripts::
	.byte 0

FallarborTown_ProfessorCozmosLab_EventScript_GrabCozmosBag::
	lock
	msgbox FallarborTown_ProfessorCozmosLab_Text_CozmosBag, MSGBOX_DEFAULT
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_POKENAV_GET
	@ give surfboard item
	@ eventual goal is to make the bike similar to gen 4, for now just give both
	giveitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	giveitem ITEM_POKE_BALL, amount=5
	setflag FLAG_STOLE_COZMOS_BAG
	goto_if_set FLAG_GRABBED_STARTER, FallarborTown_ProfessorCozmosLab_EventScript_SetLeave
	releaseall
	end

FallarborTown_ProfessorCozmosLab_EventScript_GrabStarter::
	lock
	fadescreen FADE_TO_BLACK
	special ChooseStarter
	waitstate
	setflag FLAG_GRABBED_STARTER
	goto_if_set FLAG_STOLE_COZMOS_BAG, FallarborTown_ProfessorCozmosLab_EventScript_SetLeave
	release
	end

FallarborTown_ProfessorCozmosLab_EventScript_SetLeave::
	setvar VAR_CAN_LEAVE_COZMOS_LAB, 1
	end

FallarborTown_ProfessorCozmosLab_EventScript_PreventLeave::
	msgbox FallarborTown_ProfessorCozmosLab_Text_NotLeave, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, FallarborTown_ProfessorCozmosLab_EventScript_PreventLeaveMovement
	waitmovement 0
	releaseall
	end

FallarborTown_ProfessorCozmosLab_EventScript_PreventLeaveMovement::
	walk_up
	step_end

FallarborTown_ProfessorCozmosLab_Text_CozmosBag:
	.string "A bag full of useful items.\n"
	.string "I should take these with me.\p"
	.string "{PLAYER} took the PokeDex.\p"
	.string "{PLAYER} took the PokeNav.$"

FallarborTown_ProfessorCozmosLab_Text_NotLeave:
	.string "I shouldn't leave until I have as\n"
	.string "many supplies as I can take.$"
