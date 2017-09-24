// Author: Shengrui Zhang
// Date Created: 08/29/17
/* Description:
   Input: Length of the wall
          Height of the wall
		  Doors in the wall
		  Windows in the wall
		  Price per gallon of paint
		  Percantage of sale tax
		  
   Output: Area of the wall
           Amount of paint needed
		   Amount of can of paint needed
		   Total cost before tax
		   Total cost after tax
*/
// One can of paint contains on gallon paint

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void) {
	
	// Declaring variables
	
	const int AREA_DOOR = 20;
	const int AREA_WINDOW = 15;
	const int AREA_PAINT_PER_GALLON = 350;
	
	double wallLength = 0;
	double wallHeight = 0;
	double areaTotal =0.0;
	
	int numDoors = 0;
	int numWindows = 0;
	
	double canPaint = 0.0;
	double numPaint = 0.0;
	double costTotal = 0.0;
	double costTaxed = 0.0;
	double pricePaint = 0.0;
	double tax = 0.0;
	
	
	// User Enters values
	
	printf("Enter the length of the room to be painted (in inches):");
	scanf("%lf", &wallLength);
	
	printf("\nEnter the height of the room to be painted (in inches):");
	scanf("%lf", &wallHeight);
	
	printf("\nEnter the number of doors in the wall:");
	scanf("%d", &numDoors);
	
	printf("\nEnter the number of windows in the wall:");
	scanf("%d", &numWindows);
	
	printf("\nHow much does one gallon of paint cost (in dollars)?");
	scanf("%lf", &pricePaint);
	
	printf("\nEnter in the percent sales tax of the tile (as a percent):");
	scanf("%lf", &tax);
	
	
	// Calculate the total wall area in square inches
	
	wallHeight = wallHeight / 12;
	wallLength = wallLength / 12;
	areaTotal = wallLength * wallHeight;

	/*printf("l = %.2lf\n", wallLength);
	printf("h = %.2lf\n", wallHeight);*/

	areaTotal = (areaTotal - (AREA_DOOR * numDoors) - (AREA_WINDOW * numWindows));
	printf("The total area that will be painted is %.2lf square feet\n", areaTotal);
	
	
	// Calculate the total number of gallons to be purchased in gallons 
	
	numPaint = areaTotal / AREA_PAINT_PER_GALLON;
	printf("You will need %.2f gallons of paint to cover the area.\n", numPaint);
	
	
	// cans of paint to be purchased
	
	canPaint = numPaint / 1;
	canPaint = ceil(numPaint);
	printf("You will need to buy %.0f cans of paint.\n", canPaint);
	
	// Cost
	
	costTotal = canPaint * pricePaint;
	printf("The cost of the paint will be $%.2lf, before tax.\n", costTotal);
	tax = tax / 100;
	costTaxed = (costTotal * (1 + tax));
	printf("The cost of the paint will be $%.2lf, after tax.\n", costTaxed);
	
	return 0;
}