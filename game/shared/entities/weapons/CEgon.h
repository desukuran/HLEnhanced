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
#ifndef GAME_SHARED_ENTITIES_WEAPONS_CEGON_H
#define GAME_SHARED_ENTITIES_WEAPONS_CEGON_H

class CEgon : public CBasePlayerWeapon
{
public:
	DECLARE_CLASS( CEgon, CBasePlayerWeapon );
#ifndef CLIENT_DLL
	DECLARE_DATADESC();
#endif

	void Spawn( void ) override;
	void Precache( void ) override;
	int iItemSlot( void ) override { return 4; }
	bool GetItemInfo( ItemInfo* p ) override;
	bool AddToPlayer( CBasePlayer *pPlayer ) override;

	bool Deploy() override;
	void Holster( int skiplocal = 0 ) override;

	void UpdateEffect( const Vector &startPoint, const Vector &endPoint, float timeBlend );

	void CreateEffect( void );
	void DestroyEffect( void );

	void EndAttack( void );
	void Attack( void );
	void PrimaryAttack( void ) override;
	void WeaponIdle( void ) override;

	float m_flAmmoUseTime;// since we use < 1 point of ammo per update, we subtract ammo on a timer.

	float GetPulseInterval( void );
	float GetDischargeInterval( void );

	void Fire( const Vector &vecOrigSrc, const Vector &vecDir );

	bool HasAmmo() const;

	void UseAmmo( int count );

	void GetWeaponData( weapon_data_t& data ) override
	{
		BaseClass::GetWeaponData( data );

		data.iuser3 = m_fireState;
	}

	void SetWeaponData( const weapon_data_t& data ) override
	{
		BaseClass::SetWeaponData( data );

		m_fireState = data.iuser3;
	}

	enum EGON_FIREMODE { FIRE_NARROW, FIRE_WIDE };

	enum EGON_FIRESTATE { FIRE_OFF, FIRE_CHARGE };

	CBeam				*m_pBeam;
	CBeam				*m_pNoise;
	CSprite				*m_pSprite;

	virtual bool UseDecrement() const override
	{
#if defined( CLIENT_WEAPONS )
		return true;
#else
		return false;
#endif
	}

	unsigned short m_usEgonStop;

private:
	float				m_shootTime;
	EGON_FIREMODE		m_fireMode;
	int					m_fireState;
	float				m_shakeTime;
	bool				m_deployed;

	unsigned short m_usEgonFire;
};

#endif //GAME_SHARED_ENTITIES_WEAPONS_CEGON_H