/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//  ECE175 FINAL PROJECT                                                                           //
//  BATTLESHIP GAME                                                                                //
//                                                                                                 //
//  FUNCTION DEFINITIONS                                                                           //
//                                                                                                 //
//  Author:             Shengrui Zhang                                                             //
//  Date Created:       11/09/17                                                                   //
//  Email:              shengruizhang@email.arizona.edu                                            //
//  Student ID:         23426900                                                                   //
//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "battleship.h"

ship *board_configurate                (ship *headptr, FILE *input)
{
	uint num_set_to_read = 0;
	uint sets_read = 0;
	
	uint i = 0;
	uint j = 0;
	
	uchar str[15];                                                    // TEMP CHAR STRING
	uchar str_command[SIZE_COMMAND];                                  // STR FOR COMMAND
	
	memset(str, '\0', sizeof(str));                                   // RESET STRING
	memset(str_command, '\0', sizeof(str_command));
	
	ship *temp = NULL;
	ship *newest = NULL;

	///////////////////////////////////////////////////////////////////////////////////////////////
	// COMMAND OPERATION
	if (input != stdin)
	{		
		// READ THE NUMBER OF SETS TO BE READ
		fscanf(input, "%d\n", &num_set_to_read);
		printf("\nNumber of preset to read: %d \n", num_set_to_read);
		sets_read = 0;
	}
	else if (input == stdin)                                         // INPUT FROM STDIN
	{
		printf("\nConfigurate the board manually. \n");
		num_set_to_read = 0;                                         // SO THAT IT STEPS INTO THE LOOP
	}
	else {
		printf("\nError occured. Code: 001 \n");                     // ERROR NOTICE
	}
		
	///////////////////////////////////////////////////////////////////////////////////////////////
	// LOOP FOR TAKING INPUT
	while (sets_read < num_set_to_read || strncmp(str_command, "add", 3) == 0)
	{
		memset(str_command, '\0', sizeof(str_command));
		temp = (ship*)malloc(sizeof(ship));
		
		if (input == stdin) {
			printf("\nEnter the type of the ship.\n");
		}
		
		fgets(temp->type, SIZE_SHIP_TYPE, input);                    // THE NEWLINE IS INCLUDED IN STRING
		temp->type[strlen(temp->type) - 1] = 0;                      // DELETE NEWLINE
		printf("Ship type: %s", temp->type);
		if (input != stdin) printf("\n");
		
		/////////////////////////////////////////////////////////////
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
		
		/////////////////////////////////////////////////////////////
		// LOCATES MEMORY
		temp = (ship*)realloc(temp, sizeof(ship) + 4 * temp->size *sizeof(uint));

		temp->loca_x = (uint*)malloc(temp->size * sizeof(uint));        // ALLOCATES FOR LOCATION
		temp->loca_y = (uint*)malloc(temp->size * sizeof(uint));        // ALLOCATES FOR LOCATION
		temp->loca_x_hit = (uint*)malloc(temp->size * sizeof(uint));    // ALLOCATES FOR LOCATION
		temp->loca_y_hit = (uint*)malloc(temp->size * sizeof(uint));    // ALLOCATES FOR LOCATION
		
		/////////////////////////////////////////////////////////////
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
		
		/////////////////////////////////////////////////////////////
		// TAKES THE Y LOCATIONS AT ONCE
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
			str[j] = '\0';
			if (temp->loca_y[i] == 10) {                       // HANDLE 10 DIFFERENTLY
				str[j + 1] = '\0';
				j += 1;
			}
			j += 2;
			printf("y location: %d\n", temp->loca_y[i]);
		}	
		printf("\n");
		
		/////////////////////////////////////////////////////////////
		// CHECK VALIDILTY OF THE LOCATION
		loca_protection(headptr, temp->loca_x, temp->loca_y);
		
		/////////////////////////////////////////////////////////////
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
		
		/////////////////////////////////////////////////////////////
		// COMMAND HANDLING
		if (input == stdin) {
			printf("Type \"add\" to add another ship or \"end\" to start the game. \n");
			while (fgets(str_command, SIZE_COMMAND, stdin)) {
				if (strncmp(str_command, "add", 3) == 0 || strncmp(str_command, "end", 3) == 0) {
					break;
				}
				else {
					printf("Invalid input, enter again. Code: 005 \n");
					memset(str_command, '\0', sizeof(str_command));
				}
			}
		}
		else {
			++sets_read;
		}
	}
	return newest;
}

