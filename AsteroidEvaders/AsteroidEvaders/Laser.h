#pragma once
#include "GameObject.h"
#include "Light.h"

class Laser : public GameObject
{
public:
	Laser(sf::RenderWindow & window, float posX, float posY);
	~Laser();

	void update(float dt);

	Light light;

};

