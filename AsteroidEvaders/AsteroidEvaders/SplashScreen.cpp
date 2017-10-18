#include "SplashScreen.h"


SplashScreen::SplashScreen(std::string& dir){

	if (!SplashScreen::texture.loadFromFile(dir)) {
		printf("it didnt work you moron");
	}
	SplashScreen::splashScreen.setTexture(SplashScreen::texture, true);
	
	int width = SplashScreen::splashScreen.getGlobalBounds().width;
	int height = SplashScreen::splashScreen.getGlobalBounds().height;


	SplashScreen::window.create(sf::VideoMode(width, height, 32), "Asteroid Evaders", sf::Style::None);
}

void SplashScreen::show() {

	SplashScreen::window.clear();
	SplashScreen::window.draw(SplashScreen::splashScreen);
	SplashScreen::window.display();

	sf::Event event;
	while (true){
		while (SplashScreen::window.pollEvent(event)){

			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed){

				SplashScreen::window.close();
				return;
				}
			}
		}
}

