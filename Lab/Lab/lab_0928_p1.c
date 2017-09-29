#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


/*///////////////////////////////////////////////////////////////////////////////////////*/

void distconversion(int inches, int *yard, int *feet, int *inch) {
	int r = 0;
	*yard = inches / 36; // get yards
	r = inches % 36; // get the remainder
	*feet = r / 12; // get inches
	*inch = r % 12; // get the remaining inch
	
	//////////PRINTING//////////////
	if (*yard != 0 && *feet != 0 && *inch != 0) {
		printf("Length: ");
	}
	if (*yard != 0) {       // deal with yard
		if (*yard == 1) {
			printf("1 yard ");
		}
		else if (*yard >= 1) {
			printf("%d yards ", *yard);
		}
	}
	
	if (*feet != 0) {       // deal with feet
		if (*feet == 1) {
			printf("1 foot ");
		}
		else if (*feet >= 1) {
			printf("%d feet ", *feet);
		}
	}
	
	if (*inch != 0) {       // deal with inch
		if (*inch == 1) {
			printf("1 inch");
		}
		else if (*inch >= 1) {
			printf("%d inches", *inch);
		}
	}
	printf("\n");
	
}






int main(void) {
	
	FILE *input;
	int dist = 0;
	
	int a0 = 0, a = 0, b = 0, c = 0;
	
	input = fopen("dist.txt", "r");
	
	if (input != NULL) 	{
		while (fscanf(input, "%d", &a0) != EOF) {
			printf("%d\t", a0);
			distconversion(a0, &a, &b, &c);
		}
	}
	else {
		printf("No file found\n");
	}
	
	return 0;
}