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

	void initVariables();
	void initShape();
	
public:
	Map(float x = 0.f, float y = 0.f);
	virtual ~Map();

	bool getMapState();
	void setMapState(bool state);
	void updateMap(bool state); //updateMap states
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

