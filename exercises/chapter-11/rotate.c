#include <stdio.h>

int int_size();
unsigned int rotate (unsigned int value, int n);

int main (void)
{
	unsigned int w1 = 0xabcdef00u, w2 = 0xffff1122u;
	unsigned int rotate (unsigned int value, int n);
	
	printf ("%x\n", rotate(w1, 8));
	printf ("%x\n", rotate(w1, -16));
	printf ("%x\n", rotate(w2, 4));
	printf ("%x\n", rotate(w2, -2));
	printf ("%x\n", rotate(w1, 0));
	printf ("%x\n", rotate(w1, 44));
	
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

unsigned int rotate (unsigned int value, int n)
{
	unsigned int result, bits;
	int bitNumber = int_size();
	
	// scale down the shift count to a defined range
	
	if ( n > 0 )
		n = n % bitNumber;
	else
		n = -(-n % bitNumber);
	
	if ( n == 0 )
	{
		result = value;
	}
	else if ( n > 0 )
	{
		// shall left rotate
		bits = value >> (bitNumber - n);
		result = value << n | bits;
	}
	else
	{
		// shall right rotate
		n = -n;
		bits = value << (bitNumber - n);
		result = value >> n | bits;
	}
	
	return result;
}

/* output:
 cdef00ab
 ef00abcd
 fff1122f
 bfffc448
 abcdef00
 def00abc
*/
