#include "AnimatedSprite.h"



AnimatedSprite::AnimatedSprite(sf::Texture & texture, int frameSize, int numFrames)
{
	animationState = Stopped;

	sprites = {};

	int currentPos = 0;
	for (int i = 0; i < numFrames; i++) {
		sf::Sprite sprite;

		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(i*frameSize, 0, frameSize, frameSize));

		sprites.push_back(sprite);
	}

	AnimatedSprite::frameSize = frameSize;
	
	currentSprite = sprites.at(0);
	currentFrame = -1;
	currentCycle = 1;

	setScale(1, 1);


	currentSprite.setOrigin(frameSize / 2 * scaleX, frameSize / 2 * scaleY);
	currentRotation = 0;


}
AnimatedSprite::AnimatedSprite()
{
}

AnimatedSprite::~AnimatedSprite()
{
}
void AnimatedSprite::rotate(float degrees) {
	currentSprite.rotate(degrees);
	//todo: make it rotate around the center and update the animated sprite rotation when it switches sprites
}

void AnimatedSprite::play(float speed)
{
	t = clock();
	animationState = Playing;
	frameTime = 1 / speed;
	numCycles = -1;
	currentTime = 0;
}

void AnimatedSprite::play(float speed, int numCycles)
{
	t = clock();
	animationState = Playing;
	frameTime = 1 / speed;
	AnimatedSprite::numCycles = numCycles;
	currentTime = 0;
}

void AnimatedSprite::setPosition(float x, float y) {
	posX = x;
	posY = y;

	currentSprite.setPosition(x, y);
}
sf::Vector2f AnimatedSprite::getPosition() {
	return sf::Vector2f(posX, posY);
}
void AnimatedSprite::setScale(float x, float y) {
	scaleX = x;
	scaleY = y;

	currentSprite.setScale(x, y);
}
void AnimatedSprite::draw(sf::RenderWindow & window) {

	if (animationState == Playing) {

		float dt = ((float)(clock()-t)) / CLOCKS_PER_SEC;
		t = clock();
		currentTime += dt;

		if (currentTime >= frameTime) {
			currentTime = 0;
			if (currentFrame+1 >= sprites.size()) {
				currentFrame = 0;

				if (currentCycle+1 > numCycles && numCycles != -1) {
					animationState = Stopped;
					return;
				}
				else {
					currentCycle++;
				}
			}
			else {
				currentFrame++;
			}
			currentRotation = currentSprite.getRotation();

			currentSprite = sprites.at(currentFrame);
			currentSprite.setPosition(posX, posY);
			currentSprite.setScale(scaleX, scaleY);

			currentSprite.setOrigin(frameSize / 2 * scaleX, frameSize / 2 * scaleY);
			currentSprite.setRotation(currentRotation);
		}
	}
	
	window.draw(currentSprite);
}

