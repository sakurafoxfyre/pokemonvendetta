MeteorFalls_B1F_1R_MapScripts::
	.byte 0

MeteorB1F1R_Gems::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, MeteorB1F1R_ThreeEachGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, MeteorB1F1R_ThreeEachGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, MeteorB1F1R_ThreeEachGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, MeteorB1F1R_ThreeEachGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, MeteorB1F1R_FiveEachGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, MeteorB1F1R_FiveEachGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, MeteorB1F1R_FiveEachGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, MeteorB1F1R_FiveEachGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, MeteorB1F1R_SevenEachGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, MeteorB1F1R_SevenEachGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, MeteorB1F1R_SevenEachGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, MeteorB1F1R_SevenEachGems
	end

MeteorB1F1R_ThreeEachGems::
	finditem ITEM_DARK_GEM, amount=3
	finditem ITEM_DRAGON_GEM, amount=3
	end

MeteorB1F1R_FiveEachGems::
	finditem ITEM_DARK_GEM, amount=5
	finditem ITEM_DRAGON_GEM, amount=5
	end

MeteorB1F1R_SevenEachGems::
	finditem ITEM_DARK_GEM, amount=7
	finditem ITEM_DRAGON_GEM, amount=7
	end
	
