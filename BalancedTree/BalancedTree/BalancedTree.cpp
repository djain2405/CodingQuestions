#include <iostream>
#include <conio.h>
#include <stdio.h>

bool isBalanced = false;
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int data)
{
	struct Node* newNode = (struct Node*) malloc (sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void Insert(struct Node	**head, int data)
{
	if(*head == NULL)
	{
		*head = newNode(data);
		return;
	}
	if(data <= (*head)->data)
		Insert(&((*head)->left), data);
	else
		Insert(&((*head)->right), data);
}

void
PrintTree(struct Node* head)
{
	if(head == NULL)
		return;
	
	printf("%d", head->data);
	PrintTree(head->left);
	PrintTree(head->right);
}

int getHeight(struct Node* head)
{
	if(head == NULL)
		return 0;
	int lDepth = getHeight(head->left);
	int rDepth = getHeight(head->right);

	if(lDepth > rDepth)
	{
		return (lDepth + 1);
	}
	else if(rDepth >= lDepth)
	{
		return (rDepth + 1);
	}
}
int main()
{

	struct Node* head = NULL;
	Insert(&head, 3);
	Insert(&head, 2);
	Insert(&head, 4);
	Insert(&head, 1);
	Insert(&head, 5);
	Insert(&head, 6);

	PrintTree(head);

	int height = getHeight(head);
	int leftHeight = getHeight(head->left);
	int rightHeight = getHeight(head->right);
	printf("values %d %d\n", leftHeight, rightHeight);
	
	if(leftHeight == rightHeight)
		printf("Tree is balanced\n");
	else
		printf("Tree is unbalanced\n");


	_getch();
	return 0;
}