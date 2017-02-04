#ifndef ENTITY_H
#define ENTITY_H

#include "AnimatedImage.h"
#include "Body.h"

class Entity
{
protected:
	Body body;
	AnimatedImage animatedImage;
public:
	Entity(Body _body, AnimatedImage _animatedImage);

	virtual void update() = 0;

	~Entity();
};

#endif