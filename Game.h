#pragma once
#include <iostream>
#include <string>
#include <cstdlib>


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Player.h"
#include "Map.h"
#include "Point.h"

using namespace std;

class Game {
private:
	//Variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event sfmlEvent;
	sf::Texture one, two, three, four, five, six, seven, eight, nine, findhim, spook;
	sf::Sprite sprite;

	sf::SoundBuffer buf1, buf2, buf3, buf4, buf5, buf6, buf7, buf8, buf9, buf10, buffer, bufFinal, bufNox, bufSpook, bufAAA;
	sf::Sound stab, sfx1, sfx2, sfx3, sfx4, sfx5, sfx6, sfx7, sfx8, sfx9, sfx10, sfxFinal, sfxNox, sfxSpook, sfxAAA;
	sf::Music music;
	sf::Clock m_clock;
	sf::Time elapsedTime;
	
	float TimerCount;

	bool endGame, set1, set2, set3, set4, set5, set6, set7, set8, set9, set10, set11,
	lock1, lock2, lock3, lock4, lock5, lock6, lock7, lock8, lock9, lock10, lock11, move;

	int gameRound = 1;
	sf::Vector2f num;

	//Game Objects
	Map map;
	Player player;
	Point bot_main, bot1, bot2, bot3, bot4, bot5, bot6, bot7, bot8, bot9, bot10, bot_hitbox;

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
	virtual ~Game(); 
	 
	//Accessors
	const bool getWindowIsOpen() const;

	//Functions
	void pollEvents(); 
	void collisionStates();
	bool collisionPoint();

	int getGameRound();
	void setGameRound(int gameRound);
	void input(int gameRound);

	void renderSet();

	void update();
	void render();
};

