#pragma once
#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>
#include "Document.h"

using namespace std;

class Person{
public:
	Person();
	Person(string _position, string _name, string _last_name, string _age, string _gender, string _nationality, string _status, string _reason) {
		this->position = _position;
		this->name = _name;
		this->last_name = _last_name;
		this->age = _age;
		this->gender = _gender;
		this->nationality = _nationality;
		this->status = _status;
		this->reason = _reason;
	}
	string GetName();
	string GetLastName();
	string GetAge();
	string GetGender();
	string GetNationality();
	string GetPosition();
	string GetStatus();
	string GetReason();
	std::list<Document*> documents;
	list<Document*>::iterator iteratorD = documents.begin();
	void PrintPerson();
private:
	string position;
	string name;
	string last_name;
	string age;
	string gender;
	string nationality;
	string status;
	string reason;
};
