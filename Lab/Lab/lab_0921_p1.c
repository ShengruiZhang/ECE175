// Author: Shengrui Zhang
// Date Created: 09/21/17
// Lab 2
 
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>   // Enables use of rand()
#include <time.h>     // Enables use of time()
//Read section 2.22 Random Numbers in your Zybook

////////////////////////////////////////////////////////////////////
///////// This function returns sum of 2 rolling dices /////////////
////////////////////////////////////////////////////////////////////
int RollDice(void) {
	
	int num;
	num = (rand() % 6) + 1;			//1st dice
	num = num + ((rand() % 6) + 1);	//2nd dice
	
	return num;
}

//////////////////////////////////////////////////////////////////////
///////// This function returns the result of the first game /////////
//it returns:	0   if lose the first time
//				1	if win the first time
//			   -1	otherwise
//////////////////////////////////////////////////////////////////////
int CheckWinorLoseFirstTime(int num) {

	int result = 0;
	if (num == 7 || num == 11) {
		result = 1;
	}
	else if (num == 2 || num == 3 || num == 12) {
		result = 0;
	}
	else {
	result = -1;
    }
	return result;
}

//////////////////////////////////////////////////////////////////////
int main(void) {
	
	srand((int)time(0));

	char newgame = 'y';
	char newroll = 'y';
	
	int diceval = 0;	
	int point = 0;
	
	int result = 0;
	
	int i = 1; // loop variable for the new roll loop
	
	
	
	printf("Let's play Dice Game\n");

	while (newgame != 'q') {    // A loop to determine whether to start a new game, if newgame is 'q' then terminate
		newroll = 'y';
		while (newroll != 'n') {    // loop to control a new roll, if newroll is 'n', then end the game

			diceval = RollDice();     // Roll Dice
			i++;

			printf("Roll # %d\n", i); // display the time of rolling
			printf("Sum of two Dices is %d\n", diceval); // display dice value

			result = CheckWinorLoseFirstTime(diceval);
			if (i == 1) {

				switch (result) {

				case 1:
					printf("you win!\n");
					newroll = 'n'; // update newroll to stop rolling 
					break;


				case -1:
					point = diceval;

				ROLL:
					diceval = RollDice();
					i++;

					if (diceval != point) {

						if (diceval != 7) {

							goto ROLL;
						}
						else {
							result = 0;
						}
					}
					else {
						result = 1;
					}
					break;


				case 0: // case for losing
					printf("you lose!\n");
					break;
				}


			}



			printf("Play another game (q to quit)? ");
			scanf(" %c", &newgame);
		}

	}

		return 0;
	}
