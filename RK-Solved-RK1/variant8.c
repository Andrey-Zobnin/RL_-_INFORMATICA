#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 20

void inputSize(int *rw, int *cl);
void inputMatrix(int matr[][MAX_SIZE], int rw, int cl, bool autoMode);
void printMatrix(int matr[][MAX_SIZE], int rw, int cl);
void printArray(int arr[], int len);
bool isPrime(int x);
bool hasDigit(int x, int digit);
int  collectPrimes(int matr[][MAX_SIZE], int rw, int cl, int arr[]);

int main(void)
{
    srand((unsigned)time(NULL));
    int matr[MAX_SIZE][MAX_SIZE];
    int arr[MAX_SIZE * MAX_SIZE];
    int n, m, len, mode, digit;

    printf("1 - ruchnoy, 2 - auto: ");
    scanf("%d", &mode);

    inputSize(&n, &m);
    inputMatrix(matr, n, m, mode == 2);
    printMatrix(matr, n, m);

    len = collectPrimes(matr, n, m, arr);
    if (len == 0)
        printf("Net prostyh chisel\n");
    else {
        printf("Prostye chisla:\n");
        printArray(arr, len);

        printf("Vvedite cifru: ");
        scanf("%d", &digit);

        printf("Chisla s cifroy %d:\n", digit);
        for (int i = 0; i < len; i++)
            if (hasDigit(arr[i], digit))
                printf("%d ", arr[i]);
        printf("\n");
    }

    return 0;
}

void inputSize(int *rw, int *cl)
{
    do {
        printf("Vvedite razmer (stroki stolbcy <= %d): ", MAX_SIZE);
        scanf("%d%d", rw, cl);
    } while (*rw < 1 || *cl < 1 || *rw > MAX_SIZE || *cl > MAX_SIZE);
}

void inputMatrix(int matr[][MAX_SIZE], int rw, int cl, bool autoMode)
{
    if (autoMode) {
        for (int i = 0; i < rw; i++)
            for (int j = 0; j < cl; j++)
                matr[i][j] = rand() % 50 + 1;
    } else {
        printf("Vvedite matricu %dx%d:\n", rw, cl);
        for (int i = 0; i < rw; i++)
            for (int j = 0; j < cl; j++)
                scanf("%d", &matr[i][j]);
    }
}

void printMatrix(int matr[][MAX_SIZE], int rw, int cl)
{
    printf("\nMatrica:\n");
    for (int i = 0; i < rw; i++) {
        for (int j = 0; j < cl; j++)
            printf("%5d", matr[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}

bool isPrime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

bool hasDigit(int x, int digit)
{
    x = abs(x);
    if (x == 0 && digit == 0) return true;
    while (x) {
        if (x % 10 == digit) return true;
        x /= 10;
    }
    return false;
}

int collectPrimes(int matr[][MAX_SIZE], int rw, int cl, int arr[])
{
    int len = 0;
    for (int i = 0; i < rw; i++)
        for (int j = 0; j < cl; j++)
            if (isPrime(matr[i][j]))
                arr[len++] = matr[i][j];
    return len;
}
