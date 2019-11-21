#include "Projectile.h"
#include "CollisionDetector.h"
Projectile::Projectile(std::vector<sf::Sprite>* wallSprites,double t_x, double t_y, float t_rotation) : m_x(t_x), m_y(t_y),
	m_rotation(t_rotation), m_wallSprites(wallSprites)
{
	m_xVel = cos((m_rotation * DEG_TO_RAD)) * m_projectileSpeed;
	m_yVel = sin((m_rotation * DEG_TO_RAD)) * m_projectileSpeed;
	loadTexture();
	initSprite();
}

void Projectile::init(double t_x, double t_y, float t_rotation)
{
	m_x = t_x;
	m_y = t_y;
	m_xVel = cos((t_rotation * DEG_TO_RAD)) * m_projectileSpeed;
	m_yVel = sin((t_rotation * DEG_TO_RAD)) * m_projectileSpeed;
}

bool Projectile::checkWallCollision(std::vector<sf::Sprite>* wallSprites)
{
	for (sf::Sprite const& sprite : *m_wallSprites)
	{
		// Checks if either the tank base or turret has collided with the current wall sprite.
		if (CollisionDetector::collision(m_projectileSprite, sprite))
		{
			return true;
		}
	}
	return false;
}


void Projectile::update(double dt, std::vector<sf::Sprite>* wallSprites)
{
	
	m_directionUnitVect = thor::rotatedVector(sf::Vector2f(1.0f, 0.0f), static_cast<float>(m_rotation));

	double newX = m_directionUnitVect.x * m_projectileSpeed * (dt / 1000);
	double newY = m_directionUnitVect.y * m_projectileSpeed * (dt / 1000);

	m_projectileSprite.move(newX, newY);

	if (checkWallCollision(wallSprites) || m_projectileSpeed == 0)
	{
		m_projectileSprite.setPosition(sf::Vector2f(-1000, -1000));
	}
	m_x = m_projectileSprite.getPosition().x;
	m_y = m_projectileSprite.getPosition().y;
}
bool Projectile::onScreen()
{
	if (m_x >= 0 && m_x < SCREEN_WIDTH && m_y >= 0 && m_y < SCREEN_HEIGHT)
	{
		return true;
	}
	return false;
}

void Projectile::loadTexture()
{
	sf::IntRect rect(7, 177, 6, 9);
	if (!m_texture.loadFromFile("./resources/images/SpriteSheet.png"))
	{
		std::string s("Error loading texture");
		throw std::exception(s.c_str());
	}

	m_projectileSprite.setTexture(m_texture);
	m_projectileSprite.setTextureRect(rect);
}

void Projectile::initSprite()
{
	m_projectileSprite.setOrigin(m_x,m_y);
}

void Projectile::render(sf::RenderWindow& window)
{
	m_projectileSprite.setPosition(sf::Vector2f(m_x, m_y));
	window.draw(m_projectileSprite);
}


