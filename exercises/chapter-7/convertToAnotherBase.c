#include <stdio.h>
#include <stdbool.h>

int      convertedNumber[64];
long int numberToConvert;
int      base;
int		 digit = 0;
bool cont = true;

int getNumberAndBase (void) 
{
	bool invalidBase = true;
	
	printf ("Number to be converted? ");
	scanf ("%li", &numberToConvert);
	
	if (numberToConvert == 0) {
		cont = false;
		return -1;
	}
	
	while (invalidBase) {
		printf ("Base? ");
		scanf ("%i", &base);
		
		if (base < 2 || base > 16) {
			printf ("Invalid base - please insert a base between 2 and 16\n\n");
		} else {
			invalidBase = false;
		}
	}
	
	return 1;
}

void convertNumber (void) 
{
	do {
		convertedNumber[digit] = numberToConvert % base;
		++ digit;
		numberToConvert /= base;
	}
	while (numberToConvert != 0);
}

void displayConvertedNumber (void) 
{
	const char baseDigits[16] =
		{ '0', '1', '2', '3', '4', '5', '6', '7',
		  '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	int nextDigit;
	
	printf ("Converted number = ");
	
	for (-- digit; digit >= 0; --digit) {
		nextDigit = convertedNumber[digit];
		printf ("%c", baseDigits[nextDigit]);
	}
	
	printf ("\n\n");
}

int main (void) 
{
	while (cont) {
		getNumberAndBase();
		if (!cont)
			break;
		convertNumber();
		displayConvertedNumber();
	}
	
    return 0;
} 
