#include "Projectile.h"

Projectile::Projectile(double t_x, double t_y, float t_rotation) : m_x(t_x), m_y(t_y),
	m_rotation(t_rotation)
{
	m_xVel = cos((m_rotation * DEG_TO_RAD)) * m_projectileSpeed;
	m_yVel = sin((m_rotation * DEG_TO_RAD)) * m_projectileSpeed;
}

void Projectile::init(double t_x, double t_y, float t_rotation)
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

bool Projectile::onScreen()
{
	return false;
}

void Projectile::loadTexture()
{
	if (!m_texture.loadFromFile("./resources/images/SpriteSheet.png"))
	{
		std::string s("Error loading texture");
		throw std::exception(s.c_str());
	}
}

void Projectile::initSprite()
{
	m_projectileSprite.setTexture(m_texture);
	sf::IntRect rect(7, 177, 6, 9);

	m_projectileSprite.setTextureRect(rect);
	m_projectileSprite.setOrigin(m_x,m_y);
}


