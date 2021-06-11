#ifndef PLAYER_H
#define PLAYER_H
class Player {
private:
	int locationX, locationY, grade;
	int rRecord[4][4] , dRecord[4][4];
	char direction;
	bool scores ;
public:
//	Player();
	Player(int, int, char);
	void setLocationX(int);
	void setLocationY(int);
	void setDirection(char);
	void setGrade(int);
	void scoreLasttime(bool);

	int getLocationX()const;
	int getLocationY()const;
	char getDirection()const;
	int getGrade()const;
	bool getScores()const;
	int getRecord()const;
	void setRecord(Player );
};
#endif