#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "yaml-cpp\yaml.h"

struct ObstacleData
{
  std::string m_type;
  sf::Vector2f m_position;
  double m_rotation;
};

struct TargetData
{
  std::string m_type;
  sf::Vector2f m_position;
  double m_rotation;
};

struct BackgroundData
{
   std::string m_fileName;
};

struct TankData
{
  sf::Vector2f m_position1;
  sf::Vector2f m_position2;
  sf::Vector2f m_position3;
  sf::Vector2f m_position4;
};


struct LevelData
{
   BackgroundData m_background;
   TankData m_tank;
   std::vector<ObstacleData> m_obstacles;
   std::vector<TargetData> m_targets;
};

class LevelLoader
{
public:

	// No-op constructor
	LevelLoader() = default;

   static bool load(int nr, LevelData& level);
};
