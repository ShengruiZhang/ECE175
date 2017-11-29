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

void time_delay                        (uint sec)
{
	time_t retTime = time(0) + sec;
	while (time(0) < retTime);
}

void game_title                        (void)
{
	FILE *title = NULL;
	uchar str[150];
	title = fopen("battleship.txt", "r");
	while (fgets(str, 149, title) != NULL)
	{
		printf("%s", str);
	}
}

void hour_glass                        (void)
{
	FILE *title = NULL;
	uchar str[150];
	title = fopen("hour_glass.txt", "r");
	while (fgets(str, 149, title) != NULL)
	{
		printf("%s", str);
	}
}

void buffer_clear                      (void)
{
	uchar c = '\0';
	while ((c = getchar()) != '\n' && c != EOF);
}

ship *board_configurate                (ship *headptr, FILE *input, uint ai)
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
		if (ai != 1)
		{
			printf("\nNumber of preset to read: %d \n", num_set_to_read);
		}
		sets_read = 0;
	}
	else if (input == stdin)                                         // INPUT FROM STDIN
	{
		printf("\nConfigurate the board manually. \n");
		num_set_to_read = 0;                                         // SO THAT IT STEPS INTO THE LOOP
		strncpy(str_command, "add", 3);                              // SO THAT IT STEPS INTO THE LOOP
	}
	else {
		printf("\nError occured. Code: 501 \n");                     // ERROR NOTICE
	}
	
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	// LOOP FOR TAKING INPUT
	while (sets_read < num_set_to_read || strncmp(str_command, "add", 3) == 0)
	{
		memset(str_command, '\0', sizeof(str_command));              // CLEAR COMMAND STREAM
		temp = (ship*)malloc(sizeof(ship));
		
		if (input == stdin) {
			printf("\nEnter the type of the ship.\n");
		}
		
		fgets(temp->type, SIZE_SHIP_TYPE, input);                    // THE NEWLINE IS INCLUDED IN STRING
		temp->type[strlen(temp->type) - 1] = 0;                      // DELETE NEWLINE
		if (ai != 1)
		{
			//printf("Ship type: %s", temp->type);
			if (input != stdin) printf("\n");
		}
		
		
		/////////////////////////////////////////////////////////////
		GET_SIZE:
		if (input == stdin) {
			printf("\n\nEnter the size of the ship. \n");
		}
		
		fgets(str, 5, input);
		sscanf(str, "%d", &temp->size);
		temp->sleft = temp->size;                                       // INDICATE HOW MANY LEFT
		if (temp->size > 5) {
			printf("Invalid size. Code: 502");
			goto GET_SIZE;
		}
		if (ai != 1)
		{
			//printf("Ship size: %d\n", temp->size);
		}
		
		
		/////////////////////////////////////////////////////////////
		// LOCATES MEMORY
		temp = (ship*)realloc(temp, sizeof(ship) + 4 * temp->size *sizeof(uint));

		temp->loca_x = (uint*)malloc(temp->size * sizeof(uint));        // ALLOCATES FOR LOCATION
		temp->loca_y = (uint*)malloc(temp->size * sizeof(uint));        // ALLOCATES FOR LOCATION
		temp->loca_x_hit = (uint*)malloc(temp->size * sizeof(uint));    // ALLOCATES FOR LOCATION
		temp->loca_y_hit = (uint*)malloc(temp->size * sizeof(uint));    // ALLOCATES FOR LOCATION
		
		
		/////////////////////////////////////////////////////////////
		// SET HIT LOCATIONS TO 99
		for (i = 0; i < temp->size; ++i)
		{
			temp->loca_x_hit[i] = 99;
			temp->loca_y_hit[i] = 99;
		}
		
		
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
				printf("Invalid input, enter again. Code: 503\n");
				// RESET
				j = 0;
				for (uint a = 0; a < (temp->size); ++a) {
					temp->loca_x[a] = 0;
				}
				goto LOCATION_X;
			}
			if (ai != 1)
			{	
				//printf("x location: %d\n", temp->loca_x[i]);
			}
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
				printf("Invalid input, enter again. Code: 504 \n");
				goto LOCATION_Y;
			}
			str[j] = ' ';                                      // IT HAS TO BE SPACE
			if (temp->loca_y[i] == 10) {                       // HANDLE 10 DIFFERENTLY
				str[j + 1] = ' ';                              // IT HAS TO BE SPACE
				j += 1;
			}
			if (ai != 1)
			{
				//printf("y location: %d\n", temp->loca_y[i]);
			}
			j += 2;
		}	
		printf("\n");
		
			
		/////////////////////////////////////////////////////////////
		// CHECK VALIDILTY OF THE LOCATION
		if (!loca_protection(headptr, temp)) {
			printf("locations are illegal.\n");
			goto LOCATION_X;
		}
		
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
			while (fgets(str_command, SIZE_COMMAND, stdin))
			{
				if (strncmp(str_command, "add", 3) == 0 || strncmp(str_command, "end", 3) == 0)
				{
					break;
				}
				else {
					printf("Invalid command, enter again. Code: 505 \n");
					memset(str_command, '\0', sizeof(str_command));
					buffer_clear();
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
			
		case 10:
			ship_sym = MISS;
			break;
		
		case 11:
			ship_sym = HIT;
			break;
		
		default:
			printf("Error occured. Code: 601 \n");
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
		printf("Error occured. Code: 701 \n");
		num_code = 0;
	}
	return num_code;
}

