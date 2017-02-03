#include <SFML/Graphics.hpp>
#include "Image.h"
#include "Frame.h"
#include "Animation.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "ZeePlat");
	Image img = Image(sf::Vector2f(10, 10), sf::Vector2f(100, 100), "caca.png");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		img.draw(&window);

		window.display();
	}

	return 0;
}