#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "data.h"
#include "graphics.h"
#include "trainer_pools.h"
#include "battle_transition.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/trainers.h"
#include "constants/battle_ai.h"
#include "event_data.h"
#include "script_ven_util.h"
#include "trainer_pools.h"

//0-4, 5-8, 9-10

//pool length variables
//class
const int hiker04Length = 11;
const int hiker58Length = 11;
const int hiker910Length = 11;
const int team_aqua04Length = 10;
const int team_aqua58Length = 10;
const int team_aqua910Length = 10;
const int pkmn_breeder04Length = 10;
const int pkmn_breeder58Length = 10;
const int pkmn_breeder910Length = 10;
const int cooltrainer04Length = 10;
const int cooltrainer58Length = 10;
const int cooltrainer910Length =10;
const int bird_keeper04Length = 10;
const int bird_keeper58Length = 10;
const int bird_keeper910Length = 10;
const int collector04Length = 6;
const int collector58Length = 10;
const int collector910Length = 10;
const int swimmer04Length = 10;
const int swimmer58Length = 10;
const int swimmer910Length = 10;
const int team_magma04Length = 10;
const int team_magma58Length = 10;
const int team_magma910Length = 10;
const int expert04Length = 10;
const int expert58Length = 14;
const int expert910Length = 14;
const int black_belt04Length = 5;
const int black_belt58Length = 9;
const int black_belt910Length = 9;
const int hex_maniac04Length = 8;
const int hex_maniac58Length = 8;
const int hex_maniac910Length = 8;
const int aroma_lady04Length = 6;
const int aroma_lady58Length = 13;
const int aroma_lady910Length = 13;
const int ruin_maniac04Length = 8;
const int ruin_maniac58Length = 8;
const int ruin_maniac910Length = 8;
const int tuber04Length = 10;
const int tuber58Length = 10;
const int tuber910Length = 10;
const int lady04Length = 7;
const int lady58Length = 10;
const int lady910Length = 10;
const int beauty04Length = 7;
const int beauty58Length = 10;
const int beauty910Length = 10;
const int rich_boy04Length = 8;
const int rich_boy58Length = 8;
const int rich_boy910Length = 8;
const int pokemaniac04Length = 10;
const int pokemaniac58Length = 10;
const int pokemaniac910Length = 10;
const int guitarist04Length = 8;
const int guitarist58Length = 8;
const int guitarist910Length = 8;
const int kindler04Length = 11;
const int kindler58Length = 11;
const int kindler910Length = 11;
const int camper04Length = 10;
const int camper58Length = 10;
const int camper910Length = 10;
const int picnicker04Length = 10;
const int picnicker58Length = 10;
const int picnicker910Length = 10;
const int bug_maniac04Length = 9;
const int bug_maniac58Length = 11;
const int bug_maniac910Length = 11;
const int psychic04Length = 8;
const int psychic58Length = 8;
const int psychic910Length = 8;
const int gentleman04Length = 8;
const int gentleman58Length = 8;
const int gentleman910Length = 8;
const int school_kid04Length = 8;
const int school_kid58Length = 8;
const int school_kid910Length = 8;
const int sr_and_jr04Length = 9;
const int sr_and_jr58Length = 9;
const int sr_and_jr910Length = 9;
const int pokefan04Length = 10;
const int pokefan58Length = 10;
const int pokefan910Length = 10;
const int youngster04Length = 8;
const int youngster58Length = 8;
const int youngster910Length = 8;
const int fisherman04Length = 10;
const int fisherman58Length = 10;
const int fisherman910Length = 10;
const int triathlete04Length = 10;
const int triathlete58Length = 10;
const int triathlete910Length = 10;
const int dragon_tamer04Length = 13;
const int dragon_tamer58Length = 15;
const int dragon_tamer910Length = 15;
const int ninja_boy04Length = 11;
const int ninja_boy58Length = 11;
const int ninja_boy910Length = 11;
const int battle_girl04Length = 5;
const int battle_girl58Length = 9;
const int battle_girl910Length = 9;
const int parasol_lady04Length = 7;
const int parasol_lady58Length = 10;
const int parasol_lady910Length = 10;
const int twins04Length = 10;
const int twins58Length = 10;
const int twins910Length = 10;
const int sailor04Length = 10;
const int sailor58Length = 10;
const int sailor910Length = 10;
const int bug_catcher04Length = 9;
const int bug_catcher58Length = 11;
const int bug_catcher910Length = 11;
const int pkmn_ranger04Length = 10;
const int pkmn_ranger58Length = 10;
const int pkmn_ranger910Length = 10;
const int lass04Length = 7;
const int lass58Length = 7;
const int lass910Length = 7;
const int young_couple04Length = 10;
const int young_couple58Length = 10;
const int young_couple910Length = 10;
const int sis_and_bro04Length = 9;
const int sis_and_bro58Length = 9;
const int sis_and_bro910Length = 9;
const int aether04Length = 1;
const int aether58Length = 1;
const int aether910Length = 1;

//route
const int fallarbor_rustboro04Length = 10;
const int fallarbor_rustboro58Length = 10;
const int fallarbor_rustboro910Length = 10;
const int fallarbor_lavaridge04Length = 10;
const int fallarbor_lavaridge58Length = 10;
const int fallarbor_lavaridge910Length = 10;
const int rustboro_mauville04Length = 10;
const int rustboro_mauville58Length = 10;
const int rustboro_mauville910Length = 10;
const int lavaridge_mauville04Length = 10;
const int lavaridge_mauville58Length = 10;
const int lavaridge_mauville910Length = 10;
const int rustboro_petalburg04Length = 1;
const int rustboro_petalburg58Length = 1;
const int rustboro_petalburg910Length = 1;
const int petalburg_dewford04Length = 10;
const int petalburg_dewford58Length = 10;
const int petalburg_dewford910Length = 10;
const int dewford_slateport04Length = 10;
const int dewford_slateport58Length = 10;
const int dewford_slateport910Length = 10;
const int petalburg_slateport04Length = 1;
const int petalburg_slateport58Length = 1;
const int petalburg_slateport910Length = 1;
const int slateport_mauville04Length = 1;
const int slateport_mauville58Length = 1;
const int slateport_mauville910Length = 1;
const int lavaridge_fortree04Length = 1;
const int lavaridge_fortree58Length = 1;
const int lavaridge_fortree910Length = 1;
const int mauville_mtpyre04Length = 1;
const int mauville_mtpyre58Length = 1;
const int mauville_mtpyre910Length = 1;
const int fortree_mtpyre04Length = 1;
const int fortree_mtpyre58Length = 1;
const int fortree_mtpyre910Length = 1;
const int mtpyre_lilycove04Length = 1;
const int mtpyre_lilycove58Length = 1;
const int mtpyre_lilycove910Length = 1;
const int lilycove_mossdeep04Length = 1;
const int lilycove_mossdeep58Length = 1;
const int lilycove_mossdeep910Length = 1;
const int slateport_mossdeep04Length = 1;
const int slateport_mossdeep58Length = 1;
const int slateport_mossdeep910Length = 1;
const int fallarbor04Length = 1;
const int fallarbor58Length = 1;
const int fallarbor910Length = 1;
const int rustboro04Length = 1;
const int rustboro58Length = 1;
const int rustboro910Length = 1;
const int petalburg04Length = 1;
const int petalburg58Length = 1;
const int petalburg910Length = 1;
const int dewford04Length = 1;
const int dewford58Length = 1;
const int dewford910Length = 1;
const int slateport04Length = 8;
const int slateport58Length = 8;
const int slateport910Length = 8;
const int mauville04Length = 1;
const int mauville58Length = 1;
const int mauville910Length = 1;
const int lavaridge04Length = 1;
const int lavaridge58Length = 1;
const int lavaridge910Length = 1;
const int fortree04Length = 1;
const int fortree58Length = 1;
const int fortree910Length = 1;
const int mtpyre04Length = 1;
const int mtpyre58Length = 1;
const int mtpyre910Length = 1;
const int lilycove04Length = 1;
const int lilycove58Length = 1;
const int lilycove910Length = 1;
const int mossdeep04Length = 1;
const int mossdeep58Length = 1;
const int mossdeep910Length = 1;
const int sootopolis04Length = 1;
const int sootopolis58Length = 1;
const int sootopolis910Length = 1;

//initialize pools
//class
const struct TrainerMon ClassParty_Hiker04[11] =
{
    #include "data/classparties/hikergroup/hiker04.h"
};
const struct TrainerMon ClassParty_Hiker58[11] =
{
    #include "data/classparties/hikergroup/hiker58.h"
};
const struct TrainerMon ClassParty_Hiker910[11] =
{
    #include "data/classparties/hikergroup/hiker910.h"
};

const struct TrainerMon ClassParty_Team_Aqua04[10] =
{
    #include "data/classparties/team_aquagroup/team_aqua04.h"
};
const struct TrainerMon ClassParty_Team_Aqua58[10] =
{
    #include "data/classparties/team_aquagroup/team_aqua58.h"
};
const struct TrainerMon ClassParty_Team_Aqua910[10] =
{
    #include "data/classparties/team_aquagroup/team_aqua910.h"
};

const struct TrainerMon ClassParty_Pkmn_Breeder04[10] =
{
    #include "data/classparties/pkmn_breedergroup/pkmn_breeder04.h"
};
const struct TrainerMon ClassParty_Pkmn_Breeder58[10] =
{
    #include "data/classparties/pkmn_breedergroup/pkmn_breeder58.h"
};
const struct TrainerMon ClassParty_Pkmn_Breeder910[10] =
{
    #include "data/classparties/pkmn_breedergroup/pkmn_breeder910.h"
};

const struct TrainerMon ClassParty_Cooltrainer04[10] =
{
    #include "data/classparties/cooltrainergroup/cooltrainer04.h"
};
const struct TrainerMon ClassParty_Cooltrainer58[10] =
{
    #include "data/classparties/cooltrainergroup/cooltrainer58.h"
};
const struct TrainerMon ClassParty_Cooltrainer910[10] =
{
    #include "data/classparties/cooltrainergroup/cooltrainer910.h"
};

const struct TrainerMon ClassParty_Bird_Keeper04[10] =
{
    #include "data/classparties/bird_keepergroup/bird_keeper04.h"
};
const struct TrainerMon ClassParty_Bird_Keeper58[10] =
{
    #include "data/classparties/bird_keepergroup/bird_keeper58.h"
};
const struct TrainerMon ClassParty_Bird_Keeper910[10] =
{
    #include "data/classparties/bird_keepergroup/bird_keeper910.h"
};

