#ifndef ENTITY_H
#define ENTITY_H

#include "AnimatedImage.h"
#include "Body.h"
#include "Hitbox.h"

class Entity
{
protected:
	Body body;
	AnimatedImage animatedImage;
	
	void updateEntity();
public:
	Entity(sf::Vector2f _position, sf::Vector2f _size, std::string _path, int _spriteRows, int _spriteColumns);
	Entity(Body _body, AnimatedImage _animatedImage);

	virtual void update() = 0;
	void draw(sf::RenderWindow* window);
	Body* getBody();

	~Entity();
};

#endif