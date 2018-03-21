#include "stdafx.h"
#include "Rules.h"


Rules::Rules()
{
}


Rules::~Rules()
{
}

bool Rules::isMoveOk(float oldXPos, float oldYPos, float newXPos, float newYPos, Piece *ptr[], int pos,int moveCounter)
{
	float dx = oldXPos - newXPos;
	float dy = oldYPos - newYPos;
	bool moveOk = false;
	int remove = 0;
	std::string direction;

	if (dynamic_cast<Pawn*>(ptr[pos]))
	{
		if (dy >= -128 && dy <= 128 && ptr[pos]->getIsMoved() == false)
		{
			if (dx != 0)
			{
				moveOk = false;
			}
			else if(dx == 0)
			{
				moveOk = true;
				ptr[pos]->setMoved();
			}
			
		}
		if (dy >= -64 && dy <= 64 && dy != 0)
		{

			if (dx >= -64 && dx <= 64)
			{
				if (dx == 0 || doesEnemyExistPawn(ptr, newXPos, newYPos, pos) == true)
					moveOk = true;
			}
			if (ptr[pos]->getType() == -1 && dy < 0)
			{
				moveOk = false;
			}
			if (ptr[pos]->getType() == 1 && dy > 0)
			{
				moveOk = false;
			}
			if (dx == 0 && dy != 0 && doesEnemyExistPawn(ptr, newXPos, newYPos, pos) == true)
			{
				moveOk = false;
			}

		}
		

		for (int i = 0; i < 32; i++)
		{
			if (i != pos)
			{
				if (ptr[i]->getSprite().getPosition().x == newXPos && ptr[i]->getSprite().getPosition().y == newYPos)
				{

					if (ptr[i]->getType() == ptr[pos]->getType())
					{
						moveOk = false;
					}
					
					float enemyPosForBlackX = ptr[pos]->getSprite().getPosition().x;
					float enemyPosForBlackY = ptr[pos]->getSprite().getPosition().y+64;
					if (dx == 0 && doesEnemyExistPawn(ptr,( enemyPosForBlackX),(enemyPosForBlackY), pos) == true)
					{
						moveOk = false;
					}
					float enemyPosForWhiteX = ptr[pos]->getSprite().getPosition().x;
					float enemyPosForWhiteY = ptr[pos]->getSprite().getPosition().y - 64;
					if (dx == 0 && doesEnemyExistPawn(ptr, (enemyPosForWhiteX), (enemyPosForWhiteY), pos) == true)
					{
						moveOk = false;
					}
					if (ptr[pos]->getSprite().getPosition().y == 448 && ptr[pos]->getType() == 1&& moveOk == true)
					{
						int pawnPosX = ptr[pos]->getSprite().getPosition().x;
						int pawnPosY = ptr[pos]->getSprite().getPosition().y;

						ptr[pos] = new Queen(BLACK);
						ptr[pos]->getSprite().setPosition(pawnPosX, pawnPosY);
					}
					if (ptr[pos]->getSprite().getPosition().y == 0 && ptr[pos]->getType() == -1 && moveOk == true)
					{
						int pawnPosX = ptr[pos]->getSprite().getPosition().x;
						int pawnPosY = ptr[pos]->getSprite().getPosition().y;

						ptr[pos] = new Queen(WHITE);
						ptr[pos]->getSprite().setPosition(pawnPosX, pawnPosY);
					}
					if (moveOk == true && isTurnOk(ptr, moveCounter, pos) == true)
					{
						ptr[i]->getSprite().setPosition(1000, 1000);
					}
					
					
				}
			}
			
		}
		
		
		std::cout <<"dx "<< dx << std::endl;
		std::cout <<"dy " <<dy << std::endl;
		std::cout << "true/false " << moveOk << std::endl;
			
	}

	if (dynamic_cast<Knight*>(ptr[pos]))
	{
		if (dx == 64 || dx == -64)
		{
			if (dy == 128 || dy == -128)
			{
				moveOk = true;
			}
		}
		if (dx == 128 || dx == -128)
		{
			if (dy == 64 || dy == -64)
			{
				moveOk = true;
			}
		}
		for (int i = 0; i < 32; i++)
		{
			if (i != pos)
			{
				if (ptr[i]->getSprite().getPosition().x == newXPos && ptr[i]->getSprite().getPosition().y == newYPos)
				{

					if (ptr[i]->getType() == ptr[pos]->getType())
					{
						moveOk = false;
					}
					if (moveOk == true && isTurnOk(ptr, moveCounter, pos) == true)
					{
						ptr[i]->getSprite().setPosition(1000, 1000);
					}


				}
			}
		}
		std::cout << "dx " << dx << std::endl;
		std::cout << "dy " << dy << std::endl;
		std::cout << "true/false " << moveOk << std::endl;
	}

	if (dynamic_cast<Bishop*>(ptr[pos]))
	{
		if (dx < 0 && dy < 0)
		{
			direction = "RD";
		}
		if (dx < 0 && dy > 0)
		{
			direction = "RU";
		}
		if (dx > 0 && dy > 0)
		{
			direction = "LU";
		}
		if (dx > 0 && dy <0)
		{
			direction = "LD";
		}
		int squaresMoved = (abs(dx) / 64);
		if (dx <= -64 || dx >= 64)
		{
			if (dy >= 64 || dy <= -64)
			{
				if (dx/dy ==1 || dx/dy == -1 )
				{
					moveOk = true;
				}
				
			}
		}
		for (int i = 0; i < squaresMoved; i++)
		{
			for (int k = 0; k < 32; k++)
			{
				if (k != pos)
				{
					if (direction == "LU")
					{
						if (ptr[k]->getSprite().getPosition().x == oldXPos - (i * 64) && ptr[k]->getSprite().getPosition().y == oldYPos - (i * 64))
						{
							moveOk = false;
							std::cout << "Direction: " << direction << std::endl;
						}
					}
					if (direction == "LD")
					{
						if (ptr[k]->getSprite().getPosition().x == oldXPos - (i * 64) && ptr[k]->getSprite().getPosition().y == oldYPos + (i * 64))
						{
							moveOk = false;
							std::cout << "Direction: " << direction << std::endl;
						}
					}
					if (direction == "RU")
					{
						if (ptr[k]->getSprite().getPosition().x == oldXPos + (i * 64) && ptr[k]->getSprite().getPosition().y == oldYPos - (i * 64))
						{
							moveOk = false;
							std::cout << "Direction: " << direction << std::endl;
						}
					}
					if (direction == "RD")
					{
						if (ptr[k]->getSprite().getPosition().x == oldXPos + (i * 64) && ptr[k]->getSprite().getPosition().y == oldYPos + (i * 64))
						{
							moveOk = false;
							std::cout << "Direction: " << direction << std::endl;
						}
					}
					
				}
				
			}
		}
		
		for (int i = 0; i < 32; i++)
		{
			if (i != pos)
			{
				if (ptr[i]->getSprite().getPosition().x == newXPos && ptr[i]->getSprite().getPosition().y == newYPos)
				{

					if (ptr[i]->getType() == ptr[pos]->getType())
					{
						moveOk = false;
					}
					if (moveOk == true && isTurnOk(ptr, moveCounter, pos) == true)
					{
						ptr[i]->getSprite().setPosition(1000, 1000);
					}


				}
			}
		}
		std::cout << "squares moved: " << squaresMoved << std::endl;
	}
	
	if (dynamic_cast<Rook*>(ptr[pos]))
	{
		if (dx != 0 && dy == 0)
		{
			moveOk = true;
		}
		if (dy != 0 && dx == 0)
		{
			moveOk = true;
		}
       /////DIRECTIONS/////
		if (dx == 0 && dy < 0)
		{
			direction = "D";
		}
		if (dx == 0 && dy > 0)
		{
			direction = "U";
		}
		if (dx > 0 && dy == 0)
		{
			direction = "L";
		}
		if (dx < 0 && dy == 0)
		{
			direction = "R";
		}
		int squaresMoved = 0;
		if (direction == "L" || direction == "R")
		{
			squaresMoved = (abs(dx) / 64);
		}
		if (direction == "U" || direction == "D")
		{
			squaresMoved = (abs(dy) / 64);
		}
			
		
		for (int i = 0; i < squaresMoved; i++)
		{
			for (int k = 0; k < 32; k++)
			{
				if (k != pos)
				{
					if (direction == "U")
					{
						if (ptr[k]->getSprite().getPosition().x == oldXPos  && ptr[k]->getSprite().getPosition().y == oldYPos - (i * 64))
						{
							moveOk = false;
							std::cout << "Direction: " << direction << std::endl;
						}
					}
					if (direction == "D")
					{
						if (ptr[k]->getSprite().getPosition().x == oldXPos  && ptr[k]->getSprite().getPosition().y == oldYPos + (i * 64))
						{
							moveOk = false;
							std::cout << "Direction: " << direction << std::endl;
						}
					}
					if (direction == "L")
					{
						if (ptr[k]->getSprite().getPosition().x == oldXPos - (i * 64) && ptr[k]->getSprite().getPosition().y == oldYPos )
						{
							moveOk = false;
							std::cout << "Direction: " << direction << std::endl;
						}
					}
					if (direction == "R")
					{
						if (ptr[k]->getSprite().getPosition().x == oldXPos + (i * 64) && ptr[k]->getSprite().getPosition().y == oldYPos)
						{
							moveOk = false;
							std::cout << "Direction: " << direction << std::endl;
						}
					}

				}

			}
		}
		for (int i = 0; i < 32; i++)
		{
			if (i != pos)
			{
				if (ptr[i]->getSprite().getPosition().x == newXPos && ptr[i]->getSprite().getPosition().y == newYPos)
				{

					if (ptr[i]->getType() == ptr[pos]->getType())
					{
						moveOk = false;
					}
					if (moveOk == true && isTurnOk(ptr, moveCounter, pos) == true)
					{
						ptr[i]->getSprite().setPosition(1000, 1000);
					}


				}
			}
		}
		std::cout << "squares moved: " << squaresMoved << std::endl;
	}

	if (dynamic_cast<King*>(ptr[pos]))
	{
		if (dx >= -64 && dx <= 64)
		{
			if (dy >= -64 && dy <= 64)
			{
				moveOk = true;
			}
		}
		for (int i = 0; i < 32; i++)
		{
			if (i != pos)
			{
				if (ptr[i]->getSprite().getPosition().x == newXPos && ptr[i]->getSprite().getPosition().y == newYPos)
				{

					if (ptr[i]->getType() == ptr[pos]->getType())
					{
						moveOk = false;
					}
					if (moveOk == true && isTurnOk(ptr, moveCounter, pos) == true)
					{
						ptr[i]->getSprite().setPosition(1000, 1000);
					}


				}
			}
		}
	}

	if (dynamic_cast<Queen*>(ptr[pos]))
	{
		if (dx <= -64 || dx >= 64)
		{
			if (dy >= 64 || dy <= -64)
			{
				if (dx / dy == 1 || dx / dy == -1)
				{
					moveOk = true;
				}

			}
		}
		if (dx != 0 && dy == 0)
		{
			moveOk = true;
		}
		if (dy != 0 && dx == 0)
		{
			moveOk = true;
		}
		if (dx < 0 && dy < 0)
		{
			direction = "RD";
		}
		if (dx < 0 && dy > 0)
		{
			direction = "RU";
		}
		if (dx > 0 && dy > 0)
		{
			direction = "LU";
		}
		if (dx > 0 && dy <0)
		{
			direction = "LD";
		}
		if (dx == 0 && dy < 0)
		{
			direction = "D";
		}
		if (dx == 0 && dy > 0)
		{
			direction = "U";
		}
		if (dx > 0 && dy == 0)
		{
			direction = "L";
		}
		if (dx < 0 && dy == 0)
		{
			direction = "R";
		}


		int squaresMoved = 0;
		if (direction == "L" || direction == "R")
		{
			squaresMoved = (abs(dx) / 64);
		}
		if (direction == "U" || direction == "D")
		{
			squaresMoved = (abs(dy) / 64);
		}
		if (direction == "RD" || direction == "RU" || direction == "LU" || direction == "LD")
		{
			squaresMoved = (abs(dx) / 64);
		}
			
		if (dx <= -64 || dx >= 64)
		{
			if (dy >= 64 || dy <= -64)
			{
				if (dx / dy == 1 || dx / dy == -1)
				{
					moveOk = true;
				}

			}
		}
		for (int i = 0; i < squaresMoved; i++)
		{
			for (int k = 0; k < 32; k++)
			{
				if (k != pos)
				{
					if (direction == "LU")
					{
						if (ptr[k]->getSprite().getPosition().x == oldXPos - (i * 64) && ptr[k]->getSprite().getPosition().y == oldYPos - (i * 64))
						{
							moveOk = false;
							std::cout << "Direction: " << direction << std::endl;
						}
					}
					if (direction == "LD")
					{
						if (ptr[k]->getSprite().getPosition().x == oldXPos - (i * 64) && ptr[k]->getSprite().getPosition().y == oldYPos + (i * 64))
						{
							moveOk = false;
							std::cout << "Direction: " << direction << std::endl;
						}
					}
					if (direction == "RU")
					{
						if (ptr[k]->getSprite().getPosition().x == oldXPos + (i * 64) && ptr[k]->getSprite().getPosition().y == oldYPos - (i * 64))
						{
							moveOk = false;
							std::cout << "Direction: " << direction << std::endl;
						}
					}
					if (direction == "RD")
					{
						if (ptr[k]->getSprite().getPosition().x == oldXPos + (i * 64) && ptr[k]->getSprite().getPosition().y == oldYPos + (i * 64))
						{
							moveOk = false;
							std::cout << "Direction: " << direction << std::endl;
						}
					}
					if (direction == "U")
					{
						if (ptr[k]->getSprite().getPosition().x == oldXPos  && ptr[k]->getSprite().getPosition().y == oldYPos - (i * 64))
						{
							moveOk = false;
							std::cout << "Direction: " << direction << std::endl;
						}
					}
					if (direction == "D")
					{
						if (ptr[k]->getSprite().getPosition().x == oldXPos  && ptr[k]->getSprite().getPosition().y == oldYPos + (i * 64))
						{
							moveOk = false;
							std::cout << "Direction: " << direction << std::endl;
						}
					}
					if (direction == "L")
					{
						if (ptr[k]->getSprite().getPosition().x == oldXPos - (i * 64) && ptr[k]->getSprite().getPosition().y == oldYPos)
						{
							moveOk = false;
							std::cout << "Direction: " << direction << std::endl;
						}
					}
					if (direction == "R")
					{
						if (ptr[k]->getSprite().getPosition().x == oldXPos + (i * 64) && ptr[k]->getSprite().getPosition().y == oldYPos)
						{
							moveOk = false;
							std::cout << "Direction: " << direction << std::endl;
						}
					}

				}

			}
		}
		for (int i = 0; i < 32; i++)
		{
			if (i != pos)
			{
				if (ptr[i]->getSprite().getPosition().x == newXPos && ptr[i]->getSprite().getPosition().y == newYPos)
				{

					if (ptr[i]->getType() == ptr[pos]->getType())
					{
						moveOk = false;
					}
					if (moveOk == true && isTurnOk(ptr, moveCounter, pos) == true)
					{
						ptr[i]->getSprite().setPosition(1000, 1000);
					}


				}
			}
		}

	}
	std::cout << "dx " << dx << std::endl;
	std::cout << "dy " << dy << std::endl;
	std::cout << "true/false " << moveOk << std::endl;

	
	return moveOk;
}

bool Rules::doesEnemyExistPawn(Piece * ptr[], int movingPosX, int movingPosY,int movingPiecePos)
{
	int diffX = movingPosX % 64;
	int diffy = movingPosY % 64;
	bool isExist = false;

	for (int i = 0; i < 32; i++)
	{
		if (i != movingPiecePos)
		{
			if (ptr[i]->getSprite().getPosition().x == movingPosX-diffX && ptr[i]->getSprite().getPosition().y == movingPosY-diffy)
			{
				isExist = true;
			}
		}
		
	}
	return isExist;
}

void Rules::isCheckMate(float oldXPos, float oldYPos, float newXPos, float newYPos, Piece * ptr[])
{
	// kings at 16/17

	float king;
}
bool Rules::isTurnOk(Piece * ptr[], int  moveCounter,int pos)
{
	bool turnOk = true;

	if (ptr[pos]->getType() == 1 && moveCounter % 2 != 0)
	{
		turnOk = false;
	}
	if (ptr[pos]->getType() == -1 && moveCounter % 2 == 0)
	{
		turnOk = false;
	}
	return turnOk;
}
;