const struct TrainerMon ClassParty_Collector04[6] =
{
    #include "data/classparties/collectorgroup/collector04.h"
};
const struct TrainerMon ClassParty_Collector58[10] =
{
    #include "data/classparties/collectorgroup/collector58.h"
};
const struct TrainerMon ClassParty_Collector910[10] =
{
    #include "data/classparties/collectorgroup/collector910.h"
};

const struct TrainerMon ClassParty_Swimmer04[10] =
{
    #include "data/classparties/swimmergroup/swimmer04.h"
};
const struct TrainerMon ClassParty_Swimmer58[10] =
{
    #include "data/classparties/swimmergroup/swimmer58.h"
};
const struct TrainerMon ClassParty_Swimmer910[10] =
{
    #include "data/classparties/swimmergroup/swimmer910.h"
};

const struct TrainerMon ClassParty_Team_Magma04[10] =
{
    #include "data/classparties/team_magmagroup/team_magma04.h"
};
const struct TrainerMon ClassParty_Team_Magma58[10] =
{
    #include "data/classparties/team_magmagroup/team_magma58.h"
};
const struct TrainerMon ClassParty_Team_Magma910[10] =
{
    #include "data/classparties/team_magmagroup/team_magma910.h"
};

const struct TrainerMon ClassParty_Expert04[10] =
{
    #include "data/classparties/expertgroup/expert04.h"
};
const struct TrainerMon ClassParty_Expert58[14] =
{
    #include "data/classparties/expertgroup/expert58.h"
};
const struct TrainerMon ClassParty_Expert910[14] =
{
    #include "data/classparties/expertgroup/expert910.h"
};

const struct TrainerMon ClassParty_Black_Belt04[5] =
{
    #include "data/classparties/black_beltgroup/black_belt04.h"
};
const struct TrainerMon ClassParty_Black_Belt58[9] =
{
    #include "data/classparties/black_beltgroup/black_belt58.h"
};
const struct TrainerMon ClassParty_Black_Belt910[9] =
{
    #include "data/classparties/black_beltgroup/black_belt910.h"
};

const struct TrainerMon ClassParty_Hex_Maniac04[8] =
{
    #include "data/classparties/hex_maniacgroup/hex_maniac04.h"
};
const struct TrainerMon ClassParty_Hex_Maniac58[8] =
{
    #include "data/classparties/hex_maniacgroup/hex_maniac58.h"
};
const struct TrainerMon ClassParty_Hex_Maniac910[8] =
{
    #include "data/classparties/hex_maniacgroup/hex_maniac910.h"
};

const struct TrainerMon ClassParty_Aroma_Lady04[6] =
{
    #include "data/classparties/aroma_ladygroup/aroma_lady04.h"
};
const struct TrainerMon ClassParty_Aroma_Lady58[13] =
{
    #include "data/classparties/aroma_ladygroup/aroma_lady58.h"
};
const struct TrainerMon ClassParty_Aroma_Lady910[13] =
{
    #include "data/classparties/aroma_ladygroup/aroma_lady910.h"
};

const struct TrainerMon ClassParty_Ruin_Maniac04[8] =
{
    #include "data/classparties/ruin_maniacgroup/ruin_maniac04.h"
};
const struct TrainerMon ClassParty_Ruin_Maniac58[8] =
{
    #include "data/classparties/ruin_maniacgroup/ruin_maniac58.h"
};
const struct TrainerMon ClassParty_Ruin_Maniac910[8] =
{
    #include "data/classparties/ruin_maniacgroup/ruin_maniac910.h"
};

const struct TrainerMon ClassParty_Tuber04[10] =
{
    #include "data/classparties/tubergroup/tuber04.h"
};
const struct TrainerMon ClassParty_Tuber58[10] =
{
    #include "data/classparties/tubergroup/tuber58.h"
};
const struct TrainerMon ClassParty_Tuber910[10] =
{
    #include "data/classparties/tubergroup/tuber910.h"
};

const struct TrainerMon ClassParty_Lady04[7] =
{
    #include "data/classparties/ladygroup/lady04.h"
};
const struct TrainerMon ClassParty_Lady58[10] =
{
    #include "data/classparties/ladygroup/lady58.h"
};
const struct TrainerMon ClassParty_Lady910[10] =
{
    #include "data/classparties/ladygroup/lady910.h"
};

const struct TrainerMon ClassParty_Beauty04[7] =
{
    #include "data/classparties/beautygroup/beauty04.h"
};
const struct TrainerMon ClassParty_Beauty58[10] =
{
    #include "data/classparties/beautygroup/beauty58.h"
};
const struct TrainerMon ClassParty_Beauty910[10] =
{
    #include "data/classparties/beautygroup/beauty910.h"
};

const struct TrainerMon ClassParty_Rich_Boy04[8] =
{
    #include "data/classparties/rich_boygroup/rich_boy04.h"
};
const struct TrainerMon ClassParty_Rich_Boy58[8] =
{
    #include "data/classparties/rich_boygroup/rich_boy58.h"
};
const struct TrainerMon ClassParty_Rich_Boy910[8] =
{
    #include "data/classparties/rich_boygroup/rich_boy910.h"
};

const struct TrainerMon ClassParty_Pokemaniac04[10] =
{
    #include "data/classparties/pokemaniacgroup/pokemaniac04.h"
};
const struct TrainerMon ClassParty_Pokemaniac58[10] =
{
    #include "data/classparties/pokemaniacgroup/pokemaniac58.h"
};
const struct TrainerMon ClassParty_Pokemaniac910[10] =
{
    #include "data/classparties/pokemaniacgroup/pokemaniac910.h"
};

const struct TrainerMon ClassParty_Guitarist04[8] =
{
    #include "data/classparties/guitaristgroup/guitarist04.h"
};
const struct TrainerMon ClassParty_Guitarist58[8] =
{
    #include "data/classparties/guitaristgroup/guitarist58.h"
};
const struct TrainerMon ClassParty_Guitarist910[8] =
{
    #include "data/classparties/guitaristgroup/guitarist910.h"
};

const struct TrainerMon ClassParty_Kindler04[11] =
{
    #include "data/classparties/kindlergroup/kindler04.h"
};
const struct TrainerMon ClassParty_Kindler58[11] =
{
    #include "data/classparties/kindlergroup/kindler58.h"
};
const struct TrainerMon ClassParty_Kindler910[11] =
{
    #include "data/classparties/kindlergroup/kindler910.h"
};

const struct TrainerMon ClassParty_Camper04[10] =
{
    #include "data/classparties/campergroup/camper04.h"
};
const struct TrainerMon ClassParty_Camper58[10] =
{
    #include "data/classparties/campergroup/camper58.h"
};
const struct TrainerMon ClassParty_Camper910[10] =
{
    #include "data/classparties/campergroup/camper910.h"
};

const struct TrainerMon ClassParty_Picnicker04[10] =
{
    #include "data/classparties/picnickergroup/picnicker04.h"
};
const struct TrainerMon ClassParty_Picnicker58[10] =
{
    #include "data/classparties/picnickergroup/picnicker58.h"
};
const struct TrainerMon ClassParty_Picnicker910[10] =
{
    #include "data/classparties/picnickergroup/picnicker910.h"
};

const struct TrainerMon ClassParty_Bug_Maniac04[9] =
{
    #include "data/classparties/bug_maniacgroup/bug_maniac04.h"
};
const struct TrainerMon ClassParty_Bug_Maniac58[11] =
{
    #include "data/classparties/bug_maniacgroup/bug_maniac58.h"
};
const struct TrainerMon ClassParty_Bug_Maniac910[11] =
{
    #include "data/classparties/bug_maniacgroup/bug_maniac910.h"
};

const struct TrainerMon ClassParty_Psychic04[8] =
{
    #include "data/classparties/psychicgroup/psychic04.h"
};
const struct TrainerMon ClassParty_Psychic58[8] =
{
    #include "data/classparties/psychicgroup/psychic58.h"
};
const struct TrainerMon ClassParty_Psychic910[8] =
{
    #include "data/classparties/psychicgroup/psychic910.h"
};

const struct TrainerMon ClassParty_Gentleman04[8] =
{
    #include "data/classparties/gentlemangroup/gentleman04.h"
};
const struct TrainerMon ClassParty_Gentleman58[8] =
{
    #include "data/classparties/gentlemangroup/gentleman58.h"
};
const struct TrainerMon ClassParty_Gentleman910[8] =
{
    #include "data/classparties/gentlemangroup/gentleman910.h"
};

const struct TrainerMon ClassParty_School_Kid04[8] =
{
    #include "data/classparties/school_kidgroup/school_kid04.h"
};
const struct TrainerMon ClassParty_School_Kid58[8] =
{
    #include "data/classparties/school_kidgroup/school_kid58.h"
};
const struct TrainerMon ClassParty_School_Kid910[8] =
{
    #include "data/classparties/school_kidgroup/school_kid910.h"
};

const struct TrainerMon ClassParty_Sr_And_Jr04[9] =
{
    #include "data/classparties/sr_and_jrgroup/sr_and_jr04.h"
};
const struct TrainerMon ClassParty_Sr_And_Jr58[9] =
{
    #include "data/classparties/sr_and_jrgroup/sr_and_jr58.h"
};
const struct TrainerMon ClassParty_Sr_And_Jr910[9] =
{
    #include "data/classparties/sr_and_jrgroup/sr_and_jr910.h"
};

const struct TrainerMon ClassParty_Pokefan04[10] =
{
    #include "data/classparties/pokefangroup/pokefan04.h"
};
const struct TrainerMon ClassParty_Pokefan58[10] =
{
    #include "data/classparties/pokefangroup/pokefan58.h"
};
const struct TrainerMon ClassParty_Pokefan910[10] =
{
    #include "data/classparties/pokefangroup/pokefan910.h"
};

const struct TrainerMon ClassParty_Youngster04[8] =
{
    #include "data/classparties/youngstergroup/youngster04.h"
};
const struct TrainerMon ClassParty_Youngster58[8] =
{
    #include "data/classparties/youngstergroup/youngster58.h"
};
const struct TrainerMon ClassParty_Youngster910[8] =
{
    #include "data/classparties/youngstergroup/youngster910.h"
};

const struct TrainerMon ClassParty_Fisherman04[10] =
{
    #include "data/classparties/fishermangroup/fisherman04.h"
};
const struct TrainerMon ClassParty_Fisherman58[10] =
{
    #include "data/classparties/fishermangroup/fisherman58.h"
};
const struct TrainerMon ClassParty_Fisherman910[10] =
{
    #include "data/classparties/fishermangroup/fisherman910.h"
};

const struct TrainerMon ClassParty_Triathlete04[10] =
{
    #include "data/classparties/triathletegroup/triathlete04.h"
};
const struct TrainerMon ClassParty_Triathlete58[10] =
{
    #include "data/classparties/triathletegroup/triathlete58.h"
};
const struct TrainerMon ClassParty_Triathlete910[10] =
{
    #include "data/classparties/triathletegroup/triathlete910.h"
};

