#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Particle.h"

class Player : public Entity
{
private:
	bool facingLeft;
	bool onGround;
	bool canJump;
public:
	Player();
	Player(sf::Vector2f _position);

	void update(ParticleManager* _partMngr);

	~Player();
};

#endif