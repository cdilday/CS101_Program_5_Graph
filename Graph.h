/* The prototype'd functions for the Graph ADT can be found here */
#include "ListInt.h"
#include <stdio.h>


/*Declaration of the GraphHandle empty pointer. Set it to null
 *when you first use it! */
typedef struct GraphStruct * GraphHndl;

/* This function will allocate memory for a new Graph and its n vertices, 
 * returning a POINTER to the thing allocated */
GraphHndl newGraph (int n);

/* This function ACCEPTS a pointer to a Graph and will free
 * every Vertex in the Graph, and then the Graph itself. */
/* Pre condition -> G was made with newGraph*/
/* Post Condition -> G is now set to NULL and is empty*/
void freeGraph (GraphHndl G); 

/* This function add an edge in from's adjacency list to vertex to*/
/* Pre conditions -> G was made with newGraph and from and to are
 *					both vertices in the graph*/
void addEdge (GraphHndl G, int from, int to);

/* Preforms a Breadth First search and updates G's parent and
 * distance arrays, erasing the results of any previous Breadth First Search*/
/* Pre condition -> G was made with newGraph*/
/* Post condition -> G posesses a source, and two arrays, one of which contains
 * 					Integer List ADTs that keep track of the paths to each node
 * 					from source and the other contains integers stating the length
 * 					of each path from source to a target vertex*/
void doBFS (GraphHndl G, int source);

/* Returns the distance from the last Breadth First Search's source to
 * vertex destination*/
/* Pre conditions -> G was made with newGraph and a doBFS has been
 * 					called at least once with a valid source*/
int getDistance (GraphHndl G, int destination);

/* Returns an integer list of the path from the last Breadth First Search's 
 * source to vertex destination. It will return the mxint value if there is
 * no valid path from source to destination*/
/* Pre conditions -> G was made with newGraph and a doBFS has been
 * 					called at least once with a valid source*/
IntListHndl getPathTo (GraphHndl G, int destination);

/* Prints each node and then its adjaceny list on the same line before
 * moving onto the next line and printing that node and its adjacency list */
/*Pre condition -> G was made with newGraph*/ 
void printGraph(GraphHndl G);