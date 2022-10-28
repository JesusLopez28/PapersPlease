#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
#include "Person.h"
#include "Document.h"

using namespace std;

Person::Person(){}

string Person::GetName(){
	  return name;
  }

  string Person::GetLastName(){
	  return last_name;
  }

  string Person::GetAge(){
	  return age;
  }

  string Person::GetGender(){
	  return gender;
  }

  string Person::GetNationality(){
	  return nationality;
  }

  string Person::GetPosition(){
	  return position;
  }

  string Person::GetStatus(){
	  return status;
  }

  string Person::GetReason(){
	  return reason;
  }

  void Person::PrintPerson(){
	  cout << "PERSONA " << position << endl;
	  cout << "Nombre: " << name << endl;
	  cout << "Apellido: " << last_name << endl;
	  cout << "Edad: " << age << endl;
	  cout << "Genero " << gender << endl;
	  cout << "Nacionalidad: " << nationality << endl << endl << endl;
	  cout << "INSTRUCCIONES: Debe validar que todos los datos de los documentos sean iguales." << endl;
  }

