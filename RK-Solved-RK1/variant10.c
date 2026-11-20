#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 20

void printMatrix(int matr[][MAX_SIZE], int rw, int cl);
void printArray(int arr[], int len);
void mySwap(int *a, int *b);
int  digitSum(int x);
void fillFibonacci(int matr[][MAX_SIZE], int rw, int cl);
int  collectOdd(int matr[][MAX_SIZE], int rw, int cl, int arr[]);
void sortByDigitSumDesc(int arr[], int len);

int main(void)
{
    int matr[MAX_SIZE][MAX_SIZE];
    int arr[MAX_SIZE * MAX_SIZE];
    int n, m, len;

    do {
        printf("Vvedite n m (n*m < 30): ");
        scanf("%d%d", &n, &m);
    } while (n < 1 || m < 1 || n * m >= 30 || n > MAX_SIZE || m > MAX_SIZE);

    fillFibonacci(matr, n, m);
    printMatrix(matr, n, m);

    len = collectOdd(matr, n, m, arr);
    printf("Nechetnye:\n");
    printArray(arr, len);

    sortByDigitSumDesc(arr, len);
    printf("Posle sortirovki po summe cifr (ubyv):\n");
    printArray(arr, len);

    return 0;
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

void mySwap(int *a, int *b)
{
    int t = *a; *a = *b; *b = t;
}

int digitSum(int x)
{
    x = abs(x);
    int s = 0;
    while (x) { s += x % 10; x /= 10; }
    return s;
}

void fillFibonacci(int matr[][MAX_SIZE], int rw, int cl)
{
    long long f1 = 1, f2 = 2;
    for (int i = 0; i < rw; i++)
        for (int j = 0; j < cl; j++) {
            matr[i][j] = (int)f1;
            long long next = f1 + f2;
            f1 = f2;
            f2 = next;
        }
}

int collectOdd(int matr[][MAX_SIZE], int rw, int cl, int arr[])
{
    int len = 0;
    for (int i = 0; i < rw; i++)
        for (int j = 0; j < cl; j++)
            if (matr[i][j] % 2 != 0)
                arr[len++] = matr[i][j];
    return len;
}

void sortByDigitSumDesc(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (digitSum(arr[i]) < digitSum(arr[j]))
                mySwap(&arr[i], &arr[j]);
}
