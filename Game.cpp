#include "Game.h"

void Game::initVars()
{
	this->window = nullptr;
	this->endGame = false;
	this->gameRound = 1;
	this->move = true;

	this->set1 = false;
	this->set2 = false;
	this->set3 = false;
	this->set4 = false;
	this->set5 = false;
	this->set6 = false;
	this->set7 = false;
	this->set8 = false;
	this->set9 = false;
	this->set10 = false;
	this->set11 = false;

	this->lock1 = false;
	this->lock2 = false;
	this->lock3 = false;
	this->lock4 = false;
	this->lock5 = false;
	this->lock6 = false;
	this->lock7 = false;
	this->lock8 = false;
	this->lock9 = false;
	this->lock10 = false;
	this->lock11 = false;

	this->elapsedTime = this->m_clock.restart();
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
	this->bot_main.updatePoint(1);
	this->bot1.updatePoint(2);
	this->bot2.updatePoint(2);
	this->bot3.updatePoint(2);
	this->bot4.updatePoint(2);
	this->bot5.updatePoint(2);
	this->bot6.updatePoint(2);
	this->bot7.updatePoint(2); 
	this->bot8.updatePoint(2);
	this->bot9.updatePoint(2);
	this->bot10.updatePoint(1);

	this->bot_hitbox.updatePoint(2);

	//this->bot_main.randomGrid();
	//while (this->bot_main.getGrid() == 1) this->bot_main.randomGrid(); // In case point spawns on player spawn lol
	this->bot_main.setGrid(9);
	this->bot1.setGrid(this->bot_main.getGrid());
	this->bot_main.setLockGridState(this->bot_main.getGrid());
	this->bot_main.randomSpawn();
	this->bot1.setSpawn(this->bot_main.getXCoord(), this->bot_main.getYCoord());
	//cout << endl << "Point At: " << this->point.getGrid() << endl;
	/*
	cout << endl << "Grid 1: " << this->point1.getLockState(1) << endl;
	cout << endl << "Grid 2: " << this->point1.getLockState(2) << endl;
	cout << endl << "Grid 3: " << this->point1.getLockState(3) << endl;
	cout << endl << "Grid 4: " << this->point1.getLockState(4) << endl;
	cout << endl << "Grid 5: " << this->point1.getLockState(5) << endl;
	cout << endl << "Grid 6: " << this->point1.getLockState(6) << endl;
	cout << endl << "Grid 7: " << this->point1.getLockState(7) << endl;
	cout << endl << "Grid 8: " << this->point1.getLockState(8) << endl;
	cout << endl << "Grid 9: " << this->point1.getLockState(9) << endl;
	*/
}

