#include <cstdio>

int main() {
    const double pi = 3.14159;
    int r = 0;
    double pr, sq;  // double вместо float

    printf("Enter radius: ");
    scanf("%d", &r);  // %d для int
    pr = 2 * pi * r;
    sq = pi * r * r;
    printf("Perimeter = %.2f\n", pr);
    printf("Square = %.2f\n", sq);
    return 0;
}