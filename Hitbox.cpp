#include "Hitbox.h"


Hitbox::Hitbox(sf::FloatRect _hitbox, bool _pushable)
{
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

void Hitbox::resolveCollision(Hitbox* _hitbox)
{
	float verticalOverlap = 0;
	float horizontalOverlap = 0;

	// Horizontal
	if (rect.left < _hitbox->getRect().left)
	{
		if (_hitbox->getRect().left < rect.left + rect.width)
		{
			horizontalOverlap = (rect.left + rect.width) - _hitbox->getRect().left;
		}
	}
	else
	{
		if (rect.left < _hitbox->getRect().left + _hitbox->getRect().width)
		{
			horizontalOverlap = -1 * ((_hitbox->getRect().left + _hitbox->getRect().width) - rect.left);
		}
	}

	// Vertical
	if (rect.top < _hitbox->getRect().top)
	{
		if (_hitbox->getRect().top < rect.top + rect.height)
		{
			verticalOverlap = (rect.top + rect.height) - _hitbox->getRect().top;
		}
	}
	else
	{
		if (rect.top < _hitbox->getRect().top + _hitbox->getRect().height)
		{
			verticalOverlap = -1 * ((_hitbox->getRect().top + _hitbox->getRect().height) - rect.top);
		}
	}

	// Separation
	std::cout << horizontalOverlap << ", " << verticalOverlap << "\n";
	if (horizontalOverlap != 0 && verticalOverlap != 0)
	{
		if (abs(horizontalOverlap) <= abs(verticalOverlap))
		{
			if (pushable && _hitbox->isPushable())
			{
				rect.left -= horizontalOverlap / 2;

				_hitbox->setPosition(sf::Vector2f(_hitbox->getPosition().x + (horizontalOverlap / 2), _hitbox->getPosition().y));
			}
			else if (pushable && !_hitbox->isPushable())
			{
				rect.left -= horizontalOverlap;
			}
			else if (pushable && !_hitbox->isPushable())
			{
				_hitbox->setPosition(sf::Vector2f(_hitbox->getPosition().x + horizontalOverlap, _hitbox->getPosition().y));
			}
		}
		else
		{
			if (pushable && _hitbox->isPushable())
			{
				rect.top -= verticalOverlap / 2;

				_hitbox->setPosition(sf::Vector2f(_hitbox->getPosition().x, _hitbox->getPosition().y + (verticalOverlap / 2)));
			}
			else if (pushable && !_hitbox->isPushable())
			{
				rect.top -= verticalOverlap;
			}
			else if (pushable && !_hitbox->isPushable())
			{
				_hitbox->setPosition(sf::Vector2f(_hitbox->getPosition().x, _hitbox->getPosition().y + verticalOverlap));
			}
		}
	}
}

void Hitbox::setPosition(sf::Vector2f _position)
{
	rect.left = _position.x;
	rect.top = _position.y;
}

sf::Vector2f Hitbox::getPosition()
{
	return sf::Vector2f(rect.left, rect.top);
}

sf::Vector2f Hitbox::getSize()
{
	return sf::Vector2f(rect.width, rect.height);
}

bool Hitbox::isPushable()
{
	return pushable;
}

Hitbox::~Hitbox()
{
}
