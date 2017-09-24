#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

 //Lab No. 2
 //Finding the linear interpolation

int main(void) {

	double x1 = 0.0; // Declaring
	double x2 = 0.0;
	double y1 = 0.0;
	double y2 = 0.0;

	double x = 0.0;
	double y = 0.0;
	double slope = 0.0;
	double y_intercept = 0.0;

	printf("Finding the linear interpolation. Note: Two coordinates must be different.\n");


	printf("Enter first coordinate:\n"); //Prompting
	scanf("%lf %lf", &x1, &y1);

	printf("Enter second coordinate:\n");
	scanf("%lf %lf", &x2, &y2);
	
	/*printf("(%lf,%lf)\n", x1, y1);
	printf("(%lf,%lf)\n", x2, y2);*/

	printf("Enter the known x value:\n");
	scanf("%lf", &x);

	/*********************************************************************/

	slope = ((y2 - y1) / (x2 - x1)); // Find slope
	y_intercept = y1 - (slope * x1); // Find y intercept

	/*printf("%lf", slope = ((y2 - y1) / (x2 - x1)));*/

	/*printf("%lf\n", slope);
	printf("%lf\n", y_intercept);*/

	y = ((slope * x) + y_intercept); // Find the desired y

	printf("\nThe corresponding y=");
	printf("%.2lf\n", y); // Print the dsired value


	/***********************************************************************************************************/
	//printf("\n\n\n\*********************************************************************************************\n\n\n");
	//// Problem 2
	//double H = 0.0; // Declaring; H is health
	//double E = 0.0; // E is effective health
	//double numHealth = 0.0; // Number of health
	//double numArmor = 0.0; // Number of armor
	//double cost = 0.0;
	//const double priceHealth = 2.5;
	//const double priceArmor = 18;

	//printf("Welcome to the League of Legends Effective Health Calculator!\n");
	//printf("Health costs %.0lf gold per unit. How much health would you like to purchase? ", priceHealth);
	//scanf("%lf", &numHealth);
	//printf("Armor costs %.0lf gold per unit. How much Armor would you like to purchase? ", priceArmor);
	//scanf("%lf", &numArmor);

	///*printf("%lf\n", numArmor);
	//printf("%lf\n", numHealth);*/

	//cost = ((numArmor * priceArmor) + (numHealth * priceHealth));
	///*printf("%lf\n", cost);*/

	//E = ((numHealth * (100 + numArmor)) / 100);

	//printf("%.0lf Health and %.0lf Armor costs %.0lf gold.\n", numHealth, numHealth, cost);
	//printf("%.0lf Health and %.0lf Armor provides an Effective Health of %.2lf\n", numHealth, numHealth, E);





	return 0;

}
