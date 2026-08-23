GraniteCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, GraniteCave_B1F_SetHoleWarp
	.byte 0

GraniteCave_B1F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_GRANITE_CAVE_B2F
	end

GraniteCave_EventScript_RockGems::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, GraniteCave_ThreeRockGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, GraniteCave_ThreeRockGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, GraniteCave_ThreeRockGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, GraniteCave_ThreeRockGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, GraniteCave_FiveRockGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, GraniteCave_FiveRockGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, GraniteCave_FiveRockGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, GraniteCave_FiveRockGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, GraniteCave_SevenRockGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, GraniteCave_SevenRockGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, GraniteCave_SevenRockGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, GraniteCave_SevenRockGems
	end

GraniteCave_ThreeRockGems::
	finditem ITEM_ROCK_GEM, amount=3
	end

GraniteCave_FiveRockGems::
	finditem ITEM_ROCK_GEM, amount=5
	end

GraniteCave_SevenRockGems::
	finditem ITEM_ROCK_GEM, amount=7
	end

GraniteCave_EventScript_GroundGems::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, GraniteCave_ThreeGroundGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, GraniteCave_ThreeGroundGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, GraniteCave_ThreeGroundGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, GraniteCave_ThreeGroundGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, GraniteCave_FiveGroundGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, GraniteCave_FiveGroundGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, GraniteCave_FiveGroundGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, GraniteCave_FiveGroundGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, GraniteCave_SevenGroundGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, GraniteCave_SevenGroundGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, GraniteCave_SevenGroundGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, GraniteCave_SevenGroundGems
	end

GraniteCave_ThreeGroundGems::
	finditem ITEM_GROUND_GEM, amount=3
	end

GraniteCave_FiveGroundGems::
	finditem ITEM_GROUND_GEM, amount=5
	end

GraniteCave_SevenGroundGems::
	finditem ITEM_GROUND_GEM, amount=7
	end

GraniteCave_EventScript_FightingGems::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, GraniteCave_ThreeFightingGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, GraniteCave_ThreeFightingGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, GraniteCave_ThreeFightingGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, GraniteCave_ThreeFightingGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, GraniteCave_FiveFightingGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, GraniteCave_FiveFightingGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, GraniteCave_FiveFightingGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, GraniteCave_FiveFightingGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, GraniteCave_SevenFightingGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, GraniteCave_SevenFightingGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, GraniteCave_SevenFightingGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, GraniteCave_SevenFightingGems
	end

GraniteCave_ThreeFightingGems::
	finditem ITEM_FIGHTING_GEM, amount=3
	end

GraniteCave_FiveFightingGems::
	finditem ITEM_FIGHTING_GEM, amount=5
	end

GraniteCave_SevenFightingGems::
	finditem ITEM_FIGHTING_GEM, amount=7
	end

GraniteCave_EventScript_WaterGems::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, GraniteCave_ThreeWaterGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, GraniteCave_ThreeWaterGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, GraniteCave_ThreeWaterGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, GraniteCave_ThreeWaterGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, GraniteCave_FiveWaterGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, GraniteCave_FiveWaterGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, GraniteCave_FiveWaterGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, GraniteCave_FiveWaterGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, GraniteCave_SevenWaterGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, GraniteCave_SevenWaterGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, GraniteCave_SevenWaterGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, GraniteCave_SevenWaterGems
	end

GraniteCave_ThreeWaterGems::
	finditem ITEM_WATER_GEM, amount=3
	end

GraniteCave_FiveWaterGems::
	finditem ITEM_WATER_GEM, amount=5
	end

GraniteCave_SevenWaterGems::
	finditem ITEM_WATER_GEM, amount=7
	end
	
GraniteCaveB1F_EventScript_Fiona::
	trainerbattle_single TRAINER_FIONA, GraniteCave_Text_FionaIntro, GraniteCave_Text_FionaDefeated
	msgbox GraniteCave_Text_FionaPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB1F_EventScript_Maxine::
	trainerbattle_single TRAINER_MAXINE, GraniteCave_Text_MaxineIntro, GraniteCave_Text_MaxineDefeated
	msgbox GraniteCave_Text_MaxinePostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB1F_EventScript_Lindon::
	trainerbattle_single TRAINER_LINDON, GraniteCave_Text_LindonIntro, GraniteCave_Text_LindonDefeated
	msgbox GraniteCave_Text_LindonPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB1F_EventScript_Velomachus::
	trainerbattle_single TRAINER_VELOMACHUS, GraniteCave_Text_VelomachusIntro, GraniteCave_Text_VelomachusDefeated
	msgbox GraniteCave_Text_VelomachusPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB1F_EventScript_Quentin::
	trainerbattle_single TRAINER_QUENTIN, GraniteCave_Text_QuentinIntro, GraniteCave_Text_QuentinDefeated
	msgbox GraniteCave_Text_QuentinPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB1F_EventScript_Ezra::
	trainerbattle_single TRAINER_EZRA, GraniteCave_Text_EzraIntro, GraniteCave_Text_EzraDefeated
	msgbox GraniteCave_Text_EzraPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB1F_EventScript_Eithan::
	trainerbattle_single TRAINER_EITHAN, GraniteCave_Text_EithanIntro, GraniteCave_Text_EithanDefeated
	msgbox GraniteCave_Text_EithanPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB1F_EventScript_Yerin::
	trainerbattle_single TRAINER_YERIN, GraniteCave_Text_YerinIntro, GraniteCave_Text_YerinDefeated
	msgbox GraniteCave_Text_YerinPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB1F_EventScript_Daishou::
	trainerbattle_single TRAINER_DAISHOU, GraniteCave_Text_DaishouIntro, GraniteCave_Text_DaishouDefeated
	msgbox GraniteCave_Text_DaishouPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB1F_EventScript_Dimitri::
	trainerbattle_single TRAINER_DIMITRI, GraniteCave_Text_DimitriIntro, GraniteCave_Text_DimitriDefeated
	msgbox GraniteCave_Text_DimitriPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB1F_EventScript_Lumis::
	trainerbattle_single TRAINER_LUMIS, GraniteCave_Text_LumisIntro, GraniteCave_Text_LumisDefeated
	msgbox GraniteCave_Text_LumisPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB1F_EventScript_Umbra::
	trainerbattle_single TRAINER_UMBRA, GraniteCave_Text_UmbraIntro, GraniteCave_Text_UmbraDefeated
	msgbox GraniteCave_Text_UmbraPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB1F_EventScript_Cassias::
	trainerbattle_single TRAINER_CASSIAS, GraniteCave_Text_CassiasIntro, GraniteCave_Text_CassiasDefeated
	msgbox GraniteCave_Text_CassiasPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCaveB1F_EventScript_Long::
	trainerbattle_single TRAINER_LONG, GraniteCave_Text_LongIntro, GraniteCave_Text_LongDefeated
	msgbox GraniteCave_Text_LongPostBattle, MSGBOX_AUTOCLOSE
	end
	