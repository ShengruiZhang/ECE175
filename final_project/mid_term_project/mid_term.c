/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//  ECE175 Mid-term Project                                                                        //
//  Battleship Game                                                                                //
//                                                                                                 //
//  Author:             Shengrui Zhang                                                             //
//  Date Created:       11/09/17                                                                   //
//  Email:              shengruizhang@email.arizona.edu                                            //
//  Student ID:         23426900                                                                   //
//                                                                                                 //
//                                                                                                 //
//                                                                                                 //
//  AIRCRAFT CARRIER    SYM: A   SIZE: 5                                                           //
//  BATTLESHIP          SYM: B   SIZE: 4                                                           //
//  CRUISER             SYM: C   SIZE: 3                                                           //
//  SUBMARINE           SYM: S   SIZE: 3                                                           //
//  PATROL BOAT         SYM: P   SIZE: 2                                                           //
//  KAYAK               SYM: K   SIZE: 1                                                           //
//  ROW BOAT            SYM: R   SIZE: 1                                                           //
//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// STRING SIZE DEFINING
#define SIZE_SHIP_TYPE 21
#define SIZE_BOARD_FILE 21
#define SIZE_COMMAND 16

typedef unsigned int uint;
typedef unsigned char uchar;

typedef struct ship_s {
	uchar type[SIZE_SHIP_TYPE]; 
	uint size;
	
	uint *loca_x;                      // NEED TO BE ALLOCATED DYNAMICALLY
	uint *loca_y;                      // NEED TO BE ALLOCATED DYNAMICALLY
	
	uint *loca_x_hit;                  // NEED TO BE ALLOCATED DYNAMICALLY
	uint *loca_y_hit;                  // NEED TO BE ALLOCATED DYNAMICALLY
	
	struct ship_s *next;              // POINTER TO NEXT SHIP
} ship;


ship *board_configurate(ship *headptr, FILE *input);             
// THIS FUNCTION CREATES THE LINKED LIST AT THE BEGINNING OF THE GAME

uchar ship_translate(uint code);
// THIS FUNCTION TRANSLATE THE SHIP TYPE CODE TO ONE-CHAR SYMBOL

uint ship_code_translate(uchar symbol[]);
// THIS FUNCTION TRANSLATE THE SHIP SYMBOL TO NUMBER CODE

void grid_print(ship *headptr_1, ship *headptr_2);
// THIS FUNCTION PRINTS THE GAME BOARD



