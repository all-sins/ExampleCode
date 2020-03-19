#pragma hdrstop
#pragma argsused

//#include <tsukiakariLibrary.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

/*
Izveleties jebkuru strukturoto konsoles programmu, 40 - 60 komandrindu garu, kas satur minimums vienu FOR ciklu,
vienu WHILE/DO-WHILE ciklu un minimums vienu apaksprogrammu (papildus pie main).
Pierakstiet pasas programmas uzdevumu. Uzrakstit programmas un apaksprogrammas blokshemas.
Pievienot ekransavinus korekto un nekorektu datu ievades attelosanai.

MISSION OBJECTIVES :
	* length <= 40 lines
	* <= 1 FOR cycle
	* <= 1 function

TIPS AND TRICKS :
	* When you read characters using the "%c" format, it will read the next character in the input buffer,
	 it will not skip any white-space. And when using scanf to read anything, the newline you enter to send the input to the program will also be sent,
	 and added as a white-space character after the end of your input. Most formats do skip leading white-space (like for example the "%d" format),
	 but the "%c" and "%[" formats do not.

	 When reading character it's almost always advisable to skip leading white-space, which is done by adding a space before the format, like e.g.

	 scanf(" %c", &decision);
	 //     ^^
	 //     |
	 // Note space here

*/

// Variable decleration
char repeatCode;
int windowWidth, i, animationLength = 20;

// Start of code
void main()
{

	// Loop in case user wants to repeat the code
	do
	{

		// cmdRain
		clrscr();
		printf("Ievadiet cmdRain demonstracijas platumu (terminala loga platumu) ... \n\n\a");
		scanf("%d", &windowWidth);
		clrscr();

		srand(time(NULL));
		printf("Interval set! [1 - %d]", rand() % windowWidth + 1);

	   /*	for (i = 0; i == windowWidth; i++)
		{
			gotoxy( (rand() % windowWidth + 1), i);
			printf("|");
		}*/


		// Prompt to determine if program should be repeated. Read value of repeatCode.
		printf("\n\nVai velaties atkartot programmu?\n");
		printf("\n\"j\" vai \"J\"\t-\tJa, atkartot programmu!");
		printf("\nJebkas cits\t-\tNe, aizvert programmu!\n\n");
		scanf(" %c", &repeatCode);

	}
	while ( (repeatCode == 'j') || (repeatCode == 'J') );
	// End of loop


	// End of code
	printf("\n\nEnd of program! Press any key to exit...\n\a\a");
	getch();
}

