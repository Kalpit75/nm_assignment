#include <stdio.h>

// Define the function f(x, y) representing the ODE dy/dx
double f(double x, double y) {
    return 1 + x + y; // Example ODE: dy/dx = 1 + x + y
}

// Heun's method to solve ODE y' = f(x, y)
double heun_method(double x0, double y0, double h, int steps) {
    double x = x0;
    double y = y0;
    
    for (int i = 0; i < steps; i++) {
        double slope1 = f(x, y);
        double slope2 = f(x + h, y + h * slope1);
        y += 0.5 * h * (slope1 + slope2); // Take the average of the slopes
        x += h;
    }
    
    return y;
}

int main() {
    double x0, y0, h;
    int steps;

    printf("Enter the initial value of x: ");
    scanf("%lf", &x0);
    printf("Enter the initial value of y: ");
    scanf("%lf", &y0);
    printf("Enter the step size (h): ");
    scanf("%lf", &h);
    printf("Enter the number of steps for Heun's method: ");
    scanf("%d", &steps);

    double result = heun_method(x0, y0, h, steps);
    printf("Approximate solution at x = %lf is y = %lf\n", x0 + h * steps, result);

    return 0;
}
