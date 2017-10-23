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

/*/////////////////////////////INITIATE THE BOARD TO A NUMBER//////////////////////////*/

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
	printf("  A   B   C   D   E   F   G\n");
	printf("|---|---|---|---|---|---|---|\n");
	
	for (int t = 0; t < (COL - 1); ++t)
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





/*///////////////////////////////// MAIN FUNCTION //////////////////////*/

int main(void) 
{
	printf("Let's play Connect Four in a Line\n\n");
	
	bool status = false;                                // MAIN LOOP CONDITIONAL VARI
	
	/* DEF BOARD, USE NUMBER DIGIT TO REPRESENT XS AND OS, 1 FOR X, 2 FOR O*/
	uint board[6][7];
	
	/*INITIATE EVERYTHING TO A NON 1,0 NUMBER*/
	INIT_BOARD(board, INT);
	
	/*///////// PRINTING THE BOARD ////////////////*/
	PRINT_BOARD(board);
	
	
	
	
	
	
	
	
	
	return 0;
}