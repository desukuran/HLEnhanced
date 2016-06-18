/***
*
*	Copyright (c) 1996-2001, Valve LLC. All rights reserved.
*	
*	This product contains software technology licensed from Id 
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc. 
*	All Rights Reserved.
*
*   This source code contains proprietary and confidential information of
*   Valve LLC and its suppliers.  Access to this code is restricted to
*   persons who have executed a written SDK license with Valve.  Any access,
*   use or distribution of this code by or to any unlicensed person is illegal.
*
****/
//=========================================================
// monster template
//=========================================================
//TODO: this shouldn't be in the codebase. Move it somewhere else - Solokiller
#if 0

#include	"extdll.h"
#include	"util.h"
#include	"cbase.h"
#include	"entities/NPCs/Monsters.h"
#include	"entities/NPCs/Schedule.h"

//=========================================================
// Monster's Anim Events Go Here
//=========================================================

class CMyMonster : public CBaseMonster
{
public:
	DECLARE_CLASS( CMyMonster, CBaseMonster );

	void Spawn( void ) override;
	void Precache( void ) override;
	void SetYawSpeed( void ) override;
	int  Classify ( void ) override;
	void HandleAnimEvent( MonsterEvent_t *pEvent ) override;
};
LINK_ENTITY_TO_CLASS( my_monster, CMyMonster );

//=========================================================
// Classify - indicates this monster's place in the 
// relationship table.
//=========================================================
int	CMyMonster :: Classify ( void )
{
	return	CLASS_MY_MONSTER;
}

//=========================================================
// SetYawSpeed - allows each sequence to have a different
// turn rate associated with it.
//=========================================================
void CMyMonster :: SetYawSpeed ( void )
{
	int ys;

	switch ( m_Activity )
	{
	case ACT_IDLE:
	default:
		ys = 90;
	}

	pev->yaw_speed = ys;
}

//=========================================================
// HandleAnimEvent - catches the monster-specific messages
// that occur when tagged animation frames are played.
//=========================================================
void CMyMonster :: HandleAnimEvent( MonsterEvent_t *pEvent )
{
	switch( pEvent->event )
	{
	case 0:
	default:
		CBaseMonster::HandleAnimEvent( pEvent );
		break;
	}
}

//=========================================================
// Spawn
//=========================================================
void CMyMonster :: Spawn()
{
	Precache( );

	SET_MODEL(ENT(pev), "models/mymodel.mdl");
	UTIL_SetSize( pev, Vector( -12, -12, 0 ), Vector( 12, 12, 24 ) );

	pev->solid			= SOLID_SLIDEBOX;
	pev->movetype		= MOVETYPE_STEP;
	m_bloodColor		= BLOOD_COLOR_GREEN;
	pev->health			= 8;
	pev->view_ofs		= Vector ( 0, 0, 0 );// position of the eyes relative to monster's origin.
	m_flFieldOfView		= 0.5;// indicates the width of this monster's forward view cone ( as a dotproduct result )
	m_MonsterState		= MONSTERSTATE_NONE;

	MonsterInit();
}

//=========================================================
// Precache - precaches all resources this monster needs
//=========================================================
void CMyMonster :: Precache()
{
	PRECACHE_SOUND("mysound.wav");

	PRECACHE_MODEL("models/mymodel.mdl");
}	

//=========================================================
// AI Schedules Specific to this monster
//=========================================================
#endif 0
