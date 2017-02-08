#include <stdio.h>
#include <stdbool.h>

int main (void)
{
	bool compareString (char *s1, char *s2);
	
	char s1[] = "This is a string";
	char s2[] = "This is a string";
	char s3[] = "This is a different string";
	bool isEqual;
	
	isEqual = compareString (s1, s2);
	isEqual ? printf ("\"%s\" equals \"%s\"\n", s1, s2) : printf ("\"%s\" does not equal \"%s\"\n", s1, s2);
	
	printf ("\n");
	
	isEqual = compareString (s2, s3);
	isEqual ? printf ("\"%s\" equals \"%s\"\n", s2, s3) : printf ("\"%s\" does not equal \"%s\"\n", s2, s3);
	
	return 0;
}

bool compareString (char *s1, char *s2)
{
	int i;
	
	for ( i = 0; *(s1 + i) != '\0' || *(s2 + i) != '\0'; ++i )
		if ( *(s1 + i) != *(s2 + i))
			return false;
	
	return true;
}

/* output:
 "This is a string" equals "This is a string"
 
 "This is a string" does not equal "This is a different string"
*/
