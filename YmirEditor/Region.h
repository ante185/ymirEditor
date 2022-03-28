#pragma once
#include <SFML/Graphics.hpp>

enum class CLIMATE { SEA, CONTINENTAL, OCEANIC, MEDITERRAN, TROPICAL, ARID, DESERT, NORDIC, POLAR };
enum class RELIEF { RELIEF_NONE, PLAIN, ROCKY, HILLS, MOUNTAINS };
enum class VEGETATION { VEG_NONE, FOREST };
enum class WATER { WATER_NONE, RIVER_SMALL, RIVER_MED, RIVER_LARGE, LAKE, SWAMP };
enum class WORLDOBJECT { WOBJ_NONE, PRIM_SPAWN };

static sf::Color tileTints[9]{
		sf::Color(64,64,255, 255),	//SEA
		sf::Color(40,205,40, 255),	//CONTINENTAL
		sf::Color(64,205,205, 255), //OCEANIC
		sf::Color(140,190,120, 255),//MEDITERRAN
		sf::Color(0,255,0, 255), 	//TROPICAL
		sf::Color(240,190,50, 255),	//ARID
		sf::Color(205,205,0, 255),	//DESERT
		sf::Color(160,240,230, 255),//NORDIC
		sf::Color(210,230,240, 255),//POLAR
};

class Region
{
private:
public:
	CLIMATE	climate;
	RELIEF	relief;
	VEGETATION	vegetation;
	WATER	water;
	WORLDOBJECT	object;


	void setRegionInfo(CLIMATE, RELIEF, VEGETATION, WATER, WORLDOBJECT);
};

