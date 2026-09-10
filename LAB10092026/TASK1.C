#include <stdio.h>

int main() 
{
    int numTotalMain = 0;
    int hundredsNumInInput = numTotalMain / 100;
    int simpleNumInInput = numTotalMain % 100;
    int SimpleSimpleNumInINput = simpleNumInInput % 10;
    int tensNumInInput = simpleNumInInput / 10;

    printf("Enter a number from 0 to 999: ");
    scanf("%d", &numTotalMain);
    
    if (numTotalMain < 0 || numTotalMain >= 1000) {
        printf("Error: number must be less than 1000\n");
        return 1; // kod oshibki odin
    }

    if (numTotalMain == 0) {
        printf("nol\n");
        return 0;
    }

    if (hundredsNumInInput == 1) printf("sto ");
    else if (hundredsNumInInput == 2) printf("dvesti ");
    else if (hundredsNumInInput == 3) printf("trista ");
    else if (hundredsNumInInput == 4) printf("chetyresta ");
    else if (hundredsNumInInput == 5) printf("pyatsot ");
    else if (hundredsNumInInput == 6) printf("shestsot ");
    else if (hundredsNumInInput == 7) printf("semsot ");
    else if (hundredsNumInInput == 8) printf("vosemsot ");
    else if (hundredsNumInInput == 9) printf("devyatsot ");


    if (simpleNumInInput >= 10 && simpleNumInInput <= 19) {
        if (simpleNumInInput == 10) printf("desyat");
        else if (simpleNumInInput == 11) printf("odinnadtsat");
        else if (simpleNumInInput == 12) printf("dvenadtsat");
        else if (simpleNumInInput == 13) printf("trinadtsat");
        else if (simpleNumInInput == 14) printf("chetyrnadtsat");
        else if (simpleNumInInput == 15) printf("pyatnadtsat");
        else if (simpleNumInInput == 16) printf("shestnadtsat");
        else if (simpleNumInInput == 17) printf("semnadtsat");
        else if (simpleNumInInput == 18) printf("vosemnadtsat");
        else if (simpleNumInInput == 19) printf("devyatnadtsat");
    } 
    else {
        if (tensNumInInput == 2) printf("dvadtsat ");
        else if (tensNumInInput == 3) printf("tridtsat ");
        else if (tensNumInInput == 4) printf("sorok ");
        else if (tensNumInInput == 5) printf("pyatdesyat ");
        else if (tensNumInInput == 6) printf("shestdesyat ");
        else if (tensNumInInput == 7) printf("semdesyat ");
        else if (tensNumInInput == 8) printf("vosemdesyat ");
        else if (tensNumInInput == 9) printf("devyanosto ");

        if (SimpleSimpleNumInINput == 1) printf("odin");
        else if (SimpleSimpleNumInINput == 2) printf("dva");
        else if (SimpleSimpleNumInINput == 3) printf("tri");
        else if (SimpleSimpleNumInINput == 4) printf("chetyre");
        else if (SimpleSimpleNumInINput == 5) printf("pyat");
        else if (SimpleSimpleNumInINput == 6) printf("shest");
        else if (SimpleSimpleNumInINput == 7) printf("sem");
        else if (SimpleSimpleNumInINput == 8) printf("vosem");
        else if (SimpleSimpleNumInINput == 9) printf("devyat");
    }
    return 0;
}