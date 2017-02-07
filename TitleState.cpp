#include "TitleState.h"


TitleState::TitleState() : State("title")
{
	selected = 0;
	pressed = false;

	std::vector<Frame> idle = {
		Frame(0, 1)
	};
	std::vector<Frame> selected = {
		Frame(1, 1)
	};

	start = AnimatedImage(sf::Vector2f(-12.5f, -10), sf::Vector2f(25, 10), "txtStart.png", 1, 2);
	start.addAnimation("idle", Animation(idle, false));
	start.addAnimation("selected", Animation(selected, false));
	start.play("selected");

	fullScreen = AnimatedImage(sf::Vector2f(-25, 0), sf::Vector2f(50, 10), "txtFullscreen.png", 1, 2);
	fullScreen.addAnimation("idle", Animation(idle, false));
	fullScreen.addAnimation("selected", Animation(selected, false));
	fullScreen.play("idle");

	exit = AnimatedImage(sf::Vector2f(-10, 10), sf::Vector2f(20, 10), "txtExit.png", 1, 2);
	exit.addAnimation("idle", Animation(idle, false));
	exit.addAnimation("selected", Animation(selected, false));
	exit.play("idle");
}

void TitleState::update()
{
	if (getNextStateId() != "")
	{
		setNextStateId("");
		selected = 0;
	}

	start.update();
	fullScreen.update();
	exit.update();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed)
	{
		selected--;
		pressed = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed)
	{
		selected++;
		pressed = true;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && pressed)
	{
		pressed = false;
	}

	if (selected < 0)
	{
		selected = 0;
	}
	else if (selected > 2)
	{
		selected = 2;
	}

	if (selected == 0)
	{
		start.play("selected");
		fullScreen.play("idle");
		exit.play("idle");
	}
	else if (selected == 1)
	{
		start.play("idle");
		fullScreen.play("selected");
		exit.play("idle");
	}
	else if (selected == 2)
	{
		start.play("idle");
		fullScreen.play("idle");
		exit.play("selected");
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && selected == 0)
	{
		setNextStateId("game");
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && selected == 2)
	{
		setExit(true);
	}
}

void TitleState::draw(sf::RenderWindow* window)
{
	start.draw(window);
	fullScreen.draw(window);
	exit.draw(window);
}

TitleState::~TitleState()
{
}
