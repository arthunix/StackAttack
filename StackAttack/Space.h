#ifndef SPACE_H
#define	SPACE_H

#include <iostream>
#include <cstdlib>
#include "Column.h"
#include "Hominho.h"

using namespace std;

/* This module is responsible to all game control, like the bullshit systemd I CONTROL EVERYTHING FROM HERE */
class space {
private:
	column matrix[10];
	hominho player;

	unsigned short int fakefloor = 0; // It's the position we shold to to draw the character?
	unsigned short int reg_posy = 0; // Position of the last introduced block
public:
	/* Here we need to initiate all itens with zero, void block is color zero? is it a good idea? */
	space() {
		fakefloor = HIGH_DISPLAY - 100;
		reg_posy = player.getposy();
	};

	/* For the block in space game management */

	bool allfirstoccuped() {
		for (int i = 0; i < 11; i++)
		{
			if (!matrix[i].firstoccuped()) {
				return false;
			}
		}
		return true;
	}
	/* We call this method all times one block fall in the space matrix */
	bool removeallfirst() {
		if (allfirstoccuped())
		{
			for (int i = 0; i <= 9; i++) {
				matrix[i].removefirst();
			}
			return true;
		}
		return false;
	}

	/* Here we need to receive a a number from random numbers generator
	* It's a pseudo-random numbers generator :( cryptography cry buá
	*/
	bool insertblock(block ohmyblock, unsigned short int column) {
		matrix[column].addblock(ohmyblock);
	}
	bool insertblock(block ohmyblock, unsigned short int column, unsigned short int line) {
		matrix[column].addblock(ohmyblock, line); // Here is from the middle
	}


	bool leftoccuped(unsigned short int from) {
		return matrix[from - 1].gettop() >= matrix[from].gettop();
	}
	bool rightoccuped(unsigned short int from) {
		return matrix[from + 1].gettop() >= matrix[from].gettop();
	}
	bool movleft(unsigned short int from) {
		if (from != 0)
		{
			if (!leftoccuped(from))
			{
				block aux;
				aux = matrix[from].removetopblock();
				matrix[from - 1].addblock(aux, aux.getline());
				return true;
			}
			return false;
		}
		return false;
	}
	bool movright(unsigned short int from) {
		if (from != 9)
		{
			if (!rightoccuped(from))
			{
				block aux;
				aux = matrix[from].removetopblock();
				matrix[from + 1].addblock(aux, aux.getline());
				return true;
			}
			return false;
		}
		return false;
	}

	/* For character movimentation */
	bool hominhojump() {
		if (player.getposy() != 0){
			player.setline(player.getline() + 1);
			player.setposy(0);
			return true;
		}
		return false;
	}

	/*
	bool hominhofall() {
		if (matrix[player.getcolumn()].gettop() < player.gethigh()) {
			player.sethigh(matrix[player.getcolumn()].gettop());
		}
	}*/

	/* For the character management in gamespace */
	unsigned short int getcolumn() {
		return player.getcolumn();
	}
	unsigned short int getline() {
		return player.getline();
	}
	unsigned short int getposy() {
		return player.getposy();
	}
	unsigned short int getposx() {
		return player.getposx();
	}

	bool setcolumn(unsigned short int column) {
		player.setcolumn(column);
		return true;
	}
	bool setline(unsigned short int line) {
		player.setline(line);
		return true;
	}
	bool setposx(unsigned short int posx) {
		player.setposx(posx);
		return true;
	}
	bool setposy(unsigned short int posy) {
		player.setposy(posy);
		return true;
	}
};

#endif /* SPACE_H */