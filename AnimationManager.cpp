#include "AnimationManager.h"


AnimationManager::AnimationManager()
{
	paused = false;
	currentAnimation = "";
	animations = std::map < std::string, Animation >();
}

bool AnimationManager::hasAnimation(std::string _id)
{
	bool res = true;

	try
	{
		animations.at(_id);
	}
	catch (const std::out_of_range& oor)
	{
		// Set return value to false
		res = false;
		// Log the error
		std::cerr << "AnimationManager: Out of Range error: " << oor.what() << "\n";
	}

	return res;
}

void AnimationManager::update()
{
	if (hasAnimation(currentAnimation) && !paused)
	{
		animations.at(currentAnimation).update();
	}
}

void AnimationManager::addAnimation(std::string _id, Animation _animation)
{
	if (!hasAnimation(_id))
	{
		animations.insert(std::pair<std::string, Animation>(_id, _animation));
	}
}

void AnimationManager::play(std::string _id)
{
	if (hasAnimation(_id))
	{
		currentAnimation = _id;
	}
}

int AnimationManager::getCurrentFrameNumber()
{
	int res = 0;

	if (hasAnimation(currentAnimation))
	{
		animations.at(currentAnimation).getCurrentFrameNumber();
	}

	return res;
}

bool AnimationManager::currentAnimationFinished()
{
	bool res = false;

	if (hasAnimation(currentAnimation))
	{
		if (animations.at(currentAnimation).finished())
		{
			res = true;
		}
	}

	return res;
}

void AnimationManager::pause()
{
	paused = true;
}

void AnimationManager::resume()
{
	paused = false;
}

AnimationManager::~AnimationManager()
{
}
