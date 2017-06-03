#ifndef COMMUNICAT_H
#define COMMUNICAT_H
#include <SFML\Graphics.hpp>
using namespace std;
using namespace sf;

class communicat
{
private:
	Text text;
	Font font;
	string sentence;
public:
	communicat();
	~communicat();

	void setPosition(int x, int y);
	void setString(string x);
	string getString();
	Text getText();
	void addChar(char x);
	void backspace();
	void stringToText();
	void draw(RenderWindow & window);
};

#endif