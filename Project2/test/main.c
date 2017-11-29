#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

int rand_num(int low, int high)
{
	if (low == 0) {
		return rand() % ++high;                                              // INCREASE ONE SO THAT IT CAN RETURN HIGH
	}
	else if (low > 0) {
		return rand() % ++high + low;
	}
	else {
		return 1;
	}
}

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
	char str[10];
	while (1)
	{
		if (fgets(str, 5, stdin))
		{
			printf("%d\n", rand_num(0, 2));
		}
	}
	return 0;
}