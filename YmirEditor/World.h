#pragma once
#include <SFML/Graphics.hpp>
#include "Region.h"
#include <vector>

class World
{
private:
	sf::String worldPath;
	sf::String sizeTag;
	sf::Vector2i size;
	std::vector<Region> regions;
	sf::RectangleShape layers[5];
	sf::Texture placeholder;
public:
	World();
	bool loadWorld(std::string path);
	void writeToRegion(Region);
	const Region* readRegion(sf::Vector2i);

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget* target, sf::RenderStates states = sf::RenderStates::Default);
};

