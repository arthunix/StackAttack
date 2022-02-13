#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H

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

#endif // !_PLAYER_H
