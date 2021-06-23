/*
	Muteo Includes, m_checkpoint Created At 05.02.2021, 16:43
*/

#define Checkpoint:%0(%1) \
	forward c_%0(%1); public c_%0(%1)

stock Checkpoint_Clear(playerid)
{
	DeletePVar(playerid, "t_CheckpointName"), DeletePVar(playerid, "t_CheckpointX"), DeletePVar(playerid, "t_CheckpointY"), DeletePVar(playerid, "t_CheckpointZ");
	return DisablePlayerCheckpoint(playerid);
}

stock Checkpoint_Show(playerid, function[], Float:x, Float:y, Float:z, Float:size)
{
	SetPlayerCheckpoint(playerid, x, y, z, size);
	new t_CheckpointName[32];
	strpack(t_CheckpointName, function, 32 char);
	SetPVarString(playerid, "t_CheckpointName", function), SetPVarFloat(playerid, "t_CheckpointX", x), SetPVarFloat(playerid, "t_CheckpointY", y), SetPVarFloat(playerid, "t_CheckpointZ", z);
	return 1;
}

public OnPlayerEnterCheckpoint(playerid)
{
	new string[34];
	GetPVarString(playerid, "t_CheckpointName", string, 32);
	if (strlen(string) > 0 && IsPlayerInRangeOfPoint(playerid, 15.0, GetPVarFloat(playerid, "t_CheckpointX"), GetPVarFloat(playerid, "t_CheckpointY"), GetPVarFloat(playerid, "t_CheckpointZ")))
	{
		format(string, sizeof(string), "c_%s", string);
		Checkpoint_Clear(playerid);
		CallLocalFunction(string, "d", playerid);
	}
	#if defined Muteo_OnPlayerEnterCheckpoint
	    return Muteo_OnPlayerEnterCheckpoint(playerid);
	#else
	    return 0;
	#endif
}

#if defined _ALS_OnPlayerEnterCheckpoint
	#undef OnPlayerEnterCheckpoint
#else
	#define _ALS_OnPlayerEnterCheckpoint
#endif

#define OnPlayerEnterCheckpoint Muteo_OnPlayerEnterCheckpoint

#if defined Muteo_OnPlayerEnterCheckpoint
	forward Muteo_OnPlayerEnterCheckpoint(playerid);
#endif