uint array_config                      (uint grid[][10], ship *hptr)
{
	uint index_array = 0;
	uint ship_type = 0;
	
	uint i = 0;
	
	ship *temp = hptr->next;
	
	while (temp != NULL)
	{
		ship_type = ship_code_translate(temp->type);
		for (index_array = 0; index_array < temp->size; ++index_array)
		{
			grid[temp->loca_y[index_array] - 1][temp->loca_x[index_array] - 1] = ship_type;
		}
		temp = temp->next;
		++i;
	}
	return i;
}

bool grid_print                        (player p1, player p2, uint end)
{
	// P1 FOR HUMAN PLAYER, P2 FOR AI
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
	num_ship_1 = array_config(grid_1, p1.list);
	/*
	temp = p1.list->next;
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
	*/
	// UPDATE THE MISSES AND HITS BY OPPONENT
	if (1)
	{
		for (r = 0; r < 10; ++r)
		{
			for (c = 0; c < 10; ++c)
			{
				switch (p2.map[c][r])                // MISS
				{
					case 0:
						grid_1[r][c] = 10;
						if (1)
							p1.map_0[r][c] = 10;
						break;
					
					case 1:                          // HIT
						grid_1[r][c] = 11;
						if (1)
							p1.map_0[r][c] = 11;
						break;
					
					default:
						break;
				}
			}
		}
	}
	
	// UPDATE THE GRID BASED ON THE SHIP TYPE
	//num_ship_2 = array_config(grid_2, p2.list);
	num_ship_2 = 1;

		/*
		temp = p2.list->next;
		while (temp != NULL)
		{
			ship_type = ship_code_translate(temp->type);
			for (index_array = 0; index_array < temp->size; ++index_array)
			{
				grid_2[temp->loca_y[index_array] - 1][temp->loca_x[index_array] - 1] = ship_type;
				p2.map_0[temp->loca_y[index_array] - 1][temp->loca_x[index_array] - 1] = ship_type;
			}
			++num_ship_2;
			temp = temp->next;
		*/
		
	// UPDATE THE MISSES AND HITS BY OPPONENT

	if (1)
	{
		for (r = 0; r < 10; ++r)
		{
			for (c = 0; c < 10; ++c)
			{
				switch (p1.map[c][r])                // MISS
				{
				case 0:
					grid_2[r][c] = 10;
					if (DISPLAY_GRID_END == 1)
						p2.map_0[r][c] = 10;
					break;

				case 1:                              // HIT
					grid_2[r][c] = 11;
					if (DISPLAY_GRID_END == 1)
						p2.map_0[r][c] = 11;
					break;

				default:
					break;
				}
			}
		}
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

	if (end != 1)
	{
		//printf("                               Player 1");
		printf("                             Your board");
		//printf("                                                         Player 2\n\n");
		printf("                                                         Attempts\n\n");
	}
	else
	{
		printf("                             Your board");
		printf("                                                     Opponent's board\n\n");
	}


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
				if (end != 1) {
					ship_code = ship_translate(grid_2[r_2][c]);
				}
				else {
					ship_code = ship_translate(p2.map_0[r_2][c]);
				}
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
		else if (r == 6)
		{
			printf("             ");                                              // 14 SPACES
			printf("%s        Computer\n", p1.name);
		}
		else if (r == 7)
		{
			printf("             ");                                              // 14 SPACES
			printf("Hit: %d        Hit: %d\n", p1.hit, p2.hit);
		}
		else if (r == 8)
		{
			printf("             ");                                              // 14 SPACES
			printf("Miss: %d        Miss: %d\n", p1.miss, p2.miss);
		}
		else if (r == 9)
		{
			printf("             ");                                              // 14 SPACES
			printf("Sunk: %d        Sunk: %d\n", p1.sunk, p2.sunk);
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
				if (end != 1) {
					ship_code = ship_translate(grid_2[r_2][c]);
				}
				else {
					ship_code = ship_translate(p2.map_0[r_2][c]);
				}
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
	ship *node = headptr->next;
	ship *previous = headptr;
	
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
		if (headptr->next == NULL)                 // IF IT IS THE FIRST NODE, SKIP CHECK
			break;
		for (i = 0; i < tar->size; ++i)            // LOOPING FOR ALL COORDINATES FROM THE TARGET
		{
			for (j = 0; j < temp->size; ++j)       // LOOPING FOR ALL COORDINATES FROM EXISTING SHIPS
			{
				if (tar->loca_x[i] == temp->loca_x[j] &&
				    tar->loca_y[i] == temp->loca_y[j])
				{
					// BREAK AND RETURE WITH FALSE
					//printf("x: %d\ty: %d\n", tar->loca_x[i], tar->loca_y[i]);
					//printf("x: %d\ty: %d\n", temp->loca_x[j], temp->loca_y[j]);
					return valid = false;
				}
			}				
		}
		temp = temp->next;
	}
	return valid;
}

void list_print                        (ship *headptr)
{
	ship *temp = headptr->next;
	while (temp != NULL)
	{
		printf("Ship Type: %s \t Size: %d \n", temp->type, temp->size);
		for (uint i = 0; i < temp->size; ++i)
		{
			printf("x-coordinate: %d \t y-coordinate: %d \n", temp->loca_x[i], temp->loca_y[i]);
		}
		temp = temp->next;
		printf("\n");
	}
	printf("All element in the list has been displayed.\n");
}

uint coor_translate                    (temp_shot *tar)
{
	uint status = 99;
	if ((*tar).x_c >= 65 && (*tar).x_c <= 74)
	{
		(*tar).x = (*tar).x_c - 64;
	}
	else if ((*tar).x_c >= 97 && (*tar).x_c <= 106)
	{
		(*tar).x = (*tar).x_c - 96;
	}
	else
	{
		//printf("Error occured. Code: 1401\n");
		(*tar).x = 99;
	}
	
	if ((*tar).y > 10 || (*tar).y < 1 || (*tar).x == 99)
	{
		printf("Location invalid. \n");
		status = 0;
	}
	return status;
}

uint list_update                       (temp_shot atmp, player *current_p, player *oppen)
{
	ship *temp = (*oppen).list->next;                               // OPPONENT'S LIST
	ship *previous = (*oppen).list;
	
	uint u = 0;
	
	///////////////////////////////////
	// CHECK FOR SHOT OVERLAPPING
	if ((*current_p).map[atmp.x - 1][atmp.y - 1] != 3)
	{
		printf("Location has been targeted, choose another one.");
		return u = 3;
	}
	
	while (temp != NULL)
	{
		for (u = 0; u < temp->size; ++u)                             // LOOPING FOR EVERY COORS FOR EVERY SHIP
		{
			if (temp->loca_x[u] == atmp.x &&                         // CHECK FOR HIT
			    temp->loca_y[u] == atmp.y)
			{
				// FOR TESTING
				//printf("x: %d, x_c: %c, y: %d\n", atmp.x, atmp.x_c, atmp.y);
				
				// WRITE THE COOR TO OPPONENT'S LIST
				temp->loca_x_hit[temp->sleft - 1] = atmp.x;
				temp->loca_y_hit[temp->sleft - 1] = atmp.y;

				// FOR TESTING
				//printf("List hit: x: %d, y: %d\n", temp->loca_x[temp->sleft - 1], temp->loca_y[temp->sleft - 1]);
				//printf("Hit: %d, %d\n", temp->loca_x_hit[temp->sleft - 1], temp->loca_y_hit[temp->sleft - 1]);

				--temp->sleft;
				(*current_p).hit += 1;                               // INCREASE HITS
				(*current_p).map[atmp.x - 1][atmp.y - 1] = 1;        // COPTY TO MAP FOR HIT

				u = 1;                                               // RETURN 0 IF SHIP HAS NOT SUNKEN YET
				
				// HANDLE SUNK SHIP
				if (temp->sleft == 0)
				{
					u = 2;
					(*oppen).sunk += 1;                              // OPPONENT SUNK SHIP +1
					// REMOVE THE SHIP FROM THE LIST
					previous->next = temp->next;
					free(temp);                                      // ATTEMPT TO FREE MEMORY
				}
				
				return u;
			}
			
			
		}
		previous = temp;
		temp = temp->next;
	}
	(*current_p).miss += 1;                                          // INCREASE MISSES
	(*current_p).map[atmp.x - 1][atmp.y - 1] = 0;                    // COPY MISS TO MAP
	u = 0;
	// RETURN 0 FOR MISS, 1 FOR HIT, 2 FOR SUNK, 3 FOR INVALID
	return u;
}

uint rand_num                          (uint low, uint high)
{
	if (low == 0) {
		return rand() % ++high;                                              // INCREASE ONE SO THAT IT CAN RETURN HIGH
	}
	else if (low > 0) {
		return (rand() % (high - low) + low);
	}
	else {
		return 1;
	}
}

ship *ship_generate                    (uint direc, uchar type[])
{
	// 0 FOR HORIZONTAL, 1 FOR VERTICAL, 2 FOR DIAGONAL
	
	ship *_temp = malloc(sizeof(ship));
	
	uint type_int = ship_code_translate(type);
	
	strcpy(_temp->type, type);
	
	switch (type_int)
	{
		case 1:
			_temp->size = 5;		break;
		
		case 2:
			_temp->size = 4;		break;
		
		case 3:
			_temp->size = 3;		break;
		
		case 4:
			_temp->size = 3;		break;
		
		case 5:
			_temp->size = 2;		break;
		
		case 6:
			_temp->size = 1;		break;
		
		case 7:
			_temp->size = 1;		break;

		default:					break;
	}
	_temp->sleft = _temp->size;

	_temp             = (ship*)realloc(_temp, sizeof(ship) + 4 * _temp->size * sizeof(uint));
	_temp->loca_x     = (uint*)malloc(_temp->size * sizeof(uint));
	_temp->loca_x_hit = (uint*)malloc(_temp->size * sizeof(uint));
	_temp->loca_y     = (uint*)malloc(_temp->size * sizeof(uint));
	_temp->loca_y_hit = (uint*)malloc(_temp->size * sizeof(uint));
	
	//direc = rand_num(0, 2);
	
	///////////////////////////////////
	// TESTING
	//direc = 3;
	
	switch (direc)
	{
		case 0:                        // HORIZONTAL
			_temp->loca_x[0] = rand_num(1, 10 - _temp->size);
			_temp->loca_y[0] = rand_num(1, 10 - _temp->size);
			for (uint u = 1; u < _temp->size; ++u)
			{
				_temp->loca_x[u] = _temp->loca_x[0] + u;
				_temp->loca_y[u] = _temp->loca_y[0];
			}
		break;
		
		case 1:
			_temp->loca_x[0] = rand_num(1, 10 - _temp->size);
			_temp->loca_y[0] = rand_num(1, 10 - _temp->size);
			for (uint u = 1; u < _temp->size; ++u)
			{
				_temp->loca_y[u] = _temp->loca_y[0] + u;
				_temp->loca_x[u] = _temp->loca_x[0];
			}
		break;		
		
		case 2:
			_temp->loca_x[0] = rand_num(1, 10 - _temp->size);
			_temp->loca_y[0] = rand_num(1, 10 - _temp->size);
			for (uint u = 1; u < _temp->size; ++u)
			{
				_temp->loca_y[u] = _temp->loca_y[0] + u;
				_temp->loca_x[u] = _temp->loca_x[0] + u;
			}
		break;
		
		case 3:
			_temp->loca_x[0] = rand_num(_temp->size, 10);
			_temp->loca_y[0] = rand_num(1, 11 - _temp->size);
			for (uint u = 1; u < _temp->size; ++u)
			{
				_temp->loca_y[u] = _temp->loca_y[0] + u;
				_temp->loca_x[u] = _temp->loca_x[0] - u;
			}
		break;
		
		default:			break;
	}
	
	
	//cell = _temp; 
	_temp->next = NULL;
	
	return _temp;
}

























