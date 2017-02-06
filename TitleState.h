#ifndef TITLE_STATE_H
#define TITLE_STATE_H

#include "State.h"

class TitleState : public State
{
public:
	TitleState();

	void update();
	void draw(sf::RenderWindow* window);

	~TitleState();
};

#endif