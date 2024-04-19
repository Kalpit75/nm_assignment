#include <stdio.h>
#include <math.h>

// Define the function f(x, y) representing the ODE dy/dx
double f(double x, double y) {
    return 1 + x + y; // Example ODE: dy/dx = 1 + x + y
}

// Picard's method to solve ODE y' = f(x, y)
double picard_method(double x0, double y0, double h, int iterations) {
    double y = y0;
    for (int i = 0; i < iterations; i++) {
        y = y0 + h * f(x0, y); // Update y using the formula of Picard's iteration
        y0 = y; // Update y0 for the next iteration
    }
    return y;
}

int main() {
    double x0, y0, h;
    int iterations;

    printf("Enter the initial value of x: ");
    scanf("%lf", &x0);
    printf("Enter the initial value of y: ");
    scanf("%lf", &y0);
    printf("Enter the step size (h): ");
    scanf("%lf", &h);
    printf("Enter the number of iterations for Picard's method: ");
    scanf("%d", &iterations);

    double result = picard_method(x0, y0, h, iterations);
    printf("Approximate solution at x = %lf is y = %lf\n", x0 + h * iterations, result);

    return 0;
}
