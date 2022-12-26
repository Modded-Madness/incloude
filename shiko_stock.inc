#include <tf2attributes>

#define JUMP_MIN_SPEED	268.3281572999747

/* Damage Type.
 * ---------------------------------------------------------------------- */
#define HL_DMG_GENERIC                      0                                                       // 0
#define TF_DMG_CRUSH                        (1 << 0)                                                // 1
#define TF_DMG_BULLET                       (1 << 1)                                                // 2            ► Bullet in general && Sniper Rifle ( Exception: The Classic ) && Scout's Homerun && Heavy's Showdown.
#define TF_DMG_BLEED                        (1 << 2)                                                // 4            ► Bleed in general && Cleaver && Spy's Fencing final damage.
#define TF_DMG_BURN                         (1 << 3)                                                // 8
#define SDK_DMG_UNUSED                      (1 << 4)                                                // 16
#define TF_DMG_FALL                         (1 << 5)                                                // 32           ► Fall in general && Mantreads's stomp.
#define TF_DMG_BLAST                        (1 << 6)                                                // 64           ► Also Engineer's Organ Grinder final damage.
#define TF_DMG_MISC                         (1 << 7)                                                // 128          ► Sandman's ball && Wrap Assassin's ball && Shield && Demoman's Decapitation Taunt Kill && Engineer's Dischord && Headless Horseless Horsemann.
#define SDK_DMG_UNUSED2                     (1 << 8)                                                // 256
#define SDK_DMG_UNUSED3                     (1 << 9)                                                // 512
#define DOTA_DMG_DISPERSION                 (1 << 10)                                               // 1024
#define TF_PREVENT_PHYSICS_FORCE            (1 << 11)                                               // 2048
#define TF_DMG_SOMETAUNTKILLS               TF_PREVENT_PHYSICS_FORCE | TF_DMG_BULLET                // 2050         ► Engineer's Organ Grinder spinning phase && Medic's Spinal Tap initial AND final damage && Sniper's Skewer.
#define TF_DMG_SPY_FENCING                  TF_PREVENT_PHYSICS_FORCE | TF_DMG_BLEED                 // 2052         ► Only the first 2 damages instances.
#define TF_DMG_AFTERBURN                    TF_PREVENT_PHYSICS_FORCE | TF_DMG_BURN                  // 2056
#define TF_DMG_BLAST_WRAPASSASSIN           TF_PREVENT_PHYSICS_FORCE | TF_DMG_BLAST                 // 2112
#define TF_DMG_ZATOICHI_RETURN				TF_PREVENT_PHYSICS_FORCE | TF_DMG_MISC			     	// 2176
#define TF_NEVERGIB                     	(1 << 12)                                               // 4096
#define TF_ALWAYSGIB                    	(1 << 13)                                               // 8192
#define TF_DMG_DROWN                        (1 << 14)                                               // 16384
#define DOTA_DMG_OTHER                      (1 << 15)                                               // 32768
#define TF_DMG_ENV                          (1 << 16)                                               // 65536
#define TF_PLUS1                    		(1 << 17)                                               // 131072
#define TF_DMG_LASER						TF_PLUS1 | TF_DMG_BULLET								// 131074
#define TF_PLUS2                   	 		(1 << 18)                                               // 262144
#define TF_DMG_GRENADE                      TF_PLUS2 | TF_DMG_BLAST                         		// 262208
#define TF_DMG_DROWNRECOVER                 (1 << 19)                                               // 524288
#define TF_DMG_CRIT                         (1 << 20)                                               // 1048576      ► Also Mini-Crit.
#define TF_DMG_GRENADE_CRIT                 TF_DMG_GRENADE | TF_DMG_CRIT                            // 1310784      ► Also Double Donk.
#define TF_PLUS3                    		(1 << 21)                                               // 2097152
#define TF_DMG_BULLET2                      TF_PLUS3 | TF_DMG_BULLET                        		// 2097154      ► Pistol && Minigun && Short Circuit && SMG.
#define TF_DMG_SOLDIER_KAMIKAZE             TF_PLUS3 | TF_DMG_BLAST                         		// 2097216      ► Also the Caber's explosion.
#define TF_DMG_BISON						TF_PLUS3 | TF_DMG_LASER									// 2228226		► Righteous Bison & Pomson.
#define TF_DMG_SYRINGE                      TF_PLUS3 | TF_PLUS1 | TF_PREVENT_PHYSICS_FORCE | TF_DMG_BULLET    // 2230274
#define TF_DMG_SENTRY                       TF_PLUS3 | TF_PLUS1 | TF_NEVERGIB | TF_DMG_BULLET       // 2232322
#define TF_DMG_ROCKET                       TF_PLUS3 | TF_DMG_GRENADE                       		// 2359360      ► Also Sentry's Rocket.
#define TF_DMG_STICKY                       TF_PLUS3 | TF_PLUS1 | TF_DMG_GRENADE    				// 2490432
#define TF_DMG_BULLET2_CRIT                 TF_DMG_BULLET2 | TF_DMG_CRIT                            // 3145730      ► Pistol && Minigun && Short Circuit && SMG.
#define TF_DMG_ROCKET_CRIT                  TF_DMG_ROCKET | TF_DMG_CRIT                             // 3407936
#define TF_DMG_STICKY_CRIT                  TF_DMG_STICKY | TF_DMG_CRIT                             // 3539008
#define TF_DMG_REMOVENORAGDOLL              (1 << 22)                                               // 4194304
#define SDK_DMG_UNUSED4                    	(1 << 23)                                              	// 8388608
#define TF_DMG_FIRE                         (1 << 24)                                               // 16777216     ► Fire in general && Pyro's Armageddon && Huo-Long Heater's Ring of Fire.
#define TF_DMG_FLARE                        TF_DMG_FIRE | TF_DMG_BULLET                             // 16777218
#define TF_DMG_PYRO_HADOUKEN                TF_DMG_FIRE | TF_DMG_BURN                               // 16777224
#define TF_DMG_FLAMETHROWER                 TF_PREVENT_PHYSICS_FORCE | TF_DMG_FIRE             		// 16779264
#define TF_DMG_SCORCHSHOT                   TF_DMG_FLAMETHROWER | TF_DMG_BULLET                     // 16779266     ► Scorch Shot && Pyro's Execution.
#define TF_DMG_FLARE_CRIT                   TF_DMG_FLARE | TF_DMG_CRIT                              // 17825794
#define TF_DMG_FLAMETHROWER_CRIT            TF_DMG_FLAMETHROWER | TF_DMG_CRIT                       // 17827840
#define TF_DMG_BLAST_FLARE                  TF_DMG_FLARE | TF_PLUS2                         		// 17039362     ► Scorch Shot && Detonator explosion.
#define TF_DMG_BLAST_FLARE_CRIT             TF_DMG_FLARE_CRIT | TF_PLUS2                    		// 18087938     ► Scorch Shot && Detonator explosion.
#define TF_DMG_COWMANGLER_CHARGED			TF_DMG_FIRE | TF_DMG_ROCKET								// 19136576
#define TF_PLUS4                    		(1 << 25)                                               // 33554432
#define TF_DMG_RIFLE_CHARGED                TF_PLUS4 | TF_DMG_BULLET                        		// 33554434     ► Also Crusader's Crossbow && Huntsman && The Classic.
#define TF_DMG_RIFLE_CRIT                   TF_DMG_RIFLE_CHARGED | TF_DMG_CRIT                      // 34603010     ► Also Crusader's Crossbow && Huntsman && The Classic.
#define TF_DMG_AMBASSADOR                   TF_PLUS4 | TF_DMG_BULLET2                       		// 35651586
#define TF_DMG_AMBASSADOR_CRIT              TF_DMG_AMBASSADOR | TF_DMG_CRIT                         // 35651586     ► Only when able to Headshot.
#define SDK_DMG_UNUSER5                    	(1 << 26)                                               // 67108864
#define TF_DMG_BLAST_SURFACE                (1 << 27)                                               // 134217728
#define TF_DMG_MELEE                        TF_DMG_BLAST_SURFACE | TF_NEVERGIB | TF_DMG_MISC    	// 134221952
#define TF_DMG_MELEE_CRIT                   TF_DMG_MELEE | TF_DMG_CRIT                              // 135270528
#define DOTA_DMG_BLADEMAIL                  (1 << 28)                                               // 268435456
#define TF_PLUS5                    		(1 << 29)                                               // 536870912
#define TF_DMG_SCATTERGUN                   TF_PLUS5 | TF_PLUS3                     				// 538968064    ► Scattergun && Shotgun && Rescue Ranger.
#define TF_DMG_SHORTSTOP                    TF_DMG_SCATTERGUN | TF_DMG_BULLET                       // 538968066
#define TF_DMG_SCATTERGUN_CRIT              TF_DMG_SCATTERGUN | TF_DMG_CRIT                         // 540016640    ► Scattergun && Shotgun && Rescue Ranger.
#define TF_DMG_SHORTSTOP_CRIT               TF_DMG_SHORTSTOP | TF_DMG_CRIT                          // 540016642
//#define SDK_DMG_UNKNOWN10                 (1 << 30)                                               // 1073741824

