#include "GameObject.h"



GameObject::GameObject(sf::RenderWindow & w) : window(w)
{
	isLoaded = false;
}


GameObject::~GameObject()
{
}

void GameObject::loadSprite(std::string dir) {
	
	if (!texture.loadFromFile(dir)) {
		isLoaded = false;
	}
	else {
		GameObject::dir = dir;
		sprite.setTexture(texture, true);
		isLoaded = true;
		animated = false;

		width = sprite.getTextureRect().width;
		height = sprite.getTextureRect().height;

		sprite.setOrigin(sprite.getTextureRect().width / 2, sprite.getTextureRect().height / 2);

	}
}
void GameObject::loadAnimatedSprite(std::string dir, int frameSize, int numFrames) {
	if (!texture.loadFromFile(dir)) {
		isLoaded = false;
	}
	else {
		GameObject::dir = dir;
		animatedSprite = AnimatedSprite(texture, frameSize, numFrames);
		isLoaded = true;
		animated = true;

		width = frameSize;
		height = frameSize;

	}
}
void GameObject::loadAnimatedSprite(std::string dir, int frameSize, int numFrames, float autoPlaySpeed) {
	if (!texture.loadFromFile(dir)) {
		isLoaded = false;
	}
	else {
		GameObject::dir = dir;
		animatedSprite = AnimatedSprite(texture, frameSize, numFrames);
		isLoaded = true;
		animated = true;

		width = frameSize;
		height = frameSize;
	}

	animatedSprite.play(autoPlaySpeed);
}

void GameObject::playAnimatedSprite(float speed, int numCycles) {
	animatedSprite.play(speed, numCycles);
}
void GameObject::playAnimatedSprite(float speed) {
	animatedSprite.play(speed);
}

void GameObject::setSpriteColor(int r, int g, int b, int a) {
	if (animated) {
		animatedSprite.setColor(r, g, b, a);
	}
	else {
		sprite.setColor(sf::Color(r, g, b, a));
	}
}

void GameObject::draw() {

	if (isLoaded) {
		if (animated) 
			animatedSprite.draw(window);
		else
			window.draw(sprite);
	}
}

void GameObject::setPosition(float x, float y) {
	
	if (isLoaded) {
		if (animated)
			animatedSprite.setPosition(x, y);
		else
			sprite.setPosition(x, y);
	}

}

sf::Vector2f GameObject::getPosition() {

	if (isLoaded) {
		if (animated)
			return animatedSprite.getPosition();
		else
			return sprite.getPosition();
		
	}
}

void GameObject::rotate(float degrees) {

	if (isLoaded) {
		if (animated)
			animatedSprite.rotate(degrees);
		else 
			sprite.rotate(degrees);
	}
}

void GameObject::setScale(int x, int y) {
	
	if (isLoaded) {
		if (animated)
			animatedSprite.setScale(x, y);
		else
			sprite.setScale(x, y);

		width *= x;
		height *= y;

		sprite.setOrigin(sprite.getTextureRect().width / 2 * x, sprite.getTextureRect().height / 2 * y);

	}

}

bool GameObject::isColliding(GameObject * g) {

	sf::Vector2f gPos = g->getPosition();
	sf::Vector2f pos = this->getPosition();
	
	

	//dont even try to figure out what's going on here
	if (gPos.x <= pos.x && pos.x <= gPos.x + g->width 
		|| pos.x <= gPos.x && gPos.x <= pos.x + width) {

		if (gPos.y <= pos.y && pos.y <= gPos.y + g->height
			|| pos.y <= gPos.y && gPos.y <= pos.y + height) {

			return true;
		}
	}
	return false;
}
