#include "sound.h"



sound::sound(string path, bool type)
{
	initialize(path, type);
}

void sound::initialize(string path, bool type)
{
	if (!type) {
		if (!buffer.loadFromFile(path)) {
			cout << path << " - cannot find file!" << endl;
			throw 0;
		}

		_sound.setBuffer(buffer);
		_sound.setVolume(10);
	}
	else {
		if (!_music.openFromFile(path)) {
			cout << path << " - cannot find file!" << endl;
			throw 0;
		}
		_music.setVolume(10);
	}
}

void sound::playSound()
{
	_sound.play();
	
}

void sound::playMusic()
{
	_music.play();
}



