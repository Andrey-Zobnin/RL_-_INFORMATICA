#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int const n = 20;
int arr[n] = {0};
int N = 5;
int arr3[n] = {0};
int arr5[n] = {0};

void _init();
void _printarr();
void _minmaxr();
int _cr3();
int _cr5();
void _presort();
void _sortub(int index);
void _sortv(int index);

int main() {
    int c = 0;

    _init();

    do{
    printf("\nKomandi:\
    \n0. Exit\
    \n1. Petchat massiva\
    \n2. Smena min i max\
    \n3. Massiv kratnih 3\
    \n4. Massiv kratnih 5\
    \n5. Sortirovka\
    \nVvedite comandu: ");
        scanf("%d", &c);
        switch (c){
        case 0: break;
        case 1: _printarr(); break;
        case 2: _minmaxr(); break;
        case 3: _cr3(); break;
        case 4: _cr5(); break;
        case 5: _presort(); break;
        }
    } while(c != 0);


    return 0;
}

void _init(){
    srand(time(NULL));
    int p = 1;

    do{
        printf("Vvedite razmer massiva (Ot 1 do 20): ");
        scanf("%d", &N);
    } while(N > n or N < 1);

    do {printf("\nZapolnit Avtomatom?(1 ili 0): ");
        scanf("%d", &p);} while(p != 1 and p !=0);
    if (p == 1){
        for(int i = 0; i < N; i++){
            arr[i] = rand() % 2001 - 1000;
        }
    }
    if (p == 0){
        for (int i = 0; i < N; i++){
            printf("Vvedite element %d: ", i);
            scanf("%d", &arr[i]);
        }
    }
    _printarr();
}

void _printarr(){
    printf("Massiv: ");
    for (int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }
}

void _minmaxr(){
    int mini = 0 , maxi = 0, t = 0;

    for (int i = 0; i < N; i++){
        if (arr[i] > arr[maxi]){maxi = i;}
        if (arr[i] < arr[mini]){mini = i;}
    }
    printf("\nMax: %d; Ind.: %d", arr[maxi], maxi);
    printf("\nMin: %d; Ind.: %d", arr[mini], mini);
    t = arr[maxi];
    arr[maxi] = arr[mini];
    arr[mini] = t;
    printf("\nIzmenenniy ");
    _printarr();
    printf("\nMax: %d; Ind.: %d", arr[mini], mini);
    printf("\nMin: %d; Ind.: %d", arr[maxi], maxi);
}

int _cr3(){
    int N3 = 0;

    for (int i = 0; i < N; i++){
        if (arr[i] % 3 == 0){arr3[N3] = arr[i]; N3++;}
    }
    if (N3 == 0) {printf("\nTchisel kratnih 5 net");}
    printf("\nMassiv Kratnih 3: ");
    for (int i = 0; i < N3; i++){
        printf("%d ", arr3[i]);
    }

    return N3;
}

int _cr5(){
    int N5 = 0;

    for (int i = 0; i < N; i++){
        if (arr[i] % 5 == 0){arr5[N5] = arr[i]; N5++;}
    }
    if (N5 == 0) {printf("\nTchisel kratnih 5 net");}
    printf("\nMassiv Kratnih 5: ");
    for (int i = 0; i < N5; i++){
        printf("%d ", arr5[i]);
    }

    return N5;
}

void _presort(){
    int index = 1;
    int sort = 1;
    printf("\nVibirite massiv.\
\n1. Original\
\n2. Kratnie 3\
\n3. Kratnie 5\
\nVvodite: ");
    scanf("%d", &index);
    printf("\nVibirite sortirovku.\
\n1. Ubivanie\
\n2. Vosrastanie\
\nVvodite: ");
    scanf("%d", &sort);

    switch(sort){
    case 1: _sortub(index); break;
    case 2: _sortv(index); break;
    }
}

void _sortub(int index){
    int arrs[n] = {0};
    int size = n;

    switch(index){
    case 1: size = N; for(int i = 0; i < size; i++){ arrs[i] = arr[i];} break;
    case 2: size = _cr3(); for(int i = 0; i < size; i++){ arrs[i] = arr3[i];} break;
    case 3: size = _cr5(); for(int i = 0; i < size; i++){ arrs[i] = arr5[i];} break;
    }

    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1;j++){
            if(arrs[j] < arrs[j+1]){
                int t = arrs[j];
                arrs[j] = arrs[j+1];
                arrs[j+1] = t;
            }
        }
    }

    printf("\nOtsortirovanni massiv: ");
    for (int i = 0; i < size; i++){
        printf("%d ", arrs[i]);
    }
}

void _sortv(int index){
    int arrs[n] = {0};
    int size = n;

    switch(index){
    case 1: size = N; for(int i = 0; i < size; i++){ arrs[i] = arr[i];} break;
    case 2: size = _cr3(); for(int i = 0; i < size; i++){ arrs[i] = arr3[i];} break;
    case 3: size = _cr5(); for(int i = 0; i < size; i++){ arrs[i] = arr5[i];} break;
    }

    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1;j++){
            if(arrs[j] > arrs[j+1]){
                int t = arrs[j];
                arrs[j] = arrs[j+1];
                arrs[j+1] = t;
            }
        }
    }

    printf("\nOtsortirovanni massiv: ");
    for (int i = 0; i < size; i++){
        printf("%d ", arrs[i]);
    }
}
