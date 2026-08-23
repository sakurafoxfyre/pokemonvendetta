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

// pool length variables
// gym leaders
const int roxanne04length = 12;
const int roxanne58length = 12;
const int roxanne910length = 12;
const int brawly04length = 8;
const int brawly58length = 11;
const int brawly910length = 11;
const int wally04length = 11;
const int wally58length = 11;
const int wally910length = 11;
const int flannery04length = 10;
const int flannery58length = 15;
const int flannery910length = 15;
const int may04length = 11;
const int may58length = 11;
const int may910length = 11;
const int gymtate04length = 1;
const int gymtate58length = 1;
const int gymtate910length = 1;
const int gymliza04length = 12;
const int gymliza58length = 14;
const int gymliza910length = 14;
const int wallace04length = 1;
const int wallace58length = 1;
const int wallace910length = 1;
const int zinnia04length = 16;
const int zinnia58length = 16;
const int zinnia910length = 16;

//team leaders
const int archie04length = 1;
const int archie58length = 1;
const int archie910length = 1;
const int courtney04length = 1;
const int courtney58length = 1;
const int courtney910length = 1;
const int cerise04length = 1;
const int cerise58length = 1;
const int cerise910length = 1;

//e4
const int phoebepoollength = 1;
const int normanpoollength = 1;
const int e4tatepoollength = 1;
const int e4lizapoollength = 1;
const int brendanpoollength = 1;
const int stevenpoollength = 1;

//structs
//gym leaders
const struct TrainerMon GymParty_RoxanneAces04[3] =
{
    #include "data/specialtytrainers/anchorbosses/roxanne/roxanneaces04.h"
};
const struct TrainerMon GymParty_Roxanne04[12] =
{
    #include "data/specialtytrainers/anchorbosses/roxanne/roxannepool04.h"
};
const struct TrainerMon GymParty_RoxanneAces58[3] =
{
    #include "data/specialtytrainers/anchorbosses/roxanne/roxanneaces58.h"
};
const struct TrainerMon GymParty_Roxanne58[12] =
{
    #include "data/specialtytrainers/anchorbosses/roxanne/roxannepool58.h"
};
const struct TrainerMon GymParty_RoxanneAces910[3] =
{
    #include "data/specialtytrainers/anchorbosses/roxanne/roxxaneaces910.h"
};
const struct TrainerMon GymParty_Roxanne910[12] =
{
    #include "data/specialtytrainers/anchorbosses/roxanne/roxannepool910.h"
};

const struct TrainerMon GymParty_BrawlyAces04[3] =
{
    #include "data/specialtytrainers/anchorbosses/brawly/brawlyaces04.h"
};
const struct TrainerMon GymParty_Brawly04[8] = 
{
    #include "data/specialtytrainers/anchorbosses/brawly/brawlypool04.h"
};
const struct TrainerMon GymParty_BrawlyAces58[3] = 
{
    #include "data/specialtytrainers/anchorbosses/brawly/brawlyaces58.h"
};
const struct TrainerMon GymParty_Brawly58[11] =
{
    #include "data/specialtytrainers/anchorbosses/brawly/brawlypool58.h"
};
const struct TrainerMon GymParty_BrawlyAces910[3] =
{
    #include "data/specialtytrainers/anchorbosses/brawly/brawlyaces910.h"
};
const struct TrainerMon GymParty_Brawly910[11] =
{
    #include "data/specialtytrainers/anchorbosses/brawly/brawlypool910.h"
};

const struct TrainerMon GymParty_WallyAces04[3] =
{
    #include "data/specialtytrainers/anchorbosses/wally/wallyaces04.h"
};
const struct TrainerMon GymParty_Wally04[11] =
{
    #include "data/specialtytrainers/anchorbosses/wally/wallypool04.h"
};
const struct TrainerMon GymParty_WallyAces58[3] =
{
    #include "data/specialtytrainers/anchorbosses/wally/wallyaces58.h"
};
const struct TrainerMon GymParty_Wally58[11] =
{
    #include "data/specialtytrainers/anchorbosses/wally/wallypool58.h"
};
const struct TrainerMon GymParty_WallyAces910[3] =
{
    #include "data/specialtytrainers/anchorbosses/wally/wallyaces910.h"
};
const struct TrainerMon GymParty_Wally910[11] =
{
    #include "data/specialtytrainers/anchorbosses/wally/wallypool910.h"
};

