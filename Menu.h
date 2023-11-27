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

	sf::Texture title1, title2, main1, main2, main3;
	sf::Sprite sprite;
	
	int state = 1;
	bool wait = false;

	void initVars();
	void initWindow();
	void initTex();
	void initSprite();

public:
	Menu();
	virtual ~Menu();

	const bool getWindowIsOpen() const;

	void pollEvents();

	int getState();

	void update();
	void render();
};

