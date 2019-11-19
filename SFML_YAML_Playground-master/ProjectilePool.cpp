#include "ProjectilePool.h"

int ProjectilePool::m_onScreenCount = 0;

Projectile* ProjectilePool::create()
{
	//assigns each projectile into the pool to p BY REFERENCE
	for (Projectile& p : m_pool)
	{
		if (p.onScreen() == false)
		{
			m_onScreenCount++;
			return &p;
		}
	}
	return nullptr;
}

int ProjectilePool::onScreen()
{
	return m_onScreenCount;
}