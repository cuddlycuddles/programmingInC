#include <stdio.h>
#include <stdbool.h>

void substring (const char source[], int start, int count, char result[])
{
	int i = 0;
	
	while ( count > 0 )
	{
		result[i] = source[start];
		++start;
		--count;
		++i;
	}
	
	result[i] = '\0';
}

int findString (const char str[], const char sub[])
{
	int i, j = 0, k;
	
	for ( i = 0; str[i]; ++i )
	{
		if (str[i] == sub[j])
		{
			for ( k = i, j = 0; str[k] && sub[j]; ++k, ++j )
				if ( str[k] != sub[j] )
					break;
			if ( sub[j] == '\0' )
				return i;
		}
	}
	
	return -1;
}


int main (void)
{
	char string[] = "I want Federer to win the AUS OPEN 2017!";
	char search[] = "Federer";
	int index;
	
	index = findString (string, search);
	
	index > 0 ? printf ("\"%s\" contains \"%s\" (starting index: %i) \n", string, search, index) :
		        printf ("\"%s\" does not contain \"%s\"\n", string, search);
	
	return 0;
}
