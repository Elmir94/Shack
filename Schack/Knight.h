#pragma once

#include "Piece.h"
class Knight:public Piece
{
private:

public:
	Knight(team pieceTeam);
	~Knight();

	void move();
	void draw(sf::RenderWindow &window);
	void setDefaultPosition(int x, int y);
};

