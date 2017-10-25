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
#define INT 0

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

void INIT_C_R(CURRENT_ROW *C_R);
void INIT_BOARD(uint BOARD[][COL], uint tr);
void PRINT_BOARD(uint BOARD[][COL]);
void BOARD_CHECK(uint BOARD[][COL], uint *result);
bool COLUMN_FULL(uint BOARD[][COL], uint column);


/*///////////////////////////////// MAIN FUNCTION //////////////////////*/
int main(void)
{
	//printf("Let's play Connect Four in a Line\n\n");
	bool FULL = false;                    // IF THE COLUMN IS FULL
	bool verfy = false;                   // IF THE INPUT IS VALID
	
	uint temp = 0;
	uint round = 1;                       // ROUND VARI, DETERMINE WHOSE ROUNDM, GAME STARTS W/ PLYER 1
	uint round_temp = 1;                  // ROUND VARI TEMP
	uint symbol = 1;                      // IDENTIFY WHOSE ROUND
	uint result = 0;                      // 0 FOR NOTHING, 1 FOR TIE, 2 FOR PLAYER ONE WON, 3 FOR TWO

	uchar col_i = '\0';                   // INPUT LETTER VARI, WHERE THE PLACE IS PUT
	uchar togo = 'y';                     // IF IT IS N, QUIT THE GAME, VICE VERSA FOR Y
	
	CURRENT_ROW c_r;                      // TRACK THE CURRENT ROW
		
	/* DEF BOARD, USE NUMBER DIGIT TO REPRESENT XS AND OS, 1 FOR X, 2 FOR O*/
	uint board[ROW][COL];

	/*//////////// CONTINUE THE GAME FOR Y, QUIZ FOR N ///////////////*/
	while (togo != 'n' && togo != 'N')
	{
		/*///// RESET VALUES ////*/
		round = 1;
		result = 0;
		
		/* INITIATE EVERYTHING TO A NON 1,0 NUMBER */
		INIT_BOARD(board, INT);
		INIT_C_R(&c_r);

		printf("Let's play Connect Four in a Line\n\n");

		/*///////////// GAME STARTS, LOOPING: CONDITION: RESULT, FALSE FOR GOON, TRUE FOR BREAK THE LOOP ////////////////////*/
		while (result == 0)
		{
			/*///////// PRINTING THE BOARD ////////////////*/
			PRINT_BOARD(board);

			/*//////// TAKE AND CHECK INPUT /////////////*/
			printf("\n");

			/*///// DETERMINE WHOSE ROUND, 1 FOR PLAYER 1, 2 FOR 2 //////*/
			if (round == 1) {
				printf("Player 1: Which column would you like to add an 'X'? ");
			}
			else if (round == 2) {
				printf("Player 2: Which column would you like to add an 'O'? ");
			}

			scanf(" %c", &col_i);    // TAKE INPUT

			/*//////// CHECK THE INPUT /////////////*/
			round_temp = round;
			if (round == 1 && col_i >= 65 && col_i <= 71) {           // ROUND FOR PLAYER 1, INPUT LETTER WAS CAP
				verfy = true;
				symbol = 1;
				temp = col_i - 65;   // TRANSLATE TO NUMBER
				round = 2;           // SWAP PLAYER
			}
			else if (round == 1 && col_i >= 97 && col_i <= 103) {     // ROUND FOR PLAYER 1, INPUT LETTER WAS LOWER
				verfy = true;
				symbol = 1;
				temp = col_i - 97;   // TRANSLATE TO NUMBER
				round = 2;           // SWAP PLAYER
			}
			else if (round == 2 && col_i >= 65 && col_i <= 71) {      // ROUND FOR PLAYER 2, INPUT LETTER WAS CAP
				verfy = true;
				symbol = 2;
				temp = col_i - 65;   // TRANSLATE TO NUMBER
				round = 1;           // SWAP PLAYER
			}
			else if (round == 2 && col_i >= 97 && col_i <= 103) {     // ROUND FOR PLAYER 2, INPUT LETTER WAS LOWER
				verfy = true;
				symbol = 2;
				temp = col_i - 97;   // TRANSLATE TO NUMBER
				round = 1;           // SWAP PLAYER
			}
			else {
				verfy = false;
				printf("Invalid Entry\n");
			}			
			
			/*/////////// UPDATE BOARD ///////////*/
			FULL = COLUMN_FULL(board, temp);      // CHECK IF THE COLUMN IS FULL
			if (verfy == true && FULL == false)   // NOT FULL, VALID INPUT, THEN UPDATE THE BOARD
			{
				switch (temp)
				{
					case 0:
						board[c_r.r_0][temp] = symbol;
						++c_r.r_0;
						break;
		
					case 1:
						board[c_r.r_1][temp] = symbol;
						++c_r.r_1;
						break;
		
					case 2:
						board[c_r.r_2][temp] = symbol;
						++c_r.r_2;
						break;
		
					case 3:
						board[c_r.r_3][temp] = symbol;
						++c_r.r_3;
						break;
		
					case 4:
						board[c_r.r_4][temp] = symbol;
						++c_r.r_4;
						break;
		
					case 5:
						board[c_r.r_5][temp] = symbol;
						++c_r.r_5;
						break;
		
					case 6:
						board[c_r.r_6][temp] = symbol;
						++c_r.r_6;
						break;
				}
			}
			else if (verfy ==  true && FULL != false)               // VALID INPUT, BUT COLUMN IS FULL
			{
				round = round_temp;
				printf("That column is full\n");
			}
			
			/*///////////// CHECK THE BOARD FOR TIES OR WINS ///////////////*/
			BOARD_CHECK(board, &result);
		}
		
		/*///////////////////// TERMINATED GAME, SHOW RESULT FOR TIE WINS //////////////*/
		if (result == 1)                // TIED
		{
			PRINT_BOARD(board);
			printf("TIE GAME. You should try again\n");
		}
		else if (result == 2)           // PLAYER ONE WINS
		{
			PRINT_BOARD(board);
			printf("Player 1 is a WINNER\n");
			printf("Player 2 is a LOSER\n");
		}
		else if (result == 3)           // PLAYER TWO WINS
		{
			PRINT_BOARD(board);
			printf("Player 2 is a WINNER\n");
			printf("Player 1 is a LOSER\n");			
		}

		/*////////// ASK FOR ANOTHER GAME ///////////*/
		togo = '\0';
		while (togo != 78 && togo != 110 && togo != 89 && togo != 121)
		{
			printf("Do you want to play again (y/n)? ");
			scanf(" %c", &togo);
		}
	}
	
	printf("Goodbye\n");
	return 0;
}
/*////////////////////// END MAIN ///////////////////////////////*/