const struct TrainerMon GymParty_FlanneryAces04[3] =
{
    #include "data/specialtytrainers/anchorbosses/flannery/flanneryaces04.h"
};
const struct TrainerMon GymParty_Flannery04[10] =
{
    #include "data/specialtytrainers/anchorbosses/flannery/flannerypool04.h"
};
const struct TrainerMon GymParty_FlanneryAces58[3] =
{
    #include "data/specialtytrainers/anchorbosses/flannery/flanneryaces58.h"
};
const struct TrainerMon GymParty_Flannery58[15] =
{
    #include "data/specialtytrainers/anchorbosses/flannery/flannerypool58.h"
};
const struct TrainerMon GymParty_FlanneryAces910[3] =
{
    #include "data/specialtytrainers/anchorbosses/flannery/flanneryaces910.h"
};
const struct TrainerMon GymParty_Flannery910[15] =
{
    #include "data/specialtytrainers/anchorbosses/flannery/flannerypool910.h"
};

const struct TrainerMon GymParty_MayAces04[3] =
{
    #include "data/specialtytrainers/anchorbosses/may/mayaces04.h"
};
const struct TrainerMon GymParty_May04[11] =
{
    #include "data/specialtytrainers/anchorbosses/may/maypool04.h"
};
const struct TrainerMon GymParty_MayAces58[3] =
{
    #include "data/specialtytrainers/anchorbosses/may/mayaces58.h"
};
const struct TrainerMon GymParty_May58[11] =
{
    #include "data/specialtytrainers/anchorbosses/may/maypool58.h"
};
const struct TrainerMon GymParty_MayAces910[3] =
{
    #include "data/specialtytrainers/anchorbosses/may/mayaces910.h"
};
const struct TrainerMon GymParty_May910[11] =
{
    #include "data/specialtytrainers/anchorbosses/may/maypool910.h"
};

const struct TrainerMon GymParty_GymTateAces04[3] =
{
    #include "data/specialtytrainers/anchorbosses/tategym/tategymaces04.h"
};
const struct TrainerMon GymParty_GymTate04[1] =
{
    #include "data/specialtytrainers/anchorbosses/tategym/tategym04.h"
};
const struct TrainerMon GymParty_GymTateAces58[3] =
{
    #include "data/specialtytrainers/anchorbosses/tategym/tategymaces58.h"
};
const struct TrainerMon GymParty_GymTate58[1] =
{
    #include "data/specialtytrainers/anchorbosses/tategym/tategym58.h"
};
const struct TrainerMon GymParty_GymTateAces910[3] =
{
    #include "data/specialtytrainers/anchorbosses/tategym/tategymaces910.h"
};
const struct TrainerMon GymParty_GymTate910[1] =
{
    #include "data/specialtytrainers/anchorbosses/tategym/tategym910.h"
};

const struct TrainerMon GymParty_GymLizaAces04[3] =
{
    #include "data/specialtytrainers/anchorbosses/lizagym/lizagymaces04.h"
};
const struct TrainerMon GymParty_GymLiza04[12] =
{
    #include "data/specialtytrainers/anchorbosses/lizagym/lizagym04.h"
};
const struct TrainerMon GymParty_GymLizaAces58[3] =
{
    #include "data/specialtytrainers/anchorbosses/lizagym/lizagymaces58.h"
};
const struct TrainerMon GymParty_GymLiza58[14] =
{
    #include "data/specialtytrainers/anchorbosses/lizagym/lizagym58.h"
};
const struct TrainerMon GymParty_GymLizaAces910[3] =
{
    #include "data/specialtytrainers/anchorbosses/lizagym/lizagymaces910.h"
};
const struct TrainerMon GymParty_GymLiza910[14] =
{
    #include "data/specialtytrainers/anchorbosses/lizagym/lizagym910.h"
};

const struct TrainerMon GymParty_WallaceAces04[3] =
{
    #include "data/specialtytrainers/anchorbosses/wallace/wallaceaces04.h"
};
const struct TrainerMon GymParty_Wallace04[1] =
{
    #include "data/specialtytrainers/anchorbosses/wallace/wallacepool04.h"
};
const struct TrainerMon GymParty_WallaceAces58[3] =
{
    #include "data/specialtytrainers/anchorbosses/wallace/wallaceaces58.h"
};
const struct TrainerMon GymParty_Wallace58[1] =
{
    #include "data/specialtytrainers/anchorbosses/wallace/wallacepool58.h"
};
const struct TrainerMon GymParty_WallaceAces910[3] =
{
    #include "data/specialtytrainers/anchorbosses/wallace/wallaceaces910.h"
};
const struct TrainerMon GymParty_Wallace910[1] =
{
    #include "data/specialtytrainers/anchorbosses/wallace/wallacepool910.h"
};

