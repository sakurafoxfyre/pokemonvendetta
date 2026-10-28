#include "rtc.h"
#include "constants/species.h"
#include "random.h"
#include "malloc.h"
#include "event_data.h"
#include "constants/abilities.h"
#include "pokemon.h"
#include "math.h"

struct Ven_WildPokemon
{
    u8 minLevel;
    u8 maxLevel;
    enum Species species;
    u8 encounterRate;
};

const struct Ven_WildPokemon *Ven_GetLandEncounterArray(void)
{
    //DebugPrintf("Helloooooo...?");
    u16 currentMapNum = gSaveBlock1Ptr->location.mapNum;

    static struct Ven_WildPokemon fallbackMon[2] = 
    {
        {
            .minLevel = 5,
            .maxLevel = 5,
            .species = SPECIES_SHINX,
            .encounterRate = 100,
        },
        {
            .minLevel = 0,
            .maxLevel = 0,
            .species = SPECIES_NONE,
            .encounterRate = 0,
        }
    };

    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_PETALBURG_CITY)) //gMapGroup_TownsAndRoutes
    {
        switch (currentMapNum)
        {
            case MAP_NUM(MAP_HAUNTWOOD):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayDataHauntwoodland02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/hauntwood/landencounters/hauntwoodland_02.h"
                        };
                        return arrayDataHauntwoodland02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayDataHauntwoodland35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/hauntwood/landencounters/hauntwoodland_35.h"
                        };
                        return arrayDataHauntwoodland35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayDataHauntwoodland68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/hauntwood/landencounters/hauntwoodland_68.h"
                        };
                        return arrayDataHauntwoodland68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayDataHauntwoodland910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/hauntwood/landencounters/hauntwoodland_910.h"
                        };
                        return arrayDataHauntwoodland910;
                    default:
                        static const struct Ven_WildPokemon arrayDataHauntwoodlanddefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/hauntwood/landencounters/hauntwoodland_910.h"
                        };
                        return arrayDataHauntwoodlanddefault;
                }
            case MAP_NUM(MAP_ROUTE101):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData101land02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route101/landencounters/route101land_02.h"
                        };
                        return arrayData101land02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData101land35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route101/landencounters/route101land_35.h"
                        };
                        return arrayData101land35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData101land68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route101/landencounters/route101land_68.h"
                        };
                        return arrayData101land68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData101land910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route101/landencounters/route101land_910.h"
                        };
                        return arrayData101land910;
                    default:
                        static const struct Ven_WildPokemon arrayData101landdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route101/landencounters/route101land_910.h"
                        };
                        return arrayData101landdefault;
                }
            case MAP_NUM(MAP_ROUTE102):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData102land02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route102/landencounters/route102land_02.h"
                        };
                        return arrayData102land02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData102land35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route102/landencounters/route102land_35.h"
                        };
                        return arrayData102land35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData102land68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route102/landencounters/route102land_68.h"
                        };
                        return arrayData102land68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData102land910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route102/landencounters/route102land_910.h"
                        };
                        return arrayData102land910;
                    default:
                        static const struct Ven_WildPokemon arrayData102landdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route102/landencounters/route102land_910.h"
                        };
                        return arrayData102landdefault;
                }
            case MAP_NUM(MAP_ROUTE103):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData103land02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route103/landencounters/route103land_02.h"
                        };
                        return arrayData103land02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData103land35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route103/landencounters/route103land_35.h"
                        };
                        return arrayData103land35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData103land68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route103/landencounters/route103land_68.h"
                        };
                        return arrayData103land68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData103land910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route103/landencounters/route103land_910.h"
                        };
                        return arrayData103land910;
                    default:
                        static const struct Ven_WildPokemon arrayData103landdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route103/landencounters/route103land_910.h"
                        };
                        return arrayData103landdefault;
                }
            case MAP_NUM(MAP_ROUTE104):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData104land02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route104/landencounters/route104land_02.h"
                        };
                        return arrayData104land02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData104land35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route104/landencounters/route104land_35.h"
                        };
                        return arrayData104land35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData104land68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route104/landencounters/route104land_68.h"
                        };
                        return arrayData104land68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData104land910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route104/landencounters/route104land_910.h"
                        };
                        return arrayData104land910;
                    default:
                        static const struct Ven_WildPokemon arrayData104landdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route104/landencounters/route104land_910.h"
                        };
                        return arrayData104landdefault;
                }
            case MAP_NUM(MAP_ROUTE106):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData106land02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route106/landencounters/route106land_02.h"
                        };
                        return arrayData106land02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData106land35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route106/landencounters/route106land_35.h"
                        };
                        return arrayData106land35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData106land68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route106/landencounters/route106land_68.h"
                        };
                        return arrayData106land68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData106land910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route106/landencounters/route106land_910.h"
                        };
                        return arrayData106land910;
                    default:
                        static const struct Ven_WildPokemon arrayData106landdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route106/landencounters/route106land_910.h"
                        };
                        return arrayData106landdefault;
                }
            case MAP_NUM(MAP_ROUTE109):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData109land02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route109/landencounters/route109land_02.h"
                        };
                        return arrayData109land02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData109land35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route109/landencounters/route109land_35.h"
                        };
                        return arrayData109land35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData109land68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route109/landencounters/route109land_68.h"
                        };
                        return arrayData109land68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData109land910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route109/landencounters/route109land_910.h"
                        };
                        return arrayData109land910;
                    default:
                        static const struct Ven_WildPokemon arrayData109landdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route109/landencounters/route109land_910.h"
                        };
                        return arrayData109landdefault;
                }
            case MAP_NUM(MAP_ROUTE110): 
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData110land02[12] = 
                        {
                            #include "data/wildencounters/townsandroutes/route110/landencounters/route110land_02.h"
                        };
                        return arrayData110land02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData110land35[12] = {
                            #include "data/wildencounters/townsandroutes/route110/landencounters/route110land_35.h"
                        };
                        return arrayData110land35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData110land68[12] = {
                            #include "data/wildencounters/townsandroutes/route110/landencounters/route110land_68.h"
                        };
                        return arrayData110land68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData110land910[12] = {
                            #include "data/wildencounters/townsandroutes/route110/landencounters/route110land_910.h"
                        };
                        return arrayData110land910;
                    default:
                        static const struct Ven_WildPokemon arrayDatadefault[12] = {
                            #include "data/wildencounters/townsandroutes/route110/landencounters/route110land_910.h"
                        };
                        return arrayDatadefault;
                }
            case MAP_NUM(MAP_ROUTE115):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData115land02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route115/landencounters/route115land_02.h"
                        };
                        return arrayData115land02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData115land35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route115/landencounters/route115land_35.h"
                        };
                        return arrayData115land35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData115land68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route115/landencounters/route115land_68.h"
                        };
                        return arrayData115land68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData115land910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route115/landencounters/route115land_910.h"
                        };
                        return arrayData115land910;
                    default:
                        static const struct Ven_WildPokemon arrayData115landdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route115/landencounters/route115land_910.h"
                        };
                        return arrayData115landdefault;
                }
            case MAP_NUM(MAP_ROUTE116):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData116land02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route116/landencounters/route116land_02.h"
                        };
                        return arrayData116land02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData116land35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route116/landencounters/route116land_35.h"
                        };
                        return arrayData116land35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData116land68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route116/landencounters/route116land_68.h"
                        };
                        return arrayData116land68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData116land910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route116/landencounters/route116land_910.h"
                        };
                        return arrayData116land910;
                    default:
                        static const struct Ven_WildPokemon arrayData116landdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route116/landencounters/route116land_910.h"
                        };
                        return arrayData116landdefault;
                }
            case MAP_NUM(MAP_ROUTE117):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData117land02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route117/landencounters/route117land_02.h"
                        };
                        return arrayData117land02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData117land35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route117/landencounters/route117land_35.h"
                        };
                        return arrayData117land35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData117land68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route117/landencounters/route117land_68.h"
                        };
                        return arrayData117land68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData117land910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route117/landencounters/route117land_910.h"
                        };
                        return arrayData117land910;
                    default:
                        static const struct Ven_WildPokemon arrayData117landdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route117/landencounters/route117land_910.h"
                        };
                        return arrayData117landdefault;
                }
            case MAP_NUM(MAP_RUSTBORO_PIER):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayDatarustboropierland02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/rustboropier/landencounters/rustboropierland_02.h"
                        };
                        return arrayDatarustboropierland02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayDatarustboropierland35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/rustboropier/landencounters/rustboropierland_35.h"
                        };
                        return arrayDatarustboropierland35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayDatarustboropierland68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/rustboropier/landencounters/rustboropierland_68.h"
                        };
                        return arrayDatarustboropierland68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayDatarustboropierland910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/rustboropier/landencounters/rustboropierland_910.h"
                        };
                        return arrayDatarustboropierland910;
                    default:
                        static const struct Ven_WildPokemon arrayDatarustboropierlanddefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/rustboropier/landencounters/rustboropierland_910.h"
                        };
                        return arrayDatarustboropierlanddefault;
                }
            default:
                DebugPrintf("This encounter table hasn't been set up!");
                return fallbackMon;
        }
    }
    else if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_RUSTURF_TUNNEL)) //gMapGroup_Dungeons
    {
        switch (currentMapNum){
            case MAP_NUM(MAP_GRANITE_CAVE_1F):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayDataGranite1fland02[12] = {
                            #include "data/wildencounters/dungeons/granitecave_1f/landencounters/granite1fland_02.h"
                        };
                        return arrayDataGranite1fland02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayDataGranite1fland35[12] = {
                            #include "data/wildencounters/dungeons/granitecave_1f/landencounters/granite1fland_35.h"
                        };
                        return arrayDataGranite1fland35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayDataGranite1fland68[12] = {
                            #include "data/wildencounters/dungeons/granitecave_1f/landencounters/granite1fland_68.h"
                        };
                        return arrayDataGranite1fland68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayDataGranite1fland910[12] = {
                            #include "data/wildencounters/dungeons/granitecave_1f/landencounters/granite1fland_910.h"
                        };
                        return arrayDataGranite1fland910;
                    default:
                        static const struct Ven_WildPokemon arrayDataGranite1flanddefualt[12] = {
                            #include "data/wildencounters/dungeons/granitecave_1f/landencounters/granite1fland_910.h"
                        };
                        return arrayDataGranite1flanddefualt;
                }
            case MAP_NUM(MAP_GRANITE_CAVE_B1F):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayDatagraniteb1fland02[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b1f/landencounters/graniteb1fland_02.h"
                        };
                        return arrayDatagraniteb1fland02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayDatagraniteb1fland35[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b1f/landencounters/graniteb1fland_35.h"
                        };
                        return arrayDatagraniteb1fland35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayDatagraniteb1fland68[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b1f/landencounters/graniteb1fland_68.h"
                        };
                        return arrayDatagraniteb1fland68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayDatagraniteb1fland910[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b1f/landencounters/graniteb1fland_910.h"
                        };
                        return arrayDatagraniteb1fland910;
                    default:
                        static const struct Ven_WildPokemon arrayDatagraniteb1flanddefault[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b1f/landencounters/graniteb1fland_910.h"
                        };
                        return arrayDatagraniteb1flanddefault;
                }
            case MAP_NUM(MAP_GRANITE_CAVE_B2F):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon dataArraygraniteb2fland02[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b2f/landencounters/graniteb2fland_02.h"
                        };
                        return dataArraygraniteb2fland02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon dataArraygraniteb2fland35[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b2f/landencounters/graniteb2fland_35.h"
                        };
                        return dataArraygraniteb2fland35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon dataArraygraniteb2fland68[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b2f/landencounters/graniteb2fland_68.h"
                        };
                        return dataArraygraniteb2fland68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon dataArraygraniteb2fland910[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b2f/landencounters/graniteb2fland_910.h"
                        };
                        return dataArraygraniteb2fland910;
                    default:
                        static const struct Ven_WildPokemon dataArraygraniteb2flanddefault[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b2f/landencounters/graniteb2fland_910.h"
                        };
                        return dataArraygraniteb2flanddefault;
                }
            case MAP_NUM(MAP_NEW_MAUVILLE_INSIDE):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon newmauvileland02[12] =
                        {
                            #include "data/wildencounters/dungeons/newmauvile/landencounters/newmauvileland_02.h"
                        };
                        return newmauvileland02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon newmauvileland35[12] =
                        {
                            #include "data/wildencounters/dungeons/newmauvile/landencounters/newmauvileland_35.h"
                        };
                        return newmauvileland35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon newmauvileland68[12] =
                        {
                            #include "data/wildencounters/dungeons/newmauvile/landencounters/newmauvileland_68.h"
                        };
                        return newmauvileland68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon newmauvileland910[12] =
                        {
                            #include "data/wildencounters/dungeons/newmauvile/landencounters/newmauvileland_910.h"
                        };
                        return newmauvileland910;
                    default:
                        static const struct Ven_WildPokemon newmauvilelanddefault[12] =
                        {
                            #include "data/wildencounters/dungeons/newmauvile/landencounters/newmauvileland_910.h"
                        };
                        return newmauvilelanddefault;
                }
            case MAP_NUM(MAP_PETALBURG_HAUNTED_HOUSE):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon dataArraypetalburghouseland02[12] =
                        {
                            #include "data/wildencounters/dungeons/petalburghauntedhouse/landencounters/petalburghauntedhouseland_02.h"
                        };
                        return dataArraypetalburghouseland02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon dataArraypetalburghouseland35[12] =
                        {
                            #include "data/wildencounters/dungeons/petalburghauntedhouse/landencounters/petalburghauntedhouseland_35.h"
                        };
                        return dataArraypetalburghouseland35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon dataArraypetalburghouseland68[12] =
                        {
                            #include "data/wildencounters/dungeons/petalburghauntedhouse/landencounters/petalburghauntedhouseland_68.h"
                        };
                        return dataArraypetalburghouseland68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon dataArraypetalburghouseland910[12] =
                        {
                            #include "data/wildencounters/dungeons/petalburghauntedhouse/landencounters/petalburghauntedhouseland_910.h"
                        };
                        return dataArraypetalburghouseland910;
                    default:
                        static const struct Ven_WildPokemon dataArraypetalburghouselanddefault[12] =
                        {
                            #include "data/wildencounters/dungeons/petalburghauntedhouse/landencounters/petalburghauntedhouseland_910.h"
                        };
                        return dataArraypetalburghouselanddefault;
                    }
            case MAP_NUM(MAP_PETALBURG_WOODS):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon dataArraypetalburgwoodsland02[12] =
                        {
                            #include "data/wildencounters/dungeons/petalburgwoods/landencounters/petalburgwoodsland_02.h"
                        };
                        return dataArraypetalburgwoodsland02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon dataArraypetalburgwoodsland35[12] =
                        {
                            #include "data/wildencounters/dungeons/petalburgwoods/landencounters/petalburgwoodsland_35.h"
                        };
                        return dataArraypetalburgwoodsland35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon dataArraypetalburgwoodsland68[12] =
                        {
                            #include "data/wildencounters/dungeons/petalburgwoods/landencounters/petalburgwoodsland_68.h"
                        };
                        return dataArraypetalburgwoodsland68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon dataArraypetalburgwoodsland910[12] =
                        {
                            #include "data/wildencounters/dungeons/petalburgwoods/landencounters/petalburgwoodsland_910.h"
                        };
                        return dataArraypetalburgwoodsland910;
                    default:
                        static const struct Ven_WildPokemon dataArraypetalburgwoodslanddefualt[12] =
                        {
                            #include "data/wildencounters/dungeons/petalburgwoods/landencounters/petalburgwoodsland_910.h"
                        };
                        return dataArraypetalburgwoodslanddefualt;
                }
            case MAP_NUM(MAP_RUSTURF_TUNNEL):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon dataArrayrusturfland02[12] =
                        {
                            #include "data/wildencounters/dungeons/rusturftunnel/landencounters/rusturftunnelland_02.h"
                        };
                        return dataArrayrusturfland02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon dataArrayrusturfland35[12] =
                        {
                            #include "data/wildencounters/dungeons/rusturftunnel/landencounters/rusturftunnelland_35.h"
                        };
                        return dataArrayrusturfland35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon dataArrayrusturfland68[12] =
                        {
                            #include "data/wildencounters/dungeons/rusturftunnel/landencounters/rusturftunnelland_68.h"
                        };
                        return dataArrayrusturfland68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon dataArrayrusturfland910[12] =
                        {
                            #include "data/wildencounters/dungeons/rusturftunnel/landencounters/rusturftunnelland_910.h"
                        };
                        return dataArrayrusturfland910;
                    default:
                        static const struct Ven_WildPokemon dataArrayrusturflanddefault[12] =
                        {
                            #include "data/wildencounters/dungeons/rusturftunnel/landencounters/rusturftunnelland_910.h"
                        };
                        return dataArrayrusturflanddefault;
                }
            default:
                DebugPrintf("This encounter table hasn't been set up yet!");
                return fallbackMon;
        }
    }
    else
    {
        DebugPrintf("Bro where the fuck are you.");
        return fallbackMon; 
    }
}

