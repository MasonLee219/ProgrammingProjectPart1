#pragma once
#include <SFML/Graphics.hpp>
#include "MathUtility.h"
#include "ProjectilePool.h"
#include "LevelLoader.h"
#include <ctime>

using namespace std;
/// <summary>
/// @brief A simple tank controller.
/// 
/// This class will manage all tank movement and rotations.
/// </summary>
class Tank
{
public:
	/// <summary>
	/// @brief Constructor that stores drawable state (texture, sprite) for the tank.
	/// Stores references to the texture and container of wall sprites. 
	/// Creates sprites for the tank base and turret from the supplied texture.
	/// </summary>
	/// <param name="texture">A reference to the sprite sheet texture</param>
	///< param name="texture">A reference to the container of wall sprites</param>  
	Tank::Tank(sf::Texture const& texture, std::vector<sf::Sprite>& wallSprites);
	void update(double dt);
	void render(sf::RenderWindow& window);

	void setPosition(sf::Vector2f t_pos);

	/// <summary>
	/// @brief Increases the speed by 1, max speed is capped at 100.
	/// 
	/// </summary>
	void increaseSpeed();

	/// <summary>
	/// @brief Decreases the speed by 1, min speed is capped at -100.
	/// 
	/// </summary>
	void decreaseSpeed();

	/// <summary>
	/// @brief Increases the rotation by 1 degree, wraps to 0 degrees after 359.
	/// 
	/// </summary>
	void increaseRotation();

	/// <summary>
	/// @brief Decreases the rotation by 1 degree, wraps to 359 degrees after 0.
	/// 
	/// </summary>
	void decreaseRotation();
	void increaseTurretRotation();
	void decreaseTurretRotation();
	void centreTurret();

	/// <summary>
	/// @brief Checks for collisions between the tank and the walls.
	/// 
	/// </summary>
	/// <returns>True if collision detected between tank and wall.</returns>
	bool checkWallCollision();

	/// <summary>
/// @brief Stops the tank if moving and applies a small increase in speed in the opposite direction of travel.
/// If the tank speed is currently 0, the rotation is set to a value that is less than the previous rotation value
///  (scenario: tank is stopped and rotates into a wall, so it gets rotated towards the opposite direction).
/// If the tank is moving, further rotations are disabled and the previous tank position is restored.
/// The tank speed is adjusted so that it will travel slowly in the opposite direction. The tank rotation 
///  is also adjusted as above if necessary (scenario: tank is both moving and rotating, upon wall collision it's 
///  speed is reversed but with a smaller magnitude, while it is rotated in the opposite direction of it's 
///  pre-collision rotation).
/// </summary>
	void deflect();

	void m_updateProjectile(double dt);

	void setTankPos(LevelData level1);

	/// <summary>
	/// @brief Processes control keys and applies speed/rotation as appropriate.
	/// </summary>
	void handleKeyInput()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			increaseSpeed();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			decreaseSpeed();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			decreaseRotation();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			increaseRotation();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			decreaseTurretRotation();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			increaseTurretRotation();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			centreTurret();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (readyToFire)
			{
				m_projectileUnitVec = sf::Vector2f(1, 0);
				std::cout << "BRRRRT" << endl;
			}
		}
	}


private:
	void initSprites(sf::Vector2f const& pos);
	ProjectilePool m_projectilePool;
	
	sf::Sprite m_tankBase;
	sf::Sprite m_turret;
	sf::Texture const& m_texture;
	

	// A reference to the container of wall sprites.
	std::vector<sf::Sprite>& m_wallSprites;

	// The tank speed.
	double m_speed{ 0.0 };

	// The current rotation as applied to tank base.
	double m_rotation{ 0.0 };
	double m_previousRotation{ 0.0 };
	double m_turretRotation{ 0.0 };
	double m_previousTurretRotation{ 0.0 };

	void adjustRotation();
	void getPrevious();
	bool checkFireReady();
	
	sf::Vector2f m_spawnPositions[4];
	sf::Vector2f m_spawnPosition;
	sf::Vector2f m_previousPosition;
	double m_previousSpeed{ 0.0 };

	sf::Sprite m_projectile;
	sf::Vector2f m_projectileUnitVec{ -1, -1 };
	int m_triggerTimer = { 0 };
	const int m_FIRE_RATE{ 90 };
	bool m_enableRotation = true;
	double const m_projectileSpeed = { 90.0 };
	bool readyToFire{true};
};
