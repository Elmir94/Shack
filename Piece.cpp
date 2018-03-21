#include "stdafx.h"
#include "Piece.h"


Piece::Piece()
{
	
}


Piece::~Piece()
{

}

void Piece::setText(std::string filename)
{
	spriteTexture.loadFromFile(filename);
}

sf::Sprite & Piece::getSprite()
{
	return this->SpritePtr;
}

sf::Texture & Piece::getSpriteTexture()
{
	return this->spriteTexture;
}

int Piece::getType()
{
	return type;
}

void Piece::setType(int type)
{
	this->type = type;
}
bool Piece::getIsMoved()
{
	return isMoved;
}

void Piece::setMoved()
{
	isMoved = true;
}
