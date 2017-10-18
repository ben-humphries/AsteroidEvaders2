#include "Game.h"
#include "SplashScreen.h"

std::string splashScreenDirectory = "splashscreen.png";

void showSplashScreen();

int main()
{
	showSplashScreen();
	Game::Start();

	return 0;
}

void showSplashScreen() {
	SplashScreen s(splashScreenDirectory);
	s.show();
}