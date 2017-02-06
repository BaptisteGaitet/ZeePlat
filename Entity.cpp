#include "Entity.h"

Entity::Entity(sf::Vector2f _position, sf::Vector2f _size, std::string _path, int _spriteRows, int _spriteColumns)
{
	body = Body(_position);
	animatedImage = AnimatedImage(_position, _size, _path, _spriteRows, _spriteColumns);
}

Entity::Entity(Body _body, AnimatedImage _animatedImage)
{
	body = _body;
	animatedImage = _animatedImage;
}

void Entity::updateEntity()
{
	body.update();
	animatedImage.update();
}

void Entity::draw(sf::RenderWindow* window)
{
	animatedImage.setPosition(sf::Vector2f(body.getPosition().x, body.getPosition().y));
	animatedImage.draw(window);
}

Body* Entity::getBody()
{
	return &body;
}

sf::Vector2f Entity::getCenter()
{
	return animatedImage.getCenter();
}

Entity::~Entity()
{
}
