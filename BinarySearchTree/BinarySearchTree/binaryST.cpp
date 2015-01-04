#include <iostream>
#include <conio.h>
#include <stdio.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node*
	NewNode(int data)
{
	struct node* NewNode = (struct node*) malloc(sizeof(struct node));
	NewNode->data = data;
	NewNode->left = NULL;
	NewNode->right = NULL;

	return NewNode;
}

struct node*
	build123()
{
	struct node* Node1 = NewNode(1);
	struct node* Node2 = NewNode(2);
	struct node* Node3 = NewNode(3);
	
	Node2->left = Node1;
	Node2->right = Node3;

	return Node2;
}
struct node* Insert(struct node* root, int data)
{
	if(root == NULL)
	{
		return NewNode(data);
	}
	else 
	{
		if(data < root->data)
		{
			root->left = Insert(root->left, data);
		}
		else
		{
			root->right = Insert(root->right, data);
		}
	}
	return root;
}
void printInOrder(struct node* root)
{
	
	if(root == NULL)
		return;
	else
	{
		printInOrder(root->left);
		printf("%d", root->data);
		printInOrder(root->right);
		
	}

}
int CountNodesOfTree(struct node* root)
{
	if(root == NULL)
		return 0;
	else
	{
		return (CountNodesOfTree(root->left) + 1 + CountNodesOfTree(root->right));
	}
}

int 
	CountMaxDepthOfTree(struct node* root)
{
	int lDepth = 0;
	int Rdepth = 0;
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		lDepth = CountMaxDepthOfTree(root->left);
		Rdepth = CountMaxDepthOfTree(root->right);

		if(lDepth > Rdepth)
			return (lDepth+1);
		else
			return (Rdepth+1);

	}
}

int findLeastValue(struct node* root)
{
	struct node* current = root;
	if(root == NULL)
		return 0;
	else
	{
		while(current->left != NULL)
		{
			current = current->left;
		}

		return current->data;
	}
}
int printArray(int path[], int pathlen, int sum)
{
	int i = 0;
	int localSum = 0;
	for(i = 0; i<pathlen; i++)
	{
		//printf("%d", path[i]);
		localSum += path[i];
	}
	//printf("LocalSum %d %d\n", localSum, sum);
	if (localSum == sum)
	{
		return  1;
	}
	printf("\n");
	return 0;
}
int PrintPath(struct node* root, int path[], int pathlen, int sum)
{
	int x = 0;
	int y = 0;
	if ( root == NULL)
		return 0;
	path[pathlen] = root->data;
	pathlen++;

	if ((root->left == NULL) && (root->right == NULL))
	{
		int result = printArray(path, pathlen, sum);
		if(result == 1)
		{
			//printf("Equal\n");
			return 1;
		}
	}
	else
	{
		x = PrintPath(root->left, path, pathlen, sum);
		y = PrintPath(root->right, path, pathlen, sum);
	}

	if(x || y ==1)
		return 1;
	else
		return 0;


}

void mirror(struct node* root)
{
	struct node* temp = NULL;
	if(root == NULL)
		return;
	else
	{
		mirror(root->left);
		mirror(root->right);

		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

int SameTree(struct node* root, struct node* root1)
{
	if((root == NULL) && (root1 == NULL))
	{
		return 1;
	}
	else if((root != NULL) && (root1 != NULL))
	{
		return ((root->data == root1->data) && (SameTree(root->left, root1->left)) && (SameTree(root->right, root1->right)));
	}
	else
		return 0;
}

int NumberOfBsts(int number)
{
	
	int k = 0;
	
	if(number==0 || number==1)
	{
		return 1;
	}
	else
	{
			int left = 0;
			int right = 0;
			int sum = 0;
		for(k = 1; k <= number; k++)
		{
			left = NumberOfBsts(k-1);
			right = NumberOfBsts(number-k);
			sum = sum+(left*right);
		}
		return sum;
	}
}
int main()
{
	//struct node* root = build123();
	int countNodes = 0;
	int maxDepth = 0;
	int minValue = 0;
	int path[10] = {0};
	struct node* root = NULL;
	root = Insert(root, 4);
	root = Insert(root, 2);
	root = Insert(root, 1);
	root = Insert(root, 5);
	root = Insert(root, 3);
	printInOrder(root);
	printf("\n");

	//Determine size of the tree
	countNodes = CountNodesOfTree(root);
	printf("Size %d\n", countNodes);

	//Determine Max Depth of the tree
	maxDepth = CountMaxDepthOfTree(root);
	printf("MaxDepth %d\n", maxDepth);

	//Determine min value in a BST
	minValue = findLeastValue(root);
	printf("Min Value %d\n", minValue);

	//Determine if a root to leaf path of a tree adds up to a given sum
	int sum = 8;
	int result = PrintPath(root, path, 0, sum);
	printf("Result value final %d\n", result);
	if(result == 1)
		printf("Has Sum\n");
	else
		printf("Has no sum\n");

	//To print mirror of the tree, left and right child swapped
	mirror(root);
	printInOrder(root);
	printf("\n");

	struct node* root1 = NULL;
	root1 = Insert(root1, 4);
	root1 = Insert(root1, 2);
	root1 = Insert(root1, 1);
	root1 = Insert(root1, 5);
	root1 = Insert(root1, 3);
	printInOrder(root1);
	printf("\n");

	//To determine whether two trees are same
	int isSame = SameTree(root, root1);
	if(isSame == 0)
	{
		printf("Tree is not same\n");
	}
	else
	{
		printf("Tree is same\n");
	}

	//Recursive solution to find number of BSTs with given number of elements
	int num = NumberOfBsts(6);
	printf("Number of Bsts %d", num);
	
	_getch();
	return 0;
}