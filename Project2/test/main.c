#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	/*
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
	*/

	char buffer[3];
	int a = 5;

	snprintf(buffer, 3, "%d", a);

	// if (cx>=0 && cx<100)      // check returned value

	// snprintf ( buffer+cx, 100-cx, ", and the half of that is %d.", 60/2/2 );

	puts(buffer);
	a = 10;
	snprintf(buffer, 3, "%d", a);

	puts(buffer);
	return 0;
}