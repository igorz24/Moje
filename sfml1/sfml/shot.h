#ifndef SHOT_H
#define SHOT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace sf;
using namespace std;

class shot
{
private:
	// 0 - wrogi, 1 - nasz
	bool type;
	float speed;
	float angle;
	float scale;
	Texture texture;
	Sprite _shot;

public:
	shot() {
		throw 0;
	};

	shot(bool type, float speed, float scale, float originX, float originY, float targetAngle) : type(type), speed(speed), scale(scale), angle(targetAngle) {

		load();
		initialize(originX, originY);
	};

	
	shot(const shot& other);

	~shot() = default;
	//void lockOnTarget(Sprite target);
	void load();
	void initialize(float originX, float originY);
	void move();
	bool returnType();
	void draw(RenderWindow & w);
	Sprite returnShot();

};

#endif