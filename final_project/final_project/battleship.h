/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//  ECE175 FINAL PROJECT                                                                           //
//  BATTLESHIP GAME                                                                                //
//                                                                                                 //
//  HEADER   	                                                                                   //
//                                                                                                 //
//  Author:             Shengrui Zhang                                                             //
//  Date Created:       11/09/17                                                                   //
//  Email:              shengruizhang@email.arizona.edu                                            //
//  Student ID:         23426900                                                                   //
//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#ifndef BATTLESHIP_H
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
#define SIZE_USER_NAME 31

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
	// USED TO STORE NAME AND OTHER STATS
	uchar name[SIZE_USER_NAME];
	uint hit;
	uint miss;
	uint sunk;
	ship *list;
} player;

typedef struct temp_shot_s {
	// HOLDS THE SHOTS USER DESIRED TO SHOOT
	uint y;
	uint x;
	uchar x_c;
} temp_shot;

// FUNCTION PROTOTYPES

void game_title                        (void);
// THIS FUNCTION DISPLAY THE VISUAL TITLE OF BATTLESHIP

void buffer_clear                      (void);
// THIS FUNCTION PLAINLY FOR CLEARING THE INPUT BUFFER THE RIGTH WAY, SIMPLY BECAUSE FFLUSH DOES NOT WORK IN MY PROGRAM

ship *board_configurate                (ship *headptr, FILE *input);             
// THIS FUNCTION CREATES THE LINKED LIST AT THE BEGINNING OF THE GAME

uchar ship_translate                   (uint code);
// THIS FUNCTION TRANSLATE THE SHIP TYPE CODE TO ONE-CHAR SYMBOL

uint ship_code_translate               (uchar symbol[]);
// THIS FUNCTION TRANSLATE THE SHIP SYMBOL TO NUMBER CODE

bool grid_print                        (ship *headptr_1, ship *headptr_2, uchar name[]);
// THIS FUNCTION PRINTS THE GAME BOARD

bool ship_remove                       (ship *headptr, uchar target[]);
// THIS FUNCTION REMOVE A NODE SPECIFIED BY USER

bool empty_board                       (ship *headptr);
// THIS FUNCTION CHECKS IF A BOARD IS EMPTY

bool loca_protection                   (ship *headptr, ship *tar);
// THIS FUNCTION PROVIDE PROTECTION AGAINST LOCATION OVERLAP

void list_print                        (ship *headptr);
// THIS FUNCTION PRINTS ELEMENTS IN THE LINKED LIST

uint coor_translate                    (temp_shot *tar);
// THIS FUNCTION TRANSLATE COLUMN LETTER TO INT

uint list_update                       (temp_shot atmp, player current_p, ship *oppen);
/*
CHECK IF IT IS A HIT, MISS
UPDATE THE VALUE TO OPPONENT'S LIST, TO SHOW WHICH ONE IS HIT\
UPDATE THE VALUE TO P1, TO COUNT MISS, HIT
RETURNS THE TYPE OF SHIP BEEN HIT IF THE SHOT HITS
*/

#endif