int main(void)
{
	/*//////////////////////////////////////////////
	//  GREETING INFO                             //
	//////////////////////////////////////////////*/
	
	printf("\n\t\t\t");
	printf("Welcome to the Battleship Game! \n");
	
	// A VISUAL ELEMENT FOR TEXT "BATTLESHIP"
	
	
	/*//////////////////////////////////////////////
	//  GENERAL VARIABLE DECLARATION              //
	//////////////////////////////////////////////*/
	
	FILE *inpt = NULL;                           // SOURCE OF INPUT, STDIN OR FILE
	
	uchar command[SIZE_COMMAND];                 // COMMAND STRING FOR USER INTERACTION
	uchar file_name[SIZE_BOARD_FILE];            // THE FILE NAME FOR EXTERNAL BOARD CONFIGURATION
	
	uint num_player = 0;                         // WHAT FOR TRACKING WHOSE TURN
	
	
	// LINKED LIST DECLARATION

	ship *player1_head = (ship*)malloc(sizeof(ship));
	ship *player1_tail = (ship*)malloc(sizeof(ship));
	player1_head->next = NULL;
	player1_tail->next = NULL;

	ship *player2_head = (ship*)malloc(sizeof(ship));
	ship *player2_tail = (ship*)malloc(sizeof(ship));
	player2_head->next = NULL;
	player2_tail->next = NULL;

	ship *temp = NULL;

	

	/*//////////////////////////////////////////////
	//  CONFIGURATING BOARD                       //
	//////////////////////////////////////////////*/
	
	// ASK FOR INPUT METHOR, TYPE MANUALLY OR FROM FILE
	
	num_player = 1;
	printf("\nSelect which way to configurate the game board, configurate manually or input from an existing file. \n");

	while (1)
	{
		temp = player1_head;
		if (num_player > 2) {
			temp = player2_head;
		}
		
		printf("Player %d: \nType \"manual\" or \"file\" to choose input method. \n", num_player);
		// fgets(command, SIZE_COMMAND, stdin);                      // TESTING SAKE
		strcpy(command, "file");                                     // TESTING
		
		if (strncmp(command, "manual", 6) == 0)
		{
			inpt = stdin;
			if (board_configurate(temp, inpt) != NULL) {  // BOARD CONFIGURATING
				++num_player;
				break;
			}
			else {
				printf("Error: Null list. Code: 006 \n. ");
				break;
			}
		}
		
		else if (strncmp(command, "file", 4) == 0)
		{
			while (1)
			{
				/*         // TESTING SAKE
				printf("\nType the file name. \n");

				fgets(file_name, SIZE_BOARD_FILE, stdin);
				file_name[strlen(file_name) - 1] = 0;                         // GET RID OF THE NEWLINE

				printf("\nFile name: %s \n", file_name);                      // COMFIRE FILE NAME

				inpt = fopen(file_name, "r");
				*/

				inpt = fopen("1.txt", "r");                                 // FOR TESTING SAKE
				if (inpt == NULL) {
					printf("Error when opening file. \n");
				}
				else {
					if (board_configurate(temp, inpt) != NULL) {
						fclose(inpt);
						++num_player;
						break;
					}
					else {
						printf("Error: Null list. Code: 006 \n. ");
						break;
					}
				}
			}
			if (num_player > 2)
			break;
		}
		
		else {
			printf("Wrong command, please type again. \n");
		}
	}
	
	
	
	/*//////////////////////////////////////////////
	//  MAIN GAME LOOP                            //
	//////////////////////////////////////////////*/
	
	// PRINTING THE BOARD
	grid_print(player1_head, player2_head);
	
	printf("\nLoop broke! \n");
	return 0;
}



