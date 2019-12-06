#include "LevelLoader.h"
#include "Game.h"

void getObstacleData(const YAML::Node& obstacleNode, ObstacleData& obstacle)
{
	obstacle.m_type = obstacleNode["type"].as<std::string>();
	obstacle.m_position.x = obstacleNode["position"]["x"].as<float>();
	obstacle.m_position.y = obstacleNode["position"]["y"].as<float>();
	obstacle.m_rotation = obstacleNode["rotation"].as<double>();
}
void getTargetData(const YAML::Node& targetNode, TargetData& target)
{
	target.m_type = targetNode["type"].as<std::string>();
	target.m_position.x = targetNode["position"]["x"].as<float>();
	target.m_position.y = targetNode["position"]["y"].as<float>();
	target.m_rotation = targetNode["rotation"].as<double>();
}
// The function immediately below is the logical equivalent to the above.
/*void operator >> (const YAML::Node& obstacleNode, ObstacleData& obstacle)
{
   obstacle.m_type = obstacleNode["type"].as<std::string>();
   obstacle.m_position.x = obstacleNode["position"]["x"].as<float>();
   obstacle.m_position.y = obstacleNode["position"]["y"].as<float>();
   obstacle.m_rotation = obstacleNode["rotation"].as<double>();
}*/

void getBackgroundName(const YAML::Node& backgroundNode, BackgroundData& background)
{
	background.m_fileName = backgroundNode["file"].as<std::string>();
}

void getTankData(const YAML::Node& t_tankNode, TankData& t_tankData)
{
	//tank:
	//passes the Tank's spawnpoints from the yaml file as an int
	t_tankData.m_position1.x = t_tankNode["position1"]["x"].as<int>();
	t_tankData.m_position1.y = t_tankNode["position1"]["x"].as<int>();
	t_tankData.m_position2.x = t_tankNode["position2"]["x"].as<int>();
	t_tankData.m_position2.y = t_tankNode["position2"]["x"].as<int>();
	t_tankData.m_position3.x = t_tankNode["position3"]["x"].as<int>();
	t_tankData.m_position3.y = t_tankNode["position3"]["y"].as<int>();
	t_tankData.m_position4.x = t_tankNode["position4"]["x"].as<int>();
	t_tankData.m_position4.y = t_tankNode["position4"]["y"].as<int>();
}

// The function immediately below is the logical equivalent to the above.
/*void operator >> (const YAML::Node& backgroundNode, BackgroundData& background)
{
   background.m_fileName = backgroundNode["file"].as<std::string>();
}*/

// **********************************************************************************
// Exercise: Define a function getTankData() here to read the 'tank' map
// **********************************************************************************


void readYAMLFile(const YAML::Node& levelNode, LevelData& level)
{
	getBackgroundName(levelNode["background"], level.m_background);
	getTankData(levelNode["tank"], level.m_tank);
	//levelNode["background"] >> level.m_background;

	// ****************************************************
	// Exercise: Call your function getTankData() here 
	// ****************************************************

	// Read the obstacle data (a YAML sequence)
	const YAML::Node& obstaclesNode = levelNode["obstacles"].as<YAML::Node>();
	for (const YAML::Node& obstacleNode : obstaclesNode)
	{
		ObstacleData obstacle;
		getObstacleData(obstacleNode, obstacle);
		// obstacleNode >> obstacle;
		level.m_obstacles.push_back(obstacle);
	}

	const YAML::Node& targetNode = levelNode["targets"].as<YAML::Node>();
	for (const YAML::Node& targetNode : targetNode)
	{
		TargetData target;
		getTargetData(targetNode, target);
		// obstacleNode >> obstacle;
		level.m_targets.push_back(target);
	}
}

/*void operator >> (const YAML::Node& levelNode, LevelData& level)
{
   levelNode["background"] >> level.m_background;

   levelNode["tank"] >> level.m_tank;

   const YAML::Node& obstaclesNode = levelNode["obstacles"].as<YAML::Node>();
   for (unsigned i = 0; i < obstaclesNode.size(); ++i)
   {
	  ObstacleData obstacle;
	  obstaclesNode[i] >> obstacle;
	  level.m_obstacles.push_back(obstacle);
   }
}*/


bool LevelLoader::load(int nr, LevelData& level)
{
	std::string yamlFile = "level" + std::to_string(nr) + ".yaml";

   try
   {
	  YAML::Node baseNode = YAML::LoadFile(yamlFile);
	  if (baseNode.IsNull())
	  {
		  std::string message("file: " + yamlFile + " not found");
		  throw std::exception(message.c_str());
	  }
	  readYAMLFile(baseNode, level);
	  //baseNode >> level;
   }
   catch(YAML::ParserException& e)
   {
       std::cout << e.what() << "\n";
       return false;
   }
   catch (std::exception& e)
   {
	   std::cout << e.what() << "\n";
	   return false;
   }

   return true;
}

