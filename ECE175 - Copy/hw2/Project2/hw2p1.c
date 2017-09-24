// Author: Shengrui Zhang
// Date Created: 09/10/17
/* Description:
   Input: Amount of water used
		  User type
   Output: Water bill before tax
           Water bill taxed
*/

/* This program calculate the water bill according to the user type and the usage of the water, and output the amount before and after tax*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void) {
	
const double price_resi_1 = 0.018; // Residential price class one
const double price_resi_2 = 0.032; // Class two
const double price_resi_3 = 0.08;  // Class three
const double price_commercial = 0.0288; // Commercial price

const double price_resi_fixed = 9.00;
const double price_commercial_fixed = 14.00;

const double tax = 6.1;

char user_type = '?';

double price_nontaxed = 0.0;
double price_taxed = 0.0;
double usage_water = 0.0;

	
	printf("Enter User Type (R for Residential, B for Business): ");
	scanf("%c", &user_type);
	
	printf("Enter water usage in cubic feet: ");
	scanf("%lf", &usage_water);
	//printf("water:%lf\n", usage_water);
	
	switch (user_type) {
		
		case 'R' :
		case 'r' :
			
			if (usage_water <= 700) {

				price_nontaxed = price_resi_fixed + (usage_water * price_resi_1); // Price class 1
				
				price_taxed = price_nontaxed * (tax / 100); // Get the tax amount
				price_taxed = price_nontaxed + price_taxed; // Get total amount
				
				//printf("amount: %lf", price_nontaxed);
				printf("Total cost including tax is $%.2lf\n", price_taxed);

			}
			else if ((usage_water > 700) && (usage_water <= 1500)) {

				price_nontaxed = price_resi_fixed + (700 * price_resi_1); // Fixed price and price class 1
				
				usage_water = usage_water - 700; // Find how much is exceeding 700
				price_nontaxed = price_nontaxed + (usage_water * price_resi_2); // Price class 2
				
				price_taxed = price_nontaxed * (tax / 100); // Get the tax amount
				price_taxed = price_nontaxed + price_taxed; // Get total amount
				
				//printf("amount: %lf", price_nontaxed);
				printf("Total cost including tax is $%.2lf\n", price_taxed);
			
			}
			else if (usage_water > 1500) {

				price_nontaxed = price_resi_fixed + (700 * price_resi_1); // Fixed price and class 1
				price_nontaxed = price_nontaxed + (800 * price_resi_2); // Price class 2
				
				usage_water = usage_water - 1500; // How much is exceeding 1500
				price_nontaxed = price_nontaxed + (usage_water * price_resi_3); // Price class 3
				
				price_taxed = price_nontaxed * (tax / 100); // Tax
				price_taxed = price_nontaxed + price_taxed; // Taxed
				
				//printf("amount: %lf", price_nontaxed);
				printf("Total cost including tax is $%.2lf\n", price_taxed);
				
			}
			break;
	
	
		case 'B' :
		case 'b' :
						
			price_nontaxed = price_commercial_fixed + (usage_water * price_commercial);
			
			price_taxed = price_nontaxed * (tax / 100);
			price_taxed = price_nontaxed + price_taxed;
			
			printf("Total cost including tax is $%.2lf\n", price_taxed);
			break;
	
		default :
	
			printf("Wrong User Type\n");
	
	}


return 0;

}
