﻿#include <iostream>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <conio.h>
#include <sstream>
using namespace std;


struct Uzytkownik;

vector<Uzytkownik> odczytUzytkownikowZPliku(vector <Uzytkownik> uzytkownicy);

vector <Uzytkownik> rejestracja(vector <Uzytkownik> uzytkownicy);

int logowanie(vector <Uzytkownik> uzytkownicy);

vector<Uzytkownik> usuwanieUzytkownika(vector <Uzytkownik> uzytkownicy, int idZalogowanegoUzytkownika);

vector <Uzytkownik> zmianaHasla(vector <Uzytkownik> uzytkownicy, int idZalogowanegoUzytkownika);

string konwerjsaIntNaString(int liczba);

string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);

void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);

void zmianaHaslaZalogowanegoUzytkownika(vector <Uzytkownik> &uzytkownicy, int idZalogowanegoUzytkownika);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Znajomy;

int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

int konwersjaStringNaInt(string liczba);

string zamienDaneZnajomegoNaLinieZDanymiOddzielonaPionowymiKreskami(Znajomy znajomy);

string pobierzLiczbe(string tekst, int pozycjaZnaku);

vector<Znajomy> odczytZnajomychZPliku(vector<Znajomy> wektorZnajomych, vector <Uzytkownik> uzytkownicy);

int wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector <Znajomy> &wektorZnajomych, int idZalogowanegoUzytkownika);

Znajomy pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

//vector<Znajomy> dodajZnajomegoDoListyKontaktow(vector<Znajomy> wektorZnajomych, vector <Uzytkownik> uzytkownicy, int idZalogowanegoUzytkownika);
//int dodajZnajomegoDoListyKontaktow(vector<Znajomy> wektorZnajomych, vector <Uzytkownik> uzytkownicy, int idZalogowanegoUzytkownika);

void dopiszAdresataDoPliku(Znajomy adresat);

Znajomy podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);

int dodajAdresata(vector <Znajomy> &adresaci, int idZalogowanegoUzytkownika, int idOstatniegoAdresata);

bool wyswietlWszystkichZnajomychZWektora(vector<Znajomy> wektorZnajomych);

bool szukanieKonkretnegoImieniaWWektorze(vector<Znajomy> wektorZnajomych, string imieDoWyszukania);

void wyszukiwanieZnajomegoPoImieniu(vector<Znajomy> wektorZnajomych);

bool szukanieKonkretnegoNazwiskaWWektorze(vector<Znajomy> wektorZnajomych, string nazwiskoDoWyszukania);

void wyszukiwanieZnajomegoPoNazwisku(vector<Znajomy> wektorZnajomych);

void wybierzSposobWyszukiwaniaZnajomego(vector <Znajomy> &wektorZnajomych);

bool szukanieKonkretnegoIdWWektorze(vector<Znajomy> wektorZnajomych, int szukaneId);

int usunZnajomego(vector<Znajomy> wektorZnajomych);

int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsunietegoAdresata, int idOstatniegoAdresata);

int pobierzZPlikuIdOstatniegoAdresata();

int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

int zwrocNumerLiniiSzukanegoAdresata(int idAdresata);

void usunWybranaLinieWPliku(int numerUsuwanejLinii);

void edytujZnajomego(vector <Znajomy> &znajomi);

void zaktualizujDaneWybranegoZnajomego(Znajomy adresat, int idEdytowanegoZnajomego);

void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiZnajomegoOddzielonePionowymiKreskami);

void balladaNaDowidzenia();



