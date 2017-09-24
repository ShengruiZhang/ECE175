// Author: Shengrui Zhang
// Date Created: 09/16/17

/* Description:
   Input: five coefficients
   Output: five possible roots
*/

/* This program take user inputs to find the possible roots based on Newton Rhapson method*/
 
 
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdbool.h>


double coeff_0 = 1; // Declare 5 coefficients
double coeff_1 = 2; // Declare 5 coefficients 
double coeff_2 = 3;
double coeff_3 = 4;
double coeff_4 = 5;
double coeff_5 = 6;

const double guess_1 = -10000; // Define 7 initial guess value
const double guess_2 = -1000;
const double guess_3 = -100;
const double guess_4 = 000;
const double guess_5 = 100;
const double guess_6 = 1000;
const double guess_7 = 10000;

double x = 0.0; // the possible root 

double y = 0; // y value

double y_2 = 0; // derivative of the function

double derivative = 0.0;

int i = 0; // loop counter

//bool tolerance = 0;

double deri_1st(double x) {
	
	derivative = 5 * coeff_5 * (pow(x, 4.0));
	derivative = derivative + (4 * coeff_4 * (pow(x, 3.0)));
	derivative = derivative + (3 * coeff_3 * (pow(x, 2.0)));
	derivative = derivative + (2 * coeff_2 * x);
	derivative = derivative + coeff_1;
	
	return(derivative);
}

double result = 0.0;

double function_value (double x) {
	
	result = coeff_5 * pow(x, 5.0);
	result = coeff_4 * pow(x, 4.0) + result;
	result = coeff_3 * pow(x, 3.0) + result;
	result = coeff_2 * pow(x, 2.0) + result;
	result = coeff_1 * pow(x, 1.0) + result;
	result = coeff_0 * pow(x, 0.0) + result;
	
	return(result);
}
	
