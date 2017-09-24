#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Lab 0921, problem 2


// defining a function to calculate pi with a custom accuracy
double Pi_value (int n) {
	
	double value = 0; // the calculated pi value
	
	double tar_value = 0; // the target value
	
	// defining the initial values
	double a = 1;   
	double b = 1 / sqrt(2);
	double t = 0.25;
	double p = 1;
	
	
	
	// new values
	
	double a_new = 0;   
	double b_new = 0;
	double t_new = 0;
	double p_new = 0;
	
	
	while (fabs(pi - value) > pow(10, n)) {
		
		a_new = (a + b) / 2;
		b_new = sqrt(a * b);
		t_new = t - p * pow((a_new - a), 2);
		p_new = 2 * p;
		
		value = pow((a_new + b_new), 2) / (4 * t_new);
		
		a = a_new;
		b = b_new;
		t = t_new;
		p = p_new;
	}
	
	tar_value = value;
	
	return tar_value;
}

int kf
		