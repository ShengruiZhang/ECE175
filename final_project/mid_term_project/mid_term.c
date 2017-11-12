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

#include <math.h>   // PRBABLY NOT NEED THIS

#define SIZE_SHIP_TYPE 21
#define SIZE_BOARD_FILE 21

typedef unsigned int uint;
typedef unsigned char uchar;

typedef struct coordinate_s {
	uint x;                           // X LOCATION IN NUMBERS
	uchar y;                          // Y LOCATION IN LETTERS
} cordnte;

typedef struct ship_s {
	uchar type[SIZE_SHIP_TYPE]; 
	uint size;
	cordnte location;                 // NEED TO BE ALLOCATED DYNAMICALLY
	cordnte location_hit;             // NEED TO BE ALLOCATED DYNAMICALLY
	struct ship_s *next;              // POINTER TO NEXT SHIP
} ship;

ship *board_configurate(ship *headptr, ship* tailptr, FILE *inp);             
// THIS FUNCTION CREATES THE LINKED LIST AT THE BEGINNING OF THE GAME

int main(void)
{
	/*//////////////////////////////////////////////
	//  GREETING INFO                             //
	//////////////////////////////////////////////*/
	
	printf("\n\t\t\t\t");
	printf("Welcome to the Battleship Game! \n");
	
	// A VISUAL ELEMENT FOR TEXT "BATTLESHIP"
	
	
	
	/*//////////////////////////////////////////////
	//  CONFIGURATING BOARD                       //
	//////////////////////////////////////////////*/
	
	// LINKED LIST DECLARATION
	ship *player_head = NULL;
	ship *player_tail = NULL;
	
	ship *ai_head = NULL;
	ship *ai_tail = NULL;
	
	ship *temp = NULL;
	
	
	// ASK FOR INPUT METHOR, TYPE MANUALLY OR FROM FILE
	
	printf("\nSelect which way to configurate the game board, configurate manually or input from an existing file. \n");
	printf("\nType \"manual\" or \"file\" to choose input method. \n");
	
	FILE *inpt;                                                            // TAKE INPUT FROM FILE OR STDIN
	
	uchar file_name[SIZE_BOARD_FILE];

	uchar input_method[10];
	
	while (fgets(input_method, 10, stdin))
	{
		if (strncmp(input_method, "manual", 6) == 0)
		{
			//printf("input manually\n");
			inpt = stdin;
			board_configurate(&player_head, &player_tail, inpt);
			break;
		}
		
		
		else if (strncmp(input_method, "file", 4) == 0)
		{
			// printf("Type the file name. \n");
			
			// fgets(file_name, SIZE_BOARD_FILE, stdin);
			// file_name[strlen(file_name) - 1] = 0;                       // GET RID OF THE NEWLINE
			
			// printf("File name: %s \n", file_name);
			
			//inpt = fopen(file_name, "r");
			inpt = fopen("1.txt", "r");
			
			board_configurate(&player_head, &player_tail, inpt);
			
			fclose(inpt);
			break;
		}
		
		
		else {
			printf("Wrong command, please type again. \n");
		}
	}

	printf("Loop broke! \n");
	
	
	
	
	
	
	

	
	
	
	return 0;
}

ship *board_configurate(ship *headptr, ship* tailptr, FILE *inp)
{
	uint num_set_to_read = 0;
	uchar test[11];
		
	if (inp != stdin)
	{
		// TAKING INPUT FROM A FILE
		
		 // READ THE NUMBER OF SETS TO BE READ
		 
		//fscanf(inp, "%d", &num_set_to_read);
		fgets(test, 11, inp);
		printf("sets: %s \n", test); // testing
	}
	
	
	
	
	
	
	
	//return;
}