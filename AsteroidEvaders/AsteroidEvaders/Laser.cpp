#include "Laser.h"



Laser::Laser(sf::RenderWindow & window) : GameObject(window)
{
}


Laser::~Laser()
{
}

void Laser::update(float dt) {

	sf::Vector2f currentPos = getPosition();

	if (currentPos.y <= 100) {
		//delete this;
		return;
	}

	setPosition(currentPos.x + 0 * dt, currentPos.y + -200 * dt);


}