#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class SplashScreen
{
public:
	SplashScreen(std::string& dir);
	void show();

private:
	sf::RenderWindow window;
	sf::Sprite splashScreen;
	sf::Texture texture;

};

