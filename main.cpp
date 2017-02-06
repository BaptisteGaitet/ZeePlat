#include <SFML/Graphics.hpp>
#include "Image.h"
#include "Frame.h"
#include "Animation.h"
#include "AnimatedImage.h"
#include "Hitbox.h"
#include "Body.h"
#include "StateManager.h"
#include "State.h"
#include "GameState.h"
#include "TitleState.h"

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
			if (event.type == sf::Event::Closed)
				window.close();
		}

		stateMngr.update();

		window.clear();

		stateMngr.draw(&window);

		window.display();
	}

	return 0;
}