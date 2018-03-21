#pragma once

#include "Piece.h"

class Queen:public Piece
{
private:

public:
	Queen(team pieceTeam);
	~Queen();


	void move();
	void draw(sf::RenderWindow &window);
	void setDefaultPosition(int x, int y);
	Queen* clone() const;
};

