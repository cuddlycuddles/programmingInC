/* note: the program only accepts integers as patterns, 
therefore it can't correctly search for patterns starting with 0 (e.g. 0010101) */

#include <stdio.h>

int bitpat_search (unsigned int source, unsigned int pattern, int n);

int main (void)
{
	int x = 5, y = 21, z = 65; // x is 00000101, y is 00010101, z is 01000001
	
	int result = bitpat_search (x, 5, 3); // searching for 101, length of 3
	printf ("Source: %i \nPattern: 101\nPosition: %ith bit\n\n", x, result);
	
	result = bitpat_search (y, 21, 5); // searching for 10101, length of 5
	printf ("Source: %i \nPattern: 101\nPosition: %ith bit\n\n", y, result);
	
	result = bitpat_search (z, 32, 6); // searching for 100000, length of 6
	printf ("Source: %i \nPattern: 101\nPosition: %ith bit\n\n", z, result);
	
	result = bitpat_search (z, 5, 3); // searching for 101, length of 3
	printf ("Source: %i \nPattern: 101\nPosition: %ith bit\n", z, result);
	
	return 0;
}

int bitpat_search (unsigned int src, unsigned int pattern, int n)
{
	int digitPlace = 0;
	int srcCpy = src; // copy of src for comparison
	
	// used to calculate size of unsigned int on user's computer
	int a = 1;
	int intSize = 0;

	while (a)
	{
		a <<= 1;
		++intSize;
	}
	
	// loop to find the first left-most occurrence of 1
	while (srcCpy > 0)
	{
		srcCpy >>= 1;
		++digitPlace;
	}
	
	// loop to find the first occurrence of the pattern inside source
	do
	{
		srcCpy = src >> (digitPlace - n); // shift src so that it contains 'n' number of bits starting from the left-most 1
		
		if ((srcCpy ^ pattern) == 0)
		{
			return intSize - digitPlace; // return the starting index of where the pattern was found
		}
		else
		{
			--digitPlace; // decrement digitPlace so that srcCpy in the next iteration starts from the bit AFTER the left-most 1, and so on
			srcCpy &= ~(1 << digitPlace); // clear the current left-most 1 to 0
		}
	}
	while (srcCpy);
	
	return -1; // executes if pattern is not found
}

/* output:
 Source: 5
 Pattern: 101
 Position: 29th bit
 
 Source: 21
 Pattern: 101
 Position: 27th bit
 
 Source: 65
 Pattern: 101
 Position: 25th bit
 
 Source: 65
 Pattern: 101
 Position: -1th bit
 */
