#include "GameState.h"


GameState::GameState() : State("game")
{
	player = Player(sf::Vector2f(100, 100));
	levels.insert(std::pair<std::string, Level>("test",LevelLoader::loadLevel("test.txt", "test8x8.png")));
	currentLevel = "test";
}

void GameState::update()
{
	player.update();
	levels.at(currentLevel).separate(player.getBody());

	WindowManager::getInstance().setTarget(player.getCenter());
}

void GameState::draw(sf::RenderWindow* window)
{
	levels.at(currentLevel).drawBackground(window);
	player.draw(window);
	levels.at(currentLevel).drawForeground(window);
}

GameState::~GameState()
{
}
