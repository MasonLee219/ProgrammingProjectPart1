#pragma once
#include "Projectile.h"
class ProjectilePool
{
public:
	ProjectilePool();
	Projectile* create(double t_x, double t_y, float t_rotation);
	void render(sf::RenderWindow& window);
	void update(double dt,std::vector<sf::Sprite>* wallSprites);
private:
	Projectile m_projectiles[20];
	//keeps track of how many particles are on screen
	 int m_onScreenCount;
	 
};

