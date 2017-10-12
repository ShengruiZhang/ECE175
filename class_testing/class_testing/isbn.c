#define _CRT_SECRUE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	unsigned int i = 0;
	unsigned int isbn[13];

	unsigned int sum = 0;

	printf("Type");

	for (i = 0; i < 13; ++i) {
		scanf("%d", &isbn[i]);
	}

	for (i = 0; i < 12; i = i + 2) {
		sum = sum + isbn[i];
	}

	for (i = i; i < 12; i = i + 2) {
		sum = sum + isbn[i] * 3;
	}

	sum = sum % 10;

	sum = 10 - sum;

	printf("%d\t%d", sum, isbn[12]);

	return 0;
}