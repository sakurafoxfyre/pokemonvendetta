MirageTower_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MirageTower_1F_OnTransition
	.byte 0

MirageTower_1F_OnTransition:
	setflag FLAG_ENTERED_MIRAGE_TOWER
	setflag FLAG_LANDMARK_MIRAGE_TOWER
	end

