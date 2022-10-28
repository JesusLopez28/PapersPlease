#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
#include "Player.h"

using namespace std;

Player::Player(string username) {
	this->username = username;
}

int Player::GetScore(){
	return score;
}

void Player::SubtractScore() {
	score--;
}

void Player::AddScore() {
	score++;
}

void Player::SubtractDoubleScore() {
	score -= 2;
}

void Player::AddDoubleScore() {
	score += 2;
}
