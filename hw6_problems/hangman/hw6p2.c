/*
Author: Shengrui Zhang
Student ID: 23426900
Email: shengruizhang@email.arizona.edu
Created Date: 10/15/17
*/

/*////////////////////////////////////// PROBLEM TWO /////////////////////////////////////*/
/*
Inputs:
characters

Outputs:
corresponding reaction of hangman game

Problems: play the game hangman
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define LETTSIZ 7

/*////////////////////// GET WORDS ////////////////////////////*/
void get_word(char word[]) {
	char WORD[][8] = {"program", "puzzles", "squeeze", "circuit", "devoted", "journey", "version", "totally", "respect"};
	int i, num;
	num = (rand()%9);
	for (i = 0; i < 7; ++i) {
		word[i] = WORD[num][i];
	}
}


/*///////////////////////////////////////// PRINT WORD ///////////////////////////*/

void print_word(char x[], int len) {
	int z = 0;
	printf("\n");
	for (z = 0; z < len; ++z) {
		printf("%c", x[z]);
	}
	printf("\n");
}


/*/////////////////////////////////////// MAIN ////////////////////////////////*/

int main(void) {
	srand((int)time(0));
	
	/////////////////// GETTING WORD ///////////////////////
	char target[LETTSIZ + 1] = {"*"};
	unsigned int i = 0;
	
	get_word(target);                                     // comment out for debugging
	//strcpy(target, "circuit");                              // for TESTING
	printf("Let's play Hangman. The secret word is:\n");
	//printf("%s\n", target);    // TESTING

	for (i = 0; i < strlen(target); ++i) {      // PRINTING STARS
		printf("*");
	}
	printf("\n");
	
	
	/*///////////////////// LOOPING FOR GUESSING /////////////////////
	LOOP CONDITION: WHEN TIME OF TRIES DOWN TO 0 OR PLAYER WIN THE GAME
	*/
	
	unsigned int counter = 7;              // 7 chances to guess 
	bool status = false;                   // false for losing the game, otherwise winning
	
	char letter = '\0';
	char guess[LETTSIZ + 1] = {'*', '*', '*', '*', '*', '*', '*'};
	unsigned int times = 0;
	
	while (counter != 0 && status != true) 
	{
		printf("Guess a letter: ");
		scanf(" %c", &letter);
		//printf("%c\n", letter);        // TESTING
		
		///////// CHECK IF THE NUMBER IS IN THE WORD //////////////////////
		times = 0;                           // RESET

		for (i = 0; i < LETTSIZ; ++i) 
		{
			if (letter == target[i]) {             // LETTER GUESSED IS IN THE WORD
				//printf("%c\n", letter);              
				guess[i] = letter;                  // PUT THE CORRECT INTO THE CORRESPONDING PLACE IN ARRAY GUESS
				++times;
				//printf("%c\n", guess[i]);
			}
		}
		
		if (strcmp(target, guess) == 0) {
			status = true;                            // UPDATE STATUS IF THE WHOLE WORD MATCHED
		}
		else if (times == 0) {                            // OTHERWISE SET STATUE FALSE AND DISPLAY MESG				
			--counter;                            // DECREASE COUNTER
			printf("%c is not in the secret word., You have %d tries left.\n", letter, counter);
			status = false;
		}
		else {                                     // IF THE LETTER WAS CORRECT BUT THE STILL HAVE TRIES, SHOW ME
			printf("%c was found %d times in the secret word.\n", letter, times);
		}

		print_word(guess, LETTSIZ);
	}
	
	if (status == 0) {
		///////// LOSING THE GAME
		printf("Game over! The secret word was: %s\n", target);
	}
	else {
		///// WINNING THE GAME
		printf("Congratulations! You found te secret word: %s\n", target);
	}
	
	return 0;
}