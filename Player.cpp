#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 10.f;
}

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::White);
	this->shape.setSize(sf::Vector2f(100.f, 100.f));
	this->shape.setScale(sf::Vector2f(0.5f, 0.5f));
}

Player::Player(float x, float y)
{
	this->shape.setPosition(x, y);

	this->initVariables();
	this->initShape();
}

Player::~Player()
{
	//Window Bounds Collision

}

bool Player::getcollisionState_L()
{
	return collidedLeft;
}

bool Player::getcollisionState_R()
{
	return collidedRight;
}

bool Player::getcollisionState_T()
{
	return collidedTop;
}

bool Player::getcollisionState_D()
{
	return collidedDown;
}

void Player::setcollisionState_L(bool collidedLeft)
{
	this->collidedLeft = collidedLeft;
}

void Player::setcollisionState_R(bool collidedRight)
{
	this->collidedRight = collidedRight;
}

void Player::setcollisionState_T(bool collidedTop)
{
	this->collidedTop = collidedTop;
}

void Player::setcollisionState_D(bool collidedDown)
{
	this->collidedDown = collidedDown;
}

void Player::teleport_left(bool collidedLeft)
{
	if (collidedLeft = true)
	{
		this->shape.setPosition(1280.f - this->shape.getGlobalBounds().width, this->shape.getPosition().y);
	}
}

void Player::teleport_right(bool collidedRight)
{
	if (collidedRight = true)
	{
		this->shape.setPosition(0.f, this->shape.getPosition().y);
	}
}

void Player::teleport_top(bool collidedTop)
{
	if (collidedTop = true)
	{
		this->shape.setPosition(this->shape.getPosition().x, 720.f - this->shape.getGlobalBounds().height);
	}
}

void Player::teleport_down(bool collidedDown)
{
	if (collidedDown = true)
	{
		this->shape.setPosition(this->shape.getPosition().x, 0.f);
	}
}

void Player::updateInput()
{
	//Keyboard Input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // Move Left | A
	{
		this->shape.move(-this->movementSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // Move Right | D
	{
		this->shape.move(this->movementSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) // Move Up | W
	{
		this->shape.move(0.f, -this->movementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // Move Down | S
	{
		this->shape.move(0.f, this->movementSpeed);
	}
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{
	//sf::Vector2f this->shape.getGlobalBounds() = this->shape.getPosition();
	//Test
	//Left
	if (this->shape.getGlobalBounds().left <= 0.f)
	{
		this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);
		//printf("Test\n");
		setcollisionState_L(true);
		//Call updateMap to switch to different Map
	}

	//Right
	if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x)
	{
		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width,this->shape.getGlobalBounds().top);
		setcollisionState_R(true);
	}

	//Top
	if (this->shape.getGlobalBounds().top <= 0.f)
	{
		setcollisionState_T(true);
		this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
	}

	//Bottom
	if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
	{
		this->shape.setPosition(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height);
		setcollisionState_D(true);
	}
}

void Player::update(const sf::RenderTarget* target)
{
	this->updateInput();
	this->updateWindowBoundsCollision(target);
}

void Player::render(sf::RenderTarget * target)
{
	target->draw(this->shape);
}