int main()
{
	vector <Uzytkownik> uzytkownicy;
	uzytkownicy = odczytUzytkownikowZPliku(uzytkownicy);

	int idZalogowanegoUzytkownika = 0;
	int idOstatniegoAdresata = 0;

	vector<Znajomy> wektorZnajomych;

	while (true)
	{
		if (idZalogowanegoUzytkownika == 0)
		{
			system("cls");
			cout << "1. Rejestracja" << endl;
			cout << "2. Logowanie" << endl;
			cout << "9. Zamknij program" << endl;
			cout << endl;
			cout << "Twoj wybor: " << endl;

			int wybor;
			cin >> wybor;

			switch (wybor)
			{
			case 1:
				uzytkownicy = rejestracja(uzytkownicy);
				break;
			case 2:
				idZalogowanegoUzytkownika = logowanie(uzytkownicy);
				break;
			case 9:
				balladaNaDowidzenia();
			}
		}
		else
		{
			if (wektorZnajomych.empty() == true) {
				idOstatniegoAdresata = wczytajAdresatowZalogowanegoUzytkownikaZPliku(wektorZnajomych, idZalogowanegoUzytkownika);
			}

			int idUsunietegoAdresata;

			system("cls");
			cout << "1. Dodaj znajomego do kontaktow" << endl;
			cout << "2. Wyszukaj znajomego w ksiazce kontaktow" << endl;
			cout << "3. Wyswietl wszystkie kontakty" << endl;
			cout << "4. Usun kontakt" << endl;
			cout << "5. Edytuj kontakt" << endl;
			cout << "6. Zmiana hasla" << endl;
			cout << "7. Wylogowanie" << endl;
			cout << endl;
			cout << "Twoj wybor: " << endl;

			int wyborUrzytkownika;
			cin >> wyborUrzytkownika;

			switch (wyborUrzytkownika)
			{
			case 1:
				//wektorZnajomych = dodajZnajomegoDoListyKontaktow(wektorZnajomych, uzytkownicy, idZalogowanegoUzytkownika);
				dodajAdresata(wektorZnajomych, idZalogowanegoUzytkownika, idOstatniegoAdresata);			
				break;
			case 2:
				wybierzSposobWyszukiwaniaZnajomego(wektorZnajomych);
				break;
			case 3:
				wyswietlWszystkichZnajomychZWektora(wektorZnajomych);				
				break;
			case 4:
				idUsunietegoAdresata = usunZnajomego(wektorZnajomych);
				idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
				break;
			case 5:		
				edytujZnajomego(wektorZnajomych);
				break;
			case 6:				
				zmianaHaslaZalogowanegoUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
				break;
			case 7:
				idZalogowanegoUzytkownika = 0;
				wektorZnajomych.clear();
				break;
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Uzytkownik
{
	int idUzytkownika;
	string login, haslo;
};

vector<Uzytkownik> odczytUzytkownikowZPliku(vector <Uzytkownik> uzytkownicy) {

	cout << "Wczytano dane z pliku" << endl;

	string linia;
	int numerLinii = 1;
	fstream plik;
	Uzytkownik uzytkownik;

	plik.open("uzytkownicy.txt", ios::in);


	if (plik.is_open()) {
		while (getline(plik, linia)) {
			string Uzytkownik[3];
			int dlugoscLinii = linia.length();
			int beginOfWord = 0;
			int lengthOfWord = 0;
			int numerUzytkownika = 0;

			for (int i = 0; i < dlugoscLinii; i++) {

				if ((int)linia[i] == 124) {
					lengthOfWord = i - beginOfWord;
					Uzytkownik[numerUzytkownika] = linia.substr(beginOfWord, lengthOfWord);
					beginOfWord = i + 1;
					numerUzytkownika++;
				}
			}
			uzytkownik.idUzytkownika = atoi(Uzytkownik[0].c_str());
			uzytkownik.login = Uzytkownik[1];
			uzytkownik.haslo = Uzytkownik[2];

			uzytkownicy.push_back(uzytkownik);
		}
		plik.close();

		return uzytkownicy;
	}
	else {
		plik.close();
		return uzytkownicy;
	}

	system("pause");
}

bool czyPlikJestPusty(fstream &plikTekstowy)
{
	plikTekstowy.seekg(0, ios::end);
	if (plikTekstowy.tellg() == 0)
		return true;
	else
		return false;
}

vector <Uzytkownik> rejestracja(vector <Uzytkownik> uzytkownicy)
{
	system("cls");
	fstream plik;
	string loginNowegoUzytkownika, haslo;
	Uzytkownik nowyUzytkownik;

	plik.open("uzytkownicy.txt");
	if (plik.good()) {
		plik.close();
	}
	else {
		plik.open("uzytkownicy.txt", ios::out);
		plik.close();
	}

	cout << "Podaj nazwe uzytkownika: ";
	cin >> loginNowegoUzytkownika;

	int rozmiarWektoraUzytkownicy = uzytkownicy.size();

	int i = 0;
	while (i < rozmiarWektoraUzytkownicy)
	{
		if (uzytkownicy[i].login == loginNowegoUzytkownika)
		{
			cout << endl;
			cout << "Uzytkownik o takim loginie juz istnieje. Wpisz inny login." << endl;
			cout << endl;
			cout << "Podaj nowa nazwe uzytkownika: ";
			cin >> loginNowegoUzytkownika;
			i = 0;
		}
		else {
			i++;
		}
	}
	cout << endl;
	cout << "Podaj haslo: ";
	cin >> haslo;

	int iloscUzytkownikow = uzytkownicy.size();
	int ostatnieID;
	if (uzytkownicy.empty()) {
		ostatnieID = 0;
	}
	else {
		ostatnieID = uzytkownicy[iloscUzytkownikow - 1].idUzytkownika;
	}

	nowyUzytkownik = { ostatnieID + 1, loginNowegoUzytkownika, haslo };

	uzytkownicy.push_back(nowyUzytkownik);

	plik.open("uzytkownicy.txt", ios::out | ios::app);
	if (plik.good()) {
		if (czyPlikJestPusty(plik))
		{
			plik << uzytkownicy[iloscUzytkownikow].idUzytkownika << "|";
			plik << uzytkownicy[iloscUzytkownikow].login << "|";
			plik << uzytkownicy[iloscUzytkownikow].haslo << "|";
		}
		else
		{
			plik << endl;
			plik << uzytkownicy[iloscUzytkownikow].idUzytkownika << "|";
			plik << uzytkownicy[iloscUzytkownikow].login << "|";
			plik << uzytkownicy[iloscUzytkownikow].haslo << "|";
		}

		cout << endl;
		cout << "Uzytkownik dodany" << endl;
		cout << endl;
		system("Pause");
		return uzytkownicy;
	}
	else {
		cout << "Nie udalo sie otworzyc pliku" << endl;
		system("Pause");
	}

	return uzytkownicy;
}

int logowanie(vector <Uzytkownik> uzytkownicy)
{
	if (uzytkownicy.empty())
	{
		cout << endl;
		cout << "Nie ma zadnego uzytkownika" << endl;
		cout << endl;
		system("Pause");
		return 0;
	}

	string loginAktualnegoUzytkownika, hasloAktualnegoUzytkownika;

	int liczbaProb = 0;

	cout << endl;
	cout << "Podaj nazwe uzytkownika: ";
	cin >> loginAktualnegoUzytkownika;

	int rozmiarWektoraUzytkownicy = uzytkownicy.size();

	for (int i = 0; i < rozmiarWektoraUzytkownicy; i++)
	{
		if (uzytkownicy[i].login == loginAktualnegoUzytkownika)
		{
			for (liczbaProb; liczbaProb < 3; liczbaProb++)
			{
				cout << endl;
				cout << "Podaj haslo: ";
				cin >> hasloAktualnegoUzytkownika;

				if (uzytkownicy[i].haslo == hasloAktualnegoUzytkownika)
				{
					cout << endl;
					cout << "Zalogowales sie poprawnie" << endl;
					cout << endl;
					system("Pause");
					return uzytkownicy[i].idUzytkownika;
				}

				if (liczbaProb == 2)
				{
					cout << endl;
					cout << "Nie poprawne haslo! " << endl;
					break;
				}

				cout << endl;
				cout << "Nie poprawne haslo! Sprobuj jeszcze raz." << endl;

			}

			cout << endl;
			cout << "Za duzo prob! Blokada na 3 sekundy." << endl;
			Sleep(3000);
			return 0;

		}
	}

	cout << endl;
	cout << "Nie ma uzytkownika z takim loginem" << endl;
	cout << endl;
	system("Pause");
	return 0;
}

vector<Uzytkownik> usuwanieUzytkownika(vector <Uzytkownik> uzytkownicy, int idZalogowanegoUzytkownika) {

	string wyborUrzytkownika;
	fstream plik;

	plik.open("temp.txt", ios::out);
	if (plik.good()) {

		int rozmiarWektoraUzytkownicy = uzytkownicy.size();

		for (int i = 0; i < rozmiarWektoraUzytkownicy; i++) {
			if (idZalogowanegoUzytkownika == uzytkownicy[i].idUzytkownika) {
				continue;
			}
			else {
				plik << uzytkownicy[i].idUzytkownika << "|";
				plik << uzytkownicy[i].login << "|";
				plik << uzytkownicy[i].haslo << "|" << endl;
			}
		}

		plik.close();

		remove("uzytkownicy.txt");
		rename("temp.txt", "uzytkownicy.txt");

		int numerZnajomegoDoUsuniecia = 0;
		

		for (int i = 0; i < rozmiarWektoraUzytkownicy; i++) {
			if (uzytkownicy[i].idUzytkownika == idZalogowanegoUzytkownika) {
				numerZnajomegoDoUsuniecia = i;
			}
		}
		uzytkownicy.erase(uzytkownicy.begin() + numerZnajomegoDoUsuniecia);

		return uzytkownicy;
	}
	else {
		plik.close();
		cout << "Blad odczytu pliku!" << endl;
		cout << endl;
		system("Pause");
		return uzytkownicy;
	}
}

vector <Uzytkownik> zmianaHasla(vector <Uzytkownik> uzytkownicy, int idZalogowanegoUzytkownika)
{
	Uzytkownik uzytkownikZNowymHaslem;

	int indexDoEdycji;
	string noweHaslo;
	cout << endl;
	cout << "Podaj nowe haslo: ";
	cin >> noweHaslo;

	int rozmiarWektoraUzytkownicy = uzytkownicy.size();

	for (int i = 0; i < rozmiarWektoraUzytkownicy; i++) {
		if (uzytkownicy[i].idUzytkownika == idZalogowanegoUzytkownika) {
			indexDoEdycji = i;
		}
	}
	uzytkownicy[indexDoEdycji].haslo = noweHaslo;

	usuwanieUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);

	fstream plik;

	plik.open("uzytkownicy.txt", ios::out | ios::app);
	if (plik.good()) {
		plik << uzytkownicy[indexDoEdycji].idUzytkownika << "|";
		plik << uzytkownicy[indexDoEdycji].login << "|";
		plik << uzytkownicy[indexDoEdycji].haslo << "|" << endl;
	}
	else {
		cout << "Nie udalo sie otworzyc pliku" << endl;
		system("Pause");
	}

	uzytkownicy.push_back(uzytkownikZNowymHaslem);

	cout << endl;
	cout << "Udalo sie zmienic haslo." << endl;
	cout << endl;
	system("Pause");

	return uzytkownicy;
}


string konwerjsaIntNaString(int liczba)
{
	ostringstream ss;
	ss << liczba;
	string str = ss.str();
	return str;
}

string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik)
{
	string liniaZDanymiUzytkownika = "";

	liniaZDanymiUzytkownika += konwerjsaIntNaString(uzytkownik.idUzytkownika) + '|';
	liniaZDanymiUzytkownika += uzytkownik.login + '|';
	liniaZDanymiUzytkownika += uzytkownik.haslo + '|';

	return liniaZDanymiUzytkownika;
}

void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy)
{
	fstream plikTekstowy;
	string liniaZDanymiUzytkownika = "";
	vector <Uzytkownik>::iterator itrKoniec = --uzytkownicy.end();

	plikTekstowy.open("uzytkownicy.txt", ios::out);

	if (plikTekstowy.good() == true)
	{
		for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
		{
			liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(*itr);

			if (itr == itrKoniec)
			{
				plikTekstowy << liniaZDanymiUzytkownika;
			}
			else
			{
				plikTekstowy << liniaZDanymiUzytkownika << endl;
			}
			liniaZDanymiUzytkownika = "";
		}
	}
	else
	{
		cout << "Nie mozna otworzyc pliku " << "uzytkownicy.txt" << endl;
	}
	plikTekstowy.close();
}

void zmianaHaslaZalogowanegoUzytkownika(vector <Uzytkownik> &uzytkownicy, int idZalogowanegoUzytkownika)
{
	string noweHaslo = "";
	cout << "Podaj nowe haslo: ";
	cin >> noweHaslo;

	for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
	{
		if (itr->idUzytkownika == idZalogowanegoUzytkownika)
		{
			itr->haslo = noweHaslo;
			cout << "Haslo zostalo zmienione." << endl << endl;
			system("pause");
		}
	}
	zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


struct Znajomy {
	int id;
	int idUzytkownika;

	string imie;
	string nazwisko;
	string numerTelefonu;
	string email;
	string adres;
};

vector<Znajomy> odczytZnajomychZPliku(vector<Znajomy> wektorZnajomych, vector <Uzytkownik> uzytkownicy) {

	Uzytkownik uzytkownik;

	string linia;
	int numerLinii = 1;
	fstream plik;
	Znajomy nowyZnajomy;

	plik.open("ksiazka_adresowa.txt", ios::in);

	if (plik.is_open()) {
		while (getline(plik, linia)) {
			string Znajomy[7];
			string Uzytkownik;
			int dlugoscLinii = linia.length();
			int beginOfWord = 0;
			int lengthOfWord = 0;
			int numerZnajomego = 0;

			for (int i = 0; i < dlugoscLinii; i++) {

				if ((int)linia[i] == 124) {
					lengthOfWord = i - beginOfWord;
					Znajomy[numerZnajomego] = linia.substr(beginOfWord, lengthOfWord);
					beginOfWord = i + 1;
					numerZnajomego++;
				}
			}
			nowyZnajomy.id = atoi(Znajomy[0].c_str());
			uzytkownik.idUzytkownika = atoi(Uzytkownik.c_str());
			nowyZnajomy.imie = Znajomy[2];
			nowyZnajomy.nazwisko = Znajomy[3];
			nowyZnajomy.numerTelefonu = Znajomy[4];
			nowyZnajomy.email = Znajomy[5];
			nowyZnajomy.adres = Znajomy[6];	

			wektorZnajomych.push_back(nowyZnajomy);
		}
		plik.close();

		return wektorZnajomych;
	}
	else {
		plik.close();
		return wektorZnajomych;
	}
}

int wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector <Znajomy> &wektorZnajomych, int idZalogowanegoUzytkownika)
{
	Znajomy nowyZnajomy;
	int idOstatniegoAdresata = 0;
	string daneJednegoAdresataOddzielonePionowymiKreskami = "";
	string daneOstaniegoAdresataWPliku = "";
	fstream plikTekstowy;
	plikTekstowy.open("ksiazka_adresowa.txt", ios::in);

	if (plikTekstowy.good() == true)
	{
		while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
		{
			if (idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
			{
				nowyZnajomy = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
				wektorZnajomych.push_back(nowyZnajomy);
			}
		}
		daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
	}
	else
		cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

	plikTekstowy.close();

	if (daneOstaniegoAdresataWPliku != "")
	{
		idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
		return idOstatniegoAdresata;
	}
	else
		return 0;
}

int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
	int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
	int idUzytkownika = konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

	return idUzytkownika;
}


int konwersjaStringNaInt(string liczba)
{
	int liczbaInt;
	istringstream iss(liczba);
	iss >> liczbaInt;

	return liczbaInt;
}

Znajomy pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
	Znajomy wektorZnajomych;
	string pojedynczaDanaAdresata = "";
	int numerPojedynczejDanejAdresata = 1;

	int dlugoscDanychAdresataOddzielonePionowymiKreskami = daneAdresataOddzielonePionowymiKreskami.length();

	for (int pozycjaZnaku = 0; pozycjaZnaku < dlugoscDanychAdresataOddzielonePionowymiKreskami; pozycjaZnaku++)
	{
		if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
		{
			pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
		}
		else
		{
			switch (numerPojedynczejDanejAdresata)
			{
			case 1:
				wektorZnajomych.id = atoi(pojedynczaDanaAdresata.c_str());
				break;
			case 2:
				wektorZnajomych.idUzytkownika = atoi(pojedynczaDanaAdresata.c_str());
				break;
			case 3:
				wektorZnajomych.imie = pojedynczaDanaAdresata;
				break;
			case 4:
				wektorZnajomych.nazwisko = pojedynczaDanaAdresata;
				break;
			case 5:
				wektorZnajomych.numerTelefonu = pojedynczaDanaAdresata;
				break;
			case 6:
				wektorZnajomych.email = pojedynczaDanaAdresata;
				break;
			case 7:
				wektorZnajomych.adres = pojedynczaDanaAdresata;
				break;
			}
			pojedynczaDanaAdresata = "";
			numerPojedynczejDanejAdresata++;
		}
	}
	return wektorZnajomych;
}

