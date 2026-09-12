MauvilleCity_Gym_MapScripts::
	.byte 0

MauvilleGym_EventScript_Wally::
	lock
	faceplayer
	@goto_if_set FLAG_DEFEATED_MAUVILLE_GYM_TRAINERS, MauvilleGym_EventScript_ChallengeWally
	msgbox MauvilleGym_Text_IAmLeaderWally, MSGBOX_DEFAULT
	applymovement Wally, MauvilleLookDown
	waitmovement 0
	release
	end

MauvilleGym_EventScript_ChallengeWally::
	@trainerbattle_single TRAINER_WALLY, MauvilleGym_Text_WallyIntro, MauvilleGym_Text_WallyDefeated
	@msgbox MauvilleGym_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	giveitem ITEM_TM_SWEET_SCENT
	release
	end

MauvilleGym_Wally_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_JACQUES, MauvilleGym_Wally_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_MADISON, MauvilleGym_Wally_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_LINIE, MauvilleGym_Wally_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_LUGNER, MauvilleGym_Wally_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_MAUVILLE_GYM_TRAINERS
	release
	end

MauvilleGym_Wally_EventScript_TrainersNotCompleted::
	release
	end

MauvilleGym_EventScript_Jacques::
	@trainerbattle_single TRAINER_JACQUES, MauvilleGym_Text_JacquesIntro, MauvilleGym_Text_JacquesDefeated, MauvilleGym_Wally_EventScript_CheckTrainersCompletion
	@msgbox MauvilleGym_Text_JacquesPostBattle, MSGBOX_AUTOCLOSE
	applymovement Jacques, MauvilleLookDown
	waitmovement 0
	release
	end

MauvilleGym_EventScript_Madison::
	@trainerbattle_single TRAINER_MADISON, MauvilleGym_Text_MadisonIntro, MauvilleGym_Text_MadisonDefeated, MauvilleGym_Wally_EventScript_CheckTrainersCompletion
	@msgbox MauvilleGym_Text_MadisonPostBattle, MSGBOX_AUTOCLOSE
	applymovement Madison, MauvilleLookLeft
	waitmovement 0
	release
	end

MauvilleGym_EventScript_Linie::
	@trainerbattle_single TRAINER_LINIE, MauvilleGym_Text_LinieIntro, MauvilleGym_Text_LinieDefeated, MauvilleGym_Wally_EventScript_CheckTrainersCompletion
	@msgbox MauvilleGym_Text_LiniePostBattle, MSGBOX_AUTOCLOSE
	applymovement Linie, MauvilleLookDown
	waitmovement 0
	release
	end

MauvilleGym_EventScript_Lugner::
	@trainerbattle_single TRAINER_LUGNER, MauvilleGym_Text_LugnerIntro, MauvilleGym_Text_LugnerDefeated, MauvilleGym_Wally_EventScript_CheckTrainersCompletion
	@msgbox MauvilleGym_Text_LugnerPostBattle, MSGBOX_AUTOCLOSE
	applymovement Lugner, MauvilleLookLeft
	waitmovement 0
	release
	end

MauvilleGym_EventScript_Guide::
	@msgbox MauvilleGym_Text_Guide, MSGBOX_YESNO
	switch VAR_RESULT
	goto_if_eq VAR_RESULT, NO, MauvilleGym_EventScript_GuideNo
	goto_if_eq VAR_RESULT, YES, MauvilleGym_EventScript_GuideYes
	applymovement Guide, MauvilleLookUp
	waitmovement 0
	release
	end

MauvilleGym_EventScript_GuideNo::
	@msgbox MauvilleGym_Text_GuideNo, MSGBOX_AUTOCLOSE
	applymovement Guide, MauvilleLookUp
	waitmovement 0
	release
	end

MauvilleGym_EventScript_GuideYes::
	@msgbox MauvilleGym_Text_GuideYes, MSGBOX_AUTOCLOSE
	applymovement Guide, MauvilleLookUp
	waitmovement 0
	release
	end

MauvilleGym_EventScript_Drake::
	@msgbox MauvilleGym_Text_Drake, MSGBOX_AUTOCLOSE
	applymovement Drake, MauvilleLookRight
	waitmovement 0
	release
	end

MauvilleGym_EventScript_Wattson::
	@msgbox MauvilleGym_Text_Wattson, MSGBOX_AUTOCLOSE
	applymovement Wattson, MauvilleLookDown
	waitmovement 0
	release
	end

MauvilleGym_EventScript_Barista::
	lock
	faceplayer
	message MauvilleGym_Text_Barista
	waitmessage
	pokemart MauvilleGym_Pokemart_Barista
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end
	.align 2

MauvilleGym_Pokemart_Barista:
	.2byte ITEM_LEMONADE
	.2byte ITEM_STRAWBERRY_SWEET
	.2byte ITEM_LOVE_SWEET
	.2byte ITEM_BERRY_SWEET
	.2byte ITEM_CLOVER_SWEET
	.2byte ITEM_FLOWER_SWEET
	.2byte ITEM_STAR_SWEET
	.2byte ITEM_RIBBON_SWEET
	pokemartlistend

MauvilleGym_Text_Guide:
	.string "Hello, and welcome to the Mauville Gym,\n"
	.string "Hoenn's first ever Fairy-type gym!\p"
	.string "Don't let the gentle look of this cafe\n"
	.string "fool you. The delicious scent of tea\l"
	.string "and pastries has filled the building\l"
	.string "with Aromatic Terrain.\p"
	.string "Are you familiar? I can tell you more.$"
	 
