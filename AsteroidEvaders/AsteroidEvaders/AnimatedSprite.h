#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>

class AnimatedSprite
{
public:
	AnimatedSprite(sf::Texture & texture, int frameSize, int numFrames);
	AnimatedSprite();
	~AnimatedSprite();

	enum AnimationState {Playing, Stopped};

	void play(float speed);
	void play(float speed, int numCycles);

	void draw(sf::RenderWindow & window);

	void setPosition(float x, float y);
	void rotate(float degrees);
	sf::Vector2f getPosition();
	void setScale(float x, float y);

private:

	AnimationState animationState;

	std::vector<sf::Sprite> sprites;
	sf::Texture texture;
	sf::Sprite currentSprite;
	float currentRotation;
	int currentFrame;
	float frameTime;
	int frameSize;
	int numCycles;
	int currentCycle;
	float currentTime;
	float posX, posY, scaleX, scaleY;

	clock_t t;
};

