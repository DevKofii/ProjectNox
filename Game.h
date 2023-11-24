#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Player.h"
#include "Map.h"

using namespace std;

/*
sf::Sprite sprite() {
	sf::Texture texture;
	if (!texture.loadFromFile("images\\shadow_L.png")) {
		exit(1);
	}
	texture.setSmooth(true);
	sf::Sprite Nox;
	Nox.setTexture(texture);
	return Nox;
}
*/

class Game {
private:
	//Variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event sfmlEvent;
	bool endGame;
	bool state = false;
	int lb = 10, ub_x = 1270, ub_y = 710;
	float randX = (rand() % (ub_x - lb + 1)) + lb;
	sf::Vector2f num;
	//sf::Vector2f randY = (rand() % (ub_y - lb + 1)) + lb;

	//Game Objects
	sf::RectangleShape enemy;
	Map map;
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

