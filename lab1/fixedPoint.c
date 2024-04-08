#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// Define the function whose root we want to find
#define f(x) (cos(x) - 3*x + 1)

// Define the function for Fixed Point Iteration
#define g(x) ((1 + cos(x)) / 3)

int main() {
    printf("fixed point iteration method:\n\n");
    int step = 1, max_iter;
    float x0, x1, tolerance;

    // Inputs
    printf("Enter initial guess: ");
    scanf("%f", &x0);
    printf("Enter tolerable error: ");
    scanf("%f", &tolerance);
    printf("Enter maximum number of iterations: ");
    scanf("%d", &max_iter);

    // Implementing Fixed Point Iteration
    printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
    do {
        // Calculate the next approximation
        x1 = g(x0);

        // Display current step and values
        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\n", step, x0, f(x0), x1, f(x1));

        // Update x0 for next iteration
        x0 = x1;

        // Increment the step counter
        step++;

        // Check if maximum iterations reached
        if (step > max_iter) {
            printf("Error: Maximum iterations reached. Solution not found.\n");
            exit(EXIT_FAILURE);
        }
    } while (fabs(f(x1)) > tolerance); // Repeat until the absolute value of f(x1) is less than the tolerance

    // Display the root
    printf("\nRoot is: %.6f\n", x1);

    return 0;
}
