// Author: SHENGRUI ZHANG
// Created Date: 9/23/17

// ECE 175
// Homework 4 Problem 1

/* This program takes the user input to make a certain type of fish or mice (Pretty annoying :( )

Inputs: type of output desired (fish or mice); 
		number of those
		
Outputs: Fishes or mice
*/

// Nested loop is required to use

// A fish looks like this: ><(((('>
// A mouse looks like this: ----{,_,<">

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void PRINT_FISH(void) {  // Funtion that prints the fish, save some work probably?
	printf("><(((('>\n");
	return;
}

void PRINT_MICE(void) {  // Funtion that prints the mouse, save some work probably?
	printf("----{,_,\">\n");
	return;
}


int main(void) {
	
	unsigned int type = 0; // to determine what get to display
	
	unsigned int amount = 0; // to determine how many ----{,_,<"> ><(((('> get display, also how many column it is
	
	// Printing
		
	//unsigned char quit = '?'; // quit or not?
	
	unsigned int line = 0; // to indicate the line
	
	unsigned int o = 0; // outer loop variable
	
	unsigned int i = 0; // inner loop variable, number of tab printf
	
	unsigned int i_2 = 0; // secon inner loop variable
	
	//while (quit != 'N' && quit != 'n') { // Type N or n causes program to terminate
		
		line = 0; // reset line counter
		type = 0; // reset type

		printf("This program prints\n");
		printf("1) a school of fish or\n");
		printf("2) mice in a maze.\n");

		while (type != 1 && type != 2) { // Take the valid input
			printf("Enter your option (1 or 2)");   // 1 for fish, 2 for mouse
			scanf(" %d", &type);
			printf("\n");
		}

		switch (type)
		{
		case (1):
			printf("How many fish are in the school? ");
			scanf(" %d", &amount);
			printf("\n");
			break;
		case (2):
			printf("How many mice in the maze? ");
			scanf(" %d", &amount);
			printf("\n");
		default:
			break;
		}

		printf("\n");
		
		do {   // Print a fish first or printf tab first until enough
			
			switch (type)
			{
				
				case 1:                                                        // Print fish
				if ((amount % 2) == 0) {                                // even amount
					for (o = 0; o <= ((amount / 2) - 1); o++) {
						for (i = 0; i < line; i++) {
							printf("\t");
						}
						PRINT_FISH();
						line++;
					}

					for (i_2 = 0; i_2 < (amount / 2); i_2++) {
						for (o = 0; o < i; o++) {
							printf("\t");
						}
						i--;
						PRINT_FISH();
						line++;
					}
				}
				else if ((amount % 2) != 0) {                            // odd amount
					for (o = 0; o < ((amount / 2) + 1); o++) {           // first part
						for (i = 0; i < line; i++) {
							printf("\t");
						}
						PRINT_FISH();
						line++;
					}
					
					for (i_2 = 0; i_2 < (amount / 2); i_2++) {           // second part
						for (o = 0; o < (i - 1); o++) {
							printf("\t");
						}
						i--;
						PRINT_FISH();
						line++;
					}
				}
				break;
				
				case 2:                                                         // Print mouse
				if ((amount % 2) == 0) {                                // even amount
						i_2 = (amount / 2) - 1;
						for (o = 0; o < ((amount / 2) - 0); o++) {
							for (i = 0; i < i_2; i++) {
								printf("\t");
							}
							i_2--;
							PRINT_MICE();
							line++;
						}

						i = 0;
						for (i_2 = 0; i_2 < (amount / 2); i_2++) {
							for (o = 0; o < i; o++) {
								printf("\t");
							}
							i++;
							PRINT_MICE();
							line++;
						}
					}
				else if ((amount % 2) != 0) {                            // odd amount
						i_2 = (amount / 2);
						for (o = 0; o < ((amount / 2) + 1); o++) {           // first part
							for (i = 0; i < (i_2); i++) {
								printf("\t");
							}
							i_2--;
							PRINT_MICE();
							line++;
						}

						i = 1;
						for (i_2 = 0; i_2 < (amount / 2); i_2++) {           // second part
							for (o = 0; o < i; o++) {
								printf("\t");
							}
							i++;
							PRINT_MICE();
							line++;
						}
					}
				break;
			}
			
		} while (line < (amount - 1)); // use line to printf objects

		//printf("\nWould you like to continue.(N/n to quit):");
		printf("\n");
		//scanf(" %c", &quit);
		//printf("\n");
	//}
	
	return 0;
}