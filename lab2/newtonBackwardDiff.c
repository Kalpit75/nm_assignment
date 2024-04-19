#include <stdio.h>
#include<conio.h>

// Function to perform Newton's backward difference interpolation
double newtonBackwardDifference(double x[], double y[], int n, double xi) {
    double result = 0.0, term = 1.0, h = x[1] - x[0];

    // Calculate divided differences
    double dd[n][n];
    for ( int i = 0; i < n; ++i)
	{
		dd[i][0] = y[i];
	} 
    for (int j = 1; j < n; ++j)
        for (int i = n - 1; i >= j; --i)
            dd[i][j] = dd[i][j - 1] - dd[i - 1][j - 1];

    // Calculate interpolated value at xi
    result = y[n - 1]; // Last term
    term = (xi - x[n - 1]) / h;
    for (int j = 1; j < n; ++j) {
        result += (term * dd[n - 1][j]);
        term *= (xi - x[n - 1] + j * h) / h;
    }

    return result;
}

int main() {
    printf("newton's backward difference interpolation:\n\n");
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n], xi;
    printf("Enter the data points (x, y):\n");
    for (int i = 0; i < n; ++i) scanf("%lf %lf", &x[i], &y[i]);

    printf("Enter the value of xi for interpolation: ");
    scanf("%lf", &xi);

    double result = newtonBackwardDifference(x, y, n, xi);
    printf("Interpolated value at xi = %.2lf is %.6lf\n", xi, result);
	getch();
    return 0;
}
