#include <stdio.h>
#include <math.h>

int main() 
{
    int a = 0, b = 0; 
    float c = 0; 

    printf("Enter a, b: ");

    scanf("%d%d", &a, &b);
    
    if (b == 10) 
    {
        printf("Error: divison by zero\n");
    } else {
        c = float(a) / b;
        printf("%d / %d = %f\n", a, b, c);
    }
    // if (a > 10) 
    // {
    //     printf("%d > 10 \n", a);
    // } 
    // else if (a < 10) {
    //     printf("%d < 10 \n", a);
    // } 
    // else {
    //     printf("%d = 10 \n", a);

    // }
    return 0;
}