uchar ship_translate                   (uint code)
{
	uchar ship_sym = '0';
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

uint ship_code_translate               (uchar symbol[])
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

bool grid_print                        (ship *headptr_1, ship *headptr_2)
{
	const uint ROW = 10;
	const uint COL = 10;

	bool board_empty = false;

	uint r = 0;      // FOR ROW Y LOCATION
	uint r_2 = 0;    // FOR SM BOARD Y LOCATION
	uint c = 0;      // FOR COL X LOCATION

	uint index_array = 0;
	uint ship_type = 0;

	uint num_ship_1 = 0;  // INDICATE THE NUMBER OF THE SHIPS ON THE BOARD
	uint num_ship_2 = 0;  // INDICATE THE NUMBER OF THE SHIPS ON THE BOARD

	uchar ship_code = '\0';
	uchar num_row[4];
	memset(num_row, '\0', sizeof(num_row));

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
			grid_1[temp->loca_y[index_array] - 1][temp->loca_x[index_array] - 1] = ship_type;
		}
		++num_ship_1;
		temp = temp->next;
	}
	
	temp = headptr_2->next;
	while (temp != NULL)
	{
		ship_type = ship_code_translate(temp->type);
		for (index_array = 0; index_array < temp->size; ++index_array)
		{
			grid_2[temp->loca_y[index_array] - 1][temp->loca_x[index_array] - 1] = ship_type;
		}
		++num_ship_2;
		temp = temp->next;
	}
	
	// CHECK IF BOTH BOARD IS EMPTY
	if (num_ship_1 == 0 && num_ship_2 == 0)
	{
		board_empty = true;
		return board_empty;
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	// START PRINTING

	printf("\n\n");

	printf("                               Player 1");
	printf("                                                         Player 2\n\n");


	printf("     ");                                                              // 5 SPACES
	printf("   A     B     C     D     E     F     G     H     I     J");
	printf("             ");                                                      // 14 SPACES
	printf("     A   B   C   D   E   F   G   H   I   J\n");
	
	for (r = 0; r < ROW; ++r)
	{
		printf("     ");                                                          // 5 SPACES
		printf("-------------------------------------------------------------");
		if (r_2 <= 10 && r < 6) {
			printf("             ");                                              // 14 SPACES
			printf("-----------------------------------------\n");
		}
		else {
			printf("\n");
		}
		printf("     ");                                                          // 5 SPACES
		printf("|     |     |     |     |     |     |     |     |     |     |");
		
		
		if (r_2 < 10)
		{
			snprintf(num_row, 3, "%d", r_2 + 1);
			if ((r_2 + 1) < 10)
				strncat(num_row, " ", 1);
			printf("         %s  ", num_row);                                     // SM BOARD 14 SPACES, NUM ON THIRD FROM RIGHT
			for (c = 0; c < COL; ++c)
			{
				ship_code = ship_translate(grid_2[r_2][c]);
				printf("| %c ", ship_code);
			}
			++r_2;
			printf("|\n");
		}
		else {
			printf("\n");
		}
		
		
		snprintf(num_row, 3, "%d", r + 1);
		if ((r + 1) < 10)
			strncat(num_row, " ", 1);
		printf(" %s  ", num_row);                                                 // LG BOARD 5 SPACES, NUM ON SECOND FROM RIGHT
		for (c = 0; c < COL; ++c)
		{
			ship_code = ship_translate(grid_1[r][c]);
			printf("|  %c  ", ship_code);
		}
		printf("|");
	
	
		if (r_2 < 10) {
			printf("             ");                                              // 14 SPACES
			printf("-----------------------------------------\n");
		}
		else {
			printf("\n");
		}
		
		printf("     ");                                                          // 5 SPACES
		printf("|     |     |     |     |     |     |     |     |     |     |");
		
		
		
		if (r_2 < 10)
		{
			snprintf(num_row, 3, "%d", r_2 + 1);
			if ((r_2 + 1) < 10)
				strncat(num_row, " ", 1);
			printf("         %s  ", num_row);                                     // SM BOARD 14 SPACES, NUM ON THIRD FROM RIGHT
			for (c = 0; c < COL; ++c)
			{
				ship_code = ship_translate(grid_2[r_2][c]);
				printf("| %c ", ship_code);
			}
			++r_2;
			printf("|\n");
		}
		else {
			printf("\n");
		}
	}
	printf("     ");                                                              // 5 SPACES
	printf("-------------------------------------------------------------");
	return board_empty;
}

bool ship_remove                       (ship *headptr, uchar target[])
{
	ship *node = NULL;
	ship *previous = NULL;

	node = headptr->next;
	previous = headptr;
	
	bool succeed = false;
	
	while (succeed == false)
	{
		while (node != NULL)
		{
			if (strcmp(node->type, target) == 0)
			{
				previous->next = node->next;
				succeed = true;
				break;
			}
			previous = node;
			node = node->next;
		}
		if (node == NULL) {                                     // TO BREAK THE OUTTER LOOP
			break;
		}
	}
	return succeed;
}

bool empty_board                       (ship *headptr)
{
	bool empty = false;

	if (headptr->next == NULL)
		empty = true;

	return empty;
}

bool loca_protection                   (ship *headptr, ship *tar)
{
	ship* temp = headptr->next;
	
	bool valid = true;
	
	uint i = 0;
	uint j = 0;
	
	while (temp != NULL)
	{
		for (i = 0; i < tar->size; ++i)            // LOOPING FOR ALL COORDINATES FROM THE TARGET
		{
			for (j = 0; j < temp->size; ++j)       // LOOPING FOR ALL COORDINATES FROM EXISTING SHIPS
			{
				if (tar->loca_x[i] == temp->loca_x[i] &&
				    tar->loca_y[i] == temp->loca_y[i])
				{
					// BREAK AND RETURE WITH FALSE
					return valid = false;
				}
			}				
		}
	}
	return valid;
}
























