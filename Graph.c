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
	assert(G != NULL);
	int i;
	/* Check to make sure a BFS is necessary, don't do it if it's already been done on that node*/
	if(G->source != source){
		G->source = source;
		// Mark all the vertices as not visited
		int visited[G->size];
		for(int i = 0; i < V; i++)
			visited[i] = 0;
	 
		/*Create a queue for BFS*/
		IntListHndl queue;
		queue = NULL;
		queue = newList();
	 
		/* Mark the current node as visited and enqueue it */
		visited[source] = 1;
		insertAtBack(queue, source);
	 
		while(!isEmpty(queue))
		{
			/* Dequeue a vertex from queue and print it */
			source = getFirst(queue);
			printf("%d ", source);
			deleteFirst(queue);
	 
			/* Get all adjacent vertices of the dequeued vertex s
			 * If a adjacent has not been visited, then mark it visited
			 * and enqueue it */
			moveFirst(G->graph[source]);
			for(i = getFirst(G->graph[source]); i != getLast(G->graph[source]); i = getCurrent(G->graph[source]))
			{
				if(visited[i] == 0)
				{
					visited[i] = 1;
					insertAtBack(queue, i);
				}
				moveNext(G->graph[source]);
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