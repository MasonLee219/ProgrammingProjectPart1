#include "Projectile.h"

void Projectile::init(double t_x, double t_y, double t_xVel, double t_yVel, float t_rotation)
{
	m_x = t_x;
	m_y = t_y;
	m_xVel = cos((t_rotation * DEG_TO_RAD)) * m_projectileSpeed;
	m_yVel = sin((t_rotation * DEG_TO_RAD)) * m_projectileSpeed;
}

void Projectile::update()
{
	m_x += m_xVel;
	m_y += m_yVel;
}
