#ifndef HITBOX_H
#define HITBOX_H

#include <iostream>
#include <SFML\Graphics.hpp>
#include "VectorMath.h"

class Hitbox
{
private:
	sf::FloatRect rect;
	bool pushable;
public:
	Hitbox(sf::FloatRect _rect, bool _pushable);

	sf::FloatRect getRect();
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	bool contains(sf::Vector2f _point);
	void resolveCollision(Hitbox* _rect);
	bool isPushable();

	~Hitbox();
};

#endif
