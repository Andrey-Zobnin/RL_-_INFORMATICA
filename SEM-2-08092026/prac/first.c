#include <stdio.h>
#include <math.h>

int main() 
{
    int a; 

    printf("Enter a: ");
    scanf("%d", a);
    if (a > 10) 
    {
        printf("%d > 10 \n", a);
    } 
    else if (a < 10) {
        printf("%d < 10 \n", a);
    } 
    else {
        printf("%d = 10 \n", a);

    }
    return 0;
}
