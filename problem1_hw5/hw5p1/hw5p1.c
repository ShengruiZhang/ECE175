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
	*Three_Frames_Old = *Two_Frames_Old;
	*Two_Frames_Old = *One_Frames_Old;
	*One_Frames_Old = Current_Digit;
}




/*////////////////////////////////////////////////// MAIN FUNCTION ////////////////////////////////////////////////////*/

int main(void) {

	FILE *input;                         // input file pointer
	FILE *output;
	unsigned int digit = 0;              // Digit
	unsigned char let = '?';             // letter
	
	int dig[4];                          // current array
	int dg[4];							 // target array

	int pro = 0;
	int pro_old = 0;                     // old product value
	//int digit = 0;
	int digit_old = 0;
	
	unsigned int i = 0;                  // Loop variable

	unsigned int s = 0;                  // digit variable(digit number)
	unsigned int sl = 0;                 // digit verifiy variable
	
	input = fopen("Scrambled_File.txt", "r");
	//input = fopen("1.txt", "r");
	output = fopen("Unscrambled_File.txt", "w");
	
	if (input != NULL) {
		while (fscanf(input, "%c", &let) != EOF) {
			++s;                                                               // update the digit variable, before everything
			if (isdig(let, &digit) == false) {
				
				/*///////// IF IT IS NOT A DIGIT ////////////////////*/
				fprintf(output, "%c", let);                // output to file
				if (let != 32) {						   // if it is not a space, update the value
					++sl;
				}
				
				
				
				
				
				
				
				
			}
			else if (isdig(let, &digit) == true) {
				++sl;                                                            // update local verifiy variable
				/*///////////////////////////// IF IT IS A DIGIT ////////////////////////////*/
				
				//pro_old = digit_old * dig[1] * dig[2] * dig[3];                  // calculate the old product
				Update_Samples(digit_old, &dig[1], &dig[2], &dig[3]);            // update the array
				digit_old = digit;                                               // update the old first digit
				pro = digit * dig[1] * dig[2] * dig[3];                          // calculate the new product
				if (pro > pro_old) {                                             // compare
					if (sl == s) {                                               // if the digits are continuous
						for (i = 1; i < 4; ++i) {                                // store the current array to a new output array
							dg[i] = dig[i];
							dg[0] = digit;
							pro_old = digit_old * dg[1] * dg[2] * dg[3];         // calculate the current greatest product based on the output array
						}
					}
					else if (s > sl) {                                           // if the digits are not continuous
						sl = s;                                                  // the array will start from the current digit
						dig[1] = dig[2] = dig[3] = 0;                            // reset the arrar to zero
					}
				}			
			}
		}

		pro_old = (dg[3] - '0') * (dg[2] - '0') * (dg[1] - '0') * (dg[0] - '0');
		printf("The largest product of a 4-digit sequence is ");
		printf("%c * %c * %c * %c = %d\n", dg[3], dg[2], dg[1], dg[0], pro_old);     // for testing
	}
	else {
		printf("Error when reading file.\n");
	}

	fclose(input);
	fclose(output);

	return 0;
}