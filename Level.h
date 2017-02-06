#ifndef LEVEL_H
#define LEVEL_H

#include <SFML\Graphics.hpp>
#include <string>
#include "TileMap.h"
#include "Image.h"
#include "Entity.h"

class Level
{
private:
	sf::RectangleShape background;
	TileMap* backLayer;
	TileMap* mainLayer;
	TileMap* frontLayer;
	std::vector<Entity*> entities;
public:
	Level(TileMap* _backLayer, TileMap* _mainLayer, TileMap* _frontLayer, std::vector<Entity*> _entities, sf::Color _backgroundColor);

	void update();
	void drawBackground(sf::RenderWindow* window);
	void drawForeground(sf::RenderWindow* window);
	void separate(Body* _body);

	~Level();
};

#endif