#ifndef LEVEL_H
#define LEVEL_H

#include <SFML\Graphics.hpp>
#include <string>
#include "TileMap.h"
#include "Image.h"
#include "Entity.h"
#include "WarpZone.h"

class Level
{
private:
	sf::RectangleShape background;
	TileMap* backLayer;
	TileMap* mainLayer;
	TileMap* frontLayer;
	std::vector<Entity*> entities;
	std::vector<WarpZone> warpZones;
public:
	Level(TileMap* _backLayer, TileMap* _mainLayer, TileMap* _frontLayer, std::vector<Entity*> _entities, sf::Color _backgroundColor);

	void update();
	void drawBackground(sf::RenderWindow* window);
	void drawForeground(sf::RenderWindow* window);
	void separate(Body* _body);

	void setWarpZones(std::vector<WarpZone> _warpZones);
	WarpZone getOvelapingWarpZone(sf::FloatRect _rect);

	~Level();
};

#endif