#include "deps/tinyxml2.h"
#include "Game.h"
#include "Consts.h"

using namespace tinyxml2;

Game* game = nullptr;

int main(int argc, char* argv[]) {

	game = new Game(Consts::SCREEN_WIDTH, Consts::SCREEN_HEIGHT);

	game->init();

	while (game->running()) {
		
		game->handleEvents();
		game->Update();
		game->render();

	}

	game->clean();

	return 0;
}