#ifndef LEVEL_LOADER_H
#define LEVEL_LOADER_H

#include <fstream>
#include "Level.h"

#define LEVELS_FILE "levels.txt"

class LevelLoader
{
public:
	static std::map<std::string, Level*> loadLevels();
	static Level* loadLevel(std::string _dataPath, std::string _tilesetPath);
	static std::string getStringAfterChar(std::string _line, char _char);
	static std::vector<std::string> parseLine(std::string _line, char _char);
};

#endif