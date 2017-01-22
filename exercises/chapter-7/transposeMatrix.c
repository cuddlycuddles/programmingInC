#include <stdio.h>

void transposeMatrix (int r, int c, int matrix[10][10]) {
    int transpose[10][10], i, j;
    
    // transpose original matrix
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            transpose[j][i] = matrix[i][j];
    
    // display transposed matrix
    printf ("\nTransposed matrix: \n");
    for (i = 0; i < c; ++i)
        for (j = 0; j < r; ++j) {
            printf ("%-2d ", transpose[i][j]);
            if (j == r - 1)
                printf ("\n\n");
        }
}

int main (void) {
    int matrix[10][10], r, c, i, j;
    
    printf ("Enter number of rows: ");
    scanf ("%d", &r);
    
    printf ("Enter number of columns: ");
    scanf ("%d", &c);
    
    printf ("\nEnter elements of matrix: \n");
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            printf ("Row %d Element %d: ", i + 1, j + 1);
            scanf ("%d", &matrix[i][j]);
        }
        
        printf ("\n");
    }
    
    printf ("\nEntered matrix: \n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j) {
            printf ("%-2d ", matrix[i][j]);
            if (j == c - 1)
                printf ("\n\n");
        }

    transposeMatrix(r, c, matrix);
    
    return 0;
} 
