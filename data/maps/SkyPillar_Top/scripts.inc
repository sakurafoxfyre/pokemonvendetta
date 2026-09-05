SkyPillar_Top_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_Top_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Top_EventScript_SetCleanLayout
	.byte 0

SkyPillar_Top_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SkyPillar_Top_EventScript_TryRemoveRayquaza
	end

SkyPillar_Top_EventScript_TryRemoveRayquaza::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

SkyPillar_Top_EventScript_SetCleanLayout::
	setmaplayoutindex LAYOUT_SKY_PILLAR_TOP_CLEAN
	return

SkyPillar_Top_EventScript_TryShowRayquaza::
	return

SkyPillar_Top_EventScript_ShowRayquaza::
	return

SkyPillar_Top_EventScript_RayquazaFaceDown::
	end

SkyPillar_Top_EventScript_Rayquaza::
	lockall
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_RAYQUAZA, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SkyPillar_Top_EventScript_DefeatedRayquaza
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SkyPillar_Top_EventScript_RanFromRayquaza
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SkyPillar_Top_EventScript_RanFromRayquaza
	releaseall
	end

SkyPillar_Top_EventScript_DefeatedRayquaza::
	goto SkyPillar_Top_EventScript_DefeatedRayquaza2
	end

SkyPillar_Top_EventScript_RanFromRayquaza::
	setvar VAR_0x8004, SPECIES_RAYQUAZA
	goto SkyPillar_Top_EventScript_RanFromRayquaza2
	end

SkyPillar_Top_EventScript_DefeatedRayquaza2::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

SkyPillar_Top_EventScript_RanFromRayquaza2::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	releaseall
	end

SkyPillar_Top_EventScript_AwakenRayquaza::
	lockall
	fadeoutbgm 1
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SkyPillar_Top_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	waitmoncry
	waitmovement 0
	msgbox SkyPillar_Top_Text_RayquazaFlewOff, MSGBOX_DEFAULT
	closemessage
	delay 20
	fadeinbgm 1
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SkyPillar_Top_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	releaseall
	end

@ Rayquaza has unusual movement frames
@ See comments, or sAnimTable_Rayquaza
SkyPillar_Top_Movement_RayquazaStir:
	delay_16
	walk_in_place_fast_left  @ Coiled, awake
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_left  @ Coiled, mouth open
	delay_16
	walk_in_place_right  @ Normal, awake
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

SkyPillar_Top_Movement_RayquazaFlyOff:
	delay_16
	walk_in_place_down  @ Coiled, asleep
	delay_8
	walk_in_place_right  @ Normal, awake
	delay_8
	walk_faster_up  @ Fly up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

SkyPillar_Top_Movement_CameraPanUp:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

SkyPillar_Top_Movement_CameraPanDown:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

SkyPillar_Top_Text_RayquazaFlewOff:
	.string "The awakened RAYQUAZA flew off…$"

