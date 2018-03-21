#include "stdafx.h"
#include "Game.h"


Game::Game()
{
	 window= new sf::RenderWindow(sf::VideoMode(512, 512), "ReeL Schack");
	 board = new Board();
}

void Board::loop()
{
	int x = 0;
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	
	float diffXPos;
	float diffYPos;
	float oldPos;
	bool movingPiece;

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
					if(evnt.key.code == sf::Mouse::Left)
						for (int i = 0; i < 32; i++)
						{
							if (ptr[i].getSprite().getGlobalBounds().contains(mousePos.x, mousePos.y))
							{
								movingPiece = true; x = i;
								diffXPos = mousePos.x - ptr[i].getSprite().getPosition().x;
								diffYPos = mousePos.y - ptr[i].getSprite().getPosition().y;
								
							}
						}
					if (evnt.type == sf::Event::MouseButtonReleased)
					{
						if (evnt.key.code == sf::Mouse::Left)
						{
							movingPiece = false;
						}
						if (movingPiece)
						{
							ptr[x].getSprite().setPosition(mousePos.x - diffXPos, mousePos.y - diffYPos);
						}
					}
						
			}
			 
		}
		window->clear();
		board->drawScreen(*window);
		window->display();
	}
}


Game::~Game()
{
}
