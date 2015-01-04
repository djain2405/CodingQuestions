#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include <stdio.h>

struct node
{
	int data;
	struct node* next;
};

struct station
{
	int data;
	int spend;
	struct station* next;
};

struct node* newNode(int data)
{
	struct node* NewNode = (struct node*) malloc(sizeof(struct node));
	NewNode->data = data;
	NewNode->next = NULL;

	return NewNode;
}

struct station* newStation(int data, int spend)
{
	struct station* NewNode = (struct station*) malloc(sizeof(struct station));
	NewNode->data = data;
	NewNode->spend = spend;
	NewNode->next = NULL;

	return NewNode;
}

void PushIntoLinkedList(struct node** head, int elementdata)
{
	struct node* node = newNode(elementdata);
	
	if(*head == NULL)
	{
		*head = node;
		return;
	}

	struct node* current = *head;
	while(current->next != NULL)
	{
		current = current->next;
	}

	current->next = node;
	
}

void PushIntoCircularLinkedList(struct node** head, int elementdata)
{
	struct node* node = newNode(elementdata);
	
	if(*head == NULL)
	{
		*head = node;
		node->next = *head;
		return;
	}

	struct node* current = *head;
	while(current->next != *head)
	{
		current = current->next;
	}

	current->next = node;
	node->next = *head;
	
}

void PushIntoCircularLinkedListStation(struct station** head, int elementdata, int spendData)
{
	struct station* node = newStation(elementdata, spendData);
	
	if(*head == NULL)
	{
		*head = node;
		node->next = *head;
		return;
	}

	struct station* current = *head;
	while(current->next != *head)
	{
		current = current->next;
	}

	current->next = node;
	node->next = *head;
	
}

void printLinkedList(struct node** head)
{
	struct node* current = *head;
	printf("\n");
	while(current->next != NULL)
	{
		printf("%d", current->data);
		current = current->next;
	}
	printf("%d", current->data);
}

void deleteNode(struct node** head, int key)
{
	struct node* current  = *head;
	while(current->next != NULL)
	{
		if(current->next->data == key)
		{
			current->next = current->next->next;
			return;
		}
		current = current->next;
	}
}
int main()
{
	int n = 0;
	printf("Enter number of elements\n");
	scanf("%d", &n);
	int* input = (int*) malloc (n*sizeof(int));
	int* spend = (int*) malloc (n*sizeof(int));
	struct station* head = NULL;
	struct node* nodeHead = NULL;
	
	printf("Enter elements \n");

	for ( int i = 0; i < n; i++)
	{
		//scanf("%d %d", &input[i], &spend[i]);
		//PushIntoCircularLinkedListStation(&head, input[i], spend[i]);

		scanf("%d", &input[i]);
		PushIntoLinkedList(&nodeHead, input[i]);
	
	}
	printLinkedList(&nodeHead);
	deleteNode(&nodeHead, 4);
	printLinkedList(&nodeHead);


	int result = 0;
	int i = 1;
	struct station* prev = head;
	struct station* current = head;
	
	bool isNegative = false;
	while(i < 5)
	{
		do
		{
			result = result + current->data - current->spend;
			printf("Result value %d\n", result);
			if(result < 0)
			{
				isNegative = true;
				break;
			}
			else
			{
				//printf("Current going next\n");
				current = current->next;
			}

		}while(current != prev);

		if ( isNegative == true)
		{
			prev = prev->next;
			current = prev;
			i++;
			result = 0;
			isNegative = false;
		}
		else
		{
			if(result >= 0)
			{
				printf("%d", i);
				break;
			}
		}
	}
	//printf("Result value %d\n", result);



	if(i > 4)
		printf("Impossible\n");



	/*struct station* current = head;
	if ( current == NULL)
	{
		printf("Current is null");
	}
	while(current->next != head)
	{
		printf("data is %d\n", current->data);
		current = current->next;
	}
	printf("data is %d\n", current->data);*/

	_getch();
	return 0;
}