/*////////////////////////////// CHECK IF THE COLUMN IS FULL ///////////////*/
bool COLUMN_FULL(uint BOARD[][COL], uint column)
{
	bool full = false;
	if (BOARD[ROW - 1][column] != INT)
	{
		full = true;
	}
	return(full);
}


/*/////////// INITIATE THE CURRENT ROW ////////////////////*/
void INIT_C_R(CURRENT_ROW *C_R)
{
	(*C_R).r_0 = 0;                          // STARTS FROM ROW 0
	(*C_R).r_1 = 0;
	(*C_R).r_2 = 0;
	(*C_R).r_3 = 0;
	(*C_R).r_4 = 0;
	(*C_R).r_5 = 0;
	(*C_R).r_6 = 0;
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
	
	for (int t = (ROW - 1); t >= 0; --t)
	{
		/*/////// PRINT THE CHARTS // 1 FOR X, 2 FOR O  */
		for (int c = 0; c < COL; ++c) {
			if (BOARD[t][c] == 1) {
				printf("| X ");
			}
			else if (BOARD[t][c] == 2) {
				printf("| O ");
			}
			else if (BOARD[t][c] != 1 && BOARD[t][c] != 2) {
				printf("|   ");
			}
		}
		printf("|\n");
		printf("|---|---|---|---|---|---|---|\n");
	}
}


