#include "WarpZone.h"


WarpZone::WarpZone(sf::FloatRect _zone, std::string _destinationId, sf::Vector2f _destinationPosition)
{
	zone = _zone;
	destinationId = _destinationId;
	destinationPosition = _destinationPosition;
}

bool WarpZone::overlap(sf::FloatRect _rect)
{
	sf::Vector2f overlap = sf::Vector2f(0, 0);

	// Horizontal
	if (zone.left < _rect.left)
	{
		if (_rect.left < zone.left + zone.width)
		{
			overlap.x = (zone.left + zone.width) - _rect.left;
		}
	}
	else
	{
		if (zone.left < _rect.left + _rect.width)
		{
			overlap.x = -1 * ((_rect.left + _rect.width) - zone.left);
		}
	}

	// Vertical
	if (zone.top < _rect.top)
	{
		if (_rect.top < zone.top + zone.height)
		{
			overlap.y = (zone.top + zone.height) - _rect.top;
		}
	}
	else
	{
		if (zone.top < _rect.top + _rect.height)
		{
			overlap.y = -1 * ((_rect.top + _rect.height) - zone.top);
		}
	}

	return (overlap.x !=0 && overlap.y != 0);
}

std::string WarpZone::getDestinationId()
{
	return destinationId;
}

sf::Vector2f WarpZone::getDestinationPosition()
{
	return destinationPosition;
}

WarpZone::~WarpZone()
{
}
