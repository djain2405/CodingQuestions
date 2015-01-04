#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <conio.h>

void
reverseString(char* ptr)
{
	if(*ptr)
	{
		reverseString(ptr + 1);
		printf("%c", *ptr);
	}


	
}

void swap(char *a, char *b)
{
	char temp;
	temp = *a;
	//printf("A nd B and temp  %c %c %c\n", *a, *b, temp);
	
	*a = *b;
	*b = temp;
}
void
	printpermutations( char* str, int i, int n)
{
	int j = 0;
	if ( i == n)
	{
		printf("%s\n", str);
	}
	else
	{

		for ( j = i; j <= n; j++)
		{
				swap((str+i), (str+j));
				printpermutations(str, i+1, n);
				swap((str+i), (str+j));
			
		}
	}
}
bool checkAnagram(char* str, int len)
{
	int i = 0;
	int arr[256] = {0};
	int count1 = 0;
	for ( i = 0; i < len; i++)
	{
		//printf("Str individual value : %c\n", str[i]);
		arr[str[i]]++;
	}

	for (i = 0; i < 256; i++)
	{
		//printf("Value : %d\n", arr[i]);
		if(arr[i] > 1)
		{
			if (arr[i]%2 != 0)
				return false;

		}
		else if (arr[i] == 1)
		{
			count1++;
		}
	}

	if(count1 > 1)
		return false;

	return true;
}

int
	uniquePalindrome(char* str, int len)
{
	int i = 0;
	int count = 0;
	int subcount = 0;
	int arr[256] = {0};
	for (i = 0; i < len; i++)
	{
		arr[str[i]]++;
	}

	for ( i = 0; i < 256; i++)
	{
		if(arr[i] % 2 == 0)
		{
			subcount = arr[i]/2;
			//printf("Subcount %d\n", subcount);

			count+=subcount;
		}
	}

	return count;
}
int main()
{
	int n = 0;
	char* str = NULL;
	//printf("Enter input\n");
	str = (char*) malloc(sizeof(char)*500);
	scanf("%s", str);
	int len = strlen(str);
	str = (char*) realloc(str, len+1);
	//printf("Length is %d\n", len);
	char* rev = str;
	
	//reverseString(rev);
	//printf("rev and original %s : %s", rev, str);
	printf("Reverse of string is %d\n", strcmp(_strrev(str), str));
	if (strcmp(_strrev(str), str) == 0)
	{	
		printf("1.\n");
		printf("\nyes");
	
	}
	else if (checkAnagram(str, len) == true)
	{
		printf("2.\n");
		printf("\nyes");
	}
	else 
		printf("\nno");

	if(checkAnagram(str, len) == true)
	{
		int no = 0;
		no = uniquePalindrome(str, len);
		printf("\nNo of unique pal: %d\n", no);
	}

	//printpermutations(str, 0, 3);

	_getch();
	return 0;
}
