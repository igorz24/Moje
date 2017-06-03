#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <iostream>
#include <sstream>
#include <typeinfo>
#include <string.h>
#include "entity.h"
#include "animation.h"
#include "bullet.h"
#include "player.h"
#include "alien.h"
#include "sound.h"
#include "scores.h"
#include "menu.h"
#include "communicat.h"

using namespace sf;
using namespace std;



bool isCollide(Entity *a, Entity *b)
{
	return (b->x - a->x)*(b->x - a->x) +
		(b->y - a->y)*(b->y - a->y)<
		(a->R + b->R)*(a->R + b->R);
}


int main()
{	//------------------------------------------------------------------------
	// Inicjalizacja
	srand(time(0));

	RenderWindow app(VideoMode(W, H), "Space Shooter!", Style::None);
	app.setFramerateLimit(60);
	
	menu _menu(app.getSize().x, app.getSize().y);
	communicat points, name, nameAlert, hallOfFame;
	communicat top10[10];
	nameAlert.setString("What is your name, Pilot?");
	hallOfFame.setString("Hall Of Fame");
	hallOfFame.setPosition(W / 2 - 30, H / 13);
	nameAlert.setPosition(W / 3, H / 3);
	name.setPosition(W / 2, H / 2);



	Texture t1, t2, t3, t4, t5, t6, t7;
	t1.loadFromFile("images/spaceship.png");
	t2.loadFromFile("images/earth.jpg");
	t3.loadFromFile("images/explosions/type_C.png");
	t4.loadFromFile("images/alien.png");
	t5.loadFromFile("images/fire_blue.png");
	t6.loadFromFile("images/fire_red.png");
	t7.loadFromFile("images/explosions/type_B.png");

	t1.setSmooth(true);
	t2.setSmooth(true);

	Sprite background(t2);

	Animation sExplosion(t3, 0, 0, 256, 256, 48, 0.5);
	Animation sBulletBlue(t5, 0, 0, 32, 64, 16, 0.8);
	Animation sBulletRed(t6, 0, 0, 32, 64, 16, 0.8);
	Animation sPlayer(t1, 40, 0, 40, 40, 1, 0);
	Animation sPlayer_go(t1, 40, 40, 40, 40, 1, 0);
	Animation sExplosion_ship(t7, 0, 0, 192, 192, 64, 0.5);
	Animation sAlien(t4, 0, 0, 64, 64, 1, 0);

	sound laser1("laser1.wav", 0);
	sound laser2("laser2.wav", 0);
	sound boom("explosion.wav", 0);
	sound music("space.wav", 1);

	ostringstream ss;
	scores result;
	try {
		result.loadLeaderboard();
	}
	catch (string a) {
		cout << "Nastapil wyjatek: " << a << endl;
	}
	for (int i = 0; i < 10; i++) {
		top10[i].setString(result.getScoreIAsString(i));
		top10[i].stringToText();
		top10[i].setPosition(W / 2 - 30, H*(i + 2) / 13);
	}

	bool gamePaused = 0;

	music.playMusic();

	std::list<Entity*> entities;
	int windowMode = 0;
	player *p = new player();
	

	
	//---------------------------------------------------------------------------------
	/////main loop/////
	while (app.isOpen()) {
		Event event;

		switch (windowMode) {

		case 3: {
			
			while (app.pollEvent(event))
				switch (event.type) {

				case Event::TextEntered: {
					if (event.text.unicode >= 32 && event.text.unicode <= 126)
						name.addChar((char)event.text.unicode);
					else if (event.text.unicode == 8 && name.getString().size() > 0)
						name.backspace();
					name.stringToText();
					break;
				}

				case Event::KeyReleased:
					switch (event.key.code) {
					case Keyboard::Return:
						result.setPlayerName(name.getString());
						windowMode = 1;
						result.resetPoints();
						entities.clear();
						p->settings(sPlayer, W / 2, H / 2, 0, 20);
						entities.push_back(p);

						for (int i = 0; i < 5; i++)
						{
							alien *a = new alien();
							a->settings(sAlien, rand() % W, -100, rand() % 360, 25);
							a->anim.sprite.setScale(0.5, 0.5);
							entities.push_back(a);
						}

						break;

					case Keyboard::Escape:
						windowMode = 0;
						break;

					}

				}
			//Draw
			app.clear();
			app.draw(background);
			nameAlert.draw(app);
			name.draw(app);
			app.display();
			break;
		}

		case 0: {

			
			while (app.pollEvent(event))
				switch (event.type) {

				case Event::KeyReleased:
					switch (event.key.code) {
					case Keyboard::W: _menu.moveUp();
						break;
					case Keyboard::S: _menu.moveDown();
						break;
					case Keyboard::Return:
						switch (_menu.getCurrentIndex()) {
						case 0: {
							windowMode = 3;
							break; }
						case 1: windowMode = 2; break;
						case 2: app.close(); break;
						}
						break;
					case Keyboard::Escape: app.close();
						break;
					}
				}

			// Draw
			app.clear();
			app.draw(background);
			_menu.draw(app);
			app.display();


			break;
		}

		case 1: {


			
			while (app.pollEvent(event))
			{
				if ((event.type == sf::Event::KeyReleased) && (event.key.code == Keyboard::P || event.key.code == Keyboard::Space)) {
					gamePaused = !gamePaused;
				}


				if (event.type == Event::Closed)
					app.close();

				if (event.type == Event::KeyReleased) {
					if (event.key.code == Keyboard::Escape) {
						windowMode = 0;
					}

				}

				if (!gamePaused)
					if (event.type == Event::MouseButtonPressed)
					{

						bullet *b = new bullet(1, Mouse::getPosition(app).x, Mouse::getPosition(app).y, entities.front()->x, entities.front()->y);
						b->settings(sBulletBlue, p->x, p->y, 90 - b->angle2 * 180 / M_PI, 10);
						entities.push_back(b);
						laser1.playSound();
					}


			}

			if (!gamePaused) {
				if (Keyboard::isKeyPressed(Keyboard::D)) p->angle += 3;
				if (Keyboard::isKeyPressed(Keyboard::A))  p->angle -= 3;
				if (Keyboard::isKeyPressed(Keyboard::W)) p->thrust = true;
				else p->thrust = false;
			}

			//----------------------------------------------------------
			// Update





			for (auto a : entities)
				for (auto b : entities)
				{
					if (typeid(*a).name() != typeid(*b).name()) {
						if (a->name == "alien" && b->name == "bulletBlue")
							if (isCollide(a, b))
							{
								a->life = false;
								b->life = false;

								Entity *e = new Entity();
								e->settings(sExplosion, a->x, a->y);
								e->name = "explosion";
								entities.push_back(e);
								boom.playSound();
								result.changePoints(10);

								alien *a1 = new alien();
								alien *a2 = new alien();

								int pomRand = rand() % 4;
								int w, h;
								switch (pomRand) {
								case 0:
									w = -300;
									h = rand() % 800;
									break;
								case 1:
									w = 1500;
									h = rand() % 800;
									break;
								case 2:
									w = rand() % 1200;
									h = -300;
									break;
								case 3:
									w = rand() % 1200;
									h = 1100;
									break;

								}

								a1->settings(sAlien, w, h, rand() % 360, 25);
								a2->settings(sAlien, -w, -h, rand() % 360, 25);
								a1->anim.sprite.setScale(0.5, 0.5);
								a2->anim.sprite.setScale(0.5, 0.5);
								entities.push_back(a1);
								if (rand() % 10 == 0)
									entities.push_back(a2);

							}

						if (a->name == "player" && (b->name == "alien" || b->name == "bulletRed"))
							if (isCollide(a, b))
							{
								b->life = false;
								windowMode = 2;
								result.updateLeaderboard();
								for (int i = 0; i < 10; i++) {
									top10[i].setString(result.getScoreIAsString(i));
									top10[i].stringToText();
									top10[i].setPosition(W / 2 - 30, H*(i + 2) / 13);
								}
								Entity *e = new Entity();
								e->settings(sExplosion_ship, a->x, a->y);
								e->name = "explosion";
								entities.push_back(e);
								boom.playSound();
								p->settings(sPlayer, W / 2, H / 2, 0, 20);
								p->dx = 0; p->dy = 0;
								result.resetPoints();
							}
					}
				}


			if (p->thrust)  p->anim = sPlayer_go;
			else   p->anim = sPlayer;


			for (auto e : entities)
				if (e->name == "explosion")
					if (e->anim.isEnd()) e->life = 0;

			if (!gamePaused)
				for (auto i = entities.begin(); i != entities.end();)
				{

					Entity *e = *i;
					if (e->name == "alien") {
						e->update(entities.front()->x, entities.front()->y);
						if (rand() % 1000 == 0) {
							bullet *b = new bullet(0, entities.front()->x, entities.front()->y, e->x, e->y);
							b->settings(sBulletRed, e->x, e->y, 90 - b->angle2 * 180 / M_PI, 10);
							entities.push_back(b);
							laser2.playSound();
						}
					}
					else
						e->update();
					e->anim.update();


					if (e->life == false) { i = entities.erase(i); delete e; }
					else i++;

				}


			ss.str("");
			ss << result.returnPoints();
			points.setString(ss.str());
			points.setPosition(10, 10);


			//////draw//////
			app.draw(background);

			for (auto i : entities)
				i->draw(app);
			app.draw(points.getText());
			app.display();

			break;
		}

		case 2: {

			
			while (app.pollEvent(event))
				switch (event.type) {

				case Event::KeyReleased:
					switch (event.key.code) {
					case Keyboard::Return:
						windowMode = 0;
						break;

					case Keyboard::Escape:
						windowMode = 0;
						break;

					}

				}
			//Draw
			app.clear();
			app.draw(background);
			hallOfFame.draw(app);
			for (int i = 0; i < 10; i++) {
				top10[i].draw(app);
			}

			app.display();
			break;
		}
		
		}
	}

	while (!entities.empty()) {
		delete entities.front(); 
		entities.pop_front();
	}
	try {
		result.saveLeaderboard();
	}
	catch (string a) {
		cout << "Nastapil wyjatek: " << a << endl;
	}
	return 0;
}



