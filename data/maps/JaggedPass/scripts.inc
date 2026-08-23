JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	end

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_EventScript_CleverFeather::
	goto_if_eq VAR_WORLD_DIFFICULTY, 0, JaggedPass_ThreeCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 1, JaggedPass_ThreeCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 2, JaggedPass_ThreeCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 3, JaggedPass_ThreeCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 4, JaggedPass_FourCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 5, JaggedPass_FourCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 6, JaggedPass_FourCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 7, JaggedPass_FourCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 8, JaggedPass_FiveCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 9, JaggedPass_FiveCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 10, JaggedPass_FiveCleverFeathers
	goto_if_eq VAR_WORLD_DIFFICULTY, 11, JaggedPass_FiveCleverFeathers
	end

JaggedPass_ThreeCleverFeathers::
	finditem ITEM_CLEVER_FEATHER, amount=3
	end

JaggedPass_FourCleverFeathers::
	finditem ITEM_CLEVER_FEATHER, amount=4
	end

JaggedPass_FiveCleverFeathers::
	finditem ITEM_CLEVER_FEATHER, amount=5
	end

JaggedPass_EventScript_OpenMagmaHideout::
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.string "MT. CHIMNEY's JAGGED PASS…\p"
	.string "Now this is what I've always wanted\n"
	.string "in a mountain.\p"
	.string "This jagged bumpiness…\n"
	.string "It rocks my soul!$"

JaggedPass_Text_EricDefeat:
	.string "Losing left me bitter!$"

JaggedPass_Text_EricPostBattle:
	.string "Yes, I did lose at POKéMON…\p"
	.string "But, when it comes to the love of\n"
	.string "the mountains, I have you beat!$"

JaggedPass_Text_DianaIntro:
	.string "This place isn't your casual hike.\n"
	.string "It's not suited for a picnic.$"

JaggedPass_Text_DianaDefeat:
	.string "Ohhh, no!\n"
	.string "The ground is too bumpy…$"

JaggedPass_Text_DianaPostBattle:
	.string "Did you know?\p"
	.string "Some people cleverly ride their\n"
	.string "bicycles up this horribly bumpy pass.$"

JaggedPass_Text_EthanIntro:
	.string "JAGGED PASS is hard to walk on.\n"
	.string "It's a good place for training.$"

JaggedPass_Text_EthanDefeat:
	.string "It was all over while we were still\n"
	.string "trying to find a good footing…$"

JaggedPass_Text_EthanPostBattle:
	.string "If I had an ACRO BIKE, I'd be able to\n"
	.string "jump ledges.$"

JaggedPass_Text_JulioIntro:
	.string "Aiyeeh! It's awfully scary to shoot\n"
	.string "down the mountain in one go!$"

JaggedPass_Text_JulioDefeat:
	.string "I feel like I'm falling apart…$"

JaggedPass_Text_JulioPostBattle:
	.string "My bicycle bounced around so much,\n"
	.string "my rear end's sore…$"

JaggedPass_Text_AutumnIntro:
	.string "I climb this hill every day.\n"
	.string "I have confidence in my strength!$"

JaggedPass_Text_AutumnDefeat:
	.string "Hmm…\n"
	.string "What went wrong?$"

JaggedPass_Text_AutumnPostBattle:
	.string "What is that odd rock protrusion\n"
	.string "a little up the hill from here?$"

