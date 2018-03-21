#include "stdafx.h"
#include "Board.h"


Board::Board()
{
	initializeBoard();
	for (int i = 0; i < 64; i++)
	{
		boardTiles[i].setSize(sf::Vector2f(64, 64));
	}
	
	boardTileTextureDark.loadFromFile("tiles.jpg", sf::IntRect(0, 0, 64, 64));
	boardTileTextureLight.loadFromFile("tiles.jpg", sf::IntRect(64, 0, 64, 64));
	
	defaultPosTiles();
	tileColorGen();
	initPieceArray();
	defaultPosPieces();
}


Board::~Board()
{
}

void Board::initializeBoard()
{
	for (int i = 0; i < 32; i++)
	{
		this->allPieces[i] = nullptr;
	}
}

void Board::tileColorGen()
{
	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0)
		{
			boardTiles[i].setTexture(&boardTileTextureDark);
		}
		else
		{
			boardTiles[i].setTexture(&boardTileTextureLight);
		}

	}
	for (int i = 8; i < 16; i++)
	{
		if (i % 2 != 0)
		{
			boardTiles[i].setTexture(&boardTileTextureDark);
		}
		else
		{
			boardTiles[i].setTexture(&boardTileTextureLight);
		}

	}
	for (int i = 16; i < 24; i++)
	{
		if (i % 2 == 0)
		{
			boardTiles[i].setTexture(&boardTileTextureDark);
		}
		else
		{
			boardTiles[i].setTexture(&boardTileTextureLight);
		}

	}
	for (int i = 24; i < 32; i++)
	{
		if (i % 2 != 0)
		{
			boardTiles[i].setTexture(&boardTileTextureDark);
		}
		else
		{
			boardTiles[i].setTexture(&boardTileTextureLight);
		}

	}
	for (int i = 32; i < 40; i++)
	{
		if (i % 2 == 0)
		{
			boardTiles[i].setTexture(&boardTileTextureDark);
		}
		else
		{
			boardTiles[i].setTexture(&boardTileTextureLight);
		}

	}
	for (int i = 40; i < 48; i++)
	{
		if (i % 2 != 0)
		{
			boardTiles[i].setTexture(&boardTileTextureDark);
		}
		else
		{
			boardTiles[i].setTexture(&boardTileTextureLight);
		}

	}
	for (int i = 48; i < 56; i++)
	{
		if (i % 2 == 0)
		{
			boardTiles[i].setTexture(&boardTileTextureDark);
		}
		else
		{
			boardTiles[i].setTexture(&boardTileTextureLight);
		}

	}
	for (int i = 56; i < 64; i++)
	{
		if (i % 2 != 0)
		{
			boardTiles[i].setTexture(&boardTileTextureDark);
		}
		else
		{
			boardTiles[i].setTexture(&boardTileTextureLight);
		}

	}
}


void Board::initPieceArray()
{
	for (int i = 0; i < 8; i++)
	{
		allPieces[i] = new Pawn(BLACK);
		allPieces[i]->setType(1);
	}
	for (int i = 8; i < 16; i++)
	{
		allPieces[i] = new Pawn(WHITE);
		allPieces[i]->setType(-1);
	}
	allPieces[16] = new King(BLACK);
	allPieces[17] = new King(WHITE);
	allPieces[18] = new Queen(BLACK);
	allPieces[19] = new Queen(WHITE);
	allPieces[20] = new Rook(BLACK);
	allPieces[21] = new Rook(BLACK);
	allPieces[22] = new Rook(WHITE);
	allPieces[23] = new Rook(WHITE);
	allPieces[24] = new Bishop(BLACK);
	allPieces[25] = new Bishop(BLACK);
	allPieces[26] = new Bishop(WHITE);
	allPieces[27] = new Bishop(WHITE);
	allPieces[28] = new Knight(BLACK);
	allPieces[29] = new Knight(BLACK);
	allPieces[30] = new Knight(WHITE);
	allPieces[31] = new Knight(WHITE);


	allPieces[16]->setType(1);
	allPieces[17]->setType(-1);
	allPieces[18]->setType(1);
	allPieces[19]->setType(-1);
	allPieces[20]->setType(1);
	allPieces[21]->setType(1);
	allPieces[22]->setType(-1);
	allPieces[23]->setType(-1);
	allPieces[24]->setType(1);
	allPieces[25]->setType(1);
	allPieces[26]->setType(-1);
	allPieces[27]->setType(-1);
	allPieces[28]->setType(1);
	allPieces[29]->setType(1);
	allPieces[30]->setType(-1);
	allPieces[31]->setType(-1);
	
}

