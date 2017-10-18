#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class ScrollingBackground
{
public:
	ScrollingBackground(sf::RenderWindow & w, std::string dir, float speed);
	~ScrollingBackground();
	
	void update(float dt);
	void draw();

private:
	sf::RenderWindow & window;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Sprite sprite2;
	float speed;
	sf::Color lowHPColor;
};

