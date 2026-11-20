#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 20

int  inputSqSize(void);
void inputMatrix(int matr[][MAX_SIZE], int n, bool autoMode);
void printMatrix(int matr[][MAX_SIZE], int n);
void printArray(int arr[], int len);
void mySwap(int *a, int *b);
void swapMaxWithSecondary(int matr[][MAX_SIZE], int n);
int  mainDiagonal(int matr[][MAX_SIZE], int n, int arr[]);

int main(void)
{
    srand((unsigned)time(NULL));
    int matr[MAX_SIZE][MAX_SIZE];
    int arr[MAX_SIZE];
    int n, len, mode;

    printf("1 - ruchnoy, 2 - auto: ");
    scanf("%d", &mode);

    n = inputSqSize();
    inputMatrix(matr, n, mode == 2);
    printMatrix(matr, n);

    swapMaxWithSecondary(matr, n);
    printf("Posle obmena max v stroke s pobochnoy diagonalju:\n");
    printMatrix(matr, n);

    len = mainDiagonal(matr, n, arr);
    printf("Glavnaya diagonal:\n");
    printArray(arr, len);

    double sum = 0;
    for (int i = 0; i < len; i++) sum += arr[i];
    printf("Srednee arifmeticheskoe: %.2f\n", sum / len);

    return 0;
}

int inputSqSize(void)
{
    int n;
    do {
        printf("Razmer kvadratnoy matricy (<= %d): ", MAX_SIZE);
        scanf("%d", &n);
    } while (n < 1 || n > MAX_SIZE);
    return n;
}

void inputMatrix(int matr[][MAX_SIZE], int n, bool autoMode)
{
    if (autoMode) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matr[i][j] = rand() % 41 - 20;
    } else {
        printf("Vvedite matricu %dx%d:\n", n, n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &matr[i][j]);
    }
}

void printMatrix(int matr[][MAX_SIZE], int n)
{
    printf("\nMatrica:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
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

void swapMaxWithSecondary(int matr[][MAX_SIZE], int n)
{
    for (int i = 0; i < n; i++) {
        int jmax = 0;
        for (int j = 1; j < n; j++)
            if (matr[i][j] > matr[i][jmax])
                jmax = j;
        mySwap(&matr[i][jmax], &matr[i][n - 1 - i]);
    }
}

int mainDiagonal(int matr[][MAX_SIZE], int n, int arr[])
{
    for (int i = 0; i < n; i++)
        arr[i] = matr[i][i];
    return n;
}
