#ifndef FRAME_H
#define FRAME_H

class Frame
{
private:
	int number;
	int duration;
	int timer;
public:
	Frame(int _number, int _duration);

	void update();

	int getNumber();
	bool finished();
	void reset();

	~Frame();
};

#endif