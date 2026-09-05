SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	.byte 0

SlateportCity_OnTransition:
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	end

SlateportCity_DoorLocked::
	msgbox SlateportCity_Text_DoorLocked, MSGBOX_SIGN
	end

SlateportCity_EventScript_ItemCollector::
	lock
	faceplayer
	message SlateportCity_Text_ItemCollectorSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_ItemCollector
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end
	.align 2

SlateportCity_Pokemart_ItemCollector:
	.2byte ITEM_LIGHT_BALL
	.2byte ITEM_LUCKY_PUNCH
	.2byte ITEM_THICK_CLUB
	pokemartlistend

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	end

SlateportCity_EventScript_OldWoman::
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	end

SlateportCity_EventScript_FatMan::
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_Man1::
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	end

SlateportCity_EventScript_Woman1::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_DevonTech::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_PokemartDevonTech
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end
	.align 2

SlateportCity_PokemartDevonTech:
	.2byte ITEM_FIRE_GEM
	.2byte ITEM_WATER_GEM
	.2byte ITEM_ELECTRIC_GEM
	.2byte ITEM_GRASS_GEM
	.2byte ITEM_ICE_GEM
	.2byte ITEM_FIGHTING_GEM
	.2byte ITEM_POISON_GEM
	.2byte ITEM_GROUND_GEM
	.2byte ITEM_FLYING_GEM
	.2byte ITEM_PSYCHIC_GEM
	.2byte ITEM_BUG_GEM
	.2byte ITEM_ROCK_GEM
	.2byte ITEM_GHOST_GEM
	.2byte ITEM_DRAGON_GEM
	.2byte ITEM_DARK_GEM
	.2byte ITEM_STEEL_GEM
	.2byte ITEM_NORMAL_GEM
	.2byte ITEM_FAIRY_GEM
	pokemartlistend

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end
	.align 2
	
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	pokemartlistend

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	pokemartlistend

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	waitstate
	releaseall
	end

SlateportCity_EventScript_TestBoss::
	lock
	faceplayer
	goto_if_defeated TRAINER_SLATEPORT_BOSS, SlateportCity_EventScript_TestBoss_AlreadyFought
	msgbox SlateportCity_Text_TestBoss_Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_TestBossNoBattle
	trainerbattle_single TRAINER_SLATEPORT_BOSS, SlateportCity_Text_TestBoss_YesBattle, SlateportCity_Text_TestBoss_Lose, SlateportCity_EventScript_TestBoss_FlagsAfterBattle
	msgbox SlateportCity_Text_TestBoss_PostBattle, MSGBOX_AUTOCLOSE
	release
	end

SlateportCity_EventScript_TestBoss_AlreadyFought::
	msgbox SlateportCity_Text_TestBoss_PostBattle, MSGBOX_AUTOCLOSE
	release
	end

SlateportCity_EventScript_TestBossNoBattle::
	msgbox SlateportCity_Text_TestBoss_NoBattle, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_TestBoss_FlagsAfterBattle::
	setflag FLAG_SLATEPORT_BOSS
	special IncrementPlayerKeys
	special IncrementWorldLevel
	goto_if_set FLAG_MAUVILLE_BOSS, SlateportCity_EventScript_AutoUnlock_Mauville
	goto_if_set FLAG_DEWFORD_BOSS, SlateportCity_EventScript_AutoUnlock_Dewford
	goto_if_set FLAG_PETALBURG_BOSS, SlateportCity_EventScript_AutoUnlock_Petalburg
	goto_if_set FLAG_MOSSDEEP_BOSS, SlateportCity_EventScript_AutoUnlock_Mossdeep
	release
	end

SlateportCity_EventScript_Check_ToMauville::
	goto_if_unset FLAG_SLATEPORT_MAUVILLE_STRETCH, SlateportCity_EventScript_Check_Slateport_Mauville
	end

