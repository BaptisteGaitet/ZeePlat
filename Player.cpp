#include "Player.h"

Player::Player() : Entity(sf::Vector2f(0, 0), sf::Vector2f(8, 8), "char.png", 4, 4)
{
	facingLeft = false;
	onGround = false;
	canJump = true;

	body.setPosition(sf::Vector2f(0,0));

	body.addHitbox(Hitbox(sf::FloatRect(0, 0, 4, 8), sf::Vector2f(2, 0), true, false, true));
	body.addHitbox(Hitbox(sf::FloatRect(0, 0, 8, 4), sf::Vector2f(0, 2), true, true, false));

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
	std::vector<Frame> idleRight = {
		Frame(8, 16),
		Frame(9, 16)
	};
	std::vector<Frame> idleLeft = {
		Frame(10, 16),
		Frame(11, 16)
	};
	std::vector<Frame> jumpRight = {
		Frame(12, 8)
	};
	std::vector<Frame> fallRight = {
		Frame(13, 8)
	};
	std::vector<Frame> jumpLeft = {
		Frame(15, 8)
	};
	std::vector<Frame> fallLeft = {
		Frame(14, 8)
	};
	animatedImage.addAnimation("runLeft", Animation(runLeft, true));
	animatedImage.addAnimation("runRight", Animation(runRight, true));
	animatedImage.addAnimation("idleLeft", Animation(idleLeft, true));
	animatedImage.addAnimation("idleRight", Animation(idleRight, true));
	animatedImage.addAnimation("fallRight", Animation(fallRight, true));
	animatedImage.addAnimation("fallLeft", Animation(fallLeft, true));
	animatedImage.addAnimation("jumpRight", Animation(jumpRight, true));
	animatedImage.addAnimation("jumpLeft", Animation(jumpLeft, true));
	animatedImage.play("idleLeft");
}

Player::Player(sf::Vector2f _position) : Entity(_position, sf::Vector2f(8, 8), "char.png", 4,4)
{
	facingLeft = false;
	onGround = false;
	canJump = true;

	body.setPosition(_position);

	body.addHitbox(Hitbox(sf::FloatRect(0, 0, 4, 8), sf::Vector2f(2,0), true, false, true));
	body.addHitbox(Hitbox(sf::FloatRect(0, 0, 8, 4), sf::Vector2f(0, 2), true, true, false));

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
		Frame(8, 16),
		Frame(9, 16)
	};
	std::vector<Frame> idleLeft = {
		Frame(10, 16),
		Frame(11, 16)
	};
	std::vector<Frame> jumpRight = {
		Frame(12, 8)
	};
	std::vector<Frame> fallRight = {
		Frame(13, 8)
	};
	std::vector<Frame> jumpLeft = {
		Frame(15, 8)
	};
	std::vector<Frame> fallLeft = {
		Frame(14, 8)
	};
	animatedImage.addAnimation("runLeft", Animation(runLeft, true));
	animatedImage.addAnimation("runRight", Animation(runRight, true));
	animatedImage.addAnimation("idleLeft", Animation(idleLeft, true));
	animatedImage.addAnimation("idleRight", Animation(idleRight, true));
	animatedImage.addAnimation("fallRight", Animation(fallRight, true));
	animatedImage.addAnimation("fallLeft", Animation(fallLeft, true));
	animatedImage.addAnimation("jumpRight", Animation(jumpRight, true));
	animatedImage.addAnimation("jumpLeft", Animation(jumpLeft, true));
	animatedImage.play("idleLeft");
}

void Player::update()
{
	sf::Vector2f acceleration;

	body.setVelocity(sf::Vector2f(body.getVelocity().x * 0.9, body.getVelocity().y));

	if (body.getHitboxes().at(0)->getContacts().bottom)
	{ 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
		{
			acceleration.y -= 2.0f;
			canJump = false;
		}
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		canJump = true;
	}

	//Gravity
		acceleration.y += 0.1f;
	if (!body.getHitboxes().at(0)->getContacts().bottom)
	{
	}
	else if (body.getVelocity().y > 0)
	{
		body.setVelocity(sf::Vector2f(body.getVelocity().x, 0));
	}	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		acceleration.x -= 0.1f;
		facingLeft = true;
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		acceleration.x += 0.1f;
		facingLeft = false;
	}

	if (body.getVelocity().x > 2)
	{
		body.setVelocity(sf::Vector2f(2, body.getVelocity().y));
	}
	if (body.getVelocity().x < -2)
	{
		body.setVelocity(sf::Vector2f(-2, body.getVelocity().y));
	}
	if (body.getVelocity().y > 4)
	{
		body.setVelocity(sf::Vector2f(body.getVelocity().x, 4));
	}
	if (body.getVelocity().y < -4)
	{
		body.setVelocity(sf::Vector2f(body.getVelocity().x, -4));
	}

	body.setAcceleration(acceleration);

	//Animations
	if (body.getHitboxes().at(0)->getContacts().bottom)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			animatedImage.play("runRight");
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			animatedImage.play("runLeft");
		}
		else
		{
			if (facingLeft)
				animatedImage.play("idleLeft");
			else
				animatedImage.play("idleRight");
		}
	}
	else
	{
		if (body.getVelocity().y < 0)
		{
			if (facingLeft)
				animatedImage.play("jumpLeft");
			else
				animatedImage.play("jumpRight");
		}
		else
		{
			if (facingLeft)
				animatedImage.play("fallLeft");
			else
				animatedImage.play("fallRight");
		}
	}

	updateEntity();
}

Player::~Player()
{
}
