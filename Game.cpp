#include "Game.h"

void Game::initVars()
{
	this->window = nullptr;
	this->endGame = false;
	cout << endl << "Point At: " << this->point.getGrid() << endl;
	//this->point.display(); Debug
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

void Game::initPoint()
{
	this->point.randomSpawn();
}

Game::Game()
{
	this->initVars();
	this->initWindow();
	this->initEnemies();
	this->initPoint();
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

void Game::collisionStates()
{

	// Grid 1
	if (player.getcollisionState_R() == true && map.getGridNum() == 1)
	{
		map.setGridNum(2);
		//map.updateMap(2);
		player.teleport_right(true);
		player.setcollisionState_R(false);
	}

	if (player.getcollisionState_D() == true && map.getGridNum() == 1)
	{
		map.setGridNum(4);
		//map.updateMap(4);
		player.teleport_down(true);
		player.setcollisionState_D(false);
	}

	// Grid 2
	if (player.getcollisionState_L() == true && map.getGridNum() == 2)
	{
		map.setGridNum(1);
		//map.updateMap(1);
		player.teleport_left(true);
		player.setcollisionState_L(false);
	}

	if (player.getcollisionState_R() == true && map.getGridNum() == 2)
	{
		map.setGridNum(3);
		//map.updateMap(3);
		player.teleport_right(true);
		player.setcollisionState_R(false);
	}

	if (player.getcollisionState_D() == true && map.getGridNum() == 2)
	{
		map.setGridNum(5);
		//map.updateMap(5);
		player.teleport_down(true);
		player.setcollisionState_D(false);
	}
	
	// Grid 3
	if (player.getcollisionState_L() == true && map.getGridNum() == 3)
	{
		map.setGridNum(2);
		//map.updateMap(2);
		player.teleport_left(true);
	}

	if (player.getcollisionState_D() == true && map.getGridNum() == 3)
	{
		map.setGridNum(6);
		//map.updateMap(6);
		player.teleport_down(true);
		player.setcollisionState_D(false);
	}

	// Grid 4
	if (player.getcollisionState_T() == true && map.getGridNum() == 4)
	{
		map.setGridNum(1);
		//map.updateMap(1);
		player.teleport_top(true);
		player.setcollisionState_T(false);
	}

	if (player.getcollisionState_R() == true && map.getGridNum() == 4)
	{
		map.setGridNum(5);
		//map.updateMap(5);
		player.teleport_right(true);
		player.setcollisionState_R(false);
	}

	if (player.getcollisionState_D() == true && map.getGridNum() == 4)
	{
		map.setGridNum(7);
		//map.updateMap(7);
		player.teleport_down(true);
		player.setcollisionState_D(false);
	}

	// Grid 5
	if (player.getcollisionState_L() == true && map.getGridNum() == 5)
	{
		map.setGridNum(4);
		//map.updateMap(4);
		player.teleport_left(true);
		player.setcollisionState_L(false);
	}

	if (player.getcollisionState_R() == true && map.getGridNum() == 5)
	{
		map.setGridNum(6);
		//map.updateMap(6);
		player.teleport_right(true);
		player.setcollisionState_R(false);
	}

	if (player.getcollisionState_T() == true && map.getGridNum() == 5)
	{
		map.setGridNum(2);
		//map.updateMap(2);
		player.teleport_top(true);
		player.setcollisionState_T(false);
	}

	if (player.getcollisionState_D() == true && map.getGridNum() == 5)
	{
		map.setGridNum(8);
		//map.updateMap(8);
		player.teleport_down(true);
		player.setcollisionState_D(false);
	}

	// Grid 6
	if (player.getcollisionState_L() == true && map.getGridNum() == 6)
	{
		map.setGridNum(5);
		//map.updateMap(5);
		player.teleport_left(true);
		player.setcollisionState_L(false);
	}

	if (player.getcollisionState_T() == true && map.getGridNum() == 6)
	{
		map.setGridNum(3);
		//map.updateMap(3);
		player.teleport_top(true);
		player.setcollisionState_T(false);
	}

	if (player.getcollisionState_D() == true && map.getGridNum() == 6)
	{
		map.setGridNum(9);
		//map.updateMap(9);
		player.teleport_down(true);
		player.setcollisionState_D(false);
	}

	// Grid 7
	if (player.getcollisionState_R() == true && map.getGridNum() == 7)
	{
		map.setGridNum(8);
		//map.updateMap(8);
		player.teleport_right(true);
		player.setcollisionState_R(false);
	}

	if (player.getcollisionState_T() == true && map.getGridNum() == 7)
	{
		map.setGridNum(4);
		//map.updateMap(4);
		player.teleport_top(true);
		player.setcollisionState_T(false);
	}

	// Grid 8
	if (player.getcollisionState_L() == true && map.getGridNum() == 8)
	{
		map.setGridNum(7);
		//map.updateMap(7);
		player.teleport_left(true);
		player.setcollisionState_L(false);
	}

	if (player.getcollisionState_R() == true && map.getGridNum() == 8)
	{
		map.setGridNum(9);
		//map.updateMap(9);
		player.teleport_right(true);
		player.setcollisionState_R(false);
	}

	if (player.getcollisionState_T() == true && map.getGridNum() == 8)
	{
		map.setGridNum(5);
		//map.updateMap(5);
		player.teleport_top(true);
		player.setcollisionState_T(false);
	}

	// Grid 9
	if (player.getcollisionState_L() == true && map.getGridNum() == 9)
	{
		map.setGridNum(8);
		//map.updateMap(8);
		player.teleport_left(true);
		player.setcollisionState_L(false);
	}

	if (player.getcollisionState_T() == true && map.getGridNum() == 9)
	{
		map.setGridNum(6);
		//map.updateMap(6);
		player.teleport_top(true);
		player.setcollisionState_T(false);
	}

	//Reset Collision States
	player.setcollisionState_L(false);
	player.setcollisionState_R(false);
	player.setcollisionState_T(false);
	player.setcollisionState_D(false);
}

void Game::update()
{
	this->pollEvents();
	this->map.update(this->window);
	this->player.update(this->window);
	this->point.update(this->window);
	this->collisionStates();
	cout << map.getGridNum();
}

void Game::render()
{
	//Render Game Objects
	
	this->window->clear();

	//Draw Game Objects
	this->map.render(this->window);
	this->player.render(this->window);

	if (this->point.getGrid() == this->map.getGridNum()) this->point.render(this->window);
	//this->window->draw(this->enemy);

	this->window->display();
}