SlateportCity_EventScript_Check_Slateport_Mauville::
	lock
	goto_if_unset FLAG_SLATEPORT_BOSS, SlateportCity_EventScript_ToMauville_BossUndefeated
	goto_if_lt VAR_NUMBER_OF_KEYS, 1, SlateportCity_EventScript_Cannot_Unlock_Mauville
	msgbox SlateportCity_Text_To_Mauville, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_Reject_ToMauville
	msgbox SlateportCity_Text_Accept_Mauville, MSGBOX_DEFAULT
	setflag FLAG_SLATEPORT_MAUVILLE_STRETCH
	copyvar VAR_SLATEPORT_MAUVILLE_LEVEL, VAR_WORLD_DIFFICULTY
	copyvar VAR_MAUVILLE_LEVEL, VAR_WORLD_DIFFICULTY
	special DecrementPlayerKeys
	release
	end

SlateportCity_EventScript_ToMauville_BossUndefeated::
	msgbox SlateportCity_Text_Boss_Undefeated, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_TurnFrom_Mauville
	waitmovement 0
	release
	end

SlateportCity_EventScript_AutoUnlock_Mauville::
	setflag FLAG_SLATEPORT_MAUVILLE_STRETCH
	copyvar VAR_SLATEPORT_MAUVILLE_LEVEL, VAR_WORLD_DIFFICULTY
	return
	end

SlateportCity_EventScript_Cannot_Unlock_Mauville::
	msgbox SlateportCity_Text_Cannot_Unlock, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_TurnFrom_Mauville
	waitmovement 0
	release
	end

SlateportCity_EventScript_Reject_ToMauville::
	msgbox SlateportCity_Text_Reject_Path, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_TurnFrom_Mauville
	waitmovement 0
	release
	end

SlateportCity_EventScript_Check_ToDewford::
	goto_if_unset FLAG_DEWFORD_SLATEPORT_STRETCH, SlateportCity_EventScript_Check_Dewford_Slateport
	end

SlateportCity_EventScript_Check_Dewford_Slateport::
	lock
	goto_if_unset FLAG_SLATEPORT_BOSS, SlateportCity_EventScript_ToDewford_BossUndefeated
	goto_if_lt VAR_NUMBER_OF_KEYS, 1, SlateportCity_EventScript_Cannot_Unlock_Dewford
	msgbox SlateportCity_Text_To_Dewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_Reject_ToDewford
	setflag FLAG_DEWFORD_SLATEPORT_STRETCH
	copyvar VAR_DEWFORD_SLATEPORT_LEVEL, VAR_WORLD_DIFFICULTY
	copyvar VAR_DEWFORD_LEVEL, VAR_WORLD_DIFFICULTY
	special DecrementPlayerKeys
	release
	end

SlateportCity_EventScript_ToDewford_BossUndefeated::
	msgbox SlateportCity_Text_Boss_Undefeated, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_TurnFrom_Dewford
	waitmovement 0
	release
	end

SlateportCity_EventScript_AutoUnlock_Dewford::
	setflag FLAG_DEWFORD_SLATEPORT_STRETCH
	copyvar VAR_DEWFORD_SLATEPORT_LEVEL, VAR_WORLD_DIFFICULTY
	return
	end

SlateportCity_EventScript_Cannot_Unlock_Dewford::
	msgbox SlateportCity_Text_Cannot_Unlock, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_TurnFrom_Dewford
	waitmovement 0
	release
	end

SlateportCity_EventScript_Reject_ToDewford::
	msgbox SlateportCity_Text_Reject_Path, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_TurnFrom_Dewford
	waitmovement 0
	release
	end

SlateportCity_EventScript_Check_ToPetalburg::
	goto_if_unset FLAG_PETALBURG_SLATEPORT_STRETCH, SlateportCity_EventScript_Check_Petalburg_Slateport
	end

SlateportCity_EventScript_Check_Petalburg_Slateport::
	lock
	goto_if_unset FLAG_SLATEPORT_BOSS, SlateportCity_EventScript_ToPetalburg_BossUndefeated
	goto_if_lt VAR_NUMBER_OF_KEYS, 1, SlateportCity_EventScript_Cannot_Unlock_Petalburg
	msgbox SlateportCity_Text_To_Petalburg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_Reject_ToPetalburg
	msgbox SlateportCity_Text_Accept_Petalburg, MSGBOX_DEFAULT
	setflag FLAG_PETALBURG_SLATEPORT_STRETCH
	copyvar VAR_PETALBURG_SLATEPORT_LEVEL, VAR_WORLD_DIFFICULTY
	copyvar VAR_PETALBURG_LEVEL, VAR_WORLD_DIFFICULTY
	special DecrementPlayerKeys
	release
	end

