#include <stdio.h>

void upperCase (char string[])
{
	int i;
	
	for ( i = 0; string[i] != '\0'; ++i )
		if ( string[i] >= 'a' && string[i] <= 'z' )
			string[i] = string[i] - 'a' + 'A';
}

int main (void)
{
	char string[] = "this is all lowercase";
	
	printf ("String before conversion: %s\n", string);
	
	upperCase (string);
	
	printf ("String after conversion: %s\n", string);
	
	return 0;
}

/* output:
 String before conversion: this is all lowercase
 String after conversion: THIS IS ALL LOWERCASE
 */