const struct TrainerMon ClassParty_Dragon_Tamer04[13] =
{
    #include "data/classparties/dragon_tamergroup/dragon_tamer04.h"
};
const struct TrainerMon ClassParty_Dragon_Tamer58[15] =
{
    #include "data/classparties/dragon_tamergroup/dragon_timer58.h"
};
const struct TrainerMon ClassParty_Dragon_Tamer910[15] =
{
    #include "data/classparties/dragon_tamergroup/dragon_timer910.h"
};

const struct TrainerMon ClassParty_Ninja_Boy04[11] =
{
    #include "data/classparties/ninja_boygroup/ninja_boy04.h"
};
const struct TrainerMon ClassParty_Ninja_Boy58[11] =
{
    #include "data/classparties/ninja_boygroup/ninja_boy58.h"
};
const struct TrainerMon ClassParty_Ninja_Boy910[11] =
{
    #include "data/classparties/ninja_boygroup/ninja_boy910.h"
};

const struct TrainerMon ClassParty_Battle_Girl04[5] =
{
    #include "data/classparties/battle_girlgroup/battle_girl04.h"
};
const struct TrainerMon ClassParty_Battle_Girl58[9] =
{
    #include "data/classparties/battle_girlgroup/battle_girl58.h"
};
const struct TrainerMon ClassParty_Battle_Girl910[9] =
{
    #include "data/classparties/battle_girlgroup/battle_girl910.h"
};

const struct TrainerMon ClassParty_Parasol_Lady04[7] =
{
    #include "data/classparties/parasol_ladygroup/parasol_lady04.h"
};
const struct TrainerMon ClassParty_Parasol_Lady58[10] =
{
    #include "data/classparties/parasol_ladygroup/parasol_lady58.h"
};
const struct TrainerMon ClassParty_Parasol_Lady910[10] =
{
    #include "data/classparties/parasol_ladygroup/parasol_lady910.h"
};

const struct TrainerMon ClassParty_Twins04[10] =
{
    #include "data/classparties/twinsgroup/twins04.h"
};
const struct TrainerMon ClassParty_Twins58[10] =
{
    #include "data/classparties/twinsgroup/twins58.h"
};
const struct TrainerMon ClassParty_Twins910[10] =
{
    #include "data/classparties/twinsgroup/twins910.h"
};

const struct TrainerMon ClassParty_Sailor04[10] =
{
    #include "data/classparties/sailorgroup/sailor04.h"
};
const struct TrainerMon ClassParty_Sailor58[10] =
{
    #include "data/classparties/sailorgroup/sailor58.h"
};
const struct TrainerMon ClassParty_Sailor910[10] =
{
    #include "data/classparties/sailorgroup/sailor910.h"
};

const struct TrainerMon ClassParty_Bug_Catcher04[9] =
{
    #include "data/classparties/bug_catchergroup/bug_catcher04.h"
};
const struct TrainerMon ClassParty_Bug_Catcher58[11] =
{
    #include "data/classparties/bug_catchergroup/bug_catcher58.h"
};
const struct TrainerMon ClassParty_Bug_Catcher910[11] =
{
    #include "data/classparties/bug_catchergroup/bug_catcher910.h"
};

const struct TrainerMon ClassParty_Pkmn_Ranger04[10] =
{
    #include "data/classparties/pkmn_rangergroup/pkmn_ranger04.h"
};
const struct TrainerMon ClassParty_Pkmn_Ranger58[10] =
{
    #include "data/classparties/pkmn_rangergroup/pkmn_ranger58.h"
};
const struct TrainerMon ClassParty_Pkmn_Ranger910[10] =
{
    #include "data/classparties/pkmn_rangergroup/pkmn_ranger910.h"
};

const struct TrainerMon ClassParty_Lass04[7] =
{
    #include "data/classparties/lassgroup/lass04.h"
};
const struct TrainerMon ClassParty_Lass58[7] =
{
    #include "data/classparties/lassgroup/lass58.h"
};
const struct TrainerMon ClassParty_Lass910[7] =
{
    #include "data/classparties/lassgroup/lass910.h"
};

const struct TrainerMon ClassParty_Young_Couple04[10] =
{
    #include "data/classparties/young_couplegroup/young_couple04.h"
};
const struct TrainerMon ClassParty_Young_Couple58[10] =
{
    #include "data/classparties/young_couplegroup/young_couple58.h"
};
const struct TrainerMon ClassParty_Young_Couple910[10] =
{
    #include "data/classparties/young_couplegroup/young_couple910.h"
};

const struct TrainerMon ClassParty_Sis_And_Bro04[9] =
{
    #include "data/classparties/sis_and_brogroup/sis_and_bro04.h"
};
const struct TrainerMon ClassParty_Sis_And_Bro58[9] =
{
    #include "data/classparties/sis_and_brogroup/sis_and_bro58.h"
};
const struct TrainerMon ClassParty_Sis_And_Bro910[9] =
{
    #include "data/classparties/sis_and_brogroup/sis_and_bro910.h"
};

const struct TrainerMon ClassParty_Aether04[1] =
{
    #include "data/classparties/aethergroup/aether04.h"
};
const struct TrainerMon ClassParty_Aether58[1] =
{
    #include "data/classparties/aethergroup/aether58.h"
};
const struct TrainerMon ClassParty_Aether910[1] =
{
    #include "data/classparties/aethergroup/aether910.h"
};

//routes
const struct TrainerMon RouteParty_Fallarbor_Rustboro04[10] =
{
    #include "data/routeparties/fallarbor_rustborogroup/fallarbor_rustboro04.h"
};
const struct TrainerMon RouteParty_Fallarbor_Rustboro58[10] =
{
    #include "data/routeparties/fallarbor_rustborogroup/fallarbor_rustboro58.h"
};
const struct TrainerMon RouteParty_Fallarbor_Rustboro910[10] =
{
    #include "data/routeparties/fallarbor_rustborogroup/fallarbor_rustboro910.h"
};

const struct TrainerMon RouteParty_Fallarbor_Lavaridge04[10] =
{
    #include "data/routeparties/fallarbor_lavaridgegroup/fallarbor_lavaridge04.h"
};
const struct TrainerMon RouteParty_Fallarbor_Lavaridge58[10] =
{
    #include "data/routeparties/fallarbor_lavaridgegroup/fallarbor_lavardige58.h"
};
const struct TrainerMon RouteParty_Fallarbor_Lavaridge910[10] =
{
    #include "data/routeparties/fallarbor_lavaridgegroup/fallarbor_lavaridge910.h"
};

const struct TrainerMon RouteParty_Rustboro_Mauville04[10] =
{
    #include "data/routeparties/rustboro_mauvillegroup/rustboro_mauville04.h"
};
const struct TrainerMon RouteParty_Rustboro_Mauville58[10] =
{
    #include "data/routeparties/rustboro_mauvillegroup/rustboro_mauville58.h"
};
const struct TrainerMon RouteParty_Rustboro_Mauville910[10] =
{
    #include "data/routeparties/rustboro_mauvillegroup/rustboro_mauville910.h"
};

const struct TrainerMon RouteParty_Lavaridge_Mauville04[10] =
{
    #include "data/routeparties/lavaridge_mauvillegroup/lavaridge_mauville04.h"
};
const struct TrainerMon RouteParty_Lavaridge_Mauville58[10] =
{
    #include "data/routeparties/lavaridge_mauvillegroup/lavaridge_mauville58.h"
};
const struct TrainerMon RouteParty_Lavaridge_Mauville910[10] =
{
    #include "data/routeparties/lavaridge_mauvillegroup/lavaridge_mauville910.h"
};

const struct TrainerMon RouteParty_Rustboro_Petalburg04[1] =
{
    #include "data/routeparties/rustboro_petalburggroup/rustboro_petalburg04.h"
};
const struct TrainerMon RouteParty_Rustboro_Petalburg58[1] =
{
    #include "data/routeparties/rustboro_petalburggroup/rustboro_petalburg58.h"
};
const struct TrainerMon RouteParty_Rustboro_Petalburg910[1] =
{
    #include "data/routeparties/rustboro_petalburggroup/rustboro_petalburg910.h"
};

const struct TrainerMon RouteParty_Petalburg_Dewford04[10] =
{
    #include "data/routeparties/petalburg_dewfordgroup/petalburg_dewford04.h"
};
const struct TrainerMon RouteParty_Petalburg_Dewford58[10] =
{
    #include "data/routeparties/petalburg_dewfordgroup/petalburg_dewford58.h"
};
const struct TrainerMon RouteParty_Petalburg_Dewford910[10] =
{
    #include "data/routeparties/petalburg_dewfordgroup/petalburg_dewford910.h"
};

const struct TrainerMon RouteParty_Dewford_Slateport04[10] =
{
    #include "data/routeparties/dewford_slateportgroup/dewford_slateport04.h"
};
const struct TrainerMon RouteParty_Dewford_Slateport58[10] =
{
    #include "data/routeparties/dewford_slateportgroup/dewford_slateport58.h"
};
const struct TrainerMon RouteParty_Dewford_Slateport910[10] =
{
    #include "data/routeparties/dewford_slateportgroup/dewford_slateport910.h"
};

const struct TrainerMon RouteParty_Petalburg_Slateport04[1] =
{
    #include "data/routeparties/petalburg_slateportgroup/petalburg_slateport04.h"
};
const struct TrainerMon RouteParty_Petalburg_Slateport58[1] =
{
    #include "data/routeparties/petalburg_slateportgroup/petalburg_slateport58.h"
};
const struct TrainerMon RouteParty_Petalburg_Slateport910[1] =
{
    #include "data/routeparties/petalburg_slateportgroup/petalburg_slateport910.h"
};

const struct TrainerMon RouteParty_Slateport_Mauville04[1] =
{
    #include "data/routeparties/slateport_mauvillegroup/slateport_mauville04.h"
};
const struct TrainerMon RouteParty_Slateport_Mauville58[1] =
{
    #include "data/routeparties/slateport_mauvillegroup/slateport_mauville58.h"
};
const struct TrainerMon RouteParty_Slateport_Mauville910[1] =
{
    #include "data/routeparties/slateport_mauvillegroup/slateport_mauville910.h"
};

const struct TrainerMon RouteParty_Lavaridge_Fortree04[1] =
{
    #include "data/routeparties/lavaridge_fortreegroup/lavaridge_fortree04.h"
};
const struct TrainerMon RouteParty_Lavaridge_Fortree58[1] =
{
    #include "data/routeparties/lavaridge_fortreegroup/lavaridge_fortree58.h"
};
const struct TrainerMon RouteParty_Lavaridge_Fortree910[1] =
{
    #include "data/routeparties/lavaridge_fortreegroup/lavaridge_fortree910.h"
};

