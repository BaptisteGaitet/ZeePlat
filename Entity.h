#ifndef ENTITY_H
#define ENTITY_H

#include "AnimatedImage.h"
#include "Body.h"
#include "Hitbox.h"
#include "ParticleManager.h"

class Entity
{
protected:
	Body body;
	AnimatedImage animatedImage;
	
	void updateEntity();
public:
	Entity(sf::Vector2f _position, sf::Vector2f _size, std::string _path, int _spriteRows, int _spriteColumns);
	Entity(Body _body, AnimatedImage _animatedImage);

	virtual void update(ParticleManager* _partMngr) = 0;
	void draw(sf::RenderWindow* window);
	Body* getBody();
	sf::Vector2f getCenter();

	~Entity();
};

#endif