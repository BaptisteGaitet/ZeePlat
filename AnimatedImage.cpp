#include "AnimatedImage.h"


AnimatedImage::AnimatedImage(sf::Vector2f _position, sf::Vector2f _size, std::string _path, int _rows, int _columns) : Image(_position, _size, _path)
{
	rows = _rows;
	columns = _columns;

	frameSize = sf::Vector2i(0,0);
	frameSize.x = TextureManager::getInstance().getTexture(_path)->getSize().x / rows;
	frameSize.y = TextureManager::getInstance().getTexture(_path)->getSize().y / rows;
	setTextureRect(sf::IntRect(0, 0, frameSize.x, frameSize.y));

	animMngr = AnimationManager();
}

void AnimatedImage::update()
{
	animMngr.update();

	setTextureRect(sf::IntRect(frameSize.x * (animMngr.getCurrentFrameNumber() % rows), frameSize.y * (animMngr.getCurrentFrameNumber() - (animMngr.getCurrentFrameNumber() % rows)), frameSize.x, frameSize.y));
}

void AnimatedImage::addAnimation(std::string _id, Animation _animation)
{
	animMngr.addAnimation(_id, _animation);
}

void AnimatedImage::play(std::string _id)
{
	animMngr.play(_id);
}

void AnimatedImage::pause()
{
	animMngr.pause();
}

void AnimatedImage::resume()
{
	animMngr.resume();
}

AnimatedImage::~AnimatedImage()
{
}
