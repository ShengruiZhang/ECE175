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
#include <ctype.h>
#include <conio.h>

// DEFINE MARCORS

#define SIZE_STR 100

int main(void)
{
	// DECLARATION
	
	unsigned char str[SIZE_STR];
	
	unsigned char str_new[SIZE_STR];
	
	memset(str_new,'\0', SIZE_STR);
	memset(str, '\0', SIZE_STR);
	
	unsigned int temp = 0;

	unsigned int i = 0;
	int a = 0;

	char cr[3] = " ";
	
	// MAIN
	printf("Enter data stream: \n");
	
	fgets(str, SIZE_STR, stdin);
	
	str[strlen(str) - 1] = 0;
	
	// puts(str); TESTING
	
	while (str[i] != 0)
	{
		for (i; i < strlen(str); ++i)
		{
			if (str[i + 1] == str[i])
			{
				temp++;
				// printf("%c\t%c\n", str[i + 1], str[i]);
			}
			else{
					if (temp != 0)
					{
						snprintf(cr, 3, "%d", temp + 1);
						str_new[a] = cr[0];
						if (temp >= 10) {
							++a;
							str_new[a] = cr[1];
							++a;
						}
						else {
							++a;
						}
						
						str_new[a] = str[i];
						temp = 0;
						++a;
					}
					else
					{
						str_new[a] = str[i];
						++a;
					}
			}
		}
	}
	printf("Compressed stream: %s\n", str_new);
	return 0;
}
