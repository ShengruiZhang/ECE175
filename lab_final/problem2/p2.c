/*
Student Name: Shengrui Zhang
Date Created: 11/16/17
Email: shengruizhang@email.arizona.edu
Student ID: 23426900
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define SIZE 9

void readdata(int A[][SIZE], FILE *inp);

void select(int inp[][SIZE], int outp[][SIZE]);


int main(void)
{
	FILE *raw = NULL;
	
	unsigned int input[SIZE][SIZE];
	unsigned int output[SIZE][SIZE];
	
	readdata(input, raw);
	
	
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			output[i][j] = input[i][j];
			//printf("%d ", output[i][j]);
		}
		//printf("\n");
	}

	select(input, output);

	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			//output[i][j] = input[i][j];
			printf("%d ", output[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void readdata(int A[][SIZE], FILE *inp)
{
	// THE FILE TO BE READ
	inp = fopen("mid2data1.txt", "r");
	
	for (int a = 0; a < SIZE; ++a)
	{
		for (int b = 0; b < SIZE; ++b)
		{
			fscanf(inp, "%d", &A[a][b]);
		}
	}	
}


void select(int inp[][SIZE], int outp[][SIZE])
{
	
	int inter = 0;
	unsigned int r = 0;
	unsigned int c = 0;
	
	unsigned int f = 0;
	int b = 3;
	int h = 3;
	
	unsigned int e[4] = {0, 0 ,0 ,0};
	int max = 0;
	int max_2 = 0;
	
	for (r = 0; r < 7; ++r)
	{
		for (c = 0; c < 7; ++c)
		{
			//max = inp[r][c] + inp[r][c + 2] + inp[r + 2][c] + inp[r + 2][c + 2];
			e[0] = inp[r][c];
			max = inp[r][c];
			e[1] = inp[r][c + 2];
			e[2] = inp[r + 2][c];
			e[3] = inp[r + 2][c + 2];
			h = 0;
			max_2 = 0;
			outp[r + 1][c + 1] = 0;
			for (f = 0; f < 3; ++f)
			{
				//max = e[f];
				for (b = 3; b > h; --b)
				{
					//max = e[f];
					//while (b >= 0)
					//{
					if (e[b] > e[f])
					{
						max_2 = e[b];

						//printf("%d\n", outp[r + 1][c + 1]);
					}
					//}
					if (max_2 > max) {
						//max = max_2;
						outp[r + 1][c + 1] = max_2;
						max = max_2;
					}
					else
					{
						outp[r + 1][c + 1] = max;
					}
					if (max_2 > outp[r + 1][c + 1]) {
						outp[r + 1][c + 1] = max_2;
					}
					inter = outp[r + 1][c + 1];
				}
				
				++h;
			}



			
			
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}