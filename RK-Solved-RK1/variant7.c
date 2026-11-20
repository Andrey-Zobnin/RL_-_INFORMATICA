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
void mySwap(int *a, int *b);
void swapRows(int matr[][MAX_SIZE], int cl, int k, int p);
int  collectOddFromTwoRows(int matr[][MAX_SIZE], int cl, int k, int p, int arr[]);
void sortByAbs(int arr[], int len);

int main(void)
{
    srand((unsigned)time(NULL));
    int matr[MAX_SIZE][MAX_SIZE];
    int arr[MAX_SIZE * 2];
    int n, m, len, mode, k, p;

    printf("1 - ruchnoy, 2 - auto: ");
    scanf("%d", &mode);

    inputSize(&n, &m);
    inputMatrix(matr, n, m, mode == 2);
    printMatrix(matr, n, m);

    printf("Vvedite nomera strok k i m (0..%d): ", n-1);
    scanf("%d%d", &k, &p);

    swapRows(matr, m, k, p);
    printf("Posle obmena strok:\n");
    printMatrix(matr, n, m);

    len = collectOddFromTwoRows(matr, m, k, p, arr);
    if (len == 0)
        printf("Net nechetnyh\n");
    else {
        printf("Nechetnye:\n");
        printArray(arr, len);
        sortByAbs(arr, len);
        printf("Posle sortirovki po modulyu:\n");
        printArray(arr, len);
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
                matr[i][j] = rand() % 41 - 20;
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

void mySwap(int *a, int *b)
{
    int t = *a; *a = *b; *b = t;
}

void swapRows(int matr[][MAX_SIZE], int cl, int k, int p)
{
    for (int j = 0; j < cl; j++)
        mySwap(&matr[k][j], &matr[p][j]);
}

int collectOddFromTwoRows(int matr[][MAX_SIZE], int cl, int k, int p, int arr[])
{
    int len = 0;
    for (int j = 0; j < cl; j++) {
        if (matr[k][j] % 2 != 0) arr[len++] = matr[k][j];
        if (matr[p][j] % 2 != 0) arr[len++] = matr[p][j];
    }
    return len;
}

void sortByAbs(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (abs(arr[i]) > abs(arr[j]))
                mySwap(&arr[i], &arr[j]);
}
