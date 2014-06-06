/* this is where the actual Library is created and used
*  using the Hash Table and two List ADTs I've created*/
#include "Graph.h"
#include "myinclude.h"


int main (int argc, char *argv[])
{
	int numVerts;
	int numQueries;
	char buffer[128];
	char *pbuff;
	int i;
	int tempNum;
	FILE *file;
	char fileName[1000];
	argc = argc;
	file = fopen (argv[1], "r");
	/*read in numbers from first file input*/
	pbuff = malloc(sizeof(char) * 128); 
	fgets(buffer, sizeof buffer, file);
	pbuff = buffer;
	sscanf(pbuff, "%d %d", &numVerts, &numQueries);

	GraphHndl;
	TheGraph = NULL;
	TheGraph = NewGraph(numVerts);
	
	/*insert everything from file 1 into the hash table*/
	for(i = 0; i < numVerts && fgets(buffer, sizeof buffer, file); i++)
	{
		pbuff = buffer;
		/*read in first vertex, then read in the rest*/
		sscanf(pbuff, "%d ", &tempNum);
		while(sscanf(pbuff, "%d ", &tempNum) == 1)
		{
			printf("Inserting %d into %d's adjacency list\n", tempNum, i);
			addEdge(TheGraph, i, tempNum);
		}
	}
	/* time for queries*/
	/*for(i = 0; i < numQueries && fgets(buffer, sizeof buffer, file); i++)
	{
		pbuff = buffer;
		sscanf(pbuff, "%[^\n]", buffer);
		char *tempName = malloc(sizeof(char) * 50); 
		strcpy(tempName, pbuff);
		/*printf("%s\n", tempName);*/
		/*printTableElement (Library, tempName);
	}*/
	
	freeGraph(TheGraph);
	
	return 0;
}
