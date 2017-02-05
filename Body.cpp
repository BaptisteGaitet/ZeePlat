#include "Body.h"

Body::Body()
{
	lastPosition = sf::Vector2f(0, 0);
	position = sf::Vector2f(0, 0);
	velocity = sf::Vector2f(0, 0);
	acceleration = sf::Vector2f(0, 0);
}

Body::Body(sf::Vector2f _position)
{
	lastPosition = _position;
	position = _position;
	acceleration = sf::Vector2f(0, 0);
	velocity = sf::Vector2f(0, 0);
}

void Body::snapAllToHitbox(int _index)
{
	Hitbox hb = *hitboxes.at(_index);
	position.x = hb.getPosition().x - hb.getOffset().x;
	position.y = hb.getPosition().y - hb.getOffset().y;
	snapHitboxesToBody();
}

void Body::snapHitboxesToBody()
{
	for (int i = 0; i < hitboxes.size(); i++)
	{
		sf::Vector2f nextPos = sf::Vector2f(0,0);
		nextPos.x = position.x + hitboxes.at(i)->getOffset().x;
		nextPos.y = position.y + hitboxes.at(i)->getOffset().y;
		hitboxes.at(i)->setPosition(nextPos);
	}
}

void Body::resetHitboxesContacts()
{
	for (int i = 0; i < hitboxes.size(); i++)
	{
		hitboxes.at(i)->resetContacts();
	}
}

void Body::update()
{
	lastPosition = position;

	velocity.x += acceleration.x;
	velocity.y += acceleration.y;

	position.x += velocity.x;
	position.y += velocity.y;

	acceleration.x = 0;
	acceleration.y = 0;

	snapHitboxesToBody();

	resetHitboxesContacts();
}

sf::Vector2f Body::getLastPosition()
{
	return lastPosition;
}

sf::Vector2f Body::getPosition()
{
	return position;
}

sf::Vector2f Body::getVelocity()
{
	return velocity;
}

void Body::setPosition(sf::Vector2f _position)
{
	position = _position;
}

void Body::setVelocity(sf::Vector2f _velocity)
{
	velocity = _velocity;
}

sf::Vector2f Body::getAcceleration()
{
	return acceleration;
}

void Body::setAcceleration(sf::Vector2f _acceleration)
{
	acceleration = _acceleration;
}

void Body::addHitbox(Hitbox _hitbox)
{
	Hitbox* hitbox = new Hitbox();

	hitbox->setPosition(_hitbox.getPosition());
	hitbox->setSize(_hitbox.getSize());
	hitbox->setOffset(_hitbox.getOffset());
	hitbox->setPushable(_hitbox.isPushable());
	hitbox->setCollideHorizontally(_hitbox.getCollideHorizontally());
	hitbox->setCollideVertically(_hitbox.getCollideVertically());

	hitboxes.push_back(hitbox);
}

std::vector<Hitbox*> Body::getHitboxes()
{
	return hitboxes;
}

Body::~Body()
{
}