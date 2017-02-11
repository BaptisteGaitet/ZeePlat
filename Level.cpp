#include "Level.h"


Level::Level(TileMap* _backLayer, TileMap* _mainLayer, TileMap* _frontLayer, std::vector<Animal*> _animals, sf::Color _backgroundColor)
{
	backLayer = _backLayer;
	mainLayer = _mainLayer;
	frontLayer = _frontLayer;

	for (int i = 0; i < _animals.size(); i++)
	{
		animals.push_back(_animals.at(i));
	}

	background.setFillColor(_backgroundColor);
}

void Level::update(ParticleManager* _partMngr, sf::Vector2f _playerPosition)
{
	for (int i = 0; i < animals.size(); i++)
	{
		animals.at(i)->update(_partMngr);
		animals.at(i)->updateAI(_playerPosition, mainLayer);
		separate(animals.at(i)->getBody());
	}

	if (rand() % 10 + 1 > 8)
	{
		sf::Vector2f partPos;
		partPos.x = rand() % (mainLayer->getSize().x * mainLayer->getTileSize().x);
		partPos.y = rand() % (mainLayer->getSize().y * mainLayer->getTileSize().y);
		_partMngr->addParticle(Particle(partPos, sf::Vector2f(0,0), 0.01f, 0.9f, 100 + (rand() % 100 + 1), sf::Color(100, 250, 250)));
	}
}

void Level::drawBackground(sf::RenderWindow* window)
{
	window->draw(background);
	backLayer->draw(window);
	mainLayer->draw(window);

	for (int i = 0; i < animals.size(); i++)
	{
		animals.at(i)->draw(window);
	}
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
