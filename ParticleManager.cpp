#include "ParticleManager.h"

ParticleManager::ParticleManager()
{
	particles = std::vector<Particle>();
}

void ParticleManager::update()
{
	for (int i = 0; i < particles.size(); i++)
	{
		particles.at(i).update();
	}
}

void ParticleManager::draw(sf::RenderWindow* _window)
{
	for (int i = 0; i < particles.size(); i++)
	{
		particles.at(i).draw(_window);
		if (particles.at(i).isDead())
		{
			particles.erase(particles.begin() + i);
		}
	}
}

void ParticleManager::addParticle(Particle _particle)
{
	particles.push_back(_particle);
}

ParticleManager::~ParticleManager()
{
}
