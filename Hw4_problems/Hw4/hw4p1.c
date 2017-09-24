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



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// A fish looks like this: ><(((('>
// A mouse looks like this: ----{,_,<">

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
	
	//printf("This program prints\n");
	//printf("1) a school of fish or\n");
	//printf("2) mice in a maze.\n");

	//while (type != 1 && type != 2) {
	//	printf("Enter your option (1 or 2):");   // 1 for fish, 2 for mouse
	//	scanf(" %d", &type);
	//	//printf("%d\n", type);
	//}

	//printf("How many fish are in the school?");
	//scanf(" %d", &amount);
	//printf("%d\n", amount);
	
	//PRINT_FISH();
	//PRINT_MICE();
	
	
	// Printing
	
	
	
	unsigned char quit = '?'; // quit or not?
	
	unsigned int line = 0; // to indicate the line
	
	unsigned int o = 0; // outer loop variable
	
	unsigned int i = 0; // inner loop variable, number of tab printed
	
	unsigned int i_2 = 0;
	
	while (quit != 'N' || quit != 'n') { // Type N or n causes program to terminate
		
		line = 0; // reset line counter
		type = 0; // reset type

		printf("This program prints\n");
		printf("1) a school of fish or\n");
		printf("2) mice in a maze.\n");

		while (type != 1 && type != 2) {
			printf("Enter your option (1 or 2):");   // 1 for fish, 2 for mouse
			scanf(" %d", &type);
			//printf("%d\n", type);
		}

		printf("How many fish are in the school?");
		scanf(" %d", &amount);
		//printf("%d\n", amount);

		do {   // Print a fish first or print tab first until enough
			
			switch (type) {
				
				case 1:    // Print fish
				if (line < (amount / 2)) { // print the first part of fish when line reachs half of amount
					PRINT_FISH();
					line++;
					for (i = 0; i < line; i++) { // Print tabs
						printf("\t");
					}
				}
				else if (line >= (amount / 2)) { 
					PRINT_FISH();
					line++;
					for (i_2 = 0; i_2 < i; i_2++) {
						printf("\t");
						i--;
					}
				}
				break;
				
				case 2:    // Print first
				printf("\t");
				break;
			}
			
		} while (line < (amount - 1)); // use line to print objects

		printf("Would you like to continue.(N/n to quit):");
		scanf(" %c", &quit);
	}
	
	return 0;
}