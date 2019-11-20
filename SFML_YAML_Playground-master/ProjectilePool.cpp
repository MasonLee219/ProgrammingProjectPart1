#include "ProjectilePool.h"


Projectile* ProjectilePool::create()
{
	//assigns each projectile into the pool to p BY REFERENCE
	for (int i = 0; i< 20; i++)
	{
		if (!m_projectiles[i].onScreen())
		{
			//m_projectilePool[i].init(t_x, t_y, t_xVel, t_yVel, t_rotation);	
			return &m_projectiles[i];
		}
	}
	return nullptr;
}
