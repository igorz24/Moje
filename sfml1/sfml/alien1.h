#ifndef ALIEN_H
#define ALIEN_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "shot.h"



using namespace sf;
using namespace std;



class alien
{
private:
	Sprite _alien;
	Texture texture;
	float speed;
	float angle;
	int reload;

public:
	alien() {
		throw 0;
	};
	alien(float speed) : speed(speed), reload(rand() % 50 + 50) {
		void load();
	};
	alien(const alien & other);
	~alien() = default;

	void load();
	void initialize(float scale, float originx, float originy);
	void rotate(float angle);
	void setCourse(Sprite target);
	void move();
	bool reloadWeapon();
	shot shoot();
	Sprite returnAlien();
	void infotemp();
};

#endif