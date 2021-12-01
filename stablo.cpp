#define _CRT_SECURE_NO_WARNINGS 1
#include "stablo.h"
#include <stack>
#include <queue>
using namespace std;

void Stablo::napravicvor(int a){
	
	
}
//provera velicine cvora




bool Stablo::pronadji(char* rec)
{
	Cvor* temp = koren;
	int poz;
	
	while (temp->list == false) {
		int flag = 0;
		for (poz = 0; poz < temp->brst; poz++) {
			if (strcmp(rec, temp->str[poz]) == 0) {
				return true;
			}
			if (strcmp(rec, temp->str[poz]) == -1) {
				temp = temp->pokazivaci[poz];
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			temp = temp->pokazivaci[poz];
			
		}
	}
	for (poz = 0; poz < temp->brst; poz++) {
		if (strcmp(rec, temp->str[poz]) == 0) {
			return true;
		}
		if (strcmp(rec, temp->str[poz]) == -1) {
			temp = temp->pokazivaci[poz];
			
			break;
		}
	}
	
}

bool Stablo::dodaj(char* rec) {
	Cvor* temp = koren;
	int poz = 0;
	int aaaa = 8 / 3;
	//int br_kljuceva = m;
	//int min_br_podstabala = m;
	//int max_br_podstabala = m;
	if (!temp) {
		char ime[] = "proba";
		char ime2[] = "proba2";
		Cvor* temp = new Cvor(m);
		temp->str = new char* [m - 1 + 10];
		temp->pokazivaci = new Cvor * [m];
		temp->list = true;
		temp->otac = nullptr;
		for (int i = 0; i < m; i++) {
			temp->pokazivaci[i] = nullptr;
		}
		temp->str[0] = rec;
		temp->brst++;
		koren = temp;
		return true;
	}
	int i;
	//char ime1[] = "111";
	//char ime2[] = "222";
	//char ime3[] = "333";



	if (temp->list == true) {
		if (temp->brst < m-1) {//IPSRAVITIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
			for (i = 0; i < temp->brst; i++) {

				if (strcmp(rec, temp->str[i]) == -1) {
					for (int j = temp->brst; j > i; j--) {
						temp->str[j] = temp->str[j - 1];
					}
					temp->str[i] = rec;
					temp->brst++;
					koren = temp;
					return true;
				}

			}
			temp->str[i] = rec;
			temp->brst++;
			koren = temp;
			return true;
		}
		//kada je koren pun pa mora prelivanje
		else {//niz u koji stavljam sve cvorove zbog prelamanja
			
			char** niz = new char* [temp->brst + 1 + 10];
			int brelemniza = temp->brst;
			if (!niz) {
				return false;
			}
			int i;
			char* nista = NULL;
			for (i = 0; i <= temp->brst; i++) {
				niz[i] = temp->str[i];
				temp->str[i] = nista;
				temp->brst--;
			}
			for (i = 0; i < brelemniza; i++) {
				if (strcmp(rec, niz[i]) == -1) {
					for (int j = temp->brst; j > i; j--) {
						niz[j] = niz[j - 1];
					}
					break;
				}
			}
			niz[i] = rec;
			brelemniza++;
			
			//temp->brst = 1;
			//cvorovi prvog prelamanja korena
			Cvor* novid = new Cvor(m);
			if (!novid) {
				return false;
			}
			Cvor* novil = new Cvor(m);
			if (!novil) {
				return false;
			}
			//novid->str[0] = ime1;
			//novid->str[1] = ime2;
			for (i = 0; i < brelemniza/2; i++) {
				novil->str[i] = niz[i];
				novil->brst++;
			}

			temp->str[0] = niz[i];
			temp->brst++;
			i++;
			//preskacem oca
			
			for (int j = 0; i < brelemniza; j++, i++) {
				novid->str[j] = niz[i];
				novid->brst++;
			}
			temp->pokazivaci[0] = novil;
			temp->pokazivaci[1] = novid;
			novil->otac = temp;
			novid->otac = temp;
			temp->list = false;
			//koren = temp;
			return true;
		}

	}
	Cvor* pre = temp;
	// prolazim kroz stablo


	int flag = 0;
	while (temp->list != true) {
		//if (temp->list == true) {
		//		poz--;
		//		break;
		//}
		for (poz = 0; poz < temp->brst; poz++) {

			if (strcmp(rec, temp->str[poz]) == -1) {
				pre = temp;
				temp = temp->pokazivaci[poz];
				flag = 1;
				break;
			}
			else if (strcmp(rec, temp->str[poz]) == 0) {
				return false;
			}
		}
		if (flag == 0) {
			pre = temp;
			temp = temp->pokazivaci[poz];
		}
	}
	//najjednostaviniji slucaj ubacujem u list koji nije opunjen
	if (temp->brst < m - 1) {
		for (i = 0; i < temp->brst; i++) {

			if (strcmp(rec, temp->str[i]) == -1) {
				for (int j = temp->brst; j > i; j--) {
					temp->str[j] = temp->str[j - 1];
				}
				temp->str[i] = rec;
				temp->brst++;
				//koren = temp;
				return true;
			}

		}
		temp->str[i] = rec;
		temp->brst++;
		//koren = temp;
		return true;
	}



	//list popunjen, a moguce je prelivanje, desni brat nije popunjen
	else if (poz+1 <= temp->otac->brst && temp->otac->pokazivaci[poz + 1] != nullptr) {
		if (temp->otac->pokazivaci[poz + 1]->brst < m - 1) {
			//if (poz == temp->otac->brst) {
			//	poz = poz - 1;
			//}
			int i;
			char** niz;
			//broj kljuceva u tempu + otac + broj_kljuceva u desnom bratu + novi kljuc
			niz = new char* [temp->brst + (temp->otac->pokazivaci[poz + 1]->brst) + 1 + 1 + 10];//povecao sam prostor u nizu
			if (!niz) {
				return false;
			}
			int brojelemniza = temp->brst + (temp->otac->pokazivaci[poz + 1]->brst) + 1;
			//za trenutni cvor
			int trenbrst = temp->brst;
			for (i = 0; i < trenbrst; i++) {
				niz[i] = temp->str[i];
				temp->str[i] = NULL;
				temp->brst--;
			}

			niz[i] = temp->otac->str[poz];
			temp->otac->str[poz] = NULL;
			temp->otac->brst--;
			i++;
			trenbrst = temp->otac->pokazivaci[poz + 1]->brst;
			for (int j = 0; j < trenbrst; j++, i++) {
				niz[i] = temp->otac->pokazivaci[poz + 1]->str[j];
				temp->otac->pokazivaci[poz + 1]->str[j] = NULL;
				temp->otac->pokazivaci[poz + 1]->brst--;

			}
			//int celobrojno = 7 / 2;

			for (i = 0; i < brojelemniza; i++) {
				if (strcmp(rec, niz[i]) == -1) {
					for (int j = brojelemniza; j > i; j--) {
						niz[j] = niz[j - 1];
					}
					break;
				}
			}
			niz[i] = rec;
			brojelemniza++;


			int brojac;
			if (brojelemniza % 2 == 0) {
				brojac = brojelemniza / 2 - 1;
			}
			else brojac = brojelemniza / 2;



			//temp->brst = 0;
			for (i = 0; i < brojac; i++) {
				temp->str[i] = niz[i];
				temp->brst++;
			}
			temp->otac = pre;

			temp->otac->str[poz] = niz[i];
			temp->otac->brst++;
			i++;

			//temp->otac->pokazivaci[poz + 1]->brst = 0;
			for (int j = 0; i < brojelemniza; i++, j++) {
				temp->otac->pokazivaci[poz + 1]->str[j] = niz[i];
				temp->otac->pokazivaci[poz + 1]->brst++;
			}
			temp->otac->pokazivaci[poz + 1]->otac = pre;
			delete niz;
			return true;

		}
	}//desni brat popunjen ili ne postoji, levi brat nije popunjen i postoji
	else if ((poz - 1 >= 0 && temp->otac->pokazivaci[poz - 1] != nullptr && temp->otac->pokazivaci[poz - 1]->brst < m - 1)) {
		//if (poz == temp->otac->brst) {
		//	poz = poz - 1;
		//}
		int i;
		char** niz;
		//broj kljuceva u tempu + otac + broj_kljuceva u levom bratu
		niz = new char* [temp->brst + 1 + (temp->otac->pokazivaci[poz - 1]->brst) + 1 + 10];//POVECAO SAM MESTO U NIZU
		if (!niz) {
			return false;
		}
		int brojelemniza = temp->brst + 1 + (temp->otac->pokazivaci[poz - 1]->brst) + 1;//+1 zbog dodatnog elementa na kraju
		//za trenutni cvor
		int brtemp = temp->otac->pokazivaci[poz - 1]->brst;
		for (i = 0; i < brtemp; i++) {
			niz[i] = temp->otac->pokazivaci[poz - 1]->str[i];
			temp->otac->pokazivaci[poz - 1]->str[i] = NULL;
			temp->otac->pokazivaci[poz - 1]->brst--;
		}
		niz[i] = temp->otac->str[poz - 1];
		temp->otac->str[poz - 1] = NULL;
		temp->otac->brst--;
		i++;

		brtemp = temp->brst;
		for (int j = 0; j < brtemp; j++, i++) {
			niz[i] = temp->str[j];
			temp->str[j] = NULL;
			temp->brst--;
		}




		int celobrojno = 7 / 2;

		for (i = 0; i < brojelemniza - 1; i++) {
			if (strcmp(rec, niz[i]) == -1) {
				for (int j = brojelemniza - 1; j > i; j--) {
					niz[j] = niz[j - 1];
				}
				break;
			}
		}
		niz[i] = rec;

		int brojac;
		if (brojelemniza % 2 == 0) {
			brojac = brojelemniza / 2 - 1;
		}
		else brojac = brojelemniza / 2;



		//temp->otac->pokazivaci[poz + 1]->brst = 0;

		for (i = 0; i < brojac; i++) {
			temp->otac->pokazivaci[poz - 1]->str[i] = niz[i];
			temp->otac->pokazivaci[poz - 1]->brst++;
		}
		temp->otac->pokazivaci[poz - 1]->otac = pre;


		temp->otac->str[poz - 1] = niz[i];
		temp->otac->brst++;
		i++;

		//temp->brst = 0;

		for (int j = 0; i < brojelemniza; j++, i++) {
			temp->str[j] = niz[i];
			temp->brst++;
		}
		temp->otac = pre;




		delete niz;
		return true;
	}
	//                          ^   ^
	//VELIKOOO PRELAMANJEEE < 2 1 2 1 2 >  za m=4
	//                          ^   ^
	//                      < 1 1 1 1 2 > za m=3
	else {
		// prelamanje izmedu trenutnog i desnog
		if (poz+1<= temp->otac->brst && temp->brst == m - 1 && temp->otac->pokazivaci[poz + 1] != nullptr){
			if (temp->otac->pokazivaci[poz + 1]->brst == m - 1) {

				char** niz;
				//broj kljuceva u tempu + otac + broj_kljuceva u levom bratu
				niz = new char* [2 * (m - 1) + 1 + 10];//POVECAOO SAM MESTO U NIZU
				if (!niz) {
					return false;
				}
				int brojelemniza = 2 * (m - 1) + 1;//+1 zbog dodatnog elementa na kraju
				//za trenutni cvor

				int brtemp = temp->brst;
				for (i = 0; i < brtemp; i++) {
					niz[i] = temp->str[i];
					temp->str[i] = NULL;
					temp->brst--;
				}

				niz[i] = temp->otac->str[poz];
				temp->otac->str[poz] = NULL;
				temp->otac->brst--;
				i++;



				for (int j = 0; i < brojelemniza; j++, i++) {
					niz[i] = temp->otac->pokazivaci[poz + 1]->str[j];
					temp->otac->pokazivaci[poz + 1]->str[j] = NULL;
					temp->otac->pokazivaci[poz + 1]->brst--;
				}

				for (i = 0; i < brojelemniza; i++) {
					if (strcmp(rec, niz[i]) == -1) {
						for (int j = brojelemniza; j > i; j--) {
							niz[j] = niz[j - 1];
						}
						break;
					}
				}
				niz[i] = rec;

				brojelemniza++;

				int razdelni1 = brojelemniza / 3;

				Cvor* novis = new Cvor(m);
				//RASPODELAA TREBAA ISPRAVITI
				for (i = 0; i < razdelni1; i++) {
					temp->str[i] = niz[i];
					temp->brst++;
				}
				temp->otac = pre;
				temp->otac->str[poz] = niz[i];
				i++;
				temp->otac->brst++;
				temp->otac->pokazivaci[poz] = temp;
				poz++;
				for (int j = 0; j < razdelni1; j++, i++) {
					temp->otac->pokazivaci[poz]->str[j] = niz[i];
					temp->otac->pokazivaci[poz]->brst++;
				}


				temp->otac->str[poz] = niz[i];
				i++;
				temp->otac->brst++;
				poz++;
				temp->otac->pokazivaci[poz] = novis;

				poz++;
				for (int j = 0; i < brojelemniza; i++, j++) {
					novis->str[j] = niz[i];
					novis->brst++;
				}
				novis->otac = temp->otac;
				return true;
			}
		}
		//ako desni ne postoji 
		else if (temp->brst == m - 1 && temp->otac->pokazivaci[poz - 1] != nullptr && temp->otac->pokazivaci[poz - 1]->brst == m - 1) {
				char** niz;
				//broj kljuceva u tempu + otac + broj_kljuceva u levom bratu
				niz = new char* [2 * (m - 1) + 1 + 10];//POVECAOO SAM MESTO U NIZU
				if (!niz) {
					return false;
				}
				int brojelemniza = 2 * (m - 1) + 1;//+1 zbog dodatnog elementa na kraju
				//za trenutni cvor

				int brtemp = temp->brst;
				for (i = 0; i < brtemp; i++) {
					niz[i] = temp->otac->pokazivaci[poz - 1]->str[i];
					temp->otac->pokazivaci[poz - 1]->str[i] = NULL;
					temp->otac->pokazivaci[poz - 1]->brst--;

				}

				niz[i] = temp->otac->str[poz - 1];
				temp->otac->str[poz] = NULL;
				temp->otac->brst--;
				i++;



				for (int j = 0; i < brojelemniza; j++, i++) {
					niz[i] = temp->str[j];
					temp->str[j] = NULL;
					temp->brst--;
				}

				for (i = 0; i < brojelemniza; i++) {
					if (strcmp(rec, niz[i]) == -1) {
						for (int j = brojelemniza; j > i; j--) {
							niz[j] = niz[j - 1];
						}
						break;
					}
				}
				niz[i] = rec;

				brojelemniza++;
				//////////////////////////////////////////////////////////////////////////////////////////////
				int razdelni1;
				if (brojelemniza % 3 != 0) {
					razdelni1 = brojelemniza / 3;
				}
				else razdelni1 = brojelemniza / 3 - 1;
				Cvor* novis = new Cvor(m);
				//RASPODELAA TREBAA ISPRAVITI


				for (i = 0; i < razdelni1; i++) {
					temp->otac->pokazivaci[poz - 1]->str[i] = niz[i];
					temp->otac->pokazivaci[poz - 1]->brst++;
				}


				temp->otac = pre;
				temp->otac->str[poz - 1] = niz[i];
				i++;
				temp->otac->brst++;
				//temp->otac->pokazivaci[poz] = ;


				for (int j = 0; j < razdelni1; j++, i++) {
					temp->otac->pokazivaci[poz]->str[j] = niz[i];
					temp->otac->pokazivaci[poz]->brst++;
				}


				temp->otac->str[poz] = niz[i];
				i++;
				temp->otac->brst++;

				poz++;
				temp->otac->pokazivaci[poz] = novis;


				for (int j = 0; i < brojelemniza; i++, j++) {
					novis->str[j] = niz[i];
					novis->brst++;
				}
				novis->otac = pre;
				delete niz;
				//temp->otac->brst < m - 1 &&  mozda treba da se doda proveriti
				while (koren->brst > 2*((2*m-2)/3)) {
					temp = temp->otac;
					char** niz = new char* [temp->brst + 1 + 10];
					int brelemniza = temp->brst;
					if (!niz) {
						return false;
					}
					int i;
					//char* nista = NULL;
					for (i = 0; i <= temp->brst+1; i++) {
						niz[i] = temp->str[i];
						temp->str[i] = NULL;
						temp->brst--;
					}
					
					
					//cvorovi prvog prelamanja korena
					Cvor* novid = new Cvor(m);
					if (!novid) {
						return false;
					}
					Cvor* novil = new Cvor(m);
					if (!novil) {
						return false;
					}
					//novid->str[0] = ime1;
					//novid->str[1] = ime2;
					for (i = 0; i < brelemniza / 2; i++) {
						novil->str[i] = niz[i];
						novil->brst++;
					}
					novil->list = false;
					temp->str[0] = niz[i];
					temp->brst++;
					i++;
					//preskacem oca

					for (int j = 0; i < brelemniza; j++, i++) {
						novid->str[j] = niz[i];
						novid->brst++;
					}
					novid->list = false;
					novil->pokazivaci[0] = temp->pokazivaci[0];
					temp->pokazivaci[0]->otac = novil;
					novil->pokazivaci[1] = temp->pokazivaci[1];
					temp->pokazivaci[1]->otac = novil;
					novil->otac = temp;
					
					novid->pokazivaci[0] = temp->pokazivaci[2];
					temp->pokazivaci[2]->otac = novid;
					novid->pokazivaci[1] = temp->pokazivaci[3];
					temp->pokazivaci[3]->otac = novid;
					novid->otac = temp;

					temp->pokazivaci[0] = novil;
					temp->pokazivaci[1] = novid;
					temp->pokazivaci[2] = nullptr;
					temp->pokazivaci[3] = nullptr;
					
					


					
					


				}

				return true;
		}
		
	}
}

char* Stablo::nacikticlan(int k) {
	Cvor* temp = koren;
	char** niz = new char* [temp->brst + 1 + 100];
	queue<Stablo::Cvor*> q;
	q.push(temp);
	int brojac = 1;
	int br1 = 1;
	int bro = 0;
	int i;
	int brojelemniza = 0;
	while (!q.empty()) {
		//bro = 0;
		//int flag = 1;

		temp = q.front();
		q.pop();


		for (i = 0; i < temp->brst; i++) {
			if (temp->list == false) {
				q.push(temp->pokazivaci[i]);
			}
			niz[brojelemniza] = temp->str[i];
			brojelemniza++;
		}

		if (temp->list == false) {

			q.push(temp->pokazivaci[i]);
		}

	}
	
	int j;
	char* privr;
	for (i = 0; i < brojelemniza; i++)
	{
		for (j = i + 1; j < brojelemniza; j++)
		{
			if (strcmp(niz[i],niz[j])==1)
			{
				privr = niz[i];
				niz[i] = niz[j];
				niz[j] = privr;
			}
		}
	}

	return niz[k];
}

void operator<<(ostream& os, Stablo s)
{
	Stablo::Cvor* temp = s.koren;
	
	queue<Stablo::Cvor*> q;
	q.push(temp);
	int brojac = 1;
	int br1=1;
	int bro = 0;
	int i;
	while (!q.empty()) {
		//bro = 0;
		//int flag = 1;
		
			temp = q.front();
			q.pop();
		
			
			for (i = 0; i < temp->brst; i++) {
				if (temp->list == false) {
					q.push(temp->pokazivaci[i]);
				}
				cout << temp->str[i] << "  ";
			}
			
			if (temp->list == false) {
				
				q.push(temp->pokazivaci[i]);
			}
			
	}
		//brojac = temp->brst + 1;
		//putchar('\n');
	
}
