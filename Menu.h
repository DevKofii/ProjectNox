#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;

class Menu
{
private:
	sf::RenderWindow* menuWindow;
	sf::VideoMode videoMode;
	sf::Event sfmlEvent;
	sf::SoundBuffer buffer1, buffer2, buffer3, buffer4;
	sf::Sound open, close, hover, select;
	sf::Music music;

	sf::Texture title1, title2, main1, main2, main3;
	sf::Sprite sprite;
	
	int state = 1;
	bool wait = false;

	void initVars();
	void initWindow();
	void initTex();
	void initSprite();
	void initSound();
	void initMusic();

public:
	Menu();
	virtual ~Menu();

	const bool getWindowIsOpen() const;

	void pollEvents();

	int getState();

	void update();
	void render();
};

