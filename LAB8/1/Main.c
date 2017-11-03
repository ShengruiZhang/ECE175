/*
Author: Shengrui Zhang
Student ID: 23426900
Email: shengruizhang@email.arizona.edu
Created Date: 11/02/17
*/

// LAB 8 DEALING WITH DATA

/*///////////////////////////////////// PROBLEM ONE /////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>

typedef unsigned char uchar;
typedef unsigned int uint;

typedef struct state {
	uchar State_Name[20];
	double Total_Area;
	double Water_Area;
	double Land_Area;
	uint Population;
	uint Population_per_Land;
} State;

void scan_states(State *x, FILE *in);
void print_states(State x[]);
void swap(State *a, State *b);
void selection(State x[], int size);

int main(void)
{
	FILE *data;	
	State status[10];
	uint i = 0;
	data = fopen("state_data.txt", "r");
	for (i = 0; i < 10; ++i) {
		scan_states(&status[i], data);
		// printf("%s\t %d\t %.2lf\t %.2lf\n", status[i].State_Name, status[i].Population, status[i].Total_Area, status[i].Water_Area); // FOR TESTING
	}
	for (i = 0; i < 10; ++i)
	{
		status[i].Land_Area = status[i].Total_Area - status[i].Water_Area;
		status[i].Population_per_Land = status[i].Population / status[i].Land_Area;
	}
	selection(status, 10);
	print_states(status);
	fclose(data);
	return 0;
}

void scan_states(State *x, FILE *in)
{
	if (in != NULL)
	{
		fscanf(in, "%s", &(*x). State_Name);
		fscanf(in, "%d", &(*x).Population);
		fscanf(in, "%lf", &(*x).Total_Area);
		fscanf(in, "%lf", &(*x).Water_Area);
	}
	else {
		printf("Error when reading file.\n");
	}
}

void print_states(State y[])
{
	for (int i = 0; i < 10; ++i) {
		printf("%s has %d people per square mile of dry land\n", y[i].State_Name, y[i].Population_per_Land);
	}
}

void swap(State *a, State *b)
{
	State t;
	t = *a;
	*a = *b;
	*b = t;
	
}

void selection(State x[], int size)
{	
	int i, j;
	int min;
	for (i = 0; i < size; ++i) {
		min = i; // STARTS FROM 0
		for (j = i; j < size; ++j) {
			if (x[j].Population_per_Land > x[min].Population_per_Land) {
				min = j;
			}
		}
		swap(&x[min], &x[i]);
	}
}