void Board::defaultPosPieces()
{
	int x = 0;
	for (int i = 0; i < 8; i++)
	{
		allPieces[i]->getSprite().setPosition(i * 64, 64);
	}
	for (int i = 8; i < 16; i++)
	{
		
		allPieces[i]->getSprite().setPosition(x * 64,384);
		x++;
	}
	allPieces[16]->getSprite().setPosition(4 * 64, 0);
	allPieces[17]->getSprite().setPosition(4 * 64, 448);
	allPieces[18]->getSprite().setPosition(3 * 64, 0);
	allPieces[19]->getSprite().setPosition(3 * 64, 448);
	allPieces[20]->getSprite().setPosition(0,0);
	allPieces[21]->getSprite().setPosition(448 , 0);
	allPieces[22]->getSprite().setPosition(0, 448);
	allPieces[23]->getSprite().setPosition(448, 448);
	allPieces[24]->getSprite().setPosition(128, 0);
	allPieces[25]->getSprite().setPosition(320, 0);
	allPieces[26]->getSprite().setPosition(128, 448);
	allPieces[27]->getSprite().setPosition(320, 448);
	allPieces[28]->getSprite().setPosition(64, 0);
	allPieces[29]->getSprite().setPosition(384, 0);
	allPieces[30]->getSprite().setPosition(64, 448);
	allPieces[31]->getSprite().setPosition(384, 448);


}

void Board::defaultPosTiles()
{
	int nr = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			
			this->boardTiles[nr].setPosition(k * 64, i * 64);
			nr++;
		}
	}
}



void Board::loop()
{
	int x = 0;
	sf::Vector2i pos = sf::Mouse::getPosition(*window);
	Rules check;
	
	bool movingPiece=false;
	bool moved = false;
	float oldPosX;
	float oldPosY;
	float newPosX;
	float newPosY;
	bool moveOk = false;
	bool turnOk = false;
	while (window->isOpen())
	{
		sf::Event evnt;

		while (window->pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window->close();
				break;

			case sf::Event::MouseButtonPressed:
				if (evnt.key.code == sf::Mouse::Left)
					for (int i = 0; i < 32; i++)
					{
						if (allPieces[i]->getSprite().getGlobalBounds().contains(sf::Mouse::getPosition(*window).x,sf::Mouse::getPosition(*window).y))
						{
							oldPosX = allPieces[i]->getSprite().getPosition().x;
							oldPosY = allPieces[i]->getSprite().getPosition().y;
							movingPiece = true;
							x = i;
						}
					}
				if (evnt.type == sf::Event::MouseButtonReleased)
				{
					if (evnt.key.code == sf::Mouse::Left)
					{
						movingPiece = false;
					}
					
				}
				if (movingPiece == true)
				{
					
					for (int i = 0; i < 64; i++)
					{
						if(boardTiles[i].getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
						{
							if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
							{
								newPosX = sf::Mouse::getPosition(*window).x;
								newPosY = sf::Mouse::getPosition(*window).y;
							}
							allPieces[x]->getSprite().setPosition(boardTiles[i].getPosition().x, boardTiles[i].getPosition().y);
							std::cout << boardTiles[i].getPosition().x << std::endl;
							std::cout << boardTiles[i].getPosition().y << std::endl << std::endl;

							if (allPieces[x]->getSprite().getPosition().x != oldPosX || allPieces[x]->getSprite().getPosition().y != oldPosY)
							{
								
								movingPiece = false;
								moveOk = check.isMoveOk(oldPosX, oldPosY, allPieces[x]->getSprite().getPosition().x, allPieces[x]->getSprite().getPosition().y, allPieces,x, moveCounter);
								turnOk = check.isTurnOk(allPieces, moveCounter, x);
								if (moveOk == true && turnOk == true)
								{
									moveCounter++;
								}
							}
							if (moveOk == false || turnOk == false)
							{
								allPieces[x]->getSprite().setPosition(oldPosX, oldPosY);
							}
						}
						
					}
					
				}
				
				break;
			}
			
		}
		window->clear();
		for (int i = 0; i < 64; i++)
		{
			window->draw(boardTiles[i]);
		}
		
		for (int i = 0; i < 32; i++)
		{
			window->draw(allPieces[i]->getSprite());
		}
		window->display();
	}
}

