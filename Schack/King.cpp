#include "stdafx.h"
#include "King.h"


King::King(team pieceTeam)
{
	if (pieceTeam == BLACK)
	{
		sf::Texture pieceTexture;
		sf::Vector2u textureSize = pieceTexture.getSize();

		getSpriteTexture().loadFromFile("sprites.png", sf::IntRect(0, 0, 64, 64));

		textureSize.x /= 6;
		textureSize.y /= 2;
		getSprite().setTexture(getSpriteTexture());

	}
	if (pieceTeam == WHITE)
	{
		sf::Texture pieceTexture;
		sf::Vector2u textureSize = pieceTexture.getSize();
		getSpriteTexture().loadFromFile("sprites.png", sf::IntRect(0, 64, 64, 64));
		getSprite().setTexture(getSpriteTexture());

	}
}


King::~King()
{
}


void King::move()
{

}


void King::draw(sf::RenderWindow & window)
{
	window.draw(getSprite());
}

void King::setDefaultPosition(int x, int y)
{
	getSprite().setPosition(sf::Vector2f(x + (5 * x), y + (5 * y)));
}

King * King::clone() const
{
	return nullptr;
}
