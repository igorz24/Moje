#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"




class player : public Entity
{
public:
	bool thrust;

	player()
	{
		name = "player";
	}

	void update();
	

};


#endif