#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"

class GameObject
{
public:
	GameObject(sf::RenderWindow & w);
	virtual ~GameObject();

	virtual void loadSprite(std::string dir);

	virtual void loadAnimatedSprite(std::string dir, int frameSize, int numFrames);
	virtual void loadAnimatedSprite(std::string dir, int frameSize, int numFrames, float autoPlaySpeed);
	virtual void playAnimatedSprite(float speed, int numCycles);
	virtual void playAnimatedSprite(float speed);

	virtual void draw();
	virtual void setPosition(float x, float y);
	virtual void rotate(float degrees);
	virtual void setScale(int x, int y);
	virtual bool isColliding(GameObject g);
	virtual sf::Vector2f getPosition();


protected:
	sf::RenderWindow & window;
	float width, height;


private:
	std::string dir;
	sf::Texture texture;
	sf::Sprite sprite;
	AnimatedSprite animatedSprite;

	bool animated;
	bool isLoaded;
};

