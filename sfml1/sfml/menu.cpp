#include "menu.h"






menu::menu(float width, float height)
{
	if (!font.loadFromFile("Capture_it.ttf")) {
		throw("Nie udalo sie wczytac czcionki");
	}
	
	item[0].setFont(font);
	item[0].setFillColor(Color::Red);
	item[0].setString("Start Game");
	item[0].setPosition(Vector2f(width / 2, height / (MAX_ITEMS + 1) * 1));

	item[1].setFont(font);
	item[1].setFillColor(Color::White);
	item[1].setString("Records");
	item[1].setPosition(Vector2f(width / 2, height / (MAX_ITEMS + 1) * 2));

	item[2].setFont(font);
	item[2].setFillColor(Color::White);
	item[2].setString("Exit");
	item[2].setPosition(Vector2f(width / 2, height / (MAX_ITEMS + 1) * 3));

	currentItemIndex = 0;
}

menu::~menu()
{
}

void menu::draw(RenderWindow & window)
{
	for (int i = 0; i < MAX_ITEMS; i++) {
		window.draw(item[i]);
	}
}

void menu::moveUp()
{
	if (currentItemIndex - 1 >= 0) {
		item[currentItemIndex].setFillColor(Color::White);
		currentItemIndex--;
		item[currentItemIndex].setFillColor(Color::Red);
	}
}

void menu::moveDown()
{
	if (currentItemIndex + 1 < MAX_ITEMS) {
		item[currentItemIndex].setFillColor(Color::White);
		currentItemIndex ++;
		item[currentItemIndex].setFillColor(Color::Red);
	}
}

int menu::getCurrentIndex()
{
	return currentItemIndex;
}
