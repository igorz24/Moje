#ifndef MENU_H
#define MENU_H
#include <SFML\Graphics.hpp>
using namespace std;
using namespace sf;
#define MAX_ITEMS 3


class menu
{
public:
	menu(float width,  float height);
	~menu();

	void draw(RenderWindow & window);
	void moveUp();
	void moveDown();
	int getCurrentIndex();

private:
	int currentItemIndex;
	Font font;
	Text item[MAX_ITEMS];

};

#endif
