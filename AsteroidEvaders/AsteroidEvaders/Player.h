#pragma once
#include "GameObject.h"
#include "Laser.h"

class Player: public GameObject
{
public:
	Player(sf::RenderWindow & w);
	~Player();

	void update(sf::Vector2f input, float dt, bool isFiring);
	void draw();

	std::vector<Laser*> lasers;

	int score;


private:

	clock_t t;
	float currentTime;
	float speed;
	
	float maxX, minX, maxY, minY;

	void move(sf::Vector2f input, float dt);
	void updateLasers(float dt);
	void applyConstraints(float & posX, float & posY);
	void shoot();
};

