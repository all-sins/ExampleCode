/*
	 Laboratorijas darbs - 7. praktiskais darbs - vienizm�ru dinamiskie mas�vi:
	  P�c piekt� darba uzdevuma p�rveidot mas�vu par dinamisko. j�b�t iesp�jai:
	  1.1. Izveidot mas�vu no jauna (ja jau eksist� - tad s�kum� atbr�vot atmi�u);
	  1.2. Aizpild�t autom�tiski;
	  1.3. Aizpild�t manu�li.

	  T�l�k j�b�t iesp�jai p�c lietot�ja izv�les (cikl�):
	  2.1. Izpild�t individu�lo uzdevumu;
	  2.2. Izmain�t mas�va izm�ru, saglab�jot mas�v� iepriek��j�s v�rt�bas (ja par�d�s jauni elementi,
		 tad j�aizpilda manu�li tikai tie);
	  2.3. S�kt programmu no s�kuma;
	  2.4. Beigt darbu
*/
#pragma hdrstop
#pragma argsused

#include <iostream.h>
#include <conio.h>
#include <stdlib.h>


char izvelne();
char izvelne2();
int jautat_izmeru();
int skaitit_lvs(double*, int);
void print_double_arr(double*, int);

//Jaut�t, vai lietot�js grib atkartot programmu
char izvelne() {
/*
	  P�c piekt� darba uzdevuma p�rveidot mas�vu par dinamisko. j�b�t iesp�jai:
	  1.1. Izveidot mas�vu no jauna (ja jau eksist� - tad s�kum� atbr�vot atmi�u);
	  1.2. Aizpild�t autom�tiski;
	  1.3. Aizpild�t manu�li.
*/
	//lietotaja atbilde
	char atb;

		cout << "\nIzvelies: \n";

		cout << "1 - Aizpildit masivu automatiski\n";
		cout << "2 - Aizpildit masivu manuali\n";
		cout << "\n\n";

		cin >> atb;
		clrscr();

	return atb;
}

char izvelne2() {
/*
T�l�k j�b�t iesp�jai p�c lietot�ja izv�les (cikl�):
	  2.1. Izpild�t individu�lo uzdevumu;
	  2.2. Izmain�t mas�va izm�ru, saglab�jot mas�v� iepriek��j�s v�rt�bas (ja par�d�s jauni elementi,
		 tad j�aizpilda manu�li tikai tie);
	  2.3. S�kt programmu no s�kuma;
	  2.4. Beigt darbu
*/
	//lietotaja atbilde
	char atb;

	cout << "\nIzvelies: \n";

	cout << "1 - Izpildit individualo uzdevumu\n";
	cout << "2 - Izmainit masiva izmeru saglabajot ieprieksejas vertibas\n";
	cout << "3 - Sakt programmu no sakuma\n";
	cout << "4 - Beigt darbu\n";
	cout << "\n\n";

	cin >> atb;
	clrscr();

	return atb;
}

int jautat_izmeru() {
	//masiva izmers
	int n;

	do {
		cout << "Ievadi jauno masiva izmeru (Nedzrikst but mazak par 0): ";
		cin >> n;
		if (n < 1)
		{
			cout << "Nepareiza ievade! \nIevadei ir jabut veselam, pozitivam skaitlim!\n";
			cout << "Nospieziet jebkuru pogu, lai meginatu velreiz...";
			getch();
			clrscr;
		}
	} while (n < 1);

	return n;
}

int skaitit_lvs(double *arr, int n) {
	//LIS - Largest Increasing Subsequence (visgaraka augosa apaksvirkne)
	//LIS garums
	int lis_length = 1;
	//vieta masiva kur sakas LIS
	int lis_start = 0;
	//satur augosas apaksvirknes garumu for iteracija
	int is = 1;
	int i = 0;

	// atrod LIS sakumu un garumu
	for (i = 0; i < n; i++) {
		if (i != 0){
			if (arr[i] > arr[i-1]) {
				is++;

				if (is >= lis_length) {
					lis_length = is;
					lis_start = i - lis_length;
				}
			} else {
				is = 1;
			}
		}
	}

	lis_start++;

	if (lis_length == 1) {
		cout << "\nNav Visgaraka Augosa Apaksvirkne.\n";
	} else {
		cout << "\n\nVisgaraka Augosa Apaksvirkne: \n";

		for (i = lis_start; i < lis_start + lis_length; i++)
			cout << arr[i] << "\t";

		cout << "\n\n";
		cout << "Garums: " << lis_length << "\n";

	}

	return 0;
}

void print_double_arr(double *arr, int n) {
	int i = 0;

	cout << "\nMasiva vertibas : \n\n";
	if (n < 120)
	{
		for (i = 0; i < n; i++)
			cout << arr[i] << "\t";
	}
	else
	{
		for (i = 0; i < 120; i++)
		cout << arr[i] << "\t";
		cout << "\n\n\t\t... Un vel talak " << n-120  << " vertibas ...";
	}
}


int main()
{
	//masiva izmers
	double dmas_size = 0;
	//iterators
	int i;
	//Lietotaja atbilde
	char atb1, atb2, atb3, atb4;
	//main�gais nejau�u skait�u �ener�toram
	time_t t;
	//raditajs uz dinamisku masivu
	double *dmas = NULL;
	//lietot�ja atbilde izveln�
	char izvele;
	//ja 1, programma sakas no jauna
	int skip = 0;

	//nejau�u skait�u �ener�tors
	srand((unsigned) time(&t));

	do {
		skip = 0;
		// Izveidot masivu no jauna
		free(dmas);
		dmas = NULL;

		dmas_size = jautat_izmeru();

		//calloc lai inicializet masivu ar nullem
		dmas = (double*) calloc(dmas_size, sizeof(double));

		print_double_arr(dmas, dmas_size);
		izvele = izvelne();

		//Aizpildit masivu automatiski
		if (izvele == '1') {

			clrscr();
			cout << "Pasreizejais masiva izmers ir " << dmas_size << ".\n";

			for (i = 0; i < dmas_size; i++) {
				dmas[i] = 1 + rand() % 100;
			}

		}
		else if (izvele == '2') {

			cout << "Pasreiz masiva izmers ir " << dmas_size << ".\n";

			for (i = 0; i < dmas_size ; i++) {
				clrscr();
				cout << "Ievadi masiva " << i + 1 << ". elementu: ";
				cin >> dmas[i];
			}
		}

		print_double_arr(dmas, dmas_size);

		do {
			izvele = izvelne2();

			if (izvele == '1') {
				skaitit_lvs(dmas, dmas_size);
			}
			else if (izvele == '2') {
				dmas_size = jautat_izmeru();
				dmas = (double*) realloc(dmas, dmas_size * sizeof(double));

				for (i = 0; i < dmas_size ; i++) {
					if (dmas[i] == 0) {
						cout << "Ievadi masiva " << i + 1 << ". elementa vertibu : ";
						cin >> dmas[i];
					}
				}

				print_double_arr(dmas, dmas_size);
			}
			else if (izvele == '3') {
				skip = 1;
			}
			else if (izvele == '4') {
				exit(1);
			}
			else
			{
				cout << "Nepareiza izvele!\nLudzu izmantojiet ciparus,\nkas noraditi pie izveles!";
				cout << "\nNospieziet jebkuru pogu lai meginatu velreiz...\n";
				getch();
			}
		} while (skip == 0);

		cout << "\n";
	} while (1);

}


