#include "alien1.h"



alien::alien(const alien & other): speed(other.speed), angle(other.angle), texture(other.texture), _alien(other._alien), reload(other.reload)
{
	if (!texture.loadFromFile("alien.png")) {
		cout << "Alien didn't load!!!" << endl;
		//Wyrzucenie wyj¹tku
		throw 0;
	}
	_alien.setTexture(texture);
}

void alien::load()
{
	if (!texture.loadFromFile("alien.png")) {
		cout << "Alien didn't load!!!" << endl;
		//Wyrzucenie wyj¹tku
		throw 0;
	}
	_alien.setTexture(texture);
}

//Graficzne ustawienia sprite'a
void alien::initialize(float scale, float originX, float originY)
{
	_alien.setScale(scale, scale);
	_alien.setOrigin(Vector2f(_alien.getTexture()->getSize().x * 0.5, _alien.getTexture()->getSize().y * 0.5));
	_alien.setPosition(Vector2f(originX, originY));
}

void alien::rotate(float angle)
{
	_alien.rotate(angle);
}

void alien::setCourse(Sprite target)
{
	float a = target.getPosition().x - _alien.getPosition().x;
	float b = target.getPosition().y - _alien.getPosition().y;
	//Obliczanie k¹ta miêdzy statkiem obcych a celem
	angle   = M_PI/2 -(atan2(b, a)) ;
}

void alien::move()
{
	_alien.move(Vector2f(sin(angle)*speed, cos(angle)*(speed)));

}

bool alien::reloadWeapon()
{
	if (reload <= 0) {
		reload = rand() % 50 + 50;
		return true;
	}
	else {
		reload--;
		return false;
	}
}

shot alien::shoot()
{
	int pom = (rand() % 11) - 5;
	return shot(0, 3, 0.05, _alien.getPosition().x, _alien.getPosition().y, angle += (M_PI / 180)* pom);
}

Sprite alien::returnAlien()
{
	return _alien;
}

void alien::infotemp()
{
	cout << "reload" << reload << endl;
}
