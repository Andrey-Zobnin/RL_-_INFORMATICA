// вводиться трехзначное число вычислить квадратный корень из его цифр

#include <stdio.h>

int main()
{
    int a = 0, a1, a2, a3, p;
    float res = 0;
    printf("Enter num: ");
    scanf("%d", &a);
    a1 = a / 100;
    a2 = a / 10 % 10;
    a3 = a2 % 10;

    return 0;
}