#include "Animation.h"


Animation::Animation(std::vector<Frame> _frames, bool _looped)
{
	frames = _frames;
	looped = _looped;
	currentFrameIndex = 0;
}

void Animation::update()
{
	frames.at(currentFrameIndex).update();

	if (frames.at(currentFrameIndex).finished())
	{
		if (currentFrameIndex < (frames.size() - 1))
		{
			frames.at(currentFrameIndex).reset();
			currentFrameIndex++;
		}
		else if (looped)
		{
			frames.at(currentFrameIndex).reset();
			currentFrameIndex = 0;
		}
	}
}

int Animation::getCurrentFrameNumber()
{
	return frames.at(currentFrameIndex).getNumber();
}

bool Animation::finished()
{
	bool res = false;

	if (!looped && currentFrameIndex >= frames.size() - 1)
	{
		res = true;
	}

	return res;
}

Animation::~Animation()
{
}
