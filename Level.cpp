#include "Level.h"


Level::Level(TileMap* _backLayer, TileMap* _mainLayer, TileMap* _frontLayer, std::vector<Entity*> _entities, sf::Color _backgroundColor)
{
	backLayer = _backLayer;
	mainLayer = _mainLayer;
	frontLayer = _frontLayer;

	/*for (int i = 0; i < _entities.size(); i++)
	{
		entities.push_back(_entities.at(i));
	}*/

	background.setFillColor(_backgroundColor);
}

void Level::update()
{
	for (int i = 0; i < entities.size(); i++)
	{
		entities.at(i)->update();
	}
}

void Level::drawBackground(sf::RenderWindow* window)
{
	window->draw(background);
	backLayer->draw(window);
	mainLayer->draw(window);
}

void Level::drawForeground(sf::RenderWindow* window)
{
	frontLayer->draw(window);
}

void Level::separate(Body* _body)
{
	mainLayer->separate(_body);
}

Level::~Level()
{
}
