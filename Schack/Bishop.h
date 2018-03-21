#pragma once

#include "Piece.h"
class Bishop:public Piece
{
private:

public:
	Bishop(team pieceTeam);
	~Bishop();

	void move();
	void draw(sf::RenderWindow &window);
	void setDefaultPosition(int x, int y);
	virtual Bishop* clone() const;
};

