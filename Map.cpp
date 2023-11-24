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

Map::Map(float x, float y)
{
	this->shape.setPosition(x, y);

	this->initVariables();
	this->initShape();
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


//ITT FUCKIN WOIRKED
void Map::updateMap(bool state)
{
	if (state == true)
	{
		this->shape.setFillColor(sf::Color::Red);
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