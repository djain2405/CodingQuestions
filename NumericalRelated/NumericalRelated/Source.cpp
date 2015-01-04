#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include <stdio.h>

int findBase(char* str)
{
	int length = strlen(str);
	int i = 0;
	int maximum = 0;
	for(i = 0; i < length; i++)
	{
		int value = str[i] - '0';
		if(!(value >= 0 && value <= 9))
		{
			switch(str[i])
			{
			case 'A' : value = 10;
				break;
			case 'B' : value = 11;
				break;
			case 'C' : value = 12;
				break;
			case 'D' : value = 13;
				break;
			case 'E' : value = 14;
				break;
			case 'F' : value = 15;
				break;
			}
		}
		//printf("Values %d\n", str[i]);
		if((value) > maximum)
		{
			maximum = value;
		}
	}

	printf("Base %d\n", maximum+1);
	return (maximum+1);
}

int convertNum(char* str, int base)
{
	int sum = 0;
	int i = 0;
	int length = strlen(str);
	int j = length - 1;

	for(i = 0; i < length; i++)
	{
		int value = str[j] - '0';
		if(!(value >= 0 && value <= 9))
		{
			switch(str[j])
			{
			case 'A' : value = 10;
				break;
			case 'B' : value = 11;
				break;
			case 'C' : value = 12;
				break;
			case 'D' : value = 13;
				break;
			case 'E' : value = 14;
				break;
			case 'F' : value = 15;
				break;
			}
		}
		printf("Value %d\n", value);
		printf("i and base value %d %d %d\n", i, base, base^i);
		sum += (pow(base,i)*value);
		printf("Sum value %d\n", sum);
		j--;
	}

	printf("Sum %d\n", sum);
	return sum;

}
int main()
{

	char* num1 = NULL;
	char* num2 = NULL;
	int base1 = 0;
	int base2 = 0;
	num1 = (char*) malloc(sizeof(char)*10);
	num2 = (char*) malloc(sizeof(char)*10);
	int sum1 = 0;
	int sum2 = 0;

	//printf("Enter two numbers \n");
	scanf("%s", num1);
	scanf("%s", num2);

	num1 = (char*) realloc(num1, strlen(num1)+1);
	num2 = (char*) realloc(num2, strlen(num2)+1);

	printf("%s %s\n", num1, num2);
	
	base1 = findBase(num1);
	base2 = findBase(num2);

	sum1 = convertNum(num1, base1);
	sum2 = convertNum(num2, base2);

	printf("%d", sum1+sum2);

	_getch();
	return 0;
}