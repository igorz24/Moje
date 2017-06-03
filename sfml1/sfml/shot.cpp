#include "shot.h"



shot::shot(const shot & other): type(other.type), speed(other.speed), angle(other.angle), scale(other.scale), texture(other.texture), _shot(other._shot)
{
	if (!texture.loadFromFile("shot.png")) {
		cout << "Shot1 didn't load!!!" << endl;
		//Wyrzucenie wyj¹tku
		throw 0;
	}
	_shot.setTexture(texture);
}

void shot::load()
{

		if (!texture.loadFromFile("shot.png")) {
			cout << "Shot1 didn't load!!!" << endl;
			//Wyrzucenie wyj¹tku
			throw 0;
		}
		_shot.setTexture(texture);
}

void shot::initialize(float originX, float originY)
{
	_shot.setScale(scale, scale);
	_shot.setOrigin(Vector2f(_shot.getTexture()->getSize().x * 0.5, _shot.getTexture()->getSize().y * 0.5));
	_shot.setPosition(Vector2f(originX, originY));
	if(type == false)
	_shot.setColor(Color::Green);
	_shot.setRotation(90 -angle*180/M_PI);

}

void shot::move()
{
	_shot.move(Vector2f(sin(angle)*speed, cos(angle)*(speed)));
}

bool shot::returnType()
{
	return type;
}

void shot::draw(RenderWindow & w)
{
	w.draw(_shot);
}


Sprite shot::returnShot()
{
	return _shot;
}




