#pragma once
#include <SFML/Graphics.hpp>

enum class CLIMATE { SEA, CONTINENTAL, OCEANIC, MEDITERRAN, TROPICAL, ARID, DESERT, NORDIC, POLAR };
enum class RELIEF { RELIEF_NONE, PLAIN, ROCKY, HILLS, MOUNTAINS };
enum class VEGETATION { VEG_NONE, FOREST };
enum class WATER { WATER_NONE, RIVER_SMALL, RIVER_MED, RIVER_LARGE, LAKE, SWAMP };
enum class WORLDOBJECT { WOBJ_NONE, PRIM_SPAWN };

class Region
{
private:
	sf::Vector2i pos;
	CLIMATE	climate;
	RELIEF	relief;
	VEGETATION	vegetation;
	WATER	water;
	WORLDOBJECT	object;
public:
};

