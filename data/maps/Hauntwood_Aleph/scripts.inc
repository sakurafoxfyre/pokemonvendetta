Hauntwood_Aleph_MapScripts::
	.byte 0

MadamMarigoldSign::
	msgbox Text_MadamMarigoldSign MSGBOX_AUTOCLOSE
	end

MadamMarigoldDoorClosed::
	msgbox Text_MadamMarigoldSign MSGBOX_AUTOCLOSE
	end

Text_MadamMarigoldSign:
	.string "RESIDENCE of MADAM MARIGOLD\n"
	.string "Charms, Potions, Trinkets, & Lotions$"

Text_DoorIsLocked:
	.string "The knob turns, but the door doesn't open.\n"
	.string "Pressing your ear to the decaying wood,\l"
	.string "you hear deep breathing on the other side.$"
	