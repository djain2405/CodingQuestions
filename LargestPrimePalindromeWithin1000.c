#define _CRT_SECURE_NO_WARNINGS

// Sample code to read in test cases:
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iostream>

int isPrime(int n)
{
    int i = 0;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        return 0;
    }
    return 1;
}

int isPalindrome(int n)
{
    char* str = (char*) malloc (sizeof(char)*10);
    sprintf(str, "%d", n);

    int len = strlen(str);
        
    int i = 0;
    for(i = 0; i < (len/2); i++)
    {
        if(str[i] != str[len - 1 - i])
        return 0;
    }
        
    return 1;
        
}
int main(int argc, const char * argv[]) {
  //  FILE *file = fopen(argv[1], "r");
    //char line[1024];
    //while (fgets(line, 1024, file)) {
        // Do something with the line
    //}
    
    

    int i = 0;
    for(i = 999; i >= 1; i--)
    {
        if(isPalindrome(i) && isPrime(i))
        {
            printf("%d", i);
            break;
        }
    }

	_getch();
    return 0;
} 
