#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int _i, _im1 = 0;
    printf("Vvdeite tchislo <1000: ");
    scanf("%d", &_i);

        if (_i >= 100){
            switch(_i/100){
            case 1: printf("Sto "); break;
            case 2: printf("Dvesti "); break;
            case 3: printf("Tri sotni "); break;
            case 4: printf("Chetiresta "); break;
            case 5: printf("Pyatsot "); break;
            case 6: printf("Shesot "); break;
            case 7: printf("Semsot "); break;
            case 8: printf("Vosemsot "); break;
            case 9: printf("Devatsot "); break;
            }
            if (_i%10 == 0){printf("Desat");}
        if (_i >= 20){ if(_i >= 100){_im1 = _i/10; _im1 = _im1%10;} else{_im1 = _i/10;}
            if (_im1 == 1){
                switch(_i%10){
                case 1: printf("Odinnadsat"); break;
                case 2: printf("Dvenadtsat"); break;
                case 3: printf("Trinadsat"); break;
                case 4: printf("Chetirnadsat"); break;
                case 5: printf("Pyatnadsat"); break;
                case 6: printf("Shestnadsat"); break;
                case 7: printf("Semnadsat"); break;
                case 8: printf("Dvandsat"); break;
                case 9: printf("Devatnadsat"); break;
                }
                void exit(int status);
            }
            switch(_im1){
            case 2: printf("Dvadtsat "); break;
            case 3: printf("Tridsat "); break;
            case 4: printf("Sorok "); break;
            case 5: printf("Pyatdesat "); break;
            case 6: printf("Shestdesat "); break;
            case 7: printf("Semdesat "); break;
            case 8: printf("Vosemdesat "); break;
            case 9: printf("Devanosto "); break;
            }
        }
        if (_im1 != 1){
            switch(_i%10){
            case 1: printf("Odin"); break;
            case 2: printf("Dva"); break;
            case 3: printf("Tri"); break;
            case 4: printf("Chetire"); break;
            case 5: printf("Pyat"); break;
            case 6: printf("Shest"); break;
            case 7: printf("Sem"); break;
            case 8: printf("Vosem"); break;
            case 9: printf("Devat"); break;
            case 10: printf("Desat"); break;
            }
        }
    }

        if (_i < 100 and _i >= 20){
        switch(_i/10){
        case 2: printf("Dvadtsat "); break;
        case 3: printf("Tridsat "); break;
        case 4: printf("Sorok "); break;
        case 5: printf("Pyatdesat "); break;
        case 6: printf("Shestdesat "); break;
        case 7: printf("Semdesat "); break;
        case 8: printf("Vosemdesat "); break;
        case 9: printf("Devanosto "); break;
        }
        switch(_i%10){
        case 1: printf("Odin"); break;
        case 2: printf("Dva"); break;
        case 3: printf("Tri"); break;
        case 4: printf("Chetire"); break;
        case 5: printf("Pyat"); break;
        case 6: printf("Shest"); break;
        case 7: printf("Sem"); break;
        case 8: printf("Vosem"); break;
        case 9: printf("Devat"); break;
        case 10: printf("Desat"); break;
        }
        }

        if (_i <= 10){
            switch(_i){
            case 1: printf("Odin"); break;
            case 2: printf("Dva"); break;
            case 3: printf("Tri"); break;
            case 4: printf("Chetire"); break;
            case 5: printf("Pyat"); break;
            case 6: printf("Shest"); break;
            case 7: printf("Sem"); break;
            case 8: printf("Vosem"); break;
            case 9: printf("Devat"); break;
            case 10: printf("Desat"); break;
            }
        }

        if (_i>10 and _i < 20){
            switch(_i%10){
            case 1: printf("Odinnadsat"); break;
            case 2: printf("Dvenadtsat"); break;
            case 3: printf("Trinadsat"); break;
            case 4: printf("Chetirnadsat"); break;
            case 5: printf("Pyatnadsat"); break;
            case 6: printf("Shestnadsat"); break;
            case 7: printf("Semnadsat"); break;
            case 8: printf("Dvandsat"); break;
            case 9: printf("Devatnadsat"); break;
            }
            void exit(int status);
        }


        int a, b, c = 0;
        float d,x1, x2 = 0;
        printf("\nFormula f(x) = a*(x^2) + b*x + c\n");
        printf("Vvdeite a: ");
        scanf("%d", &a);
        printf("Vvdeite b: ");
        scanf("%d", &b);
        printf("Vvdeite c: ");
        scanf("%d", &c);

        if (a == 0){
            printf("Eto pryamaya. Ne parabopla\n");
            if (b > 0){printf("Ono vozrastaet\n");}
            if (b < 0){printf("Ono ubivaet\n");}
            if (b == 0){printf("Ono pryamoe\n");}
        }
        else {
            if (a > 0) {printf("Vetvi vverh\n");}
            if (a < 0) {printf("Vetvi vniz\n");}

            d = b^2 - 4*a*c;
            if (d == 0){x1 = -b/2*a;}
            if (d > 0){x1 = (-b+sqrt(d))/2*a; x2 = (-b-sqrt(d))/2*a; printf("x1 = %f", x1);printf("\nx2 = %f", x2);}
            if (d<0){printf("Tochek peresechenia net");}
        }


        int s1, s2, s3, pr, _iu = 0;
        float sq, p2 = 0;
        printf("\nStorona 1: ");
        scanf("%d", &s1);
        printf("Storona 2: ");
        scanf("%d", &s2);
        printf("Storona 3: ");
        scanf("%d", &s3);
        pr = s1+s2+s3;
        p2 = pr/2;
        sq = sqrt(p2*(p2-s1)*(p2-s2)*(p2-s3));
        if (a+b==c or a+c==b or b+c==a){
            printf("Virozhdenni");
            _iu = 1;
        }
        if (not a+b>c or not a+c>b or not b+c>a){
            printf("Ne sushestwuet");
            _iu =1;
        }
        if (_iu != 1){printf("Ploshad: %f", sq);}


    return 0;
}
