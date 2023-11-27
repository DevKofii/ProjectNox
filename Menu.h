#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Menu
{
private:
	sf::RenderWindow* menuWindow;
	sf::VideoMode videoMode;
	sf::Event sfmlEvent;

	void initVars();
	void initWindow();

public:
	Menu();
	virtual ~Menu();

	const bool getWindowIsOpen() const;

	void pollEvents();

	void update();
	void render();
};

