#include "WindowManager.h"

WindowManager::WindowManager()
{
	switchFullscreen = false;
	zoom = 4;
	screenSize = sf::Vector2f(800, 600);

	view.setSize(screenSize);
}

WindowManager& WindowManager::getInstance()
{
	static WindowManager instance;

	return instance;
}

void WindowManager::update()
{
	center.x += (target.x - center.x) / FOLLOW_SPEED;
	center.y += (target.y - center.y) / FOLLOW_SPEED;

	view.setCenter(center);
	view.setSize(screenSize.x / zoom, screenSize.y / zoom);
}

void WindowManager::setScreenSize(sf::Vector2f _screensize)
{
	screenSize = _screensize;
}

void WindowManager::setCenter(sf::Vector2f _center)
{
	center = _center;
	target = _center;
	view.setCenter(_center);
}

void WindowManager::setTarget(sf::Vector2f _target)
{
	target = _target;
}

void WindowManager::increaseZoom()
{
	if (zoom < MAX_ZOOM)
		zoom++;
}

void WindowManager::decreaseZoom()
{
	if (zoom > MIN_ZOOM)
		zoom--;
}

sf::View WindowManager::getView()
{
	return view;
}

bool WindowManager::requestFullscreenSwitch()
{
	bool res = switchFullscreen;

	switchFullscreen = false;

	return res;
}

void WindowManager::setFullscreenRequest(bool _val)
{
	switchFullscreen = _val;
}

WindowManager::~WindowManager()
{
}
