#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;

struct Char : public Drawable
{
public:
	Texture tShape;
	Vector2i position;
	int Player;
	int size = 150;
	Sprite shape;
	void setShape();
	void draw(RenderTarget &target, RenderStates state)const override;
};

