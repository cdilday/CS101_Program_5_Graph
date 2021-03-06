/* Here will go the implementation of the List ADT. 
*  This ADT is an altered version of the List ADT I
*  with Alex Vincent for Program 2. We are not working
*  together again, but that is why, if ours are similar,
*  they are so.*/

#include "ListInt.h"
#include "myinclude.h"
#include <assert.h>

typedef struct IntNodeStruct * IntNodePtr;

typedef struct IntNodeStruct 
{
	int data;
	struct IntNodeStruct* next;
	struct IntNodeStruct* prev;
} IntNodeStruct;

typedef struct IntListStruct 
{
	IntNodePtr first;
	IntNodePtr last;
	IntNodePtr curr;
} IntListStruct;

/* CONSTRUCTORS / DESTRUCTORS */

IntListHndl NewList () 
{
	IntListHndl tempList;
	tempList = malloc ( sizeof(IntListStruct) );
	tempList->first = NULL;
	tempList->last = NULL;
	tempList->curr = NULL;
	/*printf(" New List created! \n ");*/
	return tempList;
}

void freeList (IntListHndl * L)
{
	IntNodePtr tempCurr;
	assert((*L) != NULL);
	/*FREE THE NODES! */
	tempCurr = (*(L))->first;
	(*(L))->curr = (*(L))->first;
	while((*(L))->curr != NULL)
	{
		tempCurr = (*(L))->curr->next;
		free((*(L))->curr); 
		(*(L))->curr = tempCurr;
	}
	(*(L))->first = NULL;
	(*(L))->curr = NULL;
	(*(L))->last = NULL;
	free((*L));
	(*L) = NULL;
	/*printf( "Freed the list! \n" );*/
}

int isEmpty(IntListHndl L) 
{
	assert (L != NULL);
	return (L->first == NULL);
}

int offEnd(IntListHndl L) 
{
	assert (L != NULL);
	return (L->curr == NULL);
}

int atFirst(IntListHndl L)
{
	assert (L != NULL);
	return ( (L->curr == L->first) && offEnd(L) == 1 );
}

int atLast(IntListHndl L)
{
	assert (L != NULL);
	return ( (L-> curr == L->last) && offEnd(L) == 1 );
}

int getFirst(IntListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	return (L->first->data);
}

int getLast(IntListHndl L)
{
	assert (L != NULL);
	assert (L->last != NULL);
	return (L->last->data);
}
int getCurrent(IntListHndl L)
{
	assert (L != NULL);
	assert (L->curr != NULL);
	return (L->curr->data);
}

void insertAtFront(IntListHndl L, int data)
{
	IntNodePtr tempNode;
	assert (L != NULL);
	tempNode = malloc ( sizeof(struct IntNodeStruct) );

	tempNode->data = data;
	tempNode->next = L->first;
	tempNode->prev = NULL;

	if(L->first == NULL)
	/*this means we're adding the first element, meaning L needs to have curr, first, & last assigned.*/
	{ 
		L->first = tempNode;
		L->last = tempNode;
		L->curr = tempNode;
	}
	else
	{
		L->first->prev = tempNode;
		L->first = tempNode;
	}

	/*printf("Successfully inserted a new node in the front \n");*/
}

void insertAtBack (IntListHndl L, int data)
{
	IntNodePtr tempNode;
	assert (L != NULL);
	tempNode = malloc ( sizeof(struct IntNodeStruct) );
	
	tempNode->data = data;
	tempNode->next = NULL;
	tempNode->prev = L->last;
	
	if(L->last == NULL)
	/*this means we're adding the first element, meaning L needs to have curr, first, & last assigned.*/
	{
		L->last = tempNode;
		L->first = tempNode;
		L->curr = tempNode;
	}
	else
	{
		L->last->next = tempNode;
		L->last = tempNode;
	}

	/*printf("Successfully inserted a new node into the back \n");*/
}

void printList(IntListHndl L)
{
	IntNodePtr tempCurr;
	assert (L != NULL);
	tempCurr = L->first;
	while(tempCurr != NULL)
	{
		printf("%d ", tempCurr->data);
		tempCurr = tempCurr->next;
	}
	printf("\n");
}

void printListFile(IntListHndl L, FILE *file)
{
	IntNodePtr tempCurr;
	assert (L != NULL);
	tempCurr = L->first;
	while(tempCurr != NULL)
	{
		fprintf(file, "%d ", tempCurr->data);
		tempCurr = tempCurr->next;
	}
	fprintf(file, "\n");
}  	

void makeEmpty(IntListHndl L)
{
	IntNodePtr tempCurr;
	assert (L != NULL);
	tempCurr = L->first;
	L->curr = L->first;
	while(L->curr != NULL)
	{
		tempCurr = L->curr->next;
		free(L->curr); 
		L->curr = tempCurr;
	}
	L->first = NULL;
	L->curr = NULL;
	L->last = NULL;
	
	/*printf("The list is now empty\n");*/
}

void moveFirst(IntListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	L->curr = L->first;
}

void moveLast(IntListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	L->curr = L->last;
}

void movePrev(IntListHndl L)
{
	assert (L != NULL);
	assert (L->curr != NULL);
	L->curr = L->curr->prev;
} 

void moveNext(IntListHndl L)
{
	assert (L != NULL);
	assert (L->curr != NULL);
	L->curr = L->curr->next;
}

void insertBeforeCurrent(IntListHndl L, int data)
{
	IntNodePtr tempNode;
	assert (L != NULL);
	assert (L->curr != NULL);
	
	tempNode = malloc ( sizeof(struct IntNodeStruct) );
	
	tempNode->data = data;
	tempNode->next = L->curr;
	tempNode->prev = L->curr->prev;

	L->curr->prev = tempNode;
	if(L->first == L->curr)
	{
		L->first = tempNode;
	}
	else
	{
		tempNode->prev->next = tempNode;
	}

	/*printf("Successfully inserted a new node before the current node\n");*/
	
}

void deleteFirst(IntListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	
	if(L->curr == L->first)
	{
		L->curr = L->first->next;
		free (L->first);
		L->first = L->curr;
	}
	else
	{
		IntNodePtr tempCurr;
		tempCurr = L->first->next;
		free(L->first);
		L->first = tempCurr;
	}
	L->first->prev = NULL;
}

void deleteLast(IntListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	
	if(L->curr == L->last)
	{
		L->curr = L->last->prev;
		free (L->last);
		L->last = L->curr;
	}
	else
	{
		IntNodePtr tempCurr;
		tempCurr = L->last->prev;
		free(L->last);
		L->last = tempCurr;
	}
	L->last->next = NULL;
}

void deleteCurrent(IntListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	L->curr->prev->next = L->curr->next;
	L->curr->next->prev = L->curr->prev;
	free (L->curr);
}
