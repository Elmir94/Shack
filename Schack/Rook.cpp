#include "stdafx.h"
#include "Rook.h"


Rook::Rook(team pieceTeam)
{
	if (pieceTeam == BLACK)
	{
		sf::Texture pieceTexture;
		sf::Vector2u textureSize = pieceTexture.getSize();

		getSpriteTexture().loadFromFile("sprites.png", sf::IntRect(128, 0, 64, 64));

		textureSize.x /= 6;
		textureSize.y /= 2;
		getSprite().setTexture(getSpriteTexture());

	}
	if (pieceTeam == WHITE)
	{
		sf::Texture pieceTexture;
		sf::Vector2u textureSize = pieceTexture.getSize();
		getSpriteTexture().loadFromFile("sprites.png", sf::IntRect(128, 64, 64, 64));
		getSprite().setTexture(getSpriteTexture());

	}
}


Rook::~Rook()
{
}

void Rook::move()
{

}


void Rook::draw(sf::RenderWindow & window)
{
	window.draw(getSprite());
}

void Rook::setDefaultPosition(int x, int y)
{
	getSprite().setPosition(sf::Vector2f(x + (5 * x), y + (5 * y)));
}

Rook * Rook::clone() const
{
	return nullptr;
}

