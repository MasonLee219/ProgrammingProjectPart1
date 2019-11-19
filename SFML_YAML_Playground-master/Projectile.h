#pragma once
#include <SFML/Graphics.hpp>
#include "MathUtility.h"

class Projectile
{
public:
	friend class ProjectilePool;

	void init(int t_x, int t_y, int t_xVel, int t_yVel);
	void update();

	bool onScreen() const;
	
	static const int SCREEN_WIDTH{ 800 };
	static const int SCREEN_HEIGHT{ 600 };

private:
	
	Projectile() = default;
	int m_x{ -1 };
	int m_y{ -1 };

	int m_xVel{ 0 };
	int m_yVel{ 0 };
}; 
