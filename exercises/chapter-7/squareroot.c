#include <stdio.h>

double absoluteValue (double x) { 
    if (x < 0)
        x = -x;
    return x;
}

double squareRoot (double x, double ep) {
    double guess = 1.0;
    
    while (absoluteValue (guess * guess - x) >= ep) {
        guess = (x / guess + guess) / 2.0;
        printf ("%lf\n", guess);
    }
    
    return guess;
}

int main(void) {
    printf ("squareRoot (5625.0) = %.16f\n", squareRoot (5625, 0.00001));

    return 0;
} 
