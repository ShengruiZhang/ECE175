#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

// Lab 1
// Problem 1
// Name: Shengrui Zhang

int main(void) {
	
	float time = 0;
	float temp = 0;
	float hours, minutes = 0;

	float d = 0;
	float n = 0;
	
	printf("Enter hours and minutes for a power failure: "); // user enters value
	scanf("%f %f", &hours, &minutes);
	
	minutes = minutes / 60; // Converting min to hours
	hours = hours + minutes;
	//printf("Hours: %.2f\n", hours);
	
	time = hours; // Copy value
	
	n = 4 * pow(time, 2); // Calculating
	d = time + 2;
	temp = (n / d) - 20;

	printf("Temperature in a freezer = %.3f Celsius after %.2f hours of a power failure\n", temp, time); // Printing
	
	
	return 0;
	
}