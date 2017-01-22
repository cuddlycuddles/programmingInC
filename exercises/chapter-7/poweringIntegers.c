#include <stdio.h>

unsigned long int x_to_the_n (int x, int n)
{
    double result = x;
    int i;
    
    for (i = 1; i < n; ++i) {
        result *= x;
    }
    
    return result;
}

int main (void)
{
    int number, power;
    printf ("Enter number: ");
    scanf ("%i", &number);
    
    printf ("Enter power: ");
    scanf ("%i", &power);
    
    printf ("%i to the power of %i is %lu\n", number, power, x_to_the_n(number, power));
    
    return 0;
}
