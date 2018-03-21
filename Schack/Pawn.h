#pragma once

#include "Piece.h"
#include "Pawn.h"

class Pawn:public Piece
{
private:
	
	
	
	

public:
	Pawn(team pieceTeam);
	Pawn();
	~Pawn();

	
	void move();
	void draw(sf::RenderWindow &window);
	void setDefaultPosition(int x, int y);
	
};

