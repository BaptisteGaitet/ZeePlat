#ifndef ANIMAL_H
#define ANIMAL_H

#include "Entity.h"
#include "TileMap.h"

class Animal : public Entity
{
public:
	Animal(sf::Vector2f _position, sf::Vector2f _size, std::string _path, int _spriteRows, int _spriteColumns);

	virtual void updateAI(sf::Vector2f _playerPos, TileMap* _map) = 0;

	~Animal();
};

#endif

