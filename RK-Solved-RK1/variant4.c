#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 20

void inputSize(int *rw, int *cl);
void inputMatrix(int matr[][MAX_SIZE], int rw, int cl, bool autoMode);
void printMatrix(int matr[][MAX_SIZE], int rw, int cl);
void printArray(int arr[], int len);
void mySwap(int *a, int *b);
int  greaterThanAvg(int matr[][MAX_SIZE], int rw, int cl, int arr[]);
void specialSort(int arr[], int len);

int main(void)
{
    srand((unsigned)time(NULL));
    int matr[MAX_SIZE][MAX_SIZE];
    int arr[MAX_SIZE * MAX_SIZE];
    int n, m, len, mode;

    printf("1 - ruchnoy, 2 - auto: ");
    scanf("%d", &mode);

    inputSize(&n, &m);
    inputMatrix(matr, n, m, mode == 2);
    printMatrix(matr, n, m);

    len = greaterThanAvg(matr, n, m, arr);
    printf("Elementy bolshe srednego:\n");
    printArray(arr, len);

    specialSort(arr, len);
    printf("Posle special sort:\n");
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

int greaterThanAvg(int matr[][MAX_SIZE], int rw, int cl, int arr[])
{
    long long sum = 0;
    for (int i = 0; i < rw; i++)
        for (int j = 0; j < cl; j++)
            sum += matr[i][j];
    double avg = (double)sum / (rw * cl);

    int len = 0;
    for (int i = 0; i < rw; i++)
        for (int j = 0; j < cl; j++)
            if (matr[i][j] > avg)
                arr[len++] = matr[i][j];
    return len;
}

void specialSort(int arr[], int len)
{
    for (int i = 0; i < len; i += 2)
        for (int j = i + 2; j < len; j += 2)
            if (arr[i] > arr[j]) mySwap(&arr[i], &arr[j]);

    for (int i = 1; i < len; i += 2)
        for (int j = i + 2; j < len; j += 2)
            if (arr[i] < arr[j]) mySwap(&arr[i], &arr[j]);
}
