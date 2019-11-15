#include "Game.h"
#include <iostream>


// Updates per milliseconds
static double const MS_PER_UPDATE = 10.0;

////////////////////////////////////////////////////////////
Game::Game()
	: m_window(sf::VideoMode(ScreenSize::s_height, ScreenSize::s_width, 32), "SFML Playground", sf::Style::Default)
	, m_Tank(m_spriteSheetTexture, m_wallSprites)
{
	//m_window.setVerticalSyncEnabled(true);

	int currentLevel = 1;

	// Invokes our level loader to read the YAML data - will generate an exception if level loading fails.
	try
	{
		LevelLoader::load(currentLevel, m_level);
	}
	catch (std::exception& e)
	{
		std::cout << "Level Loading failure." << std::endl;
		std::cout << e.what() << std::endl;
		throw e;
	}

	m_Tank.setPosition(m_level.m_tank.m_position);
	//if (!m_playerTexture.loadFromFile("./resources/images/E-100.png"));
	//m_player.setTexture(m_playerTexture);

	if (!m_spriteSheetTexture.loadFromFile("./resources/images/SpriteSheet.png"))
	{
		std::string s("Error loading texture");
		throw std::exception(s.c_str());
	}

	if (!m_backgroundTexture.loadFromFile(m_level.m_background.m_fileName));
	m_background.setTexture(m_backgroundTexture);


	generateWalls();
}

////////////////////////////////////////////////////////////
void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;

	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();

		lag += dt.asMilliseconds();

		processEvents();

		while (lag > MS_PER_UPDATE)
		{
			update(MS_PER_UPDATE);
			lag -= MS_PER_UPDATE;
		}
		update(MS_PER_UPDATE);

		render();
	}
}

////////////////////////////////////////////////////////////
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		processGameEvents(event);
	}
}

////////////////////////////////////////////////////////////
void Game::processGameEvents(sf::Event& event)
{
	// check if the event is a a mouse button release
	if (sf::Event::KeyPressed == event.type)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			m_window.close();
			break;
		default:
			break;
		}
	}
}
////////////////////////////////////////////////////////////
void Game::update(double dt)
{
	m_Tank.update(dt);
}

////////////////////////////////////////////////////////////
void Game::render()
{
	m_window.clear(sf::Color(0, 0, 0, 0));
	m_window.draw(m_background);	
	//int i = 0;

	/*for (int i = 0; i < m_sprites.size(); i++)
	{
		m_window.draw(m_sprites.at(i));
	}*/

	for (sf::Sprite & sprite : m_sprites)
	{
		//m_sprites.at(i), where i is the amount of sprites drawn
		m_window.draw(sprite);
		//i++;
	}
	for (sf::Sprite& sprite : m_wallSprites)
	{
		m_window.draw(sprite);
	}
	m_Tank.render(m_window);
	m_window.display();
}

////////////////////////////////////////////////////////////
void Game::generateWalls()
{
	sf::IntRect wallRect(2, 129, 33, 23);
	// Create the Walls 
	for (ObstacleData const& obstacle : m_level.m_obstacles)
	{
		sf::Sprite sprite;
		sprite.setTexture(m_spriteSheetTexture);
		sprite.setTextureRect(wallRect);
		sprite.setOrigin(wallRect.width / 2.0, wallRect.height / 2.0);
		sprite.setPosition(obstacle.m_position);
		sprite.setRotation(obstacle.m_rotation);
		m_wallSprites.push_back(sprite);
	}
}





