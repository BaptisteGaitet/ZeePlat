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
	Image();
	Image(sf::Vector2f _position, sf::Vector2f _size, std::string _path);
	Image(sf::Vector2f _position, sf::Vector2f _size, std::string _path, sf::IntRect _textureRect);
	Image(sf::Vector2f _position, sf::Vector2f _size, std::string _path, sf::Vector2i _tileSize, int _tileIndex);

	void draw(sf::RenderWindow* window);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f);
	sf::Vector2f getCenter();

	~Image();
};

#endif