#include "LevelLoader.h"

Level LevelLoader::loadLevel(std::string _dataPath, std::string _tilesetPath)
{
	std::ifstream file;
	std::string line;
	file.open(_dataPath);

	TileMap* backLayer = nullptr;
	TileMap* mainLayer = nullptr;
	TileMap* frontLayer = nullptr;
	std::vector<Entity*> entities = std::vector<Entity*>();
	entities.resize(0);

	if (file.is_open())
	{ 
		sf::FloatRect mapBounds;
		sf::Vector2i tabSize;
		sf::Vector2i tileSize;
		while (std::getline(file, line))
		{
			if (line == "[header]")
			{
				// read Width
				std::getline(file, line);
				tabSize.x = atoi(getStringAfterChar(line, '=').c_str());
				std::cout << "tabSize.x = " << tabSize.x << "\n";
				// read Height
				std::getline(file, line);
				tabSize.y = atoi(getStringAfterChar(line, '=').c_str());
				std::cout << "tabSize.y = " << tabSize.y << "\n";
				// read tileWidth
				std::getline(file, line);
				tileSize.x = atoi(getStringAfterChar(line, '=').c_str());
				std::cout << "tileSize.x = " << tileSize.x << "\n";
				// read tileHeight
				std::getline(file, line);
				tileSize.y = atoi(getStringAfterChar(line, '=').c_str());
				std::cout << "tileSize.x = " << tileSize.y << "\n";

				// set mapBounds
				mapBounds.left = 0;
				mapBounds.top = 0;
				mapBounds.width = tabSize.x * tileSize.x;
				std::cout << "mapBounds.width = " << mapBounds.width << "\n";
				mapBounds.height = tabSize.y * tileSize.y;
				std::cout << "mapBounds.height = " << mapBounds.height << "\n";
			}
			else if (line == "[layer]")
			{
				bool* tabHitboxes = new bool[tabSize.x * tabSize.y];
				int* tabTiles = new int[tabSize.x * tabSize.y];

				for (int i = 0; i < tabSize.x; i++)
				{
					for (int j = 0; j < tabSize.y; j++)
					{
						tabTiles[j * tabSize.x + i] = 0;
						tabHitboxes[j * tabSize.x + i] = false;
					}
				}

				// read layerName
				std::getline(file, line);
				std::string layerName = getStringAfterChar(line, '=');

				// Jump a line
				std::getline(file, line);

				// Get tile & hitbox values
				if (layerName == "main")
				{
					for (int i = 0; i < tabSize.y; i++)
					{
						std::getline(file, line);
						int valueCount = 0;
						for (int j = 0; j < line.length(); j++)
						{
							if (line.at(j) != ',')
							{
								if (line.at(j) != '0')
								{
									tabTiles[i * tabSize.x + valueCount] = atoi(&line.at(j))-1;
									//std::cout << atoi(&line.at(j));
									tabHitboxes[i * tabSize.x + valueCount] = true;
								}
								else
								{
									tabHitboxes[i * tabSize.x + valueCount] = false;
								}
								valueCount++;
							}
						}
						//std::cout << "\n";
					}
					// create layer
					mainLayer = new TileMap(mapBounds, tabSize, tileSize, _tilesetPath, tabTiles, tabHitboxes);
					// reset tabs
					for (int i = 0; i < tabSize.x; i++)
					{
						for (int j = 0; j < tabSize.y; j++)
						{
							tabTiles[j * tabSize.x + i] = 0;
							tabHitboxes[j * tabSize.x + i] = false;
						}
					}
				}
				else
				{
					for (int i = 0; i < tabSize.y; i++)
					{
						std::getline(file, line);
						int valueCount = 0;
						for (int j = 0; j < line.length(); j++)
						{
							
							if (line.at(j) != ',')
							{
								if (line.at(j) != '0')
								{
									tabTiles[i * tabSize.x + valueCount] = atoi(&line.at(j))-1;
								}
								valueCount++;
							}
						}
					}
					// create layer
					if (layerName == "front")
					{
						frontLayer = new TileMap(mapBounds, tabSize, tileSize, _tilesetPath, tabTiles, tabHitboxes);
					}
					else
					{
						backLayer = new TileMap(mapBounds, tabSize, tileSize, _tilesetPath, tabTiles, tabHitboxes);
					}

					// reset tabs
					for (int i = 0; i < tabSize.x; i++)
					{
						for (int j = 0; j < tabSize.y; j++)
						{
							tabTiles[j * tabSize.x + i] = 0;
							tabHitboxes[j * tabSize.x + i] = false;
						}
					}
				}
			}
		}
	}
	else
	{
		std::cout << "LevelLoader: Can't open file: " + _dataPath + "\n";
	}

	file.close();

	return Level(backLayer, mainLayer, frontLayer, std::vector<Entity*>(), sf::Color(10, 10, 10));
}

std::string LevelLoader::getStringAfterChar(std::string _line, char _char)
{
	std::string res;
	bool after = false;

	for (int i = 0; i < _line.length(); i++)
	{
		if (after)
		{
			res += _line.at(i);
		}
		else if (_line.at(i) == _char)
		{
			after = true;
		}
	}

	return res;
}