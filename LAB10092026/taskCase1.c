#include <stdio.h>

int main() 
{
    int numTotalMain = 0;

    printf("VVedite chislo ot 0 do 999: ");
    scanf("%d", &numTotalMain);

    int hundredsNumInInput = numTotalMain / 100;
    int simpleNumInInput = numTotalMain % 100;
    int SimpleSimpleNumInINput = simpleNumInInput % 10;
    int tensNumInInput = simpleNumInInput / 10;

    if (numTotalMain < 0 || numTotalMain >= 1000) {
        printf("Error: chisla ne te !!!!\n");
        return 1;
    }

    if (numTotalMain == 0) {
        printf("nol zero\n");
        return 0;
    }

    switch (hundredsNumInInput) {
        case 1: printf("sto "); break;
        case 2: printf("dvesti "); break;
        case 3: printf("trista "); break;
        case 4: printf("chetyresta "); break;
        case 5: printf("pyatsot "); break;
        case 6: printf("shestsot "); break;
        case 7: printf("semsot "); break;
        case 8: printf("vosemsot "); break;
        case 9: printf("devyatsot "); break;
    }

    if (simpleNumInInput >= 10 && simpleNumInInput <= 19) {
        switch (simpleNumInInput) {
            case 10: printf("desyat"); break;
            case 11: printf("odinnadtsat"); break;
            case 12: printf("dvenadtsat"); break;
            case 13: printf("trinadtsat"); break;
            case 14: printf("chetyrnadtsat"); break;
            case 15: printf("pyatnadtsat"); break;
            case 16: printf("shestnadtsat"); break;
            case 17: printf("semnadtsat"); break;
            case 18: printf("vosemnadtsat"); break;
            case 19: printf("devyatnadtsat"); break;
        }
    } 
    else {
        switch (tensNumInInput) {
            case 2: printf("dvadtsat "); break;
            case 3: printf("tridtsat "); break;
            case 4: printf("sorok "); break;
            case 5: printf("pyatdesyat "); break;
            case 6: printf("shestdesyat "); break;
            case 7: printf("semdesyat "); break;
            case 8: printf("vosemdesyat "); break;
            case 9: printf("devyanosto "); break;
        }

        switch (SimpleSimpleNumInINput) {
            case 1: printf("odin"); break;
            case 2: printf("dva"); break;
            case 3: printf("tri"); break;
            case 4: printf("chetyre"); break;
            case 5: printf("pyat"); break;
            case 6: printf("shest"); break;
            case 7: printf("sem"); break;
            case 8: printf("vosem"); break;
            case 9: printf("devyat"); break;
        }
    }
    printf("\n");
    return 0;
}