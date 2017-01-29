#include <stdio.h>
#include <stdbool.h>

void substring (const char source[], int start, int count, char result[])
{
	int i = 0;
	
	while ( source[start] != '\0' && count > 0 ) /* only executes if not at end of source 
	AND if letter extraction can continue */
	{
		result[i] = source[start];
		++start;
		--count;
		++i;
	}
	
	result[i] = '\0';
}

int main (void)
{
	void substring (const char source[], int start, int count, char result[]);
	
	const char s1[] = "character";
	const char s2[] = "Goodbye!";
	const char s3[] = "Hello and goodbye!";
	char result[50];
	
	substring (s1, 4, 3, result);
	printf ("%s = %s\n", s1, result); // output: character = act
	
	substring (s2, 2, 3, result);
	printf ("%s = %s\n", s2, result); // output: Goodbye! = odb
	
	substring (s3, 6, 20, result);
	printf ("%s = %s\n", s3, result); // output: Hello and goodbye! = and goodbye!
	
	return 0;
}
