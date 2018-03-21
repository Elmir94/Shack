#include "stdafx.h"
#include "Queen.h"


Queen::Queen(team pieceTeam)
{
	if (pieceTeam == BLACK)
	{
		sf::Texture pieceTexture;
		sf::Vector2u textureSize = pieceTexture.getSize();

		getSpriteTexture().loadFromFile("sprites.png", sf::IntRect(64, 0, 64, 64));

		textureSize.x /= 6;
		textureSize.y /= 2;
		getSprite().setTexture(getSpriteTexture());

	}
	if (pieceTeam == WHITE)
	{
		sf::Texture pieceTexture;
		sf::Vector2u textureSize = pieceTexture.getSize();
		getSpriteTexture().loadFromFile("sprites.png", sf::IntRect(64, 64, 64, 64));
		getSprite().setTexture(getSpriteTexture());

	}
}


Queen::~Queen()
{

}

void Queen::move()
{

}


void Queen::draw(sf::RenderWindow & window)
{
	window.draw(getSprite());
}

void Queen::setDefaultPosition(int x, int y)
{
	getSprite().setPosition(sf::Vector2f(x + (5 * x), y + (5 * y)));
}
