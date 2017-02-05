#include "Player.h"

Player::Player(sf::Vector2f _position) : Entity(_position, sf::Vector2f(32, 32), "char.png", 4,4)
{
	facingLeft = false;
	onGround = false;
	canJump = true;

	body.setPosition(_position);

	body.addHitbox(Hitbox(sf::FloatRect(0, 0, 16, 32), sf::Vector2f(8,0), true, false, true));
	body.addHitbox(Hitbox(sf::FloatRect(0, 0, 32, 16), sf::Vector2f(0, 8), true, true, false));

	std::vector<Frame> runRight = {
		Frame(0, 8),
		Frame(1, 8),
		Frame(2, 8),
		Frame(3, 8),
	};
	std::vector<Frame> runLeft = {
		Frame(4, 8),
		Frame(5, 8),
		Frame(6, 8),
		Frame(7, 8),
	};
	std::vector<Frame> idleRight= {
		Frame(8, 8),
		Frame(9, 8)
	};
	std::vector<Frame> idleLeft = {
		Frame(10, 8),
		Frame(11, 8)
	};
	animatedImage.addAnimation("runLeft", Animation(runLeft, true));
	animatedImage.addAnimation("runRight", Animation(runRight, true));
	animatedImage.addAnimation("idleLeft", Animation(idleLeft, true));
	animatedImage.addAnimation("idleRight", Animation(idleRight, true));
	animatedImage.play("idleLeft");
}

void Player::update()
{
	sf::Vector2f acceleration;

	body.setVelocity(sf::Vector2f(body.getVelocity().x * 0.8, body.getVelocity().y));

	if (body.getHitboxes().at(0)->getContacts().bottom)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
	{
		acceleration.y -= 20.0f;
		canJump = false;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		canJump = true;
	}

	//Gravity
	if (!body.getHitboxes().at(0)->getContacts().bottom)
		acceleration.y += 0.8f;
	else if (body.getVelocity().y > 0)
		body.setVelocity(sf::Vector2f(body.getVelocity().x, 0));
		

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		animatedImage.play("runLeft");
		acceleration.x -= 1.0f;
		facingLeft = true;
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		animatedImage.play("runRight");
		acceleration.x += 1.0f;
		facingLeft = false;
	}
	else
	{
		if (facingLeft)
			animatedImage.play("idleLeft");
		else
			animatedImage.play("idleRight");
	}

	if (body.getVelocity().x > 4)
	{
		body.setVelocity(sf::Vector2f(4, body.getVelocity().y));
	}
	if (body.getVelocity().x < -4)
	{
		body.setVelocity(sf::Vector2f(-4, body.getVelocity().y));
	}
	if (body.getVelocity().y > 8)
	{
		body.setVelocity(sf::Vector2f(body.getVelocity().x, 8));
	}
	if (body.getVelocity().y < -8)
	{
		body.setVelocity(sf::Vector2f(body.getVelocity().x, -8));
	}

	body.setAcceleration(acceleration);

	updateEntity();
}

Player::~Player()
{
}
