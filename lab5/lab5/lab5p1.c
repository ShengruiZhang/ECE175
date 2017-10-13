/*
Author: Shengrui Zhang
Student ID: 23426900
Email: shengruizhang@email.arizona.edu
Created Date: 10/12/17
*/

/*////////////////////////////////////// PROBLEM ONE /////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS

#define SIZE_ARRAY 12

#include <stdio.h>
#include <stdbool.h>








/*////////////////////// MAIN FUNCTION /////////////////////////////////////////*/

int main(void) {
	
	int number[SIZE_ARRAY] = {1,2,3,4,5,6,26,5,4,3,2,1};                                 ////////////// define array
	
	int i = 0;                                                    // loop vari
	
	/////  Input///////////
	
	printf("Enter 12 integer numbers (each one separated by a space):");
	
	/*for (i = 0; i < SIZE_ARRAY; ++i) {
		scanf("%d", &number[i]);
	}*/
	
	//for (i = 0; i < SIZE_ARRAY; ++i) {                              ////// testing
	//	printf("%d ", number[i]);
	//}
	
	/////// FIND MAX ////////////
	
	int max = -1111111;                                                   //// vari for max
	
	for (i = 0; i < SIZE_ARRAY; ++i) {
		if (number[i] > max) {
			max = number[i];
		}
	}
	
	//printf("\n%d ", max);                                       /// testing
	printf("Maximum all data points is %d\n", max);

	/*/////////////////// Reverse order //////////////*/
	
	printf("An array in reverse order:\n");

	for (i = (SIZE_ARRAY - 1); i >= 0; --i) {
		printf("%d ", number[i]);
	}
	
	printf("\n");
	
	
	/*/////////////////////////////  check for symmetric ////////////////*/
	
	bool symtrc = false;                                 // define
	
	for (i = 0; i < (SIZE_ARRAY / 2); ++i) {
		if (number[i] != number[(SIZE_ARRAY - 1 - i)]) {
			//printf("This array is NOT symmetric.\n");
			//goto END;
			symtrc = false;
			goto END;
		}
		else {
			symtrc = true;
			/*if (i == 6) {
				printf("This array is symmetric.\n");
			}*/
		}
	}
	END:
	if (symtrc == true) {
		printf("This array is symmetric.\n");
	}
	else {
		printf("This array is NOT symmetric.\n");
	}
	
	
	
	
	
	
	
	return 0;
	
}