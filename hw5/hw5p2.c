/*
Author: Shengrui Zhang
Student ID: 23426900
Email: shengruizhang@email.arizona.edu
Created Date: 10/06/17
*/

/*////////////////////////////////////// PROBLEM ONE /////////////////////////////////////*/
/*
Inputs:
	2 or 3 vectors

Outputs:
	magnitute or dot product or cross product

Problems: calculate the output for the given input and the calculation user wanted
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdbool.h>


/*//////////////////////////// M MODE ////////////////////////////////////////*/
double magni(double x, double y, double z) {
	
	double mag = 0;
	
	mag = pow(x, 2) + pow(y, 2) + pow(z, 2);
	mag = sqrt(mag);
	
	return(mag);
}


/*////////////////////////// DOT MODE //////////////////////////////*/
void dot_prot(void) {
	
	double vec1[3];
	double vec2[3];
	
	double pro = 0;
	double angle = 0;
	
	printf("Calculating the dot product between V1 and V2\n");
	
	printf("Enter in Vx1 Vy1 Vz1 (separated by spaces)\n");
	scanf("%lf %lf %lf", &vec1[0], &vec1[1], &vec1[2]);
	
	printf("Enter in Vx2 Vy2 Vz2 (separated by spaces)\n");
	scanf("%lf %lf %lf", &vec2[0], &vec2[1], &vec2[2]);
	
	/*///////////////////*/
	pro = (vec1[0] * vec2[0]) + (vec1[1] * vec2[1]) + (vec1[2] * vec2[2]);
	
	angle = pro / (magni(vec1[0], vec1[1], vec1[2]) * (magni(vec2[0], vec2[1], vec2[2])));
	angle = acos(angle);
	angle = (angle * 180) / (acos(-1));
	
	printf("V1 dot V2 = %.8lf, theta = %.8lf\n degrees", pro, angle);
}


/*/////////////////////////	CROSS PRODUCT ///////////////////////*/
void cross_pro (double *x1, double *y1, double *z1, double x, double y, double z, double *theta) {
	double temp = 0;
	double temp2 = 0;
	double temp3 = 0;
	temp = *x1;
	temp2 = *y1;
	*x1 = ((*y1) * z) - (y * (*z1));
	*y1 = (x * (*z1)) - (temp * z);
	temp3 = *z1;
	*z1 = (temp * y) - (x * temp2);

	*theta = magni(*x1, *y1, *z1);
	*theta = (*theta) / (magni(temp, temp2, temp3) * magni(x, y, z));
	*theta = asin(*theta);
	*theta = (*theta) * 180 / (acos(-1));
}

/*/////////////////////////// MAIN FUNCTIN /////////////////////*/
int main(void) {
	char quit = 'y';
	char mode = '?';
	
    double vec[3];
	double vec1[3];
	double vec2[3];
	double mag = 0;
	
	double angle = 0;

	while (quit == 'y') {
		
		mode = 'a';
		while (mode != 'm' && mode != 'd' && mode != 'c' && mode != 'M' && mode != 'D' && mode != 'C') {
			
			printf("Enter M to calculate the magnitude of a single 3-D vector\n");
			printf("Enter D to calculate the dot product of two 3-D vectors\n");
			printf("Enter C to calculate the cross product of two 3-D vectors\n");
			
			scanf(" %c", &mode);

			if (mode != 'm' && mode != 'd' && mode != 'c' && mode != 'M' && mode != 'D' && mode != 'C') {
				printf("Enter a valid choice\n");
			}
		}
		
		switch (mode) {
		/*////////////// MAGNITUDE //////////////////*/
		case 'M':
		case 'm':
			//printf("m\n");
			
			printf("Enter in Vx Vy Vz (separated by spaces)\n");
			scanf("%lf %lf %lf", &vec[0], &vec[1], &vec[2]);
			mag = magni(vec[0], vec[1], vec[2]);
			printf("|V| = |<%.8lf, %.8lf, %.8lf>| = %.8lf\n", vec[0], vec[1], vec[2], mag);
			
			break;
			
			
		/*/////////////////	DOT PRODUCT /////////*/
		case 'D':
		case 'd':
			//printf("d\n");

			dot_prot();

			break;
			
			
			
		/*////////////// CROSS PRODUCT //////////*/
		case 'C':
		case 'c':
			//printf("c\n");
			
			printf("Calculating the cross product between V1 and V2\n");
			
			printf("Enter in Vx1 Vy1 Vz1 (separated by spaces)\n");
			scanf("%lf %lf %lf", &vec1[0], &vec1[1], &vec1[2]);
			
			printf("Enter in Vx2 Vy2 Vz2 (separated by spaces)\n");
			scanf("%lf %lf %lf", &vec2[0], &vec2[1], &vec2[2]);
			
			cross_pro(&vec1[0], &vec1[1], &vec1[2], vec2[0], vec2[1], vec2[2], &angle);

			printf("V1 x V2 = <%.8lf, %.8lf, %.8lf>, theta = %.8lf degrees\n", vec1[0], vec1[1], vec1[2], angle);
			
			break;
		}

		
		/*////////////////// EXITING //////////////////////*/
		quit = 'z';

		do 
		{
			printf("Would you like to perform another calculation? (y/n)");
			scanf(" %c", &quit);
			if (quit != 'y' && quit != 'n') {
				printf("Enter a valid input\n");
			}
			
		} while (quit != 'y' && quit != 'n');
	}

	return 0;
}