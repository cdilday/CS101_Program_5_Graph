/* this is where the actual Library is created and used
*  using the Hash Table and two List ADTs I've created*/
#include "Graph.h"
#include "myinclude.h"


int main (int argc, char *argv[])
{
	int numVerts;
	int numQueries;
	int numDigits;
	char buffer[1024];
	char *pbuff;
	int i;
	int num;
	int tempNum;
	int digits;
	FILE *file;
	char fileName[1000];
	argc = argc;
	file = fopen (argv[1], "r");
	/*read in numbers from first file input*/
	pbuff = malloc(sizeof(char) * 1024); 
	fgets(buffer, sizeof buffer, file);
	pbuff = buffer;
	sscanf(pbuff, "%d %d", &numVerts, &numQueries);

	GraphHndl TheGraph;
	TheGraph = NULL;
	TheGraph = newGraph(numVerts);
	
	/*reading in the edges*/
	for(i = 0; i < numVerts && fgets(buffer, sizeof buffer, file); i++)
	{
		pbuff = buffer;
		/*read in first vertex */
		sscanf(pbuff, "%d", &num);
		/*loop to count the digits to format and read properly*/
		digits = 0;
		tempNum = num;
		while(tempNum != 0)
		{
			tempNum /= 10;
			digits++ ;
		}
		pbuff +=  (digits + 1);
		while(sscanf(pbuff, "%d", &num) == 1)
		{
			digits = 0;
			tempNum = num;
			while(tempNum != 0)
			{
				tempNum /= 10;
				digits++ ;
			}
			/*uncomment next line to print all the edge inserts*/
			/*printf("Inserting %d into %d's adjacency list\n", num, i);*/
			addEdge(TheGraph, i, num);
			pbuff += (digits + 1);
		}
	}
	/*uncomment to print the graph*/
	/* printGraph(TheGraph);*/
	/* time for queries, I will reuse num for the from integer and tempNum for the to integer*/
	for(i = 0; i < numQueries && fgets(buffer, sizeof buffer, file); i++)
	{
		pbuff = buffer;
		sscanf(pbuff, "%d %d", &num, &tempNum);
		/*doBFS(TheGraph, num);*/
		if(isEmpty(getPathTo(TheGraph, tempNum)) == 1)
		{
			printf("There is no way to get from %d to %d in this graph.\n", num, tempNum);
		}
		else
		{
			printf("To get from %d to %d requires %d edges, follow the path %d ", num, tempNum, getDistance(TheGraph, tempNum), num);
			printList(getPathTo(TheGraph, tempNum));
		}
	}
	
	freeGraph(TheGraph);
	
	return 0;
}
