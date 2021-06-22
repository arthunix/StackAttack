#ifndef HOMINHO_H
#define	HOMINHO_H

#include "Space.h"

class hominho {
private:
	// Am I composed of blocks too? I am in gamespace but I am not part of it?
	bool alive = true;

	/* Where i am ? See @Block.h for internal block/column position paradigma */
	unsigned short int posx = 0;
	unsigned short int posy = 100;
	unsigned short int line = 0; // from 0 to 4
	unsigned short int column = 5; // from 0 to 10
public:
	hominho() {};

	/* For the character life */
	bool getlife() {
		return alive;
	}
	bool kill() {
		// You call this method when game over
		if (alive) {
			alive = false;
			return true;
		}
		return false;
	}

	/* Related to the character internal position */

	/* For the x-axis */
	bool setposx(unsigned short int posx) {
		if ((posx >= 0) && (posx <= 50)) {
			this->posx = posx;
			return true;
		}
		return false;
	}
	unsigned short int getposx() {
		return posx;
	}
	/* For the y-axis */
	bool setposy(unsigned short int posy) {
		if ((posy >= 0) && (posy <= 100)) {
			this->posy = posy;
			return true;
		}
		return false;
	}
	unsigned short int getposy() {
		return posy;
	}

	/* Related to the character matrix control */

	/* For character line control */
	unsigned short int getline() {
		return line;
	}
	bool setline(unsigned short int line) {
		if ((line >= 0) && (line <= 10)) {
			this->line = line;
			return true;
		}
		return false;
	}
	/* For character column control */
	unsigned short int getcolumn() {
		return column;
	}
	bool setcolumn(unsigned short int column) {
		if ((column <= 9) && (column >= 0)) {
			this->column = column;
			return true;
		}
		return false;
	}
};

#endif /* HOMINHO_H */