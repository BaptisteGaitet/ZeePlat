#include "Hitbox.h"

Hitbox::Hitbox()
{
	contacts.left = false;
	contacts.right = false;
	contacts.top = false;
	contacts.bottom = false;

	rect = sf::FloatRect(0,0,0,0);
	offset = sf::Vector2f(0,0);
	pushable = false;
}

Hitbox::Hitbox(sf::FloatRect _hitbox, sf::Vector2f _offset, bool _pushable, bool _collideHorizontally, bool _collideVertically)
{
	collideHorizontally = _collideHorizontally;
	collideVertically = _collideVertically;
	offset = _offset;

	contacts.left = false;
	contacts.right = false;
	contacts.top = false;
	contacts.bottom = false;

	rect = _hitbox;
	pushable = _pushable;
}

bool Hitbox::contains(sf::Vector2f _point)
{
	bool res = false;

	if (_point.x > rect.left && _point.x < (rect.left + rect.width) && _point.y > rect.top && _point.y < (rect.top + rect.width))
	{
		res = true;
	}

	return res;
}

sf::FloatRect Hitbox::getRect()
{
	return rect;
}

void Hitbox::setPosition(sf::Vector2f _position)
{
	rect.left = _position.x;
	rect.top = _position.y;
}

void Hitbox::setSize(sf::Vector2f _size)
{
	rect.width = _size.x;
	rect.height = _size.y;
}

void Hitbox::setOffset(sf::Vector2f _offset)
{
	offset.x = _offset.x;
	offset.y = _offset.y;
}

sf::Vector2f Hitbox::getPosition()
{
	return sf::Vector2f(rect.left, rect.top);
}

sf::Vector2f Hitbox::getSize()
{
	return sf::Vector2f(rect.width, rect.height);
}

sf::Vector2f Hitbox::getOffset()
{
	return offset;
}

void Hitbox::setPushable(bool _pushable)
{
	pushable = _pushable;
}

bool Hitbox::isPushable()
{
	return pushable;
}

void Hitbox::setCollideHorizontally(bool _collideHorizontally)
{
	collideHorizontally = _collideHorizontally;
}

bool Hitbox::getCollideHorizontally()
{
	return collideHorizontally;
}

void Hitbox::setCollideVertically(bool _collideVertically)
{
	collideVertically= _collideVertically;
}

bool Hitbox::getCollideVertically()
{
	return collideVertically;
}

Contact Hitbox::getContacts()
{
	return contacts;
}

void Hitbox::setContacts(Contact _contacts)
{
	contacts = _contacts;
}

void Hitbox::resetContacts()
{
	contacts.top = false;
	contacts.bottom = false;
	contacts.left = false;
	contacts.right = false;
}

sf::Vector2f Hitbox::overlap(Hitbox* _hitbox)
{
	sf::Vector2f overlap = sf::Vector2f(0, 0);

	// Horizontal
	if (rect.left < _hitbox->getRect().left)
	{
		if (_hitbox->getRect().left < rect.left + rect.width)
		{
			overlap.x = (rect.left + rect.width) - _hitbox->getRect().left;
		}
	}
	else
	{
		if (rect.left < _hitbox->getRect().left + _hitbox->getRect().width)
		{
			overlap.x = -1 * ((_hitbox->getRect().left + _hitbox->getRect().width) - rect.left);
		}
	}

	// Vertical
	if (rect.top < _hitbox->getRect().top)
	{
		if (_hitbox->getRect().top < rect.top + rect.height)
		{
			overlap.y = (rect.top + rect.height) - _hitbox->getRect().top;
		}
	}
	else
	{
		if (rect.top < _hitbox->getRect().top + _hitbox->getRect().height)
		{
			overlap.y = -1 * ((_hitbox->getRect().top + _hitbox->getRect().height) - rect.top);
		}
	}

	return overlap;
}

void Hitbox::separate(Hitbox* _hitbox, sf::Vector2f _overlap)
{
	if (_overlap.x != 0 && _overlap.y != 0)
	{
		if (collideHorizontally && _hitbox->collideHorizontally && collideVertically && _hitbox->collideVertically)
		{
			separateBothAxis(_hitbox, _overlap);
		}
		else if (collideHorizontally && _hitbox->collideHorizontally)
		{
			separateOneAxis(_hitbox, _overlap, true);
		}
		else if (collideVertically && _hitbox->collideVertically)
		{
			separateOneAxis(_hitbox, _overlap, false);
		}
	}
}

