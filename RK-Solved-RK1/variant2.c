#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 20

void inputSize(int *rw, int *cl);
void inputMatrix(int matr[][MAX_SIZE], int rw, int cl, bool autoMode);
void printMatrix(int matr[][MAX_SIZE], int rw, int cl);
void printArrayDouble(double arr[], int len);
int  rowAverages(int matr[][MAX_SIZE], int rw, int cl, double arr[]);
void swapMaxMinDouble(double arr[], int len);

int main(void)
{
    srand((unsigned)time(NULL));
    int matr[MAX_SIZE][MAX_SIZE];
    double avg[MAX_SIZE];
    int n, m, len, mode;

    printf("1 - ruchnoy, 2 - auto: ");
    scanf("%d", &mode);

    inputSize(&n, &m);
    inputMatrix(matr, n, m, mode == 2);
    printMatrix(matr, n, m);

    len = rowAverages(matr, n, m, avg);
    printf("Srednie po strokam:\n");
    printArrayDouble(avg, len);

    swapMaxMinDouble(avg, len);
    printf("Posle obmena max i min:\n");
    printArrayDouble(avg, len);

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

void printArrayDouble(double arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%.2f ", arr[i]);
    printf("\n\n");
}

int rowAverages(int matr[][MAX_SIZE], int rw, int cl, double arr[])
{
    for (int i = 0; i < rw; i++) {
        double sum = 0;
        for (int j = 0; j < cl; j++) sum += matr[i][j];
        arr[i] = sum / cl;
    }
    return rw;
}

void swapMaxMinDouble(double arr[], int len)
{
    if (len < 2) return;
    int maxI = 0, minI = 0;
    for (int i = 1; i < len; i++) {
        if (arr[i] > arr[maxI]) maxI = i;
        if (arr[i] < arr[minI]) minI = i;
    }
    double t = arr[maxI];
    arr[maxI] = arr[minI];
    arr[minI] = t;
}