struct Ven_WildPokemon Ven_GetLandEncounterMon(void)
{
    //DebugPrintf("World Level: %d", *GetVarPointer(VAR_WORLD_DIFFICULTY));
    const struct Ven_WildPokemon* encounterData = Ven_GetLandEncounterArray();
    //DebugPrintf("%d", encounterData[0].species);
    int encounterPercentile = Random() % 100;
    //DebugPrintf("encounterPercentile: %d", encounterPercentile);
    int currentBreakpoint = 0;
    enum Ability ability = GetMonAbility(&gParties[B_TRAINER_PLAYER][0]);
    bool8 canHaveAbilityInfluencedEncounter = FALSE;
    int currentAbilityPulledIndex = 0;
    int abilityPulledIndicies[12];
    int numberOfAbilityPulledMons = 0;

    static struct Ven_WildPokemon fallbackMon = 
    {
        .minLevel = 1,
        .maxLevel = 1,
        .species = SPECIES_SHINX,
        .encounterRate = 100,
    };

    if (ability == ABILITY_STATIC || ability == ABILITY_LIGHTNING_ROD)
    {
        //DebugPrintf("Lead mon has Static!");
        for (int i = 0; i <= 11; i++) //check if there are any mons that even qualify
        {
            if (IsSpeciesOfType(encounterData[i].species, TYPE_ELECTRIC))
            {
                //DebugPrintf("This pokemon is Electric type: %d", encounterData[i].species);
                abilityPulledIndicies[currentAbilityPulledIndex] = i;
                currentAbilityPulledIndex ++;
                numberOfAbilityPulledMons ++;
                canHaveAbilityInfluencedEncounter = TRUE;
            }
        }

        if (Random() % 2 == 1 && canHaveAbilityInfluencedEncounter) //passed the 50% flat check to force electric
        {
            int newTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                //DebugPrintf("Current pulled base encounter rate: %d", encounterData[abilityPulledIndicies[i]].encounterRate);
                newTotal = newTotal + encounterData[abilityPulledIndicies[i]].encounterRate;
                //DebugPrintf("Current newTotal: %d", newTotal);
            }

            float normalizationModifier = 100.0 / newTotal;
            //DebugPrintf("normalizationModifier: %d", normalizationModifier);
            int modifiedEncounterRateTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                int currentEncounterRate = encounterData[abilityPulledIndicies[i]].encounterRate * normalizationModifier;
                //DebugPrintf("Current new encounter rate: %d", currentEncounterRate);
                modifiedEncounterRateTotal = modifiedEncounterRateTotal + currentEncounterRate;
                //DebugPrintf("Current modifiedEncounterRateTotal: %d", modifiedEncounterRateTotal);
                //DebugPrintf("encounterPercentile: %d", encounterPercentile);
                //DebugPrintf("%d", modifiedEncounterRateTotal >= encounterPercentile);
                if (modifiedEncounterRateTotal >= encounterPercentile)
                {
                    //DebugPrintf("We are returning this mon!");
                    return encounterData[abilityPulledIndicies[i]];
                }
            }

