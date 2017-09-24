#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

// Lab 2
// Problem 1
// Name: Shengrui Zhang

int main(void) {
	
	int input = 0; // user input
	
	int target = 0; // the target number to be displayed
	int amount_num = 0; // the amount of the numbers found
	int sum = 0; // the sum of all the target values
	
	int i = 0; // number count
	int n = 0; // number to be determinted
	int g = 0;
	
	printf("Enter the value of n: "); // user enter value
	scanf("%d", &input);

	while (g <= input) {
		
		n = g;
	    n = (n % 10);
				
		if (n == 7) {
			
			i = i + 1;
			target = g;
			amount_num = amount_num + target;
			printf("%d ", g);
		}
		
		g++;
	}
	
	printf("\n");
	
	printf("Total numbers found: %d\n", i);
	printf("Total sum of numbers: %d\n", amount_num);
	
	return 0;
}