SlateportCity_EventScript_ToPetalburg_BossUndefeated::
	msgbox SlateportCity_Text_Boss_Undefeated, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_TurnFrom_Petalburg
	waitmovement 0
	release
	end

SlateportCity_EventScript_AutoUnlock_Petalburg::
	setflag FLAG_PETALBURG_SLATEPORT_STRETCH
	copyvar VAR_PETALBURG_SLATEPORT_LEVEL, VAR_WORLD_DIFFICULTY
	return
	end

SlateportCity_EventScript_Cannot_Unlock_Petalburg::
	msgbox SlateportCity_Text_Cannot_Unlock, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_TurnFrom_Petalburg
	waitmovement 0
	release
	end

SlateportCity_EventScript_Reject_ToPetalburg::
	msgbox SlateportCity_Text_Reject_Path, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_TurnFrom_Petalburg
	waitmovement 0
	release
	end

SlateportCity_EventScript_Check_ToMossdeep::
	goto_if_unset FLAG_SLATEPORT_MOSSDEEP_STRETCH, SlateportCity_EventScript_Check_Slateport_Mossdeep
	end

SlateportCity_EventScript_Check_Slateport_Mossdeep::
	lock
	goto_if_unset FLAG_SLATEPORT_BOSS, SlateportCity_EventScript_ToMossdeep_BossUndefeated
	goto_if_lt VAR_NUMBER_OF_KEYS, 1, SlateportCity_EventScript_Cannot_Unlock_Mossdeep
	msgbox SlateportCity_Text_To_Mossdeep, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_Reject_ToMossdeep
	setflag FLAG_SLATEPORT_MOSSDEEP_STRETCH
	copyvar VAR_SLATEPORT_MOSSDEEP_LEVEL, VAR_WORLD_DIFFICULTY
	copyvar VAR_MOSSDEEP_LEVEL, VAR_WORLD_DIFFICULTY
	special DecrementPlayerKeys
	release
	end

SlateportCity_EventScript_ToMossdeep_BossUndefeated::
	msgbox SlateportCity_Text_Boss_Undefeated, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_TurnFrom_Mossdeep
	waitmovement 0
	release
	end

SlateportCity_EventScript_AutoUnlock_Mossdeep::
	setflag FLAG_SLATEPORT_MOSSDEEP_STRETCH
	copyvar VAR_SLATEPORT_MOSSDEEP_LEVEL, VAR_WORLD_DIFFICULTY
	return
	end

SlateportCity_EventScript_Cannot_Unlock_Mossdeep::
	msgbox SlateportCity_Text_Cannot_Unlock, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_TurnFrom_Mossdeep
	waitmovement 0
	release
	end

SlateportCity_EventScript_Reject_ToMossdeep::
	msgbox SlateportCity_Text_Reject_Path, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_TurnFrom_Mossdeep
	waitmovement 0
	release
	end

SlateportyCity_EventScript_Already_Unlocked::
	return
	end

SlateportCity_Movement_TurnFrom_Mauville:
	walk_down
	step_end

SlateportCity_Movement_TurnFrom_Dewford:
	walk_up
	step_end

SlateportCity_Movement_TurnFrom_Petalburg:
	walk_right
	step_end

SlateportCity_Movement_TurnFrom_Mossdeep:
	walk_left
	step_end

SlateportCity_Text_ItemCollectorSellWhatYouNeed:
	.string "I collect rare items like Light Ball.\p"
	.string "If you want the kind of item that helps\n"
	.string "specific Pokemon evolve, you'll have to\l"
	.string "find my brother over in Lilycove.$"

