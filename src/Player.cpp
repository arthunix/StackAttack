#include "Player.h"

Player::Player()
{
}

Player::Player(unsigned short p_Column, unsigned short p_Line = 0)
{
	m_AmIAlive = true;
	m_InWhatColumnAmI = p_Column;
	m_InWhatLineAmI = p_Line;
}

Player::~Player()
{
	m_AmIAlive = false;
}

unsigned short Player::getInWhatColumnAmI()
{
	return m_InWhatColumnAmI;
}

unsigned short Player::getInWhatLineAmI()
{
	return m_InWhatLineAmI;
}

bool Player::getAmIAlive()
{
	return m_AmIAlive;
}

void Player::setAmIAlive(bool p_AmIAlive)
{
	m_AmIAlive = p_AmIAlive;
}

void Player::MoveMeLeft()
{
	m_InWhatColumnAmI -= 1;
}

void Player::MoveMeRight()
{
	m_InWhatColumnAmI += 1;
}

void Player::MoveMeUp()
{
	m_InWhatLineAmI += 1;
}

void Player::MoveMeDown()
{
	m_InWhatLineAmI -= 1;
}
