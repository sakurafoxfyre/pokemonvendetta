#include "global.h"
#include "constants/vars.h"
#include "event_data.h"
#include "data.h"
#include "overworld.h"
#include "constants/flags.h"

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

bool8 CanCatchInArea(void) //returns TRUE if catching is allowed on the route, FALSE if not
{
    u8 mapId = gMapHeader.regionMapSectionId; //returns MAPSEC_[AREANAME] ie MAPSEC_LITTLEROOT_TOWN

    switch (mapId)
    {
        case MAPSEC_ROUTE_101:
            if (FlagGet(FLAG_101_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_102:
            if (FlagGet(FLAG_102_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_103:
            if (FlagGet(FLAG_103_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_104:
            if (FlagGet(FLAG_104_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_105:
            if (FlagGet(FLAG_105_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_106:
            if (FlagGet(FLAG_106_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_107:
            if (FlagGet(FLAG_107_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_108:
            if (FlagGet(FLAG_108_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_109:
            if (FlagGet(FLAG_109_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_110:
            if (FlagGet(FLAG_110_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_111:
            if (FlagGet(FLAG_111_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_112:
            if (FlagGet(FLAG_112_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_113:
            if (FlagGet(FLAG_113_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_114:
            if (FlagGet(FLAG_114_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_115:
            if (FlagGet(FLAG_115_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_116:
            if (FlagGet(FLAG_116_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_117:
            if (FlagGet(FLAG_117_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_118:
            if (FlagGet(FLAG_118_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_119:
            if (FlagGet(FLAG_119_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_120:
            if (FlagGet(FLAG_120_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_121:
            if (FlagGet(FLAG_121_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_122:
            if (FlagGet(FLAG_122_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_123:
            if (FlagGet(FLAG_123_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_124:
            if (FlagGet(FLAG_124_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_125:
            if (FlagGet(FLAG_125_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_126:
            if (FlagGet(FLAG_126_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_127:
            if (FlagGet(FLAG_127_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_128:
            if (FlagGet(FLAG_128_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_129:
            if (FlagGet(FLAG_129_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_130:
            if (FlagGet(FLAG_130_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_131:
            if (FlagGet(FLAG_131_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_132:
            if (FlagGet(FLAG_132_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_133:
            if (FlagGet(FLAG_133_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_ROUTE_134:
            if (FlagGet(FLAG_134_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_LITTLEROOT_TOWN:
            if (FlagGet(FLAG_LITTLEROOT_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_OLDALE_TOWN:
            if (FlagGet(FLAG_OLDALE_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_PETALBURG_CITY:
            if (FlagGet(FLAG_PETALBURG_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_RUSTBORO_CITY:
            if (FlagGet(FLAG_RUSTBORO_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_DEWFORD_TOWN:
            if (FlagGet(FLAG_DEWFORD_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_SLATEPORT_CITY:
            if (FlagGet(FLAG_SLATEPORT_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_MAUVILLE_CITY:
            if (FlagGet(FLAG_MAUVILLE_BOSS)) return FALSE;
            else return TRUE;
        case MAPSEC_VERDANTURF_TOWN:
            if (FlagGet(FLAG_VERDANTURF_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_LAVARIDGE_TOWN:
            if (FlagGet(FLAG_LAVARIDGE_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_FALLARBOR_TOWN:
            if (FlagGet(FLAG_FALLARBOR_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_FORTREE_CITY:
            if (FlagGet(FLAG_FORTREE_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_LILYCOVE_CITY:
            if (FlagGet(FLAG_LILYCOVE_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_MOSSDEEP_CITY:
            if (FlagGet(FLAG_MOSSDEEP_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_SOOTOPOLIS_CITY:
            if (FlagGet(FLAG_SOOTOPOLIS_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_PACIFIDLOG_TOWN:
            if (FlagGet(FLAG_PACIFIDLOG_CAUGHT)) return FALSE;
            else return TRUE;
        // case MAPSEC_GRANITE_CAVE_1F:
        //     if (FlagGet(FLAG_GRANITE_CAVE_1F_CAUGHT)) return FALSE;
        //     else return TRUE;
        // case MAPSEC_GRANITE_CAVE_B1F:
        //     if (FlagGet(FLAG_GRANITE_CAVE_B1F_CAUGHT)) return FALSE;
        //     else return TRUE;
        // case MAPSEC_GRANITE_CAVE_B2F:
        //     if (FlagGet(FLAG_GRANITE_CAVE_B2F_CAUGHT)) return FALSE;
        //     else return TRUE;
        // case MAPSEC_HAUNTWOOD:
        //     if (FlagGet(FLAG_HAUNTWOOD_CAUGHT)) return FALSE;
        //     else return TRUE;
        // case MAPSEC_RUSTBORO_PIER:
        //     if (FlagGet(FLAG_RUSTBORO_PIER_CAUGHT)) return FALSE;
        //     else return TRUE;
        case MAPSEC_RUSTURF_TUNNEL:
            if (FlagGet(FLAG_RUSTURF_TUNNEL_CAUGHT)) return FALSE;
            else return TRUE;
        case MAPSEC_PETALBURG_WOODS:
            if (FlagGet(FLAG_PETALBURG_WOODS_CAUGHT)) return FALSE;
            else return TRUE;
    }    
};

void SetCatchFlag(void)
{
    u8 mapId = gMapHeader.regionMapSectionId; //returns MAPSEC_[AREANAME] ie MAPSEC_LITTLEROOT_TOWN

    switch (mapId)
    {
        case MAPSEC_ROUTE_101:
            SetFlag(FLAG_101_CAUGHT);
            break;
        case MAPSEC_ROUTE_102:
            SetFlag(FLAG_102_CAUGHT);
            break;
        case MAPSEC_ROUTE_103:
            SetFlag(FLAG_103_CAUGHT);
            break;
        case MAPSEC_ROUTE_104:
            SetFlag(FLAG_104_CAUGHT);
            break;
        case MAPSEC_ROUTE_105:
            SetFlag(FLAG_105_CAUGHT);
            break;
        case MAPSEC_ROUTE_106:
            SetFlag(FLAG_106_CAUGHT);
            break;
        case MAPSEC_ROUTE_107:
            SetFlag(FLAG_107_CAUGHT);
            break;
        case MAPSEC_ROUTE_108:
            SetFlag(FLAG_108_CAUGHT);
            break;
        case MAPSEC_ROUTE_109:
            SetFlag(FLAG_109_CAUGHT);
            break;
        case MAPSEC_ROUTE_110:
            SetFlag(FLAG_110_CAUGHT);
            break;
        case MAPSEC_ROUTE_111:
            SetFlag(FLAG_111_CAUGHT);
            break;
        case MAPSEC_ROUTE_112:
            SetFlag(FLAG_112_CAUGHT);
            break;
        case MAPSEC_ROUTE_113:
            SetFlag(FLAG_113_CAUGHT);
            break;
        case MAPSEC_ROUTE_114:
            SetFlag(FLAG_114_CAUGHT);
            break;
        case MAPSEC_ROUTE_115:
            SetFlag(FLAG_115_CAUGHT);
            break;
        case MAPSEC_ROUTE_116:
            SetFlag(FLAG_116_CAUGHT);
            break;
        case MAPSEC_ROUTE_117:
            SetFlag(FLAG_117_CAUGHT);
            break;
        case MAPSEC_ROUTE_118:
            SetFlag(FLAG_118_CAUGHT);
            break;
        case MAPSEC_ROUTE_119:
            SetFlag(FLAG_119_CAUGHT);
            break;
        case MAPSEC_ROUTE_120:
            SetFlag(FLAG_120_CAUGHT);
            break;
        case MAPSEC_ROUTE_121:
            SetFlag(FLAG_121_CAUGHT);
            break;
        case MAPSEC_ROUTE_122:
            SetFlag(FLAG_122_CAUGHT);
            break;
        case MAPSEC_ROUTE_123:
            SetFlag(FLAG_123_CAUGHT);
            break;
        case MAPSEC_ROUTE_124:
            SetFlag(FLAG_124_CAUGHT);
            break;
        case MAPSEC_ROUTE_125:
            SetFlag(FLAG_125_CAUGHT);
            break;
        case MAPSEC_ROUTE_126:
            SetFlag(FLAG_126_CAUGHT);
            break;
        case MAPSEC_ROUTE_127:
            SetFlag(FLAG_127_CAUGHT);
            break;
        case MAPSEC_ROUTE_128:
            SetFlag(FLAG_128_CAUGHT);
            break;
        case MAPSEC_ROUTE_129:
            SetFlag(FLAG_129_CAUGHT);
            break;
        case MAPSEC_ROUTE_130:
            SetFlag(FLAG_130_CAUGHT);
            break;
        case MAPSEC_ROUTE_131:
            SetFlag(FLAG_131_CAUGHT);
            break;
        case MAPSEC_ROUTE_132:
            SetFlag(FLAG_132_CAUGHT);
            break;
        case MAPSEC_ROUTE_133:
            SetFlag(FLAG_133_CAUGHT);
            break;
        case MAPSEC_ROUTE_134:
            SetFlag(FLAG_134_CAUGHT);
            break;
        case MAPSEC_LITTLEROOT_TOWN:
            SetFlag(FLAG_LITTLEROOT_CAUGHT);
            break;
        case MAPSEC_OLDALE_TOWN:
            SetFlag(FLAG_OLDALE_CAUGHT);
            break;
        case MAPSEC_PETALBURG_CITY:
            SetFlag(FLAG_PETALBURG_CAUGHT);
            break;
        case MAPSEC_RUSTBORO_CITY:
            SetFlag(FLAG_RUSTBORO_CAUGHT);
            break;
        case MAPSEC_DEWFORD_TOWN:
            SetFlag(FLAG_DEWFORD_CAUGHT);
            break;
        case MAPSEC_SLATEPORT_CITY:
            SetFlag(FLAG_SLATEPORT_CAUGHT);
            break;
        case MAPSEC_MAUVILLE_CITY:
            SetFlag(FLAG_MAUVILLE_CAUGHT);
            break;
        case MAPSEC_VERDANTURF_TOWN:
            SetFlag(FLAG_VERDANTURF_CAUGHT);
            break;
        case MAPSEC_LAVARIDGE_TOWN:
            SetFlag(FLAG_LAVARIDGE_CAUGHT);
            break;
        case MAPSEC_FALLARBOR_TOWN:
            SetFlag(FLAG_FALLARBOR_CAUGHT);
            break;
        case MAPSEC_FORTREE_CITY:
            SetFlag(FLAG_FORTREE_CAUGHT);
            break;
        case MAPSEC_LILYCOVE_CITY:
            SetFlag(FLAG_LILYCOVE_CAUGHT);
            break;
        case MAPSEC_MOSSDEEP_CITY:
            SetFlag(FLAG_MOSSDEEP_CAUGHT);
            break;
        case MAPSEC_SOOTOPOLIS_CITY:
            SetFlag(FLAG_SOOTOPOLIS_CAUGHT);
            break;
        case MAPSEC_PACIFIDLOG_TOWN:
            SetFlag(FLAG_PACIFIDLOG_CAUGHT);
            break;
        // case MAPSEC_GRANITE_CAVE_1F:
        //     SetFlag(FLAG_GRANITE_CAVE_1F_CAUGHT);
        //     break;
        // case MAPSEC_GRANITE_CAVE_B1F:
        //     SetFlag(FLAG_GRANITE_CAVE_B1F_CAUGHT);
        //     break;
        // case MAPSEC_GRANITE_CAVE_B2F:
        //     SetFlag(FLAG_GRANITE_CAVE_B2F_CAUGHT);
        //     break;
        // case MAPSEC_HAUNTWOOD:
        //     SetFlag(FLAG_HAUNTWOOD_CAUGHT);
        //     break;
        // case MAPSEC_RUSTBORO_PIER:
        //     SetFlag(FLAG_RUSTBORO_PIER_CAUGHT);
        //     break;
        case MAPSEC_RUSTURF_TUNNEL:
            SetFlag(FLAG_RUSTURF_TUNNEL_CAUGHT);
            break;
        case MAPSEC_PETALBURG_WOODS:
            SetFlag(FLAG_PETALBURG_WOODS_CAUGHT);
            break;
    }
}
