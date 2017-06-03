#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace sf;
using namespace std;

class Animation
{
public:
	float Frame, speed;
	Sprite sprite;
	
	std::vector<IntRect> frames;

	Animation() {}
	Animation(Texture &t, int x, int y, int w, int h, int count, float Speed);
	void update();
	bool isEnd();
	

};

#endif