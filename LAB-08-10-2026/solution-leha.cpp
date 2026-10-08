#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

void enter_massiv(int a[], int ln);
void print_massiv(int a[], int ln);
int srednee(int a[], int ln);
int sredn_massiv(int a[], int ln, int b[], float sr);
void sort1(int a[], int ln);
int ds(int x);
void sort2(int a[],int ln);
void obmen(int* x, int* y);

int main() {
    int arr[MAX_SIZE];
    int n = 20;
    do{
        printf("Vvedite razmer massiva (<20): ");
        scanf("%d", &n);
    } while(n<1 or n>=20);


    enter_massiv(arr, n);

    printf("Massiv: ");
    print_massiv(arr, n);

    float sr = srednee(arr,n);
    int arrs[MAX_SIZE];
    int arrsln = sredn_massiv(arr, n, arrs, sr);
    printf("\nMassiv >sr: ");
    print_massiv(arrs, arrsln);

    sort1(arr, n);
    printf("\nSort. massiv 1: ");
    print_massiv(arr, n);

    sort2(arrs, arrsln);
    printf("\nSort. massiv 2: ");
    print_massiv(arrs, arrsln);

    return 0;
}

void enter_massiv(int a[], int ln){
    srand(time(NULL));
    int p = 1;
    do {printf("\nZapolnit Avtomatom?(1 ili 0): ");
        scanf("%d", &p);} while(p != 1 and p !=0);
    if (p == 1){
        for(int i = 0; i < ln; i++){
            a[i] = rand() % 2001 - 1000;
        }
    }
    if (p == 0){
        for (int i = 0; i < ln; i++){
            printf("Vvedite element %d: ", i);
            scanf("%d", &a[i]);
        }
    }
}

void print_massiv(int a[], int ln){
    for(int i = 0; i < ln; i++){
        printf("%d ", a[i]);
    }
}

int srednee(int a[], int ln){
    float c = 0.0;
    for(int i=0; i<ln;i++){
        c = c + a[i];
    }
    float r = c/ln;
    printf("\nSrednee Arf.: %.3f", r);
    return r;
}

int sredn_massiv(int a[], int ln, int b[], float sr){
    int lnb = 0;
    for(int i = 0; i<ln;i++){
        if(a[i]>sr){
            b[lnb] = a[i];
            lnb++;
        }
    }
    return lnb;
}

void sort1(int a[], int ln){
    bool flag = true;
    int temp = 0;
    for(int i=0; i<ln; i++){
        for(int j = i+2; j<ln; j+=2){
            if(i % 2 == 0){
                if(a[i] > a[j]){
                    obmen(&a[i], &a[j]);
                }
            }
            else{
                if (a[i] < a[j]){
                    obmen(&a[i], &a[j]);
                }
            }
        }
    }
}

int ds(int x){
    int sum = 0;
    if(x<0){x=-x;}

    while(x>0){
        sum += x%10;
        x /= 10;
    }

    return sum;
}

void sort2(int a[],int ln){
    int temp = 0;
    for(int i=0; i<ln; i++){
        for(int j=i+1; j<ln;j++){
            if(ds(a[i]) < ds(a[j])){
                obmen(&a[i], &a[j]);
            }
        }
    }
}

void obmen(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
