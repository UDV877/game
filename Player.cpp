#include"player.h"
#include<iostream>
using namespace std;

Player::Player(int x, int y, char dir)
{
	locationX = x;
	locationY = y;
	direction = dir;
	grade = 0;
	scores = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			rRecord[i][j] = 0;
			dRecord[i][j] = 0;
		}
	}
}
void Player::setLocationX(int x)
{
	locationX = x;
}
void Player::setLocationY(int y)
{
	locationY = y;
}
void Player::setDirection(char dir)
{
	direction = dir;
}
void Player::setGrade(int i)
{
	grade += i;
	//	scoreLasttime(1);
}
void Player::scoreLasttime(bool n)
{
	scores = n;
}
int Player::getLocationX()const
{
	return locationX;
}
int Player::getLocationY()const
{
	return locationY;
}
char Player::getDirection()const
{
	return direction;
}
int Player::getGrade()const
{
	return grade;
}
bool Player::getScores()const
{
	return scores;
}
void Player::setRecord(Player pp)
{
	if (pp.getDirection() == 'R')
	{
		rRecord[this->getLocationX() - 1][this->getLocationY() - 1] = 1;
	}
	else if (pp.getDirection() == 'D')
	{
		dRecord[this->getLocationX() - 1][this->getLocationY() - 1] = 1;
	}
}
int Player::getRecord()const
{
	if (this->getDirection() == 'R' && rRecord[this->getLocationX() - 1][this->getLocationY() - 1] == 1)
	{
		return 1;
	}
	else if (this->getDirection() == 'D' && dRecord[this->getLocationX() - 1][this->getLocationY() - 1] == 1)
	{
		return 1;
	}
	else
		return 0;
}