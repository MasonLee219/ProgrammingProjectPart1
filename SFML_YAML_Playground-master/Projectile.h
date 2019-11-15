#pragma once
#include <SFML/Graphics.hpp>
#include "MathUtility.h"

class Projectile
{
public:
	friend class ProjectilePool;

	bool inUse();
	Projectile(double speed, sf::Vector2f vector)
	{
		this->projectileSpeed = speed;
		this->unitVector = vector;	
	}
	~Projectile();

	double const PROJECTILE_SPEED = { 50.0 };
	double projectileSpeed = { 0.0 };
	sf::Vector2f unitVector;

}; 
