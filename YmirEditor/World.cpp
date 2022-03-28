#include "World.h"
#include <fstream>

World::World()
{
	for (int i = 0; i < 5; i++) {
		layers[i].setTexture(&placeholder);
		layers[i].setSize(sf::Vector2f(300.f, 225.f));
		layers[i].setOutlineThickness(-30.f);
		layers[i].setOutlineColor(sf::Color(255,255,255,60));
	}
	layers[4].setOutlineColor(sf::Color(15, 15, 15, 120));
	layers[4].setFillColor(sf::Color(15, 15, 15, 0));
}

bool World::loadWorld(std::string path)
{
	std::ifstream mapFile;
	mapFile.open(path.c_str(), std::ios::in | std::ios::ate | std::ios::binary);

	if (!mapFile.is_open()) {
		return false; //Return error
	}

	unsigned int fileLenght = (unsigned int)mapFile.tellg();
	mapFile.seekg(0);

	unsigned char* data = new unsigned char[fileLenght];

	mapFile.read((char*)data, fileLenght);
	uint64_t width = ((unsigned short*)data)[0];
	uint64_t height = ((unsigned short*)data)[1];

	mapFile.close();
	size.x = width;
	size.y = height;

	regions.resize((uint64_t)width*height);

	unsigned int i = 0;
	unsigned short k;
	Region temp;

	for (k = 0, i = 4; k < width * height; k++) {

		temp.setRegionInfo(
			(CLIMATE)data[i],
			(RELIEF)data[i + 1],
			(VEGETATION)data[i + 2],
			(WATER)data[i + 3],
			(WORLDOBJECT)data[i + 4]
		);
		i += 5;
		regions[k] = temp;
	}

	delete[] data;
	return true;
}

void World::draw(sf::RenderTarget* target, sf::RenderStates states) 
{
	for (int y = 0; y < size.y; y++) {
		for (int x = 0; x < size.x; x++) {
			for (int i = 0; i < 5; i++) {
				layers[i].setPosition(x * 300.f, y * 225.f);
			}
			layers[0].setFillColor(tileTints[(int)regions[x + y * size.x].climate]);
			target->draw(layers[0]);

			if (regions[x + y * size.x].object == WORLDOBJECT::PRIM_SPAWN) {
				target->draw(layers[4]);
			}
		}
	}
}
