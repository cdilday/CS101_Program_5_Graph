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

void freeGraph (GraphHndl * G)
{
	int i;
	assert(G != NULL);
	free(G->pathDistances);
	for(i = 0; i < n; i++)
	{
		freeList(&(G->paths[i]));
		freeList(&(G->graph[i]));
		free(G->graph[i]);
	}
	free(G);
	G = NULL;
	/*printf( "Freed the Graph! \n" );*/
}

void doBFS (GraphHndl G, int source);

int getDistance (GraphHndl G, int destination);
{
	assert(G != NULL);
	assert(G->source != -1);
	return G->pathdistances[destination];
}

IntListHndl getPathTo (Graph G, int destination)
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