#include "MainMenu.h"

MainMenu::MenuAction MainMenu::show(sf::RenderWindow & window)
{
	
	sf::Texture texture;
	texture.loadFromFile("mainmenu.png");
	sf::Sprite sprite(texture);

	//set up button coords
	MenuItem playButton;
	playButton.rect.top = 200;
	playButton.rect.left = 140;
	playButton.rect.width = 500 - 140;
	playButton.rect.height = 430 - 200;
	playButton.action = Play;

	MenuItem quitButton;
	quitButton.rect.top = 620;
	quitButton.rect.left = 100;
	quitButton.rect.width = 515 - 100;
	quitButton.rect.height = 790 - 620;
	quitButton.action = Exit;

	items[0] = playButton;
	items[1] = quitButton;

	window.draw(sprite);
	window.display();

	return getMenuResponse(window);
	
}

MainMenu::MenuAction MainMenu::click(int x, int y)
{
	for (MenuItem &item : items) {

		if (item.rect.top < y &&
			item.rect.top + item.rect.height > y &&
			item.rect.left < x &&
			item.rect.left + item.rect.width > x) {

			return item.action;
		}

	}
	
	return Nothing;
}

MainMenu::MenuAction MainMenu::getMenuResponse(sf::RenderWindow & window)
{
	sf::Event event;

	while (true) {

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::MouseButtonPressed) {
				return click(event.mouseButton.x, event.mouseButton.y);
			}
			else if (event.type == sf::Event::Closed) {
				return Exit;
			}
		}
	}
}
