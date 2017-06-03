#include "communicat.h"



communicat::communicat()
{
	if (!font.loadFromFile("Capture_it.ttf")) {
		throw("Nie udalo sie wczytac czcionki");
	};
	text.setFont(font);
	text.setCharacterSize(24);
	sentence = "";
}


communicat::~communicat()
{
}

void communicat::setPosition(int x, int y)
{
	text.setPosition(x, y);
}

void communicat::setString(string x)
{
	sentence = x;
	text.setString(sentence);
}

string communicat::getString()
{
	return sentence;
}

Text communicat::getText()
{
	return text;
}

void communicat::addChar(char x)
{
	sentence += x;
}

void communicat::backspace()
{
	sentence.erase(sentence.size() - 1, sentence.size());
}

void communicat::stringToText()
{
	text.setString(sentence);
}

void communicat::draw(RenderWindow & window)
{
	window.draw(text);
}