//	debug boxes
int g_iLaserIndex;

stock void SetupBoxBeam()
{
	g_iLaserIndex = PrecacheModel("materials/sprites/laserbeam.vmt");
}

stock void DrawDebugBox(float pos[3], float mins[3], float maxs[3])
{
	if(mins[0] == maxs[0] && mins[1] == maxs[1] && mins[2] == maxs[2]) {
		mins = view_as<float>({-15.0, -15.0, -15.0});
		maxs = view_as<float>({15.0, 15.0, 15.0});
	}
	else {
		AddVectors(pos, maxs, maxs);
		AddVectors(pos, mins, mins);
	}

	float pos1[3], pos2[3], pos3[3], pos4[3], pos5[3], pos6[3];
	pos1 = maxs;
	pos1[0] = mins[0];
	pos2 = maxs;
	pos2[1] = mins[1];
	pos3 = maxs;
	pos3[2] = mins[2];
	pos4 = mins;
	pos4[0] = maxs[0];
	pos5 = mins;
	pos5[1] = maxs[1];
	pos6 = mins;
	pos6[2] = maxs[2];

	TE_SendBeam(maxs, pos1);
	TE_SendBeam(maxs, pos2);
	TE_SendBeam(maxs, pos3);
	TE_SendBeam(pos6, pos1);
	TE_SendBeam(pos6, pos2);
	TE_SendBeam(pos6, mins);
	TE_SendBeam(pos4, mins);
	TE_SendBeam(pos5, mins);
	TE_SendBeam(pos5, pos1);
	TE_SendBeam(pos5, pos3);
	TE_SendBeam(pos4, pos3);
	TE_SendBeam(pos4, pos2);
}

