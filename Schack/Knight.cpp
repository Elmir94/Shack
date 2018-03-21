#include "stdafx.h"
#include "Knight.h"


Knight::Knight(team pieceTeam)
{
	if (pieceTeam == BLACK)
	{
		sf::Texture pieceTexture;
		sf::Vector2u textureSize = pieceTexture.getSize();

		getSpriteTexture().loadFromFile("sprites.png", sf::IntRect(192, 0, 64, 64));

		textureSize.x /= 6;
		textureSize.y /= 2;
		getSprite().setTexture(getSpriteTexture());

	}
	if (pieceTeam == WHITE)
	{
		sf::Texture pieceTexture;
		sf::Vector2u textureSize = pieceTexture.getSize();
		getSpriteTexture().loadFromFile("sprites.png", sf::IntRect(192, 64, 64, 64));
		getSprite().setTexture(getSpriteTexture());

	}
}


Knight::~Knight()
{
}

void Knight::move()
{

}


void Knight::draw(sf::RenderWindow & window)
{
	window.draw(getSprite());
}

void Knight::setDefaultPosition(int x, int y)
{
	getSprite().setPosition(sf::Vector2f(x + (5 * x), y + (5 * y)));
}

Knight * Knight::clone() const
{
	return nullptr;
}

