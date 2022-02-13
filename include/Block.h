#pragma once
#ifndef BLOCK_H
#define BLOCK_H

#define BLOCK_INACTIVE 0
#define BLOCK_COLOR_ORANGE 1
#define BLOCK_COLOR_BLUE 2
#define BLOCK_COLOR_PINK 3
#define BLOCK_COLOR_RED 4
#define BLOCK_COLOR_YELLOW 5
#define BLOCK_COLOR_GREEN 6

#define MIN_VALID_COLOR 0
#define MAX_VALID_COLOR 6

class Block {
private:
	unsigned short m_Color = BLOCK_INACTIVE;
public:
	Block();
	Block(unsigned short p_Color);
	~Block();
	void setColor(unsigned short p_Color);
	unsigned short getColor();
};

#endif // !BLOCK_H
