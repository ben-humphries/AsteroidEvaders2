#include "UI.h"



UI::UI(sf::RenderWindow & window) : window(window)
{	

	if (!UI::font.loadFromFile("font.ttf")) {
		printf("could not load font");
	}

	score.setFont(font);
	score.setString("Score: 0");
	score.setCharacterSize(15);
	score.setPosition(window.getSize().x - 120, 10);
	currentScore = 0;
}


UI::~UI()
{
}

void UI::setScore(int score) {

	currentScore += score;

	std::string scoreText = "Score: "; scoreText += std::to_string(score);


	if (UI::score.getString().getSize() < scoreText.length()) {
		UI::score.setPosition(UI::score.getPosition().x - 15, UI::score.getPosition().y);
	}

	UI::score.setString(scoreText);
}

void UI::draw() {

	window.draw(UI::score);
}
