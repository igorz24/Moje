#include "scores.h"



scores::scores()
{
	actualScore.points = 0;
	actualScore.player = "";
}


scores::~scores()
{
	if (leaderboard.size() != 0)
		leaderboard.clear();

}

void scores::changePoints(int change)
{
	actualScore.points += change;
}

int scores::getPoints()
{
	return actualScore.points;
}

string scores::getPlayer()
{
	return actualScore.player;
}

vector<score> scores::getLeaderboard()
{
	return leaderboard;
}

void scores::loadLeaderboard()
{
	ifstream file;
	file.open("leaderboard.txt");
	if (!file.is_open()) throw ("Pliku nie uda³o siê otworzyc");
	score temp;

	
	while (file >> temp.player)
	{

		file >> temp.points;
		leaderboard.push_back(temp);

	}
}

void scores::saveLeaderboard()
{
	ofstream file("leaderboard.txt");
	if (file.is_open())
	{
		for (int i = 0; i < leaderboard.size(); i++) {
			file << leaderboard[i].player << " ";
			file << leaderboard[i].points << endl;
		}
		file.close();
	}
	else throw("Unable to open leaderboard file, the game will continue without saving scores");
	return;
	
}

void scores::setPlayerName(string name)
{
	actualScore.player = name;
}

void scores::updateLeaderboard()
{
	leaderboard.push_back(actualScore);
	sort(leaderboard.begin(), leaderboard.end(), compareStructs);
}

bool scores::compareStructs(const score & a, const score & b)
{
	return a.points > b.points;
}

void scores::printLeaderboard()
{
	for (int i = 0; i < leaderboard.size(); i++) {
		cout << leaderboard[i].player << "\t" << leaderboard[i].points << endl;
	}
}

string scores::getScoreIAsString(int i)
{
	string pom;
	if (i < leaderboard.size()) {
		pom = leaderboard[i].player;
		ostringstream ss;
		ss << leaderboard[i].points;
		pom += " " + ss.str();
	}
	else
		pom = "------";
	return pom;

}

int scores::returnPoints()
{
	return actualScore.points;
}

void scores::resetPoints()
{
	actualScore.points = 0;
}

