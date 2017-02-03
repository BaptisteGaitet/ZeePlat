#include <SFML/Graphics.hpp>
#include "Image.h"
#include "Frame.h"
#include "Animation.h"
#include "AnimatedImage.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "ZeePlat");
	window.setFramerateLimit(60);
	Image img = Image(sf::Vector2f(10, 10), sf::Vector2f(100, 100), "caca.png");
	AnimatedImage anim = AnimatedImage(sf::Vector2f(400,300), sf::Vector2f(200,200), "cacanim.png", 2, 3);
	std::vector<Frame> idle = { Frame(0, 10), Frame(1, 10), Frame(2, 10), Frame(3, 10), Frame(4, 10), Frame(5, 10) };
	anim.addAnimation("idle", Animation(idle, true ));
	anim.play("idle");

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

		anim.update();
		anim.draw(&window);

		window.display();
	}

	return 0;
}