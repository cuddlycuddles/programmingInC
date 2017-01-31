#include <stdio.h>

void insertString (char string[], char insert[], char position)
{
	int i, j;
	int insertLength;
	int stringLength;
	char after[50];
	
	for ( i = 0; insert[i] != '\0'; ++i ) // calculate inserted string length
		++insertLength;
	
	for ( i = 0; string[i] != '\0'; ++i ) // calculate original string length
		++stringLength;

	for ( i = position, j = 0; string[i] != '\0'; ++i, ++j ) // save letters past insertion point
		after[j] = string[i];
	
	for ( i = position, j = 0; i < position + insertLength; ++i, ++j ) // insert letters from inserted string
		string[i] = insert[j];
	
	stringLength += insertLength;
	
	for ( i = position + insertLength, j = 0; i < stringLength; ++i, ++j) // insert letters past insertion point
		string[i] = after[j];
}

int main (void)
{
	
	char string[80] = "the wrong son";
	
	char insert[] = "per";
	
	printf ("%s\n", string);
	
	insertString (string, insert, 10);
	
	printf ("%s\n", string);
	
	return 0;
}
