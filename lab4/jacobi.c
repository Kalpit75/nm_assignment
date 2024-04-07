#include <stdio.h>
#include <math.h>

#define N 3 // Size of the system of linear equations

// Function to perform Jacobi iteration
void jacobi(double A[N][N], double b[N], double x[N], int max_iterations, double tolerance) {
    double x_new[N]; // Store the updated solution vector
    int iteration = 0;
    double error = tolerance + 1; // Initialize error to a value greater than tolerance

    while (iteration < max_iterations && error > tolerance) {
        error = 0.0; // Reset error for the current iteration

        // Update each component of the solution vector
        for (int i = 0; i < N; i++) {
            double sum = 0.0;
            for (int j = 0; j < N; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];

            // Calculate the error for this component
            error += fabs(x_new[i] - x[i]);
        }

        // Update the solution vector for the next iteration
        for (int i = 0; i < N; i++) {
            x[i] = x_new[i];
        }

        iteration++;
    }

    if (error <= tolerance) {
        printf("Solution converged after %d iterations.\n", iteration);
    } else {
        printf("Solution did not converge after %d iterations.\n", max_iterations);
    }
}

int main() {
    double A[N][N] = {{5, 1, 2}, {1, 4, 1}, {2, 1, 3}}; // Coefficient matrix
    double b[N] = {12, 11, 13}; // Constant vector
    double x[N] = {0}; // Initial guess for the solution vector
    int max_iterations = 1000; // Maximum number of iterations
    double tolerance = 1e-6; // Tolerance for convergence

    // Perform Jacobi iteration
    jacobi(A, b, x, max_iterations, tolerance);

    // Print the solution vector
    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.6f\n", i+1, x[i]);
    }

    return 0;
}
