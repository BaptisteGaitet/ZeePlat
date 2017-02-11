#include "GameState.h"

GameState::GameState() : State("game")
{
	player = Player(sf::Vector2f(100, 100));
	levels = LevelLoader::loadLevels();
	currentLevel = "room1";

	partMngr = ParticleManager();
}

void GameState::update()
{
	player.update(&partMngr);
	levels.at(currentLevel)->separate(player.getBody());
	levels.at(currentLevel)->update(&partMngr);
	partMngr.update();

	WindowManager::getInstance().setTarget(player.getCenter());

	for (int i = 0; i < player.getBody()->getHitboxes().size(); i++)
	{
		WarpZone zone = levels.at(currentLevel)->getOvelapingWarpZone(player.getBody()->getHitboxes().at(i)->getRect());
		if (zone.getDestinationId() != "")
		{
			currentLevel = zone.getDestinationId();
			player.getBody()->setPosition(zone.getDestinationPosition());
			WindowManager::getInstance().setCenter(player.getBody()->getPosition());
		}
	}
}

void GameState::draw(sf::RenderWindow* window)
{
	partMngr.draw(window);
	levels.at(currentLevel)->drawBackground(window);
	player.draw(window);
	levels.at(currentLevel)->drawForeground(window);
}

GameState::~GameState()
{
}
