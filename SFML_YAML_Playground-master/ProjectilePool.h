#pragma once
#include "Projectile.h"
class ProjectilePool
{
public:
	Projectile* create(double t_x, double t_y, float t_rotation);

private:
	Projectile m_projectiles[20];
	//keeps track of how many particles are on screen
	 int m_onScreenCount;
};

