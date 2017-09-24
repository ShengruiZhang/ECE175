#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

// Lab 1 
// Problem 2
// Name: Shengrui Zhang

int main(void) {
	sp
	
	float speed = 0.0;
	
	while (speed != 789) {

	printf("Enter the wind speed in MPH: ");
	scanf("%f", &speed);
	

		if (speed >= 157) {

			printf("With %.1f MPH, Category 5 hurricane\n", speed);

		}
		else if ((speed < 157) && (speed >= 130)) {

			printf("With %.1f MPH, Category 4 hurricane\n", speed);

		}
		else if ((speed < 130) && (speed >= 111)) {

			printf("With %.1f MPH, Category 3 hurricane\n", speed);

		}
		else if ((speed < 111) && (speed >= 96)) {

			printf("With %.1f MPH, Category 2 hurricane\n", speed);

		}
		else if ((speed < 96) && (speed >= 73)) {

			printf("With %.1f MPH, Category 1 hurricane\n", speed);

		}
		else if (speed <= 73) {

			printf("With %.1f MPH, Not a hurricane\n", speed);

		}
		else {

			printf("Invaild input");

		}

	}
	
	return 0;
	
}