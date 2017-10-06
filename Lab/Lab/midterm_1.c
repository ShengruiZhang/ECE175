///////////////////////////////////////////////////////////////////////////////////////////
/* Midterm lab

Author: SHENGRUI ZHANG (shengruizhang@email.arizona.edu)
Date: 10/05/17

*/


/*///////////////// Problem 1 ///////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*///////////////////// Function to calculate power //////////////////*/

double power(double X, int n) {
	double f = 1.0;
	int i;
	for (i = 1; i <= n; i++) {
		f *= X;
	}
	
	return(f);
}

/*//////////////////////Function to calculate acrtangent///////////////////////////////*/

double my_atan(double x) {    // here lower x is the value
	double const pi = 3.14159265358979; // define pi value
	unsigned int i = 0; // the number of power
	double b = 0;
	double ang = 0.0; // the angle to return
	
	unsigned int const MAX = 201; // try as many as 201 times
	
	
	/*/////// GETTING ANGELS ///////*/
	
	if (x > -1 && x < 1) { /////////////////// for the value in between////////////////////////
		for (i = 5; i <= MAX; i = i + 4) {   // the power of 3 7 11 15 etc
			printf("%d", i);
			//b = power(x, i);
			//ang = ang + (b / i);
		}
		ang = - ang;
		
		for (i = 3; i <= MAX; i = i + 4) {   // the power of 5 9 13 17 etc
			ang = ang + (power(x, i) / i);
		}
		
		ang = (x - ang) * 180;
		ang = ang / pi;
	}
	
	
	
	return(ang);
}

/*/////////////////////////////////////MAIN FUNCTION////////////////////////*/

int main(void) {
	
	/*int a = 0;
	for (a = 5; a <= 201; a = a + 4) {
		printf("%d\n", a);
	}*/

	FILE *input;  // pointer to file 
	FILE *output;
	
	double value = 0.0; ///////////////// for the input tangent value
	
	double angle = 0.0; /////// for the output values
	/*/////////// Open file//////////////*/
	
	input = fopen("Test_Values.txt", "r");
	output = fopen("Output_Angles.txt", "w");
	
	////////////////GETTING THE NUMBER FROM FILE////////////////////////////
	
	if (input != NULL) { 
		while (fscanf(input, "%lf", &value) != EOF) {
		//printf("%.12lf\n", value); // ////////////////// Testing file reading
			
		/*//////////////////// finding the angles //////////////*/
		
		
		// if the tangent is 1, then the angle is 45 deg
		
		if (value == 1) {
			angle = 45;
		}
		else 
		
			
		// if the tangent is -1, then the angle is -45 deg		
		
		if (value == -1) {
			angle = -45;
		}
		
		/*///////////// if the value is wired, call a defined function to deal w/ it. /////*/
		
		else {
			angle = my_atan(value);
		}
		
		
		/*///////////////////// Writing the angles to output file ////////*/
		fprintf(output, "%.10lf\n", angle);
		
		}
	}
	else {
		printf("Error when reading the file.\n");
	}
	
	
	
	
	fclose(input);
	fclose(output);

	return 0;
}