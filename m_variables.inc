/*
	Muteo Includes, m_variables Created At 06.01.2021, 09:26
*/

#include <gvar>

stock M_SetPVarInt(playerid, const varname[], int_value)
{
    SetGVarInt(varname, int_value, 99000 + playerid);
    return 1;
}

stock M_GetPVarInt(playerid, const varname[])
{
    return GetGVarInt(varname, 99000 + playerid);
}

stock M_SetPVarString(playerid, const varname[], string_value[])
{
    SetGVarString(varname, string_value, 99000 + playerid);
    return 1;
}

stock M_GetPVarString(playerid, const varname[], string[], maxlength = sizeof string)
{
    GetGVarString(varname, string, maxlength, 99000 + playerid);
    return 1;
}

stock M_SetPVarFloat(playerid, const varname[], Float:float_value)
{
    SetGVarFloat(varname, float_value, 99000 + playerid);
    return 1;
}

stock Float:M_GetPVarFloat(playerid, const varname[])
{
    return GetGVarFloat(varname, 99000 + playerid);
}

stock M_DeletePVar(playerid, const varname[])
{
    DeleteGVar(varname, 99000 + playerid);
    return 1;
}

stock M_GetPVarType(playerid, const varname[])
{
    return GetGVarType(varname, 99000 + playerid);
}

forward Muteo_OnPlayerDisconnect(playerid);
public Muteo_OnPlayerDisconnect(playerid)
{
    new t_count = GetGVarsUpperIndex(99000 + playerid);
	new t_str[64];
	for(new i = 0; i < t_count; i++)
	{
		GetGVarNameAtIndex(i, t_str, 64, 99000 + playerid);
		DeleteGVar(t_str, 99000 + playerid);
	}
    return 1;
}

#if defined _ALS_SetPVarInt
  #undef SetPVarInt
#else
	#define _ALS_SetPVarInt
#endif

#define SetPVarInt M_SetPVarInt

#if defined _ALS_GetPVarInt
  #undef GetPVarInt
#else
	#define _ALS_GetPVarInt
#endif

#define GetPVarInt M_GetPVarInt

#if defined _ALS_SetPVarFloat
  #undef SetPVarFloat
#else
	#define _ALS_SetPVarFloat
#endif

#define SetPVarFloat M_SetPVarFloat

#if defined _ALS_GetPVarFloat
  #undef GetPVarFloat
#else
	#define _ALS_GetPVarFloat
#endif

#define GetPVarFloat M_GetPVarFloat

#if defined _ALS_SetPVarString
  #undef SetPVarString
#else
	#define _ALS_SetPVarString
#endif

#define SetPVarString M_SetPVarString

#if defined _ALS_GetPVarString
  #undef GetPVarString
#else
	#define _ALS_GetPVarString
#endif

#define GetPVarString M_GetPVarString

#if defined _ALS_DetelePVar
  #undef DeletePVar
#else
	#define _ALS_DetelePVar
#endif

#define DeletePVar M_DeletePVar

#if defined _ALS_GetPVarType
  #undef GetPVarType
#else
	#define _ALS_GetPVarType
#endif

#define GetPVarType M_GetPVarType