const struct TrainerMon GymParty_ZinniaAces04[3] =
{
    #include "data/specialtytrainers/anchorbosses/zinnia/zinniaaces04.h"
};
const struct TrainerMon GymParty_Zinnia04[16] =
{
    #include "data/specialtytrainers/anchorbosses/zinnia/zinniapool04.h"
};
const struct TrainerMon GymParty_ZinniaAces58[3] =
{
    #include "data/specialtytrainers/anchorbosses/zinnia/zinniaaces58.h"
};
const struct TrainerMon GymParty_Zinnia58[16] =
{
    #include "data/specialtytrainers/anchorbosses/zinnia/zinniapool58.h"
};
const struct TrainerMon GymParty_ZinniaAces910[3] =
{
    #include "data/specialtytrainers/anchorbosses/zinnia/zinniaaces910.h"
};
const struct TrainerMon GymParty_Zinnia910[16] =
{
    #include "data/specialtytrainers/anchorbosses/zinnia/zinniapool910.h"
};

//team leaders
const struct TrainerMon LeaderParty_ArchieAces04[3] =
{
    #include "data/specialtytrainers/anchorbosses/archie/archieaces04.h"
};
const struct TrainerMon LeaderParty_Archie04[1] =
{
    #include "data/specialtytrainers/anchorbosses/archie/archiepool04.h"
};
const struct TrainerMon LeaderParty_ArchieAces58[3] =
{
    #include "data/specialtytrainers/anchorbosses/archie/archieaces58.h"
};
const struct TrainerMon LeaderParty_Archie58[1] =
{
    #include "data/specialtytrainers/anchorbosses/archie/archiepool58.h"
};
const struct TrainerMon LeaderParty_ArchieAces910[3] =
{
    #include "data/specialtytrainers/anchorbosses/archie/archieaces910.h"
};
const struct TrainerMon LeaderParty_Archie910[1] =
{
    #include "data/specialtytrainers/anchorbosses/archie/archiepool910.h"
};

const struct TrainerMon LeaderParty_CourtneyAces04[3] =
{
    #include "data/specialtytrainers/anchorbosses/courtney/courtneyaces04.h"
};
const struct TrainerMon LeaderParty_Courtney04[1] =
{
    #include "data/specialtytrainers/anchorbosses/courtney/courtneypool04.h"
};
const struct TrainerMon LeaderParty_CourtneyAces58[3] =
{
    #include "data/specialtytrainers/anchorbosses/courtney/courtneyaces58.h"
};
const struct TrainerMon LeaderParty_Courtney58[1] =
{
    #include "data/specialtytrainers/anchorbosses/courtney/courtneypool58.h"
};
const struct TrainerMon LeaderParty_CourtneyAces910[3] =
{
    #include "data/specialtytrainers/anchorbosses/courtney/courtneyaces910.h"
};
const struct TrainerMon LeaderParty_Courtney910[1] =
{
    #include "data/specialtytrainers/anchorbosses/courtney/courtneypool910.h"
};

const struct TrainerMon LeaderParty_CeriseAces04[3] =
{
    #include "data/specialtytrainers/anchorbosses/cerise/ceriseaces04.h"
};
const struct TrainerMon LeaderParty_Cerise04[1] =
{
    #include "data/specialtytrainers/anchorbosses/cerise/cerisepool04.h"
};
const struct TrainerMon LeaderParty_CeriseAces58[3] =
{
    #include "data/specialtytrainers/anchorbosses/cerise/ceriseaces58.h"
};
const struct TrainerMon LeaderParty_Cerise58[1] =
{
    #include "data/specialtytrainers/anchorbosses/cerise/cerisepool58.h"
};
const struct TrainerMon LeaderParty_CeriseAces910[3] =
{
    #include "data/specialtytrainers/anchorbosses/cerise/ceriesaces910.h"
};
const struct TrainerMon LeaderParty_Cerise910[1] =
{
    #include "data/specialtytrainers/anchorbosses/cerise/cerisepool910.h"
};

//elite four
const struct TrainerMon E4Party_PhoebeAces[3] =
{
    #include "data/specialtytrainers/elitefour/phoebe/phoebeaces.h"
};
const struct TrainerMon E4Party_PhoebePool[1] =
{
    #include "data/specialtytrainers/elitefour/phoebe/phoebepool.h"
};

const struct TrainerMon E4Party_NormanAces[3] =
{
    #include "data/specialtytrainers/elitefour/norman/normanaces.h"
};
const struct TrainerMon E4Party_NormanPool[1] =
{
    #include "data/specialtytrainers/elitefour/norman/normanpool.h"
};

const struct TrainerMon E4Party_BrendanAces[3] =
{
    #include "data/specialtytrainers/elitefour/brendan/brendanaces.h"
};
const struct TrainerMon E4Party_BrendanPool[1] =
{
    #include "data/specialtytrainers/elitefour/brendan/brendanpool.h"
};