const struct TrainerMon RouteParty_Mauville_Mtpyre04[1] =
{
    #include "data/routeparties/mauville_mtpyregroup/mauville_mtpyre04.h"
};
const struct TrainerMon RouteParty_Mauville_Mtpyre58[1] =
{
    #include "data/routeparties/mauville_mtpyregroup/mauville_mtpyre58.h"
};
const struct TrainerMon RouteParty_Mauville_Mtpyre910[1] =
{
    #include "data/routeparties/mauville_mtpyregroup/mauville_mtpyre910.h"
};

const struct TrainerMon RouteParty_Fortree_Mtpyre04[1] =
{
    #include "data/routeparties/fortree_mtpyregroup/fortree_mtpyre04.h"
};
const struct TrainerMon RouteParty_Fortree_Mtpyre58[1] =
{
    #include "data/routeparties/fortree_mtpyregroup/fortree_mtpyre58.h"
};
const struct TrainerMon RouteParty_Fortree_Mtpyre910[1] =
{
    #include "data/routeparties/fortree_mtpyregroup/fortree_mtpyre910.h"
};

const struct TrainerMon RouteParty_Mtpyre_Lilycove04[1] =
{
    #include "data/routeparties/mtpyre_lilycovegroup/mtpyre_lilycove04.h"
};
const struct TrainerMon RouteParty_Mtpyre_Lilycove58[1] =
{
    #include "data/routeparties/mtpyre_lilycovegroup/mtpyre_lilycove58.h"
};
const struct TrainerMon RouteParty_Mtpyre_Lilycove910[1] =
{
    #include "data/routeparties/mtpyre_lilycovegroup/mtpyre_lilycove910.h"
};

const struct TrainerMon RouteParty_Lilycove_Mossdeep04[1] =
{
    #include "data/routeparties/lilycove_mossdeepgroup/lilycove_mossdeep04.h"
};
const struct TrainerMon RouteParty_Lilycove_Mossdeep58[1] =
{
    #include "data/routeparties/lilycove_mossdeepgroup/lilycove_mossdeep58.h"
};
const struct TrainerMon RouteParty_Lilycove_Mossdeep910[1] =
{
    #include "data/routeparties/lilycove_mossdeepgroup/lilycove_mossdeep910.h"
};

const struct TrainerMon RouteParty_Slateport_Mossdeep04[1] =
{
    #include "data/routeparties/slateport_mossdeepgroup/slateport_mossdeep04.h"
};
const struct TrainerMon RouteParty_Slateport_Mossdeep58[1] =
{
    #include "data/routeparties/slateport_mossdeepgroup/slateport_mossdeep58.h"
};
const struct TrainerMon RouteParty_Slateport_Mossdeep910[1] =
{
    #include "data/routeparties/slateport_mossdeepgroup/slateport_mossdeep910.h"
};

const struct TrainerMon RouteParty_Fallarbor04[1] =
{
    #include "data/routeparties/fallarborgroup/fallarbor04.h"
};
const struct TrainerMon RouteParty_Fallarbor58[1] =
{
    #include "data/routeparties/fallarborgroup/fallarbor58.h"
};
const struct TrainerMon RouteParty_Fallarbor910[1] =
{
    #include "data/routeparties/fallarborgroup/fallarbor910.h"
};

const struct TrainerMon RouteParty_Rustboro04[1] =
{
    #include "data/routeparties/rustborogroup/rustboro04.h"
};
const struct TrainerMon RouteParty_Rustboro58[1] =
{
    #include "data/routeparties/rustborogroup/rustboro58.h"
};
const struct TrainerMon RouteParty_Rustboro910[1] =
{
    #include "data/routeparties/rustborogroup/rustboro910.h"
};

const struct TrainerMon RouteParty_Petalburg04[1] =
{
    #include "data/routeparties/petalburggroup/petalburg04.h"
};
const struct TrainerMon RouteParty_Petalburg58[1] =
{
    #include "data/routeparties/petalburggroup/petalburg58.h"
};
const struct TrainerMon RouteParty_Petalburg910[1] =
{
    #include "data/routeparties/petalburggroup/petalburg910.h"
};

const struct TrainerMon RouteParty_Dewford04[1] =
{
    #include "data/routeparties/dewfordgroup/dewford04.h"
};
const struct TrainerMon RouteParty_Dewford58[1] =
{
    #include "data/routeparties/dewfordgroup/dewford58.h"
};
const struct TrainerMon RouteParty_Dewford910[1] =
{
    #include "data/routeparties/dewfordgroup/dewford910.h"
};

const struct TrainerMon RouteParty_Slateport04[8] =
{
    #include "data/routeparties/slateportgroup/slateport04.h"
};
const struct TrainerMon RouteParty_Slateport58[8] =
{
    #include "data/routeparties/slateportgroup/slateport58.h"
};
const struct TrainerMon RouteParty_Slateport910[8] =
{
    #include "data/routeparties/slateportgroup/slateport910.h"
};

const struct TrainerMon RouteParty_Mauville04[1] =
{
    #include "data/routeparties/mauvillegroup/mauville04.h"
};
const struct TrainerMon RouteParty_Mauville58[1] =
{
    #include "data/routeparties/mauvillegroup/mauville58.h"
};
const struct TrainerMon RouteParty_Mauville910[1] =
{
    #include "data/routeparties/mauvillegroup/mauville910.h"
};

const struct TrainerMon RouteParty_Lavaridge04[1] =
{
    #include "data/routeparties/lavaridgegroup/lavaridge04.h"
};
const struct TrainerMon RouteParty_Lavaridge58[1] =
{
    #include "data/routeparties/lavaridgegroup/lavaridge58.h"
};
const struct TrainerMon RouteParty_Lavaridge910[1] =
{
    #include "data/routeparties/lavaridgegroup/lavaridge910.h"
};

const struct TrainerMon RouteParty_Fortree04[1] =
{
    #include "data/routeparties/fortreegroup/fortree04.h"
};
const struct TrainerMon RouteParty_Fortree58[1] =
{
    #include "data/routeparties/fortreegroup/fortree58.h"
};
const struct TrainerMon RouteParty_Fortree910[1] =
{
    #include "data/routeparties/fortreegroup/fortree910.h"
};

const struct TrainerMon RouteParty_Mtpyre04[1] =
{
    #include "data/routeparties/mtpyregroup/mtpyre04.h"
};
const struct TrainerMon RouteParty_Mtpyre58[1] =
{
    #include "data/routeparties/mtpyregroup/mtpyre58.h"
};
const struct TrainerMon RouteParty_Mtpyre910[1] =
{
    #include "data/routeparties/mtpyregroup/mtpyre910.h"
};

const struct TrainerMon RouteParty_Lilycove04[1] =
{
    #include "data/routeparties/lilycovegroup/lilycove04.h"
};
const struct TrainerMon RouteParty_Lilycove58[1] =
{
    #include "data/routeparties/lilycovegroup/lilycove58.h"
};
const struct TrainerMon RouteParty_Lilycove910[1] =
{
    #include "data/routeparties/lilycovegroup/lilycove910.h"
};

const struct TrainerMon RouteParty_Mossdeep04[1] =
{
    #include "data/routeparties/mossdeepgroup/mossdeep04.h"
};
const struct TrainerMon RouteParty_Mossdeep58[1] =
{
    #include "data/routeparties/mossdeepgroup/mossdeep58.h"
};
const struct TrainerMon RouteParty_Mossdeep910[1] =
{
    #include "data/routeparties/mossdeepgroup/mossdeep910.h"
};

const struct TrainerMon RouteParty_Sootopolis[1] =
{
    #include "data/routeparties/sootopolis.h"
};