stock void TE_SendBeam(const float vMins[3], const float vMaxs[3])
{
	TE_SetupBeamPoints(vMins, vMaxs, g_iLaserIndex, g_iLaserIndex, 0, 0, 0.051, 1.0, 1.0, 1, 0.0, { 255, 0, 0, 255 }, 0);
	TE_SendToAll();
}

stock bool IsValidClient(int client)
{
	if (client <= 0) return false;
	if (client > MaxClients) return false;
	if (!IsClientConnected(client)) return false;
	return IsClientInGame(client);
}

stock bool IsValidWeaponSlot(int client, int entity)
{
	for (int i = 0; i < 6; i++) {
		int weapon = GetPlayerWeaponSlot(client, i);
		if (weapon == entity) return true;
	}

	return false;
}

stock float GetAngleDifference(float a[3], float b[3])
{
	float fwd_a[3];
	float fwd_b[3];
	GetAngleVectors(a, fwd_a, NULL_VECTOR, NULL_VECTOR);
	GetAngleVectors(b, fwd_b, NULL_VECTOR, NULL_VECTOR);

	return RadToDeg(ArcCosine((fwd_a[0] * fwd_b[0]) + (fwd_a[1] * fwd_b[1]) + (fwd_a[2] * fwd_b[2])));
}

stock void ApplyNullVector(int client)
{
	float null_vector[3];
	null_vector[0] = 0.0;
	null_vector[1] = 0.0;
	null_vector[2] = 0.0;

	TeleportEntity(client, NULL_VECTOR, NULL_VECTOR, null_vector);
}

stock void ApplyAirBlastImpulse(int client, const float vector[3])
{
	// Knockout powerup carriers are immune to airblast
	if (TF2_IsPlayerInCondition(client, TFCond_RuneKnockout) || TF2_IsPlayerInCondition(client, TFCond_MegaHeal)) return;
	
	float force[3];
	AddVectors(force, vector, force);

	// if on the ground, require min force to boost you off it
	int flags = GetEntityFlags(client);
	if ((flags & FL_ONGROUND) && (force[2] < JUMP_MIN_SPEED)) {
		// Minimum value of vecForce.z
		force[2] = JUMP_MIN_SPEED;
	}

	flags &= ~FL_ONGROUND;
	SetEntityFlags(client, flags);
	TeleportEntity(client, NULL_VECTOR, NULL_VECTOR, force);
}

