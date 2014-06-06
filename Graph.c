/* Here is the implementation of the Graph ADT*/

#include "ListInt.h"
#include "Graph.h"
#include "myinclude.h"
#include <assert.h>

typedef struct GraphStruct 
{
	/*size is not necessary, but it makes it easier for other checks*/
	int size;
	int source;
	IntListHndl *graph;
	IntListHndl *paths;
	int *pathDistances;
} GraphStruct;

/* CONSTRUCTORS / DESTRUCTORS */

GraphHndl newGraph (int n) 
{
	int i;
	GraphHndl tempGraph;
	tempGraph = malloc ( sizeof(GraphStruct) );
	tempGraph->size = n;
	tempGraph->pathDistances = malloc(sizeof(int) * n);
	tempGraph->graph = malloc(sizeof(IntListHndl) * n);
	tempGraph->paths = malloc(sizeof(IntListHndl) * n);
	for(i = 0; i < n; i++)
	{
		tempGraph->paths[i] = NewList();
		tempGraph->graph[i] = NewList();
	}
	/* instantiate the source as -1 to show that a BFS has not been completed yet*/
	tempGraph->source = -1;
	/*printf(" New Graph created! \n ");*/
	return tempGraph;
}

void freeGraph (GraphHndl G)
{
	int i;
	assert(G != NULL);
	free(G->pathDistances);
	for(i = 0; i < G->size; i++)
	{
		freeList(&(G->paths[i]));
		freeList(&(G->graph[i]));
		free(G->graph[i]);
	}
	free(G);
	G = NULL;
	/*printf( "Freed the Graph! \n" );*/
}

void addEdge (GraphHndl G, int from, int to)
{
	int inserted;
	assert(G != NULL);
	assert(from < G->size);
	assert(to < G->size);
	
	inserted = 0;
	if(isEmpty(G->graph[from]))
	{
		insertAtFront(G->graph[from], to);
		return;
	}
	while(!offEnd(G->graph[from]))
	{
		if(getCurrent(G->graph[from]) > to)
		{
			insertBeforeCurrent(G->graph[from], to);
			inserted = 1;
			break;
		}	
		moveNext(G->graph[from]);
	}
	
	if(inserted ==0)
	{
		insertAtBack(G->graph[from], to);
		moveFirst(G->graph[from]);
	}
}

void doBFS (GraphHndl G, int source)
{
	int i;
	int tempSource;
	int *visited;
	IntListHndl queue;
	assert(G != NULL);
	/* Check to make sure a BFS is necessary, don't do it if it's already been done on that node*/
	if(G->source != source){
		printf("1\n");
		G->source = source;
		tempSource = source;
		/* Mark all the vertices as not visited*/
		visited = malloc(sizeof(int) * G->size); 
		printf("2\n");
		for( i = 0; i < G->size; i++)
			visited[i] = 0;
		printf("3\n");
		printf("%d\n",tempSource);
		/*Create a queue for BFS*/
		printf("4\n");
		queue = NewList();
		printf("5\n");
	 
		/* Mark the current node as visited and enqueue it */
		visited[source] = 1;
		printf("6\n");
		insertAtFront(queue, source);
		printf("%d \n", getFirst(queue));
		printf("7\n");
		while(isEmpty(queue) == 0)
		{
			printf("%d \n", getFirst(queue));
			printf("8\n");
			/* Dequeue a vertex from queue and print it */
			tempSource = getFirst(queue);
			printf("%d \n", tempSource);
			printf("9\n");
			deleteFirst(queue);
	 
			/* Get all adjacent vertices of the dequeued vertex s
			 * If a adjacent has not been visited, then mark it visited
			 * and enqueue it */
			if(isEmpty(G->graph[tempSource]) == 0){
				moveFirst(G->graph[tempSource]);
				for(i = getFirst(G->graph[tempSource]); i != getLast(G->graph[tempSource]); i = getCurrent(G->graph[tempSource]))
				{
					if(visited[i] == 0)
					{
						visited[i] = 1;
						insertAtBack(queue, i);
					}
					moveNext(G->graph[tempSource]);
				}
			}
		}
	}
}
 

int getDistance (GraphHndl G, int destination)
{
	assert(G != NULL);
	assert(G->source != -1);
	return G->pathDistances[destination];
}

IntListHndl getPathTo (GraphHndl G, int destination)
{
	assert(G != NULL);
	assert(G->source != -1);
	return G->paths[destination];
}

void printGraph(GraphHndl G)
{
	int i;
	assert (G != NULL);
	for(i = 0; i < G->size; i++)
	{
		printf("%d ", i);
		printList(G->graph[i]);
	}
}