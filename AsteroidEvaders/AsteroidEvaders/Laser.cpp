#include "Laser.h"
#include "Game.h"


Laser::Laser(sf::RenderWindow & window, float posX, float posY) : GameObject(window), light(sf::Vector2f(posX, posY - height / 2), sf::Vector2f(1.0f, 2.0f), sf::Color(200, 0, 0, 255))
{

}


Laser::~Laser()
{
}

void Laser::update(float dt) {

	sf::Vector2f currentPos = getPosition();
	setPosition(currentPos.x + 0 * dt, currentPos.y + -600 * dt);

	light.setPosition(currentPos.x, currentPos.y);
	Game::lights.push_back(Light(sf::Vector2f(getPosition().x, getPosition().y - height/2), sf::Vector2f(0.5f, 1.0f), sf::Color(255, 0, 0, 255)));


}