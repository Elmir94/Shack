#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>


int main()
{
	std::ifstream openFile("Map1.txt");

	sf::Texture tileTexture;
	sf::Sprite tiles;
	
	sf::Vector2i map[100][100];
	sf::Vector2i loadCounter = sf::Vector2i(0, 0);

	if (openFile.is_open())
	{
		std::string tileLocation;
		openFile >> tileLocation;
		tileTexture.loadFromFile(tileLocation);
		tiles.setTexture(tileTexture);
		while (!openFile.eof())
		{
			std::string str;
			openFile >> str;
			char x = str[0], y = str[2];
			if (!isdigit(x) || !isdigit(y))
			{
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1, -1);
			
			}
			else
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0');
			if (openFile.peek() == '/n')
			{
				loadCounter.x = 0;
				loadCounter.y++;
			}
			else
			{
				loadCounter.x++;
			}
		}
		loadCounter.y++;
	}
	sf::RenderWindow window(sf::VideoMode(640,480,32),"Loading map");
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{

			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();
		for (int i = 0; i < loadCounter.x; i++)
		{
			for (int j = 0; i < loadCounter.y; i++)
			{
				if (map[i][j].x != -1 && map[i][j].y != -1)
				{
					tiles.setPosition(i * 32, j * 32);
					tiles.setTextureRect(sf::IntRect(map[i][j].x * 32, map[i][j].y * 32, 32, 32));
					window.draw(tiles);
				}
			}
		}
		window.display();
		
	}

	return 0;
}