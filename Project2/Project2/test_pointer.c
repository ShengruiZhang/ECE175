#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n = 9;
	int *p;
	p = &n;      // make p points to n;
	*p = 2;          // set the value that p points to to 2
	//printf("%d\n", n);      // print the value of n
	printf("%d\n", &n);    // address of n
	//printf("%d\n", &p);    // address of p
	//printf("%d\n", *p);      // value of point n (value of n)
	printf("%d\n", p);      // address n
	printf("\n");

	int col[5];
	col[4] = 0;
	printf("%d\n", col[4]);
	printf("%d\n", col[1555]);




	printf("\n");
	return 0;
}