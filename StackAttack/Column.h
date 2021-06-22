#ifndef COLUMN_H
#define	COLUMN_H

#define LENGHT_DISPLAY 800
#define HIGH_DISPLAY 600
#define GRAVITY_VELOCITY 10

#include "Block.h"

/* The next instance of the game, the column stantiate de blocks */
class column {
private:
	block columnline[11];

	/// <Column considerations and explanation>
	/// This is for the single column and she has 5 of high
	/// But how can we manage the blocks will fall from the above?
	/// And if we use an column by 11 of size and then we can manage in the same way
	/// For the entire matrix see @Space.h we call these methods from there? Is it?
	/// In this class we will manage the columns add remove and more
	/// </I do not find a better way to solve this bullshit>

	unsigned short int top = 0; // Zero for void block it is not a good idea See @Space.h
	unsigned short int fakefloor = (HIGH_DISPLAY - 50); // It's the position we shold to to draw the last block?
	unsigned short int poshigh = 0; // Position of the last introduced block
	unsigned short int colhigh = 0; // Last of the last introduced block (Register)
public:
	/* Related to the column */
	column() { top = 0; } // initiate a void column

	unsigned short int gettop() {
		return top;
	}
	bool fullcolumn() {
		if (gettop() == 5) {
			return true;
		}
		return false;
	}
	bool addblock(block mynewblock) {
		if (!fullcolumn()) {
			// The block starts from the above, the fall from it
			mynewblock.setline(10);
			mynewblock.setposy(50);
			columnline[10] = mynewblock;
			colhigh = 10;
			top = top + 1;
			fakefloor = (HIGH_DISPLAY-50) - ((50) * top);
			poshigh = (HIGH_DISPLAY-50) - ((50) * 10);
			/// <Gravity considerations and new ideas>
			/// The block starts from the above and then need to fall down
			/// I think it is not here we will do it... but the main method
			/// when refresh the frame will call the gravity and if the
			/// position that is not the floor will see it and then update
			/// the position at the gravity velocity until this reach at
			/// your proper position it is ((HIGH_DISPLAY-50) - (top*50))
			/// <But this gravity bullshit is not just here See @Hominho.h>
			return true;
		}
		return false;
	}
	bool addblock(block mynewblock, unsigned short int l) {
		if (!fullcolumn()) {
			// The block starts from the above, the fall from it
			mynewblock.setline(l);
			mynewblock.setposy(50);
			columnline[l] = mynewblock;
			colhigh = l;
			top = top + 1;
			fakefloor = (HIGH_DISPLAY - 50) - ((50) * top);
			poshigh = (HIGH_DISPLAY - 50) - ((50) * 10);
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
				aux[i] = columnline[i];
			}
			for (int i = 0; i < (top - 1); i++)
			{
				columnline[i] = aux[i + 1];
			}
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
	block removetopblock() {
		top = top - 1;
		return columnline[top];
	}


	/* Related to the block internal position inside the column line */
	bool fall() {
		/* I think it is here we apply the gravity */
		if (poshigh != fakefloor) {
			/* We still need to fall */
			if (columnline[colhigh].getposy() == 0)
			{
				columnline[colhigh].setposy(50);
				columnline[colhigh].setline(columnline[colhigh].getline() - 1);
				colhigh = colhigh - 1;
				return true;
			}
			else {
				if (columnline[colhigh].getposy() <= 50) {
					columnline[colhigh].setposy(columnline[colhigh].getposy() - GRAVITY_VELOCITY);
					return true;
				}
				return true;
			}
			return false;
		}
		return false;
	}
};

#endif /* COLUMN_H */