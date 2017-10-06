/***
*
*	Copyright (c) 1996-2001, Valve LLC. All rights reserved.
*
*	This product contains software technology licensed from Id
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc.
*	All Rights Reserved.
*
*   Use, distribution, and modification of this source code and/or resulting
*   object code is restricted to non-commercial enhancements to products from
*   Valve LLC.  All other use, distribution, or modification is prohibited
*   without written permission from Valve LLC.
*
****/
#include "extdll.h"
#include "util.h"
#include "cbase.h"

#include "CFuncConveyor.h"

LINK_ENTITY_TO_CLASS( func_conveyor, CFuncConveyor );

void CFuncConveyor::Spawn( void )
{
	SetMovedir( this );
	CFuncWall::Spawn();

	if( !( pev->spawnflags & SF_CONVEYOR_VISUAL ) )
		SetBits( pev->flags, FL_CONVEYOR );

	// HACKHACK - This is to allow for some special effects
	if( pev->spawnflags & SF_CONVEYOR_NOTSOLID )
	{
		SetSolidType( SOLID_NOT );
		pev->skin = 0;		// Don't want the engine thinking we've got special contents on this brush
	}

	if( pev->speed == 0 )
		pev->speed = 100;

	UpdateSpeed( pev->speed );
}

void CFuncConveyor::Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value )
{
	pev->speed = -pev->speed;
	UpdateSpeed( pev->speed );
}

// HACKHACK -- This is ugly, but encode the speed in the rendercolor to avoid adding more data to the network stream
void CFuncConveyor::UpdateSpeed( float speed )
{
	// Encode it as an integer with 4 fractional bits
	int speedCode = ( int ) ( fabs( speed ) * 16.0 );

	if( speed < 0 )
		pev->rendercolor.x = 1;
	else
		pev->rendercolor.x = 0;

	pev->rendercolor.y = ( speedCode >> 8 );
	pev->rendercolor.z = ( speedCode & 0xFF );
}