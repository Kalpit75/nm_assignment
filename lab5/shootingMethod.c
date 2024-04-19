#include <stdio.h>
#include <math.h>

// Define the ODE: y'' = f(x, y, y')
double f(double x, double y, double yp) {
    return -y; // Example ODE: y'' = -y
}

// Runge-Kutta 4th order method for solving the IVP
double runge_kutta(double x, double y, double yp, double h) {
    double k1 = h * yp;
    double l1 = h * f(x, y, yp);
    double k2 = h * (yp + 0.5 * l1);
    double l2 = h * f(x + 0.5 * h, y + 0.5 * k1, yp + 0.5 * l1);
    double k3 = h * (yp + 0.5 * l2);
    double l3 = h * f(x + 0.5 * h, y + 0.5 * k2, yp + 0.5 * l2);
    double k4 = h * (yp + l3);
    double l4 = h * f(x + h, y + k3, yp + l3);
    
    double delta_y = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    double delta_yp = (l1 + 2 * l2 + 2 * l3 + l4) / 6;
    
    return y + delta_y;
}

// Shooting method to solve the BVP
double shooting_method(double x0, double y0, double yp1_guess, double yp2_guess, double h, double xmax, double y_target, double tolerance) {
    double yp1 = yp1_guess;
    double yp2 = yp2_guess;
    
    double y1, y2;
    do {
        y1 = runge_kutta(x0, y0, yp1, h);
        y2 = runge_kutta(x0, y0, yp2, h);
        double new_yp2 = yp2 - (y2 - y_target) * (yp2 - yp1) / (y2 - y1);
        yp1 = yp2;
        yp2 = new_yp2;
    } while (fabs(y2 - y_target) > tolerance);
    
    return y2;
}

int main() {
    double x0, y0, yp1_guess, yp2_guess, h, xmax, y_target, tolerance;

    printf("Enter the initial value of x: ");
    scanf("%lf", &x0);
    printf("Enter the initial value of y: ");
    scanf("%lf", &y0);
    printf("Enter the initial guess for y'(x0): ");
    scanf("%lf", &yp1_guess);
    printf("Enter another initial guess for y'(x0): ");
    scanf("%lf", &yp2_guess);
    printf("Enter the step size (h): ");
    scanf("%lf", &h);
    printf("Enter the maximum value of x: ");
    scanf("%lf", &xmax);
    printf("Enter the desired value of y(xmax): ");
    scanf("%lf", &y_target);
    printf("Enter the tolerance for convergence: ");
    scanf("%lf", &tolerance);

    double result = shooting_method(x0, y0, yp1_guess, yp2_guess, h, xmax, y_target, tolerance);
    printf("Approximate solution at x = %lf is y = %lf\n", xmax, result);

    return 0;
}
