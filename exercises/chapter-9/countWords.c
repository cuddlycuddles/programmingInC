#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isLetter (const char c)
{
	if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		return true;
	else
		return false;
}

bool isNotSpace (const char c)
{
	return c != 32 ? true : false; // checks if the character is a space
}

int countWords (const char string[])
{
	int i, totalWords = 0;
	unsigned long int stringLength = strlen (string); // int is 32, strlen uses 64 bits
	bool lookingForWord = true, isLetter (const char c), isSpace (const char c);
	
	for ( i = 0; i < stringLength; ++i )
		if ( isLetter(string[i]) )
		{
			if ( lookingForWord )
			{
				++totalWords;
				lookingForWord = false;
			}
		} else if ( isNotSpace(string[i]) ) // ignores non-space characters, such as apostrophes, commas etc.
			lookingForWord = false;
		else
			lookingForWord = true;
	
	return totalWords;
}

int main (void)
{
	const char string[] = "Test number one! 3.14159 is pi.";
	int totalWords;
	
	printf ("%s", string);
	
	totalWords = countWords (string);
	
	printf ("\nThe number of words in the above sentence is %i words.\n", totalWords);
	
	return 0;
}
