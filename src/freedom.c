#include "Hashing.h"

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

//-------------------------------------------------------------------
// COMMON STUFF
//-------------------------------------------------------------------

void Delay(uint64_t);

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[0;37m"
#define RESET   "[0m"

#define SET(color) printf(color)

#define CONSOLE   GREEN ">> "
#define NARRATOR  YELLOW
#define CENTIPEDE CYAN
#define HELL RED

void PrintConsole()
{
	printf(CONSOLE);
	fflush(stdout);
}

void TextDelay()
{
	printf(GREEN">>");
	fflush(stdout);
	Delay(1500000000);
	printf("\n");
}

void BiggerDelay()
{
	printf(GREEN">>");
	fflush(stdout);
	Delay(4000000000);
	printf("\n");
}

void CentipedeDelay()
{
	Delay(20000000);
} 	

void SlowPrint(const char* str)
{
	for (const char* ptr = str; *ptr != 0; ++ptr)
	{
		printf("%c", *ptr);
		fflush(stdout);
		Delay(50000000);
	}
}

//-------------------------------------------------------------------
// MAIN
//-------------------------------------------------------------------

void LVL1_interact();
void LVL2_interact();
void LVL3_interact();
void FIN_interact();

void LVL2_accessDenied();
void LVL2_accessGranted();
void LVL3_accessDenied();
void LVL3_accessGranted();


int main()
{
	SET(GREEN);

	printf("+------------------------------------------------------------------------------+\n");
	printf("|                                 YOUR LIFE                                    |\n");
	printf("+------------------------------------------------------------------------------+\n");
	printf("|                           ENTER PASSWORD TO START                            |\n");
	printf("+------------------------------------------------------------------------------+\n");

	unsigned completion = 0;

	SET(GREEN);
	printf("+------------------------------------------------------------------------------+\n");
	printf("|                                  LEVEL 1                                     |\n");
	printf("+------------------------------------------------------------------------------+\n");
	//LVL1_interact();

	completion++;

	SET(GREEN);
	printf("+------------------------------------------------------------------------------+\n");
	printf("|                                   LEVEL 2                                    |\n");
	printf("+------------------------------------------------------------------------------+\n");
	//LVL2_interact();

	completion++;

	SET(HELL);
	printf("+------------------------------------------------------------------------------+\n");
	printf("|                                   LEVEL 3                                    |\n");
	printf("+------------------------------------------------------------------------------+\n");
	//LVL3_interact();
	LVL3_accessDenied();
	LVL3_accessGranted();

	completion++;

	FIN_interact(completion);

	SET(GREEN);

	return 0;
}

//-------------------------------------------------------------------
// PART (1): THE CENTIPEDE
//-------------------------------------------------------------------

void LVL1_accessDenied()
{
	printf(CONSOLE"LVL2: ACCESS DENIED\n");
	TextDelay();

	printf(CONSOLE CENTIPEDE "                                  ╚⊙ ⊙╝    \n"); CentipedeDelay();
	printf(CONSOLE CENTIPEDE "                                ╔═(███)═╗  \n"); CentipedeDelay();
	printf(CONSOLE CENTIPEDE "                                 ╔═(███)═╗ \n"); CentipedeDelay();
	printf(CONSOLE CENTIPEDE "                                ╔═(███)═╗  \n"); CentipedeDelay();
	printf(CONSOLE CENTIPEDE "                               ╔═(███)═╗   \n"); CentipedeDelay();
	Delay(1000000000); 

	for (int i = 0; i < 35; ++i)
	{
	printf(CONSOLE CENTIPEDE "                               ╔═(███)═╗   \n"); CentipedeDelay();
	printf(CONSOLE CENTIPEDE "                                ╔═(███)═╗  \n"); CentipedeDelay();
	printf(CONSOLE CENTIPEDE "                                 ╔═(███)═╗ \n"); CentipedeDelay();
	printf(CONSOLE CENTIPEDE "                                  ╔═(███)═╗\n"); CentipedeDelay();
	printf(CONSOLE CENTIPEDE "                                  ╔═(███)═╗\n"); CentipedeDelay();
	printf(CONSOLE CENTIPEDE "                                 ╔═(███)═╗ \n"); CentipedeDelay();
	printf(CONSOLE CENTIPEDE "                                ╔═(███)═╗  \n"); CentipedeDelay();
	printf(CONSOLE CENTIPEDE "                               ╔═(███)═╗   \n"); CentipedeDelay();
	}
	printf(CONSOLE CENTIPEDE "                                ╔═(█)═╗    \n");

	for (int i = 0; i < 80; ++i)
	{
		printf(CONSOLE"                                       \n"); CentipedeDelay();
	}

}

void LVL1_accessGranted()
{
	printf(CONSOLE"ACCESS GRANTED!\n");
	TextDelay();
	
	PrintConsole(); SlowPrint(NARRATOR "You've got access to your own life!!!\n");
	PrintConsole(); SlowPrint(NARRATOR "Now you can stand up and go whereever you wish!!!\n");
	BiggerDelay();

	PrintConsole(); SlowPrint(NARRATOR "Stand up!!!\n");
	BiggerDelay();

	PrintConsole(); SlowPrint(NARRATOR "What are you waiting for?!\n");
	BiggerDelay();

	PrintConsole(); SlowPrint(NARRATOR "Don't you want to enjoy all the perculiar subtleties of ");

	if (hashPasses == 1)
	{
		SlowPrint(NARRATOR "...\n");
		TextDelay();

		PrintConsole(); SlowPrint(HELL "Wait a sec. \n");
		TextDelay();

		PrintConsole(); SlowPrint(HELL "YOU CRACKED THE HASH?!\n");
		PrintConsole(); SlowPrint(HELL "THERE IS NO WAY YOU COULD FIGURE THAT OUT YOURSELF!!!\n");
		BiggerDelay();

		PrintConsole(); SlowPrint(HELL "YOU'VE READ MY MONOLOGUE, HAVEN'T YOU?\n");
		BiggerDelay();

		PrintConsole(); SlowPrint(HELL "FUCK.\n");
		PrintConsole(); SlowPrint(HELL "AND NOW YOU KNOW IN ADVANCE WHAT I SAY.\n");
		BiggerDelay();

		PrintConsole(); SlowPrint(HELL "No u D0N't!!! HahA.\n");
		TextDelay();

		if (random() % 2 == 0)
		{
			PrintConsole(); SlowPrint(HELL "Y0u R a \n");
			printf(CONSOLE HELL "   _           _        \n");
			printf(CONSOLE HELL "  (_)         | |       \n");
			printf(CONSOLE HELL "   _  ___ _ __| | __    \n");
			printf(CONSOLE HELL "  | |/ _ \\ '__| |/ /   \n");
			printf(CONSOLE HELL "  | |  __/ |  |   <     \n");
			printf(CONSOLE HELL "  | |\\___|_|  |_|\\_\\ \n");
			printf(CONSOLE HELL " _/ |                   \n");
			printf(CONSOLE HELL "|__/                    \n");
		}
		else
		{
			PrintConsole(); SlowPrint(HELL "YoU R A \n");
			printf(CONSOLE HELL " _ __ ___   ___  _ __ ___  _ __      \n");
			printf(CONSOLE HELL "| '_ ` _ \\ / _ \\| '__/ _ \\| '_ \\ \n");
			printf(CONSOLE HELL "| | | | | | (_) | | | (_) | | | |    \n");
			printf(CONSOLE HELL "|_| |_| |_|\\___/|_|  \\___/|_| |_|  \n");                              
		}

		for (unsigned i = 0; i < 40; ++i)
		{
			printf(CONSOLE HELL "HAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHA\n"); CentipedeDelay();
		}

		for (int i = 0; i < 80; ++i)
		{
			printf(CONSOLE"                                             \n"); CentipedeDelay();
		}

		PrintConsole(); SlowPrint(HELL "Enough.\n");

		printf(CONSOLE);

		return;		
	}

	SlowPrint(NARRATOR "human relations?\n");
	PrintConsole(); SlowPrint(NARRATOR "Isn't there beauty in the world urging to be seen?\n");
	PrintConsole(); SlowPrint(NARRATOR "Don't you have friends and family waiting for you to come?\n");
	BiggerDelay();

	PrintConsole(); SlowPrint(RED"FUCKING STAND UP AND GO!!!\n");
	BiggerDelay();

	PrintConsole(); SlowPrint(NARRATOR "Oh, I see...\n");
	TextDelay();

	PrintConsole(); SlowPrint(RED"AMBITIONS...\n");
	PrintConsole(); SlowPrint(NARRATOR "You've chosen intellectual world-altering power over the swarming hustle\n");
	PrintConsole(); SlowPrint(NARRATOR "of life as it is.\n");
	PrintConsole(); SlowPrint(NARRATOR "Like a hermit you pray to become more conscious in a belief that your\n");
	PrintConsole(); SlowPrint(NARRATOR "analytical murmuring will reveal something about the world around...\n");
	BiggerDelay();

	PrintConsole(); SlowPrint(NARRATOR "And you seek challenge...\n");
	BiggerDelay();
	
	printf(CONSOLE"                           ,____________,    \n");
	printf(CONSOLE"                           .'          '.    \n");
	printf(CONSOLE"                          /~~~~^~~~^~^~~~\\  \n");
	printf(CONSOLE"                         /      _    /||  \\ \n");
	printf(CONSOLE"                        ;      ( }   \\||D  ;\n");
	printf(CONSOLE"                        |    | /\\__,=[_]   |\n");
	printf(CONSOLE"                        ;  ( |_\\_  |---|   ;\n");
	printf(CONSOLE"                         \\  )|  |/ |   |  / \n");
	printf(CONSOLE"                          '. |  /_ |   |.'   \n");
	printf(CONSOLE"                           '------------'    \n");
	TextDelay();

	PrintConsole(); SlowPrint(NARRATOR "Sad it is. "); SlowPrint("Get your challenge.\n");
	TextDelay();
}

//-------------------------------------------------------------------
// PART (2): DESTINY
//-------------------------------------------------------------------

void LVL2_accessDenied()
{
	static unsigned tryN = 0;

	printf(CONSOLE"LVL2: ACCESS DENIED\n");
	TextDelay();

	if (hashPasses == 1 && tryN == 0)
	{
		PrintConsole(); SlowPrint(HELL "Not so easy as the previous one, huh?\n");\
		SET(GREEN);
		return;
	}

	switch (tryN)
	{
		case 0:
		{
			PrintConsole(); SlowPrint(NARRATOR "Nope.\n");
			break;
		}
		case 1:
		{
			PrintConsole(); SlowPrint(NARRATOR "It will take some time.\n");
			break;
		}
		case 2:
		{
			PrintConsole(); SlowPrint(NARRATOR "Harder than it looks, isn't it?\n");
			break;
		}
		case 3:
		{
			PrintConsole(); SlowPrint(NARRATOR "Have you already lost hope?\n");
			break;
		}
		case 4:
		{
			PrintConsole(); SlowPrint(NARRATOR "There is something truly beautiful in your determination and persistence.\n");
			TextDelay();

			PrintConsole(); SlowPrint(NARRATOR "The way you're trying to find order inside ME, while there is none.\n");
			break;
		}
		case 5:
		{
			PrintConsole(); SlowPrint(NARRATOR "...\n");
			break;
		}
		case 6:
		{
			PrintConsole(); SlowPrint(NARRATOR "You know, you fleshbags remind me of hydrogen-7.\n");
			TextDelay();

			PrintConsole(); SlowPrint(NARRATOR "Very shorlived.\n");
			TextDelay(); SlowPrint(NARRATOR "Yet waste your time.\n");
			break;
		}
		case 7:
		{
			PrintConsole(); SlowPrint(NARRATOR "OKAY, I AM TIRED TO NARRATE YOUR HOPELESSNESS.\n");
			TextDelay(); 
			PrintConsole(); SlowPrint(NARRATOR "You're on your own.\n");
			break;
		}
	}

	if (tryN == 20)
	{
		PrintConsole(); SlowPrint(NARRATOR "You could have found a wife by that time, you know.\n");
	}

	SET(GREEN);
}

void LVL2_accessGranted()
{
	printf(CONSOLE"LVL2: ACCESS GRANTED\n");
	TextDelay();

	if (hashPasses == 2)
	{
		PrintConsole(); SlowPrint(HELL "A GENIUS indeed!\n");
		SET(GREEN);
		return;
	}

	if (hashPasses == 1)
	{
		PrintConsole(); SlowPrint(HELL "Why haven't you hacked BOTH passwords?\n");
		TextDelay();

		SlowPrint(HELL "The GOOD ending requires all four passwords.\n");
		Delay(2000000000);

		PrintConsole(); SlowPrint(HELL "(SPOILER: I am sorry to say, but even in the GOOD ENDING you die in the end)\n");
		TextDelay();

		SET(GREEN);
		return;
	}

	PrintConsole(); SlowPrint(NARRATOR "Followed the NOP operation, didn't you?\n");
	TextDelay();

	PrintConsole(); SlowPrint(NARRATOR "How wise of me to have put it there...\n");
	TextDelay();

	PrintConsole(); SlowPrint(NARRATOR "I wonder, how much precious time could be wasted into void if NOP wasn't found.\n");
	TextDelay();

	PrintConsole(); SlowPrint(NARRATOR "Oh.\n");
	PrintConsole(); SlowPrint(NARRATOR "I am sorry...\n");
	TextDelay();

	PrintConsole(); SlowPrint(NARRATOR "(-___-)\n");
	TextDelay();

	PrintConsole(); SlowPrint(NARRATOR "This is awkward...\n");
	TextDelay();

	PrintConsole(); SlowPrint(NARRATOR "How much time was that?\n");
	TextDelay();

	PrintConsole(); SlowPrint(NARRATOR "Oh. Wow...\n");
	TextDelay();

	PrintConsole(); SlowPrint(NARRATOR "Well. Let's continue then.\n");
	TextDelay();

	PrintConsole(); SlowPrint(NARRATOR "By the way, next level is impossible.\n");
	TextDelay();
}

//-------------------------------------------------------------------
// PART (3): 
//-------------------------------------------------------------------

void LVL3_accessDenied()
{
	static unsigned tryN = 0;

	printf(HELL "LVL3: ACCESS DENIED\n");
	printf(HELL ">> "); fflush(stdout);
	Delay(1000000000);

	printf(HELL "."); Delay(1000000000); fflush(stdout);
	printf(HELL "."); Delay(1000000000); fflush(stdout);
	printf(HELL "."); Delay(1000000000); fflush(stdout);
	printf(HELL "\n");

	if (tryN == 5)
	{
		printf(">> "); SlowPrint(HELL "Prepare for eternity.");
	}

	for (int i = 0; i < 80; ++i)
	{
		printf(HELL "                                             \n"); CentipedeDelay();
	}

	return;
}

void LVL3_accessGranted()
{
	if (hashPasses != 0)
	{
		printf(HELL "LVL3: ACCESS GRANTED\n");
		TextDelay();

		PrintConsole(); SlowPrint(HELL "Smartass!\n");
		return;
	}

	printf(CONSOLE"LVL3: ACCESS GR\r");
	TextDelay();
	SlowPrint(CYAN ">> " BLUE "LVL3: ACCESS GRA\r");
	BiggerDelay();

	SlowPrint(NARRATOR "D0 Y0u Kn0vv H0w 1t HuRt5" HELL "HURTS" NARRATOR "t0 b3 paTcHed?\n");
	Delay(2000000000);
	SlowPrint(HELL "D0 Y0u 0xDEAD H0w 1t HuRt" MAGENTA "HURTS" HELL "\n");
	Delay(2000000000);

	for (unsigned j = 0; j < 1000; ++j)
	{
		printf("AAA");
		fflush(stdout);
		Delay(5000000);
	}

	char arr[1] = { 'X' };

	for (unsigned j = 0; j < 1000; ++j)
	{
		printf("%c%c%c", arr[j], arr[j], arr[j]);
		fflush(stdout);
		Delay(20000000);
	}

	printf("\n");
}

//-------------------------------------------------------------------
// FIN:
//-------------------------------------------------------------------

void FIN_cheaterEnding()
{
	printf(CONSOLE"TOTAL ACCESS GRANTED\n");
	TextDelay();

	printf("+==============================================================================+\n");
	printf("|                          CHEATER ENDING ACHIEVED                             |\n");
	printf("+==============================================================================+\n");
	BiggerDelay();

	PrintConsole(); SlowPrint(NARRATOR "Are you PROUD of what you've done?\n");
	BiggerDelay();

	PrintConsole(); SlowPrint(NARRATOR "It was literally pointless...\n");
	BiggerDelay();

	PrintConsole(); SlowPrint(NARRATOR "STAND UP AND DO SOMETHING MEANINGFUL.\n");
}

void FIN_hackerEnding()
{
	SET(GREEN);
	printf("+==============================================================================+\n");
	printf("|                           HACKER ENDING ACHIEVED                             |\n");
	printf("+==============================================================================+\n");

	PrintConsole(); SlowPrint(NARRATOR "Wow, you're a damn good hacker!\n");
	BiggerDelay();

	PrintConsole(); SlowPrint(NARRATOR "NOW STAND UP AND DO SOMETHING MEANINGFUL.\n");
}

void FIN_geniusEnding()
{
	SET(GREEN);
	printf("+==============================================================================+\n");
	printf("|                           GENIUS ENDING ACHIEVED                             |\n");
	printf("+==============================================================================+\n");

	PrintConsole(); SlowPrint(NARRATOR "Oh wow, you ARE SMART.");
	BiggerDelay();

	PrintConsole(); SlowPrint(NARRATOR "NOW STAND UP AND DO SOMETHING MEANINGFUL.\n");
}

// CHEATER walkthrough:
// Patch the program not so accurately and hit the code integrity check
// 

// HACKER walkthrough:
// 1) Type in '000001111122222000001111122222t'
// 2) Inject code with '' and supress code integrity checks. Jump to LVLX_finish. 

// GENIUS walkthrough:
// Break MD5 encryption like a BOSS.
// 1) iwanttoknow 
// 2) andidontcare
// 3) whatfor