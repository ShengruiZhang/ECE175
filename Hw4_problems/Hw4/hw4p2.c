// Author: SHENGRUI ZHANG
// Created Date: 9/23/17

// ECE 175
// Homework 4 Problem 2

/* This program takes the user input of the gas, quantity, temp, initial volume, final volume, of a gas for a user-given increment to calculate the gas pressure within the user-defined range of volume 

Inputs: GAS NUMBER; QUANTITY; TEMP; INITIAL VOLUME, FINAL VOLUME; VOLUME INCREMENT;
		
Outputs: GAS PRESSURE
*/	

/* Two user defined functions are required

void ,pr, int _list(void)

&

double pressure_cal(int gas_type, double T, double V, double n)
(practice to use pointer)
*/

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

/*/////////// DEFINE THE FUNCTION TO PRINT THE LIST//////////*/

void print_list(void) {
	printf("Number\tGas Type\n");
	printf("1\tHelium\n");
	printf("2\tHydrogen\n");
	printf("3\tOxygen\n");
	printf("4\tChlorine\n");
	printf("5\tCarbon dioxide\n");
	return;
}



/*////////////////////// DEFINE THE FUNCTION TO TAKE USER INPUT////////////*/

void input_gas_number(unsigned int* gas) {
	
	while (*gas != 1 && *gas != 2 && *gas != 3 && *gas != 4 && *gas != 5) {
	printf("Enter Gas number (1,2,3,4 or 5)>>");
	scanf(" %d", &*gas);	
	}
    
	//switch (*gas)
	//{
	//	case (1):                //  He
	//	*value_a = 0.0341;
	//	*value_b = 0.0237;
	//	break;
	//	
	//	case (2):                  // H2
	//	*value_a = 0.244;
	//	*value_b = 0.0266;
	//	break;
	//	
	//	case (3):								// O2
	//	*value_a = 1.36;
	//	*value_b = 0.0318;
	//	break;
	//	
	//	case (4):						 // Cl2
	//	*value_a = 6.49;
	//	*value_b = 0.0562;
	//	break;
	//	
	//	case (5):										// CO2
	//	*value_a = 3.59;
	//	*value_b = 0.0427;
	//	break;
	//	
	//	default:
	//	break;
	//}
}



/*//////////////////////////// DEFINE THE FUNCTION TO CALCULATE THE VOLUME////////////////*/

double pressure_cal(int type, double temp, double volume, double quan) {
	double pressure = 0;
	double value_a, value_b; // a b value
	double R = 0.08206; // gas constant
	switch (type)
	{
		case (1): //            He
		value_a = 0.0341;
		value_b = 0.0237;
		break;
		
		case (2): // H2
		value_a = 0.244;
		value_b = 0.0266;
		break;
		
		case (3): // O2
		value_a = 1.36;
		value_b = 0.0318;
		break;
		
		case (4):  // Cl2
		value_a = 6.49;
		value_b = 0.0562;
		break;
		
		case (5): // CO2
		value_a = 3.59;
		value_b = 0.0427;
		break;
		
		default:
		break;
	}
	pressure = ( R * temp) / (  (volume / quan) - value_b  ); 
	pressure = pressure - ( value_a / pow( (volume / quan), 2)   );
	
	return(pressure);
}

/*////////////// MAIN FUNCTION////////////*/

int main(void) {
	unsigned char quit = '?';

	while (quit != 'n') {

		unsigned int num_gas = 0; // gas number

		//double a, b; // something funny

		print_list(); // print table

		input_gas_number(&num_gas);                        // Get the gas number

		//printf("%d\n", num_gas); // Test
		//printf("%.4lf\n", a); // Test
		//printf("%6lf\n", b); // Test

		double p; // pressure
		double v0, v; // initial and current volume
		double r; // gas constant
		double t; // abs-temp
		double n; // quantity of gas

		double step = 0; // volume increment

		printf("Enter Quantity of gas (in moles)>>");
		scanf(" %lf", &n);

		printf("Enter temperature (in Kelvin)>>");
		scanf(" %lf", &t);

		printf("Enter initial volume (in liters)>>");
		scanf(" %lf", &v0);

		printf("Enter final volume (in liters)>>");
		scanf(" %lf", &v);

		printf("Enter volume increment (in liters)>>");
		scanf(" %lf", &step);

		printf("\n"); // new line
		/*//////////////////////////////END INPUT//////////////////////////////////////////////*/





		/*//////////////////////////LOOPING/////////////////////////////*/

		printf("Volume (liters)\tPressure(atm)\n");

		do
		{
			//printf("%.3lf", v0); // testing printing the initial volume

			p = pressure_cal(num_gas, t, v0, n);

			printf("%.3lf\t%.4lf\n", v0, p);

			v0 = v0 + step; // update volume
		} while (v0 - v < 0.000001);

		printf("Do you want to continue (y or n)?");
		scanf(" %c", &quit);

	}
	return 0;
}