int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
	int pozycjaRozpoczeciaIdAdresata = 0;
	int idAdresata = konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
	return idAdresata;
}


string pobierzLiczbe(string tekst, int pozycjaZnaku)
{
	string liczba = "";
	while (isdigit(tekst[pozycjaZnaku]))
	{
		liczba += tekst[pozycjaZnaku];
		pozycjaZnaku++;
	}
	return liczba;
}

/*
int dodajZnajomegoDoListyKontaktow(vector<Znajomy> wektorZnajomych, vector <Uzytkownik> uzytkownicy, int idZalogowanegoUzytkownika) {

	Uzytkownik uzytkownik;

	system("cls");

	fstream plik;
	string imie, nazwisko, numerTelefonu, adres, email;
	Znajomy nowyZnajomy;

	plik.open("ksiazka_adresowa.txt");
	if (plik.good()) {
		plik.close();
	}
	else {
		plik.open("ksiazka_adresowa.txt", ios::out);
		plik.close();
	}

	int iloscZnajomych = wektorZnajomych.size();
	int idOstatniegoZnajomego;

	int idUzytkownika = idZalogowanegoUzytkownika;

	if (wektorZnajomych.empty()) {
		idOstatniegoZnajomego = 0;
	}
	else {
		//idOstatniegoZnajomego = wektorZnajomych[iloscZnajomych - 1].id;
		idOstatniegoZnajomego = dodajAdresata(wektorZnajomych, idZalogowanegoUzytkownika, idOstatniegoZnajomego);
	}

	cout << "Podaj imie znajomego: ";
	cin >> imie;
	cout << "Podaj nazwisko znajomego: ";
	cin >> nazwisko;
	cin.ignore();
	cout << "Podaj email znajomego: ";
	getline(cin, email);
	cout << "Podaj adres znajomego: ";
	getline(cin, adres);
	cout << "Podaj numer telefonu znajomego: ";
	getline(cin, numerTelefonu);

	nowyZnajomy = { idOstatniegoZnajomego + 1, idUzytkownika, imie, nazwisko, numerTelefonu, email, adres };

	wektorZnajomych.push_back(nowyZnajomy);

	int rozmiarWektoraUzytkownicy = uzytkownicy.size();

	plik.open("ksiazka_adresowa.txt", ios::out | ios::app);
	if (plik.good()) {
		plik << wektorZnajomych[iloscZnajomych].id << "|";
		for (int i = 0; i < rozmiarWektoraUzytkownicy; i++)
		{
			if (uzytkownicy[i].idUzytkownika == idZalogowanegoUzytkownika)
			{
				plik << uzytkownicy[i].idUzytkownika << "|";
			}
		}
		plik << wektorZnajomych[iloscZnajomych].imie << "|";
		plik << wektorZnajomych[iloscZnajomych].nazwisko << "|";
		plik << wektorZnajomych[iloscZnajomych].numerTelefonu << "|";
		plik << wektorZnajomych[iloscZnajomych].email << "|";
		plik << wektorZnajomych[iloscZnajomych].adres << "|" << endl;
		cout << endl;
		cout << "Dodano nowego znajomego do listy kontaktow!" << endl;
		cout << endl;
		plik.close();
		Sleep(1000);
		//return wektorZnajomych;
	}
	else {
		cout << "Nie udalo sie otworzyc pliku" << endl;
		system("Pause");
	}

	//return wektorZnajomych;
	return idOstatniegoZnajomego;
}
*/

