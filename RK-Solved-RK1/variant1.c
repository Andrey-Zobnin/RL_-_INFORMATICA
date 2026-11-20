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
int  digitSum(int x);
int  minsInColumns(int matr[][MAX_SIZE], int rw, int cl, int arr[]);
void sortByDigitSumAsc(int arr[], int len);

int main(void)
{
    srand((unsigned)time(NULL));
    int matr[MAX_SIZE][MAX_SIZE];
    int arr[MAX_SIZE];
    int n, m, len, mode;

    printf("1 - ruchnoy, 2 - auto: ");
    scanf("%d", &mode);

    inputSize(&n, &m);
    inputMatrix(matr, n, m, mode == 2);
    printMatrix(matr, n, m);

    len = minsInColumns(matr, n, m, arr);
    printf("Minimalnye elementy stolbcov:\n");
    printArray(arr, len);

    sortByDigitSumAsc(arr, len);
    printf("Posle sortirovki po summe cifr:\n");
    printArray(arr, len);

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

int digitSum(int x)
{
    x = abs(x);
    int s = 0;
    while (x) { s += x % 10; x /= 10; }
    return s;
}

int minsInColumns(int matr[][MAX_SIZE], int rw, int cl, int arr[])
{
    int len = 0;
    for (int j = 0; j < cl; j++) {
        int mn = matr[0][j];
        for (int i = 1; i < rw; i++)
            if (matr[i][j] < mn) mn = matr[i][j];
        arr[len++] = mn;
    }
    return len;
}

void sortByDigitSumAsc(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (digitSum(arr[i]) > digitSum(arr[j]))
                mySwap(&arr[i], &arr[j]);
}
