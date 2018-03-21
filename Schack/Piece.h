#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
enum team
{
	BLACK,
	WHITE
};

class Piece
{
private:
	sf::Sprite SpritePtr;
	sf::Texture spriteTexture;
	int type = 0;
	bool isMoved = false;

public:

	Piece();
	~Piece();

	virtual void setText(std::string filename);
	virtual void move() =0;
	virtual void draw(sf::RenderWindow &window) = 0;
	virtual sf::Sprite &getSprite();
	virtual void setDefaultPosition( int x, int y)=0;
	virtual sf::Texture &getSpriteTexture();
	virtual int getType();
	virtual void setType(int type);
	virtual bool getIsMoved();
	virtual void setMoved();

	

	
};

