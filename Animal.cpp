#include "Animal.h"

Animal::Animal(sf::Vector2f _position, sf::Vector2f _size, std::string _path, int _spriteRows, int _spriteColumns) : Entity(_position, _size, _path, _spriteRows, _spriteColumns)
{
}

Animal::~Animal()
{
}
