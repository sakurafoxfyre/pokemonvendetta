SlateportCity_House_MapScripts::
	.byte 0

SlateportDreamHouse::
	lock
	goto_if_le VAR_KARMA 50, BadDreams
	goto_if_gt VAR_KARMA, 50, GoodDreams
	release
	end

BadDreams::
	msgbox Text_BadDreams
	closemessage
	end

GoodDreams::
	msgbox Text_GoodDreams
	closemessage
	end

Text_BadDreams:
	.string "You have bad dreams.$"

Text_GoodDreams:
	.string "You have good dreams.$"