void Hitbox::separateOneAxis(Hitbox* _hitbox, sf::Vector2f _overlap, bool _horizontal)
{
	if (_overlap.x != 0 && _overlap.y != 0)
	{
		if (_horizontal)
		{
			if (_overlap.x > 0)
			{
				contacts.right = true;
				Contact tmp = _hitbox->getContacts();
				tmp.left = true;
				_hitbox->setContacts(tmp);
			}
			else
			{
				contacts.left = true;
				Contact tmp = _hitbox->getContacts();
				tmp.right = true;
				_hitbox->setContacts(tmp);
			}

			if (pushable && _hitbox->isPushable())
			{
				rect.left -= _overlap.x / 2;

				_hitbox->setPosition(sf::Vector2f(_hitbox->getPosition().x + (_overlap.x / 2), _hitbox->getPosition().y));
			}
			else if (pushable && !_hitbox->isPushable())
			{
				rect.left -= _overlap.x;
			}
			else if (!pushable && _hitbox->isPushable())
			{
				_hitbox->setPosition(sf::Vector2f(_hitbox->getPosition().x + _overlap.x, _hitbox->getPosition().y));
			}
		}
		else
		{
			if (_overlap.y > 0)
			{
				contacts.bottom = true;
				Contact tmp = _hitbox->getContacts();
				tmp.top = true;
				_hitbox->setContacts(tmp);
			}
			else
			{
				contacts.top = true;
				Contact tmp = _hitbox->getContacts();
				tmp.bottom = true;
				_hitbox->setContacts(tmp);
			}

			if (pushable && _hitbox->isPushable())
			{
				rect.top -= _overlap.y / 2;

				_hitbox->setPosition(sf::Vector2f(_hitbox->getPosition().x, _hitbox->getPosition().y + (_overlap.y / 2)));
			}
			else if (pushable && !_hitbox->isPushable())
			{
				rect.top -= _overlap.y;
			}
			else if (!pushable && _hitbox->isPushable())
			{
				_hitbox->setPosition(sf::Vector2f(_hitbox->getPosition().x, _hitbox->getPosition().y + _overlap.y));
			}
		}
	}
}

void Hitbox::separateBothAxis(Hitbox* _hitbox, sf::Vector2f _overlap)
{
	if (_overlap.x != 0 && _overlap.y != 0)
	{
		if (abs(_overlap.x) < abs(_overlap.y))
		{
			if (_overlap.x > 0)
			{
				contacts.right = true;
				Contact tmp = _hitbox->getContacts();
				tmp.left = true;
				_hitbox->setContacts(tmp);
			}
			else
			{
				contacts.left = true;
				Contact tmp = _hitbox->getContacts();
				tmp.right = true;
				_hitbox->setContacts(tmp);
			}

			if (pushable && _hitbox->isPushable())
			{
				rect.left -= _overlap.x / 2;

				_hitbox->setPosition(sf::Vector2f(_hitbox->getPosition().x + (_overlap.x / 2), _hitbox->getPosition().y));
			}
			else if (pushable && !_hitbox->isPushable())
			{
				rect.left -= _overlap.x;
			}
			else if (!pushable && _hitbox->isPushable())
			{
				_hitbox->setPosition(sf::Vector2f(_hitbox->getPosition().x + _overlap.x, _hitbox->getPosition().y));
			}
		}
		else
		{
			if (_overlap.y > 0)
			{
				contacts.bottom = true;
				Contact tmp = _hitbox->getContacts();
				tmp.top = true;
				_hitbox->setContacts(tmp);
			}
			else
			{
				contacts.top = true;
				Contact tmp = _hitbox->getContacts();
				tmp.bottom = true;
				_hitbox->setContacts(tmp);
			}

			if (pushable && _hitbox->isPushable())
			{
				rect.top -= _overlap.y / 2;

				_hitbox->setPosition(sf::Vector2f(_hitbox->getPosition().x, _hitbox->getPosition().y + (_overlap.y / 2)));
			}
			else if (pushable && !_hitbox->isPushable())
			{
				rect.top -= _overlap.y;
			}
			else if (!pushable && _hitbox->isPushable())
			{
				_hitbox->setPosition(sf::Vector2f(_hitbox->getPosition().x, _hitbox->getPosition().y + _overlap.y));
			}
		}
	}
}

Hitbox::~Hitbox()
{
}
