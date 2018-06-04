#include "Board.h"
#include <iostream>



Board::Board()
{
	this->gameState = 1;
	this->LoadTexture();
	this->Player = 1;
	this->font.loadFromFile("arial.ttf");
}

void Board::draw(RenderTarget &target,RenderStates state)const
{
	target.draw(this->sBg,state);
}

void Board::LoadTexture()
{
	this->tBg.loadFromFile("plansza.jpg");
	this->tPlayer.loadFromFile("gracze.png");
	this->sBg.setTexture(this->tBg);
}

int Board::Move(Vector2i position)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(position.x<200*(i+1) && position.x>200*i)
				if (position.y<200 *(j+1) && position.y>200 *j)
					if (this->Fields[i][j] == 0)
					{
						this->Fields[i][j] = this->Player;
						this->SetChar(position.x,position.y);
						return 0;
					}
					else return 100;
		}
	}
}

void Board::SetChar(int x,int y)
{
	this->znaki[ileZnaków].Player=this->Player;
	this->znaki[ileZnaków].position.x = x;
	this->znaki[ileZnaków].position.y = y;
	this->znaki[ileZnaków].tShape = this->tPlayer;
	this->znaki[ileZnaków].setShape();
	this->ileZnaków++;
	(this->Player == 1 ? this->Player = 2 : this->Player = 1);
}

int Board::ileZnakow()
{
	if (ileZnaków != 0)
	{
		return ileZnaków;
	}
	else return 0;
}

bool Board::GameState()
{
	
	const int LINIE[][3][2] = { { { 0,0 },{ 0,1 },{ 0,2 } }, // górna pozioma   
	{ { 1,0 },{ 1,1 },{ 1,2 } },// œrod. pozioma   
	{ { 2,0 },{ 2,1 },{ 2,2 } },// dolna pozioma   
	{ { 0,0 },{ 1,0 },{ 2,0 } }, // lewa pionowa   
	{ { 0,1 },{ 1,1 },{ 2,1 } }, // œrod. pionowa   
	{ { 0,2 },{ 1,2 },{ 2,2 } }, // prawa pionowa   
	{ { 0,0 },{ 1,1 },{ 2,2 } }, // p. backslashowa   
	{ { 2,0 },{ 1,1 },{ 0,2 } } }; // p. slashowa

	int Pole, ZgodnePole;
	unsigned LiczbaZgodnychPol;
	for (int i = 0; i<8; ++i)
	{
		Pole = ZgodnePole = 0;
		LiczbaZgodnychPol = 0;
		for (int j = 0; j<3; ++j)
		{
			Pole = this->Fields[LINIE[i][j][0]][LINIE[i][j][1]];
			if (Pole != 0)
			{
				if (Pole != ZgodnePole)
				{
					ZgodnePole = Pole;
					LiczbaZgodnychPol = 1;
				}
				else
					if (Pole == ZgodnePole && ZgodnePole != 0)
						++LiczbaZgodnychPol;

				if (LiczbaZgodnychPol == 3 && ZgodnePole != 0)
				{
					gameState = 2;
					return true;
				}
			}
		}
	}

}

bool Board::ResetBoard()
{
	this->ileZnaków = 0;
	this->gameState = 1;
	this->Player = 1;

	for (auto& x : this->znaki)
	{
		x.Player = 0;
		x.position = { 0,0 };
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			this->Fields[i][j] = 0;
	}

	return true;
}


