#include "stdafx.h"
#include "Pawn.h"


Pawn::Pawn(team pieceTeam) 
{
	
	if (pieceTeam == BLACK)
	{
		sf::Texture pieceTexture;
		sf::Vector2u textureSize = pieceTexture.getSize();

		getSpriteTexture().loadFromFile("sprites.png", sf::IntRect(320, 0, 64, 64));

		textureSize.x /= 6;
		textureSize.y /= 2;
		getSprite().setTexture(getSpriteTexture());

	}
	if (pieceTeam == WHITE)
	{
		sf::Texture pieceTexture;
		sf::Vector2u textureSize = pieceTexture.getSize();
		getSpriteTexture().loadFromFile("sprites.png", sf::IntRect(320, 64, 64, 64));
		getSprite().setTexture(getSpriteTexture());

	}
}



void Pawn::move()
{

}


void Pawn::draw(sf::RenderWindow & window)
{
	window.draw(getSprite());
}

void Pawn::setDefaultPosition(int x, int y)
{
	getSprite().setPosition(sf::Vector2f(x + (5 * x), y + (5 * y)));
}

Pawn * Pawn::clone() const
{
	return nullptr;
}







Pawn::~Pawn()
{
}