string zamienDaneZnajomegoNaLinieZDanymiOddzielonaPionowymiKreskami(Znajomy znajomy)
{
	string liniaZDanymiZnajomego = "";

	liniaZDanymiZnajomego += konwerjsaIntNaString(znajomy.id) + '|';
	liniaZDanymiZnajomego += konwerjsaIntNaString(znajomy.idUzytkownika) + '|';
	liniaZDanymiZnajomego += znajomy.imie + '|';
	liniaZDanymiZnajomego += znajomy.nazwisko + '|';
	liniaZDanymiZnajomego += znajomy.numerTelefonu + '|';
	liniaZDanymiZnajomego += znajomy.email + '|';
	liniaZDanymiZnajomego += znajomy.adres + '|';
	
	return liniaZDanymiZnajomego;
}

void dopiszAdresataDoPliku(Znajomy adresat)
{
	string liniaZDanymiAdresata = "";
	fstream plikTekstowy;
	plikTekstowy.open("ksiazka_adresowa.txt", ios::out | ios::app);

	if (plikTekstowy.good() == true)
	{
		liniaZDanymiAdresata = zamienDaneZnajomegoNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);

		if (czyPlikJestPusty(plikTekstowy) == true)
		{
			plikTekstowy << liniaZDanymiAdresata;
		}
		else
		{
			plikTekstowy << endl << liniaZDanymiAdresata;
		}
	}
	else
	{
		cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
	}
	plikTekstowy.close();
	cout << endl;
	cout << "Dodano nowego znajomego do listy kontaktow :)" << endl;
	cout << endl;
	system("pause");
}

