#include "entity.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "animation.h"



//void Entity::settings(Animation & a, int X, int Y, float Angle, int radius)
//
//
//void Entity::draw(RenderWindow & app)
//

void Entity::settings(Animation & a, int X, int Y, float Angle, int radius)
{
		anim = a;
		x = X; y = Y;
		angle = Angle;
		R = radius;
}

void Entity::draw(RenderWindow & app)
{

		anim.sprite.setPosition(x, y);
		anim.sprite.setRotation(angle + 90);
		app.draw(anim.sprite);

		CircleShape circle(R);
		circle.setFillColor(Color(255, 0, 0, 170));
		circle.setPosition(x, y);
		circle.setOrigin(R, R);
}
