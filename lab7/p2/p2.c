/*
Author: Shengrui Zhang
Student ID: 23426900
Email: shengruizhang@email.arizona.edu
Created Date: 10/19/17
*/

// LAB 7 NUMBER PAD FROM LETTER TO DIGITS

/*///////////////////////////////////// PROBLEM TWO /////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS

typedef unsigned char uchar;
typedef unsigned int uint;

#include <stdio.h>
#include <string.h>

void getword(uchar word[])
{
	uchar ini[50];
	
	while (strlen(ini) != 7)
	{
		printf("Enter a 7-character word: ");
		gets(ini);
		if (strlen(ini) != 7) {
			printf("Enter ONLY 7 characters\n");
		}
	}
	//printf("Length: %d\n", strlen(ini));
	
	for (int i = 0; i < 7; ++i)
	{
		if (ini[i] >= 48 && ini[i] <= 57)      // check for numbers
		{
			word[i] = ini[i];
		}
		else if (ini[i] >= 97 && ini[i] <= 122) // chcek for lowers
		{
			word[i] = ini[i];
		}
		else if (ini[i] >= 65 && ini[i] <= 90) // chcek for caps
		{
			word[i] = ini[i];
		}
		else
		{
			printf("symbol cannon be used as a phone number\n");
			break;
		}
	}
}


int main(void)
{
	uchar input[8];
	uchar quit = 'y';
	
	while (quit != 'n' && quit != 'N') // enter N or n to quit
	{
		quit = '\0';
		strcpy(input, "\0");
		getword(input);
		
		if (input != NULL)
		{
			for (int i = 0; i < 7; ++i)
			{
				if (input[i] >= 97 || input[i] <= 122 || input[i] >= 65 || input[i] <= 90)
				{
					
				}
				else
				{
					printf("Error\n");
				}
			}
		}
		
		printf("Do you want to continue (y/n)? ");
		scanf("%c", &quit);
	}
	
	return 0;
}