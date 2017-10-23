/*
Author: Shengrui Zhang
Student ID: 23426900
Email: shengruizhang@email.arizona.edu
Created Date: 10/15/17
*/

/*////////////////////////////////////// PROBLEM ONE /////////////////////////////////////*/
/*
Inputs:
a series of IMEI numbers

Outputs:
validity of IMEI

Problems: fix a scrambled file and  find the largest four sequence digits
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_IMEI(int IMEI[]);
void calc_sum(int IMEI[], int *sum_14digits);


/*////////////////////////////////// MAIN FUNCTION //////////////////////////*/

int main(void) {
	FILE *imei;
	imei = fopen("List_IMEI.txt", "r");

	int idf[15] = {0};
	
	int sum14 = 0;
	
	unsigned int i = 0;

	unsigned int v = 0;
	
	if (imei != NULL) 
	{
		while (fscanf(imei, "%d", &idf[i]) != EOF)
		{
			if (i == 14) 
			{
				sum14 = 0;
				print_IMEI(idf);
				calc_sum(idf, &sum14);
				printf("total sum of 14 digits = %d\n", sum14);
				printf("Luhn digit = %d\n", idf[14]);

				if (sum14 - ((sum14 / 10) * 10) != 0) {
					printf("check digit = %d\n", sum14 = 10 - (sum14 - ((sum14 / 10) * 10)));
					if (idf[14] == (sum14 - (sum14 / 10) * 10)) {
						printf("IMEI is valid\n");
					}
					else {
						printf("IMEI is invalid\n");
					}
				}
				else {
					printf("check digit = 0\n");
					if (idf[14] == 0) {
						printf("IMEI is valid\n");
					}
					else {
						printf("IMEI is invalid\n");
					}
				}
				printf("\n");
				i = 0;
			}
			else {
				++i;
			}
		}
	}
	
	fclose(imei);	
	return 0;
}


/*///////////////////////////////////////// PRINTING IMEI /////////////////////////////*/

void print_IMEI(int IMEI[]) {
	unsigned int n = 0;
	printf("IMEI: ");
	for (n = 0; n < 15; ++n) {
		printf("%d", IMEI[n]);
	}
	printf("\n");
}


/*///////////////////// CALCULATING ////////////////////////////////*/

void calc_sum(int IMEI[], int *sum_14digits) {
	unsigned a = 0;
	for (a = 1; a <= 13; a +=2) {
		IMEI[a] *= 2;
	}

	for (a = 1; a <= 13; a += 2) {
		if (IMEI[a] >= 10) {
			IMEI[a] = 1 + (IMEI[a] - 10);
		}
	}

	for (a = 0; a < 14; ++a) {
		*sum_14digits += IMEI[a];
	}
}