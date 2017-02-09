#include <stdio.h>

int main (void)
{
	char *message = "Programming in C is fun\n";
  	char message2[] = "You said it\n";
	char *format = "x + %i\n";
 	int x = 100;

	// set 1
	printf ("Programming in C is fun\n");
	printf ("%s", "Programming in C is fun\n");
	printf ("%s", message);
	printf (message); // prints out message, but causes Format String Issue: Format string is not a string literal (potentially insecure)
	
	// set 2
	
	printf ("You said it\n");
	printf ("%s", message2);
	printf (message2); // prints out message2, but causes Format String Issue: Format string is not a string literal (potentially insecure)
	printf ("%s", &message2[0]);
	
	// set 3
	printf ("said it\n");
	printf (message2 + 4); // prints out "said it\n" from message2, but causes Format String Issue - Format string is not a string literal (potentially insecure)
	printf ("%s", message2 + 4);
	printf ("%s", &message2[4]);
	
	// set 4
	printf ("x = %i\n", x); // prints out x = 100
	printf (format, x); // prints out x + 100, meaning that x was treated as an argument for the format character in format
	
	return 0;
}

/* output:
 Programming in C is fun
 Programming in C is fun
 Programming in C is fun
 Programming in C is fun
 You said it
 You said it
 You said it
 You said it
 said it
 said it
 said it
 said it
 x = 100
 x + 100
*/

