#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *input = fopen("1.txt", "r");
	//char test[5];
	int a,b,c;

	fscanf(input, "%d\n", &a);
	printf("Ship size: %d \n", a);
	fscanf(input, "%d\n", &a);
	printf("Ship size: %d \n", a);

	//fgets(test, 2, input);
	//fgets(test, 5, input);
	fscanf(input, "%d %d %d", &a, &b, &c);
	printf("%d %d %d\n", a, b, c);

	return 0;
}