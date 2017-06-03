#ifndef ALIEN_H
#define ALIEN_H
#include "entity.h"

class alien : public Entity
{
private:
	int reload;
public:
	alien() {
		name = "alien";
	}
	

	void  update(float targetX, float targetY);
	

};


#endif