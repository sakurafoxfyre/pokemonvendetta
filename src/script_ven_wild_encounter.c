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
            case MAP_NUM(MAP_HAUNTWOOD):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        const struct Ven_WildPokemon arrayDataHauntwoodland02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/hauntwood/landencounters/hauntwoodland_02.h"
                        };
                        memcpy(currentArray, arrayDataHauntwoodland02, sizeof(arrayDataHauntwoodland02));
                        return currentArray;
                    case 3:
                    case 4:
                    case 5:
                        const struct Ven_WildPokemon arrayDataHauntwoodland35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/hauntwood/landencounters/hauntwoodland_35.h"
                        };
                        memcpy(currentArray, arrayDataHauntwoodland35, sizeof(arrayDataHauntwoodland35));
                        return currentArray;
                    case 6:
                    case 7:
                    case 8:
                        const struct Ven_WildPokemon arrayDataHauntwoodland68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/hauntwood/landencounters/hauntwoodland_68.h"
                        };
                        memcpy(currentArray, arrayDataHauntwoodland68, sizeof(arrayDataHauntwoodland68));
                        return currentArray;
                    case 9:
                    case 10:
                        const struct Ven_WildPokemon arrayDataHauntwoodland910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/hauntwood/landencounters/hauntwood_land_910.h"
                        };
                        memcpy(currentArray, arrayDataHauntwoodland910, sizeof(arrayDataHauntwoodland910));
                        return currentArray;
                    default:
                        const struct Ven_WildPokemon arrayDataHauntwoodlanddefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/hauntwood/landencounters/hauntwood_land_910.h"
                        };
                        memcpy(currentArray, arrayDataHauntwoodlanddefault, sizeof(arrayDataHauntwoodlanddefault));
                        return currentArray;
                }
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
    else if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_RUSTURF_TUNNEL)) //gMapGroup_Dungeons
    {

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
            case MAP_NUM(MAP_PETALBURG_CITY):
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY))
                {
                    case 0:
                    case 1:
                    case 2:
                        const struct Ven_WildPokemon arrayDataPetalburgwater02[12] =
                        {
                            #include "data/wildencounters/townsandroutes/petalburgcity/waterencounters/petalburgcitywater_02.h"
                        };
                        memcpy(currentArray, arrayDataPetalburgwater02, sizeof(arrayDataPetalburgwater02));
                        return currentArray;
                    case 3:
                    case 4:
                    case 5:
                        const struct Ven_WildPokemon arrayDataPetalburgwater35[12] =
                        {
                            #include "data/wildencounters/townsandroutes/petalburgcity/waterencounters/petalburgcitywater_35.h"
                        };
                        memcpy(currentArray, arrayDataPetalburgwater35, sizeof(arrayDataPetalburgwater35));
                        return currentArray;
                    case 6:
                    case 7:
                    case 8:
                        const struct Ven_WildPokemon arrayDataPetalburgwater68[12] =
                        {
                            #include "data/wildencounters/townsandroutes/petalburgcity/waterencounters/petalburgcitywater_68.h"
                        };
                        memcpy(currentArray, arrayDataPetalburgwater68, sizeof(arrayDataPetalburgwater68));
                        return currentArray;
                    case 9:
                    case 10:
                        const struct Ven_WildPokemon arrayDataPetalburgwater910[12] =
                        {
                            #include "data/wildencounters/townsandroutes/petalburgcity/waterencounters/petalburgcitywater_910.h"
                        };
                        memcpy(currentArray, arrayDataPetalburgwater910, sizeof(arrayDataPetalburgwater910));
                        return currentArray;
                    default:
                        const struct Ven_WildPokemon arrayDataPetalburgwaterdefault[12] =
                        {
                            #include "data/wildencounters/townsandroutes/petalburgcity/waterencounters/petalburgcitywater_910.h"
                        };
                        memcpy(currentArray, arrayDataPetalburgwaterdefault, sizeof(arrayDataPetalburgwaterdefault));
                        return currentArray;
                }
            case MAP_NUM(MAP_SLATEPORT_CITY):
                
            case MAP_NUM(MAP_ROUTE110):
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
    else if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_RUSTURF_TUNNEL)) //gMapGroup_Dungeons
    {
        
    }
    else
    {
        DebugPrintf("This encounter table hasn't been set up!");
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