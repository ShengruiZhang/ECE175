#include <stdio.h>

int main(void) {
	
	FILE *inp;
	
	int num;

	inp = fopen("***.txt", "r");
	
	if (inp == NULL) {
		
		printf("no text file found\n");
	}
	
	fscanf(inp, "%d", &num);

	return 0;
}