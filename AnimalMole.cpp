#include "AnimalMole.h"

AnimalMole::AnimalMole(sf::Vector2f _position) :Animal(sf::Vector2f(_position.x * 8, _position.y * 8), sf::Vector2f(8, 8), "mole.png", 1, 8)
{
	body.setPosition(sf::Vector2f(_position.x * 8, _position.y * 8));

	std::vector<Frame> idle = {
		Frame(0, 8),
		Frame(1, 4),
		Frame(2, 8),
		Frame(3, 4)
	};

	std::vector<Frame> hide = {
		Frame(4, 4),
		Frame(5, 4),
		Frame(6, 4),
		Frame(7, 4)
	};

	std::vector<Frame> appear = {
		Frame(7, 4),
		Frame(6, 4),
		Frame(5, 4),
		Frame(4, 4)
	};

	animatedImage.addAnimation("idle", Animation(idle, true));
	animatedImage.addAnimation("hide", Animation(hide, false));
	animatedImage.addAnimation("appear", Animation(appear, false));
	animatedImage.play("idle");
}

void AnimalMole::update(ParticleManager* _partMngr)
{
	updateEntity();
}

void AnimalMole::updateAI(sf::Vector2f _playerPosition, TileMap* _map)
{
	if (animatedImage.getCurrentAnimationId() == "idle" && VectorMath::getNorm(VectorMath::vectorFromTo(_playerPosition, getCenter())) < 16)
	{
		animatedImage.play("hide");
	}

	if (animatedImage.getCurrentAnimationId() == "hide" && animatedImage.isFinished())
	{
		sf::Vector2f nextPosition = _map->getRandomGroundPosition();
		nextPosition.y -= 8;
		body.setPosition(nextPosition);
		animatedImage.play("appear");
	}
	
	if (animatedImage.getCurrentAnimationId() == "appear" && animatedImage.isFinished())
	{
		animatedImage.play("idle");
	}
}

AnimalMole::~AnimalMole()
{
}
