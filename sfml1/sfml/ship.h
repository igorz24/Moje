#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "shot.h"

using namespace sf;
using namespace std;

class ship
{
private:
	float speed;
	float rotation;
	float angle;
	int reload1;
	int reload2;
	Texture texture;
	Sprite _ship;

public:
	
	ship() : speed(0), rotation(0), angle(0) {};
	ship(float speed1, float rotation1) : speed(speed1), rotation(rotation1), angle(0), reload1(0), reload2(0) {};
	ship(const ship& other);
	~ship() = default;

	void load();
	void initialize(float scale, float originx, float originy);
	void countAngle();
	void moveUp();
	void moveDown();
	void rotate();
	bool WeaponsReady1();
	bool WeaponsReady2();
	void Reload();
	void draw(RenderWindow & w);
	void changeRotation(float change);
	shot shoot(float targetX, float targetY);
	Sprite returnShip();



};

#endif