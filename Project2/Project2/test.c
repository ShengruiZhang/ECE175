#define _CRT_SECRUE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	
	unsigned int a = 5;

	int *p;

	printf("%d", a);    //// nothing means the value of a variable

	printf("%d", &a);  ///////////// & means the address of something
	printf("\n");

	return 0;
}