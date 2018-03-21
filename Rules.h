#pragma once

#include "Pawn.h"
#include "Piece.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"

class Rules
{
private:

public:
	Rules();
	~Rules();

	bool isMoveOk(float oldXPos,float oldYPos, float newXPos, float newYPos,Piece *ptr[],int pos);
	bool doesEnemyExistPawn(Piece *ptr[],int movingPosX,int movingPosY,int movingPiecePos);
	
};

