#include "Block.h"

Block::Block()
{
	this->m_Color = BLOCK_INACTIVE;
}

Block::Block(unsigned short p_Color)
{
	if ((MIN_VALID_COLOR <= p_Color) && (p_Color <= MAX_VALID_COLOR))
	{
		this->m_Color = p_Color;
	}
}

Block::~Block()
{
	setColor(0);
}

void Block::setColor(unsigned short p_Color)
{
	if ((MIN_VALID_COLOR <= p_Color) && (p_Color <= MAX_VALID_COLOR))
	{
		this->m_Color = p_Color;
	}
}

unsigned short Block::getColor()
{
	return m_Color;
}
