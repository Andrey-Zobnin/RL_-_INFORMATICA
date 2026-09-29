#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int const n = 15;
    int N = 5;
    int arr[n] = {0};
    int p = 1;

    do{
        printf("Vvedite razmer massiva (Ot 1 do 15): ");
        scanf("%d", &N);
    } while(N > 15 or N < 1);

    do {printf("\nZapolnit Avtomatom?(1 ili 0): ");
        scanf("%d", &p);} while(p != 1 and p !=0);
    if (p == 1){
        for(int i = 0; i < N; i++){
            arr[i] = rand() % 2001 - 1000;
        }
    }
    if (p == 0){
        for (int i = 0; i < N; i++){
            printf("Vvedite element %d (Ot -100 do 100): ", i);
            scanf("%d", &arr[i]);
        }
    }
    printf("Massiv: ");
    for (int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }



    /*
    for(int i=0; i<n-1;i++){
        int imin = i;
        for (int j=i+1; j<n; j++){
            if(arr[j]<arr[imin]){
                imin=j;
            }
        }
        int bf = arr[imin];
        arr[imin] =  arr[i];
        arr[i] = bf;
    } */

    /*
    for(int j=0; j<n-1; j++){
        for(int i=0; i<n-1; i++){
            if(arr[i]>arr[i+1]){
                int bf = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = bf;
            }
        }
    } */

    /*
    bool flag  = false;
    do {
        flag = false;
        for(int i=0; i<n-1; i++){
            if(arr[i]>arr[i+1]){
                int bf = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = bf;
                flag=true;
            }
        }
    } while(flag); */



    printf("\nMassiv (Sortirovan): ");
    for (int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
