/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//  ECE175 FINAL PROJECT                                                                           //
//  BATTLESHIP GAME                                                                                //
//                                                                                                 //
//  MAIN CODE                                                                                      //
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

#include "battleship.h"

int main(void)
{
	/*//////////////////////////////////////////////
	//  GREETING INFO                             //
	//////////////////////////////////////////////*/
	
	printf("\n\t\t\t");
	printf("Welcome to the Battleship Game! \n\n");
	
	// A VISUAL ELEMENT FOR TEXT "BATTLESHIP"
	game_title();
	
	/*//////////////////////////////////////////////
	//  GENERAL VARIABLE DECLARATION              //
	//////////////////////////////////////////////*/
	
	FILE *inpt = NULL;                           // SOURCE OF INPUT, STDIN OR FILE
	
	uchar command[SIZE_COMMAND];                 // COMMAND STRING FOR USER INTERACTION
	memset(command, '\0', SIZE_COMMAND);         // INITINATE STRING
	uchar file_name[SIZE_BOARD_FILE];            // THE FILE NAME FOR EXTERNAL BOARD CONFIGURATION
	memset(file_name, '\0', SIZE_BOARD_FILE);    // INITINATE STRING
//	uchar ships[SIZE_SHIP_TYPE];                 // TO STORE THE NAME OF SHIPS, ONE AT A TIME
	
	uint num_player = 0;                         // WHAT FOR TRACKING WHOSE TURN

	bool empty = false;                          // INDICATOR FOR BOARD, EMPTY FOR TRUE
	
	player p1 = { "Player 1's name", 0, 0, 0, NULL};      // DATA FOR FIRST PLAYER
	player ai = { "Computer", 0, 0, 0, NULL};             // DATA FOR AI
	
	temp_shot t_p1;
	
	// LINKED LIST DECLARATION

	ship *player1_head = (ship*)malloc(sizeof(ship));
	ship *player1_tail = (ship*)malloc(sizeof(ship));
	player1_head->next = NULL;
	player1_tail->next = NULL;

	ship *ai_head = (ship*)malloc(sizeof(ship));
	ship *ai_tail = (ship*)malloc(sizeof(ship));
	ai_head->next = NULL;
	ai_tail->next = NULL;

	ship *temp = NULL;


	/*//////////////////////////////////////////////
	//  CONFIGURATING BOARD                       //
	//////////////////////////////////////////////*/
	
	// ASK FOR INPUT METHOR, TYPE MANUALLY OR FROM FILE
	num_player = 1;                                                           // BOTH PLAYER NEEDS TO ENTER DATA
	printf("Player: Enter your name. ");
	scanf("%s", p1.name);
	getchar();
	//printf("Your name: %s \n", p1.name);
	printf("\nSelect which way to configurate the game board, configurate manually or input from an existing file. \n");

	while (1)
	{
		// DETERMINS WHOSE TURN TO INPUT
		temp = player1_head;

		printf("\n%s: Type \"manual\" or \"file\" to choose input method. \n", p1.name);
		fgets(command, SIZE_COMMAND, stdin);
		
		// INPUT MANUALLY
		if (strncmp(command, "manual", 6) == 0)
		{
			inpt = stdin;
			if (board_configurate(temp, inpt) != NULL) {                      // BOARD CONFIGURATING
				p1.list = temp;                                               // PUT THE LIST IN THE CONTAINER 
				break;
			}
			else {
				printf("Error: Null list. Code: 006 \n. ");
				break;
			}
		}
		
		// INPUT FROM A FILE
		else if (strncmp(command, "file", 4) == 0)
		{
			while (1)
			{
				printf("\nType the file name. \n");

				fgets(file_name, SIZE_BOARD_FILE, stdin);
				file_name[strlen(file_name) - 1] = 0;                         // GET RID OF THE NEWLINE

				printf("\nFile name: %s \n", file_name);                      // COMFIRE FILE NAME

				inpt = fopen(file_name, "r");
				
				if (inpt == NULL) {
					printf("Error when opening file. \n");
					memset(file_name, '\0', SIZE_BOARD_FILE);                 // CLEAR STRING
				}
				
				else 
				{
					if (board_configurate(temp, inpt) != NULL) {
						p1.list = temp;                                       // PUT THE LIST IN THE CONTAINER     
						fclose(inpt);
						break;
					}
					else {
						printf("Error: Null list. Code: 006 \n. ");
						break;
					}
				}
			}
			break;
		}
		
		// HANDLE ERROR
		else {
			printf("Wrong command, please type again. \n");
			memset(command, '\0', SIZE_COMMAND);                              // CLEAR STRING
		}
	}
	
	// GENERATE BOARD FOR AI
	inpt = fopen("2.txt", "r");
	board_configurate(ai_head, inpt);
	ai.list = ai_head;
	fclose(inpt);
	
	/*//////////////////////////////////////////////
	//  MAIN GAME LOOP                            //
	//////////////////////////////////////////////*/
	
	while (1)
	{
		grid_print(p1.list, ai.list, p1.name);                                // DISPLAY GRID
		
		printf("\n\nEnter in the location of your next shot: row number, column letter. ");
		scanf("%d %c", &t_p1.y, &(t_p1.x_c));
		
		coor_translate(&t_p1);                                                // TRANSLATE
		//printf("row: %d, column: %c\n", t_p1.y, t_p1.x_c);
		
		list_update(t_p1, p1, ai_head);                                       // CHECK FOR HIT & MISS
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}