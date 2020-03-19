#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>


/*
 1. PARBAUDES
 2. PARBAUDES
 3. PRECIZEJUMS PIE IZVADES

 Izveidot masivu. Masiva maksimalais izmers ir 100 elementi.
 Nedrikst izmantot otru masivu! Izmainam janotiek taja pasa masiva!
 Lietotajam jabut iespejams izmainit cik elementus velas ievadit masiva!
 Kad programma pabeigta, prasa vai atkartot.

 Arturs Alsins P1-3
 21. Variants
 Masivs no N elementiem satur latinu alfabeta burtus.
 Noteikt cik reizes masiva ir sastopams katrs burts.
 */

void main() {
	// Mainigie
	int i, n, j, lielieBurti, mazieBurti, currentCharCount, forOutputFormating, i3;
	i = n = j = lielieBurti = mazieBurti = currentCharCount = forOutputFormating = i3 = 0;
	char ievade[100];
	char c2, currentChar, REPEAT;
	string c[2];

	int charToInt(char c);

	do {
		do {

			// Teksta krasa - sarkana
			system("COLOR C");
			clrscr();

			// Nosacijumu pieteiksana
			printf("Ludzu nemiet vera, ka TIKAI vertibas,");
			printf(" \nkas pieder skaitlu intervalam no 1 lidz 100 ieskaitot tiks pienemtas.");
			printf("\n\nNepareizas ievades gadijuma programma atkartos vaicajumu.\n");
			printf("\nGadijuma, ja tiek ievadita kombinacija no burtiem vai simboliem\n");
			printf("un cipariem, burti tiks ignoreti!\n");

			// Elementu skaita ievade
			printf("\n\nLudzu ievadiet cik burtus velaties ievadit...\n\n");
			scanf("%d", &n);
			clrscr();

			if ((n < 1) || (n > 100)) {

				// Teksta krasa - sarkana
				system("COLOR C");
				clrscr();

				printf("\t\t\t\t!!! Kluda !!!\n\t\t Nepieder pie veselo skaitlu intervala [1 - 100]!");
				getch();
			}
		}
		while ((n <= 0) || (n > 100));


		// Programa skaita no 0-ta elementa.
		n -= 1;

		for (i = 0; i <= n; i++) {

			do {

				// Teksta krasa - white
				system("COLOR F");
				clrscr();

				// Lietotajs skaita no 1 lidz n.
				// Izvade pieskaita viens, lai saglabatu logiku
				printf("Ievadiet %u. elementu!\n", i + 1);
				cin >> c2;
				clrscr();
				if ( !( (c2 >= 'A') && (c2 <= 'Z')   || (c2 >= 'a') && (c2 <= 'z') ) ) {

					// Teksta krasa - sarkana
					system("COLOR C");
					clrscr();

					printf("\t\t\t\t!!! Kluda !!!\n\t\t\t%c nav latinu alfabeta burts!", c2);
					getch();
					clrscr();
				}
			} while ( !( (c2 >= 'A') && (c2 <= 'Z')   || (c2 >= 'a') && (c2 <= 'z') ) );

				ievade[i] = c2;

			// Lielo un mazo burtu uzskaite
			if ((ievade[i] >= 'A') && (ievade[i] <= 'Z')) {
				lielieBurti++;
			}
			else if ((ievade[i] >= 'a') && (ievade[i] <= 'z')) {
				mazieBurti++;
			}
		};


		for (i = 0; i <= n; i++) {

			if (ievade[i] != '#')
			{

				forOutputFormating++;
				currentChar = ievade[i];
				currentCharCount = 0;


				for (j = 0; j <= n; j++) {

					if (ievade[j] == currentChar)
					{
							currentCharCount++;
					}
				}


				if (i == 0) {
					printf("\t\t\tBurti un to skaits\n\n");
				};

				if (forOutputFormating % 5 == 0)
				{
					printf("%c = %d\n", currentChar, currentCharCount);
				}
				else
				{
					printf("%c = %d\t", currentChar, currentCharCount);
				}

				// Replace duplicate values with junk value
				for (i3 = 0; i3 <= n; i3++)
				{

					if (currentChar == ievade[i3])
					{
						ievade[i3] = '#';
					}
				}

				// Reset currentCharCount
				currentCharCount = 0;
			}
		}


		// Masiva elementu vertibu izdruka
		/*
		 for (i = 0; i <= n; i++) {
		 printf("%u. elementa vertiba = %c\n", i+1, ievade[i]);
		 }
		*/

		// Krasas nomainisana, mazo un lielo burtu skaita izdruka
		printf("\n\nMazie burti = %u\n", mazieBurti);
		printf("Lielie burti = %u\n", lielieBurti);

		// Vaicajums lietotajam vai velas atkartot programmu
		printf("\n\n\t\tVai velaties atkartot programmu?\n\n");
		printf("\"J\" vai \"j\"\t\t-\tJa, atkartot programmu.");
		printf("\nJebkas cits\t\t-\tNe, aizvert programmu.\n\n");

		lielieBurti = 0;
		mazieBurti = 0;

		cin >> REPEAT;

	} // whole program
	while ((REPEAT == 'J') || (REPEAT == 'j'));

} // for main

