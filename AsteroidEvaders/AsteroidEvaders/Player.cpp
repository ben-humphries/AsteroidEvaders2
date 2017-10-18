#include "Player.h"



Player::Player(sf::RenderWindow & w) : GameObject(w)
{
	t = clock();
	speed = 500;

}


Player::~Player()
{
}

void Player::move(sf::Vector2f input, float dt) {

	if (input.x == 0 && input.y == 0)
		return;

	if (input.x != 0 && input.y != 0) {

		input.x /= sqrt(2);
		input.y /= sqrt(2);
	}

	float posX = getPosition().x + input.x * speed * dt;
	float posY = getPosition().y + input.y * speed * dt;

	applyConstraints(posX, posY);

	setPosition(posX, posY);
}

void Player::applyConstraints(float & posX, float & posY) {

	sf::Vector2u size = window.getSize();

	maxX = size.x - width/2;
	minX = width/2;
	maxY = size.y - height;
	minY = size.y - height - 100;

	if (posX > maxX)
		posX = maxX;
	else if (posX < minX)
		posX = minX;

	if (posY > maxY)
		posY = maxY;
	else if (posY < minY)
		posY = minY;

}
