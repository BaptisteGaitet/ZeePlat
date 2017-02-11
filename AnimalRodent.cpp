#include "AnimalRodent.h"

AnimalRodent::AnimalRodent(sf::Vector2f _position) : Animal(sf::Vector2f(_position.x * 8, _position.y * 8), sf::Vector2f(8, 8), "rodent.png", 1, 4)
{
	body.setPosition(sf::Vector2f(_position.x * 8, _position.y * 8));

	body.addHitbox(Hitbox(sf::FloatRect(0, 0, 8, 4), sf::Vector2f(0, 2), true, true, false));

	std::vector<Frame> runRight = {
		Frame(0, 8),
		Frame(1, 8)
	};
	std::vector<Frame> runLeft = {
		Frame(2, 8),
		Frame(3, 8)
	};

	animatedImage.addAnimation("runRight", Animation(runRight, true));
	animatedImage.addAnimation("runLeft", Animation(runLeft, true));
	animatedImage.play("runRight");
}

void AnimalRodent::update(ParticleManager* _partMngr)
{
	updateEntity();

	sf::Vector2f nextVel = body.getVelocity();

	nextVel.x = 0.9 * nextVel.x;
	nextVel.y = 0.9 * nextVel.y;

	body.setVelocity(nextVel);
}

void AnimalRodent::updateAI(sf::Vector2f _playerPosition, TileMap* _map)
{
	if (VectorMath::getNorm(VectorMath::vectorFromTo(_playerPosition, getCenter())) < 16)
	{
		if (_playerPosition.x > getCenter().x)
		{
			body.setVelocity(sf::Vector2f(-0.8, 0));
			animatedImage.play("runLeft");
		}
		else
		{
			body.setVelocity(sf::Vector2f(0.8, 0));
			animatedImage.play("runRight");
		}
	}
	else if (rand() % 40 == 1)
	{
		if (rand() % 10 > 5)
		{
			body.setVelocity(sf::Vector2f(-0.6, 0));
			animatedImage.play("runLeft");
		}
		else
		{
			body.setVelocity(sf::Vector2f(0.6, 0));
			animatedImage.play("runRight");
		}
	}
}

AnimalRodent::~AnimalRodent()
{
}
