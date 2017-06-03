#ifndef BULLET_H
#define BULLET_H
#include "entity.h"

class bullet : public Entity
{

public:
	float angle2;
	bullet(bool typ, float targetX, float targetY, float originX, float originY);

	void  update();

};


#endif