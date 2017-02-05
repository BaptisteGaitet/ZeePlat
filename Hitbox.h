#ifndef HITBOX_H
#define HITBOX_H

#include <iostream>
#include <SFML\Graphics.hpp>
#include "VectorMath.h"

struct Contact{
	bool left;
	bool right;
	bool top;
	bool bottom;
};

class Hitbox
{
private:
	sf::Vector2f offset;
	sf::FloatRect rect;
	bool pushable;
	bool collideHorizontally;
	bool collideVertically;

	Contact contacts;
public:
	Hitbox();
	Hitbox(sf::FloatRect _rect, sf::Vector2f _offset, bool _pushable, bool _collideHorizontally, bool _collideVertically);

	sf::FloatRect getRect();
	void setPosition(sf::Vector2f _position);
	void setSize(sf::Vector2f _size);
	void setOffset(sf::Vector2f _offset);
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	sf::Vector2f getOffset();

	bool contains(sf::Vector2f _point);

	void setPushable(bool _pushable);
	bool isPushable();
	void setCollideHorizontally(bool _collideHorizontally);
	bool getCollideHorizontally();
	void setCollideVertically(bool _collideVertically);
	bool getCollideVertically();

	Contact getContacts();
	void setContacts(Contact _contacts);
	void resetContacts();

	sf::Vector2f overlap(Hitbox* _hitbox);
	void separate(Hitbox* _hitbox, sf::Vector2f _overlap);
	void separateOneAxis(Hitbox* _hitbox, sf::Vector2f _overlap, bool _horizontal);
	void separateBothAxis(Hitbox* _hitbox, sf::Vector2f _overlap);

	~Hitbox();
};

#endif
