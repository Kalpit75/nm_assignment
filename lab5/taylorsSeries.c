#include<stdio.h>
#include<conio.h>
#include<math.h>

/* Define the function f(x,y) */
double f(double x, double y) {
    return x + y; // Example function, you can modify this according to your ODE
}

/* Define the derivative of f(x,y) with respect to x */
double df_dx(double x, double y) {
    return 1; // Derivative of x with respect to x is 1
}

/* Define the derivative of f(x,y) with respect to y */
double df_dy(double x, double y) {
    return 1; // Derivative of y with respect to y is 1
}

int main() {
    printf("solve ODE by using taysors series method\n\n");
    double x0, y0, xn, h, yn;
    int n, i;

//    clrscr();

    /* Input */
    printf("Enter Initial Condition\n");
    printf("x0 = ");
    scanf("%lf", &x0);
    printf("y0 = ");
    scanf("%lf", &y0);
    printf("Enter calculation point xn = ");
    scanf("%lf", &xn);
    printf("Enter number of steps: ");
    scanf("%d", &n);

    /* Calculating step size (h) */
    h = (xn - x0) / n;

    /* Taylor's Series Method */
    yn = y0;
    printf("\nx\t\ty\n");
    printf("-----------------\n");
    for(i = 0; i < n; i++) {
        yn = yn + h * (f(x0, yn) + 0.5 * h * (df_dx(x0, yn) + df_dy(x0, yn) * f(x0, yn)));
        x0 = x0 + h;
        printf("%.4f\t%.4f\n", x0, yn);
    }

    /* Displaying result */
    printf("\nValue of y at x = %.2f is %.3f", xn, yn);

    getch();
    return 0;
}
