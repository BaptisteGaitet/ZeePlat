#include "State.h"

// Creates the state with a corresponding ID
State::State(std::string _id)
{
	id = _id;
	nextStateId = "";
}

// Returns the state to switch for (empty string if no switching requested)
std::string State::getNextStateId()
{
	return nextStateId;
}

// Sets nextStateId when switching to a new state is required
void State::setNextStateId(std::string _nextStateId)
{
	nextStateId = _nextStateId;
}

// Resets nestStateId to an empty string, meaning no switching requested
void State::resetNextStateId()
{
	nextStateId = "";
}

std::string State::getId()
{
	return id;
}

State::~State()
{
}
