#define _CRT_SECRUE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef unsigned int uint;
typedef unsigned char uchar;

typedef struct node_s {
	uchar team[20];
	uint rank;
	struct node_s *next;
} node;

int main(void)
{
	node *head;
	node *temp;
	node *tail;
	uchar data[21];
	uchar command[11];
	
	printf("F1 Cars data\n");
	
	if (fgets)
	printf("Enter the team and data\n");
	gets(data);
	sscanf(data, "%s %d", temp.team, &temp.rank);
}