#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML\Graphics.hpp>
#include <iostream>
#include <map>
#include <string>

class TextureManager
{
private:
	TextureManager();
	TextureManager(TextureManager const&);
	void operator=(TextureManager const&);

	std::map<std::string, sf::Texture> textures;

	bool hasTexture(std::string _id);
public:
	static TextureManager& getInstance();

	void addTexture(std::string _path);
	sf::Texture* getTexture(std::string _id);
	void setRepeated(std::string _id, bool repeated);

	~TextureManager();
};

#endif