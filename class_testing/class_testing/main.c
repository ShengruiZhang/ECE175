#define _CRT_SECRUE_NO_WARNINGS

#include <stdio.h>

void swap(int* a, int* b) {
	int swap;
	swap = *a;
	*a = *b;
	*b = swap;
}

int main(void) {
	int temp = 0;
	int x = 0;
	int y = 0;
	x = 134;
	y = 298;
	swap(&x, &y);
	printf("%d %d\n", x, y);
	
	return 0;
}