int main(void) {

	printf("This program is to find one root of 5th-order polynomial using Newton-Rhapson method.\n");
	printf("c5x^5 + c4x^4 + c3x^3 + c2x^2 + c1x + c0\n");
	printf("Enter polynomial coefficients: c5 c4 c3 c2 c1 c0 in this order:\n");
	scanf("%lf %lf %lf %lf %lf %lf", &coeff_5, &coeff_4, &coeff_3, &coeff_2, &coeff_1, &coeff_0);

	printf("Your polynomial is ");

	if (coeff_5 != 0) {

		printf("%.1lfx^5 + ", coeff_5);
	}

	if (coeff_4 != 0) {

		printf("%.1lfx^4 + ", coeff_4);
	}

	if (coeff_3 != 0) {

		printf("%.1lfx^3 + ", coeff_3);
	}

	if (coeff_2 != 0) {

		printf("%.1lfx^2 + ", coeff_2);
	}

	if (coeff_1 != 0) {

		printf("%.1lfx", coeff_1);
	}

	if (coeff_0 != 0) {

		printf(" + %.1lf", coeff_0);
	}
	printf("\n");


	//printf("\ntest:%lf\n", function_value(1));

	i = 1;
	int j = 0; // define inner loop variable
	while (i <= 7) {

		switch (i) {

		case 1:
			x = guess_1;
			j = 0; // reset inner loop variable

			while (j < 500) {

				y = function_value(x); // case 1 uses guess value 1

				if (fabs(y) > 0.00001) {
					y_2 = deri_1st(x);
					x = x - (y / y_2);
				}
				else {
					printf("One of the roots of this polynomial is %.5lf", x);
					printf("\nStarting from an initial guess of x = %.1lf, this answer was obtained in %d iterations.", guess_1, j);
					++i;
					goto GUESS_2; // use second number to guess

					// probably need a break statement to end the loop.
				}
				++j;
				if (j == 500) {
					
					printf("The initial guess of x = %.1lf failed to converge to a solution; roots may be complex\n", guess_1);
					++i;
					goto GUESS_2; // use second number to guess
				}					
			}
			break;
			
		GUESS_2:
		case 2:
		x = guess_2;
		j = 0; // reset inner loop variable
			while (j < 500) {

				y = function_value(x); // case 1 uses guess value 1

				if (fabs(y) > 0.00001) {
					y_2 = deri_1st(x);
					x = x - (y / y_2);
				}
				else {
					printf("\nOne of the roots of this polynomial is %.5lf", x);
					printf("\nStarting from an initial guess of x = %.1lf, this answer was obtained in %d iterations.", guess_2, j);
					++i;
					goto GUESS_3; // use second number to guess

					// probably need a break statement to end the loop.
				}
				++j;
				if (j == 500) {
					
					printf("The initial guess of x = %.1lf failed to converge to a solution; roots may be complex\n", guess_2);
					++i;
					goto GUESS_3; // use second number to guess
				}
			}
			break;

		GUESS_3:
		case 3:
			x = guess_3;
			j = 0; // reset inner loop variable
			while (j < 500) {

				y = function_value(x); // case 1 uses guess value 1

				if (fabs(y) > 0.00001) {
					y_2 = deri_1st(x);
					x = x - (y / y_2);
				}
				else {
					printf("\nOne of the roots of this polynomial is %.5lf", x);
					printf("\nStarting from an initial guess of x = %.1lf, this answer was obtained in %d iterations.", guess_3, j);
					++i;
					goto GUESS_4; // use second number to guess

								  // probably need a break statement to end the loop.
				}
				++j;
				if (j == 500) {
					
					printf("The initial guess of x = %.1lf failed to converge to a solution; roots may be complex\n", guess_3);
					++i;
					goto GUESS_4; // use second number to guess
				}
			}
			break;

		GUESS_4:
		case 4:
			x = guess_4;
			j = 0; // reset inner loop variable
			while (j < 500) {

				y = function_value(x); // case 1 uses guess value 1

				if (fabs(y) > 0.00001) {
					y_2 = deri_1st(x);
					x = x - (y / y_2);
				}
				else {
					printf("\nOne of the roots of this polynomial is %.5lf", x);
					printf("\nStarting from an initial guess of x = %.1lf, this answer was obtained in %d iterations.", guess_4, j);
					++i;
					goto GUESS_5; // use second number to guess

								  // probably need a break statement to end the loop.
				}
				++j;
				if (j == 500) {
					
					printf("The initial guess of x = %.1lf failed to converge to a solution; roots may be complex\n", guess_4);
					++i;
					goto GUESS_5; // use second number to guess
				}
			}
			break;

		GUESS_5:
		case 5:
			x = guess_5;
			j = 0; // reset inner loop variable
			while (j < 500) {

				y = function_value(x); // case 1 uses guess value 1

				if (fabs(y) > 0.00001) {
					y_2 = deri_1st(x);
					x = x - (y / y_2);
				}
				else {
					printf("\nOne of the roots of this polynomial is %.5lf", x);
					printf("\nStarting from an initial guess of x = %.1lf, this answer was obtained in %d iterations.", guess_5, j);
					++i;
					goto GUESS_6; // use second number to guess

								  // probably need a break statement to end the loop.
				}
				++j;
				if (j == 500) {
					
					printf("The initial guess of x = %.1lf failed to converge to a solution; roots may be complex\n", guess_5);
					++i;
					goto GUESS_6; // use second number to guess
				}
			}
			break;

		GUESS_6:
		case 6:
			x = guess_6;
			j = 0; // reset inner loop variable
			while (j < 500) {

				y = function_value(x); // case 1 uses guess value 1

				if (fabs(y) > 0.00001) {
					y_2 = deri_1st(x);
					x = x - (y / y_2);
				}
				else {
					printf("\nOne of the roots of this polynomial is %.5lf", x);
					printf("\nStarting from an initial guess of x = %.1lf, this answer was obtained in %d iterations.", guess_6, j);
					++i;
					goto GUESS_7; // use second number to guess

								  // probably need a break statement to end the loop.
				}
				++j;
				if (j == 500) {
					
					printf("The initial guess of x = %.1lf failed to converge to a solution; roots may be complex\n", guess_6);
					++i;
					goto GUESS_7; // use second number to guess
				}
			}
			break;

		GUESS_7:
		case 7:
			x = guess_7;
			j = 0; // reset inner loop variable
			while (j < 500) {

				y = function_value(x); // case 1 uses guess value 1

				if (fabs(y) > 0.00001) {
					y_2 = deri_1st(x);
					x = x - (y / y_2);
				}
				else {
					printf("\nOne of the roots of this polynomial is %.5lf", x);
					printf("\nStarting from an initial guess of x = %.1lf, this answer was obtained in %d iterations.", guess_7, j);
					++i;
					goto END; // use second number to guess

								  // probably need a break statement to end the loop.
				}
				++j;
				if (j == 500) {
					
					printf("The initial guess of x = %.1lf failed to converge to a solution; roots may be complex\n", guess_7);
					++i;
					goto END; // end program
				}
			}
			break;
		}
	}

	END:


	return 0;
}