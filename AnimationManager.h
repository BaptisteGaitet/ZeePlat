#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H

#include <iostream>
#include <map>
#include "Animation.h"

class AnimationManager
{
private:
	std::map<std::string, Animation> animations;
	std::string currentAnimation;
	bool paused;

	bool hasAnimation(std::string _id);
public:
	AnimationManager();

	void update();
	void addAnimation(std::string _id, Animation animation);
	void play(std::string _id);
	void pause();
	void resume();
	int getCurrentFrameNumber();
	bool currentAnimationFinished();
	std::string getCurrentAnimationId();
	void resetAnimation(std::string _id);

	~AnimationManager();
};

#endif