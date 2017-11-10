#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct node_s {
	int value;
	struct node_s *next;
} node;

void print_list(node *pt)
{
	while (pt != NULL)
	{
		if (pt->value >= 3 && pt->value <= 7) {
			printf("%d\n", pt->value);
		}
		pt = pt->next;
	}
}
int main(void)
{
	/*
	int n = 9;
	int *p;
	p = &n;      // make p points to n;
	*p = 2;          // set the value that p points to to 2
	//printf("%d\n", n);      // print the value of n
	printf("%lf\n", &n);    // address of n
	//printf("%d\n", &p);    // address of p
	//printf("%d\n", *p);      // value of point n (value of n)
	printf("%d\n", p);      // address n
	printf("\n");
	*/
	node *headp = NULL;
	node *temp;
	node *tail = NULL;
	unsigned int i = 0;

	for (i = 0; i < 10; ++i)
	{
		temp = (node*)malloc(sizeof(node));
		temp->value = i;
		if (headp == NULL) {
			headp = temp;
		}
		else {
			tail->next = temp;
		}
		tail = temp;
		tail->next = NULL;
	}
	/*printf("%d ", headp->value);
	printf("%d ", headp->next->next->value);
	printf("%d ", tail->value);
	*/
	print_list(headp);



	printf("\n");
	return 0;
}