void Game::initTex()
{
	if (!this->one.loadFromFile("images\\Intermission\\1.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->two.loadFromFile("images\\Intermission\\2.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->three.loadFromFile("images\\Intermission\\3.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->four.loadFromFile("images\\Intermission\\4.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->five.loadFromFile("images\\Intermission\\5.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->six.loadFromFile("images\\Intermission\\6.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->seven.loadFromFile("images\\Intermission\\7.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->eight.loadFromFile("images\\Intermission\\8.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->nine.loadFromFile("images\\Intermission\\9.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->findhim.loadFromFile("images\\Intermission\\Error.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->spook.loadFromFile("images\\SpookyScare.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	one.setSmooth(1);
	two.setSmooth(1);
	three.setSmooth(1);
	four.setSmooth(1);
	five.setSmooth(1);
	six.setSmooth(1);
	seven.setSmooth(1);
	eight.setSmooth(1);
	nine.setSmooth(1);
	findhim.setSmooth(1);
	spook.setSmooth(1);
}

void Game::initSprite()
{
	this->sprite.setTexture(this->one);
}

void Game::initSFX()
{
	buffer.loadFromFile("sfx\\stab.mp3");
	stab.setBuffer(buffer);
	stab.setLoop(0);
	stab.setVolume(20.f);

	buf1.loadFromFile("voice\\One.mp3");
	sfx1.setBuffer(buf1);
	sfx1.setLoop(0);
	sfx1.setVolume(25.f);

	buf2.loadFromFile("voice\\Two.mp3");
	sfx2.setBuffer(buf2);
	sfx2.setLoop(0);
	sfx2.setVolume(25.f);

	buf3.loadFromFile("voice\\Three.mp3");
	sfx3.setBuffer(buf3);
	sfx3.setLoop(0);
	sfx3.setVolume(25.f);

	buf4.loadFromFile("voice\\Four.mp3");
	sfx4.setBuffer(buf4);
	sfx4.setLoop(0);
	sfx4.setVolume(25.f);

	buf5.loadFromFile("voice\\Five.mp3");
	sfx5.setBuffer(buf5);
	sfx5.setLoop(0);
	sfx5.setVolume(25.f);

	buf6.loadFromFile("voice\\Six.mp3");
	sfx6.setBuffer(buf6);
	sfx6.setLoop(0);
	sfx6.setVolume(25.f);

	buf7.loadFromFile("voice\\Seven.mp3");
	sfx7.setBuffer(buf7);
	sfx7.setLoop(0);
	sfx7.setVolume(25.f);

	buf8.loadFromFile("voice\\Eight.mp3");
	sfx8.setBuffer(buf8);
	sfx8.setLoop(0);
	sfx8.setVolume(25.f);

	buf9.loadFromFile("voice\\Nine.mp3");
	sfx9.setBuffer(buf9);
	sfx9.setLoop(0);
	sfx9.setVolume(25.f);

	buf10.loadFromFile("voice\\Error.mp3");
	sfx10.setBuffer(buf10);
	sfx10.setLoop(1);
	sfx10.setVolume(10.f);

	bufFinal.loadFromFile("voice\\whispers.mp3");
	sfxFinal.setBuffer(bufFinal);
	sfxFinal.setLoop(1);
	sfxFinal.setVolume(5.f);

	bufNox.loadFromFile("voice\\Nox.mp3");
	sfxNox.setBuffer(bufNox);
	sfxNox.setLoop(0);
	sfxNox.setVolume(25.f);

	bufSpook.loadFromFile("voice\\spookysound.mp3");
	sfxSpook.setBuffer(bufSpook);
	sfxSpook.setLoop(1);
	sfxSpook.setVolume(25.f);

	bufAAA.loadFromFile("voice\\AAA.mp3");
	sfxAAA.setBuffer(bufAAA);
	sfxAAA.setLoop(1);
	sfxAAA.setVolume(10.f);
}

void Game::initMusic()
{
	if (!music.openFromFile("music\\Spooky.mp3"))
	{
		//error
	}
	music.setVolume(25.f);
	music.setLoop(1);
	music.play();
}

Game::Game()
{
	this->sprite.setPosition(0.f, 0.f);

	this->initVars();
	this->initWindow();
	this->initPoint();
	this->initTex();
	this->initSprite();
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
		}
	}

}

void Game::collisionStates()
{
	if (this->getGameRound() != 10)
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
		player.setcollisionState_L(false);
		player.setcollisionState_R(false);
		player.setcollisionState_T(false);
		player.setcollisionState_D(false);
	}
	else
	{
		// Grid 1
		if (player.getcollisionState_R() == true && map.getGridNum() == 11)
		{
			this->map.setGridNum(12);
			//map.updateMap(2);
			player.teleport_right(true);
			player.setcollisionState_R(false);
		}

		if (player.getcollisionState_D() == true && map.getGridNum() == 11)
		{
			this->map.setGridNum(14);
			//map.updateMap(4);
			player.teleport_down(true);
			player.setcollisionState_D(false);
		}

		// Grid 2
		if (player.getcollisionState_L() == true && map.getGridNum() == 12)
		{
			this->map.setGridNum(11);
			//map.updateMap(1);
			player.teleport_left(true);
			player.setcollisionState_L(false);
		}

		if (player.getcollisionState_R() == true && map.getGridNum() == 12)
		{
			this->map.setGridNum(13);
			//map.updateMap(3);
			player.teleport_right(true);
			player.setcollisionState_R(false);
		}

		if (player.getcollisionState_D() == true && map.getGridNum() == 12)
		{
			map.setGridNum(5);
			//map.updateMap(5);
			player.teleport_down(true);
			player.setcollisionState_D(false);
		}

		// Grid 3
		if (player.getcollisionState_L() == true && map.getGridNum() == 13)
		{
			this->map.setGridNum(12);
			//map.updateMap(2);
			player.teleport_left(true);
		}

		if (player.getcollisionState_D() == true && map.getGridNum() == 13)
		{
			this->map.setGridNum(16);
			//map.updateMap(6);
			player.teleport_down(true);
			player.setcollisionState_D(false);
		}

		// Grid 4
		if (player.getcollisionState_T() == true && map.getGridNum() == 14)
		{
			this->map.setGridNum(11);
			//map.updateMap(1);
			player.teleport_top(true);
			player.setcollisionState_T(false);
		}

		if (player.getcollisionState_R() == true && map.getGridNum() == 14)
		{
			map.setGridNum(5);
			//map.updateMap(5);
			player.teleport_right(true);
			player.setcollisionState_R(false);
		}

		if (player.getcollisionState_D() == true && map.getGridNum() == 14)
		{
			this->map.setGridNum(17);
			//map.updateMap(7);
			player.teleport_down(true);
			player.setcollisionState_D(false);
		}

		// Grid 5
		if (player.getcollisionState_L() == true && map.getGridNum() == 5)
		{
			this->map.setGridNum(14);
			//map.updateMap(4);
			player.teleport_left(true);
			player.setcollisionState_L(false);
		}

		if (player.getcollisionState_R() == true && map.getGridNum() == 5)
		{
			this->map.setGridNum(16);
			//map.updateMap(6);
			player.teleport_right(true);
			player.setcollisionState_R(false);
		}

		if (player.getcollisionState_T() == true && map.getGridNum() == 5)
		{
			this->map.setGridNum(12);
			//map.updateMap(2);
			player.teleport_top(true);
			player.setcollisionState_T(false);
		}

		if (player.getcollisionState_D() == true && map.getGridNum() == 5)
		{
			this->map.setGridNum(18);
			//map.updateMap(8);
			player.teleport_down(true);
			player.setcollisionState_D(false);
		}

		// Grid 6
		if (player.getcollisionState_L() == true && map.getGridNum() == 16)
		{
			map.setGridNum(5);
			//map.updateMap(5);
			player.teleport_left(true);
			player.setcollisionState_L(false);
		}

		if (player.getcollisionState_T() == true && map.getGridNum() == 16)
		{
			this->map.setGridNum(13);
			//map.updateMap(3);
			player.teleport_top(true);
			player.setcollisionState_T(false);
		}

		if (player.getcollisionState_D() == true && map.getGridNum() == 16)
		{
			this->map.setGridNum(19);
			//map.updateMap(9);
			player.teleport_down(true);
			player.setcollisionState_D(false);
		}

		// Grid 7
		if (player.getcollisionState_R() == true && map.getGridNum() == 17)
		{
			this->map.setGridNum(18);
			//map.updateMap(8);
			player.teleport_right(true);
			player.setcollisionState_R(false);
		}

		if (player.getcollisionState_T() == true && map.getGridNum() == 17)
		{
			this->map.setGridNum(14);
			//map.updateMap(4);
			player.teleport_top(true);
			player.setcollisionState_T(false);
		}

		// Grid 8
		if (player.getcollisionState_L() == true && map.getGridNum() == 18)
		{
			this->map.setGridNum(17);
			//map.updateMap(7);
			player.teleport_left(true);
			player.setcollisionState_L(false);
		}

		if (player.getcollisionState_R() == true && map.getGridNum() == 18)
		{
			this->map.setGridNum(19);
			//map.updateMap(9);
			player.teleport_right(true);
			player.setcollisionState_R(false);
		}

		if (player.getcollisionState_T() == true && map.getGridNum() == 18)
		{
			map.setGridNum(5);
			//map.updateMap(5);
			player.teleport_top(true);
			player.setcollisionState_T(false);
		}

		// Grid 9
		if (player.getcollisionState_L() == true && map.getGridNum() == 19)
		{
			this->map.setGridNum(18);
			//map.updateMap(8);
			player.teleport_left(true);
			player.setcollisionState_L(false);
		}

		if (player.getcollisionState_T() == true && map.getGridNum() == 19)
		{
			this->map.setGridNum(16);
			//map.updateMap(6);
			player.teleport_top(true);
			player.setcollisionState_T(false);
		}
		player.setcollisionState_L(false);
		player.setcollisionState_R(false);
		player.setcollisionState_T(false);
		player.setcollisionState_D(false);
	}

	//Reset Collision States

}

bool Game::collisionPoint()
{
	if (player.collisionTest().intersects(this->bot_main.collisionTest()))
	{
		//cout << "It collided.";
		return true;
	}
	if (player.collisionTest().intersects(this->bot_hitbox.collisionTest()))
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

void Game::input(int gameRound)
{
	switch (gameRound)
	{
	case 1:
		while (this->lock1 == false)
		{
			this->sfx1.play();
			this->lock1 = true;
			this->move = false;
		}
		this->sprite.setColor(sf::Color(255, 255, 255, 255));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->set1 == false)
		{
			//this->sprite.setColor(sf::Color(255, 255, 255,  0));
			this->set1 = true;
			this->move = true;
		}
		break;
	case 2:
		while (this->lock2 == false)
		{
			this->sfx2.play();
			this->lock2 = true;
			this->move = false;
		}
		this->sprite.setTexture(two);
		this->sprite.setColor(sf::Color(255, 255, 255, 255));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->set2 == false)
		{
			set2 = true;
			this->move = true;
		}
		break;

	case 3:
		while (this->lock3 == false)
		{
			this->sfx3.play();
			this->lock3 = true;
			this->move = false;
		}
		this->sprite.setTexture(three);
		this->sprite.setColor(sf::Color(255, 255, 255, 255));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->set3 == false)
		{
			set3 = true;
			this->move = true;
		}
		break;
	case 4:
		while (this->lock4 == false)
		{
			this->sfx4.play();
			this->lock4 = true;
			this->move = false;
		}
		this->sprite.setTexture(four);
		this->sprite.setColor(sf::Color(255, 255, 255, 255));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->set4 == false)
		{
			set4 = true;
			this->move = true;
		}
		break;
	case 5:
		while (this->lock5 == false)
		{
			this->sfx5.play();
			this->lock5 = true;
			this->move = false;
		}
		this->sprite.setTexture(five);
		this->sprite.setColor(sf::Color(255, 255, 255, 255));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->set5 == false)
		{
			set5 = true;
			this->move = true;
		}
		break;
	case 6:
		while (this->lock6 == false)
		{
			this->sfx6.play();
			this->lock6 = true;
			this->move = false;
		}
		this->sprite.setTexture(six);
		this->sprite.setColor(sf::Color(255, 255, 255, 255));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->set6 == false)
		{
			set6 = true;
			this->move = true;
		}
		break;
	case 7:
		while (this->lock7 == false)
		{
			this->sfx7.play();
			this->lock7 = true;
			this->move = false;
		}
		this->sprite.setTexture(seven);
		this->sprite.setColor(sf::Color(255, 255, 255, 255));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->set7 == false)
		{
			set7 = true;
			this->move = true;
		}
		break;
	case 8:
		while (this->lock8 == false)
		{
			this->sfx8.play();
			this->lock8 = true;
			this->move = false;
		}
		this->sprite.setTexture(eight);
		this->sprite.setColor(sf::Color(255, 255, 255, 255));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->set8 == false)
		{
			set8 = true;
			this->move = true;
		}
		break;
	case 9:
		while (this->lock9 == false)
		{
			this->sfx9.play();
			this->lock9 = true;
			this->move = false;
		}
		this->sprite.setTexture(nine);
		this->sprite.setColor(sf::Color(255, 255, 255, 255));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->set9 == false)
		{
			set9 = true;
			this->move = true;
		}
		break;
	case 10:
		this->music.setVolume(0.f);
		while (this->lock10 == false)
		{
			this->sfx10.play();
			this->lock10 = true;
			this->move = false;
		}
		this->sprite.setTexture(findhim);
		this->sprite.setColor(sf::Color(255, 255, 255, 255));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->set10 == false)
		{
			this->sfx10.pause();
			set10 = true;
			this->move = true;
			this->sfxFinal.play();
		}
		break;
	case 11:
		this->player.updatePlayer(-1);
		while (this->lock11 == false)
		{
			this->sfxNox.play();
			this->lock11 = true;
			this->move = false;
		}
		TimerCount += elapsedTime.asSeconds();
		if (TimerCount > 150.f && this->set11 == false)
		{
			this->set11 = true;
			this->sfxAAA.play();
			this->player.setAlpha(0);
			this->bot1.setAlpha(0);
			this->bot2.setAlpha(0);
			this->bot3.setAlpha(0);
			this->bot4.setAlpha(0);
			this->bot5.setAlpha(0);
			this->bot6.setAlpha(0);
			this->bot7.setAlpha(0);
			this->bot8.setAlpha(0);
			this->bot9.setAlpha(0);
			this->bot10.setAlpha(0);
			this->sprite.setColor(sf::Color(255, 255, 255, 255));
			this->sprite.setTexture(spook);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->set10 == false) this->window->close();
		}
		break;
	}
}

