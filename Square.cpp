#include"Square.h"
Square::Square()
{
	setup(false);
	setdown(false);
	setright(false);
	setleft(false);
}
void Square::setup(bool n)
{
	up = n;
}
void Square::setdown(bool n)
{
	down = n;
}
void Square::setright(bool n)
{
	right = n;
}
void Square::setleft(bool n)
{
	left = n;
}
bool Square::getup()const
{
	return up;
} 
bool Square::getdown()const
{
	return down;
}
bool Square::getright()const
{
	return right;
}
bool Square::getleft()const
{
	return left;
}
bool Square::score()
{
	if (this->up == 1 && this->down == 1 && this->right == 1 && this->left == 1) {
		return true;
	}
	else return false;
}
//
