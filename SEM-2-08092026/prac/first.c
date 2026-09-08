 #include <stdio.h>
#include <math.h>

int main() 
{
    int a = 0, b = 0; 
    float c = 0; 

    printf("Enter a, b: ");

    scanf("%d%d", &a, &b);
    
    if (b == 0)  // проверяем деление на ноль
    {
        printf("Error: division by zero\n");
    } else {
        c = (float)a / b;  // правильное приведение типа
        printf("%d / %d = %f\n", a, b, c);
    }
    return 0;
}