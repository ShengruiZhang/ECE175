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

typedef struct ship_s {
	uchar type[SIZE_SHIP_TYPE]; 
	uint size;
	
	uint *loca_x;                      // NEED TO BE ALLOCATED DYNAMICALLY
	uint *loca_y;                      // NEED TO BE ALLOCATED DYNAMICALLY
	
	uint *loca_x_hit;                  // NEED TO BE ALLOCATED DYNAMICALLY
	uint *loca_y_hit;                  // NEED TO BE ALLOCATED DYNAMICALLY
	
	struct ship_s *next;              // POINTER TO NEXT SHIP
} ship;

ship *board_configurate(ship *headptr, ship* tailptr, FILE *input);             
// THIS FUNCTION CREATES THE LINKED LIST AT THE BEGINNING OF THE GAME

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
	
	FILE *inpt = NULL;                                  // SOURCE OF INPUT, STDIN OR FILE
	
	uchar command[SIZE_COMMAND];                 // COMMAND STRING FOR USER INTERACTION
	uchar file_name[SIZE_BOARD_FILE];            // THE FILE NAME FOR EXTERNAL BOARD CONFIGURATION
	
	// LINKED LIST DECLARATION

	ship *player_head = (ship*)malloc(sizeof(ship));
	ship *player_tail = (ship*)malloc(sizeof(ship));
	player_head->next = NULL;
	player_tail->next = NULL;

	ship *ai_head = NULL;
	ship *ai_tail = NULL;

	ship *temp = NULL;
	
	

	/*//////////////////////////////////////////////
	//  CONFIGURATING BOARD                       //
	//////////////////////////////////////////////*/
	
	// ASK FOR INPUT METHOR, TYPE MANUALLY OR FROM FILE
	
	printf("\nSelect which way to configurate the game board, configurate manually or input from an existing file. \n");
	printf("\nType \"manual\" or \"file\" to choose input method. \n");
	
	while (fgets(command, 10, stdin))
	{
		if (strncmp(command, "manual", 6) == 0)
		{
			inpt = stdin;
			board_configurate(player_head, player_tail, inpt);
			break;
		}
		
		else if (strncmp(command, "file", 4) == 0)
		{
			while (1)
			{
				printf("\nType the file name. \n");

				fgets(file_name, SIZE_BOARD_FILE, stdin);
				file_name[strlen(file_name) - 1] = 0;                         // GET RID OF THE NEWLINE

				printf("\nFile name: %s \n", file_name);                      // COMFIRE FILE NAME

				inpt = fopen(file_name, "r");

				//inpt = fopen("1.txt", "r");                                 // FOR TESTING SAKE
				if (inpt == NULL) {
					printf("Error when opening file. \n");
				}
				else {
					board_configurate(player_head, player_tail, inpt);        // BOARD CONFIGURATING
					fclose(inpt);
					break;
				}
			}
			break;
		}
		
		
		else {
			printf("Wrong command, please type again. \n");
		}
	}



	ship *current;
	current = player_head;
	system("CLS");
	printf("test:\n");
	printf("%s %d\n%d\n%d\n",
		current->next->type,
		current->next->size,
		current->next->loca_x[0],
		current->next->loca_y[0]);

	current = current->next;
	printf("%s %d\n%d\n%d\n",
		current->next->type,
		current->next->size,
		current->next->loca_x[0],
		current->next->loca_y[0]);

	current = current->next;
	printf("%s %d\n%d\n%d\n",
		current->next->type,
		current->next->size,
		current->next->loca_x[0],
		current->next->loca_y[0]);

	current = current->next;
	printf("%s %d\n%d\n%d\n",
		current->next->type,
		current->next->size,
		current->next->loca_x[0],
		current->next->loca_y[0]);

	current = current->next;
	printf("%s %d\n%d\n%d\n",
		current->next->type,
		current->next->size,
		current->next->loca_x[0],
		current->next->loca_y[0]);

	printf("Loop broke! \n");
	
	
	
	
	
	
	

	
	
	
	return 0;
}

ship *board_configurate(ship *headptr, ship* tailptr, FILE *input)
{
	uint num_set_to_read = 0;
	uint sets_read = 0;
	
	uint i = 0;
	uint j = 0;
	
	uchar str[15];                                                    // TEMP CHAR STRING
	
	ship *temp = NULL;
	ship *newest = (ship*)malloc(sizeof(ship));;
	
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
	//num_set_to_read = 1;
	for (sets_read = 0; sets_read < num_set_to_read; ++sets_read)
	{
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
			if (temp->loca_y[i] == 10) {
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
			headptr->next->next = tailptr;
			newest = temp;
		}
		else if (headptr->next != NULL)
		{
			newest->next = temp;
			newest->next->next = tailptr;
			newest = temp;
		}
	}
	
	
	//return;
}