#include <stdio.h>
#include <math.h>

// Define the function whose root we want to find
double function(double x) {
    return cos(x) - x * exp(x);
}

int main() {
    double x0, x1, x2, f0, f1, f2, tolerance;
    int step = 1;

    // Ask the user for initial guesses
    printf("Enter two initial guesses:\n");
    scanf("%lf %lf", &x0, &x1);

    // Ask the user for the tolerable error
    printf("Enter the tolerable error:\n");
    scanf("%lf", &tolerance);

    // Calculate the functional values at initial guesses
    f0 = function(x0);
    f1 = function(x1);

    // Check if initial guesses bracket the root
    if (f0 * f1 > 0) {
        printf("The initial guesses do not bracket the root. Please provide different guesses.\n");
        return 1; // Exit the program with error code
    }

    // Apply the bisection method
    printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    do {
        // Calculate the midpoint
        x2 = (x0 + x1) / 2;
        f2 = function(x2);

        // Display current step and values
        printf("%d\t\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n", step, x0, x1, x2, f2);

        // Update the interval based on the sign of f(x2)
        if (f0 * f2 < 0) {
            x1 = x2;
            f1 = f2;
        } else {
            x0 = x2;
            f0 = f2;
        }

        // Increment the step counter
        step++;
    } while (fabs(f2) > tolerance); // Repeat until the absolute value of f(x2) is less than the tolerance

    // Display the root
    printf("\nRoot is: %.6lf\n", x2);

    return 0;
}
