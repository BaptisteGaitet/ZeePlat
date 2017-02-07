#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
#include "Player.h"
#include "Level.h"
#include "LevelLoader.h"
#include "WindowManager.h"

class GameState :
	public State
{
private:
	Player player;
	std::map<std::string, Level*> levels;
	std::string currentLevel;
public:
	GameState();

	void update();
	void draw(sf::RenderWindow* window);

	~GameState();
};

#endif