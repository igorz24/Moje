#include "ship.h"

using namespace std;
using namespace sf;



ship::ship(const ship & other): speed(other.speed), rotation(other.rotation), angle(other.angle), texture(other.texture), _ship(other._ship)
{
	_ship.setTexture(texture);
}

void ship::load()
{
	if (!texture.loadFromFile("ship.png")) {
		cout << "Ship didn't load!!!" << endl;
		throw 0;
	}
	_ship.setTexture(texture);
}

void ship::initialize(float scale, float originX, float originY)
{
	
	_ship.setScale(scale, scale);
	_ship.setOrigin(Vector2f(_ship.getTexture()->getSize().x * 0.5, _ship.getTexture()->getSize().y * 0.5));
	_ship.setPosition(Vector2f(originX, originY));
}

void ship::countAngle()
{
	 angle = rotation * M_PI / 180;
}

void ship::moveUp()
{
	_ship.move(Vector2f(sin(angle)*speed, cos(angle)*(-speed)));
}

void ship::moveDown()
{
	_ship.move(Vector2f(0.5*sin(angle)*-speed, 0.5*cos(angle)*speed));
}

void ship::rotate()
{
	_ship.setRotation(rotation);
}

void ship::changeRotation(float change)
{
	rotation += change ;
}

shot ship::shoot(float targetX, float targetY)
{
	

	float a = targetX - _ship.getPosition().x;
	float b = targetY - _ship.getPosition().y;
	//Obliczanie k¹ta miêdzy statkiem obcych a celem
	float anglePom = M_PI / 2 - (atan2(b, a));

	int pom = (rand() % 11) - 5 ;
	return shot(1, 4, 0.05, _ship.getPosition().x, _ship.getPosition().y, anglePom += (M_PI / 180)* pom);
}

Sprite ship::returnShip()
{
	return _ship;
}

bool ship::WeaponsReady1()
{
	if (reload1 <= 0) {
		reload1 = rand() % 50 + 50;
		return true;
	}
	else {
		reload1--;
		return false;
	}
}
bool ship::WeaponsReady2()
{
	if (reload2 <= 0) {
		reload2 = rand() % 50 + 50;
		return true;
	}
	else {
		reload2--;
		return false;
	}
}

void ship::Reload()
{
	reload1--;
	reload2--;
}

void ship::draw(RenderWindow & w)
{
	w.draw(_ship);
}
