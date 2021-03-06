#include "Player.h"

Player::Player() : Entity(sf::Vector2f(0, 0), sf::Vector2f(16, 16), "character.png", 8, 8)
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
		Frame(4, 8),
		Frame(5, 8),
		Frame(6, 8),
		Frame(7, 8)
	};
	std::vector<Frame> runLeft = {
		Frame(8, 8),
		Frame(9, 8),
		Frame(10, 8),
		Frame(11, 8),
		Frame(12, 8),
		Frame(13, 8),
		Frame(14, 8),
		Frame(15, 8)
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

Player::Player(sf::Vector2f _position) : Entity(_position, sf::Vector2f(16, 16), "character.png", 8,8)
{
	facingLeft = false;
	onGround = false;
	canJump = true;

	body.setPosition(_position);

	body.addHitbox(Hitbox(sf::FloatRect(0, 0, 4, 8), sf::Vector2f(6,8), true, false, true));
	body.addHitbox(Hitbox(sf::FloatRect(0, 0, 8, 4), sf::Vector2f(4,10), true, true, false));

	std::vector<Frame> runRight = {
		Frame(0, 6),
		Frame(1, 6),
		Frame(2, 6),
		Frame(3, 6),
		Frame(4, 6),
		Frame(5, 6),
		Frame(6, 6),
		Frame(7, 6)
	};
	std::vector<Frame> runLeft = {
		Frame(8,6),
		Frame(9, 6),
		Frame(10, 6),
		Frame(11, 6),
		Frame(12, 6),
		Frame(13, 6),
		Frame(14, 6),
		Frame(15, 6)
	};
	std::vector<Frame> idleRight= {
		Frame(16, 6),
		Frame(17, 6),
		Frame(18, 6),
		Frame(19, 6)
	};
	std::vector<Frame> idleLeft = {
		Frame(20, 6),
		Frame(21, 6),
		Frame(22, 6),
		Frame(23, 6)
	};
	std::vector<Frame> jumpRight = {
		Frame(24, 8),
		Frame(25, 8)
	};
	std::vector<Frame> fallRight = {
		Frame(26, 8),
		Frame(27, 8)
	};
	std::vector<Frame> jumpLeft = {
		Frame(28, 8),
		Frame(29, 8)
	};
	std::vector<Frame> fallLeft = {
		Frame(30, 8),
		Frame(31, 8)
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

void Player::update(ParticleManager* _partMngr)
{
	//_partMngr->addParticle(Particle(getCenter(), sf::Vector2f(-body.getVelocity().x*1, -body.getVelocity().y*1), 0.2f, 0.9f, 20, sf::Color(100, 200, 100)));

	sf::Vector2f acceleration;

	body.setVelocity(sf::Vector2f(body.getVelocity().x * 0.9, body.getVelocity().y));

	if (body.getHitboxes().at(0)->getContacts().bottom)
	{ 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
		{
			acceleration.y -= 2.0f;
			canJump = false;
			for (int i = 0; i < 10; i++)
			{
				sf::Vector2f partVel = sf::Vector2f();
				partVel.x = -1.0f + ((float)(rand() % 20 + 1) / 10);
				partVel.y = -((float)(rand() % 20 + 1) / 10);
				_partMngr->addParticle(Particle(sf::Vector2f(getCenter().x, getCenter().y + 8), partVel, 0.01f, 0.6f, 20 + (rand() % 10 + 1), sf::Color(82, 38, 107)));
			}
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
		onGround = false;
	}
	else if (body.getVelocity().y > 0)
	{
		if (!onGround)
		{
			for (int i = 0; i < 10; i++)
			{
				sf::Vector2f partVel = sf::Vector2f();
				partVel.x = -1.0f + ((float)(rand() %20 + 1) / 10);
				partVel.y = -((float)(rand() % 10 + 1) / 10);
				_partMngr->addParticle(Particle(sf::Vector2f(getCenter().x, getCenter().y + 8), partVel, 0.04f, 0.8f, 20 + (rand() % 10 + 1), sf::Color(82, 38, 107)));
			}
		}
		onGround = true;
		body.setVelocity(sf::Vector2f(body.getVelocity().x, 0));
	}	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		acceleration.x -= 0.1f;
		facingLeft = true;
		if (onGround && (rand() % 10 + 1) > 5)
		{
			sf::Vector2f partVel = sf::Vector2f();
			partVel.x = ((float)(rand() % 10 + 1) / 10);
			partVel.y = -((float)(rand() % 20 + 1) / 10);
			_partMngr->addParticle(Particle(sf::Vector2f(getCenter().x, getCenter().y + 8), partVel, 0.01f, 0.6f, 10, sf::Color(82, 38, 107)));
		}
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		acceleration.x += 0.1f;
		facingLeft = false;
		if (onGround && (rand() % 10 + 1) > 5)
		{
			sf::Vector2f partVel = sf::Vector2f();
			partVel.x = -((float)(rand() % 10 + 1) / 10);
			partVel.y = -((float)(rand() % 20 + 1) / 10);
			_partMngr->addParticle(Particle(sf::Vector2f(getCenter().x, getCenter().y + 8), partVel, 0.01f, 0.6f, 10, sf::Color(82, 38, 107)));
		}
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
