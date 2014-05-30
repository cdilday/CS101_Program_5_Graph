/* Here is the implementation of the Graph ADT*/

#include "ListInt.h"
#include "Graph.h"
#include "myinclude.h"
#include <assert.h>

typedef struct GraphNodeStruct * GraphNodePtr;

typedef struct GraphNodeStruct 
{
	int data;
	IntListHndl adjacenyList;
} GraphNodeStruct;

typedef struct GraphStruct 
{
	int size;
	int source;
	int *pathDistances;
	GraphNodePtr *graph;
	IntListHndl *paths;
} GraphStruct;

/* CONSTRUCTORS / DESTRUCTORS */

GraphHndl newGraph (int n) 
{
	GraphHndl tempGraph;
	tempGraph->size = n;
	tempGraph = malloc ( sizeof(IntListStruct) );
	/*printf(" New Graph created! \n ");*/
	return tempGraph;
}

void freeGraph (GraphHndl * G)
{
	assert(G != NULL);
	free(G->pathDistances);
	freeList(&(G->paths));
	free(G);
	G = NULL;
	/*printf( "Freed the list! \n" );*/
}