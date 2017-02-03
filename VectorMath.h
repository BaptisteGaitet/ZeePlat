#ifndef VECTOR_MATH_H
#define VECTOR_MATH_H

#include <SFML/Graphics.hpp>

#define PI 3.141592

class VectorMath
{
public:
	static float dotProduct(sf::Vector2f a, sf::Vector2f b);
	static sf::Vector2f vectorFromTo(sf::Vector2f from, sf::Vector2f to);
	static sf::Vector2f normalize(sf::Vector2f vector);
	static float getNorm(sf::Vector2f vector);
	static sf::Vector2f perp(sf::Vector2f vector);
	static float angleBetweenVectors(sf::Vector2f a, sf::Vector2f b);
	static float degToRad(float deg);
	static float radToDeg(float rad);
	static float angleFromVector(sf::Vector2f vector);
	static sf::Vector2f rotateVector(sf::Vector2f vector, float amount);
};

#endif