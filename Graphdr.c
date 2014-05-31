/* This will test the BookList ADT */
#include "Graph.h"
#include "myinclude.h"

int main ()
{
	int testData = 98;
	int testData2 = 97;
	int testData3 = 99;

	/* List creation */
	GraphHndl TheGraph;
	TheGraph = NULL;
	TheGraph = NewGraph(8);

	freeGraph(&TheGraph);
	
	return(0);
}
