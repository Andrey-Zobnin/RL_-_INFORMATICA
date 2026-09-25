#include <stdio.h>
#include <math.h>

int main() {
    double a, b, h, x, y1, y2;

    printf("Введите начало интервала a: ");
    scanf("%lf", &a);
    printf("Введите конец интервала b: ");
    scanf("%lf", &b);
    printf("Введите шаг h: ");
    scanf("%lf", &h);
    if (h == 0) {
        printf("Ошибка: шаг h не может быть равен 0.\n");
        return 1;
    }
    if (b == 0) {
        printf("Ошибка: шаг b не может быть равен 0.\n");
        return 2;
    }
    if (a == 0) {
        printf("Ошибка: шаг a не может быть равен 0.\n");
        return 3;
    }

    printf("\n---------------------------------\n");
    printf("   x        y1          y2\n");
    printf("---------------------------------\n");

    for (x = a; x <= b + h/2; x += h) {
        y1 = cbrt(x);

        // зеру нуль один попало в окрестность нуля ввыдает непонятный результат 
        if (x == 0.0) {
            printf("%8.4f  %10.6f  %10s\n", x, y1, " АААААА деление на 0");
            return 4;
        } else {
            y2 = (1.0 / x) * sin(x);
            printf("%8.4f  %10.6f  %10.6f\n", x, y1, y2);
        }
    }

    return 0;
}