#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
#include "Document.h"

using namespace std;

void Document::PrintDocument() {
	cout << "Nombre: " << name << endl;
	cout << "Apellido: " << last_name << endl;
	cout << "Edad: " << age << endl;
	cout << "Fecha de nacimiento: " << DateBirth << endl;
	cout << "Vigencia: " << Validity << endl;
	cout << "Genero: " << Gender << endl;
	cout << "CURP: " << CURP << endl;
}

string Document::GetName(){
	return name;
}

string Document::GetLastName(){
	return last_name;
}

string Document::GetAge(){
	return age;
}

string Document::GetDateBirth(){
	return DateBirth;
}

string Document::GetValidity(){
	return Validity;
}

string Document::GetGender(){
	return Gender;
}

string Document::GetCURP(){
	return CURP;
}

string Document::GetPosition(){
	return pos;
}

void Id::PrintDocument(){
	cout << "ID" << endl;
	Document::PrintDocument();
	cout << "Residencia: " << Address << endl;
	cout << "Clave de elector: " << ElectorKey << endl; 
}

string Id::GetAdress(){
	return Address;
}

string Id::GetElectorKey(){
	return ElectorKey;
}

void Passport::PrintDocument(){
	cout << "PASSPORT" << endl;
	Document::PrintDocument();
	cout << "Nacionalidad: " << Nationality << endl;
	cout << "Pais de expedicion: " << ExpeditionCountry << endl;
	cout << "Numero de pasaporte: " << PassportNumber << endl;
}

string Passport::GetNationality(){
	return Nationality;
}

string Passport::GetExpeditionCountry(){
	return ExpeditionCountry;
}

string Passport::GetPassportNumber(){
	return PassportNumber;
}

ostream& operator << (ostream& os, Id& id){
	os << "ID" << endl
	<< "Nombre: " << id.GetName() << endl
	<< "Apellido: " << id.GetLastName() << endl
	<< "Edad: " << id.GetAge() << endl
	<< "Fecha de nacimiento: " << id.GetDateBirth() << endl
	<< "Vigencia: " << id.GetValidity() << endl
	<< "Genero " << id.GetGender() << endl
	<< "CURP: " << id.GetCURP() << endl
	<< "Residencia: " << id.GetAdress() << endl
	<< "Clave de elector: " << id.GetElectorKey() << endl;
	return os;
}

ostream& operator << (ostream& os, Passport& passport){
	os << "PASSPORT" << endl
	<< "Nombre: " << passport.GetName() << endl
	<< "Apellido: " << passport.GetLastName() << endl
	<< "Edad: " << passport.GetAge() << endl
	<< "Fecha de nacimiento: " << passport.GetDateBirth() << endl
	<< "Vigencia: " << passport.GetValidity() << endl
	<< "Genero " << passport.GetGender() << endl
	<< "CURP: " << passport.GetCURP() << endl
	<< "Nacionalidad: " << passport.GetNationality() << endl
	<< "Pais de expedicion: " << passport.GetExpeditionCountry() << endl
	<< "Numero de pasaporte: " << passport.GetPassportNumber() << endl;
	return os;
}