//functions
int GetClassPoolSize(const enum TrainerClassID trainerClass)
{
    switch(trainerClass)
    {
        case 0: //hiker
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return hiker04Length;
                case 5:
                case 6:
                case 7:
                case 8: return hiker58Length;
                case 9:
                case 10: return hiker910Length;
                default: return hiker910Length;
            }
        case 1: //team aqua (grunt)
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return team_aqua04Length;
                case 5:
                case 6:
                case 7:
                case 8: return team_aqua58Length;
                case 9:
                case 10: return team_aqua910Length;
                default: return team_aqua910Length;
            }
        case 2: //pkmn breeder
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return pkmn_breeder04Length;
                case 5:
                case 6:
                case 7:
                case 8: return pkmn_breeder58Length;
                case 9:
                case 10: return pkmn_breeder910Length;
                default: return pkmn_breeder910Length;
            }
        case 3: //cool trainer
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return cooltrainer04Length;
                case 5:
                case 6:
                case 7:
                case 8: return cooltrainer58Length;
                case 9:
                case 10: return cooltrainer910Length;
                default: return cooltrainer910Length;
            }
        case 4: //bird keeper
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return bird_keeper04Length;
                case 5:
                case 6:
                case 7:
                case 8: return bird_keeper58Length;
                case 9:
                case 10: return bird_keeper910Length;
                default: return bird_keeper910Length;
            }
        case 5: //collector
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return collector04Length;
                case 5:
                case 6:
                case 7:
                case 8: return collector58Length;
                case 9:
                case 10: return collector910Length;
                default: return collector910Length;
            }
        case 6: //swimmer
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return swimmer04Length;
                case 5: 
                case 6:
                case 7:
                case 8: return swimmer58Length;
                case 9:
                case 10: return swimmer910Length;
                default: return swimmer910Length;
            }
        case 7: //team magma (grunt)
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return team_magma04Length;
                case 5:
                case 6:
                case 7:
                case 8: return team_magma58Length;
                case 9:
                case 10: return team_magma910Length;
                default: return team_magma910Length;
            }
        case 8: //expert
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return expert04Length;
                case 5:
                case 6:
                case 7:
                case 8: return expert58Length;
                case 9:
                case 10: return expert910Length;
                default: return expert910Length;
            }
        case 9: //black belt
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return black_belt04Length;
                case 5:
                case 6:
                case 7:
                case 8: return black_belt58Length;
                case 9:
                case 10: return black_belt910Length;
                default: return black_belt910Length;
            }
        case 10: //hex maniac
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return hex_maniac04Length;
                case 5:
                case 6:
                case 7:
                case 8: return hex_maniac58Length;
                case 9:
                case 10: return hex_maniac910Length;
                default: return hex_maniac910Length;
            }
        case 11: //aroma lady
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return aroma_lady04Length;
                case 5:
                case 6:
                case 7:
                case 8: return aroma_lady58Length;
                case 9:
                case 10: return aroma_lady910Length;
                default: return aroma_lady910Length;
            }
        case 12: //ruin maniac
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return ruin_maniac04Length;
                case 5:
                case 6:
                case 7:
                case 8: return ruin_maniac58Length;
                case 9:
                case 10: return ruin_maniac910Length;
                default: return ruin_maniac910Length;
            }
        case 13: //tuber 
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return tuber04Length;
                case 5:
                case 6:
                case 7:
                case 8: return tuber58Length;
                case 9:
                case 10: return tuber910Length;
                default: return tuber910Length;
            }
        case 14: //lady
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return lady04Length;
                case 5:
                case 6:
                case 7:
                case 8: return lady58Length;
                case 9:
                case 10: return lady910Length;
                default: return lady910Length;
            }
        case 15: //beauty
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return beauty04Length;
                case 5:
                case 6:
                case 7:
                case 8: return beauty58Length;
                case 9:
                case 10: return beauty910Length;
                default: return beauty910Length;
            }
        case 16: //rich_boy
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return rich_boy04Length;
                case 5: 
                case 6:
                case 7:
                case 8: return rich_boy58Length;
                case 9: 
                case 10: return rich_boy910Length;
                default: return rich_boy910Length;
            }
        case 17: //pokemaniac
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return pokemaniac04Length;
                case 5:
                case 6:
                case 7:
                case 8: return pokemaniac58Length;
                case 9:
                case 10: return pokemaniac910Length;
                default: return pokemaniac910Length;
            }
        case 18: //guitarist
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return guitarist04Length;
                case 5:
                case 6:
                case 7: 
                case 8: return guitarist58Length;
                case 9:
                case 10: return guitarist910Length;
                default: return guitarist910Length;
            }
        case 19: //kindler
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return kindler04Length;
                case 5: 
                case 6:
                case 7:
                case 8: return kindler58Length;
                case 9:
                case 10: return kindler910Length;
                default: return kindler910Length;
            }
        case 20: //camper
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return camper04Length;
                case 5:
                case 6:
                case 7:
                case 8: return camper58Length;
                case 9:
                case 10: return camper910Length;
                default: return camper910Length;
            }
        case 21: //picnicker
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return picnicker04Length;
                case 5:
                case 6:
                case 7:
                case 8: return picnicker58Length;
                case 9: 
                case 10: return picnicker910Length;
                default: return picnicker910Length;
            }
        case 22: //bug maniac
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return bug_maniac04Length;
                case 5:
                case 6:
                case 7:
                case 8: return bug_maniac58Length;
                case 9:
                case 10: return bug_maniac910Length;
                default: return bug_maniac910Length;
            }
        case 23: //psychic
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return psychic04Length;
                case 5: 
                case 6:
                case 7:
                case 8: return psychic58Length;
                case 9:
                case 10: return psychic910Length;
                default: return psychic910Length;
            }
        case 24: //gentleman
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return gentleman04Length;
                case 5:
                case 6:
                case 7:
                case 8: return gentleman58Length;
                case 9:
                case 10: return gentleman910Length;
                default: return gentleman910Length;
            }
        case 25: //school kid
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return school_kid04Length;
                case 5:
                case 6:
                case 7:
                case 8: return school_kid58Length;
                case 9:
                case 10: return school_kid910Length;
                default: return school_kid910Length;
            }
        case 26: // sr and jr
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return sr_and_jr04Length;
                case 5:
                case 6:
                case 7:
                case 8: return sr_and_jr58Length;
                case 9:
                case 10: return sr_and_jr910Length;
                default: return sr_and_jr910Length;
            }
        case 27: //pokefan
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return pokefan04Length;
                case 5:
                case 6:
                case 7:
                case 8: return pokefan58Length;
                case 9:
                case 10: return pokefan910Length;
                default: return pokefan910Length;
            }
        case 28: //youngster
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return youngster04Length;
                case 5:
                case 6:
                case 7:
                case 8: return youngster58Length;
                case 9:
                case 10: return youngster910Length;
                default: return youngster910Length;
            }
        case 29: //fisherman
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return fisherman04Length;
                case 5:
                case 6:
                case 7:
                case 8: return fisherman58Length;
                case 9:
                case 10: return fisherman910Length;
                default: return fisherman910Length;
            }
        case 30: //triathlete
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return triathlete04Length;
                case 5:
                case 6:
                case 7:
                case 8: return triathlete58Length;
                case 9:
                case 10: return triathlete910Length;
                default: return triathlete910Length;
            }
        case 31: //dragon tamer
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return dragon_tamer04Length;
                case 5:
                case 6:
                case 7:
                case 8: return dragon_tamer58Length;
                case 9:
                case 10: return dragon_tamer910Length;
                default: return dragon_tamer910Length;
            }
        case 32: //ninja boy
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return ninja_boy04Length;
                case 5:
                case 6:
                case 7:
                case 8: return ninja_boy58Length;
                case 9:
                case 10: return ninja_boy910Length;
                default: return ninja_boy910Length;
            }
        case 33: //battle girl
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return battle_girl04Length;
                case 5:
                case 6:
                case 7:
                case 8: return battle_girl58Length;
                case 9:
                case 10: return battle_girl910Length;
                default: return battle_girl910Length;
            }
        case 34: //parasol lady
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return parasol_lady04Length;
                case 5: 
                case 6:
                case 7:
                case 8: return parasol_lady58Length;
                case 9: 
                case 10: return parasol_lady910Length;
                default: return parasol_lady910Length;
            }
        case 35: //twins
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return twins04Length;
                case 5:
                case 6:
                case 7:
                case 8: return twins58Length;
                case 9:
                case 10: return twins910Length;
                default: return twins910Length;
            }
        case 36: //sailor
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return sailor04Length;
                case 5:
                case 6:
                case 7:
                case 8: return sailor58Length;
                case 9:
                case 10: return sailor910Length;
                default: return sailor910Length;
            }
        case 37: //bug catcher
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return bug_catcher04Length;
                case 5:
                case 6:
                case 7:
                case 8: return bug_catcher58Length;
                case 9:
                case 10: return bug_catcher910Length;
                default: return bug_catcher910Length;
            }
            break;
        case 38: //pkmn ranger
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return pkmn_ranger04Length;
                case 5:
                case 6:
                case 7:
                case 8: return pkmn_ranger58Length;
                case 9: 
                case 10: return pkmn_ranger910Length;
                default: return pkmn_ranger910Length;
            }
        case 39: //lass
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return lass04Length;
                case 5:
                case 6:
                case 7:
                case 8: return lady58Length;
                case 9:
                case 10: return lady910Length;
                default: return lady910Length;
            }
        case 40: //young couple
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return young_couple04Length;
                case 5:
                case 6:
                case 7:
                case 8: return young_couple58Length;
                case 9:
                case 10: return young_couple910Length;
                default: return young_couple910Length;
            }
        case 41: //sis and bro
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return sis_and_bro04Length;
                case 5:
                case 6:
                case 7:
                case 8: return sis_and_bro58Length;
                case 9:
                case 10: return sis_and_bro910Length;
                default: return sis_and_bro910Length;
            }
        case 42: //aether (grunt)
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return aether04Length;
                case 5:
                case 6:
                case 7:
                case 8: return aether58Length;
                case 9:
                case 10: return aether910Length;
                default: return aether910Length;
            }
        default:
            switch (*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return lass04Length;
                case 5:
                case 6:
                case 7:
                case 8: return lady58Length;
                case 9:
                case 10: return lady910Length;
                default: return lady910Length;
            }
            break;
    };

    return 1;
};

