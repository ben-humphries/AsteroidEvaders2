#pragma once
#include <vector>
#include "Asteroid.h"
#include "SFML\Graphics.hpp"

class AsteroidSpawner
{
public:
	AsteroidSpawner(sf::RenderWindow & window);
	~AsteroidSpawner();

	void update(int playerHealth, int playerScore, float dt);
	void draw();

	std::vector<Asteroid*> asteroids;
	sf::RenderWindow & window;
	float windowWidth, windowHeight;

	float currentSpawnTime;
};

