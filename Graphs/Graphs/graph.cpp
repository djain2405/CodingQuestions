#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <conio.h>

struct node
{
	int data;
	struct node* next;
};

struct nodeList
{
	struct node* head;
};

struct Graph
{
	int v;
	struct nodeList* array;
};

struct node* NewNode(int data)
{
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

struct Graph* CreateGraph(int vertices)
{
	struct Graph* graph = (struct Graph*) malloc ( sizeof(Graph));
	graph->v = vertices;
	
	graph->array = (struct nodeList*)malloc(vertices* sizeof(struct nodeList));

	for (int v = 0; v < vertices; v++)
	{
		graph->array[v].head = NULL;
	}

	return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
	//printf("Testing---------------------\n");
	struct node* destination = NewNode(dest);
	destination->next = graph->array[src].head;
	graph->array[src].head = destination;
	
	/*struct node* source = NewNode(src);
	source->next = graph->array[dest].head;
	graph->array[dest].head = source;*/
	
}
 
void printGraph( struct Graph* graph)
{
	int v = 0;
	for (v = 0; v < graph->v; v++)
	{
		struct node* adjList = graph->array[v].head;
		printf("Adjacency list of %d", v);
		while(adjList)
		{
			printf("->%d", adjList->data);
			adjList = adjList->next;
		}
		printf("\n");
	}
}

/*
void DFSUtil(struct Graph* graph, int src, bool* visited)
{
	visited[src] = true;
	printf("%d ", src);

	struct node* adjList = graph->array[src].head;
	while(adjList)
	{
		if(visited[adjList->data] == false)
		{
			DFSUtil(graph, adjList->data, visited);
		}
		adjList = adjList->next;
	}


}
void DFS(struct Graph* graph, int src)
{
	bool* visited = (bool*) malloc (sizeof(bool)*graph->v);
	int i = 0;
	for(i = 0; i < graph->v; i++)
	{
		visited[i] = false;
	}

	DFSUtil(graph, src, visited);

}*/

bool isCyclicUtil(struct Graph* graph, int src, bool* visited)
{
	if(visited[src] == false)
	{
		visited[src] = true;
		printf("%d ", src);

		struct node* adjList = graph->array[src].head;
		while(adjList)
		{
			if((visited[adjList->data] == false) && (isCyclicUtil(graph, adjList->data, visited)))
			{
				printf("Testing for true \n");
				return true;
			}

			adjList = adjList->next;

		}

	}


	printf("Testing for false \n");
	return false;

}
bool isCyclic(struct Graph* graph)
{
	bool* visited = (bool*) malloc (sizeof(bool)*graph->v);
	int i = 0;
	for(i = 0; i < graph->v; i++)
	{
		visited[i] = false;
	}
	
	

	for (i = 0; i < graph->v; i++)
	{
			if(isCyclicUtil(graph, i, visited) == true)
			{
				printf("Testing again for true \n");
				return true;
			}
	}


	printf("Testing again for false \n");
	return false;

}

int main()
{
	int v = 0;
	int e = 0;
	
	printf("Enter number of vertices\n");
	scanf("%d", &v);

	
	struct Graph* userGraph = CreateGraph(v);
	printf("Enter number of Edges\n");
	scanf("%d", &e);
	int i = 0;
	int src = 0;
	int dest = 0;
	printf("Enter Edges \n");
	for(i = 0; i < e; i++)
	{
		scanf("%d %d", &src, &dest);
		addEdge(userGraph, src, dest);
	}
	
	printGraph(userGraph);

	/*int** mat = (int**) malloc(v*sizeof(int));
	int p = 0;
	for(p = 0; p < v; p++)
	{
		mat[p] = (int*) malloc(v*sizeof(int));
	}
	
	int j = 0;

	for (i = 0; i < v; i++)
	{
		for(j = 0; j < v; j++)
		{
			mat[i][j] = 0;
		}
	}

	for(i = 0; i < e; i++)
	{
		scanf("%d %d", &src, &dest);
		mat[src-1][dest-1] = 1;
		mat[dest-1][src-1] = 1;
	}

	for (i = 0; i < v; i++)
	{
		for(j = 0; j < v; j++)
		{
			printf("%d", mat[i][j]);
		}
		printf("\n");
	}
	*/



	/*addEdge(userGraph, 1, 2);
	addEdge(userGraph, 1, 3);
	addEdge(userGraph, 2, 3);
	addEdge(userGraph, 2, 4);
	addEdge(userGraph, 3, 4);
	addEdge(userGraph, 4, 5);
	*/
	//printGraph(userGraph);

	//DFS(userGraph, 0);

	if(isCyclic(userGraph) == true)
	{
		printf("Graph has no cycle\n");
	}
	else
	{
		printf("Graph has a cycle\n");
	}
	_getch();
	return 0;
}