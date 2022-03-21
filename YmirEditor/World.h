#pragma once
#include <SFML/Graphics.hpp>
class World
{
private:
	sf::String worldPath;
	sf::String sizeTag;
	sf::Vector2i size;
public:
	bool loadWorld(sf::String path);
};