            DebugPrintf("Generating encounter mon failed - Static or Lightning Rod found a applicable mon and triggered but did not return a valid output.");
            return fallbackMon;
        }
        else //standard mon generation
        {
            for (int i = 0; i <= 11; i++)
            {
                if (encounterData[i].encounterRate!= 0)
                {
                    currentBreakpoint = currentBreakpoint + encounterData[i].encounterRate;
                    //DebugPrintf("Current Breakpoint: %d", currentBreakpoint);
                    if (currentBreakpoint >= encounterPercentile)
                    {
                        //DebugPrintf("i is currently %d.", i);
                        return encounterData[i];
                    }
                }
            }
        }
    }
    else if (ability == ABILITY_MAGNET_PULL)
    {
        for (int i = 0; i <= 11; i++)
        {
            if (IsSpeciesOfType(encounterData[i].species, TYPE_STEEL))
            {
                abilityPulledIndicies[currentAbilityPulledIndex] = i;
                currentAbilityPulledIndex ++;
                numberOfAbilityPulledMons ++;
                canHaveAbilityInfluencedEncounter = TRUE;
            }
        }

        if (Random() % 2 == 1 && canHaveAbilityInfluencedEncounter)
        {
            int newTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                newTotal = newTotal + encounterData[abilityPulledIndicies[i]].encounterRate;
            }

            float normalizationModifier = 100.0 / newTotal;
            int modifiedEncounterRateTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                int currentEncounterRate = encounterData[abilityPulledIndicies[i]].encounterRate * normalizationModifier;
                modifiedEncounterRateTotal = modifiedEncounterRateTotal + currentEncounterRate;
                if (modifiedEncounterRateTotal >= encounterPercentile)
                {
                    return encounterData[abilityPulledIndicies[i]];
                }
            }

            DebugPrintf("Generating encounter mon failed - Magnet Pull found a applicable mon and triggered but did not return a valid output.");
            return fallbackMon;
        }
        else
        {
            for (int i = 0; i <= 11; i++)
            {
                if (encounterData[i].encounterRate!= 0)
                {
                    currentBreakpoint = currentBreakpoint + encounterData[i].encounterRate;
                    if (currentBreakpoint >= encounterPercentile)
                    {
                        return encounterData[i];
                    }
                }
            }
        }
    }
    else if (ability == ABILITY_FLASH_FIRE)
    {
        for (int i = 0; i <= 11; i++)
        {
            if (IsSpeciesOfType(encounterData[i].species, TYPE_FIRE))
            {
                abilityPulledIndicies[currentAbilityPulledIndex] = i;
                currentAbilityPulledIndex ++;
                numberOfAbilityPulledMons ++;
                canHaveAbilityInfluencedEncounter = TRUE;
            }
        }

        if (Random() % 2 == 1 && canHaveAbilityInfluencedEncounter)
        {
            int newTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                newTotal = newTotal + encounterData[abilityPulledIndicies[i]].encounterRate;
            }

            float normalizationModifier = 100.0 / newTotal;
            int modifiedEncounterRateTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                int currentEncounterRate = encounterData[abilityPulledIndicies[i]].encounterRate * normalizationModifier;
                modifiedEncounterRateTotal = modifiedEncounterRateTotal + currentEncounterRate;
                if (modifiedEncounterRateTotal >= encounterPercentile)
                {
                    return encounterData[abilityPulledIndicies[i]];
                }
            }

            DebugPrintf("Generating encounter mon failed - Flash Fire found a applicable mon and triggered but did not return a valid output.");
            return fallbackMon;
        }
        else
        {
            for (int i = 0; i <= 11; i++)
            {
                if (encounterData[i].encounterRate!= 0)
                {
                    currentBreakpoint = currentBreakpoint + encounterData[i].encounterRate;
                    if (currentBreakpoint >= encounterPercentile)
                    {
                        return encounterData[i];
                    }
                }
            }
        }
    }
    else if (ability == ABILITY_HARVEST)
    {
        for (int i = 0; i <= 11; i++)
        {
            if (IsSpeciesOfType(encounterData[i].species, TYPE_GRASS))
            {
                abilityPulledIndicies[currentAbilityPulledIndex] = i;
                currentAbilityPulledIndex ++;
                numberOfAbilityPulledMons ++;
                canHaveAbilityInfluencedEncounter = TRUE;
            }
        }

        if (Random() % 2 == 1 && canHaveAbilityInfluencedEncounter)
        {
            int newTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                newTotal = newTotal + encounterData[abilityPulledIndicies[i]].encounterRate;
            }

            float normalizationModifier = 100.0 / newTotal;
            int modifiedEncounterRateTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                int currentEncounterRate = encounterData[abilityPulledIndicies[i]].encounterRate * normalizationModifier;
                modifiedEncounterRateTotal = modifiedEncounterRateTotal + currentEncounterRate;
                if (modifiedEncounterRateTotal >= encounterPercentile)
                {
                    return encounterData[abilityPulledIndicies[i]];
                }
            }

            DebugPrintf("Generating encounter mon failed - Harvest found a applicable mon and triggered but did not return a valid output.");
            return fallbackMon;
        }
        else
        {
            for (int i = 0; i <= 11; i++)
            {
                if (encounterData[i].encounterRate!= 0)
                {
                    currentBreakpoint = currentBreakpoint + encounterData[i].encounterRate;
                    if (currentBreakpoint >= encounterPercentile)
                    {
                        return encounterData[i];
                    }
                }
            }
        }
    }
    else if (ABILITY_STORM_DRAIN)
    {
        for (int i = 0; i <= 11; i++)
        {
            if (IsSpeciesOfType(encounterData[i].species, TYPE_WATER))
            {
                abilityPulledIndicies[currentAbilityPulledIndex] = i;
                currentAbilityPulledIndex ++;
                numberOfAbilityPulledMons ++;
                canHaveAbilityInfluencedEncounter = TRUE;
            }
        }

        if (Random() % 2 == 1 && canHaveAbilityInfluencedEncounter)
        {
            int newTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                newTotal = newTotal + encounterData[abilityPulledIndicies[i]].encounterRate;
            }

            float normalizationModifier = 100.0 / newTotal;
            int modifiedEncounterRateTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                int currentEncounterRate = encounterData[abilityPulledIndicies[i]].encounterRate * normalizationModifier;
                modifiedEncounterRateTotal = modifiedEncounterRateTotal + currentEncounterRate;
                if (modifiedEncounterRateTotal >= encounterPercentile)
                {
                    return encounterData[abilityPulledIndicies[i]];
                }
            }

            DebugPrintf("Generating encounter mon failed - Storm Drain found a applicable mon and triggered but did not return a valid output.");
            return fallbackMon;
        }
        else
        {
            for (int i = 0; i <= 11; i++)
            {
                if (encounterData[i].encounterRate!= 0)
                {
                    currentBreakpoint = currentBreakpoint + encounterData[i].encounterRate;
                    if (currentBreakpoint >= encounterPercentile)
                    {
                        return encounterData[i];
                    }
                }
            }
        }
    }
    else
    {
        for (int i = 0; i <= 11; i++)
        {
            if (encounterData[i].encounterRate!= 0)
            {
                currentBreakpoint = currentBreakpoint + encounterData[i].encounterRate;
                //DebugPrintf("Current Breakpoint: %d", currentBreakpoint);
                if (currentBreakpoint >= encounterPercentile)
                {
                    //DebugPrintf("i is currently %d.", i);
                    return encounterData[i];
                }
            }
        }
    }

    DebugPrintf("Generating encounter mon failed - something very much went wrong in GetLandEncounterMon.");
    return fallbackMon;
}