Znajomy podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
	Znajomy adresat;

	string imie, nazwisko, numerTelefonu, adres, email;

	adresat.id = ++idOstatniegoAdresata;
	adresat.idUzytkownika = idZalogowanegoUzytkownika;

	cout << "Podaj imie znajomego: ";	
	cin >> imie;
	adresat.imie = imie;

	cout << "Podaj nazwisko znajomego: ";	
	cin >> nazwisko;
	adresat.nazwisko = nazwisko;

	cout << "Podaj email znajomego: ";
	cin.ignore();
	getline(cin, email);
	adresat.email = email;

	cout << "Podaj adres znajomego: ";
	getline(cin, adres);
	adresat.adres = adres;

	cout << "Podaj numer telefonu znajomego: ";
	getline(cin, numerTelefonu);
	adresat.numerTelefonu = numerTelefonu;

	return adresat;
}

int dodajAdresata(vector <Znajomy> &adresaci, int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
	Znajomy adresat;

	system("cls");
	cout << "Dodawanie nowego znajomego" << endl << endl;
	adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);

	adresaci.push_back(adresat);
	dopiszAdresataDoPliku(adresat);

	return ++idOstatniegoAdresata;
}

bool wyswietlWszystkichZnajomychZWektora(vector<Znajomy> wektorZnajomych) {

	int rozmiarwektorZnajomych = wektorZnajomych.size();

	if (wektorZnajomych.empty()) {
		system("cls");
		cout << "Brak znajomych na liscie kontaktow :(" << endl;
		Sleep(1000);
		return true;
	}
	else {
		system("cls");
		for (int i = 0; i < rozmiarwektorZnajomych; i++) {
			cout << wektorZnajomych[i].imie << endl;
			cout << wektorZnajomych[i].nazwisko << endl;
			cout << wektorZnajomych[i].numerTelefonu << endl;
			cout << wektorZnajomych[i].email << endl;
			cout << wektorZnajomych[i].adres << endl;
			cout << endl;
		}
		cout << endl;
		system("pause");
		return true;
	}
	return true;
}

