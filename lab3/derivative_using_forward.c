#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_DATA_POINTS 20

/* Function to calculate power */
float power(float base, int exponent) {
    float result = 1.0;
    int i;
    for (i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {

    printf("derivative using forward difference formula\n\n");

    float x[MAX_DATA_POINTS], y[MAX_DATA_POINTS][MAX_DATA_POINTS], xp, h, sum = 0.0, term, first_derivative;
    int i, j, n, index, flag = 0, sign = 1;

    /* Reading number of data */
    printf("Enter number of data points: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_DATA_POINTS) {
        printf("Invalid number of data points. Exiting...\n");
        return 1;
    }

    /* Reading actual data of x and y */
    printf("Enter data:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i][0]);
    }

    /* Reading calculation point */
    printf("Enter the value of x where you want to calculate the derivative: ");
    scanf("%f", &xp);

    /* Checking whether given point (xp) is a valid point in x data or not */
    for (i = 0; i < n; i++) {
        if (fabs(xp - x[i]) < 0.0001) {
            /* index of calculation point */
            index = i;
            flag = 1;
            break;
        }
    }

    /* If flag is still 0 then given point (xp) is not a valid point (not in list of x data) for this calculation */
    if (flag == 0) {
        printf("Invalid calculation point. Program exiting...\n");
        return 1;
    }

    /* Generating Forward Difference Table */
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    /* Calculate finite difference */
    h = x[1] - x[0];

    /* Applying formula for calculating sum of different terms in formula to find derivatives using forward difference formula */
    for (i = 1; i < n - index; i++) {
        term = power(y[index][i], i) / (float)i;
        sum = sum + sign * term;
        sign = -sign;
    }

    /* Dividing by h */
    first_derivative = sum / h;

    /* Displaying final result */
    printf("First derivative at x = %.2f is %.2f\n", xp, first_derivative);

    return 0;
}
