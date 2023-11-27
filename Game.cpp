#include "Game.h"

void Game::initVars()
{
	this->window = nullptr;
	this->endGame = false;
	this->gameRound = 1;
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

void Game::initPoint()
{
	this->point1.updatePoint(1);
	this->point2.updatePoint(2);
	this->point3.updatePoint(2);
	this->point4.updatePoint(2);

	this->point1.randomGrid();
	while (this->point1.getGrid() == 1) this->point1.randomGrid(); // In case point spawns on player spawn lol
	this->point2.setGrid(this->point1.getGrid());
	this->point1.setLockGridState(this->point1.getGrid());
	this->point1.randomSpawn();
	this->point2.setSpawn(this->point1.getXCoord(), this->point1.getYCoord());
	//cout << endl << "Point At: " << this->point.getGrid() << endl;
	cout << endl << "Grid 1: " << this->point1.getLockState(1) << endl;
	cout << endl << "Grid 2: " << this->point1.getLockState(2) << endl;
	cout << endl << "Grid 3: " << this->point1.getLockState(3) << endl;
	cout << endl << "Grid 4: " << this->point1.getLockState(4) << endl;
	cout << endl << "Grid 5: " << this->point1.getLockState(5) << endl;
	cout << endl << "Grid 6: " << this->point1.getLockState(6) << endl;
	cout << endl << "Grid 7: " << this->point1.getLockState(7) << endl;
	cout << endl << "Grid 8: " << this->point1.getLockState(8) << endl;
	cout << endl << "Grid 9: " << this->point1.getLockState(9) << endl;
}

void Game::initSFX()
{
	buffer.loadFromFile("sfx\\stab.mp3");
	stab.setBuffer(buffer);
	stab.setLoop(0);
	stab.setVolume(25.f);
}

void Game::initMusic()
{
	if (!music.openFromFile("music\\Undertale OST..._ - Gaster's Theme Extended.mp3"))
	{
		//error
	}
	music.setVolume(25.f);
	music.setLoop(1);
	music.play();
}

Game::Game()
{
	this->initVars();
	this->initWindow();
	this->initPoint();
	this->initSFX();
	this->initMusic();
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
		case sf::Event::LostFocus:
			this->wait = true;
			break;
		case sf::Event::GainedFocus:
			this->wait = false;
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

bool Game::collisionPoint()
{
	if (player.collisionTest().intersects(point1.collisionTest()))
	{
		//cout << "It collided.";
		return true;
	}
	return false;
}

int Game::getGameRound()
{
	return gameRound;
}

void Game::setGameRound(int gameRound)
{
	this->gameRound = gameRound;
}

void Game::update()
{
	switch (this->wait)
	{
	case true:
		break;
	case false:
		this->pollEvents();
		this->map.update(this->window);
		this->player.update(this->window);
		this->collisionStates();
		this->collisionPoint();
		break;
	}
}

void Game::render()
{
	//Render Game Objects
	this->window->clear();

	//Round Works. Time To Polish This Shit
	//Draw Game Objects
	if (this->getGameRound() == 1)
	{
		this->player.updatePlayer(1);
		//set Vars for Round1
		if (this->point1.getGrid() == this->map.getGridNum() && this->collisionPoint() == true)
		{
			this->stab.play();
			this->point1.deletePoint();
			this->point2.setAlpha(255);
			this->point1.randomGrid();
			while (this->point1.getLockState(this->point1.getGrid()) == true) this->point1.randomGrid();
			this->point3.setGrid(this->point1.getGrid());
			this->point1.setLockGridState(this->point1.getGrid());
			this->point1.randomSpawn();
			this->point3.setSpawn(this->point1.getXCoord(), this->point1.getYCoord());
			this->setGameRound(2);
			//Debug
			cout << endl << "Point At: " << this->point1.getGrid() << endl;
			cout << endl << "Grid 1: " << this->point1.getLockState(1) << endl;
			cout << endl << "Grid 2: " << this->point1.getLockState(2) << endl;
			cout << endl << "Grid 3: " << this->point1.getLockState(3) << endl;
			cout << endl << "Grid 4: " << this->point1.getLockState(4) << endl;
			cout << endl << "Grid 5: " << this->point1.getLockState(5) << endl;
			cout << endl << "Grid 6: " << this->point1.getLockState(6) << endl;
			cout << endl << "Grid 7: " << this->point1.getLockState(7) << endl;
			cout << endl << "Grid 8: " << this->point1.getLockState(8) << endl;
			cout << endl << "Grid 9: " << this->point1.getLockState(9) << endl;

		}
	}

	if (this->getGameRound() == 2)
	{
		//set Vars for Round2
		//Transfers Player to a different Round
		this->map.updateMap(2);
		this->player.updatePlayer(2);

		if (this->point1.getGrid() == this->map.getGridNum() && this->collisionPoint() == true)
		{
			this->stab.play();
			this->point1.deletePoint();
			this->point3.setAlpha(255);
			this->point1.randomGrid();
			while (this->point1.getLockState(this->point1.getGrid()) == true) this->point1.randomGrid();
			this->point4.setGrid(this->point1.getGrid());
			this->point1.setLockGridState(this->point1.getGrid());
			this->point1.randomSpawn();
			this->point4.setSpawn(this->point1.getXCoord(), this->point1.getYCoord());
			this->setGameRound(3);
			//Debug
			cout << endl << "Point At: " << this->point1.getGrid() << endl;
			cout << endl << "Grid 1: " << this->point1.getLockState(1) << endl;
			cout << endl << "Grid 2: " << this->point1.getLockState(2) << endl;
			cout << endl << "Grid 3: " << this->point1.getLockState(3) << endl;
			cout << endl << "Grid 4: " << this->point1.getLockState(4) << endl;
			cout << endl << "Grid 5: " << this->point1.getLockState(5) << endl;
			cout << endl << "Grid 6: " << this->point1.getLockState(6) << endl;
			cout << endl << "Grid 7: " << this->point1.getLockState(7) << endl;
			cout << endl << "Grid 8: " << this->point1.getLockState(8) << endl;
			cout << endl << "Grid 9: " << this->point1.getLockState(9) << endl;
		}
	}

	if (this->getGameRound() == 3)
	{
		this->map.updateMap(3);
		this->player.updatePlayer(3);
		if (this->point1.getGrid() == this->map.getGridNum() && this->collisionPoint() == true)
		{
			this->stab.play();
			this->point1.deletePoint();
			this->point1.setAlpha(0);
			this->point4.setAlpha(255);
			cout << endl << "Game Clear!" << endl;
			//this->window->close();
		}
	}
	

	this->map.render(this->window);
	this->player.render(this->window);
	if (this->point1.getGrid() == this->map.getGridNum()) this->point1.render(this->window);
	if (this->point2.getGrid() == this->map.getGridNum()) this->point2.render(this->window);
	if (this->point3.getGrid() == this->map.getGridNum()) this->point3.render(this->window);
	if (this->point4.getGrid() == this->map.getGridNum()) this->point4.render(this->window);
	//Debugs
	//cout << this->getGameRound();
	//if (this->player.getcollisionState_D() == true) this->point.~Point();
	//this->window->draw(this->enemy);

	this->window->display();
}