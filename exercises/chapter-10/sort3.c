#include <stdio.h>

int main (void)
{
	void sort3 (int x, int y, int z);
	int x, y, z; // three numbers
	
	printf ("Enter three numbers to be sorted: ");
	scanf ("%i %i %i", &x, &y, &z);
	
	sort3 (x, y, z);
  
  return 0;
}

void sort3 (int x, int y, int z)
{
	int temp;
	
	if ( x > y )
	{
		temp = x;
		x = y;
		y = temp;
	}
	
	if ( x > z )
	{
		temp = x;
		x = z;
		z = temp;
	}
	
	if ( y > z )
	{
		temp = y;
		y = z;
		z = temp;
	}
	
	printf ("%i %i %i\n", x, y, z);
}

/* output:
 Enter three numbers to be sorted: 1 5 2
 1 2 5
*/
