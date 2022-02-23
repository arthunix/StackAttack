/*
Copyright (c) 2021-2022 Arthur Eugenio Silverio. All rights reserved.
Copyright (c) 2021-2022 Ingrid Lira dos Santos. All rights reserved.
Copyright (c) 2021-2022 Arthur Eugenio Silverio. All rights reserved.

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
