#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <conio.h>


/*void
reverseString(char* ptr)
{
	if(*ptr)
	{
		reverseString(ptr + 1);
		printf("%c", *ptr);
	}	
}*/

void Reverse(char* str)
{
    int i,j;
    char temp[100];
    for(i=strlen(str)-1,j=0; i+1!=0; --i,++j)
    {
        temp[j]=str[i];
    }
    temp[j]='\0';
    strcpy(str,temp);
	//printf("String reversed is %s", str);
}

void swap(char *a, char *b)
{
	char temp;
	temp = *a;
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
int checkAnagram(char* str, int len)
{
	int i = 0;
	int arr[256] = {0};
	int count1 = 0;
	for ( i = 0; i < len; i++)
	{
		arr[str[i]]++;
	}

	for (i = 0; i < 256; i++)
	{
		if(arr[i] > 0)
		{
			if (arr[i]%2 != 0)
				count1++;
		}
	}

	if(count1 > 1)
		return 0;

	return 1;
}

int
fact(int n)
{
	if(n == 0)
		return 1;
	else if (n == 1)
		return 1;
	else
		return (n*fact(n-1));
}

int
uniquePalindrome(char* str, int len)
{
	int i = 0;
	int count = 0;
	int subcount = 1;
	int combo = 0;
	int arr[256] = {0};
	for (i = 0; i < len; i++)
	{
		arr[str[i]]++;
	}

	for ( i = 0; i < 256; i++)
	{
		if(arr[i]>1)
		{
			count = arr[i]/2;
			subcount *= fact(count);
		}
	}
	combo = fact(len/2)/ subcount;
	return combo;
}

int checkPalindrome(char* str, int len)
{
	char* ptr = (char*)malloc(sizeof(char)*(len+1));
	strcpy(ptr, str);
	//printf("String before reversal is %s\n", ptr);
	Reverse(str);
	//printf("String value after reversal %s\n", str);
	int i = 0; int flag = 0;
	while(i != (len-1))
	{
		//printf("Str and ptr values %c %c\n", str[i], ptr[i]);
		if(str[i] != ptr[i])
		{
			flag = 1;
			break;
		}
		i++;
	}

	Reverse(str);
	
	if(flag == 0)
	{
		return 1;
	}
	else
	{
		//printf("String is not a pal\n");
		return 0;
	}
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
/*	printf("Reverse of string is %d\n", strcmp(_strrev(str), str));
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
		printf("\nno");*/
	int no = 0;
	int combo = 0;
/*	if(checkAnagram(str, len) == 1)
	{
		//printf("Helloooo Checking");
		no = uniquePalindrome(str, len);
		//combo = fact(no);
	}
	*/
	//printf("%d", no);
	int isPal = checkPalindrome(str, len);
	if(isPal == 1)
	{
		printf("%d", len);
	}
	else
	{
		int i = 1;
		int pal = 0;
		int count = 1;
		for(i = len-1; i >= 0; i--)
		{
			char* substr = (char*)malloc(sizeof(char)*(i+1));
			memset(substr, '\0', sizeof(substr));
			strncpy(substr, str, i);
			
			if(checkPalindrome(substr, strlen(substr)) == 1)
			{
				printf("%d", count + len);
				break;
			}
			else
			{				
				count++;
			}
		}
		
	}
	_getch();
	return 0;
}
