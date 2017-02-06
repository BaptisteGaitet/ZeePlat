#include "TileMap.h"

TileMap::TileMap(sf::FloatRect _bounds, sf::Vector2i _size, sf::Vector2i _tileSize, std::string _path, int* _indexes, bool* _hitboxes)
{
	solid = false;
	size = _size;
	sf::Vector2f renderTileSize = sf::Vector2f(_bounds.width / _size.x, _bounds.height / _size.y);
	for (int i = 0; i < _size.x; i++)
	{
		for (int j = 0; j < _size.y; j++)
		{
			int tileIndex = _indexes[j * _size.x + i];
			sf::Vector2f tilePosition = sf::Vector2f(i * renderTileSize.x + _bounds.left, j * renderTileSize.y + _bounds.top);

			if (_hitboxes[j * _size.x + i])
			{
				solid = true;
			}
			Tile tile = Tile(tileIndex, tilePosition, renderTileSize, _tileSize, _path, _hitboxes[j * _size.x + i]);
			tiles.push_back(tile);
		}
	}
}

void TileMap::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < tiles.size(); i++)
	{
		tiles.at(i).draw(window);
	}
}

void TileMap::separate(Body* _body)
{
	for (int i = 0; i < _body->getHitboxes().size(); i++)
	{
		for (int j = 0; j < tiles.size(); j++)
		{
			if (VectorMath::getNorm(VectorMath::vectorFromTo(_body->getPosition(), tiles.at(j).getHitbox()->getPosition())) < 64)
			{
				if (tiles.at(j).isSolid())
				{
					sf::Vector2f overlap = tiles.at(j).getHitbox()->overlap(_body->getHitboxes().at(i));

					tiles.at(j).getHitbox()->separate(_body->getHitboxes().at(i), overlap);

					_body->snapAllToHitbox(i);
				}
			}
		}
	}
}

bool TileMap::isSolid()
{
	return solid;
}

TileMap::~TileMap()
{
}
