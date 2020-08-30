#include "iostream"
#include "Class.h"
#include <Windows.h>

int main(int argc, char* argv[])
{
	snake gameOne;
	while (!gameOne) {
		gameOne.draw();
		gameOne.input();
		gameOne.logic();
		Sleep(35);
	}

	return 0;
}