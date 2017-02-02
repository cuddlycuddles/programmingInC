#include <stdio.h>
#include <stdbool.h>

int strToInt (char number[])
{
	int i = 0;
	int integer = 0;
	bool isNegative = false;
	
	if ( number[i] == '-' )
	{
		isNegative = true;
		++i;
	}
	
	for ( i = i; number[i] != '\0'; ++i )
	{
		integer *= 10;
		integer += number[i] - '0';
	}
	
	if ( isNegative )
		integer *= -1;
	
	return integer;
}

int main (void)
{
	char num1[] = "1";
	char num2[] = "42";
	char num3[] = "-169";
	
	printf ("%s, %s, %s\n", num1, num2, num3);
	
	printf ("\n%i, %i, %i\n", strToInt (num1), strToInt (num2), strToInt (num3));
	
	return 0;
}
