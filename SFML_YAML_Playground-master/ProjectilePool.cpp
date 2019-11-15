#include "ProjectilePool.h"

Projectile* ProjectilePool::create()
{
	//assigns each projectile into the pool to p BY REFERENCE
	for (Projectile& p : m_pool)
	{
		if (p.onScreen() == false)
		{
			m_onScreenCount++;
			return &
		}
	}

}

int ProjectilePool::onScreen()
{
	return m_onScreenCount;
}