const struct Ven_WildPokemon *Ven_GetWaterEncounterArray(void)
{
    //DebugPrintf("Helloooooo...?");
    u16 currentMapNum = gSaveBlock1Ptr->location.mapNum;

    static struct Ven_WildPokemon fallbackMon[2] = 
    {
        {
            .minLevel = 5,
            .maxLevel = 5,
            .species = SPECIES_SHINX,
            .encounterRate = 100,
        },
        {
            .minLevel = 0,
            .maxLevel = 0,
            .species = SPECIES_NONE,
            .encounterRate = 0,
        }
    };

    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_PETALBURG_CITY)) //gMapGroup_TownsAndRoutes
    {
        switch (currentMapNum)
        {
            case MAP_NUM(MAP_PETALBURG_CITY):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayDataPetalburgwater02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/petalburgcity/waterencounters/petalburgcitywater_02.h"
                        };
                        return arrayDataPetalburgwater02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayDataPetalburgwater35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/petalburgcity/waterencounters/petalburgcitywater_35.h"
                        };
                        return arrayDataPetalburgwater35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayDataPetalburgwater68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/petalburgcity/waterencounters/petalburgcitywater_68.h"
                        };
                        return arrayDataPetalburgwater68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayDataPetalburgwater910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/petalburgcity/waterencounters/petalburgcitywater_910.h"
                        };
                        return arrayDataPetalburgwater910;
                    default:
                        static const struct Ven_WildPokemon arrayDataPetalburgwaterdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/petalburgcity/waterencounters/petalburgcitywater_910.h"
                        };
                        return arrayDataPetalburgwaterdefault;
                }
            case MAP_NUM(MAP_ROUTE102):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData102water02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route102/waterencounters/route102water_02.h"
                        };
                        return arrayData102water02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData102water35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route102/waterencounters/route102water_35.h"
                        };
                        return arrayData102water35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData102water68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route102/waterencounters/route102water_68.h"
                        };
                        return arrayData102water68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData102water910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route102/waterencounters/route102water_910.h"
                        };
                        return arrayData102water910;
                    default:
                        static const struct Ven_WildPokemon arrayData102waterdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route102/waterencounters/route102water_910.h"
                        };
                        return arrayData102waterdefault;
                }
            case MAP_NUM(MAP_ROUTE103):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData103water02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route103/waterencounters/route103water_02.h"
                        };
                        return arrayData103water02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData103water35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route103/waterencounters/route103water_35.h"
                        };
                        return arrayData103water35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData103water68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route103/waterencounters/route103water_68.h"
                        };
                        return arrayData103water68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData103water910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route103/waterencounters/route103water_910.h"
                        };
                        return arrayData103water910;
                    default:
                        static const struct Ven_WildPokemon arrayData103waterdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route103/waterencounters/route103water_910.h"
                        };
                        return arrayData103waterdefault;
                }
            case MAP_NUM(MAP_ROUTE104):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData104water02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route104/waterencounters/route104water_02.h"
                        };
                        return arrayData104water02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData104water35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route104/waterencounters/route104water_35.h"
                        };
                        return arrayData104water35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData104water68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route104/waterencounters/route104water_68.h"
                        };
                        return arrayData104water68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData104water910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route104/waterencounters/route104water_910.h"
                        };
                        return arrayData104water910;
                    default:
                        static const struct Ven_WildPokemon arrayData104waterdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route104/waterencounters/route104water_910.h"
                        };
                        return arrayData104waterdefault;
                }
            case MAP_NUM(MAP_ROUTE105):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData105water02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route105/waterencounters/route105water02.h"
                        };
                        return arrayData105water02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData105water35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route105/waterencounters/route105water35.h"
                        };
                        return arrayData105water35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData105water68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route105/waterencounters/route105water68.h"
                        };
                        return arrayData105water68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData105water910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route105/waterencounters/route105water910.h"
                        };
                        return arrayData105water910;
                    default:
                        static const struct Ven_WildPokemon arrayData105waterdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route105/waterencounters/route105water910.h"
                        };
                        return arrayData105waterdefault;
                }
            case MAP_NUM(MAP_ROUTE106):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData106water02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route106/waterencounters/route106water_02.h"
                        };
                        return arrayData106water02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData106water35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route106/waterencounters/route106water_35.h"
                        };
                        return arrayData106water35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData106water68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route106/waterencounters/route106water_68.h"
                        };
                        return arrayData106water68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData106water910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route106/waterencounters/route106water_910.h"
                        };
                        return arrayData106water910;
                    default:
                        static const struct Ven_WildPokemon arrayData106waterdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route106/waterencounters/route106water_910.h"
                        };
                        return arrayData106waterdefault;
                }
            case MAP_NUM(MAP_ROUTE107):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData107water02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route107/waterencounters/route107water_02.h"
                        };
                        return arrayData107water02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData107water35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route107/waterencounters/route107water_35.h"
                        };
                        return arrayData107water35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData107water68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route107/waterencounters/route107water_68.h"
                        };
                        return arrayData107water68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData107water910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route107/waterencounters/route107water_910.h"
                        };
                        return arrayData107water910;
                    default:
                        static const struct Ven_WildPokemon arrayData107waterdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route107/waterencounters/route107water_910.h"
                        };
                        return arrayData107waterdefault;
                }
            case MAP_NUM(MAP_ROUTE108):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData108water02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route108/waterencounters/route108water_02.h"
                        };
                        return arrayData108water02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData108water35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route108/waterencounters/route108water_35.h"
                        };
                        return arrayData108water35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData108water68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route108/waterencounters/route108water_68.h"
                        };
                        return arrayData108water68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData108water910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route108/waterencounters/route108water_910.h"
                        };
                        return arrayData108water910;
                    default:
                        static const struct Ven_WildPokemon arrayData108waterdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route108/waterencounters/route108water_910.h"
                        };
                        return arrayData108waterdefault;
                }
            case MAP_NUM(MAP_ROUTE109):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData109water02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route109/waterencounters/route109water_02.h"
                        };
                        return arrayData109water02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData109water35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route109/waterencounters/route109water_35.h"
                        };
                        return arrayData109water35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData109water68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route109/waterencounters/route109water_68.h"
                        };
                        return arrayData109water68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData109water910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route109/waterencounters/route109water_910.h"
                        };
                        return arrayData109water910;
                    default:
                        static const struct Ven_WildPokemon arrayData109waterdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route109/waterencounters/route109water_910.h"
                        };
                        return arrayData109waterdefault;
                }
            case MAP_NUM(MAP_ROUTE110):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData110water02[12] = 
                        {
                            #include "data/wildencounters/townsandroutes/route110/waterencounters/route110water_02.h"
                        };
                        return arrayData110water02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData110water35[12] = {
                            #include "data/wildencounters/townsandroutes/route110/waterencounters/route110water_35.h"
                        };
                        return arrayData110water35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData110water68[12] = {
                            #include "data/wildencounters/townsandroutes/route110/waterencounters/route110water_68.h"
                        };
                        return arrayData110water68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData110water910[12] = {
                            #include "data/wildencounters/townsandroutes/route110/waterencounters/route110water_910.h"
                        };
                        return arrayData110water910;
                    default:
                        static const struct Ven_WildPokemon arrayData110waterdefault[12] = {
                            #include "data/wildencounters/townsandroutes/route110/waterencounters/route110water_910.h"
                        };
                        return arrayData110waterdefault;
                }
            case MAP_NUM(MAP_ROUTE115):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData115water02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route115/waterencounters/route115water_02.h"
                        };
                        return arrayData115water02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData115water35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route115/waterencounters/route115water_35.h"
                        };
                        return arrayData115water35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData115water68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route115/waterencounters/route115water_68.h"
                        };
                        return arrayData115water68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData115water910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route115/waterencounters/route115water_910.h"
                        };
                        return arrayData115water910;
                    default:
                        static const struct Ven_WildPokemon arrayData115waterdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route115/waterencounters/route115water_910.h"
                        };
                        return arrayData115waterdefault;
                }
            case MAP_NUM(MAP_ROUTE117):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayData117water02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route117/waterencounters/route117water_02.h"
                        };
                        return arrayData117water02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayData117water35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route117/waterencounters/route117water_35.h"
                        };
                        return arrayData117water35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayData117water68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route117/waterencounters/route117water_68.h"
                        };
                        return arrayData117water68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayData117water910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route117/waterencounters/route117water_910.h"
                        };
                        return arrayData117water910;
                    default:
                        static const struct Ven_WildPokemon arrayData117waterdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/route117/waterencounters/route117water_910.h"
                        };
                        return arrayData117waterdefault;
                }
            case MAP_NUM(MAP_SLATEPORT_CITY):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon arrayDataSlateportwater02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/slateportcity/waterencounters/slateportcitywater_02.h"
                        };
                        return arrayDataSlateportwater02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon arrayDataSlateportwater35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/slateportcity/waterencounters/slateportcitywater_35.h"
                        };
                        return arrayDataSlateportwater35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon arrayDataSlateportwater68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/slateportcity/waterencounters/slateportcitywater_68.h"
                        };
                        return arrayDataSlateportwater68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon arrayDataSlateportwater910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/slateportcity/waterencounters/slateportcitywater_910.h"
                        };
                        return arrayDataSlateportwater910;
                    default:
                        static const struct Ven_WildPokemon arrayDataSlateportwaterdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/slateportcity/waterencounters/slateportcitywater_910.h"
                        };
                        return arrayDataSlateportwaterdefault;
                }
            default:
                DebugPrintf("This encounter table hasn't been set up!");
                return fallbackMon;
        }
    }
    else if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_RUSTURF_TUNNEL)) //gMapGroup_Dungeons
    {
        switch (currentMapNum){
            case MAP_NUM(MAP_GRANITE_CAVE_1F):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon dataArrayGranite1fwater02[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_1f/waterencounters/granite1fwater_02.h"
                        };
                        return dataArrayGranite1fwater02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon dataArrayGranite1fwater35[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_1f/waterencounters/granite1fwater_35.h"
                        };
                        return dataArrayGranite1fwater35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon dataArrayGranite1fwater68[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_1f/waterencounters/granite1fwater_68.h"
                        };
                        return dataArrayGranite1fwater68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon dataArrayGranite1fwater910[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_1f/waterencounters/granite1fwater_910.h"
                        };
                        return dataArrayGranite1fwater910;
                    default:
                        static const struct Ven_WildPokemon dataArrayGranite1fwaterdefault[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_1f/waterencounters/granite1fwater_910.h"
                        };
                        return dataArrayGranite1fwaterdefault;
                }
            case MAP_NUM(MAP_GRANITE_CAVE_B1F):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon dataArraygraniteb1fwater02[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b1f/waterencounters/graniteb1fwater_02.h"
                        };
                        return dataArraygraniteb1fwater02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon dataArraygranitewaterb1f35[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b1f/waterencounters/graniteb1fwater_35.h"
                        };
                        return dataArraygranitewaterb1f35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon dataArraygraniteb1fwater68[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b1f/waterencounters/graniteb1fwater_68.h"
                        };
                        return dataArraygraniteb1fwater68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon dataArraygraniteb1fwater910[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b1f/waterencounters/graniteb1fwater_910.h"
                        };
                        return dataArraygraniteb1fwater910;
                    default:
                        static const struct Ven_WildPokemon dataArraygraniteb1fdefault[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b1f/waterencounters/graniteb1fwater_910.h"
                        };
                        return dataArraygraniteb1fdefault;
                }
            case MAP_NUM(MAP_GRANITE_CAVE_B2F):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        static const struct Ven_WildPokemon dataArraygraniteb2fwater02[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b2f/waterencounters/graniteb2fwater_02.h"
                        };
                        return dataArraygraniteb2fwater02;
                    case 3:
                    case 4:
                    case 5:
                        static const struct Ven_WildPokemon dataArraygraniteb2fwater35[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b2f/waterencounters/graniteb2fwater_35.h"
                        };
                        return dataArraygraniteb2fwater35;
                    case 6:
                    case 7:
                    case 8:
                        static const struct Ven_WildPokemon dataArraygraniteb2fwater68[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b2f/waterencounters/graniteb2fwater_68.h"
                        };
                        return dataArraygraniteb2fwater68;
                    case 9:
                    case 10:
                        static const struct Ven_WildPokemon dataArraygraniteb2fwater910[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b2f/waterencounters/graniteb2fwater_910.h"
                        };
                        return dataArraygraniteb2fwater910;
                    default:
                        static const struct Ven_WildPokemon dataArraygraniteb2fwaterdefault[12] =
                        {
                            #include "data/wildencounters/dungeons/granitecave_b2f/waterencounters/graniteb2fwater_910.h"
                        };
                        return dataArraygraniteb2fwaterdefault;
                }
            default:
                DebugPrintf("This encounter table hasn't been set up!");
                return fallbackMon;
        }
    }
    else
    {
        DebugPrintf("Bro where the fuck are you.");
        return fallbackMon; 
    }
}

