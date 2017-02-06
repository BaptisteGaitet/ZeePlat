#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <SFML\Graphics.hpp>


class WindowManager
{
#define FOLLOW_SPEED 8.0f;
private:
	WindowManager();
	WindowManager(WindowManager const&);
	void operator=(WindowManager const&);

	sf::View view;
	sf::Vector2f screenSize;
	sf::Vector2f center;
	sf::Vector2f target;
	int zoom;

public:
	static WindowManager& getInstance();

	void update();
	void setScreenSize(sf::Vector2f _center);
	void setCenter(sf::Vector2f _center);
	void setTarget(sf::Vector2f _target);
	void increaseZoom();
	void decreaseZoom();
	sf::View getView();

	~WindowManager();
};

#endif