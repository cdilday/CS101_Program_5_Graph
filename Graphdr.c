/* This will test the BookList ADT */
#include "Graph.h"
#include "myinclude.h"

int main ()
{

	GraphHndl TheGraph;
	/* List creation */
	printf("Making the Graph...\n");
	TheGraph = NULL;
	printf("Instantiating the Graph...\n");
	TheGraph = newGraph(5);
	
	printf("Printing the (Currently empty) graph:\n");
	printGraph(TheGraph);
	printf("Adding Edges\n");
	addEdge(TheGraph, 0, 1);
	addEdge(TheGraph, 0, 2);
	addEdge(TheGraph, 2, 3);
	addEdge(TheGraph, 2, 4);
	addEdge(TheGraph, 3, 4);
	addEdge(TheGraph, 4, 3);
	addEdge(TheGraph, 4, 2);
	
	printf("Printing the graph with new edges:\n");
	
	printGraph(TheGraph);
	
	printf("Attempting BFS from 0: \n");
	doBFS(TheGraph, 0);
	
	printf("Freeing the graph\n");

	freeGraph(TheGraph);
	
	printf("Graph freed!\n");
	return(0);
}