struct Ven_WildPokemon Ven_GetWaterEncounterMon(void)
{
    //DebugPrintf("World Level: %d", *GetVarPointer(VAR_WORLD_DIFFICULTY));
    const struct Ven_WildPokemon* encounterData = Ven_GetWaterEncounterArray();
    //DebugPrintf("%d", encounterData[0].species);
    int encounterPercentile = Random() % 100;
    //DebugPrintf("encounterPercentile: %d", encounterPercentile);
    int currentBreakpoint = 0;
    enum Ability ability = GetMonAbility(&gParties[B_TRAINER_PLAYER][0]);
    bool8 canHaveAbilityInfluencedEncounter = FALSE;
    int currentAbilityPulledIndex = 0;
    int abilityPulledIndicies[12];
    int numberOfAbilityPulledMons = 0;

    static struct Ven_WildPokemon fallbackMon = 
    {
        .minLevel = 1,
        .maxLevel = 1,
        .species = SPECIES_SHINX,
        .encounterRate = 100,
    };

    if (ability == ABILITY_STATIC || ability == ABILITY_LIGHTNING_ROD)
    {
        //DebugPrintf("Lead mon has Static!");
        for (int i = 0; i <= 11; i++) //check if there are any mons that even qualify
        {
            if (IsSpeciesOfType(encounterData[i].species, TYPE_ELECTRIC))
            {
                //DebugPrintf("This pokemon is Electric type: %d", encounterData[i].species);
                abilityPulledIndicies[currentAbilityPulledIndex] = i;
                currentAbilityPulledIndex ++;
                numberOfAbilityPulledMons ++;
                canHaveAbilityInfluencedEncounter = TRUE;
            }
        }

        if (Random() % 2 == 1 && canHaveAbilityInfluencedEncounter) //passed the 50% flat check to force electric
        {
            int newTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                //DebugPrintf("Current pulled base encounter rate: %d", encounterData[abilityPulledIndicies[i]].encounterRate);
                newTotal = newTotal + encounterData[abilityPulledIndicies[i]].encounterRate;
                //DebugPrintf("Current newTotal: %d", newTotal);
            }

            float normalizationModifier = 100.0 / newTotal;
            //DebugPrintf("normalizationModifier: %d", normalizationModifier);
            int modifiedEncounterRateTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                int currentEncounterRate = encounterData[abilityPulledIndicies[i]].encounterRate * normalizationModifier;
                //DebugPrintf("Current new encounter rate: %d", currentEncounterRate);
                modifiedEncounterRateTotal = modifiedEncounterRateTotal + currentEncounterRate;
                //DebugPrintf("Current modifiedEncounterRateTotal: %d", modifiedEncounterRateTotal);
                //DebugPrintf("encounterPercentile: %d", encounterPercentile);
                //DebugPrintf("%d", modifiedEncounterRateTotal >= encounterPercentile);
                if (modifiedEncounterRateTotal >= encounterPercentile)
                {
                    //DebugPrintf("We are returning this mon!");
                    return encounterData[abilityPulledIndicies[i]];
                }
            }

