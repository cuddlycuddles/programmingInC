#include <stdio.h>

struct ent
{
	struct ent *prev;
	int value;
	struct ent *next;
};

// inserts a new pointer in the position after the previous pointer
void insertEntry (struct ent *newPtr, struct ent *prevPtr)
{
	newPtr->next = prevPtr->next;
	prevPtr->next = newPtr;
};

// function that removes the entry in the linked list AFTER prevPtr
void removeEntry (struct ent *ptr)
{
	ptr->prev->next = ptr->next;
};

int main (void)
{
	struct ent n0, n1, n2, n3, nE;
	struct ent *listPtr;
	
	n0.next = &n1;
	
	n1.value = 100;
	n1.next = &n2;
	
	n2.prev = &n1;
	n2.value = 200;
	n2.next = &n3;
	
	n3.prev = &n2;
	n3.value = 300;
	n3.next = (struct ent *) 0;
	
	nE.value = 250;
	
	printf ("Original doubly linked list:\n");
	
	// output current list
	listPtr = n0.next;
	while ( listPtr )
	{
		printf ("%i ", listPtr->value);
		listPtr = listPtr->next;
	}
	
	// remove entry number 2
	removeEntry (&n2);
	
	printf ("\n\nAltered doubly linked list:\n");
	
	// output altered list
	listPtr = n0.next;
	while ( listPtr )
	{
		printf ("%i ", listPtr->value);
		listPtr = listPtr->next;
	}
	
	insertEntry (&nE, &n1);
	
	printf ("\n\nAltered doubly linked list:\n");
	
	// output altered list
	listPtr = n0.next;
	while ( listPtr )
	{
		printf ("%i ", listPtr->value);
		listPtr = listPtr->next;
	}
	
	printf ("\n");
	
	return 0;
}

/* output:
 Original doubly linked list:
 100 200 300
 
 Altered doubly linked list:
 100 300
 
 Altered doubly linked list:
 100 250 300
*/
