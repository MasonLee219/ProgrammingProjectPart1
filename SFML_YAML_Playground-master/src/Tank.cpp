#include "Tank.h"
#include "CollisionDetector.h"

Tank::Tank(sf::Texture const& texture, std::vector<sf::Sprite>& wallSprites)
	: m_texture(texture)
	, m_wallSprites(wallSprites)
{
	// Initialises the tank base and turret sprites.
	initSprites(sf::Vector2f(0,0));
}
/// <summary>
/// @brief Processes control keys and applies speed/rotation as appropriate.
/// </summary>


void Tank::update(double dt)
{
	handleKeyInput();
	if (checkWallCollision())
	{
		deflect();
	}
	
	double x = m_tankBase.getPosition().x + std::cos(MathUtility::DEG_TO_RAD * m_rotation) * m_speed * (dt / 1000);

	double y = m_tankBase.getPosition().y + std::sin(MathUtility::DEG_TO_RAD * m_rotation) * m_speed * (dt / 1000);

	
	
	m_tankBase.setRotation(m_rotation);
	m_turret.setRotation(m_turretRotation);
	m_tankBase.setPosition(x, y);
	m_turret.setPosition(m_tankBase.getPosition());

	getPrevious();
	
	m_speed *= 0.99;
	

	m_speed = std::clamp(m_speed, -50.0, 50.0);
}

void Tank::render(sf::RenderWindow& window)
{
	window.draw(m_tankBase);
	window.draw(m_turret);
}


void Tank::initSprites(sf::Vector2f const& pos)
{
	// Initialise the tank base
	m_tankBase.setTexture(m_texture);
	sf::IntRect baseRect(2, 43, 79, 43);
	m_tankBase.setTextureRect(baseRect);
	m_tankBase.setOrigin(baseRect.width / 2.0, baseRect.height / 2.0);
	m_tankBase.setPosition(pos);

	// Initialise the turret
	m_turret.setTexture(m_texture);
	sf::IntRect turretRect(19, 1, 83, 31);
	m_turret.setTextureRect(turretRect);
	m_turret.setOrigin(turretRect.width / 3.0, turretRect.height / 2.0);
	m_turret.setPosition(pos);

}

////////////////////////////////////////////////////////////
void Tank::increaseSpeed()
{
	m_speed += 1.5;
}

////////////////////////////////////////////////////////////
void Tank::decreaseSpeed()
{
	m_speed -= 1.5;
}

////////////////////////////////////////////////////////////
void Tank::increaseRotation()
{
	m_previousRotation = m_rotation; // NEW
	m_rotation += 1;
	if (m_rotation == 360.0)
	{
		m_rotation = 0;
	}
}

////////////////////////////////////////////////////////////
void Tank::decreaseRotation()
{
	m_previousRotation = m_rotation; // NEW
	m_rotation -= 1;
	if (m_rotation == 0.0)
	{
		m_rotation = 359.0;
	}
}

void Tank::increaseTurretRotation()
{
	m_previousTurretRotation = m_turretRotation;
	m_turretRotation += 1;
	if (m_turretRotation == 360.0)
	{
		m_turretRotation = 0.0;
	}
}

void Tank::decreaseTurretRotation()
{
	m_previousTurretRotation = m_turretRotation;
	m_turretRotation -= 1;
	if (m_turretRotation == 0.0)
	{
		m_turretRotation = 359.0;
	}
}

void Tank::centreTurret()
{
	m_turretRotation = m_rotation;
}

void Tank::setPosition(sf::Vector2f t_pos)
{
	m_tankBase.setPosition(t_pos);
}

////////////////////////////////////////////////////////////
bool Tank::checkWallCollision()
{
	for (sf::Sprite const& sprite : m_wallSprites)
	{
		// Checks if either the tank base or turret has collided with the current wall sprite.
		if (CollisionDetector::collision(m_turret, sprite) ||
			CollisionDetector::collision(m_tankBase, sprite))
		{
			return true;
		}
	}
	return false;
}

////////////////////////////////////////////////////////////
void Tank::adjustRotation()
{
	// If tank was rotating...
	if (m_rotation != m_previousRotation)
	{
		// Work out which direction to rotate the tank base post-collision.
		if (m_rotation > m_previousRotation)
		{
			m_rotation = m_previousRotation - 1;
		}
		else
		{
			m_rotation = m_previousRotation + 1;
		}
	}
	// If turret was rotating while tank was moving
	if (m_turretRotation != m_previousTurretRotation)
	{
		// Set the turret rotation back to it's pre-collision value.
		m_turretRotation = m_previousTurretRotation;
	}
}

void Tank::deflect()
{
	// In case tank was rotating.
	adjustRotation();

	// If tank was moving.
	if (m_speed != 0)
	{
		// Temporarily disable turret rotations on collision.
		m_enableRotation = false;
		// Back up to position in previous frame.
		m_tankBase.setPosition(m_previousPosition);
		// Apply small force in opposite direction of travel.
		if (m_previousSpeed < 0)
		{
			m_speed = 8;
		}
		else
		{
			m_speed = -8;
		}
	}
}

void Tank::getPrevious()
{
	m_previousPosition = m_tankBase.getPosition();
	

}


