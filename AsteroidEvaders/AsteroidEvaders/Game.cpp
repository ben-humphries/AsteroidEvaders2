#include "Game.h"
#include "MainMenu.h"
#include "GameObject.h"
#include "Player.h"
#include "AnimatedSprite.h"
#include "ScrollingBackground.h"
#include "AsteroidSpawner.h"
#include "Laser.h"
#include "UI.h"

sf::RenderWindow Game::window;
std::vector<Light> Game::lights;
Game::GameState Game::gameState = Uninitialized;

int Game::width = 600;
int Game::height = 980;

clock_t Game::t;

ScrollingBackground * background;
ScrollingBackground * background2;
Player * player;
AsteroidSpawner * spawner;

sf::Texture lightTexture;
sf::Sprite light;

sf::RenderTexture lightMapTexture;
sf::Sprite lightMap;

sf::RenderTexture darknessTexture;
sf::Sprite darknessSprite;


UI * ui;

void Game::Start(void) {

	t = clock();

	if (gameState != Running)
		gameState = Menu;

	window.create(sf::VideoMode(width, height, 32), "Asteroid Evaders", sf::Style::Close);
	window.setKeyRepeatEnabled(false);

	background = new ScrollingBackground(window, "background.png", 200);
	background2 = new ScrollingBackground(window, "background2.png", 250);


	player = new Player(window);

	player->loadAnimatedSprite("spaceship.png", 64, 2, 10);
	player->setPosition(367.5 - 16, 880);


	spawner = new AsteroidSpawner(window, player);

	lightMapTexture.create(Game::width, Game::height);
	lightMap.setTexture(lightMapTexture.getTexture());

	darknessTexture.create(Game::width, Game::height);
	darknessSprite.setTexture(darknessTexture.getTexture());
	darknessTexture.clear(sf::Color(200, 200, 200));

	lightTexture.loadFromFile("light.png");

	light.setTexture(lightTexture);
	light.setTextureRect(sf::IntRect(0, 0, 64, 64));
	light.setOrigin(32, 32);

	ui = new UI(window);

	while (gameState != Exiting) {
		Game::Update();
	}

	window.close();
}

void Game::Update() {

	float dt = ((float)(clock() - t)) / CLOCKS_PER_SEC;
	t = clock();

	bool isFiring = false;

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
			else if (currentEvent.type == sf::Event::KeyPressed) {
				if (currentEvent.key.code == sf::Keyboard::Space) {
					isFiring = true;
				}
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
	lightMapTexture.clear(sf::Color(0, 0, 0));
	Game::lights.clear();

	background->update(dt);
	background2->update(dt);
	spawner->update(3, 100, dt);

	player->update(GetInput(), dt, isFiring);

	ui->setScore(player->score);

	for (int i = 0; i < Game::lights.size(); i++) {

		light.setScale(lights[i].scale);
		light.setPosition(lights[i].pos);
		light.setColor(lights[i].color);

		lightMapTexture.draw(light, sf::BlendAdd);

	}
	lightMapTexture.display();

	background->draw();
	background2->draw();
	player->draw();
	spawner->draw();

	lightMap.setTextureRect(sf::IntRect(0, 0, Game::width, Game::height));
	lightMap.setPosition(0, 0);
	window.draw(darknessSprite, sf::BlendMultiply);
	window.draw(lightMap, sf::BlendAdd);

	ui->draw();

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