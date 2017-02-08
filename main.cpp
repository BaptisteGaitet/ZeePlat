#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "State.h"
#include "GameState.h"
#include "TitleState.h"
#include "WindowManager.h"

int main()
{
	bool fullscreen = false;
	std::vector<sf::VideoMode> videoModes = sf::VideoMode::getFullscreenModes();

	StateManager stateMngr = StateManager();
	State* gameState = new GameState();
	State* titleState = new TitleState();

	stateMngr.addState(gameState);
	stateMngr.addState(titleState);
	stateMngr.setCurrentStateId("title");

	sf::RenderWindow window(sf::VideoMode(800, 600), "ZeePlat");
	window.setMouseCursorVisible(false);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Resized)
			{
				WindowManager::getInstance().setScreenSize(sf::Vector2f(event.size.width, event.size.height));
			}
			if (event.type == sf::Event::Closed || stateMngr.getExit())
				window.close();
		}

		if (WindowManager::getInstance().requestFullscreenSwitch())
		{
			if (fullscreen)
			{
				WindowManager::getInstance().setScreenSize(sf::Vector2f(800, 600));
				window.create(sf::VideoMode(800, 600), "ZeePlat");
				window.setMouseCursorVisible(false);
				window.setFramerateLimit(60);
				window.setVerticalSyncEnabled(true);
				fullscreen = false;
			}
			else
			{
				WindowManager::getInstance().setScreenSize(sf::Vector2f(videoModes.at(0).width, videoModes.at(0).height));
				window.create(videoModes.at(0), "ZeePlat", sf::Style::Fullscreen);
				window.setMouseCursorVisible(false);
				window.setFramerateLimit(60);
				window.setVerticalSyncEnabled(true);
				fullscreen = true;
			}
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