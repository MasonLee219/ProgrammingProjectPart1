#pragma once
#include <SFML/Graphics.hpp>
#include "MathUtility.h"

class Projectile
{
public:
	friend class ProjectilePool;

	void init(double t_x, double t_y, double t_xVel, double t_yVel, float t_rotation);
	void update();

	bool onScreen();
	
	static const int SCREEN_WIDTH{ 800 };
	static const int SCREEN_HEIGHT{ 600 };

private:
	
	Projectile() = default;
	double m_projectileSpeed{ 500.0 };
	double m_x{ -1.0 };
	double m_y{ -1.0};

	double m_xVel{ 0.0 };
	double m_yVel{ 0.0};
	double const DEG_TO_RAD = thor::Pi / 180.0f;
}; 
