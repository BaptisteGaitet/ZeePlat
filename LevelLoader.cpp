#include "LevelLoader.h"

std::map<std::string, Level*> LevelLoader::loadLevels()
{
	std::map<std::string, Level*> res;
	std::ifstream file;
	std::string line;
	file.open(LEVELS_FILE);

	if (file.is_open())
	{
		std::cout << LEVELS_FILE << " opened\n";
		while (std::getline(file, line))
		{
			if (line.size() > 0)
			{
				if (line.at(0) == 'l')
				{
					std::vector<std::string> parsedLevel = parseLine(line, '/');
					res.insert(std::pair<std::string, Level*>(parsedLevel.at(1), loadLevel(parsedLevel.at(1) + ".txt", parsedLevel.at(2) + ".png")));
					std::cout << "Added " << parsedLevel.at(1) << "\n";
					
					std::vector<WarpZone> warps;
					std::getline(file, line);
					while (line.size() > 0 && !file.fail())
					{
						std::vector<std::string> parsedWarp = parseLine(line, '/');
						sf::FloatRect rect = sf::FloatRect(
							atoi(parsedWarp.at(1).c_str()),
							atoi(parsedWarp.at(2).c_str()),
							atoi(parsedWarp.at(3).c_str()),
							atoi(parsedWarp.at(4).c_str())
						);
						std::cout << rect.left << ", " << rect.top << ", " << rect.width << ", " << rect.height << "\n";
						std::string destinationId = parsedWarp.at(5);
						std::cout << destinationId << "\n";
						sf::Vector2f destinationPosition = sf::Vector2f(
							atoi(parsedWarp.at(6).c_str()),
							atoi(parsedWarp.at(7).c_str())
						);
						std::cout << destinationPosition.x << ", " << destinationPosition.y << "\n";
						warps.push_back(WarpZone(rect, destinationId, destinationPosition));

						std::getline(file, line);
						std::cout << "line: " << line << "\n";
					}
					res.at(parsedLevel.at(1))->setWarpZones(warps);
				}
			}
		}
	}
	else
	{
		std::cout << "LevelLoader: Can't open file: " << LEVELS_FILE << "\n";
	}

	file.close();

	return res;
}

Level* LevelLoader::loadLevel(std::string _dataPath, std::string _tilesetPath)
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
				// read Height
				std::getline(file, line);
				tabSize.y = atoi(getStringAfterChar(line, '=').c_str());
				// read tileWidth
				std::getline(file, line);
				tileSize.x = atoi(getStringAfterChar(line, '=').c_str());
				// read tileHeight
				std::getline(file, line);
				tileSize.y = atoi(getStringAfterChar(line, '=').c_str());

				// set mapBounds
				mapBounds.left = 0;
				mapBounds.top = 0;
				mapBounds.width = tabSize.x * tileSize.x;
				mapBounds.height = tabSize.y * tileSize.y;
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

	return new Level(backLayer, mainLayer, frontLayer, std::vector<Entity*>(), sf::Color(10, 10, 10));
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

std::vector<std::string> LevelLoader::parseLine(std::string _line, char _char)
{
	std::vector<std::string> res;
	std::string current = "";

	std::cout << _line << "\n";
	for (int i = 0; i < _line.size(); i++)
	{
		if (_line.at(i) != _char)
		{
			current += _line.at(i);
		}
		else
		{
			res.push_back(current);
			current = "";
		}
	}
	res.push_back(current);

	return res;
}