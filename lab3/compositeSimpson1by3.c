#include <stdio.h>
#include <math.h>

#define MAX_DEGREE 10

float constants[MAX_DEGREE + 1];
int degree, square;

void getConstants(int n) {
    printf("Enter the constants: \n");
    for (int i = 0; i <= n; i++) {
        printf("a[%d]= ", i);
        scanf("%f", &constants[i]);
    }
}

float evaluatePolynomial(float x) {
    float result = 0;
    for (int i = 0; i <= degree; i++)
        result += constants[i] * pow(x, i);
    return square ? sqrt(result) : result;
}

float computeIntegration(float x0, float xn, int segments) {
    float h = (xn - x0) / segments;
    float sum = evaluatePolynomial(xn) + evaluatePolynomial(x0);

    for (int i = 1; i < segments; i++)
        sum += (i % 2 == 0 ? 2 : 4) * evaluatePolynomial(x0 + i * h);

    return h * sum / 3;
}

int main() {
    printf("Composite Simpsons 1/3 rule\n\n");

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    if (degree > MAX_DEGREE || degree < 0) {
        printf("Please enter a degree between 0 and %d.\n", MAX_DEGREE);
        return 1;
    }

    getConstants(degree);

    printf("Enter 1 to find square root else 0: ");
    scanf("%d", &square);

    float x0, xn;
    printf("Enter lower and upper limit:\n ");
    scanf("%f%f", &x0, &xn);

    int segments;
    printf("Enter number of segments: ");
    scanf("%d", &segments);
    if (segments <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    float result = computeIntegration(x0, xn, segments);
    printf("Result = %.3f\n", result);

    return 0;
}
