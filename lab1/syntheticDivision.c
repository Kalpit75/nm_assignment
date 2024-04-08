#include<stdio.h>
#include<math.h>

int main() {
    printf("synthetic devision:\n\n");
    int i, n, ak;
    printf("Enter the order of the polynomial, n = ");
    scanf("%d", &n);
    int a[n+1];
    int b[n];
    printf("\nEnter the values of coefficients: ");
    for(i = 0; i <= n; i++) {
        printf("\nEnter the value of a%d = ", i);
        scanf("%d", &a[i]);		
    }
    for(i = 0; i <= n; i++) {
        printf("\na%d = %d", i, a[i]);
    }
    printf("\nP(x) = ");
    for(i = n; i > 0; i--) {
        printf("%dx^%d + ", a[i], i);
    }
    printf("%d\n", a[0]);

    printf("\nEnter the value to calculate the root at: ");
    scanf("%d", &ak);
    
    b[n-1] = 0;
    while(n > 0) {
        b[n-2] = a[n] + ak * b[n-1];	
        printf("\nb = %d", b[n-2]);
        n--;
    }

    printf("  \nRemainder = %d", b[0]);
    printf("  \nQuotient = ");
    for(i = n-3; i > 0; i--) {
        printf("%dx^%d + ", b[i], i);
    }
    printf("%d = 0\n", b[0]);
    
    return 0;
}
