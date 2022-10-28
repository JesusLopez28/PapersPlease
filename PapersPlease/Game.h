#pragma once
#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
#include "Document.h"
#include "Player.h"
#include "Person.h"
#include "Document.h"

using namespace std;

class Game{
public:
	void run();
private:
	void Fill();
	std::list<Person*> persons;
	list<Person*>::iterator iteratorP = persons.begin();
};

inline void operator << (ostream& os, Person& persona) {
	persona.PrintPerson();
}
