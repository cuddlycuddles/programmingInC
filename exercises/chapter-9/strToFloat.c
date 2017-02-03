#include <stdio.h>
#include <stdbool.h>

double strToFloat (char number[])
{
	int i = 0;
	bool isNegative = false;
	bool pastDecimal = false;
	int numbersPastDecimal = 0;
	double floatVal = 0;
	
	if ( number[i] == '-' )
	{
		isNegative = true;
		++i;
	}
	
	for ( i = i; number[i] != '\0'; ++i )
	{
		if ( pastDecimal )
			++numbersPastDecimal;
		
		if ( number[i] == '.' )
			pastDecimal = true;
		else
		{
			floatVal *= 10;
			floatVal += (number[i] - '0');
		}
	}
	
	for ( i = 0; i < numbersPastDecimal; ++i )
	{
		floatVal /= 10;
	}
	
	if ( isNegative )
		floatVal *= -1;
	
	return floatVal;
}

int main (void)
{
	char floatingNum[] = "3.1415926535897";
	char floatingNum2[] = "-2.459389013895";
	
	printf ("String version: \n%s\n%s\n", floatingNum, floatingNum2);
	
	printf ("\nFloat version: \n%.15g\n%.15g\n", strToFloat (floatingNum), strToFloat (floatingNum2));
	
	return 0;
}

/* output:
 String version:
 3.1414926535897
 -2.459389013895
 
 Float version:
 3.1414926535897
 -2.459389013895
 */
