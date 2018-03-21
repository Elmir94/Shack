#pragma once

#include "Piece.h"

class Rook:public Piece
{
private:

public:
	Rook(team pieceTeam);
	~Rook();

	void move();
	void draw(sf::RenderWindow &window);
	void setDefaultPosition(int x, int y);
};

