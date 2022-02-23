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
#ifndef _PLAYER_H
#define _PLAYER_H

template<int numberOfStacks>
class Player
{
private:
	bool m_AmIAlive = 0;
	unsigned short m_InWhatColumnAmI;
	unsigned short m_InWhatLineAmI;
public:
	Player();
	Player(unsigned short, unsigned short);
	~Player();
	unsigned short getInWhatColumnAmI();
	unsigned short getInWhatLineAmI();
	bool getAmIAlive();
	void setAmIAlive(bool p_AmIAlive);
	void MoveMeLeft();
	void MoveMeRight();
	void MoveMeUp();
	void MoveMeDown();
};

template<int numberOfStacks>
inline Player<numberOfStacks>::Player()
{
}

template<int numberOfStacks>
inline Player<numberOfStacks>::Player(unsigned short p_Column, unsigned short p_Line)
{
	m_AmIAlive = true;
	m_InWhatColumnAmI = p_Column;
	m_InWhatLineAmI = p_Line;
}

template<int numberOfStacks>
inline Player<numberOfStacks>::~Player()
{
	m_AmIAlive = false;
}

template<int numberOfStacks>
inline unsigned short Player<numberOfStacks>::getInWhatColumnAmI()
{
	return m_InWhatColumnAmI;
}

template<int numberOfStacks>
inline unsigned short Player<numberOfStacks>::getInWhatLineAmI()
{
	return m_InWhatLineAmI;
}

template<int numberOfStacks>
inline bool Player<numberOfStacks>::getAmIAlive()
{
	return m_AmIAlive;
}

template<int numberOfStacks>
inline void Player<numberOfStacks>::setAmIAlive(bool p_AmIAlive)
{
	m_AmIAlive = p_AmIAlive;
}

template<int numberOfStacks>
inline void Player<numberOfStacks>::MoveMeLeft()
{
	if (m_InWhatColumnAmI != 0)
	{
		m_InWhatColumnAmI -= 1;
	}
}

template<int numberOfStacks>
inline void Player<numberOfStacks>::MoveMeRight()
{
	if (m_InWhatColumnAmI != numberOfStacks)
	{
		m_InWhatColumnAmI += 1;
	}
}

template<int numberOfStacks>
inline void Player<numberOfStacks>::MoveMeUp()
{
	m_InWhatLineAmI += 1;
}

template<int numberOfStacks>
inline void Player<numberOfStacks>::MoveMeDown()
{
	if (m_InWhatLineAmI != 0)
	{
		m_InWhatLineAmI -= 1;
	}
}

#endif // !_PLAYER_H
