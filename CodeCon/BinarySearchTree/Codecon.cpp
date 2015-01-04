#define _CRT_SECURE_NO_WARNINGS
//Problem        : Base Arithmetic
//Language       : C
//Compiled Using : GCC
//Version        : GCC 4.8.2
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <stdio.h>
#include <iostream>
#include <conio.h>

/*
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

	//printf("Base %d\n", maximum+1);
	return (maximum+1);
}

double convertNum(char* str, int base)
{
	double sum = 0;
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
		//printf("Value %d\n", value);
		//printf("i and base value %d %d %d\n", i, base, pow(base, i));
		sum += (double)(pow(base,i)*value);
		//printf("Sum value %g\n", sum);
		j--;
	}

	//printf("Sum %d\n", sum);
	return sum;

}

int main() {

	char* num1 = NULL;
	char* num2 = NULL;
	int base1 = 0;
	int base2 = 0;
	num1 = (char*) malloc(sizeof(char)*10);
	num2 = (char*) malloc(sizeof(char)*10);
	double sum1 = 0;
	double sum2 = 0;
	double sum = 0;

	//printf("Enter two numbers \n");
	scanf("%s", num1);
	scanf("%s", num2);

	num1 = (char*) realloc(num1, strlen(num1)+1);
	num2 = (char*) realloc(num2, strlen(num2)+1);

	//printf("%s %s\n", num1, num2);
	
	base1 = findBase(num1);
	base2 = findBase(num2);

	sum1 = convertNum(num1, base1);
	sum2 = convertNum(num2, base2);
	sum = sum1 + sum2;
	printf("%.0f", sum);

	_getch();
    return 0;
}
*/

float giveResult(char* temp)
{
		int len = 0;
		int i = 0;
		float result = 0.0f;
		int dotpos = 0;
		//printf("%s\n", temp );
		len = strlen(temp);
		
		for(i = 0; i < len; i++)
		{
			if(temp[i] == '.')
			{
				dotpos = len - i - 1;
			}
			else
			{
				result = result*(10.0f) + (temp[i] - '0');
			}
		}
		while(dotpos--)
		{
			result /= 10.0f;
		}

		return result;
}
int main()
{
	char dataset[100][20] = {0};
	int MinDataSet[100] = {0};
	int k = 0;
	char* temp = NULL;
	
	float value = 0.0;
	//printf("Enter k\n");
	scanf("%d\n", &k);
	int i = 0;
	
	for (i = 0; i < (k*2); i++)
	{
		scanf("%s", dataset[i]);
	}
	for(i = 0; i < (k); i++)
	{
		float result1 = 0.0f;
		float result2 = 0.0f;
		float difference = 0.0f;
		float minimum = 100.0f;
		int minIndex = 0;
		float sum1 = 0;
		
		char* copy1 = (char*) malloc(sizeof(char)*(20));
		strcpy(copy1, dataset[i]);
		copy1 = (char*) realloc(copy1, strlen(copy1)+1);
			//printf("String after copying %s\n", copy1);
		 temp = strtok(dataset[i], ",");
		 while( temp != NULL ) 
		 {
			result1 = giveResult(temp);
			//printf("Result %f", result1); 
			sum1 += result1;
    		temp = strtok(NULL, ",");
		 }
			
		// printf("sum1 %f\n", sum1);
		 int j = 0;
		 for(j = k; j < (2*k); j++)
		 {
			 float sum2 = 0;
			 char* copy2 = (char*) malloc(sizeof(char)*(20));
			 strcpy(copy2, dataset[j]);
			 copy2 = (char*) realloc(copy2, strlen(copy2)+1);
			// printf("String 2 after copying %s\n", copy2);
			 temp = strtok(dataset[j], ",");
			 while( temp != NULL ) 
			 {
				result2 = giveResult(temp);
				//printf("Result %f\n", result2); 
				sum2 += result2;
    			temp = strtok(NULL, ",");
			 }
			 //printf("sum2 %f\n", sum2);
			 if(sum1 > sum2)
			 {
				 difference = sum1 - sum2;
			 }
			 else
			 {
				 difference = sum2 - sum1;
			 }

			 if ( difference < minimum)
			 {
				 minimum = difference;
				 minIndex = j;
				// printf("Min Value and index %f %d\n", minimum, minIndex);
			 }

			 strcpy(dataset[j], copy2);
		 }

		 MinDataSet[i] = minIndex - k;
		 strcpy(dataset[i], copy1);

	}

	int p = 0;
	for ( p = 0; p < k; p++)
	{
		printf("%d %d\n", p, MinDataSet[p]);
	}
	
	_getch();
	return 0 ;

}