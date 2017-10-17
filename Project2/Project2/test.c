#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	const double carbon = 12.01;
	const double hydrogon = 1.008;
	const double oxygen = 16.00;
	const double nitrogen = 14.01;

	int n = 0;          // number of formula

	int number = 1;

	int a = 0;

	printf("Type the number of formulas:");
	scanf(" %d", &n);

	int i = 0;

	int h = 0;

	char formula[90] = "";
	double mw[10] = { 0 };

	for (i = 0; i < n; ++i) {
		printf("Enter the molecular formula:");
		scanf("%s", &formula);

		while (formula[i] != '\0') {
			if (formula[i] == 'C') {
				a = carbon;
			}
			if (formula[i] == 'H') {
				a = hydrogon;
			}
			if (formula[i] == 'O') {
				a = oxygen;
			}
			if (formula[i] == 'N') {
				a = nitrogen;
			}
			if (formula[i] >= '0' && formula[i] <= '9') {             // check if the current char is a number
				if (formula[i + 1] >= 48 && formula[i + 1] <=57) {   // check for the nect char
					number = (formula[i]-'0') * 10 + (formula[i + 1]-'0');
					mw[h] += a * number;
				}
				else {
					number = formula[i] - '0';
					mw[h] += a * number;
				}
				++h;
			}
			else {
				mw[h] += a * number;
			}

			++i;
		}

		printf("%.3lf\n", mw[0]);

	}

	return 0;
}