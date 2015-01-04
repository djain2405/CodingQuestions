#include <iostream>
#include <conio.h>
#include <stdio.h>

struct node
{
	int data;
	struct node* next;
};

struct node* newNode(int data)
{
	struct node* newNode = (struct node*) malloc ( sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

void pushToLinkedList(struct node** head, int data)
{
	if(*head == NULL)
	{
		*head = newNode(data);
		return;
	}

	struct node* current = *head;
	while(current->next != NULL)
	{
		current = current->next;
	}

	current->next = newNode(data);
}

struct node*
	AddLinkedList(struct node* L1, struct node* L2)
{
	struct node* result = NULL;
	int carry = 0;

	if(L1 == NULL && L2 == NULL)
	{
		return result;
	}

	while(L1 != NULL || L2 !=  NULL)
	{
		int temp = carry;
		int data = 0;
		if ( L1 == NULL)
			L1->data = 0;

		if ( L2 == NULL)
			L2->data = 0;
		int sum = 0;
		int n1 = L1->data;
		int n2 = L2->data;

		sum = n1 + n2 + temp;
		if(sum > 9)
		{
			data = sum%10;
			carry = sum/10;
		}
		else
		{
			data = sum;
			carry = 0;
		}

		pushToLinkedList(&result, data);
		L1 = L1->next;
		L2 = L2->next;
	}

	if(carry == 1)
	{
		pushToLinkedList(&result, carry);
	}

	return result;

}

void printLinkedList(struct node* head)
{
	if(head == NULL)
		return;
	struct node* current =  head;
	while(current->next != NULL)
	{
		printf("%d", current->data);
		current = current->next;
	}

	printf("%d", current->data);
}

int main()
{
	struct node* L1 = NULL;
	struct node* L2 = NULL;

	pushToLinkedList(&L1, 9);
	pushToLinkedList(&L1, 9);
	//pushToLinkedList(&L1, 9);
	pushToLinkedList(&L2, 9);
	pushToLinkedList(&L2, 9);
//	pushToLinkedList(&L2, );

	printLinkedList(L1);
	printf("\n");
	printLinkedList(L2);
	printf("\n");

	struct node* sum = NULL;
	sum = AddLinkedList(L1, L2);

	printLinkedList(L1);
	printf("\n");
	printLinkedList(L2);
	printf("\n");
	printLinkedList(sum);
	
	_getch();
	return 0;
}