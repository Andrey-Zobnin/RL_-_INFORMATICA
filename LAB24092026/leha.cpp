#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int const n = 15;
    int N = 5, N3 = 0;
    int arr[n] = {0};
    int arr3[n] = {0};
    int p = 0, minotr = -101;
    int mini = 0 , maxi = 0, t = 0;
    float chi = 0, chs = 0, chr = 0;
    int k = 1, m = 2, tkm = 0;

    do{
        printf("Vvedite razmer massiva (Ot 1 do 15): ");
        scanf("%d", &N);
    } while(N > 15 or N < 1);

    do {printf("\nZapolnit Avtomatom?(1 ili 0): ");
        scanf("%d", &p);} while(p != 1 and p !=0);
    if (p == 1){
        for(int i = 0; i < N; i++){
            arr[i] = rand() % 201 - 100;
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

    for (int i = 0; i < N; i++){
        if (arr[i] > arr[maxi]){maxi = i;}
        if (arr[i] < arr[mini]){mini = i;}
    }
    printf("\nMax: %d; Ind.: %d", arr[maxi], maxi);
    printf("\nMin: %d; Ind.: %d", arr[mini], mini);
    t = arr[maxi];
    arr[maxi] = arr[mini];
    arr[mini] = t;
    printf("\nMassiv (MinMaxRep Versia): ");
    for (int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }
    printf("\nMax: %d; Ind.: %d", arr[mini], mini);
    printf("\nMin: %d; Ind.: %d", arr[maxi], maxi);

    for (int i = 0; i < N; i++){
        if (arr[i] % 2 == 0){
            chi++;
            chs = chs + arr[i];
        }
    }
    chr = chs/chi;
    printf("\nSrednee Chetnih: %.2f", chr);

    for (int i = 0; i < N; i++){
        if (arr[i] % 3 == 0){arr3[N3] = arr[i]; N3++;}
    }
    if (N3 == 0)
    printf("\nMassiv Kratnih 3: ");
    for (int i = 0; i < N3; i++){
        printf("%d ", arr3[i]);
    }

    for (int i = 0; i < N; i++){
        if (arr[i] < 0 and arr[i] > minotr){minotr = arr[i];}
    }
    if (minotr == -101){printf("\nVse polozhitelnie");} else {printf("\nMaximalnoe otritzatelnoe: %d", minotr);}

    printf("\nVvedite k (Ot 0 do N-1, < m): ");
    scanf("%d",&k);
    printf("Vvedite m (Ot 0 do N-1, > k): ");
    scanf("%d",&m);
    tkm = arr[k];
    for (int i = k; i <= m; i++){
        if (arr[i] < tkm) {tkm = arr[i];}
    }
    printf("Minnimalnoe ot k do m: %d", tkm);

    return 0;
}
