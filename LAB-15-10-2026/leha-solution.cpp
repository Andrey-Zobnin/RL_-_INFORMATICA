#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 30

void input_matrix(int* rw, int* cl);
void enter_martix(int mtr[][MAX_SIZE], int rw, int cl);
void print_matrix(int mtr[][MAX_SIZE], int rw, int cl);
void obmen(int* x, int* y);

void sumcl(int mtr[][MAX_SIZE], int rw, int cl);
void sumsortcl(int mtr[][MAX_SIZE], int rw, int cl);
void privsos(int mtr[][MAX_SIZE], int rw, int cl, int arr[]);
void print_arr(int a[], int ln);

void min_pdiag_o(int mtr[][MAX_SIZE], int rw, int cl);
int prost_arr(int mtr[][MAX_SIZE], int rw, int cl, int arr[]);
void sort_array_ub(int arr[], int ln);
void spiral_matrix(int mtr[][MAX_SIZE], int rw, int cl);

int main(){
    int rw,cl = 1;
    int matr[MAX_SIZE][MAX_SIZE];
    int matr2[MAX_SIZE][MAX_SIZE];
    int a[MAX_SIZE*MAX_SIZE];
    int ap[MAX_SIZE*MAX_SIZE];
    int matr3[MAX_SIZE][MAX_SIZE];
    int s = 0;

    input_matrix(&rw, &cl);
    enter_martix(matr, rw, cl);
    print_matrix(matr, rw, cl);
    sumsortcl(matr, rw, cl);
    privsos(matr, rw, cl, a);

    printf("\nVo vtoroi zadache ispolzuetsa kvadratnaya matritsa!\n");
    do{input_matrix(&rw, &cl);} while(rw!=cl);
    enter_martix(matr2, rw, cl);
    print_matrix(matr2, rw, cl);
    min_pdiag_o(matr2, rw, cl);
    int apln = prost_arr(matr2, rw, cl, ap);
    if(apln != 0){sort_array_ub(ap, apln);}

    input_matrix(&rw, &cl);
    enter_martix(matr3, rw, cl);
    print_matrix(matr3, rw, cl);
    spiral_matrix(matr3, rw, cl);

    printf("\n\nProgramm finished 0");
    return 0;
}

void input_matrix(int* rw, int* cl){
    int p = 1;
    do{
        printf("\nViberete tip (1 - pryamoug; 0 - cvadrat): ");
        scanf("%d", &p);} while(p != 1 && p != 0);
    do{
        if(p == 1){
            printf("Vvedite RW CL: ");
            scanf("%d%d", rw, cl);
        }
        if(p==0){
            printf("Vvedite N: ");
            scanf("%d", rw);
            *cl = *rw;
        }
    } while(*rw > MAX_SIZE || *rw < 1 || *cl > MAX_SIZE || *cl < 1);

}

void enter_martix(int mtr[][MAX_SIZE], int rw, int cl){
    srand(time(NULL));

    int p = 1;
    do{
        printf("Zapolint avtomatom? (1 ili 0):");
        scanf("%d", &p);} while(p != 1 && p != 0);
    if (p == 1){
        for(int i = 0;i<rw;i++){
            for(int j = 0;j<cl;j++){
                mtr[i][j] = rand()%2001-1000;
            }
        }
    }
    if (p == 0){
        for(int i = 0;i<rw;i++){
            for(int j = 0;j<cl;j++){
                printf("Vvedite elment [%d][%d]", i, j);
                scanf("%d", &mtr[i][j]);
            }
        }
    }
}

void print_matrix(int mtr[][MAX_SIZE], int rw, int cl){
    for(int i=0;i<rw;i++){
        printf("|");
        for(int j=0;j<cl;j++){
            printf("%4d | ", mtr[i][j]);
        }
        printf("\n");
    }
}

void obmen(int* x, int* y){
    int t = *x;
    *x = *y;
    *y = t;
}

void sumcl(int mtr[][MAX_SIZE], int rw, int cl){
    int sum = 0;
    for(int i=0;i<cl;i++){
        sum=0;
        for(int j=0;j<rw;j++){
            sum+=mtr[j][i];
        }
        printf("Sum cl %d: %d\n", i, sum);
    }
}

