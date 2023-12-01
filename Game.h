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

class Game {
private:
	//Variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode; //videoMode : VideoMode
	sf::Event sfmlEvent;
	sf::Texture uno, dos, tres, findhim;
	sf::Sprite sprite;

	sf::SoundBuffer buffer;
	sf::Sound stab;
	sf::Music music;

	bool endGame, toggle1 = false, toggle2 = false, toggle3 = false, toggle4 = false; //toggle4 : bool = false
	int gameRound = 1; //gameRound : int = 1
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
	void initTex();
	void initSprite();
	void initSFX();
	void initMusic();

public:
	//Constructors
	Game();
	virtual ~Game(); // ~Game() : virtual
	 
	//Accessors
	const bool getWindowIsOpen() const;

	//Functions
	void pollEvents(); //pollEvents() : void
	void collisionStates();
	bool collisionPoint();

	int getGameRound();
	void setGameRound(int gameRound);
	void input(int round);

	void update();
	void render();
};

