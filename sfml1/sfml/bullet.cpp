#include "bullet.h"


bullet::bullet(bool typ, float targetX, float targetY, float originX, float originY)
{

		if (typ) {
			name = "bulletBlue";
		}
		else {
			name = "bulletRed";
		}
		float a = targetX - originX;
		float b = targetY - originY;
		//Obliczanie k¹ta miêdzy statkiem obcych a celem
		angle2 = M_PI / 2 - (atan2(b, a));

}

void bullet::update()
{

		x += sin(angle2) * 6;
		y += cos(angle2) * 6;

		if (x>W || x<0 || y>H || y<0) life = 0;

}
