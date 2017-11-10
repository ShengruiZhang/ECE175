/*
ECE175 mid term project
Battleship

Author: Shengrui Zhang
Date Created: 11/09/17
Email: shengruizhang@email.arizona.edu
Student ID: 23426900
*/

/*
AIRCRAFT CARRIER    SYM: A   SIZE: 5
BATTLESHIP          SYM: B   SIZE: 4
CRUISER             SYM: C   SIZE: 3
SUBMARINE           SYM: S   SIZE: 3
PATROL BOAT         SYM: P   SIZE: 2
KAYAK               SYM: K   SIZE: 1
ROW BOAT            SYM: R   SIZE: 1
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>   // PRBABLY NOT NEED THIS

#define SIZE_SHIP_TYPE 21

typedef unsigned int uint;
typedef unsigned char uchar;

typedef struct coordinate_s {
	uint x;
	uint y;
} cordnte;

typedef struct ship_s {
	uchar type[SIZE_SHIP_TYPE]; 
	uint size;
	cordnte location;                 // NEED TO BE ALLOCATED DYNAMICALLY
	cordnte location_hit;             // NEED TO BE ALLOCATED DYNAMICALLY
	struct ship_s *next;              // POINTER TO NEXT SHIP
} ship;





int main(void)
{
	
	
	
	
	
	
	
	return 0;
}