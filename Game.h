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
#include "Point.h"

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
	sf::Vector2f num;

	//Game Objects
	sf::RectangleShape enemy;
	Map map;
	Player player;
	Point point;

	//Private Functions
	void initVars();
	void initWindow();
	void initEnemies();
	void initPoint();

public:
	//Constructors
	Game();
	virtual ~Game();
	 
	//Accessors
	const bool getWindowIsOpen() const;

	//Functions
	void pollEvents();
	void collisionStates();
	void update();
	void render();
};

