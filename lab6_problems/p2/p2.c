/*
Author: Shengrui Zhang
Student ID: 23426900
Email: shengruizhang@email.arizona.edu
Created Date: 10/19/17
*/

// LAB 6, Four in a Diagonal Line
/*///////////////////////////////////// PROBLEM TWO /////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void read_mat(FILE *in, int x[][7]) {
	for (int r = 0; r < 6; ++r) {
		for (int c = 0; c < 7; ++c) {
			fscanf(in, "%d", &x[r][c]);
		}
	}
}


int CheckDiagonals (int x[][7], int TestInt) {
	int res = 0;
	int inter=0;
	int c = 0;
	
	for (int r = 0; r < 6; ++r) {
		for (int c = 0; c < 7; ++c) {
			if (x[r][c] == TestInt && x[r+1][c+1] == TestInt && x[r+2][c+2] == TestInt && x[r+3][c+3] == TestInt) {
				res = 1;
			}
		}
	}
	return(res);
}


////////////////////////////////// MAIN FUNCTION ////////////////////////////////////

int main(void) {
	FILE *ip = fopen("test_diagonals.txt", "r");
	
	int mrtx[6][7];
	
	int ret = -1;
	
	read_mat(ip, mrtx);
	
	ret = CheckDiagonals(mrtx, 1);
	
	if (ret == 1) {
		printf("At least one diagonal of four 1's exists in the matrix\n");
	}
	else {
		printf("No diagonals found in the matrix");
	}
	
	ret = -1;
	
	ret = CheckDiagonals(mrtx, 2);
	
	if (ret == 1) {
		printf("At least one diagonal of four 2's exists in the matrix\n");
	}
	else {
		printf("No diagonals found in the matrix");
	}
	
	return 0;
}