/*
Copyright (c) 2021-2022 Arthur Eugenio Silverio. All rights reserved.
Copyright (c) 2021-2022 Ingrid Lira dos Santos. All rights reserved.
Copyright (c) 2021-2022 Caroline Elisa Duarte de Souza. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

1. Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions, and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once
#ifndef _SPACE_H
#define _SPACE_H

#include "Block.h"
#include "Stack.h"
#include "Player.h"

template<int sizeOfTheStack, int numberOfStacks>
class Game
{
private:
	Stack<sizeOfTheStack> m_Columns[numberOfStacks];
	Player<numberOfStacks> m_Player = { numberOfStacks /2, 0 };
	bool areTheFirstBlocksOccupedAtAllTheColumns();
	//bool isTheLeftOccupedByABlockOrNot(unsigned short p_Column);
	//bool isTheRightOccupedByABlockOrNot(unsigned short p_Column);
	//bool canImoveABlockToTheLeftColumn(unsigned short p_Column);
	//bool canImoveABlockToTheRightColumn(unsigned short p_Column);
	//void insertBlockAtTheColumn(unsigned short p_Line, unsigned short p_Column, unsigned short p_Color);
public:
	Game();
	~Game();
	void insertBlockAtTheColumn(unsigned short p_Color, unsigned short p_Column);
	unsigned short GetBlockColor(unsigned short p_Column, unsigned short p_Line);
	bool flushAllFirstElementsInEachColumn();
	void movePlayerLeft();
	void movePlayerRight();
	void playerJump();
	void callGravity();
	bool checkPlayerLife();
	unsigned short getPlayerPositionColumn();
	unsigned short getPlayerPositionLine();
	void playerFallForever();
};

template<int sizeOfTheStack, int numberOfStacks>
inline bool Game<sizeOfTheStack, numberOfStacks>::areTheFirstBlocksOccupedAtAllTheColumns()
{
	for (int itrEachColumn = 0; itrEachColumn < numberOfStacks; itrEachColumn++)
	{
		if (m_Columns[itrEachColumn].getTop() <= 0)
		{
			return false;
		}
	}
	return true;
}

template<int sizeOfTheStack, int numberOfStacks>
inline void Game<sizeOfTheStack, numberOfStacks>::playerFallForever()
{
	while(m_Player.getInWhatLineAmI() > m_Columns[m_Player.getInWhatColumnAmI()].getTop())
	{
		m_Player.MoveMeDown();
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
inline void Game<sizeOfTheStack, numberOfStacks>::insertBlockAtTheColumn(unsigned short p_Color, unsigned short p_Column)
{
	if (((0 <= p_Column) && (p_Column < numberOfStacks))
		&& ((MIN_VALID_COLOR <= p_Color) && (p_Color <= MAX_VALID_COLOR)))
	{
		m_Columns[p_Column].insertBlock(p_Color);
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
		return true;
	}
	return false;
}

template<int sizeOfTheStack, int numberOfStacks>
inline void Game<sizeOfTheStack, numberOfStacks>::movePlayerLeft()
{
	/* For this we have the base case : The player is in the first column, unable to move left */
	if (m_Player.getInWhatColumnAmI() == 0)
		return;

	/* For this we have the case : The player free to move left with no obtacles */
	if (m_Player.getInWhatLineAmI() >= m_Columns[m_Player.getInWhatColumnAmI() - 1].getTop())
	{
		m_Player.MoveMeLeft();
	}
	else
	{
		/* For this we have the case : the previous column is the first and it's occuped */
		if (m_Player.getInWhatColumnAmI() - 1 == 0) {}
		else
		{
			/* For this we have the case : We can push the block to the left column */
			if ((m_Columns[m_Player.getInWhatColumnAmI() - 1].getTop() > m_Columns[m_Player.getInWhatColumnAmI() - 2].getTop())
				&& ((m_Player.getInWhatLineAmI() + 1) == m_Columns[m_Player.getInWhatColumnAmI() - 1].getTop()))
			{
				unsigned short temp_color = m_Columns[m_Player.getInWhatColumnAmI() - 1].removeTopBlock();
				m_Columns[m_Player.getInWhatColumnAmI() - 2].insertBlockAtTop(temp_color);
				m_Player.MoveMeLeft();
			}
		}
	}
	if ((m_Columns[m_Player.getInWhatColumnAmI()].getBlockColor(m_Player.getInWhatLineAmI() + 1) != BLOCK_INACTIVE))
	{
		m_Player.setAmIAlive(false);
	}
}

template<int sizeOfTheStack, int numberOfStacks>
inline void Game<sizeOfTheStack, numberOfStacks>::movePlayerRight()
{
	/* For this we have the base case : The player is in the last column, unable to move right */
	if (m_Player.getInWhatColumnAmI() == numberOfStacks - 1)
		return;

	/* For this we have the case : The player free to move right with no obtacles */
	if (m_Player.getInWhatLineAmI() >= m_Columns[m_Player.getInWhatColumnAmI() + 1].getTop())
	{
		m_Player.MoveMeRight();
	}
	else
	{
		/* For this we have the case : the next column is the last and it's occuped */
		if (m_Player.getInWhatColumnAmI() + 1 == numberOfStacks - 1) { }
		else
		{
			/* For this we have the case : We can push the block to the right column */
			if ((m_Columns[m_Player.getInWhatColumnAmI() + 1].getTop() > m_Columns[m_Player.getInWhatColumnAmI() + 2].getTop())
				&& ((m_Player.getInWhatLineAmI() + 1) == m_Columns[m_Player.getInWhatColumnAmI() + 1].getTop()))
			{
				unsigned short temp_color = m_Columns[m_Player.getInWhatColumnAmI() + 1].removeTopBlock();
				m_Columns[m_Player.getInWhatColumnAmI() + 2].insertBlockAtTop(temp_color);
				m_Player.MoveMeRight();
			}
		}
	}
	if ((m_Columns[m_Player.getInWhatColumnAmI()].getBlockColor(m_Player.getInWhatLineAmI() + 1) != BLOCK_INACTIVE))
	{
		m_Player.setAmIAlive(false);
	}
}

template<int sizeOfTheStack, int numberOfStacks>
inline void Game<sizeOfTheStack, numberOfStacks>::playerJump()
{
	m_Player.MoveMeUp();
	if ((m_Columns[m_Player.getInWhatColumnAmI()].getBlockColor(m_Player.getInWhatLineAmI() + 1) != BLOCK_INACTIVE))
	{
		m_Player.setAmIAlive(false);
	}
}

template<int sizeOfTheStack, int numberOfStacks>
inline void Game<sizeOfTheStack, numberOfStacks>::callGravity()
{
	for (int itrEachColumn = 0; itrEachColumn < numberOfStacks; itrEachColumn++)
	{
		m_Columns[itrEachColumn].columnCallGravity();
	}
	if ((m_Columns[m_Player.getInWhatColumnAmI()].getBlockColor(m_Player.getInWhatLineAmI() + 1) != BLOCK_INACTIVE))
	{
		m_Player.setAmIAlive(false);
	}
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
