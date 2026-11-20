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
void swapMainSecondaryInRows(int matr[][MAX_SIZE], int n);
int  secondaryDiagonal(int matr[][MAX_SIZE], int n, int arr[]);
void swapMaxMin(int arr[], int len);

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

    swapMainSecondaryInRows(matr, n);
    printf("Posle obmena glavnoy i pobochnoy v strokah:\n");
    printMatrix(matr, n);

    len = secondaryDiagonal(matr, n, arr);
    printf("Pobochnaya diagonal:\n");
    printArray(arr, len);

    swapMaxMin(arr, len);
    printf("Posle obmena max i min:\n");
    printArray(arr, len);

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

void swapMainSecondaryInRows(int matr[][MAX_SIZE], int n)
{
    for (int i = 0; i < n; i++)
        mySwap(&matr[i][i], &matr[i][n - 1 - i]);
}

int secondaryDiagonal(int matr[][MAX_SIZE], int n, int arr[])
{
    for (int i = 0; i < n; i++)
        arr[i] = matr[i][n - 1 - i];
    return n;
}

void swapMaxMin(int arr[], int len)
{
    if (len < 2) return;
    int maxI = 0, minI = 0;
    for (int i = 1; i < len; i++) {
        if (arr[i] > arr[maxI]) maxI = i;
        if (arr[i] < arr[minI]) minI = i;
    }
    mySwap(&arr[maxI], &arr[minI]);
}
