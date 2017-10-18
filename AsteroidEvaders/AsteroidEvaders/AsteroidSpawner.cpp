#include "AsteroidSpawner.h"



AsteroidSpawner::AsteroidSpawner(sf::RenderWindow & window) : window(window)
{
	currentSpawnTime = 0;
	windowWidth = window.getSize().x;
	windowHeight = window.getSize().y;
	srand(time(NULL));
}


AsteroidSpawner::~AsteroidSpawner()
{
}

void AsteroidSpawner::update(int playerHealth, int playerScore, float dt) {
	
	float asteroidFrequency = 100 + (float)playerScore / 1000; //1 asteroid per second + another asteroid per second for every 1000 points.
	float percentGreen = 0.1 * (float)playerScore / 10000; //10% green asteroids plus another 10% for each 1000 points.

	if (currentSpawnTime >= 1 / asteroidFrequency) {
		Asteroid * a = new Asteroid(window, sf::Vector2f(0, ((float)rand() / RAND_MAX + 1) * 300));
		a->loadSprite("asteroid.png");
		a->setPosition((float)rand() / RAND_MAX * windowWidth, 0);

		asteroids.push_back(a);

		currentSpawnTime = 0;
	}
	currentSpawnTime += dt;

	//http://bit.ly/2ywljQP -- in case of memory leaks
	//
	for (int i = 0; i < asteroids.size(); i++) {
		asteroids.at(i)->update(dt);

		if (asteroids.at(i)->getPosition().y > windowHeight) {
			delete asteroids.at(i);
			asteroids.erase(asteroids.begin() + i);
		}
	}
	
}

void AsteroidSpawner::draw() {
	for (int i = 0; i < asteroids.size(); i++) {
		asteroids.at(i)->draw();
	}
}
