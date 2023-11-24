#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 10.f;
}

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::White);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
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

void Player::setcollisionState_L(bool collidedLeft)
{
	this->collidedLeft = collidedLeft;
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
	}

	//Top
	if (this->shape.getGlobalBounds().top <= 0.f)
	{
		this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
	}

	//Bottom
	if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
	{
		this->shape.setPosition(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height);
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