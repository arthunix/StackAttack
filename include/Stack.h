#pragma once
#ifndef _STACK_H
#define _STACK_H

#include "Block.h"

#include <algorithm>
#include <iterator>

template<int sizeOfTheStack>
class Stack {
private:
	Block m_Column[sizeOfTheStack];
	unsigned short m_Top;
public:
	Stack();
	~Stack();
	void setTop(unsigned short);
	unsigned short getTop();
	void insertBlock(unsigned short p_Color);
	void insertBlockAtTop(unsigned short p_Color);
	unsigned int removeTopBlock();
	bool isThatColumnFull();
	unsigned short getBlockColor(unsigned short p_Line);
	void flushTheFirstBlock();
	void columnCallGravity();
};

template<int sizeOfTheStack>
inline Stack<sizeOfTheStack>::Stack()
{
	for (int i = 0; i < sizeOfTheStack; i++)
	{
		m_Column[i].setColor(BLOCK_INACTIVE);
	}
	setTop(0);
}

template<int sizeOfTheStack>
Stack<sizeOfTheStack>::~Stack()
{
}

template<int sizeOfTheStack>
void Stack<sizeOfTheStack>::setTop(unsigned short p_Top)
{
	this->m_Top = p_Top;
}

template<int sizeOfTheStack>
unsigned short Stack<sizeOfTheStack>::getTop()
{
	return m_Top;
}

template<int sizeOfTheStack>
void Stack<sizeOfTheStack>::insertBlock(unsigned short p_Color)
{
	if ((MIN_VALID_COLOR <= p_Color) && (p_Color <= MAX_VALID_COLOR))
	{
		m_Column[sizeOfTheStack - 1].setColor(p_Color);
	}
}

template<int sizeOfTheStack>
void Stack<sizeOfTheStack>::insertBlockAtTop(unsigned short p_Color)
{
	if ((MIN_VALID_COLOR <= p_Color) && (p_Color <= MAX_VALID_COLOR))
	{
		m_Column[m_Top].setColor(p_Color);
		m_Top += 1;
	}
}

template<int sizeOfTheStack>
inline unsigned int Stack<sizeOfTheStack>::removeTopBlock()
{
	unsigned int returnValue;
	if (m_Top > 0)
	{
		returnValue = m_Column[m_Top - 1].getColor();
		m_Column[m_Top - 1].setColor(BLOCK_INACTIVE);
		m_Top -= 1;
	}

	return returnValue;
}

template<int sizeOfTheStack>
inline bool Stack<sizeOfTheStack>::isThatColumnFull()
{
	return m_Top == (sizeOfTheStack / 2);
}

template<int sizeOfTheStack>
inline unsigned short Stack<sizeOfTheStack>::getBlockColor(unsigned short p_Line)
{
	if ((0 <= p_Line) && (p_Line < sizeOfTheStack))
	{
		return m_Column[p_Line].getColor();
	}
	return -1;
}

template<int sizeOfTheStack>
inline void Stack<sizeOfTheStack>::flushTheFirstBlock()
{
	Block internAuxiliarColumn[sizeOfTheStack];
	Block newBlockVoidBlock = { BLOCK_INACTIVE };
	std::copy(std::begin(m_Column), std::end(m_Column), std::begin(internAuxiliarColumn));
	std::copy(std::begin(internAuxiliarColumn) + 1, std::end(internAuxiliarColumn), std::begin(m_Column));

	m_Top -= 1;
}

template<int sizeOfTheStack>
inline void Stack<sizeOfTheStack>::columnCallGravity()
{
	for (int iteratorForColumn = m_Top + 1; iteratorForColumn < sizeOfTheStack; iteratorForColumn++) {
		Block newBlockVoidBlock = { BLOCK_INACTIVE };
		if (m_Column[iteratorForColumn].getColor() != BLOCK_INACTIVE)
		{
			m_Column[iteratorForColumn - 1] = m_Column[iteratorForColumn];
			m_Column[iteratorForColumn] = newBlockVoidBlock;
			if ((iteratorForColumn - 1) == m_Top)
			{
				m_Top += 1;
			}
		}
	}
}

#endif // !_STACK_H
