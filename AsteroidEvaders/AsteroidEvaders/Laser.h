#pragma once
#include "GameObject.h"
class Laser : public GameObject
{
public:
	Laser(sf::RenderWindow & window);
	~Laser();

	void update(float dt);


};

