#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

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
	char c[21];
	char d;
	char e[10];
	//
	//fgets(d, 5, stdin);
	if (stdin == '\0')
	{
		printf("nothing\n");
	}
	else {
		fgets(c, 6, stdin);
		while ((d = getchar()) != '\n' && d != EOF)
		{
			/*if (d == EOF) {
				break;
			}*/
		}
	}
	fgets(e, 5, stdin);
	printf("non 0: %s\n", e);
	return 0;
}