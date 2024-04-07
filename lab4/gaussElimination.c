#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define SIZE 10

void printMatrix(float a[SIZE][SIZE], int n) {
    int i, j;
    printf("Matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n + 1; j++) {
            printf("%0.2f\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
	printf("gauss Elimination medthod\n\n");
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
    
	printf("\nInitial matrix is: \n");
    printMatrix(a, n); // Print the initial matrix
    
    /* Applying Gauss Elimination */
    for(i = 1; i <= n - 1; i++) {
        if(a[i][i] == 0.0) {
            printf("Mathematical Error!");
            exit(0);
        }
        for(j = i + 1; j <= n; j++) {
            ratio = a[j][i] / a[i][i];
            for(k = 1; k <= n + 1; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
        printMatrix(a, n); // Print the matrix after each step of elimination
    }
    
    /* Obtaining Solution by Back Substitution */
    x[n] = a[n][n + 1] / a[n][n];
    
    for(i = n - 1; i >= 1; i--) {
        x[i] = a[i][n + 1];
        for(j = i + 1; j <= n; j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }
    
    /* Displaying Solution */ 
    printf("\nSolution:\n");
    for(i = 1; i <= n; i++) {
        printf("x[%d] = %0.3f\n", i, x[i]);
    }
    getch();
    return(0);
}
