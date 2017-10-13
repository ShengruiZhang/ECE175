#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int i = 0;

	for (i = 0; i < 10; i++) {
		printf("%d\n", i);
	}

	printf("\n");

	for (i = 0; i < 10; ++i) {
		printf("%d\n", i);
	}

	return 0;
}