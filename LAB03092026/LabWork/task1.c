#include <stdio.h>
#include <math.h>

int main()
{
    int num = 0, res = 0, digit0 = 0, digit1 = 0, digit3 = 0, digit4 = 0;
    
    // ввод чисел пишем юзеру что вводить и забираем у него
    printf("Введите пятизначное число: ");
    scanf("%d", &num);
    
    res = num;
    
    // основная логика
    digit0 = num / 10000;           
    digit1 = (num / 1000) % 10;     
    digit3 = (num / 10) % 10;       
    digit4 = num % 10;              
    
    // Проверяем: первая = последней И вторая = предпоследней
    
    // if (digit0 == digit4 && digit1 == digit3) {
    //     printf("Num is %d palindromm\n", res);
    // } else {
    //     printf("NUm %d not palindromm\n", res);
    // }
    
    return 0;
}