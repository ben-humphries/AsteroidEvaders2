#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Game
{

public:
	static void Start();

private:
	static void Update();
	static void ShowMenu();

	static clock_t t;

	static sf::Vector2f GetInput();

	enum GameState {Uninitialized, Menu, Running, Paused, Exiting};

	static GameState gameState;
	static sf::RenderWindow window;

	static int width;
	static int height;

};

