#include <stdio.h>
#include <math.h>
// #include <stdboo>
#include <stdbool.h>

int main()
{
    int num = 0, res = 0;
    int a1, a2, a3, a4;
    bool isPalindrome;
    
    printf("Введите пятизначное число: ");
    scanf("%d", &num);
    
    res = num;
    
    a1 = num / 10000;
    a2 = (num / 1000) % 10;
    a3 = (num / 10) % 10;
    a4 = num % 10;
    
    isPalindrome = (a1 == a4) && (a2 == a3);
    
    printf("%d %d\n", res, isPalindrome);
    
    return 0;
}