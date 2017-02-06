#include <stdio.h>

struct ent
{
	int value;
	struct ent *next;
};

// function that removes the entry in the linked list AFTER prevPtr
void removeEntry (struct ent *prevPtr)
{
	prevPtr->next = prevPtr->next->next;
};

int main (void)
{
	struct ent n0, n1, n2, n3;
	struct ent *listPtr;
	
	n0.next = &n1;
	
	n1.value = 100;
	n1.next = &n2;
	
	n2.value = 200;
	n2.next = &n3;
	
	n3.value = 300;
	n3.next = (struct ent *) 0;
	
	// print current list
	listPtr = n0.next;
	while ( listPtr )
	{
		printf ("%-3i ", listPtr->value);
		listPtr = listPtr->next;
	}
	printf ("\n");
	
	removeEntry (&n0); // remove n1
	
	// print altered list
	listPtr = n0.next;
	while ( listPtr )
	{
		printf ("%-3i ", listPtr->value);
		listPtr = listPtr->next;
	}
	printf ("\n");
	
	removeEntry (&n2); // remove n3
	
	// print altered list
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
 200 300
 200
 */
