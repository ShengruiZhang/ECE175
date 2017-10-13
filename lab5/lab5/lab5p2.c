/*
Author: Shengrui Zhang
Student ID: 23426900
Email: shengruizhang@email.arizona.edu
Created Date: 10/12/17
*/

/*////////////////////////////////////// PROBLEM TWO /////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS

#define SIZE_ARRAY 7

#include <stdio.h>
#include <math.h>
#include <stdbool.h>


////////////////////////////////////////// GET CORNERS ///////////////////////////////////////////

void get_corners(FILE *inp, double x[7], double y[7]) {
	
	unsigned int i = 0;
	unsigned int a = 0;
	
	double temp = 0;             ////// temp vari

	if (inp != NULL) {
		while (fscanf(inp, "%lf", &temp) != EOF) {
			//printf("%lf\n", temp);            // testing

			if (i % 2 == 0) {      // even number means the x value
				x[a] = temp;
				//printf("%lf\n", x[a]);            // testing
			}
			else {
				y[a] = temp;
				//printf("%lf\n", y[a]);            // testing
				++a;
			}
			++i;
		}
	}
	else {
		printf("Something wrong.\n");
	}
}


////////////////////////////////////////// POLYGON AREA //////////////////////////////

double polygon_area(double x[], double y[], int size) {
	
	double s = 0;         // area vari
	
	unsigned int i = 0;         // loop vari
	
	for (i = 0; i <= (size - 2); ++i) {
		s = s + (x[i+1] + x[i]) * (y[i+1] - y[i]);
		//printf("%lf\n", s);
	}
	//printf("%lf\n", s);
	s = fabs(s) / 2;
	//printf("%lf\n", s);
	return(s);
}

//////////////////////////////////////////// MAIN FUNCTION//////////////////////////////////


int main(void) {
	
	// declare vari
	FILE *coor;
	
	coor = fopen("polygon_1.txt", "r");
	
	double coor_x[SIZE_ARRAY];
	double coor_y[SIZE_ARRAY];
	
	unsigned int i = 0;                       // loop vari
	
	/////////////////////// GETTING COORDINATES /////////////////////////////////
	
	get_corners(coor, coor_x, coor_y);
	
	//for (i = 0; i < (SIZE_ARRAY - 1); ++i) {          // testing
	//	printf("%lf ", coor_x[i]);
	//	printf("%lf\t", coor_y[i]);
	//}


	//////////////////// DOING AREA ///////////////////////////

	double area = 0;              // area vari

	area = polygon_area(coor_x, coor_y, 7);

	///////////////////////////////// PRINTING ////////////////////////

	printf("For polygon with the following corners:\n");
	printf("x\ty\n");
	for (i = 0; i <= (SIZE_ARRAY - 1); ++i) {          // testing
		printf("%.1lf ", coor_x[i]);
		printf("%.1lf\n", coor_y[i]);
	}
	printf("\n");
	printf("Its area is %.2lf\n", area);

	return 0;
}


