#include "Projectile.h"

void Projectile::init(int t_x, int t_y, int t_xVel, int t_yVel)
{
	m_x = t_x;
	m_y = t_y;
	m_xVel = t_xVel;
	m_yVel = t_yVel;
}

void Projectile::update()
{
	m_x += m_xVel;
	m_y += m_yVel;
}
