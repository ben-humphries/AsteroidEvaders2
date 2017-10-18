#pragma once
#include "GameObject.h"

class Player: public GameObject
{
public:
	Player(sf::RenderWindow & w);
	~Player();

	void move(sf::Vector2f input, float dt);

private:

	clock_t t;
	float currentTime;
	float speed;
	
	float maxX, minX, maxY, minY;

	void applyConstraints(float & posX, float & posY);
};