int GetRoutePoolSize(const enum TrainerUnlockedAt unlockedAt) 
{
    switch (unlockedAt)
    {
        case 0: //fallarbor - rustboro
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return fallarbor_rustboro04Length;
                case 5:
                case 6:
                case 7:
                case 8: return fallarbor_rustboro58Length;
                case 9:
                case 10: return fallarbor_rustboro910Length;
                default: return fallarbor_rustboro910Length;
            }
        case 1: //fallarbor - lavaridge
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return fallarbor_lavaridge04Length;
                case 5:
                case 6:
                case 7:
                case 8: return fallarbor_lavaridge58Length;
                case 9:
                case 10: return fallarbor_lavaridge910Length;
                default: return fallarbor_lavaridge910Length;
            }
        case 2: //rustboro - mauville
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return rustboro_mauville04Length;
                case 5:
                case 6:
                case 7:
                case 8: return rustboro_mauville58Length;
                case 9:
                case 10: return rustboro_mauville910Length;
                default: return rustboro_mauville910Length;
            }
        case 3: //lavaridge - mauville
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return lavaridge_mauville04Length;
                case 5:
                case 6:
                case 7:
                case 8: return lavaridge_mauville58Length;
                case 9:
                case 10: return lavaridge_mauville910Length;
                default: return lavaridge_mauville910Length;
            }
        case 4: //rustboro - petalburg
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return rustboro_petalburg04Length;
                case 5:
                case 6:
                case 7:
                case 8: return rustboro_petalburg58Length;
                case 9:
                case 10: return rustboro_petalburg910Length;
                default: return rustboro_petalburg910Length;
            }
        case 5: //petalburg - dewford
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return petalburg_dewford04Length;
                case 5:
                case 6:
                case 7:
                case 8: return petalburg_dewford58Length;
                case 9:
                case 10: return petalburg_dewford910Length;
                default: return petalburg_dewford910Length;
            }
        case 6: //dewford - slateport
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return dewford_slateport04Length;
                case 5:
                case 6:
                case 7:
                case 8: return dewford_slateport58Length;
                case 9:
                case 10: return dewford_slateport910Length;
                default: return dewford_slateport910Length;
            }
        case 7: //petalburg - slateport
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return petalburg_slateport04Length;
                case 5:
                case 6:
                case 7:
                case 8: return petalburg_slateport58Length;
                case 9:
                case 10: return petalburg_slateport910Length;
                default: return petalburg_slateport910Length;
            }
        case 8: //slateport - mauville
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return slateport_mauville04Length;
                case 5:
                case 6:
                case 7:
                case 8: return slateport_mauville58Length;
                case 9:
                case 10: return slateport_mauville910Length;
                default: return slateport_mauville910Length;
            }
        case 9: //lavaridge - fortree
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return lavaridge_fortree04Length;
                case 5:
                case 6:
                case 7:
                case 8: return lavaridge_fortree58Length;
                case 9:
                case 10: return lavaridge_fortree910Length;
                default: return lavaridge_fortree910Length;
            }
        case 10: //mauville - mtpyre
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return mauville_mtpyre04Length;
                case 5:
                case 6:
                case 7:
                case 8: return mauville_mtpyre58Length;
                case 9:
                case 10: return mauville_mtpyre910Length;
                default: return mauville_mtpyre910Length;
            }
        case 11: //fortree - mtpyre
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return fortree_mtpyre04Length;
                case 5:
                case 6:
                case 7:
                case 8: return fortree_mtpyre58Length;
                case 9:
                case 10: return fortree_mtpyre910Length;
                default: return fortree_mtpyre910Length;
            }
        case 12: //mtpyre - lilycove
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return mtpyre_lilycove04Length;
                case 5:
                case 6:
                case 7:
                case 8: return mtpyre_lilycove58Length;
                case 9:
                case 10: return mtpyre_lilycove910Length;
                default: return mtpyre_lilycove910Length;
            }
        case 13: //lilycove - mossdeep
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return lilycove_mossdeep04Length;
                case 5:
                case 6:
                case 7:
                case 8: return lilycove_mossdeep58Length;
                case 9:
                case 10: return lilycove_mossdeep910Length;
                default: return lilycove_mossdeep910Length;
            }
        case 14: //slateport - mossdeep
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return slateport_mossdeep04Length;
                case 5:
                case 6:
                case 7:
                case 8: return slateport_mossdeep58Length;
                case 9:
                case 10: return slateport_mossdeep910Length;
                default: return slateport_mossdeep910Length;
            }
        case 15: //fallarbor
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return fallarbor04Length;
                case 5:
                case 6:
                case 7:
                case 8: return fallarbor58Length;
                case 9:
                case 10: return fallarbor910Length;
                default: return fallarbor910Length;
            }
        case 16: //rustboro
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return rustboro04Length;
                case 5:
                case 6:
                case 7:
                case 8: return rustboro58Length;
                case 9:
                case 10: return rustboro910Length;
                default: return rustboro910Length;
            }
        case 17: //petalburg
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return petalburg04Length;
                case 5:
                case 6:
                case 7:
                case 8: return petalburg58Length;
                case 9:
                case 10: return petalburg910Length;
                default: return petalburg910Length;
            }
        case 18: //dewford
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return dewford04Length;
                case 5:
                case 6:
                case 7:
                case 8: return dewford58Length;
                case 9:
                case 10: return dewford910Length;
                default: return dewford910Length;
            }
        case 19: //slateport
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return slateport04Length;
                case 5:
                case 6:
                case 7:
                case 8: return slateport58Length;
                case 9:
                case 10: return slateport910Length;
                default: return slateport910Length;
            }
        case 20: //mauville
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return mauville04Length;
                case 5:
                case 6:
                case 7:
                case 8: return mauville58Length;
                case 9:
                case 10: return mauville910Length;
                default: return mauville910Length;
            }
        case 21: //lavaridge
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return lavaridge04Length;
                case 5:
                case 6:
                case 7:
                case 8: return lavaridge58Length;
                case 9: 
                case 10: return lavaridge910Length;
                default: return lavaridge910Length;
            }
        case 22: //fortree
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return fortree04Length;
                case 5:
                case 6:
                case 7:
                case 8: return fortree58Length;
                case 9:
                case 10: return fortree910Length;
                default: return fortree910Length;
            }
        case 23: //mtpyre
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return mtpyre04Length;
                case 5:
                case 6:
                case 7:
                case 8: return mtpyre58Length;
                case 9:
                case 10: return mtpyre910Length;
                default: return mtpyre910Length;
            }
        case 24: //lilycove
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return lilycove04Length;
                case 5:
                case 6:
                case 7:
                case 8: return lilycove58Length;
                case 9:
                case 10: return lilycove910Length;
                default: return lilycove910Length;
            }
        case 25: //mossdeep
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return mossdeep04Length;
                case 5:
                case 6:
                case 7:
                case 8: return mossdeep58Length;
                case 9:
                case 10: return mossdeep910Length;
                default: return mossdeep910Length;
            }
        case 26: //sootopolis
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return sootopolis04Length;
                case 5:
                case 6:
                case 7:
                case 8: return sootopolis58Length;
                case 9:
                case 10: return sootopolis910Length;
                default: return sootopolis910Length;
            }
        default:
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return mossdeep04Length;
                case 5:
                case 6:
                case 7:
                case 8: return mossdeep58Length;
                case 9:
                case 10: return mossdeep910Length;
                default: return mossdeep910Length;
            }
    };
};

