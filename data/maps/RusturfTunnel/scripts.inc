RusturfTunnel_MapScripts::
	.byte 0

RusturfTunnel_EventScript_TunnelBlockagePos1::
	setvar VAR_TEMP_1, 1
	end

RusturfTunnel_EventScript_TunnelBlockagePos2::
	setvar VAR_TEMP_1, 2
	end

RusturfTunnel_EventScript_TunnelBlockagePos3::
	setvar VAR_TEMP_1, 3
	end

RusturfTunnel_EventScript_Mike::
	trainerbattle_single TRAINER_MIKE, RusturfTunnel_Text_MikeIntro, RusturfTunnel_Text_MikeDefeat
	msgbox RusturfTunnel_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end

RusturfTunnel_Text_MikeIntro:
	.string "I've been keeping an eye on Rusturf\n"
	.string "for years.\p"
	.string "You treating the cave alright, kid?$"

RusturfTunnel_Text_MikeDefeat:
	.string "Not like I could make ya...$"

RusturfTunnel_Text_MikePostBattle:
	.string "Long time ago, they halted development\n"
	.string "to protect Pokemon. Made me feel proud\l"
	.string "to be Hoennian.\p"
	.string "Few years ago, they imported Carbink and\n"
	.string "Glimmet, and the first Glimmora predated\l"
	.string "on all the Carbink. It was real bad...\p"
	.string "Fortunately, something changed, and now\n"
	.string "the Glimmet leave the Carbink alone.\p"
	.string "But I don't like how nobody put a stop\n"
	.string "to Aether. Thought we learned our lesson\l"
	.string "about intefering in nature. Guess not.$"
