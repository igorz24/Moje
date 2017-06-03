#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
using namespace sf;
using namespace std;
class explosion
{
private:
	bool toDelete;
	int iterations;
	int delay;
	float positionX;
	float positionY;
	Texture texture;
	Sprite _explosion;
public:
	explosion(float X, float Y);
	explosion(const explosion& other);
	~explosion() = default;

	void initialize(float originX, float originY);
	void changeFrame();
	Sprite returnExplosion();
	bool getToDelete();
};

#endif