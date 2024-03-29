#pragma once

#include <SFML/Graphics.hpp>
#include "ScreenSize.h"
#include "LevelLoader.h"
#include "MathUtility.h"
#include "Tank.h"

/// <summary>
/// @author RP
/// @date September 2019
/// @version 1.0
/// 
/// </summary>

/// <summary>
/// @brief Main class for the SFML Playground project.
/// 
/// This example illustrates how to parse YAML data inside an SFML environment. 
/// Example usage:
///		Game game;
///		game.run();
/// </summary>

class Game
{
public:
	/// <summary>
	/// @brief Default constructor that initialises the SFML window, 
	///   and sets vertical sync enabled. 
	/// </summary>
	Game();

	/// <summary>
	/// @brief the main game loop.
	/// 
	/// A complete loop involves processing SFML events, updating and drawing all game objects.
	/// The actual elapsed time for a single game loop results (lag) is stored. If this value is 
	///  greater than the notional time for one loop (MS_PER_UPDATE), then additional updates will be 
	///  performed until the lag is less than the notional time for one loop.
	/// The target is one update and one render cycle per game loop, but slower PCs may 
	///  perform more update than render operations in one loop.
	/// </summary>
	void run();

protected:
	/// <summary>
	/// @brief Placeholder to perform updates to all game objects.
	/// </summary>
	/// <param name="time">update delta time</param>
	void update(double dt);

	/// <summary>
	/// @brief Draws the background and foreground game objects in the SFML window.
	/// The render window is always cleared to black before anything is drawn.
	/// </summary>
	void render();

	/// <summary>
	/// @brief Checks for events.
	/// Allows window to function and exit. 
	/// Events are passed on to the Game::processGameEvents() method.
	/// </summary>	
	void processEvents();

	/// <summary>
	/// @brief Handles all user input.
	/// </summary>
	/// <param name="event">system event</param>
	void processGameEvents(sf::Event& event);

	/// <summary>
	/// @brief Creates the wall sprites and loads them into a vector.
	/// Note that sf::Sprite is considered a light weight class, so 
	///  storing copies (instead of pointers to sf::Sprite) in std::vector is acceptable.
	/// </summary>
	void generateWalls();

	void generateTargets();

	// main window
	sf::RenderWindow m_window;

private:
	// To store the game level data.
	Tank m_Tank;
	LevelData m_level;
	ProjectilePool m_projectilePool;
	sf::Clock m_gameClock;
	sf::Time m_gameTime = sf::seconds(0);

	sf::Font font;

	sf::Text m_gameTimeDisplay;
	sf::Text m_gameScoreDisplay;
	int m_gameScore = 0;

	sf::Sprite m_background;
	sf::Texture m_backgroundTexture;

	std::vector<sf::Sprite>  m_sprites;

	// Wall sprites
	std::vector<sf::Sprite> m_wallSprites;

	//Target sprite and texture
	sf::Texture m_targetTexture;
	std::vector<sf::Sprite> m_targetSprites;

	// Projectile sprite
	std::vector<sf::Sprite> m_projectileSprites;
	
	// A texture for the sprite sheet
	sf::Texture m_spriteSheetTexture;
};
