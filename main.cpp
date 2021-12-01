#define _CRT_SECURE_NO_WARNINGS
#include "stablo.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;
int main() {


	char** niz1 = new char* [10];
	int i = 0;
	int j = 0;
	string line;
	ifstream myfile("example.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{			
			
			
			char* char_arr;
			string str_obj = line;
			char_arr = &str_obj[0];
			char* temp = char_arr;
			niz1[i] = temp;
			i++;
		}
		myfile.close();
	}

	else cout << "Unable to open file";


	/*

	Stablo s();
	while (true) {
		cout << "2. Brisanje stabla" << endl;
		cout << "3. Pronalazenje kljuca" << endl;
		cout << "4. Ispis stabla" << endl;
		cout << "5. Umetanje kljuca" << endl;
		cout << "6. Brisanje kljuca" << endl;
		cout << "7. K-ti najmanji leksikografski kljuc" << endl;
		cout << "8. Izlaz iz programa" << endl;
		int kom;
		int m;
		cout << "Unesite m stabla: ";
		cin >> m;
		char ime1[] = "aaaa";
		char ime2[] = "bbbb";
		char ime3[] = "cccc";
		char ime4[] = "dddd";
		char ime5[] = "eeee";
		char ime6[] = "ffff";
		char ime7[] = "gggg";
		char ime8[] = "hhhh";
		char ime9[] = "iiii";
		char ime10[] = "jjjj";
		char ime11[] = "kkkk";



		Stablo s(m);

		s.dodaj(ime1);
		s.dodaj(ime2);
		s.dodaj(ime3);
		s.dodaj(ime4);
		s.dodaj(ime5);
		
		cout << "\nUnesite komandu: ";
		cin >> kom;

		switch (kom) {

		case 2: {
			cout << "Ne posotji funkcija" << endl;
			break;
		}
		case 3: {
			char unos[] = "aaaaaaaaaaa";
			cout << "\nUnesite kljuc ";
			cin >> unos;
			if (s.pronadji(unos)) cout << "Nasao";
			else cout << "Ne postoji kljuc";
			break;
		}
		case 4: {
			cout << s;
			putchar('\n');
			break;
		}
		case 5: {
			char unos[] = "aaaaaaaaaaa";
			cout << "\nUnesite kljuc ";
			cin >> unos;
			if (s.dodaj(unos)) cout << "\nUspesno dodat kljuc\n";
			else cout << "\nNeuspesno dodavanje\n";
			break;
		}
		case 6: {
			cout << "ne postoji funkcija\n";
			break;
		}
		case 7: {
			int k;
			cout << "Unesite kti kljuc ";
			cin >> k;
			cout << s.nacikticlan(k);
			break;
		}
		case 8: {
			exit(0);
			break;
		}


		}
	}
	*/
	
	char ime1[] = "aaaa";
	char ime2[] = "bbbb";
	char ime3[] = "cccc";
	char ime4[] = "dddd";
	char ime5[] = "eeee";
	char ime6[] = "ffff";
	char ime7[] = "gggg";
	char ime8[] = "hhhh";
	char ime9[] = "iiii";
	char ime10[] = "jjjj";
	char ime11[] = "kkkk";
	char ime12[] = "llll";
	char ime13[] = "mmmm";
	char ime14[] = "deee";
	char ime15[] = "ddee";
	char ime16[] = "pppp";


	Stablo s(3);

	s.dodaj(ime1);
	s.dodaj(ime2);
	s.dodaj(ime3);
	s.dodaj(ime4);
	s.dodaj(ime5);
	s.dodaj(ime6);								     //     1
	s.dodaj(ime7);									//     1 1
	s.dodaj(ime8);//TREBAAAAAAAAAAAAAA UBACITIIIIII//III 1 1 1 2 prelamanje temp->oca i tako proveravati do korena da li su popunjeni
	
	if (s.pronadji(ime9) == true) {
		printf("Pronasao\n");
	}
	else printf("Nisam\n");

	//cout << s;
	printf("%s",s.nacikticlan(1));
	s.dodaj(ime9);
	s.dodaj(ime10);
	s.dodaj(ime11);
	//s.dodaj(ime17);


	
}