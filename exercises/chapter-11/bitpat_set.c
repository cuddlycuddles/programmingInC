#include <stdio.h>

void bitpat_set (unsigned int *src, unsigned int val, int index, int field);

int main (void)
{
	unsigned int x = 42; // ...101010
	unsigned int y = 0; // ...000000
	unsigned int z = 32;// ...100000
	
	bitpat_set (&x, 0, 0, 31); // set all bits to zero
	printf ("%i\n", x);
	
	bitpat_set (&y, 42, 25, 6); // set bits to equal 42
	printf ("%i\n", y);
	
	bitpat_set (&z, 10, 27, 4); // put 1010 into 100000
	printf ("%i\n", z);
	
	return 0;
}

void bitpat_set (unsigned int *src, unsigned int val, int index, int field)
{
	int i = 1, bitSize = 0; // used to determine number of bits in unsigned int
	unsigned int left, right; // used to store the unaltered bits of src
	
	// determine number of bits in unsigned int
	while (i)
	{
		i <<= 1;
		++bitSize;
	}
	--bitSize;
	
	// retrieve bits on the left side of set area
	left = (*src >> (bitSize - index)) << (bitSize - index);
	
	// position val to align with index
	val <<= (bitSize - index - field);
	
	// retrieve bits on the right side of set area
	right = (*src << (index + field)) >> (index + field);
	
	// make all of the src bits 0, so val can be OR'd in
	*src = 0;
	
	// place left, val and right into val (note, doesn't override bits due to OR'ing)
	*src |= left | val | right;
}

/* output:
 0
 42
 42
*/
