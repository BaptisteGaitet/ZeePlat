#include "Image.h"

Image::Image()
{
	shape = sf::RectangleShape();
}

Image::Image(sf::Vector2f _position, sf::Vector2f _size, std::string _path)
{
	shape = sf::RectangleShape();
	shape.setPosition(_position);
	shape.setSize(_size);

	TextureManager::getInstance().addTexture(_path);
	shape.setTexture(TextureManager::getInstance().getTexture(_path));
}

Image::Image(sf::Vector2f _position, sf::Vector2f _size, std::string _path, sf::IntRect _textureRect)
{
	shape = sf::RectangleShape();
	shape.setPosition(_position);
	shape.setSize(_size);

	TextureManager::getInstance().addTexture(_path);
	shape.setTexture(TextureManager::getInstance().getTexture(_path));

	setTextureRect(_textureRect);
}

Image::Image(sf::Vector2f _position, sf::Vector2f _size, std::string _path, sf::Vector2i _tileSize, int _tileIndex)
{
	shape = sf::RectangleShape();
	shape.setPosition(_position);
	shape.setSize(_size);

	TextureManager::getInstance().addTexture(_path);
	shape.setTexture(TextureManager::getInstance().getTexture(_path));

	int columns = floor(TextureManager::getInstance().getTexture(_path)->getSize().x / _tileSize.x);

	setTextureRect(sf::IntRect(_tileSize.x * floor(_tileIndex % columns), _tileSize.y * floor(_tileIndex / columns), _tileSize.x, _tileSize.y));
}

void Image::setTextureRect(sf::IntRect _rect)
{
	shape.setTextureRect(_rect);
}

void Image::draw(sf::RenderWindow* window)
{
	window->draw(shape);
}

sf::Vector2f Image::getPosition()
{
	return shape.getPosition();
}

void Image::setPosition(sf::Vector2f _position)
{
	shape.setPosition(_position);
}

sf::Vector2f Image::getCenter()
{
	return sf::Vector2f(shape.getPosition().x + (shape.getSize().x / 2), shape.getPosition().y + (shape.getSize().y / 2));
}

Image::~Image()
{
}