bool szukanieKonkretnegoImieniaWWektorze(vector<Znajomy> wektorZnajomych, string imieDoWyszukania) {

	int rozmiarwektorZnajomych = wektorZnajomych.size();

	for (int i = 0; i < rozmiarwektorZnajomych; i++) {
		if (wektorZnajomych[i].imie == imieDoWyszukania) {
			return true;
		}
	}
	return false;
}

void wyszukiwanieZnajomegoPoImieniu(vector<Znajomy> wektorZnajomych) {

	string imieDoWyszukania;
	system("cls");
	cout << "Podaj imie: ";
	cin >> imieDoWyszukania;

	bool czyToImieJestWWektorze = false;

	czyToImieJestWWektorze = szukanieKonkretnegoImieniaWWektorze(wektorZnajomych, imieDoWyszukania);

	int rozmiarwektorZnajomych = wektorZnajomych.size();

	if (czyToImieJestWWektorze) {

		for (int i = 0; i < rozmiarwektorZnajomych; i++) {

			if (imieDoWyszukania == wektorZnajomych[i].imie) {
				cout << endl;
				cout << wektorZnajomych[i].imie << endl;
				cout << wektorZnajomych[i].nazwisko << endl;
				cout << wektorZnajomych[i].numerTelefonu << endl;
				cout << wektorZnajomych[i].email << endl;
				cout << wektorZnajomych[i].adres << endl;
				cout << endl;
				system("pause");
			}
		}
	}
	else {
		system("cls");
		cout << "Nie znaleziono znajomego o takim imieniu." << endl;
		cout << endl;
		system("pause");
	}
}

bool szukanieKonkretnegoNazwiskaWWektorze(vector<Znajomy> wektorZnajomych, string nazwiskoDoWyszukania) {

	int rozmiarwektorZnajomych = wektorZnajomych.size();

	for (int i = 0; i < rozmiarwektorZnajomych; i++) {
		if (wektorZnajomych[i].nazwisko == nazwiskoDoWyszukania) {
			return true;
		}
	}
	return false;
}

void wyszukiwanieZnajomegoPoNazwisku(vector<Znajomy> wektorZnajomych) {

	string nazwiskoDoWyszukania;
	system("cls");
	cout << "Podaj nazwisko: ";
	cin >> nazwiskoDoWyszukania;

	bool czyToNazwiskoJestWWektorze = false;

	czyToNazwiskoJestWWektorze = szukanieKonkretnegoNazwiskaWWektorze(wektorZnajomych, nazwiskoDoWyszukania);

	int rozmiarwektorZnajomych = wektorZnajomych.size();

	if (czyToNazwiskoJestWWektorze) {

		for (int i = 0; i < rozmiarwektorZnajomych; i++)
		{
			if (nazwiskoDoWyszukania == wektorZnajomych[i].nazwisko) {
				cout << endl;
				cout << wektorZnajomych[i].imie << endl;
				cout << wektorZnajomych[i].nazwisko << endl;
				cout << wektorZnajomych[i].numerTelefonu << endl;
				cout << wektorZnajomych[i].email << endl;
				cout << wektorZnajomych[i].adres << endl;
				cout << endl;
				system("pause");
			}
		}
	}
	else {
		system("cls");
		cout << "Nie znaleziono znajomego o takim nazwisku." << endl;
		cout << endl;
		system("pause");
	}
}

void wybierzSposobWyszukiwaniaZnajomego(vector <Znajomy> &wektorZnajomych)
{
	if (wektorZnajomych.size() == 0)
	{
		system("cls");
		cout << "Brak znajomych na liscie kontaktow :(" << endl;
		system("pause");
	}
	else {
		system("cls");
		cout << "Jak chcesz wyszukac znajomego?" << endl;
		cout << endl;
		cout << "1. Po imieniu" << endl;
		cout << "2. Po nazwisku" << endl;
		cout << endl;
		cout << "Twoj wyborUrzytkownika: ";
		char wyborUrzytkownika;
		cin >> wyborUrzytkownika;

		if (wyborUrzytkownika == '1') wyszukiwanieZnajomegoPoImieniu(wektorZnajomych);

		if (wyborUrzytkownika == '2') wyszukiwanieZnajomegoPoNazwisku(wektorZnajomych);
	}
}

bool szukanieKonkretnegoIdWWektorze(vector<Znajomy> wektorZnajomych, int szukaneId) {

	if (wektorZnajomych.empty()) {
		system("cls");
		cout << "Lista kontaktow jest pusta :(" << endl;
		system("Pause");
		return false;
	}

	int rozmiarwektorZnajomych = wektorZnajomych.size();

	for (int i = 0; i < rozmiarwektorZnajomych; i++) {

		if (wektorZnajomych[i].id == szukaneId) {
			return true;
		}
	}

	return false;
}

