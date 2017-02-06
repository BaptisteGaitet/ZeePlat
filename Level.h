#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include "TileMap.h"
#include "Image.h"
#include "Entity.h"

class Level
{
private:
	Image background;
	std::vector<TileMap> layers;
	std::vector<Entity*> entities;
public:
	Level();

	void update();
	void addLayer(TileMap _tilemap);
	void draw(sf::RenderWindow* window);

	~Level();
};

#endif