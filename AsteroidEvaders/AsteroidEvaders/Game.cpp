#include "Game.h"
#include "MainMenu.h"
#include "GameObject.h"
#include "Player.h"
#include "AnimatedSprite.h"
#include "ScrollingBackground.h"
#include "AsteroidSpawner.h"
#include "Laser.h"

sf::RenderWindow Game::window;
Game::GameState Game::gameState = Uninitialized;

int Game::width = 735;
int Game::height = 980;

clock_t Game::t;

ScrollingBackground * background;
ScrollingBackground * background2;
Player * player;
AsteroidSpawner * spawner;
Laser * laser;

void Game::Start(void) {

	t = clock();

	if (gameState != Running) 
		gameState = Menu;
	
	window.create(sf::VideoMode(width, height, 32), "Asteroid Evaders", sf::Style::Close);

	background = new ScrollingBackground(window, "background.png", 200);
	background2 = new ScrollingBackground(window, "background2.png", 250);
	
	player = new Player(window);
	player->loadAnimatedSprite("spaceship.png", 64, 2, 10);
	player->setPosition(367.5-16, 880);

	spawner = new AsteroidSpawner(window);

	laser = new Laser(window);
	laser->loadAnimatedSprite("laser.png", 32, 4, 20);
	laser->setScale(1, 2);
	laser->setPosition(300, 980);

	while (gameState != Exiting) {
		Game::Update();
	}

	window.close();
}

void Game::Update() {

	float dt = ((float)(clock() - t)) / CLOCKS_PER_SEC;
	t = clock();

	sf::Event currentEvent;
	while (window.pollEvent(currentEvent))
	{

		switch (gameState)
		{
			case Game::Running:
			{

				if (currentEvent.type == sf::Event::Closed)
				{
					gameState = Game::Exiting;
				}
				break;
			}
			case Game::Menu:
			{
				ShowMenu();
				break;
			}
		}
	}
	window.clear(sf::Color(0, 0, 0));

	background->update(dt);
	background2->update(dt);
	player->move(GetInput(), dt);
	spawner->update(3, 100, dt);
	laser->update(dt);

	background->draw();
	player->draw();
	background2->draw();
	spawner->draw();
	laser->draw();

	window.display();

}

void Game::ShowMenu() {

	MainMenu mainMenu;
	MainMenu::MenuAction action = mainMenu.show(window);

	switch (action) {

	case MainMenu::Exit:
		gameState = Exiting;
		break;

	case MainMenu::Play:
		gameState = Running;
		break;
	}
}

sf::Vector2f Game::GetInput() {

	sf::Vector2f input = { 0,0 };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
		input.x -= 1;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
		input.x += 1;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
		input.y -= 1;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
		input.y += 1;
	

	return input;
}