#include "TitleState.h"


TitleState::TitleState() : State("title")
{
	selected = 0;
	directionPressed = false;
	selectPressed = false;
	fullOn = false;

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

	on = AnimatedImage(sf::Vector2f(30, 0), sf::Vector2f(10, 10), "txtOn.png", 1, 2);
	on.addAnimation("idle", Animation(idle, false));
	on.addAnimation("selected", Animation(selected, false));
	on.play("idle");

	off = AnimatedImage(sf::Vector2f(30, 0), sf::Vector2f(15, 10), "txtOff.png", 1, 2);
	off.addAnimation("idle", Animation(idle, false));
	off.addAnimation("selected", Animation(selected, false));
	off.play("idle");

	zoom = AnimatedImage(sf::Vector2f(-20, 10), sf::Vector2f(40, 10), "txtZoom.png", 1, 2);
	zoom.addAnimation("idle", Animation(idle, false));
	zoom.addAnimation("selected", Animation(selected, false));
	zoom.play("idle");

	exit = AnimatedImage(sf::Vector2f(-10, 20), sf::Vector2f(20, 10), "txtExit.png", 1, 2);
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
	on.update();
	off.update();
	zoom.update();
	exit.update();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !directionPressed)
	{
		selected--;
		directionPressed = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !directionPressed)
	{
		selected++;
		directionPressed = true;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && directionPressed)
	{
		directionPressed = false;
	}

	if (selected < 0)
	{
		selected = 0;
	}
	else if (selected > 3)
	{
		selected = 3;
	}

	if (selected == 0)
	{
		start.play("selected");
		fullScreen.play("idle");
		on.play("idle");
		off.play("idle");
		zoom.play("idle");
		exit.play("idle");
	}
	else if (selected == 1)
	{
		start.play("idle");
		fullScreen.play("selected");
		on.play("selected");
		off.play("selected");
		zoom.play("idle");
		exit.play("idle");
	}
	else if (selected == 2)
	{
		start.play("idle");
		fullScreen.play("idle");
		on.play("idle");
		off.play("idle");
		zoom.play("selected");
		exit.play("idle");
	}
	else if (selected == 3)
	{
		start.play("idle");
		fullScreen.play("idle");
		on.play("idle");
		off.play("idle");
		zoom.play("idle");
		exit.play("selected");
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && selected == 0)
	{
		setNextStateId("game");
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !selectPressed && selected == 1)
	{
		WindowManager::getInstance().setFullscreenRequest(true);
		selectPressed = true;
		fullOn = !fullOn;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !directionPressed && selected == 2)
	{
		WindowManager::getInstance().increaseZoom();
		directionPressed = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !directionPressed && selected == 2)
	{
		WindowManager::getInstance().decreaseZoom();
		directionPressed = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && selected == 3)
	{
		setExit(true);
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && selectPressed)
	{
		selectPressed = false;
	}
}

void TitleState::draw(sf::RenderWindow* window)
{
	start.draw(window);
	fullScreen.draw(window);
	if (fullOn)
	{
		on.draw(window);
	}
	else
	{
		off.draw(window);
	}
	zoom.draw(window);
	exit.draw(window);
}

TitleState::~TitleState()
{
}
