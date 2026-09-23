#include "rtc.h"
#include "constants/species.h"
#include "random.h"
#include "malloc.h"
#include "event_data.h"

struct Ven_WildPokemon
{
    u8 minLevel;
    u8 maxLevel;
    enum Species species;
    u8 encounterRate;
};

const struct Ven_WildPokemon *Ven_GetLandEncounterArray(void)
{
    DebugPrintf("Helloooooo...?");
    struct Ven_WildPokemon* currentArray = Alloc(sizeof(struct Ven_WildPokemon) * 12);
    u16 currentMapNum = gSaveBlock1Ptr->location.mapNum;

    static struct Ven_WildPokemon fallbackMon[1] = 
    {
        {
            .minLevel = 5,
            .maxLevel = 5,
            .species = SPECIES_SHINX,
            .encounterRate = 100,
        }
    };

    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_PETALBURG_CITY)) //gMapGroup_TownsAndRoutes
    {
        switch (currentMapNum)
        {
            case MAP_NUM(MAP_ROUTE110): //Route 110
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        const struct Ven_WildPokemon arrayData110land02[12] = 
                        {
                            #include "data/wildencounters/townsandroutes/route110/landencounters/route110land_02.h"
                        };
                        memcpy(currentArray, arrayData110land02, sizeof(arrayData110land02));
                        return currentArray;
                    case 3:
                    case 4:
                    case 5:
                        const struct Ven_WildPokemon arrayData110land35[12] = {
                            #include "data/wildencounters/townsandroutes/route110/landencounters/route110land_35.h"
                        };
                        memcpy(currentArray, arrayData110land35, sizeof(arrayData110land35));
                        return currentArray;
                    case 6:
                    case 7:
                    case 8:
                        const struct Ven_WildPokemon arrayData110land68[12] = {
                            #include "data/wildencounters/townsandroutes/route110/landencounters/route110land_68.h"
                        };
                        memcpy(currentArray, arrayData110land68, sizeof(arrayData110land68));
                        return currentArray;
                    case 9:
                    case 10:
                        const struct Ven_WildPokemon arrayData110land910[12] = {
                            #include "data/wildencounters/townsandroutes/route110/landencounters/route110land_910.h"
                        };
                        memcpy(currentArray, arrayData110land910, sizeof(arrayData110land910));
                        return currentArray;
                    default:
                        const struct Ven_WildPokemon arrayDatadefault[12] = {
                            #include "data/wildencounters/townsandroutes/route110/landencounters/route110land_910.h"
                        };
                        memcpy(currentArray, arrayDatadefault, sizeof(arrayDatadefault));
                        return currentArray;
                }
            default:
                DebugPrintf("This encounter table hasn't been set up!");
                return fallbackMon;
        }
    }
    else
    {
        DebugPrintf("This encounter table hasn't been set up!");
        return fallbackMon; 
    }
}

struct Ven_WildPokemon Ven_GetLandEncounterMon(void)
{
    DebugPrintf("World Level: %d", *GetVarPointer(VAR_WORLD_DIFFICULTY));
    const struct Ven_WildPokemon* encounterData = Ven_GetLandEncounterArray();
    DebugPrintf("%d", encounterData[0].species);
    int encounterPercentile = Random() % 100;
    int breakpointArray[12];
    int currentBreakpoint = 0;
    int arrayIndex = 0;

    for (int i = 0; i >= 11; i++)
    {
        if (encounterData[i].species != 0)
        {
            DebugPrintf("encounterData[i] has data!");
            currentBreakpoint = currentBreakpoint + encounterData[i].encounterRate;
            breakpointArray[i] = currentBreakpoint;
        }
        else
        {
            break;
        }
    };

    for (int i = 0; i >= 11; i++)
    {
        if (encounterPercentile >= breakpointArray[i])
        {
            arrayIndex = i;
            DebugPrintf("encounterPercentile: %d", encounterPercentile);
        }
    }

    DebugPrintf("arrayIndex is %d", arrayIndex);
    return encounterData[arrayIndex];

    //get map group(folder) and map num(actual map) gSaveBlock1Ptr->location.mapGroup/Num
    //need to switch based on location
    //need to check world level
    //include given file (similar to how trainer pools are included)
    //get the encounter chances/ranges
    // -> array of breakpoints? (ie 10% and 10% would make breakpoints 10, 20 (bc exclusive at the top, counting from 0))
    // -> rand % 100
    // -> find what breakpoint that falls in
    // -> figure out what pokemon that corresponds with
    // -> return that 
    // -> return format will be {min level, max level, SPECIES}
    // so files will be const struct WildPokemon *someAreaLandWilds = [ {mon} ]
    // so then breakpoint indexes for the array of breakpoints will match their indx in the someAreaWilds array
    // ie if we are in breakpoint area 1 (bc we count from 0), then someAreaLandWilds[1] will be the mon we want
    // since this will be a "similar" set up to the class/route pools, we will need alice to provide the exact array sizes...
    // if we do sizeOf(someAreaLandWilds) / sizeOf(WildPokemon) = array length...
    // so we do a supplementary function that returns the specific array we need, and then we use the return of that here
    // and do all the magic here which then returns the actual wild mon encounter to the function over in the other file?
    // the main issue is the whole size thing... since there might be different amounts of enconters...
    // so we lock a max amount, do the "check how many of these are actually there lmao", and go from there
    // we'll need some extra work to account for abilities that attract other...
    // there's a bunch of other stuff it looks like, but we'll start small and work our way up
    // stuff to keep in mind
    // different rods (old, good, super)
    // rock smash
    // surf
    // sweet scent (probably just uses the other calls??????)
    // there's going to be a lot of incremental testing here rip
    // 0-2, 3-5, 6-8, 9-11
    // 12 max for each type
}