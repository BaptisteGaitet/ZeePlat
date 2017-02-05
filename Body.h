#ifndef BODY_H
#define BODY_H

#include <SFML\Graphics.hpp>
#include <iostream>
#include "Hitbox.h"

class Body
{
private:
	sf::Vector2f lastPosition;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;

	std::vector<Hitbox*> hitboxes;

	void snapHitboxesToBody();
	void resetHitboxesContacts();
public:
	Body();
	Body(sf::Vector2f _position);

	void update();
	sf::Vector2f getLastPosition();
	sf::Vector2f getPosition();
	sf::Vector2f getVelocity();
	sf::Vector2f getAcceleration();
	void setPosition(sf::Vector2f _velocity);
	void setVelocity(sf::Vector2f _velocity);
	void setAcceleration(sf::Vector2f _velocity);

	void addHitbox(Hitbox hitbox);
	std::vector<Hitbox*> getHitboxes();
	void snapAllToHitbox(int _index);

	~Body();
};

#endif