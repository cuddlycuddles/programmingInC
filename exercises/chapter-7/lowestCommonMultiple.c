#include <stdio.h>

int gcd (int u, int v) {
    int temp;
    
    while (v != 0) {
        temp = u % v;
        u = v;
        v = temp;
    }
    
    return u;
}

int lcm (int u, int v) {
    int result;
    int gcd (int u, int v);
    
    result = (u * v) / gcd(u, v);
    
    return result;
}

int main (void) {
    int u, v;
    
    printf ("Enter first number: ");
    scanf ("%i", &u);
    
    printf ("Enter second number: ");
    scanf ("%i", &v);
    
    printf ("The lowest common multiple of %i and %i is %i.\n", u, v, lcm(u, v));
}
