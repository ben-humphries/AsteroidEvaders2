#pragma once
#include "GameObject.h"
class Asteroid : public GameObject
{
public:
	Asteroid(sf::RenderWindow & window, sf::Vector2f speed);
	~Asteroid();

	void update(float dt);

private:

	sf::Vector2f speed;
};

