/*
Author: Shengrui Zhang
Student ID: 23426900
Email: shengruizhang@email.arizona.edu
Created Date: 10/19/17
*/

// LAB 7 FINDING STRINGS

/*///////////////////////////////////// PROBLEM ONE /////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS

typedef unsigned char uchar;
typedef unsigned int uint;

#include <stdio.h>
#include <string.h>

int main(void)
{
	uchar ori_str[50];
	uchar tar_str[50];

	char *ret;
	
	uint counter = 0;
	uint address = 0;
	
	printf("Enter a long string: ");
	gets(ori_str);
	
	printf("Enter a short string: ");
	gets(tar_str);
	
	while ((ret = strstr(ori_str, tar_str)) != NULL)
	{
		//printf("%s\n", ret);                    // print the case
		printf("Found %s at location %d\n", tar_str, ret - ori_str + address + 1);
		address = ret - ori_str;
		ret = ret + strlen(tar_str);     // skip to next word
		strcpy(ori_str, ret);  // update
		++counter;       // update counter
	}
	
	if (counter != 0)
	{
		printf("%s occurs %d times\n", tar_str, counter);
	}
	else {
		printf("No %s found\n", tar_str);
	}

	/* ////////////////////////// testing
	ret = strstr(ori_str, tar_str);          // find the first occurrance of tar string
	
	printf("%s\n", ret);                     // print the string from that on
	printf("%c\n", *ret);                    // print the letter
	printf("%d\n", ret);                     // print what?
	
	ret = ret + strlen(tar_str);             // skip to next occurrance
	strcpy(ori_str, ret);                    // update the array

	ret = strstr(ori_str, tar_str);
	printf("%s\n", ori_str);
	printf("%c\n", *ret);
	printf("%d\n", ret);                     // print the letter
	*/
	/*
	printf("%s\n", ori_str); // print the originl
	ret = strstr(ori_str, tar_str); // relocate
	printf("%s\n", ret); // print from that on
	printf("%d\n", ori_str); // print the index of the first letter
	printf("%d\n", ret); // print the frist letter of the string?
	*/
	return 0;
}