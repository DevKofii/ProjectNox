#include "Menu.h"

void Menu::initVars()
{
}

void Menu::initWindow()
{
}

Menu::Menu()
{
	this->initVars();
	this->initWindow();
}

Menu::~Menu()
{
}

const bool Menu::getWindowIsOpen() const
{
	return this->menuWindow->isOpen();;
}

void Menu::pollEvents()
{
}

void Menu::update()
{
}

void Menu::render()
{
}
