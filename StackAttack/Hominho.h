#ifndef HOMINHO_H
#define	HOMINHO_H

#include "Space.h"

class hominho {
private:
	// Am I composed of blocks too?
	bool alive = true;

	// Where i am
	unsigned short int column = 5; // from 0 to 9
	unsigned short int high = 0; // from 0 to 4
public:
	hominho() {};

	bool getlife() {
		return alive;
	}

	unsigned short int getcolumn() {
		return column;
	}

	bool setcolumn(unsigned short int column) {
		if ((column < 10) && (column >= 0)) {
			this->column = column;
			return true;
		}
		return false;
	}

	unsigned short int gethigh() {
		return high;
	}

	bool sethigh(unsigned short int high) {
		if ((high < 5) && (high >= 0)) {
			this->high = high;
			return true;
		}
		return false;
	}

	/*
	bool leftoccuped(space matrix) {
		return matrix[column - 1].gettop() < matrix[column].gettop();
	}

	bool rightoccuped() {
		return matrix[from + 1].gettop() < matrix[from].gettop();
	}

	bool pushright();
	bool pushleft();
	bool goleft();
	bool goright();
	bool jump();
	bool fall();*/
};

#endif /* HOMINHO_H */