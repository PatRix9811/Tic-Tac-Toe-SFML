#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <iostream>
#include <Windows.h>
#include "Board.h"
#include "Char.h"


using namespace sf;
using namespace std;

int koniec = 1;

void main()
{
	RenderWindow sWindow{VideoMode(600,600),"Kolko i krzyzyk"};
	sWindow.setFramerateLimit(60);
	Board cBoard;
	Sprite znak;
	znak.setPosition(0.f,0.f);
	znak.setTexture(cBoard.tPlayer);
	znak.setTextureRect(IntRect(0, 0, 200, 200));

	
	while (true)
	{
		sWindow.clear(Color::Black);
		Event eEvent;
		while (sWindow.isOpen())
		{
			sWindow.pollEvent(eEvent);

			switch (eEvent.type)
			{
				case Event::EventType::Closed:
				{
					sWindow.close(); break;
				}

				case Event::MouseButtonPressed:
				{
					if (Mouse::isButtonPressed(Mouse::Button::Left))
					{
						if (cBoard.gameState == 1)
						{
							cBoard.Move(Mouse::getPosition(sWindow));
							cBoard.GameState();
							Sleep(200);
						}
						else
						{
							cBoard.ResetBoard();
							koniec = 1;
							Sleep(200);
						}
					}
					continue;
				}
			}

			if(koniec != 2)
			{
				sWindow.draw(cBoard);
				int ile = cBoard.ileZnakow();
				if (ile != 0)
				{
					for (int i = 0; i < ile; i++)
					{
						sWindow.draw(cBoard.znaki[i]);
					}

					if (cBoard.gameState == 2) koniec=2;
				}
			}
			else
			{
				Text info;
				info.setString("Zagraj ponownie");
				info.setFont(cBoard.font);
				info.setCharacterSize(34);
				info.setFillColor(Color::Color(255,0,254,200));
				info.setPosition(sWindow.getSize().x/2-100, sWindow.getSize().y / 2-20);

				sWindow.draw(info);
			}

			sWindow.display();
		}
		break;

	}
}

