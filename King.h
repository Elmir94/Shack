#pragma once

#include "Piece.h"

class King:public Piece
{
private:

public:
	King(team pieceTeam);
	~King();

	void move();
	void draw(sf::RenderWindow &window);
	void setDefaultPosition(int x, int y);
};