void sumsortcl(int mtr[][MAX_SIZE], int rw, int cl){
    printf("Pered Sort:\n");
    sumcl(mtr, rw, cl);
    int sum1, sum2, t = 0;
    for(int i=0;i<cl;i++){
        for(int j=i+1; j<cl ;j++){
            sum1 = 0;
            sum2 = 0;
            for(int k=0; k<rw; k++){
                sum1 += mtr[k][i];
                sum2 += mtr[k][j];
            }
            if(sum1<sum2){
                for(int k=0; k<rw; k++){
                    t = mtr[k][i];
                    mtr[k][i] = mtr[k][j];
                    mtr[k][j] = t;
                }
            }
        }
    }
    print_matrix(mtr, rw, cl);
    printf("Posle Sort:\n");
    sumcl(mtr, rw, cl);
}

void privsos(int mtr[][MAX_SIZE], int rw, int cl, int arr[]){
    int count = 0;
    for(int i=0;i<rw;i++){
        for(int j=0;j<cl;j++){
            bool flag = true;

            if(i > 0 && mtr[i][j] <= mtr[i-1][j]){flag = false;}
            if(i < rw-1 && mtr[i][j] <= mtr[i+1][j]){flag = false;}
            if(j > 0 && mtr[i][j] <= mtr[i][j-1]){flag = false;}
            if(j < cl-1 && mtr[i][j] <= mtr[i][j+1]){flag = false;}

            if(flag){arr[count] = mtr[i][j];count++;}
        }
    }
    printf("Bolshe sosedei: ");
    print_arr(arr, count);
}

void print_arr(int a[], int ln){
    for(int i = 0; i < ln; i++){
        printf("%d ", a[i]);
    }
}

void min_pdiag_o(int mtr[][MAX_SIZE], int rw, int cl){
    int mind =0;
    for(int j=0;j<cl;j++){
        mind = 0;
        for(int i=0;i<rw;i++){
            if(mtr[i][j]<mtr[mind][j]){mind = i;}
        }
        obmen(&mtr[mind][j], &mtr[rw-1-j][j]);
    }

    printf("Obmenyali min v stolbce s pob. diag:\n");
    print_matrix(mtr, rw, cl);
}

int prost_arr(int mtr[][MAX_SIZE], int rw, int cl, int arr[]){
    int ln = 0;
    bool flag;

    for(int i=0; i<rw;i++){
        for(int j=0; j<cl; j++){
            if(mtr[i][j] <= 1){continue;}
            flag = false;
            for(int k=2;k<=mtr[i][j]/2;k++){
                if(mtr[i][j] % k == 0){flag = true; break;}
            }
            if(flag==false){arr[ln] = mtr[i][j];ln++;}
        }
    }
    if(ln == 0){printf("Prostih net");} else{printf("Massiv prostih: ");}
    print_arr(arr, ln);
    return ln;
}

void sort_array_ub(int arr[], int ln){
    for(int i=0;i<ln;i++){
        for(int j=i+1;j<ln;j++){
            if(arr[i]<arr[j]){obmen(&arr[i], &arr[j]);}
        }
    }
    printf("\nSort. massiv: ");
    print_arr(arr, ln);
}

void spiral_matrix(int mtr[][MAX_SIZE], int rw, int cl){
    int t = 0;
    int b = rw-1;
    int l = 0;
    int r = cl-1;
    int num = 0;

    printf("\nVvedite nachalo otcheta: ");
    scanf("%d", &num);

    while(t <= b && l <= r){
        for(int i = l; i<=r; i++){
            mtr[t][i] = num;
            num++;
        }
        t++;

        for(int i = t; i<=b; i++){
            mtr[i][r] = num;
            num++;
        }
        r--;

        if(t <= b){
            for(int i=r; i>=l;  i--){
                mtr[b][i] = num;
                num++;
            }
            b--;
        }

        if(l <= r){
            for(int i=b; i>=t;i--){
                mtr[i][l] = num;
                num++;
            }
            l++;
        }
    }

    print_matrix(mtr, rw, cl);
}
