#ifndef SOUND_H
#define SOUND_H
#include <SFML/Audio.hpp>
#include <iostream>


using namespace std;
using namespace sf;

class sound
{
private:
	SoundBuffer buffer;
	Sound _sound;
	Music _music;
public:
	sound(string path, bool type);
	~sound() = default;

	void initialize(string path, bool type);
	void playSound();
	void playMusic();


};

#endif