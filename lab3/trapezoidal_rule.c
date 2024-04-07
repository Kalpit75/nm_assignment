#include <stdio.h>
#include <math.h>

// Function to calculate the value of the function f(x)
float f(float x) {
    return sin(x); // Sine function
}

int main() {
    float a, b, h, integral;
    int n, i;

    // Input the interval [a, b]
    printf("Enter the lower limit (a): ");
    scanf("%f", &a);
    printf("Enter the upper limit (b): ");
    scanf("%f", &b);

    // Input the number of subintervals
    printf("Enter the number of subintervals (n): ");
    scanf("%d", &n);

    // Calculate the step size (h)
    h = (b - a) / n;

    // Initialize the integral value
    integral = 0.0;

    // Apply the trapezoidal rule
    integral += (f(a) + f(b)) / 2.0; // Add the first and last terms

    for (i = 1; i < n; i++) {
        integral += f(a + i * h); // Add the intermediate terms
    }

    integral *= h; // Multiply by the step size

    // Print the result
    printf("The integral of the function over the interval [%0.2f, %0.2f] using the trapezoidal rule with %d subintervals is: %0.6f\n", a, b, n, integral);

    return 0;
}
