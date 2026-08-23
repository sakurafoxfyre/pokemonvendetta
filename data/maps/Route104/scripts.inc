Route104_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_OnTransition
	.byte 0

Route104_OnTransition:
	call Route104_EventScript_ShowOrHideWhiteHerbFlorist
	end

Route104_EventScript_ShowOrHideWhiteHerbFlorist::
	goto_if_unset FLAG_BADGE03_GET, Route104_EventScript_HideWhiteHerbFlorist
	return

Route104_EventScript_ResistFeather::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, Route104_ThreeResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, Route104_ThreeResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, Route104_ThreeResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, Route104_ThreeResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, Route104_FourResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, Route104_FourResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, Route104_FourResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, Route104_FourResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, Route104_FiveResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, Route104_FiveResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, Route104_FiveResistFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, Route104_FiveResistFeathers
	end

Route104_ThreeResistFeathers::
	finditem ITEM_RESIST_FEATHER, amount=3
	end

Route104_FourResistFeathers::
	finditem ITEM_RESIST_FEATHER, amount=4
	end

Route104_FiveResistFeathers::
	finditem ITEM_RESIST_FEATHER, amount=5
	end

Route104_EventScript_NestBalls::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, Route104_FiveNestBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, Route104_FiveNestBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, Route104_FiveNestBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, Route104_FiveNestBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, Route104_SevenNestBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, Route104_SevenNestBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, Route104_SevenNestBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, Route104_SevenNestBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, Route104_TenNestBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, Route104_TenNestBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, Route104_TenNestBalls
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, Route104_TenNestBalls
	end

Route104_FiveNestBalls::
	finditem ITEM_NEST_BALL, amount=5
	end

Route104_SevenNestBalls::
	finditem ITEM_NEST_BALL, amount=7
	end

Route104_TenNestBalls::
	finditem ITEM_NEST_BALL, amount=10
	end

Route104_EventScript_HideWhiteHerbFlorist::
	return

Route104_EventScript_ExpertF::
	lock
	faceplayer
	msgbox Route104_Text_PlantBerriesInSoilTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_CHESTO_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_ReceivedBerry::
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_WhiteHerbFlorist::
	lock
	faceplayer
	msgbox Route104_Text_DontNeedThisTakeIt, MSGBOX_DEFAULT
	giveitem ITEM_WHITE_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

Route104_EventScript_ReceivedWhiteHerb::
	msgbox Route104_Text_FlowerShopSellingSaplings, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_Girl1::
	msgbox Route104_Text_BrineyLivesInSeasideCottage, MSGBOX_NPC
	end

Route104_EventScript_BugCatcher::
	msgbox Route104_Text_WhatsItLikeAtBottomOfSea, MSGBOX_SIGN
	end

Route104_EventScript_BrineysCottageSign::
	msgbox Route104_Text_MrBrineysCottage, MSGBOX_SIGN
	end

Route104_EventScript_RouteSignPetalburg::
	msgbox Route104_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route104_EventScript_RouteSignRustboro::
	msgbox Route104_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route104_EventScript_FlowerShopSign::
	msgbox Route104_Text_PrettyPetalFlowShop, MSGBOX_SIGN
	end

Route104_EventScript_TrainerTipsDoubleBattles::
	msgbox Route104_Text_TrainerTipsDoubleBattles, MSGBOX_SIGN
	end

Route104_EventScript_Boy1::
	msgbox Route104_Text_ThrowBallAtWeakenedPokemon, MSGBOX_NPC
	end

Route104_EventScript_Woman::
	msgbox Route104_Text_OnlyThrowBallAtWildPokemon, MSGBOX_NPC
	end

Route104_EventScript_Boy2::
	lock
	faceplayer
	msgbox Route104_Text_LikeFillingMouthWithSeedsTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_BULLET_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

Route104_EventScript_ReceivedBulletSeed::
	msgbox Route104_Text_TMsAreOneTimeUse, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_Girl2::
	msgbox Route104_Text_ImNotATrainer, MSGBOX_NPC
	end

