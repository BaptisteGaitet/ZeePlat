#include <SFML/Graphics.hpp>
#include "Image.h"
#include "Frame.h"
#include "Animation.h"
#include "AnimatedImage.h"
#include "Hitbox.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "ZeePlat");
	window.setFramerateLimit(60);
	Image img = Image(sf::Vector2f(10, 10), sf::Vector2f(100, 100), "caca.png");
	AnimatedImage anim = AnimatedImage(sf::Vector2f(400,300), sf::Vector2f(200,200), "cacanim.png", 2, 3);
	std::vector<Frame> idle = { Frame(0, 10), Frame(1, 10), Frame(2, 10), Frame(3, 10), Frame(4, 10), Frame(5, 10) };
	anim.addAnimation("idle", Animation(idle, true ));
	anim.play("idle");

	Hitbox hba = Hitbox(sf::FloatRect(100, 100, 50, 50), true);
	Hitbox hbb = Hitbox(sf::FloatRect(100, 110, 50, 50), false);

	sf::RectangleShape rca = sf::RectangleShape();
	rca.setPosition(hba.getPosition());
	rca.setSize(hba.getSize());
	rca.setFillColor(sf::Color(100, 10, 10));

	sf::RectangleShape rcb = sf::RectangleShape();
	rcb.setPosition(hbb.getPosition());
	rcb.setSize(hbb.getSize());
	rcb.setFillColor(sf::Color(10, 100, 10));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// TEST //

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			hba.setPosition(sf::Vector2f(hba.getPosition().x, hba.getPosition().y - 1));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			hba.setPosition(sf::Vector2f(hba.getPosition().x, hba.getPosition().y + 1));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			hba.setPosition(sf::Vector2f(hba.getPosition().x - 1, hba.getPosition().y));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			hba.setPosition(sf::Vector2f(hba.getPosition().x + 1, hba.getPosition().y));
		}
		rca.setPosition(hba.getPosition());
		hba.resolveCollision(&hbb);
		rcb.setPosition(hbb.getPosition());

		//////////


		window.clear();

		img.draw(&window);

		anim.update();
		anim.draw(&window);

		window.draw(rca);
		window.draw(rcb);

		window.display();
	}

	return 0;
}