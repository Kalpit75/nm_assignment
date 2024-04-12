#include<stdio.h>
// #include<conio.h>
#include<math.h>

/* Define function here */
#define f(x) (1/(1+(x)*(x)))

int main()
{
    printf("simpsons 3/8 rule:\n\n");
    float lower, upper, integration = 0.0, stepSize, k;
    int subInterval;

    // clrscr();

    /* Input */
    printf("Enter lower limit of integration: ");
    scanf("%f", &lower);
    printf("Enter upper limit of integration: ");
    scanf("%f", &upper);
    printf("Enter number of sub intervals (multiple of 3): ");
    scanf("%d", &subInterval);

    /* Calculation */
    /* Finding step size */
    stepSize = (upper - lower) / subInterval;

    /* Finding Integration Value */
    integration = f(lower) + f(upper);
    for (int i = 1; i <= subInterval - 1; i++) {
        k = lower + i * stepSize;
        integration += (i % 3 == 0) ? 2 * f(k) : 3 * f(k);
    }
    integration *= (3 * stepSize) / 8;

    /* Output */
    printf("\nRequired value of integration is: %.3f", integration);

    // getch();
    return 0;
}
