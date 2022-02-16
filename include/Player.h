#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H

template<int numberOfStacks>
class Player {
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
	m_InWhatLineAmI -= 1;
}

#endif // !_PLAYER_H
