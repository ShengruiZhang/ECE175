#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#define SIZE_SHIP_TYPE 21
#define SIZE_BOARD_FILE 21
#define SIZE_COMMAND 16
#define SIZE_USER_NAME 31
#define MISS 'X'
#define HIT 'H'
#define DISPLAY_GRID_END 1
typedef unsigned int uint;
typedef unsigned char uchar;
typedef struct ship_s {
	uchar type[SIZE_SHIP_TYPE];
	uint size;
	uint *loca_x;
	uint *loca_y;
	uint *loca_x_hit;
	uint *loca_y_hit;
	uint sleft;
	struct ship_s *next;
} ship;
typedef struct player_s {
	uchar name[SIZE_USER_NAME];
	uint hit;
	uint miss;
	uint sunk;
	uint map[10][10];
	uint map_0[10][10];
	ship *list;
} player;
typedef struct temp_shot_s {
	uint y;
	uint x;
	uchar x_c;
} temp_shot;
void time_delay                        (uint sec);
void game_title                        (void);
void hour_glass                        (void);
void buffer_clear                      (void);
ship *board_configurate                (ship *headptr, FILE *input, uint ai);             
uchar ship_translate                   (uint code);
uint ship_code_translate               (uchar symbol[]);
uint array_config                      (uint grid[][10], ship *hptr);
bool grid_print                        (player p1, player p2, uint end);
bool ship_remove                       (ship *headptr, uchar target[]);
bool empty_board                       (ship *headptr);
bool loca_protection                   (ship *headptr, ship *tar);
void list_print                        (ship *headptr);
uint coor_translate                    (temp_shot *tar);
uint list_update                       (temp_shot atmp, player *current_p, player *oppen);
uint rand_num                          (uint low, uint high);
ship *ship_generate                    (uint direc, uchar type[]);
int main(void)
{
	printf("\n\t\t\t");
	printf("Welcome to the Battleship Game! \n\n");
	game_title();
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
	ship *player1_head = malloc(sizeof(ship));
	ship *ai_head = malloc(sizeof(ship));
	player1_head->next = NULL;
	ai_head->next = NULL;
	ship *temp = NULL;
	ship *temp_2 = NULL;
	ship *temp_3 = NULL;
	printf("Player: Enter your name. ");
	scanf("%s", p1.name);
	getchar();
	printf("\nSelect which way to configurate the game board, configurate manually or input from an existing file. \n");
	while (1)
	{
		temp = player1_head;
		printf("\n%s: Type \"manual\" or \"file\" to choose input method. \n", p1.name);
		fgets(command, SIZE_COMMAND, stdin);
		if (strncmp(command, "manual", 6) == 0)
		{
			inpt = stdin;
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
				printf("\nType the file name. \n");
				fgets(file_name, SIZE_BOARD_FILE, stdin);
				inpt = fopen(file_name, "r");
				if (inpt == NULL) {
					printf("Error when opening file. \n");
				}
				else 
				{
					if (board_configurate(temp, inpt, 0) != NULL) {
						fclose(inpt);
						temp = temp->next;
						while (temp != NULL)
						{
							if (temp->size != 0)
								++counter;
							temp = temp->next;
						}
						temp_int = counter;
						break;
					}
					else {
						printf("Error: Null list. Code: 007 \n. ");
						break;
					}
				}
			}
			break;
		}
		else {
			printf("Wrong command, please type again. \n");
		}
	}
	AI_INPT:
	temp = ai_head;
	while (1)
	{
		printf("How do you want to configurate AI's grid? Type \"file\" to import from file or \"random\" to automatically fill grid. \n");
		fgets(command, SIZE_COMMAND, stdin);
		if (strncmp(command, "file", 4) == 0)
		{
			while (1)
			{
				printf("\nType the file name. \n");
				fgets(file_name, SIZE_BOARD_FILE, stdin);
				inpt = fopen(file_name, "r");
				if (inpt == NULL) {
					printf("Error when opening file. \n");
				}
				else 
				{
					if (board_configurate(temp, inpt, 0) != NULL) {
						fclose(inpt);
						temp = temp->next;
						counter = 0;
						while (temp != NULL)
						{
							if (temp->size != 0)
								++counter;
							temp = temp->next;
						}
						if (counter == temp_int)
						{
							break;
						}
						else
						{
							printf("The number of ships in two lists is different.\n");
							goto AI_INPT;
						}
					}
					else {
						printf("Error: Null list. Code: 008 \n. ");
						break;
					}
				}
			}
			break;
		}
		if (strncmp(command, "random", 4) == 0)
		{
			ai.list = ai_head;
			temp = ai_head;
			while (temp_2 != NULL)
			{
				do {
					temp_3 = ship_generate(rand_num(0, 3), temp_2->type);
				} while (!loca_protection(ai_head, temp_3));
			}
			break;
		}
		else {
			printf("Wrong command, please type again. \n");
		}
	}
	array_config(p1.map_0, p1.list);
	array_config(ai.map_0, ai.list);
	num_player = 1;
	while (1)
	{
		system("CLS");
		if (ai.list->next == NULL)
		{
			num_player = 1;
			game_end = 1;
			break;
		}
		else if (p1.list->next == NULL)
		{
			num_player = 0;
			game_end = 1;
			break;
		}
		if (num_player == 1)
		{
			LOCA_INPT:
			printf("\n\n%s: Enter in the location of your next shot: row number, column letter. ", p1.name);
			fgets(coor, SIZE_SHIP_TYPE, stdin);
			sscanf(coor, "%d %c", &t_p1.y, &(t_p1.x_c));
			if (t_p1.x_c < 65 && t_p1.x_c > 74 && t_p1.x_c < 97 && t_p1.x_c > 106)
			{
				printf("Please enter a valid location.\n");
				goto LOCA_INPT;
			}
			{
				goto LOCA_INPT;
			}
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
			t_ai.y = rand () % 11 + 1;
			t_ai.x = rand () % 11 + 1;
			t_ai.x_c = 0;
			while (list_update(t_ai, &ai, &p1) == 3)
			{
				t_ai.y = rand() % 11 + 1;
				t_ai.x = rand() % 11 + 1;
				t_ai.x_c = 0;
			}
			time_delay(1);
			num_player = 1;
		}		
	}
	system("CLS");
	if (num_player == 1)
		printf("\n\n%s won the game!\n", p1.name);
	if (num_player == 0)
		printf("\n\nComputer won the game!\n");
	printf("\nGoodbye!\n");
	return 0;
}
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
	memset(str_command, '\0', sizeof(str_command));
	ship *temp = NULL;
	ship *newest = NULL;
	if (input != stdin)
	{		
		fscanf(input, "%d\n", &num_set_to_read);
		if (ai != 1)
		{
			printf("\nNumber of preset to read: %d \n", num_set_to_read);
		}
		sets_read = 0;
	}
	{
		printf("\nConfigurate the board manually. \n");
	}
	else {
	}
	while (sets_read < num_set_to_read || strncmp(str_command, "add", 3) == 0)
	{
		temp = (ship*)malloc(sizeof(ship));
		if (input == stdin) {
			printf("\nEnter the type of the ship.\n");
		}
		if (ai != 1)
		{
			if (input != stdin) printf("\n");
		}
		GET_SIZE:
		if (input == stdin) {
			printf("\n\nEnter the size of the ship. \n");
		}
		fgets(str, 5, input);
		sscanf(str, "%d", &temp->size);
		if (temp->size > 5) {
			printf("Invalid size. Code: 502");
			goto GET_SIZE;
		}
		if (ai != 1)
		{
		}
		temp = (ship*)realloc(temp, sizeof(ship) + 4 * temp->size *sizeof(uint));
		for (i = 0; i < temp->size; ++i)
		{
			temp->loca_x_hit[i] = 99;
			temp->loca_y_hit[i] = 99;
		}
		LOCATION_X:
		if (input == stdin) {
			printf("\nEnter the x location of the ship separated by space. \n");
		}
		j = 0;
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
			{
				printf("Invalid input, enter again. Code: 503\n");
				j = 0;
				for (uint a = 0; a < (temp->size); ++a) {
					temp->loca_x[a] = 0;
				}
				goto LOCATION_X;
			}
			if (ai != 1)
			{	
			}
			j += 2;
		}
		printf("\n");
		LOCATION_Y:
		if (input == stdin) {
			printf("\nEnter the y location of the ship separated by space. \n");
		}
		j = 0;
		fgets(str, 15, input);
		for (i = 0; i < temp->size; ++i)
		{
			sscanf(str, "%d", &temp->loca_y[i]);
			if (temp->loca_y[i] <= 0 || temp->loca_y[i] > 10) {
				printf("Invalid input, enter again. Code: 504 \n");
				goto LOCATION_Y;
			}
				j += 1;
			}
			if (ai != 1)
			{
			}
			j += 2;
		}	
		printf("\n");
		if (!loca_protection(headptr, temp)) {
			printf("locations are illegal.\n");
			goto LOCATION_X;
		}
		if (headptr->next == NULL)
		{
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
			while (fgets(str_command, SIZE_COMMAND, stdin))
			{
				if (strncmp(str_command, "add", 3) == 0 || strncmp(str_command, "end", 3) == 0)
				{
					break;
				}
				else {
					printf("Invalid command, enter again. Code: 505 \n");
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
	const uint ROW = 10;
	const uint COL = 10;
	bool board_empty = false;
	uint index_array = 0;
	uint ship_type = 0;
	uchar ship_code = '\0';
	uchar num_row[4];
	memset(num_row, '\0', sizeof(num_row));
	ship *temp = NULL;
	for (c = 0; c < COL; ++c)
	{
		for (r = 0; r < ROW; ++r)
		{
			grid_1[c][r] = 0;
			grid_2[c][r] = 0;
		}
	}
	num_ship_1 = array_config(grid_1, p1.list);
	if (1)
	{
		for (r = 0; r < 10; ++r)
		{
			for (c = 0; c < 10; ++c)
			{
				{
					case 0:
						grid_1[r][c] = 10;
						if (1)
							p1.map_0[r][c] = 10;
						break;
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
	num_ship_2 = 1;
	if (1)
	{
		for (r = 0; r < 10; ++r)
		{
			for (c = 0; c < 10; ++c)
			{
				{
				case 0:
					grid_2[r][c] = 10;
					if (DISPLAY_GRID_END == 1)
						p2.map_0[r][c] = 10;
					break;
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
	if (num_ship_1 == 0 && num_ship_2 == 0)
	{
		board_empty = true;
		return board_empty;
	}
	printf("\n\n");
	if (end != 1)
	{
		printf("                             Your board");
		printf("                                                         Attempts\n\n");
	}
	else
	{
		printf("                             Your board");
		printf("                                                     Opponent's board\n\n");
	}
	printf("   A     B     C     D     E     F     G     H     I     J");
	printf("     A   B   C   D   E   F   G   H   I   J\n");
	for (r = 0; r < ROW; ++r)
	{
		printf("-------------------------------------------------------------");
		if (r_2 <= 10 && r < 6) {
			printf("-----------------------------------------\n");
		}
		else {
			printf("\n");
		}
		printf("|     |     |     |     |     |     |     |     |     |     |");
		if (r_2 < 10)
		{
			snprintf(num_row, 3, "%d", r_2 + 1);
			if ((r_2 + 1) < 10)
				strncat(num_row, " ", 1);
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
		for (c = 0; c < COL; ++c)
		{
			ship_code = ship_translate(grid_1[r][c]);
			printf("|  %c  ", ship_code);
		}
		printf("|");
		if (r_2 < 10) {
			printf("-----------------------------------------\n");
		}
		else if (r == 6)
		{
			printf("%s        Computer\n", p1.name);
		}
		else if (r == 7)
		{
			printf("Hit: %d        Hit: %d\n", p1.hit, p2.hit);
		}
		else if (r == 8)
		{
			printf("Miss: %d        Miss: %d\n", p1.miss, p2.miss);
		}
		else if (r == 9)
		{
			printf("Sunk: %d        Sunk: %d\n", p1.sunk, p2.sunk);
		}
		else {
			printf("\n");
		}
		printf("|     |     |     |     |     |     |     |     |     |     |");
		if (r_2 < 10)
		{
			snprintf(num_row, 3, "%d", r_2 + 1);
			if ((r_2 + 1) < 10)
				strncat(num_row, " ", 1);
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
			break;
		{
			{
				if (tar->loca_x[i] == temp->loca_x[j] &&
				    tar->loca_y[i] == temp->loca_y[j])
				{
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
	ship *previous = (*oppen).list;
	uint u = 0;
	if ((*current_p).map[atmp.x - 1][atmp.y - 1] != 3)
	{
		printf("Location has been targeted, choose another one.");
		return u = 3;
	}
	while (temp != NULL)
	{
		{
			    temp->loca_y[u] == atmp.y)
			{				
				temp->loca_x_hit[temp->sleft - 1] = atmp.x;
				temp->loca_y_hit[temp->sleft - 1] = atmp.y;
				--temp->sleft;
				if (temp->sleft == 0)
				{
					u = 2;
					previous->next = temp->next;
				}
				return u;
			}
		}
		previous = temp;
		temp = temp->next;
	}
	u = 0;
	return u;
}
uint rand_num                          (uint low, uint high)
{
	if (low == 0) {
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
	switch (direc)
	{
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
	_temp->next = NULL;
	return _temp;
}