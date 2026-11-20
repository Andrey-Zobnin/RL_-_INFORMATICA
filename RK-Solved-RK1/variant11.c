#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 20

void inputSize(int *rw, int *cl);
void inputMatrix(int matr[][MAX_SIZE], int rw, int cl, bool autoMode);
void printMatrix(int matr[][MAX_SIZE], int rw, int cl);
void printArray(int arr[], int len);
void findMaxPos(int matr[][MAX_SIZE], int rw, int cl, int *mi, int *mj);
int  collectRowAndCol(int matr[][MAX_SIZE], int rw, int cl, int mi, int mj, int arr[]);
void printLessThanNeighbors(int arr[], int len);

int main(void)
{
    srand((unsigned)time(NULL));
    int matr[MAX_SIZE][MAX_SIZE];
    int arr[MAX_SIZE * 2];
    int n, m, len, mode, mi, mj;

    printf("1 - ruchnoy, 2 - auto: ");
    scanf("%d", &mode);

    inputSize(&n, &m);
    inputMatrix(matr, n, m, mode == 2);
    printMatrix(matr, n, m);

    findMaxPos(matr, n, m, &mi, &mj);
    printf("Max element: %d na pozicii [%d][%d]\n", matr[mi][mj], mi, mj);

    len = collectRowAndCol(matr, n, m, mi, mj, arr);
    printf("Elementy stroki i stolbca:\n");
    printArray(arr, len);

    printf("Elementy menshe sosedey:\n");
    printLessThanNeighbors(arr, len);

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

void findMaxPos(int matr[][MAX_SIZE], int rw, int cl, int *mi, int *mj)
{
    *mi = 0; *mj = 0;
    for (int i = 0; i < rw; i++)
        for (int j = 0; j < cl; j++)
            if (matr[i][j] > matr[*mi][*mj]) {
                *mi = i;
                *mj = j;
            }
}

int collectRowAndCol(int matr[][MAX_SIZE], int rw, int cl, int mi, int mj, int arr[])
{
    int len = 0;
    // вся строка
    for (int j = 0; j < cl; j++)
        arr[len++] = matr[mi][j];
    // столбец без пересечения (уже взяли)
    for (int i = 0; i < rw; i++)
        if (i != mi)
            arr[len++] = matr[i][mj];
    return len;
}

void printLessThanNeighbors(int arr[], int len)
{
    if (len < 2) return;
    for (int i = 0; i < len; i++) {
        if (i == 0) {
            if (arr[i] < arr[i + 1]) printf("%d ", arr[i]);
        } else if (i == len - 1) {
            if (arr[i] < arr[i - 1]) printf("%d ", arr[i]);
        } else {
            if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
                printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
