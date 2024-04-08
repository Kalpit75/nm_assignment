#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define the function whose root we want to find
#define f(x) (3*x - cos(x) - 1)

// Define the derivative of the function
#define g(x) (3 + sin(x))

int main() {
    printf("newton raphson method:\n\n");
    float x0, x1, f0, f1, g0, tolerance;
    int step = 1, maxIterations;

    // Inputs
    printf("Enter initial guess:\n");
    scanf("%f", &x0);
    printf("Enter tolerable error:\n");
    scanf("%f", &tolerance);
    printf("Enter maximum number of iterations:\n");
    scanf("%d", &maxIterations);

    // Implementing Newton-Raphson Method
    printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
    do {
        // Calculate the function and its derivative at x0
        f0 = f(x0);
        g0 = g(x0);

        // Check for mathematical errors
        if (g0 == 0.0) {
            printf("Error: Division by zero occurred.\n");
            exit(EXIT_FAILURE);
        }

        // Compute the next approximation using Newton-Raphson formula
        x1 = x0 - f0 / g0;
        f1 = f(x1);

        // Display current step and values
        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\n", step, x0, f0, x1, f1);
        x0 = x1;

        step++;

        // Check if maximum iterations reached
        if (step > maxIterations) {
            printf("Error: Maximum iterations reached. Solution not found.\n");
            exit(EXIT_FAILURE);
        }
    } while (fabs(f1) > tolerance); // Repeat until the absolute value of f(x1) is less than the tolerance

    // Display the root
    printf("\nRoot is: %.6f\n", x1);

    return 0;
}
