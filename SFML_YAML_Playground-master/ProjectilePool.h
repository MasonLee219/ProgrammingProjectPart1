#pragma once
#include "Projectile.h"
class ProjectilePool
{
public:
	Projectile* create();

	static int onScreen();

private:
	Projectile m_projectilePool[20];
	//keeps track of how many particles are on screen
	static int m_onScreenCount;
};

