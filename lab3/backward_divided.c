#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("derivative using backward divided difference formula\n\n");

    float x[20], y[20], xp, h, derivative;
    int i, n;

    // Input the number of data points
    printf("Enter number of data points: ");
    scanf("%d", &n);

    // Input the data points (x, y)
    printf("Enter data points:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    // Input the value at which derivative is to be calculated
    printf("Enter the value of x at which derivative is to be calculated: ");
    scanf("%f", &xp);

    // Calculate h (step size)
    h = x[1] - x[0];

    // Find the index i at which xp lies in the data
    int index = -1;
    for (i = 1; i < n; i++) {
        if (x[i] >= xp) {
            index = i;
            break;
        }
    }

    // Check if xp is within the range of data points
    if (index == -1) {
        printf("Error: The value of x is not within the range of data points.\n");
        exit(1);
    }

    // Calculate the derivative using backward divided difference formula
    derivative = (y[index] - y[index - 1]) / (x[index] - x[index - 1]);

    // Print the calculated derivative
    printf("The derivative at x = %0.2f is: %0.2f\n", xp, derivative);

    return 0;
}
