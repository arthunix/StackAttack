#ifndef SPACE_H
#define	SPACE_H

#include <iostream>
#include <cstdlib>
#include "Column.h"
#include "Hominho.h"

using namespace std;

/* This module is responsible to the game matrix, it will be all the columns  and everything */

class space {
private:
	column matrix[10];
	hominho player;

public:
	/* Here we need to initiate all itens with zero
	* Void block is color zero? is it a good idea?
	*/
	space() {};

	bool allfirstoccuped() {
		for (int i = 0; i < 11; i++)
		{
			if (!matrix[i].firstoccuped()) {
				return false;
			}
		}
		return true;
	}

	// We call this method all times one block fall in the space matrix
	/* Remove the first elements from all the columns */
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
	bool insertblock(block ohmyblock, int column) {
		matrix[column].addblock(ohmyblock);
	}


	/*
	* We call these two methods from Hominho Class?????
	* Call we??? answer me? :( It it right? Ohhh baby :(
	* I THINK NOOOOOOOOOOOOOOOOOOOOOO
	*/

	// From here to down so ladeira abaixo bixo

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
				matrix[from - 1].addblock(aux);
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
				matrix[from + 1].addblock(aux);
				return true;
			}
			return false;
		}
		return false;
	}

	// Hominho movimentation
	bool hominhojump() {
		if (player.gethigh() > 400) {
			player.sethigh(player.gethigh() - 50);
			return true;
		}
		return false;
	}

	bool hominhofall() {
		if (matrix[player.getcolumn()].gettop() < player.gethigh()) {
			player.sethigh(matrix[player.getcolumn()].gettop());
		}
	}

	/*bool hominhogoleft() {
		if (player.getcolumn() != 0)
		{
			if (!leftoccuped(player.getcolumn()))
			{
				player.setcolumn(player.getcolumn() - 1);
				hominhofall();
				return true;
			}
			return false;
		}
		return false;
	}

	bool hominhogoright() {
		if (player.getcolumn() != 9)
		{
			if (!rightoccuped(player.getcolumn()))
			{
				player.setcolumn(player.getcolumn() + 1);
				hominhofall();
				return true;
			}
			return false;
		}
		return false;
	}*/

	bool hominhopushleft() {
		if (player.getcolumn() != 0)
		{
			if (leftoccuped(player.getcolumn()))
			{
				player.setcolumn(player.getcolumn() - 1);
				hominhofall();
				return true;
			}
			return false;
		}
		return false;
	}


	bool hominhopushright() {
		if (player.getcolumn() != 9)
		{
			if (rightoccuped(player.getcolumn()))
			{
				player.setcolumn(player.getcolumn() + 1);
				hominhofall();
				return true;
			}
			return false;
		}
		return false;
	}

	// ?? Hominho
	unsigned short int getposx() {
		return player.getcolumn();
	}
	unsigned short int getposy() {
		return player.gethigh();
	}
	bool setposx(unsigned short int posx) {
		player.setcolumn(posx);
		return true;
	}
	bool setposy(unsigned short int posy) {
		player.sethigh(posy);
		return true;
	}
};

#endif /* SPACE_H */