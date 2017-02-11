#include "Particle.h"

Particle::Particle()
{
	velocity = sf::Vector2f(0, 0);
	gravity = 0;
	dampening = 0;
	lifeSpan = 0;
	lifeTimer = 0;
	dead = false;
	color = sf::Color(0, 0, 0);
	shape = sf::RectangleShape();
}

Particle::Particle(sf::Vector2f _position, sf::Vector2f _velocity, float _gravity, float _dampening, int _lifeSpan, sf::Color _color)
{
	velocity = _velocity;
	gravity = _gravity;
	dampening = _dampening;
	lifeSpan = lifeSpan;
	lifeTimer = 0;
	dead = false;
	color = _color;
	shape = sf::RectangleShape(sf::Vector2f(1, 1));
	shape.setPosition(_position);
	shape.setFillColor(_color);
}

void Particle::update()
{
	// Manage lifespan
	lifeTimer++;
	if (lifeTimer >= lifeSpan)
	{
		dead = true;
	}

	// Manage position
	sf::Vector2f currentPosition = shape.getPosition();
	currentPosition += velocity;
	velocity.x = dampening * velocity.x;
	velocity.y = dampening * velocity.y;
	velocity.y += gravity;

	// Manage color
	int alphaFactor = (lifeTimer * 255) / lifeSpan;
	shape.setFillColor(sf::Color(color.r, color.g, color.b, alphaFactor));
}

void Particle::draw(sf::RenderWindow* window)
{
	window->draw(shape);
}

bool Particle::isDead()
{
	return dead;
}

Particle::~Particle()
{
}
