#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

void removeString (char string[], int index, int characters)
{
	int i, j;
	char copy[80];
	unsigned long stringLength = strlen (string);
	int endpoint = index + characters - 1; // point where removal of characters stops
	
	for ( i = 0, j = 0; string[i] != '\0'; ++i ) // loop to store required characters
		if (i < index || i > endpoint) { // if character is not being removed
			copy[j] = string[i];
			++j; // increment to prepare for remaining letters
		}
	copy[j] = '\0';
	
	for ( i = 0; i < stringLength; ++i ) // initialising string array
		string[i] = 0;
	
	for ( i = 0; copy[i] != '\0'; ++i ) // copying altered version of string into string
		string[i] = copy[i];
}

bool replaceString (char string[], char search[], char replace[])
{
	int position = findString (string, search);
	unsigned long replaceLength = strlen (replace) - 1;
	unsigned long searchLength = strlen (search);
	
	if ( position != -1 )
	{
		removeString (string, position, searchLength);
		insertString (string, replace, position);
		return true;
	}
	
	return false;
}

int main (void)
{
	char string[80] = "the mitochondria is the powerhouse of the cell";
	char search[] = "the";
	char replace[] = "a";
	bool stillFound;
	
	do
	{
		stillFound = replaceString (string, search, replace);
	}
	while ( stillFound );
	
	printf ("%s\n", string); // output: a mitochondria is a powerhouse of a cell

	return 0;
}