public bool TraceRayDontHitEntity(int iEntity, int contentsMask, any iData)
{
	return (iEntity != iData);
}

stock bool IsPlayerOnGround(int client)
{
	return (GetEntityFlags(client) & FL_ONGROUND == FL_ONGROUND);
}

stock bool IsPlayerDucking(int client)
{
	return (GetEntityFlags(client) & FL_DUCKING == FL_DUCKING);
}

stock int ShowParticle(char[] particlename, float time, float pos[3], float ang[3] = NULL_VECTOR)
{
	int particle = CreateEntityByName("info_particle_system");
	if (!IsValidEdict(particle)) return -1;

	TeleportEntity(particle, pos, ang, NULL_VECTOR);
	DispatchKeyValue(particle, "effect_name", particlename);
	DispatchKeyValueVector(particle, "angles", ang);
	ActivateEntity(particle);
	AcceptEntityInput(particle, "start");
	CreateTimer(time, RemoveParticle, particle);

	return particle;
}

stock void PrecacheParticle(char[] strName)
{
	if(IsValidEntity(0)) {
		int iParticle = CreateEntityByName("info_particle_system");
		if (IsValidEdict(iParticle)) {
			char tName[32];
			GetEntPropString(0, Prop_Data, "m_iName", tName, sizeof(tName));
			DispatchKeyValue(iParticle, "targetname", "tf2particle");
			DispatchKeyValue(iParticle, "parentname", tName);
			DispatchKeyValue(iParticle, "effect_name", strName);
			DispatchSpawn(iParticle);
			SetVariantString(tName);
			AcceptEntityInput(iParticle, "SetParent", 0, iParticle, 0);
			ActivateEntity(iParticle);
			AcceptEntityInput(iParticle, "start");
			CreateTimer(0.01, RemoveParticle, iParticle);
		}
	}
}

public Action RemoveParticle(Handle timer, any particle)
{
	if (IsValidEntity(particle)) {
		char classname[32];
		GetEdictClassname(particle, classname, sizeof(classname));
		if (StrEqual(classname, "info_particle_system", false)) {
			AcceptEntityInput(particle, "stop");
			AcceptEntityInput(particle, "Kill");
		}
	}

	return Plugin_Continue;
}

stock void Explode(float flPos[3], float flDamage, float flRadius, int iAttacker = 0, bool bFriendlyFire = false, const char[] strParticle, const char[] strSound)
{
    int iBomb = CreateEntityByName("tf_generic_bomb");
    DispatchKeyValueVector(iBomb, "origin", flPos);
    DispatchKeyValueFloat(iBomb, "damage", flDamage);
    DispatchKeyValueFloat(iBomb, "radius", flRadius);

    int friendlyfire = bFriendlyFire ? 1 : 0;
    char num[16];
    IntToString(friendlyfire, num, sizeof(num));
    DispatchKeyValue(iBomb, "friendlyfire", num);
    DispatchKeyValue(iBomb, "health", "1");
    DispatchKeyValue(iBomb, "explode_particle", strParticle);
    DispatchKeyValue(iBomb, "sound", strSound);
    DispatchSpawn(iBomb);

    //if (iOwner > 0 && iOwner < MaxClients && IsClientInGame(iOwner)) SetEntPropEnt(iBomb, Prop_Data, "m_hOwnerEntity", iOwner);
    //AcceptEntityInput(iBomb, "Detonate");
    if (iAttacker > 0 && iAttacker < MaxClients && IsClientInGame(iAttacker)) {
        SDKHooks_TakeDamage(iBomb, iAttacker, iAttacker, 1337.0);
    }
}  

stock void GetModelPath(int index, char[] strModel, int maxsize)
{
	int table = FindStringTable("modelprecache");
	ReadStringTable(table, index, strModel, maxsize);
}

stock void GetEntityModel(int entity, char[] strModel, int maxsize, char[] strPropName = "m_nModelIndex")
{
	//m_iWorldModelIndex
	int index = GetEntProp(entity, Prop_Send, strPropName);
	GetModelPath(index, strModel, maxsize);
}

