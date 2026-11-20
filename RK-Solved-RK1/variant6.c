#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 20

int  inputSqSize(void);
void inputMatrix(int matr[][MAX_SIZE], int n, bool autoMode);
void printMatrix(int matr[][MAX_SIZE], int n);
void printArray(int arr[], int len);
int  sumMain(int matr[][MAX_SIZE], int n);
int  sumSecondary(int matr[][MAX_SIZE], int n);
int  collectDiagonal(int matr[][MAX_SIZE], int n, int arr[], bool mainDiag);
void printGreaterThanNeighbors(int arr[], int len);

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

    int sMain = sumMain(matr, n);
    int sSec  = sumSecondary(matr, n);
    printf("Summa glavnoy: %d, summa pobochnoy: %d\n", sMain, sSec);

    if (sMain >= sSec) {
        printf("Berem glavnuyu diagonal\n");
        len = collectDiagonal(matr, n, arr, true);
    } else {
        printf("Berem pobochnuyu diagonal\n");
        len = collectDiagonal(matr, n, arr, false);
    }

    printf("Massiv diagonali:\n");
    printArray(arr, len);

    printf("Elementy bolshe sosedey:\n");
    printGreaterThanNeighbors(arr, len);

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

int sumMain(int matr[][MAX_SIZE], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++) s += matr[i][i];
    return s;
}

int sumSecondary(int matr[][MAX_SIZE], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++) s += matr[i][n - 1 - i];
    return s;
}

int collectDiagonal(int matr[][MAX_SIZE], int n, int arr[], bool mainDiag)
{
    for (int i = 0; i < n; i++)
        arr[i] = mainDiag ? matr[i][i] : matr[i][n - 1 - i];
    return n;
}

void printGreaterThanNeighbors(int arr[], int len)
{
    if (len == 0) return;
    if (len == 1) {
        printf("%d\n", arr[0]);
        return;
    }
    for (int i = 0; i < len; i++) {
        if (i == 0) {
            if (arr[i] > arr[i + 1]) printf("%d ", arr[i]);
        } else if (i == len - 1) {
            if (arr[i] > arr[i - 1]) printf("%d ", arr[i]);
        } else {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
                printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
