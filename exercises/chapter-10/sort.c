#include <stdio.h>
#include <stdbool.h>

void sort (int *a, int n, bool asc_order)
{
	int i, j, temp;
	
	for ( i = 0; i < n - 1; ++i )
	{
		for ( j = i + 1; j < n; ++j )
		{
			if ( asc_order ? *(a + i) > *(a + j) : *(a + i) < *(a + j) ) // exchange values depending on order
			{
				temp = *(a + i);
				*(a + i) = *(a + j);
				*(a + j) = temp;
			}
		}
	}
}

int main (void)
{
	int array[5] = { 42, 69, 420, -16, -99 };
	bool asc_order;
	int input;
	int i;
	
	printf ("Current array: ");
	for ( i = 0; i < 5; ++i )
		printf ("%i ", array[i]);
	
  // retrieve desired order
	printf ("\nSort in ascending order? Enter 1 for Yes, 0 for No: ");
	scanf ("%d", &input);
	
	asc_order = input == 1 ? true : false;
	
	sort (array, 5, asc_order); // sort array
	
	printf ("\nSorted array: ");
	for ( i = 0; i < 5; ++i )
		printf ("%i ", array[i]);
	
	printf ("\n");
	
	return 0;
}
/* output:
 Current array: 42 69 420 -16 -99
 Sort in ascending order? Enter 1 for Yes, 0 for No: 1
 
 Sorted array: -99 -16 42 69 420
 */

