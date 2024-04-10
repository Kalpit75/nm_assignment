#include <stdio.h>

void do_little(float matrix[][3], float lower[][3], float upper[][3], float b[], float x[]) {
    int i, j, k;
    int n = 3; // Size of the matrix

    // Perform LU decomposition
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            float sum = 0;
            for (k = 0; k < i; k++) {
                sum += lower[i][k] * upper[k][j];
            }
            upper[i][j] = matrix[i][j] - sum;
        }

        for (j = i; j < n; j++) {
            if (i == j)
                lower[i][i] = 1;
            else {
                float sum = 0;
                for (k = 0; k < i; k++) {
                    sum += lower[j][k] * upper[k][i];
                }
                lower[j][i] = (matrix[j][i] - sum) / upper[i][i];
            }
        }
    }

    // Solve Ly = b
    for (i = 0; i < n; i++) {
        float sum = 0;
        for (j = 0; j < i; j++) {
            sum += lower[i][j] * x[j];
        }
        x[i] = b[i] - sum;
    }

    // Solve Ux = y
    for (i = n - 1; i >= 0; i--) {
        float sum = 0;
        for (j = i + 1; j < n; j++) {
            sum += upper[i][j] * x[j];
        }
        x[i] = x[i] / upper[i][i];
    }
}

void print_matrix(float matrix[][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("do Little LU Decomposition:\n\n");
    float matrix[3][3], b[3], lower[3][3] = {0}, upper[3][3] = {0}, x[3] = {0};

    printf("Enter the coefficients of the 3x3 matrix:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%f", &matrix[i][j]);

    printf("Enter the values of the right-hand side vector (b):\n");
    for (int i = 0; i < 3; i++)
        scanf("%f", &b[i]);

    do_little(matrix, lower, upper, b, x);

    printf("\nLower triangular matrix:\n");
    print_matrix(lower, 3);

    printf("\nUpper triangular matrix:\n");
    print_matrix(upper, 3);

    printf("\nSolution vector (X):\n");
    for (int i = 0; i < 3; i++)
        printf("%.2f\n", x[i]);

    return 0;
}
