#include "Body.h"

Body::Body() : Hitbox(sf::FloatRect(0,0,0,0), true)
{
	maxVelocity = 0;
	velocity = sf::Vector2f(0, 0);
	gravity = 0;
}

Body::Body(sf::FloatRect _rect, float _maxVelocity, float _gravity) : Hitbox(_rect, true)
{
	maxVelocity = _maxVelocity;
	velocity = sf::Vector2f(0, 0);
	gravity = _gravity;
}

void Body::update()
{
	sf::Vector2f nextPosition = getPosition();

	if (VectorMath::getNorm(velocity) > maxVelocity)
	{
		sf::Vector2f normalizedVelocity = VectorMath::normalize(velocity);
		velocity.x = normalizedVelocity.x * maxVelocity;
		velocity.y = normalizedVelocity.y * maxVelocity;
	}

	nextPosition.y += gravity;

	nextPosition.x += velocity.x;
	nextPosition.y += velocity.y;

	setPosition(nextPosition);
}

sf::Vector2f Body::getVelocity()
{
	return velocity;
}

void Body::setVelocity(sf::Vector2f _velocity)
{
	velocity = _velocity;
}

Body::~Body()
{
}
