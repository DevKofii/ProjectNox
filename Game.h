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
	bool wait = false, endGame;
	int gameRound = 1;
	sf::Vector2f num;

	//Game Objects
	//sf::RectangleShape enemy;
	Map map;
	Player player;
	Point point1, point2, point3, point4;

	//Private Functions
	void initVars();
	void initWindow();
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
	bool collisionPoint();

	int getGameRound();
	void setGameRound(int gameRound);


	void update();
	void render();
};