SlateportCity_Text_OhYourPokemon:
	.string "Oh?\n"
	.string "Your {STR_VAR_1}…$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "Went for it stupendously!\p"
	.string "As its reward, please give it this\n"
	.string "EFFORT RIBBON.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} received the EFFORT RIBBON.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} put the EFFORT RIBBON\n"
	.string "on {STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "You have to go for it a little harder.\p"
	.string "If you do, I'll give your POKéMON\n"
	.string "something nice.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Oh! Your {STR_VAR_1}, that EFFORT\n"
	.string "RIBBON looks good on it!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "The light of the lighthouse reaches\n"
	.string "dozens of miles away.\p"
	.string "I wonder if it doesn't startle POKéMON\n"
	.string "in the sea.$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Ooh, look at this!\p"
	.string "The seaweed you can get around these\n"
	.string "parts is fresh and full of life.\p"
	.string "Why, it looks like it can even rear up\n"
	.string "and attack!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Where the water is clean, the fruits\n"
	.string "of bountiful harvest gather.\p"
	.string "And where people gather, a market\n"
	.string "soon starts.\p"
	.string "That is how a town is born and grows.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Shopping where you can breathe the\n"
	.string "scent of the ocean…\p"
	.string "SLATEPORT is such a wonderful place!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "If you put DOLLS or CUSHIONS on\n"
	.string "the floor, they'll get dirty.\p"
	.string "I'm going to buy some BRICKS so my\n"
	.string "DOLLS and CUSHIONS won't get dirty\l"
	.string "when I leave them out.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Wroooar! I'm going to compete in\n"
	.string "the BATTLE TENT, too!\p"
	.string "But before that, I need to catch\n"
	.string "some POKéMON!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Whew… I'm just bushed…\p"
	.string "I hiked over from MAUVILLE CITY.\n"
	.string "But, boy, this city's huge.\p"
	.string "If I'd known this, I would've ridden\n"
	.string "my BIKE here.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "STERN, the fellow who built the\n"
	.string "MUSEUM, also happens to be the leader\l"
	.string "of an undersea exploration team.\p"
	.string "So, everyone calls him CAPT. STERN.$"

SlateportCity_Text_VisitedMuseumOften:
	.string "When I was a child, I visited\n"
	.string "the MUSEUM often.\p"
	.string "I used to dream about the mysteries of\n"
	.string "the sea after seeing the exhibits.$"

SlateportCity_Text_SeaIsSoWet:
	.string "The sea is just so vast…\p"
	.string "Could the sea have been made by\n"
	.string "the tears shed by POKéMON?$"

SlateportCity_Text_SinkOldBoats:
	.string "Do you know what they do with old\n"
	.string "ships that become too creaky to sail?\p"
	.string "They sink them in the sea so they\n"
	.string "become habitats for POKéMON.$"

SlateportCity_Text_BuyTooMuch:
	.string "Whenever I visit here, I get carried\n"
	.string "away and buy too much.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "If you want to change your POKéMON's\n"
	.string "nickname, you'll have to get the NAME\l"
	.string "RATER to help you.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "Any POKéMON you get in a trade,\n"
	.string "you can't change its nickname.\p"
	.string "The original TRAINER's love for that\n"
	.string "POKéMON is in the nickname.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Recently, a BATTLE TENT was built\n"
	.string "in SLATEPORT.\p"
	.string "GYMS are fun, but the BATTLE TENT's\n"
	.string "awesome in its own way.\p"
	.string "You should go find tough POKéMON\n"
	.string "for the BATTLE TENT!$"

SlateportCity_Text_BattleTentSign:
	.string "BATTLE TENT SLATEPORT SITE\n"
	.string "“Find it! The ultimate POKéMON!”$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "STERN'S SHIPYARD\p"
	.string "“Wanted: A sailor capable of sailing\n"
	.string "in all currents.”$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "STERN'S SHIPYARD\p"
	.string "“Boarding of the SLATEPORT-LILYCOVE\n"
	.string "ferry S.S. TIDAL is handled at the\l"
	.string "HARBOR.”$"

SlateportCity_Text_PokemonFanClubSign:
	.string "POKéMON FAN CLUB\n"
	.string "“Calling all fans of POKéMON!”$"

SlateportCity_Text_OceanicMuseumSign:
	.string "“The endless sea sustains\n"
	.string "all life.”\p"
	.string "OCEANIC MUSEUM$"

SlateportCity_Text_CitySign:
	.string "SLATEPORT CITY\p"
	.string "“The port where people and POKéMON\n"
	.string "cross paths.”$"

SlateportCity_Text_MarketSign:
	.string "SLATEPORT MARKET\n"
	.string "“Unique items found nowhere else!”$"

