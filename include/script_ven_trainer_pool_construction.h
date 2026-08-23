#ifndef GUARD_SCRIPT_VEN_TRAINER_POOL_CONSTRUCTION_H
#define GUARD_SCRIPT_VEN_TRAINER_POOL_CONSTRUCTION_H

const struct TrainerMon *CombinePools(const struct Trainer *trainer);
int GetClassPoolSize(const enum TrainerClassID trainerClass);
int GetRoutePoolSize(const enum TrainerUnlockedAt unlockedAt);

#endif // GUARD_SCRIPT_VEN_TRAINER_POOL_CONSTRUCTION_H
