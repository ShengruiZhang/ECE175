#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main(void) {
	int num = 0;
	int value = 0;
	printf("Enter a number: ");
	scanf(" %d", &num);
	
	int i, q, a;
	a = num;
	for(i = 0; i <= num; i++) {
		for (q = 0; q < (a + 1); q++) {
			printf("%d", value);
		}

		printf("\n");
		a--;
		value += 1;
	}
	
	return 0;
}