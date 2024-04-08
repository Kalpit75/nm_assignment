#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define the function whose root we want to find
#define f(x) (x*x*x - 2*x - 5)

int main() {
    printf("a program to implement secant method:\n\n");
    float x0, x1, x2, f0, f1, f2, tolerance;
    int step = 1, maxIterations;

    // Inputs
    printf("Enter initial guesses:\n");
    scanf("%f %f", &x0, &x1);
    printf("Enter tolerable error:\n");
    scanf("%f", &tolerance);
    printf("Enter maximum number of iterations:\n");
    scanf("%d", &maxIterations);

    // Implementing Secant Method
    printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    do {
        // Calculate functional values at x0 and x1
        f0 = f(x0);
        f1 = f(x1);

        // Check if two points are too close or function is constant
        if (f0 == f1) {
            printf("Error: Unable to proceed due to mathematical reasons.\n");
            exit(EXIT_FAILURE);
        }

        // Calculate the new approximation using Secant method
        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
        f2 = f(x2);

        // Display current step and values
        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\n", step, x0, x1, x2, f2);

        // Update the points for next iteration
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;

        step++;

        // Check if maximum iterations reached
        if (step > maxIterations) {
            printf("Error: Maximum iterations reached. Solution not found.\n");
            exit(EXIT_FAILURE);
        }
    } while (fabs(f2) > tolerance); // Continue until the absolute value of f(x2) is less than the tolerance

    // Display the root
    printf("\nRoot is: %.6f\n", x2);

    return 0;
}
