#include <stdio.h>

int arraySum (int array[], int numberOfElements) {
    int i, total;
    
    for (i = 0; i < numberOfElements; ++i) {
        total += array[i];
    }
    
    return total;
}

int main (void) {
    int array[10] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    int i;
    
    for (i = 0; i < 10; ++i)
        printf ("array[%i] = %2i\n", i, array[i]);
    
    printf ("The sum of the elements in the array is %i.\n", arraySum(array, 10));
    
    return 0;
}
