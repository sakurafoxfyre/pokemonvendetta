NewMauville_Inside_MapScripts::
	.byte 0


NewMauville_EventScript_SwiftFeather::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, NewMauville_ThreeSwiftFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, NewMauville_ThreeSwiftFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, NewMauville_ThreeSwiftFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, NewMauville_ThreeSwiftFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, NewMauville_FourSwiftFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, NewMauville_FourSwiftFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, NewMauville_FourSwiftFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, NewMauville_FourSwiftFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, NewMauville_FiveSwiftFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, NewMauville_FiveSwiftFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, NewMauville_FiveSwiftFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, NewMauville_FiveSwiftFeathers
	end

NewMauville_ThreeSwiftFeathers::
	finditem ITEM_SWIFT_FEATHER, amount=3
	end

NewMauville_FourSwiftFeathers::
	finditem ITEM_SWIFT_FEATHER, amount=4
	end

NewMauville_FiveSwiftFeathers::
	finditem ITEM_SWIFT_FEATHER, amount=5
	end

NewMauville_EventScript_ElectricSeeds::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, NewMauville_ThreeElectricSeeds
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, NewMauville_ThreeElectricSeeds
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, NewMauville_ThreeElectricSeeds
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, NewMauville_ThreeElectricSeeds
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, NewMauville_FiveElectricSeeds
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, NewMauville_FiveElectricSeeds
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, NewMauville_FiveElectricSeeds
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, NewMauville_FiveElectricSeeds
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, NewMauville_SevenElectricSeeds
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, NewMauville_SevenElectricSeeds
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, NewMauville_SevenElectricSeeds
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, NewMauville_SevenElectricSeeds
	end

NewMauville_ThreeElectricSeeds::
	finditem ITEM_ELECTRIC_SEED, amount=3
	end

NewMauville_FiveElectricSeeds::
	finditem ITEM_ELECTRIC_SEED, amount=5
	end

NewMauville_SevenElectricSeeds::
	finditem ITEM_ELECTRIC_SEED, amount=7
	end

NewMauville_EventScript_ElectricGems::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, NewMauville_ThreeElectricGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, NewMauville_ThreeElectricGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, NewMauville_ThreeElectricGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, NewMauville_ThreeElectricGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, NewMauville_FiveElectricGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, NewMauville_FiveElectricGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, NewMauville_FiveElectricGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, NewMauville_FiveElectricGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, NewMauville_SevenElectricGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, NewMauville_SevenElectricGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, NewMauville_SevenElectricGems
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, NewMauville_SevenElectricGems
	end

NewMauville_ThreeElectricGems::
	finditem ITEM_ELECTRIC_GEM, amount=3
	end

NewMauville_FiveElectricGems::
	finditem ITEM_ELECTRIC_GEM, amount=5
	end

NewMauville_SevenElectricGems::
	finditem ITEM_ELECTRIC_GEM, amount=7
	end
