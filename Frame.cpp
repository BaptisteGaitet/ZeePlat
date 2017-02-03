#include "Frame.h"


Frame::Frame(int _number, int _duration)
{
	number = _number;
	duration = _duration;
	timer = 0;
}

void Frame::update()
{
	if (timer <= duration)
	{
		timer++;
	}
}

int Frame::getNumber()
{
	return number;
}

bool Frame::finished()
{
	return (timer > duration);
}

void Frame::reset()
{
	timer = 0;
}

Frame::~Frame()
{
}
