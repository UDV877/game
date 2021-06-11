#ifndef SQUARE_H
#define SQUARE_H
class Square {
private:
	bool up, down, right, left;

public:
	Square();

	void setup(bool);
	void setdown(bool);
	void setright(bool);
	void setleft(bool);
	bool getup()const;
	bool getdown()const;
	bool getright()const;
	bool getleft()const;
	bool score();
};
#endif
//
