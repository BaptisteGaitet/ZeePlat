#ifndef TILE_MAP_H
#define TILE_MAP_H

#include <vector>
#include "Tile.h"
#include "Body.h"

class TileMap
{
private:
	std::vector<Tile> tiles;
	sf::Vector2i size;
	sf::Vector2i tileSize;
	bool solid;
public:
	TileMap(sf::FloatRect _bounds, sf::Vector2i _size, sf::Vector2i _tileSize, std::string _path, int* _indexes, bool* _hitboxes);

	void draw(sf::RenderWindow* window);
	void separate(Body* _body);
	bool isSolid();
	sf::Vector2i getSize();
	sf::Vector2i getTileSize();
	sf::Vector2f getRandomGroundPosition();

	~TileMap();
};

#endif