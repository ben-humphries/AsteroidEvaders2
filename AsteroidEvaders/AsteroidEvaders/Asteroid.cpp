#include "Asteroid.h"



Asteroid::Asteroid(sf::RenderWindow & window, sf::Vector2f speed) : GameObject(window)
{
	Asteroid::speed = speed;
}


Asteroid::~Asteroid()
{
}

void Asteroid::update(float dt) {

	sf::Vector2f currentPos = getPosition();

	setPosition(currentPos.x + speed.x * dt, currentPos.y + speed.y * dt);
	rotate(speed.y * dt);

}

bool Asteroid::checkCollision(GameObject target) {
	
	if (isColliding(target)) {
		return true;
	}

	return false;
}
