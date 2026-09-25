#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MAX_SIZE 15
#define NO_ELEMENTS -9999
#define INT_MIN_VAL -2147483648

int main() {
    setlocale(LC_ALL, "Russian");
    int arr[MAX_SIZE];
    int size = 0;
    int check = 0;

    printf("Enter 1 for manual input or 2 for random: ");
    scanf("%d", &check);

    printf("Enter the number of elements (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size > MAX_SIZE) size = MAX_SIZE;
    if (size < 1) size = 1;

    if (check == 1) {
        printf("Enter %d integers:\n", size);
        for (int i = 0; i < size; i++) {
            printf("arr[%d] = ", i);
            scanf("%d", &arr[i]);
        }
    } else {
        srand(time(NULL));
        printf("Array filled with random numbers from -20 to 20:\n");
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 41 - 20;
        }
    }

    printf("Original array: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    if (size >= 2) {
        int maxIdx = 0, minIdx = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i] > arr[maxIdx]) maxIdx = i;
            if (arr[i] < arr[minIdx]) minIdx = i;
        }
        int temp = arr[maxIdx];
        arr[maxIdx] = arr[minIdx];
        arr[minIdx] = temp;
        printf("-> Maximum and minimum elements swapped.\n");
    }

    printf("Array after swap: [");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    long long sumEven = 0;
    int countEven = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            sumEven += arr[i];
            countEven++;
        }
    }
    if (countEven == 0) {
        printf("Message: No even elements.\n");
    } else {
        double avg = (double)sumEven / countEven;
        printf("Average of even elements: %.2f\n", avg);
    }

    int newArr[MAX_SIZE];
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 3 == 0) {
            newArr[newSize] = arr[i];
            newSize++;
        }
    }
    if (newSize == 0) {
        printf("Message: No elements divisible by three.\n");
    } else {
        printf("Array of multiples of three: [");
        for (int i = 0; i < newSize; i++) printf("%d ", newArr[i]);
        printf("\n");
    }

    int maxNeg = INT_MIN_VAL;
    int foundNeg = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            if (!foundNeg || arr[i] > maxNeg) {
                maxNeg = arr[i];
                foundNeg = 1;
            }
        }
    }
    if (!foundNeg) {
        printf("Message: No negative elements.\n");
    } else {
        printf("Maximum negative element: %d\n", maxNeg);
    }

    int k, m;
    printf("Enter the range boundaries k and m (from 1 to %d): ", size);
    scanf("%d %d", &k, &m);

    int start = k - 1;
    int end = m - 1;

    if (start < 0) start = 0;
    if (end >= size) end = size - 1;

    if (start > end) {
        printf("Message: Invalid range.\n");
    } else {
        int minRange = arr[start];
        for (int i = start + 1; i <= end; i++) {
            if (arr[i] < minRange) minRange = arr[i];
        }
        printf("Minimum element in range [%d, %d]: %d\n", k, m, minRange);
    }

    return 0;
}