stock void AddFolderToDownloadsTable(const char[] sDirectory) 
{
	//PrintToServer("target directory: %s", sDirectory);

	char sFilename[128];
	char sPath[256];
	DirectoryListing hDirectory = OpenDirectory(sDirectory);

	if(hDirectory != null) {
		FileType Type;
		
		while(ReadDirEntry(hDirectory, sFilename, sizeof(sFilename), Type)) {
			if(Type == FileType_Directory) {
				if(FindCharInString(sFilename, '.') == -1)
				{
					Format(sPath, sizeof(sPath), "%s/%s", sDirectory, sFilename);
					AddFolderToDownloadsTable(sPath);
					//PrintToServer("added folder %s to downloads table", sPath);
				}
			}
			else if(Type == FileType_File) {
				Format(sPath, sizeof(sPath), "%s/%s", sDirectory, sFilename);
				AddFileToDownloadsTable(sPath);
				//PrintToServer("added file %s to downloads table", sPath);
				
				int iPos = FindCharInString(sPath, '.', true);
				
				if(iPos != -1) {		   
					if(StrEqual(sPath[iPos], ".mdl") || StrEqual(sPath[iPos], ".vmt")) {
						PrecacheModel(sPath, true);
					}
					else if(StrEqual(sPath[iPos], ".mp3") || StrEqual(sPath[iPos], ".wav")) {
						ReplaceStringEx(sPath, sizeof(sPath), "sound/", "");
						PrecacheSound(sPath, true);
					}
				}
			}
		}
	}
}

stock bool IsBehindAndFacingTarget(int client, int attacker)
{
	float victim_ang[3];
	float attacker_ang[3];
	GetClientAbsAngles(client, victim_ang);
	GetClientAbsAngles(attacker, attacker_ang);

	float victim_pos[3];
	float attacker_pos[3];
	GetClientAbsOrigin(client, victim_pos);
	GetClientAbsOrigin(attacker, attacker_pos);

	// Get the forward view vector of the target, ignore Z
	float victim_forward[3];
	GetAngleVectors(victim_ang, victim_forward, NULL_VECTOR, NULL_VECTOR);
	victim_forward[2] = 0.0;
	NormalizeVector(victim_forward, victim_forward);

	// Get a vector from my origin to my targets origin
	float to_target[3];
	MakeVectorFromPoints(attacker_pos, victim_pos, to_target);
	to_target[2] = 0.0;
	NormalizeVector(to_target, to_target);

	// Get a forward vector of the attacker.
	float attacker_forward[3];
	GetAngleVectors(attacker_ang, attacker_forward, NULL_VECTOR, NULL_VECTOR);
	attacker_forward[2] = 0.0;
	NormalizeVector(attacker_forward, attacker_forward);

	float dot_attacker = GetVectorDotProduct(attacker_forward, to_target);
	float dot_victim = GetVectorDotProduct(victim_forward, to_target);

	// Make sure they're actually facing the target.
	// This needs to be done because lag compensation can place target slightly behind the attacker.
	if (dot_attacker > 0.5)
		return (dot_victim > -0.1);

	return false;
}

stock bool IsClassname(int iEntity, char[] strClassname) {
	if (iEntity <= 0) return false;
	if (!IsValidEdict(iEntity)) return false;

	char strClassname2[32];
	GetEdictClassname(iEntity, strClassname2, sizeof(strClassname2));
	if (!StrEqual(strClassname, strClassname2, false)) return false;

	return true;
}

stock void GetClientPointPosition(int iClient, float endpos[3], int iMask = MASK_PLAYERSOLID) {
	float ang[3];
	float start_pos[3];
	GetClientEyePosition(iClient, start_pos);
	GetClientEyeAngles(iClient, ang);

	float direction[3];
	GetAngleVectors(ang, direction, NULL_VECTOR, NULL_VECTOR);
	ScaleVector(direction, 500.0);
	AddVectors(start_pos, direction, endpos);  

	float temp_pos[3];
	//AddVectors(endpos, temp_pos, temp_pos);
	temp_pos[0] = endpos[0];
	temp_pos[1] = endpos[1];
	temp_pos[2] = endpos[2];

	TR_TraceRayFilter(start_pos, temp_pos, iMask, RayType_EndPoint, TraceRayDontHitEntity, iClient);
	if (TR_DidHit(INVALID_HANDLE)) {
		TR_GetEndPosition(temp_pos);

		endpos[0] = temp_pos[0];
		endpos[1] = temp_pos[1];
		endpos[2] = temp_pos[2];
	}
}

