#include "rtc.h"
#include "constants/species.h"
#include "random.h"
#include "malloc.h"
#include "event_data.h"
#include "constants/abilities.h"
#include "pokemon.h"

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
    struct Ven_WildPokemon* currentArray = Alloc(sizeof(struct Ven_WildPokemon) * 12);
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

    if (ability == ABILITY_STATIC)
    {
        DebugPrintf("Lead mon has Static!");
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
            //DebugPrintf("Static is influencing this encounter...");
            int newBreakpoint = (Random() % 100) / numberOfAbilityPulledMons + 1;
            //DebugPrintf("newBreakpoint: %d", newBreakpoint);
            //DebugPrintf("numberOfAbilityPulledMons: %d", numberOfAbilityPulledMons);
            //DebugPrintf("encounterPercentile: %d", encounterPercentile);
            for (int i = 0; i <= numberOfAbilityPulledMons; i++)
            {
                //DebugPrintf("breakpoint if check: %d", newBreakpoint * (i + 1));
                if (newBreakpoint * (i + 1) >= encounterPercentile)
                {
                    //DebugPrintf("Yippee!!");
                    return encounterData[abilityPulledIndicies[i]];
                }
            }
            DebugPrintf("Generating encounter mon failed - Static found a applicable mon and triggered but did not return a valid output.");
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