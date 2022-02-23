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
