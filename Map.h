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
	sf::Texture grid1, grid2, grid3, grid4, grid5, grid6, grid7, grid8, grid9;
	sf::Sprite sprite;
	sf::RectangleShape shape;
	bool state;
	int gridNum;

	void initTex();
	void initSprite();
	void initShape();
	
public:
	Map();
	virtual ~Map();

	bool getMapState();
	void setMapState(bool state);

	int getGridNum();
	void setGridNum(int gridNum);

	void setGridMap();

	void updateMap(int gridNum); //updateMap states
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

