#ifndef _stablo_h_
#define _stablo_h_

#include "string.h"

#include <iostream>

using namespace std;

class Stablo {
	int m;



public:
	struct Cvor {
		char** str;
		Cvor** pokazivaci;
		bool list;
		int brst;
		Cvor* otac;
		Cvor(int k) {
			str = new char* [k - 1];
			pokazivaci = new Cvor * [k];
			list = true;
			otac = nullptr;
			brst = 0;
		}
	};

	Cvor* koren = nullptr;

	//static int br_kljuceva;
	//static int min_br_podstabala;
	//static int max_br_podstabala;
	void napravicvor(int a);

	Stablo(int k) : m(k) {
		//koren = new Cvor;


		//max_br_podstabala = m;

		//	min_br_podstabala = (2 * m - 1) / 3;


	};
	bool pronadji(char* rec);
	bool dodaj(char* rec);
	friend void operator<<(ostream& os, Stablo s);

	char* nacikticlan(int k);


	void open(
		const char* _Filename,
		ios_base::openmode _Mode = ios_base::in,
		int _Prot = (int)ios_base::_Openprot
	);

};




#endif