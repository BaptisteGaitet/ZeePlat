#ifndef IMAGE_H
#define IMAGE_H

#include <SFML\Graphics.hpp>
#include "TextureManager.h"

class Image
{
private:
	sf::RectangleShape shape;
protected:
	void setTextureRect(sf::IntRect _rect);
public:
	Image(sf::Vector2f _position, sf::Vector2f _size, std::string _path);

	void draw(sf::RenderWindow* window);

	~Image();
};

#endif