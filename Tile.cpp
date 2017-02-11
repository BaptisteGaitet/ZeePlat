#include "Tile.h"


Tile::Tile(int _index, sf::Vector2f _position, sf::Vector2f _size, sf::Vector2i _tileSize, std::string _path, bool _solid)
{
	tileId = _index;
	image = Image(_position, _size, _path, _tileSize, _index);
	solid = _solid;
	if (_solid)
	{
		hitbox = Hitbox(sf::FloatRect(_position.x, _position.y, _size.x, _size.y), sf::Vector2f(), false, true, true);
	}
	else
	{
		hitbox = Hitbox();
	}
}

void Tile::draw(sf::RenderWindow* window)
{
	image.draw(window);
}

Hitbox* Tile::getHitbox()
{
	return &hitbox;
}

bool Tile::isSolid()
{
	return solid;
}

int Tile::getIndex()
{
	return tileId;
}

Tile::~Tile()
{
}
