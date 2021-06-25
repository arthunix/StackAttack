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

public:
	/* Here we need to initiate all itens with zero, void block is color zero? is it a good idea? */
	space() {};


	/* For the block in space game management */
	column bloquinhogetline(int index) {
		return matrix[index];
	}

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
	bool insertblock(unsigned short int column, unsigned short int color) {
		matrix[column].addblock(column, color);
		return true;
	}

	bool insertblock(unsigned short int line, unsigned short int column, unsigned short int color) {
		matrix[column].addblock(line, column, color);
		return true;
	}

	bool leftoccuped(unsigned short int from) {
		return matrix[from - 1].gettop() > matrix[from].gettop();
	}
	bool rightoccuped(unsigned short int from) {
		return matrix[from + 1].gettop() > matrix[from].gettop();
	}
	
	bool blockmovleft(unsigned short int from) {
		if (from != 0)
		{
			if (!leftoccuped(from))
			{
				block aux = matrix[from].removetopblock();
				matrix[from - 1].addblock(aux.getline(), aux.getcolumn() - 1,aux.getcolor());
				matrix[from].setblockcolor(0, matrix[from].gettop());
				return true;
			}
			return false;
		}
		return false;
	}
	bool blockmovright(unsigned short int from) {
		if (from != 9)
		{
			if (!rightoccuped(from))
			{
				block aux = matrix[from].removetopblock();
				matrix[from + 1].addblock(aux.getline(), aux.getcolumn() + 1, aux.getcolor());
				matrix[from].setblockcolor(0, matrix[from].gettop());
				return true;
			}
			return false;
		}
		return false;
	}

	/* For character movimentation */
	bool hominhojump() {
		player.setline(player.getline() + 1);
		return true;
	}

	bool hominhofall() {
		while (matrix[player.getcolumn()].gettop() != player.getline())
		{
			cout << "\ncolumn      : " << player.getcolumn() << endl;
			cout << "column topo : " << matrix[player.getcolumn()].gettop() << endl;
			cout << "hominho line: " << player.getline() << endl;
			player.setline(player.getline() - 1);
		}
		return true;
	}

	bool hominhomovleft() {
		if (leftoccuped(player.getcolumn())) {
			cout << "oi to ocupado" << endl;
			if (leftoccuped(player.getcolumn() - 1)) {
				cout << "oi to ocupado 2" << endl;
				return false;
			}
			else {
				blockmovleft(player.getcolumn() - 1);
				player.setcolumn(player.getcolumn() - 1);
				cout << "oi to ocupado mas nem tanto" << endl;
				return true;
			}
		}
		else {
			cout << "to passando sai da frente" << endl;
			player.setcolumn(player.getcolumn() - 1);
			return true;
		}
		return false;
	}

	bool hominhomovright() {
		if (rightoccuped(player.getcolumn())) {

			if (rightoccuped(player.getcolumn() + 1)) {
				return false;
			}
			else {
				blockmovright(player.getcolumn() + 1);
				player.setcolumn(player.getcolumn() + 1);
				return true;
			}
		}
		else {
			player.setcolumn(player.getcolumn() + 1);
			return true;
		}
		return false;
	}

	bool fall() {
		for (int i = 0; i <= 9; i++) {
			matrix[i].blockfall();
		}
		hominhofall();
		return true;
	}

	/* For the character management in gamespace */
	unsigned short int getcolumn() {
		return player.getcolumn();
	}
	unsigned short int getline() {
		return player.getline();
	}
	bool setcolumn(unsigned short int column) {
		player.setcolumn(column);
		return true;
	}
	bool setline(unsigned short int line) {
		player.setline(line);
		return true;
	}
};

#endif /* SPACE_H */