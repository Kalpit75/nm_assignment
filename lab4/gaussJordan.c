#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define SIZE 10

void printMatrix(float a[SIZE][SIZE], int n) {
    int i, j;
    printf("\nCurrent Matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n + 1; j++) {
            printf("%0.2f\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
	printf("gauss Jordan medthod\n\n");

    float a[SIZE][SIZE], x[SIZE], ratio;
    int i, j, k, n;
    
    /* Inputs */
    /* 1. Reading number of unknowns */
    printf("Enter number of unknowns: ");
    scanf("%d", &n);
    
    /* 2. Reading Augmented Matrix */
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n + 1; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    
    printMatrix(a, n); // Print the initial matrix
    
    /* Applying Gauss-Jordan Elimination */
    for(i = 1; i <= n; i++) {
        // printf("-------------------------------------");
        printf("\n\nProcessing column %d\n", i);
        if(a[i][i] == 0.0) {
            printf("Mathematical Error!");
            exit(0);
        }
        for(j = 1; j <= n; j++) {
            if(i != j) {
                ratio = a[j][i] / a[i][i];
                // printf("Subtracting %0.2f times row %d from row %d\n", ratio, i, j);
                printf("Row%d = Row%d - (%0.2f * Row%d)\n", j,j, ratio, i);
                for(k = 1; k <= n + 1; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
        printMatrix(a, n); // Print the matrix after each step
    }
    
    /* Scaling the rows to make diagonal elements 1 */
    for(i = 1; i <= n; i++) {
        ratio = a[i][i];
        printf("Scaling Row%d by dividing by %0.2f\n", i, ratio);
        for(j = 1; j <= n + 1; j++) {
            a[i][j] = a[i][j] / ratio;
        }
    }

    printMatrix(a, n);
    
    /* Displaying Solution */ 
    printf("\nSolution:\n");
    for(i = 1; i <= n; i++) {
        printf("x[%d] = %0.3f\n", i, a[i][n + 1]);
    }
    
    getch();
    return(0);
}
