#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "State.h"
#include "GameState.h"
#include "TitleState.h"
#include "WindowManager.h"

int main()
{
	StateManager stateMngr = StateManager();
	State* gameState = new GameState();
	State* titleState = new TitleState();

	stateMngr.addState(gameState);
	stateMngr.addState(titleState);
	stateMngr.setCurrentStateId("game");

	sf::RenderWindow window(sf::VideoMode(800, 600), "ZeePlat");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Resized)
			{
				WindowManager::getInstance().setScreenSize(sf::Vector2f(event.size.width, event.size.height));
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
		{
			WindowManager::getInstance().increaseZoom();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
		{
			WindowManager::getInstance().decreaseZoom();
		}

		stateMngr.update();

		window.setView(WindowManager::getInstance().getView());

		WindowManager::getInstance().update();

		window.clear();

		stateMngr.draw(&window);

		window.display();
	}

	return 0;
}