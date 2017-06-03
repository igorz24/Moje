#ifndef SCORES_H
#define SCORES_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

struct score {
	int points;
	string player;
};


class scores
{
private:
	vector<score> leaderboard;
	score actualScore;

public:
	scores();
	~scores();
	void changePoints(int change);
	int getPoints();
	string getPlayer();
	vector<score> getLeaderboard();
	void loadLeaderboard();
	void saveLeaderboard();
	void setPlayerName(string name);
	void updateLeaderboard();
	static bool compareStructs(const score &a, const score &b);
	void printLeaderboard();
	string getScoreIAsString(int i);
	int returnPoints();
	void resetPoints();

	// Kolejnoœæ
	// Load
	// SetPlayerName
	// Gra
	// Update
	// Save

	/*scores a;
	a.loadLeaderboard();
	a.setPlayerName();
	a.changePoints(3150);
	a.updateLeaderboard();
	a.printLeaderboard();
	a.saveLeaderboard();*/
};
#endif
