#include "Level.h"


Level::Level(TileMap* _backLayer, TileMap* _mainLayer, TileMap* _frontLayer, std::vector<Entity*> _entities, sf::Color _backgroundColor)
{
	backLayer = _backLayer;
	mainLayer = _mainLayer;
	frontLayer = _frontLayer;

	for (int i = 0; i < _entities.size(); i++)
	{
		entities.push_back(_entities.at(i));
	}

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

void Level::setWarpZones(std::vector<WarpZone> _warpZones)
{
	for (int i = 0; i < _warpZones.size(); i++)
	{
		warpZones.push_back(_warpZones.at(i));
	}
}

WarpZone Level::getOvelapingWarpZone(sf::FloatRect _rect)
{
	WarpZone res = WarpZone(sf::FloatRect(0, 0, 0, 0), "", sf::Vector2f(0, 0));

	for (int i = 0; i < warpZones.size(); i++)
	{
		if (warpZones.at(i).overlap(_rect))
		{
			res = warpZones.at(i);
		}
	}

	return res;
}

Level::~Level()
{
}