void Game::renderSet()
{
	switch (this->getGameRound())
	{
	case 1:
		input(1);
		if (this->set1 == true) this->sprite.setColor(sf::Color(255, 255, 255, 0));
		this->player.updatePlayer(1);
		//set Vars for Round1
		if (this->bot_main.getGrid() == this->map.getGridNum() && this->collisionPoint() == true)
		{
			this->stab.play();
			this->bot_main.deletePoint();
			this->bot1.setAlpha(255);
			//this->bot_main.randomGrid();
			//while (this->bot_main.getLockState(this->bot_main.getGrid()) == true) this->bot_main.randomGrid();
			this->bot_main.setGrid(2);
			this->bot2.setGrid(this->bot_main.getGrid());
			this->bot_main.setLockGridState(this->bot_main.getGrid());
			this->bot_main.randomSpawn();
			this->bot2.setSpawn(this->bot_main.getXCoord(), this->bot_main.getYCoord());
			this->setGameRound(2);
		}
		break;
	case 2:
		//set Vars for Round2
		//Transfers Player to a different Round
		//this->point2.setAlpha(0);
		input(2);
		if (this->set2 == true) this->sprite.setColor(sf::Color(255, 255, 255, 0));
		this->player.updatePlayer(2);

		if (this->bot_main.getGrid() == this->map.getGridNum() && this->collisionPoint() == true)
		{
			this->stab.play();
			this->bot_main.deletePoint();
			this->bot2.setAlpha(255);
			//this->bot_main.randomGrid();
			//while (this->bot_main.getLockState(this->bot_main.getGrid()) == true) this->bot_main.randomGrid();
			this->bot_main.setGrid(5);
			this->bot3.setGrid(this->bot_main.getGrid());
			this->bot_main.setLockGridState(this->bot_main.getGrid());
			this->bot_main.randomSpawn();
			this->bot3.setSpawn(this->bot_main.getXCoord(), this->bot_main.getYCoord());
			this->setGameRound(3);
		}
		break;
	case 3:
		input(3);
		if (this->set3 == true) this->sprite.setColor(sf::Color(255, 255, 255, 0));
		this->player.updatePlayer(3);
		if (this->bot_main.getGrid() == this->map.getGridNum() && this->collisionPoint() == true)
		{
			this->stab.play();
			this->bot_main.deletePoint();
			this->bot3.setAlpha(255);
			//this->bot_main.randomGrid();
			//while (this->bot_main.getLockState(this->bot_main.getGrid()) == true) this->bot_main.randomGrid();
			this->bot_main.setGrid(8);
			this->bot4.setGrid(this->bot_main.getGrid()); //
			this->bot_main.setLockGridState(this->bot_main.getGrid());
			this->bot_main.randomSpawn();
			this->bot4.setSpawn(this->bot_main.getXCoord(), this->bot_main.getYCoord()); //
			this->setGameRound(4);
		}
		break;
	case 4:
		input(4);
		if (this->set4 == true) this->sprite.setColor(sf::Color(255, 255, 255, 0));
		this->player.updatePlayer(4);
		if (this->bot_main.getGrid() == this->map.getGridNum() && this->collisionPoint() == true)
		{
			this->stab.play();
			this->bot_main.deletePoint();
			this->bot4.setAlpha(255);
			//this->bot_main.randomGrid();
			//while (this->bot_main.getLockState(this->bot_main.getGrid()) == true) this->bot_main.randomGrid();
			this->bot_main.setGrid(3);
			this->bot5.setGrid(this->bot_main.getGrid()); //
			this->bot_main.setLockGridState(this->bot_main.getGrid());
			this->bot_main.randomSpawn();
			this->bot5.setSpawn(this->bot_main.getXCoord(), this->bot_main.getYCoord()); //
			this->setGameRound(5);
		}
		break;
	case 5:
		input(5);
		if (this->set5 == true) this->sprite.setColor(sf::Color(255, 255, 255, 0));
		this->player.updatePlayer(5);
		if (this->bot_main.getGrid() == this->map.getGridNum() && this->collisionPoint() == true)
		{
			this->stab.play();
			this->bot_main.deletePoint();
			this->bot5.setAlpha(255);
			//this->bot_main.randomGrid();
			//while (this->bot_main.getLockState(this->bot_main.getGrid()) == true) this->bot_main.randomGrid();
			this->bot_main.setGrid(4);
			this->bot6.setGrid(this->bot_main.getGrid()); //
			this->bot_main.setLockGridState(this->bot_main.getGrid());
			this->bot_main.randomSpawn();
			this->bot6.setSpawn(this->bot_main.getXCoord(), this->bot_main.getYCoord()); //
			this->setGameRound(6);
		}
		break;
	case 6:
		input(6);
		if (this->set6 == true) this->sprite.setColor(sf::Color(255, 255, 255, 0));
		this->player.updatePlayer(6);
		if (this->bot_main.getGrid() == this->map.getGridNum() && this->collisionPoint() == true)
		{
			this->stab.play();
			this->bot_main.deletePoint();
			this->bot6.setAlpha(255);
			//this->bot_main.randomGrid();
			//while (this->bot_main.getLockState(this->bot_main.getGrid()) == true) this->bot_main.randomGrid();
			this->bot_main.setGrid(6);
			this->bot7.setGrid(this->bot_main.getGrid()); //
			this->bot_main.setLockGridState(this->bot_main.getGrid());
			this->bot_main.randomSpawn();
			this->bot7.setSpawn(this->bot_main.getXCoord(), this->bot_main.getYCoord()); //
			this->setGameRound(7);
		}
		break;
	case 7:
		input(7);
		if (this->set7 == true) this->sprite.setColor(sf::Color(255, 255, 255, 0));
		this->player.updatePlayer(7);
		if (this->bot_main.getGrid() == this->map.getGridNum() && this->collisionPoint() == true)
		{
			this->stab.play();
			this->bot_main.deletePoint();
			this->bot7.setAlpha(255);
			//this->bot_main.randomGrid();
			//while (this->bot_main.getLockState(this->bot_main.getGrid()) == true) this->bot_main.randomGrid();
			this->bot_main.setGrid(7);
			this->bot8.setGrid(this->bot_main.getGrid()); //
			this->bot_main.setLockGridState(this->bot_main.getGrid());
			this->bot_main.randomSpawn();
			this->bot8.setSpawn(this->bot_main.getXCoord(), this->bot_main.getYCoord()); //
			this->setGameRound(8);
		}
		break;
	case 8:
		input(8);
		if (this->set8 == true) this->sprite.setColor(sf::Color(255, 255, 255, 0));
		this->player.updatePlayer(8);
		if (this->bot_main.getGrid() == this->map.getGridNum() && this->collisionPoint() == true)
		{
			this->stab.play();
			this->bot_main.deletePoint();
			this->bot8.setAlpha(255);
			//this->bot_main.randomGrid();
			//while (this->bot_main.getLockState(this->bot_main.getGrid()) == true) this->bot_main.randomGrid();
			this->bot_main.setGrid(1);
			this->bot9.setGrid(this->bot_main.getGrid()); //
			this->bot_main.setLockGridState(this->bot_main.getGrid());
			this->bot_main.randomSpawn();
			this->bot9.setSpawn(this->bot_main.getXCoord(), this->bot_main.getYCoord()); //
			this->setGameRound(9);
		}
		break;
	case 9:
		input(9);
		if (this->set9 == true) this->sprite.setColor(sf::Color(255, 255, 255, 0));
		this->player.updatePlayer(9);
		if (this->bot_main.getGrid() == this->map.getGridNum() && this->collisionPoint() == true)
		{
			this->stab.play();
			this->bot_main.deletePoint();
			this->bot_main.setAlpha(0);
			this->bot9.setAlpha(255);
			this->bot10.setGrid(5);
			this->bot10.setSpawn(900, 330);
			this->setGameRound(10);
			this->map.setGridNum(11);
		}
		break;
	case 10:
		input(10);
		if (this->set10 == true) this->sprite.setColor(sf::Color(255, 255, 255, 0));
		this->player.updatePlayer(10);

		if (this->map.getGridNum() == 5)
		{
			this->bot_hitbox.setAlpha(0);
			this->bot_hitbox.setGrid(5);
			this->bot_hitbox.setSpawn(640, 360);

			this->bot1.setGrid(5);
			this->bot2.setGrid(5);
			this->bot3.setGrid(5);
			this->bot1.setSpawn(510, 220);
			this->bot2.setSpawn(640, 220);
			this->bot3.setSpawn(770, 220);

			this->bot4.setGrid(5);
			this->bot5.setGrid(5);
			this->bot6.setGrid(5);
			this->bot4.setSpawn(510, 360);
			this->bot5.setSpawn(640, 360);
			this->bot6.setSpawn(770, 360);

			this->bot7.setGrid(5);
			this->bot8.setGrid(5);
			this->bot9.setGrid(5);
			this->bot7.setSpawn(510, 500);
			this->bot8.setSpawn(640, 500);
			this->bot9.setSpawn(770, 500);
			if (this->collisionPoint() == true)
			{
				this->sfxFinal.pause();
				this->setGameRound(11);
			}
		}
		break;
	case 11:
		input(11);
		break;
	}
}

