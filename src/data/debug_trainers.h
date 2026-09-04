//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/debug_trainers.party
//
// If you want to modify this file see expansion PR #7154
//

#line 1 "src/data/debug_trainers.party"

#line 14
    [DIFFICULTY_NORMAL][DEBUG_TRAINER_PLAYER] =
    {
#line 15
        .trainerName = _("Player"),
#line 16
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 17
        .trainerPic = TRAINER_PIC_BRENDAN,
#line 18
        .gender = TRAINER_GENDER_MALE,
#line 19
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 0
        .multiTeamSize = MULTI_TEAM_SIZE_FULL,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 21
            .nickname = COMPOUND_STRING("Buffie"),
#line 21
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 24
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 23
            .lvl = 100,
            .ball = POKEBALL_COUNT,
#line 22
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 25
                MOVE_EARTHQUAKE,
                MOVE_FLAMETHROWER,
                MOVE_CELEBRATE,
                MOVE_CELEBRATE,
            },
            },
        },
    },
#line 30
    [DIFFICULTY_NORMAL][DEBUG_TRAINER_AI] =
    {
#line 31
        .trainerName = _("Debugger"),
#line 33
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 35
        .trainerPic = TRAINER_PIC_STEVEN,
#line 36
        .gender = TRAINER_GENDER_MALE,
#line 37
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 34
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 32
        .aiFlags = AI_FLAG_SMART_TRAINER,
#line 0
        .multiTeamSize = MULTI_TEAM_SIZE_FULL,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 39
            .species = SPECIES_METANG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 42
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 41
            .lvl = 42,
            .ball = POKEBALL_COUNT,
#line 40
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 43
                MOVE_LIGHT_SCREEN,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_METAL_CLAW,
            },
            },
            {
#line 48
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 51
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 50
            .lvl = 43,
            .ball = POKEBALL_COUNT,
#line 49
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 52
                MOVE_TOXIC,
                MOVE_AERIAL_ACE,
                MOVE_PROTECT,
                MOVE_STEEL_WING,
            },
            },
            {
#line 57
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 60
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 59
            .lvl = 44,
            .ball = POKEBALL_COUNT,
#line 58
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 61
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_SOLAR_BEAM,
                MOVE_DRAGON_CLAW,
            },
            },
        },
    },