/*/////////////////////////////// CHECKING THE BOARD ///////////////////////////////*/
void BOARD_CHECK(uint BOARD[][COL], uint *result)
{
	uint r = 0;
	uint i = 0;
	bool non_full = 1;

	/*
	// DEBUGGING
	for (int i = (ROW - 1); i >= 0; --i) {
		for (int j = 0; j < COL; ++j) {
			printf("%d ", BOARD[i][j]);
		}
		printf("\n");
	}
	*/
	
	/*//////////////// HORIZONTAL ///////////*/
	for (int r = 0; r < ROW; ++r) {
		for (int i = 0; i < 4; ++i) {
			if (BOARD[r][i] == 1 && BOARD[r][i + 1] == 1 && BOARD[r][i + 2] == 1 && BOARD[r][i + 3] == 1) // ONE WINS
			{
				*result = 2;
				break;
			}
			else if (BOARD[r][i] == 2 && BOARD[r][i + 1] == 2 && BOARD[r][i + 2] == 2 && BOARD[r][i + 3] == 2) // TWO WINS
			{
				*result = 3;
				break;
			}
			else {
				//printf("Something wrong. *0001\n");        // ERROR NOTICE, FOR DEBUGGING
			}
			//printf("%d result\n", *result);
		}
		if (*result != 0) {
			break;
		}
		else {
			//printf("Something wrong. *0002\n");        // ERROR NOTICE, FOR DEBUGGING
		}
	}
	
	/*////////////////// VERTICAL //////////////*/
	if (*result != 1 && *result != 2 && *result != 3) // NO TIE, NO VERTICAL OR HORIZONTAL WIN BEFORE THIS
	{
		for (int c = 0; c < 6; ++c)
		{
			for (r = 0; r < 3; ++r) {
				if (BOARD[r][c] == 1 && BOARD[r + 1][c] == 1 && BOARD[r + 2][c] == 1 && BOARD[r + 3][c] == 1) // ONE WINS
				{
					*result = 2;
					break;
				}
				else if (BOARD[r][c] == 2 && BOARD[r + 1][c] == 2 && BOARD[r + 2][c] == 2 && BOARD[r + 3][c] == 2) // TWO WINS
				{
					*result = 3;
					break;
				}
				else {
					//printf("Something wrong. *0003\n");        // ERROR NOTICE, FOR DEBUGGING
				}
			//printf("%d result\n", *result);
			}
			if (*result != 0) {
				break;
			}
		}
	}
	else {
		//printf("Something wrong. *0004\n");        // ERROR NOTICE, FOR DEBUGGING
	}
	
	/*////////////////////// DIAGONALLY ///////////////*/
	
	if (*result != 1 && *result != 2 && *result != 3)
	{
		/* FROM LEFT TO RIGHT */
		for (r = 0; r < 6; ++r) {
			for (int c = 0; c < 7; ++c) {
				if (BOARD[r][c] == 1 && BOARD[r+1][c+1] == 1 && BOARD[r+2][c+2] == 1 && BOARD[r+3][c+3] == 1) { // PLAYER ONE
					*result = 2;
					break;
				}
				else if (BOARD[r][c] == 2 && BOARD[r+1][c+1] == 2 && BOARD[r+2][c+2] == 2 && BOARD[r+3][c+3] == 2) { // TWO WINS
					*result = 3;
					break;
				}
				else {
					//printf("Something wrong. *0007\n");        // ERROR NOTICE, FOR DEBUGGING
				}
			}
			if (*result != 0) {
				break;
			}
		}
		/* FROM RIGHT TO LEFT*/
		for (r = 0; r < 6; ++r) {
			for (int c = 6; c <= 0; --c) {
				if (BOARD[r][c] == 1 && BOARD[r+1][c-1] == 1 && BOARD[r+2][c-2] == 1 && BOARD[r+3][c-3] == 1) { // PLAYER ONE
					*result = 2;
					break;
				}
				else if (BOARD[r][c] == 2 && BOARD[r+1][c-1] == 2 && BOARD[r+2][c-2] == 2 && BOARD[r+3][c-3] == 2) { // TWO WINS
					*result = 3;
					break;
				}
				else {
					//printf("Something wrong. *0008\n");        // ERROR NOTICE, FOR DEBUGGING
				}
			}
			if (*result != 0) {
				break;
			}
		}
	}		
	
	
	/*/////////// CHECK FOR THE BOARD, IF EVERY COLUMN IS FULL AND NO ONE WINS, THEN TIE ///////////*/
	if (*result != 1 && *result != 2 && *result != 3) {
		for (i = 0; i < 6; ++i)
		{
			non_full *= COLUMN_FULL(BOARD, i);
		}
		printf("full: %d\n", non_full);    // ERROR NOTICE, FOR DEBUGGING

		if (non_full == 1) {          // AND THE ENTIRE GRID IS FULL, THEN ANNOUNCE TIE
			*result = 1;
			//printf("Something wrong. *0015\n");        // ERROR NOTICE, FOR DEBUGGING
		}
		else if (non_full == true) {          // GRID ISN'T ENTIRELY FULL
			*result = 0;           // NOTHING
			//printf("Something wrong. *0016\n");        // ERROR NOTICE, FOR DEBUGGING
		}
		else {
			//printf("Something wrong. *0005\n");        // ERROR NOTICE, FOR DEBUGGING
		}
	}
	else {
		//printf("Something wrong. *0006\n");        // ERROR NOTICE, FOR DEBUGGING
	}
}


/*///////////////// DEBUGGING ////////////////*/
	/*for (int i = (ROW - 1); i >= 0; --i) {
		for (int j = 0; j < COL; ++j) {
			printf("%d ", BOARD[i][j]);
		}
		printf("\n");
	}*/