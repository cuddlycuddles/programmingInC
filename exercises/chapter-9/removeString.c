#include <stdio.h>
#include <stdbool.h>

void removeString (char string[], int index, int characters)
{
	int i, j;
	int endpoint = index + characters - 1; // point where removal of characters stops
	
	for ( i = 0, j = 0; string[i] != '\0'; ++i ) // loop to store required characters
	{
		if (i < index || i > endpoint) { // if character is not being removed
			string[j] = string[i];
			++j; // increment to prepare for remaining letters
		}
	}
	
	string[j] = '\0';
}
int main (void)
{
	void removeString (char string[], int index, int characters);
	char string[] = "the wrong son";
	char string2[] = "let's eat, grandpa!";
	
	printf ("String before removal: \"%s\"\n", string);
	removeString (string, 4, 6);
	printf ("String after removal: \"%s\"\n", string); // output: String after removal: "the son"
	
	printf ("\nString before removal: \"%s\"\n", string2);
	removeString (string2, 9, 1);
	printf ("String after removal: \"%s\"\n", string2); // output: String after removal: "let's eat grandpa!"
	
	return 0;
}
