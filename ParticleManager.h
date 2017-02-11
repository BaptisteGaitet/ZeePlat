#ifndef PARTICLE_MANAGER_H
#define PARTICLE_MANAGER_H

#include <SFML/Graphics.hpp>
#include "Particle.h"

class ParticleManager
{
private:
	std::vector<Particle> particles;
public:
	ParticleManager();

	void update();
	void draw(sf::RenderWindow* _window);
	void addParticle(Particle _particle);

	~ParticleManager();
};

#endif