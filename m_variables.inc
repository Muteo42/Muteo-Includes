/*
	Muteo Includes, m_variables Created At 06.01.2021, 09:26
*/

#include <gvar>

stock SetPVarInt(playerid, const varname[], int_value)
{
    SetGVarInt(varname, int_value, 99000 + playerid);
    return 1;
}

stock GetPVarInt(playerid, const varname[])
{
    return GetGVarInt(varname, 99000 + playerid);
}

stock SetPVarString(playerid, const varname[], string_value[])
{
    SetGVarString(varname, string_value, 99000 + playerid);
    return 1;
}

stock GetPVarString(playerid, const varname[], string[], maxlength = sizeof string)
{
    GetGVarString(varname, string, maxlength, 99000 + playerid);
    return 1;
}

stock SetPVarFloat(playerid, const varname[], Float:float_value)
{
    SetGVarFloat(varname, float_value, 99000 + playerid);
    return 1;
}

stock Float:GetPVarFloat(playerid, const varname[])
{
    return GetGVarFloat(varname, 99000 + playerid);
}

stock DeletePVar(playerid, const varname[])
{
    DeleteGVar(varname, 99000 + playerid);
    return 1;
}

stock GetPVarType(playerid, const varname[])
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
