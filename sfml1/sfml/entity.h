#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "animation.h"
#define M_PI 3.1415926535897932384626433
using namespace sf;
using namespace std;
const int W = 1200;
const int H = 800;
const float DEGTORAD = 0.017453f;



class Entity
{
public:
	float x, y, dx, dy, R, angle;
	bool life;
	std::string name;
	Animation anim;

	Entity() : life(1) {}
	void settings(Animation &a, int X, int Y, float Angle = 0, int radius = 1);
	virtual void update() {};
	virtual void update(float targetX, float targetY) {};
	void draw(RenderWindow &app);
	virtual ~Entity() {};
};

#endif