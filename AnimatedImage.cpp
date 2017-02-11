#include "AnimatedImage.h"

AnimatedImage::AnimatedImage() : Image(sf::Vector2f(0, 0), sf::Vector2f(0, 0), "")
{
	rows = 0;
	columns = 0;
	frameSize = sf::Vector2i(0, 0);
	animMngr = AnimationManager();
}

AnimatedImage::AnimatedImage(sf::Vector2f _position, sf::Vector2f _size, std::string _path, int _rows, int _columns) : Image(_position, _size, _path)
{
	rows = _rows;
	columns = _columns;

	frameSize = sf::Vector2i(0,0);
	frameSize.x = TextureManager::getInstance().getTexture(_path)->getSize().x / columns;
	frameSize.y = TextureManager::getInstance().getTexture(_path)->getSize().y / rows;
	setTextureRect(sf::IntRect(0, 0, frameSize.x, frameSize.y));

	animMngr = AnimationManager();
}

void AnimatedImage::update()
{
	animMngr.update();

	setTextureRect(sf::IntRect(frameSize.x * floor(animMngr.getCurrentFrameNumber() % columns), frameSize.y * floor(animMngr.getCurrentFrameNumber() / columns), frameSize.x, frameSize.y));
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

bool AnimatedImage::isFinished()
{
	return animMngr.currentAnimationFinished();
}

std::string AnimatedImage::getCurrentAnimationId()
{
	return animMngr.getCurrentAnimationId();
}

AnimatedImage::~AnimatedImage()
{
}