MauvilleGym_Text_GuideYes:
	.string "You might have encountered it if\n"
	.string "you've seen the move Sweet Scent\l"
	.string "or ability Aroma Veil.$"

MauvilleGym_Text_GuideNo:
	.string "Sounds like you're prepared!\n"
	.string "I'll wish you luck, then.$"

MauvilleGym_Text_IAmLeaderWally:
	.string "Welcome to my gym! I'm Leader Wally.\n"
	.string "If you're here for my badge, you'll\l"
	.string "need to defeat my Gym Trainers first.\p"
	.string "If you're not, feel free to buy a drink\n"
	.string "and stay a while.$"

MauvilleGym_Text_WallyIntro:
	.string "Your battles were impressive, truly.\n"
	.string "You have panache. You can go far.\p"
	.string "However, the way you command your\n"
	.string "Pokemon... Hmm.\p"
	.string "How many badges do you have? I see.\n"
	.string "I will battle you with the full force\l"
	.string "I am entitled to under my Gym Charter.\p"
	.string "To the extent I can, I will hold\n"
	.string "nothing back.\p"
	.string "I would ask of you the same, but I\n"
	.string "don't believe I have to, yes?$"

MauvilleGym_Text_WallyDefeated:
	.string "It is as I suspected...$"

MauvilleGym_Text_WallyPostBattle:
	.string "It is as I suspected. Your Pokemon are a\n"
	.string "means to an end for you, are they not?\p"
	.string "I will grant you my badge, as I am\n"
	.string "obligated to. Do not mistake it\l"
	.string "for my approval.\p"
	.string "You have within you a spark of\n"
	.string "something brighter.\l"
	.string "I hope, through your adventures in\l"
	.string "Hoenn, it will be nurtured.\p"
	.string "Here. I was waffling over whether I\n"
	.string "should give it to you...\l"
	.string "but hopefully it reminds you that\l"
	.string "battling isn't always serious.\l"
	.string "It can be charming and fun.\p"
	.string "Should you ever understand what I am\n"
	.string "trying to express, please, feel free\l"
	.string "to return here. I will battle you again.\p"
	.string "That time, perhaps, we will both\n"
	.string "be able to enjoy ourselves.$"
	 
MauvilleGym_Text_JacquesIntro:
	.string "What a perfect job for a retiree\n"
	.string "like me!\p"
	.string "Sit down, eat sweets, and test the\n"
	.string "mettle of the next generation!$"

MauvilleGym_Text_JacquesDefeated:
	.string "Mettle tested! You've got, heh, spark!$"

MauvilleGym_Text_JacquesPostBattle:
	.string "Hmm. Maybe, instead of 'spark,'\n"
	.string "I should say you have a sweet scent?\p"
	.string "No, I really shouldn't...$"

MauvilleGym_Text_MadisonIntro:
	.string "Thank Arceus, a distraction.$"

MauvilleGym_Text_MadisonDefeated:
	.string "Over too soon...$"

MauvilleGym_Text_MadisonPostBattle:
	.string "It's not that Jacques is bad company.\n"
	.string "It's that he's too much company,\l"
	.string "you know?\p"
	.string "Sometimes, I just want to enjoy\n"
	.string "my tea and my thoughts.$"

MauvilleGym_Text_LinieIntro:
	.string "I sat here so I could eavesdrop on\n"
	.string "those old guys.\p"
	.string "Apparently, they were bigshot trainers\n"
	.string "back in my parents' day.\p"
	.string "But they don't have anything useful\n"
	.string "to say at all!$"

MauvilleGym_Text_LinieDefeated:
	.string "This is so stupid!$"

MauvilleGym_Text_LiniePostBattle:
	.string "Whatever! I would've won if those\n"
	.string "old guys had helped at all.$"

MauvilleGym_Text_LugnerIntro:
	.string "My father told me all the up-and-coming\n"
	.string "guitarists work a season or two at\l"
	.string "Mauville Gym.\p"
	.string "I can't understand why at all,\n"
	.string "I feel so out of place.$"

MauvilleGym_Text_LugnerDefeated:
	.string "I was too embarrassed to lock in...$"

MauvilleGym_Text_LugnerPostBattle:
	.string "I'll say this though, the croissants\n"
	.string "here rock.$"

MauvilleGym_Text_Drake:
	.string "Hmph. Do I look like a Gym Trainer?\n"
	.string "Don't the kids recognize me anymore?\p"
	.string "If you want a battle, defeat that brat\n"
	.string "Wally first and buy me a coffee;\l"
	.string "then, I'll crush you with my dragons.$"

MauvilleGym_Text_Wattson:
	.string "Wahahahaha! I like that look in\n"
	.string "your eye, youngster. Tell you what.\p"
	.string "If you can claim my successor's badge,\n"
	.string "buy me a coffee and I'll show you that\l"
	.string "even retired Pokemon can electrify!$"

MauvilleGym_Text_Barista:
	.string "Welcome to the Mauville Aroma Cafe!\n"
	.string "We serve sweets, tea, and coffee.\l"
	.string "What would you like?$"

MauvilleLookDown:
	face_down
	step_end

MauvilleLookUp:
	face_up
	step_end

MauvilleLookLeft:
	face_left
	step_end

MauvilleLookRight:
	face_right
	step_end
