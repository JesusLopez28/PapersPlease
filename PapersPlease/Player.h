#pragma once
#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;

class Player
{
public:
	Player(string username);
	int GetScore();
	void SubtractScore();
	void AddScore();
	void SubtractDoubleScore();
	void AddDoubleScore();
private:
	string username;
	unsigned int score = 0;
};