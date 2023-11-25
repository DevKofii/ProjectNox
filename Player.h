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
	bool collidedLeft = false, collidedRight = false, collidedTop = false, collidedDown = false, collidePoint = false;
	int updateNum;

	void initVariables();
	void initShape();

public:
	Player(float x = 640.f, float y = 360.f);
	virtual ~Player();

	bool getcollisionState_L();
	bool getcollisionState_R();
	bool getcollisionState_T();
	bool getcollisionState_D();

	bool getcollisionPoint();

	void setcollisionState_L(bool collidedLeft);
	void setcollisionState_R(bool collidedRight);
	void setcollisionState_T(bool collidedTop);
	void setcollisionState_D(bool collidedDown);

	void setcollisionPoint(bool collidePoint);

	void teleport_left(bool collidedLeft);
	void teleport_right(bool collidedRight);
	void teleport_top(bool collidedTop);
	void teleport_down(bool collidedDown);

	sf::FloatRect collisionTest();

	void updatePlayer(int updateNum);

	void updateInput();
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};