#pragma once
#include <iostream>
#include <random>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;

class Point
{
private:
	sf::Texture enemy,enemy_dead;
	sf::Sprite sprite;
	//sf::RectangleShape pointShape;
	float x= 0.f, y = 0.f;
	int randGridNum;
	int updateNum;
	bool lock1 = false, lock2 = false, lock3 = false, lock4 = false, lock5 = false, lock6 = false, lock7 = false, lock8 = false, lock9 = false;

	void initTex();
	void initSprite();
	void initVariables();
	void initShape();
public:

	Point();
	virtual ~Point();

	void randomSpawn();
	void randomGrid();

	float getXCoord();
	float getYCoord();
	void setXCoord(float temp);
	void setYCoord(float temp);
	void setSpawn(float x, float y);

	void setAlpha(int temp);

	sf::FloatRect collisionTest();
	int getGrid();
	void setGrid(int grid);

	void deletePoint();
	void updatePoint(int updatePoint);
	void setLockGridState(int gridNum);
	bool getLockState(int gridNum);

	void render(sf::RenderTarget* target);
};

