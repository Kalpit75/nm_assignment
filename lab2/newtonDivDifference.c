#include <stdio.h>
void DivDif(double x[], double y[], double dd[][10], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        dd[i][0] = y[i];
    }
    for(j = 1; j < n; j++) {
        for(i = 0; i < n-j; i++) {
            dd[i][j] = (dd[i+1][j-1] - dd[i][j-1]) / (x[i+j] - x[i]);
        }
    }
}
double Interpolation(double x[], double y[], double dd[][10], int n, double xi) {
    double result = dd[0][0]; // Initialize result with the first divided difference
    double term = 1.0;
    int i, j;

    for(i = 1; i < n; i++) {
        term = term * (xi - x[i-1]);
        result = result + (dd[0][i] * term);
    }

    return result;
}

int main() {
    printf("newton's divide differnce interpolation\n\n");
    int n, i;
    double x[10], y[10], xi, result;
    double dd[10][10];

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter the data for x:\n");
    for(i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    printf("Enter the data for y:\n");
     for(i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
    }

    DivDif(x, y, dd, n);

    printf("Enter the value of xi for interpolation: ");
    scanf("%lf", &xi);
    result = Interpolation(x, y, dd, n, xi);
    
    printf("Interpolated value at xi = %.2lf is %.6lf\n", xi, result);

    return 0;
}
