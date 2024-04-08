#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

// Function to perform Newton's forward difference interpolation
double newtonForwardDifference(double x[], double y[], int n, double xi) {
    double result = 0.0, term = 1.0, h = x[1] - x[0];

    // Calculate divided differences
    double dd[n][n];
    for (int i = 0; i < n; ++i) {
        dd[i][0] = y[i];
    }
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            dd[i][j] = dd[i + 1][j - 1] - dd[i][j - 1];
        }
    }

    // Calculate interpolated value at xi
    result = y[0]; // First term
    term = (xi - x[0]) / h;
    for (int j = 1; j < n; ++j) {
        result += (term * dd[0][j]) / factorial(j);
        term *= (xi - x[0] - j * h) / h;
    }

    return result;
}

int main() {
    printf("newton's forward difference interpolation\n\n");
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n], xi;
    printf("Enter the data points (x, y):\n");
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    printf("Enter the value of xi for interpolation: ");
    scanf("%lf", &xi);

    double result = newtonForwardDifference(x, y, n, xi);
    printf("Interpolated value at xi = %.2lf is %.6lf\n", xi, result);

    return 0;
}
