#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Player.h"

class Map
{
private:
	sf::RectangleShape shape;
	bool state;
	int gridNum;

	void initVariables();
	void initShape();
	
public:
	Map();
	Map(int gridNum);
	//Map(float x = 0.f, float y = 0.f);
	//Map(float x = 0.f, float y = 0.f, int gridNum = 1);
	virtual ~Map();

	bool getMapState();
	void setMapState(bool state);

	int getGridNum();
	void setGridNum(int gridNum);

	void updateMap(int gridNum); //updateMap states
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

