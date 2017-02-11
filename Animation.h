#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include "Frame.h"

class Animation
{
private:
	std::string id;
	std::vector<Frame> frames;
	int currentFrameIndex;
	bool looped;

public:
	Animation(std::vector<Frame> _frames, bool _looped);

	void update();
	int getCurrentFrameNumber();
	bool finished();
	bool isLooped();
	void reset();

	~Animation();
};

#endif


