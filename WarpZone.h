#ifndef WARP_ZONE_H
#define WARP_ZONE_H

#include <SFML/Graphics.hpp>

class WarpZone
{
private:
	sf::FloatRect zone;
	std::string destinationId;
	sf::Vector2f destinationPosition;
public:
	WarpZone(sf::FloatRect _zone, std::string _destinationId, sf::Vector2f _destinationPosition);

	bool overlap(sf::FloatRect _rect);
	std::string getDestinationId();
	sf::Vector2f getDestinationPosition();

	~WarpZone();
};

#endif