int usunZnajomego(vector<Znajomy> wektorZnajomych) {

	system("cls");
	cout << "Podaj id kontaktu do usuniecia: ";
	int idZnajomegoDoUsuniecia;
	cin >> idZnajomegoDoUsuniecia;

	string wyborUrzytkownika;
	int numerLiniiZnajomegoDoUsuniecia;

	bool czyToIdJestWWektorze = false;

	czyToIdJestWWektorze = szukanieKonkretnegoIdWWektorze(wektorZnajomych, idZnajomegoDoUsuniecia);

	int rozmiarwektorZnajomych = wektorZnajomych.size();

	if (czyToIdJestWWektorze) {

		for (int i = 0; i < rozmiarwektorZnajomych; i++) {
			if (idZnajomegoDoUsuniecia == wektorZnajomych[i].id) {
				system("cls");
				cout << wektorZnajomych[i].imie << endl;
				cout << wektorZnajomych[i].nazwisko << endl;
				cout << wektorZnajomych[i].email << endl;
				cout << wektorZnajomych[i].adres << endl;
				cout << wektorZnajomych[i].numerTelefonu << endl;
				cout << endl;
			}
		}

		cout << endl;
		cout << "Czy chcesz usunac tego znajomego z listy kontaktow? [t/n]" << endl;
		cin >> wyborUrzytkownika;
		if (wyborUrzytkownika == "t" || wyborUrzytkownika == "y" || wyborUrzytkownika == "tak" || wyborUrzytkownika == "yes") {

			numerLiniiZnajomegoDoUsuniecia = zwrocNumerLiniiSzukanegoAdresata(idZnajomegoDoUsuniecia);
			usunWybranaLinieWPliku(numerLiniiZnajomegoDoUsuniecia);
		}
	}

	return idZnajomegoDoUsuniecia;
}

int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idZnajomegoDoUsuniecia, int idOstatniegoAdresata)
{
	if (idZnajomegoDoUsuniecia == idOstatniegoAdresata)
		return pobierzZPlikuIdOstatniegoAdresata();
	else
		return idOstatniegoAdresata;
}

int pobierzZPlikuIdOstatniegoAdresata()
{
	int idOstatniegoAdresata = 0;
	string daneJednegoAdresataOddzielonePionowymiKreskami = "";
	string daneOstaniegoAdresataWPliku = "";
	fstream plikTekstowy;
	plikTekstowy.open("ksiazka_adresowa.txt", ios::in);

	if (plikTekstowy.good() == true)
	{
		while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
		daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
		plikTekstowy.close();
	}
	else
		cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

	if (daneOstaniegoAdresataWPliku != "")
	{
		idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
	}
	return idOstatniegoAdresata;
}

