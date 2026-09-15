GraniteCave_B2F_MapScripts::
	.byte 0

GraniteCave_EventScript_MuscleFeather::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, GraniteCave_ThreeMuscleFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, GraniteCave_ThreeMuscleFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, GraniteCave_ThreeMuscleFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, GraniteCave_ThreeMuscleFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, GraniteCave_FourMuscleFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, GraniteCave_FourMuscleFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, GraniteCave_FourMuscleFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, GraniteCave_FourMuscleFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, GraniteCave_FiveMuscleFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, GraniteCave_FiveMuscleFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, GraniteCave_FiveMuscleFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, GraniteCave_FiveMuscleFeathers
	end

GraniteCave_ThreeMuscleFeathers::
	finditem ITEM_MUSCLE_FEATHER, amount=3
	end

GraniteCave_FourMuscleFeathers::
	finditem ITEM_MUSCLE_FEATHER, amount=4
	end

GraniteCave_FiveMuscleFeathers::
	finditem ITEM_MUSCLE_FEATHER, amount=5
	end

GraniteCave_EventScript_HealthFeather::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, GraniteCave_ThreeHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, GraniteCave_ThreeHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, GraniteCave_ThreeHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, GraniteCave_ThreeHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, GraniteCave_FourHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, GraniteCave_FourHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, GraniteCave_FourHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, GraniteCave_FourHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, GraniteCave_FiveHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, GraniteCave_FiveHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, GraniteCave_FiveHealthFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, GraniteCave_FiveHealthFeathers
	end

GraniteCave_ThreeHealthFeathers::
	finditem ITEM_HEALTH_FEATHER, amount=3
	end

GraniteCave_FourHealthFeathers::
	finditem ITEM_HEALTH_FEATHER, amount=4
	end

GraniteCave_FiveHealthFeathers::
	finditem ITEM_HEALTH_FEATHER, amount=5
	end

GraniteCave_EventScript_ResistFeather::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, GraniteCave_ThreeResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, GraniteCave_ThreeResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, GraniteCave_ThreeResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, GraniteCave_ThreeResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, GraniteCave_FourResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, GraniteCave_FourResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, GraniteCave_FourResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, GraniteCave_FourResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, GraniteCave_FiveResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, GraniteCave_FiveResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, GraniteCave_FiveResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, GraniteCave_FiveResistFeathers
	end

GraniteCave_ThreeResistFeathers::
	finditem ITEM_RESIST_FEATHER, amount=3
	end

GraniteCave_FourResistFeathers::
	finditem ITEM_RESIST_FEATHER, amount=4
	end

GraniteCave_FiveResistFeathers::
	finditem ITEM_RESIST_FEATHER, amount=5
	end
	
GraniteCaveB2F_EventScript_Tyler::
	@trainerbattle_single TRAINER_TYLER, GraniteCave_Text_TylerIntro, GraniteCave_Text_TylerDefeated
	@msgbox GraniteCave_Text_TylerPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB2F_EventScript_Egg::
	@trainerbattle_single TRAINER_EGG, GraniteCave_Text_EggIntro, GraniteCave_Text_EggDefeated
	@msgbox GraniteCave_Text_EggPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB2F_EventScript_Dunk::
	@trainerbattle_single TRAINER_DUNK, GraniteCave_Text_DunkIntro, GraniteCave_Text_DunkDefeated
	@msgbox GraniteCave_Text_DunkPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB2F_EventScript_Harmony::
	@trainerbattle_single TRAINER_HARMONY, GraniteCave_Text_HarmonyIntro, GraniteCave_Text_HarmonyDefeated
	@msgbox GraniteCave_Text_HarmonyPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB2F_EventScript_Mercy::
	@trainerbattle_single TRAINER_MERCY, GraniteCave_Text_MercyIntro, GraniteCave_Text_MercyDefeated
	@msgbox GraniteCave_Text_MercyPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB2F_EventScript_Frank::
	@trainerbattle_single TRAINER_FRANK, GraniteCave_Text_FrankIntro, GraniteCave_Text_FrankDefeated
	@msgbox GraniteCave_Text_FrankPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB2F_EventScript_Ziel::
	@trainerbattle_single TRAINER_ZIEL, GraniteCave_Text_ZielIntro, GraniteCave_Text_ZielDefeated
	@msgbox GraniteCave_Text_ZielPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCave_B2F_EventScript_Brawly::
	lock
	faceplayer
	goto_if_defeated TRAINER_SLATEPORT_BOSS, GraniteCave_B2F_EventScript_Brawly_AlreadyFought
	trainerbattle_single TRAINER_SLATEPORT_BOSS, GraniteCave_B2F_Text_Placeholder, GraniteCave_B2F_Text_Placeholder, GraniteCave_B2F_EventScript_Brawly_FlagsAfterBattle
	release
	end

GraniteCave_B2F_EventScript_Brawly_AlreadyFought::
	msgbox GraniteCave_B2F_Text_Placeholder, MSGBOX_DEFAULT
	release
	end

GraniteCave_B2F_EventScript_Brawly_FlagsAfterBattle::
	setflag FLAG_DEWFORD_BOSS
	special IncrementPlayerKeys
	special IncrementWorldLevel
	goto_if_set FLAG_PETALBURG_BOSS, GraniteCave_B2F_EventScript_AutoUnlock_Petalburg
	goto_if_set FLAG_SLATEPORT_BOSS, GraniteCave_B2F_EventScript_AutoUnlock_Slateport
	release
	end

GraniteCave_B2F_EventScript_AutoUnlock_Petalburg::
	setflag FLAG_PETALBURG_DEWFORD_STRETCH
	copyvar VAR_SLATEPORT_MAUVILLE_LEVEL, VAR_WORLD_DIFFICULTY
	return
	end

GraniteCave_B2F_EventScript_AutoUnlock_Slateport::
	setflag FLAG_DEWFORD_SLATEPORT_STRETCH
	copyvar VAR_DEWFORD_SLATEPORT_LEVEL, VAR_WORLD_DIFFICULTY
	return
	end

GraniteCave_B2F_Text_Placeholder:
	.string "This is placeholder text.$"
