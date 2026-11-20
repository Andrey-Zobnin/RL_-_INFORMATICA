#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 20

int  inputSqSize(void);
void inputMatrix(int matr[][MAX_SIZE], int n, bool autoMode);
void printMatrix(int matr[][MAX_SIZE], int n);
void printArray(int arr[], int len);
int  collectOddAboveMain(int matr[][MAX_SIZE], int n, int arr[]);

int main(void)
{
    srand((unsigned)time(NULL));
    int matr[MAX_SIZE][MAX_SIZE];
    int arr[MAX_SIZE * MAX_SIZE];
    int n, len, mode;

    printf("1 - ruchnoy, 2 - auto: ");
    scanf("%d", &mode);

    n = inputSqSize();
    inputMatrix(matr, n, mode == 2);
    printMatrix(matr, n);

    len = collectOddAboveMain(matr, n, arr);
    if (len == 0)
        printf("Net takih elementov\n");
    else {
        printf("Nechetnye vyshe glavnoy diagonali:\n");
        printArray(arr, len);

        double sum = 0;
        for (int i = 0; i < len; i++) sum += arr[i];
        double avg = sum / len;
        printf("Srednee: %.2f\n", avg);

        printf("Elementy menshe srednego:\n");
        for (int i = 0; i < len; i++)
            if (arr[i] < avg)
                printf("%d ", arr[i]);
        printf("\n");
    }

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

int collectOddAboveMain(int matr[][MAX_SIZE], int n, int arr[])
{
    int len = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)   // строго выше главной
            if (matr[i][j] % 2 != 0)
                arr[len++] = matr[i][j];
    return len;
}