Route104_EventScript_Ivan::
	trainerbattle_single TRAINER_IVAN, Route104_Text_IvanIntro, Route104_Text_IvanDefeat
	msgbox Route104_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_Joel::
	trainerbattle_single TRAINER_JOEL, Route104_Text_JoelIntro, Route104_Text_JoelDefeat
	msgbox Route104_Text_JoelPostBattle, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_Billy::
	trainerbattle_single TRAINER_BILLY, Route104_Text_BillyIntro, Route104_Text_BillyDefeat
	msgbox Route104_Text_BillyPostBattle, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_Haley::
	trainerbattle_single TRAINER_HALEY, Route104_Text_HaleyIntro, Route104_Text_HaleyDefeat
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_Winston::
	trainerbattle_single TRAINER_WINSTON, Route104_Text_WinstonIntro, Route104_Text_WinstonDefeat
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_Cindy::
	trainerbattle_single TRAINER_CINDY, Route104_Text_CindyIntro, Route104_Text_CindyDefeat
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_Gina::
	trainerbattle_double TRAINER_GINA_AND_MIA, Route104_Text_GinaIntro, Route104_Text_GinaDefeat, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route104_Text_GinaPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_Mia::
	trainerbattle_double TRAINER_GINA_AND_MIA, Route104_Text_MiaIntro, Route104_Text_MiaDefeat, Route104_Text_MiaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route104_Text_MiaPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_Darian::
	trainerbattle_single TRAINER_DARIAN, Route104_Text_DarianIntro, Route104_Text_DarianDefeat
	msgbox Route104_Text_DarianPostBattle, MSGBOX_AUTOCLOSE
	end

Route104_Text_BrineyLivesInSeasideCottage:
	.string "That seaside cottage is where\n"
	.string "MR. BRINEY lives.\p"
	.string "He was once a mighty sailor who never\n"
	.string "feared the sea, however stormy.$"

Route104_Text_WhatsItLikeAtBottomOfSea:
	.string "The sea, huh?\p"
	.string "I wonder what it's like at the bottom\n"
	.string "of the sea?$"

Route104_Text_ThrowBallAtWeakenedPokemon:
	.string "If you're going to throw a POKé BALL,\n"
	.string "weaken the wild POKéMON first.\p"
	.string "It will be easier to catch if it's been\n"
	.string "poisoned, burned, or lulled to sleep.$"

Route104_Text_OnlyThrowBallAtWildPokemon:
	.string "You're a thief if you try to steal\n"
	.string "someone else's POKéMON.\p"
	.string "You should throw POKé BALLS only at\n"
	.string "wild POKéMON.$"

Route104_Text_ImNotATrainer:
	.string "Oh, no, I'm not a TRAINER.\p"
	.string "But that's right, if TRAINERS lock eyes,\n"
	.string "it's a challenge to battle.\p"
	.string "If you don't want to battle, stay out\n"
	.string "of their sight.$"

Route104_Text_LikeFillingMouthWithSeedsTakeThis:
	.string "I like filling my mouth with seeds,\n"
	.string "then spitting them out fast!\p"
	.string "You can have this, so you try it out!\p"
	.string "Use it on a POKéMON, and it will learn\n"
	.string "a move for firing seeds rapidly.$"

Route104_Text_TMsAreOneTimeUse:
	.string "A word of advice!\p"
	.string "A TM, TECHNICAL MACHINE, is good only\n"
	.string "for one-time use.\p"
	.string "Once you use it, it's gone.\n"
	.string "Think twice before using it!$"

Route104_Text_DontNeedThisTakeIt:
	.string "This FLOWER SHOP started selling\n"
	.string "saplings recently.\p"
	.string "It made me so happy, I went overboard\n"
	.string "shopping.\p"
	.string "I don't need this WHITE HERB anymore.\n"
	.string "Would you take it, please?$"

Route104_Text_FlowerShopSellingSaplings:
	.string "This FLOWER SHOP started selling\n"
	.string "saplings recently.\p"
	.string "It made me so happy, I went overboard\n"
	.string "shopping. Where should I put them?$"

Route104_Text_MrBrineysCottage:
	.string "MR. BRINEY'S COTTAGE$"

Route104_Text_RouteSignPetalburg:
	.string "ROUTE 1O4\n"
	.string "{RIGHT_ARROW} PETALBURG CITY$"

Route104_Text_RouteSignRustboro:
	.string "ROUTE 1O4\n"
	.string "{UP_ARROW} RUSTBORO CITY$"

Route104_Text_PrettyPetalFlowShop:
	.string "PRETTY PETAL FLOWER SHOP$"

Route104_Text_TrainerTipsDoubleBattles:
	.string "TRAINER TIPS\p"
	.string "In the HOENN region there are pairs\n"
	.string "of TRAINERS who challenge others\l"
	.string "for 2-on-2 POKéMON battles called\l"
	.string "DOUBLE BATTLES.\p"
	.string "In a DOUBLE BATTLE, the TRAINER must\n"
	.string "send out two POKéMON, the one at the\l"
	.string "left of the list and the top one.\l"
	.string "Watch how POKéMON are lined up.$"
