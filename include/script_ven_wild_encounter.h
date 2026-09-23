#ifndef GUARD_SCRIPT_VEN_WILD_ENCOUNTER_H
#define GUARD_SCRIPT_VEN_WILD_ENCOUNTER_H

#include "rtc.h"

struct Ven_WildPokemon
{
    u8 minLevel;
    u8 maxLevel;
    enum Species species;
    u8 encounterRate;
};

struct Ven_WildPokemon *Ven_GetLandEncounterArray(void);
const struct Ven_WildPokemon Ven_GetLandEncounterMon(void);

#endif //GUARD_SCRIPT_EVEN_WILD_ENCOUNTER_H