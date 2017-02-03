#include "Image.h"


Image::Image(sf::Vector2f _position, sf::Vector2f _size, std::string _path)
{
	shape = sf::RectangleShape();
	shape.setPosition(_position);
	shape.setSize(_size);

	TextureManager::getInstance().addTexture(_path);
	shape.setTexture(TextureManager::getInstance().getTexture(_path));
}

void Image::setTextureRect(sf::IntRect _rect)
{
	shape.setTextureRect(_rect);
}

void Image::draw(sf::RenderWindow* window)
{
	window->draw(shape);
}

Image::~Image()
{
}