const struct TrainerMon E4Party_E4TateAces[3] =
{
    #include "data/specialtytrainers/elitefour/tatee4/tatee4aces.h"
};
const struct TrainerMon E4Party_E4TatePool[1] =
{
    #include "data/specialtytrainers/elitefour/tatee4/tatee4pool.h"
};

const struct TrainerMon E4Party_E4LizaAces[3] =
{
    #include "data/specialtytrainers/elitefour/lizae4/lizae4aces.h"
};
const struct TrainerMon E4Party_E4LizaPool[1] =
{
    #include "data/specialtytrainers/elitefour/lizae4/lizae4pool.h"
};

const struct TrainerMon ChampParty_StevenAces[3] =
{
    #include "data/specialtytrainers/elitefour/steven/stevenaces.h"
};
const struct TrainerMon ChampParty_StevenPool[1] =
{
    #include "data/specialtytrainers/elitefour/steven/stevenpool.h"
};

//all else should use the trainer party defined in their trainer object

int GetPooledSpecialtyTrainerPoolLength(const enum TrainerClassID trainerClass)
{
    switch(trainerClass)
    {
        case TRAINER_CLASS_ROXANNE:
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return roxanne04length;
                case 5:
                case 6:
                case 7:
                case 8: return roxanne58length;
                case 9:
                case 10: return roxanne910length;
                default: return roxanne910length;
            }
        case TRAINER_CLASS_BRAWLY:
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return brawly04length;
                case 5:
                case 6:
                case 7:
                case 8: return brawly58length;
                case 9:
                case 10: return brawly910length;
                default: return brawly910length;
            }
        case TRAINER_CLASS_WALLY:
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return wally04length;
                case 5:
                case 6:
                case 7:
                case 8: return wally58length;
                case 9:
                case 10: return wally910length;
                default: return wally910length;
            }
        case TRAINER_CLASS_FLANNERY:
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return flannery04length;
                case 5:
                case 6:
                case 7:
                case 8: return flannery58length;
                case 9:
                case 10: return flannery910length;
                default: return flannery910length;
            }
        case TRAINER_CLASS_MAY:
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return may04length;
                case 5:
                case 6:
                case 7:
                case 8: return may58length;
                case 9:
                case 10: return may910length;
                default: return may910length;
            }
        case TRAINER_CLASS_TATE:
            if (*GetVarPointer(VAR_TATE_LIZA_STATE) == 0) //tate gym
            {
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4: return gymtate04length;
                    case 5:
                    case 6:
                    case 7:
                    case 8: return gymtate58length;
                    case 9:
                    case 10: return gymtate910length;
                    default: return gymtate910length;
                }
            } else //tate e4
            {
                return e4tatepoollength;
            }
        case TRAINER_CLASS_LIZA:
            if (*GetVarPointer(VAR_TATE_LIZA_STATE) == 0) //liza e4
            {
                return e4lizapoollength;
            } else //liza gym
            {
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4: return gymliza04length;
                    case 5:
                    case 6:
                    case 7:
                    case 8: return gymliza58length;
                    case 9:
                    case 10: return gymliza910length;
                    default: return gymliza910length;
                }
            }
        case TRAINER_CLASS_WALLACE:
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return wallace04length;
                case 5:
                case 6:
                case 7:
                case 8: return wallace58length;
                case 9:
                case 10: return wallace910length;
                default: return wallace910length;
            }
        case TRAINER_CLASS_ZINNIA:
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return zinnia04length;
                case 5:
                case 6:
                case 7:
                case 8: return zinnia58length;
                case 9:
                case 10: return zinnia910length;
                default: return zinnia910length;
            }
        case TRAINER_CLASS_ARCHIE:
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return archie04length;
                case 5:
                case 6:
                case 7:
                case 8: return archie58length;
                case 9:
                case 10: return archie910length;
                default: return archie910length;
            }
        case TRAINER_CLASS_COURTNEY:
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return courtney04length;
                case 5:
                case 6:
                case 7:
                case 8: return courtney58length;
                case 9:
                case 10: return courtney910length;
                default: return courtney910length;
            }
        case TRAINER_CLASS_CERISE:
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return cerise04length;
                case 5:
                case 6:
                case 7:
                case 8: return cerise58length;
                case 9:
                case 10: return cerise910length;
                default: return cerise910length;
            }
        case TRAINER_CLASS_STEVEN: //champion fight steven
            return stevenpoollength;
        case TRAINER_CLASS_PHOEBE:
            return phoebepoollength;
        case TRAINER_CLASS_NORMAN:
            return normanpoollength;
        case TRAINER_CLASS_BRENDAN:
            return brendanpoollength;
        default:
            switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4: return roxanne04length;
                case 5:
                case 6:
                case 7:
                case 8: return roxanne58length;
                case 9:
                case 10: return roxanne910length;
                default: return roxanne910length;
            }
    }
};

