#pragma once

#include "board.h"

class Game
{
public:
	sf::RenderWindow *window;
	Board *board;


public:
	Game();
	void loop();
	~Game();
};

