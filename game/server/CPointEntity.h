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
#ifndef GAME_SERVER_CPOINTENTITY_H
#define GAME_SERVER_CPOINTENTITY_H

class CPointEntity : public CBaseEntity
{
public:
	DECLARE_CLASS( CPointEntity, CBaseEntity );

	void	Spawn( void ) override;
	virtual int	ObjectCaps( void ) override { return CBaseEntity::ObjectCaps() & ~FCAP_ACROSS_TRANSITION; }
private:
};

#endif //GAME_SERVER_CPOINTENTITY_H