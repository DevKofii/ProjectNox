#include "Map.h"

void Map::initTex()
{
	if (!this->grid1.loadFromFile("images\\Grid\\1.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->grid2.loadFromFile("images\\Grid\\2.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->grid3.loadFromFile("images\\Grid\\3.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->grid4.loadFromFile("images\\Grid\\4.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->grid5.loadFromFile("images\\Grid5.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->grid6.loadFromFile("images\\Grid\\6.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->grid7.loadFromFile("images\\Grid\\7.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->grid8.loadFromFile("images\\Grid\\8.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->grid9.loadFromFile("images\\Grid\\9.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}

	if (!this->fin1.loadFromFile("images\\Grid\\fin1.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->fin2.loadFromFile("images\\Grid\\fin2.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->fin3.loadFromFile("images\\Grid\\fin3.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->fin4.loadFromFile("images\\Grid\\fin4.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->fin6.loadFromFile("images\\Grid\\fin6.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->fin7.loadFromFile("images\\Grid\\fin7.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->fin8.loadFromFile("images\\Grid\\fin8.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->fin9.loadFromFile("images\\Grid\\fin9.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}


	grid1.setSmooth(1);
	grid2.setSmooth(1);
	grid3.setSmooth(1);
	grid4.setSmooth(1);
	grid5.setSmooth(1);
	grid6.setSmooth(1);
	grid7.setSmooth(1);
	grid8.setSmooth(1);
	grid9.setSmooth(1);

	fin1.setSmooth(1);
	fin2.setSmooth(1);
	fin3.setSmooth(1);
	fin4.setSmooth(1);
	fin6.setSmooth(1);
	fin7.setSmooth(1);
	fin8.setSmooth(1);
	fin9.setSmooth(1);
}

void Map::initSprite()
{
	this->sprite.setTexture(this->grid1);
}

void Map::initShape()
{
	//this->shape.setFillColor(sf::Color::Black);
	//this->shape.setSize(sf::Vector2f(1280.f, 720.f));
}

Map::Map()
{
	this->shape.setPosition(0.f, 0.f);

	this->initTex();
	this->initSprite();
	//this->initShape();
	gridNum = 1;
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

void Map::setGridMap()
{
	switch (this->gridNum)
	{
	case 1:
		this->sprite.setTexture(this->grid1);
		break;
	case 2:
		this->sprite.setTexture(this->grid2);
		break;
	case 3:
		this->sprite.setTexture(this->grid3);
		break;
	case 4:
		this->sprite.setTexture(this->grid4);
		break;
	case 5:
		this->sprite.setTexture(this->grid5);
		break;
	case 6:
		this->sprite.setTexture(this->grid6);
		break;
	case 7:
		this->sprite.setTexture(this->grid7);
		break;
	case 8:
		this->sprite.setTexture(this->grid8);
		break;
	case 9:
		this->sprite.setTexture(this->grid9);
		break;
	case 11:
		this->sprite.setTexture(this->fin1);
		break;
	case 12:
		this->sprite.setTexture(this->fin2);
		break;
	case 13:
		this->sprite.setTexture(this->fin3);
		break;
	case 14:
		this->sprite.setTexture(this->fin4);
		break;
	case 16:
		this->sprite.setTexture(this->fin6);
		break;
	case 17:
		this->sprite.setTexture(this->fin7);
		break;
	case 18:
		this->sprite.setTexture(this->fin8);
		break;
	case 19:
		this->sprite.setTexture(this->fin9);
		break;
	}
}

void Map::updateMap(int gridNum)
{
	switch (gridNum)
	{
	case 1:
		//this->shape.setFillColor(sf::Color::Black);
		break;
	case 2:
		//this->shape.setFillColor(sf::Color::Black);
		break;
	case 3:
		//this->shape.setFillColor(sf::Color::Black);
		break;
	}
}


void Map::update(const sf::RenderTarget* target)
{
	this->updateMap(this->state);
	this->setGridMap();
}

void Map::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}