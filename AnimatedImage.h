#ifndef ANIMATED_IMAGE_H
#define ANIMATED_IMAGE_H

#include "Image.h"
#include "AnimationManager.h"
#include "Animation.h"

class AnimatedImage :
	public Image
{
private:
	AnimationManager animMngr;
	int rows;
	int columns;
	sf::Vector2i frameSize;
public:
	AnimatedImage();
	AnimatedImage(sf::Vector2f _position, sf::Vector2f _size, std::string _path, int rows, int columns);

	void update();
	void addAnimation(std::string _id, Animation animation);
	void play(std::string _id);
	void pause();
	void resume();

	~AnimatedImage();
};

#endif