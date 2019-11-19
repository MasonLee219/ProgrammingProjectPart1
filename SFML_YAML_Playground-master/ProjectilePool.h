#pragma once
#include "Projectile.h"
class ProjectilePool
{
public:
	Projectile* create(double t_x, double t_y, double t_xVel, double t_yVel, float t_rotation);

	static int onScreen();

private:
	Projectile m_projectilePool[20];
	//keeps track of how many particles are on screen
	static int m_onScreenCount;
};

