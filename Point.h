#pragma once
#include <iostream>
#include <random>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Map.h"

using namespace std;

class Point : public Map
{
private:
	sf::RectangleShape shape;
	int randGridNum;
	void initShape();
public:

	Point();
	virtual ~Point();
	void randomSpawn();

	int getGrid();
	void render(sf::RenderTarget* target);
};

