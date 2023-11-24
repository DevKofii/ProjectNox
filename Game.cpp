#include "Game.h"

void Game::initVars()
{
	this->window = nullptr;
	this->endGame = false;
}

void Game::initWindow()
{
	this->videoMode.width = 1280;
	this->videoMode.height = 720;
	this->window = new sf::RenderWindow(this->videoMode, "Project Nox", sf::Style::Titlebar | sf::Style::Close);
	//this->window->setVerticalSyncEnabled(true);
	this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{

	this->enemy.setPosition(sf::Vector2f(0.f, 500.f));
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setScale(sf::Vector2f(0.1f, 0.1f));
	this->enemy.setFillColor(sf::Color::Yellow);
	//this->enemy.setOutlineColor(sf::Color::Red);
	//this->enemy.setOutlineThickness(2.f);
}

Game::Game()
{
	this->initVars();
	this->initWindow();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
}

//Accessors
const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}


//Functions
void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}

}


void Game::update()
{
	this->pollEvents();
	this->map.update(this->window);
	this->player.update(this->window);
	if (player.getcollisionState_L() == true)
	{
		map.setMapState(true);
	}
}

void Game::render()
{
	//Render Game Objects

	this->window->clear();

	//Draw Game Objects
	this->map.render(this->window);
	this->player.render(this->window);
	//this->window->draw(this->enemy);

	this->window->display();
}