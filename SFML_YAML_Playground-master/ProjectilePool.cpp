#include "ProjectilePool.h"


Projectile* ProjectilePool::create(double t_x, double t_y, float t_rotation)
{
	//assigns each projectile into the pool to p BY REFERENCE
	for (int i = 0; i< 20; i++)
	{
		if (!m_projectiles[i].onScreen())
		{
			m_projectiles[i].init(t_x, t_y, t_rotation);	
			return &m_projectiles[i];
		}
	}
	return nullptr;
}

void ProjectilePool::render(sf::RenderWindow& window)
{
	for (int i = 0; i < 20; i++)
	{
		if (m_projectiles[i].onScreen())
		{
			m_projectiles[i].render(window);
		}
	}
}
