NorthIsland_MapScripts::
	.byte 0

NorthIsland_EventScript_CleverFeather::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, NorthIsland_ThreeCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, NorthIsland_ThreeCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, NorthIsland_ThreeCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, NorthIsland_ThreeCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, NorthIsland_FourCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, NorthIsland_FourCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, NorthIsland_FourCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, NorthIsland_FourCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, NorthIsland_FiveCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, NorthIsland_FiveCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, NorthIsland_FiveCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, NorthIsland_FiveCleverFeathers
	end

NorthIsland_ThreeCleverFeathers::
	finditem ITEM_CLEVER_FEATHER, amount=3
	end

NorthIsland_FourCleverFeathers::
	finditem ITEM_CLEVER_FEATHER, amount=4
	end

NorthIsland_FiveCleverFeathers::
	finditem ITEM_CLEVER_FEATHER, amount=5
	end
	