#include "explosion.h"



explosion::explosion(float X, float Y) : toDelete(0), iterations(0), delay(6), positionX(X), positionY(Y)
{
	if (!texture.loadFromFile("explosion.png")) {
		cout << "Shot1 didn't load!!!" << endl;
		//Wyrzucenie wyj¹tku
		throw 0;
	}
	_explosion.setTexture(texture);
	_explosion.setPosition(Vector2f(positionX, positionY));

}

explosion::explosion(const explosion & other) : iterations(other.iterations), delay(other.delay), toDelete(0)
{
	if (!texture.loadFromFile("explosion.png")) {
		cout << "Shot1 didn't load!!!" << endl;
		//Wyrzucenie wyj¹tku
		throw 0;
	}
	_explosion.setTexture(texture);
	_explosion.setPosition(Vector2f(other.positionX, other.positionY));

}



void explosion::initialize(float originX, float originY)
{

		_explosion.setTextureRect(IntRect(0, 0, 50, 50));
		_explosion.setOrigin(Vector2f(25, 25));
}

void explosion::changeFrame()
{
	
	int temp = iterations / delay;
	cout << "iterations " << iterations << " temp " << temp << " delay " << delay << endl;
	_explosion.setTextureRect(IntRect(temp * 50, 0, 50, 50));
	iterations++;
	if (iterations == (delay *20 -2)) toDelete = 1;
}

Sprite explosion::returnExplosion()
{
	return _explosion;
}

bool explosion::getToDelete()
{
	return toDelete;
}
