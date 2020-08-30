#ifndef CLASS_H
#define  CLASS_H

class snake
{
private:
	int tailX[20] = { 0 };
	int tailY[20] = { 0 };
	int nTail;
	bool gameOver;
	const int width = 20;
	const int height = 20;
	int x, y, fruitX, fruitY, score;
	enum class eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
	eDirection dir;
public:
	operator bool() const;
	snake();
	void draw();
	void logic();
	void input();

};

#endif