void Game::update()
{
	this->pollEvents();
	this->map.update(this->window);
	if(this->move == true) this->player.update(this->window);
	this->collisionStates();
	this->collisionPoint();
}

void Game::render()
{
	//Render Game Objects
	this->window->clear();
	
	this->renderSet();

	this->map.render(this->window);
	this->window->draw(this->sprite);
	if (this->bot_main.getGrid() == this->map.getGridNum()) this->bot_main.render(this->window);
	if (this->bot1.getGrid() == this->map.getGridNum()) this->bot1.render(this->window);
	if (this->bot2.getGrid() == this->map.getGridNum()) this->bot2.render(this->window);
	if (this->bot3.getGrid() == this->map.getGridNum()) this->bot3.render(this->window);
	if (this->bot4.getGrid() == this->map.getGridNum()) this->bot4.render(this->window);
	if (this->bot5.getGrid() == this->map.getGridNum()) this->bot5.render(this->window);
	if (this->bot6.getGrid() == this->map.getGridNum()) this->bot6.render(this->window);
	if (this->bot7.getGrid() == this->map.getGridNum()) this->bot7.render(this->window);
	if (this->bot8.getGrid() == this->map.getGridNum()) this->bot8.render(this->window);
	if (this->bot9.getGrid() == this->map.getGridNum()) this->bot9.render(this->window);
	if (this->bot10.getGrid() == this->map.getGridNum()) this->bot10.render(this->window);
	this->player.render(this->window);

	//Debugs
	//cout << this->getGameRound();
	//if (this->player.getcollisionState_D() == true) this->point.~Point();
	//this->window->draw(this->enemy);

	this->window->display();
}