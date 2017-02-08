#include <stdio.h>

int main (void)
{
	
	char line[80];
	void readLine (char *line);
	
	printf ("Enter a string (press enter when done): \n");
	
	readLine (line);
	
	printf ("Your string is: \n%s\n", line);
}

void readLine (char *line)
{
	char c;
	char *ptr = line;
	do
	{
		c = getchar();
		*ptr = c;
		++ptr;
	}
	while ( c != '\n' );
	
	*ptr = '\0';
}

/* output:
 Enter a string (press enter when done):
 Here in my garage, just bought this uh new Lamborghini here
 Your string is:
 Here in my garage, just bought this uh new Lamborghini here
 */