ship *board_configurate(ship *headptr, FILE *input)
{
	uint num_set_to_read = 0;
	uint sets_read = 0;
	
	uint i = 0;
	uint j = 0;
	
	uchar str[15];                                                    // TEMP CHAR STRING
	uchar str_command[SIZE_COMMAND];                                  // STR FOR COMMAND
	memset(str, ' ', sizeof(str));
	memset(str_command, ' ', sizeof(str_command));
	
	ship *temp = NULL;
	ship *newest = (ship*)malloc(sizeof(ship));;
	
	if (input != stdin)
	{
		// TAKING INPUT FROM A FILE
		
		// READ THE NUMBER OF SETS TO BE READ
		
		fscanf(input, "%d\n", &num_set_to_read);
		printf("\nNumber of preset to read: %d \n", num_set_to_read);
		sets_read = 0;
	}
	
	
	else if (input == stdin)                                         // INPUT FROM STDIN
	{
		printf("\nConfigurate the board manually. \n");
		num_set_to_read = 0;                                         // SO THAT IT STEPS INTO THE LOOP
		strncpy(str_command, "add", 3);
	}
	
	else {
		printf("\nError occured. Code: 001 \n");                     // ERROR NOTICE
	}
	
	
	
	// LOOP FOR TAKING INPUT
	while (sets_read < num_set_to_read || strncmp(str_command, "add", 3) == 0)
	{
		memset(str_command, ' ', sizeof(str_command));
		temp = (ship*)malloc(sizeof(ship));
		
		if (input == stdin) {
			printf("\nEnter the type of the ship.\n");
		}
		
		fgets(temp->type, SIZE_SHIP_TYPE, input);                    // THE NEWLINE IS INCLUDED IN STRING
		temp->type[strlen(temp->type) - 1] = 0;                      // DELETE NEWLINE
		printf("Ship type: %s", temp->type);
		if (input != stdin) printf("\n");
		
		

		GET_SIZE:
		if (input == stdin) {
			printf("\n\nEnter the size of the ship. \n");
		}
		
		fgets(str, 5, input);
		sscanf(str, "%d", &temp->size);
		if (temp->size > 5) {
			printf("Invalid size. Code: 002");
			goto GET_SIZE;
		}
		printf("Ship size: %d\n", temp->size);
		
		
		
		temp = (ship*)realloc(temp, sizeof(ship) + 4 * temp->size *sizeof(uint));

		temp->loca_x = (uint*)malloc(temp->size * sizeof(uint));        // ALLOCATES FOR LOCATION
		temp->loca_y = (uint*)malloc(temp->size * sizeof(uint));        // ALLOCATES FOR LOCATION
		temp->loca_x_hit = (uint*)malloc(temp->size * sizeof(uint));    // ALLOCATES FOR LOCATION
		temp->loca_y_hit = (uint*)malloc(temp->size * sizeof(uint));    // ALLOCATES FOR LOCATION
		
		

		LOCATION_X:
		if (input == stdin) {
			printf("\nEnter the x location of the ship separated by space. \n");
		}
		
		// HANDLING BOTH LOWER AND UPPER LETTERS
		j = 0;
		fgets(str, 2 * temp->size + 1, input);                              // GET LOCATION AT ONCE
		
		for (i = 0; i < temp->size; ++i)
		{
			if (str[j] >= 65 && str[j] <= 74)
			{
				temp->loca_x[i] = str[j] - 64;
			}
			
			else if (str[j] >= 97 && str[j] <= 106)
			{
				temp->loca_x[i] = str[j] - 96;
			}
			
			else                                                            // HANDLE WRONG INPUT
			{
				printf("Invalid input, enter again. Code: 003\n");

				// RESET
				j = 0;
				for (uint a = 0; a < (temp->size); ++a) {
					temp->loca_x[a] = 0;
				}
				goto LOCATION_X;
			}
			printf("x location: %d\n", temp->loca_x[i]);
			j += 2;
		}
		
		printf("\n");
		


		LOCATION_Y:
		if (input == stdin) {
			printf("\nEnter the y location of the ship separated by space. \n");
		}
		
		// INPUT PROTECTION, ASSUME IN CORRECT FORMAT BUT WRONG NUMBER\LETTER
		j = 0;
		fgets(str, 15, input);
		for (i = 0; i < temp->size; ++i)
		{
			sscanf(str, "%d", &temp->loca_y[i]);
			if (temp->loca_y[i] <= 0 || temp->loca_y[i] > 10) {
				printf("Invalid input, enter again. Code: 004 \n");
				goto LOCATION_Y;
			}
			str[j] = ' ';
			if (temp->loca_y[i] == 10) {                       // HANDLE 10 DIFFERENTLY
				str[j + 1] = ' ';
				j += 1;
			}
			j += 2;
			printf("y location: %d\n", temp->loca_y[i]);
		}	

		printf("\n");
		

		// LINKS THE CURRENT CELL TO THE LIST
		if (headptr->next == NULL)
		{
			headptr->next = temp;                              // CONNECTS THE NEW CELL
			headptr->next->next = NULL;
			newest = temp;
		}
		else if (headptr->next != NULL)
		{
			newest->next = temp;
			newest->next->next = NULL;
			newest = temp;
		}
		
		if (input == stdin) {
			printf("Type \"add\" to add another ship or \"end\" to start the game. \n");
			while (fgets(str_command, SIZE_COMMAND, stdin)) {
				if (strncmp(str_command, "add", 3) == 0 || strncmp(str_command, "end", 3) == 0) {
					break;
				}
				else {
					printf("Invalid input, enter again. Code: 005 \n");
					memset(str_command, ' ', sizeof(str_command));
				}
			}
		}
		else {
			++sets_read;
		}
	}
	
	return newest;
}