int zwrocNumerLiniiSzukanegoAdresata(int idAdresata)
{
	bool czyIstniejeAdresat = false;
	int numerLiniiWPlikuTekstowym = 1;
	string daneJednegoAdresataOddzielonePionowymiKreskami = "";
	fstream plikTekstowy;
	plikTekstowy.open("ksiazka_adresowa.txt", ios::in);

	if (plikTekstowy.good() == true && idAdresata != 0)
	{
		while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
		{
			if (idAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
			{
				czyIstniejeAdresat = true;
				plikTekstowy.close();
				return numerLiniiWPlikuTekstowym;
			}
			else
				numerLiniiWPlikuTekstowym++;
		}
		if (czyIstniejeAdresat = false)
		{
			plikTekstowy.close();
			return 0;
		}
	}
	return 0;
}

void usunWybranaLinieWPliku(int numerUsuwanejLinii)
{
	fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
	string wczytanaLinia = "";
	int numerWczytanejLinii = 1;

	odczytywanyPlikTekstowy.open("ksiazka_adresowa.txt", ios::in);
	tymczasowyPlikTekstowy.open("temp.txt", ios::out | ios::app);

	if (odczytywanyPlikTekstowy.good() == true && numerUsuwanejLinii != 0)
	{
		while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
		{
			if (numerWczytanejLinii == numerUsuwanejLinii) {}
			else if (numerWczytanejLinii == 1 && numerWczytanejLinii != numerUsuwanejLinii)
				tymczasowyPlikTekstowy << wczytanaLinia;
			else if (numerWczytanejLinii == 2 && numerUsuwanejLinii == 1)
				tymczasowyPlikTekstowy << wczytanaLinia;
			else if (numerWczytanejLinii > 2 && numerUsuwanejLinii == 1)
				tymczasowyPlikTekstowy << endl << wczytanaLinia;
			else if (numerWczytanejLinii > 1 && numerUsuwanejLinii != 1)
				tymczasowyPlikTekstowy << endl << wczytanaLinia;
			numerWczytanejLinii++;
		}
		odczytywanyPlikTekstowy.close();
		tymczasowyPlikTekstowy.close();

		remove("ksiazka_adresowa.txt");
		rename("temp.txt", "ksiazka_adresowa.txt");
	}
}

void edytujZnajomego(vector <Znajomy> &znajomi)
{
	system("cls");

	string noweImie, noweNazwisko, nowyNumerTelefonu, nowyEmail, nowyAdresZamieszkania;

	Znajomy adresat;
	
	int numerLiniiEdytowanegoAdresata = 0;
	string liniaZDanymiZnajomego = "";


	system("cls");
	cout << "Podaj id kontaktu do edycji: ";
	int idEdytowanegoZnajomego;
	cin >> idEdytowanegoZnajomego;
	
	int wyborUrzytkownika;
	bool czyIstniejeAdresat = false;

	int dlugoscWektoraZnajomych = znajomi.size();

	for (int i = 0; i < dlugoscWektoraZnajomych; i++)
	{
		if (znajomi[i].id == idEdytowanegoZnajomego)
		{
			czyIstniejeAdresat = true;
			do {
				system("cls");
				cout << "Edytuj:" << endl;
				cout << "1. Imie" << endl;
				cout << "2. Nazwisko" << endl;
				cout << "3. Numer telefonu" << endl;
				cout << "4. Email" << endl;
				cout << "5. Adres" << endl;
				cout << "6. Powrot do menu glownego" << endl;
				cout << endl;
				cout << "Twoj wybor: ";
			
				cin >> wyborUrzytkownika;
			
				switch (wyborUrzytkownika)
				{
				case 1:
					cout << endl;
					cout << "Podaj nowe imie: ";				
					cin.ignore();
					getline(cin, noweImie);
					znajomi[i].imie = noweImie;				
					zaktualizujDaneWybranegoZnajomego(znajomi[i], idEdytowanegoZnajomego);				
					break;				
				case 2:
					cout << endl;
					cout << "Podaj nowe nazwisko: ";
					cin.ignore();
					getline(cin, noweNazwisko);
					znajomi[i].nazwisko = noweNazwisko;				
					zaktualizujDaneWybranegoZnajomego(znajomi[i], idEdytowanegoZnajomego);
					break;
				case 3:
					cout << endl;
					cout << "Podaj nowy numer telefonu: ";
					cin.ignore();
					getline(cin, nowyNumerTelefonu);
					znajomi[i].numerTelefonu = nowyNumerTelefonu;
					zaktualizujDaneWybranegoZnajomego(znajomi[i], idEdytowanegoZnajomego);
					break;
				case 4:
					cout << endl;
					cout << "Podaj nowy email: ";
					cin.ignore();
					getline(cin, nowyEmail);
					znajomi[i].email = nowyEmail;
					zaktualizujDaneWybranegoZnajomego(znajomi[i], idEdytowanegoZnajomego);
					break;
				case 5:
					cout << endl;
					cout << "Podaj nowy adres zamieszkania: ";
					cin.ignore();
					getline(cin, nowyAdresZamieszkania);
					znajomi[i].adres = nowyAdresZamieszkania;
					zaktualizujDaneWybranegoZnajomego(znajomi[i], idEdytowanegoZnajomego);
					break;				
				case 6:
					cout << endl << "Powrot do menu uzytkownika" << endl << endl;
					break;
				default:
					cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
					break;
				}
			} while (wyborUrzytkownika != 6);
		}
	}
	if (czyIstniejeAdresat == false)
	{
		cout << endl << "Nie ma takiego adresata." << endl << endl;
	}
	system("pause");
}

string zamienDaneZnajomegoNaLinieZDanymiOddzielonymiPionowymiKreskami(Znajomy znajomy)
{
	string liniaZDanymiZnajomego = "";

	liniaZDanymiZnajomego += konwerjsaIntNaString(znajomy.id) + '|';
	liniaZDanymiZnajomego += konwerjsaIntNaString(znajomy.idUzytkownika) + '|';
	liniaZDanymiZnajomego += znajomy.imie + '|';
	liniaZDanymiZnajomego += znajomy.nazwisko + '|';
	liniaZDanymiZnajomego += znajomy.numerTelefonu + '|';
	liniaZDanymiZnajomego += znajomy.email + '|';
	liniaZDanymiZnajomego += znajomy.adres + '|';

	return liniaZDanymiZnajomego;
}

void zaktualizujDaneWybranegoZnajomego(Znajomy znajomy, int idEdytowanegoZnajomego)
{
	int numerLiniiEdytowanegoZnajomego = 0;
	string liniaZDanymiZnajomego = "";

	numerLiniiEdytowanegoZnajomego = zwrocNumerLiniiSzukanegoAdresata(idEdytowanegoZnajomego);
	liniaZDanymiZnajomego = zamienDaneZnajomegoNaLinieZDanymiOddzielonymiPionowymiKreskami(znajomy);
	edytujWybranaLinieWPliku(numerLiniiEdytowanegoZnajomego, liniaZDanymiZnajomego);

	cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
	cout << endl;
	system("pause");
}

void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiZnajomego)
{
	fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
	string wczytanaLinia = "";
	int numerWczytanejLinii = 1;

	odczytywanyPlikTekstowy.open("ksiazka_adresowa.txt", ios::in);
	tymczasowyPlikTekstowy.open("temp.txt", ios::out | ios::app);

	if (odczytywanyPlikTekstowy.good() == true)
	{
		while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
		{
			if (numerWczytanejLinii == numerEdytowanejLinii)
			{
				if (numerWczytanejLinii == 1)
					tymczasowyPlikTekstowy << liniaZDanymiZnajomego;
				else if (numerWczytanejLinii > 1)
					tymczasowyPlikTekstowy << endl << liniaZDanymiZnajomego;
			}
			else
			{
				if (numerWczytanejLinii == 1)
					tymczasowyPlikTekstowy << wczytanaLinia;
				else if (numerWczytanejLinii > 1)
					tymczasowyPlikTekstowy << endl << wczytanaLinia;
			}
			numerWczytanejLinii++;
		}
		odczytywanyPlikTekstowy.close();
		tymczasowyPlikTekstowy.close();

		remove("ksiazka_adresowa.txt");
		rename("temp.txt", "ksiazka_adresowa.txt");
	}
}

void balladaNaDowidzenia()
{
	system("cls");
	cout << "Dziekujemy za skorzystanie z naszych uslug :)" << endl;
	cout << endl << endl << endl;
	Sleep(1000);
	exit(0);
}
