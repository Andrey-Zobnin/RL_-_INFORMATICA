#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define MAX 20

int number = 0, lenght = 0, lenSecondArray = 0;
int lenThArr = 0;
float sr = 0.0;

int* second, *numbers;

void _enter(void);
void SizeArr(void);
void _automatic_array(int numbers[], int* lenght);
void _vivod_array(int numbers[], int* lenght);
void _sam(int numbers[], int* lenght);
void _second_array(int numbers[], int* lenght);
void srAriphm(int array[], int lenght);
void sortArray(int numbers[], int* lenght);
void SecSortArray(int numbers[], int* lenght);

int main()
{
    _enter();
    SizeArr();
    srand((unsigned int)time(NULL));
    numbers = new int[lenght];
    second = new int[lenght];

    if (number == 1)
    {
        _automatic_array(numbers, &lenght);
    }

    else
    {
        _sam(numbers, &lenght);
    }

    srAriphm(numbers, lenght);

    _second_array(numbers, &lenght);

    sortArray(numbers, &lenght);

    SecSortArray(second, &lenSecondArray);

    delete[] numbers;
    delete[] second;
    return 0;
}

void _enter(void)
{
    do {
        printf("Enter 1 if automatic: ");
        if (scanf_s("%d", &number) != 1)
        {
            fprintf(stderr, "Error enter\n");

        }
    } while (number > 1 || number < 0);
}

void SizeArr(void)
{
    do {
        printf("Enter lenght array: ");
        if (scanf_s("%d", &lenght) != 1)
        {
            fprintf(stderr, "Error enter\n");

        }
    } while (lenght < 0 || lenght > MAX);
}

void _sam(int numbers[], int* lenght)
{
    for (int i = 0; i < *lenght; i++)
    {
        printf("Enter number[%d]: ", i);
        if (scanf_s("%d", &numbers[i]) != 1)
        {
            fprintf(stderr, "Error enter\n");

        }
    }
    _vivod_array(numbers, lenght);
}

void _automatic_array(int numbers[], int* lenght)
{
    

    for (int i = 0; i < *lenght; i++)
    {
        numbers[i] = rand() % 101 - 50;
    }
    _vivod_array(numbers, lenght);
}

void _vivod_array(int numbers[], int* lenght)
{
    for (int i = 0; i < *lenght; i++)
    {
        printf("number[%d] = %d\n", i, numbers[i]);
    }
}

void srAriphm(int array[], int lenght)
{
    int sum = 0;
    for (int i = 0; i < lenght; i++)
    {
        sum += array[i];
    }
    sr = float(sum) / lenght;
    printf("sr = %f\n", sr);
}

void _second_array(int numbers[], int* lenght)
{
    for (int i = 0; i < *lenght; i++)
    {
        if (numbers[i] > sr)
        {
            second[lenSecondArray] = numbers[i];
            lenSecondArray++;
        }
    }
    _vivod_array(second, &lenSecondArray);
}

void sortArray(int numbers[], int* lenght)
{
    printf("Chetkiy massiv:\n");
    int a = 0;
    int b = 0;
    for (int i = 0; i < *lenght; i++)
    {
        for (int i = 0; i < *lenght - 2; i += 2)
        {
            if (numbers[i] > numbers[i + 2])
            {
                a = numbers[i];
                numbers[i] = numbers[i + 2];
                numbers[i + 2] = a;
            }
        }
    }
    for (int i = 0; i < *lenght; i++)
    {
        for (int i = 1; i < *lenght - 2; i += 2)
        {
            if (numbers[i] < numbers[i + 2])
            {
                b = numbers[i];
                numbers[i] = numbers[i + 2];
                numbers[i + 2] = b;
            }
        }
    }
    _vivod_array(numbers, lenght);
}

void SecSortArray(int numbers[], int* lenght)
{
    printf("Sort second array:\n");

    for (int pass = 0; pass < *lenght; pass++)
    {
        int f = 0;

        for (int i = 0; i < *lenght - 1; i++)
        {
            int sum = (numbers[i] / 10) + (numbers[i] % 10);
            int sum1 = (numbers[i + 1] / 10) + (numbers[i + 1] % 10);

            if (sum > sum1)
            {
                f = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = f;
            }
        }
    }
    _vivod_array(numbers, &lenSecondArray);
}