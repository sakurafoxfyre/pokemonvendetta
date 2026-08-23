#include "global.h"
#include "constants/vars.h"
#include "event_data.h"
#include "data.h"

void IncrementPlayerKeys(void)
{
    u16 i;
    i = *GetVarPointer(VAR_NUMBER_OF_KEYS);
    i += 1;
    VarSet(VAR_NUMBER_OF_KEYS, i);

};

void DecrementPlayerKeys(void)
{

    u16 i;
    i = *GetVarPointer(VAR_NUMBER_OF_KEYS);
    i -= 1;
    VarSet(VAR_NUMBER_OF_KEYS, i);

};

void IncrementWorldLevel(void)
{
    u16 i;
    i = *GetVarPointer(VAR_WORLD_DIFFICULTY);
    i += 1;
    VarSet(VAR_WORLD_DIFFICULTY, i);

};

void RollBossParties(void)
{

};
