#include <stdio.h>

int bit_test (unsigned int num, int n);
int bit_set (unsigned int num, int n);

int main (void)
{
	int a = -2147483647;
	printf ("%i\n", bit_test(a, 0));
	
	int b = 16; // 00010000, the 1 digit is in the 28th position
	printf ("%i\n", bit_test(b, 28));
	
	int c = 4; // 0100
	printf ("%i\n", bit_set (c, 32));
	
	return 0;
}

int bit_test (unsigned int num, int n)
{
	int bit;
	
	bit = (num >> (32 - n)) & 1;
	
	return bit;
}

int bit_set (unsigned int num, int n)
{
	num |= (1 << (32 - n));
	
	return num;
}

/* output:
 1
 1
 5
 */
/*
