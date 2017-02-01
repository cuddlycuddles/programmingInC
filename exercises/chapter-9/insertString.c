#include <stdio.h>

void insertString (char string[], char insert[], char position)
{
	int i, j;
	unsigned long insertLength;
	unsigned long stringLength;
	char after[50];
	
	stringLength = strlen (string);
	insertLength = strlen (insert);
	
	for ( i = position, j = 0; string[i] != '\0'; ++i, ++j ) // save letters past insertion point
		after[j] = string[i];
	
	for ( i = position, j = 0; i < position + insertLength; ++i, ++j ) // insert letters from inserted string
		string[i] = insert[j];
	
	stringLength += insertLength;
	position += insertLength;
	
	for ( i = position, j = 0; i < stringLength; ++i, ++j) // insert letters past insertion point
		string[i] = after[j];
}

int main (void)
{
	
	char string[80] = "the wrong son";
	
	char insert[] = "per";
	
	printf ("%s\n", string); // output: the wrong son
	
	insertString (string, insert, 10);
	
	printf ("%s\n", string); // output: the wrong person
	
	return 0;
}
