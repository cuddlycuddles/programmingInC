#include <stdio.h>

int prime (int num) {
    int i;
    
    for (i = 2; i < num; ++i) {
        if (num % i == 0)
            return 0;
    }
    
    return 1;
}

int main (void) {
    int number;
    
    printf ("Enter value to check if prime: ");
    scanf ("%i", &number);
    
    if (prime(number))
        printf ("Yes, it's prime.\n");
    else
        printf ("No, it's not prime.\n");
    
    
    return 0;
}
