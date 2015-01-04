#include <iostream>
#include <conio.h>
#include <stdio.h>
int topNo = -1;
int topOper = -1;
bool isFullNo()
{
	if(topNo == 99)
		return true;
	return false;
}
bool isFullOper()
{
	if(topOper == 99)
		return true;
	return false;
}

bool isEmptyNo()
{
	if(topNo == -1)
		return true;
	return false;
}

bool isEmptyOper()
{
	if(topOper == -1)
		return true;
	return false;
}

void pushNo(int* stack, int entry)
{
	if(isFullNo() == true)
		return;

	topNo++;
	stack[topNo] = entry;

}

void pushOper(char* stack, int entry)
{
	if(isFullOper() == true)
		return;

	topOper++;
	stack[topOper] = entry;

}

int popNo(int* stack)
{
	if(isEmptyNo() == true)
		return -1;

	int x = stack[topNo];
	topNo--;
	return x;
}

char popOper(char* stack)
{
	if(isEmptyOper() == true)
		return NULL;

	char x = stack[topOper];
	topOper--;
	return x;
}

void
printStackNumber(int* stack)
{
	printf("\nStack : ");
	int i = 0;

	for(i = 0; i <= topNo; i++)
		printf("%d", stack[i]);
}

void
printStackOperator(char* stack)
{
	printf("\nStack : ");
	int i = 0;

	for(i = 0; i <= topOper; i++)
		printf("%c", stack[i]);
}

bool checkPriority(char firstOperator, char secondOperator)
{
	//printf("First : %c, second : %c\n", firstOperator, secondOperator);
	if(( firstOperator == '/' || firstOperator == '*') && (secondOperator == '+' || secondOperator == '-'))
		return true;
	else if(firstOperator == secondOperator)
		return true;
	else
		return false;
}

int calculateresult(int x, int y, char oper)
{
	int result = 0;
	switch (oper)
	{
	case '/' : result = x/y;
		break;
	case '*' : result = x*y;
		break;
	case '+' : result = x+y;
		break;
	case '-' : result = x-y;
		break;
	default:
		break;
	}

	return result;
}
int main()
{

	char* str = (char*) malloc(100*sizeof(char));
	printf("Enter expression:\n");
	fgets(str, 100, stdin);
	int i = 0;
/*	while(str[i] != NULL)
	{
		printf("%c", str[i]);
		i++;
	}*/

	int* stackNumber = (int*) malloc (sizeof(int)*100);
	char* stackOperators = (char*) malloc (sizeof(char)*100);
	//printf("%c", str[i]);
	while(str[i] != NULL)
	{
		if((str[i] - '0' >= 0) && (str[i] - '0' <= 9))
		{
			//printf("Testing.......\n");
			int number = 0;
			int j = i;
			int count = 0;
			while(str[j] - '0' >= 0 && str[j] - '0' <= 9)
			{
				j++;
				count++;
				//printf("Testing number of times............................\n");
			}
			//printf("Count is %d\n", count);
			i = j-1;
			int k = 0;
			while(count != 0)
			{
				number = number + (str[j-1] - '0')*(pow(10,k));
				//printf("Number : %d\n", number);
				k++;
				count--;
				j--;
			}
			//printf("number is %d", number);
			pushNo(stackNumber, number);
		}
		else
		{
			if(topOper >= 0 && topNo >= 1)
			{
				if(checkPriority(stackOperators[topOper], str[i]) == true)
				{
					int y = popNo(stackNumber);
					int x = popNo(stackNumber);
					char oper = popOper(stackOperators);
					int result = calculateresult(x, y, oper);
					pushNo(stackNumber, result);

					while(checkPriority(stackOperators[topOper], str[i]) == true)
					{
						int y = popNo(stackNumber);
						int x = popNo(stackNumber);
						char oper = popOper(stackOperators);
						int result = calculateresult(x, y, oper);
						pushNo(stackNumber, result);
					}
					pushOper(stackOperators, str[i]);
				}
				else if (str[i] == ')')
				{
					int y = popNo(stackNumber);
					int x = popNo(stackNumber);
					char oper = popOper(stackOperators);
					int result = 0;
					switch (oper)
					{
					case '/' : result = x/y;
						break;
					case '*' : result = x*y;
						break;
					case '+' : result = x+y;
						break;
					case '-' : result = x-y;
						break;
					default:
						break;
					}

					char temp = NULL;
					while(temp != '(')
						temp = popOper(stackOperators);
					//temp = popOper(stackOperators);
					pushNo(stackNumber, result);
				}
				else
				{
					pushOper(stackOperators, str[i]);
				}
			}
			else
			{
				pushOper(stackOperators, str[i]);
			}
		}
		i++;
		
	}

	printStackNumber(stackNumber);
	printStackOperator(stackOperators);

	while(topOper != -1)
	{
		int y = popNo(stackNumber);
		int x = popNo(stackNumber);
		char oper = NULL;
		while((oper != '*') && (oper != '/') && (oper != '+') && (oper != '-'))
		{
			oper = popOper(stackOperators);
			//printf("operator : %c\n", oper);
		}
		int result = 0;
		switch (oper)
		{
		case '/' : result = x/y;
			break;
		case '*' : result = x*y;
			break;
		case '+' : result = x+y;
			break;
		case '-' : result = x-y;
			break;
		default:
			break;
		}

		pushNo(stackNumber, result);
	}
	printf("\n..................................................................\n");
	int result = popNo(stackNumber);
	printf("Result : %d\n", result);
	_getch();
	return 0;
}