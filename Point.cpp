#include "Point.h"

void Point::initShape()
{
	this->sprite.setScale(sf::Vector2f(0.7f, 0.7f));
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

void Point::initTex()
{
	if (!this->enemy.loadFromFile("images\\Enemy.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->enemy_dead.loadFromFile("images\\Enemy_Dead.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->priest.loadFromFile("images\\Priest.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	enemy.setSmooth(1);
	enemy_dead.setSmooth(1);
	priest.setSmooth(1);
}

Point::Point()
{
	this->sprite.setPosition(-10, -10);

	this->initTex();
	this->initShape();
}

void Point::randomSpawn()
{
	srand(time(NULL));
	this->setXCoord(this->x);
	this->setYCoord(this->y);
	this->sprite.setPosition(this->x, this->y);
}

void Point::randomGrid()
{
	srand(time(NULL));
	this->randGridNum = rand() % 9 + 1;
}

sf::FloatRect Point::collisionTest()
{
	return this->sprite.getGlobalBounds();
}

int Point::getGrid()
{
	return randGridNum;
}

void Point::deletePoint()
{
	this->sprite.setPosition(-10, -10);
}

void Point::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

void Point::updatePoint(int updatePoint)
{
	//Round Switch
	switch (updatePoint)
	{
	case 1:
		this->updateNum = 1;
		this->sprite.setTexture(this->enemy);
		break;
	case 2:
		this->updateNum = 2;
		this->sprite.setTexture(this->enemy_dead);
		this->sprite.setColor(sf::Color(255,255,255,0));
		break;
	case 3:
		break;
		this->updateNum = 3;
		this->sprite.setTexture(this->priest);
		this->sprite.setColor(sf::Color(255, 255, 255, 255));
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

float Point::getXCoord()
{
	return x;
}

float Point::getYCoord()
{
	return y;
}

void Point::setXCoord(float temp)
{
	temp = (rand() % (800 - 280 + 1)) + 280;
	this->x = temp;
}

void Point::setYCoord(float temp)
{
	temp = (rand() % (500 - 120 + 1)) + 120;
	this->y = temp;
}

void Point::setAlpha(int x)
{
	this->sprite.setColor(sf::Color(255, 255, 255, x));
}

void Point::setGrid(int grid)
{
	this->randGridNum = grid;
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

void Point::setSpawn(float tempX, float tempY)
{
	this->x = tempX;
	this->y = tempY;
	this->sprite.setPosition(tempX, tempY);
}
