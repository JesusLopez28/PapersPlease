#include <iostream>
#include <stdexcept>
#include <list>
#include <fstream>
#include <algorithm>
#include <Windows.h>
#include "Game.h"
#include "Person.h"
#include "Document.h"
#include "Player.h"
#include "SFML/Audio.hpp"

using namespace std;
using namespace sf;

void Game::run(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 1);
	SoundBuffer buffer, buffer2;
	Sound correco, incorreco;
	if (!buffer.loadFromFile("correcto.ogg") || !buffer2.loadFromFile("incorrecto.ogg")) {
		cout << "No se pudo";
	}
	correco.setBuffer(buffer);
	correco.setVolume(80);
	incorreco.setBuffer(buffer2);
	incorreco.setVolume(80);
	sf::Music musica;
	musica.openFromFile("musica.ogg");
	musica.setLoop(true);
	musica.play();
	Fill();
	string Username;
	string reason_str;
	string reason, the_status = "1", the_reason, chose, bueno = "1";
	bool continuar = true;
	while (continuar == true) {
		system("cls");
		SetConsoleTextAttribute(hConsole, 2);
		cout << "----------Proyecto Parcial 2 POO----------" << endl;
		cout << "Jesus Alejandro Lopez Rosales-22110104-2|O\n\n" << endl;
		SetConsoleTextAttribute(hConsole, 5);
		cout << " -----   -----   -----   ------  -----   ----     -----          -----  -----   ----   -----" << endl;
		cout << "|     | |     | |     | |       |     | |        |     | |      |      |     | |      |" << endl;
		cout << "|-----  |-----| |-----  |---    |-----   ----    |-----  |      |---   |-----|  ----  |---" << endl;
		cout << "|       |     | |       |       |-           |   |       |      |      |     |      | |" << endl;
		cout << "|       |     | |        ------ |  - _   ----  / |       |_____  ----- |     |  ----   -----" << endl;
		SetConsoleTextAttribute(hConsole, 2);
		cout << "\n\nIngrese un nombre de usuario: ";
		cin >> Username;
		Player jugador(Username);
		system("cls");


		for (list<Person*>::iterator iteratorP = persons.begin(); iteratorP != persons.end(); ++iteratorP) {
			cout << "-------------------------------------------------------------" << endl;
			SetConsoleTextAttribute(hConsole, 1);
			cout << **iteratorP;
			SetConsoleTextAttribute(hConsole, 2);
			cout << "-------------------------------------------------------------" << endl;
			system("pause");
			system("cls");
			Person* persona = *iteratorP;
			for (list<Document*>::iterator iteratorD = persona->documents.begin(); iteratorD != persona->documents.end(); iteratorD++) {
				cout << "-------------------------------------------------------------" << endl;
				SetConsoleTextAttribute(hConsole, 1);
				cout << **iteratorD;
				SetConsoleTextAttribute(hConsole, 2);
				cout << "-------------------------------------------------------------" << endl;
			}
			cout << endl << endl;
			SetConsoleTextAttribute(hConsole, 6);
			cout << "Desea rechazar o aceptar la entrada de esta persona al pais? " << endl;
			cout << "0.-Rechazar" << endl;
			cout << "1.-Aceptar" << endl;
			cout << "Elija una opcion: ";
			cin >> chose;
			cout << endl;
			if (chose == "0") {
				SetConsoleTextAttribute(hConsole, 4);
				cout << "-------------------------------------------------------------" << endl;
				cout << "En que parametro hay diferencias? " << endl;
				cout << "1.-Nombre" << endl;
				cout << "2.-Apellido" << endl;
				cout << "3.-Edad" << endl;
				cout << "4.-Fecha de nacimiento" << endl;
				cout << "5.-CURP" << endl;
				cout << "Elija una opcion: ";
				cin >> reason;
			}
			system("cls");
			Person* per = *iteratorP;
			the_status = per->GetStatus();
			the_reason = per->GetReason();

			if (the_status == "1" && chose == "1") {
				jugador.AddScore();
				correco.play();
				SetConsoleTextAttribute(hConsole, 1);
				cout << "MUY BIEN!!" << endl;
			}
			else if (the_status == "0" && chose == "0" && the_reason!= reason) {
				jugador.AddScore();
				correco.play();
				SetConsoleTextAttribute(hConsole, 1);
				cout << "MUY BIEN!!" << endl;
			}
			else if (the_status == "1" && chose == "0") {
				jugador.SubtractScore();
				incorreco.play();
				SetConsoleTextAttribute(hConsole, 4);
				cout << "MAL!!" << endl;
			}
			else if (the_status == "0" && chose == "0" && the_reason == reason) {
				jugador.AddDoubleScore();
				correco.play();
				SetConsoleTextAttribute(hConsole, 1);
				cout << "EXCELENTE!!" << endl;
			}
			else if (the_status == "0" && chose == "1") {
				jugador.SubtractDoubleScore();
				incorreco.play();
				SetConsoleTextAttribute(hConsole, 4);
				cout << "HORRIBLE!!" << endl;
			}
			system("pause");
			system("cls");
		}
		SetConsoleTextAttribute(hConsole, 2);
		cout << "-------------------------------------------------------------" << endl;
		cout << "FIN DEL JUEGO: " << endl;
		cout << "JUGADOR: " << Username << endl;
		cout << "PUNTAJE FINAL: " << jugador.GetScore() << endl;
		cout << "-------------------------------------------------------------" << endl;
		system("pause");
		system("cls");
		cout << "Desea jugar de nuevo? " << endl;
		cout << "0.-No" << endl;
		cout << "1.-Si" << endl;
		cout << "Elija una opcion: ";
		cin >> continuar;
	}
	system("cls");
	cout << "\n-----------------\nFin del programa.\nGRACIAS POR JUGAR\n-----------------\n\n" << endl;
}


void Game::Fill(){
	ifstream Id_txt, Passport_txt, Persons_txt;
	Id_txt.open("Id.txt", ios::in);
	Passport_txt.open("Passport.txt", ios::in);
	Persons_txt.open("Persons.txt", ios::in);
	string pos2, name2, lastN2, age2, gender2, nationality2, status, reason;
	string pos, name, last_name, age, DateBirth, Validity, Gender, CURP, Address, ElectorKey;
	string pos1, name1, last_name1, age1, DateBirth1, Validity1, Gender1, CURP1, Nationality, ExpeditionCountry, PassportNumber;

	while (!Persons_txt.eof() && !Id_txt.eof() && !Passport_txt.eof()) {
		Persons_txt >> pos2 >> name2 >> lastN2 >> age2 >> gender2 >> nationality2 >> status >> reason;
		Person* persona = new Person(pos2, name2, lastN2, age2, gender2, nationality2, status, reason);
		persons.push_back(persona);

		Id_txt >> pos >> name >> last_name >> age >> DateBirth >> Validity >> Gender >> CURP >> Address >> ElectorKey;
		Document* identification = new Id(pos, name, last_name, age, DateBirth, Validity, Gender, CURP, Address, ElectorKey);
		persona->documents.push_back(identification);

		Passport_txt >> pos1 >> name1 >> last_name1 >> age1 >> DateBirth1 >> Validity1 >> Gender1 >> CURP1 >> Nationality >> ExpeditionCountry >> PassportNumber;
		Document* passport = new Passport(pos1, name1, last_name1, age1, DateBirth1, Validity1, Gender1, CURP1, Nationality, ExpeditionCountry, PassportNumber);
		persona->documents.push_back(passport);
	}
}
