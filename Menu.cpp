#include "Menu.h"

void Menu::initVars()
{
	this->menuWindow == nullptr;
}

void Menu::initWindow()
{
	this->videoMode.width = 1280;
	this->videoMode.height = 720;
	this->menuWindow = new sf::RenderWindow(this->videoMode, "Project Nox", sf::Style::Titlebar | sf::Style::Close);
	//this->window->setVerticalSyncEnabled(true);
	this->menuWindow->setFramerateLimit(60);
}

void Menu::initTex()
{
	if (!this->title1.loadFromFile("images\\Title1.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->title2.loadFromFile("images\\Title2.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->main1.loadFromFile("images\\MainMenu1.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->main2.loadFromFile("images\\MainMenu1_Play.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	if (!this->main3.loadFromFile("images\\MainMenu1_Leave.png"))
	{
		cout << endl << "Texture Not Found." << endl;
	}
	title1.setSmooth(1);
	title2.setSmooth(1);
	main1.setSmooth(1);
	main2.setSmooth(1);
	main3.setSmooth(1);
}

void Menu::initSprite()
{
	this->sprite.setTexture(this->title1);
}

Menu::Menu()
{
	this->sprite.setPosition(0.f, 0.f);

	this->initVars();
	this->initWindow();
	this->initTex();
	this->initSprite();
}

Menu::~Menu()
{
	delete this->menuWindow;
}

const bool Menu::getWindowIsOpen() const
{
	return this->menuWindow->isOpen();;
}

void Menu::pollEvents()
{
	while (this->menuWindow->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->menuWindow->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
				this->menuWindow->close();
			break;
		case sf::Event::MouseMoved:
			//cout << endl << "X: " << sfmlEvent.mouseMove.x;
			//cout << endl << "Y: " << this->sfmlEvent.mouseMove.y;
			switch (state)
			{
			case 1:
				if (this->sfmlEvent.mouseMove.x >= 587 && this->sfmlEvent.mouseMove.x <= 691 &&
					this->sfmlEvent.mouseMove.y >= 285 && this->sfmlEvent.mouseMove.y <= 431)
					this->sprite.setTexture(this->title2);
				else
					this->sprite.setTexture(this->title1);
				break;
			case 2:
				if (this->sfmlEvent.mouseMove.x >= 464 && this->sfmlEvent.mouseMove.x <= 815 &&
					this->sfmlEvent.mouseMove.y >= 315 && this->sfmlEvent.mouseMove.y <= 410)
					this->sprite.setTexture(this->main2);

				else if (this->sfmlEvent.mouseMove.x >= 464 && this->sfmlEvent.mouseMove.x <= 815 &&
					this->sfmlEvent.mouseMove.y >= 468 && this->sfmlEvent.mouseMove.y <= 560)
					this->sprite.setTexture(this->main3);

				else
					this->sprite.setTexture(this->main1);

				break;
			}
			break;
		case sf::Event::MouseButtonPressed:
			switch (state)
			{
			case 1:
				if (this->sfmlEvent.mouseButton.x >= 587 && this->sfmlEvent.mouseButton.x <= 691 &&
					this->sfmlEvent.mouseButton.y >= 285 && this->sfmlEvent.mouseButton.y <= 431)
				{
					if (this->sfmlEvent.mouseButton.button == sf::Mouse::Left)
					{
						//cout << endl << "Click!";
						this->sprite.setTexture(this->main1);
						this->state = 2;
					}
				}
				break;
			case 2:
				if (this->sfmlEvent.mouseButton.x >= 464 && this->sfmlEvent.mouseButton.x <= 815 &&
					this->sfmlEvent.mouseButton.y >= 315 && this->sfmlEvent.mouseButton.y <= 410)
				{
					if (this->sfmlEvent.mouseButton.button == sf::Mouse::Left)
					{
						//cout << endl << "Click!";
						this->state = 3;
						this->menuWindow->close();
					}
				}
				else if (this->sfmlEvent.mouseButton.x >= 464 && this->sfmlEvent.mouseButton.x <= 815 &&
					this->sfmlEvent.mouseButton.y >= 468 && this->sfmlEvent.mouseButton.y <= 560)
				{
					if (this->sfmlEvent.mouseButton.button == sf::Mouse::Left)
					{
						//cout << endl << "Click!";
						this->state = 4;
						this->menuWindow->close();
					}
				}
				break;
			}
			break;
		}

	}
}

int Menu::getState()
{
	return state;
}

void Menu::update()
{
	this->pollEvents();
}

void Menu::render()
{
	this->menuWindow->clear();
	this->menuWindow->draw(this->sprite);
	this->menuWindow->display();
}
