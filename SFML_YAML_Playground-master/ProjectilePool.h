#pragma once
#include "Projectile.h"
class ProjectilePool
{
public:
	Projectile* create();

private:
	Projectile m_projectiles[20];
	//keeps track of how many particles are on screen
	 int m_onScreenCount;
};

