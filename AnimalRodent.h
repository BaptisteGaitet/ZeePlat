#ifndef ANIMAL_RODENT_H
#define ANIMAL_RODENT_H

#include "Animal.h"

class AnimalRodent : public Animal
{
public:
	AnimalRodent(sf::Vector2f _position);

	void update(ParticleManager* partMngr);
	void updateAI(sf::Vector2f _playerPos, TileMap* _map);

	~AnimalRodent();
};

#endif