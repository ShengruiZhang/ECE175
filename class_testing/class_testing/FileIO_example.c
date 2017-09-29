#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	FILE *inp;

	FILE *outp;

	int num;
	int sum = 0;
	unsigned int counter = 0;
	double avg = 0;
	inp = fopen("data.txt", "r");
	outp = fopen("output.txt", "w");


	if (inp == NULL) {
		printf("no file found \n");
	}
	else {
		while (fscanf(inp, "%d ", &num) != EOF) {

			//fscanf(inp, "%d", &num);
			fprintf(outp, "%d ", num);
			printf("%d ", num);
			sum = sum + num;
			counter++;
		}
			printf("\n%d", sum);
			printf("\n%.4lf", avg = sum / counter);
			fprintf(outp, "\ntotal sum is %d\n", sum);
			fprintf(outp, "counter: %d\n", counter);
			fprintf(outp, "the average is: %d", avg = sum / counter);

	}
	fclose(inp);
	printf("\n");

	return 0;
}