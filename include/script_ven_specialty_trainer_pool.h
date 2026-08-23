#ifndef GUARD_SCRIPT_VEN_SPECIALTY_TRAINER_POOL_H
#define GUARD_SCRIPT_VEN_SPECIALTY_TRAINER_POOL_H

int GetPooledSpecialtyTrainerPoolLength(const enum TrainerClassID trainerClass);
bool8 IsThisTrainerPooled(const enum TrainerClassID trainerClass);
const struct TrainerMon *SpecialtyPool(const struct Trainer *trainer);

#endif // GUARD_SCRIPT_VEN_SPECIALTY_TRAINER_POOL_H