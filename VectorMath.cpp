#include "VectorMath.h"

float VectorMath::dotProduct(sf::Vector2f a, sf::Vector2f b)
{
	float res = 0;

	res = (a.x * b.x) + (a.y * b.y);

	return res;
}

sf::Vector2f VectorMath::vectorFromTo(sf::Vector2f from, sf::Vector2f to)
{
	sf::Vector2f res;

	res.x = to.x - from.x;
	res.y = to.y - from.y;

	return res;
}

sf::Vector2f VectorMath::normalize(sf::Vector2f vector)
{
	sf::Vector2f res = vector;
	float norm = getNorm(vector);
	
	res.x = vector.x / norm;
	res.y = vector.y / norm;

	return res;
}

float VectorMath::getNorm(sf::Vector2f vector)
{
	float res;

	res = sqrt(pow(vector.x, 2) + pow(vector.y, 2));

	return res;
}

sf::Vector2f VectorMath::perp(sf::Vector2f vector)
{
	sf::Vector2f res = sf::Vector2f(0,0);

	res.x = -vector.y;
	res.y = vector.x;

	return res;
}

float VectorMath::angleBetweenVectors(sf::Vector2f _a, sf::Vector2f _b)
{
	float res = 0;

	sf::Vector2f normalizedA = normalize(_a);
	sf::Vector2f normalizedB = normalize(_b);
	res = atan2(normalizedB.y, normalizedB.x) - atan2(normalizedA.y, normalizedA.x);

	return res;
}

float VectorMath::degToRad(float deg)
{
	float res = 0;

	res = deg * PI / 180;

	return res;
}

float VectorMath::radToDeg(float rad)
{
	float res = 0;

	res = rad * 180 / PI;

	return res;
}

float VectorMath::angleFromVector(sf::Vector2f vector)
{
	float res = 0;

	sf::Vector2f normalized = normalize(vector);
	res = radToDeg(atan2(normalized.y, normalized.x));

	return res;
}

sf::Vector2f VectorMath::rotateVector(sf::Vector2f vector, float amount)
{
	sf::Vector2f res = sf::Vector2f(0,0);

	float ca = cos(degToRad(amount));
	float sa = sin(degToRad(amount));
	res = sf::Vector2f(ca*vector.x - sa*vector.y, sa*vector.x + ca*vector.y);

	return res;
}