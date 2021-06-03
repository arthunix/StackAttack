#ifndef COLUMN_H
#define	COLUMN_H

#include "Block.h"

class column {
private:
	/*
	* This is for the single column and she has 5 of high
	* In this class we will manage the columns add remove and more
	* For the entire matrix see @Space.h
	* 
	* I gess we need to call methods from this class on Space class
	*/
	block columnline[5];
	unsigned short int top = 0; // Zero for void block it is not a good idea See @Space.h
public:
	column() { // initiate a void column
		top = 0;
	};

	unsigned short int gettop() {
		return top;
	}

	bool fullcolumn() {
		if (top == 5) {
			return true;
		}
		return false;
	}

	bool addblock(block mynewblock) {
		if (!fullcolumn()) {
			columnline[top] = mynewblock;
			top = top + 1;
			return true;
		}
		return false;
	}

	bool removefirst() {
		if (top > 0)
		{
			block aux[5]; // Create a column copy
			for (int i = 0; i < top; i++)
			{
				aux[i] = columnline[i];
			}
			for (int i = 0; i < (top - 1); i++)
			{
				columnline[i] = aux[i + 1];
				top = top - 1;
			}
			return true;
		}
		return false;
	}

	bool firstoccuped() {
		if (top > 0) {
			return true;
		}
		return false;
	}

	block removetopblock() {
		top = top - 1;
		return columnline[top];
	}
};

#endif /* COLUMN_H */