#include <stdio.h>
#include <stdbool.h>

void intToStr (char string[], int number)
{
	int i = 0, j = 0;
	char temp[20] = {};
	bool isNegative = false;
	
	if ( number < 0 ) // if negative number, first string element is minus sign
	{
		isNegative = true;
		number *= -1;
		string[j] = '-';
		++j;
	}
	
	while ( number != 0 )
	{
		temp[i] = number % 10 + '0';
		number /= 10;
		++i;
	} // temp becomes reversed version of number
	
	for ( --i; i >= 0; --i, ++j ) // place temp into string in proper order
	{
		string[j] = temp[i];
	}
	
	string[j] = '\0';
}

int main (void)
{
	int n1 = 142857;
	int n2 = -5625;
	char s1[20];
	char s2[20];
	
	printf ("Integer form:\n%i\n%i\n", n1, n2);
	
	intToStr (s1, n1);
	intToStr (s2, n2);
	
	printf ("\nString form:\n%s\n%s\n", s1, s2);
	
	return 0;
}

/* output:
 Integer form:
 142857
 -5625
 
 String form:
 142857
 -5625
 */
