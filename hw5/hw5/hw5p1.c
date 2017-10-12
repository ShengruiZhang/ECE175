/*
Author: Shengrui Zhang
Student ID: 23426900
Email: shengruizhang@email.arizona.edu
Created Date: 10/06/17
*/

/*////////////////////////////////////// PROBLEM ONE /////////////////////////////////////*/
/*
Inputs:
	a scrambled file

Outputs:
	unscarmbled file

Problems: fix a scrambled file and  find the largest four sequence digits
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

bool isdig(unsigned char c, unsigned int *Current_Digit) {
	bool r_digit = false;

	if (c >= 48 && c <= 57) {            //////////////// CHECK IF IT IS A DIGIT //////////////
		*Current_Digit = c;       ////// UPDATE VALUE TO C /////////////
		r_digit = true;
	}
	else {
		r_digit = false;
	}

	return(r_digit);
}

void Update_Samples(unsigned int Current_Digit, unsigned int *One_Frames_Old, unsigned int *Two_Frames_Old, unsigned int *Three_Frames_Old) {
	
}




/*////////////////////////////////////////////////// MAIN FUNCTION ////////////////////////////////////////////////////*/

int main(void) {

	FILE *input;                         // input file pointer
	FILE *output;
	unsigned int digit = 0;              // Digit
	unsigned char let = '?';             // letter
	
	unsigned int digit[4];               // array
	
	input = fopen("Scrambled_File.txt", "r");
	output = fopen("Unscrambled.txt", "w");
	
	unsigned int i = 0;
	unsigned int a = 0;
	
	int pro = 0;
	
	int old = 0;
	
	if (input != NULL) {
		while (fscanf(input, "%c", &let) != EOF) {
			if (isdig(let, &digit) == false) {
				/*///////// IF IT IS NOT A DIGIT ////////////////////*/
				fprintf(output, "%c", let);
			}
			else if (isdig(let, &digit[i]) == true) {
				/*//////////// IF IT IS A DIGIT ////////////////////////////*/
				
				//if (i == 3) {
				//	pro = digit[0] * digit[1] * digit[2] * digit[3];
				//	i = 3;
				//}
				//else {
				//	if (a < 3) {
				//		i++;       // update counter
				//	}
				//	else {
				//		old = digit[3];
				//		
				//	}
				//}
				//
				//a++;
			}
		}
	}
	else {
		printf("Error when reading file.\n");
	}
	return 0;
}