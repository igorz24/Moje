#include "alien.h"

void alien::update(float targetX, float targetY)
{
		float a = targetX - x;
		float b = targetY - y;
		//Obliczanie k¹ta miêdzy statkiem obcych a celem
		angle = M_PI / 2 - (atan2(b, a));

		x += sin(angle) * 0.5;
		y += cos(angle) * 0.5;

		if (x>W) x = 0;
		if (x<0) x = W;
		if (y>H) y = 0;
		if (y<0) y = H;
}
