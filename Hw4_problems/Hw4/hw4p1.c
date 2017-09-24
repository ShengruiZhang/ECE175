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



#define _CRT_SECURE_NO_WARNINGs

#include <stdio.h>

// A fish looks like this: ><(((('>
// A mouse looks like this: ----{,_,<">

void PROMPT(void) {
	int type = 0;
	int amount = 0;
	
	printf("This program prints\n");
	printf("1) a school of fish or\n");
	printf("2) mice in a maze.\n");
	
	printf("Enter your option (1 or 2):");
	scanf(" %d", &type);
	
	printf("How many fish are in the school?");
	scanf(" %d", &amount);
	
	return(void);
}






int main(void) {
	
	
	return 0;
}