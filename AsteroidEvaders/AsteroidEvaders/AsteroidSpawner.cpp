#include "AsteroidSpawner.h"
#include "Game.h"


AsteroidSpawner::AsteroidSpawner(sf::RenderWindow & window, Player * target) : window(Game::window)
{
	currentSpawnTime = 0;
	windowWidth = Game::window.getSize().x;
	windowHeight = Game::window.getSize().y;
	srand(time(NULL));

	player = target;
}


AsteroidSpawner::~AsteroidSpawner()
{
}

void AsteroidSpawner::update(int playerHealth, int playerScore, float dt) {
	
	float asteroidFrequency = 4 + (float)playerScore / 1000; //1 asteroid per second + another asteroid per second for every 1000 points.
	float percentGreen = 0.1 * (float)playerScore / 10000; //10% green asteroids plus another 10% for each 1000 points.

	if (currentSpawnTime >= 1 / asteroidFrequency) {

		float speed = (((float)rand() / RAND_MAX + 1) * 500);

		Asteroid * a = new Asteroid(Game::window, sf::Vector2f(0, speed));
		a->loadAnimatedSprite("asteroidanimation.png", 64, 4, speed/70);
		a->setPosition((float)rand() / RAND_MAX * Game::window.getSize().x, 0);
		//a->setSpriteColor(0, 255, 0, 255);
		asteroids.push_back(a);

		currentSpawnTime = 0;
	}
	currentSpawnTime += dt;

	//http://bit.ly/2ywljQP -- in case of memory leaks
	//
	for (int i = 0; i < asteroids.size(); i++) {
		asteroids.at(i)->update(dt);

		if (asteroids.at(i)->getPosition().y > Game::window.getSize().y) {
			delete asteroids.at(i);
			asteroids.erase(asteroids.begin() + i);
		}
		else {

			if (asteroids.at(i)->isColliding(player)) {
				delete asteroids.at(i);
				asteroids.erase(asteroids.begin() + i);


			}
			else {

				for (int j = 0; j < player->lasers.size(); j++) {
					if (asteroids.at(i)->isColliding(player->lasers.at(j))) {
						delete asteroids.at(i);
						asteroids.erase(asteroids.begin() + i);

						delete player->lasers.at(j);
						player->lasers.erase(player->lasers.begin() + j);

						player->score += 5;

						break;
					}
				}

			}
		}
	}
	
}

void AsteroidSpawner::draw() {

	for (int i = 0; i < asteroids.size(); i++) {
		asteroids.at(i)->draw();
	}
}