uchar ship_translate(uint code)
{
	uchar ship_sym = ' ';
	
	switch (code)
	{
		case 0:
			ship_sym = ' ';
			break;
			
		case 1:
			ship_sym = 'A';
			break;
		
		case 2:
			ship_sym = 'B';
			break;
			
		case 3:
			ship_sym = 'C';
			break;
			
		case 4:
			ship_sym = 'S';
			break;
			
		case 5:
			ship_sym = 'P';
			break;
			
		case 6:
			ship_sym = 'K';
			break;
			
		case 7:
			ship_sym = 'R';
			break;
		
		default:
			printf("Error occured. Code: 201 \n");
	}
	return ship_sym;
}



uint ship_code_translate(uchar symbol[])
{
	uint num_code = 0;
	if (strcmp(symbol, "AircraftCarrier") == 0 || strcmp(symbol, "aircraftcarrier") == 0)
	{
		num_code = 1;
	}
	else if (strcmp(symbol, "Battleship") == 0 || strcmp(symbol, "battleship") == 0)
	{
		num_code = 2;
	}
	else if (strcmp(symbol, "Cruiser") == 0 || strcmp(symbol, "cruiser") == 0)
	{
		num_code = 3;
	}
	else if (strcmp(symbol, "Submarine") == 0 || strcmp(symbol, "submarine") == 0)
	{
		num_code = 4;
	}
	else if (strcmp(symbol, "PatrolBoat") == 0 || strcmp(symbol, "patrolboat") == 0)
	{
		num_code = 5;
	}
	else if (strcmp(symbol, "Kayak") == 0 || strcmp(symbol, "kayak") == 0)
	{
		num_code = 6;
	}
	else if (strcmp(symbol, "RowBoat") == 0 || strcmp(symbol, "rowboat") == 0)
	{
		num_code = 7;
	}
	else {
		printf("Error occured. Code: 301 \n");
		num_code = 0;
	}
	return num_code;
}



