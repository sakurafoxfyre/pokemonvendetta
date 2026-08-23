Hauntwood_MapScripts::
	.byte 0

LucianToPetalburg::
	msgbox Text_LucianToPetalburg MSGBOX_YESNO 
	goto_if_eq VAR_RESULT, YES, TaxiToPetalburg
	end

TaxiToPetalburg::
	warp MAP_PETALBURG_CITY, 15, 12
	waitstate
	release
	end

Text_LucianToPetalburg:
	.string "This place is creepy. You quite done?$"
