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
		for (int i = 0; i < 10; i++)
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

	bool leftoccuped() {
		return player.getline() < matrix[player.getcolumn() - 1].gettop();
	}
	bool rightoccuped() {
		return player.getline() < matrix[player.getcolumn() + 1].gettop();
	}
	
	bool blockleftoccuped() {
		return matrix[player.getcolumn() - 2].gettop() >= matrix[player.getcolumn() - 1].gettop();
	}
	bool blockrightoccuped() {
		return matrix[player.getcolumn() + 2].gettop() >= matrix[player.getcolumn() + 1].gettop();
	}
	
	bool blockmovleft() {
		matrix[player.getcolumn() - 2].addblock(matrix[player.getcolumn() - 2].gettop(), player.getcolumn() - 2, matrix[player.getcolumn() - 1].getblock().getcolor());
		matrix[player.getcolumn() - 1].removetopblock();
		return false;
	}
	bool blockmovright() {
		matrix[player.getcolumn() + 2].addblock(matrix[player.getcolumn() + 2].gettop(), player.getcolumn() + 2, matrix[player.getcolumn() + 1].getblock().getcolor());
		matrix[player.getcolumn() + 1].removetopblock();
		return false;
	}

	/* For character movimentation in the gamespace */
	bool hominhojump() {
		player.setline(player.getline() + 1);
		return true;
	}

	bool hominhofall()
	{
		while (matrix[player.getcolumn()].gettop() != player.getline())
		{
			cout << "\ncolumn      : " << player.getcolumn() << endl;
			cout << "column topo : " << matrix[player.getcolumn()].gettop() << endl;
			cout << "hominho line: " << player.getline() << endl;
			player.setline(player.getline() - 1);
		}
		return true;
	}

	bool blockfall()
	{

		matrix[player.getcolumn() - 1].addblock(matrix[player.getcolumn()].gettop(), player.getcolumn() - 2, matrix[player.getcolumn() - 1].getblock().getcolor());
		matrix[player.getcolumn() - 1].removetopblock();
	}

	bool hominhomovleft() {
		if (leftoccuped()) {
			cout << "esquerda do hominho ocupada" << endl;
			if (blockleftoccuped()) {
				cout << "esquerda do hominho ocupada por dois blocos" << endl;
				return false;
			}
			else {
				if (matrix[player.getcolumn()].gettop() + 1 == matrix[player.getcolumn() - 1].gettop())
				{
					cout << "esquerda do hominho ocupada mas por um bloco" << endl;
					blockmovleft();
					player.setcolumn(player.getcolumn() - 1);
					return true;
				}
				cout << "esquerda do hominho ocupada mas por um bloco mas nem da pra empurrar" << endl;
				return false;
			}
		}
		else {
			cout << "esquerda ta livre" << endl;
			player.setcolumn(player.getcolumn() - 1);
			return true;
		}
		return false;
	}

	bool hominhomovright() {
		if (rightoccuped())
		{
			cout << "direita do hominho ocupada" << endl;
			if (blockrightoccuped()|| (player.getcolumn() == 8))
			{
				cout << "direita do hominho ocupada por dois blocos" << endl;
				return false;
			}
			else {
				if (matrix[player.getcolumn()].gettop() + 1 == matrix[player.getcolumn() + 1].gettop())
				{
					cout << "direita do hominho ocupada mas por um bloco" << endl;
					blockmovright();
					player.setcolumn(player.getcolumn() + 1);
					return true;
				}
				cout << "direita do hominho ocupada mas por um bloco mas nem da pra empurrar" << endl;
				return false;
			}
		}
		else {
			cout << "direita ta livre" << endl;
			player.setcolumn(player.getcolumn() + 1);
			return true;
		}
		return false;
	}
	/*
	bool fall() {
		for (int i = 0; i <= 9; i++) {
			matrix[i].blockfall();
		}
		hominhofall();
		return true;
	}*/

	/* For the character getters and setters */
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