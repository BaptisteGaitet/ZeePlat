#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>

class Particle
{
private:
	sf::Vector2f velocity;
	float gravity;
	int lifeSpan;
	int lifeTimer;
	bool dead;
	sf::Color color;
public:
	Particle();

	void udpate();
	void draw(sf::RenderWindow* window);

	~Particle();
};

#endif