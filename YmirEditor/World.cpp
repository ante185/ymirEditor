#include "World.h"
#include <fstream>

bool World::loadWorld(sf::String path)
{
	std::ifstream mapFile;
	mapFile.open((char*)path.getData(), std::ios::in | std::ios::ate | std::ios::binary);

	if (!mapFile.is_open()) {
		return false; //Return error
	}

	unsigned int fileLenght = (unsigned int)mapFile.tellg();
	mapFile.seekg(0);

	unsigned char* data = new unsigned char[fileLenght];

	mapFile.read((char*)data, fileLenght);
	unsigned short width = ((unsigned short*)data)[0];
	unsigned short height = ((unsigned short*)data)[1];

	mapFile.close();
	size.x = width;
	size.y = height;
}
