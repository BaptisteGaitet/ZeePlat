#ifndef STATE_H
#define STATE_H

#include <string>
#include <SFML\Graphics.hpp>
#include "UIHolder.h"
/*
This class must be inherited to represent a single independent screen in the game.
*/

class State
{
private:
	std::string id;
	std::string nextStateId;
protected:
	UIHolder uiholder;
public:
	State(std::string _id);

	std::string getNextStateId();
	void setNextStateId(std::string _nextStateId);
	void resetNextStateId();
	std::string getId();

	virtual void update() = 0;
	virtual void draw(sf::RenderWindow* window) = 0;

	~State();
};

#endif