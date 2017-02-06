#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <string>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "State.h"
#include "AudioManager.h"

/*
This class holds several states, updating and drawing the current one and handling the switch between them.
*/

class StateManager
{
private:
	std::map<std::string, State*> states;
	std::string currentStateId;

	bool hasState(std::string _id);
public:
	StateManager();

	void update();
	void draw(sf::RenderWindow* window);
	void addState(State* _state);
	void setCurrentStateId(std::string _id);

	~StateManager();
};

#endif