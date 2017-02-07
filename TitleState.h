#ifndef TITLE_STATE_H
#define TITLE_STATE_H

#include "State.h"
#include "AnimatedImage.h"

class TitleState : public State
{
private:
	int selected;
	bool pressed;
	AnimatedImage start;
	AnimatedImage fullScreen;
	AnimatedImage on;
	AnimatedImage off;
	AnimatedImage exit;
public:
	TitleState();

	void update();
	void draw(sf::RenderWindow* window);

	~TitleState();
};

#endif