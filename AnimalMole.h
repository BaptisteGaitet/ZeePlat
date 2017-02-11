#ifndef ANIMAL_MOLE_H
#define ANIMAL_MOLE_H

#include "Animal.h"
class AnimalMole : public Animal
{
public:
	AnimalMole(sf::Vector2f _position);

	void update(ParticleManager* _partMngr);
	void updateAI(sf::Vector2f _playerPosition, TileMap* _map);

	~AnimalMole();
};

#endif