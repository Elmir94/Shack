#pragma once

#include "Pawn.h"
#include "Piece.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"
#include "Rules.h"


class Board
{
private:
	sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(512, 512), "ReeL Schack");
	sf::RectangleShape boardTiles[64];
	sf::Texture boardTileTextureDark;
	sf::Texture boardTileTextureLight;
	Piece *allPieces[32];

public:
	Board();
	~Board();
	
	void initializeBoard();
	void tileColorGen();
	void initPieceArray();
	void defaultPosPieces();
	void loop();
	void defaultPosTiles();
	
	
};


