#include <stdio.h>
#include <math.h>

int main(void)
{
    int x, y;
    const double eps = 0.0000007;
    double b1 = 0;

    printf("Enter last num: ");
    scanf("%d", &y);

    for (x = 1; x < y; x++)
    {
        double n = 2.0 * x + 1;
        double m = n / pow(n * n + 1, 2);

        b1 += m;

        if (m > eps)
        {
            printf("x = %d      b = %.10lf\n", x, b1);
        }
        else
        {
            break;
        }
    }

    return 0;
}