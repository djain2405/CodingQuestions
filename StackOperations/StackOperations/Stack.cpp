#include <iostream>
#include <conio.h>
#include <stdio.h>
int top = -1;
bool isFull()
{
	if(top == 99)
		return true;
	return false;
}

bool isEmpty()
{
	if(top == -1)
		return true;
	return false;
}
void push(int* stack, int entry)
{
	if(isFull() == true)
		return;

	top++;
	stack[top] = entry;

}

int pop(int* stack)
{
	if(isEmpty() == true)
		return -1;

	int x = stack[top];
	top--;
	return x;
}

void
printStack(int* stack)
{
	printf("Stack : ");
	int i = 0;

	for(i = 0; i <= top; i++)
		printf("%d", stack[i]);
}
int main()
{
	int* stack = (int*) malloc (sizeof(int)*100);
	push(stack, 5);
	push(stack, 4);
	push(stack, 3);
	push(stack, 2);
	push(stack, 1);
	push(stack, 0);
	pop(stack);
	printStack(stack);

	_getch();
	return 0;
}