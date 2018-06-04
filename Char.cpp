#include "Char.h"

void Char::draw(RenderTarget &target, RenderStates state)const
{
	target.draw(this->shape, state);
}

void Char::setShape()
{
	shape.setPosition(position.x,position.y);
	shape.setTexture(tShape);
	shape.setTextureRect(IntRect(((200*Player)-200),0,size,size));
	shape.setOrigin(50.0f, 75.0f);
}