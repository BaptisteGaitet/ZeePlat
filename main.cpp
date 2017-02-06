#include <SFML/Graphics.hpp>
#include "Image.h"
#include "Frame.h"
#include "Animation.h"
#include "AnimatedImage.h"
#include "Hitbox.h"
#include "Body.h"
#include "Level.h"
#include "LevelLoader.h"
#include "Player.h"

int main()
{
	Player player = Player(sf::Vector2f(100,100));

	Level lvl = LevelLoader::loadLevel("test.txt", "test8x8.png");

	/*int indexes[20 * 16] = {
		3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3,
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
		3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3
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
	};*/

	sf::RenderWindow window(sf::VideoMode(800, 600), "ZeePlat");
	window.setFramerateLimit(60);

	//TileMap map = TileMap(sf::FloatRect(0, 0, 20*32, 16*32), sf::Vector2i(20, 16), sf::Vector2i(8, 8), "test8x8.png", indexes, hitboxes);

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
		
		lvl.separate(player.getBody());

		//hb.setPosition(player.getHitbox()->getPosition());

		window.clear();

		//map.draw(&window);
		lvl.drawBackground(&window);

		player.draw(&window);

		lvl.drawForeground(&window);
		//window.draw(hb);

		window.display();
	}

	return 0;
}