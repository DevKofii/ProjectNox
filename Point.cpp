#include "Point.h"

void Point::initShape()
{
	this->pointShape.setFillColor(sf::Color::White);
	this->pointShape.setSize(sf::Vector2f(100.f, 100.f));
	this->pointShape.setScale(sf::Vector2f(0.1f, 0.1f));
}

void Point::initVariables()
{
	this->updateNum = 1;
	this->lock1 = false;
	this->lock2 = false;
	this->lock3 = false;
	this->lock4 = false;
	this->lock5 = false;
	this->lock6 = false;
	this->lock7 = false;
	this->lock8 = false;
	this->lock9 = false;
}

Point::Point()
{
	this->pointShape.setPosition(-10, -10);
	this->initShape();
}

Point::~Point()
{
}

void Point::randomSpawn()
{
	srand(time(NULL));
	float x = rand() % 1080 + 200;
	float y = rand() % 620 + 100;
	this->pointShape.setPosition(x, y);
}

void Point::randomGrid()
{
	srand(time(NULL));
	this->randGridNum = rand() % 9 + 1;
}

sf::FloatRect Point::collisionTest()
{
	return this->pointShape.getGlobalBounds();
}

int Point::getGrid()
{
	return randGridNum;
}

void Point::deletePoint()
{
	//this->pointShape.setFillColor(sf::Color::Transparent);
	this->pointShape.setPosition(-10, -10);
}

void Point::render(sf::RenderTarget* target)
{
	target->draw(this->pointShape);
}

void Point::updatePoint(int updatePoint)
{
	//Round Switch
	switch (updatePoint)
	{
	case 1:
		this->pointShape.setFillColor(sf::Color::White);
		break;
	case 2:
		this->pointShape.setFillColor(sf::Color::Black);
		break;
	case 3:
		this->pointShape.setFillColor(sf::Color::Black); //Color(R,G,B,Alpha);
		break;
	}
}

bool Point::getLockState(int gridNum)
{
	switch (gridNum)
	{
	case 1:
		return this->lock1;
		break;
	case 2:
		return this->lock2;
		break;
	case 3:
		return this->lock3;
		break;
	case 4:
		return this->lock4;
		break;
	case 5:
		return this->lock5;
		break;
	case 6:
		return this->lock6;
		break;
	case 7:
		return this->lock7;
		break;
	case 8:
		return this->lock8;
		break;
	case 9:
		return this->lock9;
		break;
	}
}

void Point::setLockGridState(int gridNum)
{
	switch (gridNum)
	{
	case 1:
		this->lock1 = true;
		break;
	case 2:
		this->lock2 = true;
		break;
	case 3:
		this->lock3 = true;
		break;
	case 4:
		this->lock4 = true;
		break;
	case 5:
		this->lock5 = true;
		break;
	case 6:
		this->lock6 = true;
		break;
	case 7:
		this->lock7 = true;
		break;
	case 8:
		this->lock8 = true;
		break;
	case 9:
		this->lock9 = true;
		break;
	}
}