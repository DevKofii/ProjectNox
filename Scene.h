#pragma once

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Scene
{
private:
	//Variables
	sf::Event sceneEvent;
	bool map[]

	//Game Objects
	sf::RectangleShape 
};

/*
#pragma once
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Player.h"

class Game {
private:
	//Variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event sfmlEvent;
	bool endGame;

	//Game Objects
	sf::RectangleShape enemy;    gtht4ggg
	Player player;

	//Private Functions
	void initVars();
	void initWindow();
	void initEnemies();
public:
	//Constructors
	Game();
	virtual ~Game();

	//Accessors
	const bool getWindowIsOpen() const;

	//Functions
	void pollEvents();
	void update();
	void render();
};


* 
*/