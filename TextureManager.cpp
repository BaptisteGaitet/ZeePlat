#include "TextureManager.h"

TextureManager::TextureManager()
{
	textures = std::map<std::string, sf::Texture>();
}

TextureManager& TextureManager::getInstance()
{
	static TextureManager instance;

	return instance;
}

void TextureManager::addTexture(std::string _path)
{
	if (!hasTexture(_path))
	{
		std::cout << " -> Loading " + _path + "\n";
		sf::Texture newTexture;
		if (!newTexture.loadFromFile(_path))
		{
			std::cout << "TextureManager: Error loading: " << _path << "\n";
		}
		std::pair<std::string, sf::Texture> newEntry = std::pair<std::string, sf::Texture>(_path, newTexture);
		textures.insert(newEntry);
	}
}

sf::Texture* TextureManager::getTexture(std::string _id)
{
	sf::Texture* res = nullptr;

	if (hasTexture(_id))
	{
		res = &textures.at(_id);
	}

	return res;
}

bool TextureManager::hasTexture(std::string _id)
{
	bool valid = true;

	// Try to access the corresponding Texture
	try
	{
		textures.at(_id);
	}
	catch (const std::out_of_range& oor)
	{
		// Set return value to false
		valid = false;
		// Log the error
		std::cerr << "TextureManager: Out of Range error: " << oor.what() << "\n";
	}

	return valid;
}

void TextureManager::setRepeated(std::string _id, bool _repeated)
{
	if (hasTexture(_id))
	{
		textures.at(_id).setRepeated(_repeated);
	}
}

TextureManager::~TextureManager()
{
}
