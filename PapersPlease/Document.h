#pragma once
#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;

class Document {
public:
	Document(string pos, string name, string last_name, string age, string DateBirth, string Validity, string Gender, string CURP) {
		this->pos = pos;
		this->name = name;
		this->last_name = last_name;
		this->age = age;
		this->DateBirth = DateBirth;
		this->Validity = Validity;
		this->Gender = Gender;
		this->CURP = CURP;
	};
	virtual void PrintDocument()=0;
	string GetName();
	string GetLastName();
	string GetAge();
	string GetDateBirth();
	string GetValidity();
	string GetGender();
	string GetCURP();
	string GetPosition();
private:
	string pos;
	string name;
	string last_name;
	string age;
	string DateBirth;
	string Validity;
	string Gender;
	string CURP;
};

inline void operator << (ostream& os, Document& documento) {
	documento.PrintDocument();
}

class Id : public Document {
public:
	Id(string pos, string name, string last_name, string age, string DateBirth, string Validity, string Gender, string CURP, string _Address, string _ElectorKey)
		: Document(pos, name, last_name, age, DateBirth, Validity, Gender, CURP) {
		this->Address = _Address;
		this->ElectorKey = _ElectorKey;
	};
	void PrintDocument() override;
	string GetAdress();
	string GetElectorKey();
	friend ostream& operator << (ostream& os, Id& id);
private:
	string Address;
	string ElectorKey;
};

class Passport : public Document {
public:
	Passport(string pos, string name, string last_name, string age, string DateBirth, string Validity, string Gender, string CURP, string _Nationality, string _ExpeditionCountry, string _PassportNumber)
		: Document(pos, name, last_name, age, DateBirth, Validity, Gender, CURP) {
		this->Nationality = _Nationality;
		this->ExpeditionCountry = _ExpeditionCountry;
		this->PassportNumber = _PassportNumber;
	};
	void PrintDocument() override;
	string GetNationality();
	string GetExpeditionCountry();
	string GetPassportNumber();
	friend ostream& operator << (ostream& os, Passport& passport);
private:
	string Nationality;
	string ExpeditionCountry;
	string PassportNumber;
};