stock ShowGameText(const char[] strMessage, const char[] strIcon = "leaderboard_dominated", float life = 35.0, const char[] displayTeam = "0", const char[] bg = "0")
{
    int iEntity = CreateEntityByName("game_text_tf");
    DispatchKeyValue(iEntity,"message", strMessage);
    DispatchKeyValue(iEntity,"display_to_team", displayTeam);
    DispatchKeyValue(iEntity,"icon", strIcon);
    DispatchKeyValue(iEntity,"targetname", "game_text1");
    DispatchKeyValue(iEntity,"background", bg);
    DispatchSpawn(iEntity);
    AcceptEntityInput(iEntity, "Display", iEntity, iEntity);
    CreateTimer(life, KillGameText, EntIndexToEntRef(iEntity));
}

public Action KillGameText(Handle hTimer, any iEntityRef)
{
    int iEntity = _:EntRefToEntIndex(iEntityRef);
    if ((iEntity > 0) && IsValidEntity(iEntity)) AcceptEntityInput(iEntity, "kill");

    return Plugin_Stop;
}

stock void GetBonePosition(int client, float pos[3], char[] attachment)
{
	int start_point = CreateEntityByName("info_target");
	DispatchSpawn(start_point);
	
	SetVariantString("!activator");
	AcceptEntityInput(start_point, "SetParent", client);
	SetVariantString(attachment);
	AcceptEntityInput(start_point, "SetParentAttachment", client);

	SetVariantString("");
	AcceptEntityInput(start_point, "ClearParent"); 
	GetEntPropVector(start_point, Prop_Data, "m_vecOrigin", pos);
	AcceptEntityInput(start_point, "KillHierarchy"); 
}

stock void MatrixMultiply(float out[3][3], const float a[3][3], const float b[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                out[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

stock void MatrixVectorMultiply(float out[3], const float m[3][3], const float v[3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            out[i] += m[i][j] * v[j];
        }
    }
}

stock void Rx(float mat[3][3], float angle)
{
    mat[0][0] = 1.0;
    mat[1][1] = Cosine(angle);
    mat[1][2] = Sine(angle);
    mat[2][1] = -Sine(angle);
    mat[2][2] = Cosine(angle);
}

stock void Ry(float mat[3][3], float angle)
{
    mat[0][0] = Cosine(angle);
    mat[0][2] = -Sine(angle);
    mat[1][1] = 1.0;
    mat[2][0] = Sine(angle);
    mat[2][2] = Cosine(angle);
}

stock void Rz(float mat[3][3], float angle)
{
    mat[0][0] = Cosine(angle);
    mat[0][1] = Sine(angle);
    mat[1][0] = -Sine(angle);
    mat[1][1] = Cosine(angle);
    mat[2][2] = 1.0;
}

stock void RotatePoint(float out[3], const float p[3], const float ang[3])
{
    float rx[3][3], ry[3][3], rz[3][3], r[3][3], rfinal[3][3], angles[3];
    
    angles = ang;
    ScaleVector(angles, FLOAT_PI / 180.0);
    
    Ry(ry, angles[0]);

    Rz(rz, angles[1]);
    
    Rx(rx, angles[2]);
    
    MatrixMultiply(r, rz, ry);
    MatrixMultiply(rfinal, r, rx);
    MatrixVectorMultiply(out, rfinal, p);
}

stock bool IsEntityInSphere(int ent, const float p[3], float radius, bool rotate = true, bool add_zpos = true)
{
    float origin[3], mins[3], maxs[3], point[3];
    GetEntPropVector(ent, Prop_Data, "m_vecOrigin", origin);
    GetEntPropVector(ent, Prop_Data, "m_vecMins", mins);
    GetEntPropVector(ent, Prop_Data, "m_vecMaxs", maxs);
    if (add_zpos) {
    	origin[2] += maxs[2] * 0.5;
    }

    SubtractVectors(p, origin, point);
    
    float rpoint[3];
    
    if(!(ent > 0 && ent <= MAXPLAYERS) && rotate) {
        float angles[3];
        GetEntPropVector(ent, Prop_Data, "m_angRotation", angles);
        RotatePoint(rpoint, point, angles);
    }
    else {
        rpoint = point;
    }
    
    float p1[3] =  { 0.0, 0.0, 0.0 };
    
    for (new i = 0; i < 3; i++) {
        if (rpoint[i] > maxs[i])
        {
            p1[i] = maxs[i];
        }
        else if (rpoint[i] < mins[i])
        {
            p1[i] = mins[i];
        }
        else
        {
            rpoint[i] = 0.0;
        }
    }

    return GetVectorDistance(p1, rpoint) < radius;
}  