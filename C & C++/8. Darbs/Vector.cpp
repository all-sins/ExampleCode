﻿#pragma hdrstop
#pragma argsused

#include <vector>
#include <conio.h>
#include <windows.h>
using namespace std;

/*
8. praktiskais darbs - VEKTORI:
Pec piekta darba uzdevuma parveidot masivu par vektoru (ierobezojums par maksimalo masiva
izmeru 100 vairs nav speka).

Jabut iespejai:
1.1. Izveidot vektoru (ja jaueksiste - tad sakuma atbrivot atminu);

1.2.
	1.2.1. Aizpildīt automātiski;
	1.2.2. vai ari Aizpildit manuali.

2. Talak jabut iespejai pec lietotaja izveles (cikla):
	2.1. Izpildit individuālo uzdevumu;
	2.2. Pievienot jaunu elementu vektoram pēc lietotāja izvēles;
		2.2.1. Prieksa;
		2.2.2. Beigas;

	2.3. Dzēst elementu no vektora
		2.3.1. Prieksa;
		2.3.2. Dzest elementu ar noteikto (lietotaja ievadito) vertibu;
		2.3.3. Beigas;

	2.4. Sakt programmu no sakuma;

	2.5. Beigt darbu

Punkti 1.2., 2,2. un 2.3.jaizpilda ar apaksprogrammam!
*/

std::vector<int> inputVector(10);
int i;
char Awnser, Repeat = 'j';

void printVector()
{
	for (i = 0; i < inputVector.size(); i++)
	{
		// Programma skaita no 0, bet cilveks no 1.
		// logikas saglabasanas del pieskaitam 1.
		printf("%u. %u\t", i+1, inputVector[i]);
	}
}

void main()
{
	do
	{
	// Begining of while loop

		// Izvelnes un vectora izprintesana
		clrscr();
		printVector();
		printf("\n\n\n1. Some functionality WIP\n");
		printf("2. Iziet\n");
		printf("\nIzvelieties vienu no opcijam...\n\n");

		// Clears input buffer from previous data
		// Use this when reading chars because it also stores "ENTER" as a value
		// New Stuff!
		flushall();

		// Nolasa izveli no lietotaja
		scanf("%c", &Awnser);

		// Nosaka veicamo darbibu
		switch (Awnser) {

			case '1':
			{
				printf("WORK IN PROGRESS");
				printf("\nNospieziet jebkuru pogu, lai turpinatu...");
				getch();
				clrscr();
				break;
			}

			case '2':
			{
				Repeat = 'n';
				break;
			}

			default:
			{
				clrscr();
				printf("\t\tKluda! \n\nLudzu izmantojies izvelnes apzimetos ciparus!\n");
				printf("%c nav viens no noraditajiem izvelnes cipariem!\n", Awnser);
				printf("\nNospieziet jebkuru pogu, lai turpinatu...");
				getch();
				break;
			}

		}
		// End of switch

	// End of while
	}
	while (Repeat == 'j' || Repeat == 'J');



	// End of code
	clrscr();
	for (i = 0; i < 4; i++)
	{
		printf("Goodbye!");
		Sleep(150);
		clrscr();
		Sleep(150);
	}
}

