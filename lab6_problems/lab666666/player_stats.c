/*
Author: Shengrui Zhang
Student ID: 23426900
Email: shengruizhang@email.arizona.edu
Created Date: 10/19/17
*/

// LAB 6, PLAYER STATS
/*////////////////////////////////////// PROBLEM ONE /////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

#define NUM_ROW 6
#define NUM_COl 8

/*/////////////////////// READING /////////////////////*/

void read_ar(FILE *in, int x[][NUM_COl]) {
	for (int r = 0; r < NUM_ROW; ++r) {
		for (int c = 0; c < NUM_COl; ++c) {
			fscanf(in, "%d", &x[r][c]);
		}
	}
}


/*////////////////// MAIN FUNCTION //////////////////*/

int main(void)
{
	FILE *fp = fopen("stats.txt", "r");

	int data[NUM_ROW][NUM_COl];

	read_ar(fp, data);

	//for (int i = 0; i < NUM_ROW; ++i) {
	//	for (int j = 0; j < NUM_COl; ++j) {
	//		printf("%d ", data[i][j]);
	//	}

	//	printf("\n");
	//}

	int num;
	double avg = 0;
	double max = 0;

	for (int i = 0; i < NUM_ROW; ++i) {
		avg = 0;
		for (int j = 0; j < NUM_COl; ++j) {
			avg = avg + data[i][j];
		}
		avg = avg / NUM_COl;
		if (avg > max) {
			max = avg;
			num = i + 1;
		}
	}

	printf("Player %d has a max average of %.4lf\n", num, max);
	
	num = 0;
	max = 0;
	
	for (int i = 0; i < NUM_COl; ++i) {
		avg = 0;
		for (int j = 0; j < NUM_ROW; ++j) {
			avg += data[j][i];
		}
		avg = avg / NUM_ROW;
		if (avg > max) {
			max = avg;
			num = i + 1;
		}
	}
	
	printf("Match number %d has a max average of %.4lf\n", num, max);
	
	
	fclose(fp);
	return 0;
}