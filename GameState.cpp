#include "GameState.h"


GameState::GameState() : State("game")
{
	player = Player(sf::Vector2f(100, 100));
	std::cout << "start loadLevels\n";
	levels = LevelLoader::loadLevels();
	std::cout << "finished loadLevels\n";
	currentLevel = "room1";
}

void GameState::update()
{
	player.update();
	levels.at(currentLevel)->separate(player.getBody());

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
	levels.at(currentLevel)->drawBackground(window);
	player.draw(window);
	levels.at(currentLevel)->drawForeground(window);
}

GameState::~GameState()
{
}
