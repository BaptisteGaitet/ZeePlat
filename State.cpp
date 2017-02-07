#include "State.h"

// Creates the state with a corresponding ID
State::State(std::string _id)
{
	exit = false;
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

void State::setExit(bool _exit)
{
	exit = _exit;
}

bool State::getExit()
{
	return exit;
}

State::~State()
{
}