void grid_print(ship *headptr_1, ship *headptr_2)
{
	const uint ROW = 10;
	const uint COL = 10;

	uint r = 0; // FOR ROW Y LOCATION
	uint c = 0; // FOR COL X LOCATION

	uint index_array = 0;
	uint ship_type = 0;

	uchar ship_code = ' ';
	uchar num_row[4];
	memset(num_row, ' ', sizeof(num_row));

	ship *temp = NULL;

	uint grid_1[10][10]; // PLAYER 1
	uint grid_2[10][10]; // PLAYER 2

	// INITIATE THE ARRAY
	for (c = 0; c < COL; ++c)
	{
		for (r = 0; r < ROW; ++r)
		{
			grid_1[c][r] = 0;
			grid_2[c][r] = 0;
		}
	}
		
	
	// UPDATE THE GRID BASED ON THE SHIP TYPE
	temp = headptr_1->next;
	while (temp != NULL)
	{
		ship_type = ship_code_translate(temp->type);
		for (index_array = 0; index_array < temp->size; ++index_array)
		{
			//printf("debug: x: %d, y: %d\n", temp->loca_x[index_array], temp->loca_y[index_array]);
			grid_1[temp->loca_x[index_array] - 1][temp->loca_y[index_array] - 1] = ship_type;
		}
		temp = temp->next;
	}
	
	temp = headptr_2->next;
	while (temp != NULL)
	{
		for (index_array = 0; index_array < temp->size; ++index_array)
		{
			grid_2[temp->loca_x[index_array] - 1][temp->loca_y[index_array] - 1] = ship_type;
		}
		temp = temp->next;
	}
	

	// START PRINTING

	system("CLS");
	printf("\n\n");

	printf("                               Player 1");
	printf("                                                         Player 2\n\n");


	printf("     ");                                                              // 5 SPACES
	printf("   A     B     C     D     E     F     G     H     I     J");
	printf("             ");                                                      // 14 SPACES
	printf("     A   B   C   D   E   F   G   H   I   J\n");

	printf("     ");                                                              // 5 SPACES
	printf("-------------------------------------------------------------");
	printf("              ");                                                     // 15 SPACES
	printf("-----------------------------------------\n");



	// START PRINTING THE BOARD
	
	for (r = 0; r < ROW; ++r)
	{
		printf("     ");                                                          // 5 SPACES
		printf("|     |     |     |     |     |     |     |     |     |     |");

		snprintf(num_row, 3, "%d", r + 1);
		if ((r + 1) < 10)
			strncat(num_row, " ", 1);
		printf("          %s  ", num_row);                                        // SM BOARD 14 SPACES, NUM ON THIRD FROM RIGHT
		for (c = 0; c < COL; ++c)
		{
			//printf("debug2: %d\n", grid_1[r][c]);
			ship_code = ship_translate(grid_2[r][c]);
			printf("| %c ", ship_code);
		}
		printf("|\n");

		printf(" %s  ", num_row);                                                 // LG BOARD 5 SPACES, NUM ON SECOND FROM RIGHT
		for (c = 0; c < COL; ++c)
		{
			ship_code = ship_translate(grid_1[r][c]);
			printf("|  %c  ", ship_code);
		}
		printf("|");
		printf("              ");                                                 // 15 SPACES
		printf("-----------------------------------------\n");
	}
	









	/*
	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |");
	printf("          1  ");                                                      // SM BOARD 14 SPACES, NUM ON THIRD FROM RIGHT
	printf("|   |   |   |   |   |   |   |   |   |   |\n");

	printf("   1 ");                                                              // LG BOARD 5 SPACES, NUM ON SECOND FROM RIGHT
	printf("|     |     |     |     |     |     |     |     |     |     |");
	printf("             ");                                                      // 14 SPACES
	printf("-----------------------------------------\n");

	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |");
	printf("          2  ");                                                      // SM BOARD 14 SPACES, NUM ON THIRD FROM RIGHT
	printf("|   |   |   |   |   |   |   |   |   |   |\n");

	printf("     ");                                                              // 5 SPACES
	printf("-------------------------------------------------------------");
	printf("             ");                                                      // 14 SPACES
	printf("-----------------------------------------\n");

	//
	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |");
	printf("          3  ");                                                      // SM BOARD 14 SPACES, NUM ON THIRD FROM RIGHT
	printf("|   |   |   |   |   |   |   |   |   |   |\n");

	printf("   2 ");                                                              // LG BOARD 5 SPACES, NUM ON SECOND FROM RIGHT
	printf("|     |     |     |     |     |     |     |     |     |     |");
	printf("             ");                                                      // 14 SPACES
	printf("-----------------------------------------\n");

	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |");
	printf("          4  ");                                                      // SM BOARD 14 SPACES, NUM ON THIRD FROM RIGHT
	printf("|   |   |   |   |   |   |   |   |   |   |\n");

	printf("     ");                                                              // 5 SPACES
	printf("-------------------------------------------------------------");
	printf("             ");                                                      // 14 SPACES
	printf("-----------------------------------------\n");

	//
	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |");
	printf("          5  ");                                                      // SM BOARD 14 SPACES, NUM ON THIRD FROM RIGHT
	printf("|   |   |   |   |   |   |   |   |   |   |\n");

	printf("   3 ");                                                              // LG BOARD 5 SPACES, NUM ON SECOND FROM RIGHT
	printf("|     |     |     |     |     |     |     |     |     |     |");
	printf("             ");                                                      // 14 SPACES
	printf("-----------------------------------------\n");

	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |");
	printf("          6  ");                                                      // SM BOARD 14 SPACES, NUM ON THIRD FROM RIGHT
	printf("|   |   |   |   |   |   |   |   |   |   |\n");

	printf("     ");                                                              // 5 SPACES
	printf("-------------------------------------------------------------");
	printf("             ");                                                      // 14 SPACES
	printf("-----------------------------------------\n");

	//
	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |");
	printf("          7  ");                                                      // SM BOARD 14 SPACES, NUM ON THIRD FROM RIGHT
	printf("|   |   |   |   |   |   |   |   |   |   |\n");

	printf("   4 ");                                                              // LG BOARD 5 SPACES, NUM ON SECOND FROM RIGHT
	printf("|     |     |     |     |     |     |     |     |     |     |");
	printf("             ");                                                      // 14 SPACES
	printf("-----------------------------------------\n");

	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |");
	printf("          8  ");                                                      // SM BOARD 14 SPACES, NUM ON THIRD FROM RIGHT
	printf("|   |   |   |   |   |   |   |   |   |   |\n");

	printf("     ");                                                              // 5 SPACES
	printf("-------------------------------------------------------------");
	printf("             ");                                                      // 14 SPACES
	printf("-----------------------------------------\n");

	//
	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |");
	printf("          9  ");                                                      // SM BOARD 14 SPACES, NUM ON THIRD FROM RIGHT
	printf("|   |   |   |   |   |   |   |   |   |   |\n");

	printf("   5 ");                                                              // LG BOARD 5 SPACES, NUM ON SECOND FROM RIGHT
	printf("|     |     |     |     |     |     |     |     |     |     |");
	printf("             ");                                                      // 14 SPACES
	printf("-----------------------------------------\n");

	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |");
	printf("         10  ");                                                      // SM BOARD 14 SPACES, NUM ON THIRD FROM RIGHT
	printf("|   |   |   |   |   |   |   |   |   |   |\n");

	printf("     ");                                                              // 5 SPACES
	printf("-------------------------------------------------------------");
	printf("             ");                                                      // 14 SPACES
	printf("-----------------------------------------\n");

	// SM BOARD FINISHED, ONLY DEAL WITH THE LG BOARD
	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |\n");
	printf("   6 ");                                                              // LG BOARD 5 SPACES, NUM ON SECOND FROM RIGHT
	printf("|     |     |     |     |     |     |     |     |     |     |\n");
	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |\n");
	printf("     ");                                                              // 5 SPACES
	printf("-------------------------------------------------------------\n");

	//
	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |\n");
	printf("   7 ");                                                              // LG BOARD 5 SPACES, NUM ON SECOND FROM RIGHT
	printf("|     |     |     |     |     |     |     |     |     |     |\n");
	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |\n");
	printf("     ");                                                              // 5 SPACES
	printf("-------------------------------------------------------------\n");

	//
	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |\n");
	printf("   8 ");                                                              // LG BOARD 5 SPACES, NUM ON SECOND FROM RIGHT
	printf("|     |     |     |     |     |     |     |     |     |     |\n");
	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |\n");
	printf("     ");                                                              // 5 SPACES
	printf("-------------------------------------------------------------\n");

	//
	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |\n");
	printf("   9 ");                                                              // LG BOARD 5 SPACES, NUM ON SECOND FROM RIGHT
	printf("|     |     |     |     |     |     |     |     |     |     |\n");
	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |\n");
	printf("     ");                                                              // 5 SPACES
	printf("-------------------------------------------------------------\n");

	//
	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |\n");
	printf("  10 ");                                                              // LG BOARD 5 SPACES, NUM ON SECOND FROM RIGHT
	printf("|     |     |     |     |     |     |     |     |     |     |\n");
	printf("     ");                                                              // 5 SPACES
	printf("|     |     |     |     |     |     |     |     |     |     |\n");
	printf("     ");                                                              // 5 SPACES
	printf("-------------------------------------------------------------\n");
	*/
}