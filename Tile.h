#ifndef TILE_H
#define TILE_H

#include "Image.h"
#include "Hitbox.h"

class Tile
{
private:
	Image image;
	Hitbox hitbox;
	bool solid;
public:
	Tile(int _index, sf::Vector2f _position, sf::Vector2f _size, sf::Vector2i _tileSize, std::string _path, bool _solid);

	void draw(sf::RenderWindow* window);
	Hitbox* getHitbox();

	~Tile();
};

#endif