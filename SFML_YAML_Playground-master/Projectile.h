#pragma once
#include <SFML/Graphics.hpp>
#include "MathUtility.h"

class Projectile
{
public:
	friend class ProjectilePool;
	Projectile(std::vector<sf::Sprite> *wallSprites = nullptr, double t_x = -1 , double t_y = -1 , float t_rotation = 0);
	void init(double t_x, double t_y, float t_rotation);
	void update(double dt, std::vector<sf::Sprite>* wallSprites);

	bool onScreen();
	bool checkWallCollision(std::vector<sf::Sprite>* wallSprites);
	void loadTexture();
	void initSprite();
	void render(sf::RenderWindow& window);

private:
	sf::Sprite m_projectileSprite;
	std::vector<sf::Sprite>* m_wallSprites;
	sf::Texture  m_texture;
	double m_x{ -1.0 };
	double m_y{ -1.0};

	sf::Vector2f m_directionUnitVect;
	double m_xVel{ 0.0 };
	double m_yVel{ 0.0};
	double m_rotation;
	double const DEG_TO_RAD = thor::Pi / 180.0f;
	static const int SCREEN_WIDTH{ 1440 };
	static const int SCREEN_HEIGHT{ 900 };
	double m_projectileSpeed{ 500.0 };
}; 