SlateportCity_Text_HarborSign:
	.string "SLATEPORT HARBOR\p"
	.string "“Enjoy a delightful cruise on\n"
	.string "the ferry S.S. TIDAL.”$"

SlateportCity_Text_NameRatersHouseSign:
	.string "NAME RATER'S HOUSE\n"
	.string "“POKéMON nicknames rated.”$"

SlateportCity_Text_ExplainBerries:
	.string "If a wild POKéMON gets hurt, it heals\n"
	.string "itself by chewing on BERRIES.\p"
	.string "Did you know that?\p"
	.string "Somebody saw that and got the idea\n"
	.string "of making medicine from BERRIES.\p"
	.string "Did you know that?\p"
	.string "To turn BERRIES into medicine,\n"
	.string "they must be crushed into powder.\p"
	.string "Did you know that?\p"
	.string "You seem to have an interest\n"
	.string "in BERRIES!\p"
	.string "I've got something good for someone\n"
	.string "like you.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "I recently had machines installed at\n"
	.string "POKéMON CENTERS for crushing BERRIES.\p"
	.string "The BERRY CRUSH machines are at\n"
	.string "the DIRECT CORNER upstairs.\p"
	.string "Did you know?\p"
	.string "Could you make BERRY POWDER for\n"
	.string "me using those machines?\p"
	.string "I can make you all sorts of medicine\n"
	.string "if you bring me lots of BERRY POWDER.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "Have you brought me some\n"
	.string "BERRY POWDER?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "What would you like to exchange\n"
	.string "it with?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "Okay, you want to exchange your\n"
	.string "BERRY POWDER for one {STR_VAR_1}?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "Oh, dear. You don't have enough\n"
	.string "BERRY POWDER.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "This is fine BERRY POWDER.\n"
	.string "It will make excellent medicine.\p"
	.string "Would you like to trade more of your\n"
	.string "BERRY POWDER for something else?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "Okay! When you get some more\n"
	.string "BERRY POWDER, bring it to me, please!$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Come back if you'd like to trade your\n"
	.string "BERRY POWDER for some medicine.\p"
	.string "I'm always running a bazaar here.\p"
	.string "Did you know?$"

SlateportCity_Text_TestBoss_Intro:
	.string "I am the boss for Slateport!\n"
	.string "Do you want to battle me?$"

SlateportCity_Text_TestBoss_NoBattle:
	.string "Maybe next time, then.$"

SlateportCity_Text_TestBoss_YesBattle:
	.string "Let's battle!$"

SlateportCity_Text_TestBoss_Lose:
	.string "Wow you're strong!\p"
	.string "Totally not becuase you're using hacked\n"
	.string "test Pokemon or anything.\p"
	.string "The world level should now increase.$"

SlateportCity_Text_TestBoss_PostBattle:
	.string "Oh, you should have also gotten a key.\p"
	.string "It's not in your inventory though.\n"
	.string "It's a var in the script!$"

SlateportCity_Text_Boss_Undefeated:
	.string "There are still things I need\n"
	.string "to do here.$"

SlateportCity_Text_Cannot_Unlock:
	.string "I have things to do elsewhere first.$"

SlateportCity_Text_To_Mauville:
	.string "This is the way to Mauville City...\n"
	.string "Head this way?$"

SlateportCity_Text_Accept_Mauville:
	.string "Time to head for Mauville City.$"

SlateportCity_Text_To_Dewford:
	.string "This is the way to Dewford Town...\n"
	.string "Head this way?$"

SlateportCity_Text_Accept_Dewford:
	.string "Time to head for Dewford Town.$"

SlateportCity_Text_To_Petalburg:
	.string "This is the way to Petalburg City...\n"
	.string "Head this way?$"

SlateportCity_Text_Accept_Petalburg:
	.string "Time to head for Petalburg City.$"

SlateportCity_Text_To_Mossdeep:
	.string "This is the way to Mossdeep City...\n"
	.string "Head this way?$"

SlateportCity_Text_Accept_Mossdeep:
	.string "Time to head for Mossdeep City.$"

SlateportCity_Text_Reject_Path:
	.string "Maybe next time.$"

SlateportCity_Text_DoorLocked:
	.string "Better not draw too much attention\n"
	.string "by wandering into random buildings.$"
