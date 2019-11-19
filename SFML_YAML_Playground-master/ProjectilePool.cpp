#include "ProjectilePool.h"

int ProjectilePool::m_onScreenCount = 0;

Projectile* ProjectilePool::create(double t_x, double t_y, double t_xVel, double t_yVel, float t_rotation)
{
	//assigns each projectile into the pool to p BY REFERENCE
	for (int i = 0; i< 20; i++)
	{
		if (!m_projectilePool[i].onScreen())
		{
			m_projectilePool[i].init(t_x, t_y, t_xVel, t_yVel, t_rotation);	
			return;
		}
	}
	return nullptr;
}

int ProjectilePool::onScreen()
{
	return m_onScreenCount;
}