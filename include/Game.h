#pragma once
#ifndef _SPACE_H
#define _SPACE_H

#include "Block.h"
#include "Stack.h"
#include "Player.h"

template<int sizeOfTheStack, int numberOfStacks>
class Game {
private:
	Stack<sizeOfTheStack> m_Columns[numberOfStacks];
	Player m_Player = { numberOfStacks /2, 0 };
	bool isTheLeftOccupedByABlockOrNot(unsigned short);
	bool isTheRightOccupedByABlockOrNot(unsigned short);
	bool canImoveABlockToTheLeftColumn(unsigned short);
	bool canImoveABlockToTheRightColumn(unsigned short);
	bool areTheFirstBlocksOccupedAtAllTheColumns();
	void InsertBlockAtTheColumn(unsigned short p_Line, unsigned short p_Column, unsigned short p_Color);
public:
	Game();
	~Game();
	void InsertBlockAtTheColumn(unsigned short p_Color, unsigned short p_Column);
	unsigned short GetBlockColor(unsigned short p_Column, unsigned short p_Line);
	bool flushAllFirstElementsInEachColumn();
	void movePlayerLeft();
	void movePlayerRight();
	void PlayerJump();
	void CallGravity();
	void PlayerFall();
	bool checkPlayerLife();
	unsigned short getPlayerPositionColumn();
	unsigned short getPlayerPositionLine();
};

template<int sizeOfTheStack, int numberOfStacks>
inline bool Game<sizeOfTheStack, numberOfStacks>::isTheLeftOccupedByABlockOrNot(unsigned short Column)
{
	if (Column == 0) {
		return true;
	}
	if ((0 <= Column) && (Column < numberOfStacks)) {
		return m_Columns[Column - 1].getTop() > m_Columns[Column].getTop();
	}
	return false;
}

template<int sizeOfTheStack, int numberOfStacks>
inline bool Game<sizeOfTheStack, numberOfStacks>::isTheRightOccupedByABlockOrNot(unsigned short Column)
{
	if (Column == numberOfStacks - 1) {
		return true;
	}
	if ((0 <= Column) && (Column < numberOfStacks)) {
		return m_Columns[Column].getTop() < m_Columns[Column + 1].getTop();
	}
	return false;
}

template<int sizeOfTheStack, int numberOfStacks>
inline bool Game<sizeOfTheStack, numberOfStacks>::areTheFirstBlocksOccupedAtAllTheColumns()
{
	for (int itrEachColumn = 0; itrEachColumn < numberOfStacks; itrEachColumn++)
		if (m_Columns[itrEachColumn].getTop() <= 0)
			return false;

	return true;
}

template<int sizeOfTheStack, int numberOfStacks>
inline void Game<sizeOfTheStack, numberOfStacks>::InsertBlockAtTheColumn(unsigned short p_Line, unsigned short p_Column, unsigned short p_Color)
{
	if (((0 <= p_Column) && (p_Column < numberOfStacks)) 
		&& ((0 <= p_Line) && (p_Line < sizeOfTheStack)) 
		&& ((MIN_VALID_COLOR <= p_Color) && (p_Color <= MAX_VALID_COLOR)))
	{
		m_Columns[p_Column].insertBlock(p_Color, p_Line);
	}
}

template<int sizeOfTheStack, int numberOfStacks>
inline Game<sizeOfTheStack, numberOfStacks>::Game()
{
}

template<int sizeOfTheStack, int numberOfStacks>
Game<sizeOfTheStack, numberOfStacks>::~Game()
{
}

template<int sizeOfTheStack, int numberOfStacks>
inline void Game<sizeOfTheStack, numberOfStacks>::InsertBlockAtTheColumn(unsigned short p_Color, unsigned short p_Column)
{
	if (((0 <= p_Column) && (p_Column < numberOfStacks))
		&& ((MIN_VALID_COLOR <= p_Color) && (p_Color <= MAX_VALID_COLOR)))
	{
		m_Columns[p_Column].insertBlock(p_Color, sizeOfTheStack - 1);
	}
}

template<int sizeOfTheStack, int numberOfStacks>
inline unsigned short Game<sizeOfTheStack, numberOfStacks>::GetBlockColor(unsigned short p_Column, unsigned short p_Line)
{
	if (((0 <= p_Column) && (p_Column < numberOfStacks))
		&& (((0 <= p_Line) && (p_Line < sizeOfTheStack))))
	{
		return m_Columns[p_Column].getBlockColor(p_Line);
	}
	return 0;
}

template<int sizeOfTheStack, int numberOfStacks>
inline bool Game<sizeOfTheStack, numberOfStacks>::flushAllFirstElementsInEachColumn()
{
	if (areTheFirstBlocksOccupedAtAllTheColumns())
	{
		for (int itrEachColumn = 0; itrEachColumn < numberOfStacks; itrEachColumn++)
		{
			m_Columns[itrEachColumn].flushTheFirstBlock();
		}
	}
	return false;
}

template<int sizeOfTheStack, int numberOfStacks>
inline void Game<sizeOfTheStack, numberOfStacks>::PlayerJump()
{
	m_Player.MoveMeUp();
}

template<int sizeOfTheStack, int numberOfStacks>
inline bool Game<sizeOfTheStack, numberOfStacks>::checkPlayerLife()
{
	return m_Player.getAmIAlive();
}

template<int sizeOfTheStack, int numberOfStacks>
inline unsigned short Game<sizeOfTheStack, numberOfStacks>::getPlayerPositionColumn()
{
	return m_Player.getInWhatColumnAmI();
}

template<int sizeOfTheStack, int numberOfStacks>
inline unsigned short Game<sizeOfTheStack, numberOfStacks>::getPlayerPositionLine()
{
	return m_Player.getInWhatLineAmI();
}

#endif // !_SPACE_H