bool8 IsThisTrainerPooled(const enum TrainerClassID trainerClass)
{
    //DebugPrintf("%d", trainerClass);
    if (trainerClass == TRAINER_CLASS_ROXANNE ||
        trainerClass == TRAINER_CLASS_BRAWLY ||
        trainerClass == TRAINER_CLASS_WALLY ||
        trainerClass == TRAINER_CLASS_FLANNERY ||
        trainerClass == TRAINER_CLASS_MAY ||
        trainerClass == TRAINER_CLASS_TATE ||
        trainerClass == TRAINER_CLASS_LIZA ||
        trainerClass == TRAINER_CLASS_WALLACE ||
        trainerClass == TRAINER_CLASS_ZINNIA ||
        trainerClass == TRAINER_CLASS_ARCHIE ||
        trainerClass == TRAINER_CLASS_COURTNEY ||
        trainerClass == TRAINER_CLASS_CERISE ||
        trainerClass == TRAINER_CLASS_STEVEN ||
        trainerClass == TRAINER_CLASS_PHOEBE ||
        trainerClass == TRAINER_CLASS_NORMAN ||
        trainerClass == TRAINER_CLASS_BRENDAN ) 
    {
        //DebugPrintf("Beep.");
        return TRUE;
    } else { return FALSE; }
};

