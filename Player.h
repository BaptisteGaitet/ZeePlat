#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
private:
	bool facingLeft;
	bool onGround;
	bool canJump;
public:
	Player(sf::Vector2f _position);

	void update();

	~Player();
};

#endif