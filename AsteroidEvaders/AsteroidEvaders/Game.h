#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Light.h"

class Game
{

public:
	static void Start();

	static sf::RenderWindow window;

	static std::vector<Light> lights;

private:
	static void Update();
	static void ShowMenu();

	static clock_t t;

	static sf::Vector2f GetInput();

	enum GameState {Uninitialized, Menu, Running, Paused, Exiting};

	static GameState gameState;


	static int width;
	static int height;

};

