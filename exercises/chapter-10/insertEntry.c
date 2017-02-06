#include <stdio.h>

struct ent
{
	int value;
	struct ent *next;
};

// inserts a new pointer in the position after the previous pointer
void insertEntry (struct ent *newPtr, struct ent *prevPtr)
{
	newPtr->next = prevPtr->next;
	prevPtr->next = newPtr;
};

int main (void)
{
	struct ent n0, n1, n2, n3;
	struct ent nE;
	
	struct ent *listPtr;
	
	n0.next = &n1; // list start
	
	n1.value = 100;
	n1.next = &n2;
	
	n2.value = 200;
	n2.next = &n3;
	
	n3.value = 300;
	n3.next = (struct ent *) 0; // list end
	
	nE.value = 50;
	
	// print current linked list
	listPtr = n0.next;
	while ( listPtr )
	{
		printf ("%-3i ", listPtr->value);
		listPtr = listPtr->next;
	}
	
	printf ("\n");
	
	// insert new entry
	insertEntry (&nE, &n0);
	
	// print new linked list
	listPtr = n0.next;
	while ( listPtr )
	{
		printf ("%-3i ", listPtr->value);
		listPtr = listPtr->next;
	}
	
	printf ("\n");
	
	return 0;
}

/* output:
 100 200 300
 50  100 200 300
 */
