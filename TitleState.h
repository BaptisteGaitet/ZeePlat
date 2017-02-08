#ifndef TITLE_STATE_H
#define TITLE_STATE_H

#include "State.h"
#include "AnimatedImage.h"
#include "WindowManager.h"

class TitleState : public State
{
private:
	int selected;
	bool directionPressed;
	bool selectPressed;
	bool fullOn;
	AnimatedImage start;
	AnimatedImage fullScreen;
	AnimatedImage on;
	AnimatedImage off;
	AnimatedImage zoom;
	AnimatedImage exit;
public:
	TitleState();

	void update();
	void draw(sf::RenderWindow* window);

	~TitleState();
};

#endif