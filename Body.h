#ifndef BODY_H
#define BODY_H

#include <SFML\Graphics.hpp>
#include "Hitbox.h"

class Body : public Hitbox
{
private:
	sf::Vector2f velocity;
	float maxVelocity;
	float gravity;
public:
	Body();
	Body(sf::FloatRect _rect, float _maxVelocity, float _gravity);

	void update();
	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f _velocity);

	~Body();
};

#endif