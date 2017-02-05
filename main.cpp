#include <SFML/Graphics.hpp>
#include "Image.h"
#include "Frame.h"
#include "Animation.h"
#include "AnimatedImage.h"
#include "Hitbox.h"
#include "Body.h"
#include "TileMap.h"
#include "Player.h"

int main()
{
	Player player = Player(sf::Vector2f(64,64));

	int indexes[20 * 16] = {
		5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
		4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4,
		4, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 4,
		4, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 4,
		4, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 4,
		4, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 4,
		4, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 4,
		4, 3, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 4,
		4, 3, 6, 6, 3, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 4,
		4, 3, 6, 6, 6, 6, 6, 3, 3, 6, 6, 3, 3, 6, 6, 3, 3, 6, 3, 4,
		4, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 4,
		4, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 3, 4,
		4, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 3, 3, 4,
		4, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 3, 3, 3, 4,
		4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4,
		5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5
	};

	bool hitboxes[20 * 16] = {
		true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true,
		true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true,
		true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true,
		true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true,
		true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true,
		true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true,
		true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true,
		true, true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true,
		true, true, false, false, true, true, false, false, false, false, false, false, false, false, false, false, false, false, true, true,
		true, true, false, false, false, false, false, true, true, false, false, true, true, false, false, true, true, false, true, true,
		true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true,
		true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, true,
		true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, true, true,
		true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, true, true, true,
		true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true,
		true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true,
	};

	sf::RenderWindow window(sf::VideoMode(800, 600), "ZeePlat");
	window.setFramerateLimit(60);

	TileMap map = TileMap(sf::FloatRect(0, 0, 20*32, 16*32), sf::Vector2i(20, 16), sf::Vector2i(8, 8), "test8x8.png", indexes, hitboxes);

	sf::RectangleShape hb = sf::RectangleShape(sf::Vector2f(16, 16));
	hb.setFillColor(sf::Color(100, 200, 100, 128));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		player.update();
		
		map.separate(player.getBody());

		//hb.setPosition(player.getHitbox()->getPosition());

		window.clear();

		map.draw(&window);

		player.draw(&window);

		//window.draw(hb);

		window.display();
	}

	return 0;
}