            DebugPrintf("Generating encounter mon failed - Static or Lightning Rod found a applicable mon and triggered but did not return a valid output.");
            return fallbackMon;
        }
        else //standard mon generation
        {
            for (int i = 0; i <= 11; i++)
            {
                if (encounterData[i].encounterRate!= 0)
                {
                    currentBreakpoint = currentBreakpoint + encounterData[i].encounterRate;
                    //DebugPrintf("Current Breakpoint: %d", currentBreakpoint);
                    if (currentBreakpoint >= encounterPercentile)
                    {
                        //DebugPrintf("i is currently %d.", i);
                        return encounterData[i];
                    }
                }
            }
        }
    }
    else if (ability == ABILITY_MAGNET_PULL)
    {
        for (int i = 0; i <= 11; i++)
        {
            if (IsSpeciesOfType(encounterData[i].species, TYPE_STEEL))
            {
                abilityPulledIndicies[currentAbilityPulledIndex] = i;
                currentAbilityPulledIndex ++;
                numberOfAbilityPulledMons ++;
                canHaveAbilityInfluencedEncounter = TRUE;
            }
        }

        if (Random() % 2 == 1 && canHaveAbilityInfluencedEncounter)
        {
            int newTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                newTotal = newTotal + encounterData[abilityPulledIndicies[i]].encounterRate;
            }

            float normalizationModifier = 100.0 / newTotal;
            int modifiedEncounterRateTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                int currentEncounterRate = encounterData[abilityPulledIndicies[i]].encounterRate * normalizationModifier;
                modifiedEncounterRateTotal = modifiedEncounterRateTotal + currentEncounterRate;
                if (modifiedEncounterRateTotal >= encounterPercentile)
                {
                    return encounterData[abilityPulledIndicies[i]];
                }
            }

            DebugPrintf("Generating encounter mon failed - Magnet Pull found a applicable mon and triggered but did not return a valid output.");
            return fallbackMon;
        }
        else
        {
            for (int i = 0; i <= 11; i++)
            {
                if (encounterData[i].encounterRate!= 0)
                {
                    currentBreakpoint = currentBreakpoint + encounterData[i].encounterRate;
                    if (currentBreakpoint >= encounterPercentile)
                    {
                        return encounterData[i];
                    }
                }
            }
        }
    }
    else if (ability == ABILITY_FLASH_FIRE)
    {
        for (int i = 0; i <= 11; i++)
        {
            if (IsSpeciesOfType(encounterData[i].species, TYPE_FIRE))
            {
                abilityPulledIndicies[currentAbilityPulledIndex] = i;
                currentAbilityPulledIndex ++;
                numberOfAbilityPulledMons ++;
                canHaveAbilityInfluencedEncounter = TRUE;
            }
        }

        if (Random() % 2 == 1 && canHaveAbilityInfluencedEncounter)
        {
            int newTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                newTotal = newTotal + encounterData[abilityPulledIndicies[i]].encounterRate;
            }

            float normalizationModifier = 100.0 / newTotal;
            int modifiedEncounterRateTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                int currentEncounterRate = encounterData[abilityPulledIndicies[i]].encounterRate * normalizationModifier;
                modifiedEncounterRateTotal = modifiedEncounterRateTotal + currentEncounterRate;
                if (modifiedEncounterRateTotal >= encounterPercentile)
                {
                    return encounterData[abilityPulledIndicies[i]];
                }
            }

            DebugPrintf("Generating encounter mon failed - Flash Fire found a applicable mon and triggered but did not return a valid output.");
            return fallbackMon;
        }
        else
        {
            for (int i = 0; i <= 11; i++)
            {
                if (encounterData[i].encounterRate!= 0)
                {
                    currentBreakpoint = currentBreakpoint + encounterData[i].encounterRate;
                    if (currentBreakpoint >= encounterPercentile)
                    {
                        return encounterData[i];
                    }
                }
            }
        }
    }
    else if (ability == ABILITY_HARVEST)
    {
        for (int i = 0; i <= 11; i++)
        {
            if (IsSpeciesOfType(encounterData[i].species, TYPE_GRASS))
            {
                abilityPulledIndicies[currentAbilityPulledIndex] = i;
                currentAbilityPulledIndex ++;
                numberOfAbilityPulledMons ++;
                canHaveAbilityInfluencedEncounter = TRUE;
            }
        }

        if (Random() % 2 == 1 && canHaveAbilityInfluencedEncounter)
        {
            int newTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                newTotal = newTotal + encounterData[abilityPulledIndicies[i]].encounterRate;
            }

            float normalizationModifier = 100.0 / newTotal;
            int modifiedEncounterRateTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                int currentEncounterRate = encounterData[abilityPulledIndicies[i]].encounterRate * normalizationModifier;
                modifiedEncounterRateTotal = modifiedEncounterRateTotal + currentEncounterRate;
                if (modifiedEncounterRateTotal >= encounterPercentile)
                {
                    return encounterData[abilityPulledIndicies[i]];
                }
            }

            DebugPrintf("Generating encounter mon failed - Harvest found a applicable mon and triggered but did not return a valid output.");
            return fallbackMon;
        }
        else
        {
            for (int i = 0; i <= 11; i++)
            {
                if (encounterData[i].encounterRate!= 0)
                {
                    currentBreakpoint = currentBreakpoint + encounterData[i].encounterRate;
                    if (currentBreakpoint >= encounterPercentile)
                    {
                        return encounterData[i];
                    }
                }
            }
        }
    }
    else if (ABILITY_STORM_DRAIN)
    {
        for (int i = 0; i <= 11; i++)
        {
            if (IsSpeciesOfType(encounterData[i].species, TYPE_WATER))
            {
                abilityPulledIndicies[currentAbilityPulledIndex] = i;
                currentAbilityPulledIndex ++;
                numberOfAbilityPulledMons ++;
                canHaveAbilityInfluencedEncounter = TRUE;
            }
        }

        if (Random() % 2 == 1 && canHaveAbilityInfluencedEncounter)
        {
            int newTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                newTotal = newTotal + encounterData[abilityPulledIndicies[i]].encounterRate;
            }

            float normalizationModifier = 100.0 / newTotal;
            int modifiedEncounterRateTotal = 0;
            for (int i = 0; i < numberOfAbilityPulledMons; i++)
            {
                int currentEncounterRate = encounterData[abilityPulledIndicies[i]].encounterRate * normalizationModifier;
                modifiedEncounterRateTotal = modifiedEncounterRateTotal + currentEncounterRate;
                if (modifiedEncounterRateTotal >= encounterPercentile)
                {
                    return encounterData[abilityPulledIndicies[i]];
                }
            }

            DebugPrintf("Generating encounter mon failed - Storm Drain found a applicable mon and triggered but did not return a valid output.");
            return fallbackMon;
        }
        else
        {
            for (int i = 0; i <= 11; i++)
            {
                if (encounterData[i].encounterRate!= 0)
                {
                    currentBreakpoint = currentBreakpoint + encounterData[i].encounterRate;
                    if (currentBreakpoint >= encounterPercentile)
                    {
                        return encounterData[i];
                    }
                }
            }
        }
    }
    else
    {
        for (int i = 0; i <= 11; i++)
        {
            if (encounterData[i].encounterRate!= 0)
            {
                currentBreakpoint = currentBreakpoint + encounterData[i].encounterRate;
                //DebugPrintf("Current Breakpoint: %d", currentBreakpoint);
                if (currentBreakpoint >= encounterPercentile)
                {
                    //DebugPrintf("i is currently %d.", i);
                    return encounterData[i];
                }
            }
        }
    }

    DebugPrintf("Generating encounter mon failed - something very much went wrong in GetLandEncounterMon.");
    return fallbackMon;
}