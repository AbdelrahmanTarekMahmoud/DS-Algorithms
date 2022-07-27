#include <stdio.h>
#include <iostream>
#include <stdlib.h>


#include <iostream>
#include <string>
class GameEntry
{
public:
	GameEntry(const std::string& n = " ", int s = 0);
	std::string getName() const;
	int getScore() const;
private:
	int score;
	std::string name;
};

GameEntry::GameEntry(const std::string& n, int s) :name(n), score(s) {}
std::string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }

class Score
{
public:
	Score(int ME = 10);
	~Score();
	void add(const GameEntry& e);
	GameEntry remove(int i);
	void print();
private:
	int maxEntries;
	int numEntries;
	GameEntry* entries;
};
Score::Score(int ME)
{
	maxEntries = ME;
	entries = new GameEntry[maxEntries];
	numEntries = 0;
}
Score::~Score()
{
	delete[]entries;
}
//If this causes the number of entries to exceed maxEntries,
//the smallest is removed.
void Score::add(const GameEntry& e)
{
	int newscore = e.getScore();
	if (numEntries == maxEntries)
	{
		if (newscore <= entries[maxEntries - 1].getScore())
		{
			return;
		}
	}
	else
	{
		numEntries++;
	}
	int index = numEntries - 2;
	while (index >= 0 && newscore > entries[index].getScore())
	{
		entries[index + 1] = entries[index];
		index--;
	}
	entries[index + 1] = e;
}
GameEntry Score::remove(int i)
{
	GameEntry e = entries[i];
	for (int index = 1;index < numEntries;index++)
	{
		entries[index - 1] = entries[index];
	}
	numEntries--;
	return e;
}
void Score::print()
{
	for (int i = 0; i < numEntries; i)
	{
		std::cout << entries[i].getScore() << std::endl;
	}
}
int main()
{
int main()
{
	GameEntry e1("Mohamed", 1500);
	GameEntry e2("Mohamed", 100);
	GameEntry e3("Mohamed", 1300);
	GameEntry e4("Mohamed", 1600);
	GameEntry e5("Mohamed", 800);
	GameEntry e6("Mohamed", 500);
	GameEntry e7("Mohamed", 400);
	GameEntry e8("Mohamed", 107);
	Score s;
	s.add(e1);
	s.add(e2);
	s.add(e3);
	s.add(e4);
	s.add(e5);
	s.add(e6);
	s.add(e7);
	s.add(e8);
	s.print();
	return 0;
}
}
