#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player
{
private:
	sf::RectangleShape shape;
	float movementSpeed;
	bool collidedLeft = false;

	void initVariables();
	void initShape();

public:
	Player(float x = 640.f, float y = 360.f);
	virtual ~Player();

	bool getcollisionState_L();
	void setcollisionState_L(bool collidedLeft);
	void updateInput();
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};