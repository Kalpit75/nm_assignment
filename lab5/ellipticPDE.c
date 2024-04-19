#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to initialize the boundary conditions
void initialize_boundary_conditions(double **u, int nx, int ny) {
    // Set boundary conditions: u = 100 at (0, y) and u = 0 at (1, y)
    for (int j = 0; j < ny; j++) {
        u[0][j] = 100.0;
        u[nx - 1][j] = 0.0;
    }
}

// Function to perform one iteration of the finite difference method
double update_grid(double **u, double **u_new, int nx, int ny) {
    double max_diff = 0.0;
    for (int i = 1; i < nx - 1; i++) {
        for (int j = 1; j < ny - 1; j++) {
            u_new[i][j] = 0.25 * (u[i-1][j] + u[i+1][j] + u[i][j-1] + u[i][j+1]);
            double diff = fabs(u_new[i][j] - u[i][j]);
            if (diff > max_diff) {
                max_diff = diff;
            }
        }
    }
    return max_diff;
}

int main() {
    int nx, ny, max_iter;
    double tolerance;

    printf("Enter the number of grid points in the x direction: ");
    scanf("%d", &nx);
    printf("Enter the number of grid points in the y direction: ");
    scanf("%d", &ny);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iter);
    printf("Enter the tolerance for convergence: ");
    scanf("%lf", &tolerance);

    // Allocate memory for grids
    double **u, **u_new;
    u = (double **)malloc(nx * sizeof(double *));
    u_new = (double **)malloc(nx * sizeof(double *));
    for (int i = 0; i < nx; i++) {
        u[i] = (double *)malloc(ny * sizeof(double));
        u_new[i] = (double *)malloc(ny * sizeof(double));
    }

    initialize_boundary_conditions(u, nx, ny);

    int iter = 0;
    double max_diff;
    do {
        max_diff = update_grid(u, u_new, nx, ny);
        // Swap the grids
        double **temp = u;
        u = u_new;
        u_new = temp;
        iter++;
    } while (max_diff > tolerance && iter < max_iter);

    printf("Converged in %d iterations with maximum difference: %lf\n", iter, max_diff);

    // Free memory
    for (int i = 0; i < nx; i++) {
        free(u[i]);
        free(u_new[i]);
    }
    free(u);
    free(u_new);

    return 0;
}
