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

void Player::updateLasers(float dt) {

	for (int i = 0; i < lasers.size(); i++) {
		lasers.at(i)->update(dt);

		if (lasers.at(i)->getPosition().y < 0) {
			delete lasers.at(i);
			lasers.erase(lasers.begin() + i);
			i--;
		}
	}

	

}
void Player::draw() {

	GameObject::draw();

	for (int i = 0; i < lasers.size(); i++) {
		lasers.at(i)->draw();
	}
}

void Player::applyConstraints(float & posX, float & posY) {

	sf::Vector2u size = window.getSize();


	maxX = size.x - width/2;
	minX = width/2;
	maxY = size.y - height/2;
	minY = size.y - height/2 - 100;

	if (posX > maxX)
		posX = maxX;
	else if (posX < minX)
		posX = minX;

	if (posY > maxY)
		posY = maxY;
	else if (posY < minY)
		posY = minY;

}

void Player::shoot() {

	sf::Vector2f position = getPosition();
	
	Laser * left = new Laser(window, position.x - width / 2, position.y - height / 2);
	left->loadAnimatedSprite("laser.png", 32, 4, 20);
	left->setScale(1, 2);
	left->setPosition(position.x - width / 2, position.y - height/2);

	Laser * right = new Laser(window, position.x + width / 2, position.y - height / 2);
	right->loadAnimatedSprite("laser.png", 32, 4, 20);
	right->setScale(1, 2);
	right->setPosition(position.x + width / 2, position.y - height/2);

	lasers.push_back(left);
	lasers.push_back(right);
}

void Player::update(sf::Vector2f input, float dt, bool isFiring) {
	move(input, dt);
	updateLasers(dt);

	if (isFiring) {
		shoot();
	}

	//printf("%i\n", score);
}
