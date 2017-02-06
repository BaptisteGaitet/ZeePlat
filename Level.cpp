#include "Level.h"


Level::Level()
{
}

void Level::draw(sf::RenderWindow* window)
{
	background.draw(window);
	for (int i = 0; i < layers.size(); i++)
	{
		layers.at(i).draw(window);
	}
}

Level::~Level()
{
}
