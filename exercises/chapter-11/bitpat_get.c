#include <stdio.h>

int bitpat_get (unsigned int src, int index, int count);

int main (void)
{
	int x = 9; // 00001001
	int xx;
	int y = 63; // 00111111
	int yy;
	int z;
	
	xx = bitpat_get (x, 28, 4);
	printf ("%i contains the bits of %i\n", x, xx);
	
	yy = bitpat_get (y, 26, 6);
	printf ("%i contains the bits of %i\n", y, yy);
	
	z = bitpat_get (y, 26, 4); // 1111
	printf ("%i contains the bits of %i\n", y, z);
	
	return 0;
}

int bitpat_get (unsigned int src, int index, int count)
{
	int totalBits = 0;
	int i = 1;
	while (i) // loop to determine total number of bits stored in unsigned int on user's particular computer
	{
		i <<= 1;
		++totalBits;
	}
	
	src <<= index; // remove any 0's to the left of the desired extraction
	src >>= (totalBits - count); // remove all 0's to the right of the desired extraction
	
	return src;
}

/* output:
 9 contains the bits of 9
 63 contains the bits of 63
 63 contains the bits of 15
 */
