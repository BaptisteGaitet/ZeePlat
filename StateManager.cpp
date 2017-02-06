#include "StateManager.h"

StateManager::StateManager()
{
	// Initialize current state to an empty string
	currentStateId = "";
	states = std::map<std::string, State*>();
	AudioManager::getInstance().addSound("snd/page.ogg");
}

// Updates current state if valid
void StateManager::update()
{
	// If the current state is valid
	if (hasState(currentStateId))
	{
		// Update it
		states.at(currentStateId)->update();

		std::string next = states.at(currentStateId)->getNextStateId();
		if (next != "")
		{
			if (hasState(next))
			{

				states.at(currentStateId)->setNextStateId("");
				currentStateId = next;
				AudioManager::getInstance().playSound("snd/page.ogg");
			}
		}
	}
}

// Draw current state id valid
void StateManager::draw(sf::RenderWindow* window)
{
	// If the current state is valid
	if (hasState(currentStateId))
	{
		// Draw it
		states.at(currentStateId)->draw(window);
	}
}

// Adds new state to the map
void StateManager::addState(State* _state)
{
	// Insert a new state to the map, whith its id as string key
	states.insert(std::pair<std::string, State*>(_state->getId(), _state));
}

// Checks if a specific key exists in the map, logs error if not
bool StateManager::hasState(std::string _id)
{
	// Declare return value as strue;
	bool valid = true;

	// Try to access the corresponding state
	try
	{
		states.at(_id);
	}
	catch (const std::out_of_range& oor)
	{
		// Set return value to false
		valid = false;
		// Log the error
		std::cerr << "StateManager Out of Range error: " << oor.what() << "\n";
	}

	return valid;
}

// Sets the current state id if valid
void StateManager::setCurrentStateId(std::string _id)
{
	// Test if map contains that state
	if (hasState(_id))
	{
		// Set new currentStateId
		currentStateId = _id;
	}
}

StateManager::~StateManager()
{
}
