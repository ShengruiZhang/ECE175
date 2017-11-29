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
	//  VARIABLE DECLARATION                      //
	//////////////////////////////////////////////*/
	
	FILE *inpt = NULL;                           // SOURCE OF INPUT, STDIN OR FILE
	
	uchar command[SIZE_COMMAND];                 // COMMAND STRING FOR USER INTERACTION
	memset(command, '\0', SIZE_COMMAND);         // INITINATE STRING
	uchar file_name[SIZE_BOARD_FILE];            // THE FILE NAME FOR EXTERNAL BOARD CONFIGURATION
	memset(file_name, '\0', SIZE_BOARD_FILE);    // INITINATE STRING
//	uchar ships[SIZE_SHIP_TYPE];                 // TO STORE THE NAME OF SHIPS, ONE AT A TIME
	
	uint num_player = 0;                         // WHAT FOR TRACKING WHOSE TURN, 0 FOR AI, 1 FOR HUMAN
	
	uint ship_temp = 0;                          // FOR TEMPORARY PROCESS
	
	uint game_end = 0;                           // INDICATE THE END OF THE GAME

	bool empty = false;                          // INDICATOR FOR BOARD, EMPTY FOR TRUE
	
	player p1 = { "Player 1's name", 0, 0, 0, {0}, {0}, NULL};     // DATA FOR FIRST PLAYER
	player ai = { "Computer", 0, 0, 0, {0}, {0}, NULL};            // DATA FOR AI
	
	for (uint b = 0; b < 10; ++b)
	{
		for (uint c = 0; c < 10; ++c)
		{
			p1.map[b][c] = 3;
			ai.map[b][c] = 3;
			p1.map_0[b][c] = 0;
			ai.map_0[b][c] = 0;
		}
	}

	temp_shot t_p1;
	temp_shot t_ai;
	t_ai.y = 0;
	t_ai.x = 0;
	t_ai.x_c = 0;
	
	//////////////////////////////////////
	// LINKED LIST DECLARATION

	ship *player1_head = malloc(sizeof(ship));
	ship *ai_head = malloc(sizeof(ship));

	player1_head->next = NULL;
	ai_head->next = NULL;

	ship *temp = NULL;


	/*//////////////////////////////////////////////
	//  CONFIGURATING BOARD                       //
	//////////////////////////////////////////////*/
	
	// ASK FOR INPUT METHOR, TYPE MANUALLY OR FROM FILE
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
		//if (strcmp(command, "manual\n") == 0)
		if (strncmp(command, "manual", 6) == 0)
		{
			inpt = stdin;
			if (board_configurate(temp, inpt, 0) != NULL) {                   // BOARD CONFIGURATING
				p1.list = temp;                                               // PUT THE LIST IN THE CONTAINER 
				break;
			}
			else {
				printf("Error: Null list. Code: 006 \n. ");
				break;
			}
		}
		
		// INPUT FROM A FILE
		//else if (strcmp(command, "file\n") == 0)
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
					if (board_configurate(temp, inpt, 0) != NULL) {
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
	board_configurate(ai_head, inpt, 1);
	ai.list = ai_head;
	fclose(inpt);
	
	// COPY SHIPS LOCATIONS TO MAP_0
	array_config(p1.map_0, p1.list);
	array_config(ai.map_0, ai.list);


	/*//////////////////////////////////////////////
	//  MAIN GAME LOOP                            //
	//////////////////////////////////////////////*/
	srand((unsigned int)time(NULL));
	num_player = 1;
	while (1)
	{
		system("CLS");

		grid_print(p1, ai, game_end);                                       // DISPLAY GRID

		/////////////////////////////////////////
		// INTERRUPT THE GAME IF COMPUTER'S SHIPS ARE ALL SUNKEN
		if (ai.list->next == NULL)
		{
			printf("\n\n%s won the game!\n", p1.name);
			game_end = 1;
			break;
		}
		else if (p1.list->next == NULL)
		{
			printf("\n\nComputer won the game!\n");
			game_end = 1;
			break;
		}
		
		/////////////////////////////////////////
		// AI AND HUMAN TAKE TURN
		if (num_player == 1)
		{
			// HUMAN'S ROUND
			
			// FOR TESTING
			/*temp = ai.list->next;
			while (temp != NULL)
			{
				for (uint i = 0; i < temp->size; ++i)
				{
					printf("\nHit: x: %d, y: %d", temp->loca_x_hit[i], temp->loca_y_hit[i]);
				}
				temp = temp->next;
			}*/
			
			LOCA_INPT:
			printf("\n\n%s: Enter in the location of your next shot: row number, column letter. ", p1.name);
			scanf("%d %c", &t_p1.y, &(t_p1.x_c));
			
			if (coor_translate(&t_p1) == 0)                                   // TRANSLATE AND CHECK INPUTS
			{
				goto LOCA_INPT;
			}
			//printf("row: %d, column: %c\n", t_p1.y, t_p1.x_c);
			
			///////////////////////////
			// CHECK FOR HIT MISS SUNK, OR LOCATION INVALID
			if (list_update(t_p1, &p1, &ai) == 3)
			{
				goto LOCA_INPT;
			}
			
			num_player = 0;
		}
		else if (num_player == 0)
		{
			system("CLS");
			hour_glass();

			// AI'S ROUND
			t_ai.y = rand_num(0, 10);
			t_ai.x = rand_num(0, 10);
			t_ai.x_c = 0;

			///////////////////////////
			// CHECK FOR HIT MISS SUNK, OR LOCATION INVALID
			while (list_update(t_ai, &ai, &p1) == 3)
			{
				t_ai.y = rand_num(0, 10);
				t_ai.x = rand_num(0, 10);
				t_ai.x_c = 0;
			}
			time_delay(1);
			num_player = 1;
		}		
		
	}
	
	grid_print(p1, ai, game_end);                                           // DISPLAY GRID

	printf("\n");
	
	return 0;
}