#pragma once
#include <SFML\Graphics.hpp>
#include "Char.h"
using namespace sf;
using namespace std;

class Board : public Drawable
{
public:

	Board();
	~Board()=default;
	Char znaki[9];
	int ileZnakow();
	void SetChar(int,int);
	int Move(Vector2i); // 1- by³o wolne , 0 -by³o zajete
	bool GameState();
	Texture tPlayer;
	int gameState; // 0-no started 1-started 2-finisch
	Font font;
	bool ResetBoard();
private:
	int ileZnaków;
	int Fields[3][3]{ {0,0,0},{0,0,0},{0,0,0} };// 0-empty 1-"O" 2-"X"
	Sprite sBg;
	Texture tBg;
	int Player; // 1-"O" 2-"X"

	void draw(RenderTarget &target , RenderStates state)const  override;
	void LoadTexture(); // loading textures
};
