#ifndef LEVEL_LOADER_H
#define LEVEL_LOADER_H

#include <fstream>
#include "Level.h"

class LevelLoader
{
public:
	static Level loadLevel(std::string _dataPath, std::string _tilesetPath);
	static std::string getStringAfterChar(std::string _line, char _char);
};

#endif