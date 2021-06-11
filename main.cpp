#include<iostream>
#include"Player.h"
#include"Square.h"
using namespace std;
void draw(Player& player, const int size, Square squ[3][3])
{
	if (player.getLocationY() == 1 && player.getDirection() == 'R') {
		squ[player.getLocationX() - 1][0].setup(true);

		if (squ[player.getLocationX() - 1][0].score() == 1) {
			player.setGrade(1);
			player.scoreLasttime(true);
		}
	}
	else if (player.getLocationY() == size && player.getDirection() == 'R') {
		squ[player.getLocationX() - 1][size - 2].setdown(true);

		if (squ[player.getLocationX() - 1][size - 2].score() == 1) {
			player.setGrade(1);
			player.scoreLasttime(true);
		}
	}
	else if (player.getLocationX() == 1 && player.getDirection() == 'D') {
		squ[0][player.getLocationY() - 1].setleft(true);

		if (squ[0][player.getLocationY() - 1].score() == 1) {
			player.setGrade(1);
			player.scoreLasttime(true);
		}
	}
	else if (player.getLocationX() == size && player.getDirection() == 'D') {
		squ[size - 2][player.getLocationY() - 1].setright(true);

		if (squ[size - 2][player.getLocationY() - 1].score() == 1) {
			player.setGrade(1);
			player.scoreLasttime(true);
		}
	}
	else if (player.getDirection() == 'R' && player.getLocationY() < size) {
		squ[player.getLocationX() - 1][player.getLocationY() - 2].setdown(true);
		squ[player.getLocationX() - 1][player.getLocationY() - 1].setup(true);

		if (squ[player.getLocationX() - 1][player.getLocationY() - 2].score() == 1) {
			player.setGrade(1);
			player.scoreLasttime(true);
		}
		if (squ[player.getLocationX() - 1][player.getLocationY() - 1].score() == 1) {
			player.setGrade(1);
			player.scoreLasttime(true);
		}
	}
	else if (player.getDirection() == 'D' && player.getLocationX() < size) {
		squ[player.getLocationX() - 2][player.getLocationY() - 1].setright(true);
		squ[player.getLocationX() - 1][player.getLocationY() - 1].setleft(true);

		if (squ[player.getLocationX() - 2][player.getLocationY() - 1].score() == 1) {
			player.setGrade(1);
			player.scoreLasttime(true);
		}
		if (squ[player.getLocationX() - 1][player.getLocationY() - 1].score() == 1) {
			player.setGrade(1);
			player.scoreLasttime(true);
		}
	}
}
int main()
{
	const int size = 4;
	int x1, y1, x2, y2;
	char c1, c2;
	bool b1 = false, b2 = false, b3 = false;
	Square squ[size - 1][size - 1];
	cout << "Player1's move:";
	cin >> x1 >> y1 >> c1;
	Player recordPlayer(x1, y1, c1);
	recordPlayer.setRecord(recordPlayer);

	cout << "Player2's move:";
	cin >> x2 >> y2 >> c2;
	recordPlayer.setLocationX(x2); recordPlayer.setLocationY(y2); recordPlayer.setDirection(c2);
	recordPlayer.setRecord(recordPlayer);

	Player p1(x1, y1, c1), p2(x2, y2, c2);
	draw(p1, size, squ);
	draw(p2, size, squ);


	for (int i = 0; i < size * (size - 1) * 2 - 2; )
	{
		if (p1.getScores() == false && p2.getScores() == false
			&& b1 == false && b2 == false && b3 == false)
		{
			cout << "Player1's move: ";
			cin >> x1 >> y1 >> c1;
			recordPlayer.setLocationX(x1); recordPlayer.setLocationY(y1); recordPlayer.setDirection(c1);

			if (x1 <= size && x1 >= 1 && y1 <= size && y1 >= 1
				&& (c1 == 'D' || c1 == 'R') && recordPlayer.getRecord() == 0)
			{
				p1.setLocationX(x1); p1.setLocationY(y1); p1.setDirection(c1);
				draw(p1, size, squ);
				i++;
				recordPlayer.setRecord(recordPlayer);
			}
			else
			{
				cout << "Wrong information!" << endl;
				continue;
			}
		}
		if (p1.getScores() == true && p2.getScores() == false
			&& b2 == false && b3 == false)
		{
			cout << "You get a point! Player1's move again: ";
			cin >> x1 >> y1 >> c1;
			recordPlayer.setLocationX(x1); recordPlayer.setLocationY(y1); recordPlayer.setDirection(c1);

			if (x1 <= size && x1 >= 1 && y1 <= size && y1 >= 1
				&& (c1 == 'D' || c1 == 'R') && recordPlayer.getRecord() == 0)
			{
				p1.scoreLasttime(false);
				p1.setLocationX(x1); p1.setLocationY(y1); p1.setDirection(c1);
				draw(p1, size, squ);
				i++;
				b1 = false;
				recordPlayer.setRecord(recordPlayer);
			}
			else
			{
				cout << "Wrong information!" << endl;
				b1 = true;
				continue;
			}

		}
		if (p2.getScores() == false && p1.getScores() == false
			&& b3 == false)
		{
			cout << "Player2's move: ";
			cin >> x2 >> y2 >> c2;
			recordPlayer.setLocationX(x2); recordPlayer.setLocationY(y2); recordPlayer.setDirection(c2);

			if (x2 <= size && x2 >= 1 && y2 <= size && y2 >= 1
				&& (c2 == 'D' || c2 == 'R') && recordPlayer.getRecord() == 0)
			{
				p2.setLocationX(x2); p2.setLocationY(y2); p2.setDirection(c2);
				draw(p2, size, squ);
				i++;
				b2 = false;
				recordPlayer.setRecord(recordPlayer);
			}
			else
			{
				cout << "Wrong information!" << endl;
				b2 = true;
				continue;
			}
		}
		if (p2.getScores() == true && p1.getScores() == false)
		{
			cout << "You get a point! Player2's move again: ";
			cin >> x2 >> y2 >> c2;
			recordPlayer.setLocationX(x2); recordPlayer.setLocationY(y2); recordPlayer.setDirection(c2);

			if (x2 <= size && x2 >= 1 && y2 <= size && y2 >= 1
				&& (c2 == 'D' || c2 == 'R') && recordPlayer.getRecord() == 0)
			{
				p2.scoreLasttime(false);
				p2.setLocationX(x2); p2.setLocationY(y2); p2.setDirection(c2);
				draw(p2, size, squ);
				i++;
				b3 = false;
				recordPlayer.setRecord(recordPlayer);
			}
			else
			{
				cout << "Wrong information!" << endl;
				b3 = true;
				continue;
			}
		}
	}
	cout << endl;
	cout << "Player1 got " << p1.getGrade() << " points." << endl;
	cout << "Player2 got " << p2.getGrade() << " points." << endl;
	cout << ((p1.getGrade() > p2.getGrade()) ? "Player1" : "Player2") << " win!!";
	return 0;
}