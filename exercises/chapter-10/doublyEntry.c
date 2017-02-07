#include <stdio.h>

struct ent
{
	struct ent *prev;
	int value;
	struct ent *next;
};

int main (void)
{
	struct ent n0, n1, n2, n3;
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
	
	// output from first to last
	listPtr = n0.next;
	while ( listPtr )
	{
		printf ("%i ", listPtr->value);
		listPtr = listPtr->next;
	}
	
	printf ("\n");
	
	// output from last to first;
	listPtr = &n3;
	while ( listPtr )
	{
		printf ("%i ", listPtr->value);
		listPtr = listPtr->prev;
	}
	
	printf ("\n");
	
	return 0;
}

/* output:
 100 200 300
 300 200 100
*/
