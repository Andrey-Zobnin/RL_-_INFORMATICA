#include <stdio.h>
#include <math.h>

int main() {
    double coefA = 0, coefB = 0, coefC = 0;

    printf("Vvedite coeficcentiki A B C cherezz probel: ");
    if (scanf("%lf %lf %lf", &coefA, &coefB, &coefC) != 3) {
        printf("Oshibka vvoda!\n");
        return 1;
    }

    if (coefA == 0) {
        printf("Ne parabola!\n");
        // return 1;
    }
    // продолжает выполняться дальше доходит до вычисления дискриминанта и деления на coefA (который равен 0), что даст деление на ноль div by zero
    // moi ideiiki
    // if (coefA == 0 & coefC == 0 & coefB == 0){
    //     prinf("vse coeficcentiiki 0");
    //     return 4;
    // }
    // if (coefA > 100 || coefB > 100 || coef )
    // {

    // }
    else if (coefA > 0) printf("Vetvi vverx\n");
    else if (coefA < 0) printf("Vetvi vnizz\n");

    double discriminant = coefB * coefB - 4 * coefA * coefC;

    if (discriminant > 0) {
        printf("1");
        double x1 = (-coefB + sqrt(discriminant)) / (2 * coefA);
        double x2 = (-coefB - sqrt(discriminant)) / (2 * coefA);

        printf("Dve tochki peresecheniya s osyu X: x1 = %lf, x2 = %lf\n", x1, x2);
    }
    else if (discriminant == 0) {
        printf("2");
        double x = -coefB / (2 * coefA);
        printf("Odna tochka: x = %lf\n", x);
    }
    else {
        printf("111");
        printf("Net tochek peresecheniya s osyu X\n");
    }

    return 0;
}