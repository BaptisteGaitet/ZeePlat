#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>

class Particle
{
private:
	sf::RectangleShape shape;
	sf::Vector2f velocity;
	float gravity;
	float dampening;
	int lifeSpan;
	int lifeTimer;
	bool dead;
	sf::Color color;
public:
	Particle();
	Particle(sf::Vector2f _position, sf::Vector2f _velocity, float _gravity, float _dampening, int _lifeSpan, sf::Color _color);

	void update();
	void draw(sf::RenderWindow* window);
	bool isDead();

	~Particle();
};

#endif