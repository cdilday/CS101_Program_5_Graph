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

/* This function add an edge in from's adjacency list to vertex to*/
/* Pre conditions -> G was made with newGraph and from and to are
 *					both vertices in the graph*/
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

void doBFS (GraphHndl G, int source);

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