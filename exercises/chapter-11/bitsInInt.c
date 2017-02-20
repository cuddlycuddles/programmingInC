#include <stdio.h>

int int_size();

int main (void)
{
	printf ("On your particular machine, an int contains %i bits\n", int_size());
	return 0;
}

int int_size()
{
	int i = 1;
	int numberOfBits = 0;
	
	
	while (i) // continue to left shift until the 1 in the binary sequence is gone, therefore equating to zero
	{
		i <<= 1;
		++numberOfBits;
	}
	return numberOfBits;
}
