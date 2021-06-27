/*
* COLUMN
* (C) 2021 Ingrid Lira dos Santos
* (C) 2021 Arthur Eugenio Silverio
* (C) 2021 Caroline Elisa Duarte de Souza
*
* StackAttack is released under the Simplified BSD License (see LICENSE)
*/

#ifndef COLUMN_H
#define	COLUMN_H

#define LENGHT_DISPLAY 800
#define HIGH_DISPLAY 600
#define GRAVITY_VELOCITY 10

#include "Block.h"

/* The next instance of the game, the column stantiate de blocks */
class column {
private:
	block line[11];

	/// <Column considerations and explanation>
	/// This is for the single column and she has 5 of high
	/// But how can we manage the blocks will fall from the above?
	/// And if we use an column by 11 of size and then we can manage in the same way
	/// For the entire matrix see @Space.h we call these methods from there? Is it?
	/// In this class we will manage the columns add remove and more
	/// </I do not find a better way to solve this bullshit>

	/* I think the top block is the fakefloor too */
	unsigned short int top = 0; // Zero for void block it is not a good idea See @Space.h
	unsigned short int last = 0;
public:
	/* Related to the column */
	column() {
		for (int i = 0; i < 10; i++)
		{
			/* Initialize all columns with the value of the line */
			line[i].setline(i);
		}
		top = 0;
	} // initiate a void column

	/* Return the block instance, you can chose the top (without parameter) or a indexed*/
	block getblock(unsigned short int index) {
		return line[index];
	}

	block getblock() {
		return line[top - 1];
	}

	/* Getters and setters */
	bool setblockcolor(unsigned short int color, unsigned short int index) {
		line[index].setcolor(color);
		return true;
	}

	bool settop(unsigned short int top) {
		if ((top >= 0)&&(top <= 5)) {
			this->top = top;
			return true;
		}
		return false;
	}

	bool setlast(unsigned short int last) {
		if ((last >= 0)&&(last <= 10)) {
			this->last = last;
			return true;
		}
		return false;
	}

	unsigned short int getlast() {
		return top;
	}

	unsigned short int gettop() {
		return top;
	}

	/* Set the column value to all block of column */
	bool setcolumn(unsigned short int col)
	{
		for (int i = 0; i < 11; i++)
		{
			line[i].setcolumn(col);
		}
		return true;
	}

	bool descreaselast() {
		last--;
		return true;
	}

	bool fullcolumn() {
		if (gettop() == 5) {
			return true;
		}
		return false;
	}
	bool addblock(unsigned short int column, unsigned short int color) {
		if (!fullcolumn()) {
			// The block starts from the above, the fall from it
			line[10].setline(10);
			line[10].setcolumn(column);
			line[10].setcolor(color);
			last = 10;
			//top = top + 1;
			/// <Gravity considerations and new ideas>
			/// The block starts from the above and then need to fall down
			/// I think it is not here we will do it... but the main method
			/// when refresh the frame will call the gravity and if the
			/// position that is not the floor will see it and then update
			/// the position until the block reach to your proper place
			/// <But this gravity bullshit is not just here See @Hominho.h>
			return true;
		}
		return false;
	}
	bool addblock(unsigned short int l, unsigned short int column, unsigned short int color) {
		if (!fullcolumn()) {
			// The block starts from the above, the fall from it
			line[l].setline(l);
			line[l].setcolumn(column);
			line[l].setcolor(color);
			last = l;
			top = top + 1;
			return true;
		}
		return false;
	}
	bool removefirst() {
		if (top > 0)
		{
			// Create a column copy and then realocate
			block aux[5];
			for (int i = 0; i < top; i++)
			{
				aux[i].setcolor(line[i].getcolor());
			}
			for (int i = 0; i < (top - 1); i++)
			{
				line[i].setcolor(aux[i + 1].getcolor());
			}
			line[top - 1].setcolor(0);
			top = top - 1;
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
	bool removetopblock() {
		top = top - 1;
		line[top].setcolor(0);
		return true;
	}

	bool removetopblock(unsigned short int index) {
		top = top - 1;
		last--;
		line[index].setcolor(0);
		return true;
	}

	bool blockfall()
	{
		if (top < last)
		{
			//std::cout << "top: " << top << std::endl;
			//std::cout << "last: " << last << std::endl;
			line[last - 1].setcolor(line[last].getcolor());
			line[last - 1].setline(line[last].getline() - 1);
			line[last].setcolor(0);
			line[last].setline(0);
			last--;
			if (top == last)
			{
				top++;
			}
			return true;
		}
		return false;
	}
};

#endif /* COLUMN_H */