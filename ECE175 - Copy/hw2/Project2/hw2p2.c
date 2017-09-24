// Author: Shengrui Zhang
// Date Created: 08/29/17
/* Description:
   Input: 8 numbers inputed by user
		  
   Output: Sum of all values
		   Square of the values for each input
		   Average
		   Standard deviation
		   Maxium
*/
// Calculate the value shown above from the user input

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>


int main(void) {

	unsigned int i = 0; // Loop variable
	
	double user_value = 0.0; // User input value
	double sum = 0.0; // Sum of the value user inuputed
	double sum_square = 0.0; // Sum of square of each value
	double average = 0.0; // Average
	double max = 0.0; // Maxium value
	double stad_devi = 0.0; // Standard deviation
	

	for (i = 1; i <= 8; ++i) {

		printf("Enter data value:"); // Get user value
		scanf("%lf", &user_value);
		
		sum = sum + user_value; // Add user_value to sum
		
		sum_square = sum_square + pow(user_value, 2.0); // Add the square of user input to square sum
		
		if (user_value > max) {
			
			max = user_value;
			
		}
		
		printf("Accumulated sum of %d values is %.2lf\n", i, sum);
		printf("Accumulated sum of squares of %d values is %.2lf\n\n", i, sum_square);
		
	}
	
	i = i - 1;
	average = sum / i; // Calculate average
	stad_devi = (sum_square / i) - (pow(average, 2.0));
	stad_devi = sqrt(stad_devi);
	
	printf("Average of %d values is %.2lf\n", i, average);
	printf("Standard deviation is %.3lf\n", stad_devi);
	printf("Maximum of %d values is %.3lf\n", i, max);
	
	//printf("The end\n");
	
	
	return 0;
}

