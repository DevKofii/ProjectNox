#include "Player.h"

void Player::initTex()
{
	if (!this->tex1.loadFromFile("images\\Stage1.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->tex2_R.loadFromFile("images\\Stage2_R.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->tex3_R.loadFromFile("images\\Stage3_R.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->tex4_R.loadFromFile("images\\Stage4_R.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->tex5_R.loadFromFile("images\\Stage5_R.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->fin_R.loadFromFile("images\\Final_R.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->tex2_L.loadFromFile("images\\Stage2_L.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->tex3_L.loadFromFile("images\\Stage3_L.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->tex4_L.loadFromFile("images\\Stage4_L.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->tex5_L.loadFromFile("images\\Stage5_L.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->fin_L.loadFromFile("images\\Final_L.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->ded.loadFromFile("images\\Player_Dead.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	tex1.setSmooth(1);
	tex2_R.setSmooth(1);
	tex3_R.setSmooth(1);
	tex4_R.setSmooth(1);
	tex5_R.setSmooth(1);
	fin_R.setSmooth(1);

	tex2_L.setSmooth(1);
	tex3_L.setSmooth(1);
	tex4_L.setSmooth(1);
	tex5_L.setSmooth(1);
	fin_L.setSmooth(1);

	ded.setSmooth(1);
}

void Player::initSprite()
{
	this->sprite.setTexture(this->tex1);
}

void Player::initVariables()
{
	this->movementSpeed = 10.f;
	this->updateNum = 1;
}

void Player::initShape()
{
	this->sprite.setScale(sf::Vector2f(0.8f, 0.8f));
}

Player::Player(float x, float y)
{
	this->sprite.setPosition(x, y);

	this->initTex();
	this->initSprite();
	this->initVariables();
	this->initShape();
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

bool Player::getcollisionPoint()
{
	return collidePoint;
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

void Player::setcollisionPoint(bool collidePoint)
{
	this->collidePoint = collidePoint;
}

void Player::teleport_left(bool collidedLeft)
{
	if (collidedLeft = true)
	{
		this->sprite.setPosition(1280.f - this->sprite.getGlobalBounds().width, this->sprite.getPosition().y);
	}
}

void Player::teleport_right(bool collidedRight)
{
	if (collidedRight = true)
	{
		this->sprite.setPosition(0.f, this->sprite.getPosition().y);
	}
}

void Player::teleport_top(bool collidedTop)
{
	if (collidedTop = true)
	{
		this->sprite.setPosition(this->sprite.getPosition().x, 720.f - this->sprite.getGlobalBounds().height);
	}
}

void Player::teleport_down(bool collidedDown)
{
	if (collidedDown = true)
	{
		this->sprite.setPosition(this->sprite.getPosition().x, 0.f);
	}
}

sf::FloatRect Player::collisionTest()
{
	return this->sprite.getGlobalBounds();
}

void Player::updatePlayer(int updateNum)
{
	switch (updateNum)
	{
	case 1:
		this->updateNum = 1;
		break;
	case 2:
		this->sprite.setTextureRect(sf::IntRect(0, 0, 35, 102));
		this->updateNum = 2;
		break;
	case 3:
		this->updateNum = 3;
		break;
	case 4:
		this->sprite.setTextureRect(sf::IntRect(0, 0, 48, 122));
		this->updateNum = 4;
		break;
	case 5:
		this->updateNum = 5;
		break;
	case 6:
		this->sprite.setTextureRect(sf::IntRect(0, 0, 62, 143));
		this->updateNum = 6;
		break;
	case 7:
		this->updateNum = 7;
		break;
	case 8:
		this->sprite.setTextureRect(sf::IntRect(0, 0, 68, 143));
		this->updateNum = 8;
		break;
	case 9:
		this->updateNum = 9;
		break;
	case 10:
		this->sprite.setTextureRect(sf::IntRect(0, 0, 82, 143));
		this->updateNum = 10;
		break;
	case -1:
		this->sprite.setTexture(this->ded);
		this->sprite.setTextureRect(sf::IntRect(0, 0, 156, 75));
		this->updateNum = -1;
		break;
	}
}

int Player::getUpdateNum()
{
	return updateNum;
}

void Player::setAlpha(int num)
{
	this->sprite.setColor(sf::Color(255, 255, 255, num));
}

void Player::updateInput()
{
	//Keyboard Input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // Move Left | A
	{
		this->sprite.move(-this->movementSpeed, 0.f);
		if (this->getUpdateNum() == 1) this->sprite.setTexture(this->tex1);
		if (this->getUpdateNum() == 2 || this->getUpdateNum() == 3) this->sprite.setTexture(this->tex2_L);
		if (this->getUpdateNum() == 4 || this->getUpdateNum() == 5) this->sprite.setTexture(this->tex3_L);
		if (this->getUpdateNum() == 6 || this->getUpdateNum() == 7) this->sprite.setTexture(this->tex4_L);
		if (this->getUpdateNum() == 8 || this->getUpdateNum() == 9) this->sprite.setTexture(this->tex5_L);
		if (this->getUpdateNum() == 10) this->sprite.setTexture(this->fin_L);
		if (this->getUpdateNum() == -1) this->sprite.setTexture(this->ded);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // Move Right | D
	{
		this->sprite.move(this->movementSpeed, 0.f);
		if (this->getUpdateNum() == 1) this->sprite.setTexture(this->tex1);
		if (this->getUpdateNum() == 2 || this->getUpdateNum() == 3) this->sprite.setTexture(this->tex2_R);
		if (this->getUpdateNum() == 4 || this->getUpdateNum() == 5) this->sprite.setTexture(this->tex3_R);
		if (this->getUpdateNum() == 6 || this->getUpdateNum() == 7) this->sprite.setTexture(this->tex4_R);
		if (this->getUpdateNum() == 8 || this->getUpdateNum() == 9) this->sprite.setTexture(this->tex5_R);
		if (this->getUpdateNum() == 10) this->sprite.setTexture(this->fin_R);
		if (this->getUpdateNum() == -1) this->sprite.setTexture(this->ded);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) // Move Up | W
	{
		this->sprite.move(0.f, -this->movementSpeed);
		if (this->getUpdateNum() == -1) this->sprite.setTexture(this->ded);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // Move Down | S
	{
		this->sprite.move(0.f, this->movementSpeed);
		if (this->getUpdateNum() == -1) this->sprite.setTexture(this->ded);
	}
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{

	//Left
	if (this->sprite.getGlobalBounds().left <= 0.f)
	{
		this->sprite.setPosition(0.f, this->sprite.getGlobalBounds().top);
		setcollisionState_L(true);
	}

	//Right
	if (this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width >= target->getSize().x)
	{
		this->sprite.setPosition(target->getSize().x - this->sprite.getGlobalBounds().width,this->sprite.getGlobalBounds().top);
		setcollisionState_R(true);
	}

	//Top
	if (this->sprite.getGlobalBounds().top <= 0.f)
	{
		setcollisionState_T(true);
		this->sprite.setPosition(this->sprite.getGlobalBounds().left, 0.f);
	}

	//Bottom
	if (this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height >= target->getSize().y)
	{
		this->sprite.setPosition(this->sprite.getGlobalBounds().left, target->getSize().y - this->sprite.getGlobalBounds().height);
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
	target->draw(this->sprite);
}