Hauntwood_Epsilon_MapScripts::
	.byte 0

SpeakToShrine::
	lock
	call ShrineTextBranch

ShrineTextBranch::
	goto_if_lt VAR_HAUNTWOOD_SHRINE, 1, KarmaBlack
	goto_if_lt VAR_HAUNTWOOD_SHRINE, 5, KarmaDarkGrey
	goto_if_lt VAR_HAUNTWOOD_SHRINE, 10, KarmaDarkening
	goto_if_eq VAR_HAUNTWOOD_SHRINE, 10, KarmaGrey
	goto_if_lt VAR_HAUNTWOOD_SHRINE, 15, KarmaLightening
	goto_if_lt VAR_HAUNTWOOD_SHRINE, 20, KarmaLightGrey
	goto_if_eq VAR_HAUNTWOOD_SHRINE, 20, KarmaWhite

KarmaBlack::
	msgbox KarmaBlackText MSGBOX_AUTOCLOSE
	release
	end

KarmaBlackText:
	.string "Your karma is 0.$"

KarmaDarkGrey::
	msgbox KarmaDarkGreyText MSGBOX_AUTOCLOSE
	release
	end

KarmaDarkGreyText:
	.string "Your karma is 1-4.$"

KarmaDarkening::
	msgbox KarmaDarkeningText MSGBOX_AUTOCLOSE
	release
	end

KarmaDarkeningText:
	.string "Your karma is 5-9.$"

KarmaGrey::
	msgbox KarmaGreyText MSGBOX_AUTOCLOSE
	release
	end

KarmaGreyText:
	.string "Your karma is 10.$"

KarmaLightening::
	msgbox KarmaLighteningText MSGBOX_AUTOCLOSE
	release
	end

KarmaLighteningText:
	.string "Your karma is 11-14.$"

KarmaLightGrey::
	msgbox KarmaLightGreyText MSGBOX_AUTOCLOSE
	release
	end

KarmaLightGreyText:
	.string "Your karma is 15-19.$"

KarmaWhite::
	msgbox KarmaWhiteText MSGBOX_AUTOCLOSE
	release
	end

KarmaWhiteText:
	.string "Your karma is 20.$"
