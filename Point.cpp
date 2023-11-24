#include "Point.h"

void Point::initShape()
{
	this->shape.setFillColor(sf::Color::White);
	this->shape.setSize(sf::Vector2f(100.f, 100.f));
	this->shape.setScale(sf::Vector2f(0.1f, 0.1f));
}

Point::Point()
{
	this->shape.setPosition(-10, -10);
	srand(time(NULL));
	randGridNum = rand() % 9 + 1;
	this->initShape();
}

Point::~Point()
{
	delete this;
}

void Point::randomSpawn()
{
	srand(time(NULL));
	float x = rand() % 1080 + 100;
	float y = rand() % 620 + 50;
	this->shape.setPosition(x, y);
}

int Point::getGrid()
{
	return randGridNum;
}

void Point::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