const struct TrainerMon *CombinePools(const struct Trainer *trainer)
{
    
    u8 currentTrainerClass = trainer->trainerClass;
    u8 currentTrainerRoute = trainer->trainerUnlockedAt;
    u8 classPoolSize = GetClassPoolSize(currentTrainerClass);
    u8 routePoolSize = GetRoutePoolSize(currentTrainerRoute);

    //DebugPrintf("Class, Route Pool Size --");
    //DebugPrintf("%d", classPoolSize);
    //DebugPrintf("%d", routePoolSize);

    struct TrainerMon* poolparty = Alloc(sizeof(struct TrainerMon) * (classPoolSize + routePoolSize));

    switch(currentTrainerClass)
    {
        case 0: //hiker
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Hiker04, sizeof(ClassParty_Hiker04)); break; 
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Hiker58, sizeof(ClassParty_Hiker58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Hiker910, sizeof(ClassParty_Hiker910)); break;
                default: memcpy(poolparty, ClassParty_Hiker910, sizeof(ClassParty_Hiker910)); break;
            }
            break;
        case 1: //team aqua (grunt)
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Team_Aqua04, sizeof(ClassParty_Team_Aqua04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Team_Aqua58, sizeof(ClassParty_Team_Aqua910)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Team_Aqua910, sizeof(ClassParty_Team_Aqua910)); break;
                default: memcpy(poolparty, ClassParty_Team_Aqua910, sizeof(ClassParty_Team_Aqua910)); break;
            }
            break;
        case 2: //pkmn breeder
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Pkmn_Breeder04, sizeof(ClassParty_Pkmn_Breeder04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Pkmn_Breeder58, sizeof(ClassParty_Pkmn_Breeder58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Pkmn_Breeder910, sizeof(ClassParty_Pkmn_Breeder910)); break;
                default: memcpy(poolparty, ClassParty_Pkmn_Breeder910, sizeof(ClassParty_Pkmn_Breeder910)); break;
            }
            break;
        case 3: //cool trainer
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Cooltrainer04, sizeof(ClassParty_Cooltrainer04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Cooltrainer58, sizeof(ClassParty_Cooltrainer58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Cooltrainer910, sizeof(ClassParty_Cooltrainer910)); break;
                default: memcpy(poolparty, ClassParty_Cooltrainer910, sizeof(ClassParty_Cooltrainer910)); break;
            }
            break;
        case 4: //bird keeper
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Bird_Keeper04, sizeof(ClassParty_Bird_Keeper04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Bird_Keeper58, sizeof(ClassParty_Bird_Keeper58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Bird_Keeper910, sizeof(ClassParty_Bird_Keeper910)); break;
                default: memcpy(poolparty, ClassParty_Bird_Keeper910, sizeof(ClassParty_Bird_Keeper910)); break;
            }
            break;
        case 5: //collector
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Collector04, sizeof(ClassParty_Collector04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Collector58, sizeof(ClassParty_Collector58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Collector910, sizeof(ClassParty_Collector910)); break;
                default: memcpy(poolparty, ClassParty_Collector910, sizeof(ClassParty_Collector910)); break;
            }
            break;
        case 6: //swimmer
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Swimmer04, sizeof(ClassParty_Swimmer04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Swimmer58, sizeof(ClassParty_Swimmer58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Swimmer910, sizeof(ClassParty_Swimmer910)); break;
                default: memcpy(poolparty, ClassParty_Swimmer910, sizeof(ClassParty_Swimmer910)); break;
            }
            break;
        case 7: //team magma (grunt)
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Team_Magma04, sizeof(ClassParty_Team_Magma58)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Team_Magma58, sizeof(ClassParty_Team_Magma58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Team_Magma910, sizeof(ClassParty_Team_Magma910)); break;
                default: memcpy(poolparty, ClassParty_Team_Magma910, sizeof(ClassParty_Team_Magma910)); break;
            }
            break;
        case 8: //expert
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Expert04, sizeof(ClassParty_Expert04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Expert58, sizeof(ClassParty_Expert58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Expert910, sizeof(ClassParty_Expert910)); break;
                default: memcpy(poolparty, ClassParty_Expert910, sizeof(ClassParty_Expert910)); break;
            }
            break;
         case 9: // black belt
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Black_Belt04, sizeof(ClassParty_Black_Belt04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Black_Belt58, sizeof(ClassParty_Black_Belt58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Black_Belt910, sizeof(ClassParty_Black_Belt910)); break;
                default: memcpy(poolparty, ClassParty_Black_Belt910, sizeof(ClassParty_Black_Belt910)); break;
            }
            break;
        case 10: // hex maniac
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Hex_Maniac04, sizeof(ClassParty_Hex_Maniac04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Hex_Maniac58, sizeof(ClassParty_Hex_Maniac58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Hex_Maniac910, sizeof(ClassParty_Hex_Maniac910)); break;
                default: memcpy(poolparty, ClassParty_Hex_Maniac910, sizeof(ClassParty_Hex_Maniac910)); break;
            }
            break;
        case 11: //aroma lady
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Aroma_Lady04, sizeof(ClassParty_Aroma_Lady04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Aroma_Lady58, sizeof(ClassParty_Aroma_Lady58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Aroma_Lady910, sizeof(ClassParty_Aroma_Lady910)); break;
                default: memcpy(poolparty, ClassParty_Aroma_Lady910, sizeof(ClassParty_Aroma_Lady910)); break;
            }
            break;
        case 12: //ruin maniac
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Ruin_Maniac04, sizeof(ClassParty_Ruin_Maniac04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Ruin_Maniac58, sizeof(ClassParty_Ruin_Maniac58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Ruin_Maniac910, sizeof(ClassParty_Ruin_Maniac910)); break;
                default: memcpy(poolparty, ClassParty_Ruin_Maniac910, sizeof(ClassParty_Ruin_Maniac910)); break;
            }
            break;
        case 13: //tuber
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Tuber04, sizeof(ClassParty_Tuber04)); break;
                case 5: 
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Tuber58, sizeof(ClassParty_Tuber58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Tuber910, sizeof(ClassParty_Tuber910)); break;
                default: memcpy(poolparty, ClassParty_Tuber910, sizeof(ClassParty_Tuber910)); break;
            }
            break;
        case 14: //lady
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Lady04, sizeof(ClassParty_Lady04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Lady58, sizeof(ClassParty_Lady58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Lady910, sizeof(ClassParty_Lady910)); break;
                default: memcpy(poolparty, ClassParty_Lady910, sizeof(ClassParty_Lady910)); break;
            }
            break;
        case 15: //beauty
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Beauty04, sizeof(ClassParty_Beauty04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Beauty58, sizeof(ClassParty_Beauty58)); break;
                case 9: 
                case 10: memcpy(poolparty, ClassParty_Beauty910, sizeof(ClassParty_Beauty910)); break;
                default: memcpy(poolparty, ClassParty_Beauty910, sizeof(ClassParty_Beauty910)); break;
            }
            break;
        case 16: //rich boy
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Rich_Boy04, sizeof(ClassParty_Rich_Boy04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Rich_Boy58, sizeof(ClassParty_Rich_Boy58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Rich_Boy910, sizeof(ClassParty_Rich_Boy910)); break;
                default: memcpy(poolparty, ClassParty_Rich_Boy910, sizeof(ClassParty_Rich_Boy910)); break;
            }
            break;
         case 17: //pokemaniac
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Pokemaniac04, sizeof(ClassParty_Pokemaniac04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Pokemaniac58, sizeof(ClassParty_Pokemaniac58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Pokemaniac910, sizeof(ClassParty_Pokemaniac910)); break;
                default: memcpy(poolparty, ClassParty_Pokemaniac910, sizeof(ClassParty_Pokemaniac910)); break;
            }
            break;
        case 18: //guitarist
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Guitarist04, sizeof(ClassParty_Guitarist04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Guitarist58, sizeof(ClassParty_Guitarist58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Guitarist910, sizeof(ClassParty_Guitarist910)); break;
                default: memcpy(poolparty, ClassParty_Guitarist910, sizeof(ClassParty_Guitarist910)); break;
            }
            break;
        case 19: //kindler
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Kindler04, sizeof(ClassParty_Kindler04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Kindler58, sizeof(ClassParty_Kindler58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Kindler910, sizeof(ClassParty_Kindler910)); break;
                default: memcpy(poolparty, ClassParty_Kindler910, sizeof(ClassParty_Kindler910)); break;
            }
            break;
        case 20: //camper
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Camper04, sizeof(ClassParty_Camper04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Camper58, sizeof(ClassParty_Camper58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Camper910, sizeof(ClassParty_Camper910)); break;
                default: memcpy(poolparty, ClassParty_Camper910, sizeof(ClassParty_Camper910)); break;
            }
            break;
        case 21: //picnicker
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Picnicker04, sizeof(ClassParty_Picnicker58)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Picnicker58, sizeof(ClassParty_Picnicker58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Picnicker910, sizeof(ClassParty_Picnicker910)); break;
                default: memcpy(poolparty, ClassParty_Picnicker910, sizeof(ClassParty_Picnicker910)); break;
            }
            break;
        case 22: //bug maniac
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Bug_Maniac04, sizeof(ClassParty_Bug_Maniac04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Bug_Maniac58, sizeof(ClassParty_Bug_Maniac58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Bug_Maniac910, sizeof(ClassParty_Bug_Maniac910)); break;
            }
            break;
        case 23: //psychic
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Psychic04, sizeof(ClassParty_Psychic04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Psychic58, sizeof(ClassParty_Psychic58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Psychic910, sizeof(ClassParty_Psychic910)); break;
                default: memcpy(poolparty, ClassParty_Psychic910, sizeof(ClassParty_Psychic910)); break;
            }
            break;
        case 24: //gentleman
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Gentleman04, sizeof(ClassParty_Gentleman04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Gentleman58, sizeof(ClassParty_Gentleman58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Gentleman910, sizeof(ClassParty_Gentleman910)); break;
                default: memcpy(poolparty, ClassParty_Gentleman910, sizeof(ClassParty_Gentleman910)); break;
            }
            break;
        case 25: //school kid
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_School_Kid04, sizeof(ClassParty_School_Kid04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_School_Kid58, sizeof(ClassParty_School_Kid58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_School_Kid910, sizeof(ClassParty_School_Kid910)); break;
                default: memcpy(poolparty, ClassParty_School_Kid910, sizeof(ClassParty_School_Kid910)); break;
            }
            break;
        case 26: //sr and jr
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Sr_And_Jr04, sizeof(ClassParty_Sr_And_Jr04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Sr_And_Jr58, sizeof(ClassParty_Sr_And_Jr58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Sr_And_Jr910, sizeof(ClassParty_Sr_And_Jr910)); break;
                default: memcpy(poolparty, ClassParty_Sr_And_Jr910, sizeof(ClassParty_Sr_And_Jr910)); break;
            }
            break;
        case 27: //pokefan
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Pokefan04, sizeof(ClassParty_Pokefan04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Pokefan58, sizeof(ClassParty_Pokefan58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Pokefan910, sizeof(ClassParty_Pokefan910)); break;
                default: memcpy(poolparty, ClassParty_Pokefan910, sizeof(ClassParty_Pokefan910)); break;
            }
            break;
        case 28: //youngster
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Youngster04, sizeof(ClassParty_Youngster04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Youngster58, sizeof(ClassParty_Youngster58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Youngster910, sizeof(ClassParty_Youngster910)); break;
                default: memcpy(poolparty, ClassParty_Youngster910, sizeof(ClassParty_Youngster910)); break;
            }
            break;
        case 29: //fisherman
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Fisherman04, sizeof(ClassParty_Fisherman04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Fisherman58, sizeof(ClassParty_Fisherman58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Fisherman910, sizeof(ClassParty_Fisherman910)); break;
                default: memcpy(poolparty, ClassParty_Fisherman910, sizeof(ClassParty_Fisherman910)); break;
            }
            break;
        case 30: //triathlete
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Triathlete04, sizeof(ClassParty_Triathlete04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Triathlete58, sizeof(ClassParty_Triathlete58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Triathlete910, sizeof(ClassParty_Triathlete910)); break;
                default: memcpy(poolparty, ClassParty_Triathlete910, sizeof(ClassParty_Triathlete910)); break;
            }
            break;
        case 31: //dragon tamer
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Dragon_Tamer04, sizeof(ClassParty_Dragon_Tamer04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Dragon_Tamer58, sizeof(ClassParty_Dragon_Tamer58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Dragon_Tamer910, sizeof(ClassParty_Dragon_Tamer910)); break;
                default: memcpy(poolparty, ClassParty_Dragon_Tamer910, sizeof(ClassParty_Dragon_Tamer910)); break;
            }
            break;
        case 32: //ninja boy
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Ninja_Boy04, sizeof(ClassParty_Ninja_Boy04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Ninja_Boy58, sizeof(ClassParty_Ninja_Boy58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Ninja_Boy910, sizeof(ClassParty_Ninja_Boy910)); break;
            }
            break;
        case 33: //battle girl
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Battle_Girl04, sizeof(ClassParty_Battle_Girl04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Battle_Girl58, sizeof(ClassParty_Battle_Girl58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Battle_Girl910, sizeof(ClassParty_Battle_Girl910)); break;
            }
            break;
        case 34: //parasol lady
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Parasol_Lady04, sizeof(ClassParty_Parasol_Lady04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Parasol_Lady58, sizeof(ClassParty_Parasol_Lady58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Parasol_Lady910, sizeof(ClassParty_Parasol_Lady910)); break;
                default: memcpy(poolparty, ClassParty_Parasol_Lady910, sizeof(ClassParty_Parasol_Lady910)); break;
            }
            break;
        case 35: //twins
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Twins04, sizeof(ClassParty_Twins04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Twins58, sizeof(ClassParty_Twins58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Twins910, sizeof(ClassParty_Twins910)); break;
                default: memcpy(poolparty, ClassParty_Twins910, sizeof(ClassParty_Twins910)); break;
            }
            break;
        case 36: //sailor
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Sailor04, sizeof(ClassParty_Sailor04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Sailor58, sizeof(ClassParty_Sailor58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Sailor910, sizeof(ClassParty_Sailor910)); break;
                default: memcpy(poolparty, ClassParty_Sailor910, sizeof(ClassParty_Sailor910)); break;
            }
            break;
        case 37: //bug catchter
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Bug_Catcher04, sizeof(ClassParty_Bug_Catcher04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Bug_Catcher58, sizeof(ClassParty_Bug_Catcher58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Bug_Catcher910, sizeof(ClassParty_Bug_Catcher910)); break;
                default: memcpy(poolparty, ClassParty_Bug_Catcher910, sizeof(ClassParty_Bug_Catcher910)); break;
            }
            break;
        case 38: //pkmn ranger
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Pkmn_Ranger04, sizeof(ClassParty_Pkmn_Ranger04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Pkmn_Ranger58, sizeof(ClassParty_Pkmn_Ranger58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Pkmn_Ranger910, sizeof(ClassParty_Pkmn_Ranger910)); break;
            }
            break;
        case 39: //lass
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Lass04, sizeof(ClassParty_Lass04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Lass58, sizeof(ClassParty_Lass58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Lass910, sizeof(ClassParty_Lass910)); break;
                default: memcpy(poolparty, ClassParty_Lass910, sizeof(ClassParty_Lass910)); break;
            }
            break;
        case 40: //young couple
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Young_Couple04, sizeof(ClassParty_Young_Couple04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Young_Couple58, sizeof(ClassParty_Young_Couple58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Young_Couple910, sizeof(ClassParty_Young_Couple910)); break;
                default: memcpy(poolparty, ClassParty_Young_Couple910, sizeof(ClassParty_Young_Couple910)); break;
            }
            break;
        case 41: //sis and bro
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Sis_And_Bro04, sizeof(ClassParty_Sis_And_Bro04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Sis_And_Bro58, sizeof(ClassParty_Sis_And_Bro58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Sis_And_Bro910, sizeof(ClassParty_Sis_And_Bro910)); break;
                default: memcpy(poolparty, ClassParty_Sis_And_Bro910, sizeof(ClassParty_Sis_And_Bro910)); break;
            }
            break;
        case 42: //aether
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Aether04, sizeof(ClassParty_Aether04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Aether58, sizeof(ClassParty_Aether58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Aether910, sizeof(ClassParty_Aether910)); break;
                default: memcpy(poolparty, ClassParty_Aether910, sizeof(ClassParty_Aether910)); break;
            }
        default: 
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty, ClassParty_Lass04, sizeof(ClassParty_Lass04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty, ClassParty_Lass58, sizeof(ClassParty_Lass58)); break;
                case 9:
                case 10: memcpy(poolparty, ClassParty_Lass910, sizeof(ClassParty_Lass910)); break;
                default: memcpy(poolparty, ClassParty_Lass910, sizeof(ClassParty_Lass910)); break;
            }
            break;
    };

    //DebugPrintf("After Class Party Set--");
    //DebugPrintf("%d", poolparty[0].species);

    switch(currentTrainerRoute)
    {
        case 0: // fallarbor_rustboro
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Fallarbor_Rustboro04, sizeof(RouteParty_Fallarbor_Rustboro04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Fallarbor_Rustboro58, sizeof(RouteParty_Fallarbor_Rustboro58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Fallarbor_Rustboro910, sizeof(RouteParty_Fallarbor_Rustboro910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Fallarbor_Rustboro910, sizeof(RouteParty_Fallarbor_Rustboro910)); break;
            }
            break;
        case 1: //fallarbor_lavardige
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Fallarbor_Lavaridge04, sizeof(RouteParty_Fallarbor_Lavaridge04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Fallarbor_Lavaridge58, sizeof(RouteParty_Fallarbor_Lavaridge58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Fallarbor_Lavaridge910, sizeof(RouteParty_Fallarbor_Lavaridge910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Fallarbor_Lavaridge910, sizeof(RouteParty_Fallarbor_Lavaridge910)); break;
            }
            break;
        case 2: //rustboro_mauville
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Rustboro_Mauville04, sizeof(RouteParty_Rustboro_Mauville04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Rustboro_Mauville58, sizeof(RouteParty_Rustboro_Mauville58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Rustboro_Mauville910, sizeof(RouteParty_Rustboro_Mauville910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Rustboro_Mauville910, sizeof(RouteParty_Rustboro_Mauville910)); break;
            }
            break;
        case 3: //lavaridge_mauville
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Lavaridge_Mauville04, sizeof(RouteParty_Lavaridge_Mauville04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Lavaridge_Mauville58, sizeof(RouteParty_Lavaridge_Mauville58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Lavaridge_Mauville910, sizeof(RouteParty_Lavaridge_Mauville910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Lavaridge_Mauville910, sizeof(RouteParty_Lavaridge_Mauville910)); break;
            }
            break;
        case 4: //rustboro_petalburg
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Rustboro_Petalburg04, sizeof(RouteParty_Rustboro_Petalburg04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Rustboro_Petalburg58, sizeof(RouteParty_Rustboro_Petalburg58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Rustboro_Petalburg910, sizeof(RouteParty_Rustboro_Petalburg910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Rustboro_Petalburg910, sizeof(RouteParty_Rustboro_Petalburg910)); break;
            }
            break;
        case 5: //petalburg_dewford
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Petalburg_Dewford04, sizeof(RouteParty_Petalburg_Dewford04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Petalburg_Dewford58, sizeof(RouteParty_Petalburg_Dewford58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Petalburg_Dewford910, sizeof(RouteParty_Petalburg_Dewford910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Petalburg_Dewford910, sizeof(RouteParty_Petalburg_Dewford910)); break;
            }
            break;
        case 6: //dewford_slateport
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Dewford_Slateport04, sizeof(RouteParty_Dewford_Slateport04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Dewford_Slateport58, sizeof(RouteParty_Dewford_Slateport58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Dewford_Slateport910, sizeof(RouteParty_Dewford_Slateport910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Dewford_Slateport910, sizeof(RouteParty_Dewford_Slateport910)); break;
            }
            break;
        case 7: //petalburg_slateport
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Petalburg_Slateport04, sizeof(RouteParty_Petalburg_Slateport04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Petalburg_Slateport58, sizeof(RouteParty_Petalburg_Slateport58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Petalburg_Slateport910, sizeof(RouteParty_Petalburg_Slateport910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Petalburg_Slateport910, sizeof(RouteParty_Petalburg_Slateport910)); break;
            }
            break;
        case 8: //slateport_mauville
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Slateport_Mauville04, sizeof(RouteParty_Slateport_Mauville04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Slateport_Mauville58, sizeof(RouteParty_Slateport_Mauville58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Slateport_Mauville910, sizeof(RouteParty_Slateport_Mauville910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Slateport_Mauville910, sizeof(RouteParty_Slateport_Mauville910)); break;
            }
            break;
        case 9: //lavaridge_fortree
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Lavaridge_Fortree04, sizeof(RouteParty_Lavaridge_Fortree04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Lavaridge_Fortree58, sizeof(RouteParty_Lavaridge_Fortree58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Lavaridge_Fortree910, sizeof(RouteParty_Lavaridge_Fortree910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Lavaridge_Fortree910, sizeof(RouteParty_Lavaridge_Fortree910)); break;
            }
            break;
        case 10: //mauville_mtpyre
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Mauville_Mtpyre04, sizeof(RouteParty_Mauville_Mtpyre04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Mauville_Mtpyre58, sizeof(RouteParty_Mauville_Mtpyre58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Mauville_Mtpyre910, sizeof(RouteParty_Mauville_Mtpyre910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Mauville_Mtpyre910, sizeof(RouteParty_Mauville_Mtpyre910)); break;
            }
            break;
        case 11: //fortree_mtpyre
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Fortree_Mtpyre04, sizeof(RouteParty_Fortree_Mtpyre04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Fortree_Mtpyre58, sizeof(RouteParty_Fortree_Mtpyre58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Fortree_Mtpyre910, sizeof(RouteParty_Fortree_Mtpyre910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Fortree_Mtpyre910, sizeof(RouteParty_Fortree_Mtpyre910)); break;
            }
            break;
        case 12: //mtpyre_lilycove
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Mtpyre_Lilycove04, sizeof(RouteParty_Mtpyre_Lilycove04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Mtpyre_Lilycove58, sizeof(RouteParty_Mtpyre_Lilycove58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Mtpyre_Lilycove910, sizeof(RouteParty_Mtpyre_Lilycove910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Mtpyre_Lilycove910, sizeof(RouteParty_Mtpyre_Lilycove910)); break;
            }
            break;
        case 13: //lilycove_mossdeep
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Lilycove_Mossdeep04, sizeof(RouteParty_Lilycove_Mossdeep04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Lilycove_Mossdeep58, sizeof(RouteParty_Lilycove_Mossdeep58)); break;
                case 9: 
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Lilycove_Mossdeep910, sizeof(RouteParty_Lilycove_Mossdeep910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Lilycove_Mossdeep910, sizeof(RouteParty_Lilycove_Mossdeep910)); break;
            }
            break;
        case 14: //slateport_mossdeep
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Slateport_Mossdeep04, sizeof(RouteParty_Slateport_Mossdeep04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Slateport_Mossdeep58, sizeof(RouteParty_Slateport_Mossdeep58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Slateport_Mossdeep910, sizeof(RouteParty_Slateport_Mossdeep910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Slateport_Mossdeep910, sizeof(RouteParty_Slateport_Mossdeep910)); break;
            }
            break;
        case 15: //fallarbor
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Fallarbor04, sizeof(RouteParty_Fallarbor04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Fallarbor58, sizeof(RouteParty_Fallarbor58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Fallarbor910, sizeof(RouteParty_Fallarbor910)); break;
            }
            break;
        case 16: //rustboro
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Rustboro04, sizeof(RouteParty_Rustboro04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Rustboro58, sizeof(RouteParty_Rustboro58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Rustboro910, sizeof(RouteParty_Rustboro910)); break;
            }
            break;
        case 17: //petalburg
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Petalburg04, sizeof(RouteParty_Petalburg04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Petalburg58, sizeof(RouteParty_Petalburg58)); break;
                case 9: 
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Petalburg910, sizeof(RouteParty_Petalburg910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Petalburg910, sizeof(RouteParty_Petalburg910)); break;
            }
            break;
        case 18: //dewford
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Dewford04, sizeof(RouteParty_Dewford04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Dewford58, sizeof(RouteParty_Dewford58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Dewford910, sizeof(RouteParty_Dewford910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Dewford910, sizeof(RouteParty_Dewford910)); break;
            }
            break;
        case 19: //slateport
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2: 
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Slateport04, sizeof(RouteParty_Slateport04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Slateport58, sizeof(RouteParty_Slateport58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Slateport910, sizeof(RouteParty_Slateport910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Slateport910, sizeof(RouteParty_Slateport910)); break;
            }
            break;
        case 20: //mauville
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Mauville04, sizeof(RouteParty_Mauville04)); break;
                case 5: 
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Mauville58, sizeof(RouteParty_Mauville58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Mauville910, sizeof(RouteParty_Mauville910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Mauville910, sizeof(RouteParty_Mauville910)); break;
            }
            break;
        case 21: //lavaridge
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Lavaridge04, sizeof(RouteParty_Lavaridge04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Lavaridge58, sizeof(RouteParty_Lavaridge58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Lavaridge910, sizeof(RouteParty_Lavaridge910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Lavaridge910, sizeof(RouteParty_Lavaridge910)); break;
            }
            break;
        case 22: //fortree
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Fortree04, sizeof(RouteParty_Fortree04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Fortree58, sizeof(RouteParty_Fortree58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Fortree910, sizeof(RouteParty_Fortree910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Fortree910, sizeof(RouteParty_Fortree910)); break;
            }
            break;
        case 23: //mtpyre
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Mtpyre04, sizeof(RouteParty_Mtpyre04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Mtpyre58, sizeof(RouteParty_Mtpyre58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Mtpyre910, sizeof(RouteParty_Mtpyre910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Mtpyre910, sizeof(RouteParty_Mtpyre910)); break;
            }
            break;
        case 24: //lilycove
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Lilycove04, sizeof(RouteParty_Lilycove04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Lilycove58, sizeof(RouteParty_Lilycove58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Lilycove910, sizeof(RouteParty_Lilycove910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Lilycove910, sizeof(RouteParty_Lilycove910)); break;
            }
            break;
        case 25: //mossdeep
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Mossdeep04, sizeof(RouteParty_Mossdeep04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Mossdeep58, sizeof(RouteParty_Mossdeep58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Mossdeep910, sizeof(RouteParty_Mossdeep910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Mossdeep910, sizeof(RouteParty_Mossdeep910)); break;
            }
            break;
        case 26: //sootopolis
            memcpy(poolparty + classPoolSize, RouteParty_Sootopolis, sizeof(RouteParty_Sootopolis));
            break;
        default:
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: memcpy(poolparty + classPoolSize, RouteParty_Mossdeep04, sizeof(RouteParty_Mossdeep04)); break;
                case 5:
                case 6:
                case 7:
                case 8: memcpy(poolparty + classPoolSize, RouteParty_Mossdeep58, sizeof(RouteParty_Mossdeep58)); break;
                case 9:
                case 10: memcpy(poolparty + classPoolSize, RouteParty_Mossdeep910, sizeof(RouteParty_Mossdeep910)); break;
                default: memcpy(poolparty + classPoolSize, RouteParty_Mossdeep910, sizeof(RouteParty_Mossdeep910)); break;
            }
            break;
    };

    //DebugPrintf("Just Before Return--");
    //DebugPrintf("%d", poolparty[1].species);

    return poolparty;
};
