#include "Map.h"
#include "Player.h"

void Map::initVariables()
{

}

void Map::initShape()
{
	this->shape.setFillColor(sf::Color::Black);
	this->shape.setSize(sf::Vector2f(1280.f, 720.f));
}

Map::Map()
{
	this->shape.setPosition(0.f, 0.f);

	this->initVariables();
	this->initShape();
	gridNum = 1;
}

Map::Map(int gridNum)
{
	this->shape.setPosition(0.f, 0.f);

	this->initVariables();
	this->initShape();
	this->gridNum = gridNum;
}

Map::~Map()
{
	//Window Bounds Collision
}

bool Map::getMapState() {
	return state;
}

void Map::setMapState(bool state) {
	this->state = state;
}

int Map::getGridNum()
{
	return gridNum;
}

void Map::setGridNum(int gridNum)
{
	this->gridNum = gridNum;
}


//ITT FUCKIN WOIRKED
void Map::updateMap(int gridNum)
{
	switch (gridNum)
	{
	case 1:
		this->shape.setFillColor(sf::Color::Black);
		break;
	case 2:
		this->shape.setFillColor(sf::Color(79, 79, 79, 255));
		break;
	case 3:
		this->shape.setFillColor(sf::Color::White);
		break;
	}
}


void Map::update(const sf::RenderTarget* target)
{
	this->updateMap(this->state);
}

void Map::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}