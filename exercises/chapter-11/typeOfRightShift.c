#include <stdio.h>

int main (void)
{
	int test = -2147483647;
	
	printf ("Before right shift: %i\n", test);
	
	test >>= 1;
	
	printf ("After right shift: %i\n\n", test);
	
	if (test < 0)
	{
		printf ("Your computer performed an arithmetic right shift ");
		printf ("(the number was still a negative, meaning that a 1 on the left was shifted in, retaining the negative sign)\n");
	}
	else
	{
		printf ("Your computer performed a logical right shift ");
		printf ("(the number became positive, meaning that a 0 on the left was shifted in, losing the negative sign)\n");
	}
	return 0;
}
