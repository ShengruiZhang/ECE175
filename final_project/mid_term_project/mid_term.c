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

// STRING SIZE DEFINING
#define SIZE_SHIP_TYPE 21
#define SIZE_BOARD_FILE 21
#define SIZE_COMMAND 16

typedef unsigned int uint;
typedef unsigned char uchar;

/*
typedef struct coordinate_s {
	uint x;                           // X LOCATION IN NUMBERS
	uchar y;                          // Y LOCATION IN LETTERS
} cordnte;
*/

typedef struct ship_s {
	uchar type[SIZE_SHIP_TYPE]; 
	uint size;
	uint *loca_x;                      // NEED TO BE ALLOCATED DYNAMICALLY
	uint *loca_y;                      // NEED TO BE ALLOCATED DYNAMICALLY
	uint *loca_x_hit;                  // NEED TO BE ALLOCATED DYNAMICALLY
	uint *loca_y_hit;                  // NEED TO BE ALLOCATED DYNAMICALLY
	//cordnte location;               // NEED TO BE ALLOCATED DYNAMICALLY
	//cordnte location_hit;           // INDICATE WHICH PART OF THE SHIP IS GOT HIT, NEED TO BE ALLOCATED DYNAMICALLY
	struct ship_s *next;              // POINTER TO NEXT SHIP
} ship;

ship *board_configurate(ship *headptr, ship* tailptr, FILE *input);             
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
	//  GENERAL VARIABLE DECLARATION              //
	//////////////////////////////////////////////*/
	
	FILE *inpt;                                  // SOURCE OF INPUT, STDIN OR FILE
	
	uchar command[SIZE_COMMAND];                 // COMMAND STRING FOR USER INTERACTION
	uchar file_name[SIZE_BOARD_FILE];            // THE FILE NAME FOR EXTERNAL BOARD CONFIGURATION
	
	
	
	
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
	
	while (fgets(command, 10, stdin))
	{
		if (strncmp(command, "manual", 6) == 0)
		{
			inpt = stdin;
			board_configurate(&player_head, &player_tail, inpt);
			break;
		}
		
		
		else if (strncmp(command, "file", 4) == 0)
		{
			/*                                                            // FOR TESTING SAKE
			printf("\nType the file name. \n");
			
			fgets(file_name, SIZE_BOARD_FILE, stdin);
			file_name[strlen(file_name) - 1] = 0;                         // GET RID OF THE NEWLINE
			
			printf("\nFile name: %s \n", file_name);                      // COMFIRE FILE NAME
			
			inpt = fopen(file_name, "r");
			*/
			inpt = fopen("1.txt", "r");                                 // FOR TESTING SAKE
			board_configurate(&player_head, &player_tail, inpt);          // BOARD CONFIGURATING	
			
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

ship *board_configurate(ship *headptr, ship* tailptr, FILE *input)
{
	uint num_set_to_read = 0;
	uint sets_read = 0;
	uint i = 0;
	
	ship *temp = (ship*)malloc(sizeof(ship));
	
	if (input != stdin)
	{
		// TAKING INPUT FROM A FILE
		
		// READ THE NUMBER OF SETS TO BE READ
		
		fscanf(input, "%d\n", &num_set_to_read);
		printf("\nNumber of preset to read: %d \n", num_set_to_read);
	}
	
	
	else if (input == stdin)                                         // INPUT FROM STDIN
	{
		printf("\nConfigurate the board manually. \n");
		num_set_to_read = 999;                                       // SO THAT IT STEPS INTO THE LOOP
	}
	
	else {
		printf("\nError occured. Code: 001 \n");                     // ERROR NOTICE
	}
	
	
	
	// LOOP FOR TAKING INPUT
	
	for (sets_read = 0; sets_read < num_set_to_read; ++sets_read)
	{
		if (input == stdin) {
			printf("\nEnter the type of the ship. \n");
		}
		
		fgets(temp->type, SIZE_SHIP_TYPE, input);                    // THE NEWLINE IS INCLUDED IN STRING
		printf("\nShip type: %s", temp->type);
		
		
		
		if (input == stdin) {
			printf("\nEnter the size of the ship. \n");
		}
		
		fscanf(input, "%d", &temp->size);
		printf("\nShip size: %d\n", temp->size);
		
		temp = (ship*)realloc(temp, sizeof(ship) + 4 * temp->size *sizeof(uint));

		temp->loca_x = (uint*)malloc(temp->size * sizeof(uint));        // ALLOCATES FOR LOCATION
		temp->loca_y = (uint*)malloc(temp->size * sizeof(uint));        // ALLOCATES FOR LOCATION
		temp->loca_x_hit = (uint*)malloc(temp->size * sizeof(uint));    // ALLOCATES FOR LOCATION
		temp->loca_y_hit = (uint*)malloc(temp->size * sizeof(uint));    // ALLOCATES FOR LOCATION

		//temp = (ship*)realloc(temp, sizeof(ship));
		
		if (input == stdin) {
			printf("\nEnter the y location of the ship. \n");
		}
		
		for (i = 0; i < temp->size; ++i)
		{
			fscanf(input, "%d", &temp->loca_y[i]);
			printf("y location: %d\n", temp->loca_y[i]);
		}
		//fscanf(input, "%d %d %d", &temp->size);
		//printf("\nShip type: %s \n", temp->type);
		
		
		/*
		if (input == stdin) {
			printf("\nEnter the type of the ship. \n");
		}
		
		fgets(temp->type, SIZE_SHIP_TYPE, input);
		printf("\nShip type: %s \n", temp->type);
		*/
	}
	
	
	//return;
}