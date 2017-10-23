/*
Author: Shengrui Zhang
Student ID: 23426900
Email: shengruizhang@email.arizona.edu
Created Date: 10/20/17
*/
/*  PLAYING THE CONNECTING FOUR GAME /*/

/*////////////////////////////////////// PROBLEM ONE /////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define ROW 6
#define COL 7
#define INT 9

typedef unsigned int uint;                // DEFINE
typedef unsigned char uchar;

typedef struct CURRENT_ROW {
	int r_0;
	int r_1;
	int r_2;
	int r_3;
	int r_4;
	int r_5;
	int r_6;
} CURRENT_ROW;

void INIT_BOARD(uint BOARD[][COL], uint tr);
void PRINT_BOARD(uint BOARD[][COL]);
void BOARD_CHECK(uchar BOARD[][COL]);



/*///////////////////////////////// MAIN FUNCTION //////////////////////*/

int main(void) 
{
	printf("Let's play Connect Four in a Line\n\n");
	
	bool status = false;                  // MAIN LOOP CONDITIONAL VARI, FALSE FOR CONTINUING, TRUE FOR BREAK THE LOOP
	bool veri = false;                    // FOR CHECK THE VALIDITY OF THE LETTER
	uint round = 1;                       // ROUND VARI, DETERMINE WHOSE ROUNDM, GAME STARTS W/ PLYER 1
	uchar col_i = '\0';                   // INPUT LETTER VARI, WHERE THE PLACE IS PUT
	
	CURRENT_ROW c_r;                      // TRACK THE CURRENT ROW
	c_r.r_0 = 0;                          // STARTS FROM ROW 0
	c_r.r_1 = 0;
	c_r.r_2 = 0;
	c_r.r_3 = 0;
	c_r.r_4 = 0;
	c_r.r_5 = 0;
	c_r.r_6 = 0;
	
	uint temp = 0;
	
	/* DEF BOARD, USE NUMBER DIGIT TO REPRESENT XS AND OS, 1 FOR X, 2 FOR O*/
	uint board[ROW][COL];
	
	/* INITIATE EVERYTHING TO A NON 1,0 NUMBER */
	INIT_BOARD(board, INT);
	
	/*///////////////////////// LOOPING: CONDITION: STATUS /////////////////////////////*/

	while (status != true)
	{
		/*///////// PRINTING THE BOARD ////////////////*/
		PRINT_BOARD(board);
		
		while (veri != true)         // TRUE FOR A VALID INPUT, VICE VERSA
		{
			/*///// DETERMINE WHOSE ROUND, 1 FOR PLAYER 1, 2 FOR 2 //////*/
			if (round == 1) {
				printf("Player 1: Which column would you like to add an 'X'?");
			}
			else if (round == 2) {
				printf("Player 2: Which column would you like to add an 'O'?");
			}
			
			scanf(" %c", &col_i);    // TAKE INPUT
			
			/*//////// FILLING THE BOARD /////////////*/
			
			if (round == 1 && col_i >= 65 && col_i <= 71) {           // ROUND FOR PLAYER 1, INPUT LETTER WAS CAP
				veri = true;
				temp = col_i - 65;   // TRANSLATE TO NUMBER
				round = 2;           // SWAP PLAYER
			}
			else if (round == 1 && col_i >= 97 && col_i <= 103) {     // ROUND FOR PLAYER 1, INPUT LETTER WAS LOWER
				veri = true;
				temp = col_i - 97;   // TRANSLATE TO NUMBER
				round = 2;           // SWAP PLAYER
			
			}
			else if (round == 2 && col_i >= 65 && col_i <= 71) {      // ROUND FOR PLAYER 1, INPUT LETTER WAS CAP
				veri = true;
				temp = col_i - 65;   // TRANSLATE TO NUMBER
				round = 1;           // SWAP PLAYER
			}
			else if (round == 2 && col_i >= 97 && col_i <= 103) {     // ROUND FOR PLAYER 1, INPUT LETTER WAS LOWER
				veri = true;
				temp = col_i - 97;   // TRANSLATE TO NUMBER
				round = 1;           // SWAP PLAYER
			}
			else {
				veri = false;
				printf("Invalid Entry\n");
			}
		}
		
		/*/////////// UPDATE BOARD ///////////*/
		
		switch (temp) {
			case 0:
			board[c_r.r_0][temp] = 1;
			++c_r.r_0;
			break;
			
			case 1:
			board[c_r.r_1][temp] = 1;
			++c_r.r_1;
			break;
			
			case 2:
			board[c_r.r_2][temp] = 1;
			++c_r.r_2;
			break;
			
			case 3:
			board[c_r.r_3][temp] = 1;
			++c_r.r_3;
			break;
			
			case 4:
			board[c_r.r_4][temp] = 1;
			++c_r.r_4;
			break;
			
			case 5:
			board[c_r.r_5][temp] = 1;
			++c_r.r_5;
			break;
			
			case 6:
			board[c_r.r_6][temp] = 1;
			++c_r.r_6;
			break;
		}
	}	
	
	return 0;
}


/*///////////////////////////// INITIATE THE BOARD TO A NUMBER //////////////////////////*/

void INIT_BOARD(uint BOARD[][COL], uint tr)
{
	for (int r = 0; r < ROW; ++r) {
		for (int c = 0; c < COL; ++c) {
			BOARD[r][c] = tr;
		}
	}
}


/*///////////////////////////// PRINTING THE BOARD //////////////////////*/

void PRINT_BOARD(uint BOARD[][COL]) 
{
	printf("\n");
	printf("  A   B   C   D   E   F   G\n");
	printf("|---|---|---|---|---|---|---|\n");
	
	for (int t = ROW; t >= 0; --t)
	{
		/*/////// PRINT THE CHARS //////
		1 FOR X, 2 FOR O
		*/
		for (int c = 0; c < COL; ++c) {
			if (BOARD[t][c] == 1) {
				printf("| X ");
			}
			else if (BOARD[t][c] == 0) {
				printf("| O ");
			}
			else if (BOARD[t][c] != 0 && BOARD[t][c] != 1) {
				printf("|   ");
			}
		}
		printf("|\n");
		printf("|---|---|---|---|---|---|---|\n");
	}
}


/*/////////////////////////////// CHECKING THE BOARD ///////////////////////////////*/

void BOARD_CHECK(uchar BOARD[][COL])
{
	
}
