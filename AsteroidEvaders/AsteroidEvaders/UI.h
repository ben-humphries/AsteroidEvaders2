#pragma once
#include <SFML/Graphics.hpp>


class UI
{
public:
	UI(sf::RenderWindow & window);
	~UI();

	void setScore(int score);
	void draw();

private:

	sf::RenderWindow & window;

	sf::Font font;
	sf::Text score;
	int currentScore;
};

