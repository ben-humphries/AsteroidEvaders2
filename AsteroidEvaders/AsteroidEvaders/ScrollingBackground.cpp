#include "ScrollingBackground.h"



ScrollingBackground::ScrollingBackground(sf::RenderWindow & w, std::string dir, float scrollSpeed) : window(w)
{

	texture.loadFromFile(dir);
	sprite.setTexture(texture);
	speed = scrollSpeed;

	sprite.setPosition(0, -sprite.getTextureRect().height);

	sprite2.setTexture(texture);
	sprite2.setPosition(0, 0);

	//sprite.setColor(sf::Color::Red);
	//sprite2.setColor(sf::Color::Red);
}


ScrollingBackground::~ScrollingBackground()
{
}

void ScrollingBackground::update(float dt) {
	sprite.setPosition(0, sprite.getPosition().y + speed * dt);

	if (sprite.getPosition().y >= sprite.getTextureRect().height) {
		sprite.setPosition(0, -sprite.getTextureRect().height);
	}
	sprite2.setPosition(0, sprite2.getPosition().y + speed * dt);

	if (sprite2.getPosition().y >= sprite2.getTextureRect().height) {
		sprite2.setPosition(0, -sprite2.getTextureRect().height);
	}
}
void ScrollingBackground::draw() {

	window.draw(sprite);
	window.draw(sprite2);
}
