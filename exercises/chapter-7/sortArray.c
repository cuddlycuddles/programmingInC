#include <stdio.h>
#include <stdbool.h>

void sortArray (int a[], int n, bool asc_order) {
    int i, j, temp;
    
    for (i = 0; i < n - 1; ++i)
        for (j = i + 1; j < n; ++j)
            // sort depending if user entered yes or no
            if (asc_order > 0 ? a[i] > a[j] : a[i] < a[j]) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
            }
}

int main (void) {
    int i;
    int array[6] = { 1, 4, 29, -35, 44, 18 };
    bool asc_order;
    int order;
    void sort (int a[], int n, bool asc_order);
    
    printf ("The array before the sort:\n");
    
    for (i = 0; i < 6; ++i)
        printf ("%i ", array[i]);
    
    printf ("\n\nSort in ascending order? Enter 1 for Yes, 0 for No. ");
    scanf ("%d", &order);
    
    asc_order = order == 1 ? true : false;
    
    sortArray (array, 6, asc_order);
    
    printf ("\nThe array after the sort:\n");
    
    for (i = 0; i < 6; ++i)
        printf ("%i ", array[i]);
    
    printf ("\n");
    
    return 0;
}