const struct TrainerMon *SpecialtyPool(const struct Trainer *trainer)
{
    u8 currentTrainerClass = trainer->trainerClass;
    bool8 usePoolFiles = IsThisTrainerPooled(currentTrainerClass);
    //DebugPrintf("%d", usePoolFiles);

    if (usePoolFiles) {
        u8 poolsize = GetPooledSpecialtyTrainerPoolLength(currentTrainerClass);

        struct TrainerMon* poolparty = Alloc(sizeof(struct TrainerMon) * (poolsize + 1));
        
        switch(currentTrainerClass)
        {
            case TRAINER_CLASS_ROXANNE:
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        memcpy(poolparty, GymParty_Roxanne04, sizeof(GymParty_Roxanne04));
                        poolparty[poolsize] = GymParty_RoxanneAces04[*GetVarPointer(VAR_ROXANNE_ACE)];
                        break;
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        memcpy(poolparty, GymParty_Roxanne58, sizeof(GymParty_Roxanne58));
                        poolparty[poolsize] = GymParty_RoxanneAces58[*GetVarPointer(VAR_ROXANNE_ACE)];
                        break;
                    case 9:
                    case 10:
                        memcpy(poolparty, GymParty_Roxanne910, sizeof(GymParty_Roxanne910));
                        poolparty[poolsize] = GymParty_RoxanneAces910[*GetVarPointer(VAR_ROXANNE_ACE)];
                        break;
                    default:
                        memcpy(poolparty, GymParty_Roxanne910, sizeof(GymParty_Roxanne910));
                        poolparty[poolsize] = GymParty_RoxanneAces910[*GetVarPointer(VAR_ROXANNE_ACE)];
                        break;
                }
                break;
            case TRAINER_CLASS_BRAWLY:
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        memcpy(poolparty, GymParty_Brawly04, sizeof(GymParty_Brawly04));
                        poolparty[poolsize] = GymParty_BrawlyAces04[*GetVarPointer(VAR_BRAWLY_ACE)];
                        break;
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        memcpy(poolparty, GymParty_Brawly58, sizeof(GymParty_Brawly58));
                        poolparty[poolsize] = GymParty_BrawlyAces58[*GetVarPointer(VAR_BRAWLY_ACE)];
                        break;
                    case 9:
                    case 10:
                        memcpy(poolparty, GymParty_Brawly910, sizeof(GymParty_Brawly910));
                        poolparty[poolsize] = GymParty_BrawlyAces910[*GetVarPointer(VAR_BRAWLY_ACE)];
                        break;
                    default:
                        memcpy(poolparty, GymParty_Brawly910, sizeof(GymParty_Brawly910));
                        poolparty[poolsize] = GymParty_BrawlyAces910[*GetVarPointer(VAR_BRAWLY_ACE)];
                        break;
                }
                break;
            case TRAINER_CLASS_WALLY:
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        memcpy(poolparty, GymParty_Wally04, sizeof(GymParty_Wally04));
                        poolparty[poolsize] = GymParty_WallyAces04[*GetVarPointer(VAR_WALLY_ACE)];
                        break;
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        memcpy(poolparty, GymParty_Wally58, sizeof(GymParty_Wally58));
                        poolparty[poolsize] = GymParty_WallyAces58[*GetVarPointer(VAR_WALLY_ACE)];
                        break;
                    case 9:
                    case 10:
                        memcpy(poolparty, GymParty_Wally910, sizeof(GymParty_Wallace910));
                        poolparty[poolsize] = GymParty_WallyAces910[*GetVarPointer(VAR_WALLY_ACE)];
                        break;
                    default:
                        memcpy(poolparty, GymParty_Wally910, sizeof(GymParty_Wallace910));
                        poolparty[poolsize] = GymParty_WallyAces910[*GetVarPointer(VAR_WALLY_ACE)];
                        break;
                }
                break;
            case TRAINER_CLASS_FLANNERY:
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        memcpy(poolparty, GymParty_Flannery04, sizeof(GymParty_Flannery04));
                        poolparty[poolsize] = GymParty_FlanneryAces04[*GetVarPointer(VAR_FLANNERY_ACE)];
                        break;
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        memcpy(poolparty, GymParty_Flannery58, sizeof(GymParty_Flannery58));
                        poolparty[poolsize] = GymParty_FlanneryAces58[*GetVarPointer(VAR_FLANNERY_ACE)];
                        break;
                    case 9:
                    case 10: 
                        memcpy(poolparty, GymParty_Flannery910, sizeof(GymParty_Flannery910));
                        poolparty[poolsize] = GymParty_FlanneryAces910[*GetVarPointer(VAR_FLANNERY_ACE)];
                        break;
                    default:
                        memcpy(poolparty, GymParty_Flannery910, sizeof(GymParty_Flannery910));
                        poolparty[poolsize] = GymParty_FlanneryAces910[*GetVarPointer(VAR_FLANNERY_ACE)];
                        break;
                }
                break;
            case TRAINER_CLASS_MAY:
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        memcpy(poolparty, GymParty_May04, sizeof(GymParty_May04));
                        poolparty[poolsize] = GymParty_MayAces04[*GetVarPointer(VAR_MAY_ACE)];
                        break;
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        memcpy(poolparty, GymParty_May58, sizeof(GymParty_May58));
                        poolparty[poolsize] = GymParty_MayAces58[*GetVarPointer(VAR_MAY_ACE)];
                        break;
                    case 9:
                    case 10:
                        memcpy(poolparty, GymParty_May910, sizeof(GymParty_May910));
                        poolparty[poolsize] = GymParty_MayAces910[*GetVarPointer(VAR_MAY_ACE)];
                        break;
                    default:
                        memcpy(poolparty, GymParty_May910, sizeof(GymParty_May910));
                        poolparty[poolsize] = GymParty_MayAces910[*GetVarPointer(VAR_MAY_ACE)];
                        break;
                }
                break;
            case TRAINER_CLASS_TATE:
                if (*GetVarPointer(VAR_TATE_LIZA_STATE) == 0) //tate gym
                {
                    switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                            memcpy(poolparty, GymParty_GymTate04, sizeof(GymParty_GymTate04));
                            poolparty[poolsize] = GymParty_GymTateAces04[*GetVarPointer(VAR_TATE_GYM_ACE)];
                            break;
                        case 5:
                        case 6:
                        case 7:
                        case 8:
                            memcpy(poolparty, GymParty_GymTate58, sizeof(GymParty_GymTate58));
                            poolparty[poolsize] = GymParty_GymTateAces58[*GetVarPointer(VAR_TATE_GYM_ACE)];
                            break;
                        case 9:
                        case 10:
                            memcpy(poolparty, GymParty_GymTate910, sizeof(GymParty_GymTate910));
                            poolparty[poolsize] = GymParty_GymTateAces910[*GetVarPointer(VAR_TATE_GYM_ACE)];
                            break;
                        default:
                            memcpy(poolparty, GymParty_GymTate910, sizeof(GymParty_GymTate910));
                            poolparty[poolsize] = GymParty_GymTateAces910[*GetVarPointer(VAR_TATE_GYM_ACE)];
                            break;
                    }
                } else //tate e4
                {
                    memcpy(poolparty, E4Party_E4TatePool, sizeof(E4Party_E4TatePool));
                    poolparty[poolsize] = E4Party_E4TateAces[*GetVarPointer(VAR_TATE_E4_ACE)];
                }
                break;
            case TRAINER_CLASS_LIZA:
                if (*GetVarPointer(VAR_TATE_LIZA_STATE) == 0) //liza e4
                {
                    memcpy(poolparty, E4Party_E4LizaPool, sizeof(E4Party_E4LizaPool));
                    poolparty[poolsize] = E4Party_E4LizaAces[*GetVarPointer(VAR_LIZA_E4_ACE)];
                } else //liza gym
                {
                    switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                            memcpy(poolparty, GymParty_GymLiza04, sizeof(GymParty_GymLiza04));
                            poolparty[poolsize] = GymParty_GymLizaAces04[*GetVarPointer(VAR_LIZA_GYM_ACE)];
                            break;
                        case 5:
                        case 6:
                        case 7:
                        case 8:
                            memcpy(poolparty, GymParty_GymLiza58, sizeof(GymParty_GymLiza58));
                            poolparty[poolsize] = GymParty_GymLizaAces58[*GetVarPointer(VAR_LIZA_GYM_ACE)];
                            break;
                        case 9:
                        case 10:
                            memcpy(poolparty, GymParty_GymLiza910, sizeof(GymParty_GymLiza910));
                            poolparty[poolsize] = GymParty_GymLizaAces910[*GetVarPointer(VAR_LIZA_GYM_ACE)];
                            break;
                        default:
                            memcpy(poolparty, GymParty_GymLiza910, sizeof(GymParty_GymLiza910));
                            poolparty[poolsize] = GymParty_GymLizaAces910[*GetVarPointer(VAR_LIZA_GYM_ACE)];
                            break;
                    }
                }
                break;
            case TRAINER_CLASS_WALLACE:
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        memcpy(poolparty, GymParty_Wallace04, sizeof(GymParty_Wallace04));
                        poolparty[poolsize] = GymParty_WallaceAces04[*GetVarPointer(VAR_WALLACE_ACE)];
                        break;
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        memcpy(poolparty, GymParty_Wallace58, sizeof(GymParty_Wallace58));
                        poolparty[poolsize] = GymParty_WallaceAces58[*GetVarPointer(VAR_WALLACE_ACE)];
                        break;
                    case 9:
                    case 10:
                        memcpy(poolparty, GymParty_Wallace910, sizeof(GymParty_Wallace910));
                        poolparty[poolsize] = GymParty_WallaceAces910[*GetVarPointer(VAR_WALLACE_ACE)];
                        break;
                    default:
                        memcpy(poolparty, GymParty_Wallace910, sizeof(GymParty_Wallace910));
                        poolparty[poolsize] = GymParty_WallaceAces910[*GetVarPointer(VAR_WALLACE_ACE)];
                        break;
                }
                break;
            case TRAINER_CLASS_ZINNIA:
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        memcpy(poolparty, GymParty_Zinnia04, sizeof(GymParty_Zinnia04));
                        poolparty[poolsize] = GymParty_ZinniaAces04[*GetVarPointer(VAR_ZINNIA_ACE)];
                        break;
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        memcpy(poolparty, GymParty_Zinnia58, sizeof(GymParty_Zinnia58));
                        poolparty[poolsize] = GymParty_ZinniaAces58[*GetVarPointer(VAR_ZINNIA_ACE)];
                        break;
                    case 9:
                    case 10:
                        memcpy(poolparty, GymParty_Zinnia910, sizeof(GymParty_Zinnia910));
                        poolparty[poolsize] = GymParty_ZinniaAces910[*GetVarPointer(VAR_ZINNIA_ACE)];
                        break;
                    default:
                        memcpy(poolparty, GymParty_Zinnia910, sizeof(GymParty_Zinnia910));
                        poolparty[poolsize] = GymParty_ZinniaAces910[*GetVarPointer(VAR_ZINNIA_ACE)];
                        break;
                }
                break;
            case TRAINER_CLASS_ARCHIE:
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        memcpy(poolparty, LeaderParty_Archie04, sizeof(LeaderParty_Archie04));
                        poolparty[poolsize] = LeaderParty_ArchieAces04[*GetVarPointer(VAR_ARCHIE_ACE)];
                        break;
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        memcpy(poolparty, LeaderParty_Archie58, sizeof(LeaderParty_Archie58));
                        poolparty[poolsize] = LeaderParty_ArchieAces58[*GetVarPointer(VAR_ARCHIE_ACE)];
                        break;
                    case 9:
                    case 10:
                        memcpy(poolparty, LeaderParty_Archie910, sizeof(LeaderParty_Archie910));
                        poolparty[poolsize] = LeaderParty_ArchieAces910[*GetVarPointer(VAR_ARCHIE_ACE)];
                        break;
                    default:
                        memcpy(poolparty, LeaderParty_Archie910, sizeof(LeaderParty_Archie910));
                        poolparty[poolsize] = LeaderParty_ArchieAces910[*GetVarPointer(VAR_ARCHIE_ACE)];
                        break;
                }
                break;
            case TRAINER_CLASS_COURTNEY:
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        memcpy(poolparty, LeaderParty_Courtney04, sizeof(LeaderParty_Courtney04));
                        poolparty[poolsize] = LeaderParty_CourtneyAces04[*GetVarPointer(VAR_COURTNEY_ACE)];
                        break;
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        memcpy(poolparty, LeaderParty_Courtney58, sizeof(LeaderParty_Courtney58));
                        poolparty[poolsize] = LeaderParty_CourtneyAces58[*GetVarPointer(VAR_COURTNEY_ACE)];
                        break;
                    case 9:
                    case 10:
                        memcpy(poolparty, LeaderParty_Courtney910, sizeof(LeaderParty_Courtney910));
                        poolparty[poolsize] = LeaderParty_CourtneyAces910[*GetVarPointer(VAR_COURTNEY_ACE)];
                        break;
                    default:
                        memcpy(poolparty, LeaderParty_Courtney910, sizeof(LeaderParty_Courtney910));
                        poolparty[poolsize] = LeaderParty_CourtneyAces910[*GetVarPointer(VAR_COURTNEY_ACE)];
                        break;
                }
                break;
            case TRAINER_CLASS_CERISE:
                switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        memcpy(poolparty, LeaderParty_Cerise04, sizeof(LeaderParty_Cerise04));
                        poolparty[poolsize] = LeaderParty_CeriseAces04[*GetVarPointer(VAR_CERISE_ACE)];
                        break;
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        memcpy(poolparty, LeaderParty_Cerise58, sizeof(LeaderParty_Cerise58));
                        poolparty[poolsize] = LeaderParty_CeriseAces58[*GetVarPointer(VAR_CERISE_ACE)];
                        break;
                    case 9:
                    case 10:
                        memcpy(poolparty, LeaderParty_Cerise910, sizeof(LeaderParty_Cerise910));
                        poolparty[poolsize] = LeaderParty_CeriseAces910[*GetVarPointer(VAR_CERISE_ACE)];
                        break;
                    default:
                        memcpy(poolparty, LeaderParty_Cerise910, sizeof(LeaderParty_Cerise910));
                        poolparty[poolsize] = LeaderParty_CeriseAces910[*GetVarPointer(VAR_CERISE_ACE)];
                        break;
                }
                break;
            case TRAINER_CLASS_PHOEBE:
                memcpy(poolparty, E4Party_PhoebePool, sizeof(E4Party_PhoebePool));
                poolparty[poolsize] = E4Party_PhoebeAces[*GetVarPointer(VAR_PHOEBE_ACE)];
                break;
            case TRAINER_CLASS_NORMAN:
                memcpy(poolparty, E4Party_NormanPool, sizeof(E4Party_NormanPool));
                poolparty[poolsize] = E4Party_NormanAces[*GetVarPointer(VAR_NORMAN_ACE)];
                break;
            case TRAINER_CLASS_BRENDAN:
                memcpy(poolparty, E4Party_BrendanPool, sizeof(E4Party_BrendanPool));
                poolparty[poolsize] = E4Party_BrendanAces[*GetVarPointer(VAR_NORMAN_ACE)];
                break;
            case TRAINER_CLASS_STEVEN:
                //some check if it's the special fight or champ fight to be implemented later
                //for now this is JUST the champ fight
                memcpy(poolparty, ChampParty_StevenPool, sizeof(ChampParty_StevenPool));
                poolparty[poolsize] = ChampParty_StevenAces[*GetVarPointer(VAR_STEVEN_ACE)];
                break;
            default:
               switch(*GetVarPointer(VAR_WORLD_DIFFICULTY)){
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        memcpy(poolparty, GymParty_Roxanne04, sizeof(GymParty_Roxanne04));
                        poolparty[poolsize] = GymParty_RoxanneAces04[*GetVarPointer(VAR_ROXANNE_ACE)];
                        break;
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        memcpy(poolparty, GymParty_Roxanne58, sizeof(GymParty_Roxanne58));
                        poolparty[poolsize] = GymParty_RoxanneAces58[*GetVarPointer(VAR_ROXANNE_ACE)];
                        break;
                    case 9:
                    case 10:
                        memcpy(poolparty, GymParty_Roxanne910, sizeof(GymParty_Roxanne910));
                        poolparty[poolsize] = GymParty_RoxanneAces910[*GetVarPointer(VAR_ROXANNE_ACE)];
                        break;
                    default:
                        memcpy(poolparty, GymParty_Roxanne910, sizeof(GymParty_Roxanne910));
                        poolparty[poolsize] = GymParty_RoxanneAces910[*GetVarPointer(VAR_ROXANNE_ACE)];
                        break;
                }
                break;
        }

        //DebugPrintf("Just Before Return--");
        //DebugPrintf("%d", poolparty[0].species);

        return poolparty;

    } else {
        const struct TrainerMon *partyData = trainer->party;
        //DebugPrintf("not pooled");
        //DebugPrintf("%d", partyData[0].species);
        //DebugPrintf("%d", partyData[1].species);
        //DebugPrintf("%d", partyData[2].species);

        //return trainer->party;
        return partyData;
    }
};