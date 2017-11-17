#ifndef BATTLESHIP_H
#define _CRT_SECURE_NO_WARNINGS

#define BATTLESHIP_H

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

typedef unsigned int uint;
typedef unsigned char uchar;

typedef struct ship_s {
	uchar type[SIZE_SHIP_TYPE];
	uint size;
	
	uint *loca_x;
	uint *loca_y;
	
	uint *loca_x_hit;
	uint *loca_y_hit;
	
	struct shiap_s *next;
} ship;


uint loca_protection(ship *headptr, uint sce[][10]);
// THIS FUNCTION PROVIDE PROTECTION AGAINST LOCATION OVERLAP

uint ship_code_translate(uchar symbol[]);
// THIS FUNCTION TRANSLATE THE SHIP SYMBOL TO NUMBER CODE

uchar ship_translate(uint code);
// THIS FUNCTION TRANSLATE THE SHIP TYPE CODE TO ONE-CHAR SYMBOL

ship *board_configurate(ship *headptr, FILE *input);             
// THIS FUNCTION CREATES THE LINKED LIST AT THE BEGINNING OF THE GAME

bool grid_print(ship *headptr_1, ship *headptr_2);
// THIS FUNCTION PRINTS THE GAME BOARD

bool ship_remove(ship *headptr, uchar target[]);
// THIS FUNCTION REMOVE A NODE SPECIFIED BY USER

bool empty_board(ship *headptr);
// THIS FUNCTION CHECKS IF A BOARD IS EMPTY

#endif