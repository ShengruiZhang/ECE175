/*
Author: Shengrui Zhang
Student ID: 23426900
Email: shengruizhang@email.arizona.edu
Created Date: 10/26/17
*/
/*/////////////////////////// HOMEWORK 8 PROBLEM ONE ////////////////////*/
/* Input: A string user wants to find within a file; a file to be searched
   Output: The line the matched word is found and PRINT that whole line, how many times that word is appeared in the file.
*/
#define _CRT_SECURE_NO_WARNINGS
typedef unsigned char uchar;
typedef unsigned int uint;
#define LEN 75
#include <stdio.h>
#include <string.h>
char *gets(char *str);
int main(void)
{
	FILE *file_text;
	uchar *tar;
	uchar text[LEN];
	uchar text_temp[LEN];
	uchar file_name[LEN];
	uchar tar_str[LEN];
	uint lines = 1;  // line counter
	uint counter = 0;
	int temp = 0;
	printf("Enter a file name: ");
	gets(file_name);
	file_text = fopen(file_name, "r");
	printf("Enter in the search string: ");
	gets(tar_str);
	while (feof(file_text) == 0) // check for EOF
	{
		fgets(text, LEN, file_text); // put a line into the string
		temp = -1;
		strcpy(text_temp, text);
		while ((tar = strstr(text, tar_str)) != NULL)
		{
			tar = tar + strlen(tar_str);     // skip to next word
			strcpy(text, tar);  // update
			++counter;       // update counter
			temp = counter;
		}
		if (temp == counter)
		{
			printf("Found %s on line %d: ", tar_str, lines);
			printf("%s", text_temp);
		}
		++lines;
	}
	printf("\n");
	printf("The string: \"%s\" ", tar_str);
	printf("was found a total of %d times in the file: %s", counter, file_name);
	printf("\n");
	fclose(file_text);
	return 0;
}